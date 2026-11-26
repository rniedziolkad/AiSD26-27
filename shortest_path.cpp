#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int bfs(vector<vector<int>>& graph, int start, int end) {
    vector<int> dist(graph.size(), -1);
    dist[start] = 0;

    queue<int> q;
    q.push(start);
    while (!q.empty()){
        int current = q.front();
        q.pop();
        if (current == end) {
            return dist[current];
        }
        for (int neighbor : graph[current]) {
            if (dist[neighbor] != -1) continue;

            q.push(neighbor);
            dist[neighbor] = dist[current] + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    // wczytywanie grafu
    vector<vector<int>> adj(V);
    while (E--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int start, end;
    cin >> start >> end;

    cout << bfs(adj, start, end);

    return 0;
}
