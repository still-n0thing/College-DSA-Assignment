#include<bits/stdc++.h>

using namespace std;

class AdjacencyList {
public:
    vector<vector<long long>> lst;
    vector<bool> visited;
    long long size;

    AdjacencyList(long long n){
        size = n;
        lst = vector<vector<long long>>(size);
        visited = vector<bool>(size, false);
    }

    void insert(long long out_node, long long in_node){
        lst[out_node].push_back(in_node);
    }

    void reset_visited(){
        visited = vector<bool>(size, false);
    }
};

class AdjacencyMatrix {
public:
    vector<vector<long long>> mat;
    vector<bool> visited;
    long long size;

    AdjacencyMatrix(long long n){
        size = n;
        mat = vector<vector<long long>>(size, vector<long long>(size, 0LL));
        visited = vector<bool>(size, false);
    }

    void insert(long long out_node, long long in_node){
        mat[out_node][in_node] = 1;
    }

    void reset_visited(){
        visited = vector<bool>(size, false);
    }
};

void dfs(AdjacencyList & adj , long long node){
    adj.visited[node] = true;
    cout << (char)(node + 'A') << " ";

    for(const auto & i : adj.lst[node]){
        if(!adj.visited[i]){
            dfs(adj, i);
        }
    }
}

void dfs(AdjacencyMatrix & adj, long long node){
    adj.visited[node] = true;
    cout << (char)(node + 'A') << " ";

    for(long long i = 0; i < adj.mat[node].size(); i++){
        if(adj.mat[node][i] == 1 and (!adj.visited[i])){
            dfs(adj, i);
        }
    }
}

enum Nodes {
    A, B, C, D, E, F
};

void solve(){
    // Creating a Adjacency List and AdjacencyMatrix
    AdjacencyList a(6);
    AdjacencyMatrix b(6);

    vector<pair<long long, long long>> edges = {
        {A, B}, {A, F},
        {B, C},
        {C, E},
        {D, C},
        {E, F}, {E, A},
        {F, D}
    };

    for(const auto [x, y] : edges){
        a.insert(x, y);
        b.insert(x, y);
    }

    cout << "Using Adjacency List \n";
    
    for(long long i = 0; i < 5; i++){
        long long st = i;
        cout << "dfs(starting node = " << st << ") : ";
        dfs(a, st);
        a.reset_visited();
        cout << "\n";
    }
    cout << "\n";

    

    cout << "Using Adjacency Matrix \n";
    
    for(long long i = 0; i < 5; i++){
        long long st = i;
        cout << "dfs(starting node = " << st << ") : ";
        dfs(b, st);
        b.reset_visited();
        cout << "\n";
    }
    cout << "\n";

}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}