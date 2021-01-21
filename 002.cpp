/*lista enlazadan simple con find(de dos puneteros)*/
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class nodo{
    public:
    T info;
    nodo* sig;
    nodo(T info){this->info=info;sig =NULL;}
};

template<typename T>
class lista{
public:
  nodo<T> *start;

  lista(){
	start=NULL;}

  bool find(T x,nodo<T>**&p){
	p=&start;
	while(*p && (*p)->info<x){
		p=&((*p)->sig);
	}	
	return *p && (*p)->info ==x;
	}

  bool insertar(T x){
	nodo<T>** p;
	if(find(x,p)){
		return 0;
		}
	nodo<T> * w;
	w =new nodo<T>(x);
	w->sig=*p;
	*p=w;
	return 1;
	}

  bool eliminar(T x){
	nodo<T>** p;
	if(!find(x,p)){
		return 0;
		}
	nodo<T> * tmp;
	tmp = (*p)->sig;
	delete *p;
	*p=tmp;
	return 1;
	}
	

  void print_lista(){
	nodo<T>* cent;
	cent =start;
	if(cent){
	while(cent){
		cout<<(cent)->info<<"-> "; (cent) =(cent)->sig;
		}cout <<"NULL"<<endl;
	}
  else{
	  cout <<"lista vacia"<<endl;
  }
  }
  ~lista(){
        cout<<"delete"<<endl;
        while(start){
            eliminar(start->info);
        }
  }
};

int main(){
	 lista<int> a;
     int opcion=0,valor;
	 cout<<"      **        "<<endl;
     cout<<"    Insertar [1]"<<endl;
     cout<<"    Borrar   [2]"<<endl;
     cout<<"    Salir    [3]"<<endl;
    do{
         cout<<"Opcion: ";
         cin>>opcion;
        if(opcion == 1){
            cout<<"> ";cin>>valor;
            a.insertar(valor);
            a.print_lista();
        }
        if(opcion == 2){
            cout<<"> ";cin>>valor;
            a.eliminar(valor);
            a.print_lista();
        }
    }while(opcion!=3);

    a.print_lista();
    return 0;
}//183279
//