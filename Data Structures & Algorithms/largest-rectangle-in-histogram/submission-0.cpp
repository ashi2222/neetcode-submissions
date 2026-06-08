class Solution {
public:
    void solve(vector<int>&a , vector<int>&h , int n)
    {
        stack<int>st;
        for(int i = n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }
            if(!st.empty())a[i]=st.top();
            else {
                a[i] = n;
            }
            st.push(i);
        }
    }

    void solve1(vector<int>&b , vector<int>&h , int n)
    {
        stack<int>st;
        for(int i = 0; i < n ; i++)
        {
            while(!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                b[i]=st.top();
            }
            else{
                b[i]=-1;
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        // thoda dhyan se dekhoge toh pta chlega mujhe dono side se necst smaller elemenet btana h
        vector<int>a(n),b(n);
        solve(a,h,n);
        solve1(b,h,n);

        int ans =0;
        for(int i =0 ; i < n ; i++)
        {
            cout<<b[i]<<" "<<a[i]<<" "<<h[i]<<endl;
            int area = (a[i]-b[i]-1)*(h[i]);
            ans = max(ans,area);
        }
        return ans;
    }
};
