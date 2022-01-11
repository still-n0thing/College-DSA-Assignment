#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    long long data;
    Node * left, * right;

    Node(long long data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node * root;
    vector<long long> in, post, pre;
    long long n;

    BinaryTree(const vector<long long> & in, const vector<long long> & post, long long n){
        this->root = nullptr;
        this->in = in;
        this->post = post;
        this->n = n;
    }

    void build(){
        stack<Node *> st;
        set<Node *> s;

        long long postIndex = n-1;

        for(long long p = n - 1, i = n - 1; p >= 0;){
            Node * node = nullptr;

            do {
                node = new Node(post[p]);
                if(root == nullptr){
                    root = node;
                }

                if(st.size() > 0){
                    if(s.find(st.top()) != s.end()){
                        s.erase(st.top());
                        st.top()->left = node;
                        st.pop();
                    } else {
                        st.top()->right = node;
                    }
                }

                st.push(node);
            } while(post[p--] != in[i] and p >= 0);

            node = nullptr;

            while(st.size() > 0 and i >= 0 and st.top()->data == in[i]){
                node = st.top();
                st.pop();
                i--;
            }

            if(node != nullptr){
                s.insert(node);
                st.push(node);
            }
        }
    }

    void pre_order(Node * node){
        if(node == nullptr){
            return;
        }
        cout << ((char)node->data) << " ";
        pre_order(node->left);
        pre_order(node->right);
    }

    void pre_order(){
        cout << "preorder : ";
        pre_order(root);
        cout << "\n";
    }

    void post_order(Node * node){
        if(node == nullptr){
            return;
        }
        post_order(node->left);
        post_order(node->right);
        cout << ((char)node->data) << " ";
    }

    void post_order(){
        cout << "postorder : ";
        post_order(root);
        cout << "\n";
    }

    void in_order(Node * node){
        if(node == nullptr){
            return;
        }
        in_order(node->left);
        cout << ((char)node->data) << " ";
        in_order(node->right);
    }

    void in_order(){
        cout << "inorder : ";
        in_order(root);
        cout << "\n";
    }

    void print(const std::string& prefix, const Node* node, bool isLeft){
        if(node != nullptr){
            cout << prefix;
            cout << (isLeft ? "├──" : "└──" );
            cout << (char)node->data << std::endl;
            print( prefix + (isLeft ? "│   " : "    "), node->left, true);
            print( prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }

    void print(){
        print("", root, false);    
    }

};

void solve(){
    long long n; cin >> n;
    vector<long long> in(n), post(n);
    for(auto & i : in){
        char c; cin >> c;
        i = (long long)c;
    }
    for(auto & i : post){
        char c; cin >> c;
        i = (long long)c;
    }
    BinaryTree bt(in, post, n);
    bt.build();
    bt.in_order();
    bt.post_order();
    bt.pre_order(); 
    bt.print();
}

int main(int argc, char const ** argv){
    long long T; cin >> T;
    for(long long i = 1; i <= T; i++){
        solve();
    }    
    return 0;
}