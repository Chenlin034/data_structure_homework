#include <iostream>
using namespace std;
typedef int DataType;
struct Stack {
    int top;              // 栈顶指针，空栈为 -1
    int maxsize;          // 最大空间
    DataType *elements;   // 栈元素数组
};
//初始化空栈
Stack* initStack(int maxsize) {
    Stack *s = new Stack;
    s->elements = new DataType[maxsize];
    s->top = -1;
    s->maxsize = maxsize;
    return s;
}
//判空
bool isEmpty(Stack *s) {
    return s->top == -1;
}
//判满
bool isFull(Stack *s) {
    return s->top == s->maxsize - 1;
}
//入栈
bool push(Stack *s, DataType x) {
    if (isFull(s)) return false;
    s->top++;
    s->elements[s->top] = x;
    return true;
}
//出栈
bool pop(Stack *s, DataType &x) {
    if (isEmpty(s)) return false;
    x = s->elements[s->top];
    s->top--;
    return true;
}
void convert(int number, int base) {
    if (base < 2 || base > 9) {
        cout << "进制 base 必须在 2~9 之间！" << endl;
        return;
    }
    if (number == 0) {
        cout << "0" << endl;
        return;
    }
    Stack *s = initStack(64);   // 64 位足够存放 int 的各位数字
    int n = number;
    // 不断取余，余数依次入栈（先得低位）
    while (n > 0) {
        push(s, n % base);
        n = n / base;
    }
    // 依次出栈（后进先出），得到高位到低位的正确顺序 
    cout << number << " 转换成 " << base << " 进制为：";
    DataType digit;
    while (!isEmpty(s)) {
        pop(s, digit);
        cout << digit;
    }
    cout << endl;
    delete[] s->elements;
    delete s;
}
int main() {
    convert(255, 2);   
    convert(100, 8);   
    convert(45, 7);    
    convert(0, 5);     
    return 0;
}