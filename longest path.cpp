#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int

vi v[100001];
vi res;
vi in(100001);
vi dp(100001);

void kahn(int n)
{
	priority_queue<int,vector<int> ,greater<int> > q;
	for(int i=1;i<=n;++i)
		if(in[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int curr=q.top();
		res.pb(curr);
		q.pop();

		for(int node:v[curr])
		{
			in[node]--;
			if(in[node]==0)
				q.push(node);
		}
	}
}

int main()
{
	

	BRAHAMASTRA

	int n,m;
	cin>>n>>m;
	int a,b;
	while(m--)
	{
		cin>>a>>b;
		v[a].pb(b);
		in[b]++;
	}
	kahn(n);
	for(int i=0;i<res.size();++i)
	{
		for(auto child:v[res[i]])
			dp[child]=max(dp[child],dp[res[i]]+1);

	}
	cout<<*max_element(dp.begin(),dp.end())<<"\n";
}