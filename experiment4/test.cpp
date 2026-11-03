#include<iostream>
using namespace std;
typedef int DataType;
struct Stack{
    int top;
    int maxsize;
    DataType *elements; //存放栈元素的数组
};
//1.初始化
Stack* initStack(int maxsize){
    Stack *s = new Stack;
    s->elements = new DataType[maxsize];
    s->top = -1;         // 空栈：top = -1
    s->maxsize = maxsize;
    return s;
}
//2.判空 
bool isEmpty(Stack *s){
    return s->top == -1;
}
//3.判断是否为满
bool isFull(Stack *s){
    return s->top == s->maxsize - 1;
}
//4.入栈 
bool push(Stack *s, DataType x){
    if (isFull(s)) {   
        cout << "栈已满，入栈失败！" << endl;
        return false;
    }
    s->top++;
    s->elements[s->top] = x;
    return true;
}
//5.出栈
bool pop(Stack *s, DataType &x){
    if (isEmpty(s)) {
        cout << "栈为空，出栈失败！" << endl;
        return false;
    }
    x = s->elements[s->top];
    s->top--;        
    return true;
}
//6.获取栈顶元素
bool getTop(Stack *s, DataType &x){
    if (isEmpty(s)) {
        cout << "栈为空，无栈顶元素！" << endl;
        return false;
    }
    x = s->elements[s->top];
    return true;
}
int main(){
    Stack *s = initStack(5);
    cout << "栈是否为空：" << (isEmpty(s) ? "是" : "否") << endl;
    cout << "栈是否已满：" << (isFull(s) ? "是" : "否") << endl;   
    cout << "依次入栈 10, 20, 30：" << endl;
    push(s, 10);
    push(s, 20);
    push(s, 30);   
    DataType topVal;
    if (getTop(s, topVal))
        cout << "当前栈顶元素：" << topVal << endl;        
    DataType outVal;
    if (pop(s, outVal))
        cout << "出栈元素：" << outVal << endl;
    if (pop(s, outVal))
        cout << "出栈元素：" << outVal << endl;       
    if (getTop(s, topVal))
        cout << "当前栈顶元素：" << topVal << endl;       
    delete[] s->elements; // 释放数组
    delete s;             // 释放结构体
    return 0;
}