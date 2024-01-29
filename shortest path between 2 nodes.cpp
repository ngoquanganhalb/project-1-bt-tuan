/*
Problem: Week 6 - Shortest Path between 2 nodes on a directed graph with non-negative weights
Description
Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). Given two nodes s and t of G. Find the shortest path from s to t on G.
Input
Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
Line m+2: contains two integers s and t
Output
Write the weight of the shortest path found or write -1 if no path from s to t was found
Example
Input
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

Output
97
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int maxn = 999999;
int pre[999999];  
// s la dinh ban dau, s->u->v
int x, y, w, m, n,s,t;
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
    cin >> s >> t;
}

void dijkstra(int s,int t)
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

    cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t==s) break;
        t=pre[t];
    }
    reverse(begin(path),end(path));
    // in duong di 
//    for(int x:path)
  //  {
    //    cout << x<<' ';
    //}
}

int main()
{
    input();
    dijkstra(s,t);

    return 0;
}