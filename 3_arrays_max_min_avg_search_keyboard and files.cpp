/*Modifing the previous program 2 so that it also prompts the user for
 a score to search for with a linear search and then displays
 either the location within the array of the score or a "not found" message.*/

#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::ifstream;
int main()
{
    int no_of_scores;
    int score_offset;
    float max=-1.0;
    float min=10000000.0;
    float average_score=0;
    float search_score;
           
        ifstream infile;    //defining an input file
        infile.open("scores1.txt");    //binding the logical file to the physical file
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
            
            // code for searching a particular number in the entered scores
            cout<<"\n Please enter the score that you want to search for";
            cin>>search_score; 
            cout<<"\n you have entered the score "<<search_score<<" to search in the given set of scores";
            
            // outputing the output to a file
            ofstream outfile;       //define the file that you want to output (Step_1)
            outfile.open("results1.txt");       //binding the logical file to the physical file(step_2)
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
            outfile<<"\n you have entered the score "<<search_score<<" to search in the given set of scores";
                
            bool score_found=false;
            bool end_of_scores=true;
            score_offset=0;
            while(end_of_scores && (!score_found))  //event control loop for linear searching of a particular number in an array
            {
                
                if(scores[score_offset]==search_score) //condition to check whether the score has been found
                {
                    cout<<"\n The score "<<search_score<<" is in "<<score_offset+1;
                    outfile<<"\n The score "<<search_score<<" is in "<<score_offset+1;
                    score_found=true;
                }
                else if ((score_offset+1)==no_of_scores)   // condition to check wether the score entered is in the array
                {
                    cout<<"\n Sorry the score entered "<<search_score<<" is not found. Please enter a valid score that is present";    
                    outfile<<"\n Sorry the score entered "<<search_score<<" is not found. Please enter a valid score that is present";
                    end_of_scores=false;
                }
                score_offset++;
            }   // end of while loop
            infile.close();     // releasing the binding between the logical and the physical files
            outfile.close();     // releasing the binding between the logical and the physical files        
        }
        else
        {
            cout<<"\n File not found. Please enter a valid file name.";
            cout<<"\n Thank you";
        }
    
                
    return 0;
}
