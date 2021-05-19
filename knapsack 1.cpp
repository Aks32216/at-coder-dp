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

ll maxval(vector<ll> wt,vector<ll> val,ll n,ll w)
{
	ll dp[n+1][w+1];
	for(int i=0;i<n+1;++i)
	{
		for(int j=0;j<w+1;++j)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
		}
	}
	for(int i=1;i<n+1;++i)
	{
		for(int j=1;j<w+1;++j)
		{
			if(wt[i-1]<=j)
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("../../input.txt","r",stdin);
		freopen("../../output.txt","w",stdout);
	#endif

	BRAHAMASTRA

	ll n,w;
	cin>>n>>w;
	vector<ll> wt(n),val(n);
	for(int i=0;i<n;++i)
		cin>>wt[i]>>val[i];
	cout<<maxval(wt,val,n,w)<<"\n";
}
