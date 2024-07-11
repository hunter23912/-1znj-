#include "kmp.h"
struct WORD
{
    string word;
    int count;         // ���ʳ��ֵĴ���
    vector<int> lines; // ���ʳ��ֵ�����
};

#define MAX 100

void test(ifstream &file, const int &choice)
{
    string text;
    string firstline;
    string currentword;
    WORD pattern[MAX];

    // ��¼��Ҫͳ�Ƶĵ���
    if (choice == 2)
    {
        getchar();
        cout << "������Ҫͳ�Ƶĵ��ʣ��Կո�ָ����Ի��з�������" << endl;
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

    // ��ʼ����ͳ��
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

    // ������
    for (int i = 0; i < wordcount; ++i)
    {
        cout << pattern[i].word << "����" << pattern[i].count << "��" << endl;
        for (int &value : pattern[i].lines)
            cout << "��" << value << "��" << endl;
        cout << endl;
    }
}

int main()
{
    cout << "|----��ѧ�о�����----|" << endl;
    cout << "|---1.�ı���ȡ����---|" << endl;
    cout << "|---2.�����������---|" << endl;
    cout << "|----��ѡ��(1/2)-----|" << endl;
    int choice;
    cin >> choice;
    ifstream file("novel.txt");
    if (!file.is_open())
        cout << "�ļ���ʧ��" << endl;
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
//     cout << pattern << "������" << count << "��" << endl;
//     return 0;
// }