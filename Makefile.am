ACLOCAL_AMFLAGS = --install -I m4

AM_CFLAGS = \
			-I$(top_srcdir)/src/lib/common/ \
			-I$(top_srcdir)/src/lib/dats/
AM_LDFLAGS = -lcmocka

dist_doc_DATA = README

include_HEADERS = \
				  src/lib/common/helper.h \
				  src/lib/dats/list.h \
				  src/lib/dats/dlist.h \
				  src/lib/dats/slist.h \
				  src/lib/dats/dict.h

lib_LTLIBRARIES = libdasal.la
libdasal_la_SOURCES = \
					  src/lib/dats/list.c \
					  src/lib/dats/dlist.c \
					  src/lib/dats/slist.c \
					  src/lib/dats/dict.c
libdasal_la_LDFLAGS = -export-symbols-regex '^dtal_'

check_PROGRAMS = \
				 tests/list_tests \
				 tests/dlist_tests \
				 tests/slist_tests \
				 tests/dict_tests

# TESTS
tests_list_tests_SOURCES = tests/list_tests.c
tests_list_tests_LDADD = libdasal.la

tests_dlist_tests_SOURCES = tests/dlist_tests.c
tests_dlist_tests_LDADD = libdasal.la

tests_slist_tests_SOURCES = tests/slist_tests.c
tests_slist_tests_LDADD = libdasal.la

tests_dict_tests_SOURCES = tests/dict_tests.c
tests_dict_tests_LDADD = libdasal.la

TESTS = $(check_PROGRAMS)
