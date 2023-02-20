//
// Created by 韦澜 on 2023/2/8.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0, fastIndex;
        int size = nums.size();
        for (fastIndex = 0; fastIndex < size; fastIndex++) {
            if (nums[fastIndex] != 0)
                nums[slowIndex++] = nums[fastIndex];
        }
        for (int idx = slowIndex; idx < size; idx++)
            nums[idx] = 0;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (auto num : nums)
        cout << num << " ";
    return 0;
}

