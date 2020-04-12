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
<<<<<<< HEAD

Set lines = set_create(compare_strings, NULL);
=======
FILE* fp;
Set lines = set_create(compare_strings, NULL);  //δημιουργώ ένα σετ
>>>>>>> f852b63e4497b16fbae28a738a76e9de1f607b4a
char array[MAX][100];
int i=0;
char* value;


SetNode node;
<<<<<<< HEAD



            while(fgets(array[i], MAX, stdin) != NULL){
                set_insert(lines,&array[i]);
				node = set_find_node(lines,&array[i]);
				
				if(set_next(lines, node) == SET_EOF){
					printf("<none>\n");
=======
//όσο δεν έχουμε διαβάσει όλο το αρχείο
while (feof(fp) == 0){

            if(fgets(array[i], MAX, fp) != NULL){
                set_insert(lines,&array[i]);	//βάζω την γραμμή που μόλις διάβασα στο set
				node = set_find_node(lines,&array[i]); //βρίσκω το node της
				
		    		//αν δεν υπάρχει επόμενος κόμβος σημαίνει ότι δεν υπάρχει κόμβος που να πληρεί τα κριτήρια
				if(set_next(lines, node) == SET_BOF){
					printf("<none>");
>>>>>>> f852b63e4497b16fbae28a738a76e9de1f607b4a
				}
				else{
					//ο αμέσως επόμενος κόμβος θα είναι ο μικρότερος κόμβος από αυτούς που διαβάστηκαν που είναι μεγαλύτερος/ή ίσος από αυτόν που μόλις διαβάστηκε
					value = set_node_value(lines,set_next(lines, node));
					printf("%s\n", value);
				}

i++;
}

}



