#include <iostream>

// 打印32位整数二进制表示
void printBin(int n) {
    for (int i = 31; i > -1; i--) {
        if ((n & (1 << i)) == 0) {
            std::cout << 0;
        } else {
            std::cout << 1;
        }
    }
    std::cout << std::endl;
}

void printBin2(int n) {
    for (int i = 31; i > -1; i--) {
        std::cout << ((n & (1 << i)) == 0) ? 0 : 1;
    }
    std::cout << std::endl;
}

void printBin3(int n) {
    for (int i = 31; i > -1; i--) {
        std::cout << (((n & (1 << i)) == 0) ? 0 : 1);
    }
    std::cout << std::endl;
}

int main()
{
    printBin(0);
    printBin(65535);

    printBin2(0);
    printBin2(65535);

    printBin3(0);
    printBin3(65535);

    // std::cout << "Hello World" << std::endl;
    // system("pause");
    return 0;
}