#include <iostream>
#define PI 3.1415926
using namespace std;

void rectangle(double a, double b){
    cout << "此长方形的面积是: " << a * b << endl;
}

void square(double a){
    cout << "此正方形的面积是: " << a * a << endl;
}

void circle(double r){
    cout << "此圆的面积是: " << PI * r * r << endl;
}

int main(){
    system("chcp 65001");
    cout << "**欢迎使用图形面积计算工具**" << endl;
    cout << "A.圆形 B.长方形 C.正方形 D.退出" << endl;
    cout << "请选择你需要计算面积的图形:";
    auto choice = getchar();
    double a, b;
    switch(choice){
        case 'A':
            cout <<  "请输入圆的周长:";
            cin >> a;
            circle(a);
            break;
        case 'B':
            cout << "请输入长方形的长和宽(e.g. 10 20):";
            cin >> a >> b;
            rectangle(a, b);
            break;
        case 'C':
            cout << "请输入正方形的边长:";
            cin >> a;
            square(a);
            break;
    }
    cout << "程序已退出" << endl;
    return EXIT_SUCCESS;
}