/**
 * augmenting_path 增广路径
 * 问题描述：给定一个有向图，找到一个增广路径，使得路径上的所有边的权值之和最小，返回最小权值。
 * 算法思想：可以使用Dijkstra算法来解决这个问题。
 *      Dijkstra算法是一种贪心算法，它从起始顶点开始，逐步扩展到其他顶点，直到找到目标顶点。
 *      在每一步中，它选择当前距离起始顶点最短的顶点，并更新与该顶点相邻的顶点的距离。
 *      这样，最终我们就可以找到从起始顶点到目标顶点的最短路径。
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 augmenting_path.c -o augmenting_path
 * 运行指令：.\augmenting_path.exe
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // 顶点数

/// @brief 寻找最短路径
/// @param dist 距离数组
/// @param sptSet 标记数组
/// @return 最短路径的顶点下标
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

/// @brief Dijkstra算法
/// @param graph 图
/// @param src 起始顶点
/// @param dest 目标顶点
/// @return 最短路径的权值
int dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];        // 存储源点到各个顶点的距离
    bool sptSet[V];     // 记录顶点是否已加入最短路径

    // 1. 初始化
    for (int i = 0; i < V; i++) {   
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;  // 初始化源点到自身的距离为0

    // 2. 遍历所有的顶点，从未被访问的顶点中选择距离最近的顶点u，将u标记为已访问
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        // 3. 对于顶点u的每个邻接顶点v，如果通过顶点u到达顶点v的距离比当前记录的距离小，则更新距离值
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist[dest];
}

/// @brief 打印图
/// @param graph 图
void printGraph(int graph[V][V]) {
    printf("The graph is:\n");
    for (int i = 0; i < V; i++) {
        printf("node%d: ", i);
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {0, 0, 8, 0, 0, 0},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0}
    };
    printGraph(graph);

    int src = 0, dest = 5;
    int minWeight = dijkstra(graph, src, dest);
    printf("The minimum weight of the shortest path from %d to %d is %d\n", src, dest, minWeight);

    return 0;
}
