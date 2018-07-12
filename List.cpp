/*
 * List.cpp
 *
 *  Created on:
 *      Author:
 */
#include "List.h"
//---------------------------------------------------------------
List::List()
{
  head = NULL;
  count = 0;
}
//---------------------------------------------------------------
List::~List()
{
  Clear();
}
//---------------------------------------------------------------
bool List::Empty()
{
  return (head == NULL);
}
//---------------------------------------------------------------
bool List::Full()
{
   return false;
}
//---------------------------------------------------------------
void List::Clear()
{ ListPointer q;

  while (head != NULL)
  {  q = head;
     head = head->NextNode;
     delete q;
  }
  count = 0;
}
//---------------------------------------------------------------
long List::Size()
{
   return count;
}
//---------------------------------------------------------------
void List::Insert(long p, ListEntry x)
{ ListPointer NewNode, current;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  NewNode = new ListNode;
  NewNode->Entry = x;
  if(p == 1)
  {  NewNode->NextNode = head;
     head = NewNode;
  }
  else
  {  SetPosition(p-1,current);
     NewNode->NextNode = current->NextNode;
     current->NextNode = NewNode;
  }
  count++;
}
//---------------------------------------------------------------
void List::Delete(long p, ListEntry &x)
{ ListPointer Node, current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  if(p == 1)
  {  Node = head;
     head = Node->NextNode;
  }
  else
  {  SetPosition(p-1,current);
     Node = current->NextNode;
     current->NextNode = Node->NextNode;
  }
  x = Node->Entry;
  delete Node;
  count = count - 1;
}
//---------------------------------------------------------------
void List::Retrieve(long p, ListEntry &x)
{ ListPointer current;

  SetPosition(p,current);
  x = current->Entry;
}
//---------------------------------------------------------------
long List::Search(ListEntry x)
{ long p=1;
  ListPointer q=head;

  while (q != NULL && q->Entry != x)
  {  q = q->NextNode;
     p++;
  }
  return (q == NULL ? 0 : p);
}
//---------------------------------------------------------------
string List::toString()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q->Entry << ",";
     q = q->NextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
string List::toStringAddr()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q << ",";
     q = q->NextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
void List::SetPosition(long p, ListPointer &current)
{ long i;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  current = head;
  for(i=2; i<=p; i++)
      current = current->NextNode;
}
//---------------------------------------------------------------
long List::GetAddr(ListEntry x)
{ ListPointer current=NULL;
  long p = Search(x);
  if(p != 0)
    SetPosition(p, current);
  return (long)current;
}
//---------------------------------------------------------------
bool List::Swap(ListEntry a, ListEntry b)
{ // sua implementacao vem aqui

	//Se a lista está vazia ou contém um único elemento ou a=b, o método não altera a lista e retorna false;
	if( Empty() || a == b )
		return false;


	ListPointer ptrA = NULL; //Aponta para o A
	ListPointer ptrB = NULL; //Aponta para o B
	ListPointer ptrAa = NULL; //Aponta para o nó antes de A
	ListPointer ptrBb = NULL; //Aponta para o nó antes de B

	ListPointer q = head;
	//Procura os elementos na lista
	  while (q != NULL && (ptrA == NULL || ptrB == NULL))
	  {
		if(q->Entry == a && ptrA == NULL) {
			ptrA = q;//ptr para o nó A
		}
		else if(ptrA == NULL)
			ptrAa = q;//ptr para o nó antes de A

		if(q->Entry == b && ptrB == NULL) {
			ptrB = q; //ptr para o nó B
		}
		else if(ptrB == NULL)
			ptrBb = q;//ptr para o nó antes de B

		q = q->NextNode;
	  }
	
	  if(ptrA == NULL || ptrB == NULL) {
		  return false;
	  }
  
	ListPointer aux, aux1;


	//Se b vem antes de a, troca os ponteiros
	if( ptrA > ptrB ){
		aux = ptrA;
		aux1 = ptrAa;
		ptrA = ptrB;
		ptrAa = ptrBb;
		ptrB = aux;
		ptrBb = aux1;
	}
	
	
	//Se tem apenas dois elementos
	if(Size() == 2){
		head = ptrB;
		ptrA->NextNode = ptrB->NextNode;
		ptrB->NextNode = ptrA;
	}
	else
		//Se a e b s�o separados por um ou mais n�s na lista e n�o est�o no inicio da lista
		if(ptrA != ptrBb && ptrB != ptrAa && ptrAa != 0 && ptrBb != 0) 
		{
			aux = ptrA->NextNode;
			ptrA->NextNode = ptrB->NextNode;
			ptrB->NextNode = aux;	
			
			aux = ptrAa->NextNode;
			ptrAa->NextNode = ptrBb->NextNode;
			ptrBb->NextNode = aux;
		}
		else	
			//Se a esta no inicio da lista e n�o s�o consecutivos
			if(ptrAa == 0 && ptrA != ptrBb){	
				head = ptrB;		
				aux = ptrB->NextNode;
				ptrB->NextNode = ptrA->NextNode;
				ptrBb->NextNode = ptrA;
				ptrA->NextNode = aux;
			}
			else	
				//a e b s�o consecutivos e n�o est�o no come�o da lista
				if(ptrA == ptrBb && ptrAa != 0){
					ptrAa->NextNode = ptrB;
					aux = ptrB->NextNode;
					ptrB->NextNode = ptrA;
					ptrA->NextNode = aux;
				}
				else	
					//a e b s�o consecutivos e est�o no come�o da lista
					if(ptrA == ptrBb && ptrAa == 0) { 
						head = ptrB;
						ptrA->NextNode = ptrB->NextNode;
						ptrB->NextNode = ptrA;
					}
	return true;
}
//---------------------------------------------------------------
