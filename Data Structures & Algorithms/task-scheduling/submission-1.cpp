class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
AAABBC .. k=3
A B C null A B null null A : 9 (6+ 3)


AAABBC .. k = 2
A B C A B null A : 7 (4+3)

AAABBC .. k=4
A B C null null A B null null null A : 11 (8+3)

AAABBBC.. k=3
A B C null A B null null A B : 10

->max freq + (max freq-1 )*k
-> but if the 2nd max = max then keep adding 1 until theres a smaller max

1. get every char's freq and put in max heap
2. a= max heap.pop .. A is one cycle
3. now while (k!=0)
- pop from max heap and put in cycle 
- if none remains put null
4. continue till frequency of each finished
*/

    int fr[26]={0};

    for(auto x:tasks){
        fr[x-'A']++;
    }

    priority_queue <pair<int,char>> maxheap;

    for(int i=0;i<26;i++){
        maxheap.push({fr[i],char('A'+i)});
    }

    int mf=maxheap.top().first;
    maxheap.pop();

    int res = mf + (mf-1)*n;

    while(!maxheap.empty() && maxheap.top().first==mf){
        res++;
        maxheap.pop();
    }

    return max(res, int(tasks.size()));

    }
};
