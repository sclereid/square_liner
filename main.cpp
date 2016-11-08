#include <iostream>
#include <cmath>

using namespace std;

double tx, ty;

int liner2_solve(double a, double b, double c, double d, double e, double f)
{
	double tmp = c*d - a*f;
	if(tmp == 0)
		return 1;
	tx = (b*d - a*e)/tmp;
	ty = (a*e - b*d)/tmp;
	return 0;
}

bool judge(double a, double b, double c)
{
	return (tx*a+tx*b-c)<=0;
}


int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	
	liner2_solve(a, b, c, d, e, f);
	cout << '\n';
	cout << tx << ' ' << ty << endl;
	return 0;
}
