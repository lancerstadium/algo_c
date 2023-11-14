/**
 * Best load 最佳负载问题
 * 问题描述：最优负载问题是指在一组任务和一组处理器之间分配任务，使得处理器的负载尽可能均衡。
 * 算法思想：使用贪心算法解决最优负载问题的算法思路：
 *      1. 首先，将所有的任务按照其负载大小进行排序，负载最大的任务排在前面。
 *      2. 然后，依次将每个任务分配给当前负载最小的处理器。
 *      3. 每次分配任务后，更新处理器的负载，选择当前负载最小的处理器进行分配。
 * 
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 best_load.c -o best_load
 * 运行指令：.\best_load.exe
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义处理器数量
#define PROC_NUM 3

// 定义任务数量
#define TASK_NUM 9

// 任务负载
int tasks[TASK_NUM] = {8, 4, 9, 12, 6, 8, 9, 11, 3};

// 处理器负载
int processors[PROC_NUM];

// 找到当前负载最小的处理器
int findMinLoadProcessor() {
    int minLoad = processors[0];
    int minIndex = 0;
    for (int i = 1; i < PROC_NUM; i++) {
        if (processors[i] < minLoad) {
            minLoad = processors[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int compareLoad(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

// 分配任务给处理器
void assignTaskToProcessor(int task) {
    int minLoadProcessor = findMinLoadProcessor();
    processors[minLoadProcessor] += tasks[task];
    printf("Task %d assigned to processor %d, load: %d\n", task, minLoadProcessor, processors[minLoadProcessor]);
}

void greedyBestLoad() {
    // 1. 初始化处理器负载
    for (int i = 0; i < PROC_NUM; i++) {
        processors[i] = 0;
    }
    // 2. 对任务按照负载大小进行排序
    qsort(tasks, TASK_NUM, sizeof(int), compareLoad);

    // 3. 依次分配任务给处理器
    printf("Assigned tasks:\n");
    for (int i = 0; i < TASK_NUM; i++) {
        assignTaskToProcessor(i);
    }
}

int main() {

    // 调用贪心算法
    greedyBestLoad();

    // 输出处理器的负载
    printf("Processor loads:\n");
    for (int i = 0; i < PROC_NUM; i++) {
        printf("Processor %d: %d\n", i, processors[i]);
    }

    return 0;
}



