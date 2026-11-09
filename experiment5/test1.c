#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int DataType;
typedef struct LinkStack{
    DataType data;  //数据域
    struct LinkStack*next; //指针域:指向下一个结点    
}LinkStack;
//1.初始化空链栈
LinkStack*InitStack(){
    LinkStack*top=(LinkStack*)malloc(sizeof(LinkStack));
    if(top==NULL){  //内存分配失败
        return NULL;
    }
    top->next=NULL;  //空栈
    return top;  //返回栈顶指针(指向头结点)
}
//2.判空
bool IsEmpty(LinkStack*top){
    return top->next==NULL;
}
//3.入栈(头插法)
bool Push(LinkStack *top,DataType x){
    LinkStack *newNode=(LinkStack*)malloc(sizeof(LinkStack));
    if (newNode==NULL){
        return false;
    }
    newNode->data=x;
    newNode->next=top->next;
    top->next=newNode;
    return true;
}
//4.出栈
bool Pop(LinkStack*top,DataType *x){
    if (IsEmpty(top)){
        return false;
    }
    LinkStack *t=top->next;
    *x=t->data;
    top->next=t->next;
    free(t);
    return true;
}
//5.获取栈顶元素
bool GetTop(LinkStack*top,DataType *x){
    if (IsEmpty(top)){
        return false;
    }
    *x=top->next->data;
    return true;
}
int main(){
    DataType x;
    LinkStack *top=InitStack();
    if (top==NULL){
        printf("初始化失败！\n");
        return 1;
    }
    printf("初始化后是否为空:%s\n",IsEmpty(top)?"是":"否");
    Push(top,10);
    Push(top,20);     
    Push(top,30);  
    printf("入栈10,20,30后是否为空:%s\n",IsEmpty(top)?"是":"否"); 
    if (Pop(top,&x)){
        printf("出栈元素:%d\n",x);
    }
    if(GetTop(top,&x)){
        printf("出栈后栈顶元素:%d\n",x);
    }    
    free(top);
    return 0;
}