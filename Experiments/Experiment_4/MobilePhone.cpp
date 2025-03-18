#include <iostream>
#include <string>
using namespace std;

class MobilePhone{
    public:
        explicit MobilePhone(string brandIn, string modelIn){
            brand = std::move(brandIn);
            model = std::move(modelIn);
        }
        void charge(int minutes);
        void use(int minutes);
        void displayInfo();
    private:
        string brand;
        string model;
        int battery_level = 100;
};

void MobilePhone::charge(int minutes){
    if(battery_level == 100){
        cout << "电量本身就是满的了，不需要充电！" << endl;
    }else if(minutes <= 0){
        cout << "你在想什么？" << endl;
    }else{
        battery_level += minutes * 2;
        if(battery_level > 100){
            int charged = minutes - (battery_level - 100) / 2;
            battery_level = 100;
            cout << "充的太久了！你发现实际上只充了" << charged << "分钟就充满了" << endl;
        }else{
            cout << "摸完鱼回来发现手机已经充到" << battery_level << "了" << endl;
            if(battery_level >= 50){
                cout << "感觉这么多电量应该够玩了吧？" << endl;
            }else{
                cout << "感觉电量还是有点少，要不要再充会儿？" << endl;
            }
        }
    }
}

void MobilePhone::use(int minutes){
    if(minutes <= 0){
        cout << "你在想什么？" << endl;
    }else if(battery_level == 0){
        cout << "手机已经没电了啊，还不快充电？" << endl;
    }else{
        battery_level -= minutes * 5;
        if(battery_level <= 0){
            int hasUsed = minutes + battery_level / 5;
            battery_level = 0;
            cout << "[" << brand << " " << model << "] 电量耗尽，已关机！" << endl;
            cout << "布豪，手机玩到第" << hasUsed << "分钟后自动关机了，要不充点电？" << endl;
        }else{
            cout << "好了，现在手机还剩" << battery_level << "格电" << endl;
            if(battery_level <= 20){
                cout << "感觉电量有点不够了，要不要充点电？" << endl;
            }else{
                cout << "感觉还好，要不要继续玩会儿？" << endl;
            }
        }
    }
}

void MobilePhone::displayInfo(){
    cout << brand << " " << model << " 当前电量为：" << battery_level << endl;
}

int main(){
    string brand, model;
    int minutes;
    system("chcp 65001");
    cout << "****欢迎来到手机电量模拟器****" << endl;
    cout << "请输入你的手机品牌和型号: ";
    cin >> brand >> model;
    MobilePhone myPhone(brand, model);
    while(true){
        cout << "\n请选择你要进行的操作" << endl;
        cout << "A.查看手机信息 B.使用手机 C.给手机充电 D.退出模拟器" << endl;
        cout  << "请选择：";
        getchar();
        switch(getchar()){
            case 'A':
                myPhone.displayInfo();
                break;
            case 'B':
                cout << "\n请输入你要使用的时间(整数分钟)：";
                cin >> minutes;
                myPhone.use(minutes);
                break;
            case 'C':
                cout << "\n请输入你要充电的时间(整数分钟)：";
                cin >> minutes;
                myPhone.charge(minutes);
                break;
            case 'D':
                cout << "\n模拟器成功退出..." << endl;
                return EXIT_SUCCESS;
            default:
                cerr << "错误的输入！" << endl;
                break;
        }
    }
}