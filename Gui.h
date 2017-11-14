/////////////////////////////////GUI.H//////////////////////////////////////////
/*Esta libreria contiene las funciones descritas en el diagrama de secuencias,
estas se encargan del funcionamiento total del programa y tolo lo que el usuario
puede hacer. recibe el nombre de Gui por estar estrechamente ligada a la
interfaz del usuario.*/

////////////////////////////////LIBRERIAS///////////////////////////////////////

#ifndef _Gui_h
#define _Gui_h
#include "Actores.h"
#include <fstream.h>



/////////////////////////////VARIABLES Y CONSTANTES/////////////////////////////



//////////////////////////////////FUNCIONES/////////////////////////////////////

int Gui_Cons_Sem(char n_sem,Horario &carr);/*Funcion encargada de buscar si el
                                semestre existe y deplegarla en la pantalla,
                                retorna cero si todo esta bien y diferente de
                                cero si no.*/

int Gui_Cons_Usu(int usuario,char* codigo,Horario &carr);/*Funcion encargada de
                                            buscar si el usuario existe, retorna
                                            cero si todo esta bien y diferente
                                            de cero si no.*/

int Gui_Cons_Cod(int opcion,char* codigo,Horario &carr);/*Funcion encargada de
                              buscar la existencia de codigo, retorna cero si el
                              codigo existe y diferente de cero si no.*/

int Gui_Cons_Reg(Horario &carr,char* codigo,char* grupo);/*Funcion encargada de
                              consultar si la materia existe, y si se puede
                              registrar, retorna cero si el codigo existe, 1 si
                              no se pudo comunicar con el horario, 2 si la
                              materia no existe, 3 si el cupo esta lleno. */

void Gui_guardar_horario(Horario &carr,char *nombre);/*Funcion encargada de
                                                      guardar horario*/

void Gui_guardar_sem(Horario &carr);/*Funcion encargada de
                                                    guardar los semestres*/

void Gui_guardar_mat(Horario &carr);/*Funcion encargada de
                                                    guardar las materias*/

void Gui_guardar_gru(Horario &carr);/*Funcion encargada de
                                                    guardar los grupos*/

void Gui_guardar_secc(Horario &carr);/*Funcion encargada de
                                                    guardar las secciones*/
void Gui_guardar_prof(Horario &carr);/*Funcion encargada de
                                                    guardar los profesores*/

void Gui_guardar_est(Horario &carr);/*Funcion encargada de
                                                    guardar los estudiantes*/

void Gui_guardar_sal(Horario &carr);/*Funcion encargada de
                                                    guardar los salones*/

void Gui_abrir_horario(Horario &carr,char *nombre);/*Funcion
                                                    encargada de abrir horario*/

void Gui_abrir_sem(Horario &carr);/*Funcion encargada de
                                                    abrir los semestres*/

void Gui_abrir_mat(Horario &carr);/*Funcion encargada de
                                                    abrir las materias*/

void Gui_abrir_gru(Horario &carr);/*Funcion encargada de
                                                    abrir los grupos*/

void Gui_abrir_secc(Horario &carr);/*Funcion encargada de
                                                    abrir las secciones*/

void Gui_abrir_prof(Horario &carr);/*Funcion encargada de
                                                    abrir los profesores*/

void Gui_abrir_est(Horario &carr);/*Funcion encargada de
                                                    abrir los estudiantes*/

void Gui_abrir_sal(Horario &carr);/*Funcion encargada de
                                                    abrir los salones*/


#endif
