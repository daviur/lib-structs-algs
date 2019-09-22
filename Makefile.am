ACLOCAL_AMFLAGS = --install -I m4

dist_doc_DATA = README

include_HEADERS = \
				  src/lib/list.h \
				  src/lib/dlist.h \
				  src/lib/slist.h

lib_LTLIBRARIES = libdasal.la
libdasal_la_SOURCES = \
					  src/lib/list.c \
					  src/lib/dlist.c \
					  src/lib/slist.c
libdasal_la_LDFLAGS = -export-symbols-regex '^dtal_'

check_PROGRAMS = \
				 tests/list_tests \
				 tests/dlist_tests \
				 tests/slist_tests

tests_list_tests_SOURCES = tests/list_tests.c
tests_list_tests_LDADD = libdasal.la
tests_list_tests_CFLAGS = -I$(top_srcdir)/src/lib/
tests_list_tests_LDFLAGS = -lcmocka

tests_dlist_tests_SOURCES = tests/dlist_tests.c
tests_dlist_tests_LDADD = libdasal.la
tests_dlist_tests_CFLAGS = -I$(top_srcdir)/src/lib/
tests_dlist_tests_LDFLAGS = -lcmocka

tests_slist_tests_SOURCES = tests/slist_tests.c
tests_slist_tests_LDADD = libdasal.la
tests_slist_tests_CFLAGS = -I$(top_srcdir)/src/lib/
tests_slist_tests_LDFLAGS = -lcmocka

TESTS = $(check_PROGRAMS)
