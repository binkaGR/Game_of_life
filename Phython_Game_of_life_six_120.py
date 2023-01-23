import logging
from re import S
import threading
import time
def game_of_live(arr1, arr2, row, x, x_start):

    rule_game=0
    elemet_x=0 
    elemet_y=0

    for i in range(x_start, x):
        for j in range(row):
            elemet_x = i
            elemet_y = j

            elemet_x = elemet_x - 1
            elemet_y = elemet_y - 1 

            elemet_x_mass = elemet_x
            elemet_y_mass = elemet_y

            if elemet_x_mass==-1:
                elemet_x_mass=row-1
            elif elemet_x_mass==row-1:
                elemet_x_mass=0
            if elemet_y_mass==-1:
                elemet_y_mass=row-1
            elif elemet_y_mass==row-1:
                elemet_y_mass=0
            
            for k in range(3):
                if elemet_x_mass>=row:
                    elemet_x_mass=0
                elemet_y_mass = elemet_y
                for m in range(3):

                    if elemet_y_mass==-1:
                        elemet_y_mass=row-1;            
                    
                    if elemet_y_mass>=row: 
                        elemet_y_mass=0
                
                    if arr1[elemet_x_mass][elemet_y_mass]==1:
                        rule_game = rule_game +1

                    elemet_y_mass=elemet_y_mass+1

                elemet_x_mass=elemet_x_mass+1

            rule_game= rule_game - arr1[i][j]

            if rule_game==3 or rule_game==2:
                if arr1[i][j] == 1:
                
                    arr2[i][j]=1
            if rule_game==3:
                if arr1[i][j] == 0:
                    arr2[i][j]=1
            if rule_game>3 or rule_game<2:
                arr2[i][j]=0
            rule_game=0

def write_resulr(arr3, arr4, row):
    for i in range(row):
        for j in range(row):
            arr3[i][j]=arr4[i][j]

from array import *
from ast import Dict
i=0
j=0
row = 120
arr_1 =[
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row ]
arr_2 =[
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,
    [0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row, [0]*row, [0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row,[0]*row ]

arr_1[7][7] = 1
arr_1[7][8] = 1
arr_1[7][6] = 1
arr_1[8][7] = 1
arr_1[6][7] = 1

arr_1[0][0] = 1
arr_1[19][0] = 1
arr_1[19][19] = 1
    

format = "%(asctime)s: %(message)s"

for r in arr_1:
   for c in r:
      print(c,end = " ")
   print()
pov=0
volue_ex=0
while pov<100000:
    tread1=threading.Thread(target=game_of_live, args=(arr_1, arr_2, row , 0, 20))
    tread3=threading.Thread(target=game_of_live, args=(arr_1, arr_2, row , 20, 40))
    tread4=threading.Thread(target=game_of_live, args=(arr_1, arr_2, row , 40, 60))
    tread5=threading.Thread(target=game_of_live, args=(arr_1, arr_2, row , 60, 80))
    tread6=threading.Thread(target=game_of_live, args=(arr_1, arr_2, row , 80, 100))
    tread7=threading.Thread(target=game_of_live, args=(arr_1, arr_2, row , 100, 120))
    tread1.start()
    tread3.start()
    tread4.start()
    tread5.start()
    tread6.start()
    tread7.start()
    volue_ex=time.thread_time()



    pov+=1
    tread2=threading.Thread(target=write_resulr, args=(arr_1, arr_2, 120 ))
    tread2.start()


for r in arr_1:
   for c in r:
      print(c,end = " ")
   print()
print()
print(volue_ex)
#d=""
#input(d)