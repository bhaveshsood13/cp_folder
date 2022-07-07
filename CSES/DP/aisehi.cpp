for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if(j>w[i]){
            dp[i][j]= max(dp[i-1][j-w[i]] + v[i],dp[i-1][j-1]);
        }
        else
        {
            dp[i][j]=dp[i-1][j-1];
        }
        
    }
    
}
