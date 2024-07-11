# 上海大学ZNJ数据结构1课程研讨
本项目为SHU 计算机专业 znj数据结构1课程的四个上机研讨，在此分享给大家

在此给出四个上机研讨的题目：
## 一、面试安排

### [1] 面试安排（1）
**1、问题描述**    
&emsp;&emsp;某IT公司招聘新员工，已收到N份简历，人力资源部X和Y负责挑选简历安排面试。他们把N份简历排成一个圆圈，按逆时针方向编号为1～N。开始时X站在1号简历前，按逆时针方向数到第K份简历，选中；Y站在N号简历前，按顺时针方向数到第M份简历，选中。两人同时取走所选简历后，分别按逆时针和顺时针走到下一份简历前，然后X和Y再重复上述方法取简历，直到取走全部简历，如果两人选中同一份简历，则只输出一个编号。
 
**2、基本要求**  
&emsp;&emsp;要求输入3个数N、K和M，按取走简历的顺序（先甲后已）输出简历编号。
 
**3、测试数据**  
&emsp;&emsp;输入样例：10 4 3  
&emsp;&emsp;输出样例：4, 8; 9, 5; 3, 1; 2, 6; 10; 7

### [2] 面试安排（2）
**1、问题描述**  
&emsp;&emsp;某IT公司招聘新员工，已收到N份简历，人力资源部X和Y负责挑选简历安排面试，Z负责补充新的简历。他们把N份简历排成一个圆圈，按逆时针方向编号为1～N。开始时X站在1号简历前，按逆时针方向数到第K份简历，选中；Y站在N号简历前，按顺时针方向数到第M份简历，选中。两人同时取走所选简历后，分别按逆时针和顺时针走到下一份简历前，此时（除非所有简历都已取完或者刚刚X和Y取走的是同一份简历），Z会拿来1份新简历（编号从N+1开始递加），插到X前面，然后X和Y再重复上述方法取简历，直到取走全部简历，如果两人选中同一份简历，则只输出一个编号。
 
 **2、基本要求**  
 &emsp;&emsp;要求输入3个数N、K和M，按取走简历的顺序（先甲后已）输出简历编号。
 
**3、测试数据**  
&emsp;&emsp;输入样例：5 1 1  
&emsp;&emsp;输出样例：1, 5; 6, 4; 7, 3; 8, 2

## 二、车厢调度
### [1] 车厢调度（1）
**1、问题描述**  
&emsp;&emsp;有一个“丁”字型铁路调度系统如图1所示，它由相互垂直的2条铁轨组成，水平方向的为主铁轨，竖直方向的为辅助铁轨。辅助铁轨用于对车厢次序进行调整，它在主铁轨中间，把主铁轨分成左右两个部分。主铁轨左边的车厢只能从左边开到右边，或者从主铁轨左边进入辅助铁轨；辅助铁轨上的车厢只可以进入主铁轨右边。  
&emsp;&emsp;现在有n节火车车厢，编号为1、2、...、n，在主铁轨的左边按顺序驶入，要求通过这个调度系统，在主铁轨的右边以指定次序开出（例如：有5节车厢以1、2、3、4、5 的次序进入，要求以3、2、5、4、1的顺序出站)。请编程求解调度过程。  
**2、输入数据**  
&emsp;&emsp;输入共2行，第1行一个正整数n表示车厢数目；第2行是1-n的任意排列，表示n节车厢在主铁轨右边的排列顺序。
**3、输出数据**  
&emsp;&emsp;如果能完成调度，则输出调度过程，否则输出调度失败信息。
![图1](./images/2-1.png)  
图1 “丁”字型铁路调度系统（按指定次序驶出）


### [2] 车厢调度（2）
**1、问题描述**  
&emsp;&emsp;有一个“丁”字型铁路调度系统如图2所示，它由相互垂直的2条铁轨组成，水平方向的为主铁轨，竖直方向的为辅助铁轨。辅助铁轨用于对车厢次序进行调整，它在主铁轨中间，把主铁轨分成左右两个部分。主铁轨左边的车厢只能从左边开到右边，或者从主铁轨左边进入辅助铁轨；辅助铁轨上的车厢只可以进入主铁轨右边。  
&emsp;&emsp;现在有n节火车车厢，编号为1、2、...、n，在主铁轨的左边以任意的顺序驶入，要求通过这个调度系统，在主铁轨的右边以1、2、...、n的次序开出（例如：有5节车厢以 5、3、1、2、4 的次序进入，要求以1、2、3、4、5的顺序出站)。请编程求解调度过程。
**2、输入数据**  
&emsp;&emsp;输入共2行，第1行一个正整数n表示车厢数目；第2行是1-n的任意排列，表示n节车厢在主铁轨左边的排列顺序。
**3、输出数据**  
&emsp;&emsp;如果能完成调度，则输出调度过程，否则输出调度失败信息。

![图2](./images/2-2.png)  
图2 “丁”字型铁路调度系统（按从小到大顺序驶出）

## 三、文学研究助手
**1、问题描述**  
&emsp;&emsp;文学研究人员需要统计英文小说中某些词出现的次数和位置。试编写一个实现这一目标的文字统计系统，称为“文学研究助手”。
**2、基本要求**  
&emsp;&emsp;英文小说存于一个文本文件中，并假设小说中的单词一律不跨行，每行的长度不超过120 个字符，待统计的词汇集合要一次输入完毕。要求对英文小说扫描一遍就完成统计工作。程序的输出结果是每个单词的出现次数和出现位置所在行的行号。其格式自行设计。
**3、输入数据**  
&emsp;&emsp;输入数据包括两部分，第一部分是要统计的单词，不超过 100个，单词之间用空格分隔；第二部分是被统计的文章，可以考虑把这两部分内容放在一个文件中。
&emsp;&emsp;例如：以某一 C++源程序模拟英文小说，用 C++程序设计语言的保留字集作为待统计的词汇集。
**4、输出数据**  
&emsp;&emsp;对出现在文章中的要统计的单词，输出其在文章中出现的次数和所在的行号。

## 四、二叉树

### [1] 左右子树交换  
在二叉链表类模板中增加函数成员Revolute()，实现二叉树中所有结点的左右子树交换。

### [2] 标记二叉树
**1、问题描述**  
&emsp;&emsp;一颗二叉树，根结点标记为（1，1），规定：如果一个结点标记为&（a，b），则它的左孩子（如果存在）标记为（a+b，b），它的右孩子（如果存在）标记为（a，a+b）。现在已知某个结点的标记为（a，b），求从根结点开始需要经过多少次左分支和多少次右分支才能达到结点（a，b）。

**2、输入文件**  
&emsp;输入文件第一行只有一个整数n，表示测试的数据组数。接下来n行（第2～n+1）行，每行包括两个整数a和b。

**3、输出文件**  
&emsp;输出文件有n行，每行包括两个整数，分别表示从根结点开始到（a，b）需要经过的左分支数和右分支数。

**4、输入样例**    
2  
42&emsp;&emsp;1    
3&emsp;&emsp;4  

**5、输出样例**  
41&emsp;&emsp;0    
2&emsp;&emsp;1  
