#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<vector<int>>& tree, int v) {
    cout << v << " ";
    for (int child : tree[v]) {
        preorder(tree, child);
    }
}

void postorder(vector<vector<int>>& tree, int v) {
    for (int child : tree[v]) {
        postorder(tree, child);
    }
    cout << v << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);    // tree[i] -- lista (wektor) dzieci wierzchołka i
    int parent_i;
    for (int i = 1; i <= n; ++i) {
        cin >> parent_i;
        tree[parent_i].push_back(i);
    }

    postorder(tree, 0);
    return 0;
}