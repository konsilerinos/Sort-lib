#include <iostream>
#include "sorting_algorithms.h"

int main() {


	int n = -1;

	if (n == 0) {
		for (int i = 10000; i < 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // ������������� �������
			int time = InsertSort(array, i).count(); // ����� ������� ������ ��������� ���������� ���������

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // ������������ ������
		}
	}
	else if (n == 1) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // ������������� �������
			int time = BubbleSort(array, i).count(); // ����� ������� ������ ��������� ������������ ������

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // ������������ ������
		}
	}
	else if (n == 2) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // ������������� �������
			int time = ShellSort(array, i).count(); // ����� ������� ������ ��������� ���������� �����

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // ������������ ������
		}
	}
	else if (n == 3) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // ������������� �������
			int time = ChoiceSort(array, i).count(); // ����� ������� ������ ��������� ���������� ������� �������

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // ������������ ������
		}
	}
	else if (n == 4) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // ������������� �������
			int time = QuickSort(array, 0, i - 1).count(); // ����� ������� ������ ��������� ���������� ������� �������

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // ������������ ������
		}
	}
	else if (n == 5) {
		for (int i = 10000; i <= 100000; i = i + 10000) {

			int* array = GetSomeArray(i); // ������������� �������
			int time = BinaryInsertSort(array, i).count(); // ����� ������� ������ ��������� ���������� ������� �������

			std::cout << "Size = " << i << ", time = " << time << ";" << std::endl;

			delete[] array; // ������������ ������
		}
	}

	return 0;
}

