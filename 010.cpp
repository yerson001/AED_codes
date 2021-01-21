/*arbol binario completo con print in_orden post_and pre_order y por niveles 
use stack and vector*/
#include<iostream>
#include<stack>
#include<vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
#include<Windows.h>

template<class T>
class nodo {
public:
	T valor;
	T flag;
	nodo<T>* hijo[2]; // indices[0] y n elementos[2] 
	nodo(T x) {
		valor = x;
		flag = 0;
		hijo[0] = nullptr;
		hijo[1] = nullptr;
	}
};


void setCColor(int m){
	int color[7] = {0x00,0x00E,0x00C,0x002,0x00B,0x005,0x00F};
	static HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color[m] | (0 * 0x10 + 0x100));
}

template<class T>
class tree {
public:
	nodo<T>* root;
	tree() { root = nullptr; }

	bool find(T x, nodo<T>**& p) {
		p = &root;
		while (*p && (*p)->valor != x) {
			p = &((*p)->hijo[(*p)->valor < x]);
		}//un puntero negado es 0
		return !!*p;
	}

nodo<T>** Intercambio(nodo<T>** q) {
		q = &(*q)->hijo[0];
		while ((*q)->hijo[1]) {
			q = &((*q)->hijo[1]);
		}
		return q;
	}

bool insert(T x) {
		nodo<T>** p;
		if (find(x, p))//si encuentras el valor
			return 0;// sales xq en sin repeticion
		*p = new nodo<T>(x);// no requiere enlaca xeso no se crea un temp
		return 1;
	}
bool remove(T x) {
		nodo<T>** p, ** q;
		if (find(x, p) == 0) return 0;

		if ((*p)->hijo[0] && (*p)->hijo[1]) {
			q = Intercambio(p);
			(*p)->valor = (*q)->valor;
			p = q;
		}
		nodo<T>* t = *p;
		*p = (*p)->hijo[(*p)->hijo[1] != 0];
		delete t;
		return 1;
	}

void mostrar(nodo<T> *root){
		setCColor(4);
		string ancho = to_string(root->valor);
		vector<T> x;
		vector<vector<T> > y;
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
		for (int i = 0; i < y.size(); ++i){
			for (int j = 0, e = 0; j < x.size() and e < y[i].size(); j++){
				if (y[i][e] == x[j]){
					string aux = to_string(x[j]);
					for (int i = aux.size(); i < ancho.size(); ++i)
						aux.push_back(' ');
					cout <<aux;
					e++;
				}

				else{
					for (int i = 0; i < ancho.size(); ++i)
						cout << " ";
				}
					
			}
			cout << endl;
		}setCColor(6);
}

void in_order(nodo<T>* p) {
		if (p == nullptr) return;
		in_orden(p->hijo[0]);
		cout << p->valor << " ";
		in_orden(p->hijo[1]);
	}

void in_orden(nodo<T>* root) {
		if (root == nullptr)
			return;
		stack<nodo<T>*> List;
		nodo<T>* point = root;
		while (point != nullptr || !List.empty()) {
			while (point != nullptr) {
				List.push(point);
				point = point->hijo[0];
			}
			if (!List.empty()) {
				point = List.top();//cout<<"-- "<<point->valor<<endl;
				List.pop();//cout<<"--"<<point->valor<<endl;
				cout << point->valor << " ";
				point = point->hijo[1];
			}
		}
	}
	
void pre_orden(nodo<T>* root){
	if(root == NULL) return;
	stack<nodo<T>*> List;
	
	nodo<T>* p = root;
	while(p != NULL || !List.empty()){
		while(p != NULL){
			List.push(p);
			cout<<p->valor<<" ";
			p = p->hijo[0];
		}
		if(!List.empty()){
			p = List.top();
			List.pop();
			p = p->hijo[1];
		}
	}		
}

void post_orden(nodo<T>* root){
	if(root == NULL) return;
	stack<nodo<T>*> List;
	
	nodo<T>* p = root;
	while(p != NULL || !List.empty()){
		while(p != NULL){
			List.push(p);
			p = p->hijo[0];
		}
		if(!List.empty()){
			p = List.top();
			List.pop();
			if(p->flag == 0){
				List.push(p);
				p->flag += 1;
			}
			else if(p->flag == 1){
				cout<<p->valor<<" ";
				p->flag += 1;
			}
			p = p->hijo[1];
		}
	}	
}
void niveles(){//agregar a la cola luego insertt sus hijos
	vector<nodo<T>*> lista;
	int len;
	lista.push_back(root);
	while(lista.size()!=0){
		len = lista.size();
		for(int i=0; i<len; i++){
			if(lista[i]){
				cout<<lista[i]->valor;
				lista.push_back(lista[i]->hijo[0]);
				lista.push_back(lista[i]->hijo[1]);
				}
			}
				cout<<endl;
				lista.erase(lista.begin(),lista.begin()+len);
			}
		}
void por_niveles(nodo<T>*root,int n){
	if(root!=nullptr){
		if(n==0){
			cout<<root->valor<<" ";
		}
		por_niveles(root->hijo[0],n-1);
		por_niveles(root->hijo[1],n-1);
	}
}

int suma(nodo<T>* root){
	if(root!=nullptr){
		int root_ = root->valor;
		int hijo_0 = suma(root->hijo[0]);
		int hijo_1 = suma(root->hijo[1]);
		return root_ + hijo_0 + hijo_1;
	}
	return 0;
}

int n_nodo(nodo<T>*root ,int n){
	if(root!=nullptr){
		if(n<=0){
			return n_nodo(root->hijo[0],n-1) + n_nodo(root->hijo[1],n-1)+1;
		}
	return n_nodo(root->hijo[0],n-1) + n_nodo(root->hijo[1],n-1);
	}
	return 0;
}

int altura(nodo<T>*root){
	if(root!=nullptr){
		int hijo_0 = altura(root->hijo[0])+1;
		int hijo_1 = altura(root->hijo[1])+1;
		return (hijo_0 > hijo_1 ? hijo_0:hijo_1);
	}
	return -1;
}

int probar(nodo<T>* root) {
	int io=0;
		if (root == nullptr)
				return 0;
		stack<nodo<T>*> List;
		nodo<T>* point = root;
		while (point != nullptr || !List.empty()) {
			while (point != nullptr) {
				List.push(point);
				point = point->hijo[0];
			}
			if (!List.empty()) {
				point = List.top();//cout<<"-- "<<point->valor<<endl;
				List.pop();//
				//cout<<"--"<<point->valor;
				io++;
				if((point->hijo[0]==nullptr and point->hijo[1]==nullptr))
				//or (point->hijo[0]==nullptr and point->hijo[1]!=nullptr)
				//or (point->hijo[1]==nullptr and point->hijo[0]!=nullptr))
				{
						io--;
						//cout<<point->valor<<"  ";
				}
				//=============================
				point = point->hijo[1];
			}
		}
		return io+1;
	}


};

int main() {
	tree<int> a;
	//int arr[] = {15,6,20,3,1,4,9,7,12,18,17,24,8};
	int arr[] = {5,8,7,9,0,6,4,5,-1,-3};
	int len = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < len; i++) {
		a.insert(arr[i]);
	}
	a.mostrar(a.root);
	//a.por_niveles(a.root,0);cout<<endl;
	//cout <<a.suma(a.root)<<endl;
	//cout<<a.n_nodo(a.root,0)-a.n_nodo(a.root,a.altura(a.root)-1)<<endl;
	//cout<<a.altura(a.root)<<endl;
	//a.in_order(a.root);cout << endl;
	cout<<a.probar(a.root);

	
	return 0;
}