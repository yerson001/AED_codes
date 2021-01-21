#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
class nodo{
public:
T info;
int altura;
nodo<T>* hijos[2];

nodo(T info){
    this->info=info;
    altura=1;
    hijos[0] =NULL;
    hijos[1] =NULL;
    }

};

template<typename T>
class Arbol_AVL{
public:
  nodo<T> *root;

    Arbol_AVL(){root=NULL;}

      bool find(T x,nodo<T>**&p,stack<pair <nodo<T>**,bool> > & camino){
              p=&root;
              camino.push(make_pair(&root,0));//q dir al root?--doesn't matter
              //cout<<"x";
              while(*p && (*p)->info != x){
                  //cout<<"p";
                  bool dir=(*p)->info < x;
                  p=&((*p)->hijos[dir]);
                  camino.push(make_pair(p,dir));
                  }
              return *p;
              }

      int Alturas(nodo<T>* yop){
          if(yop->hijos[0] && yop->hijos[1])
            {return yop->hijos[0]->altura - yop->hijos[1]->altura;}
          return yop->hijos[yop->hijos[1] != nullptr]->altura;
      }


       void balanceo(stack<pair <nodo<T>**,bool> >& camino){
           pair <nodo<T>**,bool> hijo, padre;
               int diferencia;
               while(camino.size() > 1){
               padre = camino.top();
               camino.pop();

               diferencia = Alturas(*camino.top().first);
               if(diferencia == 0) return;

               if(diferencia == 1 or diferencia == -1){
                   if((*padre.first)->altura + 1 > (*camino.top().first)->altura)
                   (*camino.top().first)->altura++;
                   hijo = padre;
               }
               else if(diferencia == 2 or diferencia == -2){
                   if(hijo.second != padre.second){
                      // cout<<"\nRL v LR\n";
                       bool dir_padre=padre.second;
                       nodo<T>* w=(*padre.first);
                       (*padre.first)=(*padre.first)->hijos[!dir_padre];
                       w->hijos[!dir_padre]=(*padre.first)->hijos[dir_padre];
                       (*padre.first)->hijos[dir_padre]=w;
                        swap(w->altura,(*padre.first)->altura);
                       //hijo = padre;
                   }
                       //cout<<"\nRR v LL\n";
                       nodo<T>** abuelo=(camino.top()).first;
                       bool dir_padre=padre.second;
                       (*abuelo)->altura--;
                       nodo<T>* w=(*abuelo);
                       (*abuelo)=(*(padre.first));
                       w->hijos[dir_padre]=(*(padre.first))->hijos[!dir_padre];
                       (*abuelo)->hijos[!dir_padre]=w;

                }
               }
       }

      bool insertar(T x){
        //cout<<"nodo_in:"<<x<<endl;
        nodo<T>** p;
        stack<pair <nodo<T>**,bool> > camino;
        if(find(x,p,camino)){
            return 0;}
        *p=new nodo<T>(x);
        //cout<<"camino guardado:\t";
        //cout<<" camino_size "<<camino.size()<<endl;
        
        if(camino.size() > 1){
            balanceo(camino);
        }
        
        return 1;
        }

    nodo<T>** Intercambio(nodo<T>** q ){
        q = &(*q)->hijos[0];
        while ((*q)->hijos[1])
        {
            q = &((*q)->hijos[1]);
        }
        return q;
    }
	bool find(T x,nodo<T>**&p){
        p=&root;
        while( (*p )&& (*p)->info != x){
          p=&((*p)->hijos[(*p)->info < x]);
        }
        return *p;
    }      

     bool Remover(T x){
        nodo<T>**p, **q;
        stack<pair <nodo<T>**,bool> > camino;
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
        nodo<T>* t = *p;
        *p = (*p)->hijos[(*p)->hijos[1]!=0];
        delete t;
        return 1;
    }

    void mostrar_(){
		string ancho = to_string(root->info);
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

		
		vector<nodo<T>*> vec;
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

int main(){
	Arbol_AVL<int> a;
	int arr[] = {5,9,7,4,3,1,6};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
		a.insertar(arr[i]);
        a.mostrar_();cout<<endl;
	}
	return 0;
}