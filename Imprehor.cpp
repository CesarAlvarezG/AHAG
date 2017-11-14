#include "Imprehor.h"

/*------------------------------CLASES----------------------------------------*/

Imprehora::Imprehora()
{
 Prntr = Printer();
}

/******************************************************************************/

Imprehora::~Imprehora()
{

}

/******************************************************************************/

void Imprehora::inicializar_imp(void)
{
 Prntr->BeginDoc();
 inicializar_hoja();
}

/******************************************************************************/

void Imprehora::finalizar_imp(void)
{
 Prntr->EndDoc();//Nueva hoja por necesidad de espacio
}

/******************************************************************************/

void Imprehora::inicializar_hoja(void)
{
 x=50;//posicion en hoja en mm
 y=7;//posicion en hoja en mm
 xp=(x*Prntr->PageWidth)/216; //Ancho de una carta 216mm
 yp=(y*Prntr->PageHeight)/279; //Alto de una carta  279mm
 Prntr->Canvas->TextOutA(xp,yp,"AHAG 1.0: ASIGNACION DE HORARIOS POR MEDIO DE ALGORITMOS GENETICOS");
 y=20;
 x=10;
}

/******************************************************************************/

void Imprehora::finalizar_hoja(void)
{
 x=90;//posicion en hoja en mm
 y=270;//posicion en hoja en mm
 xp=(x*Prntr->PageWidth)/216; //Ancho de una carta 216mm
 yp=(y*Prntr->PageHeight)/279; //Alto de una carta  279mm
 Prntr->Canvas->TextOutA(xp,yp,"TESIS DE INGENIERIA ELECTRONICA");
 Prntr->NewPage();
}

/******************************************************************************/

void Imprehora::posicionar(void)
{
 if(y>256)
   {
    finalizar_hoja();
    inicializar_hoja();
   }
 xp=(x*Prntr->PageWidth)/216; //Ancho de una carta 216mm
 yp=(y*Prntr->PageHeight)/279; //Alto de una carta  279mm
}

/******************************************************************************/

void Imprehora::nueva_linea(void)
{
 int j;
 j=(3*Prntr->Canvas->Font->Size)/8;
 y+=j;
 posicionar();
}

/******************************************************************************/

void Imprehora::printf_tex(char *text)
{
 Prntr->Canvas->TextOutA(xp,yp,text);
 nueva_linea();
}

/******************************************************************************/

void Imprehora::centrar(char *text)
{
 int a,i;
 a=strlen(text);
 i=(143-a)/2;
 x=(i*216)/143;
 posicionar();
 printf_tex(text);
}

/******************************************************************************/

void Imprehora::imp_sem(int ind_sem)
{
 int ind_mat,a;
 q="********************";
 q+=carr.Sem[ind_sem].dar_nombre();
 q+="********************";
 centrar(q.c_str());
 for(ind_mat=0;ind_mat<carr.Sem[ind_sem].dar_numerom();ind_mat++)
    {
     nueva_linea();
     nueva_linea();
     imp_mat(ind_sem,ind_mat);
    }
}

/******************************************************************************/

void Imprehora::imp_mat(int ind_sem,int ind_mat)
{
 int ind_gru;
 q=carr.Sem[ind_sem].mat[ind_mat].identidad.dar_nom();
 q+=", cod:  ";
 q+=carr.Sem[ind_sem].mat[ind_mat].identidad.dar_cod();
 q+=".   No de grupos: ";
 q+=carr.Sem[ind_sem].mat[ind_mat].dar_grupos();
 centrar(q.c_str());
 for(ind_gru=0;ind_gru<carr.Sem[ind_sem].mat[ind_mat].dar_grupos();ind_gru++)
    {
     nueva_linea();
     imp_gru(ind_sem,ind_mat,ind_gru);
    }
}

/******************************************************************************/

void Imprehora::imp_gru(int ind_sem,int ind_mat,int ind_gru)
{
 int ind_pro,ind_secc;
 x=20;
 posicionar();
 q=carr.Sem[ind_sem].mat[ind_mat].gru[ind_gru].identidad.dar_nom();
 q+=": No de secciones: ";
 q+=carr.Sem[ind_sem].mat[ind_mat].gru[ind_gru].n_secc();
 q+=".  Profesor:  ";
 ind_pro=carr.ind_prof(carr.Sem[ind_sem].mat[ind_mat].gru[ind_gru].anu_profe());
 if(ind_pro!=-1)
   {
    q+=carr.profe[ind_pro].identidad.dar_nom();
   }
   else q+="NaN";
 printf_tex(q.c_str());
 nueva_linea();
 for(ind_secc=0;ind_secc<carr.Sem[ind_sem].mat[ind_mat].gru[ind_gru].n_secc();ind_secc++)
    {
     imp_secc(ind_sem,ind_mat,ind_gru,ind_secc);
    }
}

/******************************************************************************/

void Imprehora::imp_secc(int ind_sem,int ind_mat,int ind_gru,int ind_secc)
{
 int f,d,ind_sal;
 x=30;
 posicionar();
 q=carr.Sem[ind_sem].mat[ind_mat].gru[ind_gru].secc[ind_secc].time.to_str();
 ind_sal=carr.ind_sal(carr.Sem[ind_sem].mat[ind_mat].gru[ind_gru].secc[ind_secc].dar_salon());
 if(ind_sal!=-1)q+=carr.sal[ind_sal].identidad.dar_nom();
 printf_tex(q.c_str());
}

/******************************************************************************/

void Imprehora::imprimir()
{
 int ind_sem;
 Prntr->Title=carr.decir_nombre();
 inicializar_imp();
 centrar(carr.decir_nombre());
 x=10;
 nueva_linea();
 for(ind_sem=0;ind_sem<carr.dar_numero();ind_sem++)
    {
     nueva_linea();
     imp_sem(ind_sem);
    }
 finalizar_imp();
 return;
}
