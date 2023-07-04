#include <iostream>
#include <ctime>

// 随机数发生器
int f1() {
    // rand()会返回一随机数值，范围在0至RAND_MAX间
    // RAND_MAX定义在stdlib.h，其值为2147483647
    return rand() % 5 + 1;
}

int f2() {
    // 将1-5随机数发生器转变为01发生器
    int ans = f1();
    while (ans == 3) {
        ans = f1();
    }
    return (ans < 3) ? 0 : 1;
}

int f3() {
    // 将01发生器作为二进制编码，理论上可以产生任何随机数发生器
    // 这里将0-7中0的情况重复，可以得到1-7
    int res = (f2() << 2) + (f2() << 1) + (f2() << 0);
    while (res == 0) {
        res = (f2() << 2) + (f2() << 1) + (f2() << 0);
    }
    return res;
}

int main()
{
    srand((int)time(0));
    
    for (int i = 0; i < 10; i++) {
        std::cout << f3() << std::endl;
    }

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}