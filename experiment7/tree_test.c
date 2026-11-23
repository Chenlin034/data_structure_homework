#include<stdio.h>
#include<stdlib.h>
//1.结构体定义
typedef char ElementType;
typedef struct TreeNode{
    ElementType data;  //数据域，存放字符
    struct TreeNode*lchild;
    struct TreeNode*rchild;
}TreeNode,*BiTree;  //TreeNode是结点类型，*BiTree是指向结点的指针类型
//2.创建二叉树
BiTree CreateBiTree(){
    char ch;
    scanf("%c",&ch);
    if (ch=='#'){
        return NULL;
    }else{
        BiTree T=(BiTree)malloc(sizeof(TreeNode));//申请一个存放新结点的内存空间
        T->data=ch;
        T->lchild=CreateBiTree();
        T->rchild=CreateBiTree();
        return T;
    }
}
//3.先序遍历
void PreOrderTraverse(BiTree T){
    if (T == NULL) return;
    printf("%c ", T->data);      
    PreOrderTraverse(T->lchild); 
    PreOrderTraverse(T->rchild);
}
//4.中序遍历(左->根->右)
void InOrderTraverse(BiTree T) {
if (T == NULL) return;
    InOrderTraverse(T->lchild); 
    printf("%c ", T->data);       
    InOrderTraverse(T->rchild);
}
//5.后序遍历(左->根->右)
void PostOrderTraverse(BiTree T) {
    if (T == NULL) return;    
    PostOrderTraverse(T->lchild); 
    PostOrderTraverse(T->rchild); 
    printf("%c ", T->data);       
}
int main() {
    BiTree root = NULL; // 声明一个二叉树根结点指针，初始化为空 
    printf("请输入创建二叉树的字符序列 (#表示空结点):");
    root = CreateBiTree();  
    printf("先序遍历: ");
    PreOrderTraverse(root);
    printf("\n"); 
    printf("中序遍历: ");
    InOrderTraverse(root);
    printf("\n"); 
    printf("后序遍历: ");
    PostOrderTraverse(root);
    printf("\n"); 
    return 0;
}
