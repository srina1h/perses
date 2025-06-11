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



static volatile int8_t g_14 = 0x83L;
static int32_t g_59 = 2L;
static uint64_t g_71 = 18446744073709551608UL;
static int32_t g_72 = 6L;
static uint32_t g_81 = 1UL;
static volatile uint32_t g_100 = 0x3342DF67L;
static uint8_t g_156 = 246UL;
static uint64_t g_926 = 0UL;
static int64_t g_992 = (-6L);
static uint64_t g_1052 = 0xBFDAA821B431EB5BLL;
static int8_t g_1861 = 0xFEL;
static int16_t g_1973 = 1L;
static int16_t g_2223 = (-3L);
static int8_t g_2685 = 1L;
static uint16_t g_2725 = 0xF940L;
static int32_t g_2822 = 1L;
static volatile uint64_t g_2850 = 0xCF0A3F6CB511BC83LL;
static volatile int32_t g_3034 = 0x3D33D12DL;
static int16_t g_3288 = 0x68B9L;
static int8_t g_3420 = (-3L);
static int32_t g_3814 = 0x4D469CA0L;



inline static uint16_t func_1(void);
static int32_t func_2(int32_t p_3);
static int16_t func_7(int32_t p_8, uint32_t p_9, int8_t p_10, int64_t p_11);
static int16_t func_12(int64_t p_13);
static int16_t func_18(int32_t p_19, uint32_t p_20, uint32_t p_21, int32_t p_22, uint32_t p_23);
static int8_t func_28(int32_t p_29, uint64_t p_30, uint32_t p_31, uint8_t p_32, uint8_t p_33);
inline static uint8_t func_34(uint32_t p_35, int8_t p_36, int8_t p_37);
static int64_t func_38(uint8_t p_39, int16_t p_40);
inline static int16_t func_44(int16_t p_45);
inline static int32_t func_46(uint32_t p_47, uint64_t p_48);
inline static uint16_t func_1(void)
{
    uint16_t l_15 = 0xFD94L;
    int32_t l_2951 = 0x33C988FBL;
    int16_t l_2982 = 0xBB3BL;
    int8_t l_3061 = 0x1DL;
    uint32_t l_3064 = 18446744073709551609UL;
    int8_t l_3080 = 5L;
    int32_t l_3100 = 0xB99EE5D2L;
    uint8_t l_3149 = 0UL;
    int32_t l_3191 = 0x58863928L;
    int16_t l_3287 = 0x212DL;
    uint64_t l_3377 = 18446744073709551607UL;
    uint8_t l_3492 = 0x0DL;
    uint16_t l_3493 = 0xE96FL;
    int32_t l_3566 = 0x545E2138L;
    uint8_t l_3620 = 0x97L;
    uint32_t l_3672 = 0UL;
    int8_t l_3720 = 0xDDL;
    int32_t l_3770 = 0xB9FED0C5L;
    int8_t l_3815 = 0xF1L;
    l_2951 = func_2((+(((safe_sub_func_int16_t_s_s(func_7((func_12((g_14 <= l_15)) < (safe_div_func_int8_t_s_s((!((((safe_sub_func_int32_t_s_s((l_15 > g_1052), ((((g_1052 , 0xA8L) , ((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u(l_15, ((((251UL != 249UL) || 0L) > l_15) > 0x5FC200A4L))), l_15)) > g_81)) || g_81) , 0x8E4701D5L))) | 4294967290UL) < l_15) && l_15)), g_2685))), l_15, g_1052, g_81), l_15)) < 4294967289UL) == l_15)));
    for (g_992 = 10; (g_992 > 3); g_992 = safe_sub_func_uint64_t_u_u(g_992, 1))
    {
        int64_t l_2956 = (-1L);
        int32_t l_2983 = 0x04DED18DL;
        int32_t l_3035 = 0x46750389L;
        int32_t l_3081 = 0L;
        int16_t l_3293 = 5L;
        for (g_2725 = 4; (g_2725 >= 26); ++g_2725)
        {
            int32_t l_2959 = 0L;
            int16_t l_3062 = 0x2320L;
            int32_t l_3101 = 0x07ED4AABL;
            uint32_t l_3122 = 5UL;
            uint32_t l_3150 = 0x6DAD66A0L;
            uint16_t l_3164 = 0x2258L;
            g_2822 = l_2956;
            l_2951 = (safe_rshift_func_int16_t_s_u(g_2850, 1));
            if (((-1L) ^ (((0x92L & g_1973) <= l_2956) ^ (0xDADF77647E21481BLL | ((l_2959 >= (~((0L | l_2956) <= ((0xBDL < g_59) || 0x21D3EA77L)))) && l_15)))))
            {
                uint8_t l_2963 = 1UL;
                l_2983 = ((safe_sub_func_uint32_t_u_u(l_2963, (safe_lshift_func_int16_t_s_s((l_2959 > (safe_sub_func_int16_t_s_s((0xC9L ^ ((l_2956 ^ ((((+(safe_rshift_func_uint8_t_u_s(0xAEL, 3))) != (((safe_mod_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u((((safe_mod_func_int32_t_s_s(0x0B3393F9L, ((+(safe_rshift_func_uint8_t_u_u(l_2963, (safe_rshift_func_uint16_t_u_u(0UL, l_15))))) && 5L))) == 0L) && 0x00677397L), g_14)) , g_1861) ^ 0x478BL), g_2223)) >= 1UL) >= l_2963)) && g_926) == g_1052)) <= 0xFB0A4B8740B0CDDCLL)), g_1861))), 6)))) < l_2982);
            }
            else
            {
                int16_t l_2994 = 0L;
                l_2959 = (safe_div_func_int64_t_s_s(((-1L) < ((g_156 | (g_1052 ^ g_156)) >= ((safe_lshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(((g_926 > l_2982) <= (l_2959 <= (safe_div_func_int32_t_s_s((0xA7L & (l_2994 , g_992)), g_992)))), 5)), 5)) ^ (-1L)))), 6UL));
                for (g_156 = 0; (g_156 == 19); g_156 = safe_add_func_int64_t_s_s(g_156, 8))
                {
                    int64_t l_3012 = (-1L);
                    int32_t l_3013 = 0x41DFF998L;
                    l_3013 = (safe_div_func_uint64_t_u_u((((safe_add_func_uint64_t_u_u(((safe_div_func_int8_t_s_s((g_2223 ^ ((safe_lshift_func_int16_t_s_s(g_2850, 14)) | 0x4EL)), 0xD2L)) == (safe_mod_func_uint64_t_u_u((((~((safe_sub_func_uint16_t_u_u(g_1973, (safe_sub_func_int64_t_s_s(((l_2982 < g_72) || l_2956), g_2685)))) , 5L)) , 7L) < l_3012), g_2822))), g_1861)) , g_156) >= l_2956), 7L));
                    if (g_2850)
                    {
                        int16_t l_3017 = 1L;
                        g_72 = g_72;
                        g_2822 = (((g_59 , ((+((safe_div_func_int16_t_s_s(g_1861, (((l_3017 & (safe_div_func_int64_t_s_s((safe_add_func_uint32_t_u_u(((safe_sub_func_int8_t_s_s((!(l_2959 > ((((+(safe_mod_func_uint32_t_u_u(((((safe_lshift_func_int16_t_s_u((l_2994 <= 0x00L), (((((safe_div_func_uint16_t_u_u((g_59 > l_2994), (((safe_add_func_uint8_t_u_u(((g_81 & g_3034) == (-1L)), 0xC4L)) , 0x66L) | g_2725))) | g_1973) , g_81) > g_1973) > l_3017))) ^ g_926) == 0x4065FCD8C85E2BC5LL) , 4294967293UL), g_2725))) != g_1973) < l_3013) >= l_15))), (-1L))) , 0UL), 0x3C4E9F8CL)), 1UL))) < g_72) , 0x1F59L))) == g_2685)) | g_2725)) , g_14) != g_1052);
                    }
                    else
                    {
                        uint64_t l_3060 = 18446744073709551611UL;
                        l_3035 = (l_3035 , (safe_unary_minus_func_uint32_t_u((0xB74FL < (g_72 != (safe_div_func_uint16_t_u_u((l_2959 > (~((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_uint16_t_u_s(((((safe_rshift_func_int16_t_s_s((g_59 || ((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_s(((((l_2959 < (safe_div_func_uint64_t_u_u(((+(safe_div_func_uint64_t_u_u((!(((safe_sub_func_uint8_t_u_u(255UL, (safe_lshift_func_uint16_t_u_s(l_3012, 8)))) , g_71) < l_3060)), g_926))) & g_2850), g_81))) ^ 0x3D00BFB9F05404AELL) && 1L) == g_1052), 10)) >= l_2982), l_2959)) > 0x137D866BE3CCA05ELL)), 14)) || 0xF7L) == 1L) != l_2982), 13)) <= g_1861) | 0x6499L), g_992)) , l_3060))), l_3061)))))));
                        g_72 = (l_2982 == (l_3062 && ((safe_unary_minus_func_int64_t_s((g_1052 > (l_2994 , (l_2982 | l_2983))))) && l_3060)));
                    }
                    l_3064 = (l_2959 , (-1L));
                }
                if ((((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_int8_t_s_u(l_2994, 6)) , (((+((l_2959 != l_2959) & (safe_rshift_func_uint8_t_u_u(254UL, 1)))) ^ (safe_rshift_func_uint16_t_u_s(1UL, 3))) < ((safe_add_func_int64_t_s_s((l_2994 && (-1L)), (safe_div_func_uint16_t_u_u(((g_14 <= ((l_3080 , l_15) | l_2959)) , 5UL), l_3081)))) , l_2959))), l_3081)), g_71)) < g_1973) < g_72))
                {
                    uint32_t l_3088 = 0x557EFEA9L;
                    int8_t l_3121 = 0x15L;
                    g_72 = (((safe_rshift_func_int8_t_s_u(((g_59 >= (((safe_div_func_uint8_t_u_u(l_3088, l_2994)) , (safe_unary_minus_func_int16_t_s((l_3088 , (safe_add_func_uint8_t_u_u(((l_3035 < ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((safe_div_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_u(9UL, ((((g_926 , (l_3100 <= l_3101)) & l_3088) > 1L) || l_3088))), 4UL)), 11)), 3)) & 0xA9A15020L)) > (-1L)), (-3L))))))) >= 0x7F4CL)) >= g_1052), 2)) & 0x0D43C8DFL) >= 4UL);
                    g_2822 = (!((l_2951 < ((safe_sub_func_uint64_t_u_u((l_2994 >= (!(safe_rshift_func_int16_t_s_u(l_3062, 0)))), 0x205012D6531B881FLL)) || (g_14 , (safe_mod_func_int16_t_s_s((-1L), ((safe_add_func_uint8_t_u_u((~((safe_sub_func_uint16_t_u_u(2UL, (l_3062 , (safe_add_func_int32_t_s_s((safe_div_func_int16_t_s_s((l_3121 | l_2983), l_2994)), g_2223))))) < 0xE321L)), l_2994)) , 1L)))))) < g_156));
                }
                else
                {
                    return l_3122;
                }
            }
            if (g_156)
            {
                uint64_t l_3148 = 0xDF04434C42256224LL;
                int32_t l_3151 = 0L;
                for (g_2822 = 0; (g_2822 > (-7)); g_2822--)
                {
                    for (l_3035 = (-21); (l_3035 <= 12); l_3035 = safe_add_func_int16_t_s_s(l_3035, 7))
                    {
                        l_2983 = (((0x0FABF1E6L < g_3034) != g_71) || 0x55C0L);
                        return g_1973;
                    }
                    return g_992;
                }
                g_2822 = (((l_3061 ^ (0UL | g_2685)) < (safe_lshift_func_uint16_t_u_u((safe_div_func_int64_t_s_s((((safe_lshift_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((safe_div_func_uint64_t_u_u((safe_sub_func_uint64_t_u_u(g_1052, (((safe_lshift_func_int8_t_s_s(((safe_lshift_func_int8_t_s_s(g_2725, (g_2725 && (((safe_rshift_func_uint8_t_u_u(((!((safe_lshift_func_uint8_t_u_s(g_2850, 6)) , g_2850)) < (l_3148 && l_3062)), l_3149)) <= g_2223) & g_1973)))) == l_3035), g_1052)) & 4294967294UL) | l_2959))), g_72)), g_992)) != l_2983) , l_3081), l_3100)) > 1L) , g_1861), 0x8D341F148E9C7A1FLL)), 4))) < l_3150);
                l_3151 = g_1973;
                l_2959 = 0L;
            }
            else
            {
                uint16_t l_3166 = 0x2D42L;
                uint64_t l_3210 = 0xCF8792DCC35E3A8FLL;
                if ((18446744073709551613UL > (-1L)))
                {
                    uint32_t l_3163 = 1UL;
                    uint32_t l_3165 = 0UL;
                    g_72 = (((((((((-1L) >= (((l_3101 & (safe_rshift_func_int8_t_s_s((((18446744073709551610UL & (safe_lshift_func_uint8_t_u_u((~g_2685), g_156))) < (g_3034 | g_81)) , (g_2850 , (safe_rshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(0UL, 11)) && l_3163), l_3164)))), 4))) ^ 0x38CB883BDC4903DCLL) ^ 249UL)) == l_3165) | l_3166) > 0x14L) && l_3165) ^ 0L) > g_1973) && 0x27A892ADL);
                    g_2822 = ((g_3034 & ((safe_sub_func_int16_t_s_s(((((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((g_2822 ^ ((-4L) < 1UL)), (((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint64_t_u_u((safe_add_func_uint64_t_u_u(((g_72 > (((safe_lshift_func_uint8_t_u_u(((((safe_add_func_int16_t_s_s(g_1973, 5UL)) != ((0xE6D8B827391FC7DDLL && (safe_sub_func_int64_t_s_s((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((((safe_rshift_func_uint16_t_u_u((g_1973 , 1UL), 9)) & l_3191) , l_3166), 3UL)), 6)), g_1052))) & g_1861)) | g_2822) | l_3122), g_1052)) | g_156) < g_72)) ^ 5L), g_81)), l_3064)) < g_1052) , g_2685), g_992)) != 0x1C785BFDC9F9162FLL) && 65531UL))), l_3166)) && g_2685) < 0xCA2C4DAAEDED4BBBLL) || l_2982), 6UL)) & g_2725)) & 0x4972L);
                }
                else
                {
                    int32_t l_3211 = (-5L);
                    l_3211 = ((0x32L != (((safe_mod_func_uint32_t_u_u(((((-1L) > g_14) >= l_2951) > (safe_sub_func_int32_t_s_s((safe_sub_func_uint64_t_u_u((safe_mod_func_int16_t_s_s(((safe_div_func_int16_t_s_s(((g_81 >= (safe_mod_func_int8_t_s_s((safe_mod_func_int64_t_s_s(0x9BFA6F7EAC604556LL, g_59)), (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint32_t_u_u(4294967289UL, (g_1861 ^ g_81))), 0))))) != g_59), g_1861)) != l_3210), l_2956)), 0xDC2F23A084FA35EELL)), 0x16D9CFBEL))), l_3062)) <= 4294967286UL) >= l_3211)) && l_3211);
                }
                for (l_3035 = 15; (l_3035 <= (-21)); l_3035 = safe_sub_func_int8_t_s_s(l_3035, 8))
                {
                    int32_t l_3230 = 9L;
                    for (l_3122 = 10; (l_3122 >= 52); l_3122++)
                    {
                        return g_926;
                    }
                    for (l_3210 = 0; (l_3210 <= 11); l_3210 = safe_add_func_uint64_t_u_u(l_3210, 9))
                    {
                        int8_t l_3229 = 1L;
                        volatile uint8_t l_3231 = 255UL;
                        g_72 = (safe_div_func_int16_t_s_s((safe_div_func_uint16_t_u_u((l_2983 <= g_14), 0xCE30L)), (safe_sub_func_int8_t_s_s((((g_1052 , (((safe_sub_func_int8_t_s_s(((((l_2983 & ((((-4L) <= g_992) && (~(+1L))) & (!l_3081))) && l_3081) != l_3229) & l_3166), g_81)) >= l_2956) > g_992)) <= g_2685) > 0x5EAAE574L), l_3230))));
                        l_3231 = g_2850;
                    }
                    l_2983 = (safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_s((l_2959 , (safe_lshift_func_uint8_t_u_u((safe_sub_func_int64_t_s_s((l_2983 <= (-1L)), 0UL)), (safe_mod_func_int64_t_s_s(l_2959, ((0x20290AD0L >= ((3L >= (l_3081 != (((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(((((g_2725 & l_3062) > 1UL) || 0L) == l_15), 3)), g_71)), 4)), 0xBCE18E48L)) | l_3035) || l_3164))) & 1UL)) ^ g_156)))))), 6)) == 0x82B1C697L) ^ 4294967292UL), l_3230)), g_72));
                    g_72 = 0x0DC84E00L;
                }
            }
        }
        l_3191 = (0x9FE02A62L == (safe_lshift_func_int16_t_s_u(((safe_sub_func_uint8_t_u_u((((((((safe_sub_func_int8_t_s_s((safe_add_func_int16_t_s_s((0x8F6F994E03889CD7LL || g_2223), 0xABA7L)), (g_992 ^ (l_3081 ^ l_3080)))) < ((((safe_div_func_int64_t_s_s(((l_3149 && (safe_rshift_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_s(0xFCL, 5)) != l_15), l_3081)), g_2822)) || 0x6F36L) != 7UL), 5))) || g_926), g_100)) <= g_156) <= 0x95L) || 0xBDEEDE53L)) & 0xCE189CB2L) < l_3081) >= 0UL) && 0UL) >= 0xDDAAF75F6C668F34LL), g_2223)) , l_3100), l_3061)));
        l_3100 = ((g_1861 & ((0xD8A74254L <= ((safe_add_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((safe_sub_func_int64_t_s_s(l_3100, (((+((((safe_sub_func_uint16_t_u_u(g_71, (safe_lshift_func_int8_t_s_s((safe_sub_func_uint16_t_u_u(((l_3287 , (-1L)) || g_3288), (safe_div_func_int64_t_s_s(((((safe_sub_func_uint32_t_u_u(((18446744073709551615UL >= g_2223) & l_2956), g_72)) >= l_3293) && g_71) <= 255UL), g_2725)))), l_2982)))) >= g_2822) , l_3081) == 0xA7D4AF7E0B0D4EF7LL)) , g_3034) != g_926))) | 1UL) != g_992), 6)), 255UL)), g_72)), 0xBCL)) || l_2983)) , l_3064)) | 0x2786L);
    }
    l_3191 = (g_2685 & (((((g_2725 ^ 0L) == (((~((safe_sub_func_int64_t_s_s(g_2725, ((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s((~(safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((l_2951 || ((g_59 >= (4294967295UL != 0xC1BC2B44L)) < ((((safe_rshift_func_uint8_t_u_u(g_926, l_3191)) ^ g_81) , 0x8BF46C8B629F5F1ALL) != l_2951))), g_100)), 0x4DL))), 9)), g_71)) ^ g_2725) , 18446744073709551609UL) , g_1052))) , l_3287)) ^ 0x29L) && g_1973)) & l_3061) | 255UL) | l_3061));
    if ((0UL <= (l_3064 == (g_926 <= ((-5L) | g_59)))))
    {
        int16_t l_3310 = 0L;
        uint32_t l_3328 = 0xD31E8EABL;
        int32_t l_3374 = 4L;
        uint64_t l_3389 = 0UL;
        uint32_t l_3390 = 0xA2047182L;
        int32_t l_3418 = 1L;
        int8_t l_3419 = 0x53L;
        int32_t l_3425 = 0xE8386D81L;
        uint64_t l_3641 = 0x9451C119C8BA4A56LL;
        int16_t l_3673 = 0xE576L;
        uint32_t l_3702 = 0x4082CCC8L;
        uint8_t l_3779 = 251UL;
        uint32_t l_3787 = 0x35178E21L;
        uint32_t l_3789 = 0x6FD85EE5L;
        l_3191 = ((((safe_mod_func_int8_t_s_s((((g_1973 || l_3310) , ((((safe_add_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(g_81, 7)), (((~0xF2EC3023L) || (safe_div_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_u(((l_3310 || (safe_mod_func_uint16_t_u_u(((((safe_div_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((l_3328 | (safe_lshift_func_int8_t_s_u((((g_2725 , (safe_lshift_func_int16_t_s_u((safe_div_func_int8_t_s_s(((+((safe_add_func_int8_t_s_s(0L, 0x5BL)) ^ 0x3493L)) | 4294967289UL), g_100)), g_156))) >= 0xD8E90E27L) & g_72), 5))) || 0L), 1)), g_1973)) && 248UL) < l_3328) != l_3328), g_71))) >= l_3328), 9)) >= g_1861) && 3L), g_2223))) <= g_71))), 0x08DA2E2197CE8AECLL)) , 0L) | 1L) == 0xF12E44DADE81ED41LL)) | l_3100), l_3310)) == l_3328) && l_3287) ^ g_59);
        for (l_2951 = 0; (l_2951 != 19); l_2951++)
        {
            uint32_t l_3368 = 1UL;
            int8_t l_3369 = 9L;
            g_2822 = (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x18A41A52L, (safe_sub_func_uint32_t_u_u(g_3034, (0UL != ((safe_rshift_func_uint8_t_u_u(g_2223, ((((((!g_992) , ((safe_rshift_func_int16_t_s_s((((((safe_mod_func_int8_t_s_s(((l_3328 , (safe_lshift_func_int16_t_s_s((g_2223 == (0x9A31L > (~(safe_add_func_int16_t_s_s(((safe_add_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_u(g_2822, l_3368)), l_3064)) ^ l_3328), g_2725)), 3)), (-1L))) != l_3369), 0x420BL))))), 1))) , g_1861), l_15)) != g_2725) == l_3369) <= 18446744073709551615UL) > g_926), l_3080)) <= (-8L))) , l_3368) || g_992) <= 0x68154BD0L) == 0x69B6L))) != g_81)))))), g_72));
            for (g_156 = 13; (g_156 < 17); g_156 = safe_add_func_uint16_t_u_u(g_156, 7))
            {
                return l_3080;
            }
        }
        l_3374 = (safe_lshift_func_int16_t_s_s((g_3288 | 0x0FB079DBL), 6));
        if ((((safe_mod_func_int64_t_s_s((l_3377 <= (g_1052 , 0xA0L)), (l_3310 & (((0x9CD7D31C8E1D23EFLL && (g_14 ^ l_3377)) | (!((((safe_sub_func_int64_t_s_s((((((safe_div_func_int8_t_s_s((((safe_lshift_func_int16_t_s_s((~(g_81 , (+(((((((((safe_sub_func_int32_t_s_s((((l_3310 < 6L) , 0xB1L) == g_71), g_3288)) != g_1973) , l_3287) < (-7L)) >= 0x0BL) > l_3389) , l_3080) ^ l_3390) , l_3310)))), 8)) > l_15) != 0x8B6B8A7FL), g_2223)) && (-7L)) > g_1052) >= l_2951) < l_3149), g_1052)) & 0x1A8EL) > l_3310) & g_59))) || g_156)))) , 0xB0L) ^ l_3377))
        {
            int8_t l_3391 = 0x80L;
            l_3391 = 0x275DFA0CL;
            l_3191 = (g_3034 , ((((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((safe_add_func_uint32_t_u_u(((safe_sub_func_uint64_t_u_u((safe_sub_func_int64_t_s_s((l_3390 <= ((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int16_t_s_u(0L, 9)) , ((l_3287 != ((0xA0A4CB141845B1ECLL ^ (safe_div_func_int8_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_u((!(safe_unary_minus_func_int8_t_s((0xDC1EL > (safe_mod_func_int16_t_s_s(l_2951, (g_1052 ^ (((((((safe_add_func_uint8_t_u_u(((l_3391 >= l_3328) < g_992), g_2850)) | l_3100) || l_3391) != 255UL) > 2UL) || l_3374) || (-1L))))))))), g_3288)) >= g_2822), 14)), l_3390))) & l_3328)) != l_3390)), g_2822)) != 2L)), l_2951)), g_992)) <= g_992), l_3287)) , l_3418) == 0xDF3730E86C03970ELL), l_3377)), 4UL)) , l_3419) , l_3377) , 0L));
            g_2822 = g_2725;
            g_3420 = l_3310;
        }
        else
        {
            int32_t l_3430 = 0xC4665B32L;
            uint64_t l_3491 = 0xB5FE5EF64377E664LL;
            int16_t l_3517 = 1L;
            int32_t l_3567 = 7L;
            uint8_t l_3741 = 0xF3L;
            if ((g_1861 < ((((safe_mod_func_uint16_t_u_u(((((0x1A3CL < ((safe_rshift_func_uint16_t_u_u((l_3425 , g_992), (((((((safe_sub_func_uint64_t_u_u(g_71, (safe_add_func_int32_t_s_s((l_3430 & (safe_sub_func_int64_t_s_s(((0L != (safe_rshift_func_uint16_t_u_u(((((g_1973 || (l_2982 > 0x36L)) >= g_71) , g_14) > l_3430), 14))) > g_156), l_3425))), 0x156F17D1L)))) , g_3034) || l_3149) > l_3430) != g_1052) == l_3430) , 0x30B6L))) > 0xB302L)) > g_1052) <= l_3430) < l_3418), 65535UL)) ^ l_3430) <= g_2223) != g_1973)))
            {
                int16_t l_3459 = 6L;
                int16_t l_3565 = (-1L);
                if ((((safe_unary_minus_func_uint16_t_u((((safe_mod_func_uint64_t_u_u((((g_3288 == (safe_sub_func_uint32_t_u_u((l_3430 == (((safe_rshift_func_int16_t_s_u(((((safe_sub_func_int64_t_s_s((g_1861 < (safe_mod_func_int64_t_s_s(((safe_mod_func_int64_t_s_s((safe_mod_func_int8_t_s_s((safe_div_func_int16_t_s_s(((((safe_unary_minus_func_uint16_t_u((((safe_div_func_int8_t_s_s(((l_3100 , (g_72 && (((safe_lshift_func_uint16_t_u_u((((l_3328 || 0x6DL) | 65535UL) | (((g_3420 & g_3034) , g_72) || l_3374)), 9)) != g_1052) , 0L))) | 3UL), 6L)) > 0x2090393FL) & l_3459))) >= g_1861) <= 5UL) || 4294967295UL), 0x4532L)), g_71)), g_1052)) , 0L), 0x466FDFBBCBE1C070LL))), l_3061)) | g_2223) == l_3430) | l_3377), 8)) >= l_3064) < g_1052)), g_3288))) <= g_3420) <= g_3420), g_156)) < l_3459) , g_1052))) , g_3288) & l_3430))
                {
                    uint16_t l_3460 = 0xA836L;
                    int8_t l_3489 = 0x4BL;
                    int32_t l_3490 = 0x8E097163L;
                    int32_t l_3519 = (-1L);
                    g_72 = (l_3460 <= ((safe_rshift_func_uint8_t_u_s((((g_2685 && (safe_lshift_func_int8_t_s_s((((((safe_add_func_uint64_t_u_u(((g_3288 , l_3100) || l_3419), (((safe_div_func_uint8_t_u_u(((((safe_sub_func_uint64_t_u_u((g_2223 , (safe_add_func_uint32_t_u_u(((safe_sub_func_int64_t_s_s((((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(((((-4L) || ((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s(((((((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((((((18446744073709551612UL ^ (-1L)) || l_15) , l_3489) > 0UL) ^ 0xB0L), g_2822)), 0xFB9CL)) <= (-9L)) > l_3374) <= l_3490) >= l_3491) > g_100), l_3377)), g_81)) , l_3492)) ^ 1UL) >= g_926), g_2822)), g_926)) != g_81) >= 0x30L) & l_3493) >= g_1861), g_1861)) < g_59), l_3418))), l_2951)) | g_1861) || g_2822) | g_3288), l_3425)) & l_3310) >= g_59))) < (-9L)) > g_926) , 0x926E9B44C03365C7LL) > g_926), g_2685))) < l_3459) && g_2685), 6)) && g_3420));
                    for (g_2685 = 0; (g_2685 > (-25)); --g_2685)
                    {
                        uint32_t l_3518 = 1UL;
                        int32_t l_3550 = 0x7BF48C44L;
                        l_3519 = ((safe_unary_minus_func_uint8_t_u((0x8FA469F79A7A764CLL & (safe_add_func_int64_t_s_s(((+((safe_rshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_add_func_uint64_t_u_u(g_2850, (((safe_mod_func_uint16_t_u_u((((((((0xEAFE8D4CL ^ (safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(((l_3430 != g_992) , g_1052), l_3489)), (g_59 , (safe_sub_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s(((((l_3489 != 0xF1F371D3L) ^ 4294967286UL) , l_3517) ^ l_3460))), 0)) <= l_3460), g_2822)))))) ^ 0x28L) <= g_926) >= l_3518) && (-1L)) != 1L) ^ 0xFDL), 0x67CBL)) == g_3288) == g_156))), g_71)), 4)) , l_3518)) == 0xA5FCF4C2F2A22332LL), 1UL))))) == g_81);
                        l_2951 = (safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(g_926, l_3459)), g_926));
                        l_3550 = (((((safe_mod_func_uint8_t_u_u(0xCCL, (((safe_div_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u((safe_div_func_int32_t_s_s((((((safe_mod_func_uint32_t_u_u(l_3519, (safe_mod_func_int8_t_s_s(((((((safe_div_func_uint64_t_u_u((0xF69BL <= (((safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s(((g_100 || l_3518) == (safe_mod_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((safe_rshift_func_uint16_t_u_s(0x29D3L, 13)) == (l_3425 <= g_992)) & (g_71 , l_3518)), l_3374)), g_3420)), 3UL))), l_3459)), 0x89L)) | g_59) >= g_81)), 7L)) , l_3518) | l_3519) , l_3459) ^ 0xF4L) > g_81), g_2685)))) , 0x6AC5893169714318LL) & 0xC901F942517D73C4LL) | 1UL) & 0x3548A6DF8AF17503LL), l_3459)), 0xE3556834L)) | l_3191), g_2822)) < g_2223) || 0x5D09EA98L))) & l_3490) , 0x59L) >= 1UL) | g_1861);
                    }
                }
                else
                {
                    int8_t l_3564 = (-3L);
                    l_3567 = (((g_59 ^ ((((l_3389 , (safe_div_func_int32_t_s_s(((((((safe_add_func_uint32_t_u_u(g_3288, ((((((safe_rshift_func_int8_t_s_s((safe_add_func_int16_t_s_s(g_992, (+(safe_add_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((65535UL | g_14), ((l_3064 != l_3564) , g_59))), l_15))))), 2)) ^ l_3459) , l_15) == g_1861) , l_3564) , g_2822))) == g_156) > l_3565) | 18446744073709551615UL) & l_3430) || 250UL), l_3564))) != 0xB818F8F6L) & g_2822) , l_3566)) , l_3418) && g_59);
                    g_2822 = (((safe_lshift_func_uint8_t_u_s(0xFCL, g_1973)) , l_2982) <= g_59);
                    g_2822 = (+(safe_div_func_int8_t_s_s((((((!(safe_div_func_uint32_t_u_u(g_14, (((((safe_rshift_func_int8_t_s_u(g_1973, 5)) == (((((l_3565 == (((safe_lshift_func_int8_t_s_u(0L, 3)) ^ 1L) != 0L)) || (l_3064 ^ (((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u((g_2223 <= ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s(l_3287)), g_3420)), 0L)) <= (-2L))), l_3564)), l_3565)) , l_3491) > l_3566))) , g_71) != l_3491) , g_156)) < 5L) < g_81) || g_59)))) | 1UL) == g_2223) > 0x3D0AE446F941663BLL) <= g_59), 0x28L)));
                    g_72 = (safe_mod_func_uint32_t_u_u(l_3430, l_3374));
                }
            }
            else
            {
                int16_t l_3619 = 0x3AE4L;
                int16_t l_3674 = (-1L);
                int16_t l_3688 = 0x3DF3L;
                int64_t l_3701 = 0xD16BD07DBC3B1454LL;
                int32_t l_3775 = 1L;
                int8_t l_3788 = 0x0EL;
                for (g_3288 = (-10); (g_3288 <= (-11)); g_3288 = safe_sub_func_uint32_t_u_u(g_3288, 3))
                {
                    uint8_t l_3601 = 0x28L;
                    int16_t l_3621 = 5L;
                    g_72 = (((safe_mod_func_int16_t_s_s((safe_mod_func_int8_t_s_s(l_3601, (safe_lshift_func_uint16_t_u_u(((g_14 , (g_14 != ((safe_unary_minus_func_uint32_t_u(((safe_div_func_int8_t_s_s((safe_div_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_s((safe_div_func_uint32_t_u_u(((((safe_sub_func_int64_t_s_s((~0xF04CL), (((g_2685 , 0xC96AADB6L) || (~(((l_3491 != l_3619) == (l_3620 && l_3619)) & 0x4AL))) < l_3621))) & g_926) == l_3430) ^ 8L), g_59)), 1)), g_59)), l_3621)) || g_1861))) > l_3601))) ^ l_3389), g_2223)))), g_81)) | 0xF2C75BC6L) >= (-3L));
                    g_2822 = (((((safe_add_func_int64_t_s_s(((((((((l_3374 ^ (safe_lshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((safe_sub_func_int8_t_s_s(((safe_add_func_int32_t_s_s(0x11625F1AL, (((((safe_add_func_int32_t_s_s((safe_div_func_int8_t_s_s((((~(!l_3149)) || ((g_71 , (((((65532UL ^ (l_3619 , g_3288)) ^ 5UL) , (~(safe_lshift_func_uint8_t_u_u(g_926, g_992)))) != 252UL) != 0x52L)) & 0xAA3FL)) != g_72), g_1861)), 0xC42294ECL)) ^ 0xAAL) | 0x87CDL) <= l_3621) & g_156))) == l_3080), 0x9AL)) >= l_3377), 2)), 5))) <= l_3389) , g_2725) & g_3288) ^ l_3641) > 0xC2L) , l_3601) > g_2685), l_3567)) || l_3377) > 0x010E3964532E2BC1LL) <= (-1L)) <= g_81);
                }
                g_72 = ((safe_sub_func_uint64_t_u_u((!(!(((((((safe_div_func_int32_t_s_s((safe_add_func_int32_t_s_s((248UL <= l_3389), (+(0x15A3DCCCE59DC1C7LL ^ (((((safe_mod_func_int64_t_s_s(((safe_sub_func_int8_t_s_s((~(((g_1973 , 0xE48DL) > (safe_sub_func_uint64_t_u_u((safe_mod_func_uint8_t_u_u((g_156 == (safe_add_func_uint8_t_u_u(((g_3288 , (safe_div_func_uint16_t_u_u((safe_mod_func_int64_t_s_s(((g_2685 & ((safe_mod_func_int64_t_s_s((safe_sub_func_int32_t_s_s((g_81 , g_14), g_1861)), l_3619)) > l_3619)) != g_3288), g_2822)), l_3672))) > 0x453CL), g_59))), 0x92L)), g_156))) || l_3673)), g_992)) > l_3674), 0x0626F2AC0DF8BE3DLL)) , g_81) < 18446744073709551615UL) || 0xE4L) > g_3420))))), 0xFC09A20DL)) | 0L) >= l_3517) , l_3674) != 1L) != l_3619) , g_100))), 0x9F0F70EDC5ECF8BDLL)) | g_3420);
                l_3567 = ((((!(g_2822 & (((safe_unary_minus_func_uint8_t_u(0x65L)) == ((((l_3430 > (safe_mod_func_uint16_t_u_u((((safe_add_func_uint64_t_u_u((((0L ^ (((safe_lshift_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((((((((safe_rshift_func_int8_t_s_u((g_1861 & 0x5346B7FDL), 0)) != (g_2685 , (((safe_unary_minus_func_uint32_t_u(g_1052)) | ((((0xE6C6A7DDB56C0733LL ^ l_3064) | g_3420) == l_3430) < g_2223)) , 1UL))) && 65527UL) || g_2223) || l_3389) >= (-3L)) == g_156), l_3517)), l_3493)) == 4294967295UL) != g_2223)) , 0x5475258AL) & g_2223), l_3688)) != l_3389) , 65535UL), g_992))) , l_3619) || 0x46L) == g_1973)) , 0xB450L))) >= g_81) != g_2850) || l_3673);
                if ((((0xE5L && g_1973) >= (safe_lshift_func_int8_t_s_s((g_59 == (safe_mod_func_int8_t_s_s((((l_3430 , (safe_lshift_func_uint8_t_u_s(g_81, (((safe_sub_func_int16_t_s_s((((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_u((l_3701 , (((1UL > g_1861) || g_2850) > g_3420)), g_1973)), l_3702)) , l_3149) , l_3491), 0x992CL)) ^ 0x341DB1EAL) != l_3702)))) & l_3619) > g_2725), g_1052))), l_3418))) & l_3390))
                {
                    uint64_t l_3719 = 7UL;
                    g_2822 = (l_3064 , (safe_mod_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s(((((g_2685 , (safe_sub_func_uint16_t_u_u(((safe_add_func_uint64_t_u_u(0x8C66C539E36F4042LL, g_2822)) > 0x7BF7950AL), (safe_sub_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(8UL, (safe_lshift_func_uint16_t_u_u(((1L < (0L && ((((((safe_div_func_int64_t_s_s((((l_3567 | g_2223) || l_3719) <= 1UL), l_3425)) || g_3420) == 0xB87B52CBL) != l_3430) != 0xB4E0D6F0L) == 8L))) ^ g_2850), l_3191)))), l_3720))))) | g_992) == g_156) && g_1861), g_72)), g_2223)));
                    g_2822 = ((g_2822 >= ((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((0x8B660CD2BE11D3B6LL || (((((safe_unary_minus_func_int16_t_s(5L)) < g_1973) >= (((safe_add_func_uint64_t_u_u((safe_sub_func_uint64_t_u_u((safe_div_func_uint64_t_u_u(((((safe_mod_func_int32_t_s_s((safe_div_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((((l_3719 ^ g_926) <= (l_3287 <= (65528UL != ((!l_3517) <= g_2822)))) <= 18446744073709551615UL), l_3688)), 4UL)), 0xA440665DL)) || g_100) || l_3425) ^ l_3418), (-7L))), g_2725)), (-1L))) & 1UL) || g_3034)) , g_72) && g_926)), l_3719)), 4)) & 0xEB5DC200L)) & g_1973);
                    l_3741 = 0x7C9A4742L;
                }
                else
                {
                    uint32_t l_3769 = 0xC40B45B7L;
                    g_2822 = ((safe_add_func_int16_t_s_s((l_3310 || g_156), 7UL)) < (safe_sub_func_uint8_t_u_u((!0x4CL), ((((safe_div_func_uint8_t_u_u((safe_add_func_int32_t_s_s(((((safe_div_func_uint64_t_u_u((0x066FL & 0x4E43L), l_3389)) & (g_3288 , (((safe_mod_func_int64_t_s_s((((safe_add_func_int8_t_s_s((((((safe_mod_func_int16_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s((((((safe_add_func_int64_t_s_s((safe_lshift_func_uint16_t_u_u(0x514DL, 12)), g_14)) && g_3420) >= l_3701) || g_3420) , 0x5EL), l_3328)) != l_3769), 4)), g_81)) , l_3517) == 0x31L), 0xE16AL)) , g_2223) <= l_3741) || g_2850) | l_3720), 0UL)) != g_72) != g_1973), l_3770)) == g_2822) > g_3420))) == g_3288) || g_156), g_992)), l_3769)) & g_2725) <= l_3430) && 8L))));
                    if (l_3769)
                    {
                        int32_t l_3776 = 1L;
                        l_3775 = (safe_add_func_uint32_t_u_u((g_2223 >= ((safe_unary_minus_func_uint32_t_u(l_3328)) & g_2223)), (!g_2850)));
                        l_2951 = ((l_3776 || (safe_mod_func_uint16_t_u_u((l_3064 , ((l_3779 == ((safe_add_func_uint32_t_u_u((l_3619 , (safe_div_func_int64_t_s_s((((safe_unary_minus_func_uint16_t_u(((safe_add_func_int8_t_s_s((0x66L != ((l_3776 < l_3776) != l_3787)), (l_3779 | g_1052))) != 18446744073709551615UL))) == l_3788) == 0UL), l_3517))), (-1L))) | 0xE714L)) | g_156)), 4UL))) , 0x535910C0L);
                        g_72 = l_3789;
                        return l_3769;
                    }
                    else
                    {
                        return g_2223;
                    }
                }
            }
            g_2822 = l_3720;
        }
    }
    else
    {
        uint64_t l_3816 = 0xD1039E3DCDE23EACLL;
        l_3566 = (((safe_sub_func_int8_t_s_s((l_3377 , g_3034), ((g_81 , ((((+(g_1973 <= (g_2725 && (safe_sub_func_int8_t_s_s((g_156 & (safe_div_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u((g_926 & ((l_3492 , (safe_div_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_uint64_t_u(((safe_sub_func_int32_t_s_s(((((safe_mod_func_uint32_t_u_u(((((safe_lshift_func_uint8_t_u_u(g_72, g_72)) != 0x9FB94FD6L) & g_1973) < g_72), g_2725)) , g_2685) | 0x95L) & 0L), 0xC05C0CC7L)) & 0x7F3DB0838230FADCLL))), 0)), g_2685))) > g_2685)), g_3814)), (-3L))), g_59)) & l_3815), 5L))), g_2725))))) == 0xB379E67336551C80LL) ^ g_3814) != l_3816)) || 0xF055A45ED2850839LL))) && g_2850) == g_3814);
    }
    return g_100;
}







static int32_t func_2(int32_t p_3)
{
    int64_t l_2937 = (-1L);
    for (g_81 = 0; (g_81 < 37); ++g_81)
    {
        uint16_t l_2928 = 1UL;
        g_2822 = (safe_sub_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((((((safe_sub_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((((p_3 & (safe_rshift_func_uint16_t_u_u(65535UL, (safe_mod_func_int8_t_s_s((((safe_lshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s((g_71 > (safe_mod_func_int64_t_s_s(((p_3 | ((l_2928 , (0x27L || (((safe_mod_func_int8_t_s_s((safe_mod_func_int64_t_s_s(p_3, (safe_rshift_func_uint8_t_u_u(((-1L) ^ (safe_lshift_func_int8_t_s_u((-2L), g_2822))), 6)))), p_3)) || g_72) , 0xE8L))) >= 6L)) == (-1L)), 4L))), 6UL)), p_3)) ^ g_2223) | 65535UL), l_2928))))) == p_3) | 0xCFDC4DFCL), g_1861)), l_2937)) ^ p_3), 9)), (-5L))) == g_1052) || g_14) > l_2928) == 5UL) <= g_1973) < (-1L)), 0x0990L)), p_3));
        g_2822 = (safe_unary_minus_func_int32_t_s(((((safe_div_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((-2L), ((((p_3 , (g_100 > p_3)) | ((g_72 == 18446744073709551608UL) , ((safe_add_func_int16_t_s_s(0xED12L, (safe_div_func_uint16_t_u_u(((l_2928 != (safe_sub_func_int64_t_s_s(((safe_rshift_func_int8_t_s_u(g_2822, g_72)) , p_3), g_1052))) , 0x69A0L), g_1861)))) & 0xC76DL))) != g_156) == 0x85L))), p_3)) > p_3) | l_2928) , g_100)));
    }
    return l_2937;
}







static int16_t func_7(int32_t p_8, uint32_t p_9, int8_t p_10, int64_t p_11)
{
    int32_t l_2754 = 0xF5FE97D0L;
    int32_t l_2802 = 0L;
    uint32_t l_2853 = 0x4256E252L;
    int32_t l_2866 = 1L;
    if (p_10)
    {
        int32_t l_2758 = (-1L);
        int32_t l_2841 = 0x3F810DE4L;
        g_72 = ((g_81 & ((safe_lshift_func_uint8_t_u_u((p_11 <= l_2754), ((((!4294967295UL) & ((g_100 == (safe_mod_func_uint64_t_u_u((g_2725 || (4294967286UL > g_1973)), (g_71 & 0x72BDACC9L)))) , g_100)) ^ l_2758) | 0L))) <= l_2758)) == 0xDCB4CAF6L);
        g_72 = (safe_rshift_func_uint8_t_u_s((((safe_add_func_uint16_t_u_u(65531UL, (safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_s(g_1973, ((safe_sub_func_uint8_t_u_u(g_2685, ((safe_div_func_int16_t_s_s(p_10, (safe_lshift_func_int16_t_s_s(((((l_2754 <= (safe_add_func_int32_t_s_s(0x57D2D3C5L, (safe_rshift_func_int8_t_s_u(0L, (l_2754 == (safe_lshift_func_int16_t_s_s((((((((((safe_mod_func_uint32_t_u_u(((g_100 < (-8L)) ^ 5UL), p_11)) < l_2754) , g_2223) , p_9) == g_1973) >= 0UL) >= g_1861) >= 1L) | p_11), 1)))))))) | 1UL) <= g_71) != g_1973), 12)))) >= l_2754))) , g_2223))) && g_14), 0x15FD4333L)))) | 7L) && 0x88CFL), 7));
        for (p_11 = (-25); (p_11 < (-19)); p_11 = safe_add_func_int8_t_s_s(p_11, 9))
        {
            int32_t l_2787 = 6L;
            int32_t l_2801 = 0x5A56178FL;
            if ((safe_sub_func_int16_t_s_s(g_2685, ((safe_rshift_func_uint8_t_u_u((((((((((l_2787 >= (p_8 || ((((((p_8 == (((g_2685 < (p_10 , ((l_2758 , l_2754) <= (g_2685 < l_2787)))) , g_2223) ^ g_156)) && l_2787) , l_2754) ^ l_2758) || l_2787) && l_2787))) <= 1L) >= 18446744073709551615UL) < l_2758) , 0xFBL) != l_2787) == p_11) | g_2223) || p_11), 2)) | 1UL))))
            {
                uint8_t l_2797 = 0x02L;
                for (g_59 = 0; (g_59 < (-2)); g_59 = safe_sub_func_uint8_t_u_u(g_59, 7))
                {
                    int32_t l_2800 = (-6L);
                    l_2801 = (safe_mod_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u(((p_10 || (0xE847L && ((((((l_2754 <= (safe_div_func_uint8_t_u_u(((safe_unary_minus_func_uint16_t_u(p_11)) , p_9), l_2797))) <= 4294967295UL) , (((0xE5C3L == ((safe_rshift_func_int16_t_s_s((((l_2754 & l_2800) & 0x99L) <= p_10), p_9)) && g_100)) , p_8) || 0x90L)) , g_81) == l_2758) ^ p_10))) || l_2800), p_9)), l_2800));
                    l_2802 = l_2758;
                }
                return l_2797;
            }
            else
            {
                uint8_t l_2823 = 1UL;
                int32_t l_2842 = 5L;
                if ((safe_lshift_func_int8_t_s_s((((((((safe_lshift_func_int16_t_s_u(((((safe_mod_func_uint8_t_u_u((0x65ECL || (!(((g_926 || (((p_8 >= ((((safe_unary_minus_func_uint8_t_u((!0x65DEL))) ^ l_2802) || (safe_div_func_uint32_t_u_u((safe_unary_minus_func_int16_t_s((((((l_2801 && ((safe_add_func_int32_t_s_s((+(((safe_sub_func_uint32_t_u_u((((g_1973 > l_2758) && (0L >= p_11)) , p_11), p_9)) <= 0L) | p_11)), 0L)) >= l_2801)) > 0xCBL) > p_9) ^ 18446744073709551614UL) ^ l_2787))), p_10))) & 1UL)) & l_2787) >= l_2758)) < 0xBB65L) , l_2754))), 0x90L)) | p_11) >= 0xB5L) , g_2822), 4)) == p_11) , l_2787) >= 0xFDC0L) || l_2802) <= l_2823) == 0x91CF8A5DE86FE3FALL), l_2823)))
                {
                    return g_1861;
                }
                else
                {
                    uint32_t l_2834 = 0x4B02589AL;
                    int32_t l_2840 = 0L;
                    l_2840 = (safe_mod_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((safe_sub_func_uint64_t_u_u((((safe_sub_func_uint64_t_u_u(((g_2725 == ((safe_lshift_func_int8_t_s_s((l_2801 == 0x1018E7EFEA71A6E9LL), 1)) , ((l_2834 ^ g_992) != (safe_add_func_uint16_t_u_u(g_72, p_9))))) || g_992), ((safe_unary_minus_func_int32_t_s((safe_sub_func_int8_t_s_s(l_2823, l_2758)))) < 0x9BL))) == l_2758) != l_2801), l_2834)), p_8)), l_2787));
                    if (g_2822)
                        break;
                    if (l_2841)
                        continue;
                    l_2842 = p_9;
                }
                l_2758 = ((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s(((((((p_11 , (safe_rshift_func_int8_t_s_s(0xB2L, ((((0L && ((0xADBD252BL && (0L < g_72)) && 0xA56BL)) , (p_9 != ((~(g_926 && g_59)) & g_72))) , g_2850) | 0x55L)))) ^ l_2754) <= p_10) & 1UL) | g_2223) , g_1973), l_2841)) > g_1861) && 0x06DDL), 3)) >= p_9);
                l_2802 = (((((safe_rshift_func_uint16_t_u_u(p_9, l_2853)) ^ ((0x803A922BL > (g_926 > l_2758)) && (((((safe_sub_func_uint32_t_u_u(g_992, (p_11 == (safe_sub_func_int32_t_s_s(g_1973, p_9))))) , p_9) ^ g_1973) , g_2850) , l_2853))) && g_71) & p_10) >= g_156);
                l_2801 = (safe_sub_func_int64_t_s_s(((((l_2802 , (((7L >= (g_2822 , g_2223)) >= (safe_rshift_func_uint16_t_u_u((((((safe_rshift_func_uint8_t_u_s((18446744073709551609UL | 0L), 5)) <= (l_2802 > 0L)) , (safe_mod_func_uint64_t_u_u(18446744073709551610UL, p_10))) != l_2866) || p_8), 11))) , g_1052)) & (-7L)) != 18446744073709551614UL) <= 1L), p_10));
            }
        }
        l_2758 = (-1L);
    }
    else
    {
        int32_t l_2877 = (-1L);
        int64_t l_2898 = 0x5F824377D2A3173ELL;
        l_2802 = ((safe_div_func_int16_t_s_s(((p_10 | 0x7BB204A3L) , (((safe_add_func_int16_t_s_s(((safe_rshift_func_int16_t_s_u(0xB688L, 10)) | (safe_div_func_uint8_t_u_u(((0x8E3FL ^ 0xE8CBL) && (safe_add_func_int16_t_s_s((l_2877 , (safe_div_func_int64_t_s_s(g_926, p_10))), (safe_sub_func_uint16_t_u_u(((l_2853 == (-7L)) && p_10), p_11))))), 1L))), 0L)) < 3UL) , (-1L))), g_81)) && 4L);
        g_2822 = (safe_add_func_int64_t_s_s(1L, (((safe_sub_func_int32_t_s_s(g_2850, (safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u(g_926, p_9)) , ((-6L) < (safe_add_func_int32_t_s_s(((p_9 ^ (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((p_11 , l_2898) | 0x3EECL), 15)), 4))) ^ l_2877), 0x8A445206L)))), 7)), p_9)))) && p_8) != g_992)));
    }
    for (g_81 = 0; (g_81 == 57); g_81++)
    {
        int32_t l_2903 = 0x74F28D78L;
        for (g_2685 = (-1); (g_2685 <= 23); ++g_2685)
        {
            return l_2903;
        }
        if (l_2754)
            continue;
    }
    l_2802 = g_2685;
    return l_2866;
}







static int16_t func_12(int64_t p_13)
{
    uint8_t l_17 = 253UL;
    int32_t l_2268 = (-10L);
    int8_t l_2320 = 4L;
    int32_t l_2383 = (-9L);
    uint64_t l_2579 = 18446744073709551606UL;
    uint32_t l_2635 = 0x8430398CL;
    uint8_t l_2672 = 0x44L;
    uint64_t l_2704 = 0x08E463E4AE4A273DLL;
    uint32_t l_2724 = 18446744073709551609UL;
    uint16_t l_2741 = 0x47BCL;
    if (g_14)
    {
        int32_t l_16 = 0x790E8648L;
        uint16_t l_1860 = 0x8F5EL;
        l_17 = l_16;
        l_16 = (func_18((safe_div_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(((func_28(p_13, p_13, p_13, func_34(p_13, ((((l_16 <= func_38((((+(safe_mod_func_int16_t_s_s(func_44(l_16), ((0xE568C3B083FFB38BLL & ((((l_17 , l_16) == g_59) | g_59) , l_17)) , 1UL)))) > p_13) || g_81), l_16)) == p_13) , g_14) ^ l_17), p_13), p_13) < 0x52L) >= 65535UL), 0)), p_13)), g_81, p_13, l_1860, g_1861) != l_1860);
        l_16 = (+l_17);
    }
    else
    {
        uint32_t l_2188 = 0x5E841A38L;
        int32_t l_2195 = 0x16692A93L;
        int8_t l_2196 = 0x54L;
        int16_t l_2247 = 0L;
        int32_t l_2308 = 0xDD29B2B6L;
        for (g_1861 = (-28); (g_1861 == (-3)); g_1861++)
        {
            uint16_t l_2180 = 0xCB98L;
            int32_t l_2224 = 2L;
            int8_t l_2291 = 0xEEL;
            int16_t l_2322 = 0x82A9L;
            uint64_t l_2385 = 0x21BF53E9575D9D5DLL;
            int32_t l_2463 = 0L;
            g_72 = 0x0EBEBA6FL;
            g_72 = ((+65535UL) ^ ((0x3A14E8FE8BEA2EFELL < (l_2180 | (safe_add_func_int64_t_s_s((safe_sub_func_uint32_t_u_u((safe_unary_minus_func_int32_t_s(((l_2180 && (safe_sub_func_int32_t_s_s(p_13, g_1052))) | 0xE51AF620L))), ((l_2188 | (safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((safe_add_func_uint64_t_u_u(((((p_13 == p_13) ^ l_2195) & p_13) < 0xAA86L), l_17)), 6)), l_2196))) > l_2180))), 0x8FDF21306170C05DLL)))) & l_2188));
            for (l_17 = 0; (l_17 <= 32); l_17 = safe_add_func_uint16_t_u_u(l_17, 9))
            {
                int64_t l_2225 = 2L;
                int32_t l_2226 = 0xC3AE4853L;
                uint64_t l_2290 = 0xEF9522CF64ED8F92LL;
                int32_t l_2292 = (-1L);
                int8_t l_2321 = (-8L);
                uint64_t l_2384 = 0x6864299663EC877DLL;
                g_72 = 0x82C24BC1L;
                for (g_926 = 0; (g_926 == 60); ++g_926)
                {
                    int32_t l_2213 = (-6L);
                    uint32_t l_2264 = 0x49061937L;
                    uint16_t l_2293 = 0x896EL;
                    l_2224 = (safe_mod_func_uint16_t_u_u((safe_div_func_int16_t_s_s((safe_lshift_func_int16_t_s_s((p_13 && ((safe_rshift_func_int16_t_s_u(g_1861, ((p_13 , g_14) , (safe_add_func_uint32_t_u_u((p_13 < (safe_add_func_int16_t_s_s(l_2213, ((((safe_add_func_int64_t_s_s((safe_unary_minus_func_uint64_t_u((l_2213 <= ((((safe_div_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((safe_mod_func_int8_t_s_s(0xAEL, ((p_13 , l_2213) && 0xCFEFL))), p_13)), p_13)) < (-1L)) && l_2213) != 0UL)))), g_992)) < p_13) | 0x912A396946CF62D3LL) ^ l_17)))), p_13))))) != p_13)), g_2223)), g_1052)), 0x26A3L));
                    l_2226 = (l_2225 != l_2188);
                    if (((l_2213 ^ ((p_13 <= (l_2180 , (0xBDL && l_2213))) > (safe_mod_func_int16_t_s_s((((0xA562FE4CL || l_2226) == ((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint64_t_u(((safe_div_func_uint32_t_u_u((safe_div_func_int32_t_s_s((65529UL > (safe_mod_func_int16_t_s_s((l_2195 , 0xD8EBL), 0x154FL))), g_156)), 0x7056F380L)) == l_17))) , g_14), (-1L))) ^ 18446744073709551615UL)) <= g_81), 1L)))) | p_13))
                    {
                        uint32_t l_2265 = 1UL;
                        l_2213 = ((safe_rshift_func_uint16_t_u_u(l_2226, 11)) , (!(safe_rshift_func_uint8_t_u_s(0x94L, 7))));
                        l_2226 = (safe_rshift_func_int8_t_s_s(((((((safe_add_func_uint16_t_u_u(l_2247, 0x029EL)) == (((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((0UL || (((((safe_unary_minus_func_int32_t_s(3L)) & (safe_div_func_uint16_t_u_u((6UL > (safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u((((0x626DL | g_100) < (((~(g_926 | (safe_mod_func_int16_t_s_s((((safe_add_func_int32_t_s_s((((p_13 , p_13) != 0xD0L) , l_2247), g_59)) ^ 5L) <= p_13), g_59)))) , l_17) >= 0xFA02574E437F3C09LL)) || g_992), p_13)) <= 0x8F87L), p_13))), 8L))) , p_13) ^ p_13) & g_71)), 12)), 0xA6L)) >= p_13) != l_2264)) >= 0x28F4L) > 3UL) > g_71) != 0x8AL), 5));
                        l_2265 = p_13;
                        l_2268 = (safe_rshift_func_int16_t_s_s(p_13, 3));
                    }
                    else
                    {
                        int8_t l_2294 = 0x97L;
                        l_2213 = ((g_1052 != (((safe_mod_func_int64_t_s_s(((((safe_div_func_int32_t_s_s(((((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint32_t_u_u((g_156 > (-4L)), (((safe_lshift_func_int16_t_s_u((((g_14 & (safe_add_func_uint8_t_u_u((safe_add_func_uint64_t_u_u((255UL == (safe_sub_func_uint16_t_u_u((~(l_2247 > ((safe_div_func_int32_t_s_s(((((((safe_div_func_int8_t_s_s((1L > ((p_13 != (p_13 == l_2290)) != (-8L))), l_2291)) > l_2268) , l_2292) >= p_13) & l_2293) == g_992), p_13)) >= 0UL))), g_992))), l_2180)), l_2293))) == g_72) <= l_2180), l_2188)) >= l_2225) == (-1L)))) || 0x9908B1F4L), 3)) == g_2223) , 18446744073709551615UL) && p_13), p_13)) , p_13) >= g_2223) != 0x5981L), l_2294)) & 0L) ^ 1UL)) > 0x883FL);
                        if (l_2294)
                            break;
                        l_2308 = ((safe_rshift_func_uint16_t_u_u(0x9295L, l_2264)) == ((safe_mod_func_uint8_t_u_u(250UL, (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((-1L), 3)), 0)))) >= (safe_sub_func_int32_t_s_s(((0x67L & (l_2290 >= ((((safe_lshift_func_uint8_t_u_u((18446744073709551614UL | (((!l_2188) , g_14) != l_2213)), 4)) | p_13) >= p_13) != p_13))) < g_2223), (-3L)))));
                        l_2224 = (((!l_2224) && ((((l_2294 || g_59) & 0xDEL) , (safe_sub_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s(0xD818L, 9)) > (((safe_rshift_func_int16_t_s_s((safe_add_func_int32_t_s_s((((safe_add_func_uint32_t_u_u((0x7CCC302D0829C8C5LL && 1L), l_2264)) , l_2293) ^ l_2320), 0L)), p_13)) | g_926) , l_2321)) <= 4L), 0UL))) ^ l_2322)) || 0xF6L);
                    }
                }
                if ((p_13 < (!(safe_unary_minus_func_int16_t_s(l_2290)))))
                {
                    int32_t l_2336 = 0xB19BC5EFL;
                    int8_t l_2348 = 1L;
                    l_2308 = (safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(0x50A0L, 15)), (p_13 && (p_13 != l_2321)))), 3));
                    if (((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_int16_t_s_u((p_13 , (safe_unary_minus_func_uint16_t_u((l_2336 | (((~((safe_sub_func_uint64_t_u_u((safe_sub_func_int8_t_s_s(l_2336, (safe_lshift_func_uint16_t_u_s(((g_992 > (0x96L < ((1UL || ((safe_mod_func_int8_t_s_s(l_2348, (~(0UL & (((!l_17) < l_17) & g_72))))) > 0xF3L)) < l_2188))) && 8UL), 12)))), g_14)) , g_14)) < l_2308) , g_926))))), 5)) && 0x692D6C93L) || 255UL), 2)) || 0x624C731775AA1840LL))
                    {
                        int8_t l_2351 = 0x54L;
                        l_2308 = 1L;
                        if (g_1861)
                            continue;
                        l_2351 = 0xF010135FL;
                        g_72 = ((safe_sub_func_uint16_t_u_u(g_1861, (1UL ^ (safe_mod_func_uint32_t_u_u(g_1973, 0x35CFBA61L))))) < (((safe_mod_func_int32_t_s_s((g_1973 & g_71), p_13)) | ((safe_lshift_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((safe_unary_minus_func_int8_t_s(p_13)), (g_1052 , 1L))), 1)) < 0x6E13L)) == l_2180));
                    }
                    else
                    {
                        g_72 = 0L;
                    }
                    l_2224 = ((safe_div_func_uint8_t_u_u(8UL, g_72)) & ((safe_rshift_func_int8_t_s_s((((g_2223 , (safe_div_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s(p_13, 6)) | (safe_sub_func_uint32_t_u_u(((safe_add_func_int64_t_s_s(((safe_div_func_int16_t_s_s((0x998D9F9DL | (safe_div_func_int8_t_s_s((safe_add_func_int8_t_s_s(g_81, 0x87L)), 3UL))), (g_992 && g_1052))) , l_2383), l_2308)) ^ g_72), g_926))) != l_2384), p_13))) != l_2385) >= p_13), 1)) , l_2224));
                    for (l_2226 = 27; (l_2226 <= 10); --l_2226)
                    {
                        if (g_100)
                            break;
                    }
                }
                else
                {
                    uint32_t l_2394 = 1UL;
                    int32_t l_2413 = (-5L);
                    for (l_2383 = 0; (l_2383 >= (-2)); l_2383--)
                    {
                        int16_t l_2408 = 0x4FA4L;
                        int8_t l_2425 = (-7L);
                        l_2413 = ((safe_rshift_func_uint16_t_u_u((((l_2247 | ((safe_div_func_int32_t_s_s(l_2308, l_2224)) ^ l_2394)) == ((safe_div_func_uint32_t_u_u((safe_div_func_int64_t_s_s((safe_mod_func_uint8_t_u_u((l_2292 == ((safe_div_func_uint64_t_u_u(((safe_mod_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u((((!1UL) <= 0x9FL) == l_2408), 3)) && ((safe_lshift_func_uint16_t_u_s((((safe_lshift_func_int8_t_s_s((-9L), l_2268)) , l_2385) , 0xF845L), 6)) >= g_72)), l_2383)) > p_13), 1UL)) <= l_17)), l_2408)), 0xFEA707BDB5735142LL)), (-4L))) && p_13)) , p_13), p_13)) > 0UL);
                        g_72 = (safe_sub_func_int8_t_s_s((0x55L & 0x7EL), (safe_lshift_func_int8_t_s_u(((0L > l_2413) & ((p_13 | (0xE660L < (safe_rshift_func_int8_t_s_s((safe_unary_minus_func_uint16_t_u(((((g_156 || g_1052) < (safe_rshift_func_uint16_t_u_u(((safe_mod_func_uint32_t_u_u(((p_13 | p_13) <= l_2394), l_2425)) | l_2195), p_13))) ^ 0xCFF5F89CL) > l_2408))), p_13)))) , g_72)), 5))));
                    }
                    if ((safe_sub_func_uint64_t_u_u(g_72, 0x8D9D097AAFC35D4FLL)))
                    {
                        uint64_t l_2464 = 0xB7FE86F41E40B7A0LL;
                        int32_t l_2465 = 0x8E590288L;
                        g_72 = (0x4D17L < ((safe_div_func_int32_t_s_s((p_13 ^ (p_13 , 0x8A5BL)), ((((safe_div_func_int16_t_s_s(((0xAF54A725L && g_100) != (safe_lshift_func_uint16_t_u_s((g_81 | (p_13 > p_13)), p_13))), g_1052)) || g_1861) < p_13) && l_2322))) <= 0xF83EL));
                        l_2465 = ((((safe_div_func_uint8_t_u_u((((g_71 != ((safe_rshift_func_int8_t_s_u((((+(safe_add_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((g_2223 , (((safe_sub_func_int32_t_s_s(p_13, (((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((((safe_div_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((((safe_add_func_int8_t_s_s(((0x88957A10E328D291LL < ((((((safe_div_func_int64_t_s_s((((l_2290 <= ((l_2196 || ((safe_mod_func_int16_t_s_s((((l_2180 & 0UL) & (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((l_2180 && g_71), l_2195)), p_13))) == p_13), l_2463)) || l_2394)) ^ l_2394)) & p_13) && 5L), 6UL)) != l_2385) != p_13) | (-7L)) || (-5L)) & 1UL)) > l_2463), g_1052)) & g_72) < p_13) && (-6L)), 18446744073709551613UL)) || (-1L)), l_2464)) && 5L) > 0x16B4D0C8L), 3)), p_13)) || 255UL) & p_13))) < p_13) == 4294967295UL)), p_13)), l_2322))) ^ 0x8610L) <= 4294967294UL), 2)) <= p_13)) ^ p_13) == l_2291), p_13)) , p_13) , 0xB3L) ^ l_2196);
                        l_2413 = (-1L);
                    }
                    else
                    {
                        uint8_t l_2494 = 255UL;
                        g_72 = (safe_mod_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_s((p_13 && p_13), (safe_div_func_uint64_t_u_u((g_71 == ((safe_add_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_s((((g_100 < (safe_add_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s((((((safe_add_func_int8_t_s_s(((safe_add_func_uint64_t_u_u(l_2413, (safe_sub_func_int32_t_s_s(((((p_13 & g_992) , l_2268) >= (safe_mod_func_uint64_t_u_u(g_2223, g_992))) ^ g_992), g_59)))) >= l_2463), l_2322)) , l_2322) == l_2308) , g_1973) && p_13), 7)), g_81)) != 4L) | g_59), g_59)) , p_13), p_13))) || 0x54B153F7L) > l_2494), 6)) & g_81), p_13)), 7UL)) , p_13)), 0x91B0E686F9F6BB8ELL)))) ^ l_17), 1UL));
                        l_2463 = ((((safe_mod_func_int64_t_s_s((safe_mod_func_uint64_t_u_u((safe_sub_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((safe_add_func_int8_t_s_s((safe_div_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((((safe_mod_func_int64_t_s_s((safe_div_func_uint8_t_u_u(p_13, (+p_13))), (safe_add_func_uint8_t_u_u(((((safe_mod_func_int32_t_s_s(l_2290, (safe_mod_func_int64_t_s_s((safe_mod_func_int32_t_s_s((safe_mod_func_uint64_t_u_u((((-1L) == ((~((255UL != (l_2494 , l_2322)) , ((g_156 , ((((((safe_div_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((+(p_13 , l_2308)), p_13)) | p_13), g_156)), l_2394)), p_13)) ^ g_2223) && g_81), l_2292)) > g_14) , l_2290) & g_1861) , (-7L)) == g_2223)) < 0xE6C5L))) <= 0xBABB082A17B5E11ELL)) && l_2291), 0xA0DC8A2C8B8F4FCDLL)), p_13)), p_13)))) , l_2322) > g_1052) >= p_13), 0xBAL)))) && g_59) && g_926), p_13)), l_2463)), 0xFDL)) == 0x2F16D81F0E50ED79LL), 3)), 0x9BL)), g_926)), l_2320)) <= g_156) <= g_1052) >= 0xF730L);
                        l_2413 = (safe_mod_func_int32_t_s_s((((safe_sub_func_uint16_t_u_u(((p_13 >= (safe_add_func_int64_t_s_s((((l_2494 != (l_2494 & (((safe_rshift_func_uint16_t_u_u(((((safe_lshift_func_int8_t_s_s((safe_add_func_uint64_t_u_u(((safe_rshift_func_uint16_t_u_s((0xB0ADDEFBL && (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_s(p_13, 4)) , l_2383), (safe_unary_minus_func_uint16_t_u(g_1052)))), 2))), 5)) == p_13), (safe_div_func_int8_t_s_s((((1L == l_2413) && 0x84C6L) != 0x1D1DL), (-4L))))), 5)) != p_13) >= l_17) && 1UL), 8)) >= l_2494) > g_71))) | 0x267F8199L) ^ l_2195), 0x7ADC1B3C2B15226BLL))) && 0xEDL), p_13)) > 1L) >= l_2413), 0x1344290EL));
                    }
                    l_2413 = (~g_72);
                }
                l_2224 = (safe_rshift_func_int8_t_s_s((((safe_add_func_int64_t_s_s(((((0x3E5627D914D4323ELL && (safe_rshift_func_int8_t_s_u((+g_992), 3))) , p_13) , (safe_lshift_func_uint16_t_u_s(((safe_add_func_uint32_t_u_u((((0x653880ABL & ((safe_add_func_uint8_t_u_u(1UL, (0x0C812E52L <= (0L && ((((safe_sub_func_int32_t_s_s(0x1AF68AD4L, ((0xBD06FC59L || (-5L)) <= g_81))) ^ l_2320) < (-1L)) > p_13))))) > g_156)) != g_1973) > g_72), p_13)) , 0xD5F3L), 5))) || l_2308), (-7L))) , 0x9301E3B566E7C785LL) <= l_2579), l_2247));
            }
        }
        if (l_2188)
        {
            int8_t l_2582 = 0x7FL;
            g_72 = (safe_lshift_func_int16_t_s_u(1L, 0));
            return l_2582;
        }
        else
        {
            int32_t l_2622 = 1L;
            uint64_t l_2623 = 0x3BBDE044FD854948LL;
            l_2308 = (((l_2320 && (safe_sub_func_uint8_t_u_u(((safe_sub_func_uint64_t_u_u((((safe_mod_func_int64_t_s_s((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((~g_1052), (safe_add_func_uint64_t_u_u((((safe_add_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(((safe_add_func_uint64_t_u_u(((p_13 || (((safe_add_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_u(255UL, (safe_mod_func_uint8_t_u_u(0UL, (safe_lshift_func_int8_t_s_u(0x97L, 1)))))) <= ((safe_mod_func_int32_t_s_s(l_2308, ((0x779C03E64E99C8EALL <= (safe_lshift_func_int16_t_s_u((((safe_add_func_int32_t_s_s((((safe_mod_func_uint32_t_u_u((g_72 > l_2622), l_2196)) & l_2196) ^ l_2622), l_2622)) & 2UL) ^ 0L), 11))) ^ 255UL))) ^ 1L)), g_156)) && g_1861) && (-1L))) , p_13), l_2623)) ^ 1L), l_2308)), 1)) < g_1052), g_72)) || 0x04CC151CL) == l_2247), 7UL)))), g_926)), p_13)), g_81)) && l_2268) == p_13), g_71)) >= p_13), g_14))) & 1UL) && g_1861);
        }
        l_2308 = (((l_2247 || 0UL) ^ (p_13 >= ((safe_sub_func_uint64_t_u_u((p_13 > ((l_2579 , (((safe_lshift_func_uint16_t_u_s((((18446744073709551615UL == (safe_sub_func_int16_t_s_s(1L, p_13))) > 4UL) > g_1973), 13)) >= 0x24L) == 1UL)) , l_2196)), g_1861)) != g_926))) > p_13);
        l_2308 = l_17;
    }
    g_72 = (safe_rshift_func_uint16_t_u_u((((-6L) || (~(((g_81 || (p_13 < l_2635)) > (safe_div_func_int8_t_s_s((safe_add_func_uint8_t_u_u(((((safe_rshift_func_int8_t_s_u((((((((safe_rshift_func_int8_t_s_u((!((((((safe_lshift_func_uint16_t_u_s(65535UL, g_992)) == l_2383) >= l_17) && (safe_rshift_func_uint16_t_u_s((safe_mod_func_int64_t_s_s(((((safe_mod_func_uint32_t_u_u((((safe_mod_func_uint32_t_u_u(((safe_div_func_uint16_t_u_u((((safe_add_func_int16_t_s_s((~(safe_add_func_int16_t_s_s((l_2579 > p_13), l_2268))), l_17)) , p_13) ^ l_2320), g_100)) | l_2383), l_2320)) , 0x9F95L) <= p_13), g_156)) , p_13) <= 0x9248L) ^ p_13), g_2223)), 8))) <= l_17) > 0UL)), 3)) < 0x8B7A111DC1CC6136LL) < l_2635) > g_72) , p_13) , g_72) || p_13), p_13)) ^ 0x79B4BCCB4EA82B40LL) ^ 65527UL) && 0xAD5911FA2BAFEC6ALL), g_72)), 0x15L))) && l_2579))) , p_13), g_72));
    l_2268 = (safe_lshift_func_int16_t_s_s(p_13, (safe_div_func_int32_t_s_s((((((((safe_mod_func_int16_t_s_s(((safe_sub_func_int64_t_s_s(l_2672, ((((safe_add_func_uint16_t_u_u(((safe_add_func_uint64_t_u_u(((((safe_lshift_func_uint16_t_u_s(g_992, ((-1L) == (((safe_sub_func_int16_t_s_s(0xA9ACL, (safe_mod_func_int16_t_s_s(l_17, 1UL)))) < 0x74A0L) > l_2383)))) && l_2268) ^ p_13) > g_14), p_13)) > 0x8B69A80A4E51F122LL), l_2672)) <= g_59) == l_2635) | 4294967292UL))) ^ l_17), g_2685)) > p_13) >= l_2579) && p_13) != g_72) , (-7L)) && l_2635), l_2579))));
    if (((l_17 <= (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_u((safe_div_func_int64_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_sub_func_uint16_t_u_u(p_13, (g_992 < (safe_mod_func_int64_t_s_s(((safe_mod_func_uint32_t_u_u(((g_72 <= (safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(l_2383, (((l_2704 || g_2685) != (((safe_add_func_int16_t_s_s(((8UL && 0x4869L) == p_13), l_17)) , l_2383) <= 0xBE5FD26FAE821D30LL)) && g_2685))), p_13))) , l_2704), l_17)) & 0L), 0x4DAE2B3FA11199E0LL))))) < 0x6FL), 0x473BL)) == 1L) | g_1052) || g_1052), 0xA723A02F00675E40LL)), l_2383)), p_13))) | 0xFC3A5088L))
    {
        uint32_t l_2712 = 18446744073709551609UL;
        uint32_t l_2715 = 0x5DDE496CL;
        int32_t l_2742 = 0x3900574DL;
        g_72 = ((4294967288UL <= 0x50FA9EEAL) != g_100);
        for (g_1973 = (-1); (g_1973 < (-5)); g_1973--)
        {
            int64_t l_2718 = 0xBCFCE1BA41D00560LL;
            g_72 = 1L;
            g_2725 = (safe_unary_minus_func_uint64_t_u(((g_1052 < (l_2712 > (safe_add_func_int32_t_s_s((1UL == ((l_2715 ^ (g_81 > (safe_lshift_func_int8_t_s_u(p_13, l_2718)))) , l_2635)), (safe_mod_func_uint8_t_u_u((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int16_t_s_u((0x0917L | g_72), p_13)) <= p_13))), l_2724)))))) & p_13)));
            return g_992;
        }
        l_2742 = ((((p_13 , ((safe_div_func_uint16_t_u_u(((((safe_unary_minus_func_int64_t_s(g_2685)) ^ ((g_1973 ^ (safe_rshift_func_uint8_t_u_s((safe_add_func_int64_t_s_s((1L > (safe_lshift_func_int8_t_s_u((g_2725 && ((((safe_add_func_int32_t_s_s((safe_div_func_int8_t_s_s(0x65L, p_13)), ((safe_mod_func_int16_t_s_s((((((g_2685 ^ p_13) , 0L) == (-1L)) != l_2712) ^ l_2712), p_13)) , 1UL))) , 0x440C0DE7L) != g_156) != g_14)), l_2741))), l_2741)), l_2704))) == p_13)) , l_2712) <= g_156), p_13)) & (-6L))) == 0x6EBA3E6ED39236B8LL) < g_71) , 0x36F2CD99L);
    }
    else
    {
        l_2383 = 0x35CC7CACL;
    }
    return p_13;
}







static int16_t func_18(int32_t p_19, uint32_t p_20, uint32_t p_21, int32_t p_22, uint32_t p_23)
{
    int8_t l_1880 = 0xB6L;
    uint8_t l_1931 = 0xA1L;
    int8_t l_1950 = 0xD4L;
    int32_t l_1969 = 0x19CBB47BL;
    uint8_t l_2030 = 0x19L;
    if ((safe_mod_func_uint8_t_u_u((p_20 , p_21), p_21)))
    {
        int32_t l_1879 = (-1L);
        int64_t l_1881 = 0x75F31C714CE7EE57LL;
        uint16_t l_1954 = 1UL;
        uint64_t l_1972 = 18446744073709551607UL;
        if ((((safe_div_func_uint16_t_u_u((((8UL >= (((!(18446744073709551615UL && (safe_div_func_uint8_t_u_u((safe_div_func_uint8_t_u_u(p_21, g_72)), (safe_div_func_uint16_t_u_u(g_72, (safe_add_func_int16_t_s_s((((2UL > (((safe_lshift_func_int16_t_s_u((0xCEABL & (safe_sub_func_int8_t_s_s(l_1879, p_21))), g_81)) & l_1880) < p_20)) || g_1052) <= 0x033EL), g_100)))))))) , g_71) >= 0x181A2B8FL)) < p_21) < p_20), p_22)) != p_19) >= l_1881))
        {
            g_72 = (p_20 < (+p_20));
        }
        else
        {
            uint32_t l_1899 = 0xE4C75686L;
            uint8_t l_1900 = 0xE5L;
            int32_t l_1901 = 1L;
            uint64_t l_1955 = 18446744073709551615UL;
            if (g_926)
            {
                return p_22;
            }
            else
            {
                uint64_t l_1890 = 18446744073709551606UL;
                l_1901 = (safe_unary_minus_func_uint64_t_u(((((((0xC33DL > g_1052) == ((((safe_sub_func_uint64_t_u_u((p_20 & ((safe_rshift_func_uint8_t_u_u((((safe_div_func_int16_t_s_s((l_1890 >= (((safe_add_func_uint64_t_u_u((((p_19 , ((((0x7D23D42BL | (safe_sub_func_int16_t_s_s((safe_add_func_int8_t_s_s(l_1880, ((safe_rshift_func_uint16_t_u_s(((((((p_23 && p_19) < (-7L)) , l_1899) < l_1899) >= p_20) , 0UL), g_72)) | l_1880))), 0x64AFL))) | p_21) == p_20) | p_20)) , 2L) != 0x38L), l_1900)) | g_156) < g_100)), 0xDBD4L)) > 0L) , g_100), l_1890)) || g_81)), 8L)) == p_21) < l_1890) , l_1890)) >= l_1890) || g_1861) < 3L) <= 0xEF88L)));
                g_72 = ((~((safe_lshift_func_uint16_t_u_u((((p_19 || (safe_sub_func_uint32_t_u_u(l_1890, (((safe_mod_func_uint8_t_u_u((p_22 , (((g_926 >= ((+(((safe_add_func_int64_t_s_s(((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((~((safe_rshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(1L, (safe_rshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_int8_t_s((p_20 > (safe_rshift_func_int8_t_s_s((((((1UL | (((l_1881 , ((!p_20) | g_1052)) > g_1861) , g_71)) , g_156) > 1UL) <= 0x2DB8558BL) , 3L), 1))))), 5)), 0xE4EBEAB0L)), 9)))), 12)) , 0x3448L)) | g_100), 4)) ^ 0UL), 7)) , l_1881) , 0xCCC69F8E8B1B2C3ALL) < g_926), 8UL)) > 0L) & 0x2058B3B1L)) == 0x5A01A5FDL)) != p_19) , 255UL)), g_156)) & p_23) == l_1931)))) ^ l_1931) < g_992), 13)) , l_1890)) < p_19);
            }
            g_72 = (safe_rshift_func_int16_t_s_u(((safe_sub_func_int64_t_s_s(l_1900, ((((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int16_t_s_s((safe_div_func_int8_t_s_s(g_71, g_156)), 8)) && (safe_lshift_func_int16_t_s_s(p_19, ((safe_add_func_int8_t_s_s(0x6BL, (safe_lshift_func_int16_t_s_u(((2UL != l_1881) < (((g_926 && (-1L)) <= p_21) > 0x49L)), 11)))) , p_21)))), g_156)) == 0xE6F4E23CL) , g_71) || 1UL))) == p_19), l_1881));
            g_72 = ((((safe_sub_func_int32_t_s_s(0xE8CBBD7CL, 0xBF046BF3L)) && (l_1881 , (((l_1931 | l_1950) != g_81) && ((g_14 , (safe_lshift_func_int16_t_s_u(((l_1899 > (~((l_1954 ^ 1UL) != g_1861))) | l_1955), g_156))) <= p_23)))) || p_21) ^ p_22);
            return l_1879;
        }
        l_1969 = (safe_lshift_func_uint8_t_u_s(((p_21 || (g_72 >= (1UL & ((~((safe_rshift_func_int8_t_s_s(l_1931, 6)) , (safe_add_func_uint8_t_u_u((safe_div_func_int32_t_s_s((safe_div_func_int32_t_s_s((safe_mod_func_int8_t_s_s((p_23 && (p_21 | l_1879)), l_1931)), (((g_81 >= g_81) <= 0x346318E4164A0F22LL) | p_23))), 0x598D5EF2L)), l_1881)))) != 18446744073709551609UL)))) || 3UL), p_19));
        for (g_72 = 4; (g_72 != (-19)); --g_72)
        {
            g_1973 = l_1972;
        }
        l_1879 = 0L;
    }
    else
    {
        uint16_t l_1992 = 65534UL;
        int8_t l_1993 = 1L;
        int8_t l_2155 = 0L;
        uint16_t l_2174 = 1UL;
        uint8_t l_2175 = 0x26L;
        l_1993 = ((safe_mod_func_int16_t_s_s((((safe_lshift_func_uint8_t_u_s(((safe_add_func_int64_t_s_s(((safe_rshift_func_int8_t_s_u((g_14 ^ (0xFC17AA3BL != (safe_add_func_uint64_t_u_u((safe_add_func_uint32_t_u_u(((((p_23 || (p_20 && l_1969)) | p_19) < (((((p_22 ^ ((((((safe_unary_minus_func_int8_t_s((g_156 & (!(((((safe_lshift_func_int8_t_s_u((l_1969 == l_1992), p_19)) < 0x76DD4037L) , g_1052) || 0L) < l_1931))))) > l_1992) <= p_19) != p_22) , p_22) <= l_1992)) > g_1973) & l_1992) ^ l_1992) && p_20)) , p_20), l_1950)), 0xBEA3417187FBFED9LL)))), p_19)) ^ p_22), g_71)) | p_23), 5)) && g_14) >= l_1950), p_21)) == (-1L));
        for (l_1993 = 0; (l_1993 <= (-20)); l_1993--)
        {
            int32_t l_2003 = 1L;
            uint64_t l_2004 = 0xF04944464D784DECLL;
            int16_t l_2005 = 0xD1A7L;
            uint16_t l_2106 = 0x5CADL;
            int32_t l_2156 = 0x60DC2FBBL;
            l_2005 = ((safe_div_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(p_22, ((safe_add_func_uint8_t_u_u((~((((((3UL <= (p_22 >= (l_2003 <= g_14))) && g_1052) , 0x5BL) || (l_1993 || p_19)) > l_1992) == 0x9DF7FE43661B5DB1LL)), g_156)) , p_23))), g_59)) <= l_2004);
            for (g_992 = (-11); (g_992 == (-13)); g_992--)
            {
                int16_t l_2027 = 0L;
                int32_t l_2082 = 0xADA66357L;
                g_72 = (((((g_156 >= ((p_22 | (!l_2005)) < (safe_sub_func_int8_t_s_s((((safe_div_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s(l_1880, 1)), (((safe_add_func_int16_t_s_s((255UL >= (safe_add_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((1L | (safe_add_func_int8_t_s_s(l_1993, (p_19 && (0UL >= l_2027))))), 0xC40F9033L)), g_992))), l_2005)) != l_2027) ^ 0x919F63A7C79EC771LL))), g_14)) < l_1931) <= 0x99B8L), g_1861)))) < l_1931) < 0xF04C6C48L) >= 0xBF8EL) & 0xB204L);
                if (p_20)
                    continue;
                for (l_1969 = 0; (l_1969 >= (-29)); l_1969 = safe_sub_func_int64_t_s_s(l_1969, 5))
                {
                    uint32_t l_2035 = 0x6B18A170L;
                    if (l_2030)
                    {
                        uint32_t l_2040 = 4294967295UL;
                        int32_t l_2045 = (-1L);
                        l_2045 = (0L && (safe_lshift_func_int8_t_s_s((safe_div_func_int32_t_s_s((l_2035 || (safe_add_func_int8_t_s_s((4294967295UL <= ((((g_156 , (safe_sub_func_int8_t_s_s(p_23, ((((((l_2040 , (((((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s(65535UL, p_19)) < p_21), p_20)) >= g_992) > g_1052) != p_21) | g_81)) || l_1993) <= p_20) , p_21) == g_1052) & p_20)))) >= 0xE474L) , p_21) <= 0L)), l_2030))), l_2004)), 4)));
                        l_2045 = (0xA6CEL < ((safe_lshift_func_int16_t_s_s(p_22, 5)) , (l_2004 ^ ((safe_sub_func_int64_t_s_s(l_2040, (safe_div_func_uint64_t_u_u((~(safe_add_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((safe_sub_func_int32_t_s_s(l_2040, g_926)), p_22)) ^ (((((-1L) <= (safe_mod_func_int64_t_s_s(((((((safe_div_func_uint32_t_u_u((0x8FE316A3L <= l_2035), (-6L))) > 0x032DEC6F90D7DCAALL) , g_1052) , 0x2E15EBC8L) , l_2004) == l_1993), p_23))) , 0x2A520B2AL) != p_22) , g_100)), l_2005))), g_156)))) != g_72))));
                    }
                    else
                    {
                        uint8_t l_2105 = 1UL;
                        g_72 = (5UL <= (((4294967295UL < 0xBF13E5F5L) || ((safe_sub_func_int64_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_sub_func_int64_t_s_s((g_1861 && ((safe_div_func_uint8_t_u_u(((l_2035 > (safe_lshift_func_uint8_t_u_u((1UL >= (0x75BBL <= 1L)), 5))) && (((safe_mod_func_int8_t_s_s(0xE9L, p_19)) & g_926) > p_22)), g_81)) && p_19)), 0x24995109A2E2AE59LL)), 0)) < l_1931), p_19)) != l_2027)) <= g_926));
                        l_2082 = ((!g_59) , 0x625913D2L);
                        g_72 = (safe_lshift_func_int8_t_s_s(((g_81 == (((safe_rshift_func_int8_t_s_s(((((((safe_mod_func_uint32_t_u_u((((g_1052 , (safe_lshift_func_int16_t_s_u(p_19, 15))) , ((p_21 < ((safe_rshift_func_uint16_t_u_s(((safe_mod_func_int32_t_s_s((((safe_div_func_uint16_t_u_u((g_14 && (5UL ^ ((((safe_lshift_func_uint16_t_u_u((p_19 | ((safe_mod_func_uint16_t_u_u(((((l_2082 >= (safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int16_t_s_s(g_59, g_72)) ^ 0xBB1D64F0L), p_19))) >= p_23) && 0x0C403833L) <= p_19), g_100)) && l_1992)), 10)) , l_2105) < 1L) == 0x9CL))), g_72)) != p_21) , l_2106), l_1993)) || g_72), 0)) || g_1973)) , p_22)) ^ 0xC9DFL), p_19)) != 4L) <= g_81) ^ 0xF1FCL) && g_1861) | p_21), 5)) , g_926) > l_2027)) > g_1052), 7));
                    }
                }
                g_72 = (0x58F81519L | ((safe_div_func_uint64_t_u_u((g_100 > (safe_add_func_int64_t_s_s((safe_div_func_int32_t_s_s((((safe_sub_func_uint32_t_u_u(((p_20 || ((safe_sub_func_int32_t_s_s((+(((safe_rshift_func_uint8_t_u_s(g_1052, 2)) ^ (safe_div_func_int8_t_s_s(((((safe_div_func_uint64_t_u_u(((safe_add_func_int16_t_s_s(l_1880, ((l_2005 <= (safe_mod_func_uint64_t_u_u(((safe_mod_func_uint64_t_u_u(((((g_992 , ((((((safe_sub_func_int64_t_s_s(0xDDB97925A568715DLL, ((safe_rshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_u(p_19, p_22)), 6)) <= l_2027))) > l_2027) > 9UL) && 1L) < 0x3B39477AB508A852LL) ^ l_1969)) <= p_21) > g_156) ^ p_20), l_2004)) != p_22), g_81))) >= p_21))) & 0x96DC80B4AC7BE885LL), g_926)) || g_1052) == 0L) < g_1861), p_21))) , l_1931)), l_1969)) != g_926)) < l_2082), g_1973)) , 0x3BD1L) >= p_20), g_926)), l_2027))), p_23)) || l_2027));
            }
            g_72 = g_1973;
            for (g_1973 = 0; (g_1973 < (-29)); --g_1973)
            {
                l_2156 = ((safe_sub_func_uint32_t_u_u((g_156 > (((safe_sub_func_int16_t_s_s((-1L), ((((g_1861 && 4UL) && p_19) == (safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s(((0x465AF2C8DE94E1F0LL || (safe_unary_minus_func_int16_t_s((safe_div_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s(0x34L, g_926)) | (safe_add_func_uint8_t_u_u(0x90L, 1UL))), l_1992))))) == 0xEF11ECF862D3BE08LL), l_1992)) <= 0x76L) , 4294967286UL) , l_2106) >= 1L), l_2155))) , p_22))) && 18446744073709551608UL) , 0xDF07F3E6L)), l_1992)) ^ 2L);
            }
        }
        l_1969 = (safe_sub_func_uint16_t_u_u(((((safe_rshift_func_uint8_t_u_s(((safe_add_func_uint8_t_u_u((safe_mod_func_int64_t_s_s(((safe_sub_func_int64_t_s_s((-1L), (~(safe_add_func_int16_t_s_s((((safe_mod_func_int64_t_s_s((-7L), g_14)) > ((((((safe_div_func_uint8_t_u_u((l_1993 , ((((l_1992 < 0x7307L) > 0x5678FABFL) != ((g_71 == g_156) && 0UL)) | l_2155)), l_2030)) == p_22) <= 1L) ^ 1L) , 0xBE4730D6L) != 0x8007B6ECL)) >= l_2174), l_2155))))) != l_2175), l_1950)), (-3L))) >= g_81), l_1950)) >= p_19) , l_1880) , g_1052), l_2174));
    }
    return p_22;
}







static int8_t func_28(int32_t p_29, uint64_t p_30, uint32_t p_31, uint8_t p_32, uint8_t p_33)
{
    uint8_t l_664 = 249UL;
    uint32_t l_721 = 0x6FB6BC49L;
    int32_t l_725 = (-1L);
    int32_t l_774 = 0x7A75008BL;
    uint16_t l_871 = 65535UL;
    uint64_t l_894 = 0x79FDE5A4C0ACDB96LL;
    int64_t l_947 = 0x2E89F63837035CFALL;
    uint32_t l_1093 = 0x0743C8E5L;
    uint32_t l_1133 = 0x572B1976L;
    int8_t l_1161 = 0xF4L;
    uint64_t l_1276 = 0x332EA0415A9C7F79LL;
    int64_t l_1355 = 0L;
    uint32_t l_1614 = 18446744073709551615UL;
    int32_t l_1768 = 1L;
    int8_t l_1770 = 8L;
    uint8_t l_1845 = 0x93L;
    if ((g_14 > (l_664 , (safe_add_func_uint8_t_u_u((safe_sub_func_int16_t_s_s(((-1L) < (p_30 >= ((safe_lshift_func_uint8_t_u_u((((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((safe_add_func_int32_t_s_s((((safe_div_func_int64_t_s_s((safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(g_59, ((safe_rshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((safe_add_func_int64_t_s_s(((safe_rshift_func_int8_t_s_s(l_664, 6)) < p_32), ((safe_sub_func_int32_t_s_s((safe_add_func_int64_t_s_s((safe_div_func_int8_t_s_s((safe_mod_func_int16_t_s_s(p_29, g_72)), g_71)), g_72)), g_71)) , p_29))), g_156)), 3)) || 0xE993A4DEL))), g_81)), l_664)) , g_156) ^ 0L), g_72)), g_72)) <= g_81) > p_31), g_81)), p_33)) | g_156) && l_664), l_664)) && g_81))), g_72)), g_156)))))
    {
        return g_71;
    }
    else
    {
        int64_t l_705 = (-1L);
        uint16_t l_720 = 0UL;
        int32_t l_722 = 0x90DEB2BAL;
        int32_t l_815 = 0xF7EF7079L;
        uint32_t l_883 = 18446744073709551607UL;
        l_722 = (safe_add_func_uint32_t_u_u((safe_div_func_int64_t_s_s((p_33 , (l_705 ^ (((safe_lshift_func_int8_t_s_u(((safe_add_func_uint8_t_u_u((p_31 , ((((safe_sub_func_int64_t_s_s(l_705, (l_705 & 3UL))) & (safe_sub_func_uint32_t_u_u(((((p_31 <= (safe_mod_func_int64_t_s_s(((0x3707L ^ (((safe_lshift_func_uint16_t_u_u((((safe_lshift_func_int8_t_s_u(p_29, p_31)) == p_29) , l_664), p_30)) != l_705) > l_664)) , p_31), p_29))) || g_156) >= l_705) & p_30), l_720))) >= g_14) , 0x77L)), l_664)) & l_721), p_30)) > g_156) , l_664))), p_31)), l_664));
        l_725 = (safe_add_func_int64_t_s_s(g_71, g_100));
        if ((safe_div_func_uint32_t_u_u(l_705, l_725)))
        {
            int64_t l_728 = 0x4C3AB64E59935328LL;
            int32_t l_729 = 1L;
            int8_t l_817 = 0xB0L;
            uint8_t l_843 = 255UL;
            int32_t l_895 = 0xD8FE94F1L;
            if (g_71)
            {
                l_728 = p_32;
                g_72 = 0xE74276C7L;
                l_729 = 1L;
            }
            else
            {
                uint8_t l_750 = 1UL;
                int64_t l_751 = 5L;
                int32_t l_844 = 0L;
                l_729 = (g_81 , (safe_rshift_func_uint16_t_u_s((p_33 & (safe_mod_func_int8_t_s_s(0xF1L, (safe_add_func_uint16_t_u_u(l_729, 8L))))), 2)));
                g_72 = (safe_mod_func_int32_t_s_s((safe_div_func_uint64_t_u_u((safe_div_func_uint8_t_u_u(((l_721 == (l_722 , (safe_rshift_func_int16_t_s_u(g_81, g_100)))) ^ g_72), 0x3AL)), (safe_div_func_uint32_t_u_u((safe_mod_func_uint64_t_u_u((((((g_71 > p_32) & ((safe_sub_func_int64_t_s_s(((((g_59 >= l_750) != l_750) , l_750) | p_31), 0x1A2C8E1978DEEFCALL)) <= l_728)) <= 0xDF0CABE6L) , 0x1304D4EBL) , p_31), l_725)), l_751)))), g_71));
                if (p_30)
                {
                    uint64_t l_777 = 18446744073709551615UL;
                    int32_t l_785 = 2L;
                    g_72 = ((1UL ^ (0xACD3L & (safe_lshift_func_int8_t_s_s((l_729 , (safe_sub_func_int16_t_s_s((((((g_71 == (((safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((safe_div_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_add_func_uint16_t_u_u((~0x02796A0AL), (p_33 == p_31))) < (((((safe_lshift_func_int16_t_s_s(l_664, (safe_mod_func_uint16_t_u_u(((((!(safe_sub_func_int32_t_s_s(((l_720 | l_774) && l_725), 1UL))) > 0x5FAC56BDEB9DEE37LL) > 0xBFD9L) >= g_14), 0xD64EL)))) ^ p_29) > g_71) && 0L) , l_722)), g_59)) || (-7L)), p_31)), g_71)), p_32)) != g_72) >= 0xB1F7L)) | p_31) & 0UL) , 0x3BL) | g_71), 65528UL))), 5)))) | 0x28L);
                    for (l_751 = (-25); (l_751 >= (-10)); ++l_751)
                    {
                        uint16_t l_784 = 0x8E4DL;
                        g_72 = g_81;
                        l_722 = g_14;
                        l_785 = (l_777 || (((g_71 > ((safe_rshift_func_int16_t_s_u((g_14 > l_751), ((safe_add_func_int32_t_s_s(p_29, (((safe_mod_func_int64_t_s_s(1L, (p_30 , ((-1L) | ((((((g_59 || g_156) < p_29) > p_33) <= p_30) , 9L) | l_725))))) <= l_728) >= l_784))) , g_72))) , (-1L))) >= g_71) < p_32));
                    }
                }
                else
                {
                    uint32_t l_816 = 18446744073709551615UL;
                    l_729 = (safe_add_func_int8_t_s_s((safe_div_func_int8_t_s_s((((((safe_lshift_func_int8_t_s_s((safe_sub_func_int64_t_s_s(g_100, 0xCDD9D3AB9065EC86LL)), (((g_72 ^ ((((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_s((((safe_add_func_int64_t_s_s(((safe_add_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u(((0x6955L == (safe_lshift_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u((safe_div_func_int32_t_s_s(((((safe_rshift_func_uint16_t_u_s((((255UL > ((safe_sub_func_int32_t_s_s(6L, (l_815 < ((((l_705 > 0x0EL) ^ g_59) ^ g_71) != g_59)))) != g_72)) , 18446744073709551608UL) >= g_156), 9)) < g_81) ^ p_32) >= l_816), 1UL)), l_705)) & g_72) || l_817) >= 0x16L), 14))) ^ g_81))), 65527UL)) ^ g_81), g_59)) >= 0x5E147F8AL) , 0xA2F3L), 2)) , p_33), 7)) & l_728) < g_156) ^ g_81)) > l_750) | g_59))) > g_72) , g_72) < g_156) , 0x05L), l_721)), l_725));
                    l_729 = (l_720 , (safe_add_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(((p_30 == (p_33 , (safe_sub_func_uint8_t_u_u((((safe_div_func_uint16_t_u_u(((+g_72) && ((safe_div_func_int16_t_s_s((((p_32 > ((safe_add_func_int32_t_s_s(((((safe_div_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(g_71, ((g_71 & l_722) && (((safe_mod_func_uint32_t_u_u((safe_div_func_uint32_t_u_u((safe_mod_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_u((g_156 , 0xAE76L), l_721)), g_14)), 0x9B98E884L)), g_156)) > p_33) >= (-10L))))), g_72)) , 4294967286UL) | 0x01A1E7A2L) >= p_30), 0xC7CF90CBL)) | 0x2FC7EE2F9BF05AA9LL)) ^ l_750) , l_843), l_720)) && g_14)), l_750)) , 0L) > g_81), l_750)))) , g_156), l_844)), (-4L))));
                    g_72 = g_156;
                    l_725 = p_32;
                }
            }
            for (g_156 = (-26); (g_156 >= 52); g_156 = safe_add_func_int16_t_s_s(g_156, 9))
            {
                g_72 = ((safe_add_func_uint8_t_u_u(g_71, (((p_30 , (3L && (safe_div_func_int8_t_s_s((p_30 <= (g_81 < (safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s(((((g_81 > p_31) < l_722) < g_71) , 1L), g_72)), p_31)))), 0xB6L)))) != l_843) , g_14))) | g_71);
                l_722 = g_100;
                g_72 = ((0xF2L | ((((((((safe_rshift_func_uint8_t_u_s(0xF6L, (safe_add_func_int32_t_s_s((+((((g_72 == (safe_rshift_func_uint16_t_u_s(p_30, 2))) , ((-1L) < ((((safe_div_func_uint16_t_u_u(((((~g_72) & g_81) ^ ((p_29 || (safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(l_721, 6)), 4))) != (-4L))) == 0x5795A7F01DB3673DLL), l_729)) && 1L) , l_871) == 4294967293UL))) & p_32) >= g_72)), 0xA7DD806EL)))) < 1L) , g_81) | l_728) >= 0x6EL) == p_33) < g_81) && 0UL)) < p_30);
            }
            g_72 = (safe_mod_func_uint32_t_u_u((((safe_div_func_int8_t_s_s(((l_705 && (safe_div_func_int8_t_s_s((safe_sub_func_int8_t_s_s((((((safe_mod_func_uint8_t_u_u((((+((p_30 , l_883) | (((0UL && ((((p_30 > (safe_div_func_int8_t_s_s((safe_sub_func_int16_t_s_s((p_30 ^ p_33), (safe_sub_func_int8_t_s_s(0L, ((((((safe_rshift_func_int8_t_s_s(((((safe_sub_func_int32_t_s_s(g_59, l_722)) == p_29) ^ (-10L)) , (-1L)), l_894)) , 0x247691C875D53896LL) , l_895) || g_156) < p_29) | p_32))))), g_59))) == 9UL) & l_728) || l_725)) | g_14) < 0xDBCF38BDL))) == 0x5BL) , l_720), (-1L))) , p_33) >= p_30) , 18446744073709551615UL) | p_29), (-1L))), g_72))) , 0L), p_30)) , l_721) >= g_59), l_729));
            g_72 = l_883;
        }
        else
        {
            uint8_t l_927 = 0xE4L;
            g_72 = (((g_14 < (safe_unary_minus_func_int32_t_s(((safe_div_func_int8_t_s_s(l_883, (safe_lshift_func_uint16_t_u_s((safe_add_func_uint64_t_u_u(g_156, 0x5CE3714CE949701CLL)), p_29)))) | (4294967294UL | (safe_div_func_uint16_t_u_u((((safe_mod_func_int64_t_s_s((safe_div_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(0x1BDC75A9L, ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_uint8_t_u_u((((((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(p_31, (((safe_mod_func_uint64_t_u_u(((((safe_mod_func_int64_t_s_s(((safe_sub_func_int16_t_s_s((((0L > 0x93L) | g_81) , p_30), l_871)) < 0xED44L), p_33)) && 0xBAF1DDFFL) , 0x5A9972EDL) == p_31), g_59)) && p_33) == l_883))) , g_926))) , g_71) , l_927) | 0x37L) , p_33), 0x05L)) <= p_30) , 1UL) != l_774), (-5L))) >= 0UL))) , 0x778DL), l_720)), g_156)) || g_72) , p_33), l_927))))))) ^ g_71) && 0xE9L);
            return g_59;
        }
    }
    for (g_926 = 29; (g_926 < 56); ++g_926)
    {
        uint32_t l_930 = 7UL;
        int32_t l_931 = (-1L);
        int32_t l_945 = 0x2BEADB23L;
        int16_t l_946 = 0x4A26L;
        uint8_t l_962 = 254UL;
        uint64_t l_1070 = 0xA6D968D73D9F9330LL;
        uint8_t l_1612 = 0xDDL;
        uint32_t l_1615 = 0x23B70104L;
        uint64_t l_1680 = 18446744073709551615UL;
        uint16_t l_1775 = 0xF8F1L;
        l_931 = (g_14 & l_930);
        l_946 = ((g_59 <= l_931) | ((g_100 , ((((safe_sub_func_int16_t_s_s((safe_div_func_int32_t_s_s((((safe_add_func_int32_t_s_s(((248UL < (0xAEL <= ((g_72 & (safe_lshift_func_int8_t_s_u(((safe_div_func_uint8_t_u_u(p_31, 0x2FL)) ^ (!(((safe_sub_func_int32_t_s_s(l_945, l_930)) < 0x3FDCL) , g_81))), 4))) ^ l_774))) , 0x0343E425L), l_931)) , g_156) < l_871), 0xF3EFBD92L)), 0xAFFCL)) == 0xB5L) , 0x75EFF282264537E7LL) != p_33)) <= p_33));
        if ((p_33 <= (((p_31 ^ (l_947 , (safe_add_func_int32_t_s_s((((safe_rshift_func_int16_t_s_s(((!l_871) , p_31), 2)) >= (g_59 >= p_29)) == (safe_div_func_int16_t_s_s((safe_add_func_int8_t_s_s((+(safe_add_func_uint8_t_u_u(1UL, (-1L)))), p_32)), p_32))), g_72)))) < p_32) != l_946)))
        {
            uint64_t l_978 = 0xDCC4B6A2B552FCEDLL;
            int32_t l_979 = (-7L);
            uint64_t l_1021 = 0x3A4B7B9043159349LL;
            uint16_t l_1108 = 0xEE39L;
            uint64_t l_1292 = 0xE357E6A64CBA3E00LL;
            for (l_664 = 0; (l_664 == 28); l_664 = safe_add_func_int16_t_s_s(l_664, 5))
            {
                g_72 = l_962;
                for (g_71 = 21; (g_71 <= 48); g_71 = safe_add_func_uint32_t_u_u(g_71, 8))
                {
                    uint32_t l_967 = 0x1460EC7FL;
                    int16_t l_977 = (-6L);
                    g_72 = ((p_31 || (safe_lshift_func_uint8_t_u_u(251UL, g_926))) , ((((l_664 >= l_967) == (g_59 | g_71)) | (g_926 >= 1UL)) , g_72));
                    l_725 = (g_926 < ((safe_mod_func_uint64_t_u_u((p_32 && (g_81 != (((((p_29 & (safe_add_func_int64_t_s_s(g_14, (safe_unary_minus_func_uint32_t_u(l_721))))) , (g_156 && (safe_mod_func_int16_t_s_s((p_31 & (safe_div_func_int16_t_s_s((g_14 , 0L), (-5L)))), g_59)))) , p_31) | l_977) < 4294967295UL))), l_967)) < 1L));
                    l_978 = 0x08157C56L;
                }
                l_979 = l_930;
            }
            if ((((p_33 ^ 0xC48FBAFE1FC0A3F5LL) == ((((l_978 > g_156) | (safe_rshift_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_s(p_31, 2)) , (safe_sub_func_int64_t_s_s((((safe_div_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((((l_978 && (((((p_30 , (safe_div_func_uint16_t_u_u(p_31, g_156))) ^ 0UL) & l_930) <= 1UL) <= p_32)) >= l_945) > 0x4FE8095E9CFFED73LL), l_721)), 0x10L)) && g_71) >= l_946), g_992))), 5))) >= l_979) <= g_81)) ^ p_31))
            {
                int32_t l_1000 = 4L;
                l_931 = ((((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint8_t_u_u((((safe_sub_func_int16_t_s_s((((((safe_add_func_int64_t_s_s(p_31, ((l_1000 == ((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u(7UL, l_1000)), 12)) & (((safe_lshift_func_int16_t_s_u(((safe_div_func_int64_t_s_s(((safe_div_func_int8_t_s_s(g_59, (safe_rshift_func_uint8_t_u_u((((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int16_t_s_u((((l_931 < (safe_add_func_uint64_t_u_u(l_979, l_1021))) ^ (((safe_mod_func_uint8_t_u_u(0x26L, 0x47L)) == g_14) >= (-4L))) >= 0L), p_31)) != g_71), 8)) != g_59) , l_978), l_1021)) & g_992) >= g_59), 4)))) || p_30), 0x5210661155156C69LL)) ^ p_31), 9)) < g_59) && g_71))) > g_992))) , 0x48E73E2B48A80922LL) != g_71) , 0xF3D7FC76E48FBA56LL) , g_156), 1L)) >= l_894) & g_81), g_992)))) > p_33) < 0x8E888D9AL) , p_32);
                if (p_31)
                    break;
            }
            else
            {
                int16_t l_1033 = 4L;
                int8_t l_1042 = 7L;
                int32_t l_1112 = (-7L);
                uint32_t l_1277 = 18446744073709551607UL;
                if ((safe_add_func_int8_t_s_s(l_947, 252UL)))
                {
                    uint8_t l_1043 = 0xB1L;
                    int32_t l_1089 = 0x4E3982B8L;
                    g_72 = (safe_unary_minus_func_int8_t_s((safe_lshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_add_func_int32_t_s_s(l_1033, ((+(safe_mod_func_uint32_t_u_u(((((!((0L <= g_926) || 65527UL)) == (p_31 > (safe_lshift_func_uint16_t_u_s(((-7L) | (l_946 , l_1021)), (g_926 != g_14))))) || p_32) , g_72), l_1042))) < g_59))), g_926)), l_1043))));
                    for (l_871 = 6; (l_871 < 42); ++l_871)
                    {
                        g_72 = (safe_add_func_uint64_t_u_u((safe_lshift_func_int8_t_s_s(((p_32 <= (l_1033 , (safe_lshift_func_int8_t_s_s((g_1052 , l_962), 1)))) < ((safe_unary_minus_func_int8_t_s(l_1043)) >= (((safe_div_func_int8_t_s_s(((((safe_lshift_func_uint8_t_u_u(((~(((p_30 > ((((safe_add_func_int8_t_s_s((safe_add_func_uint64_t_u_u((((safe_mod_func_uint32_t_u_u((l_979 , (((safe_unary_minus_func_uint16_t_u(p_33)) < (safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((g_156 , 1L) < 0xD9E8L) ^ p_33), g_1052)), 0x4A10A23038FE283CLL))) , g_14)), (-9L))) , l_1043) , l_1070), l_1042)), g_926)) >= 0UL) || 0xD8A3D08F8BA47D60LL) || l_1043)) , 4UL) > l_664)) == g_81), g_72)) , l_1043) <= p_30) | 0L), 0x9BL)) < 251UL) & g_156))), l_930)), 7L));
                        if (l_931)
                            continue;
                        l_931 = (l_1042 , p_31);
                    }
                    for (l_871 = (-20); (l_871 >= 3); l_871++)
                    {
                        int64_t l_1088 = (-6L);
                        l_1089 = ((safe_lshift_func_uint16_t_u_s(((1L | l_1070) & (!(safe_add_func_int32_t_s_s(g_1052, ((safe_add_func_int16_t_s_s(p_32, (safe_mod_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((((safe_sub_func_int16_t_s_s(((((p_29 ^ (safe_sub_func_uint8_t_u_u((((0xDFED1ABAF480FDA3LL <= (((((g_72 > (-1L)) == (g_59 >= g_14)) | p_31) < l_978) <= p_31)) , l_1088) && p_32), p_32))) && 18446744073709551609UL) , 0x6A83L) && p_31), p_29)) | p_30) | l_725), 2)) >= l_962), l_947)))) , p_32))))), 10)) <= g_81);
                        g_72 = ((((((p_29 < (~(safe_sub_func_uint16_t_u_u((g_81 < g_81), (((l_1088 | (((l_1093 , g_59) && (g_59 || 0x7409D52CD83A8A31LL)) , (65526UL <= l_947))) && g_71) , l_979))))) > p_29) || 254UL) < 2UL) , p_32) < 255UL);
                        g_72 = ((((-8L) & ((l_979 >= (((p_32 > ((safe_rshift_func_uint16_t_u_s((safe_sub_func_int64_t_s_s(((((p_32 <= (((safe_div_func_uint32_t_u_u((safe_mod_func_int64_t_s_s((g_156 == (((safe_sub_func_uint8_t_u_u((p_32 > (((safe_div_func_int16_t_s_s(9L, ((g_14 > (((safe_sub_func_uint16_t_u_u(p_32, (-10L))) < (-2L)) != (-1L))) , l_1033))) ^ g_992) , p_32)), p_31)) || p_33) , 1UL)), g_926)), p_29)) >= l_1043) , 0xC4655D9CDE0472C3LL)) != g_59) | 0x56388EEAL) ^ l_1070), g_72)), g_992)) || g_926)) & p_32) | 1L)) && 7UL)) , l_930) ^ g_156);
                    }
                    l_1108 = (l_1033 >= l_1042);
                }
                else
                {
                    uint8_t l_1126 = 0UL;
                    int64_t l_1134 = (-5L);
                    uint8_t l_1160 = 1UL;
                    int32_t l_1171 = 6L;
                    for (l_946 = 22; (l_946 != 23); l_946++)
                    {
                        uint32_t l_1147 = 18446744073709551607UL;
                        l_1112 = (~65533UL);
                        l_1112 = (safe_lshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s((((+1L) == (((safe_rshift_func_int16_t_s_u(((safe_div_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_s(((0x8015L > 0x7296L) || ((l_1126 == ((((l_1112 && ((((safe_mod_func_uint32_t_u_u(((g_14 & ((safe_lshift_func_int16_t_s_u((((0x9CL & (((g_71 == (safe_mod_func_int64_t_s_s((g_992 && 1UL), 0xC66A19F54C33D59BLL))) > 0x57L) && p_29)) >= 0UL) | 0xD9L), g_156)) < g_156)) == g_72), g_1052)) > g_72) >= g_926) , p_29)) ^ g_1052) <= 0x9AEBB28ECB9E14F9LL) > g_59)) >= 4294967289UL)), p_29)) & 5L), l_979)) == p_30), l_894)) | l_1133) & l_1134)) == 4294967287UL), l_871)), p_33));
                        g_72 = ((safe_lshift_func_uint8_t_u_s((((safe_div_func_uint8_t_u_u(((((g_1052 , ((p_29 || (safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s((g_992 == (safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((l_1147 <= (safe_sub_func_uint16_t_u_u(((safe_div_func_int16_t_s_s((l_1147 || ((safe_rshift_func_int16_t_s_s(g_926, 8)) , (((((safe_rshift_func_uint16_t_u_u(p_31, (safe_div_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((p_32 , ((l_664 , 0UL) > p_31)), (-5L))), l_1160)))) != p_32) <= g_14) != g_156) , p_29))), g_72)) , l_1108), g_156))), 2)), l_1161))), l_1021)), 1L))) , l_1112)) , p_30) ^ l_721) || (-2L)), l_1108)) < g_81) | l_978), p_29)) > g_72);
                        l_1171 = (((safe_unary_minus_func_uint64_t_u(18446744073709551611UL)) , ((g_156 == ((((((2UL == (0x4FL || (safe_add_func_uint8_t_u_u(g_72, ((safe_rshift_func_int8_t_s_s(l_931, 2)) ^ 0xD9L))))) == (safe_mod_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(p_33, p_33)), 65535UL))) & l_947) , l_1147) < g_59) >= l_1147)) || g_81)) >= l_1033);
                    }
                    for (l_947 = 24; (l_947 != 22); l_947--)
                    {
                        int32_t l_1180 = (-1L);
                        l_1171 = (safe_mod_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_u(p_29, (safe_sub_func_uint16_t_u_u(l_1160, g_72)))) < ((((p_33 || ((g_81 & (((0x8342L < (p_31 > p_29)) >= (p_31 | g_992)) ^ g_992)) || l_1108)) , 0UL) & 0xCBL) , l_946)) & l_1180) < p_33), (-5L)));
                        g_72 = l_1161;
                        l_725 = 0L;
                    }
                    for (l_871 = (-29); (l_871 != 15); l_871 = safe_add_func_uint64_t_u_u(l_871, 8))
                    {
                        return l_1171;
                    }
                    if (((((0x69A9F0C58EB58727LL & ((safe_unary_minus_func_int64_t_s((safe_sub_func_int8_t_s_s(l_1033, ((safe_rshift_func_int16_t_s_s((safe_mod_func_uint64_t_u_u(g_926, (safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_int64_t_s(l_1112)), (safe_lshift_func_int16_t_s_u((safe_mod_func_uint32_t_u_u(((((0xEF367376L ^ (safe_rshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((((((safe_sub_func_uint8_t_u_u(((safe_mod_func_uint16_t_u_u(0UL, l_1112)) == (+0xFF6C0BA6L)), (((safe_sub_func_uint16_t_u_u((safe_add_func_int64_t_s_s((safe_add_func_int16_t_s_s((0x9EL > 0x70L), g_926)), g_72)), g_100)) > p_33) > 0x1A12508C236650BFLL))) ^ l_978) == 8L) == g_59) , g_1052) , g_81), l_1112)) == l_947), g_72)) < g_992), 7))) <= p_30) < g_71) == l_1134), 0x7C52708BL)), 14)))))), g_59)) , p_29))))) < l_945)) , g_926) , 0x2AA4060C6A31C229LL) == g_156))
                    {
                        int64_t l_1237 = 0L;
                        g_72 = (safe_sub_func_uint16_t_u_u(p_32, (safe_div_func_uint32_t_u_u(((((((safe_rshift_func_uint8_t_u_s(g_926, 5)) , (safe_mod_func_uint32_t_u_u((0x5E2AL < (safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_u(((p_33 | ((l_1134 >= (safe_sub_func_int32_t_s_s(((safe_sub_func_int64_t_s_s(((safe_lshift_func_int8_t_s_u(0L, 5)) ^ (safe_mod_func_int16_t_s_s(((~(((safe_lshift_func_uint16_t_u_s(((-9L) & 246UL), p_29)) , 4294967286UL) < 0x9C14A922L)) == g_926), 0xD639L))), l_1237)) && 0UL), g_72))) <= l_1237)) <= g_72), p_33)), 6))), (-1L)))) == l_1237) > 65528UL) | l_1021) , p_30), 7L))));
                    }
                    else
                    {
                        int64_t l_1250 = 0x259CE1B060E08864LL;
                        l_979 = ((safe_unary_minus_func_int16_t_s(g_926)) , (0L && 1UL));
                        l_1250 = ((safe_add_func_int8_t_s_s((p_31 != (((safe_mod_func_uint64_t_u_u(0x9D7E15882AE87DF1LL, ((safe_sub_func_int8_t_s_s(g_1052, (safe_add_func_uint32_t_u_u(p_32, 0x8FDFED9DL)))) || (l_1033 , (safe_div_func_uint32_t_u_u(0x5DB0E0E0L, ((!(-8L)) , l_930))))))) && g_100) != p_33)), 0x25L)) || p_33);
                    }
                }
                l_725 = (((safe_mod_func_uint64_t_u_u((safe_sub_func_uint8_t_u_u(l_1042, (safe_rshift_func_uint16_t_u_s(6UL, g_100)))), ((safe_lshift_func_int8_t_s_s(((0L != ((safe_div_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((safe_div_func_uint8_t_u_u((((safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u((p_31 | (safe_lshift_func_uint16_t_u_s((safe_mul_func_uint32_t_u_u(p_33, ((g_156 , 253UL) , (!(safe_rshift_func_int8_t_s_u(0x71L, 2)))))), l_962))), l_931)), p_32)) , 6UL) <= 7UL), l_978)), (-1L))), l_931)) != 0x9CDABB09FDB2A2CELL)) < l_1276), l_1276)) & 0xA4C1BD83BC9E5044LL))) & l_1021) , p_30);
                l_1112 = (l_1277 != (safe_rshift_func_int8_t_s_s(0x07L, (safe_add_func_int32_t_s_s((l_947 || ((safe_mod_func_int64_t_s_s(p_30, ((safe_sub_func_uint16_t_u_u(((g_926 >= (safe_sub_func_uint32_t_u_u((l_774 >= 0xB50FL), (((1UL || ((0UL && p_33) > l_1070)) >= p_31) | 0L)))) <= p_31), p_30)) || g_81))) == p_30)), 0x7F220186L)))));
            }
            l_979 = (safe_mod_func_int32_t_s_s(l_1292, ((safe_add_func_int16_t_s_s(p_31, ((((p_30 > ((safe_unary_minus_func_int8_t_s((safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(p_29, (((safe_sub_func_int64_t_s_s(g_100, (g_1052 < (((!(p_32 & (safe_lshift_func_uint8_t_u_s((safe_mul_func_uint64_t_u_u((safe_rshift_func_uint8_t_u_u(l_871, 1)), ((0x35L > 0UL) != 8L))), 6)))) <= g_59) || 0xA2L)))) & p_30) <= 0x69B69080L))), p_29)))) <= 0x73L)) | l_1093) | g_72) || p_33))) & p_32)));
            g_72 = ((((p_29 != (safe_sub_func_int32_t_s_s(((((0x18D37A08L == (+((((((p_30 & (0L & p_31)) == (safe_add_func_int8_t_s_s(((safe_mod_func_uint32_t_u_u(((p_29 > (safe_add_func_uint8_t_u_u((((((l_945 != (((g_71 ^ ((7L >= l_979) > 0x3B2608B29F4FD807LL)) > g_59) , p_30)) & p_29) && g_14) > 1L) > g_71), 0x7DL))) < 0xE1D89CC8L), l_1108)) | 0xD4L), g_992))) & l_945) , (-5L)) & p_29) | 0x5A223DDBL))) > l_1021) || (-1L)) & g_81), p_30))) != l_894) && g_71) && 0xDD4AL);
        }
        else
        {
            int8_t l_1353 = 0xDFL;
            uint16_t l_1354 = 0x5E80L;
            uint32_t l_1458 = 0x6506550FL;
            int32_t l_1485 = (-1L);
            int16_t l_1591 = 0xCD6DL;
            uint16_t l_1632 = 0x3510L;
            if (g_1052)
            {
                int8_t l_1358 = 0x0DL;
                int32_t l_1388 = 0x5B68FB46L;
                int32_t l_1513 = 0xAA43D093L;
                for (l_1161 = 0; (l_1161 == (-25)); --l_1161)
                {
                    int8_t l_1352 = 0x70L;
                    int32_t l_1363 = 1L;
                    if ((1UL ^ (0x960CL | (((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((safe_div_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_u(0xEC20L, (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s((((safe_sub_func_int8_t_s_s(p_29, (((safe_lshift_func_uint8_t_u_u((((((safe_sub_func_int8_t_s_s(g_100, ((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s(p_31, (((safe_div_func_uint64_t_u_u((safe_sub_func_int32_t_s_s(((-1L) <= 0x72BE0656L), g_72)), l_1352)) <= 0x0AB1L) == 1UL))), 0UL)) > 0x03L))) ^ p_30) , g_156) , 0x53547D557EB57D4DLL) >= 0L), l_1133)) > l_774) , l_1353))) && l_774) && 65535UL), 3)) & 5L), l_1354)))) || p_31) && l_1355) , 0x306BL), 6)), l_1352)), g_81)), p_32)) != p_30) , 0x0C2AL))))
                    {
                        g_72 = 1L;
                    }
                    else
                    {
                        l_1363 = (((safe_div_func_int8_t_s_s((((0x7352L & (g_100 >= l_1161)) | ((l_1358 , (safe_sub_func_uint64_t_u_u(((((g_926 || g_81) >= ((((g_72 & ((((safe_div_func_int32_t_s_s(((l_1353 , (g_72 != g_926)) <= g_1052), l_1352)) < 0xF5DAL) || p_30) >= l_1352)) && g_71) <= 0xD82FL) , p_33)) < p_29) != l_1354), p_29))) <= g_71)) != g_72), p_29)) , p_31) ^ p_32);
                    }
                    l_1388 = ((safe_mod_func_int32_t_s_s((((safe_lshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_s((safe_div_func_int64_t_s_s((safe_rshift_func_uint16_t_u_u(l_930, 14)), ((safe_add_func_int64_t_s_s((g_1052 >= (p_29 > (((p_30 , (-1L)) , ((((((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_s(p_31, 0)), 2)) , ((safe_mod_func_int16_t_s_s(((g_72 >= ((safe_add_func_int32_t_s_s(((safe_add_func_uint16_t_u_u(0xE617L, (safe_lshift_func_uint16_t_u_s(l_1133, g_72)))) > l_1352), g_100)) > p_33)) && 4L), p_31)) , p_33)) | p_33) , (-5L)) < p_32) , 249UL)) != g_81))), g_156)) , l_774))), l_1358)), 1)) , p_30) ^ 8UL), 1L)) , 6L);
                }
                if (l_1354)
                {
                    int8_t l_1406 = 0xCDL;
                    int32_t l_1484 = 2L;
                    if ((0x418BE3E6L < (((safe_lshift_func_int16_t_s_u((g_1052 >= (((safe_lshift_func_uint8_t_u_s(((safe_div_func_int8_t_s_s((p_32 & (safe_sub_func_uint16_t_u_u(g_59, (g_71 && (((safe_rshift_func_uint16_t_u_u(((((safe_div_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((l_1354 && l_1388), ((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s(l_1406)), 65532UL)) , (-6L)))), g_156)) , l_1353) , p_29) >= p_31), p_29)) , l_962) >= 3L))))), 0x5FL)) < l_1358), p_30)) | l_894) != p_29)), g_992)) >= g_14) > (-8L))))
                    {
                        uint64_t l_1467 = 0xD5012EE18EAD400ALL;
                        l_725 = (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_div_func_int8_t_s_s(g_926, (safe_add_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u(9UL, 3)) , (((((safe_rshift_func_int8_t_s_u(p_32, 2)) == (safe_add_func_uint16_t_u_u((((safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(4294967290UL, (safe_lshift_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u(((0xB0L == ((((((safe_div_func_uint16_t_u_u(0xF47DL, ((0xA659F79DC95E2F39LL >= ((((((safe_lshift_func_uint16_t_u_u((safe_add_func_uint64_t_u_u((((safe_sub_func_int32_t_s_s((safe_div_func_uint32_t_u_u((((safe_sub_func_uint8_t_u_u((((l_1070 == g_81) || 0xBE56L) <= 1UL), p_32)) , 0x92FDL) , g_72), g_1052)), 0x8812025DL)) == 0x37B13E3BE497CC75LL) || g_926), 0xBB10C27D3E9F52A6LL)), p_29)) <= g_992) <= 0L) <= p_31) && p_33) < p_30)) & l_946))) != g_81) , g_100) < g_72) <= p_30) & 0x9C88L)) == p_31), 0xDFL)) | l_1358), 11)))) == (-1L)), g_59)) == g_926) >= l_1406), p_30))) , g_1052) > g_992) , p_29)) , p_32), 0L)))) && 4294967292UL), l_945)) == 0UL), g_59)) && g_100), 6));
                        if (p_30)
                            continue;
                        l_931 = ((safe_mul_func_int64_t_s_s(l_1354, ((((((((((safe_lshift_func_int8_t_s_s(p_31, ((((-1L) > (((safe_sub_func_uint32_t_u_u(((g_156 & (safe_mod_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((!(0xC9E3B605E05F4888LL || ((l_1458 < ((-4L) <= ((safe_rshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((0xDEE58B38L > (safe_lshift_func_int8_t_s_s((safe_add_func_int8_t_s_s(l_1458, 0x94L)), 2))), p_31)), 5)) == l_894))) | l_1358))) != 65533UL) >= 0L), 0xDB00L)) < 9UL), 6L))) < l_1388), p_33)) | l_1354) & l_1458)) < l_1354) , l_1467))) >= g_72) <= (-5L)) == 1L) != l_1458) & g_926) == (-3L)) | p_33) == p_31) > g_1052))) != l_1467);
                    }
                    else
                    {
                        uint8_t l_1481 = 0x63L;
                        l_1484 = (safe_add_func_int32_t_s_s(g_100, ((safe_mul_func_int64_t_s_s(((l_1388 ^ ((((((((safe_sub_func_int8_t_s_s(7L, ((l_1388 != (((0x2A85133BL > (safe_lshift_func_int8_t_s_s(g_81, (safe_sub_func_uint8_t_u_u(1UL, ((((~l_1481) | (safe_div_func_uint8_t_u_u((g_71 , l_1481), g_992))) >= p_33) || l_1481)))))) == 0x7566L) == p_29)) , p_30))) && g_59) != 0xB7F732B3L) != l_1354) >= 0x898C017DL) ^ 0x4CE933CEL) && 4294967295UL) | p_29)) <= l_1481), 0L)) < l_962)));
                        g_72 = (-6L);
                        l_1485 = (-5L);
                    }
                }
                else
                {
                    for (l_664 = (-18); (l_664 > 23); ++l_664)
                    {
                        int64_t l_1514 = (-1L);
                        g_72 = ((safe_add_func_int8_t_s_s(((((!p_31) == (safe_div_func_uint16_t_u_u((((-1L) ^ p_31) ^ ((l_1358 , (safe_rshift_func_int8_t_s_u(((((safe_sub_func_int32_t_s_s(l_1458, ((7L != g_71) | 0x60D0D305L))) , (!((g_59 == g_1052) , g_14))) && l_1358) > p_30), 4))) > g_71)), l_1354))) <= p_31) && g_59), l_1358)) > g_71);
                        g_72 = ((1UL <= (((((((((0UL < (safe_unary_minus_func_uint16_t_u((safe_mod_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s(((safe_add_func_uint64_t_u_u((((((((((((safe_lshift_func_uint16_t_u_u(((p_32 , 65535UL) & (safe_lshift_func_int8_t_s_s(0x62L, ((safe_rshift_func_int16_t_s_u(0L, 11)) , 0x95L)))), 13)) , (l_946 , ((safe_div_func_int16_t_s_s((p_33 == p_30), 0x08CFL)) < 0x267F1103L))) ^ 4294967291UL) == l_1513) ^ l_1358) , p_30) & g_81) <= 3UL) >= g_992) > 18446744073709551615UL) && g_81), 1UL)) , p_32), 0xB9L)) == 6UL), l_894))))) , 1UL) , l_1514) && 18446744073709551615UL) < 0UL) < l_1358) , g_1052) | p_31) , l_930)) & g_59);
                    }
                    g_72 = g_81;
                }
            }
            else
            {
                uint32_t l_1525 = 1UL;
                uint64_t l_1543 = 0x23F36310C6C2AAE0LL;
                int32_t l_1613 = 0L;
                if (p_32)
                {
                    int16_t l_1542 = 0xDF5EL;
                    g_72 = g_72;
                    l_1485 = 0x0721545DL;
                    g_72 = (safe_lshift_func_uint16_t_u_s(((((((safe_div_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(p_31, 1)), (((((g_1052 ^ p_30) , l_962) > ((safe_add_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((p_33 & g_71), (l_1525 , (+g_72)))), (((0x96D5A28AL > p_33) , 5L) , 0xDEL))) , 0x69B1L)) == g_72) & g_72))) < g_71) != g_71) <= g_992) , 255UL) < 0UL), g_1052));
                    for (p_30 = 0; (p_30 != 28); p_30++)
                    {
                        uint8_t l_1529 = 0x49L;
                        int32_t l_1566 = 0xCDBDAFFCL;
                        l_931 = ((g_81 >= l_1525) , l_1529);
                        g_72 = ((safe_lshift_func_int8_t_s_s(g_926, 1)) ^ (safe_rshift_func_uint8_t_u_s(((0x05EA60B8L >= (((9UL ^ (g_1052 && (((65535UL & (safe_add_func_uint8_t_u_u((((safe_sub_func_int32_t_s_s(((0x97CEL >= ((1L && ((l_1525 | (((safe_add_func_uint32_t_u_u((l_1542 | 0UL), 4294967291UL)) >= p_33) < g_72)) >= (-1L))) == 0xA4L)) < p_32), p_30)) , p_33) , l_1529), l_1529))) & l_1543) ^ g_59))) == l_1543) | 0xA611300AL)) == l_1485), l_725)));
                        l_1566 = ((safe_rshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_u(((safe_sub_func_uint64_t_u_u(p_31, (((((((safe_div_func_uint32_t_u_u(0x3DC72AFFL, (safe_div_func_uint8_t_u_u(l_1543, g_72)))) != ((safe_sub_func_uint8_t_u_u((5UL || 0xF8L), ((safe_div_func_int32_t_s_s((safe_lshift_func_int16_t_s_s(l_871, ((safe_add_func_int16_t_s_s(((safe_unary_minus_func_int32_t_s((-1L))) > (+((((safe_div_func_uint64_t_u_u((p_33 == 1UL), p_32)) > g_81) , g_71) || 0x213132A1L))), 0UL)) , (-5L)))), l_1485)) < (-3L)))) || l_1529)) , 254UL) , p_30) , p_29) != 0xB9C75BB78334736ALL) < 18446744073709551612UL))) , 1UL), g_156)), g_100)) <= p_29);
                    }
                }
                else
                {
                    int32_t l_1611 = 0x36757C7EL;
                    g_72 = ((((safe_sub_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((((l_945 , (safe_add_func_uint16_t_u_u((((((((+((safe_rshift_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(0UL, ((safe_add_func_int64_t_s_s((safe_sub_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((((safe_add_func_int8_t_s_s((p_33 & (((~(safe_sub_func_int32_t_s_s(l_1591, (safe_add_func_int64_t_s_s(((((safe_rshift_func_int16_t_s_s(g_72, (~((g_926 != (safe_unary_minus_func_int8_t_s(((safe_mod_func_int64_t_s_s(((safe_add_func_int16_t_s_s((((!(safe_mod_func_uint64_t_u_u((safe_rshift_func_int8_t_s_s((safe_div_func_int8_t_s_s(1L, (safe_rshift_func_uint8_t_u_u((((0xFCDBADDD33159AB5LL >= p_33) >= 65530UL) || g_992), l_1525)))), g_156)), p_30))) , g_71) > g_1052), 0xD6DBL)) < 7UL), g_926)) != g_156)))) || l_931)))) ^ l_1543) & l_1525) == g_81), l_1458))))) , l_1611) < l_1612)), 255UL)) ^ 0L) != g_1052), g_926)), 0x14L)), g_992)) | g_59))) & 0xD99DL), l_1613)) == 2UL)) , g_81) != l_1458) && p_33) >= 0xFFL) || 0x46L) || p_30), l_1458))) , p_30) != l_1611), 2)), l_1612)), 0xA2D2780EL)) < p_32) | 0UL) , p_33);
                }
                l_1614 = p_29;
                g_72 = l_1543;
                l_1615 = l_947;
            }
            if (p_30)
            {
                uint16_t l_1636 = 0x0489L;
                int16_t l_1718 = 0x4CEBL;
                uint32_t l_1769 = 0xC2D2C192L;
                int32_t l_1791 = (-1L);
                l_1485 = 0x2E34158BL;
                if (((((safe_mul_func_int8_t_s_s(((g_81 < (p_30 != g_156)) > g_100), (((safe_sub_func_uint8_t_u_u(0x50L, (safe_lshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_s((safe_add_func_int16_t_s_s(((0L >= p_31) ^ ((safe_add_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(l_1591, (safe_div_func_int32_t_s_s(p_32, l_1458)))), 0x97L)) >= l_1355)), 0xB468L)), p_30)), 15)))) , p_32) < 0xC475973F6F264F51LL))) <= p_33) == l_1614) == 0xD1C01D6388C95B7BLL))
                {
                    int8_t l_1633 = 0xAAL;
                    int32_t l_1674 = (-3L);
                    if (l_1632)
                    {
                        int64_t l_1637 = 1L;
                        l_1633 = 0xD7D00DBBL;
                        l_931 = (safe_sub_func_uint64_t_u_u(((l_1636 == l_1637) , (safe_div_func_int8_t_s_s(0xD2L, (((safe_sub_func_uint8_t_u_u(l_1637, ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(0x00L, 2)), (safe_sub_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s((((safe_unary_minus_func_uint16_t_u(65528UL)) > ((((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(l_1636, (l_1633 , p_33))), g_59)) || 8UL) == p_32) & g_156)) || 0x24L), p_30)) || l_1614) & p_31), g_59)))) | 1L))) ^ g_59) , p_32)))), l_1637));
                    }
                    else
                    {
                        uint32_t l_1655 = 0xD599D113L;
                        l_1655 = (0xFFF5AE4B3772F187LL ^ g_59);
                        if (l_1633)
                            break;
                        if (g_59)
                            continue;
                    }
                    l_725 = (safe_lshift_func_uint8_t_u_u((((g_100 & g_156) || (((safe_add_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((p_30 , (g_100 != l_1354)) <= ((0x8C73D990L < (safe_lshift_func_int8_t_s_u(((safe_div_func_uint64_t_u_u((18446744073709551613UL < (l_1591 , (safe_lshift_func_uint8_t_u_u((((((safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((safe_lshift_func_int8_t_s_s((g_71 && l_1636), 4)), g_156)) & l_1353), 0)) , 0xD9EBBE1987825FB8LL) & 1UL) <= p_32) , 255UL), 6)))), 0x175941960F727568LL)) , g_71), l_1093))) | l_1674)), p_30)), l_945)) , p_33) >= p_33)) > g_81), l_1674));
                }
                else
                {
                    int32_t l_1678 = (-3L);
                    int8_t l_1741 = 9L;
                    g_72 = ((+0x3DL) >= (safe_mod_func_uint32_t_u_u((((((l_1353 , ((p_30 > l_1678) == (~l_1680))) , ((p_31 | (((safe_mod_func_uint8_t_u_u((((((((!(safe_rshift_func_int16_t_s_s(p_33, g_81))) && (0UL < g_81)) && g_1052) && g_100) <= l_1354) && 2L) != g_1052), l_1678)) <= 8L) ^ p_33)) && 4294967295UL)) == p_29) <= l_1355) >= p_31), p_29)));
                    l_931 = ((l_1353 < g_100) & (safe_rshift_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u(0UL, 10)) < (safe_div_func_int32_t_s_s(0xBEB79F5BL, (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((((((safe_div_func_int32_t_s_s(((g_156 > g_81) <= ((safe_add_func_uint64_t_u_u((((((safe_lshift_func_int16_t_s_u(((l_1355 , (((!((-1L) <= (safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_s(((+(safe_div_func_uint8_t_u_u((safe_add_func_int64_t_s_s(0x9407D2550782FB72LL, p_29)), 0xC7L))) < 0x71L), g_1052)) && p_31), l_664)))) > g_156) != g_81)) && g_1052), 12)) || 4294967293UL) && p_32) >= 6UL) <= l_894), 0xD921A8817EA46F1ALL)) == g_992)), 4294967292UL)) | p_32) , p_32) && g_59) || l_1636), 4)) | p_29), p_32))))), p_33)));
                    for (g_992 = 2; (g_992 < (-26)); g_992--)
                    {
                        l_1718 = (safe_sub_func_int8_t_s_s(p_31, l_1615));
                        l_931 = ((safe_div_func_uint32_t_u_u(0x5C9C99D3L, ((safe_add_func_int32_t_s_s(((+(((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(p_30, ((safe_div_func_int64_t_s_s(((g_72 > (safe_add_func_int8_t_s_s((((4L && l_1355) > (0x97938E3B57EF581ALL | (safe_add_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u((safe_mod_func_int16_t_s_s(g_100, (((safe_mod_func_uint64_t_u_u((((+g_72) < (((0xD277BE45FDB5B720LL || g_81) , l_1741) ^ 255UL)) & g_156), 0xF4ABA06BFBB200C2LL)) <= l_1636) & l_721))), l_1632)) >= l_1458), p_31)))) < l_1353), 0xC7L))) && p_32), p_29)) & 8L))), 0xD94DL)) || 18446744073709551615UL) | l_1636)) || 0x2D41L), l_1632)) & 0x84L))) | l_1485);
                    }
                    if (g_71)
                        continue;
                }
                for (l_1615 = 0; (l_1615 == 30); l_1615++)
                {
                    uint16_t l_1748 = 0xE6DBL;
                    l_1485 = (safe_rshift_func_uint16_t_u_s((0xCA90L & (safe_mod_func_int16_t_s_s((((0UL || (((((((l_1748 && (safe_rshift_func_int8_t_s_s((l_1748 ^ ((safe_div_func_int8_t_s_s((l_1354 != (g_156 > (((((+((safe_mod_func_uint32_t_u_u((((((safe_add_func_uint32_t_u_u((0x61D97FC6L < p_32), (safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((safe_sub_func_uint64_t_u_u(g_992, 0x9F027BB68479A765LL)) ^ l_1615) <= l_945) ^ g_100), (-10L))), 0x5618L)))) && l_1768) , l_1769) > g_72) >= g_1052), p_32)) == l_1770)) , p_32) && (-1L)) == p_31) >= p_30))), 0x7AL)) > p_32)), g_81))) <= g_992) | 0xD969L) < g_71) , p_29) , g_59) , g_14)) == g_992) ^ g_926), 65532UL))), 7));
                }
                l_1791 = ((safe_rshift_func_uint16_t_u_u((((g_926 > (safe_div_func_int16_t_s_s(0x4291L, (l_1775 , (safe_mod_func_uint32_t_u_u(l_1769, (safe_lshift_func_int16_t_s_s(((l_1636 , 0x873C7571L) , p_32), (safe_mod_func_uint16_t_u_u((l_1070 ^ (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint8_t_u_s((!((safe_rshift_func_int8_t_s_u((safe_mod_func_int64_t_s_s(l_1353, g_81)), p_32)) == g_72)), 6)) == l_1615), 12))), l_1769)))))))))) >= l_1458) && p_30), 0)) <= 0x7078L);
            }
            else
            {
                int64_t l_1812 = 1L;
                l_1485 = ((safe_lshift_func_uint8_t_u_u((p_32 , g_156), 6)) , (safe_add_func_int16_t_s_s(l_962, (5L < (safe_sub_func_uint16_t_u_u(l_1768, 0xC37BL))))));
                g_72 = (safe_sub_func_uint8_t_u_u((safe_div_func_int64_t_s_s(g_14, g_81)), ((safe_div_func_uint64_t_u_u(p_32, ((l_894 >= (safe_add_func_uint32_t_u_u(4UL, 8UL))) || (l_1355 , (safe_mod_func_int8_t_s_s((safe_rshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s(p_33, (((((((g_992 <= g_992) == g_1052) | 0x4C543BB8L) == p_29) == l_1812) , 0x647F3D71D9BC8B70LL) & 1UL))), g_992)), p_33)))))) || g_156)));
            }
            g_72 = p_32;
            g_72 = (253UL && (safe_div_func_int64_t_s_s(p_31, (safe_add_func_int16_t_s_s((safe_div_func_int8_t_s_s((g_1052 != ((((((safe_add_func_int16_t_s_s(g_926, l_1354)) >= ((+(3UL & ((((l_962 >= (l_1632 == (!((safe_add_func_uint16_t_u_u((safe_mod_func_int16_t_s_s((0x2F8CF37286DE76EFLL != g_992), l_894)), l_1161)) > p_30)))) && 249UL) < l_1770) < 0xAAE41E91F183D125LL))) != p_30)) <= g_14) || l_774) | g_992) != 0x3D48A0D3L)), g_156)), 0UL)))));
        }
    }
    for (g_59 = (-24); (g_59 >= (-14)); ++g_59)
    {
        uint32_t l_1847 = 4294967292UL;
        uint16_t l_1850 = 0x3681L;
        int32_t l_1859 = 0x9B2671E7L;
        for (l_1355 = 0; (l_1355 >= (-18)); l_1355 = safe_sub_func_uint32_t_u_u(l_1355, 9))
        {
            uint64_t l_1846 = 0x52B5E213A1E84FE6LL;
            int32_t l_1848 = 0x8A003DCBL;
            l_1848 = ((safe_add_func_int64_t_s_s((p_30 == (safe_sub_func_int32_t_s_s(g_59, (((safe_rshift_func_int8_t_s_s(((6UL || (safe_sub_func_uint64_t_u_u((((safe_lshift_func_int16_t_s_s(0x4FD6L, 5)) , ((safe_div_func_uint32_t_u_u(((safe_add_func_int8_t_s_s((p_31 <= l_1845), p_33)) <= p_31), l_721)) , l_1846)) < l_1847), p_33))) < l_1847), l_1846)) || 0x93L) & p_32)))), 8UL)) <= g_71);
        }
        l_1859 = (((+((-1L) & l_1850)) > 0L) , ((((((safe_add_func_int64_t_s_s(p_30, ((l_721 || ((((safe_add_func_int64_t_s_s(((l_1847 != ((p_31 , (l_1847 != (safe_rshift_func_int16_t_s_u(((safe_rshift_func_int16_t_s_u(p_30, 12)) > 0xB2008D75L), g_14)))) >= 0x1E28B7D79DD3B204LL)) >= 0x9569D8ACL), p_30)) >= g_81) <= p_31) == 0x3FFDL)) && 0xD5L))) < g_59) , 0x1E56DBC701D0860ALL) != 0xBD00F5ACF2D5BC1ALL) , 0L) , g_992));
    }
    return g_72;
}







inline static uint8_t func_34(uint32_t p_35, int8_t p_36, int8_t p_37)
{
    int64_t l_155 = 0xDDAE05CF484424FDLL;
    uint64_t l_161 = 0UL;
    int32_t l_225 = 0x31D9B203L;
    int32_t l_303 = 0xE853EBC1L;
    uint32_t l_539 = 0xE8048ABAL;
    int16_t l_556 = (-8L);
    if ((safe_sub_func_uint16_t_u_u(0xA657L, p_37)))
    {
        int32_t l_157 = 4L;
        uint32_t l_224 = 6UL;
        uint16_t l_301 = 0x1EECL;
        uint32_t l_420 = 0x0C70AD77L;
        int32_t l_464 = (-1L);
        uint32_t l_465 = 18446744073709551615UL;
        uint8_t l_466 = 252UL;
        if ((~(safe_div_func_int16_t_s_s(((((g_100 , ((safe_sub_func_int32_t_s_s((p_35 , 0x993E846AL), (((((safe_lshift_func_int8_t_s_u(((((+g_72) == 1L) , (safe_div_func_int64_t_s_s(((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((0xA0E0L <= (safe_rshift_func_int8_t_s_s((((((!(safe_lshift_func_int16_t_s_s(((safe_sub_func_uint64_t_u_u((~((safe_lshift_func_uint8_t_u_s((253UL < (safe_rshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int64_t_s((safe_add_func_int32_t_s_s((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(((((((safe_sub_func_uint64_t_u_u((safe_div_func_uint16_t_u_u((65532UL > p_37), g_72)), 1UL)) < l_155) || g_59) || p_37) != p_37) | 0L), p_37)), 2UL)) , (-5L)) || l_155), g_100)))), g_71)), g_156))), 0)) <= l_155)), p_36)) ^ l_157), 7))) < 0xAAD5B6D64A7F71B9LL) == g_156) >= l_157) < l_155), g_59))), 4)), 0x4CFB6E6AL)) || p_36), 0x601A515F4A009C7ELL))) | l_157), p_35)) | 0x2051206B3A0AE147LL) , l_157) | p_36) != g_72))) ^ g_156)) && 0xBCL) != g_81) < l_155), (-8L)))))
        {
            int16_t l_162 = 0xCB81L;
            g_72 = (!p_36);
            l_162 = ((safe_rshift_func_uint8_t_u_s((p_36 , p_35), l_161)) , (p_37 | g_14));
            g_72 = (safe_mod_func_int32_t_s_s((((((safe_div_func_uint64_t_u_u((((p_36 <= (safe_div_func_uint16_t_u_u((safe_add_func_int16_t_s_s(p_37, (safe_sub_func_uint32_t_u_u((~65535UL), (((((4294967290UL | ((safe_add_func_uint64_t_u_u(((safe_rshift_func_int8_t_s_u((safe_div_func_int16_t_s_s(g_156, ((safe_div_func_int16_t_s_s((((~((0xD5L >= (safe_rshift_func_uint16_t_u_u(((g_59 != (((((safe_mod_func_int16_t_s_s(((l_162 < ((safe_sub_func_int8_t_s_s(l_161, l_155)) != g_156)) > g_156), g_100)) > l_162) >= g_156) && l_157) < 9UL)) , 0x0620L), 14))) & p_36)) == g_72) ^ 1L), p_36)) & 4L))), p_36)) || g_71), 1UL)) == 0x9E97L)) != 0x2FL) , p_37) != 1UL) & p_37))))), g_72))) & 5L) & 1L), p_36)) || l_162) >= p_36) | l_161) >= g_59), p_35));
            g_72 = (safe_mod_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_div_func_uint8_t_u_u((safe_mod_func_int64_t_s_s((safe_add_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u((safe_mod_func_int16_t_s_s((p_36 > ((safe_sub_func_uint16_t_u_u((l_157 , g_59), ((+(g_156 >= g_72)) & ((((safe_rshift_func_int16_t_s_u(((((((safe_sub_func_uint32_t_u_u(l_157, (safe_div_func_uint8_t_u_u(0x96L, g_72)))) != (safe_lshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((safe_add_func_uint64_t_u_u(((safe_sub_func_int16_t_s_s(((((((safe_mod_func_int32_t_s_s((((safe_div_func_int64_t_s_s((((g_59 ^ g_81) || l_155) , p_37), l_157)) < g_59) && l_162), g_100)) & (-1L)) >= p_36) && 0x0AC5L) > p_36) , l_155), g_72)) || p_37), l_224)), 6)), 12))) | 0xB4BDL) , 0x36E1F282L) && l_225) & p_37), 2)) ^ p_36) , 0x62A1L) & 0L)))) || p_37)), 3UL)), p_36)) ^ 0x88A4E7FFL) < 0UL), p_35)), l_157)), 255UL)), 10)), g_59));
        }
        else
        {
            int8_t l_244 = 6L;
            int32_t l_412 = 1L;
            int64_t l_413 = 1L;
            int64_t l_484 = 0xE7518134EFF2FE3ELL;
            if ((1UL == (safe_div_func_uint8_t_u_u(251UL, 0x10L))))
            {
                g_72 = (((g_14 > ((safe_lshift_func_uint16_t_u_s((0x00L < 0x59L), 7)) , 1L)) , g_59) , ((safe_rshift_func_uint8_t_u_s((0x7D1EL || (-3L)), ((safe_sub_func_uint8_t_u_u((~(((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint16_t_u_s(p_36, 11)), 6)) | (safe_div_func_int8_t_s_s((((~(safe_unary_minus_func_uint16_t_u((safe_unary_minus_func_uint16_t_u((((l_244 && l_244) >= 0L) , p_36)))))) <= l_244) != 1UL), 0x96L))) , g_71)), 0L)) < p_35))) && l_161));
                g_72 = ((safe_add_func_int16_t_s_s((0xCBE6FDDEL | (safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_s((((~(246UL || l_244)) >= 0xC451L) == g_156), ((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s((g_71 > 0x746C22C4725C5B71LL), ((p_36 & (safe_rshift_func_int8_t_s_u((-4L), 4))) ^ 0x49L))) != p_37), 5)) > 0x6DL))), 13))), 0xC14AL)) > p_36);
            }
            else
            {
                g_72 = p_35;
            }
            g_72 = (((safe_lshift_func_int8_t_s_u((((safe_rshift_func_uint8_t_u_u((((safe_sub_func_uint16_t_u_u(0x698BL, (safe_sub_func_uint64_t_u_u(((p_37 > ((safe_sub_func_uint16_t_u_u(g_100, (p_35 > ((safe_sub_func_uint32_t_u_u((l_157 == 0xAA391307L), l_157)) || (g_156 && g_71))))) > l_157)) , g_81), l_225)))) , p_37) , p_36), p_37)) & g_156) > 18446744073709551608UL), 7)) | p_37) > l_157);
            for (l_225 = 17; (l_225 == 21); l_225 = safe_add_func_uint8_t_u_u(l_225, 1))
            {
                uint16_t l_302 = 65530UL;
                int64_t l_336 = 0x7532AD14520FFE10LL;
                l_303 = (g_72 | ((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s(((safe_mod_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((((safe_unary_minus_func_int16_t_s(((((0xC3FCBC6C6E832668LL <= ((safe_lshift_func_uint16_t_u_s((safe_sub_func_uint32_t_u_u(p_37, ((safe_rshift_func_uint8_t_u_s(((safe_unary_minus_func_int8_t_s(((safe_sub_func_int64_t_s_s(((safe_lshift_func_uint8_t_u_u((((((safe_sub_func_int32_t_s_s(((g_81 && (((l_155 , (((g_71 >= (safe_add_func_int16_t_s_s((+(safe_add_func_uint32_t_u_u((((p_36 < l_161) >= 0x350BL) & p_37), l_224))), 65535UL))) , p_36) , p_35)) > p_35) ^ g_71)) <= l_244), 0x6D92C262L)) <= g_100) <= g_72) == 0x5DE7364380347476LL) < 1L), g_156)) || l_244), 9UL)) != l_301))) , l_302), l_244)) , 4294967288UL))), l_302)) >= l_244)) > g_72) | 0xF2L) , 0xC6B1L))) , 0xC6425BE3L) , p_36), 2)), 0x63L)) == 0xA470504D8E8CD19ELL), 1)), g_59)) , g_59));
                if ((p_37 > p_37))
                {
                    int64_t l_337 = 7L;
                    int32_t l_349 = 0xF3B193B9L;
                    g_72 = (g_14 | (p_37 , ((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint64_t_u_u(18446744073709551610UL, (0L | ((((p_35 != ((safe_lshift_func_uint8_t_u_u(((safe_add_func_uint64_t_u_u(((safe_lshift_func_int8_t_s_u(((p_35 , (safe_sub_func_uint64_t_u_u(p_35, (safe_add_func_uint8_t_u_u(((p_35 > (0x430AC928L < (-1L))) && l_244), 0x18L))))) == 0x969002E6L), 2)) , 18446744073709551611UL), 0xD6C72585D44CC3E1LL)) , 0xE5L), 0)) != g_81)) >= 0L) | 0x7C646956L) && 0x1552L)))) <= p_36), 0)) == 1L)));
                    l_303 = 0L;
                    l_337 = (safe_sub_func_uint64_t_u_u(l_301, (safe_rshift_func_int16_t_s_u(p_35, (((safe_sub_func_uint32_t_u_u(g_81, ((((((safe_add_func_uint32_t_u_u(((safe_div_func_uint64_t_u_u((((safe_unary_minus_func_int8_t_s((((safe_sub_func_int8_t_s_s((((0x54F81062365FE046LL != p_35) < (~l_224)) || (safe_div_func_int16_t_s_s((l_157 ^ ((safe_sub_func_uint16_t_u_u((p_35 >= (-10L)), l_244)) <= l_244)), g_14))), l_336)) , g_81) && g_14))) <= p_37) , 0xCD922F6D8BA3A875LL), g_59)) > 65526UL), g_156)) != g_59) , p_37) && 1UL) == 0xEB27L) , 0UL))) , 65535UL) <= 1UL)))));
                    l_349 = (!(((safe_lshift_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((((((safe_lshift_func_int8_t_s_u((((g_156 != 0xCA25EC3FAA92D2B0LL) < (safe_rshift_func_uint8_t_u_u(246UL, (g_71 <= (+((safe_unary_minus_func_uint64_t_u((p_35 , (((1L & (0xBCL > g_71)) && l_225) > l_157)))) != p_37)))))) <= 8L), 1)) <= 8L) >= l_157) || l_301) > p_37) , l_336), g_72)), g_81)) == 0x7EL) , 1L));
                }
                else
                {
                    uint32_t l_387 = 1UL;
                    int8_t l_394 = (-1L);
                    for (g_156 = 5; (g_156 < 41); g_156++)
                    {
                        int32_t l_360 = (-9L);
                        g_72 = (safe_add_func_int32_t_s_s((((g_59 ^ (p_35 , ((safe_lshift_func_int16_t_s_s(l_244, 0)) < ((l_224 < g_81) > (safe_rshift_func_uint16_t_u_u((safe_sub_func_int64_t_s_s(((l_224 , (l_244 | 0x35L)) || (g_14 != p_37)), l_360)), l_360)))))) , g_59) >= g_59), (-8L)));
                    }
                    g_72 = (((safe_lshift_func_int8_t_s_s((safe_add_func_int16_t_s_s(0x7C6BL, 0UL)), (l_157 <= (!((((safe_lshift_func_int8_t_s_u((safe_rshift_func_uint16_t_u_u(l_301, (safe_lshift_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u(p_36, p_37)), (((((safe_add_func_int64_t_s_s(((!((safe_mod_func_uint32_t_u_u((safe_div_func_uint16_t_u_u((((safe_add_func_int32_t_s_s(((((safe_add_func_int8_t_s_s(l_157, ((!((~g_100) <= l_244)) , l_244))) > p_35) < g_72) == l_387), l_244)) && 0xFCL) & 18446744073709551615UL), g_72)), g_81)) != p_35)) != 0x073102F5L), 0x58FA1B864D20151ELL)) == 0xD3L) >= p_35) , l_157) != 0L))))), 5)) & p_36) >= l_303) || 0x90E3C0702EA30448LL))))) | l_336) < p_36);
                    for (l_244 = 0; (l_244 != 20); l_244 = safe_add_func_uint16_t_u_u(l_244, 8))
                    {
                        uint32_t l_399 = 0x40DCABA1L;
                        int64_t l_432 = (-4L);
                        l_303 = ((g_71 == (250UL ^ (+((safe_add_func_int8_t_s_s(((+(l_387 , l_394)) || (((((safe_rshift_func_int8_t_s_s((((((((safe_mod_func_uint8_t_u_u((l_399 , (((safe_div_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(g_72, (((((safe_sub_func_int64_t_s_s((safe_rshift_func_int8_t_s_u((((((safe_add_func_int8_t_s_s(1L, (((safe_rshift_func_int8_t_s_u((l_244 <= (((-6L) == 0UL) <= l_244)), 3)) || l_244) , 0x10L))) | p_37) , g_72) | g_71) < 0x8BL), l_224)), 18446744073709551610UL)) == l_244) | (-1L)) | 0x8BL) > l_412))), l_399)) == 0x2FF86269F678E49ELL) , g_156)), p_36)) >= l_412) ^ 0xA2ABL) , 0x1DFEF368L) , l_413) < l_302) , g_156), p_36)) , g_72) != g_59) , p_35) && 0x3BL)), l_157)) | g_14)))) == p_35);
                        l_157 = ((safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(l_336, ((safe_mod_func_uint16_t_u_u((g_72 == 0xB928183C4D56DDB9LL), l_420)) < (~((safe_sub_func_uint16_t_u_u(l_394, (0x30AEL & (1UL | (safe_div_func_uint16_t_u_u(0UL, (safe_mod_func_uint16_t_u_u((((safe_div_func_uint16_t_u_u(((safe_div_func_int64_t_s_s((0x9CL > l_399), p_35)) | l_432), l_412)) && p_36) > 65532UL), 0xFC0EL)))))))) , g_59))))), l_161)) ^ l_387);
                        if (p_36)
                            continue;
                    }
                }
                l_412 = (((((safe_div_func_int8_t_s_s((safe_sub_func_int8_t_s_s(g_72, ((safe_div_func_uint32_t_u_u((l_161 <= (((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((((safe_div_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((((safe_add_func_uint16_t_u_u(1UL, ((safe_rshift_func_uint16_t_u_u((g_59 || (safe_lshift_func_uint16_t_u_u((g_14 != ((!l_301) | ((0xE97DL < ((safe_rshift_func_uint8_t_u_s(0xAFL, 4)) || ((safe_div_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s(((safe_div_func_int8_t_s_s((((p_36 > l_464) | 0x6919L) , l_336), l_413)) == 0x0BE0AE21L), p_36)), l_465)), 255UL)) , 0x3FL))) && p_37))), l_161))), 13)) > p_37))) > p_36) , l_155), 4)) || g_100), 1L)) <= 1UL) <= l_225) != p_35) > p_36), 0x5C724C18L)), p_36)) < 0UL) && (-9L))), g_156)) && l_301))), 0x45L)) != 0x35FBB914L) <= l_466) != g_71) == 0x8F4CL);
                for (l_155 = 0; (l_155 >= (-13)); l_155--)
                {
                    uint32_t l_479 = 0x57B61FB8L;
                    for (l_244 = 4; (l_244 < 18); ++l_244)
                    {
                        l_412 = (safe_rshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s(l_479, (safe_div_func_uint64_t_u_u(p_35, (((((safe_lshift_func_uint8_t_u_s(((1L && g_14) >= (l_484 <= (p_37 & ((safe_rshift_func_uint8_t_u_u(1UL, (0x1555L | (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(((safe_div_func_int64_t_s_s((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((safe_div_func_int64_t_s_s(g_59, 2UL)), l_301)) & g_72), 0x44L)), 18446744073709551614UL)) == g_156), g_72)), l_479))))) == g_72)))), 5)) | g_71) || (-1L)) , g_72) && 0xF914459BL))))) < 0UL), p_37)), 12));
                    }
                    if (l_413)
                    {
                        int16_t l_510 = 0xFA50L;
                        if (g_14)
                            break;
                        g_72 = ((g_59 || ((l_336 | g_81) , (!((((safe_lshift_func_int16_t_s_u(((safe_div_func_int8_t_s_s((((safe_add_func_int16_t_s_s((p_36 < ((((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((((l_336 != l_510) <= (safe_lshift_func_uint16_t_u_u((((((g_100 ^ g_156) , l_161) == g_59) == g_71) || 0L), 10))) || 1UL) , 0xEF0CL), 0L)), p_36)) & 0xDFB72610L) & 1L) > 0xFDFBL)), 0x6843L)) < p_37) != p_35), g_59)) && l_157), 15)) , p_36) || 0x3B9EL) != g_71)))) < 0x5871L);
                    }
                    else
                    {
                        int32_t l_521 = 4L;
                        int8_t l_523 = (-9L);
                        g_72 = (-1L);
                        g_72 = ((((safe_add_func_int8_t_s_s(((((((safe_lshift_func_int8_t_s_s(((p_35 , l_479) < (l_413 && (safe_rshift_func_int8_t_s_u(((g_156 <= (((0x5AL >= (safe_sub_func_uint32_t_u_u(g_72, l_464))) == (l_521 == (((+((g_100 <= (-3L)) < g_71)) >= g_81) , 0xB1E4EFC2L))) || g_72)) == 1L), 0)))), 7)) != g_81) , p_37) == l_523) >= l_465) , l_336), l_466)) & l_466) ^ p_37) | 9UL);
                        if (p_37)
                            continue;
                    }
                }
            }
        }
        l_225 = (((safe_rshift_func_uint8_t_u_u(p_37, 2)) | (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u(p_36, 2)) >= p_35), ((l_225 , (!p_36)) , g_71)))) | ((0xDA5789E8L || (safe_lshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((p_36 ^ (safe_rshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u(((g_72 || 1L) < p_36), g_72)) > l_539), l_539))), 7)), 11))) <= 0L));
    }
    else
    {
        int32_t l_555 = (-1L);
        int32_t l_571 = 1L;
        uint64_t l_662 = 9UL;
        int8_t l_663 = 1L;
        for (p_37 = 0; (p_37 >= (-13)); p_37 = safe_sub_func_uint32_t_u_u(p_37, 1))
        {
            int32_t l_572 = 0xBCCC8380L;
            int32_t l_616 = 0L;
            for (l_225 = (-20); (l_225 != (-10)); l_225 = safe_add_func_uint64_t_u_u(l_225, 2))
            {
                uint16_t l_554 = 0x0EF3L;
                int32_t l_585 = 0x785C2DE3L;
                if (((g_100 < ((((((safe_rshift_func_uint16_t_u_s(((-1L) || (safe_add_func_uint64_t_u_u(((safe_rshift_func_int8_t_s_u(((0x9C97L != (p_35 <= g_71)) > (safe_sub_func_uint64_t_u_u(((((safe_mod_func_int32_t_s_s(g_59, (g_72 || l_554))) <= (((g_81 <= 0x48389AF5L) , p_37) ^ 18446744073709551614UL)) | l_161) & g_156), g_59))), 1)) || g_81), (-3L)))), l_555)) , l_161) > 0x78L) , 0xB77825118971EB0DLL) , 9L) && 5UL)) & 4294967295UL))
                {
                    uint32_t l_570 = 18446744073709551606UL;
                    int64_t l_589 = 1L;
                    g_72 = ((((-1L) != l_556) | p_36) || 0x53L);
                    for (g_156 = 0; (g_156 >= 36); g_156 = safe_add_func_int8_t_s_s(g_156, 5))
                    {
                        uint32_t l_569 = 4UL;
                        l_571 = (l_225 > (((p_37 || l_555) > (((safe_lshift_func_uint8_t_u_u((p_36 >= ((g_81 != (safe_add_func_uint64_t_u_u((((safe_mod_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(p_37, (p_35 | (p_35 > (safe_add_func_int32_t_s_s((255UL != p_36), g_14)))))), g_72)) == p_36) != g_71), 0x4277E1FF0450EE63LL))) < l_569)), 2)) <= g_71) > l_554)) | l_570));
                        if (l_572)
                            continue;
                        if (p_35)
                            continue;
                        l_585 = (l_571 ^ ((safe_div_func_int32_t_s_s((0L && ((((g_14 == (safe_sub_func_int64_t_s_s((((p_37 >= (safe_sub_func_int32_t_s_s((safe_div_func_uint32_t_u_u((safe_add_func_int64_t_s_s((g_59 , (((safe_rshift_func_uint16_t_u_u((((l_554 || 0x68ADC200L) && g_81) ^ 0x98C986FB326C4E58LL), 9)) & g_81) , p_37)), l_569)), l_569)), g_81))) && l_161) >= 0x4D44AD4DL), p_36))) | g_72) == (-9L)) != p_37)), g_72)) & 0UL));
                    }
                    if ((safe_unary_minus_func_int8_t_s((g_59 | (safe_add_func_int8_t_s_s(((p_37 & l_589) , l_556), (safe_add_func_uint32_t_u_u(l_161, 0x48E5594AL))))))))
                    {
                        int64_t l_608 = 0x32D1B386BFE8213ALL;
                        if (g_71)
                            break;
                        g_72 = (safe_rshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((((safe_mod_func_uint16_t_u_u(p_37, 65535UL)) , (safe_sub_func_int16_t_s_s(((safe_div_func_int16_t_s_s((((safe_div_func_int16_t_s_s(l_572, (safe_sub_func_uint8_t_u_u(p_37, ((g_81 < ((((safe_add_func_uint8_t_u_u(l_608, (safe_div_func_uint64_t_u_u(0x0E07BC25F3D8B2D8LL, ((p_37 | (safe_lshift_func_int8_t_s_s(((~(safe_add_func_int8_t_s_s((g_71 <= l_225), p_37))) && p_35), 0))) & p_36))))) > g_59) != p_35) , l_572)) && l_570))))) && 18446744073709551611UL) >= p_35), l_570)) & l_572), g_71))) ^ 0UL), l_554)), 5));
                        l_616 = 0xAC3C9E9EL;
                    }
                    else
                    {
                        int32_t l_617 = 0xA2694760L;
                        l_617 = 0x3A27F2B7L;
                        g_72 = ((safe_mod_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(6UL, 0)), (safe_div_func_int64_t_s_s((l_617 && (safe_lshift_func_uint16_t_u_s(0xBFA6L, 5))), (safe_lshift_func_int8_t_s_s((p_35 || p_37), 4)))))) >= 0x8BL);
                    }
                }
                else
                {
                    uint8_t l_646 = 2UL;
                    l_303 = g_71;
                    if ((1UL > p_37))
                    {
                        l_303 = (p_36 , ((safe_rshift_func_int16_t_s_s((g_14 | p_35), 13)) | 249UL));
                    }
                    else
                    {
                        int8_t l_645 = 7L;
                        g_72 = (0x22L != (p_35 , ((safe_mod_func_int8_t_s_s(((((~(246UL > (safe_sub_func_int8_t_s_s((((l_554 || g_71) , 65535UL) != (((safe_lshift_func_int8_t_s_u(((0xFD72L > (((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((safe_mod_func_int32_t_s_s((((((g_14 , (((l_645 ^ 0L) < g_156) ^ 0x2BF848020B55ECC2LL)) < p_37) || 0x208F0BCDDE0619FALL) != p_37) ^ p_35), (-1L))), g_81)), l_646)) ^ 1UL) | p_35)) | 0x6E36124339022BD2LL), 3)) && l_555) , 0xCD62L)), l_572)))) , (-9L)) >= g_156) & l_645), p_37)) != 0x1EBA4C447BCDDCC1LL)));
                    }
                    l_616 = (-4L);
                }
                g_72 = (((safe_rshift_func_uint8_t_u_u((!p_37), p_37)) | (((g_71 & (((((g_14 && (safe_rshift_func_uint16_t_u_s(g_81, 3))) || ((((safe_sub_func_uint16_t_u_u(l_571, ((safe_mod_func_int64_t_s_s(((safe_mod_func_uint32_t_u_u(4294967287UL, (safe_sub_func_int32_t_s_s(p_37, 0x2E1737B0L)))) > l_555), p_35)) , 0xCDCDL))) >= 4UL) != g_72) <= p_36)) , g_59) ^ g_156) , 0x3CA24419C1050C99LL)) | 0x99B99EB3L) >= 9UL)) == g_81);
                for (g_59 = 0; (g_59 > (-14)); g_59 = safe_sub_func_int8_t_s_s(g_59, 1))
                {
                    return l_662;
                }
            }
            l_571 = g_72;
            if (l_663)
                continue;
        }
        g_72 = g_71;
    }
    return g_72;
}







static int64_t func_38(uint8_t p_39, int16_t p_40)
{
    uint8_t l_84 = 255UL;
    int8_t l_85 = 0L;
    int32_t l_97 = 2L;
    uint64_t l_113 = 0x5C5D77E0797F44D6LL;
    l_97 = (((0xE8FEL != (safe_sub_func_int32_t_s_s((0L == ((l_84 <= ((l_85 < (((l_85 ^ (safe_unary_minus_func_int8_t_s((((safe_add_func_int16_t_s_s(g_81, g_72)) > (safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s(p_39, (safe_sub_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((((0x60CCD11DL | 8L) == p_40) | 0UL) >= l_85), 0x1B0FL)), l_84)))), g_81))) | 8UL)))) == 65535UL) != 0L)) == p_39)) & 1UL)), p_39))) <= g_14) ^ g_59);
    g_72 = (0xFA0F5A0A6BD2E779LL ^ (p_40 < l_97));
    for (g_72 = 20; (g_72 < (-2)); g_72 = safe_sub_func_uint8_t_u_u(g_72, 8))
    {
        g_100 = g_14;
    }
    l_97 = ((safe_sub_func_uint16_t_u_u(g_59, (((((safe_mod_func_uint8_t_u_u(p_40, l_97)) < (((((((((((safe_sub_func_int8_t_s_s((g_72 , (safe_add_func_int32_t_s_s(g_59, ((safe_sub_func_int32_t_s_s((((safe_sub_func_int64_t_s_s(((l_85 & 0xA9L) >= 0xFF9DL), l_84)) < p_39) || 255UL), 1L)) , p_39)))), l_84)) || g_81) & g_71) || l_97) <= 0x22L) >= g_71) < g_71) <= p_40) && p_40) >= g_72) >= l_97)) ^ 0x0DCEDD96C0B5FFC7LL) , l_113) != g_14))) > 0L);
    return l_85;
}







inline static int16_t func_44(int16_t p_45)
{
    int8_t l_60 = 1L;
    int32_t l_65 = (-5L);
    uint16_t l_70 = 65533UL;
    int16_t l_80 = (-1L);
    g_72 = func_46((+((p_45 ^ ((~(((((safe_div_func_int8_t_s_s(3L, (g_14 && 1L))) <= (safe_sub_func_int8_t_s_s((((g_59 & (l_60 > (safe_lshift_func_uint16_t_u_s((g_59 | (safe_div_func_uint64_t_u_u(l_65, (safe_sub_func_int64_t_s_s((((((((((safe_mod_func_int32_t_s_s(p_45, g_59)) , l_60) && l_65) && g_59) & g_59) >= l_60) & 0xB3E2L) < p_45) != 5UL), l_70))))), 11)))) >= 0xF16CE65C5BCCBF78LL) , 0x25L), l_60))) <= g_59) || l_65) , p_45)) >= 1L)) , p_45)), p_45);
    l_65 = l_70;
    g_72 = (((safe_sub_func_int32_t_s_s((0x30L || (l_60 >= (((safe_lshift_func_int8_t_s_u((((p_45 > ((g_71 > p_45) && (((safe_add_func_int8_t_s_s(1L, (safe_unary_minus_func_uint64_t_u((g_59 || l_60))))) & l_60) , 6L))) >= 7UL) & 0xDEL), 7)) && l_70) ^ l_80))), g_59)) || g_72) == 0x1BF9L);
    return g_71;
}







inline static int32_t func_46(uint32_t p_47, uint64_t p_48)
{
    g_71 = p_47;
    return g_71;
}





int main (void)
{
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_14, "g_14", print_hash_value);
    transparent_crc(g_59, "g_59", print_hash_value);
    transparent_crc(g_71, "g_71", print_hash_value);
    transparent_crc(g_72, "g_72", print_hash_value);
    transparent_crc(g_81, "g_81", print_hash_value);
    transparent_crc(g_100, "g_100", print_hash_value);
    transparent_crc(g_156, "g_156", print_hash_value);
    transparent_crc(g_926, "g_926", print_hash_value);
    transparent_crc(g_992, "g_992", print_hash_value);
    transparent_crc(g_1052, "g_1052", print_hash_value);
    transparent_crc(g_1861, "g_1861", print_hash_value);
    transparent_crc(g_1973, "g_1973", print_hash_value);
    transparent_crc(g_2223, "g_2223", print_hash_value);
    transparent_crc(g_2685, "g_2685", print_hash_value);
    transparent_crc(g_2725, "g_2725", print_hash_value);
    transparent_crc(g_2822, "g_2822", print_hash_value);
    transparent_crc(g_2850, "g_2850", print_hash_value);
    transparent_crc(g_3034, "g_3034", print_hash_value);
    transparent_crc(g_3288, "g_3288", print_hash_value);
    transparent_crc(g_3420, "g_3420", print_hash_value);
    transparent_crc(g_3814, "g_3814", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
