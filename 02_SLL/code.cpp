#include <bits/stdc++.h>

using namespace std;

class Student_data{
public:
    int regno;
    string name;
    string branch;
    int marks;
};

class Node {
public:
    Student_data data;
    Node * next;

    void printnode(){
        cout << data.regno << " " 
        << data.name << " " 
        << data.branch << " "
        << data.marks << "\n";
    }

    void set(int regno, string name, string branch, int marks){
        this->data.regno = regno;
        this->data.name = name;
        this->data.branch = branch;
        this->data.marks = marks;
    }
};

class Linked_list{
public:
    Node * head = nullptr;
    int size = 0;

    // Add at the end 
    void add(int regno, string name, string branch, int marks){
        Node * temp = new Node;
        temp->set(regno, name, branch, marks);
        if(head == nullptr){
            head = temp;
        } else {
            Node * itr = head;
            while(itr->next != nullptr){
                itr = itr->next;
            }
            itr->next = temp;
        }
        size++;
    }

    // Insert before the head
    void insert(int regno, string name, string branch, int marks){
        Node * temp = new Node;
        // A -> B -> C
        // |
        // K -> A -> B -> C
        // |
        temp->set(regno, name, branch, marks);
        temp->next = head;
        head = temp;
    }

    Node * cut(){
        Node * temp = head;
        head = head->next;
        return temp;
    }

    void del(int regno){
        Node * op;
        Node * itr = head;
        if(head->data.regno == regno){
            // Null(A) -> B -> C
            //  \-------------/
            op = head;
            head = head->next; 
            // delete op;
        } else {
            bool flag = false;
            while(itr != nullptr){
                // itr->printnode();
                // cout << "rengno : " << regno << "\n";
                if(itr->next->data.regno == regno){
                    flag = true;
                    break;
                }
                itr = itr->next;
            }
            if(flag){
                // A : itr 
                // B : d_node 
                // C : nxt
                Node * d_node = itr->next;
                Node * nxt = d_node->next;
                // A -> B -> C
                // \--------/

                // A -> B -> Null(C)
                //  \--------/
                itr->next = nxt;
                // delete d_node;
            } 
        }
    }

    void printall(){
        Node * ptr = head;
        while(ptr != nullptr){
            ptr->printnode();
            ptr = ptr->next;
        }
    }

    void make_circular(){
        Node * itr = head;
        while(itr->next != nullptr){
            itr = itr->next;
        }
        // itr->printnode();

        itr->next = head;
    }

    void print_cll(int n){
        Node * itr = head;
        int cnt = 0;
        while(1){
            if(itr == head){
                if(cnt + 1 <= n){
                    itr->printnode();
                    cnt++;
                } else {
                    break;
                }
            } else {
                itr->printnode();
            }
            itr = itr->next;
        }
    }

};

// Solution
void solve(){
    int n; cin >> n;
    Linked_list topper, cse, ece, eee, mech;
    while(n--){
        int regno; cin >> regno;
        string name; cin >> name;
        string branch; cin >> branch;
        int marks; cin >> marks;
        topper.add(regno, name, branch, marks);
    }
    cout << "\t---TOPPER---\n";
    topper.printall(); cout << "\n";
    
    cin >> n;
    while(n--){
        int regno; cin >> regno;
        string name; cin >> name;
        string branch; cin >> branch;
        int marks; cin >> marks;
        cse.add(regno, name, branch, marks);
    }
    cout << "\t---CSE---\n";
    cse.printall(); cout << "\n";

    cin >> n;
    while(n--){
        int regno; cin >> regno;
        string name; cin >> name;
        string branch; cin >> branch;
        int marks; cin >> marks;
        mech.add(regno, name, branch, marks);
    }
    cout << "\t---MECH---\n";
    mech.printall(); cout << "\n";

    cin >> n;
    while(n--){
        int regno; cin >> regno;
        string name; cin >> name;
        string branch; cin >> branch;
        int marks; cin >> marks;
        ece.add(regno, name, branch, marks);
    }
    cout << "\t---ECE---\n";
    ece.printall(); cout << "\n";

    cin >> n;
    while(n--){
        int regno; cin >> regno;
        string name; cin >> name;
        string branch; cin >> branch;
        int marks; cin >> marks;
        eee.add(regno, name, branch, marks);
    }
    cout << "\t---EEE---\n";
    eee.printall(); cout << "\n";

    // DONE : 1) Printing the original lists
    
    Node * itr = topper.head;
    while(itr != nullptr){
        if(itr->data.branch == "MECH"){
            cse.add(
                itr->data.regno,
                itr->data.name,
                "CSE",
                itr->data.marks
            );
            mech.del(itr->data.regno);
        } else if(itr->data.branch == "EEE"){
            ece.insert(
                itr->data.regno,
                itr->data.name,
                "ECE",
                itr->data.marks
            );
            eee.del(itr->data.regno);
        }
        itr = itr->next;
    }

    // DONE : 2) Add the MECH topper at the end of the CSE List
    // DONE : 3) Add the EEE topper at the of the ECE List

    cout << "\t---CSE(updated)---\n";
    cse.printall(); cout << "\n";
    
    cout << "\t---ECE(updated)---\n";
    ece.printall(); cout << "\n";

    cout << "\t---MECH(updated)---\n";
    mech.printall(); cout << "\n";

    cout << "\t---EEE(updated)---\n";
    eee.printall(); cout << "\n";

    // DONE : 4) Print all the updated lists

    cse.make_circular();
    ece.make_circular();

    cout << "\n\t---CSE(circular)---\n";
    cse.print_cll(1);

    cout << "\n\t---ECE(circular)---\n";
    ece.print_cll(1);
}

// Main
int main(){
    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 

    // For local code 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    

    // Complete Solution
    solve();
    return 0;
}