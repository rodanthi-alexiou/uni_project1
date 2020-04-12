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
FILE* fp;
Set lines = set_create(compare_strings, NULL);  //δημιουργώ ένα σετ
char array[MAX][100];
int i=0;
char* value;

fp = fopen("wish", "r");

if(fp == NULL)
    return -1;

SetNode node;
//όσο δεν έχουμε διαβάσει όλο το αρχείο
while (feof(fp) == 0){

            if(fgets(array[i], MAX, fp) != NULL){
                set_insert(lines,&array[i]);	//βάζω την γραμμή που μόλις διάβασα στο set
				node = set_find_node(lines,&array[i]); //βρίσκω το node της
				
		    		//αν δεν υπάρχει επόμενος κόμβος σημαίνει ότι δεν υπάρχει κόμβος που να πληρεί τα κριτήρια
				if(set_next(lines, node) == SET_BOF){
					printf("<none>");
				}
				else{
					//ο αμέσως επόμενος κόμβος θα είναι ο μικρότερος κόμβος από αυτούς που διαβάστηκαν που είναι μεγαλύτερος/ή ίσος από αυτόν που μόλις διαβάστηκε
					value = set_node_value(lines,set_next(lines, node));
					printf("%s", value);
				}
}
i++;
printf("\n");
}
}



