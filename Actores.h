/////////////////////////////ACTORES////////////////////////////////////////////
/*Esta libreria contiene las clases del modelo de dominio, sus relaciones,
restriciones y otros elementos mas. posee ademas tdos los elementos del diagrama
de clases.*/

////////////////////////////////LIBRERIAS///////////////////////////////////////

#ifndef _Actores_h
#define _Actores_h
#include <string.h>
#include <String>
#include <vcl.h>
#include "Espacio.h"
#include "Tiempo.h"
#include "Cadenas.h"

/////////////////////////////VARIABLES Y ESTRUCTURAS////////////////////////////


//////////////////////////////FUNCIONES/////////////////////////////////////////

void Ac_acond(char *a);/*Funcion encargada de acondicionar las cadenas de
                           caracteres para no tener espacios*/




////////////////////////////////CLASES//////////////////////////////////////////

class Identidad /*Clase encargada del manejo del usuario*/
{
 protected:
           String nombre;
           String codigo;
 public:
        Identidad();//Constructorpor defecto
        Identidad(const Identidad&);//Constructor por copia
        ~Identidad();//Destructor
/*----------------------------------------------------------------------------*/
        void ingre_nom(char *nom);//Se encarga de dar el nombre al usuario
        void ingre_cod(char *nom);//Se encarga de dar el codigo al usuario
/*----------------------------------------------------------------------------*/
        char* dar_nom(void);//Brinda el nombre del usuario a solicitud
        char* dar_cod(void);//Brinda el codigo del usuario a solicitud
/*----------------------------------------------------------------------------*/
        Identidad& operator=(const Identidad&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Identidad&,const Identidad&);
        friend int operator!=(const Identidad&,const Identidad&);
/*----------------------------------------------------------------------------*/
        friend ostream& operator<< (ostream&,const Identidad&);
        friend istream& operator>> (istream&,Identidad&);
};

/******************************************************************************/

class Asignacion
{
        String *grupo;//Codigo del grupo
        String *materia;//Codigo de la materia
        String *semestre;//Codigo del semestre
        int n_tol;
/*----------------------------------------------------------------------------*/
 public:
/*----------------------------------------------------------------------------*/
        Asignacion();//Contructor
        Asignacion(const Asignacion&);//Contructor por copia
        ~Asignacion();//Destructor
/*----------------------------------------------------------------------------*/
        void add_gru(char *gru,char *mat);
        void del_gru(char *gru,char *mat);
        void clear_all(void);
        int ind_gru(char *gru);
        int dar_tol(void);
        char* dar_gru(int ind);
        char* dar_mat(int ind);
        char* dar_sem(int ind);
        void ingre_n_tol(int tol);
        void ingre_gru(char *gru,int ind);
        void ingre_mat(char *mat,int ind);
        void ingre_sem(char *sem,int ind);
/*----------------------------------------------------------------------------*/
        Asignacion& operator=(const Asignacion&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Asignacion&,const Asignacion&);
        friend int operator!=(const Asignacion&,const Asignacion&);
        friend ostream& operator<< (ostream&,const Asignacion&);
        friend istream& operator>> (istream&,Asignacion&);
};

/******************************************************************************/

class Profesor/*Clase encargada del manejo del profesor*/
{
        int capacidad;//Numero maximo de materias a asignar
        int n_restri;//Numero de restricciones
        TCita *restri;/*Asignacion dinamica de las retriciones*/
 public:
        Profesor();//Constructor
        Profesor(const Profesor&);//Contructor por copia
        ~Profesor();//Destructor
        Identidad identidad;
        Asignacion asig;
/*----------------------------------------------------------------------------*/
        void capacitar(int n);/*Funcion encargada de ingresar la capacidad*/
        void n_restricciones(int tem);/*Funcion encargada de ingresar el numero
                                    de restricciones*/
        void ingre_restri(TCita tim,int secc);/*Funcion encargada de ingresar
                                               el tiempo de la restriccion*/
/*----------------------------------------------------------------------------*/
        int ind_res(TCita tim);/*Funcion encargada de retornar el indice de la
                               restriccion*/
/*----------------------------------------------------------------------------*/
        int dar_capacidad(void);/*Funcion encagada de devolver la capacidad*/
        int dar_restriciones(void);/*Funcion encargadad de dar el numero de
                                   restriciones*/
        void add_restri(TCita times);/*Funcion encargada de adicionar restriccion*/
        void del_restri(TCita times);/*Funcion encargada de eliminar restriccion*/
        TCita dar_restri(int secc);/*Funcion encargada de dar el tiempo de la
                                    restriccion*/
        void clear_restri(void);/*Funcion dinamica encargada de borrar los arreglos
                            dinamicos*/
/*----------------------------------------------------------------------------*/
        Profesor& operator=(const Profesor&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Profesor&,const Profesor&);
        friend int operator!=(const Profesor&,const Profesor&);
        friend ostream& operator<< (ostream&,const Profesor&);
        friend istream& operator>> (istream&,Profesor&);
};

/******************************************************************************/

class Estudiante/*Clase encargada del manejo del estudiante*/
{
 public:
        Identidad identidad;
        Asignacion asig;
/*----------------------------------------------------------------------------*/
        Estudiante();//Constructor
        Estudiante(const Estudiante&);//Contructor por copia
        ~Estudiante();//Destructor
        Estudiante& operator=(const Estudiante&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Estudiante&,const Estudiante&);
        friend int operator!=(const Estudiante&,const Estudiante&);
        friend ostream& operator<< (ostream&,const Estudiante&);
        friend istream& operator>> (istream&,Estudiante&);
};

/******************************************************************************/

class Salon/*Clase encargada del manejo de los salones*/
{
        int capacidad;/*Capacidad maxima de estudiantes por salon*/
 public:
        Salon();//Contructor
        Salon(const Salon&);//Contructor por copia
        ~Salon();//Destructor
        Identidad identidad;
        TVector3d pos;/*Posicion del salon*/
/*----------------------------------------------------------------------------*/
        void ingre_capa(int num);/*Funcion encargada de ingresar la capacidad*/
/*----------------------------------------------------------------------------*/
        int dar_capacidad(void);/*Funcion encargada de retornar la capacidad de
                                un salon*/
/*----------------------------------------------------------------------------*/
        int capacitar(int est);/*Funcion encargada de estimar si se excedio la
                               capacidad del salon*/
/*----------------------------------------------------------------------------*/
        Salon& operator=(const Salon&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Salon&,const Salon&);
        friend int operator!=(const Salon&,const Salon&);
        friend ostream& operator<< (ostream&,const Salon&);
        friend istream& operator>> (istream&,Salon&);
};

/******************************************************************************/

class Seccion/*Clase encargada del manejo de las secciones*/
{
        String sal;/*Codigo de los salones*/
        bool Cita_estatica;
 public:
        TCita time;/*Asignacion dinamica de la hora*/
        Seccion();//Constructor grupo
        Seccion(const Seccion&);//Contructor por copia
        ~Seccion();//Destructor
        void ingre_tiempo(TCita tim);/*Funcion encargada de ingresar el tiempo
                                     de la seccion*/
        void ingre_sal(char *salon);/*Funcion encargada de ingresar el salon de
                                   la seccion*/
        char* dar_salon(void);/*Funcion encargada de dar el codigo del salon*/
        TCita dar_tiempo(void);/*Funcion encargada de dar el tiempo de la
                                    seccion*/
        void estatica(bool);/*Funcion encargada de hacer estatico el
                                     horario de la seccion*/
        bool estatica(void);/*Funcion encargada de indicar si la seccion es
                                 estatica*/                                                              
/*----------------------------------------------------------------------------*/
        Seccion& operator=(const Seccion&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Seccion&,const Seccion&);
        friend int operator!=(const Seccion&,const Seccion&);
        friend ostream& operator<< (ostream&,const Seccion&);
        friend istream& operator>> (istream&,Seccion&);
};

/******************************************************************************/

class Grupo/*Clase encargada del manejo del grupo*/
{
        String profe;/*codigo del profesor*/
        String *estu;/*codigos de los estudiantes*/
        int n_estudiantes;/*Numero de estudiantes asignados a este curso*/
        int capacidad;/*Numero maximo de estudiantes que pueden registrar este
                      grupo*/
        int n_clas;/*Varialble que indica el numero de secciones de la materia*/
 public:
        Seccion *secc;
        Identidad identidad;
/*----------------------------------------------------------------------------*/
        Grupo();//Constructor grupo
        Grupo(const Grupo&);//Contructor por copia
        ~Grupo();//Destructor
/*----------------------------------------------------------------------------*/
        void ingre_est(int num);/*Funcion encargada de ingresar el numero de
                                estudiantes*/
        void ingre_capa(int num);/*Funcion encargada de ingresar la capacidad*/
        void n_secciones(int tem);/*Funcion encargada de ingresar el numero de
                                  secciones*/
        void ing_profe(char *cod);/*Funcion encargada de ingresar codigo del profesor*/
/*----------------------------------------------------------------------------*/
        void ing_estu(char* cod,int ind);/*Funcion encargada de ingresar el
                                        codigo del estudiante en el indice ind*/
/*----------------------------------------------------------------------------*/
        char* anu_profe(void);/*Funcion encargada de devolver el codigo del
                                  profesor a cargo del curso*/
        char* dar_est(int ind);/*Funcion encargada de retornar el codigo del
                                estudiante de indice ind*/
        int dar_ests(void);/*Funcion encargada de dar el numero de estudiantes*/
        int dar_capacidad(void);/*Funcion encargada de retornar la capacidad*/
        int n_secc(void);//Funcion encargada de indicar el numero de secciones
/*----------------------------------------------------------------------------*/
        void add_estu(char *cod);/*Funcion encargada de adicionar estudiante*/
        void del_estu(char *cod);/*Funcion encargada de eliminar estudiante*/
        void act_estu(char *cod,char *cod1);/*Funcion encargada de Actualizar
                                           estudiante*/
        void add_clas(Seccion seccion);/*Funcion encargada de adicionar seccion*/
        void del_clas(Seccion seccion);/*Funcion encargada de eliminar seccion*/
        void act_class(Seccion seccion,int i);/*Funcion encargada de actualizar
                                           seccion*/
        void clear_est();/*Funcion dinamica encargada de borrar los arreglos
                     dinamicos*/
        void clear_clas();/*Funcion dinamica encargada de borrar los arreglos
                     dinamicos*/

/*----------------------------------------------------------------------------*/
        int ind_sal(char *cod);/*Funcion encargada de retornar el indice del
                               salon*/
        int ind_est(char *cod);/*Funcion encargada de retornar el indice del
                               estudiante*/
        int ind_clas(TCita time);/*Funcion encargada de retornar el indice de
                                  la seccion en la hora*/
/*----------------------------------------------------------------------------*/
        Grupo& operator=(const Grupo&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Grupo&,const Grupo&);
        friend int operator!=(const Grupo&,const Grupo&);
        friend ostream& operator<< (ostream&,const Grupo&);
        friend istream& operator>> (istream&,Grupo&);
};

/******************************************************************************/

class Materia/*Clase encarga del manejo de la materia*/
{
        int n_grupos;/*Numero de cursos asignados a esta materia*/
 public:
        Identidad identidad;
        Grupo *gru;/*Agregacion grupo y memoria dinamica*/
/*----------------------------------------------------------------------------*/
        Materia();//Constructor materia
        Materia(const Materia&);//Contructor por copia
        ~Materia();//Destructor
/*----------------------------------------------------------------------------*/
        void cursar(int i);/*Funcion encarga de ingresar el numero de cursos*/
/*----------------------------------------------------------------------------*/
        int dar_grupos(void);//Funcion encargada de devolver el numero de grupos
/*----------------------------------------------------------------------------*/
        void add_gru(char *nom,char *cod);/*Funcion encargada de addicionar un nuevo
                                     grupo*/
        void del_gru(char *nom,char *cod);/*Funcion encargada de eliminar grupo*/
        void act_gru(char *nom,char *cod,char *nom1,char *cod1);/*Funcion encargada
                                                          de actualizar grupo*/
        void clear_gru();/*Funcion dinamica encargada de borrar los arreglos
                     dinamicos*/
/*----------------------------------------------------------------------------*/
        int ind_gru(char *cod);/*Funcion encargada de retornar el indice del
                                grupo*/
/*----------------------------------------------------------------------------*/
        Materia& operator=(const Materia&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Materia&,const Materia&);
        friend int operator!=(const Materia&,const Materia&);
        friend ostream& operator<< (ostream&,const Materia&);
        friend istream& operator>> (istream&,Materia&);
};

/******************************************************************************/

class Semestre/*clase encargada del manejo del semestre*/
{
        String nombre;/*Nombre del semestre*/
        int n_materias;/*Numero de materias asignadas al semestre*/
 public:
        Materia *mat;/*Agregacion materia y memoria dinamica*/
/*----------------------------------------------------------------------------*/
        Semestre();//Constructor
        Semestre(const Semestre&);//Contructor por copia
        ~Semestre();//Destructor
/*----------------------------------------------------------------------------*/
        void nombrar(char *nom);
        void numerar(int n);
        char* dar_nombre(void);
/*----------------------------------------------------------------------------*/
        int dar_numerom(void);/*Funcion encargada de dar el numero de materias*/
/*----------------------------------------------------------------------------*/
        void add_materia(char *nom,char *cod);/*Funcion encargada de generar una
                                              nueva materia*/
        void del_materia(char *nom,char *cod);/*Funcion encargada de eliminar
                                              materia de codigo cod*/
        void act_materia(char *nom,char *cod,char *nom1,char *cod1);/*Funcion
                                                encagada de actualizar materia*/
        void clear_mat();/*Funcion dinamica encargada de borrar los arreglos
                     dinamicos*/
/*----------------------------------------------------------------------------*/
        int ind_mat(char *cod);/*Funcion encargada de retornar el indice de la
                               materia con codigo cod*/
/*----------------------------------------------------------------------------*/
        Semestre& operator=(const Semestre&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Semestre&,const Semestre&);
        friend int operator!=(const Semestre&,const Semestre&);
        friend ostream& operator<< (ostream&,const Semestre&);
        friend istream& operator>> (istream&,Semestre&);
};

/******************************************************************************/

class Director/*Clase encargada del manejo del director y es
                             herencia de usuario*/
{
        String clave;//Clave en char para permitir uso de letras
/*----------------------------------------------------------------------------*/
        char* encritar(void);/*Funcion de encritacion de la clave*/
        void desencritar(char *encri);/*Funcion para la desencritacion de la clave*/
 public:
        Identidad identidad;
        Director();//Constructor
        Director(const Director&);//Contructor por copia
        ~Director();//Destructor
/*----------------------------------------------------------------------------*/
        void clavear(char *cla);//Ingresa la nueva clave del director
        void clavear_encri(char *encri);/*Almacena la clave desescritada*/
/*----------------------------------------------------------------------------*/
        char* darclave_encri(void);/*Retorna la clave encritadad*/
/*----------------------------------------------------------------------------*/
        int verificar(char *cla);//Retorna true si cla y clave son iguales
/*----------------------------------------------------------------------------*/
        Director& operator=(const Director&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Director&,const Director&);
        friend int operator!=(const Director&,const Director&);
        friend ostream& operator<< (ostream&,const Director&);
        friend istream& operator>> (istream&,Director&);
};

/******************************************************************************/

class Horario
{
        String nombre;/*Nombre del horario*/
        TCita Inicio,Final;
        int n_sem;/*Numero de semestres*/
        int n_profe;//Numero de profesores por horario
        int n_estudiantes;//Numero de estudiantes por horario
        int n_sal;/*Numero de salones*/
 public:
        Director Dir;/*Agregacion a director*/
        Semestre *Sem;/*Agregacion de semestre con memoria dinamica*/
        Profesor *profe;//agregacion profesor y asignacion dinamica de memoria
        Estudiante *est;//agregacion estudiante y asignacion dinamica de memoria
        Salon *sal;/*Agregacion de salon con memoria dinamica*/
/*----------------------------------------------------------------------------*/
        Horario();//Constructor de horario
        Horario(const Horario&);//Contructor por copia
        ~Horario();//Destructor
/*----------------------------------------------------------------------------*/
        TCita inicio(void){return Inicio;}/*Funcion encargada de retornar el
                                          inicio del rango de clases*/
        void inicio(TCita &i){Inicio=i;}/*Funcion encargada de ingresar la hora
                                        de inicio*/
        TCita final(void){return Final;}/*Funcion encargada de retornar el
                                        final del rango de clases*/
        void final(TCita &f){Final=f;}/*Funcion encargada de ingresar la hora del final*/
/*----------------------------------------------------------------------------*/
        void nombrar(char *nom);/*Funcion encargada de dar el nombre al horario*/
        void numerar(int num);/*Funcion encargada de guardar el numero de
                              semestres*/
        void ingre_pro(int num);/*Funcion encargada de ingresar el numero de
                                profesores*/
        void ingre_est(int num);/*Funcion encargada de ingresar el numero de
                                estudiantes*/
        void ingre_sal(int num);/*Funcion encargada de ingresar el numero de
                                salones*/
/*----------------------------------------------------------------------------*/
        char* decir_nombre(void);/*Funcion encargada de retornar el nombre del
                                 horario*/
        int dar_numero(void);/*Funcion encargada de dar el numero de semestres*/
        int dar_profes(void);/*Funcion encargada de dar el numero de profesores*/
        int dar_estudiantes(void);/*Funcion encargada de dar el numero de
                                  estudiantes en el horario*/
        int dar_salones(void);/*Funcion encargada de dar el numero de salones*/
/*----------------------------------------------------------------------------*/
        void add_sem(char *nom);/*Funcion encargada de adicionar un nuevo semestre*/
        void add_profe(char *nom,char *cod);/*Funcion encargada de crear un
                                              nuevo profesor, a la cual se
                                              ingresa, nombre y codigo*/
        void add_est(char *nom,char *cod);/*Funcion encargada de crear un
                                              nuevo estudiante, al cual se
                                              ingresa, nombre y codigo*/
        void add_sal(char *nom,char *cod);/*Funcion encargada de crear un
                                              nuevo salon, al cual se
                                              ingresa, nombre y codigo*/
/*----------------------------------------------------------------------------*/
        void clear_sem();/*Funcion dinamica encargada de borrar los arreglos
                         dinamicos*/
        void clear_profe();/*Funcion dinamica encargada de borrar los arreglos
                           dinamicos*/
        void clear_est();/*Funcion dinamica encargada de borrar los arreglos
                         dinamicos*/
        void clear_sal();/*Funcion dinamica encargada de borrar los arreglos
                     dinamicos*/
/*----------------------------------------------------------------------------*/
        void del_sem(char *nom);/*Funcion encargada de adicionar un nuevo semestre*/
        void del_profe(char *nom,char *cod);/*Funcion encargada de eliminar un
                                            profesor, a la cual se ingresa,
                                            nombre y codigo*/
        void del_est(char *nom,char *cod);/*Funcion encargada de eliminar un
                                          estudiante al cual se ingresa, nombre
                                          y codigo*/
        void del_sal(char *nom,char *cod);/*Funcion encargada de eliminar un
                                          salon, a la cual se ingresa, nombre y
                                          codigo*/
/*----------------------------------------------------------------------------*/
        void act_sem(char *nom,char *nom1);/*Funcion encargada de adicionar un nuevo semestre*/
        void act_profe(char *nom,char *cod,char *nom1,char *cod1);/*Funcion
                                            encargada de actualizar un
                                            profesor, a la cual se ingresa,
                                            nombre y codigo*/
        void act_est(char *nom,char *cod,char *nom1,char *cod1);/*Funcion
                                          encargada de actualizar un estudiante
                                          al cual se ingresa, nombre y codigo*/
        void act_sal(char *nom,char *cod,char *nom1,char *cod1);/*Funcion
                                          encargada de actualizar un salon, al
                                          cual se ingresa, nombre y codigo*/
/*----------------------------------------------------------------------------*/
        char* mat_gru(char *cod);/*Funcion encargada de retornar el codigo de la
                                 materia a la cual pertenece el grupo*/
        int ind_prof(char *cod);/*Funcion encargada de retornar el indice del
                                profesor, se recibe su codigo*/
        int ind_est(char *cod);/*Funcion encargada de retornar el indice del
                               estudiante, se recibe su codigo*/
        int ind_sal(char *cod);/*Funcion encargada de retornar el indice del
                               salon, se recibe su codigo*/
        int ind_seme(char *nom);/*Funcion encargada de retornar el indice del
                               semestre, se recibe su nombre*/
        int sem_mat(char *cod);/*Funcion encargada de retornar el semestre al
                               cual pertenece una materia de codigo cod*/
/*----------------------------------------------------------------------------*/
        int n_mat(void);/*Funcion encargada de retornar el numero de materias
                        en el horario*/
        int n_gru(void);/*Funcion encargada de retornar el numero de grupo en el
                        horario*/
        int n_secc(void);/*Funcion encargada de retornar el numero de secciones
                        en el horario*/
/*----------------------------------------------------------------------------*/
        Horario& operator=(const Horario&);
/*----------------------------------------------------------------------------*/
        friend int operator==(const Horario&,const Horario&);
        friend int operator!=(const Horario&,const Horario&);
        friend ostream& operator<< (ostream&,const Horario&);
        friend istream& operator>> (istream&,Horario&);
/*----------------------------------------------------------------------------*/
        friend void get_sem(ostream&,const Horario&);
        friend void get_mat(ostream&,const Horario&);
        friend void get_gru(ostream&,const Horario&);
        friend void get_secc(ostream&,const Horario&);
        friend void get_pro(ostream&,const Horario&);
        friend void get_est(ostream&,const Horario&);
        friend void get_sal(ostream&,const Horario&);
        friend void set_sem(istream&,Horario&);
        friend void set_mat(istream&,Horario&);
        friend void set_gru(istream&,Horario&);
        friend void set_secc(istream&,Horario&);
        friend void set_pro(istream&,Horario&);
        friend void set_est(istream&,Horario&);
        friend void set_sal(istream&,Horario&);
};

/******************************************************************************/

#endif