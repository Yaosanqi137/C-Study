#include <iostream>
#include <vector>
using namespace std;

void Joseph(int people, int amount){
    if(!people)
        return;
    int count = 0, out = 0;
    vector<int> ring(people);
    for(int i = 0; i < people; i++)
        ring.at(i) = i + 1;
    auto iter = ring.begin();

    while(out != people){
        if(++count == amount){
            cout << *iter << " " ;
            iter = ring.erase(iter);
            out++, count = 0;
            if(!(out % 10))
                cout << endl;
        }else
            iter++;
        if(iter == ring.end())
            iter = ring.begin();
    }
}

int main(){
    int people, amount;
    cin >> people >> amount ;
    Joseph(people, amount);
    return 0;
}