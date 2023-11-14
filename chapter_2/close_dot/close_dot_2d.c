/**
 * Close dot 2D 最接近点对问题
 * 问题描述：在二维数组中找到最接近的点对，点对的距离是两个点的欧氏距离
 * 算法思想：分治，将二维数组分为两半，递归调用自身，然后合并，最后得到最接近的点对
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 close_dot_2d.c -o close_dot_2d
 * 运行指令：.\close_dot_2d.exe
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义二维点的结构体
typedef struct {
    double x;
    double y;
} Point;

// 计算两个点之间的距离
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 比较函数，用于qsort排序
int compareX(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// 分治法求解最接近点对问题
double closestPair(Point points[], int n) {
    if (n <= 3) {
        // 当点的数量小于等于3时，使用暴力搜索
        double min = INFINITY;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = distance(points[i], points[j]);
                if (dist < min) {
                    min = dist;
                }
            }
        }
        return min;
    }

    // 按照x坐标对点进行排序
    qsort(points, n, sizeof(Point), compareX);

    // 分成两部分，并递归解决
    int mid = n / 2;
    double dl = closestPair(points, mid);
    double dr = closestPair(points + mid, n - mid);
    double d = fmin(dl, dr);

    // 找出中间部分距离小于d的点
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip[j] = points[i];
            j++;
        }
    }

    // 按照y坐标对strip中的点进行排序
    qsort(strip, j, sizeof(Point), compareY);

    // 检查strip中的点对
    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++) {
            double dist = distance(strip[i], strip[k]);
            if (dist < d) {
                d = dist;
            }
        }
    }

    return d;
}

int main() {
    // 一组测试点
    Point points[] = {{1, 1}, {2, 3}, {5, 4}, {7, 2}, {9, 6}, {8, 8}};
    int n = sizeof(points) / sizeof(points[0]);

    // 调用分治法求解最接近点对问题
    double minDistance = closestPair(points, n);
    printf("closest pair distance: %f\n", minDistance);

    return 0;
}



