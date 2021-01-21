/*matriz esparsa*/
#include <iostream>
using namespace std;

template<typename T>
class nodo_smx{
public:
    T m_data;
    int x_data,y_data;
    nodo_smx<T>* next;
    nodo_smx<T>* down;

nodo_smx(T info, int x ,int y){
    this->m_data=info;
    this->x_data=x;
    this->y_data=y;
    next=down=NULL;
    }
};

template<typename M>
class nodo_temp{
public:
    typedef typename M:: Tt T;
    T info;
    int x_,y_;
    M* matrix;

nodo_temp(T info, int x ,int y, M* ma ){
    this->info=info;
    this->x_=x;
    this->y_=y;
    matrix =ma;
    }
 operator T();
 nodo_temp<M>& operator =(T dato){
        cout<<"dato:"<<dato;
        cout<<"\t"<<info<<" ("<<x_<<" , "<<y_<<")"<<endl;
        if(dato == matrix->var_nul){
            matrix->eliminar(x_,y_);
        }else{
            matrix->insertar(x_,y_,dato);
        }
        return *this;
    }

 nodo_temp<M>& operator =(nodo_temp<M> dato){
        cout<<"dato:"<<dato;
        cout<<"\t"<<info<<" ("<<x_<<" , "<<y_<<")"<<endl;
        if(dato == matrix->var_nul){
            matrix->eliminar(x_,y_);
        }else{
            matrix->insertar(x_,y_,dato);
        }
        return *this;
    }
};

template<typename M>
nodo_temp<M>::operator T(){
    return info;
}


template<typename T>
class lista_smx {
public:
  nodo_smx<T> *head;

  lista_smx(){
    head=nullptr;}

  bool insert_x(int i,int j,T dato,nodo_smx<T> ** p);
  bool insert_y(nodo_smx<T> ** p);
  bool remove_x(nodo_smx<T> ** p);
  bool remove_y(nodo_smx<T> ** p);

};

template<typename T>
bool lista_smx<T>:: insert_x(int i,int j,T dato,nodo_smx<T> ** p){
    nodo_smx<T>* w;
    w=new nodo_smx<T>(i,j,dato);
    w->next=*p;
    *p=w;
    return 1;
}

template<typename T>
bool lista_smx<T>:: insert_y(nodo_smx<T> ** p){
    nodo_smx<T>* w;
    if(head == nullptr){
        head=w;
    }else{
        w->down=*p;
        *p=w;
        return 1;
    }
}

template <class T,int filas, int columnas,T nulo_char >
class Csparsa{
public:

    typedef Csparsa<T,filas,columnas,nulo_char> self;
    typedef T  Tt;

    T var_nul =nulo_char;

    nodo_smx<T>* x_[filas];
    nodo_smx<T>* y_[columnas];

    Csparsa(){
        for(int i=0;i<filas;i++){
            x_[i]=0;
        }
        for(int i=0;i<columnas;i++){
            y_[i]=0;
        }
    }
    bool insertar( int i, int j,T dato);
    bool eliminar(int i, int j);
    void debug_fila(nodo_smx<T> * cent);
    bool find_x(int i,int j,nodo_smx<T> ** &p);
    bool find_y(int i,int j,nodo_smx<T> ** &p);
    void print_matrix_x();
    void print_matrix_y();
    //T operator()(int i, int j);
    nodo_temp<self> operator()(int i, int j);
    /*nodo_smx<T>& operator()(int i, int j){
       return insertar(i,j,0);
    }*/

};

template <class T, int filas, int columnas ,T nulo_char>
inline bool Csparsa<T,filas ,columnas,nulo_char > ::insertar(int i, int j,T dato) { // Probar enviar en ptr al pseudonodo
    nodo_smx<T> **ptr;
    //cout<<"dato in:"<<dato<<endl;
    if(i >= 0 && i< filas && j>=0 && j<columnas){
        if(find_x(i,j,ptr)) { //si lo encuentra, ya existe, entonces cambio su valor
            if(dato == nulo_char){
                eliminar(i,j);
            }else{
                (*ptr)->m_data = dato;
                return 1;
            }

            return 0;
        }
        else {
            nodo_smx<T> *tmp = new nodo_smx<T>(dato,i,j);
            tmp->down = *ptr;
            *ptr = tmp;

            find_y(i,j,ptr);
            tmp->next = *ptr;
            *ptr = tmp;

            return 1;
        }
    }else{
        cout<<"\nout of range\n";

       return 0;
    }

    }

template <class T, int filas, int columnas ,T nulo_char>
inline bool Csparsa<T,filas ,columnas,nulo_char > ::eliminar(int i, int j){
    nodo_smx<T> **ptrY;
    nodo_smx<T> **ptrX;
    if(!find_y(i,j,ptrY))
        {return 0;}

    find_x(i,j,ptrX);
    nodo_smx<T> *tmpY = (*ptrY)->down;
    nodo_smx<T> *tmpX = (*ptrX)->next;
    delete *ptrY;
    *ptrY = tmpY;
    *ptrX = tmpX;
    //cout<<"s";
    return true;
}

template <class T, int filas, int columnas ,T nulo_char>
inline void Csparsa<T,filas ,columnas,nulo_char > ::debug_fila(nodo_smx<T> * cent){
    while(cent){
        cout<<cent->m_data;
        cout<<"-> ";
            cent =cent->next;
            }
}

template <class T, int filas, int columnas,T nulo_char >
inline bool Csparsa<T, filas ,columnas , nulo_char> ::find_x(int i,int j,nodo_smx<T> ** &p){
        p=&(x_[i]);
        while(*p && (*p)->y_data<j ){
            p=&((*p)->next);
        }
        return *p && (*p)->y_data == j ;
}

template <class T, int filas, int columnas,T nulo_char >
inline bool Csparsa<T, filas ,columnas , nulo_char> ::find_y(int i,int j,nodo_smx<T> ** &p){
        p=&(y_[j]);
        while(*p && (*p)->x_data<i){
            p=&((*p)->down);
        }
        return *p && (*p)->x_data == i ;
}

template <class T, int filas, int columnas ,T nulo_char>
inline void Csparsa<T, filas ,columnas,nulo_char > :: print_matrix_x(){
    cout<<"\n";
    for(int i =0;i < filas;i++){
        cout<<"\t";
        //cout<<i;
        //debug_fila(x_[i]);
        int cont =0;
        nodo_smx<T>* q=x_[i];
        while(q){
            while(q->y_data>cont){
                cout<<nulo_char<<" ";
                cont++;
            }
            cout<<q->m_data<<" ";
            q=q->next;
            cont++;
        }
        while(columnas-cont>0){
            cout<<nulo_char<<" ";
            cont++;
        }
        cout<<"\n";
    }
    cout<<"\n";
}

template <class T, int filas, int columnas ,T nulo_char>
inline void Csparsa<T, filas ,columnas,nulo_char > :: print_matrix_y(){
    for(int i =0;i < columnas;i++){
        int cont =0;
        nodo_smx<T>* q=y_[i];
        while(q ){
            while(q->x_data>cont){
                cout<<nulo_char<<" ";
                cont++;
            }
            cout<<q->m_data<<" ";
            q=q->down;
            cont++;
        }
        while(filas-cont>0){
            cout<<nulo_char<<" ";
            cont++;
        }
        cout<<"\n";
    }
}


template <class T, int filas, int columnas ,T nulo_char>
nodo_temp<Csparsa<T, filas ,columnas,nulo_char >> Csparsa<T, filas ,columnas,nulo_char > :: operator()(int i, int j){
    nodo_smx<T>** p;
    T f;
    if(find_x(i,j,p)){
        f=(*p)->m_data;
    }else{
        f=nulo_char;
    }
    return nodo_temp<self> (f,i,j,this);
}

template <class T, int filas, int columnas ,T nulo_char>
void sumar(Csparsa<T,filas,columnas,nulo_char> A,Csparsa<T,filas,columnas,nulo_char> B){
    cout<<"\nLa suma es\n";
    for(int i =0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<A(i,j)+B(i,j)<<" ";
            //cout<<(*(*(A+i)+j))+(*(*(B+i)+j))<<" ";
        }
        cout<<endl;
    }
}

template <class T, int filas, int columnas ,T nulo_char>
void restar(Csparsa<T,filas,columnas,nulo_char> A,Csparsa<T,filas,columnas,nulo_char>  B){
    cout<<"\nLa resta es\n";
    for(int i =0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<A(i,j)-B(i,j)<<" ";
            //cout<<(*(*(A+i)+j))-(*(*(B+i)+j))<<" ";
        }
        cout<<endl;
    }
}

template <class T, int filas, int columnas ,T nulo_char>
void mult(Csparsa<T,filas,columnas,nulo_char> A,Csparsa<T,filas,columnas,nulo_char> B,Csparsa<T,filas,columnas,nulo_char> C,int filas_A, int columnas_B, int columnas_A){
    cout<<"\nLa multiplicacion es\n";
    for(int i=0; i<filas_A; i++){
        for(int j=0; j<columnas_B; j++){
            C(i,j)=0;
            // *(*(C+i)+j)=0;
            for(int z=0; z<columnas_A; z++){
                T mul =A(i,z)*B(z,j);
                C(i,j)= mul;
                //*(*(C+i)+j) += *(*(A+i)+z) * *(*(B+z)+j);
            }
        }
    }
}
template <class T, int filas, int columnas ,T nulo_char>
void print_matriz(Csparsa<T,filas,columnas,nulo_char> B, string nombre){
cout<<"Matriz: "<<nombre<<endl;
    for(int i =0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            //cout<<*(*(pm+i)+j)<<" ";
            cout<<B(i,j)<<" ";
        }
        cout<<endl;
    }

}

void preguntar(int*opcion,int*opcion2){
    cout<<"\ndesea poner un numero o un random? 0: numero repetido  1:random \n";
    cin>>*opcion;
    if(*opcion==0){
        cout<<"Que numero?\n";
        cin>>*opcion2;
    }else{
        cout<<"el random ira de 0 a ...?\n";
        cin>>*opcion2;
    }
}


int main()
{
    ///m(3,3);
    ///m(3,3)=8;
    ///a=m(3,3);

    cout<<" --- S.P.A.R.S.A. Matrix ---\n";
   // Csparsa<char,4,6,64> The;
    Csparsa<int ,4,6,0> The;

    cout<<"\nMatriz A \n";
    The.print_matrix_x();//matrix vacia

    for(int i =0;i<4;i++){
        for(int j=0;j<6;j++){
            The.insertar(i,j,i+1);
        }
    }

    The.insertar(0,0,0);
    The.print_matrix_x();

    cout<<"THE[2][2]    : "<<The(2,2)<<endl;//it WORKS
    int gg;
    gg =The(2,2);//it WORKS
    cout<<"THE[2][2] +2 : "<<gg+2;
    gg =The(2,8);//it WORKS
    cout<<"\nTHE[2][8]    :"<<gg<<" out of range\n";
    cout<<"THE[2][2]    : "<<The(2,2)<<endl;//it WORKS


    for(int i=0;i<4;i++){
        The.eliminar(i,3);}
    cout<<"\n";
    The.print_matrix_x();cout<<"\n";
    cout<<"\n y la traspuesta; xD\n";
    The.print_matrix_y();//la traspuesta

        The.insertar(1,3,'+');
        The.print_matrix_x();cout<<"\n";

    The(2,2)=8;
    The(2,4)=6;
    The(0,1)=The(2,2);
    The.print_matrix_x();
    cout<<"\n finite \n";
/*
print_matriz(The,"The");
Csparsa<int,4,6,-1> B;
print_matriz(B,"B");
sumar(The,B);
restar(The,B);
cout<<"THE END =P"<<endl;
  */  return 1;
}