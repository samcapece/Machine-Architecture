#include <stdlib.h>
#include "linked_list.h"

int list_find_student(list_t *list, int value) {
    if (list == NULL) {
        return -1;
    }
    
    node_t *ptr = list->head;
    for (int i = 0; i < list->size; i++) {
        if (ptr->value == value) {
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}
