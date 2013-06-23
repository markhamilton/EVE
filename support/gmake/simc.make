# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug64
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifndef RESCOMP
  ifdef WINDRES
    RESCOMP = $(WINDRES)
  else
    RESCOMP = windres
  endif
endif

ifeq ($(config),debug64)
  OBJDIR     = obj/x64/Debug/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release64)
  OBJDIR     = obj/x64/Release/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DNDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug64)
  OBJDIR     = obj/x64/Debug/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release64)
  OBJDIR     = obj/x64/Release/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DNDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugdynamic64)
  OBJDIR     = obj/x64/DebugDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasedynamic64)
  OBJDIR     = obj/x64/ReleaseDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethread64)
  OBJDIR     = obj/x64/DebugSingleThread/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethread64)
  OBJDIR     = obj/x64/ReleaseSingleThread/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethreaddynamic64)
  OBJDIR     = obj/x64/DebugSingleThreadDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethreaddynamic64)
  OBJDIR     = obj/x64/ReleaseSingleThreadDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DNDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DNDEBUG -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugdynamic32)
  OBJDIR     = obj/x32/DebugDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasedynamic32)
  OBJDIR     = obj/x32/ReleaseDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethread32)
  OBJDIR     = obj/x32/DebugSingleThread/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethread32)
  OBJDIR     = obj/x32/ReleaseSingleThread/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethreaddynamic32)
  OBJDIR     = obj/x32/DebugSingleThreadDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethreaddynamic32)
  OBJDIR     = obj/x32/ReleaseSingleThreadDynamic/simc
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/libsimc.a
  DEFINES   += -DSIMC_LIBRARY
  INCLUDES  += -I../../external/simc/include -I../../external/simc/external/tinyxml
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/sim_linkedlist.o \
	$(OBJDIR)/sim_xml.o \
	$(OBJDIR)/sim_curtime.o \
	$(OBJDIR)/sim_queue.o \
	$(OBJDIR)/sim_threading.o \
	$(OBJDIR)/tinystr.o \
	$(OBJDIR)/tinyxml.o \
	$(OBJDIR)/tinyxmlerror.o \
	$(OBJDIR)/tinyxmlparser.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking simc
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning simc
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
ifeq (posix,$(SHELLTYPE))
	-$(SILENT) cp $< $(OBJDIR)
else
	$(SILENT) xcopy /D /Y /Q "$(subst /,\,$<)" "$(subst /,\,$(OBJDIR))" 1>nul
endif
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
endif

$(OBJDIR)/sim_linkedlist.o: ../../external/simc/source/sim_linkedlist.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/sim_xml.o: ../../external/simc/source/sim_xml.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/sim_curtime.o: ../../external/simc/source/sim_curtime.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/sim_queue.o: ../../external/simc/source/sim_queue.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/sim_threading.o: ../../external/simc/source/sim_threading.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinystr.o: ../../external/simc/external/tinyxml/tinystr.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinyxml.o: ../../external/simc/external/tinyxml/tinyxml.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinyxmlerror.o: ../../external/simc/external/tinyxml/tinyxmlerror.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/tinyxmlparser.o: ../../external/simc/external/tinyxml/tinyxmlparser.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"

-include $(OBJECTS:%.o=%.d)
