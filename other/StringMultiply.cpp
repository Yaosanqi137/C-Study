#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    static string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        auto m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string result;
        for (int num : res) {
            if (!(result.empty() && num == 0)) {
                result.push_back((char)(num + '0'));
            }
        }
        return result.empty() ? "0" : result;
        }
};

int main(){
    Solution::multiply("1000232734687283465872634562345234523652346452345123", "22345236521734765123547615823645812344523423450");
    return EXIT_SUCCESS;
}