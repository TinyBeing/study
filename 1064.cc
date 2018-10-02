#include <iostream>
#include <cstdio>
#include <math.h>
double ab(double a){
	if(a<0)
		return -a;
	return a;
}
using namespace std;
int main(void){
	double xa,ya,xb,yb,xc,yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	double xd,yd;
	double tmp,tmp2,tmp3;
	if(ab((ya-yb)/(xa-xb))==ab((ya-yc)/(xa-xc))){
		cout << "-1";
		return 0;
	}
	tmp = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb))*2+sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc))*2;
	tmp2 = sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb))*2+sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc))*2;
	tmp3 = sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya))*2+sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc))*2;
	printf("%.15f",max(ab(tmp-tmp3),max(ab(tmp-tmp2),ab(tmp2-tmp3))));
	return 0;
}
