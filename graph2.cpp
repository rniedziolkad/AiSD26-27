// znajdowanie cyklu, działa dla nieskierowanego grafu spójnego
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<char>& state, int v) {
    state[v] = 'p';     // 'p' -- wierzchołek jest przetwarzany
    for (int neighbor : adj[v]) {
        if (state[neighbor] == 'p') return true;    // znaleźlismy cykl
        if (state[neighbor] == 'd') continue;       // wierzchołek przetworzony pomijamy
        if (dfs(adj, state, neighbor)) return true; // jeżeli w rekurencji był cykl to wracamy, w przeciwnym razie pętla jest kontynuowana
    }
    state[v] = 'd';     // 'd' -- wierzchołek jest już przetworzony
    return false;       // nie było cyklu
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
    }
    vector<char> state(V, 'n');     // początkowo każdy wierzchołek jest nieprzetworzony -- 'n'
    
    if (dfs(adj, state, 0)) {
        cout << "TAK";
        return 0;
    }
    cout << "NIE";
    return 0;
}