
///finding minimum sum of absolute differences between values of two sets

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e18;

const int M=5005;

ll a[M],b[M]; ///a for 1 , b for 0
ll n,idx1,idx0;
ll dp[M][M];

ll solve(ll i,ll j) ///from occupied(1) to unoccupied(0)
{
    if(i==idx1) return 0;

    if(j==idx0) return 1e8;

    if(dp[i][j]!=-1) return dp[i][j];

    ll s1=abs(a[i]-b[j])+solve(i+1,j+1);
    ll s2=solve(i,j+1);

    return dp[i][j]=min(s1,s2);

}

int main()
{

    ll t,i,j;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        ll x;scanf("%lld",&x);
        if(x==1) a[idx1++]=i;
        else b[idx0++]=i;
    }

    memset(dp,-1,sizeof(dp));

    ll ans=solve(0,0);
    printf("%lld\n",ans);


    return 0;

}





