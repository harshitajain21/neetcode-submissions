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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        /*
        2-3-5 + 0-1-3-4

        0-1-2-3-3--4-5

        1. take head 1 and head 2 : compare, find the smallest head.. 
        - lets say here head 2.. so smallest_head= head 2 and head 2= head 2->next..t_head= head
        - i.e head 1 =2 and head 2=1
        2. again compare head 1 and head 2: find smallest head.. smallest_head= head 2 and head 2= head 2->next
        - now point t_head to smallest head... then t_head = smallest head
        - i.e head 1 =2 and head 2=3 .. and 0-1
        3. repeat
        - head 1= 3 and head 2 =3....and 0-1-2
        4. repeat
        - head 1 = 3 and head 2 = 
        */

        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode dummy(0);
        ListNode* final=&dummy;
        
        while(head1!=NULL && head2!=NULL){
            if (head1->val<head2->val){
                final->next=head1;
                head1=head1->next;
                final=final->next;

            }
            else{
                final->next=head2;
                head2=head2->next;
                final=final->next;

        }}

        while(head1!=NULL){
            final->next=head1;
            head1=head1->next;
            final=final->next;
        }
        while(head2!=NULL){
            final->next=head2;
            head2=head2->next;
            final=final->next;
        }
        
        return dummy.next; //real head is the one after dummy
    }
};
