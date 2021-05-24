
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

const int M=105;

ll vis[M][M],grid[M][M],dp[M][M];
ll n,m;

bool valid(ll i,ll j)
{
    return (i>=0 and i<n and j>=0 and j<m);
}

ll solve(ll i,ll j)
{


    if(dp[i][j]!=-1) return dp[i][j];

    ll s=0;

    if(grid[i][j]>grid[i][j+1] and valid(i,j+1))
    {
        s=max(s,1+solve(i,j+1));
    }

    if(grid[i][j]>grid[i+1][j] and valid(i+1,j))
    {
        s=max(s,1+solve(i+1,j));
    }

    if(grid[i][j]>grid[i][j-1] and valid(i,j-1))
    {
        s=max(s,1+solve(i,j-1));
    }

    if(grid[i][j]>grid[i-1][j] and valid(i-1,j))
    {
        s=max(s,1+solve(i-1,j));
    }

    if(s==0) s=1;

    return dp[i][j]=s;

}


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j,cas=0;
    cin>>t;
    while(t--)
    {
       // if(cas) cout<<endl;

        cas++;

        string s;cin>>s;
        cin>>n>>m;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) cin>>grid[i][j];
        }

        ll ans=0;
        memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ans=max(ans,solve(i,j));
            }
        }

       /// Feldberg: 7

        cout<<s<<": "<<ans<<endl;



    }

    return 0;

}

/*

2
Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38
Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

*/




