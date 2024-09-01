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

    struct ListNode* prev = NULL;  //��ֹɾ���ڵ���Ҳ������ӵ�ַ
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
            while (next != NULL && cur->val == next->val)  //**����next != NULL�ܲ��ˣ����Ӧ�����βΪ�ظ������**
            {
                next = next->next;
            }

            if (prev != NULL)   //**���ж��Ƿ�Ϊ���ܲ��ˣ����Ӧ����ͷ��Ϊ�ظ������**
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }

            //�ͷŵ��ظ����ֵĽڵ㣬�����ͷ�ֱ�������µĽڵ㣨����һ����Ҳ����ͨ��
            while (cur != next)
            {
                struct ListNode* del = cur;  //�ȱ������ͷ�
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