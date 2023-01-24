#include <iostream>
#include <iomanip>
#include <thread>
#include <pthread.h>
#include <mutex>
#include <chrono>  
#include <ctime>
#include <iomanip>
#include <fstream>
//#include <stdio.h>
//#include <stdlib.h>
using namespace std;

#define REPEAT 120
#define ROW 120
#define COLLOM 120

#define OS_LINUX
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m" 
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0"


int  Arr2[ROW][COLLOM];
int  Arr1[ROW][COLLOM];




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

void add_element_in_array(string name )
{
    string a;
    fstream file;
    file.open (name, std::fstream::in);
    if(file.is_open())
    {

        for( int i=0;i<ROW; i++)
        {
            for( int j=0;j<COLLOM;j++)
            {
                file>>Arr1[i][j];
                if(Arr1[i][j]==1)
                {
                cout<<COLOR_RED;
                cout<<Arr1[i][j]<<"|";
                }
                else
                {
                    cout<<COLOR_BLUE;
                    cout<<Arr1[i][j]<<"|";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    file.close();  
    cout<<"To start a Game insert Enter"<<endl;
    cin>>a;

}

void write_arry2_in_arrat1(int x ,int start_x)
{
        for( int i=start_x;i<x; i++)
        {
            for( int j=0;j<COLLOM;j++)
            {
                Arr1[i][j]=Arr2[i][j];
                if(Arr1[i][j]==1)
                {
                cout<<COLOR_RED;
                cout<<Arr1[i][j]<<"|";
                }
                else
                {
                    cout<<COLOR_BLUE;
                    cout<<Arr1[i][j]<<"|";
                }
            }
            cout<<endl;
        }
        cout<<endl;
}

void thread_two()
{ 
    int repeat = 0;
    int time_before_loop_begins = time(NULL);

    while (1)
    {
        std::thread first (Game_of_life,  60, 0); 
        std::thread second (Game_of_life,  120, 60);

        first.join();
        second.join();


        write_arry2_in_arrat1(120, 0); 
        
        repeat++;
        if(repeat==REPEAT)
        {
            break;
        }
        //pthread_cancel(first, 1);
        
    }
     cout<<COLOR_BLUE;
    int time_after_loop_ends  = time(NULL);
    cout<<"Second for program with two thread: "<<time_after_loop_ends - time_before_loop_begins <<endl; 
}

void thread_four()
{
    int repeat = 0;
    int time_before_loop_begins = time(NULL);
    while (1)
    {
    std::thread first (Game_of_life,  30, 0); 
    std::thread second (Game_of_life,  60, 30); 
    std::thread tree (Game_of_life,  90, 60); 
    std::thread four (Game_of_life,  120, 90); 
    four.join();
    tree.join();
    second.join();
    first.join();
        
    write_arry2_in_arrat1(120, 0);
        repeat++;
        if(repeat==REPEAT)
        {
            break;
        }
    }
    cout<<COLOR_BLUE;
    int time_after_loop_ends  = time(NULL);
    cout<<"Second for program with four thread: "<<time_after_loop_ends - time_before_loop_begins <<endl; 

}

void thread_six()
{
    int repeat=0;
    int time_before_loop_begins = time(NULL);

    while(1)
    {
        std::thread first (Game_of_life,  20, 0); 
        std::thread second (Game_of_life,  40, 20); 
        std::thread tree (Game_of_life,  60, 40); 
        std::thread four (Game_of_life,  80, 60); 
        std::thread five (Game_of_life,  100, 80); 
        std::thread six (Game_of_life,  120, 100); 
        first.join();
        second.join();
        tree.join(); 
        six.join();
        five.join();
        four.join();

        write_arry2_in_arrat1(120, 0);

        repeat++;
        if(repeat==REPEAT)
        {
            break;
        }
    }    
    cout<<COLOR_BLUE;    
    int time_after_loop_ends  = time(NULL);
    cout<<"Second for program with six thread: "<<time_after_loop_ends - time_before_loop_begins <<endl; 

}


int main()
{
    string name;
while(true)
{    cout<<COLOR_GREEN;
    int chose_model_GoL, number_of_thread;
    cout<<"Hello please enter number of model Game of life"<<endl;
    cout<<"1. Two line"<<endl;
    cout<<"2. Two Ocvilator + Block"<<endl;
    cout<<"3. Boat"<<endl;
    cout<<"4. R_pentonim"<<endl;
    cout<<"If you want to exist the program chose 0"<<endl;
    cout<<"Insert number"<<endl;
    cin>>chose_model_GoL;

    cout<<"Please inset number of thread 2, 4 or 6"<<endl;
    cout<<"If you want to exist the program chose 0"<<endl;
    cout<<"Insert number"<<endl;
    cin>>number_of_thread;


    switch (chose_model_GoL)
    {
    case 0:
    {
        cout<<"Proggram compliet"<<endl; 
        return 0;
    }
        break;
    case 1: 
        {   
            name="two_line.txt";
            switch (number_of_thread)
            {
            case 0:
                {
                    cout<<"Proggram compliet"<<endl; 
                    return 0;
                }
                break;
            case 2:
                {
                        add_element_in_array(name);
                        thread_two();
                }
                break;
            case 4:
                {
                        add_element_in_array(name);
                        thread_four();
                }
                break;
            case 6:
                {
                        add_element_in_array(name);
                        thread_six();
                }
                break;
            default:
                {
                    cout<<COLOR_RED;
                    cout<<"Nuber of thread in not true.Nuber of thread 2, 4 or 6! Please try again"<<endl;

                }
                break;
            } 
        }
        break;
    case 2: 
        {   
            name="Ocvilator_block.txt";
            switch (number_of_thread)
            {
            case 0:
                {
                    cout<<"Proggram compliet"<<endl; 
                    return 0;
                }
            case 2:
                {
                        add_element_in_array(name);
                        thread_two();
                }
                break;
            case 4:
                {
                        add_element_in_array(name);
                        thread_four();
                }
                break;
            case 6:
                {
                        add_element_in_array(name);
                        thread_six();
                }
            default:
                {
                    cout<<COLOR_RED;
                    cout<<"Nuber of thread in not true.Nuber of thread 2, 4 or 6! Please try again"<<endl;

                }
                break;
            } 
        }
        break;
    case 3: 
        {   name="Boat.txt";
            switch (number_of_thread)
            {
            case 0:
                {
                    cout<<"Proggram compliet"<<endl; 
                    return 0;
                }
            case 2:
                {
                        add_element_in_array(name);
                        thread_two();
                }
                break;
            case 4:
                {
                        add_element_in_array(name);
                        thread_four();
                }
                break;
            case 6:
                {
                        add_element_in_array(name);
                        thread_six();
                }
            default:
                {
                    cout<<COLOR_RED;
                    cout<<"Nuber of thread in not true.Nuber of thread 2, 4 or 6! Please try again"<<endl;

                }
                break;
            } 
        }
        break;
    case 4: 
        {   
            name="R_pentonim.txt";
            switch (number_of_thread)
            {
            case 0:
                {
                    cout<<"Proggram compliet"<<endl; 
                    return 0;
                }
            case 2:
                {
                        add_element_in_array(name);
                        thread_two();
                }
                break;
            case 4:
                {
                        add_element_in_array(name);
                        thread_four();
                }
                break;
            case 6:
                {
                        add_element_in_array(name);
                        thread_six();
                }
            default:
                {
                    cout<<COLOR_RED;
                    cout<<"Nuber of thread in not true.Nuber of thread 2, 4 or 6! Please try again"<<endl;
                }
                break;
            } 
        }
        break;
    default:
        break;
    }
}

return 0;
}