#include <iostream>
#include "../headfile/Assistance.h" // 辅助软件包
#include "../headfile/BinaryTree.h" // 二叉链表类
using namespace std;

namespace SLU
{
    int solution1(void)
    {
        BinTreeNode<char> *p;

        char e;

        e = '1';
        BinaryTree<char> bt(e); // 建立二叉树

        e = '2';
        p = bt.GetRoot();         // p指向根结点
        bt.InsertLeftChild(p, e); // 插入左孩子

        e = '3';
        bt.InsertRightChild(p, e); // 插入右孩子

        p = bt.LeftChild(p); // p指向左孩子
        e = '4';
        bt.InsertLeftChild(p, e); // 插入左孩子

        p = bt.GetRoot();     // p指向根结点
        p = bt.RightChild(p); // p指向右孩子
        e = '5';
        bt.InsertLeftChild(p, e); // 插入左孩子

        e = '6';
        bt.InsertRightChild(p, e); // 插入右孩子
        cout << endl
             << "示例1.使用递归方法：" << endl;
        cout << "初始二叉树结构为：" << endl;
        DisplayBTWithTreeShape<char>(bt);
        /*
         *          1
         *         / \
         *        2   3
         *       /   / \
         *      4    5  6
         */
        Revolute1<char>(bt.GetRoot());
        cout << "交换左右子树后，结构为：" << endl;
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

        char pre[] = {'1', '2', '4', '7', '8', '3', '5', '6', '9'}; // 先序序列
        char in[] = {'7', '4', '8', '2', '1', '5', '3', '6', '9'};  // 中序序列
        int n = 9;                                                  // 结点个数
        BinaryTree<char> preInbt;
        preInbt = CreateBinaryTree(pre, in, n); // 构造二叉树
        cout << endl
             << "示例2.使用非递归方法：" << endl;
        cout << "初始二叉树结构为：" << endl;
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
        cout << "交换左右子树后，结构为：" << endl;
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
            cout << "不存在该结点" << endl;
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
             << "经过的左右分支数为" << lbranch << ',' << rbranch << endl;
        return true;
    }
}