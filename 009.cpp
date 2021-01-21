/*practica AED imcomplit*/
#include<iostream>
using namespace std;
#define space cout<<endl;

template<class T>
class nodo {
public:
	T valor;
	nodo<T>* hijo[2]; // indices[0] y n elementos[2] 
    nodo<T>* next;
	nodo(T x) {
		valor = x;
		hijo[0] = nullptr;
		hijo[1] = nullptr;
        next = nullptr;

	}
};

template<class T>
class tree {
public:
	nodo<T>* root;
	tree() { root = nullptr; }

	bool find(T x, nodo<T>**& p, nodo<T>**& w) {
		while (*p && (*p)->valor != x)
			p = &((*p)->hijo[x % (*w)->valor == 0]);
		return !!*p;
	}

	bool insert(T x) {
		nodo<T>** w = &root;
		nodo<T>** p = &root;
		if (*w == nullptr) {
			*p = new nodo<T>(x);
            (*p)->next = *p;
		}
		else {
			while (*w != nullptr) {
				if (find(x, p, w)) {
					return 0;
				}
                if(x%2==0){
                    if(x%root->valor == x % (*w)->valor){
                            *p = new nodo<T>(x);
                            (*p)->next = *w;
                    }
                    w = &((*w)->hijo[0]);
                    p = w;
                }
                else{
                    *p = new nodo<T>(x);
                    (*p)->next = *w;
                    w = &((*w)->hijo[0]);
                    p = w;
                }
			}
		}
		return 1;
	}

	void in_orden(nodo<T>* p) {
		if (p == nullptr) return;
		in_orden(p->hijo[0]);
		    cout << p->valor << " ";
		in_orden(p->hijo[1]);
	}
    void mostrar(){
        nodo<T>*io = root;
       while(io){
            cout<<"raiz: "<<io->valor<<endl;
            cout<<"---------------"<<endl;
            in_orden(io->hijo[1]);cout<<endl;
            io = io->hijo[0];
        }
    }

};



int main() {
	tree<int> a;
    int opcion,dato;
    do{
        cout<<"INSERTAR[1]   MOSTRAR[2]  SALIR[3] "<<endl;
        cout<<"OPCION: ";
        cin>>opcion;
        if(opcion==1){
            cout<<"DATO: "; cin>>dato;
            a.insert(dato);
        }
        else if(opcion == 2){
            a.mostrar();
        }
    }while(opcion!=3);

	return 0;
}






