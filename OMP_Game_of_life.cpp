#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <iomanip>
#define OS_LINUX
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m" 
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0m"
using namespace std;

#define REPEAT 100000
#define ROW 120
#define COLLOM 120

int  Arr2[ROW][COLLOM];
int  Arr1[ROW][COLLOM];

int FOUR_THREAD;
int TWO_THREAD;
int SIX_THREAD;

void Game_of_life(  int x ,int start_x)
{
    int rule_game=0, repeat=0;
    for(int i=start_x;i<x;i++)
    {
        for(int j=0;j<COLLOM;j++)
        {

 
                
            int elemet_x_mass =  i - 1;;
            int elemet_y_mass =  j - 1;; 

            if(elemet_x_mass==-1)
                {
                    elemet_x_mass=ROW-1;
                }
                else
                if(elemet_x_mass==(ROW-1))
                {
                    elemet_x_mass=0;
                }


                if(elemet_y_mass==-1)
                {
                    elemet_y_mass=COLLOM-1;
                }
                else if(elemet_y_mass==(COLLOM-1))
                {
                    elemet_y_mass=0;
                }
         
            for(int k=0;k<3;k++)
            {
                if(elemet_x_mass>=ROW)
                {
                    elemet_x_mass=0;
                }
                elemet_y_mass = j-1;
                for(int m=0;m<3;m++)
                {
                    if(elemet_y_mass==-1)
                    {
                        elemet_y_mass=COLLOM-1;
                    }                
                    if(elemet_y_mass>=COLLOM)
                    {
                        elemet_y_mass=0;
                    }
                    if( Arr1[elemet_x_mass][elemet_y_mass]==1)
                    {
                        rule_game++;
                    }
                    elemet_y_mass++;
                }
                elemet_x_mass++;
                if(rule_game==5)
                {
                    break;
                }
            }

            rule_game= rule_game -  Arr1[i][j];

            if(rule_game==3 || rule_game==2)
            {
                if( Arr1[i][j] == 1)
                {
                    Arr2[i][j]=1;
                }
            }


            if(rule_game==3)
            {
                if( Arr1[i][j] == 0)
                {
                    Arr2[i][j]=1;
                }         
            }

            if(rule_game>3||rule_game<2)
            {   
                Arr2[i][j]=0;
            }
            rule_game=0;
            }

        }    

}

void write_arry2_in_arrat1(int x ,int start_x)
{
    for( int i=start_x;i<x; i++)
        {
            for( int j=0;j<COLLOM;j++)
            {
                Arr1[i][j]=Arr2[i][j];
                //if(Arr1[i][j]==1)
                //{   cout<<COLOR_RED;
                    //cout<<Arr1[i][j]<<"|";
                //}
                //else
                //{
                    //<<COLOR_BLUE;
                    //cout<<Arr1[i][j]<<"|";
                //}
            }
            //cout<<endl;
        }
        //cout<<endl;
}


void add_element_in_array( )
{
    for( int i=0;i<ROW; i++)
    {
        for( int j=0;j<COLLOM;j++)
        {
            Arr1[i][j] = 0 ;
            Arr2[i][j] = 0 ;        
        }
    }
    Arr1[30][7] = 1 ;
    Arr1[30][8] = 1 ;
    Arr1[30][6] = 1 ;
    Arr1[31][7] = 1 ;
    Arr1[29][7] = 1 ;

    Arr1[0][0] = 1 ;
    Arr1[59][0] = 1 ;
    Arr1[59][59] = 1 ;
    Arr1[0][59] = 1 ; 
    

}



void thread_two()
{ 

int repeat=0;
    for(int i=0;i<REPEAT;i++)
    {
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 30,0);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 60 ,30);
        }
        write_arry2_in_arrat1(60, 0);
    }
    cout << COLOR_BLUE;
    cout<<"Second for program with two thread: "<<omp_get_wtime()<<endl; 
}


void thread_four()
{ 

int repeat=0;
    for(int i=0;i<REPEAT;i++)
    {
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 30,0);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 60 ,30);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 90,60);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 120 ,90);
        }
        write_arry2_in_arrat1(120 , 0);
    }
        cout << COLOR_RED;
        cout<<"Second for program with four thread: "<<omp_get_wtime()<<endl; 

}


void thread_six()
{ 
    int time_before_loop_begins = time(NULL);

int repeat=0;

    for(int i=0;i<REPEAT;i++)
    {
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 20,0);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 40 ,20);
        }

        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 60,40);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 80 ,60);
        }

        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 100,80);
        }
        #pragma omp parallel shared(Arr1, Arr2)
        {
        Game_of_life( 120 ,100);
        }

        write_arry2_in_arrat1(120, 0);
    }
  
    //SIX_THREAD= omp_get_wtime();
    cout << COLOR_BLUE;
    cout<<"Second for program with six thread: "<<omp_get_wtime()<<endl; 

    int time_after_loop_ends  = time(NULL);
    cout<<"Second for program with two thread: "<<time_after_loop_ends - time_before_loop_begins <<endl; 
}



int main()
{
    cout << COLOR_GREEN;
    add_element_in_array( );
    for( int i=0;i<ROW; i++)
    {
         for( int j=0;j<COLLOM;j++)
        {
            cout<<Arr1[i][j]<<"|";
        }
         cout<<endl;    
    }
    cout<<endl;

    //thread_two();
     //add_element_in_array( );
    //thread_four();
     //add_element_in_array( );
    thread_six();


    /*cout << COLOR_GREEN;
    for( int i=0;i<ROW; i++)
    {
         for( int j=0;j<COLLOM;j++)
        {
            cout<<Arr1[i][j]<<"|";
        }
         cout<<endl;    
    }
    cout<<endl<<"Theread information"<<endl;*/

    //cout << COLOR_GREEN;
    //cout<<"Second for program with two thread: "<<TWO_THREAD<<endl; 
    //cout << COLOR_RED;
    //cout<<"Second for program with four thread: "<<FOUR_THREAD<<endl; 

return 0;
}
