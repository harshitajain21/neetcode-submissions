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

    //At any moment, we only care about the smallest current node of each list.
    //Take that node, add it to our answer, and move that list's pointer forward.
    //Doing this manually would take O(k) to find the smallest each time.
    
    //Instead, use a min-heap / priority queue.
    //One node from each non-empty list will go inside that list
    //take smallest -> put it in result -> remove it from heap and put its next in heap

public:

    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };


    // Min heap:
    // smallest node value stays at the top
    priority_queue< ListNode*, vector<ListNode*>, compare>pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Put the first node of every list into the heap
        for (ListNode* head : lists) {
            if (head != NULL) {
                pq.push(head);
            }
        }

        ListNode* new_head = NULL;
        ListNode* tail = NULL;

        while (!pq.empty()) {

            // Get the smallest current node
            ListNode* temp = pq.top();
            pq.pop();

            // Add it to our answer
            if (new_head == NULL) {
                new_head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            // Add the next node from the same list
            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return new_head;
        
    }
};
