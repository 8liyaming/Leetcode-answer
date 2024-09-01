#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0; // ps->top = -1;
	ps->_capacity = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		int newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = realloc(ps->_a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->_a = tmp;
		ps->_capacity = newCapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->_top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}



typedef struct
{
	Stack _pushST;
	Stack _popST;
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->_pushST);
	StackInit(&q->_popST);

	return q;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->_pushST, x);
}

int myQueuePop(MyQueue* obj)
{
	int front = myQueuePeek(obj); //复用下面代码，把pushST中的数据取出来放到popST中
	StackPop(&obj->_popST);  //pop popST中的数据
	return front;
}

int myQueuePeek(MyQueue* obj)
{
	if (!StackEmpty(&obj->_popST))
	{
		return StackTop(&obj->_popST);
	}
	else
	{
		while (!StackEmpty(&obj->_pushST))
		{
			StackPush(&obj->_popST, StackTop(&obj->_pushST)); //把pushST中的数据取出来放到popST中
			StackPop(&obj->_pushST);
		}

		return StackTop(&obj->_popST);
	}
}

bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->_pushST) && StackEmpty(&obj->_popST);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->_pushST);
	StackDestroy(&obj->_popST);

	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/