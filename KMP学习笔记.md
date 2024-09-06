## 一、问题

给出两个字符串 $s1$ 和 $s2$，若 $s1$ 的区间 $[l,r]$ 子串与 $s2$ 完全相同，则称 $s2$ 在 $s1$ 中出现了，其出现位置为 $l$。
现在请你求出 $s2$ 在 $s1$ 中所有出现的位置。

（我们把 $s2$ 称作模式串，把 $s1$ 称为文本串， $s1$ 可能非常长）

## 二、暴力

显然，我们可以两层循环，枚举起始位置，然后一一比较，如果失配就 continue 到下一个位置。它的时间复杂度是 $O(nm)$ 。

```pascal
for i:=1 to n do
begin
	for j:=1 to m do
	begin
		 if a[i+j-1]<>b[j] then break;
		 if j=m writeln(i);
	end;
end; 
```


## 三、优化

考虑这个暴力慢在什么地方：每一次失配后， $i$ 和 $j$ 两个指针都要回跳。如果能保证 $i$ 指针单调不减，**只移动 $j$ 指针**，就会快很多——时间复杂度变成了 $O(n+m)$ 。

这当然是可行的，观察下面这组样例：

```c
A B A C
A B A B A C A
```

在第4位失配后，如果只移动模式串，可以直接把模式串的第2位移动到与文本串的第4位对齐，如下：

```c
* * A B A C
A B A B A C A
```

这是用肉眼看出来的结果，怎么让程序知道，在第 j 位失配后，应该跳到第几位？我们想到可以预处理出一个移动数组 $nxt$ 来解决这个问题。

---

为保证**正确性**，$nxt$ 数组有如下**三条性质**：

1. $nxt_1=0$;

2. $s2_{nxt_j}=s2_j$;

3. $\forall i\in [1,n], j\in [1,nxt_i], s2_{j}=s2_{i-nxt_i+j}$。

如果得到了这个数组，在 $i$ 和 $j+1$ 失配时，就只需使 $j\gets nxt_j$，$i$ 不需改变。 

#### 四、 代码实现

假装已经知道了 $nxt$ 数组，用下面这段代码就能轻松求出 $s2$ 在 $s1$ 的位置。

```pascal
j:=0;
for i:=1 to length(a) do
begin
	while(j>0) and (a[i]<>b[j+1]) do
            j:=nxt[j];
	if a[i]=b[j+1] then inc(j);
	if j=length(b) then
	begin
		writeln(i-length(b)+1);
		j:=nxt[j];
    end;
end;
```

怎么求出 $nxt$ 数组呢？用模式串跟自己匹配即可，只需把最后一个 if 语句改为 `nxt[i]:=j` 。代码如下：

```pascal
nxt[1]:=0;
for i:=2 to length(b) do
begin
	while(j>0) and (b[i]<>b[j+1]) do 
           j:=nxt[j];
	if b[i]=b[j+1] then inc(j);
	nxt[i]:=j;
end;
```

这样做是正确的，因为跑到 `nxt[i]:=j` 这句话，说明前面一定已经匹配好了，符合前文的两条性质。

求这个竟然也有模板：[P4391 [BOI2009]Radio Transmission 无线传输](https://www.luogu.com.cn/problem/P4391)


## 四、代码

[P3375 【模板】KMP字符串匹配](https://www.luogu.com.cn/problem/P3375)

```pascal
var
	a,b:ansistring;
	i,j:longint;
	nxt:array[0..1000010] of longint;
begin
	readln(a);
	readln(b);
	nxt[1]:=0;
	for i:=2 to length(b) do
	begin
		while(j>0) and (b[i]<>b[j+1]) do 
            j:=nxt[j];
		if b[i]=b[j+1] then inc(j);
		nxt[i]:=j
	end;
	j:=0;
	for i:=1 to length(a) do
	begin
		while(j>0) and (a[i]<>b[j+1]) do
            j:=nxt[j];
		if a[i]=b[j+1] then inc(j);
		if j=length(b) then
		begin
			writeln(i-length(b)+1);
			j:=nxt[j];
        end;
	end;
	for i:=1 to length(b) do
		write(nxt[i],' ');
    writeln;
end.
```