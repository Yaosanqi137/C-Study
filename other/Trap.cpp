#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    static int trap(vector<int>& height){
        if(height.size()< 3)
            return 0;

        int water = 0;
        auto iter_left = height.begin();
        auto iter_right = height.end()- 1;
        int left_max = 0, right_max = 0;

        while(iter_left <= iter_right){
            if(*iter_left < *iter_right){
                if(*iter_left > left_max)
                    left_max = *iter_left;
                else
                    water += left_max - *iter_left;
                iter_left++;
            }else{
                if(*iter_right > right_max)
                    right_max = *iter_right;
                else
                    water += right_max - *iter_right;
                iter_right--;
            }
        }
        return water;
    }
};

int main(){
    vector<int> test = {3,2,1,2,1};
    int water = Solution::trap(test);
    cout << water << endl;
    return EXIT_SUCCESS;
}