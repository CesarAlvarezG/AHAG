////////////////////////////ACTORES.CPP////////////////////////////////////////

////////////////////////////LIBRERIAS///////////////////////////////////////////

#include "Actores.h"
/////////////////////////////////CLASES/////////////////////////////////////////


//////////////////////////////VARIABLES GLOBALES////////////////////////////////

//////////////////////////////FUNCIONES/////////////////////////////////////////

void Ac_acond(char *a)
{
 int i,j;
 if(a==NULL)return;
 j=strlen(a);
 for(i=0;i<j;i++)
    {
     if(a[i]==32)a[i]=95;
    }
 a[i]=0;//Fin de cadena
 return;
}

/******************************************************************************/



//////////////////////////////CONSTRUCTORES/////////////////////////////////////

/******************************************************************************/

Identidad::Identidad()
{
 nombre="";
 codigo="";
}

/******************************************************************************/

Identidad::Identidad(const Identidad &a)
{
 nombre=a.nombre;
 codigo=a.codigo;
}

/******************************************************************************/

Asignacion::Asignacion()
{
 n_tol=0;
 grupo=NULL;
 materia=NULL;
 semestre=NULL;
}

/******************************************************************************/

Asignacion::Asignacion(const Asignacion &a)
{
 int i;
 if(this==&a)return;
 grupo=new String[a.n_tol];
 materia=new String[a.n_tol];
 semestre=new String[a.n_tol];
 n_tol=a.n_tol;
 for(i=0;i<a.n_tol;i++)
    {
     grupo[i]=a.grupo[i];
     materia[i]=a.materia[i];
     semestre[i]=a.semestre[i];
    }
 return;
}

/******************************************************************************/

Profesor::Profesor()
{
 capacidad=0;
 n_restri=0;
}

/******************************************************************************/

Profesor::Profesor(const Profesor &a)
{
 int i;
 TCita tem;
 identidad=a.identidad;
 asig=a.asig;
 capacidad=a.capacidad;
 n_restri=a.n_restri;
 for(i=0;i<n_restri;i++)
    {
     tem=a.dar_restri(i);
     restri[i]=tem;
    }
}

/******************************************************************************/

Estudiante::Estudiante()
{

}

/******************************************************************************/

Estudiante::Estudiante(const Estudiante &a)
{
 identidad=a.identidad;
 asig=a.asig;
}

/******************************************************************************/

Salon::Salon()
{
 capacidad=0;
}

/******************************************************************************/

Salon::Salon(const Salon &a)
{
 capacidad=a.capacidad;
 identidad=a.identidad;
 pos=a.pos;
}

/******************************************************************************/

Seccion::Seccion()
{
 Cita_estatica=false;
}

/******************************************************************************/

Seccion::Seccion(const Seccion &a)
{
 sal=a.sal;
 Cita_estatica=a.Cita_estatica;
 time=a.time;
}

/******************************************************************************/

Grupo::Grupo()
{
 n_estudiantes=0;
 capacidad=0;
 n_clas=0;
}

/******************************************************************************/

Grupo::Grupo(const Grupo &a)
{
 int i;
 String tem;
 i=a.n_estudiantes;
 ingre_est(i);
 for(i=0;i<a.n_estudiantes;i++)
    {
     tem=a.estu[i];
     estu[i]=tem;
    }
 i=a.capacidad;
 ingre_capa(i);
 i=a.n_clas;
 n_secciones(i);
 ing_profe(a.profe.c_str());
 identidad=a.identidad;
}

/******************************************************************************/

Materia::Materia()
{
 gru=NULL;
 n_grupos=0;
}

/******************************************************************************/

Materia::Materia(const Materia &a)
{
 int i;
 n_grupos=a.n_grupos;
 identidad=a.identidad;
 for(i=0;i<a.n_grupos;i++)
    {
     gru[i]=a.gru[i];
    }
}

/******************************************************************************/

Semestre::Semestre()
{
 mat=NULL;
 nombre="";
 n_materias=0;
}

/******************************************************************************/

Semestre::Semestre(const Semestre &a)
{
 int i;
 nombre=a.nombre;
 a.n_materias;
 for(i=0;i<a.n_materias;i++)
    {
     mat[i]=a.mat[i];
    }
}

/******************************************************************************/

Director::Director()
{
 clave="";
}

/******************************************************************************/

Director::Director(const Director &a)
{
 identidad=a.identidad;
 clave=a.clave;
}

/******************************************************************************/

Horario::Horario()
{
 n_sem=0;
 n_profe=0;
 n_estudiantes=0;
 n_sal=0;
 Sem=NULL;
 profe=NULL;
 est=NULL;
 sal=NULL;
 Inicio.Hora=hr08;
 Inicio.Dia=dLunes;
 Final.Hora=hr18;
 Final.Dia=dViernes;
}

/******************************************************************************/

Horario::Horario(const Horario &a)
{
 int i;
 nombre=a.nombre;
 n_sem=a.n_sem;
 for(i=0;i<a.n_sem;i++)
    {
     Sem[i]=a.Sem[i];
    }
 n_profe=a.n_profe;
 for(i=0;i<a.n_profe;i++)
    {
     profe[i]=a.profe[i];
    }
 n_estudiantes=a.n_estudiantes;
 for(i=0;i<a.n_estudiantes;i++)
    {
     est[i]=a.est[i];
    }
 n_sal=a.n_sal;
 for(i=0;i<a.n_sal;i++)
    {
     sal[i]=a.sal[i];
    }
 Dir=a.Dir;
 Inicio=a.Inicio;
 Final=a.Final;
}

//////////////////////////////DESTRUCTOR////////////////////////////////////////

Identidad::~Identidad()
{
 nombre="";
 codigo="";
}

/******************************************************************************/

Asignacion::~Asignacion()
{
 int i;
 if(n_tol>0)
   {
    for(i=0;i<n_tol;i++)
       {
        grupo[i]="";
        materia[i]="";
        semestre[i]="";
       }
   }
}

/******************************************************************************/

Profesor::~Profesor()
{
 clear_restri();
 if(n_restri>0)
   {
    delete [] restri;
    restri=NULL;
   }
 capacidad=0;
 n_restri=0;
}

/******************************************************************************/

Estudiante::~Estudiante()
{

}

/******************************************************************************/

Seccion::~Seccion()
{

}

/******************************************************************************/

Salon::~Salon()
{
 capacidad=0;
}

/******************************************************************************/

Grupo::~Grupo()
{
 int i;
 profe="";
 if(n_clas>0)
   {
    delete [] secc;
   }
 if(n_estudiantes>0)
   {
    delete [] estu;
    estu=NULL;
   }
 n_estudiantes=0;
 n_clas=0;
 capacidad=0;
}

/******************************************************************************/

Materia::~Materia()
{
 if(n_grupos>0)
   {
    delete [] gru;
    gru=NULL;
   }
 n_grupos=0;
}

/******************************************************************************/

Semestre::~Semestre()
{
 if(n_materias>0)
   {
    delete [] mat;
    mat=NULL;
   }
 n_materias=0;
}

/******************************************************************************/

Director::~Director()
{
 clave="";
}

/******************************************************************************/

Horario::~Horario()
{
 if(n_sem>0)
   {
    delete [] Sem;
    Sem=NULL;
   }
 if(n_profe>0)
   {
    delete [] profe;
    profe=NULL;
   }
 if(n_estudiantes>0)
   {
    delete [] est;
    est=NULL;
   }
 if(n_sal>0)
   {
    delete [] sal;
    sal=NULL;
   }
 n_sem=0;
 n_profe=0;
 n_estudiantes=0;
 n_sal=0;
}


//////////////////////////////FUNCIONES/////////////////////////////////////////

/*-------------------------------Identidad------------------------------------*/

void Identidad::ingre_nom(char *nom)
{
 if(nom==NULL)return;
 Ac_acond(nom);
 nombre=nom;
 return;
}

/******************************************************************************/

void Identidad::ingre_cod(char *nom)
{
 if(nom==NULL)return;
 Ac_acond(nom);
 codigo=nom;
 return;
}

/******************************************************************************/

char* Identidad::dar_nom(void)
{
 return nombre.c_str();
}

/******************************************************************************/

char* Identidad::dar_cod(void)
{
 return codigo.c_str();
}

/******************************************************************************/

Identidad& Identidad::operator=(const Identidad &a)
{
 nombre=a.nombre;
 codigo=a.codigo;
 return (*this);
}

/******************************************************************************/

int operator==(const Identidad &a,const Identidad &b)
{
 return (a.nombre==b.nombre)&&(a.nombre==b.nombre);
}

/******************************************************************************/

int operator!=(const Identidad &a,const Identidad &b)
{
 return (a.nombre!=b.nombre)&&(a.nombre!=b.nombre);
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Identidad &a)
{
 co << a.nombre.c_str() <<"\t";
 co << a.codigo.c_str();
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Identidad &a)
{
 char tem[100];
 ci >> tem;
 a.nombre=tem;
 ci >> tem;
 a.codigo=tem;
 return ci;
}

/*------------------------------Asignacion------------------------------------*/

void Asignacion::add_gru(char *gru,char *mat)
{
 int i,j,n;
 String e;
 if(ind_gru(gru)!=-1)
   {
    return;//El grupo ya fue registrado
   }
 Ac_acond(gru);
 Ac_acond(mat);
 e=gru;
 j=agregar(grupo,e,n_tol);
 e=mat;
 n=n_tol-1;
 j=agregar(materia,e,n,j);
 return;
}

/******************************************************************************/

void Asignacion::del_gru(char *gru,char *mat)
{
 int i,j,k;
 String e;
 Ac_acond(gru);
 Ac_acond(mat);
 e=gru;
 j=quitar(grupo,e,n_tol);
 e=mat;
 j=quitar(materia,e,n_tol,j);
 return;
}

/******************************************************************************/

void Asignacion::clear_all(void)
{
 if(n_tol>0)
   {
    delete [] grupo;
    delete [] materia;
    delete [] semestre;
   }
 n_tol=0;  
}

/******************************************************************************/

int Asignacion::ind_gru(char *gru)
{
 int i;
 Ac_acond(gru);
 if(n_tol==0)return -1;
 for(i=0;i<n_tol;i++)
    {
     if(strcmp(grupo[i].c_str(),gru)==0)return i;
    }
 return -1;
}

/******************************************************************************/

int Asignacion::dar_tol(void)
{
 return n_tol;
}

/******************************************************************************/

char* Asignacion::dar_gru(int ind)
{
 return grupo[ind].c_str();
}

/******************************************************************************/

char* Asignacion::dar_mat(int ind)
{
 return materia[ind].c_str();
}

/******************************************************************************/

char* Asignacion::dar_sem(int ind)
{
 return semestre[ind].c_str();
}

/******************************************************************************/

void Asignacion::ingre_n_tol(int tol)
{
 if(tol>0)
   {
    n_tol=tol;
    grupo=new String [n_tol];
    materia=new String [n_tol];
    semestre=new String [n_tol];
   }
}

/******************************************************************************/

void Asignacion::ingre_gru(char *gru,int ind)
{
 Ac_acond(gru);
 if(ind>=0&&ind<n_tol)
   {
    grupo[ind]=gru;
   }
}

/******************************************************************************/

void Asignacion::ingre_mat(char *mat,int ind)
{
 Ac_acond(mat);
 if(ind>=0&&ind<n_tol)
   {
    materia[ind]=mat;
   }
}

/******************************************************************************/

void Asignacion::ingre_sem(char *sem,int ind)
{
 Ac_acond(sem);
 if(ind>=0&&ind<n_tol)
   {
    semestre[ind]=sem;
   }
}

/******************************************************************************/

Asignacion& Asignacion::operator=(const Asignacion &a)
{
 int i;
 if(*this==a)return (*this);//En caso de ser el mismo elemento
 clear_all();
 ingre_n_tol(a.n_tol);
 for(i=0;i<n_tol;i++)
    {
     grupo[i]=a.grupo[i];
     materia[i]=a.materia[i];
     semestre[i]=a.semestre[i];
    }
 return (*this);
}

/******************************************************************************/

int operator==(const Asignacion &a,const Asignacion &b)
{
 int i;
 if(a.n_tol==b.n_tol)
   {
    for(i=0;i<a.n_tol;i++)
       {
        if(a.grupo!=b.grupo)return a.grupo==b.grupo;
        if(a.materia!=b.materia)return a.materia==b.materia;
        if(a.semestre!=b.semestre)return a.semestre==b.semestre;
       }
   }
 return a.n_tol==b.n_tol;
}

/******************************************************************************/

int operator!=(const Asignacion &a,const Asignacion &b)
{
 int i;
 if(a.n_tol!=b.n_tol)return a.n_tol!=b.n_tol;
 else{
      for(i=0;i<a.n_tol;i++)
       {
        if(a.grupo!=b.grupo)return a.grupo!=b.grupo;
        if(a.materia!=b.materia)return a.materia!=b.materia;
        if(a.semestre!=b.semestre)return a.semestre!=b.semestre;
       }
     }
 return a.n_tol!=b.n_tol;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Asignacion &a)
{
 int i;
 co << a.n_tol << endl;
 for(i=0;i<a.n_tol;i++)
    {
     co << a.grupo[i].c_str() << a.materia[i].c_str() << a.semestre[i].c_str();
    }
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Asignacion &a)
{
 int i;
 char c[100];
 ci >> i;
 a.ingre_n_tol(i);
 for(i=0;i<a.n_tol;i++)
    {
     ci >> c;
     a.grupo[i]=c;
     ci >> c;
     a.materia[i]=c;
     ci >> c;
     a.semestre[i]=c;
    }
 return ci;
}

/*-------------------------------Profesor-------------------------------------*/

void Profesor::capacitar(int n)
{
 capacidad=n;
 return;
}

/******************************************************************************/

void Profesor::n_restricciones(int tem)
{
 int i;
 if(tem<0)return;
 n_restri=tem;
 if(restri!=NULL)
 {
  delete [] restri;
  restri=NULL;
 }
 restri=new TCita [n_restri];
 return;
}

/******************************************************************************/

void Profesor::ingre_restri(TCita tim,int secc)
{
 if((secc<0)&&(secc>n_restri))return;
 restri[secc]=tim;
 return;
}

/******************************************************************************/

int Profesor::ind_res(TCita tim)
{
 int i;
 i=indice(restri,tim,n_restri);
 return i;
}

/******************************************************************************/

int Profesor::dar_capacidad(void)
{
 return capacidad;
}

/******************************************************************************/

int Profesor::dar_restriciones(void)
{
 return n_restri;
}

/******************************************************************************/

void Profesor::add_restri(TCita times)
{
 int ind_restri;
 ind_restri=ind_res(times);
 if(ind_restri>=0)
   {
    agregar(restri,times,n_restri);
   }
 return;
}

/******************************************************************************/

void Profesor::del_restri(TCita times)
{
 quitar(restri,times,n_restri);
 return;
}

/******************************************************************************/

TCita Profesor::dar_restri(int secc)
{
 TCita e;
 if((secc<0)&&(secc>n_restri))return e;
 return restri[secc];
}

/******************************************************************************/

void Profesor::clear_restri()
{
 if(n_restri>0)
   {
    delete [] restri;
    restri=NULL;
   }
 n_restri=0;
}

/******************************************************************************/

Profesor& Profesor::operator=(const Profesor &a)
{
 int i;
 if(*this==a)return (*this);
 i=a.dar_capacidad();
 capacidad=i;
 i=a.dar_restriciones();
 n_restricciones(i);
 identidad=a.identidad;
 asig=a.asig;
 return (*this);
}

/******************************************************************************/

int operator==(const Profesor &a,const Profesor &b)
{
 return a.identidad==b.identidad;
}

/******************************************************************************/

int operator!=(const Profesor &a,const Profesor &b)
{
 return a.identidad!=b.identidad;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Profesor &a)
{
 int i;
 co << a.identidad << "\t";
 co << a.capacidad << "\t" <<a.n_restri << endl;
 for(i=0;i<a.n_restri;i++)
    {
     co << a.restri[i];
    }
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Profesor &a)
{
 int i;
 ci >> a.identidad;
 ci >> a.capacidad;
 ci >> a.n_restri;
 for(i=0;i<a.n_restri;i++)
    {
     ci >> a.restri[i];
    }
 return ci;
}

/*-------------------------------Estudiante-----------------------------------*/

Estudiante& Estudiante::operator=(const Estudiante &a)
{
 identidad=a.identidad;
 asig=a.asig;
 return (*this);
}

/******************************************************************************/

int operator==(const Estudiante &a,const Estudiante &b)
{
 return a.identidad==b.identidad;
}

/******************************************************************************/

int operator!=(const Estudiante &a,const Estudiante &b)
{
 return a.identidad!=b.identidad;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Estudiante &a)
{
 co << a.identidad << "\t";
 co << a.asig;
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Estudiante &a)
{
 ci >> a.identidad;
 ci >> a.asig;
 return ci;
}

/*-------------------------------Salon----------------------------------------*/

void Salon::ingre_capa(int num)
{
 if(num<0)num=0;
 capacidad=num;
 return;
}

/******************************************************************************/

int Salon::dar_capacidad(void)
{
 return capacidad;
}

/******************************************************************************/

int Salon::capacitar(int est)
{
 if(capacidad<est)return 0;
 else return 1;
}

/******************************************************************************/

Salon& Salon::operator=(const Salon &a)
{
 if(*this==a)return (*this);
 capacidad=a.capacidad;
 identidad=a.identidad;
 pos=a.pos;
 return (*this);
}

/******************************************************************************/

int operator==(const Salon &a,const Salon &b)
{
 return a.identidad==b.identidad;
}

/******************************************************************************/

int operator!=(const Salon &a,const Salon &b)
{
  return a.identidad==b.identidad;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Salon &a)
{
 co << a.identidad << "\t";
 co << a.capacidad << "\t";
 co << a.pos << endl;
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Salon &a)
{
 ci >> a.identidad;
 ci >> a.capacidad;
 ci >> a.pos;
 return ci;
}

/*-------------------------------Seccion--------------------------------------*/

void Seccion::ingre_tiempo(TCita tim)
{
 time=tim;
 return;
}

/******************************************************************************/

void Seccion::ingre_sal(char *salon)
{
 int i;
 Ac_acond(salon);
 sal=salon;
 return;
}

/******************************************************************************/

char* Seccion::dar_salon(void)
{
 return sal.c_str();
}

/******************************************************************************/

TCita Seccion::dar_tiempo(void)
{
 return time;
}

/******************************************************************************/

void Seccion::estatica(bool t)
{
 Cita_estatica=t;
 return;
}

/******************************************************************************/

bool Seccion::estatica(void)
{
 return Cita_estatica;
}

/******************************************************************************/

Seccion& Seccion::operator=(const Seccion &a)
{
 if(*this==a)return (*this);
 sal=a.sal;
 Cita_estatica=a.Cita_estatica;
 time=a.time;
 return (*this);
}

/******************************************************************************/

int operator==(const Seccion &a,const Seccion &b)
{
 return a.time==b.time;
}

/******************************************************************************/

int operator!=(const Seccion &a,const Seccion &b)
{
 return a.time!=b.time;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Seccion &a)
{
 co << a.time << "\t";
 co << a.Cita_estatica <<"\t";
 co << a.sal.c_str();
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Seccion &a)
{
 char tem[100];
 ci >> a.time;
 ci >> a.Cita_estatica;
 ci >> tem;
 a.sal=tem;
 return ci;
}

/*-------------------------------Grupo----------------------------------------*/

void Grupo::ingre_est(int num)
{
 if(num<=0)return;
 n_estudiantes=num;
 estu=new String [n_estudiantes];
 return;
}

/******************************************************************************/

void Grupo::ingre_capa(int num)
{
 capacidad=num;
 return;
}

/******************************************************************************/

void Grupo::n_secciones(int tem)
{
 int i;
 if(tem<=0)return;
 if(n_clas>0)
   {
    delete [] secc;
    secc=NULL;
   }
 n_clas=tem;
 return;
}
/******************************************************************************/

void Grupo::ing_profe(char *cod)
{
 Ac_acond(cod);
 profe=cod;
 return;
}


/******************************************************************************/

void Grupo::ing_estu(char* cod,int ind)
{
 if((ind<0)&&(ind>n_estudiantes))return;
 Ac_acond(cod);
 estu[ind]=cod;
 return;
}

/******************************************************************************/

char* Grupo::anu_profe(void)
{
 return profe.c_str();
}

/******************************************************************************/

char* Grupo::dar_est(int ind)
{
 if((ind<0)&&(ind>n_clas))return 0;
 return estu[ind].c_str();
}

/******************************************************************************/

int Grupo::dar_ests(void)
{
 return n_estudiantes;
}

/******************************************************************************/

int Grupo::dar_capacidad(void)
{
 return capacidad;
}

/******************************************************************************/

int Grupo::n_secc(void)
{
 return n_clas;
}

/******************************************************************************/

void Grupo::add_estu(char *cod)
{
 int i,j;
 String tem;
 tem=cod;
 Ac_acond(cod);
 i=ind_est(cod);
 if(i!=-1)
   {
    return;/*El estudiante ya esta registrado*/
   }
 agregar(estu,tem,n_estudiantes);
 return;
}

/******************************************************************************/

void Grupo::del_estu(char *cod)
{
 String tem;
 tem=cod;
 quitar(estu,tem,n_estudiantes);
 return;
}

/******************************************************************************/

void Grupo::act_estu(char *cod,char *cod1)
{
 int i;
 i=ind_est(cod);
 estu[i]=cod1;
 return;
}

/******************************************************************************/

void Grupo::add_clas(Seccion seccion)
{
 int ind_secc;
 agregar(secc,seccion,n_clas);
 return;
}

/******************************************************************************/

void Grupo::del_clas(Seccion seccion)
{
 quitar(secc,seccion,n_clas);
 return;
}

/******************************************************************************/

void Grupo::act_class(Seccion seccion,int i)
{
 if(i>0&&i>n_clas)return;
 secc[i]=seccion;
}

/******************************************************************************/

int Grupo::ind_sal(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_clas==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_clas;i++)
           {
            if(strcmp(secc[i].dar_salon(),cod)==0)return i;
           }
        return -1;
       }
}

/******************************************************************************/

int Grupo::ind_est(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_estudiantes==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_estudiantes;i++)
           {
            Ac_acond(cod);
            if(strcmp(estu[i].c_str(),cod)==0)return i;
           }
        return -1;
       }
}

/******************************************************************************/

int Grupo::ind_clas(TCita times)
{
 int i;
 if(n_clas==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_clas;i++)
           {
            if(secc[i].time==times)
              {
               return i;
              }
           }
        return -1;
  }
}

/******************************************************************************/

void Grupo::clear_est()
{
 int i;
 if(n_estudiantes>0)
   {
    delete [] estu;
    estu=NULL;
   }
 n_estudiantes=0;
}

/******************************************************************************/

void Grupo::clear_clas()
{
 if(n_clas>0)
   {
    delete [] secc;
    secc=NULL;
   }
 n_clas=0;
}

/******************************************************************************/

Grupo& Grupo::operator=(const Grupo &a)
{
 if(*this==a)return (*this);
 int i;
 String tem;
 i=a.n_estudiantes;
 ingre_est(i);
 for(i=0;i<a.n_estudiantes;i++)
    {
     tem=a.estu[i];
     estu[i]=tem;
    }
 i=a.capacidad;
 ingre_capa(i);
 i=a.n_clas;
 n_secciones(i);
 for(i=0;i<a.n_clas;i++)
    {
     secc[i]=a.secc[i];
    }
 ing_profe(a.profe.c_str());
 identidad=a.identidad;
 return (*this);
}

/******************************************************************************/

int operator==(const Grupo &a,const Grupo &b)
{
 return a.identidad==b.identidad;
}

/******************************************************************************/

int operator!=(const Grupo &a,const Grupo &b)
{
 return a.identidad!=b.identidad;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Grupo &a)
{
 co << a.identidad << "\t";
 co << a.capacidad << "\t";
 co << a.profe.c_str();
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Grupo &a)
{
 char tem[100];
 ci >> a.identidad;
 ci >> a.capacidad;
 ci >> tem;
 a.profe=tem;
 return ci;
}

/*-------------------------------Materia--------------------------------------*/

void Materia::cursar(int i)
{
 if(i<=0)return;
 n_grupos=i;
 if(n_grupos>0)
   {
    delete [] gru;
    gru=NULL;
   }
 gru=new Grupo [n_grupos];
 return;
}

/******************************************************************************/

int Materia::dar_grupos(void)
{
 return n_grupos;
}

/******************************************************************************/

void Materia::add_gru(char *nom,char *cod)
{
 int i,j;
 Grupo tem;
 Ac_acond(nom);
 Ac_acond(cod);
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 i=indice(gru,tem,n_grupos);
 if(i!=-1)
   {
    return;//El grupo ya existe
   }
 agregar(gru,tem,n_grupos);
 return;
}

/******************************************************************************/

void Materia::del_gru(char *nom,char *cod)
{
 int i,j;
 Grupo tem;
 Ac_acond(nom);
 Ac_acond(cod);
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 i=indice(gru,tem,n_grupos);
 if(i!=-1)
   {
    return;//El grupo si existe
   }
 quitar(gru,tem,n_grupos);
 return;
}

/******************************************************************************/

void Materia::act_gru(char *nom,char *cod,char *nom1,char *cod1)
{
 int i;
 Grupo tem;
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 Grupo tem1;
 tem1.identidad.ingre_nom(nom1);
 tem1.identidad.ingre_cod(cod1);
 i=indice(gru,tem,n_grupos);
 gru[i]=tem1;
 return;
}

/******************************************************************************/

int Materia::ind_gru(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_grupos==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_grupos;i++)
           {
            if(strcmp(gru[i].identidad.dar_cod(),cod)==0)return i;
           }
       return -1;
      }
}

/******************************************************************************/

void Materia::clear_gru()
{
 if(n_grupos>0)
   {
    delete [] gru;
    gru=NULL;
   }
 n_grupos=0;
}

/******************************************************************************/

Materia& Materia::operator=(const Materia &a)
{
 int i;
 if(*this==a)return (*this);
 clear_gru();
 n_grupos=a.n_grupos;
 identidad=a.identidad;
 for(i=0;i<a.n_grupos;i++)
    {
     gru[i]=a.gru[i];
    }
 return (*this);
}

/******************************************************************************/

int operator==(const Materia &a,const Materia &b)
{
 return a.identidad==b.identidad;
}

/******************************************************************************/

int operator!=(const Materia &a,const Materia &b)
{
 return a.identidad!=b.identidad;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Materia &a)
{
 co << a.identidad;
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Materia &a)
{
 ci >> a.identidad;
 return ci;
}

/*-------------------------------Semestre-------------------------------------*/

void Semestre::nombrar(char *nom)
{
 Ac_acond(nom);
 nombre=nom;
 return;
}

/******************************************************************************/

void Semestre::numerar(int num)
{
 if(num<=0)return;
 n_materias=num;
 if(n_materias>0)
   {
    delete [] mat;
    mat=NULL;
   }
 mat=new Materia[n_materias];
 return;
}

/******************************************************************************/

char* Semestre::dar_nombre(void)
{
 return nombre.c_str();
}

/******************************************************************************/

int Semestre::dar_numerom(void)
{
 return n_materias;
}

/******************************************************************************/

void Semestre::add_materia(char *nom,char *cod)
{
 int i,j,k;
 Materia tem;
 Ac_acond(nom);
 Ac_acond(cod);
 i=ind_mat(cod);
 if(i!=-1)
   {
    return;/*La materia ya existe*/
   }
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 agregar(mat,tem,n_materias);
 return;
}

/******************************************************************************/

void Semestre::del_materia(char *nom,char *cod)
{
 int i,j,k;
 Materia tem;
 Ac_acond(nom);
 Ac_acond(cod);
 i=ind_mat(cod);
 if(i!=-1)
   {
    return;/*La materia si existe*/
   }
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 quitar(mat,tem,n_materias);
 return;
}

/******************************************************************************/

void Semestre::act_materia(char *nom,char *cod,char *nom1,char *cod1)
{
 int i;
 Materia tem;
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 Materia tem1;
 tem1.identidad.ingre_nom(nom1);
 tem1.identidad.ingre_cod(cod1);
 i=indice(mat,tem,n_materias);
 mat[i]=tem1;
 return;
}

/******************************************************************************/

int Semestre::ind_mat(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_materias==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_materias;i++)
           {
            if(strcmp(mat[i].identidad.dar_cod(),cod)==0)return i;
           }
        return -1;
       }
}

/******************************************************************************/

void Semestre::clear_mat()
{
 if(n_materias>0)
   {
    delete [] mat;
    mat=NULL;
   }
 n_materias=0;
}

/******************************************************************************/

Semestre& Semestre::operator=(const Semestre &a)
{
 int i;
 if(*this==a)return (*this);
 nombre=a.nombre;
 n_materias=a.n_materias;
 for(i=0;i<a.n_materias;i++)
    {
     mat[i]=a.mat[i];
    }
 return (*this);
}

/******************************************************************************/

int operator==(const Semestre &a,const Semestre &b)
{
 return a.nombre==b.nombre;
}

/******************************************************************************/

int operator!=(const Semestre &a,const Semestre &b)
{
 return a.nombre!=b.nombre;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Semestre &a)
{
 co << a.nombre.c_str();
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Semestre &a)
{
 char tem[100];
 ci >> tem;
 a.nombre=tem;
 return ci;
}

/*-------------------------------Director-------------------------------------*/

char* Director::encritar(void)
{
 char *encri;
 char *tem;
 tem=new char [strlen(clave.c_str())+1];
 strcpy(tem,clave.c_str());
 unsigned int i;
 if(clave!=NULL)
   {
    encri=new char [strlen(clave.c_str())+1];
    for(i=0;i<=strlen(clave.c_str());i++)
       {
        encri[i]=~tem[i];
       }
    return encri;
   }
 else return 0;
}

/******************************************************************************/

void Director::desencritar(char *encri)
{
 char *clas;
 unsigned int i;
 clas=new char [strlen(encri)+1];
 for(i=0;i<=strlen(encri);i++)
    {
     clas[i]=~encri[i];
    }
 clave=clas;
 delete [] clas;
 return;
}

/******************************************************************************/

void Director::clavear(char *cla)
{
 int j;
 clave=cla;
 return;
}

/******************************************************************************/

void Director::clavear_encri(char *encri)
{
 desencritar(encri);
 return;
}

/******************************************************************************/

char* Director::darclave_encri(void)
{
 return encritar();
}

/******************************************************************************/

int Director::verificar(char *cla)
{
 return strcmp(clave.c_str(),cla);
}

/******************************************************************************/

Director& Director::operator=(const Director &a)
{
 if(*this==a)return (*this);
 identidad=a.identidad;
 clave=a.clave;
 return (*this);
}

/******************************************************************************/

int operator==(const Director &a,const Director &b)
{
 return a.identidad==b.identidad;
}

/******************************************************************************/

int operator!=(const Director &a,const Director &b)
{
 return a.identidad!=b.identidad;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Director &a)
{
 co << a.identidad << "\t";
 co << a.encritar();
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Director &a)
{
 char tem[100];
 ci >> a.identidad;
 ci >> tem;
 a.desencritar(tem);
 return ci;
}

/*-------------------------------Horario--------------------------------------*/

void Horario::nombrar(char *nom)
{
 Ac_acond(nom);
 if(nom==NULL)
   {
    nombre="";
    return;
   }
 nombre=nom;
 return;
}

/******************************************************************************/

void Horario::numerar(int num)
{
 if(num<=0)return;
 n_sem=num;
 Sem=new Semestre[n_sem];
 return;
}

/******************************************************************************/

void Horario::ingre_pro(int num)
{
 if(num<=0)return;
 n_profe=num;
 if(profe!=NULL)
   {
    delete [] profe;
    profe=NULL;
   }
 profe= new Profesor [n_profe];
 return;
}

/******************************************************************************/

void Horario::ingre_est(int num)
{
 if(num<=0)return;
 n_estudiantes=num;
 if(est!=NULL)
   {
    delete [] est;
    est=NULL;
   }
 est= new Estudiante [n_estudiantes];
 return;
}

/******************************************************************************/

void Horario::ingre_sal(int num)
{
 if(num<=0)return;
 n_sal=num;
 if(sal!=NULL)
   {
    delete [] sal;
    sal=NULL;
   }
 sal= new Salon [n_sal];
 return;
}

/******************************************************************************/

char* Horario::decir_nombre(void)
{
 return nombre.c_str();
}

/******************************************************************************/

int Horario::dar_numero(void)
{
 return n_sem;
}

/******************************************************************************/

int Horario::dar_profes(void)
{
 return n_profe;
}

/******************************************************************************/

int Horario::dar_estudiantes(void)
{
 return n_estudiantes;
}

/******************************************************************************/

int Horario::dar_salones(void)
{
 return n_sal;
}

/******************************************************************************/

void Horario::add_sem(char *nom)
{
 int i,j,k,l;
 Semestre tem;
 Ac_acond(nom);
 i=ind_seme(nom);
 if(i!=-1)
   {
   return;/*El semestre ya existe*/
   }
 tem.nombrar(nom);
 agregar(Sem,tem,n_sem);
 return;
}

/******************************************************************************/

void Horario::add_profe(char *nom,char *cod)
{
 int i,j;
 Profesor tem;
 Ac_acond(nom);
 Ac_acond(cod);
 i=ind_prof(cod);
 if(i!=-1)
   {
    return;/*El profesor ya existe*/
   }
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 agregar(profe,tem,n_profe);
 return;
}

/******************************************************************************/

void Horario::add_est(char *nom,char *cod)
{
 int i,j;
 Estudiante tem;
 Ac_acond(nom);
 Ac_acond(cod);
 i=ind_est(cod);
 if(i!=-1)
   {
    return;/*El estudiante ya existe*/
   }
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 agregar(est,tem,n_estudiantes);
 return;
}

/******************************************************************************/

void Horario::add_sal(char *nom,char *cod)
{
 int i;
 Salon tem;
 Ac_acond(nom);
 Ac_acond(cod);
 i=ind_sal(cod);
 if(i!=-1)
   {
    return;/*El salon ya existe*/
   }
 tem.identidad.ingre_nom(nom);
 tem.identidad.ingre_cod(cod);
 agregar(sal,tem,n_sal);
 return;
}

/******************************************************************************/

void Horario::del_sem(char *nom)
{
 int j;
 Semestre tem;
 j=ind_seme(nom);
 if(j==-1)
   {
    return;
   }
   else{
        tem.nombrar(nom);
        quitar(Sem,tem,n_sem);
       }
 return;
}

/******************************************************************************/

void Horario::del_profe(char *nom,char *cod)
{
 int j;
 Profesor tem;
 j=ind_prof(nom);
 if(j==-1)
   {
    return;
   }
   else{
        tem.identidad.ingre_nom(nom);
        tem.identidad.ingre_cod(cod);
        quitar(profe,tem,n_profe);
       }
 return;
}

/******************************************************************************/

void Horario::del_est(char *nom,char *cod)
{
 int j;
 Estudiante tem;
 j=ind_est(nom);
 if(j==-1)
   {
    return;
   }
   else{
        tem.identidad.ingre_nom(nom);
        tem.identidad.ingre_cod(cod);
        quitar(est,tem,n_estudiantes);
       }
 return;
}

/******************************************************************************/

void Horario::del_sal(char *nom,char *cod)
{
 int j;
 Salon tem;
 j=ind_prof(nom);
 if(j==-1)
   {
    return;
   }
   else{
        tem.identidad.ingre_nom(nom);
        tem.identidad.ingre_cod(cod);
        quitar(sal,tem,n_sal);
       }
 return;
}

/******************************************************************************/

void Horario::act_sem(char *nom,char *nom1)
{
 int i;
 Semestre tem;
 i=ind_seme(nom);
 tem.nombrar(nom1);
 Sem[i]=tem;
 return;
}

/******************************************************************************/

void Horario::act_profe(char *nom,char *cod,char *nom1,char *cod1)
{
 int i;
 Profesor tem;
 i=ind_prof(cod);
 tem.identidad.ingre_nom(nom1);
 tem.identidad.ingre_cod(cod1);
 profe[i]=tem;
 return;
}

/******************************************************************************/

void Horario::act_est(char *nom,char *cod,char *nom1,char *cod1)
{
 int i;
 Estudiante tem;
 i=ind_est(cod);
 tem.identidad.ingre_nom(nom1);
 tem.identidad.ingre_cod(cod1);
 est[i]=tem;
 return;
}

/******************************************************************************/

void Horario::act_sal(char *nom,char *cod,char *nom1,char *cod1)
{
 int i;
 Salon tem;
 i=ind_sal(cod);
 tem.identidad.ingre_nom(nom1);
 tem.identidad.ingre_cod(cod1);
 sal[i]=tem;
 return;
}

/******************************************************************************/

char* Horario::mat_gru(char *cod)
{
 char *tem;
 int i,j,k,l;
 Ac_acond(cod);
 tem=NULL;
 if(n_sem>0)
   {
    for(i=0;i<n_sem;i++)
       {
        if(Sem[i].dar_numerom()>0)
          {
           for(j=0;j<Sem[i].dar_numerom();j++)
              {
               if(Sem[i].mat[j].dar_grupos()>0)
                 {
                  for(k=0;k<Sem[i].mat[j].dar_grupos();k++)
                     {
                      l=strcmp(cod,Sem[i].mat[j].gru[k].identidad.dar_cod());
                      if(l==0)
                        {
                         tem=Sem[i].mat[j].identidad.dar_cod();
                        }
                     }
                 }
              }
          }
       }
   }
 return tem;
}

/******************************************************************************/

int Horario::ind_prof(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_profe==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_profe;i++)
           {
            if(strcmp(profe[i].identidad.dar_cod(),cod)==0)return i;
            }
        return -1;
       }
}

/******************************************************************************/

int Horario::ind_est(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_estudiantes==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_estudiantes;i++)
           {
            if(strcmp(est[i].identidad.dar_cod(),cod)==0)return i;
           }
        return -1;
       }
}

/******************************************************************************/

int Horario::ind_sal(char *cod)
{
 int i;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 if(n_sal==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_sal;i++)
           {
            if(strcmp(sal[i].identidad.dar_cod(),cod)==0)return i;
           }
        return -1;
       }
}

/******************************************************************************/

int Horario::ind_seme(char *nom)
{
 int i;
 Ac_acond(nom);
 if(nom==NULL)return -1;
 if(n_sem==0)
   {
    return -1;
   }
   else{
        for(i=0;i<n_sem;i++)
           {
            Ac_acond(nom);
            if(strcmp(Sem[i].dar_nombre(),nom)==0)return i;
           }
        return -1;
       }
}

/******************************************************************************/

int Horario::sem_mat(char *cod)
{
 int i,j;
 Ac_acond(cod);
 if(cod==NULL)return -1;
 for(i=0;i<n_sem;i++)
    {
     j=Sem[i].ind_mat(cod);
     if(j!=-1)return i;
     }
 return -1;
}

/******************************************************************************/

void Horario::clear_sem()
{
 if(n_sem>0)
   {
    delete [] Sem;
    Sem=NULL;
   }
 n_sem=0;
}

/******************************************************************************/

void Horario::clear_profe()
{
 if(n_profe>0)
   {
    delete [] profe;
    profe=NULL;
   }
 n_profe=0;
}

/******************************************************************************/

void Horario::clear_est()
{
 if(n_estudiantes>0)
   {
    delete [] est;
    est=NULL;
   }
 n_estudiantes=0;
}

/******************************************************************************/

void Horario::clear_sal()
{
 if(n_sal>0)
   {
    delete [] sal;
    sal=NULL;
   }
 n_sal=0;
}

/******************************************************************************/

int Horario::n_mat(void)
{
 int ind_sem;
 int acc_mat;
 //Cuenta de materias
 for(ind_sem=0,acc_mat=0;ind_sem<n_sem;ind_sem++)
    {
     acc_mat+=Sem[ind_sem].dar_numerom();
    }
 return acc_mat;
}

/******************************************************************************/

int Horario::n_gru(void)
{
 int ind_sem,ind_mat;
 int acc_gru;
 //Cuenta de grupos
 for(ind_sem=0,acc_gru=0;ind_sem<n_sem;ind_sem++)
    {
     for(ind_mat=0;ind_mat<Sem[ind_sem].dar_numerom();ind_mat++)
        {
         acc_gru+=Sem[ind_sem].mat[ind_mat].dar_grupos();
        }
    }
 return acc_gru;
}

/******************************************************************************/

int Horario::n_secc(void)
{
 int ind_sem,ind_mat,ind_gru;
 int acc_secc;
 //Cuenta de secc
 for(ind_sem=0,acc_secc=0;ind_sem<n_sem;ind_sem++)
    {
     for(ind_mat=0;ind_mat<Sem[ind_sem].dar_numerom();ind_mat++)
        {
         for(ind_gru=0;ind_gru<Sem[ind_sem].mat[ind_mat].dar_grupos();ind_gru++)
            {
             acc_secc+=Sem[ind_sem].mat[ind_mat].gru[ind_gru].n_secc();
            }
        }
    }
 return acc_secc;
}

/******************************************************************************/

Horario& Horario::operator=(const Horario &a)
{
 if(*this==a)return (*this);
 int i;
 nombre=a.nombre;
 n_sem=a.n_sem;
 for(i=0;i<a.n_sem;i++)
    {
     Sem[i]=a.Sem[i];
    }
 n_profe=a.n_profe;
 for(i=0;i<a.n_profe;i++)
    {
     profe[i]=a.profe[i];
    }
 n_estudiantes=a.n_estudiantes;
 for(i=0;i<a.n_estudiantes;i++)
    {
     est[i]=a.est[i];
    }
 n_sal=a.n_sal;
 for(i=0;i<a.n_sal;i++)
    {
     sal[i]=a.sal[i];
    }
 Dir=a.Dir;
 return (*this);
}

/******************************************************************************/

int operator==(const Horario &a,const Horario &b)
{
 return a.nombre==b.nombre;
}

/******************************************************************************/

int operator!=(const Horario &a,const Horario &b)
{
 return a.nombre!=b.nombre;
}

/******************************************************************************/

ostream& operator<< (ostream &co,const Horario &a)
{
 co << a.nombre.c_str() << endl;
 co << a.Inicio << endl;
 co << a.Final << endl;
 get_sal(co,a);
 get_pro(co,a);
 get_sem(co,a);
 get_mat(co,a);
 get_gru(co,a);
 get_secc(co,a);
 get_est(co,a);
 co << a.Dir << endl;
 return co;
}

/******************************************************************************/

istream& operator>> (istream &ci,Horario &a)
{
 char tem[100];
 ci >> tem;
 a.nombre=tem;
 ci >> a.Inicio;
 ci >> a.Final;
 set_sal(ci,a);
 set_pro(ci,a);
 set_sem(ci,a);
 set_mat(ci,a);
 set_gru(ci,a);
 set_secc(ci,a);
 set_est(ci,a);
 ci >> a.Dir;
 return ci;
}

/******************************************************************************/

void get_sem(ostream &co,const Horario &a)
{
 int i;
 co << a.n_sem << endl;
 for(i=0;i<a.n_sem;i++)
    {
     co << a.Sem << endl;
    }
  return;
}

/******************************************************************************/

void get_mat(ostream &co,const Horario &a)
{
 int ind_sem,ind_mat;
 int n_mat;
 n_mat=a.n_mat();
 co << n_mat << endl;
 for(ind_sem=0;ind_sem<a.n_sem;ind_sem++)
    {
     for(ind_mat=0;ind_mat<a.Sem[ind_sem].dar_numerom();ind_mat++)
        {
         co << a.Sem[ind_sem].dar_nombre();
         co << a.Sem[ind_sem].mat[ind_mat] << endl;
        }
    }
 return;
}

/******************************************************************************/

void get_gru(ostream &co,const Horario &a)
{
 int i,ind_sem,ind_mat,ind_gru;
 int n_gru;
 n_gru=a.n_gru();
 co << n_gru << endl;
 for(ind_sem=0;ind_sem<a.n_sem;ind_sem++)
    {
     for(ind_mat=0;ind_mat<a.Sem[ind_sem].dar_numerom();ind_mat++)
        {
         for(ind_gru=0;ind_gru<a.Sem[ind_sem].mat[ind_mat].dar_grupos();ind_gru++)
            {
             co << a.Sem[ind_sem].mat[ind_mat].identidad.dar_cod() << "\t";
             co << a.Sem[ind_sem].mat[ind_mat].gru[ind_gru] << endl;
            }
        }
    }
 return;
}

/******************************************************************************/

void get_secc(ostream &co,const Horario &a)
{
 int i,ind_sem,ind_mat,ind_gru,ind_secc;
 int n_secc;
 n_secc=a.n_secc();
 co << n_secc << endl;
 for(ind_sem=0;ind_sem<a.n_sem;ind_sem++)
    {
     for(ind_mat=0;ind_mat<a.Sem[ind_sem].dar_numerom();ind_mat++)
        {
         for(ind_gru=0;ind_gru<a.Sem[ind_sem].mat[ind_mat].dar_grupos();ind_gru++)
            {
             for(ind_secc=0;ind_secc<a.Sem[ind_sem].mat[ind_mat].gru[ind_gru].n_secc();ind_secc++)
                {
                 co << a.Sem[ind_sem].mat[ind_mat].identidad.dar_cod() << "\t";
                 co << a.Sem[ind_sem].mat[ind_mat].gru[ind_gru].identidad.dar_cod() << "\t";
                 co << a.Sem[ind_sem].mat[ind_mat].gru[ind_gru].secc[ind_secc] << endl;
                }
            }
        }
    }
 return;
}

/******************************************************************************/

void get_pro(ostream &co,const Horario &a)
{
 int i;
 co << a.n_profe << endl;
 for(i=0;i<a.n_profe;i++)
    {
     co << a.profe << endl;
    }
 return;
}

/******************************************************************************/

void get_est(ostream &co,const Horario &a)
{
 int i;
 co << a.n_estudiantes << endl;
 for(i=0;i<a.n_estudiantes;i++)
    {
     co << a.est[i] << endl;
    }
 return;
}

/******************************************************************************/

void get_sal(ostream &co,const Horario &a)
{
 int i;
 co << a.n_sal << endl;
 for(i=0;i<a.n_sal;i++)
    {
     co << a.sal[i] << endl;
    }
 return;
}

/******************************************************************************/

void set_sem(istream &ci,Horario &a)
{
 int i,n,ind_sem;
 Semestre tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> tem;
     ind_sem=a.ind_seme(tem.dar_nombre());
     if(ind_sem<0)
       {
        agregar(a.Sem,tem,a.n_sem);
       }
       else{
            a.Sem[ind_sem]=tem;
           }
    }
 return;
}

/******************************************************************************/

void set_mat(istream &ci,Horario &a)
{
 int i,n,ind_sem,ind_mat;
 char sem[100];
 Materia tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> sem;
     ci >> tem;
     ind_sem=a.ind_seme(sem);
     if(ind_sem>=0)
       {
        a.Sem[ind_sem].add_materia("Nombre",tem.identidad.dar_cod());
        ind_mat=a.Sem[ind_sem].ind_mat(tem.identidad.dar_cod());
        if(ind_mat>=0)
          {
           a.Sem[ind_sem].mat[ind_mat]=tem;
          }
       }
    }
}

/******************************************************************************/

void set_gru(istream &ci,Horario &a)
{
 int i,n,ind_sem,ind_mat,ind_gru;
 char mat[100];
 Grupo tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> mat;
     ci >> tem;
     ind_sem=a.sem_mat(mat);
     if(ind_sem>=0)
       {
        ind_mat=a.Sem[ind_sem].ind_mat(mat);
        if(ind_mat>=0)
          {
           a.Sem[ind_sem].mat[ind_mat].add_gru("Nombre",tem.identidad.dar_cod());
           ind_gru=a.Sem[ind_sem].mat[ind_mat].ind_gru(tem.identidad.dar_cod());
           if(ind_gru>=0)
             {
              a.Sem[ind_sem].mat[ind_mat].gru[ind_gru]=tem;
             }
          }
       }
    }
}

/******************************************************************************/

void set_secc(istream &ci,Horario &a)
{
 int i,n,ind_sem,ind_mat,ind_gru;
 char mat[100],gru[100];
 Seccion tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> mat;
     ci >> gru;
     ci >> tem;
     ind_sem=a.sem_mat(mat);
     if(ind_sem>=0)
       {
        ind_mat=a.Sem[ind_sem].ind_mat(mat);
        if(ind_gru>=0)
          {
           ind_gru=a.Sem[ind_sem].mat[ind_mat].ind_gru(gru);
           if(ind_gru>=0)
             {
              a.Sem[ind_sem].mat[ind_mat].gru[ind_gru].add_clas(tem);
             }
          }
       }
    }
}

/******************************************************************************/

void set_pro(istream &ci,Horario &a)
{
 int i,n,ind_pro;
 Profesor tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> tem;
     ind_pro=a.ind_prof(tem.identidad.dar_cod());
     if(ind_pro<0)
       {
        agregar(a.profe,tem,a.n_profe);
       }
     a.profe[ind_pro]=tem;  
    }
 return;
}

/******************************************************************************/

void set_est(istream &ci,Horario &a)
{
 int i,j,n,n_reg,ind_sem,ind_mat,ind_gru,ind_est;
 Estudiante tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> tem;
     ind_est=a.ind_est(tem.identidad.dar_cod());
     if(ind_est<0)
       {
        agregar(a.est,tem,a.n_estudiantes);
       }
       else{
            a.est[ind_est]=tem;
           }
        n_reg=tem.asig.dar_tol();
     for(j=0;j<n_reg;j++)
        {
         ind_sem=a.ind_seme(tem.asig.dar_sem(j));
         ind_mat=a.Sem[ind_sem].ind_mat(tem.asig.dar_mat(j));
         ind_gru=a.Sem[ind_sem].mat[ind_mat].ind_gru(tem.asig.dar_gru(j));
         a.Sem[ind_sem].mat[ind_mat].gru[ind_gru].add_estu(tem.identidad.dar_cod());
        }
    }
 return;
}

/******************************************************************************/

void set_sal(istream &ci,Horario &a)
{
 int i,n,ind_sal;
 Salon tem;
 ci >> n;
 for(i=0;i<n;i++)
    {
     ci >> tem;
     ind_sal=a.ind_sal(tem.identidad.dar_cod());
     if(ind_sal<0)
       {
        agregar(a.sal,tem,a.n_sal);
       }
       else{
            a.sal[ind_sal]=tem;
           }
    }
 return;
}

/******************************************************************************/



/*--------------------------------fin-----------------------------------------*/
