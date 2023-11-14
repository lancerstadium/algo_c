/**
 * 0-1 Bag problem 背包问题
 * 问题描述：0-1背包问题是指在一个背包中，放入物品的总重量不超过背包的总容量时，能够装入的最大重量是多少。
 * 算法思想：给定n个物品，每个物品的重量为w[i]，价值为v[i]，背包容量为C，
 *      求解在不超过背包容量的情况下，最多能放入背包的物品的总价值。
 *      动态规划是解决01背包问题的常用方法。算法的思想可以简要概括如下：
 *      1. 定义状态：首先需要定义一个二维数组dp[i][j]，其中dp[i][j]表示在前i个物品中，背包容量为j时所能获得的最大价值。
 *          状态转移方程：接下来需要确定状态转移方程。对于第i个物品，有两种情况：
 *              a. 如果第i个物品不放入背包，则dp[i][j] = dp[i-1][j]；
 *              b. 如果第i个物品放入背包，则dp[i][j] = dp[i-1][j-w[i]] + v[i]，其中w[i]表示第i个物品的重量，v[i]表示第i个物品的价值。
 *          综合考虑这两种情况，状态转移方程可以表示为：
 *              dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])
 *      2. 初始化：对于状态数组dp的初始化，一般来说，当物品数量为0或者背包容量为0时，对应的最大价值都为0，因此可以进行初始化。
 *      3. 填表求解：根据状态转移方程，从状态数组的初始状态开始，依次填表求解dp[i][j]的值，直到填满整个状态数组。
 *      4. 最优解：最终的最优解即为dp[n][C]，其中n表示物品的数量，C表示背包的容量。
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

// 定义最大物品数量和最大背包容量
#define MAX_N 100
#define MAX_C 1000

// 定义物品的重量和价值
int w[MAX_N], v[MAX_N];

// 定义动态规划数组
int dp[MAX_N + 1][MAX_C + 1];

// 返回a和b的最大值
int max(int a, int b) {
    return a > b ? a : b;
}

// 动态规划求解01背包问题
int knapsack(int n, int C) {
    // 1. 初始化边界条件
    for (int j = 0; j <= C; j++) {
        dp[0][j] = 0;
    }

    // 2. 填表求解
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // 3. 返回最优解
    return dp[n][C];
}

int main() {
    int n, C;
    printf("Enter the number of items: ");          // 物品数量
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: "); // 背包容量
    scanf("%d", &C);
    
    // 生成随机种子
    srand(time(0));

    // 生成随机的重量和价值
    for (int i = 1; i <= n; i++) {
        w[i] = rand() % 100 + 1; // 随机生成1到100的重量
        v[i] = rand() % 100 + 1; // 随机生成1到100的价值
    }

    // 打印物品的重量和价值
    printf("The weights and values of the items are:\n");
    for (int i = 1; i <= n; i++) {
        printf("Item %d: weight = %d, value = %d\n", i, w[i], v[i]);
    }

    int result = knapsack(n, C);
    printf("The maximum value that can be obtained is: %d\n", result);

    return 0;
}

