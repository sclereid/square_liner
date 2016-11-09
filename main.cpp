//
//  main.cpp
//  square_liner
//
//  Created by virtualize on 2016/11/8.
//  Copyright ? 2016 virtualize. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int k, c, tc1, tc2; //k: number the of equations, c: number the of avalible points, tc1&tc2:adress to the max and min values
double tx, ty, maxz, minz; //temporary values
double cm, cn; //expection equation parameters
double m[105], n[105], p[105]; // limit equation parameters
double x[10005], y[10005], z[10005]; //avalible points and its value

int liner2_solve(double a, double b, double c, double d, double e, double f)
{
    double tmp = a*e - b*d;
    if(tmp == 0)
        return 1; //parallel equations
    tx = (b*f - c*e)/tmp;
    ty = (c*d - a*f)/tmp;
    return 0;
} //solve two equtions

bool judge(double a, double b, double c)
{
    return (tx*a+tx*b-c)<=0;
} //judge if it is in range


int main()
{
    c = 0;
    cout << "input number of limit equations:\n";
    cin >> k;
    cout << "\nax + by + c <= 0:\n";
    for (int i = 0; i < k; i++)
    {
        cin >> m[i] >> n[i] >> p[i];
        for (int j = 0; j < i; j++)
        {
            if (liner2_solve(m[i], n[i], p[i], m[j], n[j], p[j]))
                continue;
            x[c] = tx;
            y[c] = ty;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "Can't solve.\n";
    }
    cout << "\nz = ax + by:\n";
    cin >> cm >> cn;
    maxz = -2000000;
    minz = 2000000;
    bool good_value;//good value is a point in range
    for (int i = 0; i < c; i++)
    {
    	cout << "\npoint " << i << " at\tx = " << x[i] << "\ty = " << y[i] << "\tz = " << cm*x[i] + cn*y[i];
        good_value = true;
        tx = x[i];
        ty = y[i];
        for(int j = 0; j < c; j++)
            good_value = good_value&&judge(m[j], n[j], p[j]);
        if(!good_value)
            continue;
        cout << " *";
        z[i] = cm*x[i] + cn*y[i];
        if (maxz<z[i])
        {
            maxz = z[i];
            tc1 = i;
        }
        if (minz>z[i])
        {
            minz = z[i];
            tc2 = i;
        }
    }
    //fliter and choose maxium and minium number
    cout << "\n\n";
    cout << "max{z} = " << maxz << " where x = " << x[tc1] << " and y = " << y[tc1] << '\n';
    cout << "min{z} = " << minz << " where x = " << x[tc2] << " and y = " << y[tc2] << '\n';
    cout << endl;
    //output
    return 0;
}
