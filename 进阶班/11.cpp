#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

void swap(int* arr, int i, int j);

// 计数排序
void countingSort(int* arr, int length) {
    if (length < 2) {
        return;
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < length; i++) {
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
    }
    int aux[max-min+1];
    // 初始化为0，否则会有未知的bug！
    for (int i = 0; i < max-min+1; i++) {
        aux[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        aux[arr[i] - min]++;
    }
    int idx = 0;
    for (int i = 0; i < max-min+1; i++) {
        for (int j = 0; j < aux[i]; j++) {
            arr[idx] = i + min;
            idx++;
        }
    }
}

// 基数排序
void radixSort(int* arr, int length) {
    if (length < 2) {
        return;
    }
    int max = *max_element(arr, arr+length);
    int cnt = 0;
    while (max) {
        max /= 10;
        cnt++;
    }
    int aux[length];
    int count[11];
    for (int i = 0; i < length; i++) {
        aux[i] = 0;
    }
    for (int i = 0; i < 11; i++) {
        count[i] = 0;
    }
    int base = 1;
    int curdit;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < length; j++) {
            curdit = (arr[j] / base) % 10;
            count[curdit+1]++;
        }
        for (int j = 1; j < 11; j++) {
            count[j] += count[j-1];
        }
        for (int j = length-1; j > -1; j--) {
            curdit = (arr[j] / base) % 10 + 1;
            if (count[curdit] != 0) {
                aux[count[curdit] - 1] = arr[j];
                count[curdit]--;
            }
        }
        for (int j = 0; j < length; j++) {
            arr[j] = aux[j];
        }
        for (int j = 0; j < 11; j++) {
            count[j] = 0;
        }
        base *= 10;
    }
}

// 桶排序
void bucketSort(int* arr, int length) {
    if (length < 2) {
        return;
    }
    int max = *max_element(arr, arr+length);
    int min = *min_element(arr, arr+length);
    double delta = (double)(max - min) / (double)(length - 1);
    int idx;
    // 如何初始化桶的个数？
    vector<vector<int>> buckets(length, vector<int>(1, 0));
    for (int i = 0; i < length; i++) {
        idx = (int)((arr[i] - min) / delta);
        buckets[idx].emplace_back(arr[i]);
    }
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }
    idx = 0;
    for (auto& bucket : buckets) {
        for (int j = 1; j < bucket.size(); j++) {
            arr[idx++] = bucket[j];
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
        
        countingSort(arr1, len);
        radixSort(arr2, len);
        bucketSort(arr3, len);
        
        std::sort(arr4, arr4 + len);
        if (!isEqual(arr1, arr4, len, len)) {
            std::cout << "计数排序出错" << std::endl;
        }
        if (!isEqual(arr2, arr4, len, len)) {
            std::cout << "基数排序出错" << std::endl;
        }
        if (!isEqual(arr3, arr4, len, len)) {
            std::cout << "桶排序出错" << std::endl;
        }
    }

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}