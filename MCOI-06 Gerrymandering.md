给定正整数 $n,m,k$ 能否将一个 $n\times m$ 表格染色，使得每一个颜色形成恰好一个连通块，并且每一个连通块大小为 $k$。如果存在，构造一个合法方案。

对于矩形涂色，使其形成连通块一个，一个常见思路是**走蛇形路线**：从第一行左端开始涂色，走到行末跳到下一行反向涂，涂 $k$ 个格子换色。显然，如果 $n\times m$ 能被 $k$ 整除，则可以完成涂色。如下图所示：

![](https://cdn.luogu.com.cn/upload/image_hosting/t9v11txo.png)


所以，对于样例`4 3 2`而言，我们涂色结果是这样的：

```c
1 1 2 
3 3 2
4 4 5
6 6 5
```

需要注意 $\sum n\times m \le 10^6$，所以不能直接开二维数组（MLE），可以开一个一维的 $10^6$ 的数组，只存当前行的颜色。

AC 代码：
```cpp
if (n * m % k != 0) { puts("NO"); return; }
puts("YES");
int col = 1, cnt = k; // 当前颜色 & 当前颜色还需要涂几格
for (int i = 1; i <= n; i++) {
    if (i & 1) { // 奇数行从左往右
        for (int j = 1; j <= m; j++) {
            a[j] = col;
            if (--cnt == 0) cnt = k, col++; // 行末换行
        } continue;
    }
    // 偶数行从右往左
    for (int j = m; j; j--) {
        a[j] = col;
        if (--cnt == 0) cnt = k, col++;
    }
    for (int j = 1; j <= m; j++) printf("%d ", a[j]);
    puts("");
}
```

[CF1254A](http://www.luogu.com.cn/problem/CF1254A "CF1254A")和这道题的构造思路比较相似。