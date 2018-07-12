/*
 * main.cpp
 *
 *  Created on: 19/04/2016
 *      Author: 9267011
 */
#include<iostream>
#include "List.h"
using namespace std;

int main()
{
	List l;
	 l.Insert(1,1);
	 l.Insert(2,2);
	 l.Insert(3,3);
	 l.Insert(4,4);
	 l.Insert(5,5);
	 l.Insert(6,6);
	 l.Insert(7,7);
	 l.Insert(8,8);
	 l.Insert(9,9);
	 l.Insert(10,10);
	 l.Insert(11,11);
	 l.Insert(12,12);
	 cout << "Antes Swap" << endl;
	 cout << "Lista: " << l.toString() << endl;
	 cout << "Nos..: " << l.toStringAddr() << endl;
	 
	 
	 l.Swap(12,11);
	 //cout << "Apos Swap(3,5)" << endl;
	 
	 
	 cout << "Lista: " << l.toString() << endl;
	 cout << "Nos..: " << l.toStringAddr() << endl;


 return 0;
}





