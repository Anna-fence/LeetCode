#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> positions = {};
        int left = 0;
        int right = nums.size();
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else {
                if (nums[mid + 1] == target) {
                    positions.push_back(mid);
                    positions.push_back(mid + 1);
                }
                else if (nums[mid - 1] == target) {
                    positions.push_back(mid);
                    positions.push_back(mid - 1);
                }
                else {
                    positions.push_back(mid);
                    positions.push_back(mid);
                }
            }
        }
        if (positions.empty()) {
            positions.push_back(-1);
            positions.push_back(-1);
        }
        return positions;
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
