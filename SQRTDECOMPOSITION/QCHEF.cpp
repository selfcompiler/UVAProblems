//
// Created by RAHUL KUMAR SINGH on 28/01/17.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
#include <set>
using  namespace std;
typedef long long int  LL;
int growth[100005];
int mynext[100005];
int prevmine[100005];
int last_in_block[330][100005]={0};
int block_ans[330][100005]={0};
int last[100005]={0};
int indexme[100005]={0};
int found[100005]={0};
int mytime=0;
void clearmytime(){
    mytime++;
}
bool hasKey(int i){
    return found[i]==mytime;
}
void setValue(int i,int value){
  indexme[i]=value;
  found[i]=mytime;
}
int getPosition(int i){
    return indexme[i];
}
vector< pair<int,int> > Q;
int n,m,k,blocks,block_size;

void preProcess(){
    int l,r,x,y,ans=0;
    for(int i=1;i<=n;i++)
        mynext[i]=n+1,prevmine[i]=0,last[i]=0;
    for(int i=1;i<=n;i++){
        int j=last[growth[i]];
        if(j!=0){
            mynext[j]=i;
            prevmine[i]=j;
        }
        last[growth[i]]=i;
    }
    for(int b=1;b<=blocks;b++){
        l=b*block_size-block_size+1;
        r=min(b*block_size,n);
        for( y=l;y<=r;y++){
            if(mynext[y]>r){
                x=y;
                while(x>0){
                    last_in_block[b][x]=y;
                    x=prevmine[x];
                }
            }

        }
    }
    for(x=1;x<=n;x++)
        for(y=2;y<=blocks;y++){
            if(last_in_block[y][x]==0){
                last_in_block[y][x]=last_in_block[y-1][x];
            }
        }
    ans=0;
    for(int b=1;b<=blocks;b++){
        clearmytime();
        l=b*block_size-block_size+1;
        ans=0;
        for(y=l;y<=n;y++){
            if(!hasKey(growth[y])){
                indexme[growth[y]]=y;
            }
            ans=max(ans,y-indexme[growth[y]]);
            block_ans[b][y]=ans;
        }
    }
}
void inscan(){
    int l,r;
  //  cout<<"inscan\n";
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>growth[i];
    for(int i=1;i<=k;i++){
        cin>>l>>r;
        Q.push_back(std::make_pair(l,r));
    }
    block_size=sqrt(n);
    blocks=ceil(n/block_size);
    // cout<<"completed\n";
}
int queryInBlock(int L,int R){
    map<int,int> map1;
    int ans=0;
    for(int y=L;y<=R;y++){
        if(map1.find(growth[y])==map1.end()){
            map1[growth[y]]=y;
        }
        ans=max(ans,y-map1[growth[y]]);
    }
    return ans;
}
int answerQuery(int L,int R){
    int ans,b_l,b_r,e_l,y;
    b_l=((L+block_size-1)/block_size);
    b_r=R/block_size;
    if(b_l>=b_r){
        // iterate all values;
        ans=queryInBlock(L,R);
    }
    else{
        e_l=b_l*block_size;
        ans=block_ans[b_l+1][R];
        for(int x=L;x<=e_l;x++){
            if(prevmine[x]<L){
                y=last_in_block[(int)floor(R/block_size)][x];
                while (mynext[y]<=R)
                    y=mynext[y];
                ans=max(ans,y-x);
            }
        }
    }
    return  ans;
}
void outscan(){
    for(int i=0;i<Q.size();i++)
        cout<<answerQuery(Q[i].first,Q[i].second)<<"\n";
}
int main(){
    inscan();
    preProcess();
    outscan();
    return 0;
}
