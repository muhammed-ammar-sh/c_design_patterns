
#include "list_dl.h"

typedef float observer_data_t;

typedef void (*ob_updated_cb_t)(void *obj, observer_data_t data);

typedef struct
{
	tsLdlItem _item;
	ob_updated_cb_t cb;
	void *cb_obj;
} observer_t;

typedef struct
{
	tsLdl _list;
	observer_data_t data;
} observer_core_t;

void ObserverCore_Init(observer_core_t *self);
void ObserverCore_Attach(observer_core_t *self, observer_t *observer, ob_updated_cb_t cb, void* cb_obj);
void ObserverCore_Remove(observer_core_t *self, observer_t *observer);
void ObserverCore_Set(observer_core_t* self, observer_data_t data);
observer_data_t ObserverCore_Get(observer_core_t* self);