#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    stack<int> S, T;
    deque<int> D;

    cout << "S : ";

    while(n--){
        int temp; cin >> temp;
        S.push(temp);    
    }

    cout << "T : ";

    while(m--){
        int temp; cin >> temp;
        T.push(temp);
    }

    while(!T.empty()){
        D.push_front(T.top());
        T.pop();
    }

    while(!S.empty()){
        D.push_front(S.top());
        S.pop();
    }

    // vector<int> a;

    while(!D.empty()){
        // a.push_back(D.back());
        S.push(D.back());
        D.pop_back();
    }

    // reverse(a.begin(), a.end());
    cout << "\nAfter operations : \n";
    cout << "S : ";
    
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
    cout << "\n";
}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}