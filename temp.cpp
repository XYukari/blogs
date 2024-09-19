#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], lsh[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        lsh[i] = a[i];
    }

    return 0;
}