class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //time taken to eat arr[i] pile = (arr[i]/k)+1
        //t1+t2+....<=h
        /*
        ok now first thing we know is that time to eat from ith pile → t= ceil(piles[i]/k)
now we want time to be minimum, so we want k to be big.
so if we take max k = max no. of bananas in a pile → and that k satisfies the time limit given, then min k lies in [1, max]
so in example 1: 1,2,3,4 → no, yes, yes, yes 
in example 2:    max is 25… now 1,2,3,……23,24,25→ no, no, no, …..no, no, yes
💡
so we can see there is monotonicity… the moment you see montonicity - you should think of binary search

okk so we can do this →
1. check if max element satisfies → but we dont need to do this. bcz h>=piles.length
2. now check if mid element satisfies. If not, then left = mid+1.
3. do it until you find where it satisfies*/

    int left=1;
    int right = *max_element(piles.begin(), piles.end());
    
    int k = right;

    while(left<=right){
        int mid=(left+right)/2;
        
        long long totaltime=0;
        for(int pile:piles){
            totaltime +=ceil(double(pile)/mid);
        }
        if(totaltime<=h){
            k=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }

    }
    return k;
    

    }
};
