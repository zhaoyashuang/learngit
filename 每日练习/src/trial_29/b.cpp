#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

constexpr int N = 3e5 + 10, mod = 998244353;

int n, m;
int a[N], b[N];
int s[N][N];

void solve() {
    cin >> n >> m;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans1 ^= a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        ans2 ^= b[i];
    }

    if (ans1 != ans2) {
        cout << "NO" << "\n";
        return;
    }

    for (int i = 1; i < m; i++) {
        s[n][i] = b[i];
    }

    for (int i = 1; i < n; i++) {
        s[i][m] = a[i];
    }

    int temp = a[n];
    for (int i = 1; i < m; i++) {
        temp ^= b[i];
    }
    s[n][m] = temp;
    cout << "YES" << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
