#ifndef __PECHKIN_MESSAGE_SEND_SYSTEM_HEADER_FILE_INCLUDED__
#define __PECHKIN_MESSAGE_SEND_SYSTEM_HEADER_FILE_INCLUDED__

typedef struct {
	char name[32];
	void *value;
} msg;

void pl_send(char *name, void *value, size_t size);
void *pl_read(char *msg_name);

msg *pl_get(char *msg_name);
list *pl_get_node(char *msg_name);

void pl_free();

#endif
