#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define ROW 120
#define COLLOM 120


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



int main()
{
    int arr1[ROW][COLLOM], arr2[ROW][COLLOM];    
    for( int i=0;i<ROW; i++)
    {
        for( int j=0;j<COLLOM;j++)
        {
            arr1[i][j] = 0 ;
        }
    }

    arr1[60][60] = 1 ;
    arr1[61][60] = 1 ;
    arr1[60][61] = 1 ;
    arr1[61][62] = 1 ;
    arr1[62][61] = 1 ;

    



    /*for( int j=0;j<COLLOM;j++)
    {
        arr1[20][j] = 1 ;
    }

    for( int j=0;j<COLLOM;j++)
    {
        arr1[22][j] = 1 ;
    }*/



    fstream create_file;
    create_file.open ("Boat.txt",  std::fstream::out);
    if(create_file.is_open())
    {

        for( int i=0;i<ROW; i++)
        {
            for( int j=0;j<COLLOM;j++)
            {
            create_file<<arr1[i][j];
            create_file<<endl;
            }
        }
    }
    create_file.close();
    cout<<"Arr 1"<<endl;
    for( int i=0;i<ROW; i++)
    {
         for( int j=0;j<COLLOM;j++)
        {
            cout<<arr1[i][j]<<"|";
        }
         cout<<endl;    
    }
    cout<<endl;



    create_file.open ("Boat.txt", std::fstream::in);
    if(create_file.is_open())
    {

        for( int i=0;i<ROW; i++)
        {
            for( int j=0;j<COLLOM;j++)
            {
            create_file>>arr2[i][j];
            //create_file<<endl;
            }
        }
    }
    create_file.close();

    cout<<"Arr 2"<<endl;
    for( int i=0;i<ROW; i++)
    {
         for( int j=0;j<COLLOM;j++)
        {
            cout<<arr2[i][j]<<"|";
        }
         cout<<endl;    
    }
    cout<<endl;


return 0;

}