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

    class Node{
        public:
            Node(int pData);
            Node(int pData, Node* prevNode, Node* nextNode);
            ~Node();

            void setData(int pData);
            int getData();

            void setPrev(Node* prevNode);
            Node* getPrev();

            void setNext(Node* nextNode);
            Node* getNext();

        private:
            int mData;
            Node* mPrev{nullptr};
            Node* mNext{nullptr};
    };

    class DoublyLinkedList{
        public:
            DoublyLinkedList();
            ~DoublyLinkedList();

            void insertStart(int pData);
            void insertEnd(int pData);
            void insertNth(int pData, int nth);

            int getFront();
            int getBack();
            int getNth(int nTh);

            void removeFront();
            void removeBack();
            void removeNth(int nTh);

            void print();
            void getHead();
        
        private:
            Node* mHead{nullptr};
    };
}

#endif