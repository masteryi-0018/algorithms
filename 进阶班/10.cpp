#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void swap(int* arr, int i, int j);

// 归并排序
void merge(int* arr, int left, int mid, int right) {
    int* aux = new int[right-left+1];
    int t = 0;
    for (int k = left; k <= right; k++) {
        aux[t++] = arr[k];
    }
    int i = 0;
    int j = mid+1-left;
    int k = left;
    while (i < mid+1-left && j < right-left+1) {
        if (aux[i] < aux[j]) {
            arr[k++] = aux[i++];
        } else {
            arr[k++] = aux[j++];
        }
    }
    while (i < mid+1-left) {
        arr[k++] = aux[i++];
    }
    while (j < right-left+1) {
        arr[k++] = aux[j++];
    }
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + ((right - left) >> 1);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

// 快速排序
int partition(int* arr, int left, int right) {
    int std = left;
    int idx = left+1;
    for (int i = left+1; i <= right; i++) {
        if (arr[i] < arr[std]) {
            swap(arr, i, idx);
            idx++;
        }
    }
    swap(arr, left, idx-1);
    return idx-1;
}

void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int idx = partition(arr, left, right);
    quickSort(arr, left, idx-1);
    quickSort(arr, idx+1, right);
}

// 堆排序
void siftDown(int* arr, int start, int end) {
    int dad = start;
    int son = start * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son+1]) {
            son++;
        }
        if (arr[dad] >= arr[son]) {
            break;
        } else {
            swap(arr, dad, son);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heapSort(int* arr, int length) {
    for (int i = length/2-1; i >= 0; i--) {
        siftDown(arr, i, length-1);
    }
    for (int i = length-1; i > 0; i--) {
        swap(arr, 0, i);
        siftDown(arr, 0, i-1);
    }
}

//希尔排序
void shellSort(int* arr, int length) {
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            int j = i;
            while (j-gap > -1 && arr[j] < arr[j-gap]) {
                swap(arr, j-gap, j);
                j -= gap;
            }
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
        int* arr5 = copyArr(arr1, len);

        mergeSort(arr1, 0, len-1);
        quickSort(arr2, 0, len-1);
        heapSort(arr3, len);
        shellSort(arr5, len);
        std::sort(arr4, arr4 + len);
        if (!isEqual(arr1, arr4, len, len)) {
            std::cout << "归并排序出错" << std::endl;
        }
        if (!isEqual(arr2, arr4, len, len)) {
            std::cout << "快速排序出错" << std::endl;
        }
        if (!isEqual(arr3, arr4, len, len)) {
            std::cout << "堆排序出错" << std::endl;
        }
        if (!isEqual(arr5, arr4, len, len)) {
            std::cout << "希尔排序出错" << std::endl;
        }
    }

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}