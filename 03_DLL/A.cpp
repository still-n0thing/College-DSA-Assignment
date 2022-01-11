#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    // Data Members
    int xpow; 
    int coeff;
    Node * next;

    // Functions
    Node(){
        this->xpow = 0;
        this->coeff = 0;
        this->next = nullptr;
    }

    Node(int xpow, int coeff){
        this->xpow = xpow;
        this->coeff = coeff;
        this->next = nullptr;
    }

};

class Linked_List {
public:
    // Data Members
    Node * head = nullptr;
    int size = 0;

    // Functions
    void add(int xpow, int coeff){
        if(this->head == nullptr){
            Node * temp = new Node(xpow, coeff);
            this->head = temp; 
        } else {
            Node * itr = this->head;
            while(itr != nullptr){
                if(itr->xpow == xpow){
                    itr->coeff += coeff;
                    break;
                } else if (itr->xpow > xpow and itr->next == nullptr) {
                    Node * temp = new Node(xpow, coeff);
                    itr->next = temp;
                    itr->next->next = nullptr;
                    break;
                } else if (itr->xpow > xpow and itr->next->xpow < xpow) {
                    Node * temp = new Node(xpow, coeff);
                    temp->next = itr->next;
                    itr->next = temp;
                    break;
                } else if (itr->xpow < xpow and itr == head){
                    Node * temp = new Node(xpow, coeff);
                    temp->next = itr;
                    head = temp;
                }
                itr = itr->next;
            }
        }
        size++;
    }

    void printall(){
        Node * itr = this->head;
        while(itr != nullptr){
            cout << itr->coeff;
            if(itr->xpow != 0){
                cout << "x^" << itr->xpow;
            } 
            if(itr->next == nullptr){
                cout << "\n";
                break;
            } else {
                cout << " + ";
            }
            itr = itr->next;
        }
    }

    void clearall(){
        Node * itr = head;
        while(itr != nullptr){
            head = itr;
            itr = itr->next;
            delete head;
        }
    }

};

void solve(){
    Linked_List lleq1, lleq2;
    int n;
    
    cin >> n;
    while(n--){
        int coeff, xpow;
        cin >> coeff >> xpow;
        lleq1.add(xpow, coeff);
    }
    cout << "Polynomial 1 (p1) : ";
    lleq1.printall();

    cin >> n;
    while(n--){
        int coeff, xpow;
        cin >> coeff >> xpow;
        lleq2.add(xpow, coeff);
    }
    cout << "Polynomial 2 (p2) : ";
    lleq2.printall();
    
    Node * itr = lleq2.head;
    while(itr != nullptr){
        lleq1.add(itr->xpow, itr->coeff);
        itr = itr->next;
    }
    cout << "Polynomial 3 (p1 + p2) : ";
    lleq1.printall(); 
    cout << "\n";

    lleq1.clearall();
    lleq2.clearall();

}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 

    freopen("inA.txt", "r", stdin);
    freopen("outA.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
