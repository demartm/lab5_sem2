#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point {

        int x;
        int y;
        struct point* prev;
        struct point* next;
};

struct point* addAtPos(struct point** list, int x, int y, size_t pos) {

        if (list) {

                struct point* el = (struct point*)calloc(sizeof(struct point), 1);

                if (el) {
                        el->x = x;
                        el->y = y;

                        if (!(*list) && pos == 0) {
                                (*list) = el;
                                return el;
                        }

                        size_t i = 0;
                        struct point *cur = NULL;
                        struct point* previous = NULL;
                        for (cur = *list; cur && i < pos; cur = cur->next, i++) {
                                if (cur->prev) {
                                        previous = cur;// ->prev;
                                }
                        }

                        if (i == pos) {

                                if (cur) {
                                        el->next = cur;

                                        if (cur->prev) {
                                                cur->prev->next = el;
                                        }
                                        else {
                                                (*list) = el;
                                        }


                                }
                                else {
                                        if (previous) {
                                                previous->next = el;
                                                el->prev = previous;
                                                el->next = NULL;
                                        }

                                }

                                return el;
                        }
                        else {
                                free(el);
                        }



                }




        }

        return NULL;
}

int main(){
return 0;
}
