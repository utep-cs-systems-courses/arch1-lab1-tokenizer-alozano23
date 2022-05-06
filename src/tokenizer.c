#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "malloc.h"
#include "history.h"

int space_char(char c)
{
  return c == ' '|| c == '\t'|| c == '\0';
}
int non_space_char(char c)
{
  return !(space_char(c));
}
int count_words(char *str)
{
  int is_non_space = 0;
  int count = 0;
   while(*str !='\0'){
     if(non_space_char(*str) && is_non_space == 0)
     {
       is_non_space = 1;
       count++;
     }
     if(space_char(*str)&&is_non_space == 1)
     {
         is_non_space = 0;
     }
     str++;
  }
   return count;
}
char *word_start(char *str)
{
  if(non_space_char(*str)){  
    return str;
   
  }
  if(space_char(*str) && *str == '\0')
  {
    char* start = '\0';
    return start;
  }
  else{
    str++;
    word_start(str);
  } 
}
char *word_terminator(char *word)
{
  if(non_space_char(*word))
  {
    word++;
    word_terminator(word);
  }
  else
  {
    return word;
  }
}
char *copy_str(char *inStr, short len)
{
  char* copy_word = (char*)malloc(len*sizeof(char));
  for(int i = 0; i <len; ++i)
  {
    if(non_space_char(*(inStr)))
      {
	*copy_word = *(inStr);
	copy_word++;
      }
      inStr++; 
  }
  for(int i = 0; i <len; ++i)
  {
     copy_word--;
  }
  return copy_word;
}
  char** tokenize(char* str)
  {
    int num_words = count_words(str);
    char**  arr_ptr =(char**)malloc((num_words)*sizeof(char*));
      for(int i = 0; i < num_words; ++i)
      {
	char *inStr = word_start(str);
	char *outStr =word_terminator(str);
	*arr_ptr = copy_str(inStr, outStr-inStr);
	str = *(&outStr);
	str++;
	*(arr_ptr)++;
      }
      for(int i = 0; i < num_words; ++i){
	arr_ptr--;
      }
      return arr_ptr;
  }
  void print_tokens(char **tokens)
  {
    int count = 0;
    while(*tokens){
      printf("%s ", *tokens);
      *tokens++;
      count++;
    }
    printf("\n");
    for(int i = count; i > 0; --i){
      *tokens--;
    }
    return;
  }
  void free_tokens(char **tokens)
  {
    int num_words = 0;
    while(*tokens){
      num_words++;
      *tokens++;
    }
    *tokens--;
    for(int i = num_words-1; i > 0; --i){
      free(*tokens);
      *(tokens)--;
    }
    free(tokens);
    return;
  }
