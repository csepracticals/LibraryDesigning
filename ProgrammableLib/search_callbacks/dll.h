/*Header file for Doubly Linked List*/

typedef struct dll_node_{

    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
    int (*key_match)(void *, void *);
} dll_t;

void
register_key_match_callback(dll_t *dll, int (*key_match)(void *, void *));

/*Generic Search function*/
void *
dll_search_by_key (dll_t *dll, void *key);

/* Public Function declaration to create and return
 * a new empty doubly linked list*/
dll_t *
get_new_dll();

/*  Public Function declaration to add the appication
 *  data to DLL*/
int
add_data_to_dll(dll_t *dll, void *appn_data);
