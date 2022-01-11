#include<bits/stdc++.h>
 
using namespace std;
 
void FastIO(); 

const int max_size = 10;

class Product {
public:
    string name; // has to be string
    int expiry_year; // as it year it must be int
    int cost; //in INR  
    
    Product(){
        this->name = "nil";
        this->expiry_year = -1;
        this->cost = -1;
    }
    
    Product(const string &  name, const int & expiry_year, const int & cost){
        this->name = name;
        this->expiry_year = expiry_year;
        this->cost = cost;
    }
    
    void display(){
        cout << "Name : " << this->name << endl;
        cout << "Expiry year : " << this->expiry_year << endl;
        cout << "Cost : " << this->cost << endl;
    }   

    void set(const string & name = "nil", const int & expiry_year = -1, const int & cost = -1){
        this->name = name;
        this->expiry_year = expiry_year;
        this->cost = cost;
    }

    void input(){
        cin >> (this->name) >> (this->expiry_year) >> (this->cost);
    }
    // void input(){
    //     cin >> (name) >> (expiry_year) >> (cost);
    // }
};
 
class List{
public:
    // Data Memebers
    Product a[max_size];
    int current_size = 0;   

    // Functions
    void add(Product & item, int idx = -1){
        if(current_size != max_size){
                if(idx == -1){
                    a[current_size] = item;
                } else {
                    Product temp, some;
                    temp = a[idx];
                    for(int i = idx; i < max_size - 1; i++){
                        some = a[i+1];
                        a[i+1] = temp;
                        temp = some;
                    }
                    a[idx] = item;
                }
                current_size++;
                // printall();
        } else {
            cout << "List is filled!" << endl;
        }
    }
    
    void printall(){
        cout << "---" << endl;
        for(int i = 0; i < current_size; i++){
            // cerr << current_size << endl;
            cout << "Product number : " << (i+1) << endl;
            a[i].display();
            cout << "---" << endl;
        }
    }
 
    void remove(int idx = -1){
        if(current_size != 0){
            if(idx != -1){
                a[idx].set();
                for(int i = idx; i < max_size-1; i++){
                    a[i] = a[i+1];
                }
            } else {
                a[current_size].set();
            }
            current_size--;
            // printall();
        } else {
            cout << "List is empty!" << endl;
        }
    }
    
};

void sol(){
    List l1;
    l1.printall();
    for(int i = 0; i < max_size; i++){
        cout << "Write book [name expiry_data cost] in given format :" << endl;
        Product temp;
        temp.input();
        l1.add(temp);
    }
    l1.printall();

    l1.remove(5);
    cout << "AFTER" << endl;

    l1.printall();
}

void options(){
    cout << "\t---Options---" << endl;
    cout << "1) Adding element to the list" << endl;
    cout << "2) Removing element form the list" << endl;
    cout << "3) Printing all the items in the list" << endl;
    cout << "Any other number to quit" << endl;
    cout << "\nType your choice here : "; cout.flush();
}

int main(int argc, const char ** argv){
    // For taking input form input.txt and outputting to output.txt
    // FastIO();
    // sol();

    List alist;
    int t = 1;
    Product temp;
    string name; int expiry_year, cost, idx;
    
    while(1 <= t and t <= 3){
        options(); cin >> t;
        switch (t){
        case 1:
            cout << "Type index number[1..n] or -1 for the end:";
            cin >> idx;
            if(idx != -1){
                cout << "Input the Product data in diven format" << endl;
                cout << "Format : name expiry_year price" << endl;
                cout << "Data types : string int int" << endl;
                cin >> name >> expiry_year >> cost;
                temp.set(name, expiry_year, cost);
                alist.add(temp, idx-1);
            } else {
                cout << "Input the Product data in diven format" << endl;
                cout << "Format : name expiry_year price" << endl;
                cout << "Data types : string int int" << endl;
                // cin >> name >> expiry_year >> cost;
                // temp.set(name, expiry_year, cost);
                temp.input();
                alist.add(temp);
            }
            break;
        case 2: 
            cout << "Type index number[1..n] or -1 for the end:";
            cin >> idx;
            if(idx != -1){
                alist.remove(idx-1);
            } else {
                alist.remove();
            }
            break;
        case 3:
            alist.printall();
            break;
        default:
            break;
        }    
    }
    return 0;
}




void FastIO(){
    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 
    // For local code execution
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    
}