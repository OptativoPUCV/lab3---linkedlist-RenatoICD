#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {

  List *L = (List *)malloc(sizeof(List));

  assert(L != NULL);

  L->head = L->tail = L->current = NULL;
  return L;
}

void * firstList(List * list) {

  if (list == NULL || list->head == NULL)
    return NULL;
  list->current = list->head;
  return list->head->data;
}

void * nextList(List * list) {

  if (list == NULL || list->current == NULL || list->current->next == NULL)
    return NULL;

  list->current = list->current->next;

  return list->current->data;
}

void * lastList(List * list) {

  if (list == NULL || list->tail == NULL)
      return NULL;
  list->current = list->tail;
  return list->tail->data;

  
}

void * prevList(List * list) {

  if (list == NULL || list->current == NULL || list->current->prev == NULL)
    return NULL;

  list->current = list->current->prev;

  return list->current->data;
}

void pushFront(List * list, void * data) {

  
  if (list == NULL)
    return;
  Node *new = createNode(data);

  new->data = data;
  new->next = NULL;
  new->prev = NULL;

  if (list->head == NULL){
    list->head = new;
    list->tail = new;
  }
  else{
    new->next = list->head;
    list->head->prev = new;
    list->head = new;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {

  if (list == NULL) {
    return;
  }

  Node *new = (Node *)malloc(sizeof(Node));
  
  if (new == NULL) {
      return;
  }
  new->data = data;
  new->next = NULL;
  new->prev = NULL;

  if (list->current == NULL) {
      list->head = new;
      list->tail = new;
      list->current = new;
  } 
  else {
    new->next = list->current->next;
    new->prev = list->current;
    if (list->current->next != NULL) {
      list->current->next->prev = new;
    } 
    else{
      list->tail = new;
    }
    list->current->next = new;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {

  if (list == NULL || list->current == NULL) {
    return NULL;
  }
  
  void *data = list->current->data;

  if (list->current->prev != NULL) {
    list->current->prev->next = list->current->next;
  } 
  else {
    list->head = list->current->next;
  }
  
  if (list->current->next != NULL) {
    list->current->next->prev = list->current->prev;
  } 
  else {  
    list->tail = list->current->prev;
  }

  free(list->current);
  list->current = NULL;

  return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}