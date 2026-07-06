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
    bool hasCycle(ListNode* head) {

        //1-2-3-4-1-2-1-3-4
        //hashset but it contains of a node
        //a node may hv same value but it always has a diff next

        /*ListNode* temp=head;

        unordered_set <ListNode*> seen;

        while(!seen.count(temp) && temp!=NULL){
            seen.insert(temp);
            temp=temp->next;
        }

        if(temp!=NULL){
            return true;
        }
        else{
            return false;
        }*/

        //slow(1x) and fast(2x) pointers.. if loop is there, then they will meet at some point. otherwise they will never meet.

        //1-2-3-4-1-2-1-3-4.. loop from 4 to closest 3
        //slow = 1..2..3..4..1..2..1..3..4
        //fast = 1..3..1..1..4..4..4..4..4

        //1-2-3-4-1-2-1-3-4.. loop from 4 to closest 1
        //slow = 1..2..3..4..1..2..1
        //fast = 1..3..1..1..4..3..1

        //no loop
        //slow = 1..2..3..4..1
        //fast = 1..3..1..1..4..null

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=NULL && fast->next!=NULL && fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }

        return false;

    }
};
