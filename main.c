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
  struct point* new_head = (struct point*)calloc(sizeof(struct point),1);
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

    struct point* cur = NULL;
    for (cur = (*list); cur && !(cur->x == x && cur->y == y); cur = cur->next);

    if (cur) {
      el->x = x_add;
      el->y = y_add;

      el->prev = cur->prev;
      el->next = cur;

      if (cur->prev == NULL) {

        (*list) = el;
      }
      else {

        cur->prev->next = el;
      }
        cur->prev = el;

return el;
    }
    else {
    free(el);
    }

  }
}
return NULL;
}


struct point *addAtPos(struct point **list, int x, int y, size_t pos){

if(list){
  struct point* el = (struct point*)calloc(sizeof(struct point),1);

  if(el){
    struct point *cur = NULL;
    struct point *previous = NULL;
    size_t ix = 0;

    for(cur = *list; cur && ix < pos;cur = cur->next,ix++){
      previous = cur;
    }
    el->x = x;
    el->y = y;

    if(cur){

    if(cur->prev){

      el->next = cur;
      el->prev = cur->prev;
      cur->prev->next = el;
      cur->prev = el;

    }else{

      el->next = cur;
      el->prev = NULL;
      cur->prev = el;
      (*list) = el;
    }
      return el;
    }else{
    if(ix == pos){
      el->prev = previous;
      el->next = NULL;

      if(previous){
        previous->next = el;

      }else{
        *list = el;
      }
      return el;
    }else{
      free(el);
    }

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

  if(cur->prev){
    cur->prev->next = cur->next;
  }else{
    (*list) = cur->next;
  }

  if(cur->next){
    cur->next->prev = cur->prev;
  }

  free(cur);
  }

  }


return;
}


struct point* addToTail(struct point **head,int x,int y) {
if (head) {
  struct point* new_tail = (struct point*)calloc(sizeof(struct point), 1);
  if (new_tail) {
    new_tail->x = x;
    new_tail->y = y;
    new_tail->next = NULL;

    if (*head) {
  struct point* list = NULL;

  for(list = *head; list->next;list = list->next);

    new_tail->prev = list;
      list->next = new_tail;
    }
    else {

      (*head) = new_tail;
    }

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
    if (list->next) {

      list->next->prev = el;
    }
    list->next = el;

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

    ptr->prev = NULL;
  }
  free(*head);
  (*head) = ptr;

}

return;
}

void delAtPos(struct point **list, size_t pos){
if(list && *list){
  struct point* cur = NULL;
  size_t i = 0;

  for(cur = *list; cur && i < pos; cur = cur->next, i++);

  if(cur && i == pos){
    if(cur->prev){
      cur->prev->next = cur->next;
    }

    if(cur->next){
      cur->next->prev = cur->prev;

  }
    if(i == 0){
      (*list) = cur->next;
    }
free(cur);
}
return;
}
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

void printBackwards(struct point *list){
if (list) {
  while (list) {

    printf("%d %d\n", list->x, list->y);
    list = list->prev;
  }
}
return;

}
int main() {

struct point* head = NULL;
printf("\n\nhead--------------------\n\n");
addToHead(&head,1000,10000);
printList(head);


printf("\n\nprintBack-------------------------\n\n");
struct point *tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\nelem--------------------\n\n");
for(int i = 0; i < 4; i++){
  addToHead(&head,4-i,4-i);
}
printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\ndelHead-------------------\n\n");
delHead(&head);
printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\ndelElem--------------------\n\n");
delElem(&head,3,3);
printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\nfindElem--------------------\n\n");
struct point *elem = find(head,4,4);
if(elem){
  printf("element (%d,%d) found at %p\n",elem->x,elem->y,(void*)elem);
}else{
  printf("element not found\n");
}

elem = find(head,100000,5000000);
if(elem){
  printf("element (%d,%d) found at %p\n",elem->x,elem->y,(void*)elem);
}else{
  printf("element not found\n");
}

printf("\n\nclear------------------------\n\n");
clear(&head);
printList(head);

printf("\n\n------------next part-------------\n\n");
for(int i =0; i < 4; i++){
  addToHead(&head,4-i,4-i);
}
printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\naddBefore/After------------------------\n\n");

elem = addBefore(&head,3,3,222,222);
//elem = addBefore(&head,1,1,222,222);
//elem = addBefore(&head,4,4,222,222);
if(elem){
  printf("elem added at %p\n",(void*)elem);
}else{
  printf("failed adding elem\n");
}


elem = addAfter(head,2,2,333,333);
//elem = addAfter(head,1,1,333,333);
//elem = addAfter(head,4,4,333,333);
if(elem){
  printf("elem added at %p\n",(void*)elem);
}else{
  printf("failed adding elem\n");
}

printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

delElem(&head,222,222);
delElem(&head,333,333);

printf("\n\naddAtPos--------------------------\n\n");
//elem = addAtPos(&head,999,999,0);
// elem = addAtPos(&head,999,999,1);
 elem = addAtPos(&head,999,999,2);
// elem = addAtPos(&head,999,999,3);
// elem = addAtPos(&head,999,999,4);
if(elem){
  printf("elem added at %p\n",(void*)elem);
}else{
  printf("failed adding elem");
}

printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\ndelete---------------------\n\n");
//delAtPos(&head,0);
//delAtPos(&head,1);
delAtPos(&head,2);
//delAtPos(&head,3);
//delAtPos(&head,4);
printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\naddToTail-------------------------\n\n");
elem = addToTail(&head,111,111);
if(elem){
  printf("elem added at %p\n",(void*)elem);
}else{
  printf("failed adding elem");
}

printList(head);

printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}

printf("\n\ndelTail-----------------------\n\n");
delTail(&head);
printList(head);

//delAtPos(&head,12);


printf("\nprintBack-------------------------\n\n");
tail = addToTail(&head,0,0);
tail = tail->prev;
delTail(&(tail->next));
if(tail){
  printBackwards(tail);
}


clear(&head);
return 0;
}
