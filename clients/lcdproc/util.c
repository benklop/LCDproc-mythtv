/******************************************************************************
*
*  util.c - utility functions to print some numerical values in a nice fashion
*  Copyright (C) 2005  Peter Marschall
*
*  ---
*
*  This program is free software; you can redistribute it and/or
*  modify it under the terms of the GNU General Public License
*  as published by the Free Software Foundation; either version 2
*  of the License, or (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*  ---
*
*  $Source: /root/lcdproc.cvs/lcdproc/lcdproc/clients/lcdproc/util.c,v $
*  $Revision: 1.5 $
*  Checked in by: $Author: marschap $
*
*******************************************************************************/

#include "util.h"


/** print a memory value with the correct unit to a given string */
char *
sprintf_memory(char *dst, double value, double roundlimit)
{
	if (dst != NULL) {
		char *format = "%.1f%s";

		char *unit = convert_double(&value, 1024, roundlimit);

		if (value < 100)
			format = "%.2f%s";
		if (value < 10)
			format = "%.3f%s";

		sprintf(dst, format, value, unit);
	}	
	return dst;	
}


/** print a percentage value to a given string */
char *
sprintf_percent(char *dst, double percent)
{
	if (dst != NULL) {
		if (percent > 99.9)
			strcpy(dst, "100%");
		else
			sprintf(dst, "%.1f%%", (percent >= 0) ? percent : 0);
	}	
	return dst;
}

/** converts a value with unit value
 * does not do formatting
 * base : should be 1000 for decimal and 1024 for binary units
 * roundlimit : set < 1.0 if precision of original input value is not sufficient
 */
char *
convert_double(double *value, int base, double roundlimit)
{
	static char *units[] = { "", "k", "M", "G", "T", "P", "E", "Z", "Y", NULL };
	int off = 0;

	if ((roundlimit <= 0.0) || (roundlimit > 1.0))
		roundlimit = 0.5;

	/* Get value's order of magnitude */
	while (units[off] != NULL) {
		/* Note: the check for 1000 is to idenfity the number of
		 * characters in the output needed, not to decide if to scale value.
		 */
		if (*value < 1000 * roundlimit)
			break;
		off++;
		*value /= base;
	}
	return units[off];	
}

/* EOF */
