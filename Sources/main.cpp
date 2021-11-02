#include "sort.h"
#include "view.h"
#include <iostream>

int main() {

    Sort sort;

    sort.RunTimeTest(500);
    sort.RunTimeTest(2000);

    View::Print("Press <Enter> to continue...");
    std::cin.get();
    std::cin.get();
    std::cin.get();
    std::cin.get();

    return 0;
}
