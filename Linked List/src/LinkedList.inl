template <class T>
DSA::SingleLinkedListNode<T>::SingleLinkedListNode()
{
    mNext = nullptr;
}

template <class T>
DSA::SingleLinkedListNode<T>::SingleLinkedListNode(T pData)
{
    mData = pData;
    mNext = nullptr;
}

template <class T>
DSA::SingleLinkedListNode<T>::SingleLinkedListNode(T pData, SingleLinkedListNode<T>* next)
{
    mData = pData;
    mNext = next;
}

template <class T>
DSA::SingleLinkedListNode<T>::~SingleLinkedListNode()
{

}

template <class T>
void DSA::SingleLinkedListNode<T>::setData(T pData)
{
    mData = pData;
}

template <class T>
T DSA::SingleLinkedListNode<T>::getData()
{
    return mData;
}

template <class T>
void DSA::SingleLinkedListNode<T>::setNext(SingleLinkedListNode<T>* next)
{
    mNext = next;
}

template <class T>
DSA::SingleLinkedListNode<T>* DSA::SingleLinkedListNode<T>::getNext()
{
    return mNext;
}

template <class T>
DSA::LinkedList<T>::LinkedList(T defaultErrorVal)
{
    mDefaultError = defaultErrorVal;
    mHead = nullptr;
}

template <class T>
DSA::LinkedList<T>::~LinkedList()
{
    SingleLinkedListNode<T>* tempHead = mHead;
    while(tempHead != nullptr)
    {
        SingleLinkedListNode<T>* currentNode = tempHead;
        tempHead = tempHead->getNext();
        delete currentNode;
    }

    mHead = nullptr;
}

template <class T>
DSA::SingleLinkedListNode<T>* DSA::LinkedList<T>::getHead()
{
    return mHead;
}
            
template <class T>
void DSA::LinkedList<T>::insertStart(T pData)
{
    DSA::SingleLinkedListNode<T>* tempHead = mHead;

    SingleLinkedListNode<T>* node = new SingleLinkedListNode<T>(pData);
    if (tempHead != nullptr)
    {
        node->setNext(tempHead);
        tempHead = node;
    }
    mHead = node;
}

template <class T>
void DSA::LinkedList<T>::insertEnd(T pData)
{
    DSA::SingleLinkedListNode<T>* tempHead = mHead;

    SingleLinkedListNode<T>* node = new SingleLinkedListNode<T>(pData);
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

template <class T>
void DSA::LinkedList<T>::insertNth(T pData, int nTh)
{
    int nodeCount = 0;

    SingleLinkedListNode<T>* tempHead = mHead;
    SingleLinkedListNode<T>* prevNode = mHead;
    SingleLinkedListNode<T>* node = new SingleLinkedListNode<T>(pData);
    
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

template <class T>
DSA::RETURN_VALUE<T> DSA::LinkedList<T>::getFront()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return DSA::RETURN_VALUE<T>(mDefaultError, mDefaultError, DSA::RETURN_STATE::ERROR);
    }
    return DSA::RETURN_VALUE<T>(mHead->getData(), mDefaultError, DSA::RETURN_STATE::SUCCESS);
}

template <class T>
T DSA::LinkedList<T>::getBack()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return -1;
    }

    SingleLinkedListNode<T>* tempHead = mHead;

    while(tempHead->getNext() != nullptr)
        tempHead = tempHead->getNext();
    return tempHead->getData();
}

template <class T>
T DSA::LinkedList<T>::getNth(int nTh)
{
    int nodeCount = 0;
    int lastFetchedValue = -1;

    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return lastFetchedValue;
    }

    SingleLinkedListNode<T>* tempHead = mHead;
    
    while(tempHead != nullptr)
    {
        nodeCount++;
        if (nodeCount == nTh)
            break;
        tempHead = tempHead->getNext();
    }

    return ((nodeCount == nTh) ? tempHead->getData() : lastFetchedValue);
}

template <class T>
void DSA::LinkedList<T>::removeFront()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }
    
    SingleLinkedListNode<T>* tempHead = mHead;
    mHead = mHead->getNext();
    delete tempHead;
}

template <class T>
void DSA::LinkedList<T>::removeBack()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }

    SingleLinkedListNode<T>* tempHead = mHead;
    SingleLinkedListNode<T>* prevNode = mHead;
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

template <class T>
void DSA::LinkedList<T>::removeNth(int nTh)
{
     int nodeCount = 0;

    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }

    SingleLinkedListNode<T>* tempHead = mHead;
    SingleLinkedListNode<T>* prevNode = mHead;
    
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

template <class T>
void DSA::LinkedList<T>::print()
{
    if (mHead == nullptr){
        std::cout << __FUNCTION__ << " : Container is empty" << std::endl;
        return;
    }

    std::cout << "Linked List contents are : ";
    SingleLinkedListNode<T>* tempHead = mHead;

    while (tempHead != nullptr)
    {
        std::cout << tempHead->getData() << " ";
        tempHead = tempHead->getNext();
    }

    std::cout << std::endl;
}