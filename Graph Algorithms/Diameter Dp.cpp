int N,M,Q,dp[MAXN][3],mx[MAXN],dia[MAXN]; // mx -> Max in upper subtree, dp-> two max in subtree 

void dfs(int s, int p){
    for(auto t:adj[s])if(t!=p){
        dfs(t,p);
        dp[s][2] = dp[t][0]+1;
        sort(dp[s], dp[s]+3);
        reverse( dp[s], dp[s]+3 );
    }
}
	
void dfs2(int s, int p){
    for(auto t:adj[s])if(t!=p){
        int mxx;
        if(dp[s][0]==dp[t][0]+1)t = dp[s][1];
        else t = dp[s][0];
        mx[t] = max( mx[s]+1 , t+1  );
        dfs2(t,s);
    }
}
