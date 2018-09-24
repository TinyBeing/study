#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	bool fls=true;
	char c='0';
	char c2='0';
	int n[5];
	for(int i=0; i<5; i++){
		cin >> c;
		if(c2=='0')
			c2=c;
		else if(c2!=c)
			fls=false;
		cin >> n[i];
	}
	for(int i=1; i<5; i++){
		int tmp2;
		for(int j=i; j>0; j--){
			if(n[j-1]>n[j]){
				tmp2 = n[j-1];
				n[j-1] = n[j];
				n[j] = tmp2;
			}
			else break;
		}
	}
	int point = 0;
	bool str=true;
	for(int i=0; i<4; i++)
		if(n[i+1]-n[i]!=1)
			str = false;
	if(str){
		point = n[4]+500;
		if(fls){
			point = n[4]+900;
			cout << point;
			return 0;
		}
	}
	if(fls)
		point = n[4]+600;
	int p1=0;
	int p2=0;
	int pc1=0;
	int pc2=0;
	for(int i=0; i<4; i++){
		if(n[i]==n[i+1]){
			p1++;
			pc1=n[i];
		}
		else{
			if(p1==1&&p2==1)
				break;
			if(p1!=0){p2 = p1;
			p1 = 0;
			pc2 = pc1;}
		}
	}
	if(p2==0)
		point = max(point, n[4]+100);
	if(p2==1||p1==1)
		point = max(point, max(pc2+200,pc1+200));
	if(p2==1&&p1==1)
		point = max(point, pc2+pc1*10+300);
	if(p2==2||p1==2){
		point = max(point, max(pc2+400,pc1+400));
		if(p1==1||p2==1)
		{
			if(p2==2)
				point = max(point, 700+10*pc2+pc1);
			else
				point = max(point, 700+10*pc1+pc2);
		}
	}
	if(p2>=3||p1>=3)
		point = max(800+pc2,800+pc1);
	cout << point;
	return 0;
}
