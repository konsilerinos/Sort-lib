#pragma once

#include <iostream>
#include <chrono>

int* GetSomeArray(int); // Инициализация массива
void PrintArray(std::string, int*, int); // Печать массива

std::chrono::milliseconds InsertSort(int*, int);			// Сортировка вставками 
std::chrono::milliseconds BubbleSort(int*, int);			// Сортировка стандартным обменом
std::chrono::milliseconds ShellSort(int*, int);				// Сортировка методом Шелла
std::chrono::milliseconds ChoiceSort(int*, int);			// Сортировка простым выбором
std::chrono::milliseconds QuickSort(int*, int, int);		// Сортировка методом Хоара
std::chrono::milliseconds BinaryInsertSort(int*, int);		// Сортировка бинарными вставками