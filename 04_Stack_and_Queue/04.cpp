#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

void solve(){
    string s; cin >> s;
    long long n = s.length();
    stack<long long> st;
    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        if(cnt == 0 and s[i] == '0'){
            cout << "NO\n";
            return;
        } else if (s[i] == '*') {
            if(cnt == 0){
                st.push(i);
                cnt = 2;
            } else{
                cnt = 2;
            }
        } else if (s[i] == '0') {
            cnt--;
            if(st.size() > 0) st.pop();
        }
    }
    cout << "YES\n";
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