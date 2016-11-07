/*Implementing the Password class which includes: private data of a char* string pointer and
 int length; a constructor to initialize the password to a random string of 8 to 12 characters
 chosen from uppercase letters, lowercase letters, and numbers; a reset method to replace the password
 with a new one; and a destructor to remove dynamic memory.*/

#include<iostream>
#include<cstdlib>
#include <time.h>
using std::cout;
using std::cin;
class password
{
    public:
    password();     //constructor declaration
    ~password();    //destructor declaration
    int print();
    int random_generator();
    int i;
    int reset();
    
    private:
    char* passwrd;
    int length;
};

int password::random_generator()        //method to generate random letters and numbers
{
    char temp = 0;
    length = (rand()%5)+8;
    passwrd = new char[length+1];
    for(i=0;i<length;)
    {
        temp = rand()%124;
        if((temp>=65)  &&  (temp<=91))
        {
           passwrd[i++]=(rand()%26+65);    //function to generate random uppercase letters 
        }
       if((temp>=97)  && (temp<=123) )
       {
       passwrd[i++]=(rand()%26+97);    //function to generate random lowercase letters
       }
       if((temp>=48)  &&  (temp<=57))
       {
       passwrd[i++]=(rand()%10+48);    //function to generate random numbers
       }
    } 
    
    passwrd[length+1]='\0';             //initializes the last slot in the char array to be null
    return 0;
}

password::password()        //constructor definition which generates a random password
{
    srand(time(NULL));      //function to generate a random pulse for the rand()
    random_generator();
    cout<<"\n your constructor is invoked";
    
}

password::~password()       //destructor definition to free the dynamic memory created
{
    cout<<"\n\n your destructor is invoked";
    cout<<"\n\n The previous reset password is:  "<<passwrd;
    delete[] passwrd;
    cout<<"\n\n The password is deleted:  "<<passwrd;
    cout<<"\n Your dynamic memory that was created by the constructor is now free";
}

int password::print()
{
    cout<<"\n\n Your newly generated password is:   ";
    for(i=0; i<=length;i++)
    {
        cout<<passwrd[i];
    }
    
    return 0;
}

int password::reset()       //reset method definition
{
    cout<<"\n\n Your Password is reset:";
    cout<<"\n Your password before resetting is  "<<passwrd;   
    random_generator();
    print();
    return 0;
}

int main()
{
   password p;      //object creation for the class and invoking the default constructor
   p.print();
   p.reset();
   // automatically invoking the destructor before destroying the object created
   return 0;
}