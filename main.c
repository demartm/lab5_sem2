#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point {

        int x;
        int y;
        struct point* prev;
        struct point* next;
};


bool addToHead(struct point** head,int x, int y) {
        if (head/* && *head*/) {
                struct point* new_head = (struct point*)calloc(1, sizeof(struct point));
                if (new_head) {
                        new_head->x = x;
                        new_head->y = y;
                        new_head->next = (*head);
                        new_head->prev = NULL;
                        if (*head) {
                                (*head)->prev = new_head;
                        }
                        (*head) = new_head;
                        return true;
                }
        }

        return false;
}

struct point* addToTail(struct point **head,int x,int y) {
        if (head) {
                struct point* list = *head;
                struct point* new_tail = (struct point*)calloc(sizeof(struct point), 1);
                if (new_tail) {
                        if (list) {
                                while (list->next) {
                                        list = list->next;
                                }

                                list->next = new_tail;
                        }
                        else {
                                (*head) = new_tail;
                        }
                        new_tail->x = x;
                        new_tail->y = y;
                        new_tail->prev = list;
                        new_tail->next = NULL;



                        return new_tail;

                }
        }


        return NULL;
}

bool delTail(struct point **list) {
        if (list && *list) {
                struct point* cur = *list;
                while (cur->next) {
                        //printf("%d %d\n", list->x, list->y);
                        cur = cur->next;
                }
                //list->prev->next = NULL;
                if (!(cur->prev)) {

                        free(*list);
                        *list = NULL;
                }
                else {
                        cur->prev->next = NULL;
                        free(cur);

                }

                return true;



        }

        return false;
}

int main() {
return 0;
}
