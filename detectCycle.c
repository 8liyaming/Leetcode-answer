/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        return NULL;
    }

    struct ListNode* meet = fast;
    while (head != meet)
    {
        head = head->next;
        meet = meet->next;
    }

    return meet;
}