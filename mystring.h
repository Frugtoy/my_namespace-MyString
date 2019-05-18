#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::swap;
//#define STRBUFSIZE sizeof(char*)
namespace my_namespace
{
class MyString
{
   public:
            
	 MyString();//constructor+
	 MyString(const MyString&string);//cpy+
	 MyString(const char* string);//cpy+
	 MyString& operator=(int number);
	 MyString& operator= (const MyString &string);//a=b+
	 MyString&  operator= (const char * string);//a="kyky"+
	 MyString operator+ ( MyString &string);//a+b+
	 MyString operator+ (const char * string);//a+"kyky"+
	 MyString& operator+= (MyString& string);//a+=b;+
	 MyString& operator+=(const char *sring);//a+="kyky"+
	 char& operator[](int indx); //indexof string[10]=?
	 char  operator[](int indx)const;
	 operator const char*()const;
	 bool operator== (MyString& string);//0 1+
	 bool operator== (const char* string);// 0 1+
	 bool operator<=(MyString& string);
	 bool operator<= (const char* string);
	 bool operator>=(MyString& string);
	 bool operator>=(const char *string );
     MyString reverse();//+
	 bool isEmpty();//+
	 unsigned  int getsize();
	const long set_hash() const;
	int get_number();
	
	
	  friend std::ostream& operator<<(std::ostream& stream , const MyString &string)
	 {
		stream << string._data;
		return stream;
	 }
	 friend std::istream& operator >> (std::istream& stream, const MyString &string)
	 {
		 stream >> string._data;
		return stream;	
 	 }
	 unsigned int  get_size()const{return this->_size;}
	 ~MyString();//+
   private:
	char* _data;
    mutable unsigned int _size;
	mutable long _hash;
	mutable bool _changed;
	};
}