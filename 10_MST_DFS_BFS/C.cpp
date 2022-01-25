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
 
void topo_sort(AdjacencyList & adj){
   vector<long long> in_deg(adj.lst.size(), 0);
 
   for(long long u = 0; u < adj.lst.size(); u++){
       for(const auto & i : adj.lst[u]){
           in_deg[i]++;
       }
   }
 
   queue<long long> q;
   for(long long i = 0; i < adj.lst.size(); i++){
       if(in_deg[i] == 0){
           q.push(i);
       }
   }
 
   long long cnt = 0;
 
   vector<long long> ans;
 
   while(!q.empty()){
       long long u = q.front(); q.pop();
       ans.push_back(u);
       for(const auto & i : adj.lst[u]){
           if(--in_deg[i] == 0){
               q.push(i);
           }
       }
       cnt++;
   }
 
   if(cnt != adj.lst.size()){
       cout << "These is a cycle in the graph\n";
   } else {
       for(const auto & i : ans){
           cout << (char)(i + 'm') << " ";
       }
   }
}
 
void solve(){
   enum NODES {
       m, n, o, p, q, r, s, t, u, v, w, x, y, z
   };
 
   long long num = 14;
   AdjacencyList a(num);
 
   vector<pair<long long, long long>> edges = {
       {m, q}, {m, r}, {m, x},
       {n, o}, {n, q}, {n, u},
       {o, r}, {o, s},
       {p, o}, {p, s}, {p, z},
       {q, t},
       {r, u},
       {s, r},
       {u, t},
       {v, w}, {v, x},
       {w, z},
       {y, v}
   };
 
   for(const auto [x, y] : edges){
       a.insert(x, y);
   }
 
   cout << "Topological Sort :\n";
   topo_sort(a);
   cout << "\n";
}
 
int main(){
   solve();
   return 0;
}
