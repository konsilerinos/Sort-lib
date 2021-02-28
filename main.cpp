#include <iostream>
#include "sorting_algorithms.h"

int main() {


	int n = -1;

	if (n == 0) {
		for (int i = 10000; i < 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // Инициализация массива
			int time = InsertSort(array, i).count(); // Замер времени работы алгоритма сортировки вставками

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // Освобождение памяти
		}
	}
	else if (n == 1) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // Инициализация массива
			int time = BubbleSort(array, i).count(); // Замер времени работы алгоритма стандартного обмена

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // Освобождение памяти
		}
	}
	else if (n == 2) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // Инициализация массива
			int time = ShellSort(array, i).count(); // Замер времени работы алгоритма сортировки Шелла

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // Освобождение памяти
		}
	}
	else if (n == 3) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // Инициализация массива
			int time = ChoiceSort(array, i).count(); // Замер времени работы алгоритма сортировки простым выбором

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // Освобождение памяти
		}
	}
	else if (n == 4) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // Инициализация массива
			int time = QuickSort(array, 0, i - 1).count(); // Замер времени работы алгоритма сортировки простым выбором

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // Освобождение памяти
		}
	}
	else if (n == 5) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // Инициализация массива
			int time = BinaryInsertSort(array, i).count(); // Замер времени работы алгоритма сортировки простым выбором

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // Освобождение памяти
		}
	}

	return 0;
}

