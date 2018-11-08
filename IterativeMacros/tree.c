#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

tree_t*
init_tree(void)
{
    tree_t *tree = calloc(1,sizeof(tree_t));
    if(!tree)
        return NULL;
    tree->root = NULL;
    return tree;
}

tree_node_t* init_tree_node(int n)
{
    tree_node_t *node = calloc(1, sizeof(tree_node_t));
    if(!node)   return NULL;
    node->data = n;
    return node;
}

int
add_tree_node_by_value(tree_t *tree, int n)
{
    tree_node_t *root = NULL, *parent = NULL;;
    if(!tree) return -1;
    tree_node_t *node = init_tree_node(n);
    if(!tree->root){
        tree->root = node;
        return 0;
    }

    root = tree->root;

    while(root){
        parent = root;
        root = (n <= root->data) ? root->left : root->right;
    } // while ends

    if(n <= parent->data)
        parent->left = node;
    else
        parent->right = node;

    node->parent = parent;
    return 0;
}

tree_node_t *
get_left_most(tree_node_t *node){

    if(!node->left)
        return NULL;

    while(node->left){
        node = node->left;
    }
    return node;
}

tree_node_t *
get_next_inorder_succ(tree_node_t *node){

    /* case 1 : Handling root*/
    if(!node->parent){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
        return NULL;
    }

    /*case 2 : if node is a left child of its parent*/
    if(node == node->parent->left){
        if(!node->right)
            return node->parent;
        else
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
    }

    /*case 3 : if node is a right child of its parent*/
    if(node == node->parent->right){
        if(node->right){
            if(node->right->left)
                return get_left_most(node->right);
            else
                return node->right;
        }
    }

    /* case 4 : Inorder successor of node is a ancestor whose
     * left children is also an ancestor*/

    tree_node_t *gp = node->parent->parent;
    tree_node_t *parent = node->parent;

    while(gp && gp->left != parent){

        parent = gp;
        gp = gp->parent;
    }

    return gp;
}

int
main(int argc, char **argv){

    tree_t *tree = init_tree();

    add_tree_node_by_value(tree,  100);
    add_tree_node_by_value(tree,  50);
    add_tree_node_by_value(tree,  10);
    add_tree_node_by_value(tree,  90);
    add_tree_node_by_value(tree,  95);
    add_tree_node_by_value(tree,  99);
    
    tree_node_t *treenodeptr = NULL;

    ITERATE_BST_BEGIN(tree, treenodeptr){
    
        printf("%u ", treenodeptr->data);

    } ITERATE_BST_END;
    printf("\n");
    
    return 0;
}
