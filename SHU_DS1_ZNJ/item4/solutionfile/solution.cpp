#include <iostream>
#include "../headfile/Assistance.h" // ���������
#include "../headfile/BinaryTree.h" // ����������
using namespace std;

namespace SLU
{
    int solution1(void)
    {
        BinTreeNode<char> *p;

        char e;

        e = '1';
        BinaryTree<char> bt(e); // ����������

        e = '2';
        p = bt.GetRoot();         // pָ������
        bt.InsertLeftChild(p, e); // ��������

        e = '3';
        bt.InsertRightChild(p, e); // �����Һ���

        p = bt.LeftChild(p); // pָ������
        e = '4';
        bt.InsertLeftChild(p, e); // ��������

        p = bt.GetRoot();     // pָ������
        p = bt.RightChild(p); // pָ���Һ���
        e = '5';
        bt.InsertLeftChild(p, e); // ��������

        e = '6';
        bt.InsertRightChild(p, e); // �����Һ���
        cout << endl
             << "ʾ��1.ʹ�õݹ鷽����" << endl;
        cout << "��ʼ�������ṹΪ��" << endl;
        DisplayBTWithTreeShape<char>(bt);
        /*
         *          1
         *         / \
         *        2   3
         *       /   / \
         *      4    5  6
         */
        Revolute1<char>(bt.GetRoot());
        cout << "�������������󣬽ṹΪ��" << endl;
        DisplayBTWithTreeShape<char>(bt);
        /*
         *          1
         *         / \
         *        3   2
         *       / \   \
         *      6  5    4
         */
        cout << endl;
        system("PAUSE");

        char pre[] = {'1', '2', '4', '7', '8', '3', '5', '6', '9'}; // ��������
        char in[] = {'7', '4', '8', '2', '1', '5', '3', '6', '9'};  // ��������
        int n = 9;                                                  // ������
        BinaryTree<char> preInbt;
        preInbt = CreateBinaryTree(pre, in, n); // ���������
        cout << endl
             << "ʾ��2.ʹ�÷ǵݹ鷽����" << endl;
        cout << "��ʼ�������ṹΪ��" << endl;
        DisplayBTWithTreeShape<char>(preInbt);
        /*
         *          1
         *         / \
         *        2   3
         *         \ / \
         *         4 5  6
         *        / \    \
         *       7   8    9
         */
        Revolute2<char>(preInbt.GetRoot());
        cout << "�������������󣬽ṹΪ��" << endl;
        DisplayBTWithTreeShape<char>(preInbt);
        /*
         *          1
         *         / \
         *        3   2
         *       / \   \
         *      6  5    4
         *     /       / \
         *    9       8   7
         */
        cout << endl;
        system("PAUSE");
        return 0;
    }

    bool solution2(int a, int b)
    {
        int lbranch = 0, rbranch = 0;
        int atemp = a, btemp = b;
        while (a > 1 && b > 1)
        {
            if (a > b)
            {
                lbranch += a / b;
                a %= b;
            }
            else 
            {
                rbranch += b / a;
                b %= a;
            }
        }

        if (a == 0 || b == 0)
        {
            cout << "�����ڸý��" << endl;
            return false;
        }

        if (a == 1)
        {
            rbranch += b - 1;
        }
        else
        {
            lbranch += a - 1;
        }

        cout << '(' << atemp << ',' << btemp << ')'
             << "���������ҷ�֧��Ϊ" << lbranch << ',' << rbranch << endl;
        return true;
    }
}