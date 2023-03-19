/*

test.capi.c

*/

#include <stdlib.h>
#include <stdio.h>
#include "window/Window.capi.h"

void ErrorHandler(void *obj, const char *err, void *upointer) {
	printf("%s from object %llx", err, (unsigned long long)obj);
}

int main(int argc, char** argv) {
	LoveObject *win;

	win = windowNew(ErrorHandler, NULL);



	windowDelete(win);
	
	return 0;
}