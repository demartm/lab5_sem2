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

struct point* addAtPos1(struct point **list,int x,int y,size_t pos) {
        if (list/* && *list*/) {
                struct point* new_elem = (struct point*)calloc(sizeof(struct point), 1);
                if (new_elem) {
                        new_elem->x = x;
                        new_elem->y = y;
                        struct point* cur =  (*list);
                        size_t i = 0;
                        for (i = 0; cur && i < pos; cur = cur->next, i++);
                        if (cur && i == pos) {
                                //TODO
                                //if (cur) {
                                        if (cur->prev) {
                                                //if (cur->next) {

                                                        new_elem->prev = cur->prev;
                                                        new_elem->next = cur;
                                                        cur->prev->next = new_elem;
                                                        cur->prev = new_elem;
                                                        //free(cur);
                                                //}
                                                //else {
                                                //	new_elem->prev = cur->prev;
                                                //	new_elem->next = cur;
                                                //	cur->prev->next = new_elem;
                                                //	cur->prev = new_elem;

                                                //	//free(cur);
                                                //}

                                        }
                                        else {
                                                //if (cur->next) {
                                                new_elem->next = cur;
                                                new_elem->prev = NULL;
                                                cur->prev = new_elem;
                                                (*list) = new_elem;
                                                /*				cur->next->prev = NULL;
                                                                                (*list) = cur->next;
                                                                                free(cur);*/
                                                                                /*		}
                                                                                                else {

                                                                                                }*/
                                        }
                                return new_elem;
                                //}
                                //else {
                                //	//new_elem->prev = NULL;// cur->prev;
                                //	//new_elem->next = NULL;// cur;
                                //	//(*list) = new_elem;
                                //	free(new_elem);
                                //}

                        }
                        else {
                                free(new_elem);
                        }

                }
        }

        return NULL;
}

int main(){
return 0;
}
