#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <forward_list>
#include <array>
using namespace std;
// 数据结构

int main(){
    // 栈 stack
    // 后进先出，只能在栈顶进行插入和删除操作
    stack<int> STACK;
    // 插入到栈顶
    STACK.push(1);
    // 输出栈顶的元素
    cout << STACK.top() << endl;
    // 弹出栈顶元素
    STACK.pop();

    // 队列
    // 先进先出
    queue<int> QUEUE;
    // 插入元素
    QUEUE.push(1);
    // 输出队列元素
    cout << QUEUE.front() << endl; // 先进先出
    cout << QUEUE.back() << endl; // 先进后出
    // 弹出先进入的元素
    QUEUE.pop();

    // 优先序列
    // 弹出的总是优先级最高（即值最大）的元素
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    cout << pq.top() << endl; // 输出 2
    pq.pop(); // 弹出 2

    // 双端队列
    // 可以在两端进行插入和删除
    deque<int> DEQUE;
    // 两端元素插入
    DEQUE.push_front(1); // 前
    DEQUE.push_back(2); // 后
    // 输出
    cout << DEQUE.front() << endl; // 前
    cout << DEQUE.back() << endl; // 后
    // 删除
    DEQUE.pop_front(); // 前
    DEQUE.pop_back(); // 后

    // 无序映射
    // 不保证元素顺序，用键值对存储数据，类似 python 的字典
    unordered_map<int, int> hashmap;
    hashmap[1] = 10;
    hashmap.insert({2, 20}); // 使用 insert 方法也可以插入元素
    hashmap.insert(make_pair(3, 30)); //也可以用 make_pair 方法插入
    cout << hashmap[1] << endl;
    // 无序映射迭代器
    auto iter = hashmap.find(1); // 找到键为 1 的元素，如果找到了就返回对应的迭代器，不然返回 hashmap.end()
    hashmap.erase(iter); // 也可以擦除一个范围，但是容易死，这里 erase 方法没有返回值
    auto i = hashmap.erase(1); // 用键来删除对应元素，返回删除元素的数量
    // 无序映射遍历
    for(const auto& element : hashmap) // 类似于 python 中的 for element in array
        cout << "键: " << element.first << "值: " << element.second << endl; // 结果每次都不一定相同

    // 使用 clear 方法清空无序映射
    hashmap.clear();

    // 映射
    // 有序的键值对容器，会自动按升序排序，性能比 unordered_map 差一点
    map<int, int> MAP;
    MAP[1] = 10;
    MAP.insert({2, 20}); // 使用 insert 方法也可以插入元素
    MAP.insert(make_pair(3, 30)); //也可以用 make_pair 方法插入
    cout << MAP[1] << endl;
    // 迭代器
    auto iter1 = MAP.begin();
    auto iter2 = MAP.end();
    auto iter3 = hashmap.find(1); // 找到键为 1 的元素，如果找到了就返回对应的迭代器，不然返回 MAP.end()
    MAP.erase(iter1); // 也可以擦除一个范围，但是容易死，这里 erase 方法没有返回值
    auto j = MAP.erase(1); // 用键来删除对应元素，返回删除元素的数量
    // 映射遍历
    for(const auto& element : MAP) // 类似于 python 中的 for element in array
        cout << "键: " << element.first << "值: " << element.second << endl; // 结果每次都一样

    // 使用 clear 方法清空映射
    hashmap.clear();

    // 集合
    // 元素都唯一，并且有序（升序）
    set<int> SET; // 可以用 容器、迭代器、
    SET.insert(1); // 用 insert 方法插入元素
    auto a = SET.count(1); // 返回某元素的个数
    auto riter1 = SET.rbegin(); // 返回指向最后一个元素的反向迭代器(也就是递增递减含义颠倒的迭代器)
    auto riter2 = SET.rend(); // 返回指向第一个元素的反向迭代器
    // ... //

    // 双向链表
    // 懂得都懂
    list<int> LIST;
    LIST.push_front(1);
    auto iter4 = LIST.begin();
    auto iter5 = --LIST.end();

    // 单向链表
    // 只能向前遍历，不能后退
    forward_list<int> flist;

    // 无序集合
    // 没有顺序，元素不能重复
    unordered_set<int> unset;

    // 数组
    // 懂得都懂，不能改变大小，有点难绷
    array<int, 5> arr = {1, 2, 3, 4, 5};
    arr.fill(1); // 用 1 来填充整个数组的值
    array<int, 5> arr1 = {0};
    arr1.fill(2);
    arr.swap(arr1); // 交换两个数组的元素

    /*
     * 所有容器以及支持的操作
     * 顺序容器:
     * vector, deque, list, forward_list, array
     *
     * 无序容器:
     * unordered_set, unordered_map, unordered_multiset, unordered_multimap
     *
     * 几乎所有操作
     * push_back( val ) 在尾部插入元素
     * pop_back() 删除尾部元素
     * insert(迭代器, val 或者一个序列) 在迭代器指向的元素前插入元素
     * erase(迭代器 or val) 删除迭代器指向的元素 或 erase(迭代器, 迭代器) 删除一个范围的元素，闭区间,填值返回删除个数，填迭代器无返回值
     * begin(), end() 返回指向第一个元素和最后一个元素之后的迭代器
     * front(), back() 返回第一个和最后一个元素
     * reserve(n) 预分配内存，能够加快速度
     * resize(n, val) 改变容器的大小，改为 n 个初始化值为 val 的容器，不填 val 默认是 0
     * clear() 删除容器所有元素
     * size() 返回容器的元素个数
     * fill() 用某个值填充容器
     * distance(迭代器, 迭代器) 返回元素和元素之间的距离
     */
}