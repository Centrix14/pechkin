#ifndef __PECHKIN_MESSAGE_SEND_SYSTEM_HEADER_FILE_INCLUDED__
#define __PECHKIN_MESSAGE_SEND_SYSTEM_HEADER_FILE_INCLUDED__

#include "tl2/list.h"

typedef struct {
	char name[32];
	void *value;
} msg;

void pl_send(char *name, void *value, size_t size);
void *pl_read(char *msg_name);
void pl_remove(char *msg_name);

msg *pl_get(char *msg_name);
list *pl_get_node(char *msg_name);

void pl_free();

int pl_is_exist(char *msg_name);

list *pl_get_msg_list();
void pl_set_msg_list(list *new_msg_list);

#endif
