// 如果用二分法的闭区间写法，最终的mid会面临+1还是-1的问题
// 求平方也要尽量避免，很容易溢出，可以用除法代替
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int beg = 0;
        int end = x;
        int mid;
        // 1是特殊情况
        if (x == 1)
            return 1;

        while (beg < end - 1) {
            mid = beg + (end - beg) / 2;
            if (mid > x / mid) {
                end = mid;
            } else
                beg = mid;
        }
        return beg;
    }
};

int main() {
    Solution solution = Solution();
    int number = 4;
    cout << solution.mySqrt(number) << endl;
    return 0;
}