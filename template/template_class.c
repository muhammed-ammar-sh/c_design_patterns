#include <stdio.h>
#include "template_class.h"

static void Template_Step4(template_t *me);

const template_methods_t template_methods = {
	.step_1 = Template_Step1,
	.step_2 = Template_Step2,
	.step_3 = Template_Step3,
	.step_4 = Template_Step4,
};

void Template_Init(template_t *me)
{
	if (me)
	{
		me->methods = &template_methods;
		me->template_val_1 = 0;
		me->template_val_2 = 0;
	}
}

void Template_StartProcess(template_t *me)
{
	if (me && me->methods)
	{
		me->methods->step_1(me);
		me->methods->step_2(me);
		me->methods->step_3(me);
		me->methods->step_4(me);
	}
}

void Template_Step1(template_t *me)
{
	printf("Step 1 method is called from Template class.\n");
}

void Template_Step2(template_t *me)
{
	printf("Step 2 method is called from Template class.\n");
}

void Template_Step3(template_t *me)
{
	printf("Step 3 method is called from Template class.\n");
}

static void Template_Step4(template_t *me)
{
	//printf("Step 4 is an abstract method and should be overriden in subclasses.\n");
	(void*)me;
}
