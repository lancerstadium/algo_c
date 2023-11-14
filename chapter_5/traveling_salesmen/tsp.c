/**
 * Traveling Salesmen TSP 旅行商问题
 * 问题描述：目标是找到一条最短的路径，使得旅行商可以访问所有城市并回到起点。
 *      在TSP中，旅行商需要访问每个城市一次，然后返回起点城市，
 *      而且每个城市都只能被访问一次。
 *      该问题是一个NP难题，随着城市数量的增加，
 *      计算所有可能的路径的数量呈指数级增长。
 * 算法思想：使用回溯法解决TSP问题
 *      1. 从起始城市开始，逐个访问每个城市，并尝试找到一条最短的路径；
 *      2. 对于每个城市，都需要考虑两种情况：
 *          a. 如果当前城市还未被访问过，可以选择访问它并继续搜索；
 *          b. 如果当前城市已经被访问过，需要回溯到上一个城市并尝试其他路径；
 *      3. 在递归的过程中，需要记录当前路径的长度，并找到最短的路径。
 * 
 * 时间复杂度：O(2^n)
 * 空间复杂度：O(n)
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 tsp.c -o tsp
 * 运行指令：.\tsp.exe
*/


#include <stdio.h>
#include <stdbool.h>

#define N 6         // 城市数量
#define INF 999999  // 无穷大

int graph[N][N] = {
    {0, 10, 15, 20, 25, 30},
    {10, 0, 35, 40, 45, 50},
    {15, 35, 0, 55, 60, 65},
    {20, 40, 55, 0, 75, 80},
    {25, 45, 60, 75, 0, 85},
    {30, 50, 65, 80, 85, 0}
};

//
int min(int a, int b) {
    return (a < b) ? a : b;
}

/// @brief 回溯求解旅行商问题
/// @param current 当前城市
/// @param visited 访问过的城市
/// @param count 访问过的城市数量
/// @param cost 当前路径长度
/// @param path 当前路径
/// @param minCost 最短路径
/// @param minPath 最短路径
void tspUtil(int current, bool visited[], int count, int cost, int path[], int *minCost, int minPath[]) {
    if (count == N) {
        if (graph[current][0] != 0) {
            if ((cost + graph[current][0]) < *minCost) {
                *minCost = cost + graph[current][0];
                for (int i = 0; i < N; i++) {
                    minPath[i] = path[i];
                }
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[current][i] != 0) {
            path[count] = i;
            visited[i] = true;
            tspUtil(i, visited, count + 1, cost + graph[current][i], path, minCost, minPath);
            visited[i] = false;
        }
    }
}

void tsp(int graph[N][N]) {
    int path[N];        // 当前路径
    int minPath[N];     // 最短路径
    int minCost = INF;  // 最短路径长度
    bool visited[N] = {false};  // 访问过的城市

    path[0] = 0;        // 起始城市
    visited[0] = true;  // 起始城市已经访问过
    tspUtil(0, visited, 1, 0, path, &minCost, minPath);

    printf("The shortest path is: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", minPath[i]);
    }
    printf("\nThe cost is: %d\n", minCost);
}

void printGraph(int graph[N][N]) {
    printf("The graph is: \n");
    for (int i = 0; i < N; i++) {
        printf("city%d : ", i);
        for (int j = 0; j < N; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printGraph(graph);
    tsp(graph);
    return 0;
}

