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

        ListNode* temp=head;

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
        }


    }
};
