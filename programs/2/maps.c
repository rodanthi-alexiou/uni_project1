#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "ADTMap.h"


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

char array[MAX];
int i=0;

Map lines = map_create(compare_strings, NULL, NULL);

int* times;

            while(fgets(array, MAX, stdin) != NULL){
                char* saved= strdup(array);

		//αν δεν υπάρχει η γραμμή που διαβάστηκε σαν key στο map
                if(map_find(lines,saved) == NULL){
                    times = create_int(0);		//δεν έχει ξαναδιαβαστεί άρα οι φορές είναι 0
                    map_insert(lines, saved, times);
                    printf("%d \n", *times );
                }
		    //αλλιώς η γραμμή που διαβάστηκε έχει ξαναδιαβαστεί άρα υπάρχει ως key στο map
                else{
                    times = map_find(lines, saved);
                    (*times)+=1;
                    map_insert(lines, saved, times);
                    printf("%d \n", *times);
                }


i++;
}
}
