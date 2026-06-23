class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    // int count = 0;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        this->k = k;
        for(int i = 0 ; i < n ; i++)
        {
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i] >= pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        // cout<<"count "<<(++count)<<endl;
        if(pq.size() < k){
            pq.push(val);
            return pq.top();
        }
        else{
            if( val >= pq.top()){
                // cout<<pq.top()<<endl;
                pq.pop();
                pq.push(val);
            }
            auto it = pq.top();
            // cout<<"ans"<<it<<endl;
            return it;
        }
        return 0;
    }
};
