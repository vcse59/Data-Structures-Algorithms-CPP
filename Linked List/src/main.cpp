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

    llContainer->insertEnd(10);
    llContainer->insertEnd(20);
    llContainer->insertEnd(30);
    llContainer->insertEnd(40);

    llContainer->print();
    DSA::RETURN_VALUE<int> returnVal = llContainer->getFront();

    if (returnVal.getErrorState() == DSA::RETURN_STATE::SUCCESS)
        cout << "Front : " << returnVal.get() << endl;

    cout << "Remove element from front" << endl;
    llContainer->removeFront();

    llContainer->print();
    cout << endl << endl << endl;
}

void StringLinkedList()
{
    cout << "*****************************************" << endl;
    cout << "Template operation with String data type" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
    
    std::shared_ptr<DSA::LinkedList<string>> llContainer = std::make_shared<DSA::LinkedList<string>>("INVALID");

    llContainer->insertEnd("String1");
    llContainer->insertEnd("String2");
    llContainer->insertEnd("String3");
    llContainer->insertEnd("String4");
    llContainer->insertEnd("String5");

    llContainer->print();
    DSA::RETURN_VALUE<string> returnVal = llContainer->getFront();

    if (returnVal.getErrorState() == DSA::RETURN_STATE::SUCCESS)
        cout << "Front : " << returnVal.get() << endl;

    cout << "Remove element from front" << endl;
    llContainer->removeFront();

    llContainer->print();
    cout << endl << endl << endl;
}


int main(int argc, char *argv[])
{
    IntegerLinkedList();   
    StringLinkedList();
    return 0;
}
