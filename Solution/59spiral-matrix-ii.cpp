//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 数组最开始注意要初始化！
        vector<vector<int>> matrix (n, vector<int> (n, 0));
        int count = 1;
        int offset = 1;
        int i = 0;
        int j = 0;
        int times = n / 2;
        // 需要定义起始位置
        int startX = 0;
        int startY = 0;
        // 始终遵循左闭右开原则
        while (times)  { //画方块的次数，偶数的话正好，奇数中间会多一个，直接在循环之后赋值即可。
            for (j = startY; j < n - offset; j ++) {
                matrix[startX][j] = count;
                count ++;
            } // 此时j的位置就是下一条边的纵坐标
            for (i = startX; i < n - offset; i++) {
                matrix[i][j] = count;
                count++;
            }
            for (; j > startY; j--) {
                //走到第三条边的时候横纵坐标都有了，不需要初始化；同时最后一个点不处理（留给下一条边），所以要大于起始位置
                matrix[i][j] = count;
                count ++;
            }
            for (; i > startX; i--) {
                matrix[i][j] = count;
                count ++;
            }
            times--;
            offset ++;
            startX ++;
            startY ++;
        }
        if (n%2 == 1)
            matrix[n/2][n/2] = count;
        return matrix;
    }
};

int main() {
    Solution solution = Solution();
    int n = 10;
    auto result = solution.generateMatrix(n);
    for (auto &vec1: result) {
        for (auto vec2:vec1) {
            cout << vec2 << " ";
        }
        cout << endl;
    }
    return 0;
}