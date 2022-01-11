#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node * left;
    Node * right;

    Node(){
        data = -1;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    void insert(Node * ptr, int element){
        if(element < ptr->data){
            if(ptr->left == nullptr){
                Node * some = new Node();
                some->data = element;
                ptr->left = some;
                return;
            } else {
                insert(ptr->left, element);
            }
        } else {
            if(ptr->right == nullptr){
                Node * some = new Node();
                some->data = element;
                ptr->right = some;
                return;
            } else {
                insert(ptr->right, element);
            }
        }
    }

    void inorder(Node * ptr){
        if(ptr != nullptr){
            inorder(ptr->left);
            cout << ptr->data << " ";
            inorder(ptr->right);
        }
    }

    void preorder(Node * ptr){
        if(ptr != nullptr){
            cout << ptr->data << " ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(Node * ptr){
        if(ptr != nullptr){
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->data << " ";
        }
    }
public:
    Node * root;
    int size;

    BST(){
        root = nullptr;
        size = 0;
    }

    void insert(int element){
        if(root == nullptr){
            Node * some = new Node();
            some->data = element;
            root = some;
        } else {
            insert(root, element);
        }
    }

    void inorder(){
        cout << "inorder : ";
        inorder(root);
        cout << "\n";
    }

    void preorder(){
        cout << "preorder : ";
        preorder(root);
        cout << "\n";
    }

    void postorder(){
        cout << "postorder : ";
        postorder(root);
        cout << "\n";
    }
};

int main(int argc, const char * argv[]){
    const int n = 8;
    int a[n] = {8, 3, 1, 6, 4, 7, 10, 14};
    BST bst;
    for(int i = 0; i < n; i++){
        bst.insert(a[i]);
    }
    bst.inorder();
    bst.preorder();
    bst.postorder();
    return 0;
}