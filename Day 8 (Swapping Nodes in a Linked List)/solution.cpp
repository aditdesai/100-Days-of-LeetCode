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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1, *slow, *fast;
        n1 = slow = fast = head;
        for(int i = 1; i < k; ++i)
        {
            n1 = n1->next;
            fast = fast->next;
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        int tmp = n1->val;
        n1->val = slow->val;
        slow->val = tmp;

        return head;
        
    }
};