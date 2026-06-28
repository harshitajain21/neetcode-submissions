class Solution {
public:
    int maxArea(vector<int>& heights) {
        //max distance and biggest 2nd height
        //lets take 1 and 6..biggest distance..store
        //now move the smaller one - 7 to 6..store
        //again move the smaller one - 7 to 3..store 

        int n = heights.size();

        int left =0;
        int right = n-1;

        int area = (right-left)*min(heights[left],heights[right]);

        int maxarea=0;

        while(left<right){
            area = (right-left)*min(heights[left],heights[right]);
            if (heights[left]>heights[right]){
                right--;
            }
            else{
                left++;
            }
            if(area>maxarea){
                maxarea=area;
            }
}
    return maxarea;
    }
};
