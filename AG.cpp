//////////////////////////////AG.CPP////////////////////////////////////////////

/////////////////////////////LIBRERIAS//////////////////////////////////////////

#include "AG.h"

///////////////////////////////VARIABLES////////////////////////////////////////



///////////////////////////////FUUNCIONES////////////////////////////////////////

template <class T> int Min(T *cadena,int n)
{
 int ind,i;/*Indice del mejor individuo e indice de ciclo*/
 /*Algoritmo clasico para encontrar el indice del menor*/
 for(i=0,ind=0;i<n;i++)
    {
     if(cadena[ind]>cadena[i])
       {
        ind=i;
       }
    }
 return ind;
}

/******************************************************************************/

template <class T> int Max(T *cadena,int n)
{
 int ind,i;/*Indice del mejor individuo e indice de ciclo*/
 /*Algoritmo clasico para encontrar el indice del mayor*/
 for(i=0,ind=0;i<n;i++)
    {
     if(cadena[ind]<cadena[i])
       {
        ind=i;
       }
    }
 return ind;
}

///////////////////////////////CONSTRUTORES/////////////////////////////////////

Evolucion_Natural::Evolucion_Natural()
{
 ta_fitness=NULL;
 poblacion=NULL;
 copia_poblacion=NULL;
 ingre_busk(Minimo);
 Tipo[Minimo]=Min;
 Tipo[Maximo]=Max;
}

/******************************************************************************/

Evolucion_Natural::Evolucion_Natural(int n,int c,int m,int l)
{
 n_individuos=n;
 pc=c;
 pm=m;
 lc=l;
}

/////////////////////////////DESTRUCTOR/////////////////////////////////////////

Evolucion_Natural::~Evolucion_Natural()
{
 if(n_individuos>0)
   {
    delete [] poblacion;
    poblacion=NULL;
    delete [] copia_poblacion;
    copia_poblacion=NULL;
    delete [] ta_fitness;
    ta_fitness=NULL;
   }
}
/*----------------------------------------------------------------------------*/

Evolucion_Sharing::~Evolucion_Sharing()
{
}


/******************************************************************************/

Evolucion_crowding::~Evolucion_crowding()
{
 tabla=NULL;
 grupo=NULL;
 hamming=NULL;
 opci=NULL;
 a=NULL;
}

/******************************************************************************/

/////////////////////////////FUNCIONES NATURAL//////////////////////////////////

/*--------------------------PROTECTED------------------------------------------*/

/******************************************************************************/

Individuo& Evolucion_Natural::el_mejor(void)
{
 int ind,i;
 ind=Tipo[tipo](ta_fitness,dar_n_ind());
 return poblacion[ind];
}

/******************************************************************************/

void Evolucion_Natural::evaluar(void)
{
 eva_ind();
 mej=el_mejor();
}

/******************************************************************************/

void Evolucion_Natural::eva_ind(void)
{
 int i;
 double b;
 for(i=0;i<dar_n_ind();i++)
    {
     b=poblacion[i].fitness();
     ta_fitness[i]=b;
    }
}

/******************************************************************************/

void Evolucion_Natural::back_up(void)
{
 int i;
 for(i=0;i<dar_n_ind();i++)
    {
     copia_poblacion[i]=poblacion[i];
    }
}

/*---------------------------PUBLICAS-----------------------------------------*/

void Evolucion_Natural::ingre_n(int n)
{
 if(n<=0)return;
 clear_g();
 n_individuos=n;
 poblacion=new Individuo [n_individuos];
 copia_poblacion=new Individuo [n_individuos];
 ta_fitness=new double [n_individuos];
 return;
}

/******************************************************************************/

void Evolucion_Natural::ingre_pc(int p)
{
 if((p>=0)&&(p<=100))
   {
    pc=p;
   }
 else{
      pc=100;
     }
 return;
}

/******************************************************************************/

void Evolucion_Natural::ingre_pm(int p)
{
 if((p>=0)&&(p<=100))
   {
    pm=p;
   }
 else{
      pm=100;
     }
 return;
}

/******************************************************************************/

void Evolucion_Natural::ingre_lc(int p)
{
 if((p>=0)&&(p<=100))
   {
    lc=p;
   }
 else{
      lc=50;
     }
 return;
}

/******************************************************************************/

void Evolucion_Natural::evolucionar(void)
{
 //2.Evaluación de las soluciones planteadas.
 evaluar();
 //3.Selección de la o las mejores soluciones.
 //Copia de la poblacion para facilitar el trabajo
 recombinar();
 return;
}

/******************************************************************************/

void Evolucion_Natural::clear_g(void)
{
 if(n_individuos>0)
   {
    delete [] poblacion;
    poblacion=NULL;
    delete [] copia_poblacion;
    copia_poblacion=NULL;
    delete [] ta_fitness;
    ta_fitness=NULL;
   }
 n_individuos=0;
}

/******************************************************************************/

void Evolucion_Natural::inizializar(int n)
{
 int i;
 randomize();
 ingre_n(n);
 poblacion[0].Inicializar();
 poblacion[0].ingre_lc(dar_lc());
 for(i=1;i<dar_n_ind();i++)
    {
     poblacion[i].gen_ram();
    }
}

/******************************************************************************/

void Evolucion_Natural::cruzar(void)
{
 int i,j,k,l;
 /*Cruce*/
 for(i=0;i<((dar_n_ind()*dar_pc())/100);i++)
    {
     j=random(dar_n_ind());
     k=random(dar_n_ind());
     l=random(dar_n_ind());
     poblacion[l].cruzar(copia_poblacion[j],copia_poblacion[k]);
    }
}

/******************************************************************************/

void Evolucion_Natural::mutar(void)
{
 int i,k;
 /*Mutacion*/
 for(i=0;i<((dar_n_ind()*dar_pm())/100);i++)
    {
     k=random(dar_n_ind());
     poblacion[k].mutar();
    }
}

/******************************************************************************/

void Evolucion_Natural::recombinar(void)
{
 back_up();
 cruzar();
 mutar();
 poblacion[0]=mej;
 return;
}

/******************************************************************************/

Individuo& Evolucion_Natural::mejor(void)
{
 return mej;
}

////////////////////////FUNCIONES SHARING///////////////////////////////////////

/*---------------------------PRIVADAS-----------------------------------------*/

double Evolucion_Sharing::Sha_fit(int *hamming)
{
 int i,suma_Ham,ham_max;/*Sumatoria de los Hamming y hamming maximo*/
 double fsha;/*Factor de correccion del fitnes para Sharing*/
 ham_max=dar_n_ind()*poblacion[0].dar_bits();
 ae=alpha[tipo];
 be=-(log(ae))/(ham_max*(Des_Gen/100));/*Factor calculado online*/
 for(i=0,suma_Ham=0;i<dar_n_ind();i++)
    {
     suma_Ham+=hamming[i];/*Hamming total*/
    }
 if(suma_Ham>ham_max*(Des_Gen/100))
   {
    return 1.0;
   }
 fsha=ae*exp(be*suma_Ham);
 if(fsha>(alpha[Minimo]))fsha=alpha[Minimo];
 if(fsha<(alpha[Maximo]))fsha=alpha[Maximo];
 return fsha;
}

/******************************************************************************/

void Evolucion_Sharing::ini_sha(void)
{
 int i;
 hamm=new int* [dar_n_ind()];
 for(i=0;i<dar_n_ind();i++)
    {
     hamm[i]=new int [dar_n_ind()];
    }
 ban=true;
}

/******************************************************************************/

void Evolucion_Sharing::evaluar_sha(void)
{
 int i;
 for(i=0;i<dar_n_ind();i++)
    {
     ta_fitness[i]=Sha_fit(hamm[i])*ta_fitness[i];
    }
}

/******************************************************************************/

void Evolucion_Sharing::clear_sha(void)
{
 int i;
 if(ban==true)
   {
    for(i=0;i<dar_n_ind();i++)
       {
        delete [] hamm[i];
        hamm[i]=NULL;
       }
    delete [] hamm;
    hamm=NULL;
    ban=false;
   }
}

/******************************************************************************/

void Evolucion_Sharing::dis_hamm(void)
{
 int i,j;
 back_up();
 for(i=0;i<dar_n_ind();i++)
    {
     for(j=0;j<dar_n_ind();j++)
        {
         hamm[i][j]=Hamming(copia_poblacion[i],copia_poblacion[j]);
        }
    }
}

/******************************************************************************/

void Evolucion_Sharing::con_sha(void)
{
 ini_sha();
 /*Medición de distancia la Hamming entre los individuos*/
 dis_hamm();
 /*Calculo de la función de Sharing para cada individuo*/
 evaluar_sha();
 /*Selección de una nueva generación*/
 clear_sha();
 return;
}

/******************************************************************************/

void Evolucion_Sharing::evaluar(void)
{
 eva_ind();
 con_sha();
 mej=el_mejor();
 return;
}

/*---------------------------PUBLICAS-----------------------------------------*/


void Evolucion_Sharing::evolucionar(void)
{
 evaluar();
 recombinar();
 return;
}

////////////////////////FUNCIONES CROWDING///////////////////////////////////////

/*---------------------------PRIVADAS-----------------------------------------*/

void Evolucion_crowding::ini_cro(void)
{
 int i;
 if(grupo!=NULL)
   {
    delete [] grupo;
    grupo=NULL;
   }
 if(tabla!=NULL)
   {
    delete [] tabla;
    tabla=NULL;
   }
 if(opci!=NULL)
   {
    delete [] opci;
    opci=NULL;
   }
 if(hamming!=NULL)
   {
    delete [] hamming;
    hamming=NULL;
   }
 if(a!=NULL)
   {
    delete [] a;
    a=NULL;
   }
 cf=2;//Factor de crowding (numero de grupos)
 cs=dar_n_ind()/cf;//Calculo del tamaño de los grupos
 grupo= new int* [cf];///Asignacion de memoria para los grupos
 tabla=new int[dar_n_ind()];
 opci= new int [cf];//Asignacion dinamica para los opcionados
 hamming= new int [cs];//Asignacion dinamica para el calculo de las distancias
 a=new double [cf];//Fitnes de los individuos de nuevo grupo
 for(i=0;i<cf;i++)grupo[i]= new int[cs];
}

/******************************************************************************/

void Evolucion_crowding::clear(void)
{
 int i;
 for(i=0;i<cf;i++)
    {
     delete [] grupo[i];//Liberacion de memoria para grupo
     grupo[i]=NULL;
    }
 delete [] grupo;
 grupo=NULL;
 delete [] tabla;
 tabla=NULL;
 delete [] a;
 a=NULL;
 delete [] hamming;
 hamming=NULL;
 return;
}                                                   

/******************************************************************************/

void Evolucion_crowding::grupos(void)
{
 int l,q,h;
 for(l=0;l<dar_n_ind();l++)
    {
     tabla[l]=0;//Inicializacion de tabla
    }
 for(l=0;l<cf;l++)//Numero de grupos
    {
     for(q=0;q<cs;q++)//Tamaño del grupo
        {
         //codigo para evitar que algun individuo se repita
         for(;;)
            {
             h=random(dar_n_ind());
             if(tabla[h]==0)
               {
                grupo[l][q]=h;
                tabla[h]=1;//bandera indicando que ya ha sido seleccionado el individuo
                break;
               }
            }
       }
    }
 return;
}

/******************************************************************************/

void Evolucion_crowding::dis_hamming(int r)
{
 int l,q,h;
 for(l=0;l<cf;l++)//Numero de grupos
    {
     for(q=0;q<cs;q++)//tamaño del grupo
        {
         hamming[q]=Hamming(hijo[r],copia_poblacion[grupo[l][q]]);
        }
     //Selección del individuo de cada grupo más similar al hijo
     opci[l]=grupo[l][Min(hamming,cs)];
   }
 return;
}

/******************************************************************************/

void Evolucion_crowding::sustituir(int r)
{
 int l,q,j;
 if(tipo==Minimo)j=Tipo[Maximo](a,cf);
 else j=Tipo[Minimo](a,cf);
 poblacion[opci[j]]=hijo[r];
}

/******************************************************************************/

void Evolucion_crowding::cru_cro(void)
{
 int j,k;
 j=random(dar_n_ind());//Indice del primer individuo a cruzar
 k=random(dar_n_ind());//Indice del segundo individuo a cruzar
 hijo[0].cruzar(copia_poblacion[j],copia_poblacion[k]);
 hijo[1].cruzar(copia_poblacion[k],copia_poblacion[j]);
}

/******************************************************************************/

void Evolucion_crowding::cruzar(void)
{
 int i,r,l,o,j;
 for(i=0;i<(dar_n_ind()*dar_pc())/100;i++)
    {
     cru_cro();
     for(r=0;r<2;r++)//Crowding por hijo
        {
         //Selección aleatoria de grupos de C individuos
         grupos();
         //Medición de distancia la Hamming de los individuos al hijo
         dis_hamming(r);
         //Evaluación del Fitness en cada individuo del nuevo grupo
         for(l=0;l<cf;l++)
            {
             o=opci[l];
             a[l]=ta_fitness[o];
            }
         //Sustitución de individuo con el Fitness mas bajo por el hijo
         sustituir(r);
        }
   }
}

/******************************************************************************/

void Evolucion_crowding::recombinar(void)
{
 back_up();
 cruzar();
 mutar();
 poblacion[0]=mej;
 return;
}


/*---------------------------PUBLICAS-----------------------------------------*/

void Evolucion_crowding::evolucionar(void)
{
 int i,j,k,l,r;
 ini_cro();
 //Cruzamiento de los indiviuos
 evaluar();
 recombinar();
 return;
}

/******************************************************************************/

