#ifndef SUB_CLASS_1_H
#define SUB_CLASS_1_H

#include "template_class.h"

typedef struct 
{
	template_t super;
	int sub_class_var_1;
	int sub_class_var_2;
}sub_class_1_t;

void SubClass1_Init(sub_class_1_t* me);


#endif