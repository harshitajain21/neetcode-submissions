class Solution {
public:

    void backtr(vector<string> &result, string onecase, int &open, int &suml, int &sumr, int index, int n){


        if(index==2*n){
            result.push_back(onecase);
            return;
        }

        //option 1: add ( and suml++
        if(suml<n){
            onecase.push_back('(');
            suml++;
            open++;
            backtr(result, onecase, open, suml, sumr, index+1,n);

            //undo (inside the if, so it only runs if we actually added)
            onecase.pop_back();
            suml--;
            open--;
            }

        //option 2: close the existing )s
        if(open>0 && sumr<n){
            onecase.push_back(')');
            sumr++;
            open--;
            backtr(result,onecase, open, suml, sumr, index+1, n); 

            sumr--;
            open++;}
    };

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string onecase="";

        int open=0;
        int suml=0;
        int sumr=0;

        int index =0;

        backtr( result, onecase, open, suml, sumr, index,n);

        return result;
    }
};
