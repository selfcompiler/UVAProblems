//
// Created by RAHUL KUMAR SINGH on 07/01/17.
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
int main(){
    int tc,w;
    int n,ans;
    vector<int> weight;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>n;
        ans=0;
        weight.clear();
        for(int k=0;k<n;k++){
            cin>>w;
            weight.push_back(w);
        }
        sort(weight.begin(),weight.end());
        int l=0;
        int r=n-1;
        int ws=weight[r];
        while(l<r){
            if(ws>=50){
                ans++;
                ws=0;
                r--;
                if(r>=0)
                {
                    ws=weight[r];
                }
            }
            else{
                ws+=weight[r];
                l++;
            }
        }
        if(ws>=50)
            ans++;
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
