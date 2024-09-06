[考查异或的基本性质。](https://codeforces.com/problemset/problem/1872/E "考查异或的基本性质。")

对于操作2，用两个变量 $X_0,X_1$ 记录 $s_i=0/1$ 位置的异或和，在查询时直接输出即可。那么，在操作 1 如何更新 $X_0,X_1$？

如果操作 1 只改变一个数，比如将 $s_i$ 从 $0$ 改为 $1$，那么我们只需将 $a_i$ 从 $X_0$ 中消除，并异或入 $X_1$。如何消除？因为**一个数和自身异或结果为 $0$**，所以直接令 $X_0=X_0\oplus a_i$ 即可。不难发现，异或和“撤销异或”的操作是相同的，我们同时对 $X_1$ 的操作也是 $X_1=X_1\oplus a_i$。

现在操作 1 对一个区间取反，我们的操作变成 $X_0=X_0\oplus (a_l+\cdots+a_r),X_1=X_1\oplus (a_l+\cdots+a_r)$，其中 $(a_l+\cdots+a_r)$ 显然可以用前缀和维护，总复杂度为 $O(q)$。

下面是 AC 代码：

```cpp
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
    }
    int x0 = 0, x1 = 0;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            x0 ^= a[i];
        } else {
            x1 ^= a[i];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r;
            cin >> l >> r;
            x0 ^= p[r] ^ p[l - 1];
            x1 ^= p[r] ^ p[l - 1];
        } else {
            int g;
            cin >> g;
            cout << (g ? x1 : x0) << " ";
        }
    }
    cout << endl;
}
```