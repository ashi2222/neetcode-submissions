class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>visited(n+1 , 0);
        visited[n-1]=1;
        for(int i = n-2 ; i>= 0 ;i--)
        {  
            int j = i + nums[i];
            int k = i+1;
            // cout<<i<<" "<<j<<" "<<k<<endl;
            while(k <= j && visited[k]==0){
                k++;
            }
            if(k<=j){
                // cout<<i<<endl;
                visited[i]=1;
            }
            // cout<<visited[i]<<endl;
        }
        return visited[0];
    }
};
