#include <stdio.h>
#include <stdlib.h>
typedef int Datatype;
//顺序队列结构体 
struct SeqQueue {
    int front;              // 队首指针（下标）
    int rear;               // 队尾指针（下标，指向队尾元素的下一个位置）
    int maxsize;            // 队列最大长度
    Datatype *elements;     // 数据存储数组
};
//1.初始化顺序队列 
struct SeqQueue* InitQueue(int maxsize) {
    struct SeqQueue *q = (struct SeqQueue*)malloc(sizeof(struct SeqQueue));
    q->maxsize = maxsize;
    q->front = 0;
    q->rear = 0;
    q->elements = (Datatype*)malloc(maxsize * sizeof(Datatype));
    return q;
}
//2.判断队列是否为空
int IsEmpty(struct SeqQueue *q) {
    return q->front == q->rear;
}
//3. 判断队列是否满
int IsFull(struct SeqQueue *q) {
    return (q->rear + 1) % q->maxsize == q->front;
}

//4.入队
int EnQueue(struct SeqQueue *q, Datatype x) {
    if (IsFull(q)) {
        printf("队列已满，入队失败\n");
        return 0;
    }
    q->elements[q->rear] = x;
    q->rear = (q->rear + 1) % q->maxsize;   // 循环后移
    return 1;
}
//5.出队
int DeQueue(struct SeqQueue *q, Datatype *x) {
    if (IsEmpty(q)) {
        printf("队列为空，出队失败\n");
        return 0;
    }
    *x = q->elements[q->front];
    q->front = (q->front + 1) % q->maxsize; // 循环后移
    return 1;
}
//6.获取队首元素值 
int GetFront(struct SeqQueue *q, Datatype *x) {
    if (IsEmpty(q)) {
        printf("队列为空，无队首元素\n");
        return 0;
    }
    *x = q->elements[q->front];
    return 1;
}
int main() {
    struct SeqQueue *q = InitQueue(5);
    Datatype x;
    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);
    GetFront(q, &x);
    printf("队首元素: %d\n", x);         
    DeQueue(q, &x);
    printf("出队元素: %d\n", x);         
    GetFront(q, &x);
    printf("新队首元素: %d\n", x);        
    printf("队列是否为空: %d\n", IsEmpty(q)); 
    printf("队列是否满: %d\n", IsFull(q));    
    return 0;
}