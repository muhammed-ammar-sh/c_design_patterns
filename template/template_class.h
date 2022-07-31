#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H

typedef struct template_struct template_t;

typedef struct 
{
	void (*step_1) (template_t*);
	void (*step_2) (template_t*);
	void (*step_3) (template_t*);
	void (*step_4) (template_t*);
}template_methods_t;

struct template_struct
{
	const template_methods_t * methods;
	int template_val_1;
	int template_val_2;
};

void Template_Init(template_t* me);
void Template_StartProcess(template_t * me);

void Template_Step1(template_t *me);
void Template_Step2(template_t *me);
void Template_Step3(template_t *me);

#endif