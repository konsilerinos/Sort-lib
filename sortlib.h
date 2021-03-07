# pragma once

#include <iostream>
#include <iomanip>

//------------------------------------------------------------

namespace sort_lib {

	namespace data {
		static int left = -50;
		static int right = 50;

		static int size = 7;

		static void SetLeftRightSize(int new_left, int new_right, int new_size) {
			if (new_left > new_right || size < 0) {
				exit(1);
			}

			left = new_left;
			right = new_right;
			size = new_size;
		}
	}

	//==============================================================================
	//==============| Инициализация и вывод в стандартный поток

	namespace create_f {

		template <typename T> void CreateArray(T*& array) {
			srand(time(NULL));

			array = new T[data::size];

			for (int i = 0; i < data::size; i++) {
				int whole_part = rand() % (data::right - data::left + 1) + data::left;
				double fractional_part = static_cast<double>(1) / (rand() % (data::right - data::left + 1) + 1);
				array[i] = whole_part + fractional_part;
			}
		}

	}
	namespace print_f {

		template <typename T> void PrintArray(T array) {
			for (int i = 0; i < data::size; i++) {
				std::cout << std::left << std::setw(10) << std::setprecision(4) << array[i];
			}

			std::cout << std::endl;
		}

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
		for (int i = 0; i < data::size; i++) {
			int index = aux_alg::FindMinElementIndex(array, i, data::size);
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
		for (int i = 0; i < data::size - 1 ; i++) {
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
		for (int i = 0; i < data::size - 1; i++) {
			aux_alg::BinaryInsert(array, i);
		}
	}

	//------------------------------------------------------------------------------
	//--------------| Сортировка слиянием

	template <typename T> void MergeSorting(T* array, int start, int end) {
		if (end - start < 2) {
			return; // Сортировка не требуется
		}
		else if (end - start == 2) {
			if (array[start] > array[start + 1]) {
				aux_alg::Swap(array[start], array[start + 1]); // Сортировка массива из двух элементов
				return;
			}
		}

		// Рекурсивная сортировка
		MergeSorting(array, start, start + (end - start) / 2);
		MergeSorting(array, start + (end - start) / 2, end);

		T* temp = new T[end - start];
		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;

		for (int i = 0; i < end - start; i++) {
			// b1 >= e1 - выход за пределы массива 1
			// b2 < end && array[b2] <= array[b1]) - проверка для элемента массива 2
			if (b1 >= e1 || (b2 < end && array[b2] <= array[b1])) {
				temp[i] = array[b2];
				b2++;
			}
			else {
				temp[i] = array[b1];
				b1++;
			}
		}

		// Изменение промежутка исходного массива
		for (int i = start; i < end; i++) {
			array[i] = temp[i - start];
		}

		delete[] temp;
	}

	//------------------------------------------------------------------------------
	//--------------| Сортировка стандартным обменом

	template <typename T> void BubbleSorting(T array) {
		for (int i = 0; i < data::size - 1; i++) {
			for (int j = i + 1; j < data::size; j++) {
				if (array[j] < array[j-1]) {
					aux_alg::Swap(array[j], array[j - 1]);
				}
			}
		}
	}

	//------------------------------------------------------------------------------
	//--------------| Быстрая сортировка (Хоара)

	template <typename T> void QuickSorting(T* array, int left, int right) {		
		T value = array[left];

		int left_c = left;
		int right_c = right;

		while (left < right)
		{
			while ((array[right] >= value) && (left < right)) {
				right--;
			}
				
			if (left != right)
			{
				array[left] = array[right];
				left++;
			}

			while ((array[left] <= value) && (left < right)) {
				left++;
			}
			
			if (left != right)
			{
				array[right] = array[left];
				right--;
			}
		}

		array[left] = value;

		int new_left = left;
		left = left_c;
		right = right_c;

		if (left < new_left) {
			QuickSorting(array, left, new_left - 1);
		}
		if (right > new_left) {
			QuickSorting(array, new_left + 1, right);
		}

	}

}

