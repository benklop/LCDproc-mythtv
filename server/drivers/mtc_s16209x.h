/*
 * LCD Driver for MTC_S16209x LCD display, used with lcdproc (lcdproc.org)
 * Copyright (C) 2002 SecureCiRT, A SBU of Z-Vance Pte Ltd (Singapore)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

/*
 * Michael Boman - SecureCiRT Security Architect <michael.boman@securecirt.com>
 *
 * Heres a bit more info on the display.
 * It is the MTC-S16209x and is made by Microtips Technology Inc, Taiwan
 * The web page for it is http://www.microtips.com.tw
 *
 * The LCD is optional front panel for Gigabyte GS-SR104 system from
 * Gigabyte (http://www.gigabyte.com.tw)
 *
 */

#ifndef MTC_S16209X_H
#define MTC_S16209X_H

#include "lcd.h"

MODULE_EXPORT int  MTC_S16209X_init(Driver * drvthis, char *device);
MODULE_EXPORT void MTC_S16209X_close(Driver * drvthis);
MODULE_EXPORT int  MTC_S16209X_width (Driver *drvthis);
MODULE_EXPORT int  MTC_S16209X_height (Driver *drvthis);
MODULE_EXPORT void MTC_S16209X_clear (Driver * drvthis);
MODULE_EXPORT void MTC_S16209X_flush(Driver * drvthis);
MODULE_EXPORT void MTC_S16209X_string (Driver * drvthis, int x, int y, char string[]);
MODULE_EXPORT void MTC_S16209X_chr(Driver * drvthis, int x, int y, char c) ;
int MTC_S16209X_gotoxy(int x, int y);

MODULE_EXPORT void MTC_S16209X_old_vbar(Driver * drvthis, int x, int len);
MODULE_EXPORT void MTC_S16209X_old_hbar(Driver * drvthis, int x, int y, int len);
MODULE_EXPORT void MTC_S16209X_num(Driver * drvthis, int x, int num);
MODULE_EXPORT int  MTC_S16209X_icon(Driver * drvthis, int x, int y, int icon);

MODULE_EXPORT void MTC_S16209X_set_char(Driver * drvthis, int n, char *dat);

MODULE_EXPORT void MTC_S16209X_backlight(Driver * drvthis, int on);

MODULE_EXPORT void MTC_S16209X_init_vbar(Driver * drvthis);
MODULE_EXPORT void MTC_S16209X_init_hbar(Driver * drvthis);
MODULE_EXPORT void MTC_S16209X_init_num(Driver * drvthis);

#endif
