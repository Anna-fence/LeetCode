// 搞不懂什么时候更新现在篮子里的水果：只有在不能摘的时候才要更新
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int leftBasket = fruits[left];
        int rightBasket = fruits[right];
        int maxLength = 0;
        int currentLength = 0;
        while (right < fruits.size()) {
            //移动右边界的时候有两种可能性，一种是可以继续摘，那么就要继续滑动左边界；
            //另一种是现在不满足条件，那么就要移动左边界，直到所有可能都被检查一遍
            if ((fruits[right] == rightBasket) || (fruits[right] == leftBasket)) {
                currentLength = right - left + 1;
                maxLength = max(maxLength, currentLength);
                right ++;
//                rightBasket = fruits[right];
            }
            else {
                left = right - 1;
                leftBasket = fruits[left];
                rightBasket = fruits[right];
                while (left >= 1 && fruits[left - 1] == leftBasket) {
                    left --;
                }
                currentLength = right - left + 1;
                maxLength = max(maxLength, currentLength);
//                leftBasket = fruits[left];
            }
        }
        return maxLength;
    }
};


int main() {
    Solution solution = Solution();
    vector<int> nums = {1,2,3,2,2};
    auto result = solution.totalFruit(nums);
    cout << result << endl;
    return 0;
}