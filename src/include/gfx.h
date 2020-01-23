#pragma once
/* gfx driver includes */

/* (init_gfx): Initialize the gfx driver */
extern void init_gfx();

/* (cls): Clear the Screen */
extern void cls();

/* (settextcolour): Set the foreground and background colour */
extern void settextcolour(unsigned char forecolour, unsigned char backcolour);

/* (resettextcolour): Reset the text colour to white on black */
extern void resettextcolour();

/* (putch): Put a character to the screen */
extern void putch(unsigned char c);

/* (puts): Put a string to the screen */
extern void puts(char *str);

