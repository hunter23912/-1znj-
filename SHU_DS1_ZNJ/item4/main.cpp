#include <iostream>
#include "solution.h"
using namespace std;

int main()
{
    int choice;
    while (true)
    {
        cout << "[1] ������������" << endl;
        cout << "[2] ��Ƕ�����" << endl;
        cout << "[0] �˳�" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            SLU::solution1();
            break;
        case 2:
            cout << "��������������:" << endl;
            int n;
            cin >> n;
            int a, b;
            cout << "�������������:" << endl;
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
