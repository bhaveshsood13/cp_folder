for (int i = 0; i < n; i++)
        {
            cout<<i<<"\n";
            for(auto x : adj[i]){
                cout<<" "<<x;
            }
            cout<<"\n";
        }