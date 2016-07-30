//
//  11044_Searching_for_Nessy.cpp
//  
//
//  Created by RAHUL KUMAR SINGH on 30/07/16.
//
//


//
//  template_file.cpp
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
int minSonar(int n,int m){
    int minSonar=0;
    minSonar=(n/3)*(m/3);
    return minSonar;
}
int main(){
    int n,m,tc,sonars;
    cin>>tc;
    while(tc--){
        sonars=0;
        cin>>n>>m;
        sonars=minSonar(n,m);
        cout<<sonars<<endl;
    }
    return 0;
}
