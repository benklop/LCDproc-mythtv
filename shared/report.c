/*
 * report.c
 * This file is part of LCDd, the lcdproc server.
 *
 * This file is released under the GNU General Public License. Refer to the
 * COPYING file distributed with this package.
 *
 * Copyright (c) 1999, William Ferrell, Scott Scriven
 *		 2001, Joris Robijn
 *
 *
 * Contains reporting functions
 *
 */

#include <stdlib.h>
#include "report.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

int report_level = RPT_INFO;
int report_dest = RPT_DEST_STORE;

#define MAX_STORED_MSGS 200

static char *stored_msgs[MAX_STORED_MSGS];
static int stored_levels[MAX_STORED_MSGS];
static int num_stored_msgs = 0;


// local functions
static void store_report_message( int level, const char *message );
static void flush_messages();

void report( const int level, const char *format, .../*args*/ )
{
	// Check if we should report it
	if( level <= report_level || report_dest == RPT_DEST_STORE ) {

	  	char buf[1024];

		// Following functions appear to work on RedHat and Debian
		// Linux, FreeBSD and Solaris

		va_list ap;
		va_start(ap, format); /* measure the required size (the number of elements of format) */

     		switch( report_dest ) {
     		  case RPT_DEST_STDERR:
			vfprintf( stderr, format, ap );
			fprintf( stderr, "\n" );
			break;
		  case RPT_DEST_SYSLOG:
			vsyslog( LOG_USER|(level+2), format, ap );
			break;
		  case RPT_DEST_STORE:
		  	vsnprintf( buf, sizeof(buf), format, ap );
		  	buf[sizeof(buf)-1] = 0; // be sure to have a terminating 0
		  	store_report_message( level, buf );
			break;
		}
		va_end(ap);
	}
}


int set_reporting( int new_level, int new_dest )
{
	if( new_level < RPT_CRIT || new_level > RPT_DEBUG ) {
		report( RPT_ERR, "debug level invalid: %d", new_level );
		return -1;
	}

	if( report_dest != RPT_DEST_SYSLOG && new_dest == RPT_DEST_SYSLOG ) {
		openlog( "LCDd", 0, LOG_USER );
	}
	else if( report_dest == RPT_DEST_SYSLOG && new_dest != RPT_DEST_SYSLOG ) {
		closelog();
	}

	report_level = new_level;
	report_dest = new_dest;

	if( report_dest != RPT_DEST_STORE )
		flush_messages();

	return 0;
}


static void store_report_message( int level, const char *message )
{
	stored_msgs[num_stored_msgs] = malloc(strlen( message )+1);
	strcpy( stored_msgs[num_stored_msgs], message );
	stored_levels[num_stored_msgs] = level;
	num_stored_msgs ++;
}


static void flush_messages()
{
	int i;
	for( i=0; i<num_stored_msgs; i++ ) {
		report( stored_levels[i], "%s", stored_msgs[i] );
		free( stored_msgs[i] );
	}
	num_stored_msgs = 0;
}
