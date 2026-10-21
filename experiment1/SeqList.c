#include <stdio.h>  
#define MAX 100    
// 1. 定义顺序表结构体
typedef struct {
    int data[MAX]; 
    int len;       
} List;
void init(List *L) {
    L->len = 0; 
}
// 3. 创建（输入数据）
void create(List *L, int n) {
    printf("请输入 %d 个整数（用空格隔开）: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]); // 循环输入
    }
    L->len = n; // 更新表长
}
// 4. 判断是否为空 (返回1代表空，返回0代表非空)
int isEmpty(List L) {
    return L.len == 0; 
}
// 5. 计算长度
int getLength(List L) {
    return L.len; 
}
// 6. 输出
void print(List L) {
    if (isEmpty(L)) {
        printf("空表\n");
        return;
    }
    for (int i = 0; i < L.len; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}
// 7. 按位置查找（获取第 p 个元素的值）
int getElem(List L, int p) {
    // 位置不合法（小于1或超出长度），返回 -1 表示出错
    if (p < 1 || p > L.len) {
        printf("位置越界！\n");
        return -1; 
    }
    return L.data[p - 1]; // 数组下标 = 位置 - 1
}
// 8. 按值查找（返回第1次出现的位置）
int locate(List L, int v) {
    for (int i = 0; i < L.len; i++) {
        if (L.data[i] == v) return i + 1; 
    }
    return 0; 
}
// 9. 插入（在位置 p 插入值 v）
void ins(List *L, int p, int v) {
    // 位置不合法，或表满了，直接结束
    if (p < 1 || p > L->len + 1 || L->len >= MAX) return; 
    for (int i = L->len - 1; i >= p - 1; i--) {
        L->data[i + 1] = L->data[i]; 
    }
    L->data[p - 1] = v; 
    L->len++;           // 长度加 1
}
// 10. 删除指定位置 p
void del(List *L, int p) {
    if (p < 1 || p > L->len) return; // 越界直接结束
    for (int i = p; i < L->len; i++) {
        L->data[i - 1] = L->data[i]; 
    } 
    L->len--; // 长度减 1
}
// 11. 删除所有值为 v 的元素
void delVal(List *L, int v) {
    int k = 0; // k 记录保留下来的元素应该放的位置
    for (int i = 0; i < L->len; i++) {
        if (L->data[i] != v) { // 如果不是要删的，就保留
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->len = k; // 更新长度
}
// 主函数：测试所有功能
int main() {
    List L;
    init(&L);
    create(&L, 5); 
    printf("原始表: ");
    print(L);
    printf("当前表长: %d\n", getLength(L));
    // 测试查找
    printf("第2个位置的元素是: %d\n", getElem(L, 2));
    int pos = locate(L, 99);
    if (pos != 0) printf("99 在第 %d 个位置\n", pos);
    else printf("没找到 99\n");
    // 测试插入
    ins(&L, 2, 99); 
    printf("在第2个位置插入99后: ");
    print(L);
    // 测试删除位置
    del(&L, 1); 
    printf("删除第1个位置后: ");
    print(L);
    // 测试删除值
    delVal(&L, 99); 
    printf("删除所有的99后: ");
    print(L);
    return 0;
}