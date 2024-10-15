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
        if (i == index)
            break;
        prev = current;
        current = current->getNextPtr();
        i++;
    }

    Node *newNode = new Node(data, current, prev);
    prev->setNextPtr(newNode);
    current->setPrevPtr(newNode);
}

void List::deleteAtIndex(int index){

    Node *current = headPtr->getNextPtr();
    Node *prev = headPtr;

    int i = 0;

    while (current != NULL){
        if (i == index)
            break;
        prev = current;
        current = current->getNextPtr();
        i++;
    }
    Node *nextPtr = current->getNextPtr();
    prev->setNextPtr(current->getNextPtr());
    nextPtr->setPrevPtr(prev);
}

void List::readItem(int index){

    Node *current = headPtr->getNextPtr();

    int i = 0;

    while (current != NULL){
        if (i == index){
            cout << current->getData() << endl;
            return;
        }
        current = current->getNextPtr();
        i++;
    }
    cout <<  current->getData() << endl;
}

void List::reverseList(){

    Node *tempPrev;
    Node *front = tailPtr;
    Node *temp = tailPtr;

    while(temp != NULL) {
        tempPrev = temp->getPrevPtr();
        temp->setPrevPtr(temp->getNextPtr());
        temp->setNextPtr(tempPrev);
        temp = tempPrev;
    }
    headPtr = front;
    tailPtr = tempPrev;
}

void List::printForward(){

    Node *current = headPtr->getNextPtr();

    while(current != NULL){
        cout << current->getData() << endl;
        current = current->getNextPtr();
    }
}

void List::printBackward(){

    Node *current = tailPtr->getPrevPtr();

    while(current != NULL && current->getPrevPtr() != NULL){
        cout << current->getData() << endl;
        current = current->getPrevPtr();
    }
}
