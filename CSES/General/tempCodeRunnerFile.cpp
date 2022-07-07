
ll dif=INT_MAX;
 void recurse (ll sum2,vi &v,int i , ll csum){
     if(i>v.size()) return;
     if(csum>sum2) return;
     if(abs(sum2-csum)<dif){
            dif=abs(sum2-csum);
     }
     recurse(sum2,v,i+1,csum+v[i]);
     recurse(sum2,v,i+1,csum);

 }
 
int main(){
    int n;
    cin>>n;
    vi v(n);
    ll sum=0;
    for (int i = 0; i < n; i++)
    {   
        cin>>v[i];
        sum+=v[i];
    }
    recurse(sum/2,v,0,0);
    ll half=sum/2;
    ll s1=abs(half-dif);
    ll s2=sum-s1;
    cout<<(abs(s2-s1));
  return 0;
  }