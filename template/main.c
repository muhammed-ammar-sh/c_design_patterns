#include "template_class.h"
#include "sub_class_1.h"
/**
 * "The Template pattern is designed for situations where we have several 
 * different tasks to accomplish that have some, but not all, steps in 
 * common. The common steps are implemented in a base class, and the 
 * distinct steps are overridden in subclasses to provide custom behavior."
 * "it's an implementation to support the Don't Repeat Yourself principle."
 * Python 3 Object-oriented Programming - Second Edition, Dusty Phillips
 */

void main(void)
{
	sub_class_1_t c;
	SubClass1_Init(&c);
	Template_StartProcess((template_t *)&c);
	/*
	Step 1 method is called from Template class.
	Step 2 method is called from Template class.
	Step 3 method is called from Template class.
	Step 4 method is called from Sub class 1.
	*/
}