        /*
         * Created by Rahul Goel.
         * Problem URL - https://codeforces.com/contest/1144/problem/F
        */
        #include <bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        #define vi vector < ll >
        #define vvi vector < vector < ll > >
        #define pb push_back
        ll INF = 1000000000;
        ll MOD = 998244353;
        vvi adj;
        vi vis, parity, parent, dist;
         
        void add_edge( ll u, ll v)
        {
        	adj[u].pb(v), adj[v].pb(u);
        }
         
          
        int  main()
        {
            ll n, m;
            cin >> n >> m;
         	adj.resize(n+1), vis.resize(n+1, 0), parent.resize(n+1, -1), dist.resize(n+1, INF);
         	vector < pair < ll , ll > > list;	
            for(ll i=0; i<m; i++)
            {
            	ll u, v;
    		cin >> u >> v;
    		add_edge(u, v);
    		list.pb({u, v});
            }
    	queue < ll > q;
    	q.push(1), dist[1]=0, vis[1]=1;
           	ll flag = 1;
    	while(!q.empty())
    	{
    		ll v = q.front();
    		q.pop();
    		for(auto u : adj[v])
    		{
    			if(!vis[u])
    				vis[u]=1, parent[u]=v, dist[u]=dist[v]+1, q.push(u);
    			else if((dist[u]&1)^(dist[v]&1) == 0)
    			{
    				flag = 0;
    				break;
    			}
    		}
    		if(flag == 0)
    			break;
    	}	
    	if(flag == 0)
    		cout << "NO" << endl;
    	else
    	{
    		cout << "YES" << endl;
    		for(auto p : list)
    		{
    			ll u = p.first, v = p.second;
    			if(dist[u]&1)
    				cout << 1;
    			else
    				cout << 0;
    		}
    		cout << endl;
    	}
        	return 0;
        }
