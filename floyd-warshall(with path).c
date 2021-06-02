        ll n;
        cin>>n;
        ll a[n+1][n+1];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==-1)
                {
                    a[i][j]=INT_MAX;
                }
            }
        }
        ll next[n+1][n+1];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                next[i][j]=j;
            }
        }
        for (ll k = 0; k < n; k++)
        {
			for (ll i = 0; i < n; i++)
            {
				for (ll j = 0; j < n; j++)
                {
                  if(a[i][j]>(a[i][k]+a[k][j]))
                  {
                      a[i][j]=a[i][k]+a[k][j];
                      next[i][j]=next[i][k];
                  }
                }
            }
        }



        ll r;
        cin>>r;
        while(r--)
        {
            ll x,y;
            cin>>x>>y;
            vector<ll>v;
            ll i=x-1,j=y-1;
            v.push_back(i);
            while(i!=j)
            {
                i=next[i][j];
                v.push_back(i);
            }
            for(ll i=0;i<v.size();i++)
            {
                cout<<v[i]+1<<" ";
            }
            cout<<endl;

            cout<<x<<" "<<y<<": "<<a[x-1][y-1]<<endl;
        }
