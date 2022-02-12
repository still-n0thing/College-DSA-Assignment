#include <bits/stdc++.h>

using namespace std;

class AdjacencyList{
public:
    vector<vector<pair<int, int>>> adj;

    AdjacencyList(int n){
        adj = vector<vector<pair<int,int>>>(n);
    }

    void insert(int u, int v, int w){
        adj[u].push_back({v, w});
    }
};

const int INF = (1e5) + 5;

pair<vector<int>, vector<int>> dijkstra(AdjacencyList & G, int start){
    const int n = (int)G.adj.size();
    vector<int> distance(n, INF), previous(n, -1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0, start});
    distance[start] =  0;
    
    while(!q.empty()){
        int u = q.top().second;
        int wt = q.top().first;
        q.pop();
        for(auto & [v, w] : G.adj[u]){
            int d = w + distance[u];
            if(d < distance[v]){
                distance[v] = d;
                previous[v] = u;
                q.push({d, v});
            }
        }
    }
    return {distance, previous};
}

void solve(){
    enum ChartoInt {
        A, B, C, D, E, F, G
    };
    vector<vector<int>> edges = {
        {A, B, 2}, {A, D, 1},
        {B, D, 3}, {B, E, 10},
        {C, A, 4}, {C, F, 5},
        {D, C, 2}, {D, E, 2}, {D, F, 8}, {D, G, 4},
        {E, G, 6},
        {G, F, 1}
    };

    int n = 7;
    AdjacencyList a(n);
    for(auto arr : edges){
        a.insert(arr[0], arr[1], arr[2]);
    }

    pair<vector<int>, vector<int>> ans = dijkstra(a, A);
    vector<int> distance = ans.first, previous = ans.second;
    
    cout << "Running Dijkstra's algorithm on the given graph\n\n";
    const int m = (int)(ans.first.size());
    for(int i = 0; i < m; i++){
        int d = distance[i];
        int p = previous[i];
        if(p != -1){
            cout << "total weights on the path : " << d << "\n";
            cout << "shortest path : ";
            int x = i;
            while(previous[x] != -1){
                cout << (char)(x + 'A') << " <- ";
                x = previous[x];
            }
            cout << 'A' << "\n";
            cout << "\n";
        }
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T; 
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}