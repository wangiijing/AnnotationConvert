#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef enum ConverState
{
	c_open,
	c_close
}ConverState;
typedef enum State
{
	SUCCESS,
	FILE_ERROR,
	NO_MATCH
}State;

ConverState Convert();
ConverState AnnotationConvert();