#include <set>
#include <algorithm>
using namespace std;

int main(){
    // 创建 int 型 set
    // set 是有序的，因此不用单向顺序问题，

    set<int> intSet;

    // 基础操作
    intSet.clear(); // 清除所有元素
    intSet.insert({10, 20, 30}); // 插入原神
    auto [iter0, isInserted] = intSet.insert(10); // set 中的元素是唯一的，不重复的，插入单个元素的时候返回是否插入成功和对应迭代器，如果元素已经存在返回 false
    intSet.erase(10); // 删除元素
    auto iterator = intSet.find(10); // 查找对应元素，并返回对应迭代器，如果没找到就返回 end()
    auto exist = intSet.count(10); // 查找元素，返回的是 0 or 1
    auto count = intSet.size(); // 返回元素数量
    auto isEmpty = intSet.empty(); // 检查 set 是否为空

    // 元素遍历
    for(auto begin = intSet.begin(); begin != intSet.end(); begin++) {}
    for(int num : intSet) {}

    // 范围查找
    auto low = intSet.lower_bound(10); // 返回第一个大于等于 10 的元素的迭代器，找不到就返回 end()
    auto up = intSet.upper_bound(50); // 返回第一个大于等于 50 的元素的迭代器，找不到就返回 end()

    // 集合操作
    set<int> intSet2;
    set<int> intSet3;
    intSet.insert({30, 100});
    set_intersection(intSet.begin(), intSet.end(),
                     intSet2.begin(), intSet2.end(),
                     inserter(intSet3, intSet3.begin())); // 求交集，此处输出 {30}

    set_union(intSet.begin(), intSet.end(),
              intSet2.begin(), intSet2.end(),
              inserter(intSet3, intSet3.begin())); // 求并集，此处输出 {20, 30, 100}

    set_difference(intSet.begin(), intSet.end(),
                   intSet2.begin(), intSet2.end(),
                   inserter(intSet3, intSet3.begin())); // 求差集，此处输出 {20}
}