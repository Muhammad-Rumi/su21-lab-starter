#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    node* hare = head;
    node* tortoise = head;
    for ( ;hare != NULL && tortoise !=NULL && hare->next != NULL; )
    {
        hare = hare ->next -> next;
        tortoise = tortoise ->next;
        if (hare == tortoise)
        {
            return 1;
        }
        
    }
     
    /* TODO: Implement ll_has_cycle */
}
