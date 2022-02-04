#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif

// Max Heap
class Heap {
public:
    int size;
    vector<int> tree;

    Heap(int n){
        size = 0;
        tree.assign(n, 0LL);
    }

    void insert(int v){
        if(size == (int)tree.size()){
            cerr << "Heap is full\n";
            return;
        }
        int x = size;
        tree[x] = v;
        while((x - 1) / 2 >= 0 and tree[x] > tree[(x - 1) / 2]){
            swap(tree[x], tree[(x - 1) / 2]);
            x = (x - 1) / 2;
        }
        size++;
    }

    int pop(){
        if(size == 0){
            cerr << "Heap is empty\n";
            return INT32_MAX;
        }
        
        int res = tree[0];
        size--;

        if(size == 0){
            tree[size] = 0;
            return res;
        }

        tree[0] = tree[size];
        tree[size] = 0;
        int x = 0, len = (int)tree.size();
        while((2 * x + 1 < len and tree[x] < tree[2 * x + 1]) or (2 * x + 2 < len and tree[x] < tree[2 * x + 2])){
            if(tree[x] <= tree[2 * x + 1] and (2 * x + 2 < len and tree[2 * x + 1] >= tree[2 * x + 2])){
                swap(tree[x], tree[2 * x + 1]);
                x = 2 * x + 1;
            } else if(tree[x] <= tree[2 * x + 2]){
                swap(tree[x], tree[2 * x + 2]);
                x = 2 * x + 2;
            }
        }

        return res;
    }

    bool empty(){
        return (size == 0);
    }

};

void solve(){
    int n = 8;
    vector<int> a = {
        45, 36, 54, 27, 63, 72, 61, 18
    };

    Heap hp(n);
    cout << "heap values : ";
    for(const auto & i : a){
        hp.insert(i);
        cout << i << " ";
    } cout << "\n";

    dbg(hp.tree);

    while(!hp.empty()){
        cout << "Top : " << hp.pop() << "\n";
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int T = 1;
    // cin >> T; 
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}