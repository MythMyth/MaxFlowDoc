#include <bits/stdc++.h>

using namespace std;

class MaxFlow {
    public:
    vector<vector<int>> conn;
    int source, sink;

    MaxFlow(int node) {
        conn = vector<vector<int>>(node, vector<int>(node, 0));
        source = 0; sink = node - 1;
    }

    void addEdge(int start, int end, int val) {
        conn[start][end] = val;
    }

    bool bfs(vector<int> &parent) {
        int n = conn.size();
        vector<bool> visited(n,false);
        queue<int> travel;
        travel.push(source);
        visited[source] = true;
        while(!travel.empty()) {
            int node = travel.front();
            travel.pop();
            for(int i = 0; i < n; i++) {
                if(conn[node][i] == 0 || visited[i]) continue;
                visited[i] = true;
                parent[i] = node;
                if(i == sink) return true;
                travel.push(i);
            }
        }
        return false;
    }

    int flow() {
        int n = conn.size();
        vector<int> parent(n);
        int ret = 0;
        while(bfs(parent)) {
            int curr = sink;
            int fl = INT_MAX;
            while(curr != source) {
                int par = parent[curr];
                fl = min(fl, conn[par][curr]);
                curr = par;
            }
            ret += fl;
            curr = sink;
            while(curr != source) {
                int par = parent[curr];
                conn[par][curr] -= fl;
                conn[curr][par] += fl;
                curr = par;
            }
        }
        return ret;
    }

};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t-- > 0) {
        int n; cin >> n;
        MaxFlow flow_graph(n + 2);
        int pos_sum = 0;
        for(int i = 1; i <= n; i++) {
            int score; cin >> score;
            if(score < 0) {
                flow_graph.addEdge(i, flow_graph.sink, -score);
            } else {
                flow_graph.addEdge(flow_graph.source, i, score);
                pos_sum += score;
            }
        }
        for(int i = 1; i <= n; i++) {
            int depend; cin >> depend;
            for(int b = 0; b <depend; b++) {
                int bn; cin >> bn;
                flow_graph.addEdge(i, bn, INT_MAX);
            }
        }
        cout << pos_sum - flow_graph.flow() << "\n";
    }
    return 0;
}

