#include <stdio.h>
#include <string.h>

#include "st.h/st.h"
#include "pl.h"

st_name("t1");
st_debug_start(1);

int main() {
	st_start();

	char *names[] = {"It", "is", "a", "Pechkin", "test"};
	char *values[] = {"It-msg", "is-msg", "a-msg", "Pechkin-msg", "test-msg"};

	for (int i = 0; i < 5; i++)
		pl_send(names[i], values[i], strlen(values[i]) + 1);

	st_end();
	return 0;
}
