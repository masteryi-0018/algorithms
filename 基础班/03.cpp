#include <iostream>

void swap(int* arr, int i, int j);

// 选择排序，每次选择最小元素放在第i个位置
void selectSort(int* arr, int length) {
    for (int i = 0; i < length-1; i++) {
        int min = i;
        for (int j = i+1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr, i, min);
    }
}

// 冒泡排序，相邻元素中大的往后换，放在倒数第i个位置
void bubbleSort(int* arr, int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = 1; j < length-i; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr, j-1, j);
            }
        }
    }
}

// 插入排序，拿到一张牌向右比较找到适合的位置，使用了while
void insertSort(int* arr, int length) {
    for (int i = 1; i < length; i++) {
        int j = i;
        while (j-1 > -1 && arr[j] < arr[j-1]) {
            swap(arr, j-1, j);
            j--;
        }
    }
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 对数器暂时没有

int main()
{
    int arr1[] = {8,4,5,3,1,7,9,0,2,6};
    int length = sizeof(arr1) / sizeof(arr1[0]);
    selectSort(arr1, length);
    for (int i = 0; i < length; i++) {
        std::cout << arr1[i] << ' ';
    }
    std::cout << std::endl;

    int arr2[] = {8,4,5,3,1,7,9,0,2,6};
    bubbleSort(arr2, length);
    for (int i = 0; i < length; i++) {
        std::cout << arr2[i] << ' ';
    }
    std::cout << std::endl;

    int arr3[] = {8,4,5,3,1,7,9,0,2,6};
    insertSort(arr3, length);
    for (int i = 0; i < length; i++) {
        std::cout << arr3[i] << ' ';
    }
    std::cout << std::endl;

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}