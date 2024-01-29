/*
Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
Write a program that computes the sequence of nodes visited using a BFS algorithm (the nodes are considered in a lexicographic order)

Input
Line 1: contains 2 integers n and m which are the number of nodes and the number of edges
Line i+1 (i = 1, ..., m): contains 2 positive integers u and v which are the end points of the ith edge

Output
Write the sequence of nodes visited by a BFS procedure (nodes a are separated by a SPACE character)
Example

Input
6 7
2 4
1 3
3 4
5 6
1 2
3 5
2 3

Output
1 2 3 4 5 6
*/

#include<bits/stdc++.h>
using namespace std;
long long x,y,n,m;
bool visited[9999];
vector<long long> adj[9999];
void input()
{   cin >> n >> m;
    for(long long i=0;i<n;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    memset(visited,false,sizeof(visited));
}

void bfs(long long u)
{
    // khoi tao 
    queue <long long> q;
    q.push(u);
    visited[u]=true;
    // lap
    while(!q.empty()){
        long long v=q.front(); // lay dinh dau hang doi 
        q.pop();
        cout << v << " "; // dinh nay da di qua 

         // Sort the adjacency list for ascending order
        sort(adj[v].begin(), adj[v].end());
        // duyet danh sach ke 
        for(long long x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
int main()
{
    input();
    bfs(1);
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

const int maxN  = 1e5 + 7;

int n, m, components = 0;
bool visit[maxN];
vector <int> g[maxN];

void bfs(int s) {
    ++components;
    queue <int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
         sort(g[u].begin(), g[u].end());
        for (auto v : g[u]) {
            if (!visit[v]) {
                visit[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill_n(visit, n + 1, false);
    for (int i = 1; i <= n; ++i)
       if (!visit[i]) bfs(i);
}
*/