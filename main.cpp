#include <iostream>
#include "mystring.h"
 using std::cin;
 using std::cout;
 using my_namespace::MyString;
 int main()
 { 

     MyString a("lama ");
     const MyString b("star ");
     MyString c;
     c = a + b;
     a+=b;
     cout<<a<<endl;
     cout<<c<<endl;
     cout<<b<<endl;
     cout<<c.set_hash()<<endl;
     cout<<a.set_hash()<<endl;
     cout<<b.set_hash()<<endl;
     if(a==b)
        cout<<"yah"<<endl;
     else 
        cout<<"nah"<<endl;
     if(a.isEmpty()==false)
        cout<<"(a)string is not empty"<<endl;
        cout<<a.reverse()<<endl;

      if ( a >= b)
         cout<<"yah baby"<<endl;
      else 
         cout<<"no bro"<<endl;

     cout<< c.get_size()<<endl;
     try
     {
        cout<<c[11];
     }
     catch(const std::exception& e)
     { 
        std::cerr << e.what() << '\n';
     }
   
      MyString k;
      k = -2;
      cout<<endl<<"the string by numb is: " <<k<<endl;
   return 0;
}