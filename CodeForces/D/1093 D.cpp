        /*
         * Created by Rahul Goel.
         * Problem URL - https://codeforces.com/contest/1093/problem/D
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
         
        ll power(ll a, ll b)
        {
        	ll ans = 1;
        	while(b)
        	{
        		if(b&1)
        			ans = (ans*a)%MOD;
        		b>>=1, a = (a*a)%MOD;
        	}
        	return ans;
        }
         
        int  main()
        {
        	ll t;
        	cin >> t;
        	while(t--)
        	{
        		ll n, m, ans = 1;
        		cin >> n >> m;
        		adj.clear(), adj.resize(n+1), vis.clear(), vis.assign(n+1, 0);
        		parity.clear(), parity.assign(n+1, -1), dist.clear(), dist.assign(n+1, INF);
        		parent.clear(), parent.assign(n+1, -1);
        		for(ll i=0; i<m; i++)
        		{
        			ll u, v;
        			cin >> u >> v;
        			add_edge(u, v);
        		}
        		
        		for(ll i=1; i<=n; i++)
        		{
        			if(vis[i])
        				continue;
        			queue < ll > q;
        			q.push(i), vis[i] = 1, parity[i]=1, dist[i]=0;
        		        ll c[2]={0}, flag = 1;
        			c[1] = 1;
        			while(!q.empty())
        			{
        				ll v = q.front();
        				q.pop();
        				for(ll u : adj[v])
        				{
        					if(vis[u])
        					{
        						flag = (dist[u]&1)^(dist[v]&1);
        						if(flag==0)
    							break;
        					}
        					if(!vis[u])
        					{
        						q.push(u), vis[u]=1, parity[u]=!parity[v], c[parity[u]]++;
        						parent[u]=v, dist[u] = dist[v]+1;
        					}
        				}
        				if(flag == 0)
        					break;
        			}
        			if(flag == 0)
        			{
        				ans = 0;
        				break;
        			}
        			ans = (ans * (power(2, c[0]) + power(2, c[1]))%MOD)%MOD;
        		}
        		cout << ans << endl;
        	}
        	return 0;
        }
