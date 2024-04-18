#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis;
vector<int>topo;
void dfs(int node)
{
	vis[node]=1;
	for(auto v:g[node])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
	topo.push_back(node);
}

int dp[100100];
int rec(int node)
{
	if(dp[node]!=-1)return dp[node];
	int ans=1;
	for(auto v:g[node])
	{
		ans = max(ans,1+rec(v));
	}
	return dp[node]=ans;
}


int main()
{
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}

	// memset(dp,-1,sizeof(dp));
	// int ans=0;
	// for(int i=0;i<=n;i++)
	// {
	// 	ans=max(ans,rec(i));
	// }
	// cout<<ans<<endl;



	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	// reverse(topo.begin(),topo.end());paapa  
	// for(auto v:topo)
	// {
	// 	cout<<v<<" ";
	// }
	int final=0;
	for(auto node:topo)
	{
		int ans=1;
		for(auto v:g[node])
		{
			ans = max(ans,1+dp[v]);
		}
		dp[node] = ans;
		final = max(final,dp[node]);
	}
	cout<<final<<endl;
}
