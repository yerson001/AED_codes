/*lista enlazada simple
con find de un puntero fint(int x, nodo<int>*&p)*/

#include<iostream>
using namespace std;

template<typename T>
class nodo{
public:
    T valor;
    nodo<T>*next;
    nodo(T x){valor = x; next = nullptr;}
    ~nodo(){
            cout<<"nuerto"<<endl;
  }
};

template<typename T>
class lista{
public:
    nodo<T>*head = nullptr;
    bool find(T x,nodo<T>*&pos){
        pos = nullptr;
        for(nodo<T>*p = head; p && p->valor <= x; pos = p, p = p->next){
            if(p->valor == x) return 1;
        }
        return 0;
    }

    bool insert(T x){
        nodo<T>*pos;
        nodo<T>*t;
        if(head==nullptr){
            head = new nodo<T>(x);
        }
        else{
            if(!find(x,pos)){
                t = new nodo<T>(x);
                if(pos==nullptr){
                    t->next = head;
                    head = t;
                }
                else{
                    t->next = pos->next;
                    pos->next = t;
                }
            }
        }
      return 1;
    }
    bool Delete(T x){
        nodo<T>*pos = head;
        nodo<T>*prev = nullptr; 
        if(pos){
            while(pos && pos->valor != x){
                prev = pos;
                pos = pos->next;
            }
        if(!pos){
            cout <<"el valor no esta en la lista"<<endl;
        }
        else if(!prev){
            head = head->next;
            delete pos;
        }
        else{
            prev->next = pos->next;
            delete pos; 
        }
        }
        else{
            cout<<"-----"<<endl;
        }
        return 1;
    }

    void show(){
        nodo<T>*p = head;
        if(p){
            while(p){
                cout <<p->valor<<" -> ";
                p = p->next;
            }cout <<" null"<<endl;
        }
        else{
            cout<<"no hay elementos "<<endl;
            return;
        }
    
    }
      ~lista(){
        cout<<"delete"<<endl;
        while(head){
            Delete(head->valor);
        }
    }
};

void interface(){
     lista<int> a;
     int opcion,valor;
     cout<<"Insertar[1]"<<endl;
     cout<<"Borrar[2]"<<endl;
     cout <<"Mostrar[3]"<<endl;
     cout<<"Salir[4]"<<endl;
     cout<<"Opcion: ";cin>>opcion;
    
        if(opcion == 1){
            cout<<"> ";cin>>valor;
            a.insert(valor);
            a.show();
        }
        else if(opcion == 2){
            cout<<"> ";cin>>valor;
            a.Delete(valor);
            a.show();
        }
        else if(opcion == 3){
            a.show();
        }
     }

int main(){
     lista<int> a;
     int opcion=0,valor;
     cout<<"      *      "<<endl;
     cout<<"    Insertar [1]"<<endl;
     cout<<"    Borrar   [2]"<<endl;
     cout<<"    Salir    [3]"<<endl;
    do{
         cout<<"Opcion: ";
         cin>>opcion;
        if(opcion == 1){
            cout<<"> ";cin>>valor;
            a.insert(valor);
            a.show();
        }
        if(opcion == 2){
            cout<<"> ";cin>>valor;
            a.Delete(valor);
            a.show();
        }
    }while(opcion!=3);

    a.show();

    return 0;
}