#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<vector<int>>& tree, int v) {
    for(int child : tree[v]) {
        preorder(tree, child);
    }
    cout << v << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);    // dla każdego wierzchołka v = {0..=N} przechowuje listę indeksów dzieci
    int parent_i;
    for (int i = 1; i <= n; ++i) {
        cin >> parent_i;
        tree[parent_i].push_back(i);
    }
    preorder(tree, 0);

    return 0;
}