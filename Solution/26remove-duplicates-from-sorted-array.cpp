// 第一个元素始终不需要删除
// 从第二个元素开始，用快慢指针检索，快指针一旦找到和刚刚那个不同的数，就让慢指针更新这个数
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int slowIndex = 1, fastIndex = 1;
        if (size < 2) return size;
        for (fastIndex = 1; fastIndex < size; fastIndex++) {
            if (nums[fastIndex - 1] != nums[fastIndex])
                nums[slowIndex++] = nums[fastIndex];
        }
        return slowIndex;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {1};
    cout << solution.removeDuplicates(nums) << endl;
    for (auto num : nums)
        cout << num << " ";
    return 0;
}