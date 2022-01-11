#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

void solve(){
    long long n; cin >> n;
    long long alive = n;
    vector<long long> a(n);
    vector<bool> dead(n, false);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long days = 0;
    while(alive > 1){
        long long cur = LLONG_MAX;
        long long cnt = 0;
        for(long long i = 0; i < n; i++){
            if(dead[i] == false and a[i] > cur){
                dead[i] = true;
                cnt++;
                cur = a[i];
            } else if(dead[i] == false){
                cur = a[i];
            }
        }
        alive -= cnt;
        if(cnt == 0) break;
        days++;
    }
    cout << days << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    

    // long long T; cin >> T; while(T--)
    solve();
    return 0;
}