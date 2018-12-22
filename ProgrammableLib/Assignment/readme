In this assignment, We will write a generic diff function diff() which can tell whether the two similar Data structures are clones of each other or not. Two similar Data structures could be two linked list, two trees or anything.  diff() should be generic and should work for all data structures.

Instructions :
Create two new Linked lists : list1 and list2. See evaluation.c file, in main(), i have created two lists for you already called student_db1 and student_db2.
list1 and list2 both holds the records of type student_t. student_t is defined as :

typedef struct student_{
    char name[32];
    unsigned int year_of_birth;
    unsigned int height;
    unsigned int weight;
    unsigned int total_marks;
} student_t;


Step 1 (Done): Create two linked list and add some records in both list. I have done it for you in evaluation.c file. I have used library dll.h/.c  which you have already created so far.


Step 2 : Now write an iterator function called "void* list_iterator (void *list_node)" in evaluation.c file. which takes an input a pointer to node of a linked list, and return the pointer to next node. Signature of function should be generic as below. Handle NULL cases.
    Signature : void* list_iterator (void *list_node);



Step 3 : Write a comparator function called "int student_comparator (void *_studentobj1, void *_studentobj2)" in evaluation.c file which takes an input the pointer to objects of type student_t and return 0 if two objects are equal , otherwise -1. The signature of function should be generic as below :
    Signature : int student_comparator (void *studentobj1, void *studentobj2);



Step 4 : Write a function called "void * get_app_data_from_list_node(void *list_node)" in file evaluation.c which takes an input the pointer to node of linked list and return the object to data held by the node of the linked list.
    Signature : void *get_app_data_from_list_node(void *list_node);


Step 5 : Now write a diff function in diff.c file. Signature of the function should be generic as below :

    int  /*return 0 if two Data structures are equal, else -1*/
    diff (void *root1,    /*pointer to starting node of list 1*/
          void *root2,    /*pointer to starting node of list 2*/
          void *(*iterator(void *)),        /*Iterator function callback*/
          int comparator(void *, void *),   /*Comparison function callback*/
          void *(*get_app_data(void *)));   /*get application data function callback*/



Step 6 : you should call the diff() as follows in evaluation.c file :

if(diff (first_node1, first_node2, list_iterator, student_comparator, get_app_data_from_list_node) == 0)
    printf("Data structures are equal\n");
else
    printf("Data structures are not equal\n");


Step 7 : Compile and execute the final executable. Your output should be "Data structures are equal".
Step 8 : Modify the Student list as per your convinience and verify that you get appropriate output.

Step 9 : Repeat the above exercise for trees. You should NOT modify diff() that you have written in step 5, it should work for tree data structures as well.
