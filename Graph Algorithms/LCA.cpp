const int l = 35;

int n,up[MAX][l+1], timer=0, tin[MAX], tout[MAX] , x, y, q ;
vi adj[MAX] ;

// Take care where and how to start dfs(1,1) or (1,0)

void dfs(int s, int p){

    tin[s] = ++timer;
    up[s][0]=p;

    for(auto t: adj[s] ){
        if(t!=p){
            dfs(t, s);
        }
    }

    tout[s] = ++timer;

}



bool is_ancestor(int u, int v){

    return tin[v]>=tin[u] && tout[u]>=tout[v];

}

void init(){

    for(int i = 1; i<=l; i++){
        for(int j = 1; j<=n; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }

}

int lca(int u, int v){


    if(is_ancestor(u, v))return u;
    if(is_ancestor(v, u))return v;

    for(int i = l; i>=0; i-- ){
        if(!is_ancestor(up[u][i] , v ))u = up[u][i];
    }

    return up[u][0];

}
