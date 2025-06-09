#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#define N 100000
using namespace std;

int main(){
    system("chcp 65001");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100000); // 随机数生成种子

    vector<int> vec1;
    for(int i = 0; i < N; i++) vec1.push_back(dis(gen));
    vector<int> vec2 = vec1;
    cout << "成功生成了 10 万个数字" << endl;

    auto start = clock();
    sort(vec1.begin(), vec1.end());
    auto end = clock();
    cout << "前十个最小数为：" << endl;
    for(int i = 0; i < 10; i++) cout << vec1[i] << " ";
    cout << endl << "运行时间为" << end - start << "ms" << endl;

    start = clock();
    partial_sort(vec2.begin(), vec2.begin() + 10, vec2.end());
    end = clock();
    cout << "前十个最小数为：" << endl;
    for(int i = 0; i < 10; i++) cout << vec2[i] << " ";
    cout << endl << "运行时间为" << end - start << "ms" << endl;

    return EXIT_SUCCESS;
}
