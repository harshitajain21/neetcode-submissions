/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //3-7-4-5-NULL

        //now, see when you create a copy suppose 3's random points to 4.. but we haven't created 4 yet in the copy..so what to do.. basically ignore randoms and just make a normal copy with next. now use hashmap to insert randoms  

        unordered_map <Node* , Node*> oldtocopy;
        oldtocopy[NULL]=NULL;

        Node* temp=head;
        while(temp!=NULL){
            Node* copy = new Node(temp->val);
            oldtocopy[temp]=copy;
            temp=temp->next;
        }

        Node* temp2=head;        
        while(temp2!=NULL){
            Node* copy = oldtocopy[temp2];
            copy->next = oldtocopy[temp2->next];
            copy->random = oldtocopy[temp2->random];
            temp2 = temp2->next;
        }

        return oldtocopy[head];

    }
};
