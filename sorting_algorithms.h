# pragma once

#include <iostream>
#include <iomanip>
#include <vector>

//------------------------------------------------------------

namespace sort_alg {
	const int left = -10;
	const int right = 10;

	const int size = 10;

	//==============================================================================
	//==============| Инициализация и вывод в стандартный поток

	template <typename T> void CreateArray(T*& array) {
		srand(time(NULL));
		
		array = new T[size];

		for (int i = 0; i < size; i++) {
			int whole_part = rand() % (right - left + 1) + left;
			double fractional_part = static_cast<double>(1) / (rand() % (right - left + 1) + 1);
			array[i] = whole_part + fractional_part;
		}
	}
	template <typename T> void PrintArray(T array) {
		for (int i = 0; i < size; i++) {
			std::cout << std::left << std::setw(10) << std::setprecision(4) << array[i];
		}

		std::cout << std::endl;
	}

	//==============================================================================
	//==============| Функции сортировки
	
	//------------------------------------------------------------------------------
	//--------------| Сортировка простым выбором

	namespace aux_alg {
		template <typename T>void Swap(T& digit_1, T& digit_2) {
			digit_1 = digit_1 + digit_2;
			digit_2 = digit_1 - digit_2;
			digit_1 = digit_1 - digit_2;
		}
		template <typename T> int FindMinElementIndex(T array, int left, int right) {
			int min_index = left;

			for (int i = left; i < right; i++) {
				if (array[i] < array[min_index]) {
					min_index = i;
				}
			}

			return min_index;
		}
	}

	template <typename T> void SortingByChoice(T array) {
		for (int i = 0; i < size; i++) {
			int index = aux_alg::FindMinElementIndex(array, i, size);
			if (i != index) {
				aux_alg::Swap(array[i], array[index]);
			}
		}
	}

	//------------------------------------------------------------------------------
	//--------------| Сортировка простой вставкой

	namespace aux_alg {
		template <typename T1> void SimpleInsert(T1 array, int i) {

			int index = i + 1;
			int value = array[index];

			while ((index > 0) && (value < array[index - 1])) {
				array[index] = array[index - 1];
				index--;
			}

			array[index] = value;

		}
	}

	template <typename T> void SortingBySimpleInserts(T array) {
		for (int i = 0; i < size - 1 ; i++) {
			aux_alg::SimpleInsert(array, i);
		}
	}

	//------------------------------------------------------------------------------
	//--------------| Сортировка бинарной вставкой

	namespace aux_alg {
		template <typename T1, typename T2> int BinaryMinFind(T1 array, T2 value, int left, int right) {
			int m = 0;

			while (right - left > 1) {
				m = (left + right) / 2;

				if (array[m] < value) {
					left = m;
				}
				else {
					right = m;
				}
			}

			if (array[left] <= value) {
				return right;
			}
			else {
				return left;
			}

		}
		template <typename T> void BinaryInsert(T array, int i) {
			
			int index = i + 1;
			int value = array[index];
			int up = BinaryMinFind(array, array[index], 0, index);

			while (index > up){
				array[index] = array[index - 1];
				index--;
			}

			array[index] = value;

		}
	}

	template <typename T> void SortingByBinaryInserts(T array) {
		for (int i = 0; i < size - 1; i++) {
			aux_alg::BinaryInsert(array, i);
		}
	}

	//------------------------------------------------------------------------------
	//--------------| Сортировка слиянием

	namespace aux_alg {
		template<typename T> void Merge(T* array, int left, int right) {
			int m = (left + right) / 2;

			if (left >= right || m < left || m > right) {
				return;
			}
			if (right == left + 1 && array[left] > array[right]) {
				aux_alg::Swap(array[left], array[right]);
				return;
			}

			T* temp = new T[right + 1];
			for (int i = 0; i < right + 1; i++) {
				temp[i] = array[left + i];
			}

			int j = 0;
			int k = m - left + 1;
			for (int i = left; i <= right; i++) {
				if (j > m - left) {
					array[i] = temp[k];
					k++;
				}
				else if (k > right - left) {
					array[i] = temp[j];
					j++;
				}
				else {
					if (temp[j] < temp[k]) {
						array[i] = temp[j];
						j++;
					}
					else {
						array[i] = temp[k];
						k++;
					}
				}
			}
		}
	}

	template<typename T> void MergeSort(T array, int left, int right) {
		if (left >= right) {
			return;
		}

		int m = (left + right) / 2;

		MergeSort(array, left, m);
		MergeSort(array, m + 1, right);
		Merge(array, left, right);
	}

}

