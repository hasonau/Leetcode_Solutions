class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=0;
        int l2=0;
        vector<int> combinedArray;

        while(l1<nums1.size() && l2<nums2.size()){
            if(nums1[l1]<nums2[l2]) {
                combinedArray.push_back(nums1[l1]);
                l1+=1;
            }
            else{
                combinedArray.push_back(nums2[l2]);
                l2+=1;
            }
        }
        if(l1<nums1.size()){
            while(l1<nums1.size()){
                combinedArray.push_back(nums1[l1]);
                l1+=1;
            }
        }
        if(l2<nums2.size()){
            while(l2<nums2.size()){
                combinedArray.push_back(nums2[l2]);
                l2+=1;
            }
        }
        int mid = combinedArray.size()/2;
        return combinedArray.size()%2 == 0 ? (combinedArray[mid]+combinedArray[mid-1])/2.0f : combinedArray[mid];   
    }
};