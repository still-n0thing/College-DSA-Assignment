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
    vector<int> arr;

    HashTable(int sz){
        n = sz;
        size = 0;;
        arr.assign(n, -1LL);
    }

    inline int h(int x){
        return (x % n);
    }

    int& operator[](int idx){
        // INCOMPLETE
        int y = n;
        int i = h(idx); 
        while(n > 0){

        }
    }
};

void solve(){
    
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