#include <iostream>
#include "sortlib.h"

int main() {

	double* array = nullptr;

	sort_lib::create::CreateArray(array);

	sort_lib::print::PrintArray(array);

	//std::cout << "Average time sorting by choises (ns): " << sort_lib::time::ChoiseSortingTest(array, 100).count() << std::endl;
	//std::cout << "Average time sorting by inserts (ns): " << sort_lib::time::InsertSortingTest(array, 100).count() << std::endl;
	//std::cout << "Average time sorting by binary inserts (ns): " << sort_lib::time::BinaryInsertSortingTest(array, 100).count() << std::endl;
	std::cout << "Average time merge sorting (ns): " << sort_lib::time::MergeSortingTest(array, 100).count() << std::endl;
	//std::cout << "Average time sorting by exchange (ns): " << sort_lib::time::ExchangeSortingTest(array, 100).count() << std::endl;
	//std::cout << "Average time shake sorting (ns): " << sort_lib::time::ShakerSortingTest(array, 100).count() << std::endl;
	//std::cout << "Average time shell sorting (ns): " << sort_lib::time::ShellSortingTest(array, 100).count() << std::endl;
	//std::cout << "Average time quick sorting (ns): " << sort_lib::time::QuickSortingTest(array, 100).count() << std::endl;

	sort_lib::print::PrintArray(array);

	delete[] array;

	return 0;
}