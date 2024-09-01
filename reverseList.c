/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    //********反转链表法：利用三个指针移位*********//
   if (head == NULL || head -> next == NULL)
   {
        return head;
   }

    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head -> next;
    while(n2 != NULL)
    {
        //反转
        n2 -> next = n1;

        //迭代
        n1 = n2;
       n2 = n3;
        
        if (n3 != NULL)
        {
            n3 = n3 -> next;
        }
    }

    return n1;

    //***头插法：取cur头插到以newhead为头的新链表中***//
    struct ListNode* newHead = NULL;
    struct ListNode* cur = head;

    while (cur != NULL)
    {
        struct ListNode* next = cur->next;  //定义到循环外面可能会出现空指针的问题

        //头插
        cur->next = newHead;
        newHead = cur;

        cur = next;
    }

    return newHead;
}