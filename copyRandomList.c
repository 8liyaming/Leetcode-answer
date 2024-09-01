/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // 1.�����ڵ㣬���ӵ�ԭ�ڵ����
    struct Node* cur = head;
    while (cur != NULL)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->next = NULL;
        copy->random = NULL;
        copy->val = cur->val;

        struct Node* next = cur->next;   //��Ҫ�ʼ��if�ж�
        cur->next = copy;
        copy->next = next;

        cur = next;
    }

    // 2.�������ڵ��random
    cur = head;
    while (cur != NULL)
    {
        struct Node* copy = cur->next;
        if (cur->random != NULL)
        {
            copy->random = cur->random->next;
        }
        else
        {
            copy->random = NULL;
        }

        cur = cur->next->next;
    }

    // 3.������������
    cur = head;
    struct Node* copyHead = head->next;
    while (cur != NULL)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        cur->next = next;
        if (next != NULL)
        {
            copy->next = next->next;
        }
        else
        {
            copy->next = NULL;
        }

        cur = next;
    }

    return copyHead;
}