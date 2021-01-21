/*
binary tree with function swap
inorden recursuve
*/
#include<iostream>
using namespace std;
#define space cout<<endl;

template<class T>
class nodo{
public:
	T valor;
	nodo<T>*hijo[2]; // indices[0] y n elementos[2] 
	nodo(T x){valor = x;
		hijo[0] = nullptr;
		hijo[1] = nullptr;
	}
};

template<class T>
class tree{
public:
	nodo<T>*root;
	tree(){root = nullptr;}

	bool find(T x,nodo<T>**&p){
		//root es un puntero ^ pos guarda direcoin de punteros
		//*pos es un puntero como root con el puedes accedes los mienbros
		p = &root;
		while(*p && (*p)->valor!=x){
			p = &((*p)->hijo[(*p)->valor<x]);
		}//un puntero negado es 0
		return !!*p;
	}

	nodo<T>** Intercambio(nodo<T>** q ){
		q = &(*q)->hijo[0];
		while ((*q)->hijo[1]){
			q = &((*q)->hijo[1]);
		}
		return q;
	}

	bool insert(T x){
		nodo<T>**p;
		if(find(x,p))//si encuentras el valor
			return 0;// sales xq en sin repeticion
		*p = new nodo<T>(x);// no requiere enlaca xeso no se crea un temp
		return 1;
	}
	bool remove(T x){
		nodo<T>**p,**q;
		if(find(x,p)==0) return 0;
		//bool left = !!(*p)->hijo[0];///para laver si un nodo tiene hijo
		//bool rigth = !!(*p)->hijo[1];// | left or rigth| or ambos
		if((*p)->hijo[0] && (*p)->hijo[1]){
			q = Intercambio(p);
			(*p)->valor = (*q)->valor;
			p = q;
		}
		nodo<T> *t = *p;
		*p = (*p)->hijo[(*p)->hijo[1]!=0];
		delete t;
		return 1;
	}


	void in_orden(nodo<T>*p){
		if(p==nullptr) return ;
		in_orden(p->hijo[0]);
		cout<<p->valor<<" ";
		in_orden(p->hijo[1]);
	}

};
/*
void In(nodo<int>*p,int x,int &a){
		if(p==nullptr) return ;
		In(p->hijo[1],x,a);
		if(x==p->valor) 
			a=1;
	}
void On(nodo<int>*p,int x,int &a){
	while(p!=nullptr){
		if((p)->valor==x)
			a = 1;
			p = p->hijo[0];
	}
	}
*/
int main(){
	tree<int> a;
	int in=0,on=0;
	//despues de la cindicin hace es primero 
		// la funcion insert,luego aumenta el orden cambia los valores 
	int arr[] = {8,3,1,6,4,7,10,14,13};
	for(int i=0; i<9; i++){
		a.insert(arr[i]);
	}
	a.in_orden(a.root);space
	//In(a.root,10,in);
	//On(a.root,3,on);
	cout<<"in: "<<in<<endl;
	cout<<"on: "<<on<<endl;
	 return 0;
 }