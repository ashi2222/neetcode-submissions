class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        int i = 0 , j = 0 , n = nums1.size() , m = nums2.size();
        while(i<n && j < m)
        {
            if(nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i<n)
        {
            merged.push_back(nums1[i++]);
        }
        while(j<m)
        {
            merged.push_back(nums2[j++]);
        }
        int odd = (n+m)%2;
        int k = (n+m)/2;
        if(!odd){
            double ans = (double)((double)(merged[k]) + (double)(merged[k-1]))/2;
            return ans;
        }
        return merged[k];
    }
};
