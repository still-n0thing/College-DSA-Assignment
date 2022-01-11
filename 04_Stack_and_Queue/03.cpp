#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << x; cerr<<endl;

void solve(){
    string s; cin >> s;
    long long n = s.length();
    stack<long long> st;
    long long cnt = 0;
    long long a = 0, b = 0;

    for(long long i = 0; i < n; i++){
        if(s[i] == '<') a++;
        else b++;
    }
    
    if(a != b){
        cout << "0\n";
        return;
    }

    for(long long i = 0; i < n; i++){
        if(s[i] == '<'){
            st.push(i);
        } else if (st.size() > 0) {
            long long idx = st.top();
            st.pop();
            cnt = max({cnt, i - idx + 1});
        } else {
            break;
        }
    }
    cout << cnt << "\n";
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
