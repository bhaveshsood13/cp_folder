#include <bits/stdc++.h>
using namespace std;

void allPossibleSubset (int arr[], int n, int k, map < int, vector < int >> &m)
{
  int count = pow (2, n);
  vector < int >v;
  // The outer for loop will run 2^n times to print all subset .
  // Here variable i will act as a binary counter
  for (int i = 1; i < count; i++)
    {
      int sum = 0;
      // The inner for loop will run n times , As the maximum number of elements a set can have is n
      // This loop will generate a subset
      for (int j = 0; j < n; j++)
	{
	  // This if condition will check if jth bit in binary representation of  i  is set or not
	  // if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
	  // otherwise exclude arr[j]
	  if ((i & (1 << j)) > 0)
	    {
	      cout << arr[j + k] << " ";
	      v.push_back (arr[j + k]);
	      sum += arr[j + k];
	    }
	}
      cout << "!" << sum << "\n";
      m[sum] = v;
      v.clear ();
    }
}

void pair_sum(map < int, vector < int >> &m_l, map < int, vector < int >> &m_r, int target){
   
   int flag =0;
   auto i = m_l.begin();
   auto j = m_r.end();
   j--;
    while( i != m_l.end() and j != m_r.begin() ){
        

        int sum = i->first + j->first ;
        // while(j!=m_r.end()){
        // cout<<"Khushi"<<j->first;
        // j--;
        // }
        if(sum == target){
            
            cout<<"Subset having sum = "<<target<<" : ";
            for(auto itr : i->second){
                cout<<itr<<" ";
            }
            for(auto itr : j->second){
                cout<<itr<<" ";
            }
            cout<<'\n';
            flag = 1;
            break;
        }
        else if(sum > target){
            j--;
            cout<<" j "<<j->first<<" target "<< target << m_r.rend()->first ;
        }
        else{
            i++;
        }
    }
    if(flag == 0){
        cout<<"Subset sum to target not found!"<<'\n';
    }
}

int main ()
{
  int n, n1,target;
  cout << "Enter size of the set\n";
  cin >> n;

  int arr[n];
  cout << "Enter Elements of the set\n";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
    cin>>target;
  if (n % 2 != 0)
    n1 = (n / 2) + 1;
  else
    n1 = n / 2;
  //sum = key, subset = value
  map < int, vector < int >>m_r;
  map < int, vector < int >>m_l;
  allPossibleSubset (arr, n1, 0, m_l);	//first half
  allPossibleSubset (arr, n1, (n / 2), m_r);	// 2nd half
  cout<<"*";
  
  if(m_r.count(target)){
      cout<<"Subset having sum = "<<target<<" : ";
      for(auto i : m_r[target]){
          cout<<i<<" ";
      }
      cout<<'\n';
  }
  else if(m_l.count(target)){
      cout<<"Subset having sum = "<<target<<" : ";
      for(auto i : m_l[target]){
          cout<<i<<" ";
      }
      cout<<'\n';
  }
  else{
      pair_sum(m_l, m_r, target);
      cout<<"came here!";
  }
// for(auto i : m_r){
//     cout<<i.first<<" ";
//     for(auto itr : i.second)
//     {cout<<itr<<" ";}
//     cout<<endl;
// }
  return 0;
}

