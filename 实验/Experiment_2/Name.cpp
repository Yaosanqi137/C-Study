#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> sqlit(const string& name, const char delim){
    vector<string> names;
    istringstream ss(name);
    string partName;
    while(getline(ss, partName, ' '))
        names.push_back(partName);
    return names;
}

int main(){
    string fullName;
    system("chcp 65001");
    cout << "请输入人名：";
    getline(cin, fullName);
    vector<string> names = sqlit(fullName, ' ');
    // 输入字符串和分割处理
    auto iter1 = names.begin() + 1;
    auto iter2 = names.end() - 1;
    cout << "缩写为：　　" << *names.begin() << " ";
    for(; iter1 < iter2; iter1++)
        cout << (char)toupper((*iter1)[0]) << ". ";
    cout << *iter2 << endl;
    return EXIT_SUCCESS;
}