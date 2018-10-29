#include "dll.h"
#include <memory.h>
#include <stdlib.h>

/* Public Function Implementation to create and return
 * new empty doubly linked list*/

dll_t *
get_new_dll(){

    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    dll->key_match = NULL;
    return dll;
}

void
register_key_match_callback(dll_t *dll, 
                             int (*key_match)(void *, void *)){

    dll->key_match = key_match;
}

/*Generic Search function*/
void *
dll_search_by_key (dll_t *dll, void *key){

    if(!dll || !dll->head) return NULL;

    dll_node_t *head = dll->head;

    while(head){
        if(dll->key_match(head->data, key) == 0)
            return (void *)head->data;
        head = head->right;
    }
    return NULL;
}

/* Public Function Implementation to add a new application
 *  * data to DLL */
int
add_data_to_dll (dll_t *dll, void *app_data){

    if(!dll || !app_data) return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    /*Now add this to the front of DLL*/
    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    dll_new_node->right = first_node;
    first_node->left = dll_new_node;
    dll->head = dll_new_node;
    return 0;
}

