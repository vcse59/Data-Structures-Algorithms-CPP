#include <iostream>
#include <memory>
#include <string>
#include "../include/LinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::shared_ptr<DSA::LinkedList<string>> llContainer = std::make_shared<DSA::LinkedList<string>>("Invalid String");

    llContainer->insertEnd("Test1");
    llContainer->insertEnd("Test2");
    llContainer->insertEnd("Test3");
    llContainer->insertEnd("Test4");

    llContainer->print();
    cout << "Front : " << llContainer->getFront().get() << endl;

    cout << "Remove element from front" << endl;
    llContainer->removeFront();

    llContainer->print();

    return 0;
}
