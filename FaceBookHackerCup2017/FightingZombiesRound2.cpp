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
int N;
LL R;
struct Rectangle{
    LL x;
    LL y;
    LL lenght;
};
inline bool operator<(const Rectangle& lhs, const Rectangle& rhs)
{
    return lhs.x!=rhs.y||lhs.y!=rhs.y||lhs.lenght!=rhs.lenght;
}

set<struct Rectangle> rectangles;
vector< pair <LL ,LL > > points;
struct Rectangle getupperRight(LL x,LL y,LL length){
    struct Rectangle temp;
    temp.x=x;
    temp.y=y;
    temp.lenght=length;
    return temp;
}

struct Rectangle getupperLeft(LL x,LL y,LL length){
    struct Rectangle temp;
    temp.x=x-length;
    temp.y=y;
    temp.lenght=length;
    return temp;
}

struct Rectangle getdownRight(LL x,LL y,LL length){
    struct Rectangle temp;
    temp.x=x;
    temp.y=y-length;
    temp.lenght=length;
    return temp;
}

struct Rectangle getdownLeft(LL x,LL y,LL length){
    struct Rectangle temp;
    temp.x=x-length;
    temp.y=y-length;
    temp.lenght=length;
    return temp;
}

void populateRectangles(int length){
    LL x,y;
    for(int i=0;i<points.size();i++){
        x=points[i].first;
        y=points[i].second;
        rectangles.insert(getupperRight(x,y,length));
        rectangles.insert(getupperLeft(x,y,length));
        rectangles.insert(getdownRight(x,y,length));
        rectangles.insert(getdownLeft(x,y,length));
    }
    return;
}
bool isInRectangle(struct Rectangle rectangle,pair<int,int> zombie){
    LL xlow,xhigh,ylow,yhigh;
    xlow=rectangle.x;
    ylow=rectangle.y;
    xhigh=rectangle.x+rectangle.lenght;
    yhigh=rectangle.y+rectangle.lenght;
    if(zombie.first<xlow || zombie.first>xhigh || zombie.second<ylow||zombie.second>yhigh)
        return false;
    return true;
}
int solve(){
    unsigned long ans=0;
    set< pair<int,int> > pointsInUnionRectangle;
    for(set<struct Rectangle>::iterator rectangle1=rectangles.begin();rectangle1!=rectangles.end();rectangle1++){
        for(set<struct Rectangle>::iterator rectangle2=rectangles.begin();rectangle2!=rectangles.end();rectangle2++){
            pointsInUnionRectangle.clear();
            for(int i=0;i<points.size();i++){
                if(isInRectangle(*rectangle1,points[i])){
                    pointsInUnionRectangle.insert(points[i]);
                }
                else if(isInRectangle(*rectangle2,points[i])){
                    pointsInUnionRectangle.insert(points[i]);
                }
            }
            ans=max(ans,pointsInUnionRectangle.size());
        }
    }
    return ans;
}
int main() {
    int tc;
    LL x, y;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        points.clear();
        rectangles.clear();
        cin>>N>>R;
        for(int i=1;i<=N;i++) {
            cin >> x >> y;
            points.push_back(std::make_pair(x, y));
        }
        sort(points.begin(),points.end());
        populateRectangles(R);
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
    return 0;
}
