#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point {

        int x;
        int y;
        struct point* prev;
        struct point* next;
};

bool delElem(struct point **list,int x, int y) {
        if (list && *list) {

                struct point* cur = NULL;
                for (cur = (*list); cur && !(cur->x == x && cur->y == y); cur = cur->next);


                if (cur) {

                        if (cur->prev) {
                                if (cur->next) {
                                        cur->prev->next = cur->next;
                                        cur->next->prev = cur->prev;
                                        free(cur);
                                }
                                else {
                                        cur->prev->next = NULL;
                                        free(cur);
                                }
                        }
                        else {
                                if (cur->next) {
                                        cur->next->prev = NULL;
                                        (*list) = cur->next;
                                        free(cur);
                                }
                                else {
                                        free(cur);
                                        (*list) = NULL;
                                }
                        }

                        return true;
                }

        }


        return false;
}

void clear(struct point **list) {

        if (list && *list) {

                struct point* ptr = (*list);// ->next;
                while (ptr) {
                        struct point* next = ptr->next;
                        //if (ptr && ptr->prev) {
                                free(ptr);
                                ptr = next;
                        //}
                        //*list = NULL;

                }
                (*list) = NULL;
                //return true;
        }



        return;
}

void printList(struct point *list) {
        if (list) {
                while (list) {
                        printf("%d %d\n", list->x, list->y);
                        list = list->next;
                }


        }
        return;
}

int main(){
return 0;
}
