#include <bits/stdc++.h>
using namespace std;

bool ok(int mid, vector<int> v, string s, string p)
{
    vector<int> v1;
    //cout<<mid<<"!";
    cout<<'\n';
    for (int i = 0; i <= mid; i++)
    {
        v1.push_back(v[i]);
       cout<<v1[i]<<" ";
    }
   cout<<'\n';
    sort(v1.begin(), v1.end());
    string s1="";
    int k=0;
    
    for(int i=1;i<=s.size();i++){
        if(i==v1[k]){
            k++;
            continue;
        }
        else{
            s1+=s[i-1];
            // cout<<" !! s1 "<<s1<<" i "<< i <<" v[k] "<<v[k];
        }
    }
    // cout<<"\nS1 "<<s1;
    int j,i;
    for( i=0,j=0; i<p.size() and j<s1.size();j++){
        if(p[i] == s1[j]){
            i++;
        }
    }
    cout<<" i " <<i;
    if(i == p.size()){
        return true;
    }
    else return false;

}
int main()
{
    string s, p;
    cin >> s;
    cin >> p;
    vector<int> v(s.size());
    for (int i = 0; i < s.size(); i++)
        cin >> v[i];

    int start = 0, end = s.size()-1;
    int mid;
    int ans=0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (ok(mid, v,s,p))
        {
            start = mid+1;
            ans = mid;
            cout<<"here";
        }

        else
        {
            end = mid - 1;
        }
    }
    cout<<"\n"<<ans+1<<'\n';
    return 0;
}