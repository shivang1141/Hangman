#include "array_vector.h"
#include <stdlib.h>
#include <stdio.h>

Vector_String_Ptr * load_array_vector_string(FILE * words)
{
	Vector_String_Ptr * vString_Ptr = malloc(sizeof(Vector_String_Ptr)*30);
	if(vString_Ptr)
	{
		int i = 0;
		for (i = 0; i < 30; i++)
		{
			vString_Ptr[i] = vector_string_init_default();
		}
		
		String_Ptr hstring = string_init_default_function();

		while(string_extraction(hstring, words))
		{

			if (hstring->size >= 30)
			{
				printf("size larger than index 29.\n");
				exit(1);
			}

			vector_string_push_back(vString_Ptr[hstring->size-1], hString);
		}

		string_destroy(&hstring);
	}
	
	return vString_Ptr;
}

void destroy_array_vector_string(Vector_String_Ptr ** pArray)
{
	if(pArray)
	{
		for(int i = 0; i < 30; i++)
		{
			vector_string_destroy(&(*pArray)[i]);
		}
	
		free(*pArray);
		pArray=NULL;
	}
}