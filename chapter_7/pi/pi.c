/**
 * estimatePi 投点法计算pi值
 * 问题描述：计算pi值
 * 算法思想：使用了rand()函数来生成随机的x和y坐标，
 *      然后计算这些点到圆心的距离，最后统计落在圆内的点的数量，
 *      并根据投点法的原理计算出π的估计值。
 * 时间复杂度：
 * 空间复杂度：
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 pi.c -o pi
 * 运行指令：.\pi
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double estimatePi(int numPoints) {
    int pointsInsideCircle = 0;

    // 设置随机数种子
    srand(time(NULL));

    for (int i = 0; i < numPoints; i++) {
        double x = (double)rand() / RAND_MAX;  // 在0到1之间生成随机x坐标
        double y = (double)rand() / RAND_MAX;  // 在0到1之间生成随机y坐标

        // 计算点到圆心的距离
        double distance = x * x + y * y;

        // 如果距离小于1，则点在圆内
        if (distance <= 1) {
            pointsInsideCircle++;
        }
    }

    // 计算π值的估计
    double pi = 4 * (double)pointsInsideCircle / numPoints;
    return pi;
}

int main() {
    int numPoints = 1000000;  // 投点数量
    double pi = estimatePi(numPoints);
    printf("Estimated value of pi: %f\n", pi);

    return 0;
}
