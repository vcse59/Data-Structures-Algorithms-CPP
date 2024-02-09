#include <iostream>
#include <memory>
#include "../include/DoublyLinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::shared_ptr<DSA::DoublyLinkedList> dllContainer = std::make_shared<DSA::DoublyLinkedList>();
    dllContainer->insertStart(10);
    dllContainer->insertStart(20);
    dllContainer->insertStart(30);
    dllContainer->insertStart(40);
    dllContainer->insertStart(50);

    dllContainer->insertEnd(60);

    dllContainer->insertNth(70, 2);

    dllContainer->print();

    cout << "Front : " << dllContainer->getFront() << endl;
    cout << "Back : " << dllContainer->getBack() << endl;
    cout << "3rd Node : " << dllContainer->getNth(3) << endl;

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
    return 0;
}
