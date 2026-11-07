class Solution {
public:
//so basically check all possible lenghts of substring
//
    string longestPalindrome(string s) {

        //1. Initialize a dp (2x2) for indices 
        //dp[i][j]= true if s[i...j] is palindrome and false otherwise
        //note: dp[i][j], i.e, s[i...j] is palindrome if s[i]=s[j] and [i+1....j-1] or dp[i+1][j-1] is palindrome 
        int n=s.size(); 
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        //2. Initialise variables - start (for start of longest palindromic substring) and max_len (for length of longest palindromic substring)
        int start=0;
        int max_len = 1;

        //3. edge cases: length 1 -> always palindrome
        for(int i=0;i<s.size();i++){
            dp[i][i]=true;}

        //5. consider lengths from 2 to n
        for(int length=2;length<=s.size();length++){
            //generate every possible substring of length l
            for(int i=0; i+length<=s.size();i++){
                int j= i+length -1;

                //edge case
                if(length ==2 && s[i]==s[j]){
                    dp[i][j]=true;
                    if(length>max_len){
                        max_len=length;
                        start=i;
                    }
                }
                //check palindrome
                else if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(length>max_len){
                        max_len=length;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};
                       