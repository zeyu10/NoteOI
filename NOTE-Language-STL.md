# 语法（包含 STL 库）

## STL

### 01. vector

| Statement | Action |
|---|---|
| type v[index] | 获取 v 中第 index 个元素。 |
| v.push_back(type item) | 向 v 后面添加⼀个元素 item。 |
| v.pop_back() | 删除 v 最后⼀个元素。 |
| v.size() | 获取 v 中元素个数，返回 size_type 类型。 |
| v.resize(int n) | 把 v 的⻓度设定为 n 个元素。 |
| v.empty() | 判断 v 是否为空，空返回 1，不空返回 0。 |
| v.clear() | 清空 v 中的元素。 |
| v.insert(iterator it, type item) | 向迭代器 it 指向元素前增加一个元素 item。 |
| v.erase(iterator it) | 删除向量中迭代器指向元素。 |
| v.front() | 返回首元素的引用。 |
| v.back() | 返回尾元素的引用。 |
| v.begin() | 返回首迭代器，指向第一个元素。 |
| v.end() | 返回尾迭代器，指向向量最后一个元素的下一个位置。 |

### 02. set

| Statement | Action |
|---|---|
| s.insert(type item) | 在 s 中插⼊⼀个元素。 |
| s.size() | 获取 s 中元素个数。 |
| s.empty() | 判断 s 是否为空。 |
| s.clear() | 清空 s。 |
| s.find(type item) | 在 s 中查找⼀个元素并返回其迭代器，找不到的话返回 s.end()。 |
| s.begin() | 返回 s 中最小元素的迭代器，只可以用到 -- 和 ++。 |
| s.end() | 返回 s 中最大元素的迭代器的后一个迭代器。 |
| s.count(type item) | 返回 s 中 item 的数量。返回值只能是 0 或 1，在 multiset 中会返回存的个数。 |
| s.erase(position) | 删除 s 中迭代器 position 对应位置的元素。 |
| s.erase(type item) | 删除 s 中对应元素。 |
| s.erase(pos1, pos2) | 删除 [pos1, pos2) 这个区间的位置的元素。 |
| s.lower_bound(type item) | 返回 s 中第一个大于等于 item 的元素的迭代器，找不到就返回 s.end()。 |
| s.upper_bound(type item) | 返回 s 中第一个大于 item 的元素的迭代器，找不到就返回 s.end()。 |

### 03. multiset

| Statement | Action |
|---|---|
| ms.count(type item) | 返回 ms 中 item 的数量。 |

### 04. map

| Statement | Action |
|---|---|
| mp.size() | 获取 mp 中元素个数。 |
| mp.empty() | 判断 mp 是否为空，空返回 1，不空返回 0。 |
| mp.clear() | 清空 mp。 |
| mp.begin() | 返回 mp 中最小 key 的迭代器，只可以用到 -- 和 ++ 操作。 |
| mp.end() | 返回 mp 中最大 key 的迭代器的后一个迭代器。 |
| mp.find(key) | 在 mp 中查找⼀个 key 并返回其 iterator，找不到的话返回 s.end()。 |
| mp.count(key) | 在 mp 中查找 key 的数量，只会返回 0 或 1。 |
| mp.erase(key) | 在 mp 中删除 key 所在的项，key 和 value 都会被删除。 |
| mp.lower_bound(type item) | 返回 mp 中第一个 key 大于等于 item 的迭代器，找不到就返回 mp.end()。 |
| mp.upper_bound(type item) | 返回 mp 中第一个 key 大于 item 的迭代器，找不到就返回 mp.end()。 |
| mp[key] | 返回 mp 中 key 对应的 value。如果 key 不存在，则返回 value 类型的默认构造器 (default constructor) 所构造的值，并该键值对插⼊到 mp 中。 |
| mp[key] = value | 如果 mp 中找不到对应的 key 则将键值对 (key: value) 插⼊到 mp 中，如果存在 key 则将这个 key 对应的值改变为 value。 |

### 05. stack (LIFO)

| Statement | Action |
|---|---|
| s.top() | 返回一个栈顶元素的引用。 |
| s.push(type item) | 可以将 item 压入栈顶。 |
| s.pop() | 弹出栈顶元素。 |
| s.size() | 返回栈中元素的个数。 |
| s.empty() | 判断 s 是否为空，空返回 1，不空返回 0。 |

### 06. queue (FIFO)

| Statement | Action |
|---|---|
| q.push(type item) | 在 q 的最后添加⼀个 type 类型元素 item。 |
| q.pop() | 使 q 最前面的元素出队。 |
| q.front() | 获取 q 最前面的元素。 |
| q.size() | 获取 q 中元素个数。 |
| q.empty() | 判断 q 是否为空，空返回 1，不空返回 0。 |

### 07. priority_queue

```text
数字大的优先级越大（越小越往后）：priority_queue<int, vector<int>, less<int> > q;
数字小的优先级越大（越大越往后）：priority_queue<int, vector<int>, greater<int> > q;
```

| Statement | Action |
|---|---|
| q.top() | 返回优先队列对顶元素，返回优先队列中有最高优先级的元素。 |

### 08. deque

| Statement | Action |
|---|---|
| d.push_back(type item) | 向 d 后面添加⼀个元素 item。 |
| d.push_front(type item) | 向 d 前面添加⼀个元素 item。 |
| d.pop_back() | 删除 d 最后⼀个元素。 |
| d.pop_front() | 删除 d 最前面的元素。 |
| d.size() | 获取 d 中元素个数。 |
| d.empty() | 判断 d 是否为空，空返回 1，不空返回 0。 |
| d.clear() | 清空 d。 |
| d.begin() | 返回 d 中最前面元素的迭代器，只可以用到 -- 和 ++。 |
| d.end() | 返回 d 中最后⼀个元素的后⼀个位置的迭代器。 |
| d.front() | 返回 d 中最前面元素的引用。 |
| d.back() | 返回 d 中最后⼀个元素的引用。 |
| d.insert(iterator it, type item) | 向迭代器 it 指向元素前增加一个元素 item。 |
| d.erase(iterator it) | 删除向量中迭代器 it 指向元素。 |
| d.erase(pos1, pos2) | 删除 [pos1, pos2) 这个区间的位置的元素。 |

### 09. pair

| Statement | Action |
|---|---|
| pair<type1, type2> p; | 定义一个 pair 变量 p，p 的类型是 pair<type1, type2>。 |
| p.first | 获取 p 的第一个元素。 |
| p.second | 获取 p 的第二个元素。 |

### 10. string

| Statement | Action |
|---|---|
| s.size() | 获取 s 中元素个数。 |
| s.empty() | 判断 s 是否为空，空返回 1，不空返回 0。 |
| s.clear() | 清空 s。 |
| s.begin() | 返回 s 中最前面元素的迭代器，只可以用到 -- 和 ++。 |
| s.end() | 返回 s 中最后⼀个元素的后⼀个位置的迭代器。 |
| s.front() | 返回 s 中最前面元素的引用。 |
| s.back() | 返回 s 中最后⼀个元素的引用。 |
| s.substr(pos, len) | 返回 s 中从 pos 开始的 len 个字符组成的字符串。 |
| s.push_back(type item) | 将 item 添加到 s 的末尾。 |
| s.pop_back() | 删除 s 的末尾元素。 |
| s.swap(type item) | 将 s 和 item 交换。 |
| s.copy(type item, pos, len) | 将 s 的 pos 位置开始的 len 个字符复制到 item 中。 |
| s.erase(pos) | 删除向量中迭代器 pos 指向元素。 |
| s.erase(pos, len) | 删除 s 的 pos 位置开始的 len 个字符。 |
| s.erase(pos1, pos2) | 删除 [pos1, pos2) 这个区间的位置的元素。 |
| s.find(type item) | 在 s 中查找⼀个元素并返回其迭代器，找不到的话返回 s.end()。 |
| s.find(type item, pos) | 从 s 的 pos 位置开始查找 item 并返回其迭代器，找不到的话返回 s.end()。 |
| s.compare(type item) | 比较 s 和 item，如果 s 大于 item 则返回 1，如果 s 小于 item 则返回 -1，如果 s 等于 item 则返回 0。 |
| s.compare(type item, pos, len) | 比较 s 和 item 的 pos 位置开始的 len 个字符，如果 s 大于 item 则返回 1，如果 s 小于 item 则返回 -1，如果 s 等于 item 则返回 0。 |
| s.append(type item) | 将 item 添加到 s 的末尾。 |
| s.append(type item, pos, len) | 将 item 的 pos 位置开始的 len 个字符添加到 s 的末尾。 |
| s.insert(pos, type item) | 将 item 插入到 s 的 pos 位置。 |
| s.insert(pos, type item, pos2, len2) | 将 item 的 pos2 位置开始的 len2 个字符插入到 s 的 pos 位置。 |
| s.replace(pos, len, type item) | 将 s 的 pos 位置开始的 len 个字符替换为 item。 |
| s.replace(pos, len, type item, pos2, len2) | 将 s 的 pos 位置开始的 len 个字符替换为 item 的 pos2 位置开始的 len2 个字符。 |

## 常用 STL 函数

01. `min(x, y)` ：求两个元素的最小值。

02. `max(x, y)` ：求两个元素的最大值。

03. `swap(x, y)` ：交换两个元素。

04. `find(begin, end, x)` ：返回指向区间 [begin, end) 第 1 个值为 x 的元素指针。如果没找到，则返回 end。

05. `count(begin, end, x)` ：返回指向区间 [begin, end) 值为 x 的元素数量，返回值为整数。

06. `reverse(begin, end)` ：翻转一个序列。

07. `random_shuffle(begin, end)` ：随机打乱一个序列。

08. `unique(begin, end)` ：将连续的相同元素压缩为一个元素，返回去重后的尾指针。不连续的相同元素不会被压缩因此一般先排序后去重。

09. `fill(begin, end, val)` ：将区间 [begin, end) 的每个元素都设置为 val。

10. `sort(begin, end, compare)` ：对一个序列排序，参数 begin 和 end 表示待排序数组的首地址和尾地址；compare 表示排序的比较函数，可省略，默认为好序。`stable_sort(begin, end, compare)` 为稳定排序，即保持相等元素的相对顺序。

11. `nth_element(begin, begin + k, end, compare)` ：使区间 [begin, end) 第 k 小的元素处在第k个位置上，左边元素都小于或等于它，右边元素都大于或等于它，但并不保证其他元素有序。

12. `lower_bound(begin, end, x) / upper_bound(begin, end, x)` ：利用二分查找的方法，在有序数组中查找第1个满足条件（$\geqslant$、$\gt$）的元素，返回指向该元素的指针。

13. `next_permutation(begin, end) / pre_permutation(begin, end)` ：next_permutation() 是求按字典序的下一个排列的函数；pre_permutation() 是求按字典序的上一个排列的函数。

14. `binary_search(begin, end, x)` ：利用二分查找的方法，在有序数组中查找第 1 个满足条件（$\geqslant$、$\gt$）的元素，返回值为布尔值。

### binary_search

```cpp
binary_search(a, a + n, x);
binary_search(v.begin(), v.end(), x);
binary_search(v.begin() + l, v.begin() + r, x);
```

### lower_bound

意思是“下界”（在左侧），这个数出现的位置最靠前也就是这个位置了，也就是第一个大于等于这个数的位置。

```cpp
lower_bound(a, a + n, x) - a;
lower_bound(v.begin(), v.end(), x) - v.begin();
```

### upper_bound

意思是“上界”（在右侧），这个数出现的位置不能在这个位置及以后了，也就是第一个大于这个数的位置。

```cpp
upper_bound(a, a + n, x) - a;
upper_bound(v.begin(), v.end(), x) - v.begin();
```

## 重载运算符

```cpp
struct Data {
    int a, b;

    bool operator<(const Data rhs) const {
        return (a == rhs.a) ? (b < rhs.b) : (a < rhs.a);
    }
} data[1000];

bool cmp(const Data x, const Data y) {
    return (x.a == y.a) ? (x.b < y.b) : (x.a < y.a);
}

// ...
vector<Data> v;
v.push_back({1, 2});
v.push_back({2, 1});
v.push_back({1, 1});
v.push_back({2, 2});
std::sort(v.begin(), v.end());  // 使用结构体中定义的 < 运算符，从小到大排序
std::sort(v.begin(), v.end(), cmp);  // 使用 cmp 函数进行比较，从小到大排序
```

```output
1 1
1 2
2 1
2 2
```

## 常用数学函数

```cpp
// 计算浮点值 arg 的绝对值。
double abs(double arg);
// 计算 base 的 exp 或 iexp 次幂。
double pow(double base, double exp);
// 计算 arg 的平方根。
double sqrt(double arg);
// 计算 arg 的立方根。
double cbrt(double arg);
// 计算 x 与 y 平方和的平方根，而不会在计算的中间阶段有过度的上溢或下溢。
double hypot(double x, double y);
// 计算不小于 arg 的最小整数值。（上取整）
double ceil(double arg);
// 计算不大于 arg 的最大整数值。（下取整）
double floor(double arg);
// 计算 arg 的最接近整数值（以浮点格式），中点情况舍入为远离零，无关乎当前舍入模式。（四舍五入取整）
double round(double arg);
```

## File

```cpp
freopen("data.in", "r", stdin);
freopen("data.out", "w", stdout);
```

## 迭代器（iterator）

### string

```cpp
// 1. 使用索引遍历
for (int i = 0; i < str.size(); ++i) {
    cout << str[i] << " ";
}
// 2. 使用范围 for 循环
for (char c : str) {
    cout << c << " ";
}
for (auto c : str) {
    cout << c << " ";
}
// 3. 使用迭代器遍历
for (string::iterator it = str.begin(); it != str.end(); ++it) {
    cout << *it << " ";
}
for (auto it = str.begin(); it != str.end(); ++it) {
    cout << *it << " ";
}
```

### vector

```cpp
// 1. 使用索引遍历
for (int i = 0; i < vec.size(); ++i) {
    cout << vec[i] << " ";
}
// 2. 使用范围 for 循环
for (int i : vec) {
    cout << i << " ";
}
for (auto i : vec) {
    cout << i << " ";
}
// 3. 使用迭代器遍历
for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
}
for (auto it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
}
```

### 迭代器复杂使用场景

#### 1. 使用 set 和 struct

```cpp
#include <iostream>
#include <set>
using namespace std;
struct Point {
    int x, y;
    // 注意 const
    bool operator<(const Point &rhs) const {
        return (x == rhs.x ? y < rhs.y : x < rhs.x);
    }
};
int main() {
    int n;
    set<Point> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point temp;
        cin >> temp.x >> temp.y;
        v.insert(temp);
    }
    // 注意 set<T> 中 T 的类型
    for (set<Point>::iterator it = v.begin(); it != v.end(); it++) {
        cout << it->x << " " << it->y << endl;
    }
    return 0;
}

```

#### 2. 使用 multiset

```cpp
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> se;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se.insert(x);
    }
    while (m--) {
        int x;
        cin >> x;
        multiset<int>::iterator it = se.lower_bound(x);
        if (it == se.end()) {
            cout << -1 << endl;
        } else {
            cout << *it << endl;
            se.erase(it);
        }
    }
    return 0;
}
```

#### 3. 使用二维 map

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    // 理解 map<key, val> mp 以及 mp[key] = val
    // 按照 info[class_id][name] = value 的顺序从左到右声明 info
    // 最终操作的是 info->second->second 的 value
    map<int, map<string, int> > info;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int class_id;
        string name;
        cin >> class_id >> name;
        info[class_id][name]++;
    }
    // 注意 first 与 second 为元素
    // 不需要附加括号
    for (map<int, map<string, int> >::iterator it1 = info.begin(); it1 != info.end(); it1++) {
        for (map<string, int>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
            cout << "There are " << it2->second << " people named " << it2->first << " in class " << it1->first << endl;
        }
    }
    // 使用 auto 改写（C++14）
    for (auto it1 = info.begin(); it1 != info.end(); it1++)
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
    return 0;
}
```

## Lambda 表达式

### 概述

在 C++11 及更高版本中，Lambda 表达式（通常称为 Lambda）是一种定义匿名函数对象（闭包）的简便方法。它们通常用于封装传递给算法或异步函数的少量代码行。Lambda 表达式的基本语法如下：

```cpp
[capture](parameters) -> return_type {
    // function body
};
```

- **capture**：捕获列表，指定哪些外部变量以及如何捕获（通过值或引用）。
- **parameters**：参数列表，指定传递给 Lambda 的参数。
- **return_type**：返回类型，可以省略，编译器会自动推导。
- **function body**：函数体，包含要执行的代码。

---

### 示例

1. 简单的Lambda表达式

    ```cpp
    #include <iostream>

    int main() {
        auto add = [](int a, int b) { return a + b; }; // 定义一个加法的Lambda表达式
        std::cout << add(3, 4) << std::endl;           // 输出：7
        return 0;
    }
    ```

2. 使用捕获外部变量

    ```cpp
    #include <iostream>

    int main() {
        int x = 10;
        int y = 20;

        auto multiply = [x, y]() { return x * y; };  // 捕获x和y
        std::cout << multiply() << std::endl;        // 输出：200

        return 0;
    }
    ```

3. 按引用捕获外部变量

    ```cpp
    #include <iostream>

    int main() {
        int x = 5;

        auto increment = [&x]() { x++; };  // 捕获x的引用
        increment();
        std::cout << x << std::endl;       // 输出：6

        return 0;
    }
    ```

4. 结合`std::for_each`使用 Lambda

    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};

        std::for_each(vec.begin(), vec.end(), [](int v) {
            std::cout << v << " ";   // 输出：1 2 3 4 5
        });

        return 0;
    }
    ```

### 捕获方式

Lambda 表达式可以使用不同的捕获方式来指定如何捕获外部变量。以下是一些常见的捕获方式：

- `[]`：不捕获任何外部变量。
- `[&]`：按引用捕获所有外部作用域的变量。
- `[=]`：按值捕获所有外部作用域的变量。
- `[x]`：按值捕获`x`。
- `[&x]`：按引用捕获`x`。
- `[=, &y]`：按值捕获其他所有变量，但按引用捕获`y`。

### 返回类型推导

如果 Lambda 函数的返回类型能够被推导，则可以省略 `-> return_type`，否则需要显式指定。

```cpp
#include <iostream>

int main() {
    auto divide = [](int a, int b) -> double { return static_cast<double>(a) / b; };
    std::cout << divide(10, 3) << std::endl;  // 输出：3.33333

    return 0;
}
```

---

Lambda 表达式在 C++ 中非常灵活，可以结合STL、算法库等场景使用，使代码更加简洁明了。

更多详细信息和示例，请参考 [Microsoft Learn 上的相关文档](https://learn.microsoft.com/zh-cn/cpp/cpp/lambda-expressions-in-cpp)。

## 正则表达式

### 简介

在 C++ 中，正则表达式（Regular Expression, regex）由 **`<regex>`** 头文件提供，它允许使用模式匹配字符串，非常适用于文本搜索、替换、验证等任务。

### 常见的正则表达式模式

| 正则表达式 | 说明 |
|-----------|------|
| `.` | 匹配任意字符 |
| `\d` | 匹配数字（0-9），写成 `\\d` |
| `\D` | 匹配非数字 |
| `\w` | 匹配字母、数字、下划线 |
| `\W` | 匹配非字母、数字、下划线 |
| `\s` | 匹配空格（包括 `\t`、`\n`） |
| `\S` | 匹配非空格 |
| `^` | 匹配字符串开头 |
| `$` | 匹配字符串结尾 |
| `*` | 匹配 0 次或多次 |
| `+` | 匹配 1 次或多次 |
| `?` | 匹配 0 次或 1 次 |
| `{n,m}` | 匹配 n 到 m 次 |
| `[]` | 匹配字符集，如 `[a-z]` 匹配小写字母 |
| `()` | 分组 |

### 正则表达式的基本用法

#### (1) 匹配整个字符串（`regex_match`）

如果 **整个** 字符串符合正则表达式，则返回 `true`：

```cpp
std::string str = "12345";
std::regex pattern("\\d+"); // 匹配由数字组成的字符串
if (std::regex_match(str, pattern)) {
    std::cout << "匹配成功" << std::endl;
} else {
    std::cout << "匹配失败" << std::endl;
}
```

**注意**：

- `\\d+` 表示匹配一个或多个数字（由于 C++ 中 `\` 需要转义，所以写成 `\\d+`）。
- `regex_match` 要求整个字符串必须匹配正则模式。

#### (2) 索字符串（`regex_search`）

用于在 **部分** 字符串中查找匹配项：

```cpp
std::string str = "abc123xyz";
std::regex pattern("\\d+");
std::smatch match;

if (std::regex_search(str, match, pattern)) {
    std::cout << "找到匹配项: " << match.str() << std::endl;
}
```

**输出**：

```output
找到匹配项: 123
```

**说明**：

- `regex_search` 适用于查找 **子字符串**。
- `match.str()` 提取匹配到的内容。

#### (3) 替换字符串（`regex_replace`）

使用 `regex_replace` 进行字符串替换：

```cpp
std::string str = "hello 123 world 456";
std::regex pattern("\\d+"); 
std::string result = std::regex_replace(str, pattern, "XXX");

std::cout << "替换后的字符串: " << result << std::endl;
```

**输出**：

```output
替换后的字符串: hello XXX world XXX
```

#### (4) 捕获组

捕获组用于提取匹配的子字符串：

```cpp
std::string str = "My email is example@mail.com";
std::regex pattern(R"((\w+)@(\w+\.\w+))"); // 提取邮箱地址
std::smatch match;

if (std::regex_search(str, match, pattern)) {
    std::cout << "完整匹配: " << match.str(0) << std::endl;
    std::cout << "用户名: " << match.str(1) << std::endl;
    std::cout << "域名: " << match.str(2) << std::endl;
}
```

**输出**：

```output
完整匹配: example@mail.com
用户名: example
域名: mail.com
```

**说明**：

- `match.str(0)` 返回整个匹配项。
- `match.str(1)` 返回第一个捕获组（用户名）。
- `match.str(2)` 返回第二个捕获组（域名）。
