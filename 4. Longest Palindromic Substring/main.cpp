class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        int len = nums1.size()-1;
        if(len%2==0){return (double)nums1[len/2];}
        else{return (nums1[len/2] + nums1[len/2+1])/2.0;}

    }
};