/**
 *    author: A K M S Limon
 *    created: 10-March-2024  13:32:12
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, pair<string, int>>> v;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string process;
        int at, bt;
        cin >> process;
        cin >> at >> bt;
        v.push_back(make_pair(at, make_pair(process, bt)));
    }
    sort(v.begin(), v.end());
    int ct[n + 1], tat[n + 1], wt[n + 1];
    int start = 0;
    for (int i = 0, j = 0; i < n; i++) {
        start = max(j, v[i].first);
        ct[i + 1] =  start + v[i].second.second;
        j = start + v[i].second.second;
    }
    for (int i = 1; i <= n; i++) {
        tat[i] = ct[i] - v[i - 1].first;
        wt[i] = tat[i] - v[i - 1].second.second;
    }
    cout << "Process\t\t" << "AT\t" << "BT\t" << "CT\t" << "TAT\t" << "WT\t" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << v[i - 1].second.first << "\t\t" << v[i - 1].first << "\t" << v[i - 1].second.second << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << '\n';
    }
    return 0;
}
