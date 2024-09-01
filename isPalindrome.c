/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 //之前题目的变形，利用快慢指针+链表逆置

  //链表逆置代码
struct ListNode* reverseList(struct ListNode* head)
{
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

    if (prev != NULL)       //不判断会报错？按道理slow比fast慢，不会为空
    {
        prev->next = NULL;
    }

    slow = reverseList(slow);  //调用之前链表逆置代码

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