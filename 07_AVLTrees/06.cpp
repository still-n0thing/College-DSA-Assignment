#include <bits/stdc++.h>

using namespace std;

class BinTree {
public:
    vector<int> tree;
    int size;

    BinTree(int height, vector<int> a){
        size = (1<<height);
        tree = vector<int>(2*size, -1);

        for(int i = 0; i < a.size(); i++){
            tree[i] = a[i];
        } 
        
    }

    int find(int val){
        for(int i = 0; i <tree.size(); i++){
            if(tree[i] == val){
                return i;
            }
        }
        return -1;
    }

    void findGPandP(int val){
        int idx = find(val);
        int pidx = (idx-1)/2;
        int gpidx = (pidx-1)/2;
        if(idx >= 0){
            cout << "node : " << tree[idx] << "\n";
        }
        if(pidx >= 0){
            cout << "parent : " << tree[pidx] << "\n";
        }
        if(gpidx >= 0){
            cout << "grandparent : " << tree[gpidx] << "\n";
        }
    }

    void inorder(){
        cout << "inorder : ";
        inorder(0);
        cout << "\n";
    }

    void inorder(int x){
        if(x >= tree.size()) return;
        else if(tree[x] != -1){
            inorder(2 * x + 1);
            cout << tree[x] << " ";
            inorder(2 * x + 2);
        }
    }
    
    void preorder(){
        cout << "preorder : ";
        preorder(0);
        cout << "\n";
    }

    void preorder(int x){
        if(x >= tree.size()) return;
        else if(tree[x] != -1){
            cout << tree[x] << " ";
            preorder(2 * x + 1);
            preorder(2 * x + 2);
        }
    }

    void postorder(){
        cout << "postorder : ";
        postorder(0);
        cout << "\n";
    }

    void postorder(int x){
        if(x >= tree.size()) return;
        else if(tree[x] != -1){
            postorder(2 * x + 1);
            postorder(2 * x + 2);
            cout << tree[x] << " ";
        }
    }
};

void solve(){
    vector<int> a = {
        1, 2, 7, 3, 5, 8, 9, 4, -1, -1, 6, -1, -1, 10, -1
    };

    BinTree bintree(3, a);

    bintree.inorder();
    bintree.preorder();
    bintree.postorder();

    cout << "\n";    
    bintree.findGPandP(8);
}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}