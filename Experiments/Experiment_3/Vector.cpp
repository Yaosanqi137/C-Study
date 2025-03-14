#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

void statistic(map<int, vector<int>>& map, vector<int>& vec){
    for(int pos = 0; pos < vec.size(); pos++)
        map[vec[pos]].push_back(pos);
}

int main(){
    system("chcp 65001");
    map<int, vector<int>> map;
    vector<int> vec;
    int num;
    cout << "请输入数组(输入完毕后按下ctrl D终止输入): ";
    while(cin >> num)
        vec.push_back(num);
    // 输入数组
    statistic(map, vec);
    for(const auto& element : map){
        cout << element.first << " 出现的次数: " << element.second.size() << " 出现的位置:";
        for(const auto& pos : element.second)
            cout << setw(4) << right << pos;
        cout << endl;
    }
    return EXIT_SUCCESS;
}