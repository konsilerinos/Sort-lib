#pragma once

#include <iostream>
#include <chrono>

int* GetSomeArray(int);						// Initializing an array
void PrintArray(std::string, int*, int);	// Printing an array

std::chrono::milliseconds InsertSort(int*, int);			// Sorting by inserts
std::chrono::milliseconds BubbleSort(int*, int);			// Sorting by standard exchange
std::chrono::milliseconds ShellSort(int*, int);				// Sorting by the Shell method
std::chrono::milliseconds ChoiceSort(int*, int);			// Sort by simple selection
std::chrono::milliseconds QuickSort(int*, int, int);		// Hoare sorting method
std::chrono::milliseconds BinaryInsertSort(int*, int);		// Sorting by binary inserts

void TestSortingAlgorithms();	// Testing of sorting algorithms

void InsertSortTest();			// Testing the insertion sorting algorithm	
void BubbleSortTest();			// Testing the "bubble" sorting algorithm
void ShellSortTest();			// Testing the Shell sorting algorithm
void ChoiseSortTest();			// Testing the selection sorting algorithm
void QuickSorttest();			// Testing the Quick sort algorithm
void BunarySortTest();			// Testing the binary sorting algorithm