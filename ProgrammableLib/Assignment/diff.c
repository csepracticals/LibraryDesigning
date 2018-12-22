#include <stdlib.h>

/*Step 5 : */

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

      void *next1 = NULL, *next2 = NULL;
      /*Basic quick sanity checks*/
      if(root1 && !root2)
          return -1;
      if(!root1 && root2)
          return -1;
      if(comparator(get_app_data(root1), get_app_data(root2)))
          return -1;
      
      next1 = iterator(root1);
      next2 = iterator(root2);         
      
      while(1){
        if(comparator(get_app_data(next1), get_app_data(next2)))
            return -1;
        next1 = iterator(next1);
        next2 = iterator(next2);
        if(!next1 && !next2) return 0;
      }
      return 0;
}
