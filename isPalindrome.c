/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 //֮ǰ��Ŀ�ı��Σ����ÿ���ָ��+��������

  //�������ô���
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* newHead = NULL;
    struct ListNode* cur = head;

    while (cur != NULL)
    {
        struct ListNode* next = cur->next;  //���嵽ѭ��������ܻ���ֿ�ָ�������

        //ͷ��
        cur->next = newHead;
        newHead = cur;

        cur = next;
    }

    return newHead;
}

bool isPalindrome(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)       //���жϻᱨ��������slow��fast��������Ϊ��
    {
        prev->next = NULL;
    }

    slow = reverseList(slow);  //����֮ǰ�������ô���

    while (head != NULL)
    {
        if (head->val != slow->val)
        {
            return false;
        }
        else
        {
            head = head->next;
            slow = slow->next;
        }

    }
    return true;
}