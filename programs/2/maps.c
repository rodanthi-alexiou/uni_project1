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

char array[MAX][100];
int i=0;

Map lines = map_create(compare_strings, NULL, NULL);

<<<<<<< HEAD
int* times;

            while(fgets(array[i], MAX, stdin) != NULL){
=======

//είχα χρησιμοποιείσει ένα αρχείο text.txt για την ανάγνωση των σειρών
fp = fopen("text.txt", "r");

if(fp == NULL)
    return -1;

int* times; //οι φορές που έχει διαβαστεί η σειρά


//όσο το αρχείο δεν έχει διαβαστεί πλήρως
while (feof(fp) == 0){

            if(fgets(array[i], MAX, fp) != NULL){
>>>>>>> f852b63e4497b16fbae28a738a76e9de1f607b4a

		//αν δεν υπάρχει η γραμμή που διαβάστηκε σαν key στο map
                if(map_find(lines,&array[i]) == NULL){
                    times = create_int(0);		//δεν έχει ξαναδιαβαστεί άρα οι φορές είναι 0
                    map_insert(lines, &array[i], times);
                    printf("%d \n", *times );
                }
		    //αλλιώς η γραμμή που διαβάστηκε έχει ξαναδιαβαστεί άρα υπάρχει ως key στο map
                else{
<<<<<<< HEAD
                    times = map_find(lines, &array[i]);
                    (*times)+=1;
                    map_insert(lines, &array[i], times);
=======
                    times = map_find(lines, &array[i]);		//βρίσκουμε το value του key δηλαδή της γραμμής
                    (*times)+=1; 	//και αυξάνουμε τις φορές κατά μια 
                    map_insert(lines, &array[i], times); //και αλλάξουμε το value
>>>>>>> f852b63e4497b16fbae28a738a76e9de1f607b4a
                    printf("%d \n", *times);
                }


i++;
}
<<<<<<< HEAD
}
=======
}
fclose(fp);
}
>>>>>>> f852b63e4497b16fbae28a738a76e9de1f607b4a
