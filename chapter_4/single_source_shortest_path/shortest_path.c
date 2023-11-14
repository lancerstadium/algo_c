/**
 * Single source shortest path 单源最短路径问题
 * 问题描述：给定一张有向图，求出从起点到终点的最短路径。
 * 算法思想：使用Dijkstra算法解决单源最短路径问题
 *      1. 初始化一个数组dist[]，用来保存源点到各个顶点的距离，初始时源点到自身的距离为0，到其他顶点的距离为无穷大；
 *      2. 初始化一个数组visited[]，用来标记顶点是否已经被访问过，初始时所有顶点均未被访问；
 *      3. 从未被访问的顶点中选择距离最近的顶点u，将u标记为已访问；
 *      4. 对于顶点u的每个邻接顶点v，如果通过顶点u到达顶点v的距离比当前记录的距离小，则更新距离值；
 *      5. 重复步骤3和步骤4，直到所有顶点都被访问。
 * 
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 shortest_path.c -o shortest_path
 * 运行指令：.\shortest_path.exe
*/


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // 顶点数

// 寻找最短路径
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// 打印最短路径
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];        // 存储源点到各个顶点的距离
    bool sptSet[V];     // 记录顶点是否已加入最短路径

    // 1. 初始化
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // 2. 初始化源点到自身的距离为0
    dist[src] = 0;
    
    // 遍历所有的顶点
    for (int count = 0; count < V - 1; count++) {
        // 3. 从未被访问的顶点中选择距离最近的顶点u，将u标记为已访问
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        // 4. 对于顶点u的每个邻接顶点v，如果通过顶点u到达顶点v的距离比当前记录的距离小，则更新距离值
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
