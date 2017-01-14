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
class Point{

public:int dimension;
public:    vector<double> points; // x,y,z;

public:Point(double x,double y){
        dimension=2;
        points.push_back(x);
        points.push_back(y);
    }
public:Point(double x,double y,double z){
        dimension=3;
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
    }

//public:Point(Point &point){
//        this.dimension=point.dimension;
//        for(int i=0;i<dimension;i++){
//            this.points.push_back(point.points[i]);
//        }
//    }

public: static double distanceBetweenTwoPoints(Point p1,Point p2){
        //    cout<<p1.dimension<<" "<<p2.dimension<<endl;
        assert((p1.dimension==p2.dimension));
        double distance=0;
        for(int i=0;i<p1.dimension;i++){
            distance+=(p1.points[i]-p2.points[i])*(p1.points[i]-p2.points[i]);
        }
        return sqrt(distance);
    }
};
class MathVector{
    int dimension;
    vector<double> vector1;
public: MathVector(){
        dimension=0;
    }
public: MathVector(double i, double j){
        dimension=2;
        vector1.push_back(i);
        vector1.push_back(j);
    }

public: MathVector(double i, double j, double k){
        dimension=3;
        vector1.push_back(i);
        vector1.push_back(j);
        vector1.push_back(k);
    }
public:MathVector(Point p1,Point p2){  // treat p1 as origin  vector=p2-p1
        assert((p1.dimension==p2.dimension) && "create vector ,Point1 and Point2 does not have same dimensions");
        dimension=p1.dimension;
        for(int i=0;i<dimension;i++){
            vector1.push_back(p2.points[i]-p1.points[i]);
        }
    }
public:static double AngleBetweenVectors(MathVector v1,MathVector v2){
        /* Clock wise angle from v1 to v2 */
        assert((v1.dimension==v2.dimension) &&"unequal dimensions");
        assert((v1.dimension!=0) &&"0 dimensions not valid");
        assert((v1.dimension<=3) &&"more then 3 dimensions");
        double angle;
        if(v1.dimension==2)
            angle=AngleBetween2DVectors(v1,v2);
        else
            angle=AngleBetween3DVectors(v1,v2);
        if(angle<0)
            angle*=-1;
        else
            angle=360-angle;
        return angle;
    }
private:static  double AngleBetween2DVectors(MathVector v1,MathVector v2){
        double dot=v1.vector1[0]*v2.vector1[0]+v1.vector1[1]*v2.vector1[1];
        double det=v1.vector1[0]*v2.vector1[1]-v1.vector1[1]*v2.vector1[0];
        return ((atan2(det,dot)*180.0)/PI);
    }
private:static double AngleBetween3DVectors(MathVector v1,MathVector v2){
        double dot=v1.vector1[0]*v2.vector1[0]+v1.vector1[1]*v2.vector1[1]+v1.vector1[2]*v2.vector1[2];
        double lenSq1=v1.vector1[0]*v1.vector1[0]+v1.vector1[1]*v1.vector1[1]+v1.vector1[2]*v1.vector1[2];
        double lenSq2=v2.vector1[0]*v2.vector1[0]+v2.vector1[1]*v2.vector1[1]+v2.vector1[2]*v2.vector1[2];
        return ((acos(dot/sqrt(lenSq1*lenSq2))*180.0)/PI);
    }
};


int main(){
    double tc,p,x,y,dist,radius=50.0;
    cin>>tc;
    for(int i=1;i<=tc;i++) {
        cin >> p >> x >> y;
        if(p==0)
        {
            cout <<"Case #"<<i<<": "<< "white\n";
            continue;
        }
        Point point = Point(x,y);
        Point center =  Point(50.0,50.0);
        dist = Point::distanceBetweenTwoPoints(center, point);
        if ((dist - 0.000001) > 50.0) {
            cout <<"Case #"<<i<<": "<< "white\n";
            continue;
        }
        Point centerAbove=Point(50.0,100.0);
        MathVector mathVector1=MathVector(center,centerAbove);
        MathVector mathVector2=MathVector(center,point);
        double  angle=MathVector::AngleBetweenVectors(mathVector1,mathVector2);
        double  arcAngale=(p*360)/100;
          cout<<arcAngale<<" "<<angle<<"\n";
        if((arcAngale-angle)>0.000001){
            cout <<"Case #"<<i<<": "<< "black\n";
            continue;
        }
        cout <<"Case #"<<i<<": "<< "white\n";
    }
    return 0;
}
