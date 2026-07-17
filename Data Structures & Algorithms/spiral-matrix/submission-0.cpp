class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0 , down = m-1 , left =0 , right = n-1;
        vector<int>ans;
        while(up <= down && left <= right){
            for(int i = left ; i<= right ; i++)
            {
                ans.push_back(matrix[up][i]);
            }
            up++;
            if(up>down)break;
            // cout<<up<<" "<<down<<endl;
            for(int i = up ; i <= down ; i++)
            {
                // cout<<i<<" "<<right<<" "<<matrix[i][right]<<endl;
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(left > right)break;
            for(int i = right ; i>= left ; i--)
            {
                ans.push_back(matrix[down][i]);
            }
            down--;
            if(up>down)break;
            for(int i = down ; i >= up ; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
