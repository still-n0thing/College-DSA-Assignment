#include <bits/stdc++.h>

using namespace std;

long long get_priority(char c){
    if (c == '-' or c == '+'){
        return 1;
    } else if (c == '*' or c == '/'){
        return 2;
    } else if (c == '^'){
        return 3;
    } else {
        return 0;
    }
}

bool is_operator(char c){
    return (!isalpha(c) and !isdigit(c));
} 

string in_to_postfix(string infix){
    infix = '(' + infix + ')';
    long long n = infix.size();
    stack<char> st;
    string ans = "";

    for(long long i = 0; i < n; i++){
        if(isalpha(infix[i]) or isdigit(infix[i])){
            ans += infix[i];
        } else if(infix[i] == '('){
            st.push(infix[i]);
        } else if(infix[i] == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            if(is_operator(st.top())){
                if(infix[i] == '^'){
                    while(get_priority(infix[i] <= get_priority(st.top()))){
                        ans += st.top();
                        st.pop();
                    }
                } else {
                    while (get_priority(infix[i]) < get_priority(st.top())){
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(infix[i]);
            }
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

string post_to_prefix(string postfix){
    stack<string> st;
    long long n = postfix.size();
    for(long long i = 0; i < n; i++){
        if(is_operator(postfix[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = postfix[i] + op2 + op1 ;
            st.push(temp);
        } else {
            st.push(string(1, postfix[i]));
        }
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

void solve(){
    string s; cin >> s; 
    cout << "infix : " << s << "\n";
    string post = in_to_postfix(s);
    string pre = post_to_prefix(post);
    cout << "postfix : " << post << "\n";
    cout << "prefix : " << pre << "\n";
}

int main(int argc, const char ** argv){
    long long T; cin >> T;
    for(long long i = 1; i <= T; i++){
        solve();
    }
    return 0;
}
