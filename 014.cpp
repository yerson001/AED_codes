/*cola de prioridades con insert mostrar y remove*/
#include<iostream>
using namespace std;

template<class T>
class nodo{
public:
    T dato;
    T priori;
    T def;
    nodo<T>*next;
    nodo(T x, T pri){   dato = x; priori = pri;
                        next = nullptr; def=0;
    }
};

template<class T>
class cola{
public:
    nodo<T>*head;
    cola(){head=nullptr;}
    void find(T x,T pri,nodo<T>**&p){
        if(pri){
            p = &head;
            while(*p && (*p)->priori<pri){
                p = &((*p)->next);
            }
        }
        else{
             p = &head;
            while(*p && (*p)->dato!=x){
                p = &((*p)->next);
            }
        }
    }
    bool insert(T x, T pri){
        nodo<T>**p,*w;
        find(x,pri,p);
        w = new nodo<T>(x,pri);
        w->next = (*p);
        (*p) = w;
        return 1;
    }
    bool remove(T x){
        nodo<T>**p;
        nodo<T>*w;
        find(x,0,p);
        w = (*p)->next;
        delete (*p);
        (*p) = w;
        return 1;
    }
    void print(){
        if(head){
            nodo<T>*i = head;
            while(i){
                cout<<"   "<<i->dato<<"  |  "<<i->priori<<endl;
                i = i->next;
            }
        }else{
            cout<<"     VACIA    "<<endl;
        }
    }
};

int main(){
    cola<int> a;
    int opcion;
    do{
        cout<<"INSERT[1] MOSTRAR[2] ELININAR[3] SALIR[4]"<<endl;
        cout<<"OPCION: ";cin>>opcion;
        if(opcion==1){
            int dato,prio;
            cout<<"Dato: ";cin>>dato;
            cout<<"Prio: ";cin>>prio;
            a.insert(dato,prio);
        }
        if(opcion==2){
            cout<<" DATO  PRIO"<<endl;
            a.print();
        }
        if(opcion==3){
            int dato;
            cout<<"Dato: ";cin>>dato;
            a.remove(dato);
        }
    }while(opcion!=4);
    
    return 0;
}















