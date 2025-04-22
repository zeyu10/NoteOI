#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class CoordinateCompressor {
private:
    // 存储去重后的离散值
    vector<T> values;

public:
    // 添加数据（但不去重）
    void add(T x) {
        values.push_back(x);
    }

    // 进行排序和去重，构建离散化映射
    void build() {
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
    }

    // 查询 x 对应的离散化值（0-based 索引）
    int compress(T x) const {
        return lower_bound(values.begin(), values.end(), x) - values.begin();
    }

    // 获取离散化后的值域大小
    int size() const {
        return values.size();
    }

    // 获取离散化后的数值列表（仅调试用）
    void print() const {
        for (auto v : values) cout << v << " ";
        cout << endl;
    }

};

int main() {
    CoordinateCompressor<int> compressor;
    
    vector<int> data = {100, 300, 200, 100, 500};

    for (int x : data) compressor.add(x);

    compressor.build();

    cout << "数据原始值: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    cout << "离散化结果: ";
    for (int x : data) cout << compressor.compress(x) << " ";
    cout << endl;

    return 0;
}
