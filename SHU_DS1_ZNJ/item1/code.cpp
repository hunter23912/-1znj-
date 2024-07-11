#include <iostream>
using namespace std;

class Node // 结点类
{
public:
    int data;                           // 简历编号，从1到n
    Node *prior;                        // 前驱
    Node *next;                         // 后继
    Node() : prior(NULL), next(NULL) {} // 默认构造函数
};

class Link // 链表类
{
public:
    int len; // 链表结点数
    Node *head;
    Link(int n) : len(n) // 构造n个结点的环形链表，不包含头结点
    {
        head = new Node;
        Node *r, *p;
        head->data = 1;
        p = head;
        for (int i = 2; i <= n; i++)
        {
            r = new Node;
            r->data = i;
            r->prior = p;
            p->next = r;
            p = r;
        }
        p->next = head;
        head->prior = p;
    }
};

void solution1(Link &l, int k, int m)
{
    Node *x, *y;
    x = l.head;
    y = l.head->prior;
    int count = 0;         // 记录输出元素个数
    while (count != l.len) // 输出n个元素后,跳出循环
    {
        for (int i = 1; i < k; i++) // x,y分别找到相应位置
            x = x->next;
        for (int i = 1; i < m; i++)
            y = y->prior;
        if (x->data == y->data) // 若x,y指向同一个元素，只输出一个
        {
            cout << x->data;
            if (count < l.len - 1)
                cout << "; ";
            count++;
            x->prior->next = x->next;
            x->next->prior = x->prior;
            x = x->next;
            y = y->prior;
        }
        else
        {
            cout << x->data << ", ";
            x->prior->next = x->next;
            x->next->prior = x->prior;
            count++;
            x = x->next;
            cout << y->data;
            if (count < l.len - 1)
                cout << "; ";
            y->prior->next = y->next;
            y->next->prior = y->prior;
            count++;
            int t;
            t = y->data;
            y = y->prior;
            if (x->data == t) // 特殊情况判断，如果先前x,y相邻，x指针需要多移一位
                x = x->next;
        }
    }
}

void solution2(Link &l, int k, int m)
{
    Node *x, *y;
    x = l.head; // 初始化X,Y的指向，X指向1，Y指向末位
    y = l.head->prior;
    int count = 0, j = 0;
    while (count < l.len + j)
    {
        for (int i = 1; i < k; i++)
            x = x->next;
        for (int i = 1; i < m; i++)
            y = y->prior;
        if (x->data == y->data)
        {
            cout << x->data;
            if (count < l.len + j - 1)
                cout << "; ";
            count++;
            x->prior->next = x->next;
            x->next->prior = x->prior;
            x = x->next;
            y = y->prior;
        }
        else
        {
            cout << x->data << ", ";
            count++;
            cout << y->data;
            if (count < l.len + j - 1)
                cout << "; ";
            count++;
            if (x->next == y && y->next == x) // 特殊情况判断，x,y取完简历，不需要递上新简历，终止循环
                break;
            j++;
            x->data = l.len + j; // z递上新简历，编号从n+1开始递加
            y->prior->next = y->next;
            y->next->prior = y->prior;
            y = y->prior;
            if (y->data == x->data)
                y = y->prior;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {

        cout << "请选择要解决的问题序号：\n"
             << "1.面试安排（1）\n"
             << "2.面试安排（2）\n"
             << "0.退出\n";
        cin >> choice;
        if (choice == 0)
            break;
        int n, k, m;
        cout << "请输入N K M" << endl;
        cin >> n >> k >> m;
        Link l(n);
        switch (choice)
        {
        case (1):
            solution1(l, k, m);
            cout << endl;
            break;
        case (2):
            solution2(l, k, m);
            cout << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}