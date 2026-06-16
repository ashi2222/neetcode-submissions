class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ,m =nums2.size();
        int left = (n+m+1)/2;
        // 7 -> 4,3 
        if(m<n)return findMedianSortedArrays(nums2,nums1);

        int low = 0;
        int high = n;

        while(low <= high)
        {
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;

            int i1 = INT_MIN , i2 = INT_MIN , j1 = INT_MAX , j2 = INT_MAX;

            if(mid1>0)i1=nums1[mid1-1];
            if(mid2>0)i2=nums2[mid2-1];
            if(mid1<n)j1=nums1[mid1];
            if(mid2<m)j2=nums2[mid2]; 

            int a = max(i1,i2) ;
            int b = min(j1,j2);
            if(j1 >= i2 && j2 >= i1)
            {
                if((n+m)%2 == 0)return (double)(a+b)/2;
                else return (double)a;
            }
            else if(i1 >= j2)
            {
                high = mid1-1;
            }
            else{
                low = mid1+1;
            }
        }
        return 0;
    }
};