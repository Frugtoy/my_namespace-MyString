#include "mystring.h"
#include <exception>
using std::runtime_error;
using my_namespace::MyString;
MyString::MyString()
{
	this->_size=0;
	cout<<"&&&&&simple constructor&&&&&"<<endl;
	this->_data = new char[1];
	this->_data[0] ='\0';
	this->_hash =0;
	this ->_changed=true;
}
MyString::~MyString()
{
  cout<<"&&&&&destructor&&&&&"<<endl;
  delete[] this->_data;
  this-> _size = 0;
}

MyString::MyString(const MyString &string)//!!!!!!!!!!!!!
{
	cout<<"&&&&&copy constructor&&&&&"<<endl;
	this->_size=string._size;
	this->_data= new char[_size + 1];
	strcpy(this->_data, string._data);

}
MyString::MyString(const char* string)
{
	cout<<"&&&&&copy str constructor&&&&&"<<endl;
  this->_size = strlen(string);
  this->_data = new char [this->_size+1];
  strcpy(this->_data,string);
}
MyString& MyString::operator= (const MyString &string)//!!!
{
	cout<<"&&&&&copy = operator&&&&&"<<endl;
	if (this != &string)//проверка на приравнивание переменной к самой себе 
	{
		delete[] this->_data;
		this->_size = string._size;
		this->_data = new char[this->_size+1];
		strcpy(this->_data,string._data);
		this->_changed=true;
		this->set_hash();
	}
	return *this;
}

MyString& MyString::operator= (const char* string)
{
  cout<<"&&&&copy = oper for string&&&&"<<endl;
  delete[]this->_data;
  this->_size = strlen(string);
  this->_data = new char[_size+1];
  strcpy(this->_data ,string);
	this->_changed=true;
	this->set_hash();
  return *this;

}

unsigned  int MyString::getsize()
{
	 return this->_size;
}

bool MyString::isEmpty()
{
	cout<<"&&&&isempty check&&&&"<<endl;
	if(this->_size!=0 )
	  return false;
	else 
	  return true;
}

MyString MyString::reverse()
{	 
		cout<<"&&& reverse: ";
	  int k =1;
    char swElem = 'o';
	  if (this->getsize()%2==0)
	  {
      	for(unsigned long int i =0;i<this->getsize()/2;i++) 
	  	{
				swElem = this->_data[i];
				this->_data[i]=this->_data[this->getsize()-(i+1)];
				this->_data[this->getsize()-(i+1)]=swElem;
		  }
		}
	 else
	 {
	      	for(unsigned long int i =0;i < this->getsize()/2;i++) 
	  	    {
						swElem = this->_data[i];
						this->_data[i]=this->_data[this->getsize()-k];
						this->_data[this->getsize()-k]=swElem;
						k++;
		  	  }
	 }
	 this->_changed=true;
	 this->set_hash();
	 return *this;
	}

    MyString MyString::operator+ ( MyString &string)
	{
		cout <<"&&&&simple operator +&&&&"<<endl;
	
		MyString sum ; 
		sum._size = this->_size+string._size;//two \0
		sum._data = new char[sum._size];
		unsigned long k = 0;	
		for(unsigned int i = 0; i<sum._size;i++)
		{
			if (i<this->_size)
				sum._data[i]=this->_data[i];
			else 
			{
				sum._data[i]=string._data[k];
				k++;
			}
		}
		sum._data[sum._size]='\0';
		sum._changed=true;
		sum.set_hash();
		return sum;
	}
	
	 MyString MyString::operator+(const char * string)
	{
		cout<<"&&&&string operator +&&&&"<<endl;
		unsigned long k = 0;	
		MyString sum ; 
		sum._size = this->_size+strlen(string);//two \0
		sum._data = new char(sum._size);
		for(unsigned int i = 0; i<sum._size-1;i++)
		{
			if (i<this->_size-1)
				sum._data[i]=this->_data[i];
			else 
			{
				sum._data[i]=string[k];
				k++;
			}
		}
			sum._data[sum._size]='\0';
		sum._changed=true;
		sum.set_hash();
		return sum;
	}
	
	 MyString& MyString::operator+=(MyString& string)//a+=b;
	 {
		 cout <<"&&&&simple operator +&&&&"<<endl;
		 *this = *this+string ;
		 this->_changed = true;
		 this->set_hash();
		 return *this;

	 }
	 MyString& MyString::operator+=(const char *string)//a+="kyky"
	 {
		 cout <<"&&&&&string operator +=&&&&&"<<endl;
		 MyString str(string);
		 *this = *this+ str;
		 this->_changed = true;
		 this->set_hash();
		 return *this;//(this +string)??

	 }
	 
	 bool MyString::operator== (MyString& string)//0 1
	 {
		 cout <<"&&&&simple operator ==&&&&"<<endl;
		 bool flag = true;
		 if(this->_size!=string._size)
		 	return false;

		 	for(unsigned int i =0; i<this->_size;++i)
			{
				if(this->_data[i]!=string._data[i])
				{
					flag = false;
					return flag;
				}
			}
			return flag;
	 }
	 bool MyString::operator== (const char* string)// 0 1
	 {
		 cout <<"&&&&string operator ==&&&&"<<endl;
		 MyString a(string);
		 return (*this == a);
   }
	 char& MyString::operator[](int indx)
	 {
		 if(indx<0||indx>=this->_size)
		 { 
		 		throw runtime_error("there is no spot in string wiz this index bro\n");
		 }
		 return *this->_data;
	 }
	 char MyString::operator[](int indx)const
	 {
		 		 if(indx<0||indx>=this->_size)
		 { 
		 		throw runtime_error("there is no spot in string wiz this index bro\n");
		 }
		 return this->_data[indx];
	 }
	 MyString::operator const char*()const{return this->_data;};
 
  const long MyString::set_hash() const
	{
		if(this->_changed==true)
		{
			this->_hash =0;
			for(int i = 0; i< this->_size;++i)
			{
				this->_hash+=this->_data[i];
			}
			
			this->_changed =false;
		}
		  cout<<"&&&&&hash: ";
			return this->_hash;
		
	}
	 bool MyString :: operator<=(MyString&string)
	 {
      if (strlen(this->_data)<=strlen(string._data))
						return true;
			else 
						return false;
	 }
	 bool MyString:: operator<= (const char* string)
	 {
		   MyString buf(string);

			 if ( strlen(this->_data)<= strlen(buf._data))
			 		return true ;
			 else 
					return false;

	 }
	 bool MyString:: operator>=(MyString& string)
	 {
		 	if (strlen (this->_data) >= strlen(string._data))
			 return true;
			
			return false;
	 }
	 bool MyString :: operator>=(const char *string )
	 {	
		 MyString  buf (string);
		 if (strlen(this->_data)>=strlen(buf._data))
		 		return true ;
			
		 return false;
	 }
	 int MyString::get_number() {
		 int result = 0;
		 bool positive = true;
		 int start_pos =0;
		 if(this->_data[0]=='-') {
		 		positive =false;
		 		start_pos++;
		 }
		 for(int i =start_pos ;i<this->_size;++i)
		 {
			  switch (this->_data[i])
				{
				case '0': {
					 result*=10;
					break;
				}
				case '1': {
					 result*=10;
					 result+=1;
					break;
				}
				case '2': {
					 result*=10;
					 result+=2;
					break;
				}
				case '3': {
					 result*=10;
					 result+=3;
					break;
				}
				case '4':{
					 result*=10;
					 result+=4;
					 
					break;
				}
				case '5':{
					 result*=10;
					 result+=5;
					break;
				}
				case '6': {
					 result*=10;
					 result+=6;
					break;
				}
				case '7': {
					 result*=10;
					 result+=7;
					break;
				}
				case '8': {
					 result*=10;
					 result+=8;
					break;
				}
				case '9': {
					 result*=10;
					 result+=9;
					break;
				}
			  default:{
					throw std::logic_error("cannot convert that string to number"); 
				}
			}
		}
		  positive == true ? :result*=-1;
			return result;
	  }
      
		MyString&  MyString::operator=(int number)  {

			 if (number == 0) {
				 MyString buf("0");
				 *this = buf;
				 return *this;
			 }
			 else {
			 	int k =number;
			 	int razryad = 1;
			 	int tail =1;
				MyString buf;
			 	if(number < 0)
			 	{
					 buf = "-";
					 number*=-1;
				}
			 	while(k/10!=0)
			 	{
					 razryad++;
					 k/=10;
					 tail*=10;
			 	}
	
			 	do {
				 switch (number / tail) {
			     case 0 : {
				    buf+="0";
				   break;
				   }
					 case 1 : {
				    buf+="1";
				   break;
				   }
					 case 2 : {
				   buf+="2";
				   break;
				   }
					 case 3 : {
				   buf+="3";
				   break;
				   }
					 case 4 : {
				   buf+="4";
				   break;
				   }
					 case 5 : {
				   buf+="5";
				   break;
				   }
					 case 6 : {
				   buf+"6";
				   break;
				   }
					 case 7 : {
				   buf+="7";
				   break;
				   }
					 case 8 : {
				   buf+="8";
				   break;
				   }
					 case 9 : {
				   buf+="9";
				   break;
				   }
			     default: {
					   throw std::logic_error("cannot convert float number , sorry");
				     break;
				   }
			   }
				 number = number % tail;
				 tail/=10;
				 razryad --;
				 
			 }
			 while (razryad);
			 *this = buf;
		}
		 return *this;
}