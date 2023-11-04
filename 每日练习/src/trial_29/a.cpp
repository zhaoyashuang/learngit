#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;

int n;
string s;
int x, y;
int sumx[N], sumy[N];

int check(int mid) {
    for(int l = 1; l + mid - 1 <= n; l++) {
        int r = l + mid - 1;
        //不需要修改的区间长度
        int xx = sumx[l - 1] + sumx[n] - sumx[r];
        int yy = sumy[l - 1] + sumy[n] - sumy[r];
        //需要修改的
        int sum = abs(xx - x) + abs(yy - y);
        if (sum <= mid && (mid - sum) % 2 == 0) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n;
    cin >> s;
    cin >> x >> y;
    s = " " + s;
    int x1 = 0, y1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') {
           sumy[i] = sumy[i - 1] + 1;
           sumx[i] = sumx[i - 1];
           y1 += 1;
        } else if (s[i] == 'D') {
            sumy[i] = sumy[i - 1] - 1;
            sumx[i] = sumx[i - 1];
            y1 -= 1;
        } else if (s[i] == 'R') {
            sumx[i] = sumx[i - 1] + 1;
            sumy[i] = sumy[i - 1];
            x1 += 1;
        } else if (s[i] == 'L') {
            sumx[i] = sumx[i - 1] - 1;
            sumy[i] = sumy[i - 1];;
            x1 -= 1;
        }
    }

    if (x1 == x && y1 == y) {
        cout << 0 << "\n";
        return;
    }

    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
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
