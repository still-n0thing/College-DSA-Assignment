#include<bits/stdc++.h>
 
using namespace std;
 
// To get random value
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)
 
class Edgelist {
public:
   vector<vector<long long>> edges;
   long long sz;
   long long nodes;
 
   Edgelist(long long n){
       sz = 0;
       nodes = n;
   }
 
   void addEdge(long long v, long long u, long long w){
       edges.push_back({w, v, u});
       sz++;
   }
 
   long long size(){
       return sz;
   }
};
 
class AdjacencyList {
public:
   vector<vector<pair<long long, long long>>> lst;
   vector<bool> visited;
   long long size;
 
   AdjacencyList(long long n){
       size = n;
       lst = vector<vector<pair<long long, long long>>>(size);
       visited = vector<bool>(size, false);
   }
 
   void insert(long long v, long long u, long long w){
       lst[v].push_back({w, u});
       lst[u].push_back({w, v});
   }
 
   void reset_visited(){
       visited = vector<bool>(size, false);
   }
};
 
template<typename T>
class DSU {
public:
   vector<T> p;
   vector<T> r;
   long long sz;
 
   DSU(long long n){
       p = vector<T>(n);
       iota(p.begin(), p.end(), 0);
       r = vector<T>(n, 1);
   }
 
   T find(T x){
       T y = x;
       while(y != p[y]){
           y = p[y];
       }
       while(x != p[x]){
           T z = p[x];
           p[x] = y;
           x = z;
       }
       return x;
   }
 
   void join(T x, T y){
       x = find(x), y = find(y);
       if(r[x] > r[y]){
           swap(x, y);
       }
       p[x] = y;
       if(x != y and r[x] == r[y]){
           r[y]++;
       }
   }
};
 
long long Kruskals_MST(Edgelist & a){
   // TO get the edges with minimum weights
   sort(a.edges.begin(), a.edges.end());
 
   DSU<long long> dsu(a.nodes);
  
   long long ans = 0;
   vector<vector<long long>> used;
 
   for(auto & i : a.edges){
       long long w = i[0], v = i[1], u = i[2];
       if(dsu.find(v) != dsu.find(u)){
           ans += w;
           used.push_back({w, u, v});
           dsu.join(v, u);
       }
   }
 
   cout << "Edges used (v --(w)-- u):\n";
   for(auto & i : used){
       long long w = i[0], v = i[1], u = i[2];
       cout << (v + 1) << " --(" << w << ")-- " << (u + 1) << "\n";
   }
 
   return ans;
}
 
typedef pair<long long,long long> pll;
 
long long Prims_MST(AdjacencyList & a){
   priority_queue<pll, vector<pll>, greater<pll>> pq;
   const long long INF = (1e18);
   int src = 0;
  
   vector<long long> key(a.size, INF);
   vector<long long> parent(a.size, -1);
 
   key[src] = 0;
   pq.push(make_pair(0, src));
 
   while(!pq.empty()){
       long long u = pq.top().second; pq.pop();
       a.visited[u] = true;
 
       for(const auto & i : a.lst[u]){
           long long v = i.second;
           long long w = i.first;
 
           if(!a.visited[v] and key[v] > w){
               key[v] = w;
               pq.push(make_pair(key[v], v));
               parent[v] = u;
           }
       }
   }
   return accumulate(key.begin(), key.end(), 0LL);
}
 
void solve(){
 
   long long num = 6;
   vector<vector<long long>> d = {
       {6, 1, 2},
       {1, 1, 3},
       {5, 1, 4},
       {5, 2, 3},
       {5, 3, 4},
       {3, 2, 5},
       {6, 3, 5},
       {4, 3, 6},
       {2, 4, 6},
       {6, 5, 6}
   };
 
   Edgelist a(num);
   AdjacencyList b(num);
   for(auto & i : d){
       long long w = i[0], v = i[1], u = i[2];
       v--; u--; // For DSU
       a.addEdge(v, u, w);
       b.insert(v, u, w);
   }
   long long kans = Kruskals_MST(a); cout << "\n";
   cout << "Cost of MST using Kruskal's Algorithm : " << kans << "\n";
 
   long long pans = Prims_MST(b); cout << "\n";
   cout << "Cost of MST using Prim's Algorithm : " << pans << "\n";
   cout << "\n";
}
 
int main(){
   solve();
   return 0;
}
