/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* smallTail = malloc(sizeof(struct ListNode));
    struct ListNode* smallHead = smallTail;
    struct ListNode* largeTail = malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = largeTail;

    struct ListNode* cur = head;
    while (cur != NULL)
    {
        if (cur->val < x)
        {
            smallTail->next = cur;
            smallTail = smallTail->next;
        }
        else
        {
            largeTail->next = cur;
            largeTail = largeTail->next;
        }
        cur = cur->next;
    }

    largeTail->next = NULL;
    smallTail->next = largeHead->next;

    return smallHead->next;
}