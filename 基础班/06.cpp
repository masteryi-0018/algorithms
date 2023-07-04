#include <iostream>
using namespace std;

// 二分查找v1
int binSearch1(int* arr, int len, int num) {
    int left = 0;
    int right = len-1;
    while (left <= right) {
        // 防止越界
        int mid = left + ((right-left) >> 1);
        // 左侧比较1次，右侧比较2次，常数系数为1.5，可以用Fibonacci优化常数时间
        if (arr[mid] < num) {
            left = mid+1;
        } else if (arr[mid] > num) {
            right = mid-1;
        } else {
            return mid;
        }
    }
    // 没有找到
    return -1;
}

// 二分查找v2，找到不大于num的最右元素
int binSearch2(int* arr, int len, int num) {
    int left = 0;
    int right = len-1;
    // 未找到
    int ans = -1;
    while (left <= right) {
        int mid = left + ((right-left) >> 1);
        if (arr[mid] <= num) {
            // 只有满足的条件才更新ans
            ans = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return ans;
}

// 二分查找v3，找到不小于num的最左元素
int binSearch3(int* arr, int len, int num) {
    int left = 0;
    int right = len-1;
    int ans = -1;
    while (left <= right) {
        int mid = left + ((right-left) >> 1);
        if (arr[mid] >= num) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return ans;
}

int main()
{
    int arr[8] = {1,2,2,2,4,6,8,9};
    int len = sizeof(arr) / sizeof(arr[0]);
    int num = 2;
    
    int idx1 = binSearch1(arr, len, num);
    cout << idx1 << endl;

    int idx2 = binSearch2(arr, len, num);
    cout << idx2 << endl;

    int idx3 = binSearch3(arr, len, num);
    cout << idx3 << endl;

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}