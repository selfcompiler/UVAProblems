//
//  11172_Relational_Operator.cpp
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
    int tc;
    ll a,b;
    cin>>tc;
    while(tc--){
        cin>>a>>b;
        if (a>b) {
            cout<<">"<<endl;
        }
        else if(a==b){
            cout<<"="<<endl;
        }
        else{
            cout<<"<"<<endl;
        }
    }
    return 0;
}

