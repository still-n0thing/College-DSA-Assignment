#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

vector<long long> arr(100005);

void solve(){
    long long n; cin >> n;
    vector<long long> a(n);

    for(long long i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    stack<pair<long long, long long>> s;
    long long ans = 0;
    for(long long i = n-1 ; i >= 0 ; i--){
        while(!s.empty()){
            long long temp = s.top().first;
            long long index = s.top().second;
            if(temp > a[i]){
                arr[i] = max({arr[i] + 1, arr[index]});
                ans = max({ans, arr[i]});
                s.pop();
            } else {
                break;
            }
        }
        s.push(make_pair(a[i], i));
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    

    // long long T; cin >> T; while(T--)
    solve();
    return 0;
}