#pragma once
#include <iostream>
#include "Excep.h"
#include <algorithm>
using namespace std;



class Int_Array :public bad_length, bad_range
{
public:

	Int_Array() = default;

	Int_Array(int length);

	~Int_Array();

	void erase();

	int& operator[](int Index);
	
	int getLength() const;

	void Realocate(int New_Length);
	
	void Resize(int New_Length);

	Int_Array(const Int_Array& a);

	Int_Array operator=(const Int_Array& a);

	void insertBefore(int value, int index);

	void remove(int index);


	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, _Length); }

	

private:
	int _Length;
	int* Arr{};
	
};

