#ifndef MODE_H
#define MODE_H

#include "main.h"

//TODO: get rid of these global variables!
extern char *tmp;
extern char *buffer;

int mode_init ();
void mode_close ();

int update_screen (mode * m, int display);
int credit_screen (int rep, int display, int *flags_ptr);

#endif
