#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <ctime>

namespace sort_lib {

	namespace data {

		const int size = 10;
		
		const int a = 0;
		const int b = 10;
	}

	namespace create {

		template <typename T> void CreateArray(T*& array) {

			srand(time(NULL));

			array = new T[data::size];

			for (int i = 0; i < data::size; i++) {

				int whole_part = rand() % (data::b - data::a + 1) + data::a;
				double fractional_part = static_cast<double>(1) / (rand() % (data::b - data::a + 1) + 1);

				array[i] = whole_part + fractional_part;
			}
		}

		template <typename T> T* GetArrayCopy(T* array) {

			T* newArray = new T[data::size];

			for (int i = 0; i < data::size; i++) {

				newArray[i] = array[i];
			}

			return newArray;
		}
	}

	namespace print {

		template <typename T> void PrintArray(T array) {

			std::cout << "Array: ";

			for (int i = 0; i < data::size; i++) {

				std::cout << std::fixed << std::setprecision(2) << std::setw(7) << array[i];
			}

			std::cout << std::endl;
		}
	}

	namespace aux_fun {

		template <typename T> void Swap(T& digit1, T& digit2) {

			digit1 = digit1 + digit2;
			digit2 = digit1 - digit2;
			digit1 = digit1 - digit2;
		}
		template <typename T> int FindMinElementIndex(T array, int left, int right) {

			int minElementIndex = left;

			for (int i = left + 1; i < right; i++) {

				if (array[minElementIndex] > array[i]) {

					minElementIndex = i;
				}
			}

			return minElementIndex;
		}

		template <typename T> void InsertElement(T* array, int index) {

			T value = array[index];

			while ((index > 0) && (value < array[index - 1])) {

				array[index] = array[index - 1];
				index--;
			}

			array[index] = value;
		}

		template <typename T> int BinaryFindMinElementIndex(T* array, T value, int left, int right) {

			int middle = 0;

			while (right - left > 1) {

				middle = (left + right) / 2;

				if (array[middle] < value) {

					left = middle;
				}
				else {

					right = middle;
				}
			}

			if (array[left] <= value) {

				return right;
			}
			else {

				return left;
			}
		}
		template <typename T> void BinaryInsert(T* array, int i) {

			int index = i + 1;
			T value = array[index];
			int up = BinaryFindMinElementIndex(array, array[index], 0, index);

			while (index > up) {

				array[index] = array[index - 1];
				index--;
			}

			array[index] = value;
		}

		template <typename T> void MergeSorting(T* array, int start, int end) {

			if (end - start < 2) {

				return;
			}
			else if (end - start == 2) {

				if (array[start] > array[start + 1]) {

					aux_fun::Swap(array[start], array[start + 1]);
				}
			}

			MergeSorting(array, start, (start + end) / 2);
			MergeSorting(array, (start + end) / 2, end);

			T* temp = new T[end - start];

			int start1 = start;
			int end1 = (start + end) / 2;

			int start2 = end1;
			int end2 = end;

			for (int i = 0; i < end - start; i++) {

				if ((start1 >= end1) || ((start2 < end2) && (array[start2] < array[start1]))) {

					temp[i] = array[start2];
					start2++;
				}
				else {

					temp[i] = array[start1];
					start1++;
				}
			}

			for (int i = start; i < end; i++) {

				array[i] = temp[i - start];
			}

			delete[] temp;
		}

		template <typename T> void QuickSorting(T* array, int left, int right) {

			T value = array[left];

			int left_c = left;
			int right_c = right;

			while (left < right) {

				while ((array[right] >= value) && (left < right)) {

					right--;
				}

				if (left != right) {

					array[left] = array[right];
				}

				while ((array[left] <= value) && (left < right)) {

					left++;
				}

				array[right] = array[left];
				right--;
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

	template <typename T> void ChoiseSorting(T array) {

		for (int i = 0; i < data::size; i++) {

			int index = aux_fun::FindMinElementIndex(array, i, data::size);

			if (index != i) {

				aux_fun::Swap(array[index], array[i]);
			}
		}
	}
	template <typename T> void InsertSorting(T array) {

		for (int i = 1; i < data::size; i++) {

			aux_fun::InsertElement(array, i);
		}
	}
	template <typename T> void BinaryInsertSorting(T array) {

		for (int i = 1; i < data::size - 1; i++) {

			aux_fun::BinaryInsert(array, i);
		}
	}
	template <typename T> void MergeSorting(T array) {

		aux_fun::MergeSorting(array, 0, data::size);
	}
	template <typename T> void ExchangeSorting(T array) {

		for (int i = 0; i < data::size; i++) {

			for (int j = 0; j < data::size - 1; j++) {

				if (array[j] > array[j + 1]) {

					aux_fun::Swap(array[j], array[j + 1]);
				}
			}
		}
	}
	template <typename T> void ShakerSorting(T array) {

		int left = 0;
		int right = data::size - 1;

		while (left < right) {

			int lastSwap = 0;

			for (int i = left; i < right; i++) {

				if (array[i] > array[i + 1]) {

					aux_fun::Swap(array[i], array[i + 1]);
					lastSwap = i;
				}
			}

			right = lastSwap;

			for (int i = right; i > left; i--) {

				if (array[i - 1] > array[i]) {

					aux_fun::Swap(array[i - 1], array[i]);
					lastSwap = i;
				}
			}

			left = lastSwap;
		}
	}
	template <typename T> void ShellSorting(T array) {

		for (int s = data::size; s > 0; s /= 2) {

			for (int i = 0; i < data::size; i++) {

				for (int j = i + s; j < data::size; j += s) {

					if (array[i] > array[j]) {

						aux_fun::Swap(array[i], array[j]);
					}
				}
			}
		}
	}
	template <typename T> void QuickSorting(T array) {

		aux_fun::QuickSorting(array, 0, data::size - 1);
	}

	namespace time {

		namespace aux_fun {

			template <typename T> std::chrono::nanoseconds ChoiseSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				ChoiseSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds InsertSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				InsertSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds BinaryInsertSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				BinaryInsertSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds MergeSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				MergeSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds ExchangeSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				ExchangeSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds ShakerSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				ShakerSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds ShellSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				ShellSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}

			template <typename T> std::chrono::nanoseconds QuickSortingTest(T array) {

				std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

				QuickSorting(array);

				std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

				std::chrono::nanoseconds resultTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				return resultTime;
			}
		}

		template <typename T> std::chrono::nanoseconds ChoiseSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::ChoiseSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds InsertSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::InsertSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds BinaryInsertSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::BinaryInsertSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds MergeSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::MergeSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds ExchangeSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::ExchangeSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds ShakerSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::ShakerSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds ShellSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::ShellSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}

		template <typename T> std::chrono::nanoseconds QuickSortingTest(T array, int count) {

			std::chrono::nanoseconds averageTime = std::chrono::nanoseconds(0);

			for (int i = 0; i < count; i++) {

				T arrayCopy = create::GetArrayCopy(array);

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				averageTime += aux_fun::QuickSortingTest(array);
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				delete[] arrayCopy;
			}

			averageTime /= count;

			return averageTime;
		}
	}
}