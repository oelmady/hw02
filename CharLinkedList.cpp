/*
 *  CharLinkedList.cpp
 *  Omar Elmady
 *  June 8
 *
 *  CS 15 HW 2
 *
 *  This file implements a CharLinkedList class with properties similar to std:vector using linked lists
 *
 */

#include "CharLinkedList.h"
#include <iostream>

using namespace std;
//The default constructor takes no parameters and initializes an empty list with no nodes.
CharLinkedList::CharLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

//helper function for destructor that recursively frees node data of a linkedlist, and returns nothing
void CharLinkedList::destroy(Node *node) 
{
    if (node == nullptr) return;
    cout << "destroying: " << &node << endl;
    Node * next = node->next;
    free(node);

    if (next == nullptr) return;
    else 
    {
        cout << "next up is: " << &next << endl;
        destroy(next);
    }
}
//Define a destructor that destroys/deletes/recycles all heap-allocated data in the cur- rent list. It has no parameters and returns nothing. This function uses a private recursive helper function destry(Node *head).
CharLinkedList::~CharLinkedList()
{
    if (head != nullptr)
    {
        destroy(head);
    }
}
//A size function that takes no parameters and returns an integer value that is the number of characters in the list. The size of a list is 0 if and only if it isEmpty.
int CharLinkedList::size() const
{  
    int result = 0;
    Node * temp = head;
    while (temp != nullptr) 
    {
        result++;
        temp = temp->next;
    }
    return result;
}
//An isEmpty function that takes no parameters and returns a boolean value that is true if this specific instance of the class is empty (has no characters) and false otherwise.
bool CharLinkedList::isEmpty() const
{
    return (head == nullptr);
}
//The second constructor takes in a single character as a parameter and creates a one element list consisting of that character.
CharLinkedList::CharLinkedList(char c)
{
    head = new Node;
    tail = new Node;
    head->data = c;
    head->next = tail;
    length = 1;
}
//A first function that takes no parameters and returns the first element (char) in the list. If the list is empty it should throw a C++ std::runtime_error exception with the message “cannot get first of empty LinkedList”.
char CharLinkedList::first() const
{
    if (head == nullptr)
    {
        throw std::runtime_error("cannot get first of empty LinkedList");
    }
    return head->data;
}

void CharLinkedList::copyRec(Node *node)
{
    return;
};
//A copy constructor for the class that makes a deep copy of a given instance.
CharLinkedList::CharLinkedList(const CharLinkedList &other)
{
    if (other.head == nullptr) 
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    // create new nodes for each of the nodes of the &other list
    // and add them to the head of the list

}
//A clear function that takes no parameters and has a void return type. It makes the instance into an empty list using the recurisve destroy(*node) function.
void CharLinkedList::clear()
{
    if (head != nullptr)
    {
        destroy(head);
    }

    head   =  nullptr;
    tail   = nullptr;
    length = 0;
}
//A last function that takes no parameters and returns the last element (char) in the list. If the list is empty it throws a C++ std::runtime_error exception with the message “cannot get last of empty LinkedList”.
char CharLinkedList::last() const
{
    if (tail == nullptr) 
    {
        throw std::runtime_error("Cannot get last of linked list");
    }
    return tail->data;
}
//A pushAtBack function that takes an element (char) and has a void return type. It inserts the given new element after the end of the existing elements of the list.
void CharLinkedList::pushAtBack(char c)
{
    Node * node = new Node{c, nullptr};
    tail->next = node;
    tail = node;
    length++;
}
//A pushAtFront function that takes an element (char) and has a void return type. It inserts the given new element in front of the existing elements of the list.
void CharLinkedList::pushAtFront(char c)
{
    Node * node = new Node{c, head};
    head = node;
    length++;
}

//An elementAt function that takes an integer index and returns the element (char) in the list at that index. NOTE: Indices are 0-based. If the index is out of range it should throw a C++ std::range_error exception with the message “index (IDX) not in range [0..SIZE)” where IDX is the index that was given and SIZE is the size of the linked list.
char CharLinkedList::elementAt(int index) const
{
    if (index < 0 || index >= size())
    {
        string msg = "index" + to_string(index) + " is not in range [0.." + to_string(size()) + ")";
        throw std::range_error(msg);
    }
    if (index == 0) return head->data;
    else if (index == size()) return tail->data;

    Node * nextNode = head;
    for (int i = 0; i < index; i++) 
    {
        nextNode = nextNode->next;
    }
    return nextNode->data;
} 
//A toString function that takes no parameters and has a std::string return type. It returns a string which contains the characters of the CharLinkedList. The string will be formatted like this:
// [CharLinkedList of size 5 <<Alice >>]
string CharLinkedList::toString() const
{
    string msg = "[CharLinkedList of size " + to_string(length);
    msg +=  " <<";
    Node * node = head;
    char data;
    for (int i = 0; i < length; i++)
    {
        data = node->data;
        msg += data;
        node = node->next;
    }
    msg += ">>]";
    return msg;
}