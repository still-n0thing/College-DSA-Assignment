#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

inline bool match(char x, char y){
    return (x == '(' and y == ')') or (x == '[' and y == ']') or (x == '{' and y == '}');
}

void solve(){
    string s; cin >> s;
    const long long n = s.length();
    stack<char> st;
    for(long long i = 0; i < n; i++){
        // cerr << s[i] << "\n";
        if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
            st.push(s[i]);
        } else {
            if(st.size() == 0 or !match(st.top(), s[i])){
                cout << "NO\n";
                // cerr << "top = " << st.top() << "\n";
                return;
            } else {
                st.pop();
            } 
        }
    }
    if(st.size() > 0){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    // cerr << "\n\n";
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