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

class HashTable {
public:
    int size, n;
    vector<int> table;

    HashTable(int sz){
        n = sz;
        size = 0;;
        table.assign(n, -1LL);
    }

    inline int h(int x){
        return (x % n);
    }

    void insert(int key){
        int val = h(key);
        int lp = n;
        while(lp--){
            if(table[val] == -1){
                table[val] = key;
                size++;
                return;
            }
            val = (val + 1) % n;
        }
        cerr << "table is full\n";
    }

    int get(int key){
        int val = h(key);
        int lp = n;
        while(lp--){
            if(table[val] == key){
                return val;
            }
            val = (val + 1) % n;
        }
        cerr << "value not in table\n";
        return INT32_MAX;
    }
};

void solve(){
    vector<int> a = {
        1234, 6236, 9123, 2326, 3214, 4355
    };
    HashTable ht(10);
    for(auto & i : a){
        ht.insert(i);
    }
    for(auto & i : a){
        cout << "value = [" << i << "] : index = [" << ht.get(i) << "]\n"; 
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T; 
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}