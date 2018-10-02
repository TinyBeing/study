#include <iostream>
using namespace std;
int main(void){
	bool y[4];
	for(int i=0; i<3; i++){
		char r = 'A'-1;
		for(int j=0; j<4; j++){
			cin >> y[j];
			if(!y[j])
				r = r+1;
		}
		if(r == 'A'-1)
			r = 'E';
		cout << r << endl;
	}
}
