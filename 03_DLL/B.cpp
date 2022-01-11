#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node * prev;

    Node(){
        this->data = -1;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Doubly_linked_list {
public:
    Node * head = nullptr;
    Node * tail = nullptr;
    int size = 0;

    void append(int data){
        if(head == tail and head == nullptr){
            Node * temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->next = nullptr; 
            temp->prev = nullptr;
            head = temp; tail = temp;
        } else {
            Node * itr = head;
            while(itr->next != nullptr){
                itr = itr->next;
            }
            Node * temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->prev = itr;
            temp->next = nullptr;
            itr->next = temp;
            tail = temp;
        }
        this->size++;
    }

    void printall(){
        Node * itr = head;
        while(1){
            cout << itr->data << " ";
            if(itr == tail) {
                break;
            }
            itr = itr->next;
        }
        cout << "\n";
    }

    // For element with this->data == data
    void pop(int data){
        Node * itr = head;
        bool flag = false;
        while(itr != nullptr){
            if(itr->data == data){
                flag = true;
                break;
            }
            itr = itr->next;
        }
        if(flag){
            Node * p = itr->prev;
            Node * n = itr->next;
            free(itr);
            if(p != nullptr){
                p->next = n;
            } 
            if(n != nullptr){
                n->prev = p;
            }
            size--;
        } else {
            cout << "Data does not exist int the list\n";
        }
    }

    // For last element 
    void pop(){
        if(tail != nullptr){
            Node * p = tail->prev;
            p->next = nullptr;
            free(tail);
            tail = p;
            size--;
        } else {
            cout << "Empty List\n";
        }
    }

    void insert(int data, int pos){
        int idx = 0;
        Node * itr = head;
        while(itr != nullptr){
            idx++;
            if(idx == (pos-1)){
                break;
            }
            itr = itr->next;
        }
        Node * temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        Node * n = itr->next;
        itr->next = temp;
        temp->prev = itr;
        if(n != nullptr){
            n->prev = itr;
        } else {
            tail = temp;
        }
        temp->next = n;
        size++;
    }

    void clearall(){
        size = 0;
        Node * cur;
        while(head != nullptr){
            cur = head;
            head = head->next;
            free(cur);
        }
        head = nullptr;
        tail = nullptr;
    }

};

void solve(){
    Doubly_linked_list dll;
    int n; 
    
    cin >> n;
    while(n--){
        int dt; cin >> dt;
        dll.append(dt);
    }

    cout << "INPUT LIST : \n";
    dll.printall(); cout << "\n";

    int q; cin >> q;
    int dt, pos;
    while(q--){
        int info; cin >> info;
        switch (info){
        case 1:
            cin >> dt;
            cout << "QUERY : Delete " << dt << "\n"; 
            dll.pop(dt);
            cout << "UPDATED LIST : \n";
            dll.printall(); cout << "\n";
            break;
        case 2:
            cin >> dt >> pos;
            cout << "QUERY : Insert " << dt << " to " << pos << " position\n";
            dll.insert(dt, pos);
            cout << "UPDATED LIST : \n";
            dll.printall(); cout << "\n";
            break;
        case 3:
            cout << "QUERY : Delete last element\n";
            dll.pop();
            cout << "UPDATED LIST : \n";
            dll.printall(); cout << "\n";
            break;
        default:
            break;
        }
    }

    dll.clearall();
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 

    freopen("inB.txt", "r", stdin);
    freopen("outB.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
