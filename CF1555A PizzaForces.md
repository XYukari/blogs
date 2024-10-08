3 个购买方案中做一块披萨的时间都是 2.5 分钟，只需考虑怎样用 6, 8, 10 组合出大于等于 $n$ 且最小的数。

可以证明，这三个数可以组合成不小于 6 的所有偶数：

- 对于不小于 6 的任意偶数 $n$，它都可以被表示为 $6 \times a + b$ 的形式，其中 $a \in \mathbb{N}$ 且 $b \in \{0,2,4\}$。
- 当 $b=0$ 时，$n$ 能被 6 整除；当 $b=2$ 时，$n$ 能被 8 整除；而当 $b=4$ 时，$n$ 能被 10 整除。。

得到该性质后，分类讨论：

1. 若 $n<6$，直接输出 15；
2. 若 $n \ge 6$ 且 $n$ 为奇数，$n \gets n+1$，转到情况 3。
3. 若 $n \ge 6$ 且 $n$ 为偶数，在 6 块的基础上，**每多 2 块就要加 5 分钟**，即 $(n-6) \times \dfrac{5}{2} + 15$