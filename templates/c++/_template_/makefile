# chuckeng: 07/06/2017
#  updated: 08/16/2018
EXE::=a.out
SRCDIR::=src
BLDDIR::=build
# uncoment to add packages - use the following command to discover installed packages
#    pkg-config --list-all
CCPKGS::=
#CCPKGS::=$(shell pkg-config --cflags gtkmm-3.0 freetype2)
#CCPKGS::=$(shell pkg-config --cflags libavformat libavcodec libavutil x264 x265)
CPPPKGS::=
#CPPPKGS::=$(shell pkg-config --cflags gtkmm-3.0 freetype2)
#CPPPKGS::=$(shell pkg-config --cflags libavformat libavcodec libavutil x264 x265)
LIBS::=-pthread -lm
#LIBS+=$(shell pkg-config --libs gtkmm-3.0 freetype2)
#LIBS+=$(shell pkg-config --libs libavformat libavcodec libavutil x264 x265)

#CPP::=clang++
#CC::=clang
CPP::=g++
CC::=gcc
#SHELL::=/bin/sh

# make DEBUG=1 for debug
# make DEBUG=0 for release
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	BLDTYPE::=debug
else
	BLDTYPE::=release
endif
OUTDIR::=$(BLDDIR)/$(BLDTYPE)
ifeq ($(DEBUG), 1)
	CPPFLAGS::=-g -DDEBUG -O0 -Wall -std=c++14 $(CPPPKGS)
	CCFLAGS::=-g -DDEBUG -O0 -Wall -std=c99 $(CCPKGS)
	LINKFLAGS::=-Wl,-Map,$(OUTDIR)/$(EXE).map -g $(LIBS)
else
	CPPFLAGS::=-DNDEBUG -O3 -Wall -std=c++14 $(CPPPKGS)
	CCFLAGS::=-DNDEBUG -O3 -Wall -std=c99 $(CCPKGS)
	LINKFLAGS::=-Wl,-Map,$(OUTDIR)/$(EXE).map -s -O3 $(LIBS)
endif

CSRCS::=$(notdir $(wildcard $(SRCDIR)/*.c))
CDEPS::=$(notdir $(wildcard $(SRCDIR)/*.h))
COBJS::=$(CSRCS:.c=.o)
SRCS::=$(notdir $(wildcard $(SRCDIR)/*.cpp))
DEPS::=$(notdir $(wildcard $(SRCDIR)/*.hpp)) $(CDEPS)
OBJS::=$(SRCS:.cpp=.o)

# link program
# add following line for ui
#cp $(SRCDIR)/*.ui $(OUTDIR)
$(OUTDIR)/$(EXE): $(OUTDIR) $(addprefix $(OUTDIR)/,$(COBJS)) $(addprefix $(OUTDIR)/,$(OBJS))
	@echo "\nLinking for $(BLDTYPE): $(EXE)..."
	$(CPP) $(addprefix $(OUTDIR)/,$(OBJS)) -o $@ $(LINKFLAGS)

# compile C
$(OUTDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(SRCDIR)/,$(CDEPS))
	@echo "\nCompiling $(notdir $<)..."
	$(CC) -c $(CCFLAGS) $< -o $@

# compile C++
$(OUTDIR)/%.o: $(SRCDIR)/%.cpp $(addprefix $(SRCDIR)/,$(DEPS))
	@echo "\nCompiling $(notdir $<)..."
	$(CPP) -c $(CPPFLAGS) $< -o $@

# create output build folder
$(OUTDIR):
	@echo "Creating build output folder: '$(OUTDIR)'"
	@mkdir -p $(OUTDIR)

.PHONY: check clean gone
check:
	@echo CSRCS=$(CSRCS)
	@echo COBJS=$(COBJS)
	@echo CDEPS=$(CDEPS)
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)
	@echo DEPS=$(DEPS)
	@echo REQS=$(addprefix $(OUTDIR)/,$(COBJS)) $(addprefix $(OUTDIR)/,$(OBJS))

clean:
	@$(RM) -rf $(BLDDIR)/*

gone:
	@$(RM) -rf $(BLDDIR)/
