/*
 *  CharLinkedList.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2
 *
 *  This file implements a CharLinkedList class with properties similar to std:vector using linked lists
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <iostream>

using namespace std;

class CharLinkedList {
public:
    CharLinkedList(); //
    CharLinkedList(char c); //
    CharLinkedList(char arr[], int size);
    CharLinkedList(const CharLinkedList &other);
    ~CharLinkedList();
    CharLinkedList &operator=(const CharLinkedList &other);

    bool isEmpty() const; //
    void clear();//
    int size() const; //
    char first() const; //
    char last() const;//

    char elementAt(int index) const; //
    string toString() const;//

    void pushAtBack(char c); //
    void pushAtFront(char c);//
    void insertAt(char c, int index);
    void insertInOrder(char c);
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);

    void concatenate(CharLinkedList *other);
private:
    int length;
    struct Node 
    {
        char data;
        Node* next;
    };
    Node *head;
    Node *tail;

    void destroy(Node *node);
    void copyRec(Node *node);
};

#endif
