/* Modify the previous program so that calculations for max, min and
 average are performed by functions. The linear search and bubble sort
 should also be performed by functions.*/

#include<iostream>
#include<fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
ofstream outfile;


int max_value(float scores[], int no_of_scores)   //function to calculate max value
{
    int score_offset;
    float max=-1.0;
  for(score_offset=0;score_offset<no_of_scores;score_offset++)   //loop for calculating the maximum score out of all the scores entered
    {
        if(max<scores[score_offset])   //condition to compare and check wether the score is maximum
        {
            max=scores[score_offset];  //if the score is maximum then it stores it in a max variable
        }
    }       //end of for loop
    outfile<<"\n The maximum of the entered scores are:\t"<<max;
    cout<<"\n The maximum of the entered scores are:\t"<<max;
}

int min_value(float scores[], int no_of_scores)   //function to calculate min value
{
    int score_offset;
    float min=10000000.0;
  for(score_offset=0;score_offset<no_of_scores;score_offset++)  //loop for calculating the minimum score out of all the scores entered
    {
        if(min>scores[score_offset])   //condition to compare and check wether the score is minimum
        {
            min=scores[score_offset];  //if the score is min then it stores it in a min variable  
        }
    }       //end of for loop
    outfile<<"\n The minimum of the entered scores are:\t"<<min;  
    cout<<"\n The minimum of the entered scores are:\t"<<min;  
}

int avg_value(float scores[], int no_of_scores)   //function to calculate avg value
{
    int score_offset;
    float average_score=0;
  for(score_offset=0;score_offset<no_of_scores;score_offset++)  //loop for calculating the average of all the scores entered
    {
        average_score=average_score+scores[score_offset];  //formula for adding all the scores entered
    }       //end of for loop
    
    average_score=average_score/no_of_scores;     //formula for calculating the average of scores entered
        
    outfile<<"\n The average score of "<<no_of_scores<<" students is: "<<average_score;  
    cout<<"\n The average score of "<<no_of_scores<<" students is: "<<average_score;  
}

int search(float scores[], int no_of_scores)      //function for searching a particular number in the entered scores
{
    float search_score;
    cout<<"\n\n Please enter the score that you want to search for: ";
    cin>>search_score;
    cout<<"\n you have entered the score "<<search_score<<" to search in the given set of scores";
    outfile<<"\n you have entered the score "<<search_score<<" to search in the given set of scores";
    
        bool score_found=false;
        bool end_of_scores=true;
        int score_offset=0;

        while(end_of_scores && (!score_found))  //event control loop for linear searching of a particular number in an array
    {
    
        if(scores[score_offset]==search_score) //condition to check whether the score has been found
        {
            cout<<"\n The score "<<search_score<<" is in "<<score_offset+1;
            outfile<<"\n The score "<<search_score<<" is in "<<score_offset+1;
            score_found=true;
        }
        else if ((score_offset+1)==no_of_scores)   // condition to check whether the score entered is in the array
        {
            cout<<"\n Sorry the score entered "<<search_score<<" is not found. Please enter a valid score that is present";
            outfile<<"\n Sorry the score entered "<<search_score<<" is not found. Please enter a valid score that is present";
            end_of_scores=false;
        }
        score_offset++;
    }   // end of while loop
}

int sort(float scores[], int no_of_scores)    // condition for bubble sorting of the entered scores
{
    int score_offset;
    int sink_index=0;
    bool swap_occured;
    do
    {
        swap_occured=false;
        for(int pair_index=0;pair_index<=(no_of_scores-2-sink_index);pair_index++)    //loop for comparing two elements in an array during a single traversal
        {
            if(scores[pair_index]<scores[pair_index+1])
            {
                float temp=scores[pair_index];
                scores[pair_index]=scores[pair_index+1];
                scores[pair_index+1]=temp;
                swap_occured=true;
            }
        }
        sink_index++;
    }while(swap_occured);       //end of do-while loop
    
    cout<<"\n\nThe sorted order of the scores entered are:\n";
    outfile<<"\n\nThe sorted order of the scores entered are:\n";
    for(score_offset=0;score_offset<no_of_scores;score_offset++)      //loop for displaying the sorted entered scores
    {
        cout<<scores[score_offset];
        outfile<<scores[score_offset];
        cout<<"\n";
        outfile<<"\n";
    }       //end of for loop
}

int main()
{
    ifstream infile;
    infile.open("scores3.txt");
    //ofstream outfile;
    outfile.open("functionresults.txt");
    if(infile)
    {
        int no_of_scores;
        int score_offset;
        infile>>no_of_scores;
        float scores[no_of_scores];
        for(score_offset=0;score_offset<no_of_scores;score_offset++)      // loop for entering the scores of the students
        {
            infile>>scores[score_offset];
        }       //end of for loop
        cout<<"\n The entered scores are\n";
        outfile<<"\n The entered scores are\n";
        for(score_offset=0;score_offset<no_of_scores;score_offset++)      //loop for displaying the entered scores
        {
            cout<<"\n The entered score "<<score_offset+1<<" is: ";
            cout<<scores[score_offset];
            cout<<"\n";
            outfile<<"\n The entered score "<<score_offset+1<<" is: ";
            outfile<<scores[score_offset];
            outfile<<"\n";
        }       //end of for loop
        
        max_value(scores, no_of_scores);  //function call to find the min value
        min_value(scores, no_of_scores);  //function call to find the max value
        avg_value(scores, no_of_scores);  //function call to find the avg value
        search(scores, no_of_scores);     //function call to execute linear search
        sort(scores, no_of_scores);       //function call to execute bubble sort
        infile.close();
    }
    else
    {
        cout<<"\nFile not found. Please enter a valid file name";
    }
    outfile.close();
    
    return 0;
}
