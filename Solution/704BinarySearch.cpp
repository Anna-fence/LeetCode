#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size() - 1;
        int mid;
        while (beg <= end) {
            mid =  beg + (end - beg) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                beg = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> numbers = {-1,0,3,5,9,12};
    int tar = 9;
    cout << solution.search(numbers, tar) << endl;
    return 0;
}
