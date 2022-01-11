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
    Node * build(vector<int> in, vector<int> post, int st, int ed, int & idx, map<int,int> & mp){
        if(st > ed){
            return nullptr;
        }

        int curr = post[idx];
        Node * temp = new_Node(curr);
        idx--;

        if(st == ed){
            return temp;
        }

        int iidx = mp[curr];
        
        temp->right = build(in, post, iidx + 1, ed, idx, mp);
        temp->left = build(in, post, st, iidx - 1, idx, mp);

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

    BinaryTree(vector<int> in, vector<int> post, int n){
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[in[i]] = i;
        }
        int idx = n - 1;

        root = build(in, post, 0, n - 1, idx, mp);
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
    vector<int> inOrder = {9,4,18,6,8,2,11,14,12};
    vector<int> postOrder = {4,9,6,18,2,14,12,11,8};

    BinaryTree bintree(inOrder, postOrder, inOrder.size());

    bintree.inorder();
    bintree.postorder();
    bintree.preorder();

}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}
