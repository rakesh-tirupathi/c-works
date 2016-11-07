/*Modifying the 1 program so that it reads the quantity
 and scores from a file "scores.txt" and writes the max, min and average
 to "results.txt".*/

#include<iostream>
#include<fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
int main()
{
    int no_of_scores;
    int score_offset;
    float max=-1.0;
    float min=10000000.0;
    float average_score=0;
    
    ifstream infile;    //defining an input file
    infile.open("scores.txt");    //binding the logical file to the physical file
    if(infile)
    {
        
        infile>>no_of_scores;     //using the file
        float scores[no_of_scores];
        
        for(score_offset=0;score_offset<no_of_scores;score_offset++)      // loop for entering the scores
        {
            infile>>scores[score_offset];   //using the file
        }       //end of for loop
        cout<<"\n The entered scores are\n";
        for(score_offset=0;score_offset<no_of_scores;score_offset++)      //loop for displaying the entered scores
        {
            cout<<"\n The entered score "<<score_offset+1<<" is: ";
            cout<<scores[score_offset];
            cout<<"\n";
        }       //end of for loop
        
        for(score_offset=0;score_offset<no_of_scores;score_offset++)   //loop for calculating the maximum score out of all the scores entered
        {
            if(max<scores[score_offset])   //condition to compare and check wether the score is maximum
            {
                max=scores[score_offset];  //if the score is maximum then it stores it in a max variable
            }
        }       //end of for loop
        cout<<"\n The maximum of the entered scores are:\t"<<max;
        
        for(score_offset=0;score_offset<no_of_scores;score_offset++)  //loop for calculating the minimum score out of all the scores entered
        {
            if(min>scores[score_offset])   //condition to compare and check wether the score is minimum
            {
                min=scores[score_offset];  //if the score is min then it stores it in a min variable  
            }
        }       //end of for loop
        cout<<"\n The minimum of the entered scores are:\t"<<min;
        
        for(score_offset=0;score_offset<no_of_scores;score_offset++)  //loop for calculating the average of all the scores entered
        {
            average_score=average_score+scores[score_offset];  //formula for adding all the scores entered
        }       //end of for loop
        
        average_score=average_score/no_of_scores;     //formula for calculating the average of scores entered
            
        cout<<"\n The average score of "<<no_of_scores<<" entered scores is: "<<average_score;
        
        infile.close();     // releasing the binding between the logical and the physical files
        
        // outputing the output to a file        
    
        ofstream outfile;       //define the file that you want to output (Step_1)
        outfile.open("results.txt");       //binding the logical file to the physical file(step_2)
        outfile<<"\n The entered scores are\n";
        for(score_offset=0;score_offset<no_of_scores;score_offset++)      //loop for displaying the entered scores
        {
            outfile<<"\n The entered score "<<score_offset+1<<" is: ";
            outfile<<scores[score_offset];
            outfile<<"\n";
        }       //end of for loop
        
        outfile<<"\n The maximum of the entered scores are:\t"<<max<<"\n";
        outfile<<"\n The minimum of the entered scores are:\t"<<min<<"\n";
        outfile<<"\n The average score of "<<no_of_scores<<" entered scores is: "<<average_score;
        outfile.close();     // releasing the binding between the logical and the physical files
        
    }
    else
    {
        cout<<"\n File not found. Please enter a valid file name.";
        cout<<"\n Thank you";
    }  
    return 0;
} 