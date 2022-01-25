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
 
void bfs(AdjacencyList & adj, long long node){
   adj.visited[node] = true;
   cout << (char)(node + 'A') << " ";
 
   queue<long long> q;
   q.push(node);
 
   while(!q.empty()){
       long long cur_node = q.front(); q.pop();
 
       for(const auto & i : adj.lst[cur_node]){
           if(!adj.visited[i]){
               adj.visited[i] = true;
               cout << (char)(i + 'A') << " ";
               q.push(i);
           }
       }
   }
}
 
void bfs(AdjacencyMatrix & adj, long long node){
   adj.visited[node] = true;
   cout << (char)(node + 'A') << " ";
 
   queue<long long> q;
   q.push(node);
 
   while(!q.empty()){
       long long cur_node = q.front(); q.pop();
 
       for(long long i = 0; i < adj.mat[cur_node].size(); i++){
           if(adj.mat[cur_node][i] == 1 and (!adj.visited[i])){
               adj.visited[i] = true;
               cout << (char)(i + 'A') << " ";
               q.push(i);
           }
       }
   }
}
 
enum Nodes {
   A, B, C, D, E, F, G, H
};
 
void solve(){
   long long num = 8;
   // Creating a Adjacency List and AdjacencyMatrix
   AdjacencyList a(num);
   AdjacencyMatrix b(num);
 
   vector<pair<long long, long long>> edges = {
       {A, B}, {A, C}, {A, D},
       {B, E}, {B, C},
       {C, E},
       {D, C}, {D, F},
       {E, A},
       {F, C},
       {G, D}, {G, F}, {G, H},
       {H, C}
   };
 
   for(const auto [x, y] : edges){
       a.insert(x, y);
       b.insert(x, y);
   }
 
   cout << "Using Adjacency List \n";
   for(long long i = 0; i < num; i++){
       long long st = i;
       cout << "dfs(starting node = " << (char)(st + 'A') << ") : ";
       dfs(a, st);
       a.reset_visited();
       cout << "\n";
   }
   cout << "\n";
 
 
   cout << "Using Adjacency Matrix \n";
   for(long long i = 0; i < num; i++){
       long long st = i;
       cout << "dfs(starting node = " << (char)(st + 'A') << ") : ";
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
