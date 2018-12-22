#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int
diff (void *root1,    /*pointer to first node of data struture 1*/
        void *root2,    /*pointer to first node of data struture 2*/
        void *(*iterator)(void *), /*Iterator function callback*/
        int (*comparator)(void *, void *),
        void *(*get_app_data)(void *)); /*Comparison function callback*/


/*Application specific data structures*/
typedef struct student_{
    char name[32];
    unsigned int year_of_birth;
    unsigned int height;
    unsigned int weight;
    unsigned int total_marks;
} student_t;


/*Step 2 : Implement list iterator function here*/
void* list_iterator (void *list_node){

    /*write your code here*/
    return NULL;    
}

/*Step 3 : implement student comparator function here*/

int student_comparator (void *_studentobj1, void *_studentobj2){

    /*Write your code here*/
    return -1;
} 

/*Step 4 : implement get_app_data_from_list_node function*/
void*
get_app_data_from_list_node(void *list_node){

    /*Write your code here*/
    return NULL;
}


int
main(int argc, char **argv){

    /*Student database list 1*/
    student_t *student1 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student1->name, "Abhishek", strlen("Abhishek"));
    student1->year_of_birth = 2000;
    student1->height = 167;
    student1->weight = 80;
    student1->total_marks = 90;

    student_t *student2 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student2->name, "Sagar", strlen("Sagar"));
    student2->year_of_birth = 2001;
    student2->height = 170;
    student2->weight = 82;
    student2->total_marks = 80;

    student_t *student3 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student3->name, "Vineet", strlen("Vineet"));
    student3->year_of_birth = 2002;
    student3->height = 161;
    student3->weight = 62;
    student3->total_marks = 72;

    student_t *student4 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student4->name, "Neeraj", strlen("Neeraj"));
    student4->year_of_birth = 1998;
    student4->height = 167;
    student4->weight = 76;
    student4->total_marks = 67;


    dll_t *student_db1 = get_new_dll();
    add_data_to_dll(student_db1, student1);
    add_data_to_dll(student_db1, student2);
    add_data_to_dll(student_db1, student3);
    add_data_to_dll(student_db1, student4);


    /*Student database list 2*/
    student_t *student5 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student5->name, "Abhishek", strlen("Abhishek"));
    student5->year_of_birth = 2000;
    student5->height = 167;
    student5->weight = 80;
    student5->total_marks = 90;

    student_t *student6 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student6->name, "Sagar", strlen("Sagar"));
    student6->year_of_birth = 2001;
    student6->height = 170;
    student6->weight = 82;
    student6->total_marks = 80;

    student_t *student7 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student7->name, "Vineet", strlen("Vineet"));
    student7->year_of_birth = 2002;
    student7->height = 161;
    student7->weight = 62;
    student7->total_marks = 72;

    student_t *student8 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student8->name, "Neeraj", strlen("Neeraj"));
    student8->year_of_birth = 1998;
    student8->height = 167;
    student8->weight = 76;
    student8->total_marks = 67;

    dll_t *student_db2 = get_new_dll();
    add_data_to_dll(student_db2, student5);
    add_data_to_dll(student_db2, student6);
    add_data_to_dll(student_db2, student7);
    add_data_to_dll(student_db2, student8);

    /*Step 6*/

    if(diff((void *)student_db1->head, (void *)student_db2->head, list_iterator, student_comparator, get_app_data_from_list_node) == 0)
        printf("Data sructures are equal\n");
    else
        printf("Data sructures are not equal\n");
    return 0;
}
