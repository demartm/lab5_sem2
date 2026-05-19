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



    }
    else {
    free(el);
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

int main() {
return 0;
}

return NULL;
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
