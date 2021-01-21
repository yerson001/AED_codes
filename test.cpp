/*arbol de prioridades  primera vercion con heap sort en el vector*/
#include<iostream>
#include<vector>
using namespace std;


int main(){
	vector<string> a;
	a.push_back("hola");
	a.push_back("mundo");
	a.push_back("como");

	for(int i=0; i<a.size(); i++){
		if(a[i]=="mundo"){
			a.erase(a.begin()+i,a.begin()+i+1);
		}
	}

		for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}

    return 0;
}