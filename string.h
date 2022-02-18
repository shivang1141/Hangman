#include <stdio.h>
#include "status.h"

typedef struct string* String_Ptr;
typedef struct string String;


String_Ptr string_init_default_function();

String_Ptr string_init_c_string(char * c_str);

Status string_destroy(String_Ptr* phString);

int string_compare(String_Ptr hString1, String_Ptr hString2);

int string_get_size(String_Ptr hString);

int string_get_capacity(String_Ptr hString);

Status string_extraction(String_Ptr hString, FILE * fp);

Status string_insertion(String_Ptr hString, FILE * fp);

Status string_push_back(String_Ptr hString, char item);

Status string_pop_back(String_Ptr hString);

char* string_at(String_Ptr hString, int index);

char* string_c_str(String_Ptr hString);

Status string_concat(String_Ptr hResult, String_Ptr hAppend);

Boolean string_empty(String_Ptr hString);

