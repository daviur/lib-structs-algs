define([NAME], [Data Structures and Algorithms])
define([TARNAME], [dasalg])
define([VERSION_MAJOR], [1])
define([VERSION_MINOR], [0])
define([VERSION_BUG_FIX], [0])
define([BUG_REPORT], [david.urbina@acm.org])

AC_INIT([NAME], [VERSION_MAJOR.VERSION_MINOR.VERSION_BUG_FIX], [BUG_REPORT], [TARNAME])
AC_CONFIG_SRCDIR([src/lib/dats/list.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([autotools])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects no-dist-gzip dist-xz])

AC_PROG_CC
AM_PROG_AR

LT_INIT

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
