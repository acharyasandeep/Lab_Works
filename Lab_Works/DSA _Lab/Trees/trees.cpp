//this is a binary search tree
#include <iostream>
#include <ctime>
using namespace std;
template <typename T> class Tree;
template <typename T>
class Node{
    //three fields data left child and right child
    T data;
    Node<T>* left;
    Node<T>* right;
public:
    Node<T>(T value):left(nullptr),right(nullptr),data(value){}
    friend class Tree<T>;
};
template <typename T>
class Tree{
    Node<T>* root; //root indicates the root node of the binary search tree
    int leafCount; //denotes the no of leaf nodes
public:
    Tree<T>():root(nullptr){}
    //check if the tree is empty
    bool isEmpty();
    //helper function to inserts node in a tree
    //it is created because we can pass root node to this function using wrapper function for inserting node
    //this wrapper function and helper function concept is expanded to every other function that needs the access to root node
    void insertNodeHelper(Node<T>* &curr,T value);
    //wrapper function for inserting a new node
    void insertNode(T value);
    //helper function for searching key in BST
    bool searchNodeHelper(Node<T>* &curr,T value);
    //wrapper function for searching key in BST
    bool searchNode(T value);
    //finds minimum key in tree
    Node<T>* findMinimum(Node<T>* &curr);
    //delete node helper function
    void deleteNodeHelper(Node<T>* &curr,T value);
    //delete node wrapper function
    void deleteNode(T value);
    //helper function to find the height of node
    int heightHelper(Node<T>* &curr);
    //find height of BST
    int height();
    //finds the no of Nodes in BST helper function
    int noOfNodesHelper(Node<T>* &curr);

    int noOfNodes();
    //tree traversals
    //in order traversal of BST gives sorted data
    void inorderTraversalHelper(Node<T>* &curr);
    void inorderTraversal();
    void preorderTraversalHelper(Node<T>* &curr);
    void preorderTraversal();
    void postorderTraversalHelper(Node<T>* &curr);
    void postorderTraversal();

    //find no of leaf Nodes
    void noOfLeafNodesHelper(Node<T>* &curr);
    int noOfLeafNodes();

};
template <typename T>
bool Tree<T>::isEmpty()
{
    //if root pointer of tree is null it's empty
    return root == nullptr;
}
template <typename T>
void Tree<T>::insertNodeHelper(Node<T>* &curr ,T value)
{
    //if the root is null then insert node directly in the tree
    if(curr == nullptr)
    {
        Node<T> *newNode = new Node<T>(value);
        curr = newNode;
        cout<<value<<" inserted into the tree."<<endl;
        return;
    }
    else
    {
        //ignore the duplicate data
        if(value == curr->data)
        {
            cout<<value<<" ignored. Duplicate data"<<endl;
            return;
        }
        //if the value is greater than node data insert it in right sub tree
        else if(value > curr->data)
            insertNodeHelper(curr->right,value);
        //if value is lesser than node data insert it in the left sub tree
        else
            insertNodeHelper(curr->left,value);
    }
}
template <typename T>
void Tree<T>::insertNode(T value)
{
    //passing root node to helper function from the wrapper function
    insertNodeHelper(root,value);
}
template <typename T>
bool Tree<T>::searchNodeHelper(Node<T>* &curr,T value)
{
    if(curr == nullptr)
        return false;
    else if(value == curr->data)
            return true;
    else if(value > curr->data)
        return searchNode(curr->right,value);
    else
        return searchNode(curr->left,value);

}
template <typename T>
bool Tree<T>::searchNode(T value)
{
    return searchNodeHelper(root, value);
}
template <typename T>
Node<T>* Tree<T>::findMinimum(Node<T>* &curr)
{
    //minimum is found in the leftmost child of the tree
    if(curr->left == nullptr)
        return curr;
    else
        return findMinimum(curr->left);
}
template <typename T>
void Tree<T>::deleteNodeHelper(Node<T>* &curr, T value)
{
    if(curr == nullptr)
    {
        cout<<value<<" is not found in this tree. Delete operation failed"<<endl;
        return;
    }
    else if(value > curr->data)
        deleteNodeHelper(curr->right, value);
    else if(value < curr->data)
        deleteNodeHelper(curr->left, value);
    else if(value==curr->data)
    {
        //value is found so,
        //if it has no child just delete noda and return
        if((curr->left == nullptr) && (curr->right == nullptr))
        {
            cout<<value<<"1. deleted from the tree."<<endl;
            delete curr;
            curr=nullptr;
            return;
        }
        else if(curr->right == nullptr)
        {
            //if it has left sub tree than link the parent node of the node to be deleted with its left child
            cout<<value<<"2. deleted from the tree."<<endl;
            Node<T>* temp = curr;
            curr=curr->left;
            temp->left = temp->right = nullptr;
            delete temp;
        }
        else if(curr->left == nullptr)
        {
            //if it has right sub tree than link the parent node of the node to be deleted with its right child
            cout<<value<<"3. deleted from the tree."<<endl;
            Node<T>* temp = curr;
            curr=curr->right;
            temp->left = temp->right = nullptr;
            delete temp;
        }
        else
        {
            //if it has both childs, find minimum key in the right sub tree
            Node<T>* temp = findMinimum(curr->right);
            //replace the value of node to be deleted with the minimum node found
            curr->data = temp->data;
            //delete that minimum node we found earlier
            deleteNodeHelper(curr->right,temp->data);
        }
    }
}
template <typename T>
void Tree<T>::deleteNode(T value)
{
    deleteNodeHelper(root,value);
}
template <typename T>
int Tree<T>::heightHelper(Node<T>* &curr)
{
    int height = 0;
    if(curr == nullptr)
        return height;
    else
    {
        int leftHeight = heightHelper(curr->left)+1;
        int rightHeight =  heightHelper(curr->right)+1;
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }
}
template <typename T>
int Tree<T>::height()
{
    return heightHelper(root);
}
template <typename T>
int Tree<T>::noOfNodesHelper(Node<T>* &curr)
{
    if(curr == nullptr)
        return 0;
    else
    {
        int leftNodes = noOfNodesHelper(curr->left);
        int rightNodes = noOfNodesHelper(curr->right);
        return leftNodes + rightNodes + 1;
    }
}
template<typename T>
int Tree<T>::noOfNodes()
{
    return noOfNodesHelper(root);
}

template<typename T>
void Tree<T>::noOfLeafNodesHelper(Node<T>* & curr)
{
    if(curr == nullptr)
        return;
    else if(curr->left == nullptr && curr->right == nullptr)
    {
        //if the node don't have both childs increase the leaf count,very simple logic
        leafCount++;
        return;
    }
    else
    {
        noOfLeafNodesHelper(curr->left);
        noOfLeafNodesHelper(curr->right);
    }
}

template <typename T>
int Tree<T>::noOfLeafNodes()
{
    leafCount = 0;
    noOfLeafNodesHelper(root);
    return leafCount;
}

template <typename T>
void Tree<T>::inorderTraversalHelper(Node<T>* &curr)
{
    if(curr == nullptr)
        return;
    else
    {
        inorderTraversalHelper(curr->left);
        cout<<curr->data<<" ";
        inorderTraversalHelper(curr->right);
    }
}
template <typename T>
void Tree<T>::inorderTraversal()
{
    inorderTraversalHelper(root);
    cout<<endl;
}

template <typename T>
void Tree<T>::preorderTraversalHelper(Node<T>* &curr)
{
    if(curr == nullptr)
        return;
    else
    {
        cout<<curr->data<<" ";
        preorderTraversalHelper(curr->left);
        preorderTraversalHelper(curr->right);
    }
}
template <typename T>
void Tree<T>::preorderTraversal()
{
    preorderTraversalHelper(root);
    cout<<endl;
}

template <typename T>
void Tree<T>::postorderTraversalHelper(Node<T>* &curr)
{
    if(curr == nullptr)
        return;
    else
    {
        postorderTraversalHelper(curr->left);
        postorderTraversalHelper(curr->right);
        cout<<curr->data<<" ";
    }
}
template <typename T>
void Tree<T>::postorderTraversal()
{
    postorderTraversalHelper(root);
    cout<<endl;
}


int main()
{

    srand(time(NULL));
    Tree<int> binTree;

//    for(int i=0;i<10;i++)
//    {
//        binTree.insertNode(50+rand()%100);
//    }
//    binTree.insertNode(30);
//    binTree.displayTree();
//    binTree.deleteNode(30);


    int arr[]={45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
        binTree.insertNode(arr[i]);

    cout<<"Inorder Traversal"<<endl;
    binTree.inorderTraversal();

    cout<<endl<<"Preorder Traversal"<<endl;
    binTree.preorderTraversal();

    cout<<endl<<"Postorder Traversal:"<<endl;
    binTree.postorderTraversal();

    cout<<endl;

    cout<<"Height of Tree: "<<binTree.height()<<endl;
    cout<<"No of Nodes in a Tree: "<<binTree.noOfNodes()<<endl;
    cout<<"No of leaf Nodes in a Tree: "<<binTree.noOfLeafNodes()<<endl;
    return 0;
}
