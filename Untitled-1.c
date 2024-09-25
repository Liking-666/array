#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  



void swap(int* a, int* b) {
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
void update(int arr[], int size, int index, int newValue) {  
    if (index < 0 || index >= size) {  
        printf("更新位置无效！\n");  
        return 1;  
    }  
    arr[index] = newValue;  
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
    int* arr;  
    int i, valueToInsert, insertIndex, size, updateIndex, newValue;
    int t =1;
    // 初始化随机数生成器  
    srand((unsigned)time(NULL));
    // 获取用户想要的数组大小  
    printf("请输入数组的大小：");
    scanf("%d", &size);

    // 动态分配数组  
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 使用for循环填充数组  
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // 打印数组内容  
    printf("随机生成的数组是:");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 获取用户输入的值和位置  
    printf("请输入你要插入的值：");
    scanf("%d", &valueToInsert);
    printf("请输入你插入的位置（0-%d）：", size - 1);
    scanf("%d", &insertIndex);

    // 插入新元素  
    insert(arr, size, insertIndex, valueToInsert);
    int max = findMax(arr, size);
    int min = findMin(arr, size);

    printf("随机生成的数组是:");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("请输入你要更新的位置（0-%d）：", size - 1);  
    scanf("%d", &updateIndex);  
    printf("请输入你要更新的值：");  
    scanf("%d", &newValue);  
  
    // 更新数组元素  
    update(arr, size, updateIndex, newValue);  
  
    // 打印更新后的数组  
    printf("更新后的数组是:");  
    for (i = 0; i < size; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  




    printf("随机生成的数组是:");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("数组中的最大值是：%d\n", max);
    printf("数组中的最小值是：%d\n", min);




    // 对数组进行排序  
    for (i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    // 打印排序后的数组  
    printf("排序后的数组为：");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}