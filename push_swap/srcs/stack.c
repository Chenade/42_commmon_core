#include "push_swap.h"

void ft_push(char element, char stack[], int *top, int stackSize){
 if(*top == -1){
  stack[stackSize - 1] = element;
  *top = stackSize - 1;
 }
 else if(*top == 0){
  printf("The stack is already full. \n");
 }
 else{
  stack[(*top) - 1] = element;
  (*top)--;
 }
}

void ft_pop(char stack[], int *top, int stackSize){
 if(*top == -1){
   printf("The stack is empty. \n");
 }
 else{
  printf("===Element popped: %c \n", stack[(*top)]);
  // If the element popped was the last element in the stack
  // then set top to -1 to show that the stack is empty
  if((*top) == stackSize - 1){
    (*top) = -1;
  }
  else{
    (*top)++;
  }
 }
}
