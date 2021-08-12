
#ifndef __HIRT_MAXIMUM_LENGTH_SEQUENCES__
#define __HIRT_MAXIMUM_LENGTH_SEQUENCES__

#include <AH_Types.h>

// Feedback Mask

static const AH_UInt32 feedback_mask_vals[] = {0x0u, 0x0u, 0x2u, 0x6u, 0xCu, 0x14u, 0x30u, 0x60u, 0xE1u, 0x100u, 0x240u, 0x500u, 0xE08u, 0x1C80u, 0x3802u, 0x6000u, 0xD008u, 0x12000u, 0x20400u, 0x72000u, 0x90000u, 0x500000u, 0xC00000u, 0x420000u, 0xE10000u};

// MLS Structure

struct t_mls
{
    AH_UInt32 feedback_mask;
    AH_UInt32 lfsr;

    AH_UInt32 T;
    AH_UInt32 order;

    double amp;
};

// Get Length

static inline AH_UInt32 mls_get_length (t_mls *x)
{
    return x->T;
}

// Function Prototypes

void mls_params(t_mls *x, AH_UInt32 log2_T, double amp);
void mls_reset(t_mls *x);

void mls_gen_float(t_mls *x, float *out, AH_UIntPtr N);
void mls_gen_double(t_mls *x, double *out, AH_UIntPtr N);

void mls_gen_block(t_mls *x, void *out, AH_UIntPtr N, AH_Boolean double_precision);
void mls_gen(t_mls *x, void *out, AH_Boolean double_precision);

AH_UInt32 get_next_lfsr_int(AH_UInt32 lfsr, AH_UInt32 feedback_mask) ;

#endif    /* __HIRT_MAXIMUM_LENGTH_SEQUENCES__ */
