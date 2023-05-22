/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (left && right)
        {
            if (left->val <= right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        if (left)
            curr->next = left;
        if (right)
            curr->next = right;
            
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *afterMiddle = slow->next;
        slow->next = NULL;

        ListNode *left = sortList(head);
        ListNode *right = sortList(afterMiddle);

        return merge(left, right);
    }
};