#include <stdio.h>
#include <stdlib.h>
typedef int Datatype;
//结点结构体
struct Node {
    Datatype data;
    struct Node *next;
};
//链队列结构体
struct LinkQueue {
    struct Node *front;     // 队首指针（指向头结点）
    struct Node *rear;      // 队尾指针
};
//1.初始化空链队列（带头结点）
struct LinkQueue* InitQueue() {
    struct LinkQueue *q = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    q->front = head;
    q->rear = head;
    return q;
}
//2.判断链队列是否为空
int IsEmpty(struct LinkQueue *q) {
    return q->front == q->rear;
}
//3.入队 
void EnQueue(struct LinkQueue *q, Datatype x) {
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    q->rear->next = p;      // 挂到队尾
    q->rear = p;            // 更新队尾指针
}
//4.出队 
int DeQueue(struct LinkQueue *q, Datatype *x) {
    if (IsEmpty(q)) {
        printf("队列为空，出队失败\n");
        return 0;
    }
    struct Node *p = q->front->next;   // 队首结点
    *x = p->data;
    q->front->next = p->next;          // 摘下队首结点
    if (q->rear == p)                  // 若出队的是最后一个结点
        q->rear = q->front;            // 队尾指针回退到头结点
    free(p);
    return 1;
}
//5.获取队首元素值
int GetFront(struct LinkQueue *q, Datatype *x) {
    if (IsEmpty(q)) {
        printf("队列为空，无队首元素\n");
        return 0;
    }
    *x = q->front->next->data;
    return 1;
}
int main() {
    struct LinkQueue *q = InitQueue();
    Datatype x;
    EnQueue(q, 100);
    EnQueue(q, 200);
    EnQueue(q, 300);
    GetFront(q, &x);
    printf("队首元素: %d\n", x);        
    DeQueue(q, &x);
    printf("出队元素: %d\n", x);       
    GetFront(q, &x);
    printf("新队首元素: %d\n", x);    
    printf("队列是否为空: %d\n", IsEmpty(q));
    return 0;
}