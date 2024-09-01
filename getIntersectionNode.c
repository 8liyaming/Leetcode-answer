/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //思想：让长的链表的指针先走差值步，保证了两链表指针同时到达相交节点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //求出两链表的长度
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    int lA = 0;
    int lB = 0;
    while (curA != NULL)
    {
        lA++;
        curA = curA->next;
    }
    while (curB != NULL)
    {
        lB++;
        curB = curB->next;
    }

    //判断谁长谁短（这里没有分3种情况讨论，而是采用******假设法!!!!!*******）
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    if (lB > lA)
    {
        longList = headB;
        shortList = headA;
    }

    //长的链表的指针先走差值步
    int gap = abs(lA - lB);
    while (gap--)
    {
        longList = longList->next;
    }

    //循环查找
    while (longList)
    {
        if (longList == shortList)
        {
            return longList;
        }
        longList = longList->next;
        shortList = shortList->next;
    }

    return NULL;
}