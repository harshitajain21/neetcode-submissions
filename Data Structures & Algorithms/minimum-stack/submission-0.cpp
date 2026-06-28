class MinStack {

    //we can do like when making the stack that is while pushing we can keep updating minimum
    //now we need to keep track of 2nd min while popping also..
    //so we can do is make another stack s.t each position stores what the minimum was at that point in time.

    //1,2,3,3,2,0
    //min_st:1,1,1,1,1,0

    //5,3,7,1
    //min_st: 5,3,3,1

    stack <int> st;
    stack <int> min_st;

public:


    MinStack() {
}
    

    void push(int val) {
        st.push(val);
        if(min_st.empty()){
            min_st.push(val);
        }
        else if(!min_st.empty()){
            if(val<min_st.top()){
                min_st.push(val);
            }
            else{
                min_st.push(min_st.top());
            }
        }
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();        
    }
    
    int getMin() {
        return min_st.top();
    }
};
