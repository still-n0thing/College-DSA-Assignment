#include <bits/stdc++.h>

using namespace std;

long long eval(string infix){
    stack<long long> st;
    long long n = infix.size();

    for(long long i = 0; i < n; i++){
        if(isdigit(infix[i])){
            st.push((long long)(infix[i] - '0'));
        } else {
            long long val1 = st.top(); st.pop();
            long long val2 = st.top(); st.pop();

            switch(infix[i]){
                case '+':
                    st.push(val2 + val1);
                    break;
                case '-':
                    st.push(val2 - val1);
                    break;
                case '*':
                    st.push(val2 * val1);
                    break;
                case '/':
                    st.push(val2 / val1);
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}

void solve(){
    string s; cin >> s;
    long long q; cin >> q;
    vector<pair<string, string>> avec;
    while(q--){
        string f, s, t; cin >> f >> s >> t;
        avec.push_back({f, t});
    }

    for(auto & [x, y] : avec){
        s = regex_replace(s, regex(x), y);
    }

    cout << "postfix : " << s << "\n";
    cout << "evaluation : " << eval(s) << "\n";
}   

int main(int argc, const char ** argv){
    long long T; cin >> T;
    for(long long i = 1; i <= T; i++){
        solve();
    }
    return 0;
}
