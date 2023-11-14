/**
 * Max clique 最大团问题
 * 问题描述：指在一个无向图中寻找一个完全子图，使得这个子图中的任意两个顶点都有一条边相连，并且这个完全子图的顶点数最大。
 * 算法思想：回溯算法解决最大团问题思路：
 *      1. 从图中任选一个顶点作为起始点，将其加入当前团中。
 *      2. 逐个考察与当前团中的顶点相邻且未加入团中的顶点，将它们加入团中，形成一个新的候选团。
 *      3. 对新的候选团进行递归搜索，在每一步搜索中，都尝试将一个未加入团中的相邻顶点加入团中，直到无法再加入新的顶点。
 *      4. 在递归搜索的过程中，记录最大的团的大小和对应的顶点集合。
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 max_clique.c -o max_clique
 * 运行指令：.\max_clique.exe
*/

#include <stdio.h>
#include <stdbool.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0}
};

bool isSafe(int v, bool clique[], int graph[V][V], int pos) {
    for (int i = 0; i < pos; i++) {
        if (graph[v][clique[i]] == 0) {
            return false;
        }
    }
    return true;
}

void findMaxCliqueUtil(int v, bool clique[], int pos, int *maxSize, bool *maxClique, int graph[V][V]) {
    if (v == V) {
        if (pos > *maxSize) {
            *maxSize = pos;
            for (int i = 0; i < pos; i++) {
                maxClique[i] = clique[i];
            }
        }
        return;
    }

    if (isSafe(v, clique, graph, pos)) {
        clique[pos] = v;
        findMaxCliqueUtil(v + 1, clique, pos + 1, maxSize, maxClique, graph);
    }

    findMaxCliqueUtil(v + 1, clique, pos, maxSize, maxClique, graph);
}

int main() {
    bool maxClique[V];
    bool clique[V];
    int maxSize = 0;
    // 打印图
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    findMaxCliqueUtil(0, clique, 0, &maxSize, maxClique, graph);

    printf("The maximum clique is: ");
    for (int i = 0; i < maxSize; i++) {
        printf("%d ", maxClique[i]);
    }
    return 0;
}
