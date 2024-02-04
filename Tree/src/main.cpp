#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

class TreeNode
{
    public:
        TreeNode(){
            data = -1;
            leftNode = nullptr;
            rigthNode = nullptr;
        }

        TreeNode(int pData){
            data = pData;
            leftNode = nullptr;
            rigthNode = nullptr;
        }
        ~TreeNode(){}

        void setLeft(TreeNode* node){
            leftNode = node;
        }

        void setRight(TreeNode* node){
            rigthNode = node;
        }

        int  getData() {
            return data;
        }

        void setData(int pData){
            data = pData;
        }

        TreeNode*   getLeft(){
            return leftNode;
        }

        TreeNode*   getRight(){
            return rigthNode;
        }

    protected:
        int data;
        TreeNode*   leftNode;
        TreeNode*   rigthNode;
};

enum treeType
{
    TREE_UNKNOWN = 0,
    TREE_BT = 0,
    TREE_BST
};

class TreeInterface
{
    public:
    TreeInterface() {head = nullptr;}
    virtual ~TreeInterface() {
        TreeNode* tempHead = head;
        if (head == nullptr)
        {
            cout << mType << " Tree is empty" << endl;
            return;
        }

        queue<TreeNode*> cont;
        cont.push(head);
        do{
            TreeNode* node = cont.front();
            cont.pop();
            if (node->getRight() != nullptr)
            {
                cont.push(node->getRight());
            }
            if (node->getLeft() != nullptr)
            {
                cont.push(node->getLeft());
            }
            delete node;
        }while(!cont.empty());

        head = nullptr;
    }

    void setTreeType(treeType type)
    {
        switch(type)
        {
            case treeType::TREE_BST:
            {
                mType = "Binary Search Tree";
                break;
            }
            case treeType::TREE_BT:
            {
                mType = "Binary Tree";
                break;
            }
            default :
                mType = "Unknown";
        }
    }

    TreeNode* getHead(){
            return head;
        }

    virtual void insertData(int data) = 0;
    void preorderTraversalIterative() {
        TreeNode* tempHead = head;
        stack<TreeNode*> cont;

        if (head == nullptr)
        {
            cout << mType << " Tree is empty" << endl;
            return;
        }

        cout << mType << " PreOrder Traversal : " ;

        if (tempHead != nullptr)
            cont.push(tempHead);

        while (!cont.empty())
        {
            TreeNode* node = cont.top();
            cout << node->getData() << " ";
            cont.pop();

            if (node->getRight() != nullptr)
                cont.push(node->getRight());
            if (node->getLeft() != nullptr)
                cont.push(node->getLeft());
        }
    }

    void PreorderTraversalRecursion(TreeNode* rootNode)
    {
        if (rootNode == nullptr)
            return;
        cout << rootNode->getData() << " ";
        PreorderTraversalRecursion(rootNode->getLeft());
        PreorderTraversalRecursion(rootNode->getRight());
    }

    void inorderTraversalIterative() {
        TreeNode* tempHead = head;
        stack<TreeNode*> cont;

        if (head == nullptr)
        {
            cout << mType << " Tree is empty" << endl;
            return;
        }


        if (tempHead != nullptr)
            cont.push(tempHead);

        cout << mType << " InOrder Traversal : " ;
        
        while(!cont.empty()){

            if (tempHead == nullptr)
            {
                TreeNode *node = cont.top();
                cout << node->getData() << " ";
                cont.pop();

                if (node->getRight() != nullptr)
                {
                    cont.push(node->getRight());
                    tempHead = node->getRight();
                }
            }
            else
            {
                tempHead = tempHead->getLeft();
                if (tempHead != nullptr)
                    cont.push(tempHead);
            }
        }
    }

    void InorderTraversalRecursion(TreeNode* rootNode)
    {
        if (rootNode == nullptr)
            return;
        InorderTraversalRecursion(rootNode->getLeft());
        cout << rootNode->getData() << " ";
        InorderTraversalRecursion(rootNode->getRight());
    }

    void postorderTraversalIterative() {
        TreeNode* tempHead = head;
        stack<TreeNode*> cont;
        unordered_set<TreeNode*> visitedNode;

        if (head == nullptr)
        {
            cout << mType << " Tree is empty" << endl;
            return;
        }
        cont.push(tempHead);
        cout << mType << " PostOrder Traversal : " ;
        while(!cont.empty()){
            TreeNode* node = cont.top();
            if (node->getRight() != nullptr && visitedNode.find(node->getRight()) == visitedNode.end())
                cont.push(node->getRight());
            else
            {
                if (node->getLeft() == nullptr)
                {
                    cout << node->getData() << " ";
                    visitedNode.insert(node);
                    cont.pop();
                }
            }

            if (node->getLeft() != nullptr)
            {
                if (visitedNode.find(node->getLeft()) == visitedNode.end())
                    cont.push(node->getLeft());
                else
                {
                    cout << node->getData() << " ";
                    visitedNode.insert(node);
                    cont.pop();
                }
            }
        }
    }

    void PostorderTraversalRecursion(TreeNode* rootNode)
    {
        if (rootNode == nullptr)
            return;
        PostorderTraversalRecursion(rootNode->getLeft());
        PostorderTraversalRecursion(rootNode->getRight());
        cout << rootNode->getData() << " ";
    }

    void levelOrderTraversalIterative()
    {
        queue<TreeNode*> cont;
        TreeNode* tempHead = head;

        cont.push(tempHead);
        while(!cont.empty())
        {
            TreeNode* node = cont.front();
            cont.pop();

            cout << node->getData() << " ";

            if (node->getLeft() != nullptr)
            {
                cont.push(node->getLeft());
            }

            if (node->getRight() != nullptr)
            {
                cont.push(node->getRight());
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder()
    {

        vector<vector<int>> output;
        if (head == nullptr)
            return output;
        TreeNode *temp = head;
        queue<TreeNode *> cont;
        bool left = true;
        cont.push(temp);
        int nodeLevelSize = 1;
        queue<TreeNode *> tempQueue;

        while (!cont.empty())
        {
            int size = cont.size();
            vector<int> vec;

            if (size == nodeLevelSize)
            {
                int validCount = 0;
                for (int index = 0; index < size; index++)
                {
                    if (cont.front() == nullptr)
                        continue;

                    if (cont.front()->getData() == INT_MAX)
                    {
                        cont.pop();
                        continue;
                    }
                    vec.push_back(cont.front()->getData());
                    tempQueue.push(cont.front());
                    cont.pop();
                    validCount++;
                }
                if (validCount == 0)
                    break;
                nodeLevelSize = (2 * validCount);
            }

            TreeNode *node = tempQueue.front();
            tempQueue.pop();

            if (node->getRight() != nullptr)
                cont.push(node->getRight());
            else
            {
                cont.push(new TreeNode(INT_MAX));
            }
            if (node->getLeft() != nullptr)
                cont.push(node->getLeft());
            else
            {
                cont.push(new TreeNode(INT_MAX));
            }

            if (vec.size() > 0)
            {
                if (left)
                {
                    reverse(vec.begin(), vec.end());
                    left = false;
                }
                else
                    left = true;

                output.push_back(vec);
            }
        }

        return output;
    }

    protected:
        TreeNode* head;
        string mType = "Unknown";
};

class BinaryTree : public TreeInterface
{
    public:
        BinaryTree(){}
        ~BinaryTree(){}

        virtual void insertData(int data) override {
            TreeNode *node = new TreeNode();
            node->setData(data);
            if (head == nullptr)
            {
                head = node;
            }
            else
            {
                TreeNode *placeToBeInsert = nullptr;
                TreeNode* tempHead = head;
                while (tempHead != nullptr)
                {
                    placeToBeInsert = tempHead;
                    if (tempHead->getLeft() == nullptr)
                    {
                        tempHead->setLeft(node);
                        break;
                    }
                    else if (tempHead->getRight() == nullptr)
                    {
                        tempHead->setRight(node);
                        break;
                    }
                    tempHead = tempHead->getLeft();
                }
            }
        }
};


class BinarySearchTree : public TreeInterface
{
    public:
        BinarySearchTree(){}
        ~BinarySearchTree(){}

        void insertData(int data) {
            TreeNode *node = new TreeNode();
            node->setData(data);
            if (head == nullptr)
            {
                head = node;
            }
            else
            {
                TreeNode *placeToBeInsert = nullptr;
                TreeNode* tempHead = head;
                while (tempHead != nullptr)
                {
                    placeToBeInsert = tempHead;
                    if (data > tempHead->getData())
                    {
                        tempHead = tempHead->getRight();
                    }
                    else
                    {
                        tempHead = tempHead->getLeft();
                    }
                }

                if (data > placeToBeInsert->getData())
                {
                    placeToBeInsert->setRight(node);
                }
                else{
                    placeToBeInsert->setLeft(node);
                }
            }
        }
};

class createContainers
{
    public:
    static shared_ptr<TreeInterface> createBinaryTree() {
        shared_ptr<TreeInterface> obj = make_shared<BinaryTree>();
        obj->setTreeType(treeType::TREE_BT);
        return obj;
    }
    static shared_ptr<TreeInterface> createBinarySearchTree() {
        shared_ptr<TreeInterface> obj = make_shared<BinarySearchTree>();
        obj->setTreeType(treeType::TREE_BST);
        return obj;
    }
};

class Solution {
public:
};


int main(int argc, char *argv[])
{
    shared_ptr<TreeInterface> treeContainer1 = createContainers::createBinarySearchTree();
    treeContainer1->insertData(60);
    treeContainer1->insertData(20);
    treeContainer1->insertData(70);
    treeContainer1->insertData(55);
    treeContainer1->insertData(15);

    treeContainer1->preorderTraversalIterative();
    cout << endl;
    cout << "Recursive Preorder Traversal in Recursion : ";
    treeContainer1->PreorderTraversalRecursion(treeContainer1->getHead());
    cout << endl;
    treeContainer1->inorderTraversalIterative();
    cout << endl;
    cout << "Recursive Inorder Traversal in Recursion : ";
    treeContainer1->InorderTraversalRecursion(treeContainer1->getHead());
    cout << endl;
    treeContainer1->postorderTraversalIterative();
    cout << endl;
    cout << "Recursive Postorder Traversal in Recursion : ";
    treeContainer1->PostorderTraversalRecursion(treeContainer1->getHead());
    cout << endl;



    shared_ptr<TreeInterface> treeContainer2 = createContainers::createBinaryTree();
    treeContainer2->insertData(60);
    treeContainer2->insertData(20);
    treeContainer2->insertData(70);
    treeContainer2->insertData(55);
    treeContainer2->insertData(15);

    treeContainer2->preorderTraversalIterative();
    cout << endl;
    cout << "Recursive Preorder Traversal in Recursion : ";
    treeContainer2->PreorderTraversalRecursion(treeContainer2->getHead());
    cout << endl;
    treeContainer2->inorderTraversalIterative();
    cout << endl;
    cout << "Recursive Inorder Traversal in Recursion : ";
    treeContainer2->InorderTraversalRecursion(treeContainer2->getHead());
    cout << endl;
    treeContainer2->postorderTraversalIterative();
    cout << endl;
    cout << "Recursive Postorder Traversal in Recursion : ";
    treeContainer2->PostorderTraversalRecursion(treeContainer2->getHead());
    cout << endl;
    cout << "Level Order traversal : ";
    treeContainer2->levelOrderTraversalIterative();
    cout << endl;
    vector<vector<int>> output = treeContainer2->zigzagLevelOrder();
    cout << "ZigZag Level Order : ";
    for (auto it1 = output.begin(); it1 != output.end(); it1++)
    {
        cout << "[ ";
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
