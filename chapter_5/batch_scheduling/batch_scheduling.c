/**
 * Batch scheduling 批处理作业调度问题
 * 问题描述：有若干个作业需要处理，每个作业在不同的位置上需要花费不同的时间，
 *          如何安排作业的顺序以使得作业的总处理时间最短的问题。
 * 算法思想：
 *      1. 从第一个作业开始，逐个尝试将每个作业安排在不同的位置；
 *      2. 对于每个位置，都需要考虑两种情况：将当前作业放在这个位置和不放在这个位置；
 *          a. 如果放在这个位置，那么这个位置的完成时间将是前一个作业的完成时间加上这个作业的处理时间；
 *          b. 如果不放在这个位置，那么这个位置的完成时间将是前一个作业的完成时间；
 *      3. 在递归的过程中，需要记录当前作业的顺序和已经安排的作业的完成时间，并找到最短的完成时间。
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 batch_scheduling.c -o batch_scheduling
 * 运行指令：.\batch_scheduling.exe
*/


#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 6 // 作业数量
#define M 3 // 流水线阶段数量

int processingTime[N][M] = {
    {1, 2, 3},
    {2, 3, 1},
    {4, 2, 3},
    {1, 2, 3},
    {3, 4, 2},
    {4, 3, 1}
};

int minCompletionTime = INT_MAX; // 最短的作业完成时间
int currentCompletionTime = 0; // 当前作业完成时间
int currentSchedule[N]; // 当前调度方案
int bestSchedule[N]; // 最优调度方案

void pipelineSchedulingUtil(int currentJob, bool assigned[]) {
    if (currentJob == N) {
        if (currentCompletionTime < minCompletionTime) {
            minCompletionTime = currentCompletionTime;
            for (int i = 0; i < N; i++) {
                bestSchedule[i] = currentSchedule[i];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!assigned[i]) {
            assigned[i] = true; // 标记作业i已经被安排
            currentSchedule[currentJob] = i; // 记录当前作业的调度顺序
            for (int j = 0; j < M; j++) {
                currentCompletionTime += processingTime[i][j]; // 更新当前作业完成时间
                pipelineSchedulingUtil(currentJob + 1, assigned); // 递归调用，尝试下一个作业
            }
            assigned[i] = false; // 回溯，取消作业i的安排
            for (int j = 0; j < M; j++) {
                currentCompletionTime -= processingTime[i][j]; // 回溯，恢复当前作业完成时间
            }
        }
    }
}

void pipelineScheduling(int processingTime[N][M]) {
    bool assigned[N] = {false}; // 记录作业是否已经被安排
    pipelineSchedulingUtil(0, assigned);
    printf("The minimum completion time is: %d\n", minCompletionTime);
    printf("The best schedule is: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", bestSchedule[i]);
    }
    printf("\n");
}

void printProcessingTime() {
    printf("The processing time is: \n");
    for (int i = 0; i < N; i++) {
        printf("Job %d: ", i+1);
        for (int j = 0; j < M; j++) {
            printf("%d ", processingTime[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printProcessingTime();
    pipelineScheduling(processingTime);
    return 0;
}


