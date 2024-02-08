#include "../include/LinkedList.h"
#include <iostream>

DSA::SingleLinkedListNode::SingleLinkedListNode()
{
    mNext = nullptr;
}

DSA::SingleLinkedListNode::SingleLinkedListNode(int pData)
{
    mData = pData;
    mNext = nullptr;
}

DSA::SingleLinkedListNode::SingleLinkedListNode(int pData, SingleLinkedListNode* next)
{
    mData = pData;
    mNext = next;
}

DSA::SingleLinkedListNode::~SingleLinkedListNode()
{

}

void DSA::SingleLinkedListNode::setData(int pData)
{
    mData = pData;
}

int DSA::SingleLinkedListNode::getData()
{
    return mData;
}

void DSA::SingleLinkedListNode::setNext(SingleLinkedListNode* next)
{
    mNext = next;
}

DSA::SingleLinkedListNode* DSA::SingleLinkedListNode::getNext()
{
    return mNext;
}

DSA::LinkedList::LinkedList()
{
    mHead = nullptr;
}

DSA::LinkedList::~LinkedList()
{
    SingleLinkedListNode* tempHead = mHead;
    while(tempHead != nullptr)
    {
        SingleLinkedListNode* currentNode = tempHead;
        tempHead = tempHead->getNext();
        delete currentNode;
    }

    mHead = nullptr;
}

DSA::SingleLinkedListNode* DSA::LinkedList::getHead()
{
    return mHead;
}
            
void DSA::LinkedList::insertStart(int pData)
{
    DSA::SingleLinkedListNode* tempHead = mHead;

    SingleLinkedListNode* node = new SingleLinkedListNode(pData);
    if (tempHead != nullptr)
    {
        node->setNext(tempHead);
        tempHead = node;
    }
    mHead = node;
}

void DSA::LinkedList::insertEnd(int pData)
{
    DSA::SingleLinkedListNode* tempHead = mHead;

    SingleLinkedListNode* node = new SingleLinkedListNode(pData);
    if (tempHead == nullptr)
    {
        mHead = node;
    }else{
        while(tempHead->getNext() != nullptr)
        {
            tempHead = tempHead->getNext();
        }
        tempHead->setNext(node);
    }
}

void DSA::LinkedList::insertNth(int pData, int nTh)
{
    int nodeCount = 0;

    SingleLinkedListNode* tempHead = mHead;
    SingleLinkedListNode* prevNode = mHead;
    SingleLinkedListNode* node = new SingleLinkedListNode(pData);
    
    while(tempHead != nullptr)
    {
        nodeCount++;
        if (nodeCount == nTh)
        {
            prevNode->setNext(node);
            node->setNext(tempHead);
            break;
        }

        prevNode = tempHead;
        tempHead = tempHead->getNext();
    }
}

int DSA::LinkedList::getFront()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return -1;
    }
    return mHead->getData();
}

int DSA::LinkedList::getBack()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return -1;
    }

    SingleLinkedListNode* tempHead = mHead;

    while(tempHead->getNext() != nullptr)
        tempHead = tempHead->getNext();
    return tempHead->getData();
}

int DSA::LinkedList::getNth(int nTh)
{
    int nodeCount = 0;
    int lastFetchedValue = -1;

    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return lastFetchedValue;
    }

    SingleLinkedListNode* tempHead = mHead;
    
    while(tempHead != nullptr)
    {
        nodeCount++;
        if (nodeCount == nTh)
            break;
        tempHead = tempHead->getNext();
    }

    return ((nodeCount == nTh) ? tempHead->getData() : lastFetchedValue);
}

void DSA::LinkedList::removeFront()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }
    
    SingleLinkedListNode* tempHead = mHead;
    mHead = mHead->getNext();
    delete tempHead;
}

void DSA::LinkedList::removeBack()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }

    SingleLinkedListNode* tempHead = mHead;
    SingleLinkedListNode* prevNode = mHead;
    while(tempHead->getNext() != nullptr)
    {
        prevNode = tempHead;
        tempHead = tempHead->getNext();
    }

    if (tempHead == mHead)
        mHead = nullptr;
    else
        prevNode->setNext(nullptr);

    delete tempHead;
}

void DSA::LinkedList::removeNth(int nTh)
{
     int nodeCount = 0;

    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }

    SingleLinkedListNode* tempHead = mHead;
    SingleLinkedListNode* prevNode = mHead;
    
    while(tempHead != nullptr)
    {
        nodeCount++;
        if (nodeCount == nTh)
        {
            if (prevNode == mHead)
                mHead = nullptr;
            else
                prevNode->setNext(tempHead->getNext());
            delete tempHead;
            break;
        }

        prevNode = tempHead;
        tempHead = tempHead->getNext();
    }
}

void DSA::LinkedList::print()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }

    std::cout << "Linked List contents are : ";
    SingleLinkedListNode* tempHead = mHead;

    while (tempHead != nullptr)
    {
        std::cout << tempHead->getData() << " ";
        tempHead = tempHead->getNext();
    }

    std::cout << std::endl;
}