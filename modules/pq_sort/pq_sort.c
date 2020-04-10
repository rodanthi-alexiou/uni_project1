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

		PriorityQueue pq = pqueue_create(compare, NULL, vec);


int size = vector_size(vec);
		
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
			Vector vec = vector_create(size, NULL);
			int i=0;
			for(ListNode node=list_first(list); node!= LIST_EOF; node=list_next(list,node)){
			int* p= list_node_value(list,node);
			vector_set_at(vec, i, p);
			i++;
		}

		pq_sort_vector(vec,compare);

	
		for(int j=size-1; j>=0; j--){
		list_insert_next(list,LIST_BOF, vector_get_at(vec,j));
		}

int* value = vector_get_at(vec,size-1);
int times=size;
ListNode no = list_find_node(list,value,compare);
while(times!=0){
list_remove_next(list,no);
times--;
}
}