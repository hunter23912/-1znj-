#pragma once

// 顺序栈模板类
template<class ElemType>
class SeqStack
{
protected:
	// 顺序栈的数据成员:
	int top;										// 栈顶指针 
	int maxSize;									// 栈的最大容量 
	ElemType* elems;								// 元素存储空间

public:
	//  顺序栈的方法声明及重载编译系统默认方法声明:
	SeqStack(int size = DEFAULT_SIZE);				// 构造函数
	virtual ~SeqStack();							// 析构函数
	int GetLength() const;							// 求栈的长度			 
	bool IsEmpty() const;							// 判断栈是否为空
	void Clear();									// 将栈清空
	void Traverse(void (*Visit)(const ElemType&)) const;	// 遍历栈
	void Push(const ElemType e);				    // 入栈
	ElemType Top() const;				               // 取顶元素
	void Pop();					                   // 出栈
};


// 顺序栈类的实现部分

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// 操作结果：构造一个最大容量为size的空栈
{
	maxSize = size;						// 栈的最大容量
	if (elems != NULL) delete[]elems;	// 释放已有存储空间
	elems = new ElemType[maxSize];		// 分配新的存储空间
	top = -1;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// 操作结果：销毁栈
{
	delete[]elems;					// 释放栈的存储空间
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
// 操作结果：返回栈中元素个数
{
	return top + 1;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
// 操作结果：如栈为空，则返回true，否则返回false
{
	return top == -1;
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
// 操作结果：清空栈
{
	top = -1;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
// 操作结果：从栈顶到栈底依次对栈的每个元素调用函数(*visit)访问 
{
	for (int i = top; i >= 0; i--)
		(*Visit)(elems[i]);
}

template<class ElemType>
void SeqStack<ElemType>::Push(const ElemType e)
{
	if (top == maxSize - 1) // 栈已满
		return ;
	else {	// 操作成功
		elems[++top] = e;	// 将元素e追加到栈顶 
	}
}

template<class ElemType>
ElemType SeqStack<ElemType>::Top() const
{
	if (IsEmpty())	 // 栈空
		return 0;
	else { // 栈非空,操作成功
		return elems[top];
	}
}

template<class ElemType>
void SeqStack<ElemType>::Pop()
{
	if (IsEmpty())	 // 栈空
		return;
	else { // 操作成功
	    top--; // 用e返回栈顶元素
	}
}

