#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "ADTSet.h"

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

Set lines = set_create(compare_strings, NULL);
char array[MAX][100];
int i=0;
char* value;


SetNode node;



            while(fgets(array[i], MAX, stdin) != NULL){
                set_insert(lines,&array[i]);
				node = set_find_node(lines,&array[i]);
				
				if(set_next(lines, node) == SET_EOF){
					printf("<none>\n");
				}
				else{
					value = set_node_value(lines,set_next(lines, node));
					printf("%s\n", value);
				}

i++;
}

}



