#include <stdlib.h>
#include <stdio.h>
#include "string.h"

struct string {

	int size;
	int capacity;
	char* char_arr;
};

String_Ptr string_init_default_function() {
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
	if (pString == NULL) {
		printf("Alloc memory for pString failed.\n");
		exit(1);
	}
	pString->capacity = 7;
	pString->size = 0;
	pString->char_arr = (char*)malloc(sizeof(char)*pString->capacity);
	if (pString->char_arr == NULL) {
		printf("Alloc memory for pString->char_arr failed.\n");
		free(pString);
		exit(1);
	}
	return pString;
}

String_Ptr string_init_c_string(char* str) {
	int i = 0;
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
	if (pString == NULL) {
		printf("Alloc memory for pString failed.\n");
		exit(1);
	}
	while(str[i]!='\0')
	{
	  i++;
	}
	pString->capacity = i + 1;
	pString->size = i;
	pString->char_arr = (char*)malloc(sizeof(char) * pString->capacity);
	if (pString->char_arr == NULL) {
		printf("Alloc memory for pString->char_arr failed.\n");
		exit(1);
	}
	for (i = 0; i < pString->capacity; i++) {
		pString->char_arr[i] = str[i];
	}

	return pString;
}

Status string_destroy(String_Ptr* pPString) {
	Status s = SUCCESS;
	if(*pPString)
	{
		if ((*pPString)->char_arr)
		{	
			free((*pPString)->char_arr);
			//pPString = NULL;
			//printf("Successful destory string\n");
		}
		else
		{
			s = FAILER;
			printf("Fail destory string\n");
		}
		free((*pPString));
		pPString = NULL;
	}
	else
	{
		s = FAILER;
		printf("Fail destory string\n");
	}

	return s;
}

int string_compare(String_Ptr str1, String_Ptr str2) {
	int i;
	if (str1->size > str2->size) return 2;
	if (str1->size < str2->size) return -2;
	if (str1->size == str2->size) {
		for (i = 0; i < str1->capacity; i++) {
			if (str1->char_arr[i] > str2->char_arr[i])
				return 1;
			if (str1->char_arr[i] < str2->char_arr[i])
				return -1;
		}
	}
	return 0;
}

int string_get_size(String_Ptr hString) {
	return hString->size;
}

int string_get_capacity(String_Ptr hString) 
{
	return hString->capacity;
}

Status string_extraction(String_Ptr str, FILE * fp) 
{
	Status s = SUCCESS;
	char c, *copy;
	int i = 0;
	if(fp == NULL)
	{
		printf("Failed to read file!\n");
		s = FAILER;
		return s;
	}
	
	while (fscanf(fp, "%c", &c) != -1) {
		if ((c == ' ' || c == '\n') && i != 0) {
			ungetc(c, fp);
			break;	
		}
		if (c != ' ' && c != '\n') {
			str->char_arr[i] = c;
			i++;
			str->size = i;
		}
		if (i == str->capacity) {
			copy = (char*)malloc(sizeof(char) * str->capacity);
			for (i = 0; i<str->size; i++) 
				copy[i] = str->char_arr[i];
			free(str->char_arr);
			str->capacity = str->capacity * 2;
			str->char_arr = (char*)malloc(sizeof(char) * str->capacity);
			for (i = 0; i<str->size; i++)
				str->char_arr[i] = copy[i];
			free(copy);
		}
		
	}
	
	if (i == 0) {
		str->size = 0;
		s = FAILER;
		//printf("File is empty.\n");
		return s;
	}
	str->char_arr[i] = '\0';
	return s;
}

Status string_insertion(String_Ptr str, FILE * fp)
{
	Status s = SUCCESS;
	if(fp == NULL)
	{
		printf("Failed to read file!\n");
		s = FAILER;
		return s;
	}
	int i = 0;
	while (str->char_arr[i] != '\0')
	{
		fputc(str->char_arr[i], fp);
		i++;
	}
	return s;
}

Status string_push_back(String_Ptr hString, char item) {
	int i;
	char* copy;
	Status s = SUCCESS;
	if (hString->size == hString->capacity - 1) {
		copy = (char*)malloc(sizeof(char) * hString->capacity);
		for (i = 0; i<hString->size; i++)
			copy[i] = hString->char_arr[i];
		copy[i] = '\0';
		free(hString->char_arr);
		hString->capacity = hString->capacity * 2;
		hString->char_arr = (char*)malloc(sizeof(char) * hString->capacity);
		if (hString->char_arr == NULL)
		{
			printf("Failed to resize the string!\n");
			s = FAILER;
			return s;
		}
		
		for (i = 0; i<hString->size; i++)
			hString->char_arr[i] = copy[i];
		free(copy);
		hString->char_arr[i] = '\0';
	}
	hString->char_arr[hString->size] = item;
	hString->size++;
	hString->char_arr[hString->size] = ' ';
	hString->size++;
	hString->char_arr[hString->size] = '\0';
	return s;
}

Status string_pop_back(String_Ptr hString) {
	Status s = SUCCESS;
	if(hString->size == 0)
	{
		printf("String is empty!\n");
		s = FAILER;
		return s;
	}
	hString->size--;
	hString->char_arr[hString->size] = '\0';
	
	return s;
}

char* string_at(String_Ptr hString, int index)
{
	if(index > hString->size)
		return NULL;

	return &hString->char_arr[index];
}

char* string_c_str(String_Ptr hString)
{
	char* copy;
	int i;
	/**
	if(hString->char_arr[hString->size] != '\0'){
		copy = (char*)malloc(sizeof(char) * (hString->size+1));
		for (i = 0; i<hString->size; i++)
			copy[i] = hString->char_arr[i];
		copy[i] = '\0';
		free(hString->char_arr);
		hString->char_arr = copy;
		hString->capacity = hString->size+1;	
	}
	**/
	return hString->char_arr;
}

Status string_concat(String_Ptr hResult, String_Ptr hAppend)
{
	Status s = SUCCESS;
	char* copy;
	int i;
	if(hAppend->size == 0)
	{
		s = FAILER;
	}
	else if(hResult->size == 0)
	{
		for (i = 0; i<hAppend->size; i++)
			hResult->char_arr[i] = hAppend->char_arr[i];
		hResult->size = hAppend->size;
		hResult->capacity =hResult->size +1; 
	}
	else
	{
		int size = hResult->size + hAppend->size + 1;
		int cap = size + 1;
		copy = (char*)malloc(sizeof(char) * cap);
		if (copy == NULL)
		{
			s = FAILER;
			return s;
		}
		for (i = 0; i<hResult->size; i++)
			copy[i] = hResult->char_arr[i];
		copy[i] = ' ';
		for (i = 0; i<hAppend->size; i++)
			copy[hResult->size+1+i] = hAppend->char_arr[i];
		copy[hResult->size+1+i] = '\0';
		free(hResult->char_arr);
		hResult->char_arr = copy;
		hResult->capacity = cap;
		hResult->size = size;	
	}
	return s;
}

Boolean string_empty(String_Ptr hString)
{
	if(hString->size == 0)
		return TRUE;
	else
		return FALSE;
}
