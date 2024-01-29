/*
Problem: Week 6 - All pair shortest paths
Description
Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
Input
Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
Output
Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
Example
Input
4 9 
1 2 9 
1 3 7 
1 4 2 
2 1 1 
2 4 5 
3 4 6 
3 2 2 
4 1 5 
4 2 8
Output
0 9 7 2  
1 0 8 3  
3 2 0 5  
5 8 12 0
*/#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int maxn = 999999;
int pre[999999];  
// s la dinh ban dau, s->u->v
int x, y, w, m, n;
vector<pair<int, int>> adj[maxn];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w; // w la kc tu x-> y or y->x
     /* vo huong
        adj[x].push_back({y, w});
        adj[y].push_back({x, w}); */
            
        //co huong
        adj[x].push_back({y,w});
        
    }

}

void dijkstra(int s)
{
    // khoi tao d[s]=0 , d[cac dinh khac] =INF
    vector<long long> d(n + 1, INF);
    d[s] = 0;
    pre[s]=s;

    // priority_queue sort khoang cach theo min-> max (khoang cach,dinh)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s}); // khoang cach, dinh

    while (!q.empty())
    {
        // lay dinh co khoang cach toi s nho nhat
        pair<int, int> top = q.top();
        q.pop();
        int u = top.second; //top<first,second>
        int kc=top.first;
        if(kc>d[u]) continue;
        // cap nhat khoang cach tu s toi moi dinh ke voi u
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                pre[v]=u; // trc v la u
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
   // do dai duong di cout << d[t] << endl;
  /*  vector<int> path;
    while(1){
        path.push_back(t);
        if(t==s) break;
        t=pre[t];
    }
    reverse(begin(path),end(path));
    // in duong di 
    for(int x:path)
    {
        cout << x<<' ';
    }
}
*/

int main()
{
    input();
    for(int i=1;i<=n;i++)
    {
    dijkstra(i);
    }
    return 0;
}