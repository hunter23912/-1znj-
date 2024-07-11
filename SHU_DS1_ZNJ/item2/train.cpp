#include "Assistance.h"
#include "SeqStack.h"
#include <vector>

bool train_dispatch1(const vector<int> &target, vector<string> &result)
{
    SeqStack<int> helper;
    int current = 1;

    for (int car : target)
    {
        if (current <= car)
        {
            while (current < car)
            {
                helper.Push(current);
                result.push_back("���� " + to_string(current) + " ����������߽��븨������");
                current++;
            }
            result.push_back("���� " + to_string(current++) + " ����������߽����������ұ�");
        }
        else if (!helper.IsEmpty() && helper.Top() == car)
        {
            helper.Pop();
            result.push_back("���� " + to_string(car) + " �Ӹ�����������������ұ�");
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool train_dispatch2(int &n, const vector<int> &origin, vector<string> &result)
{
    // ����һ��ջ�����ڴ洢����ı��
    SeqStack<int> helper;
    // ����һ���������������ڼ�¼��ǰ����ı��
    int i = 0;
    // ����ÿһ������
    for (int car = 1; car <= n; car++)
    {
        // �����ǰ������С��n���ҵ�ǰ�����ŵ��ڵ�ǰ�������ĳ�����
        if (i <= n - 1 && origin[i] == car)
        {
            // ����ǰ�����ź͵�ǰ�������������ķ�����ӵ������
            result.push_back("���� " + to_string(origin[i++]) + " ����������߽����������ұ�");
        }
        // �����ǰ������С��n���ҵ�ǰ�����Ŵ��ڵ�ǰ�������ĳ����ţ���ջΪ�ջ���ջ�������Ŵ��ڵ�ǰ������
        else if (i <= n - 1 && origin[i] > car && (helper.IsEmpty() || helper.Top() > origin[i]))
        {
            // ����ǰ��������ӵ�ջ�У�������ǰ�����ź͵�ǰ������븨������ķ�����ӵ������
            while (origin[i] > car)
            {
                helper.Push(origin[i]);
                result.push_back("���� " + to_string(origin[i++]) + " ����������߽��븨������");
            }
            // ����ǰ�����ź͵�ǰ�������������ķ�����ӵ������
            result.push_back("���� " + to_string(origin[i++]) + " ����������߽����������ұ�");
        }
        // ���ջ��Ϊ�գ���ջ�������ŵ��ڵ�ǰ�������ĳ�����
        else if (!helper.IsEmpty() && helper.Top() == car)
        {
            // ��ջ�������ŵ�����������ǰ�������������ķ�����ӵ������
            helper.Pop();
            result.push_back("���� " + to_string(car) + " �Ӹ�����������������ұ�");
        }
        // ���򣬷���false
        else
        {
            return false;
        }
    }
    // �����������������true
    return true;
}

void test1()
{
    cout << "�����복����Ŀ��" << endl;
    int n, data;
    vector<int> target;
    cin >> n;
    cout << "������" << n << "�ڳ����վ˳��" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        target.push_back(data);
    }
    vector<string> process;
    if (train_dispatch1(target, process))
    {
        for (const string &step : process)
        {
            cout << step << endl;
        }
    }
    else
    {
        cout << "�޷�����ָ��˳����ȳ���" << endl;
    }
}

void test2()
{
    // ��ʾ�û����복����
    cout << "�����복����Ŀ��" << endl;
    int n, data;
    // ����һ��vector�����ڴ洢�����ԭʼ˳��
    vector<int> origin;
    // ����һ��vector�����ڴ洢���ȹ���
    vector<string> process;
    // ��ȡ�û����������
    cin >> n;
    // ��ʾ�û����복���ԭʼ˳��
    cout << "������" << n << "�ڳ���ʻ��˳��" << endl;
    // ѭ����ȡ�û���������֣�������洢��origin��
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        origin.push_back(data);
    }
    cout << endl;

    // ����train_dispatch2���������ȳ���
    if (train_dispatch2(n, origin, process))
    {
        // ������ȳɹ�����������ȹ���
        for (const string &step : process)
        {

            cout << step << endl;
        }
    }
    else
    {
        // �������ʧ�ܣ�����ʾ�û�
        cout << "�޷�����ָ��˳����ȳ���" << endl;
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout << "��ѡ�����⣺\n"
             << "1.������ȣ�1��\n"
             << "2.������ȣ�2��\n"
             << "0.�˳�\n";
        cin >> choice;
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        }
        cout << endl;
    }
    return 0;
}