#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
int values[MAXN];
int subtreeSize[MAXN];
int start[MAXN], en[MAXN], timer;
int eulerTour[2 * MAXN];
int parent[MAXN];
int n, m;

class SegmentTree {
public:
    SegmentTree(int n) : size(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void update(int l, int r, int value, int node = 0, int start = 0, int en = -1) {
        if (en == -1) en = size - 1;
        push(node, start, en);
        if (start > en || start > r || en < l) return;
        if (start >= l && en <= r) {
            tree[node] += value;
            if (start != en) {
                lazy[node * 2 + 1] += value;
                lazy[node * 2 + 2] += value;
            }
            return;
        }
        int mid = (start + en) / 2;
        update(l, r, value, node * 2 + 1, start, mid);
        update(l, r, value, node * 2 + 2, mid + 1, en);
        tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
    }

    int query(int l, int r, int node = 0, int start = 0, int en = -1) {
        if (en == -1) en = size - 1;
        push(node, start, en);
        if (start > en || start > r || en < l) return INT_MIN;
        if (start >= l && en <= r) return tree[node];
        int mid = (start + en) / 2;
        int leftQuery = query(l, r, node * 2 + 1, start, mid);
        int rightQuery = query(l, r, node * 2 + 2, mid + 1, en);
        return max(leftQuery, rightQuery);
    }

private:
    vector<int> tree, lazy;
    int size;

    void push(int node, int start, int en) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != en) {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
};

SegmentTree segTree(MAXN);

void dfs(int node, int par) {
    start[node] = timer++;
    eulerTour[start[node]] = node;
    subtreeSize[node] = 1;
    parent[node] = par;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
            subtreeSize[node] += subtreeSize[child];
        }
    }
    en[node] = timer - 1;
}

void updatePath(int u, int v, int delta) {
    vector<int> pathU, pathV;
    while (u != -1) {
        pathU.push_back(start[u]);
        u = parent[u];
    }
    while (v != -1) {
        pathV.push_back(start[v]);
        v = parent[v];
    }
    reverse(pathU.begin(), pathU.end());
    reverse(pathV.begin(), pathV.end());

    int lca = 0;
    while (lca < pathU.size() && lca < pathV.size() && pathU[lca] == pathV[lca]) {
        lca++;
    }
    lca--;

    for (int i = 0; i <= lca; ++i) {
        segTree.update(pathU[i], pathU[i], delta);
    }
    for (int i = lca + 1; i < pathU.size(); ++i) {
        segTree.update(pathU[i], pathU[i], delta);
    }
    for (int i = lca + 1; i < pathV.size(); ++i) {
        segTree.update(pathV[i], pathV[i], delta);
    }
}

string compare(int u) {
    int subtreeMax = segTree.query(start[u], en[u]);
    int maxRest = segTree.query(0, MAXN - 1) - subtreeMax;
    if (subtreeMax < maxRest) return "<";
    else if (subtreeMax == maxRest) return "=";
    else return ">";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // DFS để tính chỉ số bắt đầu và kết thúc cho mỗi node
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        segTree.update(start[i], start[i], values[i]);
    }

    cin >> m;
    while (m--) {
        string type;
        cin >> type;
        if (type == "add") {
            int u, v, t;
            cin >> u >> v >> t;
            updatePath(u, v, t);
        } else if (type == "com") {
            int u;
            cin >> u;
            cout << compare(u) << "\n";
        }
    }

    return 0;
}
