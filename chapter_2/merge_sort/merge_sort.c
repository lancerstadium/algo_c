/**
 * Merge sort 归并排序
 * 问题描述：对有序数组进行排序
 * 算法思想：归并排序，将数组分为两半，递归调用自身，然后合并，最后得到有序数组
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 操作系统：Windows 11
 * 编译器：GCC 11.2.0
 * C标准：C11
 * 编译指令：gcc --std=c11 merge_sort.c -o merge_sort
 * 运行指令：.\merge_sort.exe
*/

#include <stdio.h>

/// @brief 归并
/// @param arr 数组
/// @param left 左侧元素
/// @param mid 中间元素
/// @param right 右侧元素
void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1]; // 临时数组：存储排序后的数组，大小为 right - left + 1
    int i = left;               // 左指针：指向左侧元素
    int j = mid + 1;            // 右指针：指向中间元素
    int k = 0;                  // 临时数组指针
    while (i <= mid && j <= right) {    // 1. 如果左右指针都没有越界，则继续循环
        if (arr[i] < arr[j]) {          // 1.1 如果左指针的元素小于右指针的元素，将左指针的元素放入临时数组，并将左指针右移
            temp[k++] = arr[i++];
        } else {                        // 1.2 如果右指针的元素小于左指针的元素，将右指针的元素放入临时数组，并将右指针右移
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {                  // 2. 如果左指针没有越界，将剩余的元素放入临时数组
        temp[k++] = arr[i++];
    }
    while (j <= right) {                // 3. 如果右指针没有越界，将剩余的元素放入临时数组
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++) {           // 4. 将临时数组的元素放入原数组
        arr[left + i] = temp[i];
    }
}

/// @brief 归并排序
/// @param arr 数组
/// @param left 左侧元素
/// @param right 右侧元素
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}



int main() {
    int arr[] = {10, 2, 4, 8, 1, 3, 7, 9, 15, -4};    // 无序数组 arr
    merge_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}