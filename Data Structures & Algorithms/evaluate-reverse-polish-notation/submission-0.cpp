class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i : tokens)
        {
            if(i=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = a+b;
                st.push(c);
            }
            else if(i=="-")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b-a;
                st.push(c);
            }
            else if(i=="*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = a*b;
                st.push(c);
            }
            else if(i=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b/a;
                st.push(c);
            }
            else{
                int a = stoi(i);
                cout<<i<<" "<<a<<endl;
                st.push(a);
            }
        }
        return st.top();
    }
};
