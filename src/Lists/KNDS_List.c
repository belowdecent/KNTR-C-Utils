#include "KNDS_List.h"
#include <stdlib.h>

void KNDS_ListFree(KNDS_List* list, void(*data_function)(void*)) {
  if (*data_function == NULL) {
    while (list != NULL) {
      KNDS_List* last_node = list;
      list = list->next;

      free(last_node);
    }
  } else {
    while (list != NULL) {
      KNDS_List* last_node = list;
      list = list->next;

      data_function(last_node->data);
      free(last_node);
    }
  }
}

int KNDS_ListLength(const KNDS_List* list) {
  int length = 0;
  while (list != NULL) {
    length += 1;
  }

  return length;
}

KNDS_List* KNDS_ListGetLast(KNDS_List* list) {
  if (list == NULL)
    return NULL;
  
  while (list->next != NULL)
    list = list->next;
  
  return list;
}

KNDS_List* KNDS_ListGet(KNDS_List* list, size_t position) {
  for (unsigned int i = 0; i < position; ++i) {
    if (list == NULL) return NULL;
    list = list->next;
  }
  
  return list;
}

KNDS_List* KNDS_ListNew(void* data, KNDS_List* next) {
  KNDS_List* list = malloc(sizeof(KNDS_List));
  list->data = data;
  list->next = next;
  return list;
}

KNDS_List* KNDS_ListClone(const KNDS_List* list) {
  if (list == NULL)
    return NULL;

  KNDS_List* out = KNDS_ListNew(list->data, NULL);
  KNDS_List* prev = out;
  list = list->next;

  while (list != NULL) {
    KNDS_List* next = KNDS_ListNew(list->data, NULL);
    prev->next = next;
    prev = next;

    list = list->next;
  }

  return out;
}
