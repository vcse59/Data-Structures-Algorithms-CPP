#include <iostream>
#include <memory>
#include "../include/LinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::shared_ptr<DSA::LinkedList> llContainer = std::make_shared<DSA::LinkedList>();

    llContainer->insertStart(10);
    
    llContainer->print();

    cout << endl << "Front : " << llContainer->getFront() << " 10th : " << llContainer->getNth(10) << " back : " << llContainer->getBack() << endl;

    llContainer->print();
    llContainer->removeNth(100);
    llContainer->print();
    llContainer->removeBack();
    llContainer->print();

    llContainer->print();
    llContainer->removeFront();
    llContainer->print();
    llContainer->removeFront();
    llContainer->print();

    llContainer->print();
    llContainer->removeNth(2);
    llContainer->print();
    llContainer->removeNth(5);
    llContainer->print();

    llContainer->print();
    llContainer->getFront();
    llContainer->print();
    llContainer->getFront();
    llContainer->print();

    llContainer->print();
    llContainer->getBack();
    llContainer->print();
    llContainer->getBack();
    llContainer->print();

    llContainer->print();
    llContainer->getNth(4);
    llContainer->print();
    llContainer->getNth(7);
    llContainer->print();

    return 0;
}
