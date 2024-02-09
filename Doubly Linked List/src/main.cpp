#include <iostream>
#include <memory>
#include <string>
#include "../include/DoublyLinkedList.h"

using namespace std;

void IntegerDoublyLinkedList(){

    cout << endl;   
    cout << "*****************************************" << endl;
    cout << "Template operation with Integer data type" << endl;
    cout << "*****************************************" << endl;
    cout << endl;

    std::shared_ptr<DSA::DoublyLinkedList<int>> dllContainer = std::make_shared<DSA::DoublyLinkedList<int>>(-1);
    dllContainer->insertStart(10);
    dllContainer->insertStart(20);
    dllContainer->insertStart(30);
    dllContainer->insertStart(40);
    dllContainer->insertStart(50);

    dllContainer->insertEnd(60);

    dllContainer->insertNth(70, 2);

    dllContainer->print();

    cout << "Front : " << dllContainer->getFront().get() << endl;
    cout << "Back : " << dllContainer->getBack().get() << endl;
    cout << "3rd Node : " << dllContainer->getNth(3).get() << endl;

    dllContainer->print();

    cout << "Remove Front" << endl;
    dllContainer->removeFront();

    dllContainer->print();

    cout << "Remove Back" << endl;
    dllContainer->removeBack();

    dllContainer->print();

    cout << "Remove 3rd" << endl;
    dllContainer->removeNth(3);

    dllContainer->print();

    int elemToBeFound = 20;
    cout << "Find " << elemToBeFound << endl;
    DSA::Node<int>* node = dllContainer->find(elemToBeFound);
    if (node != nullptr)
        cout << "Element " << elemToBeFound << " found in Doubly LinkedList Container" << endl;
    else
        cout << "Element " << elemToBeFound <<" not found in Doubly LinkedList Container" << endl;

    cout << endl << endl << endl;
}

void StringDoublyLinkedList(){

    cout << endl;
    cout << "*****************************************" << endl;
    cout << "Template operation with String data type" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
    
    std::shared_ptr<DSA::DoublyLinkedList<string>> dllContainer = std::make_shared<DSA::DoublyLinkedList<string>>("INVALID");
    dllContainer->insertStart("STRING 1");
    dllContainer->insertStart("STRING 2");
    dllContainer->insertStart("STRING 3");
    dllContainer->insertStart("STRING 4");
    dllContainer->insertStart("STRING 5");
    dllContainer->insertStart("STRING 6");

    dllContainer->insertEnd("STRING 7");

    dllContainer->insertNth("STRING 8", 2);

    dllContainer->print();

    cout << "Front : " << dllContainer->getFront().get() << endl;
    cout << "Back : " << dllContainer->getBack().get() << endl;
    cout << "3rd Node : " << dllContainer->getNth(3).get() << endl;

    dllContainer->print();

    cout << "Remove Front" << endl;
    dllContainer->removeFront();

    dllContainer->print();

    cout << "Remove Back" << endl;
    dllContainer->removeBack();

    dllContainer->print();

    cout << "Remove 3rd" << endl;
    dllContainer->removeNth(3);

    string elemToBeFound = "STRING 2";
    cout << "Find " << elemToBeFound << endl;
    DSA::Node<string>* node = dllContainer->find(elemToBeFound);
    if (node != nullptr)
        cout << "Element " << elemToBeFound << " found in Doubly LinkedList Container" << endl;
    else
        cout << "Element " << elemToBeFound <<" not found in Doubly LinkedList Container" << endl;

    dllContainer->print();
    cout << endl << endl << endl;
}

int main(int argc, char *argv[])
{
    IntegerDoublyLinkedList();
    StringDoublyLinkedList();
    return 0;
}
