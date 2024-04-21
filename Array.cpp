#include"Array.h"
#include <stdexcept>


Int_Array::Int_Array(int length) :_Length(length)
{
	if (length <= 0)
	{
		throw bad_length();
	}
	else
	{
		Arr = new int[length] {};
	}
}
Int_Array::~Int_Array()
{
	delete[] Arr;
}

void Int_Array::  erase()
{
	delete[] Arr;
     
	Arr = nullptr;
	_Length = 0;
}

 int& Int_Array:: operator[] (int Index)
{
	
	 if (Index < 0 || Index > _Length)
	 {
		 throw bad_length();
		 
	 }
	 else
	 return Arr[Index];
}

 int Int_Array::getLength() const
{
         return _Length;
}

 void Int_Array::Realocate(int New_Length)
 {

	 erase();

	 if (New_Length<=0)
	 {
		 return;
	 }

	 Arr = new int[New_Length];
	 _Length = New_Length;

 }

 void Int_Array::Resize(int New_Length)
 {
	 if (New_Length==_Length)
		 return;

	 if (New_Length <= 0)
	 {
		 erase();
		 return;
	 }

	 int* _Arr{ new int[_Length] };

	 if (_Length>0)
	 {
		 int El_Copy{ (New_Length > _Length) ? _Length : New_Length };
		 std::copy_n(Arr, El_Copy, _Arr);
	 }
	 delete[] Arr;

	 Arr = _Arr;
	 _Length = New_Length;
 }

 Int_Array::Int_Array(const Int_Array& a) : Int_Array(a.getLength())
 {
	 std::copy_n(a.Arr, _Length, Arr);
 }

 Int_Array Int_Array::operator=(const Int_Array& a)
 {
	 if (&a == this)
		 return *this;

	
	 Realocate(a.getLength());
	 std::copy_n(a.Arr, _Length, Arr); 

	 return *this;
 }

 void Int_Array::insertBefore(int value, int index)
 {/*
	 throw (index > 0 && index <= _Length);*/
	 if (index > _Length || index < 0)
	 {
		 throw bad_range();
	 }

	 int* aArr{ new int[_Length+1] };

	 std::copy_n(Arr, index, aArr);

	 aArr[index] = value;

	 std::copy_n(Arr + index, _Length - index, aArr + index + 1);

	 delete[] Arr;
	 Arr = aArr;
	 ++_Length;
 }

 void Int_Array::remove(int index)
 {
	
	 if (index > _Length || index < 0)
	 {
		 throw bad_range();
	 }

	 if (_Length==1)
	 {
		 erase();
		 return;
	 }

	 int* Arra{ new int[_Length - 1] };

	 std::copy_n(Arr, index, Arra);

	 std::copy_n(Arr + index + 1, _Length - index - 1, Arra + index);

	 delete[] Arr;
	Arr = Arra;
	 --_Length;
 }

