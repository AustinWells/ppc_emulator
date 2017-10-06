#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <limits.h>

#define endian_swap(num) ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000)

typedef int reg;

typedef struct ppc_cpu {
        reg gp_reg[32]; //general purpose
        reg fp_reg[2][32]; //floating point
        reg cond_reg; //condition
        reg fpscr_reg; //Floating Point Status and Control Register
        reg ex_reg; //Exception Register
        reg link_reg; //Link Register
        reg ctr_reg; //Counter Register
        reg instruction_pointer;
} cpu_t;

#define FOUR_GB (1024*1024*1024*4)

void *open_rom(char *filename)
{
    struct stat st;
    stat(filename, &st);

    int fd = open(filename  , O_RDWR);

    return mmap(NULL, st.st_size ,PROT_READ | PROT_EXEC, MAP_SHARED, fd, 0);
}

int main(int argc, char **argv)
{


    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <image file name>\n", argv[0]);
        exit(1);
    }

    int *rom = open_rom(argv[0]);

    char *ram = mmap(NULL, UINT_MAX, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS, -1, 0);

    cpu_t cpu;
    bzero(&cpu, sizeof(cpu_t));

    for(cpu.ctr_reg = 0;;)
    {
        switch(rom[cpu.ctr_reg])
        {
            case ():
                break;
        }

    }

}
