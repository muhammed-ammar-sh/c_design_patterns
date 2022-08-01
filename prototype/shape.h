#ifndef SHAPE_H
#define SHAPE_H

typedef struct shape_st shape_t;

typedef struct
{
	void (*draw)(shape_t *);
	shape_t *(*clone)(shape_t *);
} shape_methods_t;

struct shape_st
{
	const shape_methods_t *methods;
	int x;
	int y;
	char * color;
};

void Shape_Init(shape_t *shape);

static inline shape_t *Shape_Clone(shape_t *shape)
{
	if (shape && shape->methods && shape->methods->clone)
		return shape->methods->clone(shape);
}

static inline void Shape_Draw(shape_t *shape)
{
	if (shape && shape->methods && shape->methods->draw)
		shape->methods->draw(shape);
}

#endif
