#include <iostream>
#include <vector>
#include <algorithm>
#define M 10
#define N 5
using namespace std;

// 下面展示 vector 容器的使用
int main(){
    system("chcp 65001");

    vector<int> vec0; // 创建了一个 int 型的空 vector 容器

    vector<int> vec1(5, 10); // 创建了一个包括 5 个元素，值均为 10 （不填就是 0 ）的 vector 容器

    vector<int> vec2 = {1, 2, 3, 4}; // 也可以像 数组 那样直接赋值初始化

    vector<int> vec3(vec2); // 用 vec2 中的所有元素初始化 vec3 或者 vector<int> vec3 = vec2 也行

    vector<vector<int>> matrix(M, vector<int>(N)); // 二维 vector 容器，长 N 宽 M

    vector<int>& vec4 = vec2; // 引用

    bool TorF = vec0.empty(); // 如果 vec1 是 空的，就返回 true 不然就 false

    unsigned long long amount = vec1.size(); // 返回 vec1 的元素个数

    vec2.push_back(10); // 在容器末尾添加元素 10

    vec2.pop_back(); // 删除尾元素

    int& i = vec2[1]; // 返回第 1 个位置(也就是第二个元素)的引用，这个变量(i)改了，对应位置的元素一起改

    int I = vec2[1]; // 单纯获取这个位置的值

    int& j = vec2.back(); // 获取 vec2 最后一个元素的引用

    int& J = vec2.front(); // 获取 vec2 第一个元素的引用

    int& m = vec2.at(1); // 同 i ，但是 at() 方法自带边界检查，如果越界就抛出 std::out_of_range 异常

    try{
        cout << vec2.at(10) << endl;
    }catch(const out_of_range& e){
        cout << "错误 " << e.what() << endl;
    }

    // 迭代器遍历、插入、删除
    auto iter = vec2.begin(); // 类似于 C 的指针，也可以解引用
    while(iter != vec2.end()){ // 防止迭代器越界
        cout << *iter << endl; // 使用 * 解引用
        iter++; // 跳到下一个元素
    }

    auto iter1 = vec2.begin();
    auto iter2 = vec2.insert(iter1 + 1, 10); // 使用 insert() 方法，在 vec2 的第二个元素之前插入元素，也可以插入列表 e.g. {1, 2, 3}, insert 返回新插入元素的迭代器
    auto iter3 = vec2.erase(iter1 + 1); // 使用 erase() 方法删除 第二个 元素， 返回被删除元素之后元素的迭代器
    auto iter4 = vec2.erase(iter1 + 1, iter1 + 3); // 也可以删除一个范围，这是删除第二到第四个元素

    // 可以使用 sort() 方法对 vector 进行排序
    // 需要导入 algorithm 库
    sort(vec2.begin(), vec2.end()); // 由小排到大
    reverse(vec2.begin(), vec2.end()); // 由大排到小
    sort(vec2.begin(), vec2.end(), greater<>()); // 也可以这样写实现由大排到小

    // 可以使用 unique 方法将容器中相邻的重复元素移动到容器的末尾，并返回一个指向容器中去重后的新末尾的迭代器，一般搭配sort使用
    // e.g. 1 1 1 2 2 2 3 3 3 -> 1 2 3 1 1 2 2 3 3
    // e.g. 1 2 2 1 -> 1 2 1 2
    sort(vec2.begin(), vec2.end());
    auto iter5 = unique(vec2.begin(), vec2.end());
    vec2.erase(iter5, vec2.end()); // 这样，容器中的重复元素就被去除了

    // 获取容器中的最大值
    auto iter6 = max_element(vec2.begin(), vec2.end());
    // 获取容器中的最小值
    auto iter7 = min_element(vec2.begin(), vec2.end());
    // 使用 distance 方法获取两个元素的距离
    auto dis = distance(iter6, iter7);
    // 可以用于获取元素的索引
    auto index = distance(vec2.begin(), iter6);

    // 使用 resize 方法重新调整容器分配的内存
    vec2.resize(3, 10); // 调整为含 3 个元素，并且初始值为 10 的容器，也可以往里面套容器
}
