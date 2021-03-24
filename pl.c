#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tl2/list.h"
#include "pl.h"

static list *msg_list = NULL;

void pl_init_list() {
	msg_list = list_init_node(NULL);
}

void pl_send(char *name, void *value, size_t size) {
	static char is_first = 0;
	list *last = NULL;
	msg *message = NULL;

	if (!is_first) {
		pl_init_list();

		is_first = 1;
	}

	list_add_node(msg_list);

	last = list_get_last(msg_list);

	message = (msg*)malloc(sizeof(msg));
	strcpy(message->name, name);

	message->value = malloc(size);
	memcpy(message->value, value, size);

	list_set_data(last, message);
}

void pl_free() {
	list_free_list(msg_list);
}

msg *pl_get(char *msg_name) {
	list *lptr = NULL;
	msg *message = NULL;

	lptr = msg_list;
	while (lptr) {
		if (lptr && lptr->data)
			message = (msg*)lptr->data;
		if (message && !strcmp(msg_name, message->name))
			return message;

		lptr = lptr->next;
	}

	return NULL;
}

void *pl_read(char *msg_name) {
	msg *message = NULL;

	message = pl_get(msg_name);
	if (message)
		return message->value;
	return NULL;
}

list *pl_get_node(char *msg_name) {
	list *lptr = NULL;
	msg *message = NULL;

	lptr = msg_list;
	while (lptr) {
		if (lptr && lptr->data)
			message = (msg*)lptr->data;
		if (message && !strcmp(msg_name, message->name))
			return lptr;

		lptr = lptr->next;
	}

	return NULL;
}

void pl_remove(char *msg_name) {
	list *lptr = NULL;
	msg *message = NULL;

	if (!pl_is_exist(msg_name))
		return ;

	lptr = pl_get_node(msg_name);

	// free data
	message = (msg*)lptr->data;
	free(message->value);
	free(message);

	// unlink node
	if (lptr->prev)
		lptr->prev->next = lptr->next;
	if (lptr->next)
		lptr->next->prev = lptr->prev;

	free(lptr);
}

int pl_is_exist(char *msg_name) {
	return pl_read(msg_name) ? 1 : 0;
}
