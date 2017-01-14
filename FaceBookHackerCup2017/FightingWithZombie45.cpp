//
// Created by RAHUL KUMAR SINGH on 26/12/16.
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
char str[40];
struct node{
    int t;
    int f;
    int z;
    int sign;
};
struct node decode(){
    struct node dice;
    int t=0,f=0,z=0,i=0,sign=0;
    for(;i<strlen(str);i++){
        if(str[i]=='d')
        { i++;break;}
        t=t*10+str[i]-48;
    }
    for(;i<strlen(str);i++){
        if(str[i]=='-'||str[i]=='+')
        {    if(str[i]=='-')
                sign=-1;
             if(str[i]=='+')
                 sign=1;
            i++;
            break;
        }
        f=f*10+str[i]-48;
    }
    for(;i<strlen(str);i++){
        z=z*10+str[i]-48;
    }
    dice.f=f;
    dice.t=t;
    dice.z=z;
    dice.sign=sign;
    return dice;
}

double solve(int face,int time,int offset,int sign,int RequirePower){
    double dp[404][26]={0};
    double prob,f=face;
    for(int i=1;i<=f;i++){
        dp[i][1]=1.0/f;
    }
    for(int sum=1;sum<=(face*time);sum++){
        for(int i=2;i<=time;i++){
            prob=0;
            for(int k=1;k<=face;k++){
                if((sum-k)>=0)
                    prob+=dp[sum-k][i-1]/f;
            }
            dp[sum][i]+=prob;
        }
    }
    double ans=0.0;
    for(int i=time;i<=(face*time);i++){
        if((i+offset*sign)>=RequirePower){
            ans+=dp[i][time];
        }
    }
    return ans;
}
int main(){
    int tc,h,s;
    double ans=0;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>h>>s;
        ans=0;
        for(int j=0;j<s;j++){
            cin>>str;
            struct node temp=decode();
            ans=max(ans,solve(temp.f,temp.t,temp.z,temp.sign,h));
        }
        printf("Case #%d: %lf\n",i,ans);
    }
    return 0;
}
