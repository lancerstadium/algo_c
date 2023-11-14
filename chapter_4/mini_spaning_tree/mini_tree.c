/**
 * Mini spaning tree 最小生成树问题
 * 问题描述：
 * 算法思想：使用贪心算法解决最小生成树问题的经典算法是Prim算法：
 *      1. 初始化一个数组key[]，用来保存源点到各个顶点的权值，初始时源点到自身的权值为0，到其他顶点的权值为无穷大；
 *      2. 初始化一个数组parent[]，用来保存最小生成树的父节点；
 *      3. 初始化一个数组mstSet[]，用来标记顶点是否已加入最小生成树；
 *      4. 选择一个顶点作为起始点，将其加入最小生成树中；
 *      5. 重复以下步骤，直到所有顶点都加入最小生成树：
 *          a. 从已加入最小生成树的顶点中选择一个顶点v，找到与v相连的未加入最小生成树的顶点中权值最小的边。
 *          b. 将该边的另一端顶点加入最小生成树。
 * 
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 mini_tree.c -o mini_tree
 * 运行指令：.\mini_tree.exe
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // 顶点数

// 寻找最小权值边连接的顶点
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// 打印最小生成树
void printSolution(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// prim算法
void primMST(int graph[V][V]) {
    int parent[V];      // 存储最小生成树的父节点
    int key[V];         // 存储最小生成树的权值
    bool mstSet[V];     // 记录顶点是否已加入最小生成树

    // 1. 初始化
    for (int i = 0; i < V; i++) { 
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // 2. 选择0为第一个顶点，其父节点为-1
    key[0] = 0;
    parent[0] = -1;

    // 遍历所有的顶点
    for (int count = 0; count < V - 1; count++) {
        // 3. 从未被访问的顶点中选择权值最小的边的顶点，将点加入最小生成树
        int u = minKey(key, mstSet);    
        mstSet[u] = true;               

        // 4. 对于顶点u的每个邻接顶点v，如果通过顶点u到达顶点v的距离比当前记录的距离小，则更新生成树的权值
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 打印最小生成树
    printSolution(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}


