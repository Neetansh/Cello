/*
** == List ==
**
**  + A dynamically sized list of data objects
**  + Simply contains pointers to data objects
**  + Is not responsible object deallocation
*/

#ifndef ListPlus_h
#define ListPlus_h

#include "Prelude+.h"
#include "Type+.h"

module List;

data {
  var type;
  int num_items;
  int num_slots;
  var* items;
  int cursor;
} ListData;

/** List_New(var self, int count, ... items) */
var List_New(var self, va_list* args);
var List_Delete(var self);
void List_Assign(var self, var obj);
var List_Copy(var self);

bool List_Eq(var self, var obj);

int List_Len(var self);
bool List_IsEmpty(var self);
void List_Clear(var self);
bool List_Contains(var self, var obj);
void List_Discard(var self, var obj);

void List_Push_Back(var self, var obj);
void List_Push_Front(var self, var obj);
void List_Push_At(var self, var obj, int i);

var List_Pop_Back(var self);
var List_Pop_Front(var self);
var List_Pop_At(var self, int i);

var List_At(var self, int i);
void List_Set(var self, int i, var obj);

var List_Iter_Start(var self);
var List_Iter_End(var self);
var List_Iter_Next(var self, var curr);

instance(List, New) = { sizeof(ListData), List_New, List_Delete };
instance(List, Assign) = { List_Assign };
instance(List, Copy) = { List_Copy };
instance(List, Eq) = { List_Eq };
instance(List, Collection) = { List_Len, List_IsEmpty, List_Clear, List_Contains, List_Discard };
instance(List, Push) = { List_Push_Back, List_Push_At, List_Push_Back, List_Push_Front, List_Pop_Back, List_Pop_At, List_Pop_Back, List_Pop_Front };
instance(List, At) = { List_At, List_Set };
instance(List, Iter) = { List_Iter_Start, List_Iter_End, List_Iter_Next };



#endif