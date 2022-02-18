#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector.h"
#include "status.h"

int main(){
  Vector_String_Ptr theVector = vector_string_init_default();
  String_Ptr theString = string_init_c_string("Test");
  vector_string_push_back(theVector, theString);
  printf("String: %s\n", string_c_str(theString));
  printf("--------------------------------------------------\n");
  printf("the capacity %d, the size %d, \nthe value is %s\n", vector_string_get_capacity(theVector), vector_string_get_size(theVector), string_c_str(*vector_string_at(theVector, 0)));

  while(!string_empty(theString)){
    string_pop_back(theString);
    }
  
  printf("the capacity %d, the size %d, \nthe value is %s\n", vector_string_get_capacity(theVector), vector_string_get_size(theVector), string_c_str(*vector_string_at(theVector, 0)));
  string_push_back(theString,'C');
  printf("--------------------------------------------------\n");
  printf("the capacity %d, the size %d, \nthe value is %s\n", vector_string_get_capacity(theVector), vector_string_get_size(theVector), string_c_str(*vector_string_at(theVector, 0)));
  string_destroy(&theString);
  vector_string_destroy(&theVector);
}
