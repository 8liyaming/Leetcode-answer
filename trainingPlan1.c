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
        //    if (fast != NULL)   ���cntֵ�������ȴ�����⣬����û�в��Ը��������
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