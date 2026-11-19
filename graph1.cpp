#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor: adj[v]) {
            if (visited[neighbor]) continue;    // sąsiad już odwiedzony, pomijamy
            q.push(neighbor);
            visited[neighbor] = true;
        }
    }
}

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (int neighbor: adj[v]) {
            if (visited[neighbor]) continue;    // sąsiad już odwiedzony, pomijamy
            s.push(neighbor);
            visited[neighbor] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);     // adj[v] -- lista sąsiadów wierzchołka v
    while (E--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);        // bo jest to graf nieskierowany
    }
    int cc_count = 0;               // liczba spójnych składowych
    vector<bool> visited(V, false); // visited[v] -- czy wierzchołek v jest już przetworzony
    for (int v = 0; v < V; ++v) {
        if (visited[v]) continue;   // przetworzony wierzchołek nie tworzy nowej spojnej składowej, pomijamy
        cc_count++;                 // znaleźlismy nową spójną składową
        dfs(adj, visited, v);       // odwiedzamy wszystkie wierzchołki w tej spójnej składowej
    }
    cout << cc_count;

    // for (int v = 0; v < V; ++v) {
    //     cout << "Sasiedzi " << v << ": ";
    //     // for (int u = 0; u < adj[v].size(); ++u) {
    //     //     cout << adj[v][u] << ' ';
    //     // }
    //     for (int neighbor : adj[v]) {
    //         cout << neighbor << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}