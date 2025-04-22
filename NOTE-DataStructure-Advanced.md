# 数据结构（进阶）

## 树状数组

[树状数组](https://oi-wiki.org/ds/fenwick/)

实现[树状数组](code/binary-indexed-tree.cpp)

### 建树

<img src="https://oi-wiki.org/ds/images/fenwick.svg" style="background-color: white;" alt="Fenwick Tree" />

规定 $c[x]$ 的管辖范围：记 $x$ 二进制最低 `1` 以及后面的 `0` 组成的数为 $\text{lowbit}(x)$，那么 $c[x]$ 管辖的区间就是 $[x-\text{lowbit}(x)+1,x]$。

![tr1](https://cdn.luogu.com.cn/upload/image_hosting/b0cujsbk.png)

![tr2](https://cdn.luogu.com.cn/upload/image_hosting/g43es59o.png)

```cpp

```

### 查询

<img src="https://oi-wiki.org/ds/images/fenwick-query.svg" style="background-color: white;" alt="Fenwick Tree Query" />

```cpp

```

### 修改

```cpp

```

## 线段树

- [线段树基础](https://oi-wiki.org/ds/seg/)

- 实现[基础线段树](code/segment-tree-basic.cpp)

- 实现[基础线段树（无注释）](code/segment-tree-basic-nc.cpp)
