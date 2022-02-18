#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "vector.h"
#include "status.h"

struct vector_string {
	int size;
	int capacity; 
	String_Ptr * data;
}; 

typedef struct vector_string Vector_String;

// Precondition: None
// Postcondition: allocates memory to a pointer to a vector of strings 
// it also sets the size to 0 and the capacity to 1
// it allocates an array of string_ptr of capacity 1
Vector_String_Ptr vector_string_init_default(void)
{
	Vector_String_Ptr mermemeow = (Vector_String_Ptr) malloc(sizeof(Vector_String));
	if(mermemeow){
		mermemeow->data = (String_Ptr*) malloc(sizeof(String_Ptr));
		if (mermemeow->data){
			mermemeow->size = 0;
			mermemeow->capacity = 1;
		}
		else {
			free(mermemeow);
		}
	}
	return mermemeow;
}

// Precondition: phVectorString: a pointer to a handle to a vector of strings
// Postcondition: makes sure that the memory is correctly freed
// You have multiple levels to free accordingly:
// 1- you need to loop through the array of String_Ptr and
// call the strong_destroy function
// 2- You need to free the array itself
// 3- You need to free the vector of strings (*phVectorString)
void vector_string_destroy(Vector_String_Ptr * phVectorString)
{
	if(phVectorString)
	{
		if((*phVectorString)->data)
		{
			int i = 0;
			while (i < (*phVectorString)->size)
			{
				string_destroy(&((*phVectorString)->data[i]));
				i++;
			}
			free((*phVectorString)->data);
		}
		free(*phVectorString);
		phVectorString=NULL;
	}
}

// Precondition: hVectorString: a handle to a vector of strings and
// hString: a handle to the string to be added. The string is already
// created and allocated by the calling program. Check if the hString
// is NULL before adding it to the vector.
// Postcondition: Adding a handle to a string to the end of the vector.
// If size == capacity of the vector (i.e, no room to add the string), then 
// the vector needs to expand to hold more strings.
// Returns SUCCESS of the string was successfully added.
// Return FAILURE:
// - hString was NULL or the hVectorString was NULL.
// - Could not expand the internal array
Status vector_string_push_back(Vector_String_Ptr hVectorString, String_Ptr hString)
{
	Status status = SUCCESS;
	if (!hString)
	{
		status = FAILER;
	}
	else{
			if( hVectorString->size == hVectorString->capacity-1)
			{
				String_Ptr * temp = malloc(sizeof(String_Ptr) * hVectorString->capacity * 2);
				if(!temp)
				{
					status = FAILER;
					return status;
				}
				int i;
				for(i=0;i<hVectorString->size;i++)
				{
					temp[i] = hVectorString->data[i];
				}
				free(hVectorString->data);
				hVectorString->data = temp;
				hVectorString->capacity *= 2;
			}
		
		hVectorString->data[hVectorString->size] = string_init_c_string(string_c_str(hString));
		hVectorString->size += 1;
	}

	return status;

}


// Precondition: hVectorString: a handle to a vector of strings to get its size 
// Postcondition: the size of the vector of strings.
int vector_string_get_size(Vector_String_Ptr hVectorString)
{
	return hVectorString->size;
}


// Preconiditon: hVectorString: a handle to a vector of strings to get its capacity 
// Postcondition: the capacity of the vector of strings
int vector_string_get_capacity(Vector_String_Ptr hVectorString)
{
	return hVectorString->capacity;
}

// Precondition: hVectorString: a handle to a vector of strings to check if 
// empty or not
// Postcondition: True if it is empty, false otherwise
Boolean vector_string_empty(Vector_String_Ptr hVectorString)
{
	return hVectorString->size == 0;
}

// Precondition: hVectorString: a handle to a vector of strings and the index of the 
// string to return
// Postcondition: a pointer to a string pointer. Returns null if the
// index is negative or > size.
String_Ptr* vector_string_at(Vector_String_Ptr hVectorString, int index)
{
	if (index >= hVectorString->size || index < 0)
	{
		return NULL;
	}
	return &hVectorString->data[index];

}

