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
                result.push_back("车厢 " + to_string(current) + " 从主铁轨左边进入辅助铁轨");
                current++;
            }
            result.push_back("车厢 " + to_string(current++) + " 从主铁轨左边进入主铁轨右边");
        }
        else if (!helper.IsEmpty() && helper.Top() == car)
        {
            helper.Pop();
            result.push_back("车厢 " + to_string(car) + " 从辅助铁轨进入主铁轨右边");
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
    // 定义一个栈，用于存储车厢的编号
    SeqStack<int> helper;
    // 定义一个索引变量，用于记录当前车厢的编号
    int i = 0;
    // 遍历每一辆车厢
    for (int car = 1; car <= n; car++)
    {
        // 如果当前车厢编号小于n，且当前车厢编号等于当前遍历到的车厢编号
        if (i <= n - 1 && origin[i] == car)
        {
            // 将当前车厢编号和当前车厢进入主铁轨的方向添加到结果中
            result.push_back("车厢 " + to_string(origin[i++]) + " 从主铁轨左边进入主铁轨右边");
        }
        // 如果当前车厢编号小于n，且当前车厢编号大于当前遍历到的车厢编号，且栈为空或者栈顶车厢编号大于当前车厢编号
        else if (i <= n - 1 && origin[i] > car && (helper.IsEmpty() || helper.Top() > origin[i]))
        {
            // 将当前车厢编号添加到栈中，并将当前车厢编号和当前车厢进入辅助铁轨的方向添加到结果中
            while (origin[i] > car)
            {
                helper.Push(origin[i]);
                result.push_back("车厢 " + to_string(origin[i++]) + " 从主铁轨左边进入辅助铁轨");
            }
            // 将当前车厢编号和当前车厢进入主铁轨的方向添加到结果中
            result.push_back("车厢 " + to_string(origin[i++]) + " 从主铁轨左边进入主铁轨右边");
        }
        // 如果栈不为空，且栈顶车厢编号等于当前遍历到的车厢编号
        else if (!helper.IsEmpty() && helper.Top() == car)
        {
            // 将栈顶车厢编号弹出，并将当前车厢进入主铁轨的方向添加到结果中
            helper.Pop();
            result.push_back("车厢 " + to_string(car) + " 从辅助铁轨进入主铁轨右边");
        }
        // 否则，返回false
        else
        {
            return false;
        }
    }
    // 如果遍历结束，返回true
    return true;
}

void test1()
{
    cout << "请输入车箱数目：" << endl;
    int n, data;
    vector<int> target;
    cin >> n;
    cout << "请输入" << n << "节车厢出站顺序：" << endl;
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
        cout << "无法按照指定顺序调度车厢" << endl;
    }
}

void test2()
{
    // 提示用户输入车箱数
    cout << "请输入车箱数目：" << endl;
    int n, data;
    // 定义一个vector，用于存储车厢的原始顺序
    vector<int> origin;
    // 定义一个vector，用于存储调度过程
    vector<string> process;
    // 读取用户输入的数字
    cin >> n;
    // 提示用户输入车厢的原始顺序
    cout << "请输入" << n << "节车厢驶入顺序：" << endl;
    // 循环读取用户输入的数字，并将其存储到origin中
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        origin.push_back(data);
    }
    cout << endl;

    // 调用train_dispatch2函数，调度车厢
    if (train_dispatch2(n, origin, process))
    {
        // 如果调度成功，则输出调度过程
        for (const string &step : process)
        {

            cout << step << endl;
        }
    }
    else
    {
        // 如果调度失败，则提示用户
        cout << "无法按照指定顺序调度车厢" << endl;
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout << "请选择问题：\n"
             << "1.车厢调度（1）\n"
             << "2.车厢调度（2）\n"
             << "0.退出\n";
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