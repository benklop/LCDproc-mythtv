/* acconfig.h
*   $Id: acconfig.h,v 1.22 2002/10/22 06:49:24 hmilz Exp $
*   This file is in the public domain.
*
*   Descriptive text for the C preprocessor macros that
*   the distributed Autoconf macros can define.
*   No software package will use all of them; autoheader copies the ones
*   your configure.in uses into your configuration header file templates.
*
*   The entries are in sort -df order: alphabetical, case insensitive,
*   ignoring punctuation (such as underscores).  Although this order
*   can split up related entries, it makes it easier to check whether
*   a given entry is in the file.
*
*   To add a new driver, insert the appropriate variable into
*   this list alphabetically.
*/
/*   Leave the following blank line there!!  Autoheader needs it.  */


#undef CURSES_HAS__ACS_CHAR

#undef CURSES_HAS_ACS_MAP

#undef CURSES_HAS_REDRAWWIN

#undef CURSES_HAS_WCOLOR_SET

#undef DEBUG

#undef DEFINED_ACS

#undef LCDPORT

#undef LINUX

#undef LOAD_MAX

#undef LOAD_MIN

/* Define the package name */
#undef PACKAGE

/* Define the protocol version */
#undef PROTOCOL_VERSION

#undef API_VERSION

#undef MODULE_EXTENSION

#undef SGX120_DRV

#undef SLI_DRV

#undef SOLARIS

#undef STAT_NFS

#undef STAT_SMBFS

/* Define for AIX if your compiler is a genuine IBM xlC/xlC_r
   and you want support for AIX C++ shared extension modules. */
#undef AIX_GENUINE_CPLUSPLUS

/* two-argument statfs with statfs.bsize member (AIX, 4.3BSD) */
#undef STAT_STATFS2_BSIZE

/* two-argument statfs with statfs.fsize member (4.4BSD and NetBSD) */
#undef STAT_STATFS2_FSIZE

/* two-argument statfs with struct fs_data (Ultrix) */
#undef STAT_STATFS2_FS_DATA

/* 3-argument statfs function (DEC OSF/1) */
#undef STAT_STATFS3_OSF1

/* four-argument statfs (AIX-3.2.5, SVR3) */
#undef STAT_STATFS4

/* Define if you have the statvfs function */
#undef STAT_STATVFS

#undef SVGALIB_DRV

#undef TEXT_DRV

#undef T6963_DRV

/* Define the package version */
#undef VERSION

/* Leave that blank line there!!  Autoheader needs it.
   If you're adding to this file, keep in mind:
   The entries are in sort -df order: alphabetical, case insensitive,
   ignoring punctuation (such as underscores).  */
