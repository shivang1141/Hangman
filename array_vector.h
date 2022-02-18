#ifndef ARRAY_VECTOR_STR_H
#define ARRAY_VECTOR_STR_H

#include "vector.h"

// Precondition: words is a file contains all the words in
// a dictionary up to length 29
// Postcondition: returns an array of pointers to vector of strings
// The function will do the following:
// 1- First, allocate a memory for an array sufficient to
// hold 30 vector_string_ptr
// 2- Loop through each entry in the array to allocate a
// memory for each vector_string_ptr
// 3- Extract all the strings from the file using the
// string_extract method (from the string object)
// 4- Get the length of the string. Based on its length,
// add it to the corresponding vector. For example, if the
// word was hello, the length is 4. Then, you add the word
// hello to the vector_string at index 4 in the array
Vector_String_Ptr * load_array_vector_string(FILE * words);


// Precondition: pArray is a pointer to an array of vector_string_ptr
// Postcondition: destroy the whole array, free the memory and
// free the memory for each single vector_string_ptr inside the
// array, and then finally, set the array pointer to null
void destroy_array_vector_string(Vector_String_Ptr ** pArray);

#endif