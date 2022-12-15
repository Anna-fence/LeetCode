#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else
                return mid;
        }
        return left;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> numbers = {1,3,5,6};
    int tar = 6;
    cout << solution.searchInsert(numbers, tar) << endl;
    return 0;
}
