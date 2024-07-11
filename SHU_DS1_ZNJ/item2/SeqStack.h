#pragma once

// ˳��ջģ����
template<class ElemType>
class SeqStack
{
protected:
	// ˳��ջ�����ݳ�Ա:
	int top;										// ջ��ָ�� 
	int maxSize;									// ջ��������� 
	ElemType* elems;								// Ԫ�ش洢�ռ�

public:
	//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SeqStack(int size = DEFAULT_SIZE);				// ���캯��
	virtual ~SeqStack();							// ��������
	int GetLength() const;							// ��ջ�ĳ���			 
	bool IsEmpty() const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear();									// ��ջ���
	void Traverse(void (*Visit)(const ElemType&)) const;	// ����ջ
	void Push(const ElemType e);				    // ��ջ
	ElemType Top() const;				               // ȡ��Ԫ��
	void Pop();					                   // ��ջ
};


// ˳��ջ���ʵ�ֲ���

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// �������������һ���������Ϊsize�Ŀ�ջ
{
	maxSize = size;						// ջ���������
	if (elems != NULL) delete[]elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
	top = -1;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// �������������ջ
{
	delete[]elems;					// �ͷ�ջ�Ĵ洢�ռ�
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
// �������������ջ��Ԫ�ظ���
{
	return top + 1;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	return top == -1;
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
// ������������ջ
{
	top = -1;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
// �����������ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)���� 
{
	for (int i = top; i >= 0; i--)
		(*Visit)(elems[i]);
}

template<class ElemType>
void SeqStack<ElemType>::Push(const ElemType e)
{
	if (top == maxSize - 1) // ջ����
		return ;
	else {	// �����ɹ�
		elems[++top] = e;	// ��Ԫ��e׷�ӵ�ջ�� 
	}
}

template<class ElemType>
ElemType SeqStack<ElemType>::Top() const
{
	if (IsEmpty())	 // ջ��
		return 0;
	else { // ջ�ǿ�,�����ɹ�
		return elems[top];
	}
}

template<class ElemType>
void SeqStack<ElemType>::Pop()
{
	if (IsEmpty())	 // ջ��
		return;
	else { // �����ɹ�
	    top--; // ��e����ջ��Ԫ��
	}
}

