#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// 构造模式串pattern的失效函数
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

// 使用KMP算法统计模式串pattern在主串text中出现的次数
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

