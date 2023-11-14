/**
 * intergrate 投点法求积
 * 问题描述：计算定积分
 * 算法思想：使用了rand()函数生成随机的x和y坐标，
 *      然后统计落在曲线下方的点的数量，
 *      并根据投点法的原理计算出定积分的估计值。
 *      这个方法的精度取决于投点数量的多少，
 *      投点数量越大，估计的定积分值越精确。
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

double f(double x) {
    return x * x;  // 定义被积函数f(x) = x^2
}

double integrateFunction(int numPoints) {
    int pointsBelowCurve = 0;

    // 设置随机数种子
    srand(time(NULL));

    for (int i = 0; i < numPoints; i++) {
        double x = (double)rand() / RAND_MAX;  // 在0到1之间生成随机x坐标
        double y = (double)rand() / RAND_MAX;  // 在0到1之间生成随机y坐标

        // 如果随机点在曲线下方，则计数加一
        if (y <= f(x)) {
            pointsBelowCurve++;
        }
    }

    // 计算定积分的估计值
    double integral = (double)pointsBelowCurve / numPoints;
    return integral;
}

int main() {
    int numPoints = 1000000;  // 投点数量
    double integral = integrateFunction(numPoints);
    printf("Caculate f(x) = x^2 from 0 to 1\n");
    printf("Estimated value of the definite integral: %f\n", integral);

    return 0;
}
