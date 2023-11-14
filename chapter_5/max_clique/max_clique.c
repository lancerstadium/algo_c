/**
 * Max clique 最大团问题
 * 问题描述：指在一个无向图中寻找一个完全子图，使得这个子图中的任意两个顶点都有一条边相连，并且这个完全子图的顶点数最大。
 * 算法思想：回溯算法解决最大团问题思路：
 *      1. 从图中任选一个顶点作为起始点，将其加入当前团中；
 *      2. 逐个考察与当前团中的顶点相邻且未加入团中的顶点，直到无法再加入新的顶点，考虑两种情况：
 *          a. 若该顶点可以加入当前团，则将其加入当前团中；
 *          b. 若该顶点不可以加入当前团，则回溯到上一个顶点。
 *      4. 在递归搜索的过程中，记录最大的团的大小和对应的顶点集合。
 *
 * 时间复杂度：O(2^n)
 * 空间复杂度：O(n)
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 max_clique.c -o max_clique
 * 运行指令：.\max_clique.exe
*/

#include <stdio.h>
#include <stdbool.h>

#define V 5 // 顶点数


// 判断顶点v是否可以加入最大团
bool isSafe(int v, bool clique[], int graph[V][V], int pos) {
    for (int i = 0; i < pos; i++) {
        if (graph[v][clique[i]] == 0) {
            return false;
        }
    }
    return true;
}

/// @brief 找到最大团的递归函数
/// @param v 当前顶点
/// @param clique 当前团
/// @param pos 当前团的大小
/// @param maxSize 最大团的大小
/// @param maxClique 最大团
/// @param graph 图
void findMaxCliqueUtil(int v, bool clique[], int pos, int *maxSize, bool *maxClique, int graph[V][V]) {
    // 1. 递归出口：当前团的大小等于顶点数
    if (v == V) {
        if (pos > *maxSize) {
            *maxSize = pos;
            for (int i = 0; i < pos; i++) {
                maxClique[i] = clique[i];
            }
        }
        return;
    }

    // 2. 如果当前顶点可以加入最大团，加入并递归执行
    if (isSafe(v, clique, graph, pos)) {
        clique[pos] = true;
        findMaxCliqueUtil(v + 1, clique, pos + 1, maxSize, maxClique, graph);
    }

    // 3. 否则，不加入最大团，递归执行
    findMaxCliqueUtil(v + 1, clique, pos, maxSize, maxClique, graph);
}

// 打印最大团
void printSolution(bool maxClique[], int maxSize) {
    printf("Maximum Clique: ");
    for (int i = 0; i < maxSize; i++) {
        if (maxClique[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("Size: %d\n", maxSize);
}

// 找到最大团
void findMaxClique(int graph[V][V]) {
    bool maxClique[V];  // 存储最大团的顶点集
    bool clique[V];     // 存储当前团的顶点集
    int maxSize = 0;    // 最大团的大小

    findMaxCliqueUtil(0, clique, 0, &maxSize, maxClique, graph);

    printSolution(maxClique, maxSize);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };
    findMaxClique(graph);
    return 0;
}
