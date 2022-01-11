#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

// Recursive Method
void reverse(stack<long long> & st, stack<long long> & ans){
    if(st.size() > 0){
        // cout << st.top() << " ";
        ans.push(st.top());
        st.pop();
        reverse(st, ans);
    }
}

void display(stack<long long> s){
    long long cnt = 0;
    while(s.size() > 0){
        if(cnt == 0){
            cout << "[top->" << s.top() << "] ";
            s.pop();
        } else {
            cout << "[" << s.top() << "] ";
            s.pop();
        }
        cnt++;
    }
    cout << "\n";
}

void solve(){
    long long n; cin >> n;
    stack<long long> st, ans;
    for(long long i = 0; i < n; i++){
        long long x; cin >> x;
        st.push(x);
    }

    cout << "INPUT STACK  : "; display(st); 
    reverse(st, ans); st = ans;
    cout << "OUTPUT STACK : "; display(st);
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    

    long long T; cin >> T; while(T--)
    solve();
    return 0;
}
