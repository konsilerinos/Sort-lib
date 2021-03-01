#include "sorting_algorithms.h"
#include <iostream>
#include <chrono>
#include <ctime>

//---------------------------------------------------------------------------------------

// Getting an array of pseudo-random numbers
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

// Printing an array
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

// Sort by inserts, returns the execution time
std::chrono::milliseconds InsertSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // Saving the start time of execution

	int index = 0, temp = 0;

	for (int i = 0; i < size - 1; i++) {

		index = i + 1;		// Index of the sorted element
		temp = mas[index];	// Value of the sorted element

		/* Shifting large elements to the place of the sorted element */
		for (int j = i + 1; j > 0; j--) { // Убрать +1
			/* If the sortable element is smaller, then move it to the right */
			if (temp < mas[j - 1]) {
				mas[j] = mas[j - 1];
				index = j - 1; // Index of "free space""
			}
		}

		mas[index] = temp; // Saving a sortable element to an array
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

// Sorting by standard exchange, returns the execution time
std::chrono::milliseconds BubbleSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // Saving the start time of execution

	/* Traversing pairs of elements in an array */
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			/* Sort in ascending order */
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

// Shell sorting, returns the execution time
std::chrono::milliseconds ShellSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // Saving the start time of execution

	int interval = size / 2; // Distance between the objects being compared

	while (interval > 0)
	{
		for (int i = 0; i < size - interval; i++)
		{
			int j = i;
			/* Comparing pairs of elements, sorting in ascending order */
			while (j >= 0 && mas[j] > mas[j + interval])
			{
				int temp = mas[j];
				mas[j] = mas[j + interval];
				mas[j + interval] = temp;

				j--; // Consideration of the previous element
			}
		}
		interval = interval / 2; // Reducing the interval of two times
	}

	auto end = std::chrono::steady_clock::now(); // Saving the end-of-execution time

	/* The run time of the algorithm */
	auto result_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	/* The transmission of information about the execution time of the algorithm */
	return result_time;
}

// Sort by simple selection, returns the execution time
std::chrono::milliseconds ChoiceSort(int* mas, int size) {

	auto begin = std::chrono::steady_clock::now(); // Сохранение времени начала выполнения

	/* Passing through the sorted part of the array */
	for (int i = 0; i < size; i++)
	{
		int temp = mas[0]; // Saving the start time of execution
		/* Finding the minimum element in the unsorted part of the array */
		/* and the formation of the sorted part */
		for (int j = i + 1; j < size; j++)
		{
			/* Sort in ascending order */
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

// Hoare sorting method, returns the execution time
std::chrono::milliseconds QuickSort(int* mas, int first, int last) {

	auto begin = std::chrono::steady_clock::now(); // Saving the start time of execution

	int i = first, j = last, element = mas[(first + last) / 2];

	/* Defining the element and sorting boundaries */
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

	/* Recursive call */
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

// Binary insertion sort, returns the execution time
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

void TestSortingAlgorithms() {
	
	bool loopParameter = true;
	while (loopParameter) {
		std::cout << "---> Select the algorithm whose time you want to find out\n" << std::endl;

		std::cout << "Sort by inserts................1" << std::endl;
		std::cout << "Sorting by standard exchange...2" << std::endl;
		std::cout << "Shell sorting..................3" << std::endl;
		std::cout << "Sort by simple selection.......4" << std::endl;
		std::cout << "Hoare sorting method...........5" << std::endl;
		std::cout << "Binary insertion sort..........6" << std::endl;
		std::cout << "Exit...........................7\n" << std::endl;

		int sortNumber = 0;

		std::cout << "---> Number of the sorting algorithm: ";
		std::cin >> sortNumber;
		std::cin.get();
		std::cout << std::endl;

		switch (sortNumber) {
		case 1:
			InsertSortTest();
			break;
		case 2:
			BubbleSortTest();
			break;
		case 3:
			ShellSortTest();
			break;
		case 4:
			ChoiseSortTest();
			break;
		case 5:
			QuickSorttest();
			break;
		case 6:
			BunarySortTest();
			break;
		case 7:
			loopParameter = false;
			break;
		default:
			break;
		}

		std::cout << std::endl;

	}
}

//---------------------------------------------------------------------------------------

// Testing the insertion sorting algorithm
void InsertSortTest() {

	std::cout << "> Insert sort time testing" << std::endl;

	for (int i = 10000; i < 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = InsertSort(array, i).count(); // Measuring the running time of the insertion sorting algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

// Testing the "bubble" sorting algorithm
void BubbleSortTest() {

	std::cout << "> Bubble sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = BubbleSort(array, i).count(); // Замер времени работы алгоритма стандартного обмена

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

// Testing the Shell sorting algorithm
void ShellSortTest() {

	std::cout << "> Shell sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = ShellSort(array, i).count(); // Measuring the running time of the Shell sorting algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

// Testing the selection sorting algorithm
void ChoiseSortTest() {

	std::cout << "> Choise sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = ChoiceSort(array, i).count(); // Measuring the running time of the sorting algorithm by simple selection

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

// Testing the Quick sort algorithm
void QuickSorttest() {

	std::cout << "> Quick sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = QuickSort(array, 0, i - 1).count(); // Measuring the running time of the quick sort algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}

// Testing the binary sorting algorithm
void BunarySortTest() {

	std::cout << "> Binary sort time testing" << std::endl;

	for (int i = 10000; i <= 100000; i = i + 10000) {

		int* array = GetSomeArray(i); // Initializing an array
		int time = BinaryInsertSort(array, i).count(); // Measuring the running time of the binary sorting algorithm

		std::cout << "Size = " << i << ", time = " << time << "ms;" << std::endl;

		delete[] array; // Freeing up memory
	}
}