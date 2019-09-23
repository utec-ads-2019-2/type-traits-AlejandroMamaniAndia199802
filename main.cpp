#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Tester::execute();
    SelfList<int> list(SelfList<int>::Count);
    for (int i = 0; i < 100; i++) {
        list.insert(i);
    }

    list.find(5);

    return EXIT_SUCCESS;
}

