#include<bits/stdc++.h>

using namespace std;

class single_node{
public:
    // Data memebers
    long long data;
    single_node * next;

    // Functions
    single_node(){
        this->data = LLONG_MIN;
        this->next = nullptr;
    }
    single_node(long long data, single_node * next){
        this->data = data;
        this->next = next;
    }

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

class Queue{
private:
    // Data Members
    single_node * head = nullptr;
    single_node * tail = nullptr;
public:
    long long n;
    // Functions
    Queue(){
        head = new single_node;
        tail = head;
        n = 0;
    }

    void add(long long x){
        
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

    long long remove(){
        single_node * res = head;
        if(n == 0){
           cerr << "Cannot remove element from a empty Queue";
           return LLONG_MIN; 
        }
        else{
            n--;
            long long ans = head->data;
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

void solve(){
    long long n; cin >> n;
    Queue a, b, c;
    while(n--){
        long long temp; cin >> temp;
        a.add(temp);
        
    }

    cout << "input queue :\n";

    a.traversing();

    vector<long long> some;
    // int t = a.remove();
    while(a.n != 0){
        long long temp = a.remove();
        b.add(temp);
        some.push_back(temp);
    }

    cout << "a) Copy content from one queue to another in the same order : \n";
    b.traversing();

    // t = b.remove();

    vector<long long> arr;

    while(b.n != 0){
        arr.push_back(b.remove());
    }

    reverse(arr.begin(), arr.end());
    for(const auto & i : arr){
        c.add(i);
    }

    cout << "b) Copy content from one queue to another in reverse order : \n";
    c.traversing();

    cout << "c) check whether two queues are identical : \n";
    cout << ( arr == some ? "true" : "false") << "\n";
    
    cout << "d) count the number of elements in Queue : \n";
    cout << "count = " << c.n << "\n";
}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}