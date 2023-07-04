#include <iostream>

// 计算 1! + 2! + ... + N!
int factorial(int n) {
    int res = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        res += ans;
    }
    return res;
}
// 这里换成long更好一些

int main()
{
    int res = factorial(5);
    std::cout << res << std::endl;

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}