/*Modifying the 5 so that it first reads two integers from the file "2d scores.txt",
 the number of students in a class and the number of tests taken so far, e.g. 20 and 3. The program would
 then read a total of 60 scores into a 100 x 10 2D array. Calculate the max, min and average for each test,
 the average for each student's scores, and then bubble sort the data by student average in descending order.*/

#include<iostream>
#include<fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;

int main()
{
    int no_of_students;
    int tests_taken;
    int rows;
    int columns;
    int score_offset;
    ifstream infile;
    ofstream outfile;
    infile.open("2dscores.txt");
    outfile.open("2dresults.txt");
    if(infile)
    {
        infile>>no_of_students;
        infile>>tests_taken;
        float scores[no_of_students][tests_taken];
        cout<<"\n Please enter the scores of the students";
        
        for(rows=0;rows<no_of_students;rows++)      //for loop for entering the no of rows
        {
            for(columns=0;columns<tests_taken;columns++)    //for loop for entering the no of columns
            {
                infile>>scores[rows][columns];
            }
        }
        
        for(rows=0;rows<no_of_students;rows++)      //for loop for displaying the no of rows
        {
            cout<<"\n The student "<<rows+1<<" scores are:\t";
            outfile<<"\n The student "<<rows+1<<" scores are:\t";
            for(columns=0;columns<tests_taken;columns++)    //for loop for displaying the no of columns
            {
                cout<<scores[rows][columns];
                outfile<<scores[rows][columns];
                cout<<"\t";
                outfile<<"\t";
            }
            cout<<"\n";
            outfile<<"\n";
        }
        
        //for loop for calculating the maximum score and minimum of each student
        float max=-1.0;
        float min=10000000.0;
        for(rows=0;rows<no_of_students;rows++)  
        {
            max=-1.0;
            min=10000000.0;
            for(columns=0;columns<tests_taken;columns++)
            {
                if(max<scores[rows][columns])   //condition to compare and check whether the score is maximum
                {
                    max=scores[rows][columns];  //if the score is maximum then it stores it in a max variable
                }
                if(min>scores[rows][columns])   //condition to compare and check whether the score is minimum
                {
                    min=scores[rows][columns];  //if the score is minimum then it stores it in a min variable
                }
              
            }
            cout<<"\n The maximum of the entered scores of student"<<rows+1<<" is: "<<max;
            cout<<"\n The minimum of the entered scores of student"<<rows+1<<" is: "<<min<<"\n";
            outfile<<"\n The maximum of the entered scores of student"<<rows+1<<" is: "<<max;
            outfile<<"\n The minimum of the entered scores of student"<<rows+1<<" is: "<<min<<"\n";
        }       //end of for loop
        
       //for loop for calculating the average score of each student
        float average_score=0;
        float average[no_of_students];
        
        for(rows=0;rows<no_of_students;rows++)  //loop for calculating the average of all the scores entered in a row
        {
            for(columns=0;columns<tests_taken;columns++)
            {
        
                {
                    average_score=average_score+scores[rows][columns];  //formula for adding all the scores entered
                }
            }
            average_score=average_score/tests_taken;     //formula for calculating the average of scores entered
            cout<<"\n The average score of entered scores of student" <<rows+1<<" is: "<<average_score<<"\n";
            outfile<<"\n The average score of entered scores of student" <<rows+1<<" is: "<<average_score<<"\n";
            average[rows]=average_score;
            average_score=0;
        }       //end of for loop
        
        //printing the average values of the students
        
        for(rows=0;rows<no_of_students;rows++)  //loop for displaying the student average
        {
            cout<<"\n The average score of student "<<rows+1<<" is:\t"<<average[rows]<<"\n";
            outfile<<"\n The average score of student "<<rows+1<<" is:\t"<<average[rows]<<"\n";
        }
        
        //for loop for calculating the maximum score and minimum for each test
         max=-1.0;
         min=10000000.0;
        for(rows=0;rows<no_of_students;rows++)  
        {
            max=-1.0;
            min=10000000.0;
            for(columns=0;columns<tests_taken;columns++)
            {
                if(max<scores[columns][rows])   //condition to compare and check whether the score is maximum
                {
                    max=scores[columns][rows];  //if the score is maximum then it stores it in a max variable
                }
                if(min>scores[columns][rows])   //condition to compare and check whether the score is minimum
                {
                    min=scores[columns][rows];  //if the score is minimum then it stores it in a min variable
                }
              
            }
            cout<<"\n The maximum of the entered scores of the test"<<rows+1<<" is: "<<max;
            cout<<"\n The minimum of the entered scores of the test"<<rows+1<<" is: "<<min<<"\n";
            outfile<<"\n The maximum of the entered scores of the test"<<rows+1<<" is: "<<max;
            outfile<<"\n The minimum of the entered scores of the test"<<rows+1<<" is: "<<min<<"\n";
        }       //end of for loop
        
         //for loop for calculating the average score of each test
        average_score=0;
        float average_test[no_of_students];
        
        for(rows=0;rows<no_of_students;rows++)  //loop for calculating the average of all the scores entered in a row
        {
            for(columns=0;columns<tests_taken;columns++)
            {
        
                {
                    average_score=average_score+scores[columns][rows];  //formula for adding all the scores entered
                }
            }
            average_score=average_score/tests_taken;     //formula for calculating the average of scores entered
            cout<<"\n The average score of entered scores of test" <<rows+1<<" is: "<<average_score<<"\n";
            outfile<<"\n The average score of entered scores of test" <<rows+1<<" is: "<<average_score<<"\n";
            average_test[rows]=average_score;
            average_score=0;
        }       //end of for loop
        
        //printing the average values of the tests taken
        
        for(rows=0;rows<no_of_students;rows++)  //loop for displaying the test average
        {
            cout<<"\n The average score of test "<<rows+1<<" is:\t"<<average_test[rows]<<"\n";
            outfile<<"\n The average score of test "<<rows+1<<" is:\t"<<average_test[rows]<<"\n";
        }
        
        
        //bubble sorting the average scores of students
        int sink_index=0;
        int pair_index;
        bool swap_occured;
        do
        {
            swap_occured=false;
            for(int pair_index=0;pair_index<=(rows-2-sink_index);pair_index++)    //loop for comparing two elements in an array during a single traversal
            {
                if(average[pair_index]<average[pair_index+1])
                {
                    float temp=average[pair_index];
                    average[pair_index]=average[pair_index+1];
                    average[pair_index+1]=temp;
                    swap_occured=true;
                }
            }
            sink_index++;
        }while(swap_occured);       //end of do-while loop
        
        cout<<"\n\nThe sorted order of the average scores of students entered are:\n";
        outfile<<"\n\nThe sorted order of the average scores of students entered are:\n";
        
        for(int score_offset=0;score_offset<no_of_students;score_offset++)      //loop for displaying the sorted average scores of students
        {
            cout<<average[score_offset];
            cout<<"\n";
            outfile<<average[score_offset];
            outfile<<"\n";
        }       //end of for loop
        
        //bubble sorting the average scores of tests taken
        sink_index=0;
        pair_index;
        swap_occured;
        do
        {
            swap_occured=false;
            for(int pair_index=0;pair_index<=(rows-2-sink_index);pair_index++)    //loop for comparing two elements in an array during a single traversal
            {
                if(average_test[pair_index]<average_test[pair_index+1])
                {
                    float temp=average_test[pair_index];
                    average_test[pair_index]=average_test[pair_index+1];
                    average_test[pair_index+1]=temp;
                    swap_occured=true;
                }
            }
            sink_index++;
        }while(swap_occured);       //end of do-while loop
        
        cout<<"\n\nThe sorted order of the average scores of tests taken are:\n";
        outfile<<"\n\nThe sorted order of the average scores of tests taken are:\n";
        
        for(int score_offset=0;score_offset<no_of_students;score_offset++)      //loop for displaying the sorted average scores of students
        {
            cout<<average_test[score_offset];
            cout<<"\n";
            outfile<<average_test[score_offset];
            outfile<<"\n";
        }       //end of for loop
        
        infile.close();
    }
    else
    {
        cout<<"\n File does not exist. Please enter a valid file name";
     
    }
    outfile.close();
    return 0;
}