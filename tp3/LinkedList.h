/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);// te da una copia del puntero que apunta al elemento
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);//saca todos y deja el primero incializado esperando ser cargado.
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);//se le pasa un puntero y ll devulve un puntero es como un "buscar"
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);//devuelve la referencia del indice que pusiste y lo saca de la lista
int ll_contains(LinkedList* this, void* pElement);//parecido a indesof pero solamente dice si esta el elemento
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);//le pasa el ll (decis desde donde hasta donde) y devuelve un subconunto del ll
LinkedList* ll_clone(LinkedList* this);//copia el ll en la memoria y devuelve el puntero del primer elemento es algo asi como un copy paste
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*)/*lo de atras es un puntero a una funcion*/, int order);// hace un burbujeo pero hay que completarla
//el nombre de una funcion sin los parentesis es la direccion de memoria de esa funcion. y se puede invocar de otro lado
