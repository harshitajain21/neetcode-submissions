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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //321 + 654 = 9 7 5 = 5-7-9
        //654 (4-5-6) + 67(7-6) = 7 2 1 = (1-2-7)
        //- 7+4=1..5+6+1=2..6+1=7

        //start from each head ..add -> carry = x/10.. res=x%10

        ListNode* dummy = new ListNode();
        ListNode* res=dummy;
        int sum=0;
        int carry=0;
        int v1=0;
        int v2=0;

        while(l1!=NULL || l2!=NULL || carry!=0 ){
            
            int v1 = (l1 != NULL) ? l1->val : 0;
            int v2 = (l2 != NULL) ? l2->val : 0;

            sum = v1+v2 + carry;
            res->next=new ListNode(sum%10);
            res=res->next;
            carry=sum/10;
            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }
        ListNode* final_head = dummy->next;
        delete dummy;
        return final_head;
    }
};
