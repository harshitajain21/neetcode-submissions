class MedianFinder {
public:

//1 3 5 6 7 | 10 | 11 14 15 19 20
//or
// 1 3 5 6 7 | 11 14 15 19 20 : here median is 7+11/2
//Use two heaps: a max heap for the smaller LEFT half and a min heap for the larger RIGHT half.
//Keep their sizes balanced, with the max heap having at most one extra element (so that if n is odd)

    priority_queue <int> left;

    priority_queue <int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // Put num into the correct half
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } 
        else {
            right.push(num);
        }

        // Rebalance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    
    double findMedian() {
        if(left.size()==right.size()){
            return((left.top()+right.top())/2.0);
        }
        else{
            return(left.top());
        }
    }
};
