#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int water = 0, temp = 0;
        auto iter = height.begin();
        auto iter1 = iter;
        while(iter < height.end()){
            while(*(iter + 1) >= *iter && iter < height.end() - 1) iter++;
            if(iter == height.end() - 1)
                break;
            iter1 = iter + 1;
            while(*iter1 < *(iter + 1) && iter1 < height.end()){
                temp += *iter - *iter1;
                iter1++;
            }
            if(iter1 == height.end())
                break;
            water += temp;
            if(*iter1 < *iter)
                water -= distance(iter, iter1) * (*iter - *iter1);
            iter = iter1;
        }
        return water;
    }
};