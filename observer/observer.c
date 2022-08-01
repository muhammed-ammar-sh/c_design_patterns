#include "observer.h"

void ObserverCore_Init(observer_core_t *self)
{
	self->_list.count = 0;
	self->_list.head = NULL;
	self->_list.tail = NULL;
	self->data = 0;
}

void ObserverCore_Attach(observer_core_t *self, observer_t *observer, ob_updated_cb_t cb, void *cb_obj)
{
	if (self && observer)
	{
		observer->cb = cb;
		observer->cb_obj = cb_obj;
		ldlInsertTail(&self->_list, observer);
	}
}

void ObserverCore_Remove(observer_core_t *self, observer_t *observer)
{
	if (self && observer)
	{
		ldlDelete(&self->_list, observer);
	}
}
void ObserverCore_Set(observer_core_t *self, observer_data_t data)
{
	if (self)
	{
		self->data = data;
		observer_t *ob;
		LIST_DL_FOREACH(ob, &self->_list)
		{
			ob->cb(ob->cb_obj, data);
		}
	}
}

observer_data_t ObserverCore_Get(observer_core_t *self)
{
	return self->data;
}