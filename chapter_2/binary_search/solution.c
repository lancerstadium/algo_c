/**
 * Binary search 二分查找
 * 编译器：https://www.programiz.com/c-programming/online-compiler/
 * 算法思路：使用递归
 * 输入：有序数组、目标元素
 * 输出：目标元素下标
 * ```
 * Index of 7 is 4.
 * ```
*/

#include <stdio.h>

int binary_search(int arr[], int left, int right, int target)
{
    // 1. 递归终止条件：如果left > right
    if(left >= right)
        return -1;
    int mid = (left + right) / 2;
    
    // 2. 如果找到则返回
    if(arr[mid] == target){
        return mid;
    } else if(arr[mid] > target) {
        // 中间值大于 target 递归左半
        binary_search(arr, left, mid, target);
    } else{
        // 中间值小于 target 递归右半
        binary_search(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {-1, 3, 4, 5, 7, 10, 14};   // 有序数组
    int n = sizeof(arr)/sizeof(arr[0]);     // 数组长度
    int target = 7;                         // 目标元素

    int index = binary_search(arr, 0, n-1, target);
    printf("Index of %d is %d.\n", target, index);
    return 0;
}