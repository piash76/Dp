
/*

Implementation of 0/1 knapsack problem. Given the weight and profit of
some objects. Pick objects in a way that maximizes the profit and does not
exceed a given weight limit.

5
1 120
7 400
4 280
3 150
4 200
10

600


*/




///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>


using namespace std;

const int N=5005;
int wt[N],pt[N],dp[N][N];
int n,cap;


int solve(int idx,int tot)
{
    if(idx>=n) return 0;

    if(tot==cap) return 0;

    if(dp[idx][tot]!=-1) return dp[idx][tot];

    int mx=solve(idx+1,tot);

    if(tot+wt[idx]<=cap) mx=max(mx,pt[idx]+solve(idx+1,tot+wt[idx]));

    return dp[idx][tot]=mx;


}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>pt[i];

    }



    cin>>cap;

    memset(dp,-1,sizeof(dp));

    int ans=solve(0,0); ///index,weight

    cout<<ans<<endl;



    return 0;

}





