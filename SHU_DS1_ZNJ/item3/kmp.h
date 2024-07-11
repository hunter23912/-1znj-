#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// ����ģʽ��pattern��ʧЧ����
int buildkmp(string &pattern, int plength, int *next)
{
    int prefix = 0;
    next[0] = 0;
    for (int i = 1; i < plength; ++i)
    {
        while (prefix > 0 && pattern[i] != pattern[prefix])
            prefix = next[prefix - 1];
        if (pattern[i] == pattern[prefix])
            ++prefix;
        next[i] = prefix;
    }
    return 0;
}

// ʹ��KMP�㷨ͳ��ģʽ��pattern������text�г��ֵĴ���
int searchwithkmp(string &text, int tlength, string &pattern, int plength, int &count, int flag = 0)
{
    int *next = new int[plength];
    buildkmp(pattern, plength, next);
    int j = 0;
    for (int i = 0; i < tlength; ++i)
    {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            ++j;
        if (j == plength)
        {
            flag = 1;
            count++;
            j = 0;
        }
    }
    delete[] next;
    return flag;
}

