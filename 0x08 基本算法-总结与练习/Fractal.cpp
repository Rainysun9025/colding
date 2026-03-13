#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 预计算每个度数对应的图形边长：size[n] = 3^(n-1)
const int sizeTable[8] = {0, 1, 3, 9, 27, 81, 243, 729};

// 画布，全局变量方便递归操作
vector<string> grid;

// 递归绘制函数
// n    : 当前度数
// r, c : 当前子分形左上角在画布上的行、列坐标
void draw(int n, int r, int c) {
    if (n == 1) {
        grid[r][c] = 'X';          // 基础情况：放置一个 X
        return;
    }

    int subSize = sizeTable[n - 1]; // 子分形的边长（即 B(n-1) 的尺寸）
    // 五个子分形的左上角坐标
    draw(n - 1, r, c);                          // 左上
    draw(n - 1, r, c + 2 * subSize);             // 右上
    draw(n - 1, r + subSize, c + subSize);       // 中间
    draw(n - 1, r + 2 * subSize, c);             // 左下
    draw(n - 1, r + 2 * subSize, c + 2 * subSize); // 右下
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        int size = sizeTable[n];          // 当前度数对应的图形边长
        grid.assign(size, string(size, ' ')); // 初始化画布为空格

        draw(n, 0, 0);                     // 从 (0,0) 开始绘制整个分形

        // 输出画布，每行去除末尾多余空格
        for (int i = 0; i < size; ++i) {
            string row = grid[i];
            // 找到最后一个非空格字符的位置
            size_t lastChar = row.find_last_not_of(' ');
            if (lastChar != string::npos) {
                cout << row.substr(0, lastChar + 1) << endl;
            } else {
                // 理论上不会出现全空行，但以防万一
                cout << endl;
            }
        }
        cout << "-" << endl; // 每个测试用例后的分隔线
    }
    return 0;
}
