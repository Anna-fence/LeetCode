// 滑动窗口，注意resultLength的取值，如果没被改动过说明没有符合条件的子序列
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int startIndex = 0;
        int endIndex = 0;
        int sum = 0;
        int resultLength = nums.size() + 1;
        for (endIndex = 0; endIndex < nums.size(); endIndex++) {
            sum += nums[endIndex];
            while (sum >= target) {
                //记录长度
                int currentLength = endIndex - startIndex + 1;
                if (currentLength <= resultLength)
                    resultLength = currentLength;
                sum -= nums[startIndex];
                startIndex ++;
            }
        }
        if (resultLength != nums.size() + 1)
            return resultLength;
        else
            return 0;
    }
};


int main() {
    Solution solution = Solution();
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    auto result = solution.minSubArrayLen(target, nums);
    cout << result << endl;
    return 0;
}