

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node * prev;
    
    Node(){
        int data = -1;
        next = nullptr;
        prev = nullptr;
    }
    
    Node(int x){
        int data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL {
public:
    Node * head;
    Node * tail;
    int size;
    
    DLL(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void insert(int x){
        if(head == nullptr and tail == nullptr){
            Node * temp = new Node();
            temp->data = x;
            head = temp;
            tail = temp;
        } else {
            Node * temp = new Node();
            temp->data = x;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    
    void traverse(){
        Node * some = head;
        while(some != nullptr){
            cout << some->data << " ";
            some = some->next;
        }
    }
    
};

int main(){
    int n; cin >> n;
    DLL d1, d2;
    
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        d1.insert(temp);
    }
    
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        d2.insert(temp);
    }
    
    int ans = 0;
    Node * h1 = d1.head, * h2 = d2.tail;
    
    cout << "SUM = ";
    for(int i = 0; i < n; i++){
        cout << "A" << (i + 1) << "*" << "B" << (n - i);
        if(i != n - 1){
            cout << " + ";
        }   
    }
    cout << "\n";

    cout << "SUM = ";
    while(h1 != nullptr or h2 != nullptr){
        ans += (h1->data)*(h2->data);
        cout << (h1->data) << "*" << (h2->data);
        h1 = h1->next;
        h2 = h2->prev;
        if(h1 != nullptr) {
            cout << " + ";
        }
    }
    cout << "\n";
    
    cout << "SUM = " << ans << "\n";
    
    return 0;
}