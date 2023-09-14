EE_TOOL_PREFIX = mips64r5900el-ps2-elf-
EE_CC := $(EE_TOOL_PREFIX)gcc

EE_OBJS = main.o log.o mips.o memalloc.o injector.o

MKDIR = mkdir

EE_SRC_DIR = src/
EE_INC_DIR = include/
EE_OBJS_DIR = obj/
EE_BIN_DIR = bin/

EE_INCS := -I$(EE_INC_DIR)
EE_OBJS := $(EE_OBJS:%=$(EE_OBJS_DIR)%)
EE_LIBS = -lc -lgcc
EE_BIN := $(EE_BIN_DIR)B4Plugin.elf

BASE_ADDRESS = 0x02100000
EE_LINKFILE = Linkfile

EE_WARNFLAGS = -Wall
EE_OPTFLAGS = -Os
EE_LDFLAGS = -Wl,--entry=init -Wl,-zmax-page-size=128 -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'
EE_CFLAGS := -D_EE -G0 $(EE_OPTFLAGS) $(EE_WARNFLAGS) $(EE_INCS)

DIR_GUARD = @$(MKDIR) -p $(@D)

$(EE_OBJS_DIR)%.o: $(EE_SRC_DIR)%.c
	$(DIR_GUARD)
	$(EE_CC) $(EE_CFLAGS) -c $< -o $@
	
$(EE_BIN): $(EE_OBJS)
	$(DIR_GUARD)
	$(EE_CC) -T$(EE_LINKFILE) $(EE_OPTFLAGS) -o $(EE_BIN) -nostartfiles -nostdlib -nodefaultlibs $(EE_OBJS) $(EE_LDFLAGS) $(EE_LIBS)

clean:
	rm -f -r $(EE_OBJS_DIR) $(EE_BIN_DIR)

all: clean $(EE_BIN)

re: clean all
