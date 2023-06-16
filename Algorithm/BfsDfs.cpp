#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<char, list<char>> g;
    unordered_map<char, bool> visited;
    int v, ed;

   public:
    void read() {
        ifstream file("input.txt");

        int v, ed;
        file >> v >> ed;
        this->v = v;
        this->ed = ed;
        string line;
        while (getline(file, line)) {
            char st = line[0];
            for (int i = 1; i < line.size(); i++) {
                if (line[i] == ' ') {
                    continue;
                } else {
                    addEdges(st, line[i]);
                }
            }
        }
    }

    void addEdges(char a, char b) {
        g[a].push_back(b);
    }

    void bfs(char st) {
        queue<char> qu;
        unordered_map<char, bool> visit;

        qu.push(st);
        visit[st] = true;

        while (!qu.empty()) {
            char fnt = qu.front();
            qu.pop();
            cout << fnt << " ";

            for (auto node : g[fnt]) {
                if (!visit[node]) {
                    qu.push(node);
                    visit[node] = true;
                }
            }
        }

        cout << endl;
    }

    void dfs(char st) {
        cout << st << " ";
        visited[st] = true;

        for (auto node : g[st]) {
            if (!visited[node]) {
                dfs(node);
            }
        }
    }

    void printGraph() {
        for (auto no : g) {
            cout << no.first << ": ";
            for (auto el : no.second) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph gp;
    gp.read();
    cout << "BFS: ";
    gp.bfs('a');

    cout << "DFS: ";
    gp.dfs('a');
    cout << endl;

    return 0;
}