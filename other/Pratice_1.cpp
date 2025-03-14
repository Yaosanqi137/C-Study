#include <iostream> // 相当于 C 的 stdio.h
using namespace std;

int main(){
    // 基本类型
    short z; // 短型
    int a; // 整数型
    float b; // 单精度浮点
    double c; // 双精度浮点
    char d; // 字符型
    // void 空类型
    bool e; // 布尔型 true & false
    wchar_t f; // 宽字符型
    char16_t g; // 16 位 Unicode 字符类型 (c++11 std)
    char32_t h; // 32 位 Unicode 字符类型 (c++11 std)

    // 修饰
    /*
     * signed 有符号
     * unsigned 无符号
     * short 表示短整型 short int 占 2 字节
     * long 表示长整型 long int 占 8 字节 long double 拓展精度浮点 占 8、12、16字节
     * const 表示常量
     * volatile 表示变量可能被意外修改，不能被编译器优化掉
     * mutable 表示类成员可以再 const 对象中修改
     */

    // C++ std 新增类型
    /*
     * auto 自动推断类型 e.g. auto a;
     * decltype 获取表达式的类型 decltype(a)
     * nullptr 空指针常量
     * std::initializer_list 初始化列表类型
     * std::tuple 元组类型
     * 下面是例子
     */
    initializer_list<int> list = {1, 2, 3};
    tuple<int, float, double, char32_t> t(1, 2.0, 3.1415926, 'M');

    // 标准库类型
    string str = "hello"; // 字符串型
    // 其他的有点猎奇，我不写了

    // 派生的新数据类型
    // 引用，也就是编译器不会为了引用变量而重新开辟内存空间，而是复用
    int& A = a; // 这里 A 就是 a 的别名,二者的值如果其中一个被修改了,那么另外一个也会变(类似于指针的概念)
    // 引用可以多次引用，也可以重复引用

    // 类
    /* 类的封装，其实就是用protected/private 把成员封装起来，然后也开放一些公有(public)的成员函数提供使用
     * 可访问性 public > protected > private
     * 访问修饰符	类内部	派生类	类外部对象
     * private	  ✔️	 ❌	      ❌
     * protected  ✔️	 ✔️	      ❌
     * public	  ✔️	 ✔️  	  ✔️
     */
    class dog{
        public: // 都可以访问
            string name;
        protected: // 只有类内部和派生类中可访问
            int weight;
        private: // 只有类内部才可以访问
            int color;

        public:
            void setValue(string&& Name, int Weight, int Color){
                name = Name;
                weight = Weight;
                color = Color;
            }
    };

    dog ghc;
    ghc.setValue("Gao Hao cum", 57, 1); // 借助 public 的函数修改类内部的 private 和 protected 对象
    // ghc.color = 1; 这是非法的，这是在类外访问

    /*
     * 继承
     * public继承:
     * 基类的public成员：在派生类中仍然是public。
     * 基类的protected成员：在派生类中仍然是protected。
     * 基类的private成员：不能直接访问（依然不可见，但可以通过基类的public或protected方法间接访问）。
     * protected 继承:
     * 基类的public成员：在派生类中变为protected。
     * 基类的protected成员：在派生类中仍然是protected。
     * 基类的private成员：不能直接访问（和public继承一样）。
     * private 继承:
     * 基类的public成员：在派生类中变为private。
     * 基类的protected成员：在派生类中变为private。
     * 基类的private成员：不能直接访问。
     */
    class SpecialDog : public dog {
        public:
            string skill;
    };
    // 大概就先写这么多了 :(
}