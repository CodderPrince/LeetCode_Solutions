class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fnc(ans,n,0,0,"");
        return ans;
    }

    void fnc(vector<string>&ans, int n, int open, int closeB,string curr_str)
    {
        //base case
        if(curr_str.size()==n*2)
        {
            ans.push_back(curr_str);
            return;
        }

        if(open<n)
        {
            fnc(ans,n,open+1,closeB,curr_str+"(");
        }
        if(closeB<open)
        {
            fnc(ans,n,open,closeB+1,curr_str+")");
        }
    }
};
