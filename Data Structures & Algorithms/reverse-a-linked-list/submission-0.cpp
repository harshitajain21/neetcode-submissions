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
    ListNode* reverseList(ListNode* head) {

        //0->1->2->3->NULL
        //3->2->1->0->NULL

        /*
        NEW_HEAD = NULL
        TRAVERSOR = HEAD
        TEMP = NULL*/

        //0->NULL...... 1->2->3->NULL
        //REMOVE 0->1 ...PUT 0->NULL 
            /*TEMP = TRAVERSOR ->NEXT
            TRAVERSOR -> NEXT = NEW_HEAD 
            NEW_HEAD= TRAVERSOR
            TRAVERSOR=TEMP*/

        //1->0->NULL....... 2->3->NULL
        //REMOVE 1->2...PUT 1->0
            /*TEMP=TRAVERSOR->NEXT 
            TRAVERSOR->NEXT = NEW_HEAD
            NEW_HEAD = TRAVERSOR
            TRAVERSOR = TEMP*/

        //2->1->0->NULL.... 3->NULL
        //REMOVE 2->3 ... PUT 2->1

        //3->2->1->0->NULL
        //PUT 3->2

        ListNode* new_head = NULL;
        ListNode* traversor = head;
        ListNode* temp = NULL;

        while(traversor!=NULL){
            temp = traversor->next;
            traversor->next=new_head;
            new_head=traversor;
            traversor= temp;
        }

        
        return new_head;
    }
};
