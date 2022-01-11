#include<bits/stdc++.h>

using namespace std;
 
class Node{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};


class AVLTree {    
private:
    int height(Node *N){
        if (N == nullptr)
            return 0;
        return N->height;
    }

    Node* newNode(int key){
        Node* node = new Node();
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1; 
        return(node);
    }

    Node *rightRotate(Node *y){
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;
        return x;
    }
    
    Node *leftRotate(Node *x){
        Node *y = x->right;
        Node *T2 = y->left;
    
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        return y;
    }
    
    int getBalance(Node *N){
        if (N == nullptr)
            return 0;
        return height(N->left) -
            height(N->right);
    }
    
    Node* insert(Node* node, int key){
        if (node == nullptr)
            return(newNode(key));
    
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else 
            return node;
    
        
        node->height = 1 + max(height(node->left),
                            height(node->right));
    
        
        int balance = getBalance(node);
    
    
        // Left Left Case
        if (balance > 1 and key < node->left->key)
            return rightRotate(node);
    
        // Right Right Case
        if (balance < -1 and key > node->right->key)
            return leftRotate(node);
    
        // Left Right Case
        if (balance > 1 and key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    
        // Right Left Case
        if (balance < -1 and key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    
        /* return the (unchanged) node pointer */
        return node;
    }
    
    Node * minValueNode(Node* node){
        Node* current = node;
    
        /* loop down to find the leftmost leaf */
        while (current->left != nullptr)
            current = current->left;
    
        return current;
    }
    
    Node* deleteNode(Node* root, int key){
        if (root == nullptr)
            return root;
    
        if ( key < root->key )
            root->left = deleteNode(root->left, key);
        else if( key > root->key )
            root->right = deleteNode(root->right, key);
        else
        {
            if( (root->left == nullptr) or
                (root->right == nullptr) )
            {
                Node *temp = root->left ?
                            root->left :
                            root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else 
                *root = *temp; 
                free(temp);
            }
            else
            {
                
                Node* temp = minValueNode(root->right);
    
                root->key = temp->key;
    
                root->right = deleteNode(root->right,
                                        temp->key);
            }
        }
    
        if (root == nullptr)
        return root;
    
        root->height = 1 + max(height(root->left),
                            height(root->right));
    
        int balance = getBalance(root);
    
        // Left Left Case
        if (balance > 1 and
            getBalance(root->left) >= 0)
            return rightRotate(root);
    
        // Left Right Case
        if (balance > 1 and
            getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    
        // Right Right Case
        if (balance < -1 and
            getBalance(root->right) <= 0)
            return leftRotate(root);
    
        // Right Left Case
        if (balance < -1 and
            getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    
        return root;
    }
    
    void preOrder(Node *root){
        if(root != nullptr)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(Node *root){
        if(root != nullptr)
        {
            preOrder(root->left);
            cout << root->key << " ";
            preOrder(root->right);
        }
    }

    void postOrder(Node *root){
        if(root != nullptr)
        {
            preOrder(root->left);
            preOrder(root->right);
            cout << root->key << " ";
        }
    }

    Node * findP(Node * t, int x){
        if(t == nullptr){
            return nullptr;
        } else if(t->key == x){
            return nullptr;
        } else if(x < t->key){
            if(x == t->left->key) return t;
            else return findP(t->left, x);
        } else {
            if(x == t->right->key) return t;
            else return findP(t->right, x);
        }
    }
public:
    Node * ptr;

    AVLTree(){
        ptr = nullptr;
    }

    void insert(int x){
        ptr = insert(ptr, x);
    }

    void remove(int x){
        ptr = deleteNode(ptr, x);
    }

    void inOrder(){
        cout << "inorder : ";
        inOrder(ptr);
        cout << "\n";
    }

    void preOrder(){
        cout << "preorder : ";
        preOrder(ptr);
        cout << "\n";
    }

    void postOrder(){
        cout << "postorder : ";
        postOrder(ptr);
        cout << "\n";
    }

    void findGPandP(int x){
        cout << "node : " << x << "\n";
        Node * p = findP(ptr, x);
        Node * gp = nullptr;
        if(p != nullptr){
            gp = findP(ptr, p->key);
            cout << "parent : " << p->key << "\n";
        }
        if(gp != nullptr){
            cout << "grandparent : " << gp->key << "\n";
        }

    }
};

int main(int argc, char const *argv[]){
    vector<int> a = {
        1, 2, 7, 3, 5, 8, 9, 4, 6, 10
    };
    AVLTree avl;
    for(const auto & i : a){
        avl.insert(i);
    }
    avl.inOrder();
    avl.preOrder();
    avl.postOrder();
    cout << "\n";
    
    avl.findGPandP(10);
    return 0;
}
