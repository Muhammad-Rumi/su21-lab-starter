/* Include the system headers we need */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Include our header */
#include "vector.h"  // NOLINT

/* Define what our struct is */
struct vector_t {
  size_t size;
  int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
  fprintf(stderr, "Out of memory.\n");
  exit(1);
}

/* Bad example of how to create a new vector */
// vector_t *bad_vector_new() {
//     /* Create the vector and a pointer to it */
//     vector_t *retval, v;
//     retval = &v;

//     /* Initialize attributes */
//     retval->size = 1;
//     retval->data = malloc(sizeof(int));
//     if (retval->data == NULL) {
//         allocation_failed();
//     }

//     retval->data[0] = 0;
//     return retval;
// }

/* Another suboptimal way of creating a vector */
// vector_t also_bad_vector_new() {
//     /* Create the vector */
//     vector_t v;

//     /* Initialize attributes */
//     v.size = 1;
//     v.data = malloc(sizeof(int));
//     if (v.data == NULL) {
//         allocation_failed();
//     }
//     v.data[0] = 0;
//     return v;
// }

/* Create a new vector with a size (length) of 1 and set its single component to
   zero... the right way */
// TODO(Runi): uncomment the code that is preceded by
vector_t *vector_new() {
  /* Declare what this function will return */
  vector_t *retval;

  /* First, we need to allocate memory on the heap for the struct */
  retval = malloc(sizeof(vector_t));

  /* Check our return value to make sure we got memory */
  if (retval == NULL) {
    allocation_failed();
  }

  /* Now we need to initialize our data.
     Since retval->data should be able to dynamically grow,
     what do you need to do? */
  retval->size = 1;
  retval->data = malloc(sizeof(int));

  /* Check the data attribute of our vector to make sure we got memory */
  if (retval->data == NULL) {
    free(retval);  // Why is this line necessary?
    allocation_failed();
    exit(1);
  }

  /* Complete the initialization by setting the single component to zero */
  //  = 0;
  retval->data[0] = 0;
  /* and return... */
  return retval; /* UPDATE RETURN VALUE */
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {
  /* If we are passed a NULL pointer for our vector, complain about it and exit.
   */
  if (v == NULL) {
    fprintf(stderr, "vector_get: passed a NULL vector.\n");
    abort();
  }

  /* If the requested location is higher than we have allocated, return 0.
   * Otherwise, return what is in the passed location.
   */
  if (v->size > loc) {
    return *(v->data + loc);
  }
  return 0;
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
  free(v->data);
  free(v);
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
  /* What do you need to do if the location is greater than the size we have
   * allocated?  Remember that unset locations should contain a value of 0.
   */
  int old_size = 0;
  if (v->size < loc) {
    // int jp = (loc + 1) * (sizeof(int));
    v->data = realloc(v->data, loc*sizeof(int));
    old_size = v->size;
    v->size = loc + 1;
    // v->data == NULL ?  ({free(v->data); allocation_failed();}) :
    // (memset(&v->data + *v->size -1, 0, sizeof(int)*loc));
    if (v->data == NULL) {
      free(v->data);
      allocation_failed();
      exit(1);
    }
    memset(v->data + old_size, 0, sizeof(int) * (loc +1 - old_size));
    assert(v->data);
  // v->size += loc;
  }
  v->data[loc] = value;
}
