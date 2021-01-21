/*arbol binario completo con print in_orden post_and pre_order y por niveles 
use stack and vector*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class HeapSort {
public:

    void heapSort(vector<int> &v, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(v, n, i);
        }
        cout << "Arun : ";
        for (auto &i : v)
            cout << i << " ";
        for (int i = n - 1; i >= 0; i--) {
            swap(v[0], v[i]);
            heapify(v, i, 0);
        }

    }
private:
    static void heapify(vector<int> &v, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && v[left] > v[largest]) largest = left;
        if (right < n && v[right] > v[largest]) largest = right;
        if (largest != i) {
            swap(v[i], v[largest]);
            heapify(v, n, largest);
        }
    }
};
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

template<class T>
class tree {
public:
	nodo<T>* root;
	tree() { root = nullptr; }
	vector<nodo<T>*> arr;

	bool find(T x, nodo<T>**& p) { 
		p = &root;
		nodo<T>**w = &root;
		while (*w && (*w)->valor != x) {
			p = &((*p)->hijo[(*p)->valor > x]);
		}//un puntero negado es 0
		return !!*p;
	}

	bool insert(T x,int i) {
		nodo<T>** p;
		if (root==nullptr){
			*p = new nodo<T>(x);// no requiere enlaca xeso no se crea un temp
			(*p)->hijo[0] = new nodo<T>(arr[2*i+1]->valor);
			(*p)->hijo[1] = new nodo<T>(arr[2*i+2]->valor);
		}
		if (find(x, p)){
			(*p)->hijo[0] = new nodo<T>(arr[2*i+1]->valor);
			(*p)->hijo[1] = new nodo<T>(arr[2*i+2]->valor);
		}
		return 1;
	}

	void llenar(){
		int n,val;
		cout<<"num nodo: ";cin>>n;
		for(int i=0; i<n; i++){
			cout<<"nodo: "<<i<<endl;
			//cout<<" valor: ";cin>>valor_;
			cout<<" val: ";cin>>val;
			nodo<T>*neo = new nodo<T>(val);
			arr.push_back(neo);
		}
	}
	void build(){
		llenar();
		//for (int i = 0; i < arr.size(); i++) {
		 	insert(arr[0]->valor,0);// cout<<"i"<<endl;
			insert(arr[1]->valor,1);// cout<<"i"<<endl;
		  	//for (int j = 0; j < 2; j++) {cout<<"j"<<endl;
			//	insert(arr[2*i+1+j]->valor,j);
			//}
		//}
	}

void niveles(){
	vector<nodo<T>*> lista;
	int len;
	lista.push_back(root);
	cout<<" ";
	while(lista.size()!=0){
		len = lista.size();
		for(int i=0; i<len; i++){
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

};
int main() {
	tree<int> a;
	a.build();
	a.niveles();
	return 0;
}