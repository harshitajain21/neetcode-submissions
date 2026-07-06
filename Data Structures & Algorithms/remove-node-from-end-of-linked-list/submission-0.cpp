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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        /*
        1-2-3-4-5.. n=2
        1-2-3-5
        REMOVE 3-4 AND 4-5.. MAKE 3-5

        5...N=1
        IF SINGLE NODE OR EMPTY: RETURN EMPTY LIST I.E LISTNODE* HEAD=NULL;

        1-2-3....N=1   
        1-2 
        REMOVE 2-3 .. MAKE 2-NULL
        
        1-2-3...N=3 (n=size)
        2-3
        REMOVE 1-2 ...MAKE 2 HEAD*/

        //1. get number of nodes
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

        int position = size - n +1;

        if(head==NULL || head->next==NULL){
            head=NULL;
            return head;
        }

        else if(n==1){
            ListNode* traversor=head;
            while(traversor->next->next!=NULL){
                traversor=traversor->next;
            }
            ListNode* temp=traversor->next;
            traversor->next=NULL;
            delete temp;

            return head;
        }

        else if(n==size){
            ListNode* new_head=head->next;
            delete head;

            return new_head;
        }
        
        else{
            ListNode* traversor = head;
            ListNode* prev=NULL;
            for(int i=1; i<position;i++){
                prev=traversor;
                traversor=traversor->next;
            }
            prev->next = traversor->next;
            delete traversor;

            return head;
        }


    }
};
