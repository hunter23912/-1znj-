#include "kmp.h"
struct WORD
{
    string word;
    int count;         // 单词出现的次数
    vector<int> lines; // 单词出现的行数
};

#define MAX 100

void test(ifstream &file, const int &choice)
{
    string text;
    string firstline;
    string currentword;
    WORD pattern[MAX];

    // 记录需要统计的单词
    if (choice == 2)
    {
        getchar();
        cout << "请输入要统计的单词，以空格分隔，以换行符结束：" << endl;
        getline(cin, firstline);
        string temp;
        getline(file, temp);
    }
    else
        getline(file, firstline);
    istringstream iss(firstline);
    int wordcount = 0;
    while (iss >> currentword && wordcount <= MAX)
    {
        pattern[wordcount++] = {currentword, 0, {}};
    }

    // 开始逐行统计
    string line;
    int linenumber = 2;
    while (getline(file, line))
    {
        for (int i = 0; i < wordcount; ++i)
        {

            if (searchwithkmp(line, line.length(), pattern[i].word, pattern[i].word.length(), pattern[i].count))
            {
                pattern[i].lines.push_back(linenumber);
            }
        }
        linenumber++;
    }

    // 输出结果
    for (int i = 0; i < wordcount; ++i)
    {
        cout << pattern[i].word << "出现" << pattern[i].count << "次" << endl;
        for (int &value : pattern[i].lines)
            cout << "第" << value << "行" << endl;
        cout << endl;
    }
}

int main()
{
    cout << "|----文学研究助手----|" << endl;
    cout << "|---1.文本读取查找---|" << endl;
    cout << "|---2.自行输入查找---|" << endl;
    cout << "|----请选择(1/2)-----|" << endl;
    int choice;
    cin >> choice;
    ifstream file("novel.txt");
    if (!file.is_open())
        cout << "文件打开失败" << endl;
    else
        test(file, choice);
    file.close();
    return 0;
}

// int main()
// {
//     string text = "abcdefac";
//     string pattern = "be";
//     int count = 0, flag = 0;
//     searchwithkmp(text, text.length(), pattern, pattern.length(), count, flag);
//     cout << pattern << "出现了" << count << "次" << endl;
//     return 0;
// }