#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

namespace DSA
{

    enum RETURN_STATE
    {
        SUCCESS = 0,
        ERROR = 1
    };


    template<class T>
    class RETURN_VALUE
    {
        public:
            RETURN_VALUE(T returnVal, T errorVal, RETURN_STATE errorState) {
                mT1 = returnVal;
                mErrorValue = errorVal;
                mState = errorState;
            }

            T get() { 
                if (mState == RETURN_STATE::SUCCESS)
                    return mT1;
                else
                    return mErrorValue;
            }

        private:
            T mT1;
            T mErrorValue;
            RETURN_STATE mState;
    };

    template<class T>
    class SingleLinkedListNode{
        public:
            SingleLinkedListNode();
            SingleLinkedListNode(T pData);
            SingleLinkedListNode(T pData, SingleLinkedListNode* next);
            ~SingleLinkedListNode();

            void setData(T pData);
            T getData();

            void setNext(SingleLinkedListNode* next);
            SingleLinkedListNode* getNext();

        private:
            T mData;
            SingleLinkedListNode* mNext;
    };

    template<class T>
    class LinkedList
    {
        public:
            LinkedList(T defaultErrorVal);
            ~LinkedList();

            SingleLinkedListNode<T>* getHead();
            
            void insertStart(T pData);
            void insertEnd(T pData);
            void insertNth(T pData, int nth);

            DSA::RETURN_VALUE<T> getFront();
            T getBack();
            T getNth(int nTh);

            void removeFront();
            void removeBack();
            void removeNth(int nTh);

            void print();

        private:
            SingleLinkedListNode<T>* mHead;
            T mDefaultError;
    };
}

#include "../src/LinkedList.inl"


#endif