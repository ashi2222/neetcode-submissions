class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum =0 ;
        int start = 0;
        int maxi = 0;
        for(int i =0 ; i < gas.size() ; i++)
        {
            sum += gas[i];
            sum -= cost[i];
        }
        if(sum < 0)return -1;
        sum=0;
        for(int i =0 ; i < gas.size() ; i++)
        {
            sum += gas[i];
            sum -= cost[i];
            if(sum < 0){    
                sum = 0;
                start = i+1;
            }
        }
        return start;
    }
};
