/**
 *    author: A K M S Limon
 *    created: 05-November-2024  10:03:13
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, q; cin >> n >> k >> q;
    int a[n][k];
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            if (i) {
                a[i][j] |= a[i - 1][j];
            }
            v[j][i] = a[i][j];
        }
    }
    while (q--) {
        int m; cin >> m;
        int ans1 = 0, ans2 = n;
        while (m--) {
            int r; cin >> r;
            char ch; cin >> ch;
            int value; cin >> value;
            if (ch == '>') {
                ans1 = max(ans1, int(upper_bound(v[r - 1].begin(), v[r - 1].end(), value) - v[r - 1].begin()));
            }
            else {
                ans2 = min(ans2, int(lower_bound(v[r - 1].begin(), v[r - 1].end(), value) - v[r - 1].begin()));
            }
        }
        cout << ((ans1 < ans2) ? ans1 + 1 : -1) << '\n';
    }
    return 0;
}