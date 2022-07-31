#include <stdio.h>
#include "sub_class_1.h"

static void SubClass1_Step4(template_t *me);

const template_methods_t sub_class_methods = {
	.step_1 = Template_Step1,
	.step_2 = Template_Step2,
	.step_3 = Template_Step3,
	.step_4 = SubClass1_Step4,
};

void SubClass1_Init(sub_class_1_t *me)
{
	if (me)
	{
		Template_Init((template_t *)me);
		me->super.methods = &sub_class_methods;
		me->sub_class_var_1 = 0;
		me->sub_class_var_2 = 0;
	}
}

static void SubClass1_Step4(template_t *me)
{
	sub_class_1_t *sub_me = (sub_class_1_t *)me;
	(void*)sub_me;
	printf("Step 4 method is called from Sub class 1.\n");
}
