#include <iostream>
#include "sorting_algorithms.h"

int main() {

	int* array = nullptr;

	sort_alg::CreateArray(array);
	sort_alg::PrintArray(array);

	sort_alg::MergeSorting(array, 0, sort_alg::size);
	sort_alg::PrintArray(array);

	delete[] array;

	return 0;
}