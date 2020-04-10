#include <stdio.h>
#include <string.h>

#define MAX 40
#define LINES 1000

int main(){

FILE* fp;
char array[LINES][MAX];

fp = fopen("text.txt", "r");
if(fp == NULL)
    return -1;

int i=0;
int times;
int k;

while (feof(fp) == 0){

if(fgets(array[i], MAX, fp) != NULL){
    k=0;
    times=0;
    

    // συγκρίνω κάθε καινούριο line που διαβάζω με όσα lines έχουν προηγηθεί και είναι αποθηκευμένα στο array

    while(k<i){
        if(strcmp(array[k],array[i]) == 0)
                times++;
    k++;
    
    }
        printf("%s %d \n", array[i], times);
        i++;
}
}

fclose(fp);

}