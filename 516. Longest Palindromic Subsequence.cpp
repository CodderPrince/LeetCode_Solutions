class Solution {
public:
int t[1001][1001];
int lps(string &s, int i, int j)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return 1;
    }
    if(t[i][j] != -1)
    {
        return t[i][j];
    }
    if(s[i]==s[j])
    {
        return t[i][j] =  2 + lps(s,i+1,j-1);
    }
    else
    {
        return t[i][j]= max(lps(s,i+1,j),lps(s,i,j-1));
    }
}
    int longestPalindromeSubseq(string s) {
        memset(t,-1,sizeof(t));
        return lps(s,0,s.length());
    }
};
