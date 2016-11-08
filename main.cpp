//
//  main.cpp
//  square_liner
//
//  Created by virtualize on 2016/11/8.
//  Copyright © 2016 virtualize. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int k, c, tc1, tc2;
double tx, ty, maxz, minz;
double cm, cn;
double m[105], n[105], p[105];
double x[10005], y[10005], z[10005];

int liner2_solve(double a, double b, double c, double d, double e, double f)
{
    double tmp = a*e - b*d;
    if(tmp == 0)
        return 1;
    tx = (b*f - c*e)/tmp;
    ty = (c*d - a*f)/tmp;
    return 0;
}

bool judge(double a, double b, double c)
{
    return (tx*a+tx*b-c)<=0;
}


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
    cout << "\nz = ax + by + c:\n";
    cin >> cm >> cn;
    maxz = -21747483648;
    minz = 21747483647;
    bool good_value;
    for (int i = 0; i < c; i++)
    {
        good_value = true;
        tx = x[i];
        ty = y[i];
        for(int j = 0; j < c; j++)
            good_value = good_value&&judge(m[j], n[j], p[j]);
        if(!good_value)
            continue;
        z[i] = cm*x[i] + cn*z[i];
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
    
    cout << "\n\n";
    cout << "max{z} = " << maxz << " where x = " << x[tc1] << " and y = " << y[tc1] << '\n';
    cout << "min{z} = " << minz << " where x = " << x[tc2] << " and y = " << y[tc2] << '\n';
    cout << endl;
    return 0;
}
