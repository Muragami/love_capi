/*

test.capi.c

*/

#include <stdlib.h>
#include <stdio.h>
#include "window/Window.capi.h"

void ErrorHandler(void *obj, const char *err, void *upointer) {
	printf("%s from object [%llx]", err, (unsigned long long)obj);
}

int main(int argc, char** argv) {
	LoveObject *win;
	windowSettings winSettings;

	windowSetDefaultSettings(&winSettings);

	win = windowNew(ErrorHandler, NULL);

	if (windowSetWindow(win, 800, 600, &winSettings) == TRUE) {

	} else {
		
	}

	windowDelete(win);
	
	return 0;
}