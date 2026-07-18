class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1.00000;
        if(n<0)return (1.00000/myPow(x,-n));
        double ans = myPow(x,n/2)*myPow(x,n/2);
        if(n%2==0){
            // cout<<n<<" "<<ans<<endl;
            return ans;
        }
        // cout<<n<<" "<<x*ans<<endl;
        return x*ans;
    }
};
