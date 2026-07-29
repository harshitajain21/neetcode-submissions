class Solution {
public:
    //its simple binary search
    //first find row where element lies by binary search..row[0]<= target and row[last element]>=target
    //now do binary search in the row to find the target
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                
        //1. find the row
        int left=0;
        int right=matrix.size()-1;

        int col= matrix[0].size();

        int mid=0;

        while(left<=right){
            mid=(left+right)/2;
            if(matrix[mid][0]<=target && matrix[mid][col-1]>=target){
                if(matrix[mid][0]==target || matrix[mid][col-1]==target){
                    return true;
                }
                else{
                    break;
                }}
            else if(matrix[mid][0]>target){
                right=mid-1;
            }
            else if(matrix[mid][col-1]<target){
                left=mid+1;
            }
            }
        
        //2. find the element in the row.. so here mid is the row
        int l=0;
        int r=col-1;
        while(l<=r){
            int midc=(l+r)/2;
            if(matrix[mid][midc]<target){
                l=midc+1;
            }
            else if(matrix[mid][midc]>target){
                r=midc-1;
            }
            else{
                return true;
            }
        }
        return false; 
    }};

