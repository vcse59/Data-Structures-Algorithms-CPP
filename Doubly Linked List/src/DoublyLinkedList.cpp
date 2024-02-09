#include <iostream>
#include "../include/DoublyLinkedList.h"

DSA::Node::Node(int pData){
    mData = pData;
    mPrev = nullptr;
    mNext = nullptr;
}

DSA::Node::Node(int pData, Node* prevNode, Node* nextNode){
    mData = pData;
    mPrev = prevNode;
    mNext = nextNode;
}

DSA::Node::~Node(){

}

void DSA::Node::setData(int pData){
    mData = pData;
    mPrev = nullptr;
    mNext = nullptr;
}

int DSA::Node::getData(){
    return mData;
}

void DSA::Node::setPrev(Node* prevNode){
    mPrev = prevNode;
}

DSA::Node* DSA::Node::getPrev(){
    return mPrev;
}

void DSA::Node::setNext(Node* next){
    mNext = next;
}

DSA::Node* DSA::Node::getNext(){
    return mNext;
}

DSA::DoublyLinkedList::DoublyLinkedList(){
    mHead = nullptr;
}

DSA::DoublyLinkedList::~DoublyLinkedList(){
    mHead = nullptr;
}

void DSA::DoublyLinkedList::insertStart(int pData){
    
    Node* tempHead = mHead;

    Node* node = new Node(pData, nullptr, nullptr);

    if (mHead != nullptr) {
        mHead->setPrev(node);
        node->setNext(mHead);
    }
    mHead = node;
}

void DSA::DoublyLinkedList::insertEnd(int pData){

    Node* tempHead = mHead;

    Node* node = new Node(pData, nullptr, nullptr);

    if(tempHead == nullptr)
        mHead = node;
    else {
        while(tempHead->getNext() != nullptr){
            tempHead = tempHead->getNext();
        }

        node->setPrev(tempHead);
        tempHead->setNext(node);
    }
}

void DSA::DoublyLinkedList::insertNth(int pData, int nth){
    int nodeCount = 0;
    Node* tempHead = mHead;

    Node* node = new Node(pData, nullptr, nullptr);

    if(tempHead == nullptr)
        mHead = node;
    else {
        while(tempHead->getNext() != nullptr){
        nodeCount++;

        if (nodeCount == nth)
            break;

        tempHead = tempHead->getNext();
        }
        
        if (nodeCount != nth){
            node->setPrev(tempHead);
            tempHead->setNext(node);
        }else{
            tempHead->getPrev()->setNext(node);
            node->setPrev(tempHead->getPrev());
            node->setNext(tempHead);
            tempHead->setPrev(node);
        }
    }
}

int DSA::DoublyLinkedList::getFront(){
    if (mHead == nullptr)
        return -1;

    return mHead->getData();
}

int DSA::DoublyLinkedList::getBack(){
    if (mHead == nullptr)
        return -1;

    Node* tempHead = mHead;

    while(tempHead->getNext() != nullptr){
        tempHead = tempHead->getNext();
    }

    return  tempHead->getData();
}

int DSA::DoublyLinkedList::getNth(int nth){
    int nodeCount = 0;
    int retNthVal = -1;

    if (mHead == nullptr)
        return retNthVal;

    Node* tempHead = mHead;
    while(tempHead != nullptr){
        nodeCount++;
        if (nodeCount == nth){
            retNthVal = tempHead->getData();
            break;
        }
        tempHead = tempHead->getNext();
    }

    return retNthVal;
}

void DSA::DoublyLinkedList::removeFront(){
    Node* tempHead = mHead;

    if (mHead == nullptr)
        return;

    mHead = mHead->getNext();
    mHead->setPrev(nullptr);

    delete tempHead;
}

void DSA::DoublyLinkedList::removeBack(){
    Node* tempHead = mHead;

    if (mHead == nullptr)
        return;

    while(tempHead->getNext() != nullptr){
        tempHead = tempHead->getNext();
    }

    tempHead->getPrev()->setNext(nullptr);
    delete tempHead;
}

void DSA::DoublyLinkedList::removeNth(int nTh){
    Node* tempHead = mHead;
    int nodeCount = 0;

    if (mHead == nullptr)
        return;

    while(tempHead != nullptr){
        nodeCount++;

        if(nodeCount == nTh)
            break;

        tempHead = tempHead->getNext();
    }

    if (nodeCount == nTh){
        tempHead->getPrev()->setNext(tempHead->getNext());
        tempHead->getNext()->setPrev(tempHead->getPrev());
        delete tempHead;
    }
}

void DSA::DoublyLinkedList::print(){
    Node* tempHead = mHead;

    std::cout << "Doubly Linked List contents are : ";
    while(tempHead != nullptr){
        std::cout << tempHead->getData() << " ";
        tempHead = tempHead->getNext();
    }
    std::cout << std::endl;
}

