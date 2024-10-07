//
//  List.cpp
//  DoublyLinkedList
//
//  Created by Madhuri Debnath on 9/24/20.
//

#include<iostream>
#include "List.h"
using namespace std;

void List::insert(int value){

    Node *current = headPtr->getNextPtr();
    Node *prev = headPtr;

    while (current != NULL){
        prev = current;
        current = current->getNextPtr();
    }

    Node *newNode = new Node(value, NULL, prev);
    prev->setNextPtr(newNode);
    tailPtr->setPrevPtr(newNode);
}

void List::insertAtIndex(int data, int index){

    Node *current = headPtr->getNextPtr();
    Node *prev = headPtr;

    int i = 0;

    while (current != NULL){
        if (i = index)
            break;
        prev = current;
        current = current->getNextPtr();
        i++;
    }

    Node *newNode = new Node(data, current, prev);
    prev->setNextPtr(new Node);
}
void List::deleteAtIndex(int index)
{}
void List::readItem(int index){}
void List::reverseList(){}

void List::printForward()
{}
void List::printBackward()
{}
