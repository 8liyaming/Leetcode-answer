/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            //处理第一个节点即为要删除的节点的特殊情况
            //if (prev == NULL)
            if (cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);

                // 处理最后一个节点即为要删除的节点的特殊情况(不处理的话，cur被free后到whlie循环会出现野指针)
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}