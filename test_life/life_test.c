//////////////////////////////////////////////////////////////////
//
// Test για το life module
//
//////////////////////////////////////////////////////////////////


#include <limits.h>
#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "life.h"

//int* create_int(int value) {
//	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
//	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
//	return pointer;
//}

void test_life_create(){

   LifeState state = life_create();

    int size = set_size(state);
    TEST_CHECK( size == 0);

    set_destroy(state);

}

void test_life_create_from_rle(){
    char file[] = "bο$2bo$3o!";

   LifeState state = life_create_from_rle(file);

    int size = set_size(state);
    TEST_CHECK( size == 5);

    set_destroy(state);

}

void test_life_save_to_rle(){
    char file[] = "bο$2bo$3o!";

    LifeState state = life_create_from_rle(file);
   life_save_to_rle(state,file);

    
    TEST_CHECK( 1 == 2);

    set_destroy(state);

}

void test_life_get_cell(){
    char file[] = "bo$2bo$3o!";

   LifeState state = life_create_from_rle(file);

    LifeCell cell;
    cell.x=1;
    cell.y=2;
    TEST_CHECK(  life_get_cell(state,cell) == true);
    LifeCell new;
    new.x=4;
    new.y=3;
    TEST_CHECK(  life_get_cell(state,new) == false);

    set_destroy(state);

}

void test_life_set_cell(){
    char file[] = "bo$2bo$3o!";

   LifeState state = life_create_from_rle(file);

    LifeCell cell;
    cell.x=1;
    cell.y=2;
    life_set_cell(state,cell,false);
    TEST_CHECK(  set_size(state) == 4);
    LifeCell new;
    new.x=4;
    new.y=3;
    life_set_cell(state,new,true);
    TEST_CHECK(  set_size(state) == 5);

    set_destroy(state);

}

void test_life_destroy(){

   char file[] = "bo$2bo$3o!";
   LifeState state = life_create_from_rle(file);
 life_destroy(state);
TEST_CHECK( 1 == 1 );

}


// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "life_create_from_rle",test_life_create_from_rle },
	{ "life_save_to_rle",test_life_save_to_rle },
    { "life_create",test_life_create },
    { "life_get_cell",test_life_get_cell },
    { "life_set_cell",test_life_set_cell },
    { "life_destroy",test_life_destroy },


	{ NULL, NULL} // τερματίζουμε τη λίστα με NULL
};