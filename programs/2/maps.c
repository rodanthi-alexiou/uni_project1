#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "ADTMap.h"
#include "ADTVector.h"

#define MAX 200

int compare_strings(Pointer a, Pointer b){
    return strcmp(a,b);
}

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}

int main(){

char array[MAX][100];
int i=0;

Map lines = map_create(compare_strings, NULL, NULL);

int* times;

            while(fgets(array[i], MAX, stdin) != NULL){


                if(map_find(lines,&array[i]) == NULL){
                    times = create_int(0);
                    map_insert(lines, &array[i], times);
                    printf("%d \n", *times );
                }
                else{
                    times = map_find(lines, &array[i]);
                    (*times)+=1;
                    map_insert(lines, &array[i], times);
                    printf("%d \n", *times);
                }


i++;
}
}