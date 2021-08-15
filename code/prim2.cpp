#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> > adj[1000];
vector<int> d(1000, 1e9);
void readData(){
    freopen("INPUT.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            int x;
            cin >> x;
            if(x) adj[i].push_back(make_pair(j, x));// adj[i].push_back(j);
        }
    }
}
void prim(int x){
    vector<pair<int,int> > spanningTree;
    priority_queue<tuple <int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > pq;
    /*
    voi pq.top() la (w, u, v) trong do:
    w la khoang cach ngan nhat tu dinh v toi cay khung hien tai,
    u la dinh da nam trong cay khung
    */
    d[0] = 0;
    pq.push(make_tuple(0, 0, x));
    d[x] = 0;

    int tongTrongSo = 0;//tong trong so cua cay khung nho nhat
    while(!pq.empty()){
        int u, v, w; tie(w, u, v) = pq.top();
        pq.pop();
        if(d[v] < w) continue;
        tongTrongSo += d[v] - d[u];
//        cout << tongTrongSo << endl;
//        cout << u << " " << v << " " << w << endl;
        spanningTree.push_back(make_pair(u, v));
        for(auto val: adj[v]){
            int z, w; tie(z, w) = val;
            if(d[z] > d[v] + w){
                d[z] = d[v] + w;
                pq.push(make_tuple(d[z], v, z));
            }
        }
    }

    if((int)spanningTree.size() != n){
        cout << "do thi khong co cay khung nho nhat";
        return ;
    }
    cout << "cay khung nho nhat cua do thi gom cac canh sau\n";
    for(auto e: spanningTree){
        cout << e.first << " " << e.second << endl;
    }
    cout << "trong so cua cay khung nho nhat la: " << tongTrongSo;
}
int main(){
    readData();
    prim(1);
}

