#include <stdio.h>
#include <string.h>

#include "tl2/list.h"
#include "st.h/st.h"
#include "pl.h"

st_name("t3");
st_debug_start(1);

int main() {
	st_start();

	char *names[] = {"It", "is", "a", "Pechkin", "test"};
	char *values[] = {"It-msg", "is-msg", "a-msg", "Pechkin-msg", "test-msg"};

	for (int i = 0; i < 5; i++)
		pl_send(names[i], values[i], strlen(values[i]) + 1);

	printf("| pl_is_exist(It)? = %d\n", pl_is_exist("It"));
	printf("| pl_is_exist(Qwerty)? = %d\n", pl_is_exist("Qwerty"));

	st_end();
	return 0;
}
