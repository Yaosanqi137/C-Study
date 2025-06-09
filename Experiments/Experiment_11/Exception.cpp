#include <iostream>
#include <exception>
using namespace std;

class HJT2Exception /*你的异常类*/: public exception /*继承exception类，不然可能会报警*/{
public:
    explicit HJT2Exception(string& message) : message(message) /*给你自定义 Exception 信息的地方*/{}
    string& what() {
        return message;
    }
private:
    string message;
};

int main(){
    system("chcp 65001");
    try {
        string exceptionMess = "HJT太强了";
        throw HJT2Exception(exceptionMess);
    } catch(HJT2Exception& e) {
        cerr << e.what() << endl;
    }
    // C++ 中还有一系列标准的异常，定义于 <exception> 中
    // 内存分配错误
    try {
        int* badArr = new int[1145141919810]; /* new 关键字: wtf, 这什么玩意，throw 个 bad_alloc 压压惊 */
    } catch (bad_alloc& e) {
        cerr << "内存分配炸了" << e.what() << endl;
    }

    // 类型转换错误
    try {
        exception a;
        HJT2Exception e = dynamic_cast<HJT2Exception&>(a);
    } catch(bad_cast& e) {
        cerr << "抽象" << e.what() << endl;
    }

    // ... 其他的自己脑补
}