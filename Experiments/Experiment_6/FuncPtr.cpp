#include <iostream>
using namespace std;

void func(const int* const ptr){
    cout << *ptr << endl;
}

int main(){
    void (*funcPtr)(const int* const ptr);
    funcPtr = func;
    int a = 114514;
    int *ptr = &a;
    funcPtr(ptr);
    return EXIT_SUCCESS;
}