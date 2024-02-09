#include <iostream>
#include <memory>
#include <string>
#include "../include/LinkedList.h"

using namespace std;


void IntegerLinkedList()
{
    cout << "*****************************************" << endl;
    cout << "Template operation with Integer data type" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
    std::shared_ptr<DSA::LinkedList<int>> llContainer = std::make_shared<DSA::LinkedList<int>>(-1);

    llContainer->insertStart(10);
    llContainer->insertStart(20);
    llContainer->insertStart(30);
    llContainer->insertStart(40);
    llContainer->insertStart(50);

    llContainer->insertEnd(60);

    llContainer->insertNth(70, 2);

    llContainer->print();

    cout << "Front : " << llContainer->getFront().get() << endl;
    cout << "Back : " << llContainer->getBack().get() << endl;
    cout << "3rd Node : " << llContainer->getNth(3).get() << endl;

    llContainer->print();

    cout << "Remove Front" << endl;
    llContainer->removeFront();

    llContainer->print();

    cout << "Remove Back" << endl;
    llContainer->removeBack();

    llContainer->print();

    cout << "Remove 3rd" << endl;
    llContainer->removeNth(3);

    llContainer->print();

    int elemToBeFound = 20;
    cout << "Find " << elemToBeFound << endl;
    DSA::SingleLinkedListNode<int>* node = llContainer->find(elemToBeFound);
    if (node != nullptr)
        cout << "Element " << elemToBeFound << " found in LinkedList Container" << endl;
    else
        cout << "Element " << elemToBeFound <<" not found in LinkedList Container" << endl;

    cout << endl << endl << endl;
}

void StringLinkedList()
{
    cout << "*****************************************" << endl;
    cout << "Template operation with String data type" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
    
    std::shared_ptr<DSA::LinkedList<string>> llContainer = std::make_shared<DSA::LinkedList<string>>("INVALID");

    llContainer->insertStart("STRING 1");
    llContainer->insertStart("STRING 2");
    llContainer->insertStart("STRING 3");
    llContainer->insertStart("STRING 4");
    llContainer->insertStart("STRING 5");
    llContainer->insertStart("STRING 6");

    llContainer->insertEnd("STRING 7");

    llContainer->insertNth("STRING 8", 2);

    llContainer->print();

    cout << "Front : " << llContainer->getFront().get() << endl;
    cout << "Back : " << llContainer->getBack().get() << endl;
    cout << "3rd Node : " << llContainer->getNth(3).get() << endl;

    llContainer->print();

    cout << "Remove Front" << endl;
    llContainer->removeFront();

    llContainer->print();

    cout << "Remove Back" << endl;
    llContainer->removeBack();

    llContainer->print();

    cout << "Remove 3rd" << endl;
    llContainer->removeNth(3);

    string elemToBeFound = "STRING 2";
    cout << "Find " << elemToBeFound << endl;
    DSA::SingleLinkedListNode<string>* node = llContainer->find(elemToBeFound);
    if (node != nullptr)
        cout << "Element " << elemToBeFound << " found in Doubly LinkedList Container" << endl;
    else
        cout << "Element " << elemToBeFound <<" not found in Doubly LinkedList Container" << endl;

    cout << endl << endl << endl;
}


int main(int argc, char *argv[])
{
    IntegerLinkedList();   
    StringLinkedList();
    return 0;
}
