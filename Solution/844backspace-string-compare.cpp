// 删除元素是栈的强项，而且字符串本身就可以当做栈来使用
// 需要考虑字符串为空时出现退格键的情况
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S; // 栈
        string T; // 栈
        for (auto ele: s) {
            if (ele != '#')
                S += ele;
            else if (!S.empty())
                S.pop_back();
        }
        for (auto ele: t) {
            if (ele != '#')
                T += ele;
            else if (!T.empty())
                T.pop_back();
        }
        return (S==T);
    }
};

int main() {
    Solution solution = Solution();
    string s = "a##c";
    string t = "#a#c";
    cout << solution.backspaceCompare(s, t) << endl;
    return 0;
}