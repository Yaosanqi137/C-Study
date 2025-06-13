#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    system("chcp 65001");

    // 输入 10 个数
    ofstream firstFile, secondFile;
    firstFile.open("first.dat", ios::binary);
    secondFile.open("second.dat", ios::binary);
    int temp;
    
    cout << "输入五个整数: ";
    for(int i = 0; i < 5; i++){
        cin >> temp;
        firstFile << temp << " ";
    }
    cout << "再输入五个整数: ";
    for(int i = 0; i < 5; i++){
        cin >> temp;
        secondFile << temp << " ";
    }

    firstFile.close();
    secondFile.close();
    // 分别存放
    ifstream secRead;
    secRead.open("second.dat", ios::binary);
    ofstream firstWrite;
    firstWrite.open("first.dat", ios::app);

    while(secRead >> temp){
        firstWrite << temp << " ";
    }

    secRead.close();
    firstWrite.close();
    // 排序并覆写
    ofstream secOverwrite("second.dat", ios::trunc);
    ifstream firstRead("first.dat", ios::binary);
    vector<int> arr;

    while(firstRead >> temp){
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for(int num : arr){
        secOverwrite << num << " ";
    }

    secOverwrite.close();
    firstRead.close();

    return EXIT_SUCCESS;
}