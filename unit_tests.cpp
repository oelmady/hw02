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
    CharLinkedList b('b');
    CharLinkedList * p = &b;
    b.pushAtFront('a');
    b.pushAtBack('c');
    b.concatenate(p);
    cout << b.toString() << endl;

    try 
    {
        CharLinkedList a;
        a.concatenate(p);
        cout << a.toString() << endl;
    } 
    catch (const runtime_error &e) 
    {
        cerr << e.what() << endl;
    }

    cout << "alhamdulillah!" << endl;
    return 0;
}