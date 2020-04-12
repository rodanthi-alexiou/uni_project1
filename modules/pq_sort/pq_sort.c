////////////////////////////////
//
// Υλοποίηση του pq_sort module
//
////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

#include "pq_sort.h"
#include "ADTPriorityQueue.h"


void pq_sort_vector(Vector vec, CompareFunc compare) {
	// Προσοχή! Μέσα στη συνάρτηση αυτή θα χρειαστεί να αντικαταστήσουμε τα περιεχόμενα του vector. Δε
	// θέλουμε όμως όσο το κάνουμε αυτό το vector να καλέσει τη destroy! Οπότε αλλάζουμε προσωρινά τη
	// συνάρτηση destroy σε NULL (αποθηκεύοντας την παλιά τιμή).
	DestroyFunc old_destroy = vector_set_destroy_value(vec, NULL);

		PriorityQueue pq = pqueue_create(compare, NULL, vec); //φτιάχνω μια priority queue και βάζω ως όρισμα τα στοιχεία του vec


int size = vector_size(vec);
		//με μια επανάληψη ξαναβάζω τα στοιχεία με την σειρά στο vec
		for(int i=size -1; i >= 0; i--){
			int* value= pqueue_max(pq);
			vector_set_at(vec,i,value);
			pqueue_remove_max(pq);
		}




	// επαναφορά της destroy
	vector_set_destroy_value(vec, old_destroy);

}


void pq_sort_list(List list, CompareFunc compare) {
	
	int size = list_size(list);
			Vector vec = vector_create(size, NULL); //φτιάχνω ένα vector και βάζω όλα τα στοιχεία της λίστας σε αυτό
			int i=0;
			for(ListNode node=list_first(list); node!= LIST_EOF; node=list_next(list,node)){
			int* p= list_node_value(list,node);
			vector_set_at(vec, i, p);
			i++;
		}
//καλώ την pq_sort_vector και βάζω ως όρισμα το vec με τα στοιχεία της λίστας
		pq_sort_vector(vec,compare);

	//βάζω τα στοιχεία σε σειρά στην αρχή της λίστας μου
		for(int j=size-1; j>=0; j--){
		list_insert_next(list,LIST_BOF, vector_get_at(vec,j));
		}

int* value = vector_get_at(vec,size-1); //το στοιχείο στο vector size-1 είναι το πρώτο στοιχείο που μπήκε ξανά στην λίστα μετά το κάλεσμα την συνάρτησης και όλα τα άλλα insert γινοντουσαν πριν από αυτό
int times=size;
ListNode no = list_find_node(list,value,compare); //μετά το πρώτο στοιχείο της λίστας που θα έχει αυτό το value θα είναι τα μη-ταξινομημένα στοιχεία γιαυτό θα τα αφαιρέσουμε
while(times!=0){
list_remove_next(list,no);
times--;
}
}
