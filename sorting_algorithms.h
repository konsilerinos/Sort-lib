#pragma once

#include <iostream>
#include <chrono>

int* GetSomeArray(int); // ������������� �������
void PrintArray(std::string, int*, int); // ������ �������

std::chrono::milliseconds InsertSort(int*, int);			// ���������� ��������� 
std::chrono::milliseconds BubbleSort(int*, int);			// ���������� ����������� �������
std::chrono::milliseconds ShellSort(int*, int);				// ���������� ������� �����
std::chrono::milliseconds ChoiceSort(int*, int);			// ���������� ������� �������
std::chrono::milliseconds QuickSort(int*, int, int);		// ���������� ������� �����
std::chrono::milliseconds BinaryInsertSort(int*, int);		// ���������� ��������� ���������