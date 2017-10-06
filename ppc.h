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
