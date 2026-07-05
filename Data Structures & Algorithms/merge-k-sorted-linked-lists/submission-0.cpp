class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Insert first node of every list
        for (ListNode* node : lists) {
            if (node)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next)
                pq.push(smallest->next);
        }

        return dummy.next;
    }
};