/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode* prev = NULL;  //防止删掉节点后找不到链接地址
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;

    while (next != NULL)
    {
        if (cur->val != next->val)
        {
            prev = cur;
            cur = next;
            next = next->next;
        }
        else
        {
            while (next != NULL && cur->val == next->val)  //**不加next != NULL跑不了，这对应链表结尾为重复的情况**
            {
                next = next->next;
            }

            if (prev != NULL)   //**不判断是否为空跑不了，这对应链表开头即为重复的情况**
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }

            //释放掉重复数字的节点，不用释放直接连上新的节点（上面一步）也可以通过
            while (cur != next)
            {
                struct ListNode* del = cur;  //先保存再释放
                cur = cur->next;
                free(del);
            }

            if (next != NULL)
            {
                next = cur->next;
            }
        }
    }

    return head;
}