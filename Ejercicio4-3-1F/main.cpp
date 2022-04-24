#include <string>
#include <iostream>
#include <cstdlib>

#define anioact 2021
using namespace std;

/* PRACTICA 4.3.1F LIQUIDACION DE HABERES Corte de Control y
Funciones
Efectuar liquidacion de haberes de una empresa, para lo cual se
suministran los
sig. datos de cada empleado: Nro. Seccion (1/10), Nro. de Empleado
(1/200), Apellido y nombre,
Sueldo, Antiguedad, presentismo, Horas extras (50 y 100%).
Los registros se hallan ordenados por Nro. de Seccion y Nro. de
empleados, en orden ascendente.
Para finalizar: Nro de Seccion igual a 9999. Se pide informar:
a) Por cada empleado: Nro. Legajo, Apellido y Nombre, Sueldo basico,
Antiguedad, presentismo, Horas extras (50 y 100%).
Aporte Jubilatorio (11%), Aporte Obra Social (3%), Aporte INSSJP
(Ley 19032) 3%. Sueldo Neto a cobrar.
b) Por Seccion, Totales de: Sueldos brutos, sueldos netos, cant.
empleados y prom. de sueldos brutos.
c) Totales Generales: Sueldos brutos, Mejor sueldo, Nro. empleado,
Seccion y total de empleados. */

int fsecciones(int,int);
int fempleados(int,int);
float fsueldos(float,float);

int main(int argc, char** argv) {
	string nombre_1;
	int 
	sec,secx,legajo,anioing,qdias,secmax=0,emplsec=0,totemp=0
	,totempg=0,antig,he50,he100,descinas;
	
	float sueldo,present=0,premioant,totsue=0,suegen=0,suemax=0
	,sueneto,jubil=0,obrasoc=0,inssjp=0,totsuenetos
	,imphe50=0,imphe100=0,baseap=0,tothab,totdes,sueldodia
	,descdias;
	
	cout<<"PRACTICA 4.3.1F"<<endl;
	
	sec=fsecciones(0,10);
	
	while(sec!=0)
	{
		secx=sec;
		
		while(sec==secx)
		{
		legajo=fempleados(1,300);	
		
		cout<<"Ingrese nombre del empleado: "<<endl;
		cin>>nombre_1;
		
		cout<<"ingrese el anio de ingreso(4 digitos): "<<endl;
		cin>>anioing;
		
		sueldo=fsueldos(30000,100000);
		
		cout<<"Ingrese cant. horas extras al 50%: "<<endl;
		cin>>he50;
		if(he50>0) imphe50=he50*sueldo/200;
			
		cout<<"Ingrese cant.horas extras al 100%: "<<endl;
		cin>>he100;
		if(he100>0) imphe100=he100*sueldo/200*2;
		
		antig=anioact-anioing;
		if(antig>=10)
			premioant=sueldo*0.10;
		else if(antig>5)
			premioant=sueldo*0.05;
			
		cout<<"Dias de inasistencias: "<<endl;
		cin>>qdias;
		if(qdias>0)
		{
			cout<<"Se descuenta los dias de inasistencias? (NO=0 / SI=1): "<<endl;
			cin>>descinas;
		}
		if(descinas==1) 
			{	sueldodia=sueldo/200; descdias=sueldodia*-qdias;}
		
		cout<<"Se descuentas el PRESENTISMO? (NO=0 / SI=1): "<<endl;
		cin>>present;
		if(present==1) present=sueldo*-0.0833; 
		
		tothab=sueldo+premioant+imphe50+imphe100+present+descdias;
		jubil=tothab*-0.11;
		obrasoc=tothab*-0.03;
		inssjp=tothab*-0.03;
		totdes=jubil+obrasoc+inssjp;
		sueneto=tothab+totdes;
		
		if(sueldo>suemax)
			{ suemax=sueldo; secmax=sec; emplsec=legajo; }
		
			cout<<endl<<"	------------------------------------------------------------"<<endl<<endl;
			cout<<" N de legajo: "<<legajo<<" Nombre: "<<nombre_1<<endl;
			cout<<"                                          HABERES     DESCUENTOS"<<endl;
			cout<<" SUELDO BASICO:                           "<<sueldo<<endl;
			cout<<" PRESENTISMO:                                           "<<present<<endl;
			cout<<" ANTIGUEDAD:                              "<<antig<<endl;
			cout<<" HORAS EXTRAS AL 50%: "<<he50<<"                   "<<imphe50<<endl;
			cout<<" HORAS EXTRAS AL 100%: "<<he100<<"                 "<<imphe100<<endl;
			cout<<" DESCUENTOS: "<<qdias<<"                                          "<<descdias<<endl;
			cout<<" APORTE JUBILATORIO (11):                               "<<jubil<<endl;
			cout<<" APORTE OBRA SOCIAL (3):                                "<<obrasoc<<endl;
			cout<<" APORTE INSSJP (3):                                     "<<inssjp<<endl;
			cout<<" TOTAL HABERES:                           "<<tothab<<endl;
			cout<<" TOTAL DESCUENTOS:                                      "<<totdes<<endl;
			cout<<" -SUELDO NETO A COBRAR-                   $"<<sueneto<<endl;
				cout<<endl<<"	------------------------------------------------------------"<<endl<<endl;
			
			totemp++; totsue+=sueldo; totsuenetos+=sueneto; suegen+=sueldo; imphe50=0;
			imphe100=0; present=0; descdias=0;
			
			sec=fsecciones(0,10);	
		}
		
	cout<<endl<<"	------------------------------------------------------------"<<endl<<endl;
	cout<<" TOTALES SECCION: "<<secx<<endl;
	cout<<" Sueldos brutos: "<<totsue<<endl;
	cout<<" Sueldos netos: "<<totsuenetos<<endl;
	cout<<" Empleados: "<<totemp<<endl;
	cout<<" Promedio de sueldos brutos:"<<totsue/totemp<<endl;
	cout<<endl<<"	------------------------------------------------------------"<<endl<<endl;
	if(sec!=0) cout<<endl<<" Ud. esta en la SECCION: "<<sec<<endl;
	totempg+=totemp; totsue=0; totemp=0; totsuenetos=0;
	}
	
	cout<<endl<<"	------------------------------------------------------------"<<endl<<endl;
	cout<<" TOTALES GENERALES: "<<endl;
	cout<<" Sueldo brutos: "<<suegen<<endl;
	cout<<" Mejor sueldo: "<<suemax<<endl;
	cout<<" Empleado con mejor sueldo: "<<emplsec<<endl;
	cout<<" Seccion com mejor sueldo: "<<secmax<<endl;
	cout<<" Cantidad de empleados: "<<totempg<<endl;
	cout<<endl<<"	------------------------------------------------------------"<<endl<<endl;
	cout<<endl<<" FIN."<<endl;
	return 0;
}

int fsecciones(int x,int y)
{
	int sec;
	
	do
	{
		cout<<"Ingrese seccion(0/10): "<<endl;
		cin>>sec;
	}while(sec<x||sec>y);
	
	return sec;
}

int fempleados(int x,int y)
{
	int empleado;
	
	do
	{
		cout<<"Ingrese Nro. de empleado(1/300): "<<endl;
		cin>>empleado;
	}while(empleado<x||empleado>y);
	
	return empleado;
}

float fsueldos(float x,float y)
{
	float sueldo;
	
	do
	{
		cout<<"Ingrese sueldo(30.000/100.000): "<<endl;
		cin>>sueldo;
	}while(sueldo<x||sueldo>y);
	
	return sueldo;
}
