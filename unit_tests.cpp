/*
 *  unit_tests.cpp
 *  Omar Elmady
 *  June 8
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  This file drives a CharLinkedList class with properties similar to std:vector 
 *
 */
#include <iostream>
#include "CharLinkedList.h"

using namespace std;

int main() {
    cout << "bismillah..." << endl;
    CharLinkedList b('a');
    
    b.pushAtFront('b');
    b.pushAtBack('c');
    
    CharLinkedList bac(b);
    cout << bac.toString() << endl;
    
    cout << b.toString() << endl;
    cout << "alhamdulillah!" << endl;
    return 0;
}