#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

namespace DSA
{
    class SingleLinkedListNode{
        public:
            SingleLinkedListNode();
            SingleLinkedListNode(int pData);
            SingleLinkedListNode(int pData, SingleLinkedListNode* next);
            ~SingleLinkedListNode();

            void setData(int pData);
            int getData();

            void setNext(SingleLinkedListNode* next);
            SingleLinkedListNode* getNext();

        private:
            int mData;
            SingleLinkedListNode* mNext;
    };

    class LinkedList
    {
        public:
            LinkedList();
            ~LinkedList();

            SingleLinkedListNode* getHead();
            
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

        private:
            SingleLinkedListNode* mHead;
    };
}
#endif