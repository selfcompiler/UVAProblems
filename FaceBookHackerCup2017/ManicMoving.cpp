//
// Created by RAHUL KUMAR SINGH on 15/01/17.
//

#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <math.h>
#include <queue>
using  namespace std;

#define FOR(a,b) for(int i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define PI 3.14159265
typedef long long int LL;
typedef int64_t i64;
#define INF 300033999999
LL mdst[102][102];
int N,M,K;
struct family{
    int source;
    int destination;
    LL backward;
    LL direct;
    LL forward;
};
vector<struct family> familylist;
void takeInput(){
    int x,y;
    LL s,d,gas;
    cin>>N>>M>>K;
    familylist.clear();
    for(int i=0;i<=101;i++){
        for(int j=0;j<=101;j++){
            mdst[i][j]=INF;
        }
    }
    for(int i=0;i<=101;i++)
        mdst[i][i]=0;
    for(int i=1;i<=M;i++){
        cin>>x>>y>>gas;
        mdst[x][y]=min(mdst[x][y],gas);
        mdst[y][x]=min(mdst[y][x],gas);
    }
    struct family temp1;
    temp1.source=1;
    temp1.destination=1;
    temp1.forward=0;
    temp1.backward=0;
    temp1.direct=0;
    familylist.push_back(temp1);
    for(int i=1;i<=K;i++){
        struct family temp;
        cin>>s>>d;
        temp.source=s;
        temp.destination=d;
        temp.forward=INF;
        temp.backward=INF;
        temp.direct=INF;
        familylist.push_back(temp);
    }
    return;
}
void floyD(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                mdst[i][j]=min(mdst[i][j],mdst[i][k]+mdst[k][j]);
            }
        }
    }
}
LL solve(){
    familylist[1].direct=mdst[1][familylist[1].source]+mdst[familylist[1].source][familylist[1].destination];
    familylist[1].backward=INF;
    familylist[1].forward=INF;
    if(K>=2)
        familylist[1].forward=mdst[1][familylist[1].source]+mdst[familylist[1].source][familylist[2].source]+mdst[familylist[2].source][familylist[1].destination];
    if(familylist[1].forward>=INF)
        familylist[1].forward=INF;
    if(familylist[1].direct>=INF)
        familylist[1].direct=INF;

    for(int i=2;i<=K;i++){
          familylist[i].direct=min(familylist[i-1].direct,familylist[i-1].backward)+mdst[familylist[i-1].destination][familylist[i].source]+mdst[familylist[i].source][familylist[i].destination];
          familylist[i].backward=min(familylist[i-1].forward,familylist[i].backward)+mdst[familylist[i-1].destination][familylist[i].destination];
          if(i!=K)
            familylist[i].forward=min(familylist[i-1].forward+mdst[familylist[i-1].destination][familylist[i+1].source]+mdst[familylist[i+1].source][familylist[i].destination], min(familylist[i-1].direct,familylist[i-1].backward)+mdst[familylist[i-1].destination][familylist[i].source]+mdst[familylist[i].source][familylist[i+1].source]+mdst[familylist[i+1].source][familylist[i].destination]);
          else
            familylist[i].forward=INF;

          if(familylist[i].direct>=INF)
              familylist[i].direct=INF;
          if(familylist[i].backward>=INF)
              familylist[i].backward=INF;
    }
    LL ans=min(familylist[K].backward,familylist[K].direct);
    if(ans>=INF)
        return -1;
    return min(familylist[K].backward,familylist[K].direct);
}
void printG(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(mdst[i][j]==INF)
                cout<<"-1 ";
            else
                cout<<mdst[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        takeInput();
     //   printG();
        floyD();
     //   printG();
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
    return 0;
}
