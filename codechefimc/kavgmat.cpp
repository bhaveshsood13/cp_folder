#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int mat[n][m];
        long long aux[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                aux[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                aux[i][j] += aux[i][j - 1];
            }
        }
        // for(int i =0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<aux[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                aux[i][j] += aux[i - 1][j];
            }
        }
        //   for(int i =0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<aux[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        int li, lj, ri, rj;
        li = lj = 0;
        rj = ri = 0;
        long long submatrixsum;
        // submatrixsum=aux[ri][rj]-aux[ri][lj-1]-aux[li-1][rj]+aux[li-1][lj-1];
        // cout<<submatrixsum;
        long long count = 0;
        long long totalpoints = 0;
        for (int l = 0; l < n; l++)
        {
            for (int i = 0; i < n-l; i++)
            {   
                int s=0,e=m-1-l;
                int mid=(s+e)/2;
                int idx=-1,flag=0;
                while(s<=e)
                {
                    // if (i + l >= n or j + l >= m)
                    //     continue;
                    mid=(s+e)/2;
                    li = i;
                    lj = mid;
                    ri = i + l;
                    rj = mid + l;
                    if (lj - 1 >= 0 and li - 1 >= 0)
                        submatrixsum = aux[ri][rj] - aux[ri][lj - 1] - aux[li - 1][rj] + aux[li - 1][lj - 1];
                    else if (lj - 1 >= 0)
                        submatrixsum = aux[ri][rj] - aux[ri][lj - 1];
                    else if (li - 1 >= 0)
                        submatrixsum = aux[ri][rj] - aux[li - 1][rj];
                    else
                        submatrixsum = aux[ri][rj];
                    totalpoints = (l + 1) * (l + 1);
                    submatrixsum /= totalpoints;
                    if (submatrixsum >= k)
                    {
                      
                         e = mid - 1;
                        idx = mid;
                        //  cout<<"i "<<i<<" j "<<idx<<" l"<<l<<"\n";
                        // cout<<"subsum "<<submatrixsum <<"mid "<<mid <<"\n";
                        flag = 1;
                        // cout<<"i"<<i<<"j"<<j<<"l"<<l<<"sum"<<submatrixsum<<"\n";
                    }
                    else
                    {
                        s = mid + 1;
                    }
                }
                
                if (flag == 1)
                {   
                    // cout<<"final i "<<i<<" j "<<idx<<" l"<<l<<"\n";
                    count += (m - idx - l );
                }

            }
        }
        // long long count = 0;
        long long subsum = 0;
        // for (int l = 1; l <= n; l++)
        // {

        //     for (int i = 0; i <= n - l; i++)
        //     {

        //         int lo = 0, hi = m - l;
        //         int mid;
        //         mid = (hi + lo) / 2;
        //         int idx=-1, flag = 0;

        //         while (lo <= hi)
        //         {    
                    
        //              li = i;
        //             lj = mid;
        //             ri = i + l-1;
        //             rj = mid+ l-1;

        //             mid = (hi + lo) / 2;
        //             if (lj - 1 >= 0 and li - 1 >= 0)
        //                 submatrixsum = aux[ri][rj] - aux[ri][lj - 1] - aux[li - 1][rj] + aux[li - 1][lj - 1];
        //             else if (lj - 1 >= 0)
        //                 submatrixsum = aux[ri][rj] - aux[ri][lj - 1];
        //             else if (li - 1 >= 0)
        //                 submatrixsum = aux[ri][rj] - aux[li - 1][rj];
        //             else
        //                 submatrixsum = aux[ri][rj];
        //             submatrixsum=(submatrixsum / (l * l));
        //             if ( submatrixsum >= k)
        //             {
        //                 hi = mid - 1;
        //                 idx = mid;
        //                 cout<<"i "<<i<<" j "<<idx<<" l"<<l<<"\n";
        //                 cout<<"subsum "<<submatrixsum <<" mid "<<mid <<"\n";
        //                 flag = 1;
        //             }
        //             else
        //             {
        //                 lo = mid + 1;
        //             }
        //         }
                
        //         if (flag == 1)
        //         {   cout<<"final i "<<i<<" j "<<idx<<" l"<<l<<"\n";
        //             count += (m - idx - l +1);
        //         }
        //     }
        // }
        cout << count << endl;
    }

    return 0;
}
