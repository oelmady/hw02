/*
 *  unit_tests.cpp
 *  Omar Elmady
 *  June 8
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  This file implements a CharLinkedList class with properties similar to std:vector using linked lists
 *
 */
#include <iostream>
#include "CharLinkedList.h"

using namespace std;

int main() {
    cout << "bismillah..." << endl;
    CharLinkedList b('b');
    // CharLinkedList c('c');

    // b.pushAtBack('c');
    b.pushAtFront('a');
    cout << b.toString() << endl;

    cout << "alhamdulillah!" << endl;
    return 0;
}