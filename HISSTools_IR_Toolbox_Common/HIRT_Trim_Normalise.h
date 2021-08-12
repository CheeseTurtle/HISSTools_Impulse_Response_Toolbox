
#ifndef __TRIM_NORMALISE__
#define __TRIM_NORMALISE__

#include <AH_Types.h>

// Fade Type Enum

enum t_fade_type
{
    FADE_LIN = 0,
    FADE_SQUARE = 1,
    FADE_SQUARE_ROOT = 2,
    FADE_COS = 3,
    FADE_GOMPERTZ = 4,
};

// RMS Result Enum

enum t_rms_result
{
    RMS_RESULT_SUCCESS = 0,
    RMS_RESULT_IN_LEVEL_NOT_FOUND = 1,
    RMS_RESULT_OUT_LEVEL_NOT_FOUND = 2,
};

// Function Prototypes

double norm_find_max(double *in, AH_UIntPtr length, double start_max);

void fade_calc_fade_in(double *in_buf, AH_UIntPtr fade_length, AH_UIntPtr length, t_fade_type fade_type);
void fade_calc_fade_out(double *in_buf, AH_UIntPtr fade_length, AH_UIntPtr length, t_fade_type fade_type);

t_rms_result trim_find_crossings_rms(double *in_buf, AH_UIntPtr length, AH_UIntPtr window_in, AH_UIntPtr window_out, double in_db, double out_db, double mul, AH_UIntPtr *current_start, AH_UIntPtr *current_end);
void trim_copy_part(double *out_buf, double *in_buf, AH_UIntPtr offset, AH_UIntPtr length);

#endif /* __TRIM_NORMALISE__ */
