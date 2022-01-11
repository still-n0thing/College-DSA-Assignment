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
                size++;
                return;
            } else {
                insert(ptr->left, element);
            }
        } else {
            if(ptr->right == nullptr){
                Node * some = new Node();
                some->data = element;
                ptr->right = some;
                size++;
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
            size++;
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

    void del(int element){
        if(root == nullptr){
            cout << "Cannot find the element\n";
        } else {
            root = del(root, element);
        }
    }

    Node * find_min(Node * ptr){
        while(ptr->left != nullptr) ptr = ptr->left;
        return ptr;
    }

    Node * del(Node * ptr, int data) {
        if(ptr == nullptr) return ptr; 
        else if(data < ptr->data) ptr->left = del(ptr->left, data);
        else if (data > ptr->data) ptr->right = del(ptr->right, data);	
        else {
            // Case 1:  No child
            if(ptr->left == nullptr && ptr->right == nullptr) { 
                delete ptr;
                ptr = nullptr;
            }
            //Case 2: One child 
            else if(ptr->left == nullptr) {
                Node * temp = ptr;
                ptr = ptr->right;
                delete temp;
            }
            else if(ptr->right == nullptr) {
                Node * temp = ptr;
                ptr = ptr->left;
                delete temp;
            }
            // case 3: 2 children
            else { 
                Node * temp = find_min(ptr->right);
                ptr->data = temp->data;
                ptr->right = del(ptr->right,temp->data);
            }
        }
        return ptr;
    }
};

int main(int argc, const char * argv[]){
    const int n = 8;
    int a[n] = {8, 3, 1, 6, 4, 7, 10, 14};
    BST bst;
    for(int i = 0; i < n; i++){
        bst.insert(a[i]);
    }
    int b[] = {14, 3, 8};
    for(int i = 0; i < 3; i++){
        bst.del(b[i]);
        bst.inorder();
        bst.preorder();
        bst.postorder();
        cout << "\n";
    }
    return 0;
}