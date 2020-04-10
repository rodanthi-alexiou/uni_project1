#include "life.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int compare_x(Pointer a, Pointer b){
    LifeCell* pA = a;
    LifeCell* pB = b;
    int yA = pA->y;
    int yB = pB->y;
    int xA = pA->x;
    int xB = pB->x;
    if((yB - yA) == 0){
        return xA - xB;
    }
    else
    return yA - yB;
}



// Δημιουργεί μια κατάσταση του παιχνιδιού όπου όλα τα κελιά είναι νεκρά.
LifeState life_create(){
    LifeState state = set_create(compare_x,NULL);

    return state;
}

// Δημιουργεί μία κατάσταση του παιχνιδιού με βάση τα δεδομένα του αρχείο file (RLE format)
LifeState life_create_from_rle(char* file){
        
    LifeState state = set_create(compare_x,NULL);

char* FILE = strdup(file);
char* token, *o_line;
char* saved, *rest;
char* ch;
int  b_value, o_value, lx, ly=0;
LifeCell* cell;

for(token = strtok_r(FILE, "$!", &saved); token!= NULL; token =strtok_r(NULL, "$!", &saved)){

       lx=0;

    for (o_line = strtok_r(token, "o", &rest); o_line != NULL; o_line = strtok_r(NULL, "o", &rest)){
    b_value=0;

       if(strchr(o_line, 'b') != NULL){
           b_value=atoi(o_line);

        ch = strchr(o_line, 'b');
        ch++;
        o_value=atoi(ch);

        if(b_value==0)
            b_value=1;

       }
       else{
           o_value= atoi(o_line);
       }

lx+=b_value;


if(o_value == 0)
        o_value=1;


    for(int i=0; i<o_value; i++){
        cell=malloc(sizeof(LifeCell));
       cell->x= lx;
        cell->y=ly;
        set_insert(state,cell);
        lx++;
       }
        
    }

    ly++;
}
//for(SetNode node=set_first(state); node!= SET_EOF; node = set_next(state,node)){
 //     LifeCell* yes = set_node_value(state,node);
//    printf("NEW x: %d and y: %d \n", yes->x, yes->y);
//}
 return state;
}

// Αποθηκεύει την κατάσταση state στο αρχείο file (RLE format)
void life_save_to_rle(LifeState state, char* file){
//SetNode node = set_last(state);
//LifeCell* last = set_node_value(state,node);
//int size = last->y;

//        for(int i=0; i<size; i++){

  //      }
        
}

// Επιστρέφει την τιμή του κελιού cell στην κατάσταση state (true: ζωντανό, false: νεκρό)
bool life_get_cell(LifeState state, LifeCell cell){

    LifeCell* new= malloc(sizeof(LifeCell));
    new->x=cell.x;
    new->y=cell.y;
    if(set_find(state,new) != NULL)
    return true;

    else{
        return false;
    }
}

// Αλλάζει την τιμή του κελιού cell στην κατάσταση state
void life_set_cell(LifeState state, LifeCell cell, bool value){
    LifeCell* new = malloc(sizeof(LifeCell));
    new->x=cell.x;
    new->y=cell.y;
    if(value==false){
        set_remove(state,new);
    }
    else{
        set_insert(state,new);
    }

}

// Παράγει μια νέα κατάσταση που προκύπτει από την εξέλιξη της κατάστασης state
LifeState life_evolve(LifeState state){

int alive=0;

    LifeCell new;
     
        for(int y_value=ly-1; y_value<=ly+1; y_value++){
           for(int x_value=lx-1; x_value<=lx+1; x_value++){
               new.x=x_value;
                new.y=y_value;
                if(life_get_at(state,new) == true){
                   alive++;
                }
                else{
                    life_set_cell(state,new,true);
                    life_evolve(state);
                }
            
            }
        }
if(alive>2 || alive<3){
    life_set_cell(state,new,false);
}

    return state;
}

// Καταστρέφει την κατάσταση ελευθερώντας οποιαδήποτε μνήμη έχει δεσμευτεί
void life_destroy(LifeState state){
        set_destroy(state);
}