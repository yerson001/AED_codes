#include <iostream>
#include <time.h>
#include<stack>
#include<vector>
#include<windows.h>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

template<typename T>
struct cFxA{
    int operator()(T n,int size){
        return n % size;
    }

};

template<typename T>
class cFxB{
public:
    int operator()(T n,int size){
        return (n*7) % size;
    }

};


template<typename T>
class nodo_a{
public:
	T info;
	nodo_a<T>* hijos[2];

	nodo_a(T info){
		this->info=info;
		hijos[0] =NULL;
		hijos[1] =NULL;
		}
};

template<typename T>
class Arbol{
public:
  nodo_a<T> *root;
  Arbol(){
      root = nullptr; 
  }
  typedef T value_type;

      bool find(T x,nodo_a<T>**&p){
        p=&root;
        while(*p && (*p)->info != x){
            p=&((*p)->hijos[(*p)->info < x]);
            }
        return *p;
        }

      bool insertar(T x){
        //cout<<"nodo_in:"<<x<<endl;
        nodo_a<T>** p;
        if(find(x,p)){
            return 0;}
        *p=new nodo_a<T>(x);
        return 1;
        }



    nodo_a<T>** Intercambio(nodo_a<T>** q ){
        q = &(*q)->hijos[0];
        while ((*q)->hijos[1])
        {
            q = &((*q)->hijos[1]);
        }
        return q;
    }

     bool eliminar(T x){
        nodo_a<T>**p, **q;
        if (!find(x, p))
        {
            return 0;
        }
        if ((*p)->hijos[0] && (*p)->hijos[1])
        {
            q = Intercambio(p);
            (*p)->info = (*q)->info;
            p = q;
        }
        nodo_a<T>* t = *p;
        *p = (*p)->hijos[(*p)->hijos[1]!=0];
        delete t;
        return 1;
    }

    void print_(){
        if(root == NULL)
            {cout<<"\nEl arbol esta vacio"<<endl;}
        else{
            //cout<<"\nEl arbol impreso  inorden es: "<<endl;
            print_inorden(root);
        }
    }

    void print_inorden(nodo_a<T>* yop){
        if(!yop){return;}
            print_inorden(yop->hijos[0]);
        cout<<yop->info<<" - ";
            print_inorden(yop->hijos[1]);
     }
void mostrar(){
		string ancho = to_string(root->info);
		vector<T> x;
		vector<vector<T> > y;
		stack< pair<nodo_a<T>*, int> > stk;
		stk.push({ root, 0 });
		nodo_a<T>* aux = NULL;
		string str;
		while (!stk.empty()){
			aux = stk.top().first;
			if (!aux) stk.pop();
			else{
				if (stk.top().second == 0){
					str = to_string(aux->info); if (str.size() > ancho.size()) ancho = str;
					stk.top().second++;
					stk.push({ aux->hijos[0], 0 });
				}

				else{
					stk.pop();
					x.push_back(aux->info);
					stk.push({ aux->hijos[1], 0 });
				}
			}
		}
		vector<nodo_a<T>*> vec;
		vector<T> vecaux;
		if (root){
			vec.push_back(root);
			vecaux.push_back(root->info);
		}
		while (vec.size() > 0){
			y.push_back(vecaux);
			vecaux.clear();
			for (int i = 0, aux = vec.size(); i < aux; ++i){
				if (vec[0]->hijos[0]){
					vec.push_back(vec[0]->hijos[0]);
					vecaux.push_back(vec[0]->hijos[0]->info);
				}
				if (vec[0]->hijos[1]){
					vec.push_back(vec[0]->hijos[1]);
					vecaux.push_back(vec[0]->hijos[1]->info);
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

template<typename T>
class nodo{
public:
	T info;
	nodo* sig;

	nodo(T info){
		this->info=info;
		sig =NULL;
		}
};

template<typename T>
class lista{
public:
    typedef T value_type;
  nodo<T> *start;

  lista(){
    start=NULL;}

  bool find(T x,nodo<T>**&p){
    p=&start;
    while(*p && (*p)->info<x){
        p=&((*p)->sig);
        //cout<<".";
    }
    return *p && (*p)->info ==x;
    }

  bool found(T x){
      nodo<T>* cent;
      cent =start;
      while(cent){
          if(cent->info == x){return 1;}
              (cent) =(cent)->sig;
              }
      return 0;
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
        cout<<"no find "<<x<<"\n";
        return 0;
        }
    nodo<T> * tmp;
    tmp = (*p)->sig;
    delete *p;
    *p=tmp;
    return 1;
    }


  void print_(){
    nodo<T>* cent;
    cent =start;
    //cout<<"\nLa lista es:\n";
    while(cent){
        cout<<(cent)->info;
        cout<<"-> ";
            (cent) =(cent)->sig;
            }
    //cout<<endl;
  }

};

template<class Ds>
class Cadaptor{
public:
    typedef typename Ds::value_type Tipo;
    Ds  estruct;

    bool insertar(Tipo x){
        return estruct.insertar(x);
    }
    bool eliminar(Tipo x){
        return estruct.eliminar(x);
    }
    bool buscar(Tipo x){
        return estruct.found(x);
    }
    void imprimir(){
        estruct.print_();
    }
};

template< class T,class Fx,class Ds, int Sz >// T = dato  Fx = funcion dispércion  Ds = adaptaodor SV = tem vector
class ChashTable{
public:
    Ds* m_table[Sz];
    Fx m_f;

    ChashTable(){
        for(int i=0;i<Sz;i++){
            m_table[i]=nullptr; // inicializamos todo con cero el areglo 
        }
    }

    void print_table(){
        for(int i=0;i<Sz;i++){
            cout<<endl<<i<<":";
            if(m_table [i]== nullptr){
                cout<<"--";
            }else{
                m_table[i]->imprimir();
            }
        }
        cout<<"\n";
    }

    bool insert(T info){
         int pos = m_f(info,Sz);
         if(m_table[pos] == nullptr){
              m_table[pos]=new Ds;}
        return m_table[pos]->insertar(info);
        }

    bool remove(T info){
        int pos = m_f(info,Sz);
        if(m_table[pos] == nullptr){
             return 0;}
        return m_table[pos]->eliminar(info);
    }

    bool find(T info){
        int pos = m_f(info,Sz);
        if(m_table[pos] == nullptr){
             return 0;}
        return m_table[pos]->buscar(info);
    }
};



int main()
{
    cout<<" --- TABLAS HASH ---\n";
/*
    //ChashTable<int,cFxB<int>,lista<int>,11> my_hash;
    ChashTable<int,cFxA<int>,Cadaptor<lista<int>>,20> my_hash;

    srand((unsigned)time(NULL));
    int insertado;
    for(int i=0;i<40;i++){
        insertado =rand() % 100;
        my_hash.insert(insertado);
    }
    my_hash.print_table();
*/


    ChashTable<int,cFxA<int>,Cadaptor<Arbol<int>>,20> my_hashB;
    srand((unsigned)time(NULL));
    int inserto;
    for(int i=0;i<10;i++){
        inserto =rand() % 100;
        my_hashB.insert(inserto);
    }
    cout<<"\n\nde arboles con print inorden";
    my_hashB.print_table();
    my_hashB.remove(1);
    my_hashB.print_table(); 
    Arbol<int> a;
    a.mostrar();
	
	return 0;
}