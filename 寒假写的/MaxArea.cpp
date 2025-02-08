//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//返回容器可以储存的最大水量。
//
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height){
    auto start = height.begin();
    auto end = height.end() - 1;
    auto iter = height.end();
    int temp = 0, area;
    while(start != end){
        iter = end;
        while(start != iter){
            if(*start > *iter){
                area = distance(start, iter) * *iter;
                iter--;
                temp = area > temp ? area : temp;
            }else{
                area = distance(start, iter) * *start;
                temp = area > temp ? area : temp;
                break;
            }
            if(distance(start, iter) * *start < temp)
                break;
        }
        while((distance(start, end) * *start) <= temp && start != end) start++;
        iter = start;
        while(end != iter){
            if(*end > *iter){
                area = distance(iter, end) * *iter;
                iter++;
                temp = area > temp ? area : temp;
            }else{
                area = distance(iter, end) * *end;
                temp = area > temp ? area : temp;
                break;
            }
            if(distance(iter, start) * *start < temp)
                break;
        }
        while((distance(start, end) * *end) <= temp && start != end) end--;
    }
    return temp;
}