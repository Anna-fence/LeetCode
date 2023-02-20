// 快慢指针，快指针负责找不是需要删除的元素的位置，慢指针找需要删除的元素的位置
// 其实快指针一直在动，但是慢指针遇到了要删的元素就会停下来，在下一个回合把这个元素替换掉
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0, fastIndex = 0;
        int size = nums.size();
        while (fastIndex < size) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
            ++ fastIndex;
        }
        return slowIndex;
    }
};


int main(){
 Solution solution = Solution();
 vector<int> nums = {3, 2, 2, 3};
 int val = 3;
 cout << solution.removeElement(nums, val) << endl;
 for (auto num : nums)
     cout << num << " ";
 return 0;
}