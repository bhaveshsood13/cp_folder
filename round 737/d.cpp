int dp[1000][1000][2],c;
string a, b;
int fun(int i, int j, int rotated)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(a[i]==b[i])
            return 0;
        return 1;
    }
    if(dp[i][j][rotated]>=0)
        return dp[i][j][rotated];
    int ans = 100000;
    if(rotated==1)
    {
        return dp[i][j][1] = ((a[j]!=b[i]) + (a[i]!=b[j]) + fun(i+1, j-1, 1)); 
    }
    ans = min(ans, c + (a[i]!=b[j]) + (a[j]!=b[i])+ fun(i+1, j-1, 1));
    ans = min(ans, (a[i]!=b[i]) + fun(i+1, j, 0) );
    ans = min(ans, (a[j]!=b[j]) + fun(i, j-1, 0) );
    return dp[i][j][0] = ans;
}

int Solution::solve(string A, string B, int C) {
    int n = A.length();
    a = A;
    b = B;
    c = C;
    memset(dp, -1, sizeof dp);
    int ans = fun(0,n-1,0);
    return ans;
}
