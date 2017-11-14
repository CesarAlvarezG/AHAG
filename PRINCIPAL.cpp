//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string.h>
#include "PRINCIPAL.h"
#include "Gui.h"
//#include "AG.h"
//#include "Imprehor.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PERFGRAP"
#pragma resource "*.dfm"

/******************************************************************************/

Horario carr;/*Objecto horario, puede ser puntero para asignacion dinamica en
             caso de ampliacion*/
/*Ag evolucion;/*Objecto Ag, para la evolucion de los horarios, puede ser puntero
             para el caso de la asognacion dinamica*/

int usuario;/*Varialble que indica el tipo de usuario que accede a la
            aplicacion. 0 Director, 1 Profesor, 2 Estudiante.*/

String s;

int acc_dir=0;/*Variable encargada describir las acciones del director*/

//int uso_vario;

int archivo;/*Variable que indica la operacion de archivo a realizar*/

int n_sem=0;/*Variable que indica cual es el semestre que el programa muestra en
           la pantalla.*/

int exito;/*Varible que indica si la opercion fue realizada con exito o no.
          si exito= 0: exito, !=0 falla*/

char codigo[40];/*Variable para la insercion de distintos codigos a lo largo de
                la ejecucion.*/

/*char nombre[40];/*Variable para la insercion de distintos nombres a lo largo de
                la ejecucion.*/

char codigo_usu[40];//Codigo del usuario actual

String nombregra;/*Variable para graficacion de los semestres*/

String cod_gri[6][20];/*Codigo de materias en el grid*/

String cod_gri_gru[6][20];/*Codigo de grupo en el grid*/

int ho[6][20];/*Seccion graficada en el horario*/

//char nombre_archivo[40];/*Variable para almacenar el nombre del archivo actual*/

char estado;/*Variable que indica el estado de los paneles, 0 adicionar,
            1 actualizar, 2 eliminar, 3 mover.*/

/*int elemento;/*Variable temporal usada para indicar el elemento sobre el cual se
             desea operar*/

/*int gene;/*Variable usada para conocer el numero de generacion actual en el
         algoritmo genetico*/

/*float evo;/*Variable encargada de registrar el valor del fitness en el mejor
          individuo*/

/******************************************************************************/

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


////////////////////////////GRAFICACION/////////////////////////////////////////

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 /*Mensaje inicial del programa*/
 ShowMessage("DESARROLLADO POR: ING. CESAR AUGUSTO ALVAREZ GASPAR");
 MessageBeep(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
 /*Dibujo del horario en el area de trabajo*/
 int Col,Row,ind_Col,ind_Row;
 TCita ini,fin,op;
 ini=carr.inicio();
 fin=carr.final();
 op.Hora=fin.Hora-ini.Hora;
 Row=op.Hora.ToInt();
 op.Dia=fin.Dia-ini.Dia;
 Col=op.Dia.ToInt();
 StringGrid1->ColCount=Col;
 StringGrid1->RowCount=Row;
 StringGrid1->DefaultColWidth=(0.98*StringGrid1->Width)/StringGrid1->ColCount;
 StringGrid1->DefaultRowHeight=(0.98*StringGrid1->Height)/StringGrid1->RowCount;
 StringGrid1->Repaint();
 op=ini;
 for(ind_Row=0,ind_Col=1;ind_Col<=Col;ind_Col++,op.Dia++)
    {
     StringGrid1->Cells[ind_Col][ind_Row]=op.Dia.to_str();
    }
 for(ind_Row=1,ind_Col=0;ind_Row<=Row;ind_Row++,op.Dia++)
    {
     StringGrid1->Cells[Col][Row]=op.Hora.to_str();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::USUARIOChange(TObject *Sender)
{
 /*ComboBox usuario*/
 int i,j;
 char tem[][10]={{"DIRECTOR"},{"PROFESOR"},{"ESTUDIANTE"}};
 /*comparar para dar valor*/
 for(i=0;i<4;i++)
    {
     s=USUARIO->Text;
     j=strcmp(tem[i],s.c_str());
     if(j==0)break;
    }
 usuario=i;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 /*Funcion cerrar programa*/
 ShowMessage("DESARROLLADO POR: ING. CESAR AUGUSTO ALVAREZ GASPAR");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label28Click(TObject *Sender)
{
 /*Funcion mostrar semestre en memo*/
 int i;
 String q;
 ListBox1->Clear();
 for(i=0;i<carr.dar_numero();i++)
    {
     q=carr.Sem[i].dar_nombre();
     ListBox1->Items->Add(q);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label1Click(TObject *Sender)
{
 /*Funcion mostrar curso en ListBox1*/
 int i,j;
 String q,t;
 ListBox1->Items->Clear();
 i=Gui_Cons_Sem(n_sem,carr);
 if(i==0)
   {
    for(i=0;i<carr.dar_numero();i++)
       {
        q=carr.Sem[i].dar_nombre();
        q+=":";
        ListBox1->Items->Add(q);
        q="";
        ListBox1->Items->Add(q);
        for(j=0;j<carr.Sem[i].dar_numerom();j++)
           {
            t=carr.Sem[i].mat[j].identidad.dar_nom();
            ListBox1->Items->Add(t);
           }
        q="";
        ListBox1->Items->Add(q);
        ListBox1->Items->Add(q);
       }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label3Click(TObject *Sender)
{
 /*Funcion mostrar profesores en ListBox*/
 int i,j;
 String q;
 ListBox1->Items->Clear();
 i=carr.dar_profes();
 if(i>=0)
   {
    for(i=0;i<carr.dar_profes();i++)
       {
        q=carr.profe[i].identidad.dar_nom();
        ListBox1->Items->Add(q);
        q="";
        ListBox1->Items->Add(q);
        for(j=0;j<carr.profe[i].asig.dar_tol();j++)
           {
            q=carr.profe[i].asig.dar_gru(j);
            ListBox1->Items->Add(q);
           }
       }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label4Click(TObject *Sender)
{
 /*Funcion mostrar salon en ListBox1*/
 int i,j;
 String q;
 ListBox1->Items->Clear();
 i=carr.dar_salones();
 if(i!=0)
   {
    for(i=0;i<carr.dar_salones();i++)
       {
        q=carr.sal[i].identidad.dar_nom();
        ListBox1->Items->Add(q);
       }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2Click(TObject *Sender)
{
 /*Funcion mostrar grupo en ListBox1*/
 int i,j,l;
 String q,t;
 ListBox1->Items->Clear();
 i=Gui_Cons_Sem(n_sem,carr);
 if(i==0)
   {
    for(i=0;i<carr.dar_numero();i++)
       {
        for(j=0;j<carr.Sem[i].dar_numerom();j++)
           {
            for(l=0;l<carr.Sem[i].mat[j].dar_grupos();l++)
               {
                q=carr.Sem[i].mat[j].gru[l].identidad.dar_nom();
                ListBox1->Items->Add(q);
               }
           }
       }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label27Click(TObject *Sender)
{
 /*Funcion mostrar estudiante en ListBox1*/
 int i,j;
 String q;
 ListBox1->Items->Clear();
 i=carr.dar_estudiantes();
 if(i>=0)
   {
    for(i=0;i<carr.dar_estudiantes();i++)
       {
        q=carr.est[i].identidad.dar_nom();
        ListBox1->Items->Add(q);
        q="";
        ListBox1->Items->Add(q);
        for(j=0;j<carr.est[i].asig.dar_tol();j++)
           {
            q=carr.est[i].asig.dar_gru(j);
            ListBox1->Items->Add(q);
           }
       }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
 /*Funcion encargada de colocar los dias de restricion del profesor*/
 int i,n;
 TCita ini,fin,op;
 ini=carr.inicio();
 fin=carr.final();
 op.Hora=fin.Hora-ini.Hora;
 op.Dia=fin.Dia-ini.Dia;
 ComboBox3->Items->Clear();
 n=op.Dia.ToInt();
 for(i=0;i<n;i++,op.Dia++)
    {
     ComboBox3->Items->Add(op.Dia.to_str());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox5Change(TObject *Sender)
{
 /*Funcion encargada de dar la hora de las restriciones del profesor*/
 int i,n;
 TCita ini,fin,op;
 ini=carr.inicio();
 fin=carr.final();
 op.Hora=fin.Hora-ini.Hora;
 op.Dia=fin.Dia-ini.Dia;
 ComboBox5->Items->Clear();
 n=op.Hora.ToInt();
 for(i=0;i<n;i++,op.Hora++)
    {
     ComboBox5->Items->Add(op.Hora.to_str());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
 /*Fucion encargda de dar el codigo del profesor en las restriciones*/
 /*ComboBox2 reemplaza a Edit43*/
 int i,n;
 n=carr.dar_profes();
 ComboBox2->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox2->Items->Add(carr.profe[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox6Change(TObject *Sender)
{
 /*Funcion encargada de ingresar el codigo del salon*/
 /*ComboBox6 reemplaza a Edit15*/
 int i,n;
 n=carr.dar_salones();
 ComboBox6->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox6->Items->Add(carr.sal[i].identidad.dar_nom());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox8Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del salon*/
 /*ComboBox8 reemplaza a Edit16*/
 int i,n;
 n=carr.dar_salones();
 ComboBox8->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox8->Items->Add(carr.sal[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox9Change(TObject *Sender)
{
 /*Funcion encargada de colocar el nombre de profesor*/
 /*ComboBox9 reemplaza a Edit38*/
 int i,n;
 n=carr.dar_profes();
 ComboBox9->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox9->Items->Add(carr.profe[i].identidad.dar_nom());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox10Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del profesor*/
 /*ComboBox10 reemplaza a Edit39*/
 int i,n;
 n=carr.dar_profes();
 ComboBox10->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox10->Items->Add(carr.profe[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox11Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del estudiante*/
 /*ComboBox11 reemplaza a Edit14*/
 int i,n;
 n=carr.dar_estudiantes();
 ComboBox11->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox11->Items->Add(carr.est[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox12Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo de la mataria*/
 /*ComboBox12 reemplaza a Edit13*/
 int i,j,n,m;
 n=carr.dar_numero();
 ComboBox12->Items->Clear();
 for(i=0;i<n;i++)
    {
     m=carr.Sem[i].dar_numerom();
     for(j=0;j<m;j++)
        {
         ComboBox12->Items->Add(carr.Sem[i].mat[j].identidad.dar_cod());
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox13Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del grupo*/
 /*ComboBox13 reemplaza a Edit44*/
 int i,j,k,n,m;
 ComboBox13->Items->Clear();
 i=carr.sem_mat(ComboBox12->Text.c_str());
 if(i<0)return;
 j=carr.Sem[i].ind_mat(ComboBox12->Text.c_str());
 if(j<0)return;
 n=carr.Sem[i].mat[j].dar_grupos();
 for(k=0;k<n;k++)
    {
     ComboBox13->Items->Add(carr.Sem[i].mat[j].gru[k].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox14Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo de la mataria*/
 /*ComboBox14 reemplaza a Edit21*/
 int i,j,n,m;
 n=carr.dar_numero();
 ComboBox14->Items->Clear();
 for(i=0;i<n;i++)
    {
     m=carr.Sem[i].dar_numerom();
     for(j=0;j<m;j++)
        {
         ComboBox14->Items->Add(carr.Sem[i].mat[j].identidad.dar_cod());
        }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox15Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del profesor*/
 /*ComboBox15 reemplaza a Edit6*/
 int i,n;
 n=carr.dar_profes();
 ComboBox15->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox15->Items->Add(carr.profe[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox16Change(TObject *Sender)
{
 /*Funcion encargada de colocar el nombre del grupo*/
 /*ComboBox16 reeplaza a Edit7*/
 int i,j,k,n,m;
 ComboBox16->Items->Clear();
 i=carr.sem_mat(ComboBox15->Text.c_str());
 if(i<0)return;
 j=carr.Sem[i].ind_mat(ComboBox15->Text.c_str());
 if(j<0)return;
 n=carr.Sem[i].mat[j].dar_grupos();
 for(k=0;k<n;k++)
    {
     ComboBox16->Items->Add(carr.Sem[i].mat[j].gru[k].identidad.dar_nom());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox17Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del grupo*/
 /*ComboBox17 reemplaza a Edit18*/
 int i,j,k,n,m;
 ComboBox17->Items->Clear();
 i=carr.sem_mat(ComboBox14->Text.c_str());
 if(i<0)return;
 j=carr.Sem[i].ind_mat(ComboBox14->Text.c_str());
 if(j<0)return;
 n=carr.Sem[i].mat[j].dar_grupos();
 for(k=0;k<n;k++)
    {
     ComboBox17->Items->Add(carr.Sem[i].mat[j].gru[k].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox18Change(TObject *Sender)
{
 /*Funcion encargada de colocar el nombre de la materia*/
 /*ComboBox18 reemplaza a Edit5*/
 int i,j,n,m;
 n=carr.dar_numero();
 ComboBox18->Items->Clear();
 for(i=0;i<n;i++)
    {
     m=carr.Sem[i].dar_numerom();
     for(j=0;j<m;j++)
        {
         ComboBox18->Items->Add(carr.Sem[i].mat[j].identidad.dar_nom());
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox19Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo de la materia*/
 /*ComboBox19 reemplaza a Edit4*/
 int i,j,n,m;
 n=carr.dar_numero();
 ComboBox19->Items->Clear();
 for(i=0;i<n;i++)
    {
     m=carr.Sem[i].dar_numerom();
     for(j=0;j<m;j++)
        {
         ComboBox19->Items->Add(carr.Sem[i].mat[j].identidad.dar_cod());
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox20Change(TObject *Sender)
{
 /*Funcion encargada de colocar los semestres*/
 /*ComboBox20 reeplaza a Edit35*/
 int i,n;
 ComboBox20->Items->Clear();
 n=carr.dar_numero();
 for(i=0;i<n;i++)
    {
     ComboBox20->Items->Add(carr.Sem[i].dar_nombre());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox21Change(TObject *Sender)
{
 /*Funcion encargada de colocar los semestres*/
 /*ComboBox21 reemplaza a Edit33*/
 int i,n;
 ComboBox21->Items->Clear();
 n=carr.dar_numero();
 for(i=0;i<n;i++)
    {
     ComboBox21->Items->Add(carr.Sem[i].dar_nombre());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox22Change(TObject *Sender)
{
 /*Funcion encargada de colocar el nombre del estudiante*/
 /*ComboBox22 reemplaza a Edit10*/
 int i,n;
 n=carr.dar_estudiantes();
 ComboBox22->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox22->Items->Add(carr.est[i].identidad.dar_nom());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox23Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del estudiante*/
 /*ComboBox23 reemplaza a Edit11*/
 int i,n;
 n=carr.dar_estudiantes();
 ComboBox23->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox23->Items->Add(carr.est[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox25Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo de la materia*/
 /*ComboBox25 reemplaza a Edit22*/
 int i,j,n,m;
 n=carr.dar_numero();
 ComboBox25->Items->Clear();
 for(i=0;i<n;i++)
    {
     m=carr.Sem[i].dar_numerom();
     for(j=0;j<m;j++)
        {
         ComboBox25->Items->Add(carr.Sem[i].mat[j].identidad.dar_cod());
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox26Change(TObject *Sender)
{
 /*Funcion encargada de colocar el codigo del grupo*/
 /*ComboBox26 reemplaza a Edit23*/
 int i,j,k,n,m;
 ComboBox26->Items->Clear();
 i=carr.sem_mat(ComboBox25->Text.c_str());
 if(i<0)return;
 j=carr.Sem[i].ind_mat(ComboBox25->Text.c_str());
 if(j<0)return;
 n=carr.Sem[i].mat[j].dar_grupos();
 for(k=0;k<n;k++)
    {
     ComboBox26->Items->Add(carr.Sem[i].mat[j].gru[k].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox27Change(TObject *Sender)
{
 /*ComboBox27 reemplaza a Edit36*/
 int i,n;
 n=carr.dar_salones();
 ComboBox27->Items->Clear();
 for(i=0;i<n;i++)
    {
     ComboBox27->Items->Add(carr.sal[i].identidad.dar_cod());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox4Change(TObject *Sender)
{
 int i,n;
 TCita ini,fin,op;
 ini=carr.inicio();
 fin=carr.final();
 op.Hora=fin.Hora-ini.Hora;
 op.Dia=fin.Dia-ini.Dia;
 ComboBox4->Items->Clear();
 n=op.Dia.ToInt();
 for(i=0;i<n;i++,op.Dia++)
    {
     ComboBox4->Items->Add(op.Dia.to_str());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox7Change(TObject *Sender)
{
 int i,n;
 TCita ini,fin,op;
 ini=carr.inicio();
 fin=carr.final();
 op.Hora=fin.Hora-ini.Hora;
 op.Dia=fin.Dia-ini.Dia;
 ComboBox7->Items->Clear();
 n=op.Hora.ToInt();
 for(i=0;i<n;i++,op.Hora++)
    {
     ComboBox7->Items->Add(op.Hora.to_str());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox28Change(TObject *Sender)
{
 /*Funcion encargada de colocar las secciones*/
 /*ComboBox28 reemmplaza a Edit24*/
 int i,j,k,l,n,m;
 String se;
 ComboBox28->Items->Clear();
 i=carr.sem_mat(ComboBox25->Text.c_str());
 if(i<0)return;
 j=carr.Sem[i].ind_mat(ComboBox25->Text.c_str());
 if(j<0)return;
 k=carr.Sem[i].mat[j].ind_gru(ComboBox26->Text.c_str());
 n=carr.Sem[i].mat[j].gru[k].n_secc();
 for(l=0;l<n;l++)
    {
     se=l;
     ComboBox28->Items->Add(se.c_str());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Graf_Sem(void)
{
 /*Funcion encargada de gaficar el horario*/
 int i,j,k,x,y;
 String t,g,f,se;
 TCita t1,op,ini,fin;
 ini=carr.inicio();
 fin=carr.final();
 /*se borra la graficacion anterior*/
 for(i=1;i<=StringGrid1->ColCount;i++)
    {
     for(j=1;j<=StringGrid1->RowCount;j++)
        {
         StringGrid1->Cells[i][j]=" ";
        }
    }
 if(carr.dar_numero()>0)
   {
    Label31->Caption=carr.Sem[n_sem].dar_nombre();
    StringGrid1->Hint=carr.Sem[n_sem].dar_nombre();
    StringGrid1->ShowHint=true;
    for(i=0;i<carr.Sem[n_sem].dar_numerom();i++)
       {
        nombregra=carr.Sem[n_sem].mat[i].identidad.dar_nom();
        for(j=0;j<carr.Sem[n_sem].mat[i].dar_grupos();j++)
           {
            t=carr.Sem[n_sem].mat[i].gru[j].identidad.dar_nom();
            for(k=0;k<carr.Sem[n_sem].mat[i].gru[j].n_secc();k++)
               {
                op=carr.Sem[n_sem].mat[i].gru[j].secc[k].time;
                t1.Hora=op.Hora-ini.Hora;
                t1.Dia=op.Dia-ini.Dia;
                x=t1.Dia.ToInt()+1;
                y=t1.Hora.ToInt()+1;
                if(x<StringGrid1->ColCount&&y<StringGrid1->RowCount)
                  {
                   if(carr.Sem[n_sem].mat[i].gru[j].dar_ests()>0)
                     {
                      StringGrid1->Cells[x][y]=nombregra;
                      cod_gri[x][y]=carr.Sem[n_sem].mat[i].identidad.dar_cod();
                      cod_gri_gru[x][y]=carr.Sem[n_sem].mat[i].gru[j].identidad.dar_cod();
                      ho[x][y]=k;
                     }
                  }
                  else
                      {
                       f=nombregra+ ": " + t +" fuera de rango";
                       ShowMessage(f);
                      }
                if(x<StringGrid1->ColCount&&(y+1)<StringGrid1->RowCount)
                  {
                   StringGrid1->Cells[x][y+1]=t;
                  }
               }
           }
       }
   }
 return;
}

//--------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
 /*Funcion al hacer click en horario*/


 /////////////////Fucion para revisar toda//////////////////////////////////

 int i,j,k,l,q,w;
 String as;
 if(n_sem<0)ShowMessage("ERROR SEMESTRE NO ENCONTRADO");
 else{
      exito=Gui_Cons_Sem(n_sem,carr);
      if(exito!=0)ShowMessage("ERROR SEMESTRE NO ENCONTRADO");
      else{
           Label31->Caption=carr.Sem[n_sem].dar_nombre();
           i=carr.Sem[n_sem].ind_mat(cod_gri[StringGrid1->Col][StringGrid1->Row].c_str());
           if(i!=-1)
             {
              Label77->Caption=carr.Sem[n_sem].mat[i].identidad.dar_nom();
              j=carr.Sem[n_sem].mat[i].ind_gru(cod_gri_gru[StringGrid1->Col][StringGrid1->Row].c_str());
              if(j!=-1)
                {
                 ListBox1->Clear();
                 for(q=0;q<carr.Sem[n_sem].mat[i].gru[j].dar_ests();q++)
                    {
                     as=carr.Sem[n_sem].mat[i].gru[j].dar_est(q);
                     w=carr.ind_est(as.c_str());
                     ListBox1->Items->Add(carr.est[w].identidad.dar_nom());
                    }
                 Label78->Caption=carr.Sem[n_sem].mat[i].gru[j].identidad.dar_nom();
                 k=carr.ind_prof(carr.Sem[n_sem].mat[i].gru[j].anu_profe());
                 if(k!=-1)Label79->Caption=carr.profe[k].identidad.dar_nom();
/*Ojo*/                 as=carr.Sem[n_sem].mat[i].gru[j].secc[ho[StringGrid1->Col][StringGrid1->Row]].dar_salon();
                 l=carr.ind_sal(as.c_str());
                 if(l!=-1)
                   {
                    Label80->Caption=carr.sal[l].identidad.dar_nom();
                   }
                }
             }
          }
     }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox29Change(TObject *Sender)
{
 /*Funcion encargada de colocar los dias de inicio de jornada*/
 int i,n;
 TCita op;
 op.Hora=hr00;
 op.Dia=dDomingo;
 ComboBox29->Items->Clear();
 n=7;
 for(i=0;i<n;i++,op.Dia++)
    {
     ComboBox29->Items->Add(op.Dia.to_str());
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox31Change(TObject *Sender)
{
 /*Funcion encargada de colocar los dias de final de jornada*/
 int i,n;
 TCita op;
 op.Hora=hr00;
 op.Dia=dDomingo;
 ComboBox31->Items->Clear();
 n=7;
 for(i=0;i<n;i++,op.Dia++)
    {
     ComboBox31->Items->Add(op.Dia.to_str());
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox30Change(TObject *Sender)
{
 /*Funcion encargada de colocar las horas de inicio de jornada*/
 int i,n;
 TCita op;
 op.Hora=hr00;
 op.Dia=dDomingo;
 ComboBox30->Items->Clear();
 n=24;
 for(i=0;i<n;i++,op.Hora++)
    {
     ComboBox30->Items->Add(op.Hora.to_str());
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox32Change(TObject *Sender)
{
 /*Funcion encargada de colocar las horas de final de jornada*/
 int i,n;
 TCita op;
 op.Hora=hr00;
 op.Dia=dDomingo;
 ComboBox32->Items->Clear();
 n=24;
 for(i=0;i<n;i++,op.Hora++)
    {
     ComboBox32->Items->Add(op.Hora.to_str());
    }
}
//---------------------------------------------------------------------------


/////////////////////////////FUNCIONES//////////////////////////////////////////

void __fastcall TForm1::Centrar(TPanel *Panel)
{
 Panel->Left=(Form1->Width-Panel->Width)/2;
 Panel->Top=(Form1->Height-Panel->Height)/2;
 Panel->Visible=true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Vent_Par(char* opc)
{
 /*Funcion ventana particular*/
 int i,j;
 char tem[][15]={{"SEMESTRE"},{"MATERIA"},{"SALON"},{"PROFESOR"},{"ESTUDIANTE"},
                {"GRUPO"}};
 for(i=0;i<6;i++)
    {/*RUTINA PARA CAMBIAR A VALOR NUMERICO LA OPCION DE ADICION*/
     j=strcmp(tem[i],opc);
     if(j==0)break;
    }
 switch(estado)
       {
        case 0:/*Adiccionar*/
        switch(i)
              {
               case 0:/*SEMESTRE*/
                      Centrar(Panel8);
                      ADD_CURSO->Visible=false;
                      Panel4->Visible=false;
                      Panel12->Visible=false;
                      ADD_ESTUDIANTE->Visible=false;
                      /*Ingreso de parametros*/
                      ComboBox21->Text=Edit2->Text;
                      Edit2->Clear();
                      ComboBox21->Enabled=false;
               break;
               case 1:/*MATERIA*/
                      Panel8->Visible=false;
                      Centrar(ADD_CURSO);
                      Panel4->Visible=false;
                      Panel12->Visible=false;
                      ADD_ESTUDIANTE->Visible=false;
                      /*Ingreso de parametros*/
                      ComboBox19->Text=Edit2->Text;
                      ComboBox18->Text="";
                      ComboBox20->Text="";
                      Edit2->Clear();
                      ComboBox19->Enabled=false;
               break;
               case 2:/*SALON*/
                      Panel8->Visible=false;
                      Centrar(Panel4);
                      ADD_CURSO->Visible=false;
                      Panel12->Visible=false;
                      ADD_ESTUDIANTE->Visible=false;
                      /*Ingreso de parametros*/
                      ComboBox8->Text=Edit2->Text;
                      Edit2->Clear();
                      ComboBox8->Enabled=false;
               break;
               case 3:/*PROFESOR*/
                      Panel8->Visible=false;
                      Centrar(Panel12);
                      Panel4->Visible=false;
                      ADD_CURSO->Visible=false;
                      ADD_ESTUDIANTE->Visible=false;
                      /*Ingreso de parametros*/
                      ComboBox10->Text=Edit2->Text;
                      Edit2->Clear();
                      ComboBox10->Enabled=false;
               break;
               case 4:/*ESTUDIANTE*/
                      Panel8->Visible=false;
                      Centrar(ADD_ESTUDIANTE);
                      ComboBox23->Text=Edit2->Text;
                      Panel4->Visible=false;
                      ADD_CURSO->Visible=false;
                      Panel12->Visible=false;
                      /*Ingreso de parametros*/
                      ComboBox23->Text=Edit2->Text;
                      Edit2->Clear();
                      ComboBox23->Enabled=false;
               break;
               case 5:/*GRUPO*/
                      Centrar(Panel9);
                      ComboBox17->Text=Edit2->Text;
                      Edit2->Clear();
                      ComboBox17->Enabled=false;
               break;
               default:/*MUESTRA MENSAJE DE ERROR*/
                       ShowMessage("LA OPCION NO ES VALIDA");
               break;
              }
        break;
       }
 return;
}

/******************************************************************************/

void __fastcall TForm1::Habilitar(int usuario)
{
 /*Funcion habilitar*/
 switch(usuario)
       {
        case 0://Director
               GUARDAR1->Enabled=false;
               GUARDARCOMO1->Enabled=true;
               SpeedButton29->Enabled=true;
               IMPRIMIR1->Enabled=true;
               SpeedButton28->Enabled=true;
               ACTUALIZARHORARIO1->Enabled=true;
               SpeedButton26->Enabled=true;
               ADICIONAR1->Enabled=true;
               SpeedButton25->Enabled=true;
               MOVER1->Enabled=true;
               SpeedButton24->Enabled=true;
               ELIMINAR1->Enabled=true;
               SpeedButton23->Enabled=true;
               OPCIONES1->Enabled=true;
               SpeedButton21->Enabled=true;
               RESTRICCIONPROFESOR1->Enabled=true;
               SpeedButton2->Enabled=true;
               REGISTRARMATERIA1->Enabled=true;
               SpeedButton3->Enabled=true;
               StringGrid1->PopupMenu=PopupMenu1;
               ListBox1->Visible=true;
               RANGOHORARIO1->Enabled=true;
               /*Configuracion por defecto de las opciones del Ag*/
               Edit8->Text="100";
               Edit25->Text="10";
               Edit26->Text="50";
               Edit27->Text="50";
               Edit30->Text="50";
        break;
        case 1://Profesor
               GUARDAR1->Enabled=true;
               SpeedButton29->Enabled=true;
               GUARDARCOMO1->Enabled=false;
               IMPRIMIR1->Enabled=true;
               SpeedButton28->Enabled=true;
               ACTUALIZARHORARIO1->Enabled=false;
               SpeedButton26->Enabled=false;
               ADICIONAR1->Enabled=false;
               SpeedButton25->Enabled=false;
               MOVER1->Enabled=false;
               SpeedButton24->Enabled=false;
               ELIMINAR1->Enabled=false;
               SpeedButton23->Enabled=false;
               RUN2->Enabled=false;
               SpeedButton22->Enabled=false;
               OPCIONES1->Enabled=false;
               SpeedButton21->Enabled=false;
               RESTRICCIONPROFESOR1->Enabled=false;
               SpeedButton2->Enabled=false;
               REGISTRARMATERIA1->Enabled=false;
               SpeedButton3->Enabled=false;
               StringGrid1->PopupMenu=PopupMenu3;
               ListBox1->Visible=false;
               RANGOHORARIO1->Enabled=false;
        break;
        case 2://Estudiante
               GUARDAR1->Enabled=true;
               SpeedButton29->Enabled=true;
               GUARDARCOMO1->Enabled=false;
               IMPRIMIR1->Enabled=true;
               SpeedButton28->Enabled=true;
               ACTUALIZARHORARIO1->Enabled=false;
               SpeedButton26->Enabled=false;
               ADICIONAR1->Enabled=false;
               SpeedButton25->Enabled=false;
               MOVER1->Enabled=false;
               SpeedButton24->Enabled=false;
               ELIMINAR1->Enabled=false;
               SpeedButton23->Enabled=false;
               RUN2->Enabled=false;
               SpeedButton22->Enabled=false;
               OPCIONES1->Enabled=false;
               SpeedButton21->Enabled=false;
               RESTRICCIONPROFESOR1->Enabled=false;
               SpeedButton21->Enabled=false;
               REGISTRARMATERIA1->Enabled=true;
               SpeedButton3->Enabled=true;
               StringGrid1->PopupMenu=PopupMenu2;
               ListBox1->Visible=false;
               RANGOHORARIO1->Enabled=false;
        break;
        default:
                ShowMessage("Acceso no valido");
        break;
       }
  return;
}

//--------------------------------------------------------------------------

/////////////////BOTONES BARRA DE MENU//////////////////////////////////////////

void __fastcall TForm1::NUEVOHORARIO1Click(TObject *Sender)
{
 /*Boton NUEVO HORARIO*/
 usuario=0;//Se indica que el usuario es el director
 Centrar(Panel11);
 Edit31->Clear();
 Edit32->Clear();
 Edit20->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GESTIONDEUSUARIO1Click(TObject *Sender)
{
 /*Boton ABRIR*/
 archivo=0;
 if(OpenDialog1->Execute())
   {
    usuario=2;
    Gui_abrir_horario(carr,OpenDialog1->FileName.c_str());
    Label83->Caption=carr.decir_nombre();
    Label83->Visible=true;
    GUARDAR1->Enabled=true;
    SpeedButton27->Enabled=true;
    USUARIO1->Enabled=true;
    Centrar(IDENTIFICACION);
    Graf_Sem();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GUARDAR1Click(TObject *Sender)
{
 /*Boton GUARDAR*/
 Gui_guardar_horario(carr,SaveDialog1->FileName.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GUARDARCOMO1Click(TObject *Sender)
{
 /*Boton GUARDAR COMO*/
 if(SaveDialog1->Execute())
   {
    Gui_guardar_horario(carr,SaveDialog1->FileName.c_str());
    GUARDAR1->Enabled=true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IMPRIMIR1Click(TObject *Sender)
{
 /*Boton IMPRIMIR horario*/
 int i;
 String q;
// Imprehora impr;
 //Se ordena imprimir el horario del area de trabajo
 if(PrintDialog1->Execute())
   {
    for(i=0;i<PrintDialog1->Copies;i++)
       {
        //impr.imprimir();
       }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CONFIIMPRIMIR1Click(TObject *Sender)
{
 /*Boton configurar impresion de horario*/
 PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::USUARIO1Click(TObject *Sender)
{
 /*Boton IDENTIFICACION*/
 Centrar(IDENTIFICACION);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ACTUALIZARHORARIO1Click(TObject *Sender)
{
 /*Boton ACTUALIZAR HORARIO*/
 /*CAMBIAR PANELES*/
 Label24->Caption="ACTUALIZAR";
 Label76->Caption="ACTUALIZAR PROFESOR";
 Label22->Caption="ACTUALIZAR ESTUDIANTE";
 Label25->Caption="ACTUALIZAR MATERIA";
 estado=1;
 Edit2->Clear();
 Centrar(ADICIONAR);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ADICIONAR1Click(TObject *Sender)
{
 /*Boton ADICIONAR*/
 /*CAMBIAR PANELES*/
 Label24->Caption="ADICIONAR";
 Label76->Caption="ADICIONAR PROFESOR";
 Label22->Caption="ADICIONAR ESTUDIANTE";
 Label25->Caption="ADICIONAR MATERIA";
 Label37->Caption="ADICIONAR";
 Label62->Caption="ADICIONAR SEMESTRE";
 estado=0;
 Edit2->Clear();
 Centrar(ADICIONAR);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MOVER1Click(TObject *Sender)
{
 /*Boton MOVER*/
 Label24->Caption="MOVER";
 Label76->Caption="MOVER PROFESOR";
 Label22->Caption="MOVER ESTUDIANTE";
 Label25->Caption="MOVER MATERIA";
 Label37->Caption="MOVER";
 Label62->Caption="MOVER SEMESTRE";
 estado=3;
 Edit2->Clear();
 Centrar(ADICIONAR);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ELIMINAR1Click(TObject *Sender)
{
 /*Boton ELIMINAR*/
 /*CAMBIAR PANELES*/
 Label24->Caption="ELIMINAR";
 Label76->Caption="ELIMINAR PROFESOR";
 Label22->Caption="ELIMINAR ESTUDIANTE";
 Label25->Caption="ELIMINAR MATERIA";
 Label37->Caption="ELIMINAR";
 Label62->Caption="ELIMINAR SEMESTRE";
 estado=2;
 Edit2->Clear();
 Centrar(ADICIONAR);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RESTRICCIONPROFESOR1Click(TObject *Sender)
{
 /*Boton RESTRICION PROFESOR*/
 Centrar(Panel15);
 Button38->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::REGISTRARMATERIA1Click(TObject *Sender)
{
 /*Boton REGISTRAR MATERIA*/
 if(usuario==0)//Director
   {
    ComboBox11->Enabled=true;
    Centrar(Panel1);
    return;
   }
 if(usuario==2)//Estudiante
   {
    ComboBox11->Text=codigo_usu;
    Centrar(Panel1);
    ComboBox11->Enabled=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RANGOHORARIO1Click(TObject *Sender)
{
 /*Boton RANGO HORARIO*/
 TCita op;
 Centrar(Panel6);
 op=carr.inicio();
 ComboBox29->Text=op.Dia.to_str();
 ComboBox30->Text=op.Hora.to_str();
 op=carr.final();
 ComboBox31->Text=op.Dia.to_str();
 ComboBox32->Text=op.Dia.to_str();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RUN2Click(TObject *Sender)
{
 /*Boton RUN para correr el algoritmo genetico*/
 /*
 int i,j;
 char textop[][15]={{"SIMPLE"},{"SHARING"},{"CROWDING"}};
 String dir;
 //el sistema ordena iniciar la evolucion del horario
 s=ComboBox1->Text;
 for(i=0;i<=3;i++)
    {
     j=strcmp(s.c_str(),textop[i]);
     if(j==0)break;
    }
 if(SaveDialog3->Execute())
   {
    dir=SaveDialog3->FileName;
    Panel2->Left=(Form1->Width-Panel2->Width)/2;
    Panel2->Top=(Form1->Height-Panel2->Height)/2;
    Panel2->Visible=true;
    evolucion.indicar_pro(ProgressBar1);
    evolucion.gen=ProgressBar2;
    evolucion.graf=PerformanceGraph1;
    evolucion.run(&carr,i,dir.c_str());
    //El sistema termino de evolucionar
    Panel2->Visible=false;
    Graf_Sem();
   }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OPCIONES1Click(TObject *Sender)
{
 /*Boton OPCIONES DE RUN*/
 Centrar(Panel5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ACERCADE1Click(TObject *Sender)
{
 /*boton ACERCA DE*/
 /*Panel que indica el desarrollador del software*/
 Centrar(Panel3);
}
//---------------------------------------------------------------------------


/////////////////////////////BOTONES////////////////////////////////////////////

void __fastcall TForm1::Button34Click(TObject *Sender)
{
 /*Boton aceptar nombre de horario*/
 s=Edit20->Text;
 carr.nombrar(s.c_str());//Guardar el nombre de la carrera
 NUEVOHORARIO1->Enabled=false;//Se deshabilita la opcion de crear un nuevo horario
 Panel11->Visible=false;
 Centrar(Panel7);
 Label83->Caption=carr.decir_nombre();
 Label83->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button35Click(TObject *Sender)
{
 /*Boton cancelar nombre de horario*/
 Panel11->Visible=false;
 Edit20->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
 /*Boton aceptar ingresar director*/
 s=Edit31->Text;
 carr.Dir.identidad.ingre_nom(s.c_str());
 s=Edit32->Text;
 carr.Dir.identidad.ingre_cod(s.c_str());
 acc_dir=1;//Se indica que es un director nuevo
 Centrar(Panel13);
 Panel7->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
 /*Boton cancelar ingresar director*/
 Edit31->Clear();
 Edit32->Clear();
 Centrar(Panel7);
 Panel7->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button36Click(TObject *Sender)
{
 /*Boton aceptar contraseña*/
 String conf;/*Variable de confirmacion de clave*/
 int i;
 switch(acc_dir)
       {
        case 0://Director existente y verificando clave
               s=Edit9->Text;
               i=carr.Dir.verificar(s.c_str());
               if(i==0)
                 {
                  Habilitar(0);
                 }/*HABILITA LOS PERMISOS DEL CASO Y CIERRA LA VENTANA.*/
                 /*SI LA CLAVE DEL DIRECTOR NO COINCIDE*/
                 else{
                      /*EL SISTEMA MUESTRA EL MENSAJE DE ERROR*/
                      ShowMessage("LA CONTRASEÑA NO COINCIDE EL SISTEMA SE CERRARA");
                      Close();
                      exit(1);/*CIERRA LA APLICACIÓN.*/
                     }
        break;
        case 1://nuevo director ingresando clave por primera vez
               s=Edit9->Text;
               conf=Edit3->Text;
               if(strcmp(s.c_str(),conf.c_str())!=0)
                 {
                  ShowMessage("La contraseña no coincide");
                  break;
                 }
                 carr.Dir.clavear(s.c_str());
                 Habilitar(0);
                 acc_dir=0;//Se indica que el director ya existe
                 SpeedButton27->Enabled=true;
                 USUARIO1->Enabled=true;
        break;
        default://Posible director ingresando clave porcion de codigo a revisar
                ShowMessage("Opcion no validad");
        break;
       }
 Panel13->Visible=false;
 Edit9->Clear();
 Edit3->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button37Click(TObject *Sender)
{
 /*Boton cancelar contraseña*/
 Edit9->Clear();
 Panel13->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 /*Boton Aceptar de identificacion*/
 char opc[24];
 int i,j;
 /*EL USUARIO ESCOGE EL TIPO DE ACTOR AL QUE PERTENECE E INGRESA UN CÓDIGO
 (OTORGADO POR LA UNIVERSIDAD) Y PRESIONA ACEPTAR.*/
 IDENTIFICACION->Visible=false;/*EL SISTEMA CIERRA LA VENTANA DE IDENTIFICACIÓN*/
 strcpy(codigo,Edit1->Text.c_str());
 strcpy(codigo_usu,codigo);
 s=USUARIO->Text;
 strcpy(opc,s.c_str());
 char tem[][12]={{"DIRECTOR"},{"PROFESOR"},{"ESTUDIANTE"}};
 for(i=0;i<3;i++)
    {/*RUTINA PARA CAMBIAR A VALOR NUMERICO LA OPCION DE
     IDENTIFICACION*/
     j=strcmp(tem[i],opc);
     if(j==0)break;
    }
 usuario=i;
 exito=Gui_Cons_Usu(usuario,codigo,&carr);/*CONSULTA LA EXISTENCIA DEL USUARIO.*/
 if(exito!=0)
   {/*SI LA BÚSQUEDA DEL ACTOR FALLA EL SISTEMA.*/
    /*MUESTRA EL MENSAJE DE ERROR.*/
    ShowMessage("ERROR EL USUARIO NO ES ENCONTRADO");
    /*EL USUARIO PRESIONA ACEPTAR Y EL SISTEMA CIERRA EL MENSAJE Y
    ABRE LA VENTANA ADICCIONAR .*/
    ADICIONAR->Left=(Form1->Width-ADICIONAR->Width)/2;
    ADICIONAR->Top=(Form1->Height-ADICIONAR->Height)/2;
    ADICIONAR->Visible=true;
    return;
   }
 /*SI ES EL DIRECTOR ABRE LA VENTANA DE SEGURIDAD.*/
 if(usuario==0)
   {
    Panel13->Left=(Form1->Width-Panel13->Width)/2;
    Panel13->Top=(Form1->Height-Panel13->Height)/2;
    Panel13->Visible=true;
    acc_dir=0;
    Edit1->Clear();
   }
   else{
        Habilitar(usuario);/*HABILITA LOS PERMISOS DEL CASO Y CIERRA LA
        VENTANA.*/
        Edit1->Clear();
       }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
 /*Boton cancelar rango horario*/
 ComboBox29->Text="DIA:";
 ComboBox31->Text="DIA:";
 ComboBox30->Text="HORA:";
 ComboBox32->Text="HORA:";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 /*Boton aceptar rango horario.*/
 TCita ini,fin;

///////////////////////////////////ojo////////////////////////////////////////


/* ini.Dia<<ComboBox29->Text.c_str();
 ini.Hora<<ComboBox30->Text.c_str();
 fin.Dia<<ComboBox31->Text.c_str();
 fin.Hora<<ComboBox32->Text.c_str();*/
 if(fin<ini)permutar(ini,fin);
 carr.inicio(ini);
 carr.final(fin);
 ComboBox29->Text="DIA:";
 ComboBox31->Text="DIA:";
 ComboBox30->Text="HORA:";
 ComboBox32->Text="HORA:";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
{
 /*Boton cancelar de acerca de*/
 /*Se Cierra el mensaje del desarrollador*/
 Panel3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 /*Boton cancelar de adicionar estudiante*/
 /*SI EL USUARIO PRESIONA CANCELAR EL SISTEMA IGNORA LOS DATOS.*/
 ComboBox22->Text="";
 ComboBox23->Text="";
 ADD_ESTUDIANTE->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 /*Boton cancelar adicionar materia*/
 /*SI EL USUARIO PRESIONA CANCELAR EL SISTEMA IGNORA LOS DATOS.*/
 ComboBox19->Text="";
 ComboBox18->Text="";
 ComboBox15->Text="";
 ComboBox16->Text="";
 ComboBox17->Text="";
 ComboBox20->Text="";
 Edit19->Clear();
 ADD_CURSO->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 /*Boton cancelar adicionar*/
 /*SI EL DIRECTOR PRESIONA CANCELAR EL SISTEMA IGNORA LOS DATOS.*/
 Edit2->Clear();
 ADICIONAR->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 /*Boton cancelar identificacion*/
 /*SI EL USUARIO PRESIONA CANCELAR EL SISTEMA IGNORA LOS DATOS.*/
 Edit1->Clear();
 IDENTIFICACION->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
 /*Boton cancelar adiccionar profesor*/
 /*SI EL USUARIO PRESIONA CANCELAR EL SISTEMA IGNORA LOS DATOS.*/
 ComboBox9->Text="";
 ComboBox10->Text="";
 Panel12->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button15Click(TObject *Sender)
{
 /*Boton siguiente semestre en panel de tareas*/
 /*Se visualiza el semestre siguiente*/
 n_sem++;
 if(n_sem<carr.dar_numero())
   {
    exito=Gui_Cons_Sem(n_sem,carr);
   }
   else{
        exito=1;
       }

 if(exito!=0)
   {
    ShowMessage("ERROR SEMESTRE NO ENCONTRADO");
    n_sem--;
   }
 else Graf_Sem();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
 /*Boton semestre anterior en panel de tareas*/
 /*Se visualiza el semestre anterior*/
 n_sem--;
 if(n_sem<0)
   {
    ShowMessage("ERROR SEMESTRE NO ENCONTRADO");
    n_sem=0;
   }
   else{
        exito=Gui_Cons_Sem(n_sem,carr);
        if(exito!=0)ShowMessage("ERROR SEMESTRE NO ENCONTRADO");
        else Graf_Sem();
       }
 }
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
 /*Boton aceptar adicionar*/
 int i,j;
 char opcion[][15]={{"SEMESTRE"},{"MATERIA"},{"SALON"},{"PROFESOR"},{"ESTUDIANTE"},{"GRUPO"}};
 s=ADICION->Text;
 for(i=0;i<=6;i++)
    { /*DETERMINACION DE LA OPCION TOMADA*/
     j=strcmp(s.c_str(),opcion[i]);
     if(j==0)break;
    }
 s=Edit2->Text;
 strcpy(codigo,s.c_str());/*LECTURA DEL CODIGO*/
 exito=Gui_Cons_Cod(i,codigo,&carr);/*EL SISTEMA VERIFICA LA EXISTENCIA DEL
                                   CÓDIGO*/
 switch(estado)
       {
        case 0:/*ADICIONAR*/
               /*EL USUARIO ESCOGE EL ELEMENTO A ADICIONAR E INGRESA EL
               CÓDIGO (OTORGADO POR LA UNIVERSIDAD) Y PRESIONA ACEPTAR*/
               if(exito==0)
                 {/*SI EL CÓDIGO EXISTE*/
                  /*SE DESPLIEGA UN MENSAJE INDICANDO QUE EL
                  ELEMENTO YA EXISTE.*/
                  ShowMessage("EL ELEMENTO A ADICCIONAR YA EXISTE");
                  /*EL DIRECTOR PRESIONA ACEPTAR, EL MENSAJE SE
                  CIERRA.*/
                 }
                 else{/*SI EL CODIGO NO EXISTE*/
                      s=ADICION->Text;;
                      Vent_Par(s.c_str());/*ABRE LA VENTANA PARTICULAR*/
                     }
               break;
               case 1:/*ACTUALIZAR*/
                      /*EL DIRECTOR INGRESA EL CÓDIGO DEL ELEMENTO A ACTUALIZAR
                      Y PRESIONA ACEPTAR.*/
                      if(exito==0)
                        {/*SI EL CÓDIGO EXISTE*/
                         s=ADICION->Text;
                         Vent_Par(s.c_str());/*ABRE LA VENTANA PARTICULAR*/
                        }
                      else{/*SI LA BÚSQUEDA DEL ELEMENTO FALLA*/
                           /*EL SISTEMA MUESTRA EL MENSAJE DE ERROR.*/
                           ShowMessage("EL ELEMENTO A ACTUALIZAR NO EXISTE");
                          }
               break;
               case 2:/*ELIMINAR*/
                      /*EL DIRECTOR INGRESA EL CÓDIGO DEL ELEMENTO A ELIMINAR
                      Y PRESIONA ACEPTAR.*/
                      if(exito==0)
                        {/*SI EL CÓDIGO EXISTE*/
                         /*ABRE LA VENTANA PARTICULAR*/
                         s=ADICION->Text;
                         Vent_Par(s.c_str());/*ABRE LA VENTANA PARTICULAR*/
                        }
                      else{
                           ShowMessage("EL ELEMENTO A ELIMINAR NO EXISTE");
                          }
               break;
               case 3:/*MOVER*/
                      /*EL DIRECTOR INGRESA EL CÓDIGO DEL ELEMENTO A MOVER
                      Y PRESIONA ACEPTAR.*/
                      if(exito==0)
                        {/*SI EL CÓDIGO EXISTE*/
                         /*ABRE LA VENTANA PARTICULAR*/
                         s=ADICION->Text;
                         Vent_Par(s.c_str());/*ABRE LA VENTANA PARTICULAR*/
                        }
                        else{
                             ShowMessage("EL ELEMENTO A MOVER NO EXISTE");
                            }
               break;
               default:
                       ShowMessage("OPCION NO VALIDA");
               break;
              }
 ADICIONAR->Visible=false;/*CIERRA LA VENTANA*/
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Button9Click(TObject *Sender)
{
 /*Boton aceptar agregar profesor*/
 int i,j;
 switch(estado)
       {
        case 0:/*Adiccionar profesor*/
               ComboBox10->Enabled=false;
               s=ComboBox10->Text;
               strcpy(codigo,s.c_str());
               s=ComboBox9->Text;
               strcpy(nombre,s.c_str());
               carr.add_profe(nombre,codigo);
               i=carr.ind_prof(codigo);
               j=Edit46->Text.ToInt();
               carr.profe[i].capacitar(j);
               Panel12->Visible=false;
               ComboBox10->Text="";
               ComboBox9->Text="";
               Edit46->Text=0;
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
        default:
        break;
       }
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------


void __fastcall TForm1::Button24Click(TObject *Sender)
{
 /*
 String nombre,tipo;
 switch(archivo){
                 case 0:
                        Gui_abrir_horario(&carr,nombre.c_str());
                        Label83->Caption=carr.decir_nombre();
                        Label83->Visible=true;
                 break;
                 case 1:
                        Gui_guardar_horario(&carr,nombre.c_str());
                 break;
                 default:
                        ShowMessage("OPCION NO VALIDA");
                 break;
                }
 GUARDAR1->Enabled=true;
 SpeedButton27->Enabled=true;
 USUARIO1->Enabled=true;*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
 /*Boton aceptar opciones de evolucion*/
 /*Se ingresan los parametros del algoritmo genetico*/
 /*Numero de generaciones*/
 s=Edit8->Text;
 evolucion.indicar_n_gen(s.ToInt());
 /*Numero de individuos*/
 s=Edit25->Text;
 evolucion.indicar_n_ind(s.ToInt());
 /*Probabilidad de cruce*/
 s=Edit26->Text;
 evolucion.indicar_pc(s.ToInt());
 /*Probabilidad de mutacion*/
 s=Edit27->Text;
 evolucion.indicar_pm(s.ToInt());
 /*Longitud de Crowding*/
 s=Edit30->Text;
 evolucion.indicar_lc(s.ToInt());
 Panel5->Visible=false;
 RUN2->Enabled=true;
 SpeedButton22->Enabled=true;
}

//---------------------------------------------------------------------------




void __fastcall TForm1::DIRECTOR1Click(TObject *Sender)
{
 /*
 usuario=0;//Se indica que el usuario es el director
 */
}

//---------------------------------------------------------------------------

void __fastcall TForm1::PROFESOR1Click(TObject *Sender)
{
 /*
 usuario=1;//Se indica que el usuario es un profesor
 */
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ESTUDIANTE1Click(TObject *Sender)
{
 /*
 usuario=2;//Se indica que el usuario es un estudiante
 */
}

//---------------------------------------------------------------------------



void __fastcall TForm1::Button19Click(TObject *Sender)
{
 /*ComboBox11->Clear();
 Panel2->Visible=false;*/
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
 /*Boton cancelar adicionar materia*/
 ComboBox11->Text="";
 ComboBox12->Text="";
 ComboBox13->Text="";
 Panel1->Left=(Form1->Width-Panel1->Width)/2;
 Panel1->Top=(Form1->Height-Panel1->Height)/2;
 Panel1->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
 /*Boton cancelar opciones de evolucion*/
 Edit8->Clear();
 Edit26->Clear();
 Edit25->Clear();
 Edit27->Clear();
 Edit30->Clear();
 Panel5->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
 /*Boton cancelar adicionar salon*/
 Panel4->Visible=false;
 ComboBox6->Text="";
 ComboBox8->Text="";
 Edit17->Text=0;
 Edit34->Text=0;
 Edit29->Text=0;
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button29Click(TObject *Sender)
{
 /*Boton canelar adicionar semestre*/
 /*EL SISTEMA IGNORA LOS DATOS*/
 Panel8->Visible=false;
 ComboBox21->Text="";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
 /*Boton aceptar adicionar semestre*/
 /*1 actualizar, 2 eliminar, 3 mover.*/
 switch(estado)
       {
        case 0:/*Adiccionar*/
               s=ComboBox21->Text;
               carr.add_sem(s.c_str());
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
       }
 ComboBox21->Enabled=true;
 Panel8->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
 /*Boton acetar adicionar salon*/
 int i;
 float x,y,z;
 switch(estado)
       {
        case 0:/*Adiccionar*/
               s=ComboBox6->Text;
               strcpy(nombre,s.c_str());
               s=ComboBox8->Text;
               strcpy(codigo,s.c_str());
               carr.add_sal(nombre,codigo);
               i=carr.ind_sal(codigo);
               x=(float)Edit17->Text.ToInt();
               y=(float)Edit34->Text.ToInt();
               z=(float)Edit29->Text.ToInt();
               carr.sal[i].posicionar(x,y,z);
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
       }
 Panel4->Visible=false;
 ComboBox6->Text="";
 ComboBox8->Text="";
 Edit17->Text=0;
 Edit34->Text=0;
 Edit29->Text=0;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 /*Boton aceptar adicionar estudiante*/
 switch(estado)
       {
        case 0:/*Adiccionar*/
               s=ComboBox22->Text;
               strcpy(nombre,s.c_str());
               s=ComboBox23->Text;
               strcpy(codigo,s.c_str());
               carr.add_est(nombre,codigo);
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
       }
 ComboBox22->Text="";
 ADD_ESTUDIANTE->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
 /*Boton aceptar registrar materia*/
 /*EL ESTUDIANTE O DIRECTOR INGRESA EL CÓDIGO DE LA MATERIA A REGISTRAR, Y
 PRESIONA ACEPTAR*/
 /*EL SISTEMA VERIFICA LA EXISTENCIA Y VALIDES DEL CÓDIGO*/
 char ce[20],cm[20],cg[20];
 int i,j,k,l,g;
 s=ComboBox11->Text;
 strcpy(ce,s.c_str());//Codigo del estudiante
 s=ComboBox12->Text;
 strcpy(cm,s.c_str());//Codigo de materia
 s=ComboBox13->Text;
 strcpy(cg,s.c_str());//Codigio del grupo
 l=carr.ind_est(ce);
 if(l==-1)
   {
    ShowMessage("EL ESTUDIANTE NO EXISTE");
    return;
   }
 exito=Gui_Cons_Reg(&carr,cm,cg);
 switch(exito){
               case 0:
                      i=carr.sem_mat(cm);
                      j=carr.Sem[i].ind_mat(cm);
                      k=carr.Sem[i].mat[j].ind_gru(cg);
                      g=carr.Sem[i].mat[j].gru[k].ind_est(ce);
                      if(g==-1)
                        {
                         carr.Sem[i].mat[j].gru[k].add_estu(ce);
                         carr.est[l].add_gru(cg,cm);
                         g=carr.est[l].ind_gru(cg);
                         carr.est[l].ingre_sem(carr.Sem[i].dar_nombre(),g);
                        }
                      Panel1->Visible=false;/*CIERRA LA VENTANA REGISTRAR.*/
               break;
               case 1:/**/
                      ShowMessage("");/* EL USUARIO
                      PRESIONA ACEPTAR Y EL SISTEMA CIERRA EL MENSAJE.*/
               break;
               case 2:/*SI LA MATERIA NO ES VALIDA MUESTRA UN
                      MENSAJE DE MATERIA NO EXISTENTE.*/
                      ShowMessage("ERROR LA MATERIA NO EXISTE");
               break;
               case 3:/* SI LA MATERIAS TIENEN EL CUPO LLENO
                      NUESTRA UN MENSAJE DE REGISTRO NO VALIDO*/
                      ShowMessage("REGISTRO NO VALIDO, CUPO LLENO");/*EL USUARIO
                      PRESIONA ACEPTAR SISTEMA CIERRA EL MENSAJE.*/
               break;
               default:
                       ShowMessage("ERROR");
               break;
              }
 ComboBox11->Text="";
 ComboBox12->Text="";
 ComboBox13->Text="";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 /*Boton aceptar adicionar materia*/
 int i;
 switch(estado)
       {
        case 0://Adicionar
               s=ComboBox18->Text;
               strcpy(nombre,s.c_str());
               s=ComboBox19->Text;
               strcpy(codigo,s.c_str());
               s=ComboBox20->Text;
               i=carr.ind_seme(s.c_str());
               if(i==-1)
                 {
                  ShowMessage("SEMESTRE INEXISTENTE");
                  return;
                 }
               else{
                    carr.Sem[i].add_materia(nombre,codigo);
                    ADD_CURSO->Visible=false;
                   }
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
       }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender)
{
 /*Boton cancelar adicionar grupo*/
 ComboBox16->Text="";
 ComboBox15->Text="";
 ComboBox17->Text="";
 Edit19->Clear();
 ComboBox14->Text="";
 Panel9->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
 /*Boton cancelar adicionar seccion*/
 ComboBox27->Text="";
 Edit37->Clear();
 Panel10->Visible=false;
 Panel9->Left=(Form1->Width-Panel9->Width)/2;
 Panel9->Top=(Form1->Height-Panel9->Height)/2;
 Panel9->Visible=true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
 /*Boton aceptar adicionar grupo*/
 int i,j,k,l,g;
 switch(estado)
       {
        case 0:/*Adicionar*/
               s=ComboBox14->Text;
               i=carr.sem_mat(s.c_str());
               if(i==-1)ShowMessage("ERROR");
                 else{
                      s=ComboBox16->Text;
                      strcpy(nombre,s.c_str());
                      s=ComboBox17->Text;
                      strcpy(codigo,s.c_str());
                      s=ComboBox14->Text;
                      j=carr.Sem[i].ind_mat(s.c_str());
                      if(j==-1)
                        {
                         ShowMessage("ERROR");
                         return;
                        }
                      k=carr.Sem[i].mat[j].ind_gru(codigo);
                      if(k!=-1)
                        {
                         ShowMessage("EL CURSO YA EXISTE");
                         return;
                        }
                      carr.Sem[i].mat[j].add_gru(nombre,codigo);
                      k=carr.Sem[i].mat[j].ind_gru(codigo);
                      s=ComboBox15->Text;
                      l=carr.ind_prof(s.c_str());
                      if(l!=-1)
                        {
                         carr.Sem[i].mat[j].gru[k].ing_profe(s.c_str());
                         s=ComboBox14->Text;
                         carr.profe[l].add_gru(ComboBox17->Text.c_str(),s.c_str());
                         g=carr.profe[l].ind_gru(ComboBox17->Text.c_str());
                         carr.profe[l].ingre_sem(carr.Sem[carr.sem_mat(s.c_str())].dar_nombre(),g);
                        }
                      l=Edit19->Text.ToInt();
                      carr.Sem[i].mat[j].gru[k].n_secciones(l);
                      l=Edit37->Text.ToInt();
                      carr.Sem[i].mat[j].gru[k].ingre_capa(l);
                      if(CheckBox2->Checked==true)
                        {
                         Panel9->Visible=false;
                         ComboBox25->Text=carr.Sem[i].mat[j].dar_cod();
                         ComboBox26->Text=ComboBox17->Text;
                         Panel10->Left=(Form1->Width-Panel10->Width)/2;
                         Panel10->Top=(Form1->Height-Panel10->Height)/2;
                         Panel10->Visible=true;
                         ComboBox28->Text=1;
                        }
                      ComboBox16->Text="";
                      ComboBox15->Text="PROFE";
                      Edit37->Clear();
                      ComboBox17->Text="";
                      Edit19->Clear();
                     }
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
        }
 Panel9->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
 /*Boton aceptar adicionar seccion*/
 int i,j,k,ii,jj,kk;
 Tiempo tem;
 switch(estado)
       {
        case 0:/*Adiccionar*/
               s=ComboBox25->Text;
               i=carr.sem_mat(s.c_str());
               j=carr.Sem[i].ind_mat(s.c_str());
               s=ComboBox26->Text;
               k=carr.Sem[i].mat[j].ind_gru(s.c_str());
               s=ComboBox4->Text;
               for(ii=0;ii<=5;ii++)
                  {
                   jj=strcmp(s.c_str(),text[ii]);
                   if(jj==0)break;
                  }
               s=ComboBox7->Text;
               for(jj=0;jj<=11;jj++)
                  {
                   kk=strcmp(s.c_str(),text1[jj]);
                   if(kk==0)break;
                  }
               tem.hora=jj;
               tem.dia=ii;
               if(CheckBox1->Checked==true)tem.bandera=1;
               else tem.bandera=0;
               carr.Sem[i].mat[j].gru[k].act_class(tem,(ComboBox28->Text.ToInt()-1));
               s=ComboBox27->Text;
               jj=carr.ind_sal(s.c_str());
               if(jj==-1)
                 {
                  ShowMessage("SALON INEXISTENTE");
                 }
                 else{
                      kk=ComboBox28->Text.ToInt();
                      carr.Sem[i].mat[j].gru[k].ingre_sal(s.c_str(),kk);
                     }
        break;
        case 1://Actualizar
        break;
        case 2://Eliminar
        break;
        case 3://Mover
        break;
       }
 ComboBox27->Text="";
 CheckBox1->Checked=false;
 ComboBox28->Text=ComboBox28->Text.ToInt()+1;
 if(ComboBox28->Text.ToInt()>carr.Sem[i].mat[j].gru[k].n_secc())
   {
    Panel10->Visible=false;
   }
}

//---------------------------------------------------------------------------








void __fastcall TForm1::Button38Click(TObject *Sender)
{
 /*Boton aceptar retriccion para profesor*/
 int i,j,k,ii,jj,kk;
 Tiempo tem;
 s=ComboBox2->Text;
 i=carr.ind_prof(s.c_str());
 if(i==-1)
   {
    ShowMessage("ERROR. EL PROFESOR NO EXISTE");
    return;
   }
 s=ComboBox3->Text;
 for(ii=0;ii<=5;ii++)
    {
     jj=strcmp(s.c_str(),text[ii]);
     if(jj==0)break;
    }
 if(ii>5)
   {
    ShowMessage("ERROR. EL DIA NO ES VALIDO");
    return;
   }
 s=ComboBox5->Text;
 for(jj=0;jj<=11;jj++)
    {
     kk=strcmp(s.c_str(),text1[jj]);
     if(kk==0)break;
    }
 if(jj>11)
   {
    ShowMessage("ERROR. LA HORA NO ES VALIDA");
    return;
   }
 tem.hora=jj;
 tem.dia=ii;
 tem.bandera=0;
 if((Edit45->Text.ToInt())==carr.profe[i].dar_restriciones())
   {
    carr.profe[i].add_restri(tem);
   }
 ComboBox2->Enabled=true;
 ComboBox27->Text="";
 Edit45->Text=Edit45->Text.ToInt()+1;
 ComboBox3->Text="DIA:";
 ComboBox5->Text="HORA:";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button39Click(TObject *Sender)
{
 /*Boton cancelar restricion para el profesor*/
 Panel15->Visible=false;
 ComboBox2->Text="";
 ComboBox3->Text="DIA:";
 ComboBox5->Text="HORA:";
 Edit43->Enabled=true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button40Click(TObject *Sender)
{
 /*Boton atras restricion para profesor*/
 /*Cambio decendente de restriccion*/
 int i,e,j,y;
 Tiempo tem;
 Edit45->Text=Edit45->Text.ToInt()-1;
 if(Edit45->Text.ToInt()<0)Edit45->Text=0;
 s=Edit43->Text;
 e=carr.ind_prof(s.c_str());
 if(e==-1)
   {
    ShowMessage("ERROR. EL PROFESOR NO EXISTE");
    return;
   }
 tem=carr.profe[e].dar_restri((Edit45->Text.ToInt()-1));
 j=tem.hora;
 y=tem.dia;
 if(j<5)ComboBox3->Text=text[j];
 if(y<12)ComboBox5->Text=text1[y];
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button41Click(TObject *Sender)
{
 /*Boton adelante restricion de profesor*/
 /*Cambio asendente de restricion*/
 int i,e,j,y;
 Tiempo tem;
 Edit45->Text=Edit45->Text.ToInt()+1;
 if(Edit45->Text.ToInt()>carr.profe->dar_restriciones())Edit45->Text=(carr.profe->dar_restriciones()+1);
 s=Edit43->Text;
 e=carr.ind_prof(s.c_str());
 if(e==-1)
   {
    ShowMessage("ERROR. EL PROFESOR NO EXISTE");
    return;
   }
 tem=carr.profe[e].dar_restri((Edit45->Text.ToInt()-1));
 j=tem.hora;
 y=tem.dia;
 if(j<12)ComboBox3->Text=text1[j];
 if(y<5)ComboBox5->Text=text[y];
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button42Click(TObject *Sender)
{
 /*Boton cargar restricion para el profesor*/
 /*Al ingersar el codigo del profesor*/
 int e,i,j,y;
 Tiempo tem;
 s=Edit43->Text;
 e=carr.ind_prof(s.c_str());
 if(e==-1)
   {
    ShowMessage("ERROR. EL PROFESOR NO EXISTE");
    return;
   }
 i=carr.profe[e].dar_restriciones();
 if(i<0)return;
 Edit45->Text=i;
 Edit43->Enabled=false;
 Button38->Enabled=true;
 ComboBox3->Text="DIA:";
 ComboBox5->Text="HORA:";
}

//---------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




