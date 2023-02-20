#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> positions = {};
        int leftBound = findLeftBound(nums, target);
        int rightBound = findRightBound(nums, target);
        if (leftBound == -2 || rightBound == -2) {
            positions = {-1, -1};
        }
        else if (rightBound - leftBound > 1) {
            positions = {leftBound + 1, rightBound - 1};
        }
        else
            positions = {-1, -1};
        return positions;
    }
private:
    int findLeftBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBound = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
                leftBound = right;
            }
        }
        return leftBound;
    }
    int findRightBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBound = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
                rightBound = left;
            }
        }
        return rightBound;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> numbers = {1,3,5,6};
    int tar = 6;
    auto result = solution.searchRange(numbers, tar);
    for (auto & position: result) {
        cout << position << endl;
    }
    return 0;
}
