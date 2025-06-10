#include <iostream>
#include <fstream>
using namespace std;

class Data {
public:
    Data(const int& ageIn, const double& heightIn) : age(ageIn), height(heightIn) {}
    void print() const {
        cout << age << height << endl;
    }
    int age;
    double height;
};

int main(){
    /* ios::app 追加模式，把所有写入都追加到文件的末尾
     * ios::ate 文件打开后定位到文件末尾
     * ios::in 打开文件并只读
     * ios::out 打开文件并只写
     * ios::trunc 如果文件已经存在，那么就把它的内容清除然后重新写
     */
    ofstream file1;
    file1.open("test.txt", ios::out | ios::trunc); // 写入文件，为了防止文件已经存在，可以再加一个 trunc
    file1 << "测试" << endl; // 输入文件内容
    file1.close();

    ifstream file2;
    file2.open("test.txt", ios::out | ios::in); // 读写文件
    string data;
    file2 >> data; // 输出文件内容
    cout << data << endl;
    file2.close();

    fstream file3;
    file3.open("test.txt", ios::out | ios::in);
    file3.seekg(2, ios::beg); // 将文件位置指针定位到file3的第2个字节
    file3.seekg(2, ios::cur); // 将文件位置指针往后移2个字节
    file3.seekg(2, ios::end); // 让文件位置指针从文件末尾往前移动2个字节
    auto pos = file3.tellg(); // 记录当前位置
    file3.seekg(pos); // 可以回到你记录的位置

    Data person1(19, 170);
    ofstream file4;
    file4.open("test.dat", ios::binary);
    file4.write(reinterpret_cast<const char*>(&person1), sizeof(Data)); // 存储类的信息
    file4.close();

    ifstream file5;
    file5.open("test.dat", ios::binary);
    Data person2(20, 180);
    file5.read(reinterpret_cast<char*>(&person2), sizeof(Data));
    file5.close();
    person2.print();

    return EXIT_SUCCESS;
}