/*Creating the fraction class and including methods to add, subtract,
 multiply and divide with integers and other fractions using constructors.*/

#include<iostream>
using std::cout;
using std::cin;

class fraction
{
    public:
    fraction(int, int);     //parameterized constructor declaration
    int numerator;
    int denominator;
    int i,j,deno,nume;
    /*//method declarations to perform operations on integers
    fraction add(int);      
    fraction subtract(int);
    fraction multiply(int);
    fraction divide(int);*/
    //method declarations to perform operations on fractions
    fraction add(int,int);      
    fraction subtract(int,int);
    fraction multiply(int,int);
    fraction divide(int,int);
    int print();
    int print_input_fraction();
    int input();
    int user_input();
    //int input_fraction();
};

int main()
{
    int numerator, denominator;
    cout<<"\n Please enter the numerator:  ";
    cin>>numerator;
    cout<<"\n Please enter the denominator:  ";
    cin>>denominator;
    fraction f1(numerator,denominator);     //invoking the parameterized constructor
    f1.print();
    cout<<"\n";
    f1.input();
    return 0;
}

int fraction::print()
{
    cout<<"\n The fraction is:  ";
    cout<<numerator;
    cout<<"/";
    cout<<denominator;
    cout<<"\n";
    return 0;
}

int fraction::print_input_fraction()
{
    cout<<"\n the Entered fraction is:   ";
    cout<<i;
    cout<<"/";
    cout<<j;
    return 0;  
}

int fraction::input()   //input method definition
{
    cout<<"\n";
    cout<<"\n Please enter the fraction that you want to add with the initial fraction: ";
    user_input();
    fraction t = add(i,j);    //storing the value of add in an temp object t and calling the add method
    t.print();
    cout<<"\n Please enter the fraction that you want to subtract with the initial fraction: ";
    user_input();
    t = subtract(i,j);        //calling the subtract method and storing it in a temp object t
    t.print();
    cout<<"\n Please enter the fraction that you want to multiply with the initial fraction: ";
    user_input();
    t = multiply(i,j);        //calling the multiply method and storing it in a temp object t
    t.print();
    cout<<"\n Please enter the fraction that you want to divide with the initial fraction: ";
    user_input();
    t = divide(i,j);      //calling the divide method and storing it in a temp object t
    t.print();
    return 0;
}

int fraction::user_input()      //method for inputing the fraction from the user
{
   cout<<"\n Enter numerator:  ";
    cin>>i;
    cout<<"\n Enter denominator: ";
    cin>>j;
    print_input_fraction();
    cout<<"\n";
}

fraction::fraction(int n, int d)        //parameterized constructor definition
{
    numerator=n;
    denominator=d;
    //cout<<"\n\n The parameterized constructor is invoked";
}

fraction fraction::add(int,int)     //add method definition to add a fraction
{
    int deno=denominator*i;
    int nume= j*numerator;
    int d=denominator*j;
    int n= nume+deno;
    return fraction(n,d);               //returning the value to the parameterized constructor
}

fraction fraction::subtract(int,int)        //subtract method definition to subtract a fraction
{
    int deno=denominator*i;
    int nume= j*numerator;
    int d=denominator*j;
    int n= nume-deno;
    return fraction(n,d);               //returning the value to the parameterized constructor
}

fraction fraction::multiply(int,int)        //multiply method definition to multiply a fraction
{
    int d=denominator*j;
    int n= numerator*i;
    return fraction(n,d);           //returning the value to the parameterized constructor
}

fraction fraction::divide(int,int)      //divide method definition to divide a fraction
{
    int d=denominator*i;
    int n= numerator*j;
    return fraction(n,d);       //returning the value to the parameterized constructor
}
    
    