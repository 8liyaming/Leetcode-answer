/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    //********��ת��������������ָ����λ*********//
   if (head == NULL || head -> next == NULL)
   {
        return head;
   }

    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head -> next;
    while(n2 != NULL)
    {
        //��ת
        n2 -> next = n1;

        //����
        n1 = n2;
       n2 = n3;
        
        if (n3 != NULL)
        {
            n3 = n3 -> next;
        }
    }

    return n1;

    //***ͷ�巨��ȡcurͷ�嵽��newheadΪͷ����������***//
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