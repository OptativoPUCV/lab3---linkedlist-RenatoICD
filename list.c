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

  return list->current;
}

void pushFront(List * list, void * data) {

  if (list == NULL)
    return;
  Node *new = createNode(data);
  for (Node *aux = list->head; aux != NULL; aux = aux->next)
    list->head = new;
  new->next = list->head;
  list->head = new;
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
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

  // if (list == NULL || list->current == NULL)
  //   return NULL;

  // Node* current = list->current;
  // Node* prev = list->prev;

  // while (current != NULL)
  //   if (current->data == )
  // if (list->current == NULL)
  //   return NULL;
  // if (list->current == list->head)

  // void * data = list->current->data;
  
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}