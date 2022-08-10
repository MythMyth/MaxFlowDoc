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
    int agroup[4] = {1, 3, 5, 7};
    int bgroup[4] = {2, 3, 6, 7};
    int cgroup[4] = {4, 5, 6, 7};
    int t; cin >> t;
    while(t-- > 0) {
        int n, na, nb, nc;
        cin >> n >> na >> nb >> nc;
        int ma, mb, mc;
        vector<int> demand(n + 1, 0);
        cin >> ma;
        for(int i = 0; i < ma; i++) {
            int v; cin >> v;
            demand[v] += 1;
        }
        cin >> mb;
        for(int i = 0; i < mb; i++) {
            int v; cin >> v;
            demand[v] += 2;
        }
        cin >> mc;
        for(int i = 0; i < mc; i++) {
            int v; cin >> v;
            demand[v] += 4;
        }

        vector<vector<int>> group(8);
        for(int i = 1; i <= n; i++) {
            group[demand[i]].push_back(i);
        }
        MaxFlow flow_graph(12);
        for(int i = 1; i <= 7; i++) {
            flow_graph.addEdge(flow_graph.source, i, group[i].size());
        }
        for(int i = 0; i < 4; i++) {
            flow_graph.addEdge(agroup[i], 8, group[agroup[i]].size());
            flow_graph.addEdge(bgroup[i], 9, group[bgroup[i]].size());
            flow_graph.addEdge(cgroup[i], 10, group[cgroup[i]].size());
        }

        flow_graph.addEdge(8, flow_graph.sink, na);
        flow_graph.addEdge(9, flow_graph.sink, nb);
        flow_graph.addEdge(10, flow_graph.sink, nc);

        cout << flow_graph.flow() << "\n";

        for(int i = 0; i < 4; i++) {
            int vgr = agroup[i];
            int vn = flow_graph.conn[8][vgr];
            while(vn-- > 0) {
                cout << *group[vgr].rbegin() << " A\n";
                group[vgr].pop_back();
            }

            vgr = bgroup[i];
            vn = flow_graph.conn[9][vgr];
            while(vn-- > 0) {
                cout << *group[vgr].rbegin() << " B\n";
                group[vgr].pop_back();
            }

            vgr = cgroup[i];
            vn = flow_graph.conn[10][vgr];
            while(vn-- > 0) {
                cout << *group[vgr].rbegin() << " C\n";
                group[vgr].pop_back();
            }
        }
    }
    return 0;
}

