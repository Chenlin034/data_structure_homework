#include <iostream>
#include <cstring>
using namespace std;
// 定义联系人结构体
struct Contact
{
    char name[50]; // 联系人姓名
    char phone[12]; // 联系人电话
    struct Birthday // 联系人生日
    {
        int year;  // 年
        int month; // 月
        int day;   // 日
    } birthday;
    int age; // 联系人年龄
};
// 定义通讯录结点结构体
struct Node
{
    Contact data; // 联系人信息
    Node* next;   // 指向下一个结点的指针
};
// 初始化一个空的通讯录链表
Node* InitAddressBook()
{
    Node* head = new Node; 
    if(head == NULL) 
        cout << "内存分配失败！" << endl;
    else
        head->next = NULL; 
    return head; 
}
// 采用尾插法创建一个通讯录链表 (用于按顺序添加)
bool CreateAddressBookTail(Node* head, Contact data)
{
    static Node* tail = head; // 静态变量记录尾指针
    Node* node = new Node; 
    if (node == NULL) 
    {
        cout << "内存分配失败！" << endl;
        return false; 
    }
    node->data = data; 
    node->next = NULL; 
    tail->next = node; 
    tail = node; 
    return true; 
}
// 输入单个联系人信息
Contact InputContact()
{
    Contact data;
    cout << "请输入联系人姓名：";
    cin >> data.name;
    cout << "请输入联系人电话：";
    cin >> data.phone;
    cout << "请输入联系人生日(年 月 日，空格隔开)：";
    cin >> data.birthday.year >> data.birthday.month >> data.birthday.day;
    cout << "请输入联系人年龄：";
    cin >> data.age;
    return data;
}
// 输出单个联系人信息
void OutputContact(Contact data)
{
    cout << "姓名：" << data.name << "\t";
    cout << "电话：" << data.phone << "\t";
    cout << "生日：" << data.birthday.year << "年" << data.birthday.month << "月" << data.birthday.day << "日\t";
    cout << "年龄：" << data.age << endl;
}
// 输出通讯录中所有联系人信息
void OutputAddressBook(Node* head)
{
    Node* node = head->next;
    if (node == NULL) {
        cout << "通讯录为空！" << endl;
        return;
    }
    while (node) {
        OutputContact(node->data);
        node = node->next;
    }
}
// 按姓名查找通讯录中指定联系人信息
Node* SearchContactByName(Node* head, char* name)
{
    Node* node = head->next;
    while (node) {
        if(strcmp(node->data.name, name) == 0)
            return node; 
        node = node->next;
    }
    return NULL; 
}
// 查找指定联系人的前驱结点
Node* SearchPreNode(Node* head, Node* target)
{
    for(Node* pre = head; pre->next != NULL; pre = pre->next) {
        if(pre->next == target)
            return pre; 
    }
    return NULL; 
}
// 删除指定联系人
bool DeleteContact(Node* head, Node* target)
{
    Node* pre = SearchPreNode(head, target); 
    if(pre) {
        pre->next = target->next; 
        delete target; 
        return true; 
    }
    return false; 
}
// 在指定联系人的后面插入一个新的联系人
bool InsertContactAfter(Node* head, Node* target, Contact data)
{
    Node* node = new Node; 
    if (node) {
        node->data = data; 
        node->next = target->next; 
        target->next = node; 
        return true; 
    }
    return false; 
}
// 打印用户选择菜单 
int PrintMenu()
{
    int choice;
    cout << "\n===== 通讯录管理程序 =====" << endl;
    cout << "1. 通讯录链表的建立" << endl;
    cout << "2. 通讯者节点的插入" << endl;
    cout << "3. 通讯者节点的查询" << endl;
    cout << "4. 通讯者节点的删除" << endl;
    cout << "5. 通讯录链表的输出" << endl;
    cout << "0. 退出管理系统" << endl;
    cout << "==========================" << endl;
    cout << "请输入您的选择(0-5): ";
    cin >> choice;
    return choice;
}
int main()
{
    // 1.初始化一个带头结点的空链表
    Node* head = InitAddressBook(); 
    int choice;
    char searchName[50];
    Contact newContact;
    Node* targetNode = NULL;

    while (true)
    {
        choice = PrintMenu();

        switch (choice)
        {
        case 1: // 1. 通讯录链表的建立
        {
            int n;
            cout << "请输入要一次性建立的联系人数量：";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "--- 输入第 " << i + 1 << " 个联系人信息 ---" << endl;
                newContact = InputContact();
                CreateAddressBookTail(head, newContact);
            }
            cout << "通讯录建立完成！" << endl;
            break;
        }
        case 2: // 2. 通讯者节点的插入
        {
            char targetName[50];
            cout << "请输入要在哪位联系人【之后】插入？(输入其姓名)：";
            cin >> targetName;
            targetNode = SearchContactByName(head, targetName);
            
            if (targetNode != NULL) {
                cout << "--- 请输入新联系人信息 ---" << endl;
                newContact = InputContact();
                if (InsertContactAfter(head, targetNode, newContact)) {
                    cout << "插入成功！" << endl;
                } else {
                    cout << "插入失败！" << endl;
                }
            } else {
                cout << "未找到联系人：" << targetName << "，插入失败！" << endl;
            }
            break;
        }
        case 3: // 3. 通讯者节点的查询
        {
            cout << "请输入要查询的联系人姓名：";
            cin >> searchName;
            targetNode = SearchContactByName(head, searchName);
            if (targetNode != NULL) {
                cout << "查询成功，联系人信息如下：" << endl;
                OutputContact(targetNode->data);
            } else {
                cout << "未找到该联系人！" << endl;
            }
            break;
        }
        case 4: // 4. 通讯者节点的删除
        {
            cout << "请输入要删除的联系人姓名：";
            cin >> searchName;
            targetNode = SearchContactByName(head, searchName);
            if (targetNode != NULL) {
                if (DeleteContact(head, targetNode)) {
                    cout << "删除成功！" << endl;
                } else {
                    cout << "删除失败！" << endl;
                }
            } else {
                cout << "未找到该联系人，无法删除！" << endl;
            }
            break;
        }
        case 5: // 5. 通讯录链表的输出
        {
            cout << "--- 当前通讯录所有联系人 ---" << endl;
            OutputAddressBook(head);
            break;
        }
        case 0: // 6. 退出管理系统
        {
            cout << "已退出通讯录管理系统，再见！" << endl;
            return 0;
        }
        default:
            cout << "输入无效，请输入 0~5 之间的数字！" << endl;
            break;
        }
    }
    return 0;
}