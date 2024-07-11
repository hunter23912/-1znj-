#include <iostream>
using namespace std;

class Node // �����
{
public:
    int data;                           // ������ţ���1��n
    Node *prior;                        // ǰ��
    Node *next;                         // ���
    Node() : prior(NULL), next(NULL) {} // Ĭ�Ϲ��캯��
};

class Link // ������
{
public:
    int len; // ��������
    Node *head;
    Link(int n) : len(n) // ����n�����Ļ�������������ͷ���
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
    int count = 0;         // ��¼���Ԫ�ظ���
    while (count != l.len) // ���n��Ԫ�غ�,����ѭ��
    {
        for (int i = 1; i < k; i++) // x,y�ֱ��ҵ���Ӧλ��
            x = x->next;
        for (int i = 1; i < m; i++)
            y = y->prior;
        if (x->data == y->data) // ��x,yָ��ͬһ��Ԫ�أ�ֻ���һ��
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
            if (x->data == t) // ��������жϣ������ǰx,y���ڣ�xָ����Ҫ����һλ
                x = x->next;
        }
    }
}

void solution2(Link &l, int k, int m)
{
    Node *x, *y;
    x = l.head; // ��ʼ��X,Y��ָ��Xָ��1��Yָ��ĩλ
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
            if (x->next == y && y->next == x) // ��������жϣ�x,yȡ�����������Ҫ�����¼�������ֹѭ��
                break;
            j++;
            x->data = l.len + j; // z�����¼�������Ŵ�n+1��ʼ�ݼ�
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

        cout << "��ѡ��Ҫ�����������ţ�\n"
             << "1.���԰��ţ�1��\n"
             << "2.���԰��ţ�2��\n"
             << "0.�˳�\n";
        cin >> choice;
        if (choice == 0)
            break;
        int n, k, m;
        cout << "������N K M" << endl;
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