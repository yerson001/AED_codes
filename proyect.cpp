#include <iostream>
#include <windows.h>
#include <vector>
#include <string>  // stoi()  "89"  = 89

using namespace std;

//vector new teaches
vector<string > nombreP;
vector<string > direccionP;
vector<string>    celularP;
vector<string > profecionP;
vector<string > passwordP;
vector<string > codigoP;
vector<vector<string> >cursos_profesor;
//=======================
//vector alumno
vector<string >nombreA;
vector<int> edadA;
vector<string> carreraA;
vector<string > codigoA;
//=======================
//vector de new course
vector<string > codigoC;
vector<string > nombreC;
vector<int > ncreditos;
vector<string > facultad;
vector<string > tipoC;
//cofigo del profesor existente
//===============================

//   Matricula
vector<string> alumno;
vector<string> curso;
//assistencia
vector<string> asistencia;
//vector<string> codigo_matricula;
vector<int> n_vez;
vector<bool> state;

//asistencia
vector<string> name_asitencia;
vector<string> sino;
//
vector<string > mat2;
vector<string> mat_asis;
vector<string > algebr;
vector<string> alge_asis;
vector<string > infor;
vector<string> info_asis;



void precargados(){
	//profesores
	nombreP.push_back("hugo");
	nombreP.push_back("daniel");
	nombreP.push_back("victor");
	//direccion
	direccionP.push_back("322");
	direccionP.push_back("123");
	direccionP.push_back("321");
	//cel
	celularP.push_back("111111111");
	celularP.push_back("111111112");
	celularP.push_back("111111113");
	//profecion
	profecionP.push_back("aaa");
	profecionP.push_back("bbb");
	profecionP.push_back("ccc");
	//passwo
	passwordP.push_back("123");
	passwordP.push_back("321");
	passwordP.push_back("1234");
	//cidigo
	codigoP.push_back("123456");
	codigoP.push_back("123457");
	codigoP.push_back("123458");
	//===========alumnos=================
	nombreA.push_back("lucas");
	nombreA.push_back("noa");
	nombreA.push_back("Pablo ");
	//edad
	edadA.push_back(23);
	edadA.push_back(24);
	edadA.push_back(17);
	//carrera
	carreraA.push_back("ccomp");
	carreraA.push_back("ccomp1");	
	carreraA.push_back("ccomp2");
	//codigo
	codigoA.push_back("125600");
	codigoA.push_back("123570");
	codigoA.push_back("123580");
	codigoA.push_back("345600");
	codigoA.push_back("125700");
	codigoA.push_back("123480");
	codigoA.push_back("103480");
	//cursos
	codigoC.push_back("123456");
	codigoC.push_back("654321");
	codigoC.push_back("123654");
	//nombre curso
	nombreC.push_back("matematica II");
	nombreC.push_back("algebra ");
	nombreC.push_back("movil ");
	nombreC.push_back("Informatica");
	nombreC.push_back("Desarrollo app");
	//numcredito
	ncreditos.push_back(4);
	ncreditos.push_back(3);
	ncreditos.push_back(8);
	//facultal
	facultad.push_back("ing");
	facultad.push_back("ing1");
	facultad.push_back("ing2");
	//tipo
	tipoC.push_back("e");
	tipoC.push_back("o");
	tipoC.push_back("o");

	//matriculados previos
	alumno.push_back("juan");
	alumno.push_back("noa");
	alumno.push_back("luis");
	alumno.push_back("leo");
	alumno.push_back("juanito");
	alumno.push_back("lucho");
	alumno.push_back("lucas");
	//cursos
	curso.push_back("matematica II");
	curso.push_back("algebra");
	curso.push_back("Informatica ");
	curso.push_back("algebra");
	curso.push_back("Informatica ");
	curso.push_back("matematica II");
	curso.push_back("Informatica ");
	//veces mat
	n_vez.push_back(3);
	n_vez.push_back(2);
	n_vez.push_back(1);
	n_vez.push_back(3);
	n_vez.push_back(2);
	n_vez.push_back(1);
	n_vez.push_back(3);
	//stado
	state.push_back(1);
	state.push_back(0);
	state.push_back(1);
	state.push_back(1);
	state.push_back(0);
	state.push_back(1);
	state.push_back(1);

//********************************************
//********************************************
//para los cursos  mate
	mat2.push_back("juan");
	mat2.push_back("noa");
	mat2.push_back("leo");
	mat2.push_back("lucas");
	mat2.push_back("pio");
	mat2.push_back("carlos");
	mat2.push_back("sebas");

	mat_asis.push_back("6");
	mat_asis.push_back("17");
	mat_asis.push_back("14");
	mat_asis.push_back("20");
	mat_asis.push_back("14");
	mat_asis.push_back("12");
	mat_asis.push_back("20");
//********************************
//            alge
	algebr.push_back("juan");
	algebr.push_back("noa");
	algebr.push_back("leo");
	algebr.push_back("lucas");
	algebr.push_back("pio");
	algebr.push_back("carlos");
	algebr.push_back("sebas");

	alge_asis.push_back("12");
	alge_asis.push_back("10");
	alge_asis.push_back("14");
	alge_asis.push_back("20");
	alge_asis.push_back("29");
	alge_asis.push_back("18");
	alge_asis.push_back("22");
//******************************
//         informatica
	infor.push_back("juan");
	infor.push_back("noa");
	infor.push_back("leo");
	infor.push_back("lucas");
	infor.push_back("pio");
	infor.push_back("carlos");
	infor.push_back("sebas");

	info_asis.push_back("21");
	info_asis.push_back("13");
	info_asis.push_back("15");
	info_asis.push_back("26");
	info_asis.push_back("1");
	info_asis.push_back("28");
	info_asis.push_back("18");


}

int color[7] = {0x00,0x00E,0x00C,0x002,0x00B,0x005,0x00F};

void setCColor(int color){
	static HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color | (0 * 0x10 + 0x100));
}

void gotoxy(int x, int y){
		HANDLE hCon;
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hCon, dwPos);
}

void limites(){
		system("cls");
		setCColor(color[2]);
		for(int x=0; x<=79; x++){
			gotoxy (x,0);
			printf("%c", 220);
			gotoxy (x,24);
			printf("%c", 220);
	}
			
		for(int y=1; y<=24; y++){
			gotoxy (0,y);
			printf("%c", 219);
			gotoxy (79,y);
			printf("%c", 219);
		}setCColor(color[6]);
}
void menu(){ setCColor(color[2]);
		gotoxy(24,3);cout<<"\tSISTEMA DE ASISTENCIAS"<<endl;
		gotoxy(24,4);cout<<"\t----------------------"<<endl;
		gotoxy(24,5);cout<<"\t        ucsp          "<<endl;
		gotoxy(24,6);cout<<"\t       ------         "<<endl;
		cout<<endl<<endl<<endl;
		setCColor(color[6]);
				
		gotoxy(10,7);cout<<"1. INSERCIONES"<<endl;
		gotoxy(15,8);cout<<"\t a.NUEVOS PROFESORES"<<endl;
		gotoxy(15,9);cout<<"\t b.NUEVOS ALUMNOS"<<endl;
		gotoxy(15,10);cout<<"\t c.NUEVOS CURSOS"<<endl;
		gotoxy(10,11);cout<<"2. MATRICULAS"<<endl;
		gotoxy(15,12);cout<<"\t a.MATRICULAR ALUMNO EN CURSO"<<endl;
		gotoxy(15,13);cout<<"\t b.ELIMINAR MATRICULA"<<endl;
		gotoxy(10,14);cout<<"3. TOMA DE ASISTENCIAS"<<endl;
		gotoxy(10,15);cout<<"4. REPORTE"<<endl;
		gotoxy(15,16);cout<<"\t a.ASISTENCIA POR CURSO"<<endl;
		gotoxy(15,17);cout<<"\t b.ASISTENCIA POR MATRICULA"<<endl;
		gotoxy(15,18);cout<<"\t c.LISTADO DE INHABILITADOS PARA FINAL"<<endl;
		gotoxy(10,19);cout<<"5. SALIR"<<endl;
		gotoxy(10,20);cout<<"Ingrese opcion: ";
		setCColor(color[6]);
}	
void  registros(){
	gotoxy(24,3);cout<<"REGISTROS"<<endl;
	gotoxy(10,4);cout<<">> 1.Nuevos Profesores "<<endl;
	gotoxy(10,5);cout<<">> 2.Nuevos Alumnos "<<endl;
	gotoxy(10,6);cout<<">> 3.Nuevos cursos "<<endl;
	gotoxy(10,7);cout<<">> 4.Volver a menu "<<endl;
	gotoxy(10,8);cout<<"Opcion: ";
}
bool buscar_name(vector<string > tabla,string dato){
	for(int i=0; i<tabla.size(); i++){
		if(tabla[i]==dato){
			return 1;
		}
	}
	return 0;
}
void mostrar_cursos_dis(){
	gotoxy(36,4);cout<<"CURSOS"<<endl;
	for(int i=0; i<curso.size(); i++){
		gotoxy(36,5+i);cout<<curso[i];
	}
}

void ingresar_registro(){
	system("cls");
	limites();
	string nombre,direccion,profecion,passwor,codigop,cel;
	gotoxy(24,3);cout<<"REGISTROS"<<endl;
		gotoxy(10,4);cout<<"Nombre y apellido: ";
		cin>>nombre;
		while(buscar_name(nombreP,nombre)){
			gotoxy(10,5);cout<<"Usuario ya existe ingrese otro"<<endl;
			gotoxy(10,4);cout<<"Nombre y apellido: ";
			cin>>nombre;
		}
		nombreP.push_back(nombre);
		//---------------------------
		gotoxy(10,5);cout<<"Direccion: ";
		cin>>direccion;
		direccionP.push_back(direccion);
		//---------------------------
		gotoxy(10,6);cout<<"Celular: ";
		cin>>cel;
		while(cel.size()!=9){
			gotoxy(10,7);cout<<"9 digitos"<<endl;
		    gotoxy(10,6);cout<<"Celular: ";cin>>cel;
		}
		celularP.push_back(cel);
		//---------------------------
		mostrar_cursos_dis();
		gotoxy(10,8);cout<<"Profesion: ";
		cin>>profecion;
		while(!!buscar_name(curso,profecion)){
			gotoxy(10,9);cout<<"curso no existe "<<endl;
			gotoxy(10,8);cout<<"curso: ";
			cin>>profecion;
		}
		profecionP.push_back(profecion);
		//---------------------------
		gotoxy(10,9);cout<<"password: ";
		cin>>passwor;
		while(passwor.size()!=6){
			gotoxy(10,10);cout<<"password 6 digitos"<<endl;
			gotoxy(10,9);cout<<"password: ";cin>>passwor;
		}
		passwordP.push_back(passwor);
		//---------------------------
		gotoxy(10,11);cout<<"Codigo: ";
		cin>>codigop;
		codigoP.push_back(codigop);
}
void mostrarP(){
	system("cls");
	limites();
	gotoxy(24,3);cout<<"REGISTROS"<<endl;
	for(int i=0; i<nombreP.size(); i++){
		gotoxy(10,5);cout<<"nombres  :"<<nombreP[i]<<endl;
		gotoxy(10,6);cout<<"Direccion:"<<direccionP[i]<<endl;
		gotoxy(10,7);cout<<"cel      :"<<celularP[i]<<endl;
		gotoxy(10,8);cout<<"profes   :"<<profecionP[i]<<endl;
		gotoxy(10,9);cout<<"passw    :"<<passwordP[i]<<endl;
		gotoxy(10,10);cout<<"codigo   :"<<codigoP[i]<<endl;
	}
}
void ingresar_registro_A(){
	system("cls");
	limites();
	string nombre,carrera,codigo;
	int edad;
		gotoxy(24,3);cout<<"REGISTROS"<<endl;
		gotoxy(10,4);cout<<"Nombre y apellido: ";
		cin>>nombre;
		while(buscar_name(nombreA,nombre)){
			gotoxy(10,5);cout<<"Usuario ya existe ingrese otro"<<endl;
			gotoxy(10,4);cout<<"Nombre y apellido: ";
			cin>>nombre;
		}
		nombreA.push_back(nombre);
		//---------------------------
		gotoxy(10,5);cout<<"edad: ";
		cin>>edad;
		while(edad<0 || edad>80){
			gotoxy(10,6);cout<<"fuera de rango "<<endl;
			gotoxy(10,5);cout<<"edad: ";
			cin>>edad;
		}
		edadA.push_back(edad);
		gotoxy(10,6);cout<<"Carrera: ";
		cin>>carrera;
		carreraA.push_back(carrera);
		//---------------------------
		gotoxy(10,7);cout<<"Codigo: ";
		cin>>codigo;
		codigoA.push_back(codigo);
}
void mostrarA(){
	system("cls");
	limites();
	gotoxy(24,3);cout<<"REGISTROS"<<endl;
	for(int i=0; i<nombreA.size(); i++){
		gotoxy(10,5);cout<<"nombres  :"<<nombreA[i]<<endl;
		gotoxy(10,6);cout<<"edad     :"<<edadA[i]<<endl;
		gotoxy(10,7);cout<<"carrera  :"<<carreraA[i]<<endl;
		gotoxy(10,8);cout<<"codigo   :"<<codigoA[i]<<endl;
	}
}
void ingresar_registro_C(){
	system("cls");
	limites();
	string codigoc,nombre,facultad_,tipo;int nrocredito;
		gotoxy(24,3);cout<<"REGISTROS"<<endl;
		gotoxy(10,4);cout<<"Codigo: ";
		cin>>codigoc;
		codigoC.push_back(codigoc);
		
		gotoxy(10,5);cout<<"Nombre: ";
		cin>>nombre;
		while(buscar_name(nombreC,nombre)){
			gotoxy(10,6);cout<<"Usuario ya existe ingrese otro"<<endl;
			gotoxy(10,4);cout<<"Nombre: ";
			cin>>nombre;
		}
		nombreC.push_back(nombre);
		//---------------------------
		gotoxy(10,6);cout<<"Creditos: ";
		cin>>nrocredito;
		while(nrocredito<0 || nrocredito>10){
			gotoxy(10,7);cout<<"fuera de rango ";
			gotoxy(10,6);cout<<"Creditos: ";
			cin>>nrocredito;
		}
		ncreditos.push_back(nrocredito);
		//===============================

		gotoxy(10,7);cout<<"facultad: ";
		cin>>facultad_;
		facultad.push_back(facultad_);
		//---------------------------
		gotoxy(10,8);cout<<"Tipo: ";
		cin>>tipo;
		tipoC.push_back(tipo);
		//codigo profesor
}
void mostrarC(){
	system("cls");
	limites();
	gotoxy(24,3);cout<<"REGISTROS"<<endl;
	for(int i=0; i<nombreC.size(); i++){
		gotoxy(10,5);cout<<"CODIGO    :"<<codigoC[i]<<endl;
		gotoxy(10,6);cout<<"NOMBRE    :"<<nombreC[i]<<endl;
		gotoxy(10,7);cout<<"N_CREDITOS:"<<ncreditos[i]<<endl;
		gotoxy(10,8);cout<<"FACULTAD  :"<<facultad[i]<<endl;
		gotoxy(10,9);cout<<"TIPO      :"<<tipoC[i]<<endl;
	}
}
//=======================
void matriculas(){
	gotoxy(24,3);cout<<"MATRICULAS"<<endl;
	gotoxy(10,4);cout<<">> 1.Matricular Alumno en curso"<<endl;
	gotoxy(10,5);cout<<">> 2.Eliminar Matricula "<<endl;
	gotoxy(10,6);cout<<">> 3.Volver a menu "<<endl<<endl;
	gotoxy(10,7);cout<<"opcion: ";
}

void ingresar_registro_m(){
	system("cls");
	limites();
	string nombre,curso_;int n_vezz;bool sta;
		gotoxy(24,3);cout<<"MATRICULAS"<<endl;
		gotoxy(10,4);cout<<"Nombre: ";
		cin>>nombre;
		while(buscar_name(alumno,nombre)){
			gotoxy(10,5);cout<<"Usuario ya existe ingrese otro"<<endl;
			gotoxy(10,4);cout<<"Nombre: ";
			cin>>nombre;
		}
		alumno.push_back(nombre);
		gotoxy(30,4);cout<<"CURSOS DISPONIBLES";
		mostrar_cursos_dis();
		gotoxy(10,6);cout<<"Curso: ";
		cin>>curso_;
		while(!!buscar_name(curso,curso_)){
			gotoxy(10,7);cout<<"curso no existe "<<endl;
			gotoxy(10,6);cout<<"curso: ";
			cin>>curso_;
		}
		curso.push_back(curso_);
		gotoxy(10,8);cout<<"N_vez: ";
		cin>>n_vezz;
		n_vez.push_back(n_vezz);
		gotoxy(10,9);cout<<"Estado(0/1): ";
		cin>>sta;
		state.push_back(sta);
}
void mostrarM(){
	system("cls");
	limites();
	for(int i=0; i<alumno.size(); i++){
		gotoxy(10,5);cout<<"Alumno  :"<<alumno[i]<<endl;
		gotoxy(10,6);cout<<"Curso   :"<<curso[i]<<endl;
		gotoxy(10,7);cout<<"N_vez   :"<<n_vez[i]<<endl;
		gotoxy(10,8);cout<<"Estado  :"<<state[i]<<endl;
	}
}
int posi(vector<string> alumno,string dato){
	for(int i=0; i<alumno.size(); i++){
		if(alumno[i]==dato){
			return i;
		}
	}
	return 0;
}

void mostrar_alu(){
	gotoxy(20,8);cout<<"Matriculados"<<endl;
	for(int i=0; i<alumno.size(); i++){
		gotoxy(20,10+i);cout<<i<<" "<<alumno[i]<<endl;
	}
}

void eliminarM(){
	
	system("cls");
	limites();
	gotoxy(24,3);cout<<"ELIMINAR MATRICULA"<<endl;
	gotoxy(10,4);cout<<"Codigo: ";
	string cod;
	cin>>cod;
	bool verific;

	for(int i=0; i<codigoA.size(); i++){
		if(codigoA[i]==cod){
			gotoxy(10,5);cout<<"USUARIO: "<<nombreA[i];//si el usuario esta en alumno
				if(buscar_name(alumno,nombreA[i])){//significa q tiene matricula
					//cout<<"en alumno"<<endl;
					int pos = posi(alumno,nombreA[i]);
					alumno.erase(alumno.begin()+pos,alumno.begin()+pos+1);
					curso.erase(curso.begin()+pos,curso.begin()+pos+1);
					n_vez.erase(n_vez.begin()+pos,n_vez.begin()+pos+1);
					state.erase(state.begin()+pos,state.begin()+pos+1);
					gotoxy(10,6);cout<<"Se elimino la Matricula"<<endl;
					Sleep(2000);
					verific = 1;
					break;
				}
		}
	}
	if(verific==0){
			gotoxy(10,7);cout<<"UD no tiene matricula o estado es 0"<<endl;
			gotoxy(10,8);system("pause");	
		}

}

//==============tomar asistencia===============
string contrasenia_asistencia(){
	system("cls");
	limites();
	string user,passw;
	bool acceso;
	gotoxy(24,3);cout<<"ASISTENCIA"<<endl;
	gotoxy(10,4);cout<<"*USUARIO    :"; cin>>user;
	gotoxy(10,5);cout<<"*CONTRASENIA:";  cin>>passw;
	if(buscar_name(nombreP,user) && buscar_name(passwordP,passw)){//si existen el usuario y pass
		for(int i=0; i<nombreP.size(); i++){
			if(nombreP[i]==user){
				if(passwordP[i]==passw){
				setCColor(color[3]);
				gotoxy(40,6);cout<<"!!ACCESO"<<endl;
				Sleep(2000);
				setCColor(color[6]);
					return user;
				}

			}
		}
	}
	else{setCColor(color[2]);
		gotoxy(40,6);cout<<"!!ACCESO DENEGADO"<<endl;
		Sleep(2000);
		setCColor(color[6]);
	}
	return "no";
}

void mostrar_curso_pro(int v,int c){
	limites();
	for(int i=v; i<c; i++){
		for(int j=0; j<3; j++){
			gotoxy(15,7+j);cout<<j<<" >>"<<cursos_profesor[i][j];cout<<endl;
		}
		cout<<endl;
	}
	gotoxy(15,13);cout<<"opcion: ";
}

void asignar_curso(){
	   int mm;
		vector<string >aux;
		aux.push_back(nombreP[0]+'\n');//cout<<nombreP[0]<<endl;
		aux.push_back(curso[0]);
		aux.push_back(curso[1]);
		cursos_profesor.push_back(aux);
		aux.erase(aux.begin(),aux.begin()+aux.size());
		//*************************
		aux.push_back(nombreP[1]+'\n');//cout<<nombreP[1]<<endl;
		aux.push_back(curso[2]);
		aux.push_back(curso[0]);
		cursos_profesor.push_back(aux);
		aux.erase(aux.begin(),aux.begin()+aux.size());
		//***********************
}

void saber_matriculados_en_curso(string curs){
	system("cls");
	limites();
	int s=0;
	string asistencia;
	gotoxy(20,4);cout<<"ALUMNOS MATRUCULADOS EN ( "<< curs<<" )"<<endl;
	for(int i=0; i<alumno.size(); i++){
		if(curs==curso[i]){
			gotoxy(10,7+s++);cout<<alumno[i]<<" ASISTIO:(si)/(no): ";
			cin>>asistencia;
			name_asitencia.push_back(alumno[i]);
			sino.push_back(asistencia);
		}
	}
}

void mostrar_asistencias(){
	system("cls");
	limites();
	gotoxy(24,3);cout<<"ASISTENCIAS"<<endl;
	for(int i=0; i<name_asitencia.size(); i++){
		gotoxy(15,4+i);cout<<name_asitencia[i]<<"  "<<sino[i]<<endl;
	}
}

void tomar_asistencia(){
	int opcion;
	if(contrasenia_asistencia()=="hugo"){//mate2 7 algebra
		mostrar_curso_pro(0,1);
		cin>>opcion;
		if(opcion == 1){
			saber_matriculados_en_curso("matematica II");
		}
		if(opcion == 2){
			saber_matriculados_en_curso("algebra");
		}

	}
	
	else if(contrasenia_asistencia()=="daniel"){//informatica mate2
		mostrar_curso_pro(1,2);
		cin>>opcion;
		if(opcion == 1){
			saber_matriculados_en_curso("Informatica");
		}
		if(opcion == 2){
			saber_matriculados_en_curso("matematica II");
		}
	}
}

//opcion 4

void reporte(){
	system("cls");
	limites();
	gotoxy(24,3);cout<<"REPORTE"<<endl;
	gotoxy(10,4);cout<<"1.ASISTENCIA POR CURSO"<<endl;
	gotoxy(10,5);cout<<"2.ASISTENCIA POR MATRICULA"<<endl;
	gotoxy(10,6);cout<<"3.LISTADO DE INHABILITADOS PARA FINAL"<<endl;
	gotoxy(10,7);cout<<"opcion: ";
}


void sort(vector<string> &a){
	for (int i = 0;i < a.size(); i++){
		for (int j = 0; j< a.size()-1; j++){
			if (a[j] > a[j+1]){ 
			swap(a[j],a[j+1]);
			}
		}
	}
}
//*************************************************


vector<string >report;
void reporte_mate(){
	system("cls");
	limites();

	gotoxy(10,4);cout<<"CODIGO        CURSO           NOMBRE       N_ASISTENCIAS"<<endl;
	for(int i=0; i<mat2.size(); i++){
		report.push_back( codigoA[i]+"    "+"MATEMATICA II"+"        "+alumno[i]+"           "+info_asis[i]);
	}
	sort(report);
	for(int i=0; i<report.size(); i++){
		gotoxy(11,6+i);cout<<report[i]<<endl;
	}
	report.erase(report.begin(),report.begin()+report.size());
}

void reporte_alge(){
	system("cls");
	limites();

	gotoxy(10,4);cout<<"CODIGO        CURSO           NOMBRE       N_ASISTENCIAS"<<endl;
	for(int i=0; i<mat2.size(); i++){
		report.push_back( codigoA[i]+"    "+"ALGEBRA II"+"        "+alumno[i]+"           "+alge_asis[i]);
	}
	sort(report);
	for(int i=0; i<report.size(); i++){
		gotoxy(11,6+i);cout<<report[i]<<endl;
	}
	report.erase(report.begin(),report.begin()+report.size());
}
void reporte_info(){
	system("cls");
	limites();

	gotoxy(10,4);cout<<"CODIGO        CURSO           NOMBRE       INA_ASISTENCIAS"<<endl;
	for(int i=0; i<mat2.size(); i++){
		report.push_back( codigoA[i]+"    "+"INFORMATICA "+"        "+alumno[i]+"           "+info_asis[i]);
	}
	sort(report);
	for(int i=0; i<report.size(); i++){
		gotoxy(11,6+i);cout<<report[i]<<endl;
	}
	report.erase(report.begin(),report.begin()+report.size());
}
void asistencia_curso(){
	gotoxy(10,2);cout<<"ALUMNO CODIGO: ";
	string op;
	cin>>op;
	if(buscar_name(codigoA,op)){
		for(int i=0; i<codigoA.size(); i++){
			if(codigoA[i]==op){
				gotoxy(24,3);cout<<alumno[i];
				gotoxy(10,4);cout<<curso[i]<<"         "<<codigoA[i]<<"          "<<(stoi(mat_asis[i])*100)/30<<"%";
				gotoxy(10,5);cout<<curso[i+1]<<"               "<<codigoA[i]<<"        "<<(stoi(info_asis[i])*100)/30<<"%";
				gotoxy(10,6);cout<<curso[i+2]<<"           "<<codigoA[i]<<"        "<<(stoi(alge_asis[i])*100)/30<<"%";
				}
			}
		}
	cout<<endl;
}
void porcentaje_mat(){
	system("cls");
	limites();
	gotoxy(20,4);cout<<"MATEMATICA"<<endl;
	for(int i=0; i<mat_asis.size(); i++){
		if((stoi(mat_asis[i])*100)/30<70){
			gotoxy(10,5+i);cout<<codigoA[i]<<"          "<<mat2[i]<<"         "<<(stoi(mat_asis[i])*100)/30<<"%"<<endl;
		}
	}
	system("pause");
}

void porcentaje_alge(){
	system("cls");
	limites();
	gotoxy(20,4);cout<<"ALGEBRA"<<endl;
	for(int i=0; i<alge_asis.size(); i++){
		if((stoi(alge_asis[i])*100)/30<70){
			gotoxy(10,5+i);cout<<codigoA[i]<<"          "<<algebr[i]<<"         "<<(stoi(alge_asis[i])*100)/30<<"%"<<endl;
		}
	}
	system("pause");
}

void porcentaje_info(){
	system("cls");
	limites();
	gotoxy(20,4);cout<<"INFORMATICA"<<endl;
	for(int i=0; i<alge_asis.size(); i++){
		if((stoi(alge_asis[i])*100)/30<70){
			gotoxy(10,5+i);cout<<codigoA[i]<<"          "<<infor[i]<<"         "<<(stoi(alge_asis[i])*100)/30<<"%"<<endl;
		}
	}
	system("pause");
}

int main(){
	int opcion;
	precargados();	
	//asistencia_curso();
	
			do{
			limites();
		    menu();
		    c
			
			if(opcion == 1){
			//=====REGISTROS============
				int op_registro;
				do{
					limites();
					registros();
					cin>>op_registro;
				if(op_registro==1){
					ingresar_registro();
					mostrarP();
					gotoxy(10,10);
					Sleep(1000);//system("pause");
				}
				else if(op_registro==2){
					ingresar_registro_A();
					mostrarA();
					gotoxy(10,10);
					Sleep(1000);//system("pause");
				}
				else if(op_registro==3){
					ingresar_registro_C();
					mostrarC();
					gotoxy(10,10);
					Sleep(2000);//system("pause");
				}
				}while(op_registro!=4);
			}
			//===========================
			if(opcion==2){
				int op_matri;
		   //=======MATRICULA===============
				do{
					limites();
					matriculas();
					cin>>op_matri;
					if(op_matri == 1){
						ingresar_registro_m();
						mostrarM();
						gotoxy(10,10);
						Sleep(1000);
						//system("pause");
					}
					else if(op_matri==2){
						limites();
						eliminarM();
						mostrar_alu();
						gotoxy(10,10);
						system("pause");
						}

					}while(op_matri!=3);
				}
			if(opcion==3){
				asignar_curso();
				tomar_asistencia();
				mostrar_asistencias();
				gotoxy(10,10);
				Sleep(2000);
				}
			if(opcion==4){
				int opci;
				reporte();
				cin>>opci;
				if(opci==1){//por curso
					int op;
					do{
					system("cls");
					limites();
					gotoxy(24,3);cout<<"REPORTE"<<endl;
					gotoxy(10,4);cout<<"1.MATEMATICA II"<<endl;
					gotoxy(10,5);cout<<"2.ALGEBRA"<<endl;
					gotoxy(10,6);cout<<"3.INFORMATICA"<<endl;
					gotoxy(10,7);cout<<"4.VOLVER MENU"<<endl;
					gotoxy(10,8);cout<<"opcion: ";
					cin>>op;
					if(op==1){
						reporte_mate();
						gotoxy(10,50);
				    	system("pause");
					}
					else if(op==2){
						reporte_alge();
						gotoxy(10,50);
				    	system("pause");
					}
					else if(op==3){
						reporte_info();
						gotoxy(10,50);
				    	system("pause");
					}
					}while(op!=4);
				}
			else if(opci==2){
				system("cls");
				limites();
				asistencia_curso();
				gotoxy(10,50);
				system("pause");
			}
			else if(opci==3){
				
				porcentaje_mat();	
				porcentaje_alge();				
				porcentaje_info();
			}
			}
		}while(opcion!=5);
		system("cls");
	return 0;
}

//nombre_table.erase(nobmre_table.begin()+pos,nombetable.begin()+pos+1)