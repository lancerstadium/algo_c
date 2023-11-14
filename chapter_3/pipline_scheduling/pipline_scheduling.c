/**
 * Pipeline scheduling 流水线作业调度问题
 * 问题描述：流水线上有若干个作业需要处理，每个作业在不同的流水线上需要花费不同的时间，
 *          如何安排作业的顺序以使得作业的总处理时间最短的问题。
 * 算法思想：动态规划解决批处理作业调度问题的算法思想如下：
 *          1. 定义状态：首先需要定义一个二维数组dp[i][j]，其中dp[i][j]表示第i个作业在第j条流水线上完成时的最早完成时间。
 *              状态转移方程：dp[i][j] = min(dp[i-1][k] + processingTime[i][j])
 *              对于第i个作业，它在第j条流水线上完成时的最早完成时间可以通过前一个作业在各个流水线上的最早完成时间和第i个作业在第j条流水线上的处理时间来计算。
 *          2. 初始化：对于第一个作业而言，它在任何一条流水线上的最早完成时间都是它自己的处理时间。
 *          3. 填表求解：根据状态转移方程，从状态数组的初始状态开始，依次填表求解dp[i][j]的值，直到填满整个状态数组。
 *          4. 最优解：最终的最优解即为最后一个作业在各个流水线上的最早完成时间的最小值。
 * 
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 pipline_scheduling.c -o pipline_scheduling
 * 运行指令：.\pipline_scheduling
*/

#include <stdio.h>

// 定义流水线的数量和作业的数量
#define PROC_NUM 3
#define JOB_NUM 4

// 定义每个作业在各个流水线上的处理时间
int processingTime[JOB_NUM][PROC_NUM] = {{3, 6, 7}, {8, 5, 9}, {4, 7, 2}, {2, 3, 6}};

// 定义动态规划数组
int dp[JOB_NUM][PROC_NUM];

// 返回a和b的最小值
int min(int a, int b) {
    return a < b ? a : b;
}

// 动态规划求解流水作业调度问题
int flowShopScheduling() {
    // 1. 初始化边界条件：对于第一个作业而言，它在任何一条流水线上的最早完成时间都是它自己的处理时间
    for (int j = 0; j < PROC_NUM; j++) {
        dp[0][j] = processingTime[0][j];
    }

    // 2. 填表求解
    for (int i = 1; i < JOB_NUM; i++) {
        for (int j = 0; j < PROC_NUM; j++) {
            dp[i][j] = dp[i-1][j] + processingTime[i][j];
            if (j > 0) {    // 如果不是第一个流水线：比较前一个作业在第j条流水线上的最早完成时间和第i个作业在第j条流水线上的处理时间
                dp[i][j] = min(dp[i][j], dp[i][j-1] + processingTime[i][j]);
            }
        }
    }

    // 3. 返回最优解
    return dp[JOB_NUM-1][PROC_NUM-1];
}

int main() {
    int result = flowShopScheduling();
    // 打印作业在各个流水线上处理时间
    for (int i = 0; i < JOB_NUM; i++) {
        printf("Job %d: ", i+1);
        for (int j = 0; j < PROC_NUM; j++) {
            printf("%d ", processingTime[i][j]);
        }
        printf("\n");
    }


    printf("Minimum completion time is: %d\n", result);
    return 0;
}
