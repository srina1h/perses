#include <string.h>
#include <float.h>
#include <math.h>



 #include <limits.h>



 #include <stdint.h>



#include <assert.h>
#include <stdio.h>


static void
platform_main_begin(void)
{

}

static void
platform_main_end(uint32_t crc, int flag)
{





 printf ("checksum = %X\n", crc);
}
static int8_t
(safe_unary_minus_func_int8_t_s)(int8_t si )
{

  return


    (si==INT8_MIN) ?
    ((si)) :


    -si;
}

static int8_t
(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > (INT8_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT8_MIN-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int8_t
(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT8_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int8_t
(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > (INT8_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT8_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT8_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT8_MAX / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int8_t
(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT8_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int8_t
(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT8_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int8_t
(safe_lshift_func_int8_t_s_s)(int8_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT8_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int8_t
(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT8_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static int8_t
(safe_rshift_func_int8_t_s_s)(int8_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :

    (left >> ((int)right));
}

static int8_t
(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :

    (left >> ((unsigned int)right));
}



static int16_t
(safe_unary_minus_func_int16_t_s)(int16_t si )
{

  return


    (si==INT16_MIN) ?
    ((si)) :


    -si;
}

static int16_t
(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > (INT16_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT16_MIN-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int16_t
(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT16_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int16_t
(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > (INT16_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT16_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT16_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT16_MAX / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int16_t
(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT16_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int16_t
(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT16_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int16_t
(safe_lshift_func_int16_t_s_s)(int16_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT16_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int16_t
(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT16_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static int16_t
(safe_rshift_func_int16_t_s_s)(int16_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :

    (left >> ((int)right));
}

static int16_t
(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :

    (left >> ((unsigned int)right));
}



static int32_t
(safe_unary_minus_func_int32_t_s)(int32_t si )
{

  return


    (si==INT32_MIN) ?
    ((si)) :


    -si;
}

static int32_t
(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > (INT32_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT32_MIN-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int32_t
(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT32_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int32_t
(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > (INT32_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT32_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT32_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT32_MAX / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int32_t
(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT32_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int32_t
(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT32_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int32_t
(safe_lshift_func_int32_t_s_s)(int32_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT32_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int32_t
(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT32_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static int32_t
(safe_rshift_func_int32_t_s_s)(int32_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :

    (left >> ((int)right));
}

static int32_t
(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :

    (left >> ((unsigned int)right));
}




static int64_t
(safe_unary_minus_func_int64_t_s)(int64_t si )
{

  return


    (si==INT64_MIN) ?
    ((si)) :


    -si;
}

static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > (INT64_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT64_MIN-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT64_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > (INT64_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT64_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT64_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT64_MAX / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT64_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return

    ((si2 == 0) || ((si1 == INT64_MIN) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT64_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT64_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static int64_t
(safe_rshift_func_int64_t_s_s)(int64_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :

    (left >> ((int)right));
}

static int64_t
(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :

    (left >> ((unsigned int)right));
}







static uint8_t
(safe_unary_minus_func_uint8_t_u)(uint8_t ui )
{

  return -ui;
}

static uint8_t
(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return ui1 + ui2;
}

static uint8_t
(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return ui1 - ui2;
}

static uint8_t
(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint8_t
(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 % ui2);
}

static uint8_t
(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 / ui2);
}

static uint8_t
(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT8_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint8_t
(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > (UINT8_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static uint8_t
(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :

    (left >> ((int)right));
}

static uint8_t
(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{

  return

    (((unsigned int)right) >= 32) ?
    ((left)) :

    (left >> ((unsigned int)right));
}



static uint16_t
(safe_unary_minus_func_uint16_t_u)(uint16_t ui )
{

  return -ui;
}

static uint16_t
(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return ui1 + ui2;
}

static uint16_t
(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return ui1 - ui2;
}

static uint16_t
(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint16_t
(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 % ui2);
}

static uint16_t
(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 / ui2);
}

static uint16_t
(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT16_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint16_t
(safe_lshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > (UINT16_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static uint16_t
(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :

    (left >> ((int)right));
}

static uint16_t
(safe_rshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{

  return

    (((unsigned int)right) >= 32) ?
    ((left)) :

    (left >> ((unsigned int)right));
}



static uint32_t
(safe_unary_minus_func_uint32_t_u)(uint32_t ui )
{

  return -ui;
}

static uint32_t
(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return ui1 + ui2;
}

static uint32_t
(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return ui1 - ui2;
}

static uint32_t
(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint32_t
(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 % ui2);
}

static uint32_t
(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 / ui2);
}

static uint32_t
(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT32_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint32_t
(safe_lshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > (UINT32_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static uint32_t
(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :

    (left >> ((int)right));
}

static uint32_t
(safe_rshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{

  return

    (((unsigned int)right) >= 32) ?
    ((left)) :

    (left >> ((unsigned int)right));
}




static uint64_t
(safe_unary_minus_func_uint64_t_u)(uint64_t ui )
{

  return -ui;
}

static uint64_t
(safe_add_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return ui1 + ui2;
}

static uint64_t
(safe_sub_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return ui1 - ui2;
}

static uint64_t
(safe_mul_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return ((unsigned long long)ui1) * ((unsigned long long)ui2);
}

static uint64_t
(safe_mod_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 % ui2);
}

static uint64_t
(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return

    (ui2 == 0) ?
    ((ui1)) :

    (ui1 / ui2);
}

static uint64_t
(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT64_MAX >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > (UINT64_MAX >> ((unsigned int)right)))) ?
    ((left)) :

    (left << ((unsigned int)right));
}

static uint64_t
(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right )
{

  return

    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :

    (left >> ((int)right));
}

static uint64_t
(safe_rshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{

  return

    (((unsigned int)right) >= 32) ?
    ((left)) :

    (left >> ((unsigned int)right));
}
static float
(safe_add_func_float_f_f)(float sf1, float sf2 )
{

  return

    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * FLT_MAX)) ?
    (sf1) :

    (sf1 + sf2);
}

static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{

  return

    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * FLT_MAX)) ?
    (sf1) :

    (sf1 - sf2);
}

static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{

  return

    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * FLT_MAX))) ?
    (sf1) :

    (sf1 * sf2);
}

static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{

  return

    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * FLT_MAX))))) ?
    (sf1) :

    (sf1 / sf2);
}




static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{

  return

    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * DBL_MAX)) ?
    (sf1) :

    (sf1 + sf2);
}

static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{

  return

    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * DBL_MAX)) ?
    (sf1) :

    (sf1 - sf2);
}

static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{

  return

    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * DBL_MAX))) ?
    (sf1) :

    (sf1 * sf2);
}

static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{

  return

    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * DBL_MAX))))) ?
    (sf1) :

    (sf1 / sf2);
}






static int32_t
(safe_convert_func_float_to_int32_t)(float sf1 )
{

  return

    ((sf1 <= INT32_MIN) || (sf1 >= INT32_MAX)) ?
    (INT32_MAX) :

    ((int32_t)(sf1));
}

static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;

static void
crc32_gentab (void)
{
 uint32_t crc;
 const uint32_t poly = 0xEDB88320UL;
 int i, j;

 for (i = 0; i < 256; i++) {
  crc = i;
  for (j = 8; j > 0; j--) {
   if (crc & 1) {
    crc = (crc >> 1) ^ poly;
   } else {
    crc >>= 1;
   }
  }
  crc32_tab[i] = crc;
 }
}

static void
crc32_byte (uint8_t b) {
 crc32_context =
  ((crc32_context >> 8) & 0x00FFFFFF) ^
  crc32_tab[(crc32_context ^ b) & 0xFF];
}
static void
crc32_8bytes (uint64_t val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
 crc32_byte ((val>>32) & 0xff);
 crc32_byte ((val>>40) & 0xff);
 crc32_byte ((val>>48) & 0xff);
 crc32_byte ((val>>56) & 0xff);
}

static void
transparent_crc (uint64_t val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
 }
}



static void
transparent_crc_bytes (char *ptr, int nbytes, char* vname, int flag)
{
    int i;
    for (i=0; i<nbytes; i++) {
        crc32_byte(ptr[i]);
    }
 if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
 }
}


static long __undefined;



static int32_t g_2 = 0xB110C93BL;
static int32_t g_5[10] = {0x4EBB0CB8L, 0x9609C3FBL, 0xDF98A59CL, 0xDF98A59CL, 0x9609C3FBL, 0x4EBB0CB8L, 0x9609C3FBL, 0xDF98A59CL, 0xDF98A59CL, 0x9609C3FBL};
static int32_t g_8[3][2] = {{0xEC79E672L, 0xEC79E672L}, {0xEC79E672L, 0xEC79E672L}, {0xEC79E672L, 0xEC79E672L}};
static int32_t g_9 = 0L;
static int8_t g_10 = 0x15L;
static uint32_t g_101 = 0x7C3E802FL;
static int8_t g_142[5][5] = {{(-1L), (-1L), 0x39L, 7L, (-6L)}, {(-1L), (-1L), 0x39L, 7L, (-6L)}, {(-1L), (-1L), 0x39L, 7L, (-6L)}, {(-1L), (-1L), 0x39L, 7L, (-6L)}, {(-1L), (-1L), 0x39L, 7L, (-6L)}};
static uint32_t g_208 = 0x8879A0F3L;
static uint16_t g_227 = 0x2153L;
static int16_t g_358 = 0L;
static uint16_t g_405[9] = {65530UL, 0xF13BL, 65530UL, 0xF13BL, 65530UL, 0xF13BL, 65530UL, 0xF13BL, 65530UL};
static int16_t g_406 = (-2L);
static int8_t g_458[1] = {0x90L};
static uint32_t g_508[3][10][1] = {{{0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}}, {{0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}}, {{0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}, {0xA0ABFA0EL}}};
static int16_t g_520[9] = {3L, 3L, 4L, 3L, 3L, 4L, 3L, 3L, 4L};
static int32_t g_580[4] = {0xD7605479L, 0xD7605479L, 0xD7605479L, 0xD7605479L};
static int8_t g_754 = (-7L);
static int32_t g_830 = (-1L);
static int8_t g_1165 = (-1L);
static uint32_t g_1195 = 0x8B77D5C4L;
static uint8_t g_1588 = 0xE5L;
static uint32_t g_1625 = 0x37ADF603L;



static int32_t func_1(void);
static int8_t func_11(uint16_t p_12, int16_t p_13, int32_t p_14, uint32_t p_15, uint32_t p_16);
static uint16_t func_21(uint16_t p_22);
static int8_t func_23(int8_t p_24, uint8_t p_25, uint16_t p_26, int32_t p_27);
static int16_t func_36(uint32_t p_37, int32_t p_38);
static int16_t func_46(int8_t p_47, int32_t p_48, uint8_t p_49, int32_t p_50);
static uint32_t func_61(uint16_t p_62, uint8_t p_63, int32_t p_64);
static int32_t func_72(int16_t p_73);
static uint32_t func_78(int8_t p_79, int16_t p_80);
static uint8_t func_118(uint8_t p_119, int32_t p_120, int16_t p_121, uint16_t p_122, int32_t p_123);
static int32_t func_1(void)
{
    uint16_t l_2038 = 0x0693L;
    int32_t l_2067[3];
    uint8_t l_2142 = 0x9AL;
    int32_t l_2231 = 1L;
    int i;
    for (i = 0; i < 3; i++)
        l_2067[i] = 0x95763659L;
    for (g_2 = 0; (g_2 <= 28); g_2 = safe_add_func_uint16_t_u_u(g_2, 9))
    {
        uint8_t l_2036 = 0x5DL;
        for (g_5[6] = 0; (g_5[6] == (-15)); g_5[6]--)
        {
            int8_t l_2037[6][7][2] = {{{0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}}, {{0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}}, {{0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}}, {{0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}}, {{0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}}, {{0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}, {0x1CL, 0L}}};
            int32_t l_2059 = (-1L);
            uint16_t l_2141 = 0xF260L;
            int32_t l_2163 = 0xB8660EB2L;
            int32_t l_2229 = 0xD9767C14L;
            int i, j, k;
            for (g_9 = 1; (g_9 >= 0); g_9 -= 1)
            {
                int16_t l_2149 = 0xCCC4L;
                int32_t l_2232[2];
                int i, j;
                for (i = 0; i < 2; i++)
                    l_2232[i] = 1L;
                g_10 = g_8[(g_9 + 1)][g_9];
                for (g_10 = 0; (g_10 <= 1); g_10 += 1)
                {
                    int32_t l_2058 = 0x38544D0EL;
                    uint32_t l_2070 = 1UL;
                    int32_t l_2085 = 0x0E069FBBL;
                    int16_t l_2198[9];
                    int32_t l_2233 = 0xB91FAD3AL;
                    int i, j;
                    for (i = 0; i < 9; i++)
                        l_2198[i] = 0L;
                    if ((0x9150L >= g_8[(g_10 + 1)][g_9]))
                    {
                        int8_t l_2035 = 0xC1L;
                        l_2058 = (func_11(((g_5[6] , (safe_sub_func_uint32_t_u_u(g_8[(g_10 + 1)][g_9], (safe_rshift_func_uint16_t_u_u(func_21(g_10), (((safe_mod_func_int8_t_s_s(l_2035, g_9)) | l_2035) <= l_2036)))))) , (l_2036 , g_9)), l_2037[4][5][0], g_8[(g_9 + 1)][g_9], l_2038, g_8[(g_9 + 1)][g_9]) != l_2035);
                        if (g_1165)
                            continue;
                        l_2059 = l_2036;
                    }
                    else
                    {
                        uint16_t l_2086 = 0x583EL;
                        uint32_t l_2105 = 18446744073709551612UL;
                        g_830 = g_520[6];
                        g_580[1] = g_227;
                        g_580[1] = (safe_add_func_int32_t_s_s((((safe_unary_minus_func_uint8_t_u(l_2059)) | (g_1625 || (safe_lshift_func_int16_t_s_s((safe_mod_func_int16_t_s_s(l_2036, l_2067[2])), 15)))) & (safe_mod_func_uint16_t_u_u(g_1195, l_2070))), (((safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((g_1195 ^ (safe_mod_func_int16_t_s_s((((((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s((0xBAL < ((safe_sub_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(g_8[(g_9 + 1)][g_9], g_508[1][4][0])) & l_2085), g_508[2][4][0])) == 1UL)), 1)), g_830)) >= l_2067[2]) == l_2037[3][6][1]) >= l_2086) , g_520[0]), g_508[1][2][0]))) < l_2038), 10)), 0xF45DL)) != g_1588) , l_2067[1])));
                        g_830 = (safe_rshift_func_int16_t_s_u(8L, (((safe_mul_func_int8_t_s_s(((safe_lshift_func_int8_t_s_u(l_2038, ((((safe_mul_func_uint16_t_u_u(((0x22L && 0xDAL) <= (safe_mod_func_int8_t_s_s((safe_rshift_func_int8_t_s_s((g_5[3] > ((0x6CL | (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u(0UL, l_2038)) < ((safe_rshift_func_int16_t_s_s(g_8[(g_9 + 1)][g_9], g_520[0])) , 0x12767035L)), (-5L)))) == 0x85E16F77L)), g_1588)), g_830))), 65527UL)) >= g_580[1]) != g_8[2][1]) > g_358))) != g_10), g_9)) || l_2105) ^ g_405[8])));
                    }
                    for (l_2038 = 0; (l_2038 <= 1); l_2038 += 1)
                    {
                        uint8_t l_2120 = 247UL;
                        l_2120 = ((l_2070 , (g_580[1] <= (3L > ((safe_sub_func_uint8_t_u_u(((g_580[3] && (safe_mul_func_int16_t_s_s((safe_add_func_uint16_t_u_u(0x0E34L, ((safe_mul_func_uint16_t_u_u(1UL, (safe_mul_func_uint16_t_u_u((((safe_mul_func_uint16_t_u_u(((0x3BE3L != (-1L)) , l_2038), 1UL)) ^ g_2) & g_1195), g_101)))) ^ g_8[1][0]))), l_2058))) != l_2038), g_1588)) < g_458[0])))) >= g_227);
                        if (g_2)
                            break;
                        if (l_2036)
                            break;
                        g_580[2] = ((safe_add_func_int16_t_s_s((((l_2036 & (l_2070 != (l_2120 > l_2036))) != (0L != (((-2L) == ((safe_mod_func_int32_t_s_s((((((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(((safe_mul_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((g_830 | (((((safe_rshift_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s((l_2067[2] && (g_1195 | 1L)), l_2058)), 1L)) == l_2070), 15)) ^ 3L) <= 0x8039L) && 0x76520C5AL) | 4UL)), g_101)), l_2120)) >= g_458[0]), 1UL)), 5)), 15)) <= 1L) || l_2038) >= 0x7247L) <= l_2037[4][5][0]), l_2141)) & 2L)) , g_227))) ^ (-1L)), l_2142)) ^ g_142[3][0]);
                    }
                    if ((((safe_mod_func_int32_t_s_s((safe_sub_func_int16_t_s_s((((safe_mul_func_int8_t_s_s((g_5[1] == l_2142), (g_405[6] || l_2149))) && 1UL) <= g_508[2][4][0]), (((safe_mul_func_uint8_t_u_u((g_1195 & (((+((0x94L && ((safe_add_func_uint32_t_u_u(((((safe_rshift_func_int8_t_s_u((0x24C81AC5L != 0x21380933L), 4)) || 0xD40C0F3CL) || g_8[(g_9 + 1)][g_9]) | 0x52D8L), g_2)) < g_8[(g_10 + 1)][g_9])) == 0L)) & l_2085) > l_2067[2])), g_1165)) & 7L) == l_2059))), 0xCF5CA7DDL)) <= g_8[(g_9 + 1)][g_9]) | l_2067[1]))
                    {
                        uint8_t l_2162[4] = {0x53L, 0x0DL, 0x53L, 0x0DL};
                        int i;
                        g_580[1] = (l_2036 >= ((+0xE040D8F8L) | ((g_508[2][4][0] ^ ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int8_t_s_s((255UL >= (l_2142 != (((((safe_rshift_func_int16_t_s_s(g_508[2][4][0], 0)) , l_2067[2]) != l_2141) || ((1UL ^ 246UL) != l_2142)) | 4294967293UL))), 2)) , (-1L)) >= 1L), 1L)) | g_1625)) < l_2162[3])));
                        l_2163 = l_2162[0];
                        l_2058 = ((((safe_mul_func_int16_t_s_s((-8L), ((safe_rshift_func_int16_t_s_s((((((l_2070 ^ (safe_add_func_int16_t_s_s((g_458[0] ^ ((safe_rshift_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u(g_142[0][1])) , 0x7182L), l_2036)) , g_5[6])), ((g_508[2][4][0] , ((((safe_sub_func_int16_t_s_s((3L > 6L), l_2162[3])) && 0L) , l_2067[2]) | l_2085)) >= 0x7B49L)))) , 0UL) & g_101) == g_8[(g_9 + 1)][g_9]) & g_458[0]), 6)) >= g_405[8]))) , g_2) != g_405[8]) , 0x53BBB007L);
                    }
                    else
                    {
                        int32_t l_2197 = (-9L);
                        uint16_t l_2230[4][10][5] = {{{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}, {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}, {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}, {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}, {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}};
                        int i, j, k;
                        l_2198[6] = (g_101 , (((safe_add_func_uint16_t_u_u((((((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s((!(((-1L) > (safe_add_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(l_2085, (safe_sub_func_int32_t_s_s(((safe_add_func_uint16_t_u_u((l_2085 || (safe_lshift_func_int16_t_s_s((g_1625 > (safe_sub_func_uint8_t_u_u(((l_2036 | (safe_mod_func_uint16_t_u_u(g_520[0], (g_405[8] ^ ((safe_mod_func_int8_t_s_s((-8L), g_830)) >= l_2149))))) & l_2038), g_830))), 12))), l_2197)) >= l_2197), l_2070)))) == g_458[0]), 0UL))) == g_1588)), l_2058)), l_2142)) > 0xA7511AFCL) ^ g_10) | 0x4495FEC8L) == g_458[0]) > 65532UL) > 0x730FL), 0xE99FL)) , g_458[0]) >= 4294967295UL));
                        g_580[1] = (safe_add_func_uint16_t_u_u((((((safe_add_func_uint8_t_u_u((((((safe_mul_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u(((((l_2197 > 0xC0L) | (((safe_add_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(((((safe_mul_func_int16_t_s_s((~((safe_sub_func_uint32_t_u_u(0xE8633FD1L, (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((0L > g_101) && (((l_2036 , (l_2036 && (safe_mod_func_uint16_t_u_u((g_1588 & (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((((((l_2036 && g_208) && l_2229) < g_520[6]) == g_508[0][6][0]) || g_227), 0x30L)), g_5[6])) != l_2230[0][3][3]) , g_1588), 1L))), g_1625)))) >= g_458[0]) , l_2142)), g_458[0])), l_2036)))) & l_2231)), 2UL)) <= g_358) <= g_8[(g_9 + 1)][g_9]) != g_101), (-1L))), 0xAE57AF4CL)) && 255UL) <= 5UL)) < l_2232[1]) != 0L), g_8[(g_10 + 1)][g_9])) <= g_754) | g_580[1]), l_2233)) <= (-1L)) > l_2197) , l_2058) == 0xDED5L), 0x8AL)) == l_2232[1]) == l_2229) || g_1165) , l_2231), 0xC11BL));
                    }
                }
                g_580[0] = 1L;
            }
            if (g_508[1][1][0])
                break;
            l_2163 = (9UL | g_508[2][4][0]);
        }
    }
    return g_458[0];
}







static int8_t func_11(uint16_t p_12, int16_t p_13, int32_t p_14, uint32_t p_15, uint32_t p_16)
{
    uint8_t l_2046 = 1UL;
    for (g_1588 = (-5); (g_1588 > 16); g_1588 = safe_add_func_uint32_t_u_u(g_1588, 8))
    {
        int16_t l_2057 = (-6L);
        for (p_12 = 0; (p_12 > 47); p_12++)
        {
            uint8_t l_2043 = 251UL;
            l_2057 = ((l_2043 && (p_16 < (safe_rshift_func_uint16_t_u_s(l_2046, 4)))) && ((((safe_add_func_int16_t_s_s(p_15, ((((p_16 >= ((!(((safe_lshift_func_int16_t_s_u((((((((safe_sub_func_uint16_t_u_u(((-1L) && 0xCD2EL), l_2046)) == (safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(g_208, 0)), g_1165))) <= p_13) >= p_14) >= g_520[1]) <= p_12) & l_2046), g_2)) > 0xFD0C81B8L) , 1L)) != 0xB223C613L)) <= l_2043) || p_15) , g_8[2][0]))) > g_1588) >= g_508[1][1][0]) || g_8[0][1]));
            if (p_15)
                break;
        }
    }
    return p_16;
}







static uint16_t func_21(uint16_t p_22)
{
    uint32_t l_45[3];
    uint8_t l_51 = 0x0FL;
    int32_t l_1687 = 0xA3E2613DL;
    int32_t l_1776 = 0x3BBE683FL;
    uint32_t l_1946 = 18446744073709551607UL;
    int8_t l_2024 = 1L;
    int i;
    for (i = 0; i < 3; i++)
        l_45[i] = 0UL;
lbl_1856:
    g_580[1] = (func_23(((safe_mod_func_uint16_t_u_u(g_2, (safe_lshift_func_int16_t_s_u(((safe_mod_func_uint32_t_u_u((((((func_36(p_22, p_22) && (safe_add_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(l_45[0], func_46(p_22, g_9, g_5[8], (((((g_5[6] | l_51) | p_22) > 252UL) | 0xA4L) == 5L)))), g_1588))) , g_1625) || p_22) , (-7L)) , 4294967295UL), l_45[0])) , g_8[1][0]), g_5[0])))) > 0UL), g_2, p_22, g_2) , g_458[0]);
    if (g_1195)
    {
        int16_t l_1688 = 0x35CEL;
        int32_t l_1717[2];
        int16_t l_1850[2];
        int16_t l_1895 = 0x421BL;
        int i;
        for (i = 0; i < 2; i++)
            l_1717[i] = 0L;
        for (i = 0; i < 2; i++)
            l_1850[i] = 0L;
lbl_1843:
        l_1687 = l_51;
        g_580[0] = 0x7EAF790BL;
        if (p_22)
        {
            uint8_t l_1693 = 255UL;
            uint32_t l_1700 = 4UL;
            int32_t l_1733 = (-7L);
            uint8_t l_1767 = 252UL;
            int32_t l_1768 = 0x9FD3A243L;
            if (((((((+(p_22 >= (((((l_1688 , ((((((((((((safe_add_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x33L, (p_22 ^ (l_1693 || (g_101 != (safe_mul_func_uint8_t_u_u(p_22, ((safe_add_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s(2UL, 14)), 0xD796L)) && p_22)))))))), g_520[6])) , l_1688) | 0x19L) == g_458[0]) , l_1688) <= 1L) > 1UL) | l_1688) <= g_830) & l_51) <= g_5[6]) > p_22)) , g_1195) || 4294967289UL) < l_1700) != 0x0591EFB8L))) & p_22) & g_5[6]) || l_1693) ^ g_754) | g_227))
            {
                int8_t l_1714 = (-1L);
                g_830 = ((((safe_mod_func_int32_t_s_s((safe_unary_minus_func_uint32_t_u(((safe_sub_func_int16_t_s_s(l_45[0], 65534UL)) == ((safe_lshift_func_int16_t_s_s(((safe_sub_func_uint8_t_u_u(((((safe_mod_func_int8_t_s_s(0x24L, ((((safe_rshift_func_int16_t_s_s((l_1714 > g_405[1]), (p_22 >= ((((safe_sub_func_int32_t_s_s((((-1L) | (0UL > 4UL)) & p_22), p_22)) && 0x32C4976CL) , l_1688) == l_1688)))) < 0x6D99L) ^ p_22) | 2UL))) & l_1688) & 0x22D6D603L) | p_22), l_1688)) & 0L), 10)) , l_45[0])))), g_1588)) || g_580[0]) < 0L) > l_1714);
                l_1717[1] = ((p_22 >= 0x35D6L) > p_22);
                l_1717[1] = (safe_sub_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((((p_22 && (!l_1717[1])) >= g_520[0]) == ((safe_unary_minus_func_uint32_t_u((((safe_add_func_int32_t_s_s((l_1700 | (safe_mod_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((1UL <= (((((((safe_lshift_func_uint16_t_u_s((p_22 != (((safe_sub_func_int8_t_s_s((l_1733 != l_1717[0]), (-1L))) ^ g_406) && g_2)), l_1700)) , 6UL) != g_458[0]) ^ g_458[0]) , p_22) >= g_520[0]) & l_1717[1])), 3)), l_1714))), g_5[6])) <= 0xD47E2DAEL) != p_22))) , 4294967295UL)), g_405[8])), g_754));
            }
            else
            {
                uint32_t l_1766[5][9] = {{18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L, 18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL, 0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL}, {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L, 18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL, 0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL}, {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L, 18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL, 0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL}, {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L, 18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL, 0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL}, {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L, 18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL, 0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL}};
                int i, j;
                for (l_51 = 0; (l_51 >= 5); l_51++)
                {
                    uint8_t l_1749[1];
                    int32_t l_1769[10] = {0x7732275CL, 1L, 0x7732275CL, 1L, 0x7732275CL, 1L, 0x7732275CL, 1L, 0x7732275CL, 1L};
                    int i;
                    for (i = 0; i < 1; i++)
                        l_1749[i] = 255UL;
                    for (l_1688 = 0; (l_1688 <= 8); l_1688 += 1)
                    {
                        int32_t l_1750 = 0xE6909761L;
                        int i;
                        g_580[2] = ((((g_520[l_1688] || ((safe_lshift_func_int8_t_s_s((((((safe_add_func_uint32_t_u_u(((p_22 && (safe_rshift_func_int8_t_s_s(((p_22 != ((safe_unary_minus_func_uint32_t_u((safe_rshift_func_int8_t_s_s(l_1700, 4)))) , ((safe_rshift_func_int16_t_s_s((safe_mul_func_int8_t_s_s(((((g_520[0] , ((l_45[0] != g_520[0]) <= g_358)) | (p_22 , p_22)) != 0x19L) != 0x005AD943L), p_22)), g_1588)) || l_51))) || p_22), g_1625))) , 0x4A949223L), l_1749[0])) > g_358) <= g_2) , l_1749[0]) <= 4294967295UL), 2)) & p_22)) > p_22) ^ l_1750) != 9L);
                        g_830 = ((safe_sub_func_int8_t_s_s((safe_add_func_int8_t_s_s(((l_1749[0] | ((safe_sub_func_int32_t_s_s((-8L), l_1750)) & (l_1749[0] == (((safe_add_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s(p_22, 9)), p_22)) <= ((l_1749[0] < (((p_22 & ((safe_add_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((safe_unary_minus_func_uint32_t_u((~((255UL != g_142[4][2]) <= l_1766[1][5])))) & l_1767), 0xF4D917C2L)), l_1749[0])) >= g_5[5])) ^ l_51) < 0xC01B4D91L)) , 0xE50CL)) , l_1693)))) ^ g_520[l_1688]), 0x28L)), 0x7EL)) & 0x14ABCF1FL);
                        l_1768 = p_22;
                    }
                    l_1769[8] = 0x403F0A83L;
                    l_1717[0] = g_358;
                }
                return p_22;
            }
            g_580[0] = ((((safe_mul_func_uint16_t_u_u(((0xC009L > g_1588) & (safe_mod_func_uint32_t_u_u(l_1693, (safe_sub_func_int16_t_s_s(g_508[2][0][0], l_1776))))), (((safe_rshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_s((((safe_mul_func_int8_t_s_s((g_2 <= (((((((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_u(((safe_mul_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_mul_func_int8_t_s_s(l_1767, (safe_rshift_func_int8_t_s_s(((safe_mul_func_int16_t_s_s((safe_add_func_uint32_t_u_u((0x56B8C77BL > ((g_142[0][1] && 4294967286UL) <= l_1776)), 0xE9C2AEB3L)), l_1776)) & p_22), 3)))), g_1625)) , l_1717[1]), 3UL)) , p_22), p_22)) > l_1776), p_22)) && g_458[0]) == (-1L)), l_1688)), 2)) , l_1776), p_22)) >= (-1L)) , 0x547DA53AL) <= g_208) || p_22) || 0L) && l_51)), p_22)) , 0xABC20D0AL) ^ 0x4B215BF4L), l_45[2])) , g_1588) , 1UL) || p_22) || l_1688), 9)) , g_9) < g_1195))) > l_51) , (-1L)) , (-1L));
            return l_1717[0];
        }
        else
        {
            uint32_t l_1823 = 0xA82F9AD5L;
            int32_t l_1900 = 0xF70E6F28L;
lbl_1855:
            if (((g_508[2][4][0] | (0x79L & ((((safe_mod_func_uint8_t_u_u(((p_22 && (safe_mul_func_uint8_t_u_u((((l_1717[1] , ((p_22 ^ (p_22 , (((safe_add_func_int8_t_s_s((((safe_mul_func_int16_t_s_s((p_22 < g_405[6]), (safe_add_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(((((((safe_sub_func_int16_t_s_s(((g_580[0] || g_5[3]) ^ 0L), p_22)) , 0x7DE91883L) >= p_22) & g_508[2][4][0]) | 0x2254L) >= 65527UL), 8)), 2)) == p_22), 0xBB9BE894L)))) >= l_1823) , 0xCFL), 0L)) != p_22) < 0x873EFC68L))) > p_22)) > 0x2FL) , l_1823), 0UL))) , g_10), g_458[0])) , 0x922804D8L) , 0x91E0L) < g_405[7]))) , p_22))
            {
                uint32_t l_1830[10];
                int i;
                for (i = 0; i < 10; i++)
                    l_1830[i] = 4294967295UL;
                l_1717[1] = (safe_rshift_func_uint16_t_u_s(0xFDA2L, 2));
                g_580[1] = (safe_add_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(g_10, l_1823)), (((l_1830[7] && (safe_add_func_int16_t_s_s(((safe_mod_func_int8_t_s_s((0xA9L <= ((((safe_sub_func_uint8_t_u_u((l_1830[4] > (safe_mod_func_uint16_t_u_u(l_1717[1], g_458[0]))), p_22)) ^ ((safe_lshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((l_1823 , 0UL), g_830)), 6)) | g_580[1])) == g_458[0]) ^ 9L)), g_520[8])) , p_22), 1UL))) < p_22) || p_22)));
            }
            else
            {
                if (g_406)
                    goto lbl_1843;
            }
            for (g_754 = 14; (g_754 == 22); ++g_754)
            {
                uint32_t l_1865[5] = {18446744073709551615UL, 9UL, 18446744073709551615UL, 9UL, 18446744073709551615UL};
                uint32_t l_1913 = 0UL;
                int i;
                if ((p_22 < (+(safe_mul_func_int16_t_s_s(((l_1823 | ((0UL <= l_1688) , (0x9BD7L ^ (g_580[1] , 0UL)))) | (l_1850[0] , ((safe_mod_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_u(((g_580[1] >= l_1823) , g_5[0]), l_1717[1])) <= p_22) & g_458[0]) ^ 0xDC55F0E0L) , p_22), 0x5B47L)) == 0xF93BA45EL))), 65535UL)))))
                {
                    int32_t l_1864[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_1864[i] = 0xA80823F4L;
                    if (g_830)
                        goto lbl_1855;
                    if (l_45[0])
                    {
                        uint8_t l_1868 = 0x39L;
                        if (g_208)
                            goto lbl_1856;
                        l_1864[8] = (((safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_int32_t_s((l_1823 ^ (safe_add_func_int8_t_s_s((((safe_lshift_func_uint8_t_u_u(((l_1864[3] , 0x963AL) , l_1865[3]), 5)) <= g_754) || 0xD056L), (safe_sub_func_int16_t_s_s((g_227 ^ l_1868), 0xED95L))))))) >= l_1865[4]), l_45[0])) <= 255UL) & 0xF124L);
                        return g_405[4];
                    }
                    else
                    {
                        int16_t l_1886 = 1L;
                        g_580[2] = ((((safe_rshift_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((((-7L) == (p_22 <= g_508[2][8][0])) > (safe_unary_minus_func_uint8_t_u((0UL & 0x5DL)))), (safe_sub_func_int16_t_s_s(7L, (!((safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_u(0x5EL, 7)), ((safe_sub_func_int8_t_s_s(g_830, ((safe_add_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s(l_1823, 2UL)) | l_1886), l_1865[3])) || g_754))) >= g_580[3]))) | p_22)))))), g_508[2][4][0])) || 0xD8L) || 0UL) , p_22);
                    }
                    if (l_1864[3])
                        continue;
                    return p_22;
                }
                else
                {
                    for (g_1625 = (-3); (g_1625 < 18); g_1625++)
                    {
                        l_1895 = ((((safe_add_func_int16_t_s_s(((g_458[0] && (l_1865[3] < (l_45[0] >= l_1717[1]))) , ((0xA7L == (((safe_sub_func_uint32_t_u_u((0L > 0x56L), (g_458[0] > (safe_sub_func_uint16_t_u_u((g_5[2] & g_101), l_1850[0]))))) , 255UL) && p_22)) == g_580[1])), l_1688)) & g_208) & g_458[0]) >= g_358);
                    }
                }
                l_1900 = (safe_mul_func_int16_t_s_s(((g_101 >= (((safe_rshift_func_uint16_t_u_s(((l_1900 ^ (((0x9DDDL && p_22) & (safe_add_func_int32_t_s_s((((!l_1687) <= ((safe_unary_minus_func_int32_t_s((((((0x987DL | 0x7EA5L) && ((safe_lshift_func_int8_t_s_u((((safe_sub_func_uint32_t_u_u(p_22, ((safe_unary_minus_func_int16_t_s((safe_rshift_func_int8_t_s_s((g_358 && g_405[8]), 6)))) ^ p_22))) | p_22) , l_1913), p_22)) <= 65526UL)) & 0x78E3253FL) < 4L) || p_22))) >= p_22)) , p_22), p_22))) > 9UL)) | (-4L)), g_405[5])) , l_1688) != p_22)) >= p_22), l_1895));
            }
            return g_405[1];
        }
    }
    else
    {
        uint16_t l_1926 = 65535UL;
        if (g_1588)
        {
            int16_t l_1931 = 1L;
            int32_t l_1945[6] = {(-1L), (-1L), 0x35121526L, (-1L), (-1L), 0x35121526L};
            int i;
            if ((safe_add_func_uint8_t_u_u((~(p_22 || p_22)), (((((safe_add_func_int16_t_s_s((g_2 <= (((safe_mod_func_uint16_t_u_u(6UL, p_22)) , (safe_sub_func_uint32_t_u_u(((((safe_add_func_int8_t_s_s((g_580[1] > (((l_1926 | ((safe_rshift_func_uint16_t_u_s((safe_mod_func_int32_t_s_s(g_142[4][1], g_830)), 15)) < g_508[0][7][0])) ^ p_22) , l_1931)), g_227)) != g_8[2][1]) <= p_22) ^ p_22), g_1195))) >= 4294967295UL)), g_358)) ^ l_1931) < 0L) == g_208) > 1UL))))
            {
                int8_t l_1944[4][7] = {{(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L}, {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L}, {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L}, {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L}};
                int i, j;
                l_1945[1] = ((((safe_sub_func_uint8_t_u_u(0x41L, ((((((safe_mod_func_uint8_t_u_u(1UL, (safe_sub_func_int16_t_s_s(g_458[0], (safe_mod_func_int16_t_s_s(l_1926, p_22)))))) != (safe_mul_func_int16_t_s_s(((safe_mul_func_uint8_t_u_u((p_22 != (((p_22 || 0L) != (g_1195 , 1L)) != l_1944[1][0])), p_22)) , 0xF0FBL), g_580[2]))) ^ 0x88D3L) , (-1L)) & p_22) , g_406))) || 0L) <= p_22) ^ l_45[0]);
                if ((l_1946 , p_22))
                {
                    g_830 = l_1945[1];
                }
                else
                {
                    uint16_t l_1960 = 65526UL;
                    int32_t l_2025 = 0x45968C25L;
                    if ((((!p_22) , ((1L | (~(((safe_sub_func_int32_t_s_s(((safe_mul_func_uint8_t_u_u(((safe_add_func_int16_t_s_s(1L, (((p_22 , (!((((p_22 != (safe_unary_minus_func_int8_t_s((safe_sub_func_int16_t_s_s(p_22, ((safe_unary_minus_func_uint16_t_u(((safe_mul_func_int16_t_s_s((((g_520[0] , l_1926) , (safe_unary_minus_func_int8_t_s(l_1687))) || g_405[8]), 1UL)) < l_1926))) | 0x7D6B8347L)))))) , 0x8DBCE599L) , g_580[2]) || 1L))) ^ p_22) | 0UL))) > p_22), p_22)) <= p_22), 0xC2A58029L)) < p_22) & l_1960))) & l_1926)) , g_508[1][9][0]))
                    {
                        return g_2;
                    }
                    else
                    {
                        int32_t l_1987 = 3L;
                        uint16_t l_1997 = 1UL;
                        g_830 = (((((((safe_rshift_func_uint16_t_u_s((g_1588 && (+(safe_unary_minus_func_int32_t_s((safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_u((((p_22 == (safe_lshift_func_int16_t_s_s(((-4L) != 0x1AL), 13))) | ((safe_add_func_uint16_t_u_u(((safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(0x58E6L, (safe_lshift_func_uint8_t_u_s((safe_lshift_func_int8_t_s_s(g_101, 2)), (safe_lshift_func_uint16_t_u_s(((((g_10 < ((safe_mod_func_uint8_t_u_u(250UL, (safe_unary_minus_func_int8_t_s(((((safe_mul_func_uint8_t_u_u(((p_22 <= 0x590E5EE8L) || p_22), g_10)) == 0x52L) || 0xB726L) , l_1926))))) || g_405[8])) , g_5[2]) || g_754) != l_1931), 13)))))), p_22)) , g_2), l_1960)) <= 0x2277BEF4L)) >= g_10), p_22)) < l_1987), 6)))))), 12)) , g_520[5]) || l_1960) < l_1946) || l_1945[1]) || 0x67029D07L) > l_51);
                        g_580[1] = l_1926;
                        l_1997 = ((safe_unary_minus_func_uint8_t_u(p_22)) < (safe_lshift_func_int8_t_s_s(g_580[1], ((((l_1926 || ((0x4D32D024L && p_22) != (safe_rshift_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s(p_22, (((g_1588 , ((safe_add_func_int8_t_s_s((-10L), 0x0FL)) <= 0x68B0L)) || 0x5EA29434L) | p_22))) , l_1926), l_1987)))) < p_22) || 1L) | g_5[7]))));
                    }
                    l_2025 = (safe_mod_func_int32_t_s_s(((((((4L && ((safe_sub_func_int8_t_s_s(((safe_sub_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((p_22 & (p_22 != ((safe_mod_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(l_1960, ((l_1945[1] , (safe_add_func_int32_t_s_s(l_1926, (safe_sub_func_uint16_t_u_u((((safe_mod_func_int16_t_s_s(((safe_sub_func_int32_t_s_s((-3L), (safe_sub_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s(g_5[1], ((!(safe_mul_func_int16_t_s_s(((0UL | 0x79L) < p_22), p_22))) && 0xCA02L))) || 3UL) <= 0xEB80L), l_1944[1][0])))) >= 0xA59DL), 5L)) < 0xE20FL) <= l_2024), 0x0714L))))) >= l_1945[1]))), g_508[0][2][0])) < g_405[8]))), g_227)) != 0x788B78DBL), 0x182DL)) && p_22), 0x99L)) & l_45[0])) , l_51) != p_22) , p_22) >= 0x03L) && g_405[1]), p_22));
                }
                l_1945[1] = 0xACFEA494L;
            }
            else
            {
                return g_458[0];
            }
            l_1776 = (4294967295UL <= ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(g_458[0], g_10)), (safe_lshift_func_uint8_t_u_u(g_458[0], 1)))) > p_22));
        }
        else
        {
            uint32_t l_2032 = 0x5A3B6E36L;
            return l_2032;
        }
        l_1776 = l_45[0];
        return g_208;
    }
}







static int8_t func_23(int8_t p_24, uint8_t p_25, uint16_t p_26, int32_t p_27)
{
    uint16_t l_1640 = 1UL;
    int32_t l_1684 = 5L;
    for (p_24 = 21; (p_24 != (-17)); --p_24)
    {
        uint8_t l_1641 = 0UL;
        int32_t l_1642 = 1L;
        int32_t l_1659 = 0L;
        l_1642 = ((((safe_rshift_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(p_27, 7)) ^ ((((((safe_rshift_func_int8_t_s_s((~((g_405[8] && (safe_mod_func_uint8_t_u_u((0xACE4L != 0xAB04L), 0x7AL))) & l_1640)), g_8[0][1])) >= (0x059FL || ((l_1641 >= 0xC7228C1EL) < g_9))) & 0x9EL) == p_24) || p_25) , g_1625)), p_24)), 2)), l_1640)) ^ g_1195) != 0x95792450L) ^ g_227);
        l_1659 = (((safe_mod_func_uint16_t_u_u((0x973613BCL > g_830), (l_1640 | ((safe_rshift_func_int16_t_s_s(0x3FFAL, (safe_lshift_func_int16_t_s_u(((g_10 || (safe_lshift_func_int16_t_s_u(((l_1641 , l_1641) , (((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_u(((safe_mod_func_uint32_t_u_u(((safe_mod_func_uint32_t_u_u(((l_1641 , (g_9 > 0xE0315AD3L)) <= g_1588), l_1642)) > 0xC097L), 0x43E008B5L)) || 4294967295UL), p_25)), p_24)) , 0xA80F52FFL) & l_1640)), g_101))) <= l_1641), 2)))) > 252UL)))) , l_1641) > g_358);
        l_1684 = (((((((safe_mul_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint8_t_u_s(((safe_mul_func_int16_t_s_s(((safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_u(l_1640, 0)) == (((l_1640 >= (g_5[6] && l_1640)) > (p_26 >= (safe_add_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_u(l_1640, (g_508[1][9][0] , (((safe_sub_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u(((((g_208 , (1UL & g_754)) > l_1659) < 0UL) || 0xF2B8L), l_1640)) , 0xD990L), 6L)) | 0x90AEL) != g_1625)))) && g_208) && l_1640), p_25)))) , 1UL)), l_1659)), 1L)), 1UL)) && 0xB6F8L), p_27)) , l_1659), 2)), p_25)), 249UL)) && p_24) < (-1L)) >= g_10) && 0xCDL) > g_8[0][0]) , g_227);
        for (g_830 = 0; (g_830 >= (-23)); g_830 = safe_sub_func_int16_t_s_s(g_830, 7))
        {
            l_1642 = 0L;
        }
    }
    return l_1640;
}







static int16_t func_36(uint32_t p_37, int32_t p_38)
{
    for (p_37 = (-13); (p_37 == 10); p_37 = safe_add_func_uint16_t_u_u(p_37, 5))
    {
        return g_5[9];
    }
    return p_38;
}







static int16_t func_46(int8_t p_47, int32_t p_48, uint8_t p_49, int32_t p_50)
{
    uint32_t l_54 = 0x0B2B0402L;
    int32_t l_1520 = 0x4B97A823L;
lbl_1442:
    p_50 = ((safe_add_func_int32_t_s_s(func_36(l_54, g_8[0][1]), (safe_mul_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s((+((safe_sub_func_int8_t_s_s(g_2, (func_36(func_61(l_54, ((safe_rshift_func_uint16_t_u_u(0x021FL, (safe_mod_func_int32_t_s_s(l_54, 1L)))) , ((-8L) >= g_5[6])), l_54), g_9) == p_48))) | 9L)), p_49)) < 1UL) , l_54), 0UL)))) != 0x129EF3EDL);
    for (g_358 = 11; (g_358 <= 23); g_358 = safe_add_func_int8_t_s_s(g_358, 1))
    {
        uint32_t l_1425 = 18446744073709551606UL;
        int32_t l_1430[9] = {(-4L), 0x55F5237AL, (-4L), 0x55F5237AL, (-4L), 0x55F5237AL, (-4L), 0x55F5237AL, (-4L)};
        int i;
        g_580[2] = (((((safe_rshift_func_uint8_t_u_u((l_1425 , p_47), (safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u((((!(+0x6D3AL)) != 65526UL) > (!((l_1430[0] , (!2L)) >= (p_50 | (safe_mul_func_int16_t_s_s((((((0xE9L == l_1425) > p_47) && g_405[1]) | l_1425) && 0x0B4CL), p_47)))))), 0)) > 0L), g_101)))) > 0x51848BAAL) ^ p_50) >= (-1L)) && p_47);
        for (l_54 = 0; (l_54 > 5); l_54++)
        {
            uint32_t l_1441 = 0x3B2833C5L;
            int32_t l_1600 = (-7L);
            for (p_47 = 0; (p_47 >= 5); p_47 = safe_add_func_int32_t_s_s(p_47, 6))
            {
                g_830 = (safe_mod_func_uint16_t_u_u(((safe_mod_func_uint32_t_u_u(0UL, l_54)) ^ l_1430[0]), l_1441));
                if (g_101)
                    goto lbl_1442;
            }
            p_48 = (safe_lshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s(g_458[0], (((((safe_rshift_func_uint8_t_u_s(p_47, 1)) <= l_1441) == 0x7EL) < 0x1C77L) & (~l_1441)))), (safe_lshift_func_int8_t_s_u((l_1441 || ((((p_49 < (g_227 >= p_50)) != 1L) || 1UL) || 0x80L)), l_1425))));
            if (p_47)
                break;
            for (p_47 = (-15); (p_47 >= 15); p_47++)
            {
                int16_t l_1514 = 9L;
                uint32_t l_1599 = 0UL;
                for (p_50 = 16; (p_50 <= (-2)); p_50--)
                {
                    int32_t l_1515 = 1L;
                    for (l_1441 = 0; (l_1441 >= 14); l_1441 = safe_add_func_uint16_t_u_u(l_1441, 5))
                    {
                        p_48 = (safe_lshift_func_int8_t_s_u(g_520[1], (safe_sub_func_uint16_t_u_u(g_520[0], (safe_sub_func_int32_t_s_s(0xA6C3DB96L, ((safe_mod_func_int16_t_s_s(((safe_add_func_int8_t_s_s(0x93L, p_49)) != (p_50 == (safe_add_func_int32_t_s_s((safe_mul_func_uint16_t_u_u(0x0F69L, (safe_lshift_func_uint16_t_u_u(65527UL, 13)))), 0UL)))), 0xC3B3L)) > 9UL)))))));
                        p_48 = (safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_s((255UL <= (g_101 < (safe_unary_minus_func_int32_t_s((~p_50))))), (safe_sub_func_uint8_t_u_u(g_508[0][2][0], (((((4L != (-1L)) != 248UL) | g_520[0]) || ((safe_unary_minus_func_uint8_t_u((((safe_lshift_func_int8_t_s_s((0xDDL ^ g_405[8]), 0)) , 0L) & g_227))) >= 0x38L)) || 0xC96FD962L))))), p_49));
                        p_48 = (((((l_1425 ^ (((+(safe_mul_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s(65531UL, 4)) || (8L == (safe_add_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u(4294967286UL, (safe_lshift_func_uint16_t_u_u(g_508[2][4][0], 5)))) ^ ((safe_unary_minus_func_int32_t_s((safe_mul_func_int8_t_s_s(((safe_sub_func_int16_t_s_s((((((safe_add_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((safe_add_func_uint8_t_u_u(g_5[7], g_405[8])), (safe_lshift_func_uint16_t_u_u(p_49, 7)))), l_1430[4])) >= 0x123CL) > l_54) , p_48) , l_54), l_1441)) < l_1514), p_50)))) == p_47)) , g_5[6]), l_1515)), 12)), p_48)), 0x60FFL)))), p_49))) , p_48) <= 0x51L)) <= 4294967288UL) || 1UL) <= g_508[2][4][0]) , g_10);
                    }
                }
                for (p_50 = 0; (p_50 > (-6)); p_50 = safe_sub_func_int8_t_s_s(p_50, 8))
                {
                    int32_t l_1541 = 1L;
                    if ((safe_sub_func_int16_t_s_s(0xF400L, p_49)))
                    {
                        uint8_t l_1552 = 0UL;
                        uint8_t l_1553 = 1UL;
                        l_1520 = g_142[2][1];
                        g_830 = ((safe_mod_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u(l_1514, (safe_sub_func_uint32_t_u_u((((safe_add_func_int32_t_s_s((safe_mul_func_uint8_t_u_u((((g_406 , (p_50 ^ (safe_add_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u(((safe_add_func_int8_t_s_s((((((safe_sub_func_uint32_t_u_u((((g_1195 && l_1541) > g_520[1]) == (safe_add_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(((0x3CL || ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(l_1430[0], (safe_mod_func_int8_t_s_s(l_1541, g_227)))), l_1541)) >= p_49)) && p_49), l_1430[0])) >= p_47), l_1552))), l_1552)) && g_405[8]) < 1L) || 1UL) | g_9), g_8[1][1])) || g_580[2]), 65532UL)) || l_54), p_49)), l_54)))) == 0xE349AC0DL) || l_1430[0]), l_1552)), l_1553)) & p_50) <= p_48), g_5[0])))) >= l_1520), p_48)) & 0xE0C5L);
                    }
                    else
                    {
                        p_48 = (((safe_add_func_uint8_t_u_u((l_1430[0] & (safe_mul_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(((((safe_add_func_uint16_t_u_u(l_1514, p_48)) >= (g_580[3] && ((safe_sub_func_uint8_t_u_u((((safe_rshift_func_uint8_t_u_s(8UL, (((((safe_sub_func_int32_t_s_s(g_405[1], (p_48 || (g_580[1] || (safe_unary_minus_func_uint32_t_u((~0xCB5318F6L))))))) != 1L) | 0xD9L) & l_1520) && p_50))) >= l_1441) , g_101), g_458[0])) & g_227))) > l_54) , p_48), p_48)), 0x00CEL))), g_458[0])) , g_358) > 0xAAL);
                    }
                    if ((0UL && (l_1541 == 65531UL)))
                    {
                        int32_t l_1601 = (-2L);
                        p_48 = ((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((safe_unary_minus_func_int8_t_s((safe_add_func_int8_t_s_s(((((p_50 || (g_580[0] , (((-3L) > ((0x485EL || 0UL) > ((safe_add_func_int16_t_s_s((safe_mod_func_uint32_t_u_u(g_458[0], (((safe_lshift_func_int16_t_s_u((p_49 < (safe_mul_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((((safe_sub_func_int16_t_s_s(((((1L <= g_5[6]) || g_406) <= 7L) == l_1441), 1L)) == g_8[0][0]) , p_49), l_1541)), p_48))), 9)) || l_1514) | g_406))), (-10L))) & g_458[0]))) || l_1541))) == 0xF0L) >= p_50) , l_1520), g_405[8])))), g_580[0])) <= g_508[0][6][0]), l_54)) > p_47) , (-1L)) || g_458[0]);
                        if (g_1588)
                            continue;
                        g_580[1] = (safe_add_func_uint32_t_u_u(((g_458[0] < g_508[1][1][0]) & (((safe_lshift_func_int16_t_s_s((g_830 || g_8[0][0]), ((-5L) & (safe_lshift_func_uint16_t_u_u((((((safe_lshift_func_int8_t_s_s((((p_49 , (((g_9 ^ ((safe_mul_func_int8_t_s_s((((0x4304L && (+g_101)) , l_1541) & (-1L)), p_50)) , 65527UL)) < l_1599) | g_405[0])) , l_1600) < 0x7BL), 4)) >= 0UL) || p_47) == l_1601) <= l_1441), 12))))) ^ p_47) && l_54)), l_1541));
                    }
                    else
                    {
                        g_580[1] = (safe_mod_func_uint32_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u(2UL, ((((((g_10 < l_1541) > (safe_unary_minus_func_int32_t_s(g_10))) , (((l_1514 > (safe_sub_func_int32_t_s_s(((safe_mul_func_uint16_t_u_u((((((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((!0xE1D3L), l_1541)), ((p_49 && g_508[2][4][0]) || l_1520))) , g_1165) >= g_458[0]) != g_227) & p_47), g_405[8])) , 0xCFEA8D0CL), l_1541))) , 0x77L) <= l_54)) > p_47) == 0L) && g_101))), g_8[0][0])) & p_47) ^ p_47), 3UL));
                        if (l_1599)
                            goto lbl_1442;
                    }
                    if (g_458[0])
                        break;
                    p_48 = ((safe_add_func_int16_t_s_s((-1L), (safe_lshift_func_uint8_t_u_u((((-1L) == ((0x11L && (l_1441 , 0x99L)) & (((((safe_mod_func_uint16_t_u_u(p_48, (safe_mul_func_int8_t_s_s(p_49, g_1625)))) , 0x2752A5C7L) > g_580[1]) < l_1430[3]) , 4L))) & 6UL), 4)))) == 65535UL);
                }
            }
        }
        l_1520 = g_5[0];
    }
    return p_47;
}







static uint32_t func_61(uint16_t p_62, uint8_t p_63, int32_t p_64)
{
    int16_t l_83 = 0x81F0L;
    int32_t l_640 = 1L;
    int32_t l_661 = 0x37621463L;
    int16_t l_755 = 1L;
    int32_t l_763 = 0x91DAA854L;
    int32_t l_814 = 0xE6CF3267L;
    uint8_t l_921 = 250UL;
    uint32_t l_927 = 0x77982F67L;
    uint16_t l_974 = 65535UL;
    uint16_t l_997[3];
    int32_t l_1015 = 0x21F353DDL;
    int32_t l_1057 = 0xF3E5B39BL;
    int32_t l_1280 = (-1L);
    uint32_t l_1340 = 0UL;
    int i;
    for (i = 0; i < 3; i++)
        l_997[i] = 0xE02CL;
lbl_824:
    for (p_64 = 0; (p_64 <= 4); p_64++)
    {
        int32_t l_71[5][9][5] = {{{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}}, {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}}, {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}}, {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}}, {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}, {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}}};
        uint16_t l_686[3][7][10] = {{{65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}}, {{65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}}, {{65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}, {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL, 65535UL, 0xD2A9L, 0UL, 0x4DEDL}}};
        int32_t l_724[3][1][4];
        int i, j, k;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
            {
                for (k = 0; k < 4; k++)
                    l_724[i][j][k] = 0x90B84A7FL;
            }
        }
        for (p_63 = 0; (p_63 <= 4); p_63 += 1)
        {
            uint8_t l_637 = 0x74L;
            int16_t l_645[2][9][5] = {{{7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}}, {{7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}, {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}}};
            int i, j, k;
            for (p_62 = 0; (p_62 <= 4); p_62 += 1)
            {
                if (g_10)
                    break;
            }
            l_637 = func_72(((((g_10 >= 0L) != (((safe_mod_func_uint16_t_u_u((9L != p_64), func_36((((safe_mod_func_uint32_t_u_u(0x2FE49608L, ((g_8[1][0] & (func_78(g_2, ((((((((safe_mod_func_int8_t_s_s(l_83, (0x31L ^ p_62))) != 1L) | p_64) != l_71[3][5][2]) <= 65527UL) , g_9) , 0xD621L) < l_83)) , p_64)) , g_9))) , p_62) >= p_64), g_5[6]))) == 0x8A45DB5CL) < 0x9E86L)) || 0x69L) , g_405[8]));
            l_640 = (p_63 > (safe_add_func_uint8_t_u_u(0UL, 0L)));
            if (l_637)
                continue;
            for (l_640 = 0; (l_640 <= 4); l_640 += 1)
            {
                int32_t l_656 = 7L;
                uint16_t l_662 = 65526UL;
                for (g_208 = 0; (g_208 <= 4); g_208 += 1)
                {
                    int8_t l_660 = 0x91L;
                    for (l_637 = 0; (l_637 <= 4); l_637 += 1)
                    {
                        int8_t l_641 = 0x31L;
                        int32_t l_642 = 0x52312FD2L;
                        uint16_t l_659 = 0x51F4L;
                        l_641 = g_8[1][0];
                        l_642 = 0xABA84B95L;
                        g_580[3] = (safe_mul_func_uint8_t_u_u((((l_645[1][4][3] && (l_71[0][2][4] , (p_62 == (safe_rshift_func_int8_t_s_s((((safe_lshift_func_int8_t_s_s(((safe_lshift_func_int16_t_s_s((safe_sub_func_int8_t_s_s(l_656, ((safe_rshift_func_int16_t_s_s(l_71[0][4][0], (l_659 , (-1L)))) > g_2))), 14)) || (l_637 < 0UL)), g_405[5])) | 7L) > p_64), l_645[1][3][2]))))) , l_71[3][6][3]) >= l_660), p_63));
                    }
                    l_661 = p_62;
                }
                g_580[0] = (g_142[3][0] | (((l_656 >= (((((l_71[4][8][3] , l_662) < (safe_add_func_uint16_t_u_u((+((safe_mul_func_uint8_t_u_u(l_656, (safe_add_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int8_t_s(p_64)), 2)) & l_71[1][5][1]), (safe_rshift_func_int16_t_s_s(l_662, 1)))))) && ((safe_sub_func_int32_t_s_s(p_63, p_62)) , g_580[0]))), 0L))) , p_62) & p_64) || p_64)) , g_358) & 7L));
            }
        }
        for (g_101 = (-2); (g_101 != 53); g_101++)
        {
            uint32_t l_723 = 0UL;
            for (g_227 = 0; (g_227 <= 0); g_227 += 1)
            {
                uint32_t l_693 = 0x1280DB3CL;
                int32_t l_725[8][3] = {{9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}};
                int i, j;
                if (g_405[(g_227 + 2)])
                {
                    int i, j, k;
                    l_693 = ((safe_sub_func_uint16_t_u_u((g_508[(g_227 + 2)][(g_227 + 7)][g_227] & 0x09L), (((((((safe_mod_func_int32_t_s_s((safe_sub_func_int8_t_s_s(((p_62 == g_405[(g_227 + 2)]) , g_405[5]), (((safe_rshift_func_uint8_t_u_s(l_686[2][2][8], (!(0x23D2FE6FL < ((safe_rshift_func_uint16_t_u_s(((~(safe_mod_func_uint32_t_u_u(((((safe_mod_func_uint16_t_u_u(((((((g_580[1] ^ ((p_64 | p_63) > g_10)) , (-9L)) == g_405[8]) >= g_458[0]) < l_640) != 0x541A2144L), 0x35FBL)) != 0xA8583C15L) ^ p_62) && (-4L)), g_405[7]))) < 1L), 5)) , p_62))))) == 0x8B5A455AL) , l_83))), 0x5634D574L)) ^ (-8L)) | 0x8BL) < p_62) < g_227) <= g_405[8]) && g_142[1][0]))) || g_227);
                    l_724[2][0][3] = ((safe_add_func_int8_t_s_s(p_63, (safe_unary_minus_func_uint32_t_u((0x4E926192L | (safe_add_func_int16_t_s_s(((safe_mul_func_int8_t_s_s((0x61CDL && (5UL & (safe_add_func_int8_t_s_s((safe_add_func_int32_t_s_s((+(-2L)), (((((((((safe_sub_func_uint16_t_u_u((+(((safe_mul_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(((safe_add_func_int32_t_s_s(p_62, p_62)) | g_5[6]), (safe_unary_minus_func_int8_t_s((safe_unary_minus_func_uint32_t_u((((safe_lshift_func_int8_t_s_s(((safe_sub_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((0x3FA9B884L == g_508[2][4][0]), 0)) > p_62) > g_10), p_62)), g_101)) > l_693), g_142[1][1])) ^ p_64) && g_580[1]))))))), 1UL)) ^ p_62) || 6L)), 0x9512L)) > g_142[3][1]) >= g_405[(g_227 + 2)]) >= l_723) , g_508[(g_227 + 2)][(g_227 + 7)][g_227]) == 0xC5L) != l_723) , p_63) || p_64))), g_10)))), p_64)) && g_405[4]), g_508[(g_227 + 2)][(g_227 + 7)][g_227]))))))) < p_64);
                }
                else
                {
                    for (g_208 = 0; (g_208 <= 4); g_208 += 1)
                    {
                        return p_64;
                    }
                    l_725[3][1] = 0L;
                }
                for (l_83 = 0; (l_83 >= 0); l_83 -= 1)
                {
                    int32_t l_726 = 1L;
                    g_580[1] = l_726;
                    if (l_723)
                        break;
                    return g_101;
                }
            }
        }
        if (g_2)
            break;
    }
    for (p_64 = 0; (p_64 >= 0); p_64 -= 1)
    {
        uint16_t l_727[1];
        int32_t l_756[3];
        int32_t l_823 = 0x9C30125BL;
        int32_t l_1306 = 0xEC270E8BL;
        uint8_t l_1355 = 1UL;
        int i;
        for (i = 0; i < 1; i++)
            l_727[i] = 0x2E4CL;
        for (i = 0; i < 3; i++)
            l_756[i] = (-2L);
        for (l_83 = 0; (l_83 >= 0); l_83 -= 1)
        {
            int32_t l_789[9][5][3] = {{{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}, {{(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}, {(-1L), 1L, 0x85AF06F7L}}};
            int i, j, k;
            l_727[0] = (g_458[l_83] , g_2);
            l_756[2] = (0xCD2CL && (((((((0xE1L && (safe_mod_func_uint32_t_u_u((((safe_mod_func_uint32_t_u_u(((safe_mul_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((0UL != g_508[2][4][0]), (safe_lshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s(((((safe_rshift_func_int8_t_s_u((g_458[0] , (((safe_mul_func_int8_t_s_s((safe_add_func_int8_t_s_s(((((safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u(g_405[3], (safe_mul_func_int16_t_s_s(((g_520[0] > ((g_458[l_83] , g_406) && g_508[0][7][0])) == l_727[0]), 65532UL)))) == g_458[0]), 7)) <= p_62), l_727[0])) != g_208) >= 0UL) && g_5[6]), (-1L))), p_64)) ^ g_10) > g_458[l_83])), g_208)) & g_508[1][0][0]) ^ 0xE994016DL) && 1UL), 0xC9F6559CL)), g_458[0])))) == p_62), g_754)) , p_62), l_727[0])) <= 9UL) <= (-4L)), l_727[0]))) >= l_755) >= p_62) & p_63) & g_8[2][1]) != 0L) >= 1UL));
            l_756[0] = (safe_sub_func_int16_t_s_s((((safe_sub_func_int16_t_s_s(p_62, (safe_lshift_func_uint16_t_u_s(g_458[l_83], l_763)))) ^ l_83) >= (l_640 , l_83)), ((safe_add_func_uint16_t_u_u(g_458[l_83], (safe_add_func_uint16_t_u_u(((p_62 && ((safe_rshift_func_int8_t_s_s(((safe_unary_minus_func_uint16_t_u(5UL)) , p_64), g_2)) , l_756[1])) && 252UL), 0xD886L)))) || p_62)));
            l_789[1][1][1] = ((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_mod_func_int16_t_s_s(p_62, (safe_lshift_func_uint8_t_u_u((((g_458[0] == (safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((l_661 < ((safe_sub_func_int8_t_s_s((-4L), g_5[8])) == (safe_sub_func_int16_t_s_s((((+(g_405[2] & (p_64 > (safe_rshift_func_int8_t_s_u(p_62, ((p_64 < l_756[1]) < g_754)))))) >= p_62) > 0xC3L), p_63)))), 3)), g_406))) || g_101) & p_62), g_208)))), 2)), g_458[l_83])) <= g_8[0][1]) || g_9) > 0x8AFB7F0AL);
        }
        if ((((((g_358 && p_63) != g_458[0]) >= (safe_lshift_func_uint8_t_u_u(((((((safe_lshift_func_int8_t_s_u(((((~((safe_rshift_func_uint16_t_u_s((((safe_add_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(((((0x96L < (!g_101)) > (((safe_mul_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((((safe_lshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s((safe_mul_func_uint8_t_u_u((((safe_mod_func_int16_t_s_s((l_814 >= (((safe_add_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(65526UL, (safe_rshift_func_int8_t_s_s(((0x31D7DD22L && (((~(safe_sub_func_int16_t_s_s(p_62, l_814))) != l_756[2]) == g_405[3])) & p_62), 0)))), p_62)) < g_406) , 4UL)), 0xC3E5L)) || g_101) | 1L), l_727[0])), p_62)) != l_727[0]), p_64)) , l_823) <= 0L), l_763)), p_62)) > p_64) <= l_756[2])) , g_406) & 0x6981L), g_458[0])), 4294967295UL)) != 0UL), 0xBAL)) | g_5[9]) <= g_580[2]), 5)) && g_520[3])) & 2UL) > 0x0DL) >= l_756[2]), p_64)) == (-1L)) <= l_727[0]) | g_580[1]) < p_62) , 0xCCL), 5))) && g_208) ^ p_62))
        {
            uint32_t l_850 = 3UL;
            for (g_358 = 0; (g_358 <= 0); g_358 += 1)
            {
                uint32_t l_827 = 18446744073709551608UL;
                int32_t l_853 = 0xA6453C23L;
                for (g_101 = 0; (g_101 <= 0); g_101 += 1)
                {
                    int i;
                    if (l_727[g_101])
                    {
                        int16_t l_849 = (-10L);
                        uint8_t l_851 = 0xB2L;
                        uint16_t l_852 = 0UL;
                        if (l_814)
                            goto lbl_824;
                        l_853 = (!((safe_mod_func_uint32_t_u_u((((l_827 == (l_827 , ((((safe_add_func_int16_t_s_s(((g_830 < (((p_62 | ((((safe_lshift_func_int8_t_s_u((safe_mul_func_uint16_t_u_u(((((safe_add_func_int8_t_s_s(((((((safe_add_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int16_t_s((safe_unary_minus_func_uint16_t_u(((safe_mul_func_int16_t_s_s(((((p_62 || ((g_830 , (((safe_rshift_func_int16_t_s_u(g_520[2], 4)) | 248UL) != g_754)) ^ l_827)) <= p_62) , l_849) != p_64), l_850)) > g_227))))), l_83)) || 9L) && g_458[0]), g_142[1][4])) == 0x87AFL), p_63)) && g_142[2][1]) > 0x31A8B881L) , g_2) , l_851) | l_827), l_852)) < g_8[1][0]) > p_63) || 1L), 0x3521L)), 7)) , g_508[0][2][0]) ^ g_405[8]) > 255UL)) == l_727[0]) || 0UL)) & g_9), 0xF6C2L)) > g_101) || g_458[0]) , p_64))) < 4294967292UL) ^ l_853), 0xDB2E79DAL)) < 0UL));
                    }
                    else
                    {
                        return g_580[0];
                    }
                    l_853 = ((p_62 <= (l_727[g_101] >= (safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u(p_63, ((safe_rshift_func_int8_t_s_s(0x2CL, (safe_sub_func_uint32_t_u_u(((0x50L | (safe_add_func_int16_t_s_s(((((0xF4L < 0x8EL) & 4UL) || (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_u(l_727[g_101], 11)) && 1L), p_64))) & 255UL), l_853))) ^ l_756[2]), g_458[0])))) < l_827))), p_63)), l_727[0])), p_64)) & g_520[5]), 4)))) & 0x3EL);
                }
                if (p_62)
                    continue;
                if (l_850)
                    continue;
            }
            l_756[2] = ((p_62 != (l_756[2] | (((((safe_mul_func_uint8_t_u_u(0x2AL, g_754)) != (safe_mul_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((g_458[0] | p_64), ((((((safe_add_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(1UL, 14)), (((safe_mod_func_int16_t_s_s(((safe_mul_func_uint16_t_u_u(((((p_64 , 4294967295UL) & g_580[1]) | l_850) || g_227), l_756[0])) , l_756[0]), g_8[0][0])) < 0x5671L) , g_5[5]))) <= p_63) < 0x55L) == p_63) >= g_9) < 0x317A8966L))), 0x2DB7L))) , 1L) & p_64) | g_9))) < g_754);
            if (g_101)
                continue;
        }
        else
        {
            int32_t l_904[9][4] = {{(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}, {(-5L), 1L, (-1L), 1L}};
            int32_t l_922 = 0L;
            int8_t l_950 = 8L;
            int32_t l_964 = (-6L);
            int16_t l_973[4];
            uint32_t l_1123 = 18446744073709551606UL;
            int i, j;
            for (i = 0; i < 4; i++)
                l_973[i] = 9L;
            for (g_830 = 0; (g_830 >= 0); g_830 -= 1)
            {
                uint32_t l_890[1][6] = {{4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL}};
                int i, j;
                g_580[2] = (((g_9 == (!l_890[0][3])) , (~(((safe_mod_func_int8_t_s_s((l_890[0][3] >= p_63), ((safe_lshift_func_uint16_t_u_s((((safe_mod_func_uint8_t_u_u(((l_756[0] <= g_830) || (((!(safe_unary_minus_func_uint16_t_u(((0x1B0EL & (safe_sub_func_int8_t_s_s(((((((safe_mod_func_int8_t_s_s(((safe_add_func_uint32_t_u_u(l_755, ((l_83 < p_63) ^ l_904[5][3]))) >= l_727[0]), 0x59L)) ^ 0x89A0L) | g_142[0][0]) >= g_405[8]) <= 0xBB51L) ^ g_5[9]), g_227))) <= p_64)))) == l_640) == l_661)), p_64)) <= 0xBEF9L) , p_62), p_63)) | 0UL))) , l_727[0]) , p_62))) <= 65528UL);
                g_580[1] = (((!((safe_sub_func_int16_t_s_s((l_727[0] >= (safe_mul_func_int16_t_s_s(((safe_mul_func_int16_t_s_s(((0x0EL || ((safe_rshift_func_int8_t_s_u(((l_904[2][0] >= ((safe_mod_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u((+l_640), (safe_sub_func_uint8_t_u_u(((l_763 < l_904[5][3]) >= (((0xD7C1E087L <= ((((((safe_add_func_uint8_t_u_u(1UL, g_520[1])) && l_890[0][3]) >= g_458[0]) & 0x1AL) ^ 0x17F9L) | p_63)) || l_763) < p_64)), g_754)))) & 0UL), l_904[4][3])) > p_62)) != p_63), l_763)) <= l_890[0][3])) || 65534UL), p_62)) < (-1L)), 1UL))), l_921)) && l_814)) != g_520[6]) > l_727[0]);
                for (l_763 = 0; (l_763 >= 0); l_763 -= 1)
                {
                    int8_t l_928 = 0xB2L;
                    int32_t l_951[3];
                    int i;
                    for (i = 0; i < 3; i++)
                        l_951[i] = (-10L);
                    if ((4L <= g_458[0]))
                    {
                        l_922 = l_904[7][1];
                        return p_63;
                    }
                    else
                    {
                        l_640 = 7L;
                        g_580[1] = 1L;
                        g_580[1] = ((l_890[0][4] >= (g_520[2] || ((safe_add_func_uint16_t_u_u(((((g_5[3] | (p_64 ^ (((65535UL ^ ((safe_mul_func_int16_t_s_s(1L, 0UL)) >= p_63)) > ((l_927 && g_520[5]) ^ p_62)) , l_727[0]))) & l_756[2]) == g_406) != 2L), l_928)) > 4294967294UL))) , 5L);
                    }
                    for (l_823 = 0; (l_823 <= 0); l_823 += 1)
                    {
                        l_922 = ((safe_sub_func_uint16_t_u_u((((safe_mul_func_int8_t_s_s((+(safe_sub_func_int32_t_s_s(p_62, ((safe_sub_func_int8_t_s_s((((((safe_rshift_func_uint8_t_u_u(g_5[6], (p_63 < (p_62 || (safe_sub_func_uint8_t_u_u((p_62 & (safe_rshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(((safe_unary_minus_func_int32_t_s(g_358)) , l_950), g_458[0])), 7)), 9)), ((g_405[8] ^ 0UL) <= l_922)))), p_62)))))) >= g_227) , l_922) != p_64) && p_64), 0L)) & g_406)))), l_928)) & 0xABL) || g_830), p_64)) <= g_520[0]);
                        return l_951[1];
                    }
                    for (l_928 = 0; l_928 < 1; l_928 += 1)
                    {
                        l_727[l_928] = 0x7BD8L;
                    }
                    l_756[2] = 1L;
                }
            }
            g_580[1] = g_458[0];
            if (((((((safe_mod_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((p_62 ^ (((g_5[4] == (((((((g_754 >= (safe_rshift_func_int8_t_s_s((((g_830 & (safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(g_508[2][4][0], p_63)), 1))) , ((g_406 > ((l_964 ^ (safe_lshift_func_int8_t_s_s((((((safe_add_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_s(((((((((safe_add_func_int8_t_s_s(0x5BL, l_727[0])) < p_64) & 0x8B34L) || l_814) <= l_823) , 0x58L) || l_756[0]) == p_62), p_64)) | l_763), 255UL)) || g_508[2][4][0]) < g_405[8]) != l_973[3]) | 4UL), 3))) , 2L)) | g_8[0][0])) , l_974), 3))) <= p_62) ^ g_208) & g_508[2][4][0]) > 1UL) , 0x57L) <= g_208)) , 0x4CD98EB1L) & 1L)), p_64)) && p_64), p_62)), l_973[3])) | g_580[0]) != 7UL) && l_727[0]) == g_9) <= p_63))
            {
                int32_t l_990[10][10][2] = {{{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}, {{0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}, {0x9F73B750L, (-4L)}}};
                uint16_t l_1058 = 0xDDC3L;
                int32_t l_1095 = (-6L);
                uint16_t l_1152[4][5] = {{1UL, 1UL, 0xD25DL, 0x11DDL, 0xC6A8L}, {1UL, 1UL, 0xD25DL, 0x11DDL, 0xC6A8L}, {1UL, 1UL, 0xD25DL, 0x11DDL, 0xC6A8L}, {1UL, 1UL, 0xD25DL, 0x11DDL, 0xC6A8L}};
                uint32_t l_1193 = 0xDA9E0F60L;
                int i, j, k;
                for (g_406 = 2; (g_406 >= 0); g_406 -= 1)
                {
                    int16_t l_985 = 0x6F80L;
                    int i;
                    l_990[2][5][1] = ((0xF8D1L != (safe_lshift_func_int8_t_s_s(l_756[p_64], 1))) > (g_5[3] <= ((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u(((((((((g_142[4][2] , (l_985 >= (l_974 == p_63))) ^ (safe_mod_func_int16_t_s_s(((l_756[1] & (safe_add_func_int32_t_s_s((p_64 == p_63), g_520[5]))) , l_727[0]), 2L))) && g_508[2][4][0]) || 0L) || 0UL) & 0xC3DBB9F8L) & g_2) <= (-1L)), l_904[3][2])) && p_64), 7)) , p_62) , g_9) | 0xA5EE051CL)));
                }
                for (l_763 = 0; (l_763 <= 0); l_763 += 1)
                {
                    if (l_990[6][2][1])
                        break;
                }
                if (((((248UL >= p_63) & p_62) && p_62) != (safe_lshift_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u(246UL, (((safe_add_func_int32_t_s_s((l_997[0] <= (safe_add_func_uint8_t_u_u(((0xD6L && (g_208 | 0x3A76L)) | p_62), p_62))), l_823)) || 65535UL) == g_406))), 9))))
                {
                    int32_t l_1016 = 0xCADE2AB4L;
                    if ((safe_rshift_func_uint8_t_u_s(((((l_904[5][3] || ((safe_add_func_int32_t_s_s(((((safe_add_func_uint16_t_u_u(0xE377L, (safe_lshift_func_int16_t_s_u((((safe_unary_minus_func_int8_t_s((safe_mul_func_uint16_t_u_u(p_62, (safe_rshift_func_int16_t_s_u(((p_63 && (safe_add_func_uint8_t_u_u(251UL, (0x6130L < (g_520[3] | 0xBA19AC48L))))) > (0x21D4L > l_1015)), g_406)))))) , l_973[3]) , l_1016), 15)))) , p_64) && p_63) , g_830), 0x2D094497L)) == l_922)) <= p_62) == p_64) ^ g_5[4]), 1)))
                    {
                        int16_t l_1063 = 0xB889L;
                        int32_t l_1076 = 0x97144F28L;
                        g_830 = (g_508[2][4][0] , (safe_rshift_func_uint8_t_u_u(p_63, (safe_lshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((g_9 && (safe_sub_func_int16_t_s_s(((((safe_add_func_uint16_t_u_u((safe_add_func_int8_t_s_s((((safe_sub_func_uint8_t_u_u(g_2, l_756[1])) <= (safe_lshift_func_uint16_t_u_s(g_520[0], 9))) || (safe_mul_func_int16_t_s_s((-1L), ((p_64 & (((((g_754 ^ g_580[0]) & p_62) , p_62) & p_63) || 0xB8456F11L)) ^ 1L)))), l_763)), 0x832BL)) || l_973[1]) <= l_922) || p_62), p_64))), 5)), 1)))));
                        l_1058 = (safe_rshift_func_int8_t_s_s(l_755, ((safe_rshift_func_uint8_t_u_s(l_727[0], (((-6L) & 0x273874EBL) < (safe_mod_func_int8_t_s_s(g_9, ((((l_964 <= (((safe_add_func_int8_t_s_s((safe_add_func_uint8_t_u_u(0x80L, (safe_add_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(l_1016, ((safe_lshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u((((((p_64 == p_64) == 0x7568155AL) >= l_1057) , 65529UL) && (-9L)), l_756[2])), 0xF6ADL)), 1)) | g_227), g_5[6])) > (-1L)))), l_950)))), g_208)) > 3L) < g_10)) == g_754) , 1L) && l_1016)))))) , 0x94L)));
                        l_1076 = (safe_mul_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s(l_1063, ((~((+(safe_lshift_func_int8_t_s_s(((!(~(l_973[3] != (((safe_mul_func_int8_t_s_s((l_1063 <= l_1063), p_64)) , ((safe_add_func_uint16_t_u_u(((p_64 && ((safe_mul_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s((safe_mul_func_uint16_t_u_u(p_62, l_1058)), 1UL)) , g_2), g_580[1])) >= 0x801A5322L)) > l_990[2][5][1]), g_458[0])) , g_458[0])) != p_64)))) , l_756[1]), 0))) || (-5L))) ^ 0xEF0240FEL))), (-2L)));
                    }
                    else
                    {
                        g_580[3] = g_520[2];
                        if (p_62)
                            continue;
                        if (p_62)
                            break;
                    }
                    for (l_1057 = 0; (l_1057 <= 0); l_1057 += 1)
                    {
                        int i;
                        g_580[1] = (safe_lshift_func_uint16_t_u_s((~(safe_rshift_func_int16_t_s_s(l_973[(l_1057 + 2)], 15))), ((((g_520[0] & (((!(safe_lshift_func_uint8_t_u_u(((l_727[0] != (p_63 != l_990[2][0][0])) & ((safe_sub_func_int8_t_s_s((((g_406 >= ((p_64 , p_62) | (l_727[0] > 0UL))) , 3L) & 0x3077710BL), l_973[(l_1057 + 2)])) , 0xAEB0AC0BL)), 7))) || 0x45D8L) , l_990[2][5][1])) & g_580[1]) & 0UL) && l_990[2][5][1])));
                        l_1095 = (+((+(safe_mod_func_int16_t_s_s((safe_mod_func_int8_t_s_s((safe_mod_func_int16_t_s_s((-6L), l_1016)), 5L)), (safe_mul_func_uint16_t_u_u(((((((+l_661) == g_520[2]) && l_904[5][3]) < (safe_mul_func_uint16_t_u_u(g_5[4], (((g_508[1][7][0] , g_142[2][2]) , (-1L)) | p_63)))) != l_814) == 0xE3D17476L), g_9))))) ^ l_756[2]));
                        g_830 = 0x8E45BA00L;
                    }
                }
                else
                {
                    return p_62;
                }
                for (l_974 = 0; (l_974 <= 0); l_974 += 1)
                {
                    int i, j;
                    if (((safe_mod_func_int32_t_s_s(((((safe_mod_func_int32_t_s_s((((((((safe_mod_func_int8_t_s_s(((((safe_mul_func_int8_t_s_s(2L, ((safe_rshift_func_int8_t_s_u((~(safe_lshift_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s(((~(safe_mod_func_int16_t_s_s((0xF9L > 0xDFL), l_904[p_64][(p_64 + 1)]))) && (((g_458[p_64] <= (((((safe_sub_func_int8_t_s_s(l_904[0][2], (safe_lshift_func_uint16_t_u_s(0UL, 9)))) , ((((safe_lshift_func_uint8_t_u_u(((safe_add_func_int16_t_s_s(((safe_unary_minus_func_int16_t_s(p_63)) > ((safe_add_func_int8_t_s_s(((0xE3608696L == l_756[2]) | l_990[0][3][1]), g_458[0])) & g_458[0])), 0x4250L)) , 0xEBL), 3)) > p_64) != 249UL) && l_727[0])) , p_62) & p_63) || l_640)) & l_950) <= l_927)), g_2)) && l_727[0]) <= p_62) , 0x68DFL), 9))), 0)) <= 65532UL))) , g_508[0][4][0]) , g_520[1]) || l_974), 0xC0L)) <= 0UL) & g_830) >= 0x5457B129L) & 4L) < 0xD20CC5A8L) || g_508[2][4][0]), l_1123)) , 0UL) | g_754) , l_990[6][2][0]), l_927)) < p_64))
                    {
                        int16_t l_1131 = 1L;
                        l_1131 = (l_1058 , ((((safe_sub_func_uint32_t_u_u(l_974, l_1058)) == ((p_64 >= 0x2F24AB06L) , 4294967293UL)) > (g_754 && (safe_unary_minus_func_int32_t_s((safe_mul_func_uint16_t_u_u(((g_520[0] == (safe_mul_func_uint8_t_u_u((g_227 , g_520[5]), p_62))) , 0xB353L), p_62)))))) > g_8[1][0]));
                        l_1152[1][3] = (safe_sub_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(4294967288UL, ((safe_rshift_func_int8_t_s_s((safe_mod_func_uint16_t_u_u(((safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s((l_756[2] | p_63), l_756[0])), ((safe_sub_func_int8_t_s_s(((p_63 < ((p_64 <= p_63) & (l_1095 > (safe_mul_func_uint8_t_u_u(p_62, g_208))))) < 0xE0L), 1UL)) < l_1095))) ^ l_1058), (-4L))), g_580[2])) && g_9))), g_2)), 0xE6L)), 0L));
                        l_756[2] = ((safe_sub_func_uint16_t_u_u((!l_973[3]), ((safe_add_func_uint16_t_u_u((((safe_sub_func_int16_t_s_s((((((+(g_2 == (safe_mod_func_int16_t_s_s(p_64, ((!((safe_sub_func_uint32_t_u_u(l_1057, 6L)) == (((((l_1131 , (((l_823 > ((safe_add_func_int32_t_s_s(0xC231CB9CL, 0xCB6EA573L)) < g_2)) && g_580[0]) | g_2)) > g_1165) , 0x1EADAC8EL) == g_830) && (-2L)))) & 8L))))) | l_755) == 0x83D4FE7EL) <= g_458[0]) & g_405[8]), l_904[p_64][(p_64 + 1)])) >= 1L) , g_580[1]), g_9)) < l_1131))) || p_64);
                    }
                    else
                    {
                        uint16_t l_1194 = 0xA356L;
                        l_1095 = ((safe_rshift_func_uint16_t_u_u(l_1095, 8)) == (((safe_mul_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((((((safe_lshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s(0x31L, (((g_405[0] || 0xEEECL) >= g_8[2][1]) | 5L))), 13)) && ((safe_add_func_int8_t_s_s((l_904[p_64][(p_64 + 1)] , (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(l_950, l_755)), 1))), l_756[1])) >= 1UL)) <= p_64) , g_8[2][0]) < 0L), 65535UL)), 0x85L)) >= l_1152[2][4]) ^ g_208));
                        l_1194 = (((~(safe_mul_func_int8_t_s_s((p_63 >= (safe_mul_func_int16_t_s_s(((((((((safe_rshift_func_uint16_t_u_s(2UL, ((safe_add_func_int16_t_s_s((l_1058 > p_64), (p_64 >= (safe_sub_func_int8_t_s_s((g_8[0][1] | (l_904[p_64][(p_64 + 1)] <= (safe_unary_minus_func_uint32_t_u(((((((9L >= (0x7D23L != g_508[1][5][0])) >= g_101) | 0L) < g_830) < 5L) || g_227))))), 255UL))))) , p_63))) == p_64) && p_62) < g_2) == l_904[p_64][(p_64 + 1)]) ^ g_520[0]) || p_62) < l_1193), 0x519EL))), p_63))) , 9UL) , l_950);
                        g_830 = g_2;
                    }
                    if (g_1195)
                        continue;
                }
            }
            else
            {
                uint8_t l_1222 = 2UL;
                uint32_t l_1281 = 1UL;
                uint32_t l_1282 = 0UL;
                int32_t l_1323 = (-5L);
                if (l_727[0])
                    break;
                for (l_927 = 0; (l_927 <= 0); l_927 += 1)
                {
                    int8_t l_1214 = 8L;
                    int8_t l_1303 = 0xCBL;
                    if (((safe_lshift_func_int16_t_s_s(p_63, (l_964 == ((safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s(0x27L, ((safe_lshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(((safe_lshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s(((safe_rshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(l_1214, p_62)), 13)) | ((safe_unary_minus_func_int32_t_s(l_904[1][1])) && (safe_add_func_uint16_t_u_u(l_997[0], (g_5[3] | ((safe_lshift_func_int8_t_s_u(7L, p_63)) == l_1222)))))), l_997[0])), 0)) <= 4294967286UL), g_830)), g_754)) || 1L))), g_508[2][4][0])) , p_62)))) , l_997[0]))
                    {
                        if (l_727[0])
                            break;
                    }
                    else
                    {
                        g_580[1] = ((((g_358 & ((((p_64 != l_1222) , (((safe_mul_func_int16_t_s_s(0xF19BL, g_830)) != (safe_mul_func_int8_t_s_s(((((((safe_mul_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(p_62, (safe_add_func_int32_t_s_s((l_727[0] ^ (safe_mul_func_int16_t_s_s((safe_mul_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_406, (~p_64))), g_1195)), p_62))), l_950)))) && p_63) > p_63), p_63)) ^ 9UL) <= p_62) <= 65532UL) < 1UL) == 0x3964L), g_520[3]))) ^ 252UL)) || 0x1805L) , (-7L))) == p_64) < 0x90L) > 0UL);
                    }
                    for (g_830 = 0; (g_830 <= 0); g_830 += 1)
                    {
                        uint32_t l_1279 = 0UL;
                        g_580[1] = ((safe_rshift_func_int16_t_s_s(0x7D76L, (safe_rshift_func_uint8_t_u_u(g_2, ((safe_mod_func_uint16_t_u_u((((safe_mod_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(((safe_add_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u((p_62 >= ((safe_mul_func_uint8_t_u_u(((g_101 == l_1214) < ((safe_lshift_func_uint8_t_u_u((((safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u((((l_1123 == ((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((0x1470L || (safe_lshift_func_int16_t_s_u((((safe_sub_func_int8_t_s_s(l_1279, ((((p_64 < 0x03L) <= g_406) & 0x2ADDL) != g_580[0]))) & p_62) > p_64), l_1279))), 0x058AL)), 9L)), l_1280)), l_1281)), (-1L))) > l_1214)) < l_1282) , 0xDBL), p_62)), 0xB9276A9FL)) , 0xB6AEL) || l_973[3]), 1)) , p_63)), l_756[2])) <= l_974)), g_1165)) > l_756[2]), 1)) || 1UL), 10)), l_1282)) == g_227), p_63)) | l_964), l_1015)) | g_142[3][3]) , 65531UL), l_727[0])) , p_63))))) ^ p_62);
                    }
                    g_580[1] = ((((((safe_mul_func_int8_t_s_s(p_62, ((safe_rshift_func_int16_t_s_u(0xAEBBL, ((safe_mul_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(g_2, g_508[2][7][0])), g_405[1])) | (safe_lshift_func_uint8_t_u_s((+((g_9 <= ((safe_mul_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_s(((l_756[1] || (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(0x4CL, p_63)), l_1303)), 2))) , g_9), 9)) , l_950), 0xBFL)) < 1L)) != p_64)), 0))))) < 254UL))) , l_964) != 65534UL) , l_756[2]) & p_64) , l_1281);
                    g_580[1] = (-10L);
                }
                for (g_101 = 0; (g_101 <= 0); g_101 += 1)
                {
                    l_1323 = ((g_830 | ((safe_add_func_uint32_t_u_u((l_640 , (l_1306 && (((((safe_add_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(((safe_sub_func_uint16_t_u_u(((g_1165 < 0xC28FL) && (255UL | ((~((safe_add_func_uint16_t_u_u((safe_sub_func_int16_t_s_s((((safe_mod_func_uint8_t_u_u((p_63 >= p_63), (safe_lshift_func_uint16_t_u_s(p_63, g_208)))) & 0L) , 0x09BEL), 0xA83BL)), 1L)) > g_405[7])) , 0x00L))), g_458[0])) || l_921), l_756[2])), 0x5FL)), l_997[1])) < 1L) < g_580[1]) <= p_63) | 0xF1L))), p_62)) | 0x0BA29BD4L)) && l_964);
                    g_580[1] = p_64;
                    for (l_83 = 0; (l_83 <= 0); l_83 += 1)
                    {
                        uint16_t l_1324[6][5] = {{0x4A7AL, 65535UL, 2UL, 65535UL, 0x4A7AL}, {0x4A7AL, 65535UL, 2UL, 65535UL, 0x4A7AL}, {0x4A7AL, 65535UL, 2UL, 65535UL, 0x4A7AL}, {0x4A7AL, 65535UL, 2UL, 65535UL, 0x4A7AL}, {0x4A7AL, 65535UL, 2UL, 65535UL, 0x4A7AL}, {0x4A7AL, 65535UL, 2UL, 65535UL, 0x4A7AL}};
                        int32_t l_1325 = 0x0AC3F34CL;
                        int i, j;
                        l_1325 = l_1324[1][4];
                        return g_520[4];
                    }
                }
                if ((((safe_lshift_func_uint16_t_u_u(((g_2 , ((safe_sub_func_int16_t_s_s(((safe_add_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(p_64, g_405[8])), (g_1165 && (safe_mod_func_int16_t_s_s(((3UL == (p_64 && ((g_10 ^ (((safe_mul_func_int16_t_s_s(0xE06FL, ((safe_add_func_uint16_t_u_u(g_754, l_1340)) , g_8[0][0]))) , g_2) , p_64)) , 0x3140L))) < p_64), g_405[8]))))) < 0x90L), g_142[3][1])) < g_358)) , l_823), 14)) || p_62) != l_1282))
                {
                    l_1306 = (l_973[3] ^ ((l_1306 > ((safe_lshift_func_uint8_t_u_u((p_64 && (((safe_mul_func_uint8_t_u_u(0xC4L, ((((~((safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(255UL, 0x63L)), ((((g_508[2][4][0] ^ ((((((g_10 ^ (safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((safe_mul_func_uint8_t_u_u((l_1281 < g_458[0]), p_62)), 15)), l_1355))) < l_727[0]) | g_8[1][1]) <= (-1L)) , 0x87L) | 248UL)) & 0x1E0CL) == l_1123) ^ 0x1BCC6511L))) , 0L)) == p_62) && 0x55F9L) > p_62))) , 1L) ^ g_520[1])), 3)) | g_101)) <= g_520[7]));
                }
                else
                {
                    uint16_t l_1364 = 0xA54AL;
                    int32_t l_1366 = (-8L);
                    for (l_755 = 0; (l_755 >= 0); l_755 -= 1)
                    {
                        int8_t l_1365 = (-1L);
                        l_1366 = (((l_964 | (p_62 == 7L)) , (((safe_sub_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u((((0xB14F7415L || (0xC3L & ((p_64 , ((1L >= p_63) || (safe_add_func_int8_t_s_s((((p_63 || 0L) != l_1364) || l_756[2]), l_1365)))) > 0UL))) <= l_921) >= p_64), p_64)) , 4UL), 0x7B83L)) || g_406) >= p_64)) != 65526UL);
                    }
                    g_580[1] = g_520[0];
                    for (g_406 = 0; (g_406 <= 0); g_406 += 1)
                    {
                        int8_t l_1381[7];
                        int i;
                        for (i = 0; i < 7; i++)
                            l_1381[i] = 0x3DL;
                        g_830 = ((safe_rshift_func_uint8_t_u_u((g_5[2] > (p_62 ^ ((((l_823 | (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(p_62, (((0x8D89FDC7L || (safe_mod_func_uint8_t_u_u((((+((safe_mul_func_int8_t_s_s((p_63 , (((safe_sub_func_int32_t_s_s(g_1195, g_227)) || (safe_mul_func_int8_t_s_s(l_1323, 0xD1L))) < 0x05D53980L)), l_1381[2])) != l_1381[4])) != g_508[2][4][0]) > g_754), p_63))) && 0L) , 4UL))), p_64))) | p_64) < 0xBA0DEFB6L) == g_5[6]))), 1)) ^ p_64);
                        l_1057 = (((p_63 != (safe_lshift_func_uint8_t_u_u(((p_64 ^ g_520[7]) != p_62), (g_358 > (l_1222 && l_973[3]))))) | ((safe_add_func_int32_t_s_s((p_64 == g_406), p_64)) >= g_1195)) || g_8[0][0]);
                        l_922 = ((~g_580[1]) && ((((safe_rshift_func_int8_t_s_s(g_2, p_62)) , (safe_mul_func_int16_t_s_s(g_406, 65535UL))) > (safe_add_func_int8_t_s_s(l_1381[2], ((65534UL > l_950) == (safe_mod_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_unary_minus_func_int16_t_s(g_227)), l_1381[2])), 0x5D52FB02L)))))) && 0xE61E85CEL));
                        return l_1282;
                    }
                    l_1323 = (+(safe_rshift_func_uint8_t_u_s((((((safe_mul_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s((((((l_1366 & (safe_add_func_int16_t_s_s(((+250UL) == ((safe_lshift_func_int8_t_s_s(0x2DL, (((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_s(((safe_rshift_func_int16_t_s_s(l_1364, l_1340)) <= (!0x84L)), 4)) < (((safe_add_func_int32_t_s_s(((safe_mul_func_uint8_t_u_u(0UL, l_904[5][3])) & g_405[8]), p_62)) <= p_62) < 5UL)), p_64)) , 0x0EL) , g_101))) <= l_1364)), l_1306))) > p_62) > l_1364) < l_1280) ^ 0xE820L), p_62)), l_973[3])) <= 0x3D553A9EL) | g_458[0]) > 0L) || l_950), p_63)));
                }
            }
        }
    }
    return g_1195;
}







static int32_t func_72(int16_t p_73)
{
    int16_t l_407 = 0xC69DL;
    int16_t l_420 = 0xB340L;
    uint16_t l_421 = 1UL;
    int16_t l_453 = 0xD169L;
    uint32_t l_484 = 0x3CD6C90BL;
    int32_t l_485 = 0xCACFB812L;
    uint8_t l_556[4] = {254UL, 0UL, 254UL, 0UL};
    int i;
    l_407 = 0x1952EC49L;
    if ((0x3EL > ((safe_mul_func_uint16_t_u_u(1UL, (safe_mod_func_int32_t_s_s(p_73, ((safe_rshift_func_int16_t_s_s((p_73 , (l_407 == (safe_unary_minus_func_uint32_t_u((~(((((safe_lshift_func_int8_t_s_s((0x370377B8L || (p_73 ^ ((((((1L >= (safe_rshift_func_uint8_t_u_s((((safe_unary_minus_func_int16_t_s((p_73 & g_358))) != (-1L)) <= l_420), l_420))) ^ g_5[6]) == 0L) & l_420) > l_421) , l_407))), l_420)) ^ l_420) < l_421) , l_421) ^ g_2)))))), p_73)) , 4294967286UL))))) ^ 0xD2L)))
    {
        uint32_t l_422[1];
        int32_t l_426 = 0xC366842CL;
        int i;
        for (i = 0; i < 1; i++)
            l_422[i] = 0UL;
        l_426 = (((p_73 && ((((p_73 & l_422[0]) & 0x8077E666L) < (safe_rshift_func_int16_t_s_s(((p_73 && (((((l_420 >= g_208) , (+(p_73 ^ ((safe_unary_minus_func_int16_t_s(4L)) | 8L)))) & 8L) && 0x6DL) <= p_73)) , 0xEA8FL), p_73))) & l_407)) , 0x6AL) & p_73);
        l_426 = ((((0x512EL & (((((p_73 > (((((safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_10, (safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(((safe_mul_func_uint16_t_u_u((!((safe_mul_func_uint8_t_u_u(((0xE82BF19AL & (safe_add_func_uint16_t_u_u(((((((((((((((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u(((l_422[0] , (~0x7A72L)) && l_420), 5)) != ((safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((g_406 > (safe_add_func_uint32_t_u_u(((1L & 1L) < (-3L)), l_407))) <= l_422[0]), p_73)) < g_405[0]), 0x6A7EL)) == g_101)), p_73)) || p_73) <= 0UL) >= 0x3B3CL) < l_426) <= p_73) && p_73) > l_426) | g_208) & l_422[0]) == p_73) & 1UL) == l_426) , 4UL), l_453))) == 0xDBCAL), g_5[6])) & p_73)), l_420)) , 0x52DDL), l_426)), 0xBC1A0054L)), g_2)))), 3)) , l_421) && 0x99L) && l_407) < g_5[6])) > g_405[5]) ^ p_73) , p_73) | (-2L))) != g_405[8]) && l_420) , p_73);
        g_458[0] = (((safe_rshift_func_uint8_t_u_s(((p_73 != l_407) & (((safe_add_func_int8_t_s_s(6L, ((p_73 & (l_422[0] < (p_73 || (((~l_422[0]) | 8L) && (l_407 , l_421))))) == g_358))) <= p_73) != l_422[0])), g_227)) != 65532UL) > (-1L));
    }
    else
    {
        uint32_t l_494 = 0UL;
        int16_t l_595[1];
        int32_t l_597 = 0x1951CAB3L;
        int i;
        for (i = 0; i < 1; i++)
            l_595[i] = 6L;
        for (l_421 = 0; (l_421 <= 8); l_421 += 1)
        {
            int i;
            l_485 = (g_405[l_421] == ((safe_sub_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_10 >= ((safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(0xD697L, (safe_sub_func_int32_t_s_s(((safe_unary_minus_func_uint16_t_u((((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s(g_2, 15)), (((g_5[2] != ((((safe_add_func_int32_t_s_s(((g_405[l_421] <= g_406) == ((((safe_sub_func_uint32_t_u_u(((!(1L | g_405[l_421])) > p_73), g_10)) && 0x95L) <= g_458[0]) >= p_73)), 1UL)) || g_406) | p_73) >= 5L)) || g_2) < 0x13L))), g_358)) && l_407) >= 0L) | g_208) , g_5[8]), l_484)), p_73)) , g_405[l_421]) >= 0x9AL))) , p_73), 0x89E1DE85L)))), 0x229333FCL)) <= g_10)), 2)) ^ p_73) ^ g_405[8]) || g_8[0][1]) < g_458[0]), g_405[l_421])) , p_73));
            for (l_453 = 0; (l_453 >= 0); l_453 -= 1)
            {
                int i;
                l_494 = (g_458[l_453] , ((p_73 <= g_405[l_421]) , (((safe_mod_func_int8_t_s_s(g_5[6], (safe_mul_func_int16_t_s_s(g_5[6], (safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((g_2 <= ((p_73 || (0x52L <= g_142[3][0])) > g_458[l_453])) ^ g_8[0][1]), 2)), 8L)))))) ^ l_484) , g_10)));
            }
        }
        for (l_420 = 4; (l_420 >= 0); l_420 -= 1)
        {
            uint8_t l_507 = 253UL;
            int32_t l_509 = 0x022C297BL;
            int32_t l_555[1][4];
            uint32_t l_581 = 0xAF662C58L;
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 4; j++)
                    l_555[i][j] = (-2L);
            }
            for (l_407 = 4; (l_407 >= 0); l_407 -= 1)
            {
                int i, j;
                l_509 = (((g_142[l_407][l_420] < 0x5EA8L) == (((safe_sub_func_uint16_t_u_u((((((((safe_sub_func_int32_t_s_s(((safe_add_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u(g_405[(l_420 + 3)], ((0x93L != ((((g_458[0] , p_73) , 0xDCE2L) , (safe_rshift_func_uint16_t_u_s(((safe_add_func_int8_t_s_s(l_507, g_508[2][4][0])) != 0xA5L), 13))) != g_10)) == p_73))), l_507)) , p_73), l_494)) , g_405[8]) >= 0x4BDEL) > 5L) == 0xA886L) <= 0xC2A5C605L) & 0x7EF740C2L), 1L)) != l_507) | p_73)) , 0xDA301567L);
            }
            g_520[0] = (0x65L || (safe_sub_func_int8_t_s_s(((3L >= ((((l_494 ^ 0L) ^ (((safe_sub_func_uint8_t_u_u((((+(((safe_mod_func_int8_t_s_s((0x4AL | l_507), (((safe_unary_minus_func_int32_t_s((safe_mul_func_uint8_t_u_u((safe_unary_minus_func_uint32_t_u(1UL)), ((g_10 <= (~4294967286UL)) >= g_458[0]))))) , l_507) , p_73))) >= p_73) && 4294967294UL)) && l_420) & l_509), 255UL)) & p_73) < 0x652B3F93L)) != l_494) <= p_73)) , l_507), g_405[8])));
            for (p_73 = 0; (p_73 <= 4); p_73 += 1)
            {
                int32_t l_535 = 0x60123917L;
                int i, j;
                l_509 = 0xB72EF4DCL;
                l_509 = (safe_rshift_func_uint8_t_u_s(g_142[p_73][p_73], 7));
                l_535 = (safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_u(0x7531L, (((g_142[l_420][l_420] || 0x018CL) <= p_73) , (l_494 <= (g_142[p_73][p_73] | (safe_mod_func_int32_t_s_s(g_142[p_73][p_73], (safe_add_func_int32_t_s_s(((((((0xF8L | (safe_sub_func_uint16_t_u_u((+(safe_rshift_func_uint8_t_u_u(g_9, g_142[p_73][p_73]))), g_5[5]))) , g_142[p_73][p_73]) < l_484) ^ 0x3EA5L) == l_494) && p_73), 0L))))))))), 15));
            }
            if (l_485)
                continue;
            for (l_494 = 0; (l_494 <= 4); l_494 += 1)
            {
                uint32_t l_572 = 18446744073709551615UL;
                uint16_t l_596 = 0xE1B1L;
                for (l_453 = 8; (l_453 >= 3); l_453 -= 1)
                {
                    int32_t l_557 = 1L;
                    int i;
                    l_557 = (safe_unary_minus_func_uint32_t_u(((g_405[l_494] < ((safe_lshift_func_int16_t_s_s((((safe_mod_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u(((1L ^ g_405[(l_494 + 1)]) == ((safe_sub_func_int16_t_s_s(0xBDE0L, ((safe_mul_func_uint16_t_u_u((p_73 != (safe_mul_func_uint8_t_u_u(((0x095EA4B4L || (safe_add_func_uint8_t_u_u(0UL, (safe_add_func_int8_t_s_s(((l_555[0][1] < (((0L != g_208) && g_208) , 1L)) == (-6L)), g_520[8]))))) | p_73), g_508[0][3][0]))), g_520[0])) ^ l_556[2]))) && g_358)), g_405[8])), 3)), g_520[0])) , p_73) | 255UL), 9)) , 1L)) == g_10)));
                }
                for (l_421 = 0; (l_421 <= 4); l_421 += 1)
                {
                    int8_t l_575[8] = {0x31L, 0x31L, 0xF5L, 0x31L, 0x31L, 0xF5L, 0x31L, 0x31L};
                    uint8_t l_594 = 1UL;
                    int i;
                    for (g_227 = 0; (g_227 <= 3); g_227 += 1)
                    {
                        int8_t l_582 = 0x3AL;
                        g_580[1] = ((1UL > (safe_sub_func_int32_t_s_s(((((safe_lshift_func_uint8_t_u_s(((safe_add_func_int16_t_s_s(((safe_mul_func_uint16_t_u_u(p_73, (safe_rshift_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(l_494, ((l_572 | ((safe_add_func_int32_t_s_s(g_227, (l_575[5] , (p_73 == (safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((0x2930L >= (((g_580[1] != l_555[0][3]) == 0xAAL) >= 0x36E8L)), l_581)), p_73)))))) != g_406)) , 0x72L))), l_485)) , g_8[1][0]), 6)))) | 0xE7E6L), g_580[3])) >= g_508[2][4][0]), l_582)) ^ 0x16F1L) == 255UL) >= g_2), g_142[0][1]))) | g_358);
                        l_597 = ((safe_unary_minus_func_int32_t_s((((g_5[6] , p_73) != (l_572 ^ 0xB618L)) < (g_101 & l_575[5])))) , ((safe_add_func_uint32_t_u_u(g_458[0], (safe_mul_func_int8_t_s_s((!g_142[1][1]), (((safe_add_func_int32_t_s_s((((safe_add_func_int32_t_s_s((safe_add_func_int16_t_s_s((((4294967286UL || g_406) || l_594) <= l_507), p_73)), l_507)) ^ p_73) == l_595[0]), p_73)) , l_596) & p_73))))) , g_2));
                        g_580[2] = (0x5D2D4502L == g_8[0][1]);
                    }
                    l_509 = ((((safe_rshift_func_int8_t_s_s(0x72L, 2)) & l_555[0][1]) > (4294967295UL >= (((safe_add_func_uint8_t_u_u(((safe_add_func_int16_t_s_s(p_73, l_597)) <= p_73), ((~(+((safe_add_func_int8_t_s_s(((((safe_mul_func_uint16_t_u_u(((p_73 || p_73) , (!(safe_rshift_func_uint8_t_u_u(l_485, 7)))), p_73)) , l_453) , 4294967295UL) > p_73), p_73)) , 0x7AL))) & 0x36L))) < l_421) ^ 4294967292UL))) >= p_73);
                }
            }
        }
    }
    for (g_227 = (-2); (g_227 > 24); g_227++)
    {
        int16_t l_616 = (-1L);
        uint16_t l_628 = 1UL;
        l_628 = (safe_mul_func_int8_t_s_s((((safe_add_func_uint16_t_u_u(l_616, (-1L))) > (safe_sub_func_uint16_t_u_u((((safe_lshift_func_int8_t_s_u((((((safe_unary_minus_func_int8_t_s(g_142[2][2])) <= ((safe_lshift_func_int8_t_s_u((((((((safe_rshift_func_uint16_t_u_s(0xCD89L, ((safe_sub_func_uint32_t_u_u(((0x401CDDD9L && g_580[2]) || 1L), p_73)) >= p_73))) , p_73) >= 0x85L) >= 0xA1A1L) ^ 0xD50A5EE1L) , g_580[1]) && p_73), 5)) , g_9)) ^ p_73) && g_458[0]) > l_484), g_580[1])) && 0x6DL) >= 0x5CD8L), p_73))) >= g_142[4][3]), g_101));
    }
    l_485 = ((((g_405[8] | (0x292C3D8EL && g_2)) && (l_485 || g_520[5])) , (l_556[2] <= (l_407 != (+(((safe_add_func_uint32_t_u_u((safe_mod_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(9UL, (p_73 , g_8[0][1]))), g_520[1])), p_73)) ^ 252UL) > (-1L)))))) == p_73);
    return p_73;
}







static uint32_t func_78(int8_t p_79, int16_t p_80)
{
    int16_t l_99[3][7] = {{0xE080L, 0x4F5AL, 0L, 0x9881L, 0x718AL, 0L, 0x718AL}, {0xE080L, 0x4F5AL, 0L, 0x9881L, 0x718AL, 0L, 0x718AL}, {0xE080L, 0x4F5AL, 0L, 0x9881L, 0x718AL, 0L, 0x718AL}};
    uint32_t l_100 = 4294967295UL;
    int32_t l_139 = (-8L);
    uint8_t l_149 = 0x63L;
    uint32_t l_255 = 0UL;
    int32_t l_356 = 0xB94147C4L;
    int i, j;
lbl_110:
    if (g_5[6])
    {
        uint8_t l_92[2];
        int i;
        for (i = 0; i < 2; i++)
            l_92[i] = 246UL;
        g_101 = (safe_mod_func_int16_t_s_s((g_5[6] <= p_79), func_36((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((safe_mul_func_uint16_t_u_u(p_80, l_92[1])), p_80)) < ((safe_lshift_func_int16_t_s_u((g_5[6] == l_92[1]), 13)) , 0x10L)), ((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(l_99[0][5], g_5[6])), p_80)) >= (-9L)))) && l_100) < g_5[6]), l_92[1])));
    }
    else
    {
        return g_5[3];
    }
lbl_272:
    for (p_80 = 4; (p_80 == 22); p_80 = safe_add_func_uint32_t_u_u(p_80, 2))
    {
        uint8_t l_117 = 7UL;
        int32_t l_144 = (-1L);
        uint8_t l_192 = 0xC2L;
        if ((safe_mul_func_uint16_t_u_u((0x20L || (p_79 >= ((-10L) ^ func_36((((g_5[7] || func_36((safe_add_func_uint32_t_u_u((p_79 == 0x62DAC39FL), p_79)), g_8[0][0])) != 0x83L) , 0xD6BEAEC5L), g_2)))), 0xA390L)))
        {
            for (g_101 = 9; (g_101 >= 22); ++g_101)
            {
                return l_100;
            }
        }
        else
        {
            int8_t l_138 = 0x75L;
            if (g_101)
                goto lbl_110;
            l_144 = ((p_79 == (safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(((2UL == func_36(g_8[2][0], l_117)) | (func_118(((((safe_mul_func_int16_t_s_s((~1L), (((safe_rshift_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u(g_9, ((p_79 ^ (safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u(((((((safe_mul_func_int8_t_s_s(p_80, 0x2FL)) , l_117) | 0xCAL) | l_138) <= g_9) , l_100), p_80)), g_2)), g_9))) , 0x86L))), 0)) , g_5[6]) == l_117))) >= p_79) ^ l_99[0][5]) > l_138), g_10, g_5[5], g_5[6], l_139) || p_80)), (-1L))), 0L)), 0x9C82L))) , 0x5A8FD6DDL);
            for (l_139 = 0; (l_139 == 15); l_139 = safe_add_func_int32_t_s_s(l_139, 1))
            {
                uint32_t l_193 = 0xD12158B1L;
                int32_t l_254[8][4][4] = {{{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}, {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}, {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}};
                int i, j, k;
                for (g_101 = (-17); (g_101 < 8); g_101 = safe_add_func_int16_t_s_s(g_101, 4))
                {
                    int8_t l_166 = 0x86L;
                    uint8_t l_167 = 0xC6L;
                    uint16_t l_168[6];
                    int i;
                    for (i = 0; i < 6; i++)
                        l_168[i] = 0x379BL;
                    if ((l_149 && (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u(g_2, (((safe_rshift_func_int16_t_s_s((((((safe_add_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_mul_func_int16_t_s_s((safe_mul_func_int16_t_s_s((g_8[1][0] & (!l_166)), (-6L))), l_117)) ^ (((l_167 , (l_168[1] , ((l_99[1][4] && p_80) , g_10))) , 1UL) <= p_80)), 3UL)) >= 0xAC6AL) , g_142[2][3]), 0x2FL)) >= l_166) ^ p_79) && 0x0DL) , p_79), l_168[1])) , 1L) >= 0xC1D1B066L))) , g_101), l_144)) < p_80), l_168[1]))))
                    {
                        int32_t l_187 = 0L;
                        l_144 = (safe_mul_func_uint8_t_u_u((((((((((safe_sub_func_uint8_t_u_u((((safe_add_func_int16_t_s_s(((g_5[3] ^ ((safe_mod_func_uint32_t_u_u((((((safe_add_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(p_79, (((65531UL <= p_80) || g_5[6]) , ((safe_rshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(g_5[6], 14)) ^ (safe_sub_func_int32_t_s_s((l_187 && (safe_lshift_func_uint8_t_u_u(p_80, ((safe_sub_func_int8_t_s_s((((p_79 , l_166) & p_80) & l_144), l_192)) || l_144)))), g_10))), l_168[5])) , l_193)))), g_2)) < g_2) | 0xFEL) < 0xE21D6552L) > g_10), g_10)) , p_80)) || g_142[1][2]), p_79)) < p_80) , g_142[1][4]), 0x32L)) ^ 0L) , 0x5B5EL) == g_9) < l_138) == 0xD71703F9L) | l_193) , p_79) , 5UL), p_79));
                    }
                    else
                    {
                        g_208 = ((((+(safe_lshift_func_uint8_t_u_s((((p_79 == 0x2EL) != (p_79 <= ((((((~g_2) && ((+((safe_lshift_func_uint16_t_u_u(0xEE89L, (safe_mul_func_int16_t_s_s((((((l_99[0][5] ^ (((safe_mul_func_uint16_t_u_u((8UL & (safe_mul_func_int16_t_s_s((g_5[6] | g_8[0][0]), 0xCE8CL))), 1L)) ^ g_5[1]) != l_149)) <= (-1L)) || g_5[6]) > g_10) || 1L), l_168[1])))) && g_5[6])) <= g_9)) , 255UL) <= p_79) >= g_5[5]) >= 7UL))) > l_167), p_79))) >= p_79) , (-2L)) != p_80);
                    }
                }
                g_227 = ((safe_add_func_int8_t_s_s((l_117 , g_9), (safe_lshift_func_int16_t_s_u((+(safe_add_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(p_80, 2)) & (safe_mul_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s(p_79, 0xD1L)) , (safe_add_func_int32_t_s_s((safe_rshift_func_int16_t_s_u(2L, 2)), l_192))) != (0xEFCB1569L && (safe_mul_func_uint8_t_u_u(((l_193 >= 0x8CD2L) , 0xA4L), g_5[6])))), 0xA05CL))), g_208))), 6)))) , g_142[3][4]);
                l_254[5][2][2] = ((safe_mul_func_uint16_t_u_u(l_138, (g_5[1] | ((safe_rshift_func_int8_t_s_s(l_100, 4)) | (safe_mul_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((~(safe_mod_func_int8_t_s_s(((safe_add_func_int32_t_s_s(l_138, (safe_mod_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~(safe_lshift_func_uint8_t_u_s(((p_79 == (((safe_mul_func_int16_t_s_s((((+(l_193 , p_80)) <= (safe_lshift_func_uint8_t_u_s(((safe_mul_func_int8_t_s_s(l_149, ((safe_rshift_func_int16_t_s_u(l_193, 6)) > 1L))) , l_193), l_138))) && p_79), l_138)) <= p_79) && l_193)) < p_80), 4))), 6)), l_193)))) && p_80), l_117))), 3)) ^ p_79), 0xF83BL)))))) || g_8[1][0]);
            }
        }
        if (l_255)
            continue;
    }
    for (l_100 = 1; (l_100 <= 4); l_100 += 1)
    {
        uint8_t l_270[3];
        int32_t l_271 = 0xC06C30A7L;
        int32_t l_393 = 0xA6E4B284L;
        int i;
        for (i = 0; i < 3; i++)
            l_270[i] = 255UL;
        l_271 = (safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u((g_10 == p_80), 3L)) > p_79) < l_149) <= ((safe_add_func_int32_t_s_s(0x9C167B5BL, (safe_add_func_int8_t_s_s((safe_mul_func_int8_t_s_s(0x59L, (safe_add_func_int32_t_s_s((((1L < p_80) != p_80) != g_5[6]), l_255)))), 0x48L)))) != 0xC8L)) > l_270[0]), l_99[2][1])), 5UL));
        if (l_139)
            goto lbl_272;
        l_139 = ((safe_mul_func_uint8_t_u_u((g_5[5] <= ((safe_add_func_int32_t_s_s((((((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u(((((((((safe_mul_func_uint8_t_u_u(p_80, (g_8[0][0] && ((safe_rshift_func_uint8_t_u_u(0x95L, ((p_80 & (safe_mul_func_uint16_t_u_u((~(((((safe_add_func_int8_t_s_s(p_80, 0xE6L)) == ((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(((((safe_sub_func_int32_t_s_s((l_99[0][6] | (((1UL == (-1L)) & g_5[6]) < l_100)), l_255)) >= l_99[2][4]) == 1L) & 0x5AC83A63L), p_79)), l_149)) <= 0L), l_139)), 0xC67E8D82L)) || p_79)) , l_139) <= p_80) && 255UL)), (-1L)))) || 0L))) , p_80)))) ^ g_227) , g_142[0][4]) == 0UL) & 0x2B3F61FCL) || 4294967286UL) && 1UL) & 1UL), 0)) , 0x36697B6FL), 0xCBE982E7L)) <= g_142[3][4]) < l_270[2]) > l_270[1]) , g_5[7]), p_79)) != g_227)), p_80)) <= l_99[0][5]);
        for (l_149 = 1; (l_149 <= 4); l_149 += 1)
        {
            int32_t l_333[4][3][7] = {{{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}}, {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}}, {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}}, {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}, {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}}};
            int i, j, k;
            for (l_139 = 4; (l_139 >= 0); l_139 -= 1)
            {
                int32_t l_334[3][8][6] = {{{6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}}, {{6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}}, {{6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}, {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}}};
                int32_t l_335 = (-8L);
                int i, j, k;
                l_335 = (safe_mod_func_int8_t_s_s(l_99[2][2], (safe_mul_func_int16_t_s_s(((safe_mul_func_int8_t_s_s(l_270[0], (safe_mul_func_int16_t_s_s((7UL != p_79), (((((safe_rshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(0x6BL, 0)), (safe_mod_func_uint8_t_u_u((safe_add_func_int32_t_s_s((p_79 , (safe_mul_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((p_79 || g_2), ((safe_add_func_int32_t_s_s(0xA10EE6A9L, g_8[2][0])) ^ g_208))) > (-3L)), p_80)), p_79)), g_2)) <= l_333[3][1][4]), l_334[1][5][1])), l_270[0]))), g_142[0][0])), p_80)))), 0x576EL)), 6)) && g_2) ^ 0x5DL) || p_80) != 0x130623DAL))))) == p_79), 0x85D1L))));
                l_356 = (safe_rshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s((g_5[6] | (g_208 , (safe_sub_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((l_333[2][1][5] <= (safe_sub_func_int32_t_s_s(0x03310008L, (safe_mod_func_uint16_t_u_u(((safe_mod_func_uint32_t_u_u(0x41DCC979L, (((((l_334[1][5][1] <= (+0x1C9BFA93L)) == (((((safe_sub_func_uint16_t_u_u(p_79, ((safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_u(p_79, 10)), g_208)) <= p_80))) <= 0x97F4BBE4L) , 0x60007889L) != l_333[3][1][4]) == l_333[3][2][4])) > 0x1D0DC95DL) > g_9) || p_79))) , p_80), g_208))))), l_333[3][1][4])), g_9)))), l_333[3][1][4])), 2));
            }
        }
        for (l_271 = 4; (l_271 >= 1); l_271 -= 1)
        {
            int16_t l_357[1];
            int32_t l_364[5] = {0x8076C985L, 0xBCB5D35EL, 0x8076C985L, 0xBCB5D35EL, 0x8076C985L};
            int i;
            for (i = 0; i < 1; i++)
                l_357[i] = 1L;
            g_358 = l_357[0];
            l_364[0] = ((l_139 ^ (((0x1BL < (g_101 , ((safe_rshift_func_uint8_t_u_s(l_270[1], (g_101 & (!(g_227 , ((safe_unary_minus_func_uint32_t_u(g_208)) >= g_5[5])))))) && (safe_rshift_func_uint8_t_u_s(0x9CL, 2))))) > 0x571DL) != l_357[0])) , 0x64FC777FL);
            for (l_149 = 1; (l_149 <= 4); l_149 += 1)
            {
                uint32_t l_392 = 0UL;
                for (g_358 = 4; (g_358 >= 1); g_358 -= 1)
                {
                    int16_t l_391 = 0x7A41L;
                    uint32_t l_404 = 1UL;
                    l_393 = (((((safe_sub_func_uint16_t_u_u((((((safe_add_func_uint16_t_u_u((p_79 > ((safe_add_func_int32_t_s_s(p_80, (safe_mul_func_int8_t_s_s(l_271, (((((((g_10 || (safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s(((safe_mul_func_int8_t_s_s(((0x51BAL && g_9) == ((((safe_mul_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((((safe_add_func_int32_t_s_s((l_270[0] ^ (safe_lshift_func_int16_t_s_u(((l_357[0] ^ 0xD1EE3892L) , 3L), 2))), 4294967292UL)) > p_80) & g_2), p_80)), 4UL)), g_9)) | 65535UL) ^ g_9) == 0xEBL)), p_79)) <= p_80), l_391)), l_364[0])), l_271))) >= 0x9A8E6CA8L) <= g_10) || l_270[0]) || 0x18BEC9C2L) != l_149) | 0x5891L))))) == g_208)), 0xE40EL)) , p_79) , l_391) && p_80) & p_80), 65535UL)) & l_391) , p_79) , (-1L)) ^ l_392);
                    g_405[8] = (safe_mul_func_int8_t_s_s((p_79 == ((((safe_add_func_uint8_t_u_u((l_270[0] | (248UL == ((safe_sub_func_int8_t_s_s(l_99[0][5], (p_79 >= (safe_sub_func_int16_t_s_s(g_2, ((safe_lshift_func_uint16_t_u_u((p_80 | (((((p_79 | ((p_80 & 0xBC50E1AEL) & 0x79D4BE2AL)) ^ p_79) >= l_270[0]) != 0xAF85L) >= 0x6AL)), p_80)) & l_357[0])))))) | (-1L)))), l_404)) ^ 1UL) , l_356) < 0L)), p_79));
                }
            }
            g_406 = g_142[2][1];
        }
    }
    return g_405[8];
}







static uint8_t func_118(uint8_t p_119, int32_t p_120, int16_t p_121, uint16_t p_122, int32_t p_123)
{
    int32_t l_143 = 0L;
    for (p_119 = (-1); (p_119 < 45); p_119 = safe_add_func_int8_t_s_s(p_119, 1))
    {
        for (g_101 = 0; (g_101 <= 4); g_101 += 1)
        {
            p_123 = 0L;
        }
    }
    return l_143;
}





int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_2, "g_2", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        transparent_crc(g_5[i], "g_5[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_8[i][j], "g_8[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_9, "g_9", print_hash_value);
    transparent_crc(g_10, "g_10", print_hash_value);
    transparent_crc(g_101, "g_101", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_142[i][j], "g_142[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_208, "g_208", print_hash_value);
    transparent_crc(g_227, "g_227", print_hash_value);
    transparent_crc(g_358, "g_358", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_405[i], "g_405[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_406, "g_406", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_458[i], "g_458[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 1; k++)
            {
                transparent_crc(g_508[i][j][k], "g_508[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_520[i], "g_520[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_580[i], "g_580[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_754, "g_754", print_hash_value);
    transparent_crc(g_830, "g_830", print_hash_value);
    transparent_crc(g_1165, "g_1165", print_hash_value);
    transparent_crc(g_1195, "g_1195", print_hash_value);
    transparent_crc(g_1588, "g_1588", print_hash_value);
    transparent_crc(g_1625, "g_1625", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
