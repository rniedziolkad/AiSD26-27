#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long** d = new long long*[n + 1];
    for (int i = 1; i <= n; ++i) {
        d[i] = new long long[n + 1];
        for (int j = 1; j <= n; ++j) {
            d[i][j] = __INT64_MAX__;
            if (i == j) d[i][j] = 0;
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < d[a][b]) d[a][b] = c;
    }

    // algorytm Floyda-Warshalla
    for (int u = 1; u <=n; ++u) {
        for (int v1 = 1; v1 <= n; ++v1) {
            for (int v2 = 1; v2 <= n; ++v2) {
                if (d[v1][u] == __INT64_MAX__ || d[u][v2] == __INT64_MAX__) continue;

                long long dist = d[v1][u] + d[u][v2];
                if (dist < d[v1][v2]) d[v1][v2] = dist;
            }
        }
    }

    // wyświetlanie wyniku
    for (int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if (d[i][j] == __INT64_MAX__) {
                cout << "BRAK ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << '\n';
        delete[] d[i];
    }
    delete[] d;

    return 0;
}
