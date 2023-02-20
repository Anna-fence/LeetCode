// 如果不验算一下的话，5就通不过测试（2==5/2）
// 直接用mid * mid比较也行，不过要考虑下数据范围的问题，使用long类型来保存mid * mid的结果
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int min = 0;
        int max = num;
        int mid;

        if (num == 1) return true;

        while (max >= min) {
            mid = min + (max - min) / 2;
            if (mid < num / mid)
                min = mid + 1;
            else if (mid > num / mid)
                max = mid - 1;
            else {
                break;
            }
        }
        if (mid * mid == num)
            return true;
        else return false;
    }
};
int main(){
    Solution solution = Solution();
    int num = 5;
    cout << solution.isPerfectSquare(num) << endl;
    return 0;
}