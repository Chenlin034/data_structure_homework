#include <stdio.h>
// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // 外层循环：控制排序的轮数，共 n-1 轮
        for (int j = 0; j < n - 1 - i; j++) { // 内层循环：控制每轮的比较次数，已排好的不再比较
            if (arr[j] > arr[j + 1]) { // 如果前一个元素大于后一个，则交换
                int t= arr[j]; // 暂存前一个元素
                arr[j] = arr[j + 1]; // 后一个元素覆盖前一个
                arr[j + 1] = t; // 暂存的值赋给后一个
            }
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) { // 遍历数组打印每个元素
        printf("%d ", arr[i]);
    }
    printf("\n"); // 打印完换行
}
int main() {
    // 测试组 1：普通无序数组
    int test1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(test1) / sizeof(test1[0]); // 计算数组长度
    printf("测试组1 排序前: ");
    printArray(test1, n1); // 排序前打印
    bubbleSort(test1, n1); // 调用冒泡排序
    printf("测试组1 排序后: ");
    printArray(test1, n1); // 排序后打印
    printf("-------------------\n");   
    // 测试组 2：小规模数组
    int test2[] = {5, 1, 4, 2, 8};
    int n2 = sizeof(test2) / sizeof(test2[0]);
    printf("测试组2 排序前: ");
    printArray(test2, n2);
    bubbleSort(test2, n2);
    printf("测试组2 排序后: ");
    printArray(test2, n2);
    printf("-------------------\n"); 
    // 测试组 3：包含负数的数组
    int test3[] = {10, -1, 3, 0, -5};
    int n3 = sizeof(test3) / sizeof(test3[0]);
    printf("测试组3 排序前: ");
    printArray(test3, n3);
    bubbleSort(test3, n3);
    printf("测试组3 排序后: ");
    printArray(test3, n3);
    return 0;
}