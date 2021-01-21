/*arbol de prioridades  primera vercion con heap sort en el vector*/
#include<iostream>
#include<stack>
#include<vector>
#include <iomanip>
#include<windows.h>
#include <queue>
#include <cmath>
using namespace std;

template<class T>
class nodo {
public:
	T valor;
	T flag;
	nodo<T>* hijo[2]; // indices[0] y n elementos[2] 
	nodo(T x) {
		valor = x;
		hijo[0] = nullptr;
		hijo[1] = nullptr;
	}
};

template<typename T>
void swap_(T &a,T &b){
	T t = a;
	a = b;
	b = t;
}
template<class T>
class tree {
public:
	nodo<T>* root;
	vector<nodo<T>*> list;
	vector<nodo<T>*> copy;
	tree() { root = nullptr; }

	void print_(vector<nodo<T>*> list,int len){
		for(int i=0; i<len; i++)
			cout<<list[i]->valor<<" ";
		cout<<endl;
	}
	bool insert(T x) {
		nodo<T>** p;
		if (find(x, p))//si encuentras el valor
			return 0;// sales xq en sin repeticion
		*p = new nodo<T>(x);// no requiere enlaca xeso no se crea un temp
		return 1;
	}

  void llenar(T x){
		nodo<T>* p;
		p = new nodo<T>(x);
		list.push_back(p);
		//cout<<"lleno"<<endl;
	}

	void ordenar(vector<nodo<T>*> &list){
		for(int j=0; j<list.size()/2; j++){
			for(int i=0; i<list.size()/2; i++){
				int l = 2*i+1;
				int r = 2*i+2;
				if(list[i]->valor < list[l]->valor && l<list.size())
					 swap_<T>(list[i]->valor,list[l]->valor);
				if(list[i]->valor < list[r]->valor && r<list.size())
					 swap_<T>(list[i]->valor,list[r]->valor);
				insertar(list[i],list[l],list[r]);
			}
		}
	}
	bool insertar(nodo<T>*pt,nodo<T>*l,nodo<T>*r){
		 pt->hijo[0] = l;
         pt->hijo[1] = r;
		return 1;
	}

	void copiar(vector<nodo<T>*> l){
		for(int i=0; i<l.size(); i++){
			copy[i] = l[i];
		}
	}
 void remove(vector<nodo<T>*> lis,int valor){cout<<"<<<"<<endl;
	 int i=0;
		while(list[i]->valor!=valor){
			i++;
		}
	 if(list[2*i+1]->valor > list[2*i+2]->valor){
			swap_<T>(list[i]->valor,list[2*i+1]->valor);
			for(int m=2*i+1; m<list.size()-1; m++){
				swap(list[m],list[m+1]);
			}list.pop_back();
			//copiar(list);
		}
	else{
		swap_<T>(list[i]->valor,list[2*i+2]->valor);
		for(int m=2*i+2; m<list.size()-1; m++){
			swap(list[m],list[m+1]);
		}list.pop_back();
		//copiar(list);
	}
 }

void niveles(nodo<T>* root){
	vector<nodo<T>*> lista;
	int len;
	lista.push_back(root);
	while(lista.size()!=0){
		len = lista.size();
		for(int i=0; i<len; i++){
            //cout<<" ";
			if(lista[i]){
				cout<<lista[i]->valor<<" ";
				lista.push_back(lista[i]->hijo[0]);
				lista.push_back(lista[i]->hijo[1]);
				}
			}
				cout<<endl;
				lista.erase(lista.begin(),lista.begin()+len);
			}
		}

	void mostrar(nodo<T> *root){
		string ancho = to_string(root->valor);
		vector<T> x;
		vector<vector<T> > y;

		// eje x ________________________________________
		stack< pair<nodo<T>*, int> > stk;
		stk.push({ root, 0 });

		nodo<T>* aux = NULL;
		
		string str;
		while (!stk.empty()){
			aux = stk.top().first;
			if (!aux) stk.pop();
			else{
				if (stk.top().second == 0){
					str = to_string(aux->valor); if (str.size() > ancho.size()) ancho = str;
					stk.top().second++;
					stk.push({ aux->hijo[0], 0 });
				}

				else{
					stk.pop();
					x.push_back(aux->valor);
					stk.push({ aux->hijo[1], 0 });
				}
			}
		}

		// eje y ____________________________________
		vector<nodo<T>*> vec;
		vector<T> vecaux;
		if (root){
			vec.push_back(root);
			vecaux.push_back(root->valor);
		}

		while (vec.size() > 0){
			y.push_back(vecaux);
			vecaux.clear();
			for (int i = 0, aux = vec.size(); i < aux; ++i){
				if (vec[0]->hijo[0]){
					vec.push_back(vec[0]->hijo[0]);
					vecaux.push_back(vec[0]->hijo[0]->valor);
				}

				if (vec[0]->hijo[1]){
					vec.push_back(vec[0]->hijo[1]);
					vecaux.push_back(vec[0]->hijo[1]->valor);
				}

				vec.erase(vec.begin());
			}
		}

		
		// print xd 
		for (int i = 0; i < y.size(); ++i){
			for (int j = 0, e = 0; j < x.size() and e < y[i].size(); j++){
				if (y[i][e] == x[j]){
					string aux = to_string(x[j]);
					for (int i = aux.size(); i < ancho.size(); ++i)
						aux.push_back(' ');
					cout << aux;
					e++;
				}

				else{
					for (int i = 0; i < ancho.size(); ++i)
						cout << " ";
				}
					
			}
			cout << endl;
		}
	}
};


int main() {
	tree<int> a;
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);//cout<<len<<endl;
	for (int i = 0; i < len; i++) 
		a.llenar(arr[i]);
//===================================================
	//a.print_(a.list,a.list.size()); //par 1    impar 0
	//cout<<"1"<<endl;
	a.ordenar(a.list);
	a.print_(a.list,a.list.size());
	a.mostrar(a.list[0]);
cout<<"mmm";
	//a.print_(a.copy,a.list.size());
	return 0;
}