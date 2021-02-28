#include "sorting_algorithms.h"
#include <iostream>
#include <chrono>
#include <ctime>

//---------------------------------------------------------------------------------------

/* Getting an array of pseudo-random numbers */
int* GetSomeArray(int size) {

	int* new_mas = new int[size]; // Allocating memory for an array

	srand(time(NULL)); // Initializing the pseudo-random number generator

	/* Writing an array */
	for (int i = 0; i < size; i++) {
		new_mas[i] = rand() % 10;
	}

	/* Returning the result */
	return new_mas;
}

/* Printing an array */
void PrintArray(std::string msg, int* mas, int size) {
	std::cout << msg; // Custom Message

	/* Displaying array elements on the screen */
	for (int i = 0; i < size; i++) {
		std::cout << mas[i] << " ";
	}

	/* Line break */
	std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

/* ���������� ���������, ���������� ����� ���������� */
std::chrono::milliseconds InsertSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // ���������� ������� ������ ����������

	int index = 0, temp = 0;

	for (int i = 0; i < size - 1; i++) {

		index = i + 1;		// ������ ������������ ��������
		temp = mas[index];	// �������� ������������ ��������

		/* ����� ������� ��������� �� ����� ������������ �������� */
		for (int j = i + 1; j > 0; j--) { // ������ +1
			/* ���� ����������� ������� ������, �� �������� ������ */
			if (temp < mas[j - 1]) {
				mas[j] = mas[j - 1];
				index = j - 1; // ������ "���������� �����"
			}
		}

		mas[index] = temp; // ���������� ������������ �������� � ������
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

/* ���������� ����������� �������, ���������� ����� ���������� */
std::chrono::milliseconds BubbleSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // ���������� ������� ������ ����������

	/* ����� ��� ��������� � ������� */
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			/* ���������� � ������� ����������� */
			if (mas[j] > mas[j + 1]) {
				int temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

/* ���������� ������� �����, ���������� ����� ���������� */
std::chrono::milliseconds ShellSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // ���������� ������� ������ ����������

	int interval = size / 2; // ���������� ����� ������������� ���������

	while (interval > 0)
	{
		for (int i = 0; i < size - interval; i++)
		{
			int j = i;
			/* ����������� ��� ���������, ���������� � ������� ����������� */
			while (j >= 0 && mas[j] > mas[j + interval])
			{
				int temp = mas[j];
				mas[j] = mas[j + interval];
				mas[j + interval] = temp;

				j--; // ������������ ����������� ��������
			}
		}
		interval = interval / 2; // ���������� ��������� � ��� ����
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

/* ���������� ������� �������, ���������� ����� ���������� */
std::chrono::milliseconds ChoiceSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // ���������� ������� ������ ����������

	/* ������ �� ��������������� ����� ������� */
	for (int i = 0; i < size; i++)
	{
		int temp = mas[0]; // ���������� ��� �������� ������������ ��������
		/* ����� ������������ �������� � ����������������� ����� ������� */
		/* � ������������ ��������������� ����� */
		for (int j = i + 1; j < size; j++)
		{
			/* ���������� � ������� ����������� */
			if (mas[i] > mas[j])
			{
				temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

/* ���������� ������� �����, ���������� ����� ���������� */
std::chrono::milliseconds QuickSort(int* mas, int first, int last) {

	auto begin = std::chrono::steady_clock::now(); // ���������� ������� ������ ����������

	int i = first, j = last, element = mas[(first + last) / 2];

	/* ����������� �������� � ������ ���������� */
	do {
		while (mas[i] < element) {
			i++;
		}
		while (mas[j] > element) {
			j--;
		}

		if (i <= j) {
			if (mas[i] > mas[j]) {
				int temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}

			i++;
			j--;
		}
	} while (i <= j);

	/* ����������� ����� */
	if (i < last) {
		QuickSort(mas, i, last);
	}
	if (first < j) {
		QuickSort(mas, first, j);
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

/* ���������� �������� ��������, ���������� ����� ���������� */
std::chrono::milliseconds BinaryInsertSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // Saving the start time of execution

	int element = 0, left = 0, right = 0, average = 0;

	for (int i = 1; i < size; i++) {
		if (mas[i - 1] > mas[i]) {

			element = mas[i];
			left = 0;
			right = i - 1;

			do {
				average = (left + right) / 2;
				if (mas[average] < element) {
					left = average + 1;
				}
				else {
					right = average - 1;
				}
			} while (left <= right);

			for (int j = i - 1; j >= left; j--) {
				mas[j + 1] = mas[j];
			}

			mas[left] = element;
		}
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

//---------------------------------------------------------------------------------------

void InsertSortTest() {

	std::cout << "> Insert sort time testing" << std::endl;

	for (int i = 10000; i < 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = InsertSort(array, i).count(); // Measuring the running time of the insertion sorting algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

void BubbleSortTest() {

	std::cout << "> Bubble sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = BubbleSort(array, i).count(); // ����� ������� ������ ��������� ������������ ������

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

void ShellSortTest() {

	std::cout << "> Shell sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = ShellSort(array, i).count(); // Measuring the running time of the Shell sorting algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

void ChoiseSortTest() {

	std::cout << "> Choise sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = ChoiceSort(array, i).count(); // Measuring the running time of the sorting algorithm by simple selection

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

void QuickSorttest() {

	std::cout << "> Quick sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = QuickSort(array, 0, i - 1).count(); // Measuring the running time of the quick sort algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

void BunarySortTest() {

	std::cout << "> Binary sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = BinaryInsertSort(array, i).count(); // Measuring the running time of the binary sorting algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}