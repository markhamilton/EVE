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
  OBJDIR     = obj/x64/Debug/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVEd
  DEFINES   += -DDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release64)
  OBJDIR     = obj/x64/Release/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE
  DEFINES   += -DNDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug64)
  OBJDIR     = obj/x64/Debug/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVEd
  DEFINES   += -DDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release64)
  OBJDIR     = obj/x64/Release/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE
  DEFINES   += -DNDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugdynamic64)
  OBJDIR     = obj/x64/DebugDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVEd
  DEFINES   += -DEVE_SIM -DDEBUG -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasedynamic64)
  OBJDIR     = obj/x64/ReleaseDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE
  DEFINES   += -DEVE_SIM -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethread64)
  OBJDIR     = obj/x64/DebugSingleThread/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_std
  DEFINES   += -DEVE_SIM -DDEBUG -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethread64)
  OBJDIR     = obj/x64/ReleaseSingleThread/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_st
  DEFINES   += -DEVE_SIM -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethreaddynamic64)
  OBJDIR     = obj/x64/DebugSingleThreadDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_std
  DEFINES   += -DEVE_SIM -DDEBUG -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethreaddynamic64)
  OBJDIR     = obj/x64/ReleaseSingleThreadDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_st
  DEFINES   += -DEVE_SIM -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVEd32
  DEFINES   += -DDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE32
  DEFINES   += -DNDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVEd32
  DEFINES   += -DDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE32
  DEFINES   += -DNDEBUG -DEVE_SIM
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugdynamic32)
  OBJDIR     = obj/x32/DebugDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVEd32
  DEFINES   += -DEVE_SIM -DDEBUG -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasedynamic32)
  OBJDIR     = obj/x32/ReleaseDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE32
  DEFINES   += -DEVE_SIM -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethread32)
  OBJDIR     = obj/x32/DebugSingleThread/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_std32
  DEFINES   += -DEVE_SIM -DDEBUG -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethread32)
  OBJDIR     = obj/x32/ReleaseSingleThread/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_st32
  DEFINES   += -DEVE_SIM -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debugsinglethreaddynamic32)
  OBJDIR     = obj/x32/DebugSingleThreadDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_std32
  DEFINES   += -DEVE_SIM -DDEBUG -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),releasesinglethreaddynamic32)
  OBJDIR     = obj/x32/ReleaseSingleThreadDynamic/EVE
  TARGETDIR  = ../../bin
  TARGET     = $(TARGETDIR)/EVE_st32
  DEFINES   += -DEVE_SIM -DEVDS_DYNAMIC -DIVSS_DYNAMIC -DRDRS_DYNAMIC -DSIMC_DYNAMIC -DEVDS_SINGLETHREADED -DIVSS_SINGLETHREADED -DRDRS_SINGLETHREADED -DSIMC_SINGLETHREADED
  INCLUDES  += -I../../include -I../../external/irrlicht/include -I../../external/evds/include -I../../external/simc/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -g -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -lstdc++
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LIBS      += -lm -lpthread -lOgreMain -lOIS -lboost_system
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(RESOURCES) $(ARCH) $(LIBS) $(LDFLAGS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/PlanetManager.o \
	$(OBJDIR)/SimApp.o \
	$(OBJDIR)/Planet.o \
	$(OBJDIR)/EventHandler.o \
	$(OBJDIR)/ScriptConsole.o \

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
	@echo Linking EVE
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
	@echo Cleaning EVE
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

$(OBJDIR)/PlanetManager.o: ../../source/PlanetManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/SimApp.o: ../../source/SimApp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/Planet.o: ../../source/Planet.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/EventHandler.o: ../../source/EventHandler.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"
$(OBJDIR)/ScriptConsole.o: ../../source/ScriptConsole.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -MF $(@:%.o=%.d) -c "$<"

-include $(OBJECTS:%.o=%.d)
