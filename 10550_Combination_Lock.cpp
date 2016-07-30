//
//  10550_Combination_Lock.cpp
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
int anticlockdistance(int a, int b){
    // from a--->b
    int dis;
    dis=b-a;
    if (dis<0) {
        dis+=40;
    }
    return dis;
}
int clockdistance(int a, int b){
    // from a -- > b
    int dis;
    dis=a-b;
    if(dis<0){
        dis+=40;
    }
    return dis;
}
int main(){
    int a,b,c,d,total_distance;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)&&(a||b||c||d)){
        total_distance=120+clockdistance(a,b)+anticlockdistance(b,c)+clockdistance(c,d);
        cout<<total_distance*9<<endl;
    }
    return 0;
}
