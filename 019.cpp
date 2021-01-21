/*Arbol de prioridades time log(n)*/
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <utility>
#include <iostream>
#define m num[0]
using namespace std;
template<class T>
struct nodo {
	T dato;
	nodo<T>* hijos[2];
	nodo(T valor) : dato(valor) { hijos[0] = nullptr; hijos[1] = nullptr; }
};

template <typename T>
struct arbol {
	nodo<T>* root = nullptr;
	vector<nodo<T>**> lista;
	vector<nodo<T>*> num;
	arbol() { lista.push_back(&root); }

	void print_(vector<nodo<T>*> list) {
		for (int i = 0; i < list.size(); i++)
			cout << list[i]->dato << " ";
		cout << endl;
	}

	bool find(T valor, nodo<T>**& p) {
		int i = 0;
		for (; (*lista[i]) and (*lista[i])->dato != valor; ++i);
		p = lista[i];
		return (*p) and (*p)->dato == valor;
	}
	void swaper(nodo<T>* p) {
		if (!p) return;
		if (p->hijos[0] and (p->dato < p->hijos[0]->dato)) {
			swap(p->dato, p->hijos[0]->dato);
			swaper(root);
		}
		else
			swaper(p->hijos[0]);
		if (p->hijos[1] and (p->dato < p->hijos[1]->dato)) {
			swap(p->dato, p->hijos[1]->dato);
			swaper(root);
		}
		else
			swaper(p->hijos[1]);
	}
	void insert(T valor) {
		nodo<T>** p = nullptr;
		if (!find(valor, p)) {
			(*p) = new nodo<T>(valor);
			lista.push_back(&(*p)->hijos[0]);
			lista.push_back(&(*p)->hijos[1]);
		}
		swaper(root);
	}
	void mostrar() {
		string ancho = to_string(root->dato);
		vector<T> x;
		vector<vector<T> > y;
		stack< pair<nodo<T>*, int> > stk;
		stk.push({ root, 0 });
		nodo<T>* aux = nullptr;
		string str;
		while (!stk.empty()) {
			aux = stk.top().first;
			if (!aux) stk.pop();
			else {
				if (stk.top().second == 0) {
					str = to_string(aux->dato); if (str.size() > ancho.size()) ancho = str;
					stk.top().second++;
					stk.push({ aux->hijos[0], 0 });
				}
				else {
					stk.pop();
					x.push_back(aux->dato);
					stk.push({ aux->hijos[1], 0 });
				}
			}
		}
		vector<nodo<T>*> vec;
		vector<T> vecaux;
		if (root) {
			vec.push_back(root);
			vecaux.push_back(root->dato);
		}
		while (vec.size() > 0) {
			y.push_back(vecaux);
			vecaux.clear();
			for (int i = 0, aux = vec.size(); i < aux; ++i) {
				if (vec[0]->hijos[0]) {
					vec.push_back(vec[0]->hijos[0]);
					vecaux.push_back(vec[0]->hijos[0]->dato);
				}
				if (vec[0]->hijos[1]) {
					vec.push_back(vec[0]->hijos[1]);
					vecaux.push_back(vec[0]->hijos[1]->dato);
				}
				vec.erase(vec.begin());
			}
		}
		for (int i = 0; i < y.size(); ++i) {
			for (int j = 0, e = 0; j < x.size() and e < y[i].size(); j++) {
				if (y[i][e] == x[j]) {
					string aux = to_string(x[j]);
					for (int i = aux.size(); i < ancho.size(); ++i)
						aux.push_back(' ');
					cout << aux;
					e++;
				}
				else {
					for (int i = 0; i < ancho.size(); ++i)
						cout << " ";
				}
			}
			cout << endl;
		}
	}
	void mostrar_(nodo<T>* root) {
		string ancho = to_string(root->dato);
		vector<T> x;
		vector<vector<T> > y;
		stack< pair<nodo<T>*, int> > stk;
		stk.push({ root, 0 });
		nodo<T>* aux = nullptr;
		string str;
		while (!stk.empty()) {
			aux = stk.top().first;
			if (!aux) stk.pop();
			else {
				if (stk.top().second == 0) {
					str = to_string(aux->dato); if (str.size() > ancho.size()) ancho = str;
					stk.top().second++;
					stk.push({ aux->hijos[0], 0 });
				}
				else {
					stk.pop();
					x.push_back(aux->dato);
					stk.push({ aux->hijos[1], 0 });
				}
			}
		}
		vector<nodo<T>*> vec;
		vector<T> vecaux;
		if (root) {
			vec.push_back(root);
			vecaux.push_back(root->dato);
		}
		while (vec.size() > 0) {
			y.push_back(vecaux);
			vecaux.clear();
			for (int i = 0, aux = vec.size(); i < aux; ++i) {
				if (vec[0]->hijos[0]) {
					vec.push_back(vec[0]->hijos[0]);
					vecaux.push_back(vec[0]->hijos[0]->dato);
				}
				if (vec[0]->hijos[1]) {
					vec.push_back(vec[0]->hijos[1]);
					vecaux.push_back(vec[0]->hijos[1]->dato);
				}
				vec.erase(vec.begin());
			}
		}
		for (int i = 0; i < y.size(); ++i) {
			for (int j = 0, e = 0; j < x.size() and e < y[i].size(); j++) {
				if (y[i][e] == x[j]) {
					string aux = to_string(x[j]);
					for (int i = aux.size(); i < ancho.size(); ++i)
						aux.push_back(' ');
					cout << aux;
					e++;
				}
				else {
					for (int i = 0; i < ancho.size(); ++i)
						cout << " ";
				}
			}
			cout << endl;
		}
	}

	void maxheap() {
		(*lista[0])->dato = (*lista[lista.size() / 2 - 1])->dato;
		//cout<<" --->  "<<(*lista[0])->dato<<" size_ "<<lista.size()<<endl;
		(*lista[lista.size() / 2 - 1]) = nullptr;
		lista.pop_back();
		swaper(root);
		lista.pop_back();
		swaper(root);
	}

	void heapsort() {
		list<int> l;
		int aux = lista.size() / 2;
		for (int i = 0; i < aux; ++i) {
			l.push_front((*lista[0])->dato);
			maxheap();
			//mostrar();
		}
		for (list<int>::iterator i = l.begin(); i != l.end(); i++)
			cout << *i << " ";
		cout << endl;
	}

	void niveles(T x) {
		nodo<T>* p;
		for (int i = 0; i < x; i++) {
			p = new nodo<T>((*lista[i])->dato);
			num.push_back(p);
		}
	}
	void extramax() {
		nodo<T>* p = num[0];
		num[0]->dato = num[num.size() - 1]->dato;
		nodo<T>* tmp;
		if (p->hijos[1]) {
			tmp = p->hijos[1];
			p->hijos[1] = NULL;
			delete tmp;
		}
		else {
			tmp = p->hijos[0];
			p->hijos[0] = NULL;
			delete tmp;
		}
		num.pop_back();
		eliminar(1);
	}

	void eliminar(int i) {
		int left = 2 * i;//1
		int right = (2 * i + 1);//2
		int parent = i;//1 real 0
		if (left - 1 < num.size() && (num[left - 1]->dato > num[parent - 1]->dato))//>
			parent = left;
		if (right - 1 < num.size() && (num[right - 1]->dato > num[parent - 1]->dato))//>
			parent = right;
		if (parent != i) {
			swap(num[i - 1]->dato, num[parent - 1]->dato);
			eliminar(parent);
		}
	}
	void io(vector<nodo<T>*>& list) {
		//for(int j=0; j<list.size()/2; j++){
		for (int i = 0; i < list.size() / 2; i++) {
			int l = 2 * i + 1;
			int r = 2 * i + 2;
			insertar(list[i], list[l], list[r]);
		}
		//}
	}
	bool insertar(nodo<T>* pt, nodo<T>* l, nodo<T>* r) {
		pt->hijos[0] = l;
		pt->hijos[1] = r;
		return 1;
	}
};



int main()
{
	arbol<int> a;
	int arr[] = {10,9,8,7,6,5,4,3,2,1};


	int tam = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < tam; i++) {
		a.insert(arr[i]);
		a.mostrar();
		cout<<"---------------"<<endl;
	}
	a.niveles(tam);


	int n;
	cout<<"numero de extrmax: "; cin>>n;
	for(int i=0; i<n; i++){
		a.extramax();
	}a.io(a.num);
	a.mostrar_(a.m);



	return 0;
}