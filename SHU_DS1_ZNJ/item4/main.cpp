#include <iostream>
#include "solution.h"
using namespace std;

int main()
{
    int choice;
    while (true)
    {
        cout << "[1] 左右子树交换" << endl;
        cout << "[2] 标记二叉树" << endl;
        cout << "[0] 退出" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            SLU::solution1();
            break;
        case 2:
            cout << "请输入数据组数:" << endl;
            int n;
            cin >> n;
            int a, b;
            cout << "请输入测试数据:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "(" << i + 1 << ")";
                cin >> a >> b;
                SLU::solution2(a, b);
                cout << endl;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}
