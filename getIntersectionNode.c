/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //˼�룺�ó��������ָ�����߲�ֵ������֤��������ָ��ͬʱ�����ཻ�ڵ�
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //���������ĳ���
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

    //�ж�˭��˭�̣�����û�з�3��������ۣ����ǲ���******���跨!!!!!*******��
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    if (lB > lA)
    {
        longList = headB;
        shortList = headA;
    }

    //���������ָ�����߲�ֵ��
    int gap = abs(lA - lB);
    while (gap--)
    {
        longList = longList->next;
    }

    //ѭ������
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