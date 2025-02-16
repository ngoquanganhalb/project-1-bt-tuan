#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int u,v;
    int w;
};
vector <edge> canh;
const int maxn =1001;
int n,m;
int parent[maxn];
int sz[maxn];

void make_set(){
    for(int i =0;i<n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
}

void find(int v)
{
    if(v==parent[v])
    {
        return v;                           //1-3-5-2
    }
    else return parent[v] = find(parent[v]); // de quy tim parent root 
}

bool Union(int a , int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
    {
        return false ;
    }
    // gop a->b
    if(sz[a]<sz[b])
    {
        swap(a,b);
    }
    sz[a]+=sz[b];
    parent[b]=a;
    return true;
}

void input()
{   cout << n << m;
    for(int i=0;i<m;i++)
    {   int x,y,z;
        cout << x << y << z;
        edge e= edge(x,y,z); // add x,y,z to struct e 
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b){
    return a.z<b.z; // length a <b return true
}
void kruskal()
{
    //B1 tao cay khung cuc tieu rong
    vector<edge> minspantree;
    int d=0; //lengh of mst
    //B2 sort canh ngan nhat
    sort(canh.begin(),canh.end(),cmd) // sort setting cmp
    //B3 lap
    for(int i=0;i<m;i++)
    {
        if(minspantree.size()==n-1) break; // dinh -1 -> break
        edge e=canh[i];
        if(Union(e.x,e.y))  // 2 dinh cua canh e[i] k tao chu trinh
        {
            minspantree.push_back(e);
            d+=e.z;
        }
        
    }
    if(minspantree.size()!=n-1) cout<< " do thi k lien thong \n"; 
   for(auto it : minspantree)
   {
    cout<< it.x << it.y << it.z ;
   }
}


int main()
{
    input();
    kruskal();

    return 0;
}