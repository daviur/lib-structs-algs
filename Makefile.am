ACLOCAL_AMFLAGS = --install -I m4

dist_doc_DATA = README

include_HEADERS = src/lib/list.h

lib_LTLIBRARIES = libdasal.la
libdasal_la_SOURCES = src/lib/list.c
libdasal_la_LDFLAGS = -export-symbols-regex '^dtal_'

check_PROGRAMS = tests/list_tests
tests_list_tests_SOURCES = tests/list_tests.c
tests_list_tests_LDADD = libdasal.la
tests_list_tests_CFLAGS = -I$(top_srcdir)/src/lib/
tests_list_tests_LDFLAGS = -lcmocka
TESTS = $(check_PROGRAMS)
