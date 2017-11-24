#include <bits/stdc++.h>

#define CASE(t) printf("Case %d: ",++t) // t initialized 0
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
double sqr(double x)
{
    return (x*x);
}
double DEG_to_RAD(double d)
{
    return d * PI / 180.0;
}

double RAD_to_DEG(double r)
{
    return r * 180.0 / PI;
}

struct point_i
{
    int x, y;     // whenever possible, work with point_i
    point_i()
    {
        x = y = 0;    // default constructor
    }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};          // constructor

struct point
{
    double x, y;   // only used if more precision is needed
    point()
    {
        x = y = 0.0;    // default constructor
    }
    point(double _x, double _y) : x(_x), y(_y) {}
};      // constructor
struct vec
{
    double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)         // convert 2 points to vector a->b
{
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}
point translate(point p, vec v)          // translate p according to v
{
    return point(p.x + v.x, p.y + v.y);
}
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double dist(point p1, point p2)                  // Euclidean distance
{
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
vec scale(vec v, double s)          // nonnegative s = [<1 .. 1 .. >1]
{
    return vec(v.x * s, v.y * s);
}               // shorter.same.longer
double distToLine(point p, point a, point b, point &c)
{
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));                  // translate a to c
    return dist(p, c);
}           // Euclidean distance between p and c

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y);                   // closer to a
        return dist(p, a);
    }         // Euclidean distance between p and a
    if (u > 1.0)
    {
        c = point(b.x, b.y);                   // closer to b
        return dist(p, b);
    }         // Euclidean distance between p and b
    return distToLine(p, a, b, c);
}          // run distToLine as above

double angle(point a, point o, point b)    // returns angle aob in rad
{
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
int insideCircle(point_i p, point_i c, int r)   // all integer version
{
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
} //inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point &c)
{
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}         // to get the other center, reverse p1 and p2
struct intersected_points
{
    bool no_intersection;
    pair<point,point>i_pts;
};
//intersection points of circle
//Reference :http://www.ambrsoft.com/TrigoCalc/Circles2/circle2intersection/CircleCircleIntersection.htm
intersected_points intersectPts(point c1,point c2, double r1,double r2)
{
    intersected_points ret;

    double x1 = c1.x;
    double y1 = c1.y;
    double x2 = c2.x;
    double y2 = c2.y;
    double sqx = sqr(x1-x2);
    double sqy = sqr(y1-y2);
    double dis = sqrt(sqx+sqy);
    if(r1+r2>dis && dis>fabs(r1-r2))
    {
        ret.no_intersection = false;

        double delta = (dis+r1+r2)*(dis+r1-r2)
                       *(dis-r1+r2)*(-dis+r1+r2);
        delta = 1.00*(sqrt(delta))/4.00;

        double x_i_1,y_i_1,x_i_2,y_i_2;

        x_i_1 = (x1+x2)/2.00;
        x_i_1 += ((x2-x1)*(sqr(r1)-sqr(r2)))/(2.000*sqr(dis));
        x_i_1 += (2.00*(y1-y2)*delta)/(sqr(dis));

        x_i_2 = (x1+x2)/2.00;
        x_i_2 += ((x2-x1)*(sqr(r1)-sqr(r2)))/(2.000*sqr(dis));
        x_i_2 -= (2.00*(y1-y2)*delta)/(sqr(dis));

        y_i_1 = (y1+y2)/2.00;
        y_i_1 += ((y2-y1)*(sqr(r1)-sqr(r2)))/(2.000*sqr(dis));
        y_i_1 += (2.00*(x1-x2)*delta)/(sqr(dis));

        y_i_2 = (y1+y2)/2.00;
        y_i_2 += ((y2-y1)*(sqr(r1)-sqr(r2)))/(2.000*sqr(dis));
        y_i_2 -= (2.00*(x1-x2)*delta)/(sqr(dis));
        point i_p1(x_i_1,y_i_1);
        point i_p2(x_i_2,y_i_2);
        ret.i_pts.first = i_p1;
        ret.i_pts.second = i_p2;


    }
    else
    {
        ret.no_intersection = true;
    }

    return ret;

}

int main()
{
    int tc,cas=0;
    cin>>tc;
    while(tc--)
    {
        double x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        point c1(x1,y1);
        point c2(x2,y2);

        intersected_points ip =
            intersectPts(c1,c2,r1,r2);

        if(ip.no_intersection)
        {
            CASE(cas);
            printf("%lf\n",0.00);
        }
        else
        {
            point ip1 = ip.i_pts.first;
            point ip2 = ip.i_pts.second;
            double ang1 = angle(c1,ip1,c2);
            if(ang1>(PI))
            {
                ang1 = 2*PI - ang1;
            }
            double area_sector1
                = (PI*sqr(r1)*ang1)/(2.00*PI);
            double t_a = sqrt(sqr(c1.x-ip1.x)
                              + sqr(c1.y-ip1.y));
            double t_b = sqrt(sqr(c1.x-ip2.x)
                              + sqr(c1.y-ip2.y));
            double t_c = sqrt(sqr(ip1.x-ip2.x)
                              + sqr(ip1.y-ip2.y));

            double t_s = (t_a+t_b+t_c)/2;

            double t_area = sqrt(t_s*(t_s-t_a)
                                 *(t_s-t_b)
                                 *(t_s-t_c));

            area_sector1 -= t_area;



            double ang2 = angle(c1,ip2,c2);

            if(ang2>PI)
            {
                ang2 = 2*PI - ang2;
            }
            double area_sector2
                = (PI*sqr(r1)*ang2)/(2.00*PI);
            t_a = sqrt(sqr(c2.x-ip1.x)
                       + sqr(c2.y-ip1.y));
            t_b = sqrt(sqr(c2.x-ip2.x)
                       + sqr(c2.y-ip2.y));
            t_c = sqrt(sqr(ip1.x-ip2.x)
                       + sqr(ip1.y-ip2.y));

            t_s = (t_a+t_b+t_c)/2;

            t_area = sqrt(t_s*(t_s-t_a)
                          *(t_s-t_b)
                          *(t_s-t_c));

            area_sector2 -= t_area;

            double fin_area
                = area_sector1 + area_sector2;

            CASE(cas);
            printf("%f\n",fin_area);


        }


    }

    return 0;
}
