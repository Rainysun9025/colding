#include <stdio.h>
#include <string.h>

int main() {
    int n;
    unsigned int m;
    scanf("%d %u", &n, &m);
    
    // 预处理：初始全 0 和全 1 经过所有防御门后的结果
    unsigned int zero = 0, one = 0xFFFFFFFF;
    
    for (int i = 0; i < n; i++) {
        char op[5];
        unsigned int t;
        scanf("%s %u", op, &t);
        
        if (op[0] == 'A') {         // AND 运算
            zero &= t;
            one  &= t;
        } else if (op[0] == 'O') {  // OR 运算
            zero |= t;
            one  |= t;
        } else {                    // XOR 运算
            zero ^= t;
            one  ^= t;
        }
    }
    
    unsigned int ans = 0;  // 最终伤害
    unsigned int cur = 0;  // 当前构造的初始攻击力
    
    // 从高位到低位贪心选择，由于数据范围，循环到第 29 位即可，但第 31 位开始也可以
    for (int i = 31; i >= 0; i--) {
        // 如果该位初始为 0 最终能得到 1，则直接选择 0
        if ((zero >> i) & 1) {
            ans |= (1u << i);
        }
        // 否则如果该位初始为 1 最终能得到 1，且选择后不超过 m，则选择 1
        else if (((one >> i) & 1) && (cur + (1u << i) <= m)) {
            ans |= (1u << i);
            cur += (1u << i);
        }
        // 否则该位只能为 0，最终结果也为 0，无需操作
    }
    
    printf("%u\n", ans);
    return 0;
}
