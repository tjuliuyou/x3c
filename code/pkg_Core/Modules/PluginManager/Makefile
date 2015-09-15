ROOTDIR = ../../../..
include $(ROOTDIR)/config.mk

CFLAGS_SO   +=   -I$(INCLUDE_DIR)/pkg_Core/Interface

ifeq ($(OS),Darwin)
all:
	$(CC) $(CFLAGS_SO) -c  Cx_ObjectFactory.cpp
	$(CC) $(CFLAGS_SO) -c  Module.cpp
	$(CC) $(CFLAGS_SO) -c  Cx_PluginLoader.cpp
	$(CC) $(CFLAGS_SO) -c  DelayLoad.cpp
	
	$(CC) $(C_FLAGS_SO) -o $(PLUGINS_DIR)/libPluginManager.dylib *.o $(LIBS)
else
all:
	$(CC) $(CFLAGS_SO) -c  Cx_ObjectFactory.cpp
	$(CC) $(CFLAGS_SO) -c  Module.cpp
	$(CC) $(CFLAGS_SO) -c  Cx_PluginLoader.cpp
	$(CC) $(CFLAGS_SO) -c  DelayLoad.cpp
	$(CC) $(C_FLAGS_SO) -o $(PLUGINS_DIR)/libPluginManager.so *.o $(LIBS)	
endif

clean:
	rm -rf *.so
	rm -rf *.dylib
	rm -rf *.o


