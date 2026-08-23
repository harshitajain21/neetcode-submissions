class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1,2,5,6,7  //1,4,6,8,8,8  --> 1,1,2,4,5,6,6,7,8,8,8 --> 6
// Total number of elements = m + n
// If odd, median is at index (m+n)/2
// If even, median = average of elements at indices (m+n)/2 - 1 and (m+n)/2

//now we want to find median without merging
//so suppose lets take merged array .. there are (m+n)/2 elements on left and right

//so similary lets cut array 1 at some point i.. array 2 will be cut at (m+n)/2-i
//now imagine both of them as left part of merged array
//check necessary conditions for them to be imagined as sorted merged array
//if conditions fail, move cut accordingly

if (nums1.size() > nums2.size()) {
    return findMedianSortedArrays(nums2, nums1);
}

        vector<int>& A = nums1;
        vector<int>& B = nums2;

        int m=A.size();
        int n=B.size();
        int half = (m+n + 1) / 2;

        int l = 0;
        int r = m;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m+n) % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;



    }
};
