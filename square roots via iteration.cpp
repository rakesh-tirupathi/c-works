// square roots via iteration

#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::setw;
int main()
{
    float sqrt_no;
    int dec_place;
    double delta=1;
    float error;
    int i=1;
    float j;
    double k;
    int l;
    double m=1;
    cout<<"\n Enter the number for which you want to find the square root:\t";
    cin>>sqrt_no;
    cout<<"\n Enter the number of decimal places for approximation:\t";
    cin>>dec_place;
    cout<<"\n Finding the square root of\t"<<sqrt_no<<"\tto\t"<<dec_place<<"\tdecimal places";
    cout<<"\n-----------------------------------------------------------------------";
    cout<<"\n";
   
    //event control loop to find the next smallest perfect square
    while(i*i<sqrt_no)
    {
        i++;
    }
    cout<<"\n The next largest perfect square is:\t"<<i*i;
    
    //event control loop to find the next largest perfect square
    j=sqrt_no;
    while(sqrt_no<j*j)
    {
        j--;
    }
    cout<<"\n The next smallest perfect square is:\t"<<j*j;
    
    //average of next largest and the next smallest perfect squares
    k=(i+j)/2;
    cout<<"\n The average of the next largest and the next smallest perfect squares is:\t"<<k;
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<setw(10)<<"delta";
    cout<<setw(30)<<"approx sq root";
    cout<<setw(20)<<"error";
    cout<<"\n";
    cout<<setw(10)<<"-----";
    cout<<setw(30)<<"--------------";
    cout<<setw(20)<<"-----";
    cout<<"\n";
    cout<<setprecision(dec_place)<<fixed;
    cout<<"\n"<<setw(35)<<k;
    
    //count control loop to calculate the decimal places and an event control for incrementation and decrementation of the value
    for(l=1;l<=dec_place;l++)   //l++ is used as the decimal position counter
    {
        cout<<"\n";
       delta=delta*(1.0/10.0);            // delta value calculation
                
                while(m<sqrt_no)      // to compare the value of k^2 with the actual number (increment)   
                {
                    k=k+delta;
                    m=k*k;
                    error=sqrt_no-m;
		            cout<<"\n"<<setw(10)<<delta;
	                cout<<setw(25)<<k;
	                cout<<setw(26)<<error;
                }
                
                if(delta!=0.1)
                {
                while(m>sqrt_no)    // to compare the value of k^2 with the actual number (decrement)
                {
                    k=k-delta;
                    m=k*k;
                    error=sqrt_no-m;
                    cout<<"\n"<<setw(10)<<delta;
	                cout<<setw(25)<<k;
	                cout<<setw(26)<<error;
                }
                }
                                        
    }
    cout<<"\n";
    cout<<"\n";
    cout<<"\n The square root of\t"<<sqrt_no<<"\tto\t"<<dec_place<<"\t decimal places is:\t"<<k;
    cout<<"\n";
    cout<<"\n The approximation\t"<<k<<"\tsquared is:\t"<<k*k;
    cout<<"\n";
    cout<<"\n The actual square root of\t"<<sqrt_no<<"\tto\t"<<dec_place+1<<"\tdecimal places is\t"<<setprecision(dec_place+1)<<fixed<<k*k;
    return 0;
}

 
