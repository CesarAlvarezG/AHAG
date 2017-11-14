/////////////////////////////////AG.H//////////////////////////////////////////
/*Esta libreria contiene las clases y funciones utilizadas por el algoritmo
genetico, asi como todo aquello que necesite*/

/*PROTOTIPO DE INDIVIDUO PARA EL USO DE ESTAS FUNCIONES

Se crea una libreria llamada Individuo.h 

class Individuo
{
 private:
         static int lc;//Longitud de cruce
         tipo_variable Adn;
 public:
        //Constructores
        Individuo();//Contructor por defecto
        Individuo(Individuo &a);//Constructor de copia
        //Destructor
        ~Individuo();
        //Sobrecarga de los operadores
        Individuo& operator=(Individuo&);
        friend int operator==(const Individuo&,const Individuo&);
        friend int operator!=(const Individuo&,const Individuo&);
        friend int Hamming(const Individuo&,const Individuo&);
//------------------------------------------------------------------------------
        double fitness(void);//Funcion encargada de calcular su Fitness
        void Inicializar(void);//Funcion encargada de Inicializar el individuo
        void gem_ram(void);//Funcion encargada de crear un individuo de Adn aleatorio
        void ingre_lc(int l);//Funcion encargada de ingresar la longitud de cruce
        void cruzar(const Individuo a,const Individuo b);
        //Funcion encargada de realizar el cruce de dos individuos
        void mutar(void);//Funcion encargada de mutar un indivduo
        int dar_bits(void);//Funcion encargada de retornar el numero total de bits 
};

*/
////////////////////////////////LIBRERIAS///////////////////////////////////////

#ifndef _AG_h
#define _AG_h
#include <vcl.h>
#include <math.h>
#include "Individuo.h"

////////////////////////VARIABLES, CONSTANTES y ESTRUTURAS//////////////////////

//////////////////////////////////CLASES////////////////////////////////////////

//class Individuo;

template <class T> int Min(T *cadena,int n);//Funcion encargada de encontrar el minimo de una cadena
template <class T> int Max(T *cadena,int n);//Funcion encargada de encontrar el maximo de una cadena

enum Busqueda{Minimo,Maximo};

class Evolucion_Natural
{
 protected:
           int n_individuos;
           int pc;//Probabilidad de cruce
           int pm;//Probabilidad de mutacion
           int lc;
           void clear_g(void);
           double *ta_fitness;/*Arreglo con los valores de los fitness de cada
                          individuo para agilizar los calculos*/
           Individuo *poblacion,*copia_poblacion;/*Puntero para asignacion dinamica de memoria*/
           /*Para uso de nuevas generaciones*/
           Individuo mej;
           Individuo& el_mejor(void);
           void evaluar(void);
           void eva_ind(void);
           void back_up(void);
           Busqueda tipo;
           int (*Tipo[2])(double *cadena,int n);
 public:
        Evolucion_Natural();
        Evolucion_Natural(int n,int c,int m,int l);
        ~Evolucion_Natural();
        void ingre_busk(Busqueda ti){tipo=ti;}
        void ingre_n(int n);/*Funcion encargada de ingresar el numero de
                                   individuos*/
        void ingre_pc(int p);/*Funcion encargada de ingresar la probabilidad
                               de cruce*/
        void ingre_pm(int p);/*Funcion encargada de ingresar la probabilidad
                               de mutacion*/
        void ingre_lc(int p);
/*----------------------------------------------------------------------------*/
        Busqueda dar_busk(void){return tipo;}
        int dar_n_ind(void){return n_individuos;}/*Funcion en cargada de retornar el numero de
                            individuos*/
        int dar_pc(void){return pc;}/*Funcion encargada de retornar la probabilidad de cruce*/
        int dar_pm(void){return pm;}/*Funcion encargada de retornar la probabilidad de
                         mutacion*/
        int dar_lc(void){return lc;}
/*----------------------------------------------------------------------------*/
        void evolucionar(void);
        void inizializar(int n);
        void cruzar(void);
        void mutar(void);
        void recombinar(void);
        Individuo& mejor(void);
};

/******************************************************************************/

class Evolucion_Sharing:public Evolucion_Natural
{
        int **hamm;
        int mejor_sha();
        double atenuacion;
        double alpha[2];
        double ae,be;
        double Sha_fit(int *hamming);
        double Des_Gen;
        void ini_sha(void);
        void evaluar_sha(void);
        Individuo& el_mejor_sha(void);
        void clear_sha(void);
        bool ban;
        void dis_hamm(void);
        void evaluar(void);
        void con_sha(void);
 public:
        Evolucion_Sharing():Evolucion_Natural()
        {
         double atenuacion=20.0;
         hamm=NULL;
         ban=false;
         alpha[Minimo]=1+(atenuacion/100);
         alpha[Maximo]=1-(atenuacion/100);
         Des_Gen=20;
        }
        Evolucion_Sharing(int n,int c,int m,int l):Evolucion_Natural(n,c,m,l)
        {
         double atenuacion=20.0;
         hamm=NULL;
         ban=false;
         alpha[Minimo]=1+(atenuacion/100);
         alpha[Maximo]=1-(atenuacion/100);
         Des_Gen=20;
        }
        ~Evolucion_Sharing();
        void ingre_ate(double a)
        {
         if(a<0)a=0;
         if(a>100)a=100;
         atenuacion=a;
         alpha[Minimo]=1-(atenuacion/100);
         alpha[Maximo]=1+(atenuacion/100);
        }
        double dar_ate(void){return atenuacion;}
        void ingre_DG(double a)
        {
         if(a<=0)a=1;
         if(a>100)a=100;
         Des_Gen=a;
        }
        double dar_DG(void){return Des_Gen;}
        void evolucionar(void);
};

/******************************************************************************/

class Evolucion_crowding:public Evolucion_Natural
{
        int cs;
        int *tabla;//Tabla de asignacion para no repetir individuos
        int cf;//Factor de Crowding por defecto
        int **grupo;//Grupo para realizar el algoritmo formado por los indices
        int *hamming;//Valor de las distancias hamming en cada individuo
        int *opci;//indice de los mas opcionados de cada grupo en crowding
        Individuo hijo[2];//Hijo producto del cruce
        double *a;
        void ini_cro(void);
        void grupos(void);//Selección aleatoria de grupos de C individuos
        void dis_hamming(int r);
        void sustituir(int r);
        void cru_cro(void);//Funcion encargada de generar los hijos a sustituir
        void clear(void);
        void cruzar(void);
        void recombinar(void);
 public:
        Evolucion_crowding():Evolucion_Natural()
        {
         tabla=NULL;
         grupo=NULL;
         hamming=NULL;
         opci=NULL;
         a=NULL;
        }
        Evolucion_crowding(int n,int c,int m,int l):Evolucion_Natural(n,c,m,l)
        {
         tabla=NULL;
         grupo=NULL;
         hamming=NULL;
         opci=NULL;
         a=NULL;
        }
        ~Evolucion_crowding();
        void evolucionar(void);
};

/******************************************************************************/

#endif

