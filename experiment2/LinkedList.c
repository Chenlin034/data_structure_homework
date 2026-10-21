#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
//单链表结构体定义：
typedef int DataType;
struct Node
{
DataType data; //数据域
struct Node * next;//指针域
};
// 1. 初始化一个带有头结点的单链表
struct Node*InitList(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));//malloc分配头结点内存
    if(head==NULL){
        printf("内存分配失败！\n");
}  
    head->next=NULL;
    return head;
}
// 2. 采用头插法建立单链表
void CreateListHeadInsert(struct Node*head,int n){
    printf("请输入%d个整数:",n);
    for (int i = 0; i < n; i++)
    {
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));//创建新结点
        scanf("%d",&newNode->data);//读入数据
        newNode->next=head->next;//将新结点插入到头结点之后
        head->next=newNode;
    }
}
// 3. 采用尾插法建立单链表
void CreateListTailInsert(struct Node*head,int n){
    struct Node *Tail=head;
    printf("请输入%d个整数:",n);
    for (int i = 0; i < n; i++)
    {
       struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));//创建新结点
       scanf("%d",&newNode->data);//读入数据
       newNode->next=NULL;
       Tail->next=newNode;//将新结点插入到表尾
       Tail=newNode;//尾指针后移
    }  
}
// 4. 判断链表是否为空
bool IsEmpty(struct Node*head){
    if(head->next==NULL){
        return true;
    }
    return false;
}
// 5. 计算链表的长度
int GetLength(struct Node*head){
    int length=0;
    struct Node *p=head->next;//从第一个有效数据进行遍历
    while (p!=NULL) {
        length++;
        p=p->next;
    }
    return length;
}
// 6. 输出链表的内容
void PrintList(struct Node*head){
    struct Node *p=head->next;
    if (p==NULL)
    {
        printf("空链表\n");
        return;
    }
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    // 测试 1：初始化
    struct Node *head = InitList();
    printf("--- 初始化链表完成 ---\n");
    // 测试 4：判断是否为空
    if (IsEmpty(head)) {
        printf("当前链表为空。\n");
    }
    // 测试 2：头插法
    CreateListHeadInsert(head, 3);
    printf("头插法建立后的链表内容: ");
    PrintList(head); // 测试 6：输出
    printf("当前链表长度为: %d\n", GetLength(head)); // 测试 5：计算长度
    // 清空链表重新测试尾插法
    while (head->next) {
        struct Node* temp = head->next;
        head->next = temp->next;
        free(temp);
    }
    // 测试 3：尾插法
    CreateListTailInsert(head, 4);
    printf("尾插法建立后的链表内容: ");
    PrintList(head);
    printf("当前链表长度为: %d\n", GetLength(head));
    // 再次判断是否为空
    if (!IsEmpty(head)) {
        printf("当前链表不为空。\n");
    }
    // 程序结束前释放头结点
    free(head);
    return 0;
}