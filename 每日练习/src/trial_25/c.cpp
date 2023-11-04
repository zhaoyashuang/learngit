#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

constexpr int N = 3e5 + 10, mod = 998244353;

ll n;
ll d[N], val[N], ans[N];
vector<ll> v[N];
vector<PII> v1[N];

// 初始化时，初始化每一个结点的深度
void dfs(int u, int x, ll sum) {
    sum += val[d[u]]; // sum加上的是深度为u的节点在作为子树时，别的节点对其产生的变化
    for (int i = 0; i < v1[u].size(); i++) {
        sum += v1[u][i].second; // 这个加上的就是以自己为根节点时产生的变化
        if (d[u] + v1[u][i].first + 1 <= n) {
            val[d[u] + v1[u][i].first + 1] -= v1[u][i].second; // 维护差分数组，大于这个深度的点需要减去这一部分贡献。
        }
    }
    ans[u] = sum; // 该节点为根，别的结点无法对其产生影响
    for (int i = 0; i < v[u].size(); i++) {
        int k = v[u][i];
        if (k == x) {
            continue;
        }
        d[k] = d[u] + 1;
        dfs(k, u, sum);
    }

    for (int i = 0; i < v1[u].size(); i++) {
        if (d[u] + v1[u][i].first + 1 <= n) {
            val[d[u] + v1[u][i].first + 1] += v1[u][i].second; // 回溯时维护下差分数组，在递归时，对其产生的影响需要减去，就是加上原来减去的部分
        }
    }
}

void solve() {
    cin >> n;
    int x, y;
    int k = n - 1;
    while (k--) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int m;
    cin >> m;
    ll q;
    ll l, r;
    for (int i = 1; i <= m; i++) {
        cin >> q >> l >> r;
        v1[q].push_back({l, r}); // 存储以 q 为根节点时，他能给最大深度为多少的节点产生影响
    }

    d[1] = 1;
    dfs(1, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
