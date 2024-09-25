#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
#define ARRAY_SIZE 10 // 定义数组的大小  
  
void swap(int *a, int *b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
// 注意：这个函数会检查插入位置是否超出了数组的有效范围  
void insert(int arr[], int size, int index, int value) {  
    if (index < 0 || index >= size) {  
        printf("插入位置无效！\n");  
        return;  
    }  
    // 从数组的末尾开始，将元素向后移动一位  
    for (int i = size - 1; i > index; i--) {  
        arr[i] = arr[i - 1];  
    }  
    // 在指定位置插入新元素  
    arr[index] = value;  
}  
// 求数组中的最大值  
int findMax(int arr[], int size) {  
    int max = arr[0];  
    for (int i = 1; i < size; i++) {  
        if (arr[i] > max) {  
            max = arr[i];  
        }  
    }  
    return max;  
}  
  
// 求数组中的最小值  
int findMin(int arr[], int size) {  
    int min = arr[0];  
    for (int i = 1; i < size; i++) {  
        if (arr[i] < min) {  
            min = arr[i];  
        }  
    }  
    return min;  
}  
  
int main() {  
    int arr[ARRAY_SIZE]; // 声明一个整型数组  
    int i, valueToInsert, insertIndex;  
  
    // 初始化随机数生成器  
    srand((unsigned)time(NULL));  
  
    // 使用for循环填充数组  
    for (i = 0; i < ARRAY_SIZE; i++) {  
        arr[i] = rand() % 100 + 1;  
    }  
  
    // 打印数组内容  
    printf("随机生成的数组是:");  
    for (i = 0; i < ARRAY_SIZE; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
  
    // 获取用户输入的值和位置  
    printf("请输入你要插入的值：");  
    scanf("%d", &valueToInsert);  
    printf("请输入你插入的位置（0-%d）：", ARRAY_SIZE - 1);  
    scanf("%d", &insertIndex);  
  
    // 插入新元素  
    insert(arr, ARRAY_SIZE, insertIndex, valueToInsert);  
    int max = findMax(arr, ARRAY_SIZE);  
    int min = findMin(arr, ARRAY_SIZE);  
      
    printf("数组中的最大值是：%d\n", max);  
    printf("数组中的最小值是：%d\n", min);  




    // // 对数组进行排序  
    // for (i = 0; i < ARRAY_SIZE - 1; i++) {  
    //     for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {  
    //         if (arr[j] > arr[j + 1]) {  
    //             swap(&arr[j], &arr[j + 1]);  
    //         }  
    //     }  
    // }  
  
    // // 打印排序后的数组  
    // printf("排序后的数组为：");  
    for (i = 0; i < ARRAY_SIZE; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
  
    return 0;  
}