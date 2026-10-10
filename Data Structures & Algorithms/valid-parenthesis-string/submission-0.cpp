class Solution {
public:
    bool checkValidString(string s) {
        //((**)*) - valid as it can be (()) or (( ))() or (((*)))
        //put ( in stack until they are resolved
        //put * in another stack

        //s1: ((,  s2: **, so we reached ) , now as s1 is not empty, use it to resolve a ( and pop,  now s1: (, s2: ***.. now we reachd ) , now as s1 is not empty, use it to resolve a ( and pop.. now end of string we have s1: nill, s2: ***.. 

        //now suppose we had ) but s1 is empty -> so use * 
        
        //now suppose we didnt hv enough ) so we would hv taken * from s2 as long as they come after ( 

        //now if s1 is not empty in the end after all this - false


        /*
        - s1: stack storing the indices of (
        - s2: stack storing the indices of *

        1. Iterate through the string from left to right.
        2. For each character:
        - If it is (, push its index onto s1.
        - If it is *, push its index onto s2.
        - If it is ):
            - If s1 is not empty, pop from s1 to match the ).
            - Otherwise, if s2 is not empty, pop from s2 and use that * as (.
            - Otherwise, return false, because this ) cannot be matched.
        3. After processing the entire string, some unmatched ( may remain in s1.
        - While s1 is not empty:
            - If s2 is empty, return false.
            - If the top index of s2 is less than the top index of s1, return false. The * occurs before the (, so it cannot close it.
            - Otherwise, pop from both stacks. Use the * as ) to match the (.
        4. If s1 is empty after all these steps, return true.

        */

        stack<int> s1; // indices of '('
        stack<int> s2; // indices of '*'

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                s1.push(i);
            }
            else if (s[i] == '*') {
                s2.push(i);
            }
            else { // s[i] == ')'
                if (!s1.empty()) {
                    s1.pop();
                }
                else if (!s2.empty()) {
                    s2.pop(); // use '*' as '('
                }
                else {
                    return false;
                }
            }
        }

        // Resolve remaining '(' using '*' occurring after them
        while (!s1.empty()) {
            if (s2.empty()) {
                return false;
            }

            if (s2.top() < s1.top()) {
                return false;
            }

            s1.pop();
            s2.pop();
        }

        return true;
    }
};
