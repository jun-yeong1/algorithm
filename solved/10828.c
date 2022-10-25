#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000
typedef int element;
element stack[MAX_STACK_SIZE];
int top_f = -1;

int empty(){
  if(top_f==-1){
    return 1;
  }
  else{
    return 0;
  }
}
element top(){
  if(top_f==-1){
    return -1;
  }else return stack[top_f];
}
element pop(){
  if(top_f == -1){
    return -1;
  }
  else{
    return stack[top_f--];
  }
}
element push(element n){
  top_f = top_f + 1;
  return stack[top_f] = n;
}

element size(){
  return top_f + 1;
}

int main(){
  int i, n;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    char g[9];
    scanf("%s", g);
    if(strcmp(g, "push")==0){
      int b;
      scanf("%d", &b);
      push(b);
    }
    else if(strcmp(g, "pop")==0){
      printf("%d\n", pop());
    }
    else if(strcmp(g, "size")==0){
      printf("%d\n", size());
    }
    else if(strcmp(g, "empty")==0){
      printf("%d\n", empty());
    }
    else if(strcmp(g, "top")==0){
      printf("%d\n", top());
    }
  }
}