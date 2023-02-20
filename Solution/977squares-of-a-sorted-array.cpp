// 除了一般的先算平方再快排的思路（复杂度为O(n + nlogn)）之外，还可以用双指针（只要比较两头的数据，因为原数组是有序的）
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> copyNums (nums.size(), 0);
        while (leftIndex <= rightIndex) {
            if(nums[leftIndex] * nums[leftIndex] <= nums[rightIndex] * nums[rightIndex]) {
                copyNums[index--] = nums[rightIndex] * nums[rightIndex];
                rightIndex--;
            }
            else {
                copyNums[index--] = nums[leftIndex] * nums[leftIndex];
                leftIndex++;
            }
        }
        return copyNums;
    }
};

//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        for (auto &num: nums)
//            num = num * num;
//        sort(nums.begin(), nums.end());
//        return nums;
//    }
//};

int main() {
    Solution solution = Solution();
    vector<int> nums = {-4, -1, 0, 3, 10};
    auto solutionNums = solution.sortedSquares(nums);
    for (auto num : solutionNums)
        cout << num << " ";
    cout << endl;
    return 0;
}