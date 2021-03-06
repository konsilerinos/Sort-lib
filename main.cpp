#include <iostream>
#include "sorting_algorithms.h"

int main() {

	double *array = nullptr;

	sort_lib::create_f::CreateArray(array);
	sort_lib::print_f::PrintArray(array);

	sort_lib::MergeSorting(array, 0, sort_lib::size);

	sort_lib::print_f::PrintArray(array);

	delete[] array;

	return 0;
}