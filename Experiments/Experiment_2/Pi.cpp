#include <iostream>
#include <iomanip>
#define PI 3.1415926
using namespace std;

void isLegal(double e){
    if(e < 3 / 8.0 || e > PI){
        cout << "程序异常: 非法输入!" << endl;
        exit(EXIT_FAILURE);
    }
}

pair<double, int> pi(double e){
    double pi = 2;
    double temp = pi;
    int n = 0, x = 2, y = 1;
    for(; e > pi; n++, x += 2){
        temp = pi;
        pi *= x / (double)y;
        y += 2;
        pi *= x / (double)y;
    }
    return make_pair(temp, n - 1);
}

int main(){
    system("chcp 65001");
    double e;
    cout << "请输入e:";
    cin >> e;
    isLegal(e);
    auto result = pi(e);
    cout << fixed << setprecision(8) << "结果为: " << result.first << " 迭代次数: " << result.second << endl;
    return EXIT_SUCCESS;
}