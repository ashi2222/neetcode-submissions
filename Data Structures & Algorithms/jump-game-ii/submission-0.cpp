class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();
        vector<int>visited(n,INT_MAX);
        visited[n-1]=0;
        int goal = n-1;
        for(int i = n-2 ; i>=0 ; i--)
        {
            int j = i + nums[i];
            int k = i+1;
            // cout<<j<<" bhar "<<k<<endl;
            if(j >= goal){
                visited[i]=1;
                continue;
            }
            while(k <= j){
                // cout<<visited[k]<<" mid "<<visited[i]<<endl;
                if(visited[k]!=INT_MAX && visited[i] > visited[k] + 1)
                {
                    // cout<<k<<" "<<visited[k]<<endl;
                    visited[i] = 1 + visited[k];
                }
                k++;
            }
        }
        return visited[0];
    }
};
