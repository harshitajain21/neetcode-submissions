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

    //1-2-3-4-5-6
    /*

    1. at each point, check if there are k nodes.. if not then just return new_head 
    
    2. for the first k elements
        while(k!=0):
            reverse
    so now new_head is 3 and 3->2->1 ..and temp=4 and 4-5-6

    3. let head_og be temp
    check if there are k nodes..if there are, 
      while(k!=0)
         reverse
    now we have to point 1 to new_head2 .. so head -> next = new head2

    so in general its head_og->next=newhead
    */
public:

    //1-2-3-4-5-6-7-8, k=3
    //3-2-1-6-5-4-7-8
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* main_traversor = head;
        // Head of the final answer
        ListNode* new_head = NULL;

        // Tail of the previous reversed group
        ListNode* prev_tail = NULL;


        while(main_traversor!=NULL){
                    
        //1. check if k nodes after head_og
        ListNode* t=main_traversor;
        int c=0;
        while(t!=NULL&& c<k){
            t=t->next;
            c++;
        }
        if (c!=k){
            //connect remaining to list
            if (prev_tail != NULL)
                    prev_tail->next = main_traversor;
            return new_head;
        }

            // 2. Save original head
            // After reversal, this becomes the tail
            ListNode* head_og = main_traversor;

            //3. reverse
            ListNode* grp_new_head=NULL;
            ListNode* tr = main_traversor;
            ListNode* temp=NULL;

            int a=k;

            while(tr!=NULL && a!=0){
                temp=tr->next;
                tr->next=grp_new_head;
                grp_new_head=tr;
                tr=temp;
                a--;
            }

            //4. connect
            if (new_head == NULL) { //first group
                new_head = grp_new_head;
            }
            else {
                prev_tail->next = grp_new_head;
            }

            //5. head_og is now the tail of this group
            prev_tail = head_og;

            //6. Move to next group
            main_traversor = tr;
        }  

        return new_head;
    }
};
