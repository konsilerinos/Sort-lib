#include <iostream>
#include "sortlib.h"

int main() {

	int* array = nullptr;

	sort_lib::create_f::CreateArray(array);
	sort_lib::print_f::PrintArray(array);

	std::cout << "Sorting time: " << sort_lib::algo::quick_sort::TestQuickSorting(array).count() << " ns" << std::endl;

	delete[] array;

	return 0;
}