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
    class Compare
    {
        public:
            bool operator()(ListNode *l1, ListNode *l2)
            {
                return l1->val > l2->val;
            }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        for(int i = 0; i < n; ++i)
            if (lists[i] != NULL)
                pq.push(lists[i]);

        if (pq.empty())
            return NULL;

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            curr->next = temp;
            pq.pop();
            curr = curr->next;

            if (temp->next != NULL)
                pq.push(temp->next);

        }

        return dummy->next;
        
    }
};