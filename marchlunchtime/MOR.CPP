    /**
     * author: Bhavesh
    **/
    
    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    typedef string str;
    typedef pair<int, int> pi;
    typedef pair<ll,ll> pl;
    typedef pair<ld,ld> pd;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<ld> vd;
    typedef vector<str> vs;
    typedef vector<pi> vpi;
    typedef vector<pl> vpl;
    
    #define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
    #define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
    #define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
    #define fo(i,a) forn(i,0,ll(a))
    #define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
    #define ro(i,a) rforn(i,0,a)
    #define trav(a,x) for (auto& a: x)
    
    #define mp make_pair
    #define pb push_back
    #define eb emplace_back
    #define f first
    #define sec second
     
    void __print(int x) {cerr << x;}
    void __print(long x) {cerr << x;}
    void __print(long long x) {cerr << x;}
    void __print(unsigned x) {cerr << x;}
    void __print(unsigned long x) {cerr << x;}
    void __print(unsigned long long x) {cerr << x;}
    void __print(float x) {cerr << x;}
    void __print(double x) {cerr << x;}
    void __print(long double x) {cerr << x;}
    void __print(char x) {cerr << '\'' << x << '\'';}
    void __print(const char *x) {cerr << '\"' << x << '\"';}
    void __print(const string &x) {cerr << '\"' << x << '\"';}
    void __print(bool x) {cerr << (x ? "true" : "false");}
    template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
    #ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #else
    #define debug(x...)
    #endif
    const ll INF = 1e18;
    
    
    
    int main(){
        int t;
        cin>>t;
        while(t--){
          int n,m;
          cin>>n>>m;
          int  arr[n][m];
          vector<pair<int,pi>> all ;
          for (int i = 0; i < n; i++)
          {
              for (int j = 0; j < m; j++)
              {
                  cin>>arr[i][j];
                //   debug(arr[i][j]);
                  
              }
            //   if(i==1) debug(arr[1][0]);
              sort(arr[i],arr[i]+m);
            //   if(i==1) debug(arr[1][0]);
          }

            // debug("AFTER SORTING ");

            
        //  for (int i = 0; i < n; i++)
        //  {
        //      for (int j = 0; j < m; j++)
        //      {
        //          cout<<arr[i][j]<<" ";
        //      }
        //      cout<<"\n";
        //  }
         


             for (int i = 0; i < n; i++)
          {
              for (int j = 0; j < m; j++)
              {
                  all.pb({arr[i][j],{i,j}});
                  
              }
          }

         sort(all.begin(),all.end());
        vector<vi> marked(n, vi (m ,0));
        for (int i = 0; i < m; i++)
        {
            int id=all[i].sec.f;
            int jd=all[i].sec.sec;
            marked[id][jd]=1;

        }
        
        //     debug("AFTER MARKINGG ");

            
        //  for (int i = 0; i < n; i++)
        //  {
        //      for (int j = 0; j < m; j++)
        //      {
        //          cout<<marked[i][j]<<" ";
        //      }
        //      cout<<"\n";
        //  }

        int col[m]={0};
        


         debug(all,"\n");
        //  bool marked1=false;
        // cout<<"\n";
         for (int i = 0; i < m; i++)
         {
             bool marked1=false;
             for (int j = 0; j < n; j++)
             {  
                //  debug(j,i,col[i]);
                 if(marked[j][i]==1 and col[i]==0){
                     marked1=true;
                    //  debug("found");
                     col[i]=1;
                 }
                 else if( marked[j][i]==1 and col[i]==1){
                    
                     int st=i;st++;
                     while(st<m ){
                         int temp=arr[j][i];
                         
                        if(col[st]==0 and marked[j][st]!=1){
                        //  debug("foundnext",j,st,i);
                        arr[j][i]=arr[j][st];
                         arr[j][st]=temp;   
                             col[st]=1;
                             break;
                         }
                         st++;
                     }
                 }


             }
             
         }

         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++)
             {
                 cout<<arr[i][j]<<" ";
             }
             cout<<"\n";
         }
         
         



          
        }
    
      return 0;
      }