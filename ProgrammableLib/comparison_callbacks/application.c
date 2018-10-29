#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/*Application specific data structures*/
typedef struct student_{

    char name[32];
    int age;
    int weight;
    unsigned int rollno;
} student_t;

static void
print_student_details(student_t *student){

    printf("Name = %s\n",   student->name);
    printf("Age = %d\n",    student->age);
    printf("weight = %d\n", student->weight);
    printf("rollno = %u\n", student->rollno);
}

static void
print_student_db(dll_t *student_db) {

    if(!student_db || !student_db->head) return;

    dll_node_t *head = student_db->head;
    student_t *data = NULL;

    while(head){
        data = head->data;
        print_student_details(data);
        head = head->right;    
    }
}

/*Application specific data structures*/
typedef struct employee_{

    char name[32];
    char designation[32];
    unsigned int salary;
    unsigned int emp_id;
} employee_t;

static void
print_employee_details(employee_t *employee){

    printf("Name = %s\n",   employee->name);
    printf("Designation = %s\n",    employee->designation);
    printf("salary = %u\n", employee->salary);
    printf("emp_id = %u\n", employee->emp_id);
}

static void
print_employee_db(dll_t *student_db) {

    if(!student_db || !student_db->head) return;

    dll_node_t *head = student_db->head;
    student_t *data = NULL;

    while(head){
        data = head->data;
        print_student_details(data);
        head = head->right;    
    }
}

/*Search function*/

student_t *
search_student_by_rollno(dll_t *student_db, 
                         unsigned int rollno/*search key*/){

    if(!student_db || !student_db->head) return NULL;

    dll_node_t *head = student_db->head;
    student_t *data = NULL;

    while(head){
        data = head->data;
        if(data->rollno == rollno)
            return data;
        head = head->right;    
    }
}


/*Search function*/

employee_t *
search_employee_by_emp_id(dll_t *employee_db, 
                         unsigned int emp_id/*search key*/){

    if(!employee_db || !employee_db->head) return NULL;

    dll_node_t *head = employee_db->head;
    employee_t *data = NULL;

    while(head){
        data = head->data;
        if(data->emp_id == emp_id)
            return data;
        head = head->right;    
    }
}

/*Search callbacks*/
static int /*return 0 if matches, return -1 if do not match*/
search_student_db_by_key(void *data, void *key){

    student_t *student = (student_t *)data;
    unsigned int rollno = (unsigned int)key;
    if(student->rollno == rollno)
        return 0;
    return -1;
}

/*Search callbacks*/
static int /*return 0 if matches, return -1 if do not match*/
search_employee_db_by_key(void *data, void *key){

    employee_t *emp = (employee_t *)data;
    unsigned int emp_id = (unsigned int)key;
    if(emp->emp_id == emp_id)
        return 0;
    return -1;
}

/*Comparion Callback*/
/*Return 0 if equal,
 *      -1 if stud1 < stud2
 *       1 if stud1 > stud2*/

static int
student_comparison_fn(void *stud1, void *stud2){
    
    /*Let us define the sorting order of students, 
     * Let us compare the students Alphabetically on their names
     * If two students have same name, younger students should 
     * come before elder student
     * If age is also same, lighter student comes before heavier
     * if Weight is also same, students with numerically lesser rollno
     * comes before in the DLL*/
    
     student_t *student1 = (student_t *)stud1;
     student_t *student2 = (student_t *)stud2;

     if(strncmp(student1->name, student2->name, 32) < 0)
         return -1;
     else if(strncmp(student1->name, student2->name, 32) > 0)
         return 1;
     else if(student1->age < student2->age)
         return -1;
     else if(student1->age > student2->age)
         return 1;
     else if(student1->weight < student2->weight)
         return -1;
     else if(student1->weight > student2->weight)
         return 1;
     else if(student1->rollno < student2->rollno)
         return -1;
     else if(student1->rollno > student2->rollno)
         return 1;
     assert(0); /*intentionally Crash the program !!*/
}

int 
main(int argc, char **argv){

    /*Student database*/
    student_t *student1 = calloc(1, sizeof(student_t));
    strncpy(student1->name, "Abhishek", strlen("Abhishek"));
    student1->age = 31;
    student1->weight = 75;
    student1->rollno = 800000;

    student_t *student2 = calloc(1, sizeof(student_t));
    strncpy(student2->name, "Joseph", strlen("Joseph"));
    student2->age = 41;
    student2->weight = 70;
    student2->rollno = 800400;

    student_t *student3 = calloc(1, sizeof(student_t));
    strncpy(student3->name, "Jack", strlen("Jack"));
    student3->age = 29;
    student3->weight = 55;
    student3->rollno = 800400;
    
    student_t *student4 = calloc(1, sizeof(student_t));
    strncpy(student3->name, "Abhishek", strlen("Abhishek"));
    student3->age = 29;
    student3->weight = 55;
    student3->rollno = 800399;

    /*Create a new Linked List*/

    dll_t *student_db = get_new_dll();
    register_key_match_callback(student_db, search_student_db_by_key);
    register_comparison_callback(student_db, student_comparison_fn);
    dll_priority_insert_data(student_db, student1);
    dll_priority_insert_data(student_db, student2);
    dll_priority_insert_data(student_db, student3);
#if 0
    //student_t *student = search_student_by_rollno(student_db, 800400);
    student_t *student = dll_search_by_key(student_db, (void *)800400);
    if(!student){
        printf("Student record not found\n");
    }
    else{
        print_student_details(student);    
    }
#endif
    printf("Printing Stduents list\n");
    print_student_db(student_db);
    
#if 0
    /*Employee database*/
    employee_t *employee1 = calloc(1, sizeof(employee_t));
    strncpy(employee1->name, "Harsh", strlen("Harsh"));
    strncpy(employee1->designation, "Vice President", strlen("Vice President"));
    employee1->salary = 11131;
    employee1->emp_id = 10000;

    employee_t *employee2 = calloc(1, sizeof(employee_t));
    strncpy(employee2->name, "Huma", strlen("Huma"));
    strncpy(employee2->designation, "CEO", strlen("CEO"));
    employee1->salary = 127000;
    employee1->emp_id = 10001;

    employee_t *employee3 = calloc(1, sizeof(employee_t));
    strncpy(employee3->name, "Neena", strlen("Neena"));
    strncpy(employee2->designation, "Manager", strlen("Manager"));
    employee1->salary = 139000;
    employee1->emp_id = 10002;

    /*Create a new Linked List*/

    dll_t *employee_db = get_new_dll();
    register_key_match_callback(employee_db, search_employee_db_by_key);
    register_comparison_callback(employee_db, student_comparison_fn);

    add_data_to_dll(employee_db, employee1);
    add_data_to_dll(employee_db, employee2);
    add_data_to_dll(employee_db, employee3);

    employee_t *employee = dll_search_by_key(employee_db, (void *)10002);
    if(!employee){
        printf("Student record not found\n");
    }
    else{
        print_employee_details(employee);    
    }
#endif
    return 0;
}
