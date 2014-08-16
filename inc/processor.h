#ifndef _FOOF_PROCESSOR_H
#define _FOOF_PROCESSOR_H
#include <stdint.h>

typedef enum arch {
	ARCH_NONE,
	ARCH_I386,
	ARCH_AMD64,
} arch_t;

typedef enum mode {
	MODE_OFF,
	MODE_REAL,
	MODE_PROTECTED,
	MODE_LONG,
} mode_t;

typedef union gen_reg {
	uint64_t r;
	uint32_t e;
	uint16_t x;
	uint8_t  h[2];
} gen_reg_t;

typedef struct registers {
	union {
		gen_reg_t num[16];
		// TODO: reorder these to appropriate reg. numbers
		gen_reg_t a, b, c, d, bp, sp, si, di;
	};

	gen_reg_t cs, ss, ds;
	gen_reg_t ip;
	gen_reg_t crt[4];

	uint32_t eflags;

} registers_t;

typedef struct processor {
	arch_t arch;
	mode_t mode;

	registers_t reg;
} processor_t; 

#endif
