#@copyright : abdallah_ahmed
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2 
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ=$(As:.s=.o)
PROJECT_NAME =learn_in_depth_cortex_m3_aa

all: $(PROJECT_NAME).hex

%.o:%.c
	$(CC)gcc.exe -c  $(CFLAGS) $(INCS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(LIBS)$(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
$(PROJECT_NAME).hex:	$(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $<  $@
	
clean_all:
	
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin