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

FILE* fp;
char array[MAX][100];
int i=0;

Map lines = map_create(compare_strings, NULL, NULL);



fp = fopen("text.txt", "r");

if(fp == NULL)
    return -1;

int* times;



while (feof(fp) == 0){

            if(fgets(array[i], MAX, fp) != NULL){


                if(map_find(lines,&array[i]) == NULL){
                    times = create_int(0);
                    map_insert(lines, &array[i], times);
                    printf("%s and times: %d \n", array[i], *times );
                }
                else{
                    times = map_find(lines, &array[i]);
                    (*times)+=1;
                    map_insert(lines, &array[i], times);
                    printf("%s %d \n", array[i], *times);
                }


i++;
}
}
fclose(fp);
}