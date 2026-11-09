#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef char DataType;
typedef struct LinkStack{
    DataType data;  
    struct LinkStack*next;    
}LinkStack;
//1.初始化空链栈
LinkStack *InitStack() {
    LinkStack *top = (LinkStack *)malloc(sizeof(LinkStack));
    if (top == NULL) {              // 内存分配失败
        return NULL;                
    }
    top->next = NULL;               // 空栈
    return top;                     // 返回栈顶指针（指向头结点）
}
//2.判空
bool IsEmpty(LinkStack *top) {
    return top->next == NULL;       
}
//3.入栈
bool Push(LinkStack *top, DataType x) {
    LinkStack *newNode = (LinkStack *)malloc(sizeof(LinkStack)); 
    if (newNode == NULL) {          
        return false;              
    }
    newNode->data = x;              
    newNode->next = top->next;      // 新结点指向原栈顶结点
    top->next = newNode;            // 头结点指向新结点，新结点成为新栈顶
    return true;                    
}
//4.出栈
bool Pop(LinkStack *top, DataType *x) {
    if (IsEmpty(top)) {             
        return false;               // 出栈失败
    }
    LinkStack *t = top->next;       // t 指向当前栈顶结点
    *x = t->data;                   // 带回栈顶字符
    top->next = t->next;            // 头结点跳过栈顶结点
    free(t);                        // 释放原栈顶结点，防止内存泄漏
    return true;                    
}
//5. 获取栈顶元素值
bool GetTop(LinkStack *top, DataType *x) {
    if (IsEmpty(top)) {             
        return false;               
    }
    *x = top->next->data;           
    return true;                 
}
/* ==================== 括号匹配 ==================== */
bool BracketMatch(const char *str) {
    LinkStack *stack = InitStack(); // 1.初始化一个空栈（带头结点）
    if (stack == NULL) {           
        return false;               
    }
    bool flag = true;               // 2.匹配标记，初值 true，false 表示已发现错误
    int i = 0;                      // 扫描下标
    char ch, topCh;                 // ch 为当前字符，topCh 为栈顶字符
 //3.依次扫描字符，只要没到串尾且尚未出错就继续
    while (str[i] != '\0' && flag) {
        ch = str[i];                // 取出当前字符
        if (ch == '(' || ch == '[' || ch == '{') {
            //A. 遇到左括号：直接压入栈中，等待后续右括号来匹配
            Push(stack, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            //B. 遇到右括号：必须栈非空，且栈顶是对应类型的左括号
            if (!IsEmpty(stack) && GetTop(stack, &topCh)) {
                if ((ch == ')' && topCh == '(') ||   
                    (ch == ']' && topCh == '[') || 
                    (ch == '}' && topCh == '{')) {  
                    Pop(stack, &topCh);              // 匹配成功，弹出栈顶左括号
                } else {
                    flag = false;                    // 类型不匹配，置错误标记
                }
            } else {
                flag = false;                        // 栈空却遇到右括号，右括号多余
            }
        }
        i++;                        // 继续扫描下一个字符
    }
    //4.扫描结束后：栈必须为空（没有多余左括号）且 flag 为真，匹配成功 
    bool result = flag && IsEmpty(stack);
    // 释放栈中可能剩余的结点，防止内存泄漏 
    while (!IsEmpty(stack)) {
        Pop(stack, &ch);            
    }
    free(stack);                    // 释放头结点
    return result;                  
}
int main() {
    const char *tests[] = {
        "{[{}]}",       
        "{[}]}",       
        "((()))",      
        "([)]",         
        "{[]}",        
        "(",            
        ")"            
    };
    int n = sizeof(tests) / sizeof(tests[0]);   // 计算测试用例个数
    for (int i = 0; i < n; i++) {
        printf("输入：%-10s 输出：%s\n",
               tests[i],                                
               BracketMatch(tests[i]) ? "匹配" : "不匹配"); 
    }
    return 0;                      
}