lib_LTLIBRARIES = libirstlm.la
	
AM_CXXFLAGS = -isystem/usr/include -W -Wall -ffor-scope -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES $(BOOST_CPPFLAGS) -DMYCODESIZE=3

libirstlm_ladir = ${includedir}

libirstlm_la_HEADERS = \
        cmd.h \
        dictionary.h \
        gzfilebuf.h \
        htable.h \
        index.h \
        lmmacro.h \
        lmtable.h \
        mempool.h \
        mfstream.h \
        n_gram.h \
        ngramcache.h \
        ngramtable.h \
        timer.h \
        util.h \
        interplm.h \
        linearlm.h \
        mdiadapt.h \
        mixture.h \
        normcache.h \
        shiftlm.h \
		cplsa.h \
		doc.h

libirstlm_la_SOURCES = \
        cmd.c \
        dictionary.cpp \
        htable.cpp \
        lmmacro.cpp \
        lmtable.cpp \
        mempool.cpp \
        mfstream.cpp \
        n_gram.cpp \
        ngramcache.cpp \
        ngramtable.cpp \
        timer.cpp \
        util.cpp \
        interplm.cpp \
        linearlm.cpp \
        mdiadapt.cpp \
        mixture.cpp \
        normcache.cpp \
        shiftlm.cpp \
		cplsa.cpp \
		doc.cpp

CLEANFILES = $(BUILT_SOURCES)

libirstlm_la_LIBADD = $(BOOST_LDFLAGS) $(BOOST_THREAD_LIB)

bin_PROGRAMS = dict ngt compile-lm interpolate-lm prune-lm quantize-lm prune-lm score-lm tlm plsa

dict_SOURCES = dict.cpp
ngt_SOURCES = ngt.cpp
compile_lm_SOURCES = compile-lm.cpp
interpolate_lm_SOURCES = interpolate-lm.cpp
prune_lm_SOURCES = prune-lm.cpp
quantize_lm_SOURCES = quantize-lm.cpp
score_lm_SOURCES = score-lm.cpp
tlm_SOURCES = tlm.cpp
plsa_SOURCES = plsa.cpp


LDADD = -lirstlm 
DEPENDENCIES = libirstlm.la

