#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point {

        int x;
        int y;
        struct point* prev;
        struct point* next;
};


void addToHead(struct point** head,int x, int y) {
if (head) {
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
  }
}
return;
}

struct point* addBefore(struct point **list,int x,int y,int x_add,int y_add) {
if (list) {

  struct point* el = (struct point*)calloc(sizeof(struct point), 1);
  if (el) {

    struct point* cur = NULL;// (*list);
    for (cur = (*list); cur && !(cur->x == x && cur->y == y); cur = cur->next);

    if (cur) {
      el->x = x_add;
      el->y = y_add;

      el->prev = cur->prev;
      el->next = cur;

      if (cur->prev == NULL) {

        el->prev = NULL;
        cur->prev = el;
        (*list) = el;
      }
      else {

        el->prev = cur->prev;
        cur->prev->next = el;
        cur->prev = el;
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

el->prev = cur->prev;
cur->prev = el;

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


void delElem(struct point **list,int x, int y) {
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


  }

  }


return;
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

void delTail(struct point **list) {
if (list && *list) {

  struct point* cur = *list;

  while (cur->next) {
    cur = cur->next;
  }

  if (!(cur->prev)) {

    free(*list);
    *list = NULL;
  }
  else {
    cur->prev->next = NULL;
    free(cur);
  }




}
return;
}



struct point *addAfter(struct point *list,int x,int y,int x_add,int y_add) {
if (list) {
struct point *el = (struct point*)calloc(sizeof(struct point), 1);

if (el) {

  while (list && !(list->x == x && list->y == y)) {
    list = list->next;
  }

  if (list) {
    el->x = x_add;
    el->y = y_add;

    el->prev = list;
    el->next = list->next;
    list->next = el;

    if (el->next) {

      el->next->prev = el;
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
struct point* find(struct point *head,int x,int y) {
if (head) {
  while (head && !(head->x == x && head->y == y)) {

    head = head->next;
  }
  if (head) {

    return head;
  }
}
return NULL;
}

void delHead(struct point** head) {
if (head && *head) {

  struct point* ptr = (*head)->next;

  if (ptr) {

    (*head)->next->prev = NULL;
  }
  free(*head);
  (*head) = ptr;

}

return;
}
void delAtPos(struct point **list,size_t pos) {
if (list && *list) {

struct point* cur = NULL;// *list;

size_t i = 0;

for (cur = *list; i < pos && cur; cur = cur->next, i++);

if (cur && i == pos) {

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

}


}


return;
}

void clear(struct point **list) {

if (list && *list) {

  struct point* ptr = (*list);// ->next;
  while (ptr) {

    struct point* next = ptr->next;
    free(ptr);
    ptr = next;
  }
  (*list) = NULL;
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
int main() {

        struct point* head = NULL;

addToHead(&head,1000,10000);
printList(head);

for(int i =0; i< 10; i++){
addToHead(&head,10-i,10-i);
}


printList(head);

delHead(&head);

printf("\n\n-------------------------\n\n");
printList(head);

delElem(&head,2,2);
printf("\n\n-------------------------\n\n");
printList(head);

struct point *elem = find(head,5,5);
if(elem){
printf("element (%d,%d) found at %p",elem->x,elem->y,&elem);
}else{
printf("element not found");
}

clear(&head);


printf("\n\n-------------------------\n\n");
printList(head);


for(int i =0; i< 10; i++){
addToHead(&head,10-i,10-i);
}
addBefore(&head,7,7,222,222);


printf("\n\n------------next part-------------\n\n");
printList(head);

addAfter(head,7,7,333,333);


printf("\n\n-------------------------\n\n");
printList(head);


addAtPos(&head,999,876,3);

printf("\n\n-------------------------\n\n");
printList(head);

delAtPos(&head,3);
printf("\n\n-------------------------\n\n");
printList(head);


addToTail(&head,111,111);
printf("\n\n-------------------------\n\n");
printList(head);

delTail(&head);
printf("\n\n-------------------------\n\n");
printList(head);

clear(&head);
return 0;
        //struct point* head = (struct point*)calloc(sizeof(struct point), 1);
        //struct point* el1 = (struct point*)calloc(sizeof(struct point), 1);
        //struct point* el2 = (struct point*)calloc(sizeof(struct point), 1);
        //struct point* el3 = (struct point*)calloc(sizeof(struct point), 1);
        //struct point* el4 = (struct point*)calloc(sizeof(struct point), 1);

        //head->prev = NULL;
        //head->next = el1;
        //el1->prev = head;
        //el1->next = el2;
        //el2->prev = el1;
        //el2->next = el3;

        //el3->prev = el2;
        //el3->next = el4;
        //
        //el4->prev = el3;
        //el4->next = NULL;

        //el1->x = 1;
        //addToHead(&head, 1, 3);
        //addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 2);
        addToHead(&head, 1, 3);
        ////clear(&head);
        ////delHead(&head);
        //addToTail(&head, 5, 9909);
        //addToTail(&head, 5, 5);
        //addToHead(&head, 9999, 9999);
        //addToTail(&head, 5, 5);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delTail(&head);
        //delElem(&head, 9999, 9999);
        //struct point *elem = find(head, 9999, 9999);
        addAtPos(&head, 13, 37, 0);
        //addAfter(head, 9999, 9999,100,100);
        addAtPos(&head, 99, 10, 21);
        //delAtPos(&head, 21);
        addBefore(&head, 13, 37, 188998, 9289289);
        //if(elem) { printf("\nfound %d %d \n\n", elem->x, elem->y); }
        printList(head);




return 0;
}
