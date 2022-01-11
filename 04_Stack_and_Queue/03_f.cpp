#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << x; cerr<<endl;

void solve(){
    string s; cin >> s;
    long long n = s.length();

    stack<long long> st;
    long long cnt = 0, ans = 0;

    for(long long i = 0; i < n; i++){
        if(s[i] == '<'){
            st.push(i);
            cnt++;
        } else if (st.size() > 0) {
            st.pop();
            cnt++;
            if(st.size() == 0){
                ans = max({cnt, ans});
            }
        } else {
            break;
        }
    }
    cout << ans << "\n";
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
