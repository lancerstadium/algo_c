/**
 * max_network_flow 最大网络流
 * 问题描述：网络最大流问题是指在一个有向图中，每条边都有一个容量限制，
 *      而源点和汇点之间存在流量的传输。
 *      问题的目标是找到从源点到汇点的最大流量，
 *      即在给定的网络中能够从源点到汇点传输的最大数据量。
 * 算法思想：Ford-Fulkerson算法求解网络最大流问题：
 *      1. 首先创建一个残余图，将其初始化为原始图的副本；
 *      2. 在残余图上执行广度优先搜索（BFS），以查找增广路径：
 *          如果存在增广路径，则找到该路径上的最小容量（即最小残余容量），并更新残余图。
 *      3. 重复步骤2，直到没有增广路径为止；
 *      4. 最后，计算最大流的值，即通过增广路径所能通过的最大容量之和。
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 max_netflow.c -o max_netflow
 * 运行指令：.\max_netflow.exe
*/



#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6     // 顶点数


/// @brief 广度优先搜索（BFS）
/// @param rGraph 残余图
/// @param s 起始点
/// @param t 终止点
/// @param parent 记录路径
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    // 1. 初始化
    bool visited[V];            // 访问标记
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    int queue[V];               // 队列
    int front = 0, rear = 0;    // 队列头，队列尾

    // 2. 将起始点加入队列
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    // 3. 广度优先搜索
    while (front != rear) {
        int u = queue[front++];   // 出队
        for (int v = 0; v < V; ++v) {   
            // 如果存在一条从u到v的边且v未被访问
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

/// @brief fordFulkerson 网络最大流
/// @param graph 原始图
/// @param s 起始点
/// @param t 终止点
int fordFulkerson(int graph[V][V], int s, int t) {
    // 1. 初始化：将残余图初始化为原始图
    int rGraph[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            rGraph[i][j] = graph[i][j];
        }
    }

    int parent[V];       // 记录路径
    int max_flow = 0;    // 最大流

    // 2. 执行广度优先搜索：寻找增广路径
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;    // 最小残余容量
        // 找到最小残余容量
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];  // 父节点
            // 最小残余容量 = 
            path_flow = path_flow < rGraph[u][v] ? path_flow : rGraph[u][v];
        }

        // 3. 更新残余图
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        // 4. 更新最大流
        max_flow += path_flow;
    }

    // 打印记录路径
    printf("Path: \n");
    for (int i = 0; i < V; ++i) {
        printf("%d -> %d, value: %d\n", parent[i], i, graph[parent[i]][i]);
    }

    return max_flow;
}

/// @brief 打印图
/// @param graph 图
void printGraph(int graph[V][V]) {
    printf("Graph:\n");
    for (int i = 0; i < V; ++i) {
        printf("node%d: ", i);
        for (int j = 0; j < V; ++j) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
    };

    printGraph(graph);

    int source = 0, sink = 5;
    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink));
    return 0;
}
