typedef struct
{
    int* _a;
    int _front;
    int _rear;
    int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->_a = (int*)malloc(sizeof(int) * (k + 1));  //多开一个
    q->_front = 0;
    q->_rear = 0;
    q->_k = k;

    return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);  //手动声明一下，这个在使用位置后面给出的，把该接口移到这里也可以
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    //满了则不让插入
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    //不满则插入，并将_rear位置向后挪动一位
    else
    {
        obj->_a[obj->_rear] = value;
        obj->_rear++;
        obj->_rear %= (obj->_k + 1); //到最后一个位置后回到开头
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //空的则不让删除
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    //不为空则可以执行删除操作（可以不用将对应元素剔除，只用将_front往后走一位即可）
    else
    {
        ++obj->_front;
        obj->_front %= (obj->_k + 1); //到最后一个位置后回到开头
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    //如果队列为空，返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    //如果队列不为空，返回首元素
    else
    {
        return obj->_a[obj->_front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    //如果队列为空，返回-1
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    //如果队列不为空，返回尾元素
    else
    {
        int tail = obj->_rear - 1;  //注意真正的尾元素为（_rear-1）处
        // _rear 为0时，不能-1，跳到最后位置
        if (obj->_rear == 0)
        {
            tail = (obj->_k);
        }
        return obj->_a[tail];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->_a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/