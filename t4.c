#include <stdio.h>

#include "pl.h"
#include "st.h/st.h"

st_name("t4");
st_debug_start(1);

void send_arg(int arg) {
	pl_send("send-arg-msg", &arg, sizeof(int));
}

void read_arg() {
	printf("arg = %d\n", *(int*)pl_read("send-arg-msg"));
}

int main() {
	st_start();

	send_arg(123);
	read_arg();

	st_end();
	return 0;
}
