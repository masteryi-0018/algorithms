#include <iostream>
#include <ctime>
#include <algorithm>

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

// 对数器
int* genRanArr(int len, int maxVal) {
    // 在函数中定义的数组在函数执行完后已经被系统释放掉了
    // 解决办法就是动态分配内存，在函数中 new 一个数组
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % maxVal;
    }
    return arr;
}

int* copyArr(int* arr, int len) {
    int* cArr = new int[len];
    for (int i = 0; i < len; i++) {
        cArr[i] = arr[i];
    }
    return cArr;
}

bool isSorted(int* arr, int len) {
    if (len < 2) {
        return true;
    }
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

bool isEqual(int* arr1, int* arr2, int len1, int len2) {
    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void printArr(int* arr, int len) {
    // 当数组传入函数时，传入的是指针，指针仅指向数组头arr[0]
    // 不带有任何长度信息，所以在传入数组时，要把数组长度同时传入函数
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    srand((int)time(0));

    int testTime = 10000;
    int maxLen = 100;
    int maxVal = 100;
    for (int i = 0; i < testTime; i++) {
        // 函数只能返回指针，所以长度要先设置
        int len = rand() % maxLen;
        int* arr1 = genRanArr(len, maxVal);
        int* arr2 = copyArr(arr1, len);
        int* arr3 = copyArr(arr1, len);
        int* arr4 = copyArr(arr1, len);

        selectSort(arr1, len);
        bubbleSort(arr2, len);
        insertSort(arr3, len);
        if (!isSorted(arr1, len)) {
            std::cout << "选择排序出错" << std::endl;
        }
        if (!isSorted(arr2, len)) {
            std::cout << "冒泡排序出错" << std::endl;
        }
        if (!isSorted(arr3, len)) {
            std::cout << "插入排序出错" << std::endl;
        }

        // 如果有暴力法或者其他保证结果正确的方法，可以使用isEqual进行对比验证
        // 这里使用系统的sort函数进行验证
        std::sort(arr4, arr4 + len);
        if (!isEqual(arr1, arr4, len, len)) {
            std::cout << "选择排序出错" << std::endl;
        }
        if (!isEqual(arr2, arr4, len, len)) {
            std::cout << "冒泡排序出错" << std::endl;
        }
        if (!isEqual(arr3, arr4, len, len)) {
            std::cout << "插入排序出错" << std::endl;
        }
    }

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}