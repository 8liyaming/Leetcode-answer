/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* trainingPlan(struct ListNode* head, int cnt)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (cnt--)
    {
        //    if (fast != NULL)   解决cnt值比链表长度大的问题，此题没有测试该特殊情况
        //    {
        fast = fast->next;
        //    }
        //     else
        //      {
        //        return NULL;
        //      }
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}