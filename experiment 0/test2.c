#include<stdio.h>
int main(){
    double sum=0; 
    int a=2,b=1; 
    for(int i=0;i<10;i++){ // 循环 10 次，求前 10 项
       sum+=(double)a/b; // 将当前项累加到 sum 中，强制类型转换保证浮点除法
       int t=a; // 用临时变量 t 暂存当前分子
       a=a+b; // 计算下一项的分子：前一项分子 + 前一项分母
       b=t; // 计算下一项的分母：等于前一项分子
    }
    printf("该项数列的前10项之和:%f\n",sum); 
    return 0;
}