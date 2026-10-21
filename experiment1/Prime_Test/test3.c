 #include <stdio.h>
int isPrime(int n) {
    if (n <= 1) { // 1 和小于 1 的数不是素数
        return 0; 
    }
    for (int i = 2; i < n; i++) { // 从 2 遍历到 n-1，寻找因子
        if (n % i == 0) { // 如果 n 能被 i 整除，说明不是素数
            return 0; 
        }
    }
    return 1; // 循环顺利结束，没有找到其他因子，则是素数
}
int main() {
    int num;  
    printf("请输入一个整数: ");
    scanf("%d", &num); // 读取用户输入的整数
    if (isPrime(num)) { // 调用 isPrime 函数，返回 1 则为真
        printf("%d 是素数\n", num);
    } else {
        printf("%d 不是素数\n", num);
    }   
    return 0;
}