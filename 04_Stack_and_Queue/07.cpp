#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

void solve(){
    long long n1, n2, n3; cin >> n1 >> n2 >> n3;
    
    vector<long long> a(n1);
    stack<long long> s1, s2, s3;
    long long h1 = 0, h2 = 0, h3 = 0;
    
    for(long long i = 0; i < n1; i++){
        cin >> a[i];
        h1 += a[i];
    }
    reverse(a.begin(), a.end());
    for(auto i : a){
        s1.push(i);
    }

    a = vector<long long>(n2);
    for(long long i = 0; i < n2; i++){
        cin >> a[i];
        h2 += a[i];
    }
    reverse(a.begin(), a.end());
    for(auto i : a){
        s2.push(i);
    }

    a = vector<long long>(n3);
    for(long long i = 0; i < n3; i++){
        cin >> a[i];
        h3 += a[i];
    }
    reverse(a.begin(), a.end());
    for(auto i : a){
        s3.push(i);
    }

    // cerr << "h1 = " << h1 << "\n"; 
    // cerr << "h2 = " << h2 << "\n";
    // cerr << "h3 = " << h3 << "\n";

    while(h1 != h2 or h2 != h3 or h3 != h2){
        vector<pair<long long, long long>> some = {
            {h1, 1}, {h2, 2}, {h3, 3}
        };
        sort(some.begin(), some.end());
        // reverse(a.begin(), a.end());
        // cerr << "h1 = " << h1 << "\n"; 
        // cerr << "h2 = " << h2 << "\n";
        // cerr << "h3 = " << h3 << "\n";
        // for(auto i : some){
        //     cerr << "F = " << i.first << " S = " << i.second << "\n";
        // }

        const long long t = some.size() - 1;

        // cerr << "some  = " << some[0].second << "\n";

        if(some[t].second == 1){
            h1 -= s1.top(); 
            s1.pop();
        } else if(some[t].second == 2){
            h2 -= s2.top();
            s2.pop();
        } else {
            h3 -= s3.top();
            s3.pop();
        }
    }

    // cerr << h1 << " " << h2 << " " << h3;
    cout << (h1 == h2 and h2 == h3 and h3 == h1 ? h1 : 0) << "\n";
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