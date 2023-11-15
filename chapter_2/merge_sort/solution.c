/**
 * Merge Sort 归并排序
 * 编译器：https://www.programiz.com/c-programming/online-compiler/
 * 算法思路：使用递归
 * 输入：无序数组
 * 输出：有序数组
 * 
*/

void merge(int arr[], int left, int mid, int right) {
    int temp_arr[right - left + 1]; // 临时数组
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    // 如果都没到顶，继续迭代
    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            temp_arr[k++] = arr[i++];
        }else {
            temp_arr[k++] = arr[j++];
        }
    }
    
    // 处理剩余元素
    while(i<=mid){
        temp_arr[k++] = arr[i++];
    }
    while(j<=right){
        temp_arr[k++] = arr[j++];
    }
    
    for(i = 0; i < k; i++) {
        arr[left + i] = temp_arr[i];
    }
}


void merge_sort(int arr[], int left, int right) {
    // 1. 递归出口
    if(left >= right)
        return;
    
    // 2. 子问题求解
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);         // 左半排序
    merge_sort(arr, mid + 1, right);    // 右半排序
    merge(arr, left, mid, right);       // 合并
}


int main() {
    int arr[] = {9, -3, 2, 7, 4, 16, -1};   // 无序数组
    int n = sizeof(arr) / sizeof(arr[0]);   // 数组长度
    
    merge_sort(arr, 0, n - 1);
    
    printf("Merge sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}