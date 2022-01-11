#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node * left;
    Node * right;

    
};

class BinaryTree {
private:
    Node * build(vector<int> in, vector<int> pre, int st, int ed, map<int,int> & mp){
        static int preidx = 0;
        if(st > ed) {
            return nullptr;
        }

        int curr = pre[preidx++];
        Node * temp = new_Node(curr);

        if(st == ed){
            return temp;
        }

        int inidx = mp[curr];

        temp->left = build(in, pre, st, inidx - 1, mp);
        temp->right = build(in, pre, inidx + 1, ed, mp);

        return temp;

    }

    void inorder(Node * ptr){
        if(ptr == nullptr){
            return;
        }
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }

    void preorder(Node * ptr){
        if(ptr == nullptr){
            return;
        }
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void postorder(Node * ptr){
        if(ptr == nullptr){
            return;
        }
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }

public:
    Node * root;
    int size;

    BinaryTree(vector<int> in, vector<int> pre, int n){
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[in[i]] = i;
        }

        root = build(in, pre, 0, n - 1, mp);
    }

    Node * new_Node(int x){
        Node * temp = new Node();
        temp->data = x;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
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

void solve(){
    vector<int> inOrder = {2,5,6,7,10,12,14,15,16};
    vector<int> preOrder = {10,5,2,6,7,14,12,15,16};
    
    BinaryTree bintree(inOrder, preOrder, inOrder.size());

    bintree.inorder();
    bintree.preorder();
    bintree.postorder();

}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}
