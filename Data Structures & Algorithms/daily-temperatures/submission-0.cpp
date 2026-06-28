class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
//day 0, temp 30 → nobody waiting, push 0
//day 1, temp 38 → 38 is warmer than 30, pop 0 → result[0] = 1-0 = 1->  check top day ..push 1 (day 1)
//day 2, temp 30 → 30 is colder than 38. push 2 (day 2)
//now day 1 and day 2 is unprocessed
//day 3, temp 36 -> 36 is warmer than 30, pop 2 -> result[2]=3-2 = 1 -> push 3 (day 3)
//now day 1 and day 3 is unprocessed
//day 4, temp 35 -> 35 is colder than 36. push 4 (day 4)
//day 5, temp 40 -> 40 is warmer than 35, pop 4 -> result[4] = 5-4 = 1 
//-> ..check day 3: 40 is warmer than 36: pop 3; result[4]=5-3  
//-> ..check day 1 : 40 is warmer than 38 : pop 1; result[1]= 5-1 =4;now push 5(day 5)
//now day 5 unprocessed
//day 6, temp 28 -> 28 is colder than 40, push 28
//now everything done.. so now pop each from stack and put its result as 0

//algorithm:When you arrive at day i, pop everyone from the stack who is colder than you
//1. start..if stack empty: push day number
//2. now case 1: if temp > stack.top -> result(stack.top) = day number - stack.top().. pop stack ..
        //- now check again until u get temp<stack.top
//3. case 2: if temp<stack.top -> push day number
//4. finally after all temperatures seen.. pop each from stack and put its result as 0

stack <int> days_np; //days not processed
vector <int> result(temperatures.size());

for(int day=0; day<temperatures.size();day++){
    if(days_np.empty()){
        days_np.push(day);
    }
    else{
        while(!days_np.empty() && temperatures[day]>temperatures[days_np.top()]){
            result[days_np.top()]= day - days_np.top();
            days_np.pop();
        }
        days_np.push(day);
    }
}
while(!days_np.empty()){
    result[days_np.top()]=0;
    days_np.pop();
}
return result;

    }
        };
