/*Writing a program to read an integer quanity (number of scores) from
 the keyboard, followed by reading this many scores from the keyboard
 into an array. The program should then compute the maximum, minimum, and
 average of the scores.*/


#include<iostream>
using std::cout;
using std::cin;
int main()
{
    int no_of_scores;
    int score_offset;
    float max=-1.0;
    float min=10000000.0;
    float average_score=0;
    
    cout<<"\n Please enter the number of scores that you want to enter:   ";
    cin>>no_of_scores;
    float scores[no_of_scores];
    cout<<"\n Please enter the scores:\n";
    for(score_offset=0;score_offset<no_of_scores;score_offset++)      // loop for entering the scores of the students
    {
        cout<<"\n Please enter the score "<<score_offset+1<<":\t";
        cin>>scores[score_offset];
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
    
    return 0;
}