#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <limits.h>

#include "ppc.h"

/**
returns a (void) pointer to the memory mapped rom. given by path 
*//

void *open_rom(char *filename)
{
    struct stat st;
    stat(filename, &st);

    int fd = open(filename  , O_RDWR);

    return mmap(NULL,st.st_size,PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <image file name>\n", argv[0]);
        exit(1);
    }

    //open supplied rom file
    int *rom = open_rom(argv[0]);

    //emulated ram
    char *ram = mmap(NULL, UINT_MAX, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS, -1, 0);

    cpu_t cpu;
    bzero(&cpu, sizeof(cpu_t));

    //fetch-decode loop
    for(cpu.ctr_reg = 0;;)
    {
        switch(rom[cpu.ctr_reg])
        {
            case ():
                break;
        }
    }
}
