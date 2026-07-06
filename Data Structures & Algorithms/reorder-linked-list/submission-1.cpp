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

/*0-1-2-3-4-5-6   n=7 (odd)
0-6-1-5-2-4-3

0-1-2-3-4-5-6-7    n=8(even)
0-7-1-6-2-5-3-4

head - tail
update new head and tail by head= head->next.. tail ->next = head. tail = tail ->next
then we want to get last prv and connect tail->next to it 
put how do we get last prv?
notice! 0 1 2 .... 6 5 4 3 and 0 1 2 3 ....7 6 5 4
so we can maybe reverse the second part? and then 2 pointers
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        
        if (!head || !head->next) return;


        //1. reverse second part .. find n
        ListNode* temp1 = head;
        int n=0;
        while(temp1!=NULL){
            n++;
            temp1=temp1->next;
        }

        //n/2 -1 changing

        ListNode* traversor = head;
        ListNode* prev = NULL;
        for(int i=0; i<n/2;i++){
            prev=traversor;
            traversor = traversor->next;
        }

        prev->next=NULL;
        
        ListNode* new_head = NULL;
        ListNode* temp = NULL;

        while(traversor!=NULL){
            temp = traversor->next;
            traversor->next=new_head;
            new_head=traversor;
            traversor= temp;
        }

        //2. now head and new_head linked list will be joined
        ListNode* tail=head;
        head=head->next;

        while(new_head!=NULL && head!=NULL){
            tail->next= new_head;
            tail=tail->next;
            new_head=new_head->next;

            tail->next=head;
            tail=tail->next;
            head=head->next;}

        while(new_head!=NULL){
            tail->next= new_head;
            tail=tail->next;
            new_head=new_head->next;
        }

        while(head!=NULL){
            tail->next=head;
            tail=tail->next;
            head=head->next;
        }

        tail->next = NULL;

    }
};
