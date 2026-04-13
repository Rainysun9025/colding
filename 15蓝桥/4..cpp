#include <bits/stdc++.h>
using namespace std;

// 高精度乘以 2
void multiply_by_two(vector<int>& digits) {
    int carry = 0;
    for (size_t i = 0; i < digits.size(); ++i) {
        int cur = digits[i] * 2 + carry;
        digits[i] = cur % 10;
        carry = cur / 10;
    }
    if (carry) digits.push_back(carry);
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 解析整数部分和小数部分
    string int_part, frac_part;
    size_t dot_pos = s.find('.');
    if (dot_pos == string::npos) {
        int_part = s;
        frac_part = "";
    } else {
        int_part = s.substr(0, dot_pos);
        frac_part = s.substr(dot_pos + 1);
    }
    if (int_part.empty()) int_part = "0";

    // 构建高精度数字：低位在数组开头
    vector<int> digits;
    // 先放小数部分（低位到高位）
    for (int i = (int)frac_part.size() - 1; i >= 0; --i)
        digits.push_back(frac_part[i] - '0');
    // 再放整数部分（低位到高位）
    for (int i = (int)int_part.size() - 1; i >= 0; --i)
        digits.push_back(int_part[i] - '0');

    int frac_len = (int)frac_part.size();

    // 乘以 2 的 n 次方
    for (int i = 0; i < n; ++i)
        multiply_by_two(digits);

    // 四舍五入
    if (frac_len > 0) {
        // 判断小数部分最高位（索引 frac_len-1）是否 >= 5
        if (digits[frac_len - 1] >= 5) {
            int carry = 1;
            for (size_t i = frac_len; i < digits.size(); ++i) {
                int sum = digits[i] + carry;
                digits[i] = sum % 10;
                carry = sum / 10;
                if (carry == 0) break;
            }
            if (carry) digits.push_back(carry);
        }
        // 删除小数部分
        digits.erase(digits.begin(), digits.begin() + frac_len);
    }

    // 输出结果（去除前导零，但要保留一个 0）
    if (digits.empty()) {
        cout << "0\n";
    } else {
        // 从高位向低位输出
        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
            cout << *it;
        cout << '\n';
    }

    return 0;
}