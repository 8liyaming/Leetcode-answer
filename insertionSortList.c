/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //核心思想：依次从后面（第二个开始，第一个当默认的头）取一个节点在前面合适位置插入
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode* sortHead = head;
    struct ListNode* cur = head->next;
    sortHead->next = NULL;   //处理完需要置空，以免形成环

    while (cur != NULL)
    {
        struct ListNode* next = cur->next;  //记录下一个节点的位置，以免断开找不到

        //把cur插入到sortHead链表中，并且保持有序
        //头插的情况
        if (cur->val <= sortHead->val)
        {
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //中间插入的情况
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

            //尾插的情况
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