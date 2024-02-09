#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

namespace DSA{

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

            RETURN_STATE getErrorState(){
                return mState;
            }

        private:
            T mT1;
            T mErrorValue;
            RETURN_STATE mState;
    };

    template<class T>
    class Node{
        public:
            Node(T pData);
            Node(T pData, Node* prevNode, Node* nextNode);
            ~Node();

            void setData(T pData);
            T getData();

            void setPrev(Node* prevNode);
            Node* getPrev();

            void setNext(Node* nextNode);
            Node* getNext();

        private:
            T mData;
            Node* mPrev{nullptr};
            Node* mNext{nullptr};
    };

    template<class T>
    class DoublyLinkedList{
        public:
            DoublyLinkedList(T defaultErrorValue);
            ~DoublyLinkedList();

            void insertStart(T pData);
            void insertEnd(T pData);
            void insertNth(T pData, int nth);

            RETURN_VALUE<T> getFront();
            RETURN_VALUE<T> getBack();
            RETURN_VALUE<T> getNth(int nTh);

            void removeFront();
            void removeBack();
            void removeNth(int nTh);

            Node<T>* find(T elem);

            void print();
            void getHead();
        
        private:
            Node<T>* mHead{nullptr};
            T mDefaultErrorVal;
    };
}

#include "../src/DoublyLinkedList.impl"

#endif