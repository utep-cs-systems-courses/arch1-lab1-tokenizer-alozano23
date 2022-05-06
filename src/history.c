#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history(){
  struct s_Item* root= (struct s_Item*)calloc(1, sizeof(struct s_Item) );
  struct s_Item* next_node = (struct s_Item*)calloc(1, sizeof(struct s_Item) );
  root->id = 0;
  root->next = next_node;
  struct s_List* list = (struct s_List*)malloc(sizeof(struct s_List) );
  list->root = root;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *string){
  if(list->root->str == NULL){
    //printf("||||||||||||\n");
    list->root->str = string;
    //list->root->next = (struct s_Item*)malloc(sizeof(struct s_Item) );
    list->root->next = NULL;
    list->root->next = (struct s_Item*)malloc(sizeof(struct s_Item) );
    //list->root->next->id = 1;
    return;
  }
  
  struct s_Item* temp = list->root;
  int count = 0;
  while (temp->next->str != NULL){
    printf("%s %d\n ", temp->str, temp->id);
    temp = temp->next;
    count++;
  }
  printf("%s %d \n", temp->str, temp->id);
  temp->next = (struct s_Item*) malloc(sizeof(struct s_Item) );
  temp->next->id = count+1;
  temp->next->str = string;
  temp->next->next = NULL;
  return;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
/*
char *get_history(List *list, int id){
  return;
}
*/
/*Print the entire contents of the list. */

void print_history(List *list){
  //printf("%s\n", list->root->str);
  if(!(list->root->str)){
    printf("There is nothing to print out\n");
    return;
  }
  //struct s_Item* temp = (struct s_Item*)malloc(sizeof(struct s_Item));
  struct s_Item* temp = list->root;
  while(temp != NULL){
    printf("%d. %s\n", temp->id, temp->str);
    temp = temp->next;
  }
  //free(temp);
  //printf("stop\n");
  return;
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  return;
}
