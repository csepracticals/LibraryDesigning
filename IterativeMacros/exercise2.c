#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_NBRS    5
#define NAME_SIZE   32

typedef struct node_{

    char node_name[NAME_SIZE];
    struct node_ *nbrs[MAX_NBRS];
} node_t ;

void
add_nbr(node_t *node1, node_t *node2){

    int i = 0;
    for(; i < MAX_NBRS; i++){
        if(node1->nbrs[i]) continue;
        node1->nbrs[i] = node2;
        return;
    }
    /*Do not try to add more than MAX_NBRS*/
    assert(0);
} 

node_t *
create_new_node(char *name){

    node_t *node = calloc(1, sizeof(node_t));
    strncpy(node->node_name, name, NAME_SIZE);
    node->node_name[NAME_SIZE] = '\0';
    /*rest of the members is already NULL as 
     * we have used calloc*/
    return node;
}

#define ITERATE_NBRS_BEGIN(node, nbrnode)   \
{                                           \
    unsigned int _i = 0;                    \
    for(; _i < MAX_NBRS; _i++){             \
        if(!node->nbrs[_i]) break;          \
        nbrnode = node->nbrs[_i];

#define ITERATE_NBRS_END }}


#define ITERATE_ONE_HOP_NBRS_BEGIN(node, nbrnode) \
{                                                 \
    node_t *_direct_nbr = NULL;                   \
    ITERATE_NBRS_BEGIN(node, _direct_nbr){        \
        ITERATE_NBRS_BEGIN(_direct_nbr, nbrnode){ \
            if(nbrnode == node) continue;

#define ITERATE_ONE_HOP_NBRS_END    \
    } ITERATE_NBRS_END;             \
    } ITERATE_NBRS_END;             \
}
    
int
main(int argc, char **argv){

/*Problem 2  : */
    
    node_t *A = create_new_node("A");
    node_t *B = create_new_node("B");
    node_t *C = create_new_node("C");
    node_t *D = create_new_node("D");
    node_t *E = create_new_node("E");
    node_t *F = create_new_node("F");
    node_t *G = create_new_node("G");
    node_t *H = create_new_node("H");

/*Let us create the following graph now*/
/*
         A-------------B------------C---------H
         |             |            |
         |             |            |
         |             |            |
         |             |            |
         |             |            |
         E-------------D------------F---------G
*/

    add_nbr(A,B);
    add_nbr(A,E);

    add_nbr(B,A);
    add_nbr(B,D);
    add_nbr(B,C);

    add_nbr(C,B);
    add_nbr(C,F);
    add_nbr(C,H);
    
    add_nbr(D,B);
    add_nbr(D,E);
    add_nbr(D,F);
    
    add_nbr(E,A);
    add_nbr(E,D);

    add_nbr(F,C);
    add_nbr(F,D);
    add_nbr(F,G);

    add_nbr(G,F);

    add_nbr(H,C);
    
    node_t *nbr = NULL;
    printf("Nbrs of A : \n");
    ITERATE_NBRS_BEGIN(A, nbr){
        
        printf("Nbr name = %s\n", nbr->node_name);
    } ITERATE_NBRS_END;
    
    printf("Nbrs of H : \n");
    ITERATE_NBRS_BEGIN(H, nbr){
        
        printf("Nbr name = %s\n", nbr->node_name);
    } ITERATE_NBRS_END;

    printf("Nbrs of D : \n");
    ITERATE_NBRS_BEGIN(D, nbr){
        
        printf("Nbr name = %s\n", nbr->node_name);
    } ITERATE_NBRS_END;

    printf("One hop Nbrs of A : \n");
    ITERATE_ONE_HOP_NBRS_BEGIN(A, nbr){
        printf("Nbr name = %s\n", nbr->node_name);
    } ITERATE_ONE_HOP_NBRS_END;

    return 0;
}
