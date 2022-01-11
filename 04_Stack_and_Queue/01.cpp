#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = "; deb(x); cerr<<endl;

typedef long long ll;

class single_node{
public:
    // Data memebers
    ll data;
    single_node * next;

    // Functions
    single_node(){
        this->data = LLONG_MIN;
        this->next = nullptr;
    }
    single_node(ll data, single_node * next){
        this->data = data;
        this->next = next;
    }

    // WARNING : Memeory Leak
    // Reason for not defining destructor 
    // Link : https://stackoverflow.com/questions/68998679/how-to-delete-this-in-c-class-so-that-it-doesnt-enter-infinte-loop
    // ~single_node(){
    //     cerr<<"destructor is called\n";
    //     if(this->next != nullptr){
    //         delete this->next;
    //     }
    // }

    void show(){ 
        // For Debugging
        single_node * temp = next;
        cout << data << "\n";
        while(temp != nullptr){
            cout << data << " - ";
            temp = temp->next;
        } 
        cout << "\n";
    }
    
};

class single_linked_list{
public:
    // Data members
    single_node * head = new single_node;

    // Functions
    single_linked_list(){
        head->data = LLONG_MIN;
        head->next = nullptr;
    }

    void add_after(ll data){
        // Clearly O(n) as we need to find the end to add the element
        if(head->data == LLONG_MIN){
            head->data = data;
            head->next = nullptr;
        }
        else{
            single_node * temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            single_node * z = new single_node;
            temp->next = z;
            z->data = data;
        }
    }

    void traversing(bool flag = false){
        // O(n)
        if(flag){
            single_node * temp = this->head;
            while(temp != nullptr){
                // cout << "(" << temp << ")";
                // cout << temp->data << " -> ";
                cout << temp->data << "(" << temp << ")" << " -> ";
                temp = temp->next;

            }
            cout << "null" << "(" << temp << ")\n";
        }
        else{
            single_node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }
};

class Queue{
private:
    // Data Members
    single_node * head = nullptr;
    single_node * tail = nullptr;
    ll n;
public:
    // Functions
    Queue(){
        head = new single_node;
        tail = head;
        n = 0;
    }

    void add(ll x){
        
        if(n == 0 and head != nullptr){
            head->data = x;
        }
        else if(head == nullptr){
            head = new single_node;
            tail = head;
            head->data = x;
        }
        else{
            single_node * temp = new single_node;
            temp->data = x;
            tail->next = temp;
            tail = temp;
        }
        n++;
    }

    ll remove(){
        single_node * res = head;
        if(n == 0){
           cerr << "Cannot remove element from a empty Queue";
           return LLONG_MIN; 
        }
        else{
            n--;
            ll ans = head->data;
            head = head->next;
            return ans;
        }
    }

    void traversing(bool flag = false){
        // O(n)
        if(flag){
            single_node * temp = this->head;
            while(temp != nullptr){
                // cout << "(" << temp << ")";
                // cout << temp->data << " -> ";
                cout << temp->data << "(" << temp << ")" << " -> ";
                temp = temp->next;

            }
            cout << "null" << "(" << temp << ")\n";
        }
        else{
            single_node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }

};

// Main Solution
class Stack {
public:
    // Data Members
    Queue q1;
    Queue q2;
    int sw;
    int size;

    Stack(){
        sw = 0;
        size = 0;
    }

    void push(ll x){
        if(sw == 0){
            q1.add(x);
        } else {
            q2.add(x);
        }
        size++;
    }

    ll pop(){
        if(sw == 0){
            ll t = size - 1;
            while(t--){
                q2.add(q1.remove());
            }
            sw = 1;
            size--;
            return q1.remove();
        } else {
            ll t = size - 1;
            while(t--){
                q1.add(q2.remove());
            }
            sw = 0;
            size--;
            return q2.remove();
        }
    }

};

void solve(){
    ll n; cin >> n;
    Stack s1;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        s1.push(x);
    }
    while(s1.size != 0){
        cout << s1.pop() << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif    

    long long T; cin >> T; while(T--)
    solve();
    return 0;
}