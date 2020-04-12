#include <stdio.h>
#include <string.h>

#define MAX 20
#define LINES 1000000

int main(){

char array[LINES][MAX];


int i=0;
int times;
int k;

while(fgets(array[i], MAX, stdin) != NULL){
    k=0;
    times=0;
    

    // συγκρίνω κάθε καινούριο line που διαβάζω με όσα lines έχουν προηγηθεί και είναι αποθηκευμένα στο array

    while(k<i){
        if(strcmp(array[k],array[i]) == 0)
                times++;
    k++;
    
    }
        printf("%d \n", times);
        i++;
}


}
