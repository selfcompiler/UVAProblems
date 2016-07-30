//
//  11364_Parking.cpp
//  
//
//  Created by RAHUL KUMAR SINGH on 30/07/16.
//
//


#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<utility>
#include<cstdio>
#include<cmath>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE
#define INF 1000000000
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// common memset setting
// memset(memo,-1,sizeof memo);
// memset(arr,0,sizeof arr);

// frequent used
int main(){
    int tc,n,minv,maxv,loc;
    cin>>tc;
    while(tc--){
        cin>>n;
        minv=101;
        maxv=-1;
        for (int i=0; i<n; i++) {
            cin>>loc;
            minv=min(loc,minv);
            maxv=max(loc,maxv);
            
        }
        cout<<2*(maxv-minv)<<endl;
        
    }
    return 0;
}

