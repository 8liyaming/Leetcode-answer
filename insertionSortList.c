/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //����˼�룺���δӺ��棨�ڶ�����ʼ����һ����Ĭ�ϵ�ͷ��ȡһ���ڵ���ǰ�����λ�ò���
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode* sortHead = head;
    struct ListNode* cur = head->next;
    sortHead->next = NULL;   //��������Ҫ�ÿգ������γɻ�

    while (cur != NULL)
    {
        struct ListNode* next = cur->next;  //��¼��һ���ڵ��λ�ã�����Ͽ��Ҳ���

        //��cur���뵽sortHead�����У����ұ�������
        //ͷ������
        if (cur->val <= sortHead->val)
        {
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //�м��������
            struct ListNode* sortPrev = sortHead;
            struct ListNode* sortCur = sortPrev->next;
            while (sortCur != NULL)
            {
                if (cur->val <= sortCur->val)
                {
                    sortPrev->next = cur;
                    cur->next = sortCur;
                    break;
                }
                else
                {
                    sortPrev = sortCur;
                    sortCur = sortCur->next;
                }
            }

            //β������
            if (sortCur == NULL)
            {
                sortPrev->next = cur;
                cur->next = NULL;
            }
        }

        cur = next;
    }

    return sortHead;
}