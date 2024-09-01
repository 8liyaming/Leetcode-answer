/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //本题核心思想：取小的节点下来尾插
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    //    if(list1 -> val < list2 -> val)
    //    {
    //        head = tail = list1;
    //        list1 = list1 -> next;
    //    }
    //    else
    //    {
    //        head = tail = list2;
    //        list2 = list2 -> next;
    //    }

        //带哨兵位的头节点，他不存储有效数据，方便尾插（与上面方法二选一）
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

    //取小的节点尾插
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }

    //    return head;  //(与下面二选一)

    struct ListNode* realhead = head->next;
    free(head);
    return realhead;
}
