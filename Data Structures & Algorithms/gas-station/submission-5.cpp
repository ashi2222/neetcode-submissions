class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit =0 ;
        int sum = 0;
        int start = 0;
        for(int i =0 ; i < gas.size() ; i++)
        {
            sum += (gas[i] - cost[i]);
            if(sum < 0)
            {
                start = i+1;
                deficit += sum;
                sum = 0;
            }
        }
        if(sum + deficit < 0)return -1;
        return start;
    }
};