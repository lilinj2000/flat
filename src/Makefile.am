AUTOMAKE_OPTIONS = foreign

SUBDIRS = traderflow

bin_PROGRAMS = flat
flat_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc 


flat_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(FLYER_CPPFLAGS) \
		$(AIR_CPPFLAGS)


flat_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FLYER_LIBADD) \
	$(AIR_LIBADD)


flat_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh \
		Log.hh \
		Server.hh


EXTRA_DIST = env.sh flat.cfg log.cfg

flatdir = $(bindir)
flat_DATA = $(EXTRA_DIST)
