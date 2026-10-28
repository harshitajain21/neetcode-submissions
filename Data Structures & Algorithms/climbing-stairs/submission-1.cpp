class Solution {
public:

//let p[i] = total no. of ways to reach i
//p[i] = p[i-1]+p[i-2]
//we want p(N)
    int climbStairs(int n) {
        
        vector<int> p(n+1);

        p[1]=1;
        //edge case: if n =1 , we cant access n=2
        if(n==1) return p[1];
        p[2]=2;

        for(int i=3;i<n+1;i++){
            p[i] = p[i - 1] + p[i - 2];
        }

        return p[n];
    }
};
