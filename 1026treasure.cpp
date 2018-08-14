#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int tmp;
	int *a = new int[n];
	int *b = new int[n];
	
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<n; i++){
		tmp = a[i];
		for(int j=i+1; j<n; j++)
		        if(tmp>a[j]){
			        a[i] = a[j];
				a[j] = tmp;
				tmp = a[i];
			}
		a[i] = tmp;
	}
	for(int i=0; i<n; i++){
		tmp = b[i];
		for(int j=i+1; j<n; j++)
		       if(tmp<b[j]){
			        b[i] = b[j];
		       		b[j] = tmp;
				tmp = b[i];
		       }
		b[i] = tmp;
	}
	tmp = 0;
	for(int i=0; i<n; i++)
		tmp+=a[i]*b[i];

	cout<<tmp;
	return 0;
}
