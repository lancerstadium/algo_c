/**
 * Close dot 1D 最接近点对问题
 * 问题描述：在一维数组中找到最接近的点对，点对的距离是两个点的欧氏距离
 * 算法思想：分治，将一维数组分为两半，递归调用自身，然后合并，最后得到最接近的点对
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 close_dot.c -o close_dot
 * 运行指令：.\close_dot.exe
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 计算两个点之间的距离
double distance(double x1, double x2) {
    return fabs(x1 - x2);
}

// 比较函数，用于qsort排序
int compare(const void *a, const void *b) {
    return *(double *)a - *(double *)b;
}


// 递归求解一维最接近点对
double close_dot(double arr[], int n) {
    // 1. 递归结束条件：如果元素个数小于等于3，使用暴力搜索
    if (n <= 3) {
        double min = INFINITY;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = distance(arr[i], arr[j]);
                if (dist < min) {
                    min = dist;
                }
            }
        }
        return min;
    }

    // 2. 按照数值对点进行排序
    qsort(arr, n, sizeof(double), compare);

    // 3. 分成两部分，并递归解决
    int mid = n / 2;                            // 中间点
    double dl = close_dot(arr, mid);            // 左半部分
    double dr = close_dot(arr + mid, n - mid);  // 右半部分
    double d = fmin(dl, dr);                    // d为最小距离

    return d;
}




int main() {
    double arr[] = {13.4, 15.6, 2.4, 5.6, 17.8, 11.2, 9.8};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\nmin distance: %.2f\n", close_dot(arr, n));
}





