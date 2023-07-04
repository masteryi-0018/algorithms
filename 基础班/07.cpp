#include <iostream>
#include <ctime>
using namespace std;

// 局部最小值
int findLocalMin(int* arr, int len) {
    if (len == 0) {
        return -1;
    } else if (len == 1) {
        return 0;
    } else if (arr[0] < arr[1]) {
        return 0;
    } else if (arr[len-2] > arr[len-1]) {
        return len-1;
    }
    int left = 0;
    int right = len-1;
    int ans = -1;
    while (left < right-1) {
        int mid = left + ((right-left) >> 1);
        if (arr[mid-1] > arr[mid] && arr[mid] < arr[mid+1]) {
            return mid;
        } else if (arr[mid-1] < arr[mid]) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return arr[left] < arr[right] ? left : right;
}

int* genRanArr(int len, int maxVal) {
    if (len == 0) {
        return nullptr;
    }
    int* arr = new int[len];
    arr[0] = rand() % maxVal;
    for (int i = 1; i < len; i++) {
        do {
            arr[i] = rand() % maxVal;
        } while (arr[i] == arr[i-1]);
    }
    return arr;
}

bool check(int* arr, int len, int idx) {
    if (len == 0) {
        return idx == -1;
    }
    int left = idx - 1;
    int right = idx + 1;
    bool leftBigger = left > -1 ? arr[left] > arr[idx] : true;
    bool rightBigger = right < len ? arr[right] > arr[idx] : true;
    return leftBigger && rightBigger;
}

int main()
{
    srand((int)time(0));

    int testTime = 10000;
    int maxLen = 10;
    int maxVal = 20;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % maxLen;
        int* arr = genRanArr(len, maxVal);
        int idx = findLocalMin(arr, len);
        if (!check(arr, len, idx)) {
            cout << "出错了" << endl;
        }
    }

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}