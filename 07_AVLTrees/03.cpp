#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    char data;
    Node * left;
    Node * right;

    Node(){
        data = -1;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node * newNode(char c){
        Node * temp = new Node;
        temp->data = c;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    void inorder(Node * ptr){
        if(ptr == nullptr){
            return;
        }
        inorder(ptr->left);
        cout << ptr->data;
        inorder(ptr->right);
    }

    void preorder(Node * ptr){
        if(ptr == nullptr){
            return;
        }
        cout << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void postorder(Node * ptr){
        if(ptr == nullptr){
            return;
        }
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data;
    }

public:
    Node * root;

    BinaryTree(string & s){
        stack<Node *> stN;    
        stack<char> stC;
        Node * t, * t1, * t2;
    
        map<char, int> p;
        p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
        p[')'] = 0;
    
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') {
    
                stC.push(s[i]);
            }
    
            else if (isalpha(s[i]))
            {
                t = newNode(s[i]);
                stN.push(t);
            }
            else if (p[s[i]] > 0)
            {
                while (
                    !stC.empty() && stC.top() != '('
                    && ((s[i] != '^' && p[stC.top()] >= p[s[i]])
                        || (s[i] == '^'
                            && p[stC.top()] > p[s[i]])))
                {
    
                    t = newNode(stC.top());
                    stC.pop();
    
                    t1 = stN.top();
                    stN.pop();
    
                    t2 = stN.top();
                    stN.pop();
    
                    t->left = t2;
                    t->right = t1;
    
                    stN.push(t);
                }
    
                stC.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!stC.empty() && stC.top() != '(')
                {
                    t = newNode(stC.top());
                    stC.pop();
                    t1 = stN.top();
                    stN.pop();
                    t2 = stN.top();
                    stN.pop();
                    t->left = t2;
                    t->right = t1;
                    stN.push(t);
                }
                stC.pop();
            }
        }
        root = stN.top();
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
    string expression = "A*B+C/(D-E+F)-(G*H^I)+J";
    expression = '(' + expression + ')';
    BinaryTree bintree(expression);

    bintree.inorder();
    bintree.preorder();
    bintree.postorder();
}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}
