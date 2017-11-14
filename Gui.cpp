//////////////////////////////GUI.CPP///////////////////////////////////////////

/////////////////////////////LIBRERIAS//////////////////////////////////////////

#include "Gui.h"
#include <vcl.h>
#include <string.h>
#include "Mio.h"


/////////////////////////////VARIABLES//////////////////////////////////////////

ofstream archo;/*Objecto para manipulacion de archivos de salida*/
ifstream archi;/*Objecto para manipulacion de archivos de entrada*/

/////////////////////////////FUNCIONES//////////////////////////////////////////

/******************************************************************************/

int Gui_Cons_Sem(char n_sem,Horario &carr)
{
 int i;
 i=carr.dar_numero();
 if(i==0)return 1;
 if(n_sem<=i)return 0;
 else return 1;
}

/******************************************************************************/

int Gui_Cons_Usu(int usuario, char* codigo, Horario &carr)
{
 int i,j,n;
 switch(usuario){
                 case 0:/*Director*/
                        i=strcmp(codigo,carr.Dir.identidad.dar_cod());
                        /*Se compara el codigo ingresa con el del director*/
                        if(i==0)return 0;
                        else return 1;
                 case 1:/*Profesor*/
                        i=carr.ind_prof(codigo);
                        if(i==-1)return 1;
                        else return 0;
                 case 2:/*Estudiante*/
                        i=carr.ind_est(codigo);
                        if(i==-1)return 1;
                        else return 0;
                 default:
                         ShowMessage("Usuario no valido");
                         return 1;
               }
}
/******************************************************************************/

int Gui_Cons_Cod(int opcion,char* codigo,Horario &carr)
{
 int i,j,h,l,k;
 char *tem;
 switch(opcion){
                case 0://Semestre
                       i=carr.ind_seme(codigo);
                       if(i==-1)return 1;
                       else return 0;
                case 1://Materia
                       i=carr.sem_mat(codigo);
                       if(i==-1)return 1;
                       else return 0;
                case 2://Salon
                       i=carr.ind_sal(codigo);
                       if(i==-1)return 1;
                       else return 0;
                case 3://Profesor
                       i=carr.ind_prof(codigo);
                       if(i==-1)return 1;
                       else return 0;
                case 4://Estudiante
                       i=carr.ind_est(codigo);
                       if(i==-1)return 1;
                       else return 0;
                case 5://Grupo
                       tem=carr.mat_gru(codigo);
                       if(tem==NULL)return 1;
                       else return 0;
                default:
                        ShowMessage("Opcion no valido");
                break;
               }
 return i;
}

/******************************************************************************/

int Gui_Cons_Reg(Horario &carr,char* codigo,char* grupo)
{
 int i,j,k,l;
 i=carr.sem_mat(codigo);
 if(i==-1)return 2;//La materia no existe
 j=carr.Sem[i].ind_mat(codigo);
 k=carr.Sem[i].mat[j].ind_gru(grupo);
 l=carr.Sem[i].mat[j].gru[k].dar_capacidad()-carr.Sem[i].mat[j].gru[k].dar_ests();
 if(l>0)return 0;//La materia y el grupo existe y se puede registrar
 else return 3;
}

/******************************************************************************/

void Gui_guardar_horario(Horario &carr,char *nombre)
{
 int i,len;
 char ext[4];
 bool prueba;
/*--------Apertura del archivo para el almacenamiento del horario-------------*/
 archo.open(nombre);
 prueba=archo.is_open();
 if(prueba==true)
   {
    len=strlen(nombre);
    for(i=0;i<3;i++)
       {
        ext[i]=nombre[len-3+i];/*Extencion del archivo*/
       }
/*-------------------------Horario--------------------------------------------*/
    if(Mi_strcmp(ext,"hor")==0)
      {
       archo << carr;
      }
/*----------------------Datos de los salones----------------------------------*/
    if(Mi_strcmp(ext,"sal")==0)
      {
       Gui_guardar_sal(carr);
      }
/*----------------------Datos de los profesores-------------------------------*/
    if(Mi_strcmp(ext,"pro")==0)
      {
       Gui_guardar_prof(carr);
      }
/*-----------------------Datos de semestre------------------------------------*/
    if(Mi_strcmp(ext,"sem")==0)
      {
       Gui_guardar_sem(carr);
      }
/*-----------------------Datos de materias------------------------------------*/
    if(Mi_strcmp(ext,"mte")==0)
      {
       Gui_guardar_mat(carr);
      }
/*----------------------Datos de los grupos-----------------------------------*/
    if(Mi_strcmp(ext,"gru")==0)
      {
       Gui_guardar_gru(carr);
      }
/*-----------------Datos de las secciones-------------------------------------*/
    if(Mi_strcmp(ext,"sec")==0)
      {
       Gui_guardar_secc(carr);
      }
/*--------------------------Datos de los estudiantes--------------------------*/
    if(Mi_strcmp(ext,"est")==0)
      {
       Gui_guardar_est(carr);
      }
    archo.close();/*Cierre del archivo*/
   }
 else{
      ShowMessage("ERROR. EL ARCHIVO NO SE PUDO GUARDAR");
     }
 return;
}

/******************************************************************************/

void Gui_guardar_sal(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 get_sal(archo,carr);
}

/******************************************************************************/

void Gui_guardar_prof(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 get_pro(archo,carr);
}


/******************************************************************************/

void Gui_guardar_sem(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 /*Almacenamineto del numero de semestres*/
 get_sem(archo,carr);
 return;
}

/******************************************************************************/

void Gui_guardar_mat(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 get_mat(archo,carr);
}

/******************************************************************************/

void Gui_guardar_gru(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 get_gru(archo,carr);
}

/******************************************************************************/

void Gui_guardar_secc(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 get_secc(archo,carr);
}

/******************************************************************************/

void Gui_guardar_est(Horario &carr)
{
 bool prueba=false;
 prueba=archo.is_open();
 if(prueba==false)
   {
    return;
   }
 get_est(archo,carr);
}

/******************************************************************************/

void Gui_abrir_horario(Horario &carr,char *nombre)
{
 char *s,ext[4],cmp[4];
 int i,j,k,l,o,tem;
 int f,len;
 bool prueba;
 s=nombre;
 archi.open(s);//Apretura del archivo para la utilizacion del horario
 prueba=archi.is_open();
 if(prueba==true)
   {
    len=strlen(nombre);
    for(i=0;i<3;i++)
       {
        ext[i]=nombre[len-3+i];/*Extencion del archivo*/
       }
/*---------------------------Horario------------------------------------------*/
    if(Mi_strcmp(ext,"hor")==0)
      {
       archi >> carr;
      }
/*---------------------------Salones------------------------------------------*/
    if(Mi_strcmp(ext,"sal")==0)
      {
       Gui_abrir_sal(carr);
      }
/*----------------------Datos de los profesores-------------------------------*/
    if(Mi_strcmp(ext,"pro")==0)
      {
       Gui_abrir_prof(carr);
      }
/*------------------------Datos de los semestres------------------------------*/
    if(Mi_strcmp(ext,"sem")==0)
      {
       Gui_abrir_sem(carr);
      }
/*------------------------Datos de materias-----------------------------------*/
    if(Mi_strcmp(ext,"mte")==0)
      {
       Gui_abrir_mat(carr);
      }
/*-------------------------Datos de los grupos--------------------------------*/
    if(Mi_strcmp(ext,"gru")==0)
      {
       Gui_abrir_gru(carr);
      }
/*--------------------------Datos de las secciones----------------------------*/
    if(Mi_strcmp(ext,"sec")==0)
      {
       Gui_abrir_secc(carr);
      }
/*---------------------------Datos de los estudiantes-------------------------*/
    if(Mi_strcmp(ext,"est")==0)
      {
       Gui_abrir_est(carr);
      }
    archi.close();/*Cierre del archivo*/
   }
 else{
      ShowMessage("ERROR. EL ARCHIVO NO SE PUDO ABRIR");
     }
 return;
}

/******************************************************************************/

void Gui_abrir_sal(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_sal(archi,carr);
}

/******************************************************************************/

void Gui_abrir_prof(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_pro(archi,carr);
}

/******************************************************************************/

void Gui_abrir_sem(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_sem(archi,carr);
}

/******************************************************************************/

void Gui_abrir_mat(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_mat(archi,carr);
 }
/******************************************************************************/

void Gui_abrir_gru(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_gru(archi,carr);
}

/******************************************************************************/

void Gui_abrir_secc(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_secc(archi,carr);
}

/******************************************************************************/

void Gui_abrir_est(Horario &carr)
{
 bool prueba=false;
 prueba=archi.is_open();
 if(prueba==false)
   {
    return;
   }
 set_est(archi,carr);
}
