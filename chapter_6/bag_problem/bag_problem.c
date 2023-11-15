/**
 * 0-1 Bag problem 背包问题
 * 问题描述：0-1背包问题是指在一个背包中，放入物品的总重量不超过背包的总容量时，能够装入的最大重量是多少。
 * 算法思想：用分支限界法解决01背包问题，思路如下：
 * 
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 bag_problem.c -o bag_problem
 * 运行指令：.\bag_problem.exe
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100       // 物品最大数量
#define MAX_W 1000      // 背包最大容量


// 定义物品的重量和价值
int w[MAX_N], v[MAX_N];

int max_value = 0;  // 最大价值
int n = 0;  // 物品数量
int C = 0;  // 背包容量

void knapsack(int i, int now_w, int now_v) {
    // 1. 递归出口：当到达最后一个物品时，更新最大价值
    if(i > n) {
        if(now_v > max_value) {
            max_value = now_v;
        }
        return;
    }
    // 2. 递归调用
    if(now_w + w[i] > w) {
        // 当前重量加上第i个物品的重量大于背包容量时，只能选择不放入第i个物品
        knapsack(i+1, now_w, now_v);
    } else {
        // 当前重量加上第i个物品的重量小于背包容量时，可以选择放入第i个物品
        knapsack(i+1, now_w + w[i], now_v + v[i]);
        // 或者不放入第i个物品
        knapsack(i+1, now_w, now_v); 
    }
}




int main() {
    printf("Enter the number of items: ");          // 物品数量
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: "); // 背包容量
    scanf("%d", &C);
    
    // 生成随机种子
    srand(time(0));

    // 生成随机的重量和价值
    for (int i = 0; i < n; i++) {
        w[i] = rand() % 100 + 1; // 随机生成1到100的重量
        v[i] = rand() % 100 + 1; // 随机生成1到100的价值
    }

    // 打印物品的重量和价值
    printf("The weights and values of the items are:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: weight = %d, value = %d\n", i+1, w[i], v[i]);
    }

    knapsack(0, 0, 0);
    printf("The maximum value that can be obtained is: %d\n", max_value);
    return 0;
}

