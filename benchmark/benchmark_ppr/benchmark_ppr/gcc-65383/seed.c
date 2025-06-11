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
crc32_8bytes (uint32_t val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
}

static void
transparent_crc (uint32_t val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %X\n", vname, crc32_context ^ 0xFFFFFFFFU);
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



static int32_t g_5 = (-10L);
static int16_t g_27[3][1] = {{5L},{5L},{5L}};
static uint32_t g_32[9][2] = {{4294967290UL,0x520F3038L},{6UL,0x520F3038L},{4294967290UL,6UL},{0xD06F6293L,0xD06F6293L},{0xD06F6293L,6UL},{4294967290UL,0x520F3038L},{6UL,0x520F3038L},{4294967290UL,6UL},{0xD06F6293L,0xD06F6293L}};
static uint32_t g_33 = 0x2CD8491FL;
static int8_t g_34[10] = {0xF9L,0xF9L,0xF9L,0xF9L,0xF9L,0xF9L,0xF9L,0xF9L,0xF9L,0xF9L};
static uint8_t g_35 = 0x2EL;
static volatile uint32_t g_44 = 4294967289UL;
static int16_t g_53 = 0x702BL;
static uint32_t g_86 = 0x19166C0CL;
static uint16_t g_108 = 65535UL;
static volatile uint32_t g_126 = 0x7CFDFC4DL;
static uint32_t g_127 = 1UL;
static uint8_t g_132 = 0xA8L;
static uint32_t g_183[10] = {0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L,0x3F7E2340L};
static uint8_t g_185[2][9][3] = {{{0xBEL,0x9FL,0x9FL},{0xBEL,0x9FL,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L}},{{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L},{0x9FL,0x44L,0x44L}}};
static int16_t g_203 = (-9L);
static uint32_t g_247 = 0x34D8CA7FL;
static uint32_t g_250[1][5] = {{0UL,0UL,0UL,0UL,0UL}};
static uint32_t g_276 = 0UL;
static int16_t g_298 = 0L;
static int32_t g_315 = 0xA0711357L;
static uint32_t g_317 = 5UL;
static uint32_t g_318 = 0UL;
static int16_t g_344 = 0xB4C2L;
static uint16_t g_391 = 2UL;
static uint16_t g_400 = 65528UL;
static int8_t g_419 = 0xF8L;
static int32_t g_427[3] = {0x92A1D2CDL,0x92A1D2CDL,0x92A1D2CDL};
static uint32_t g_449 = 0xEA1D27C7L;
static uint8_t g_456 = 248UL;
static uint32_t g_486 = 0x2CAB0F51L;
static volatile uint32_t g_499 = 0xCCA17D6DL;
static uint16_t g_503 = 0x06D7L;
static uint16_t g_504[10][8][3] = {{{1UL,0x4B63L,0x3008L},{65535UL,1UL,0x3008L},{0xEF53L,6UL,0xAA53L},{0xA4E2L,65535UL,0x3008L},{0x4B63L,6UL,0x3008L},{6UL,0xEF53L,0xAA53L},{6UL,5UL,0x3008L},{5UL,0xA4E2L,0x3008L}},{{0xFFB4L,0xFFB4L,0xAA53L},{1UL,0x4B63L,0x3008L},{65535UL,1UL,0x3008L},{0xEF53L,6UL,0xAA53L},{0xA4E2L,65535UL,0x3008L},{0x4B63L,6UL,0x3008L},{6UL,0xEF53L,0xAA53L},{6UL,5UL,0x3008L}},{{5UL,0xA4E2L,0x3008L},{0xFFB4L,0xFFB4L,0xAA53L},{1UL,0x4B63L,0x3008L},{65535UL,1UL,0x3008L},{0xEF53L,6UL,0xAA53L},{0xA4E2L,65535UL,0x3008L},{0x4B63L,6UL,0x3008L},{6UL,0xEF53L,0xAA53L}},{{6UL,5UL,0x3008L},{5UL,0xA4E2L,0x3008L},{0xFFB4L,0xFFB4L,0xAA53L},{1UL,0x4B63L,0x3008L},{65535UL,1UL,0x3008L},{0xEF53L,6UL,0xAA53L},{0xA4E2L,65535UL,0x3008L},{0x4B63L,6UL,0x3008L}},{{6UL,0xEF53L,0xAA53L},{6UL,5UL,0x3008L},{5UL,0xA4E2L,0x3008L},{0xFFB4L,0xFFB4L,0xAA53L},{1UL,0x4B63L,0x3008L},{65535UL,1UL,0x3008L},{0xEF53L,6UL,0xAA53L},{0xA4E2L,65535UL,0x3008L}},{{0x4B63L,6UL,0x3008L},{6UL,0xEF53L,0xAA53L},{6UL,5UL,0x3008L},{5UL,0xA4E2L,0x3008L},{0xFFB4L,0xFFB4L,6UL},{0xF860L,0x316FL,0xEF53L},{0UL,0xF860L,0xEF53L},{65530UL,0xE9B3L,6UL}},{{0x2DF2L,0UL,0xEF53L},{0x316FL,0UL,0xEF53L},{0xE9B3L,65530UL,6UL},{0UL,0x90F2L,0xEF53L},{0x90F2L,0x2DF2L,0xEF53L},{6UL,6UL,6UL},{0xF860L,0x316FL,0xEF53L},{0UL,0xF860L,0xEF53L}},{{65530UL,0xE9B3L,6UL},{0x2DF2L,0UL,0xEF53L},{0x316FL,0UL,0xEF53L},{0xE9B3L,65530UL,6UL},{0UL,0x90F2L,0xEF53L},{0x90F2L,0x2DF2L,0xEF53L},{6UL,6UL,6UL},{0xF860L,0x316FL,0xEF53L}},{{0UL,0xF860L,0xEF53L},{65530UL,0xE9B3L,6UL},{0x2DF2L,0UL,0xEF53L},{0x316FL,0UL,0xEF53L},{0xE9B3L,65530UL,6UL},{0UL,0x90F2L,0xEF53L},{0x90F2L,0x2DF2L,0xEF53L},{6UL,6UL,6UL}},{{0xF860L,0x316FL,0xEF53L},{0UL,0xF860L,0xEF53L},{65530UL,0xE9B3L,6UL},{0x2DF2L,0UL,0xEF53L},{0x316FL,0UL,0xEF53L},{0xE9B3L,65530UL,6UL},{0UL,0x90F2L,0xEF53L},{0x90F2L,0x2DF2L,0xEF53L}}};
static int32_t g_566 = 0xB2D08BC0L;
static volatile int16_t g_577 = 2L;
static uint32_t g_639 = 0x5BF4443DL;
static uint32_t g_692 = 0x09391D9FL;
static int32_t g_693[2] = {0xCB57FED6L,0xCB57FED6L};
static uint32_t g_739 = 0xD789D116L;
static volatile int8_t g_769 = 0x1EL;
static int16_t g_820 = 0L;
static int32_t g_897[2][3] = {{0xD7D9BB05L,0xD7D9BB05L,0xD7D9BB05L},{(-1L),(-1L),(-1L)}};
static volatile int32_t g_918[5][2][9] = {{{3L,(-1L),3L,0x91CF556EL,0L,0xEAB8A1A6L,0x91CF556EL,0xED0869A6L,(-1L)},{(-1L),0xED0869A6L,0x91CF556EL,0xEAB8A1A6L,0L,0x91CF556EL,3L,(-1L),3L}},{{1L,9L,0x91CF556EL,0x91CF556EL,9L,1L,0xEAB8A1A6L,0x8D07C015L,0x6320F129L},{1L,0xED0869A6L,3L,1L,(-1L),0x6320F129L,(-1L),0x8D07C015L,3L}},{{(-1L),(-1L),0xEAB8A1A6L,0x6320F129L,(-1L),0x6320F129L,0xEAB8A1A6L,(-1L),(-1L)},{3L,0x8D07C015L,(-1L),0x6320F129L,(-1L),1L,3L,0xED0869A6L,1L}},{{0x6320F129L,0x8D07C015L,0xEAB8A1A6L,1L,9L,0x91CF556EL,0x91CF556EL,9L,1L},{3L,(-1L),3L,0x91CF556EL,0L,0xEAB8A1A6L,0x91CF556EL,0xED0869A6L,(-1L)}},{{(-1L),0xED0869A6L,0x91CF556EL,0xEAB8A1A6L,(-1L),0x1D3921EBL,0x385EB4D3L,0L,0x385EB4D3L},{4L,0x91CF556EL,0x1D3921EBL,0x1D3921EBL,0x91CF556EL,4L,0xB5D366A8L,3L,0x5DC9BADBL}}};
static uint32_t g_972 = 0x3AAFA27AL;
static volatile uint32_t g_1001 = 0xD12476D2L;
static uint16_t g_1044 = 0x24BFL;
static volatile int16_t g_1045 = 0x8739L;
static int16_t g_1138 = 0xDCAAL;
static uint16_t g_1328 = 0x2078L;
static volatile uint32_t g_1357 = 0UL;
static int32_t g_1363 = 0x09F5684CL;
static int32_t g_1472 = (-1L);
static int8_t g_1669 = 8L;
static int32_t g_2084 = (-1L);
static int32_t g_2222 = 0x8FE31437L;
static volatile int32_t g_2236[6] = {0x0E7B8307L,0x0E7B8307L,0x0E7B8307L,0x0E7B8307L,0x0E7B8307L,0x0E7B8307L};
static volatile int8_t g_2610 = 0xB6L;
static volatile int16_t g_2674 = 0L;
static uint16_t g_2729[3][7] = {{65528UL,0xB42CL,1UL,0xB42CL,65528UL,1UL,1UL},{65528UL,0xB42CL,1UL,0xB42CL,65528UL,1UL,1UL},{65528UL,0xB42CL,1UL,0xB42CL,65528UL,1UL,1UL}};
static int32_t g_2942 = 0L;
static uint8_t g_3003 = 0x76L;
static int32_t g_3045[3][7] = {{0x26980768L,0x26980768L,0x26980768L,0x26980768L,0x26980768L,0x26980768L,0x26980768L},{8L,8L,8L,8L,8L,8L,8L},{0x26980768L,0x26980768L,0x26980768L,0x26980768L,0x26980768L,0x26980768L,0x26980768L}};
static volatile uint8_t g_3159[3][4][2] = {{{0x8AL,0x8AL},{0x8AL,0x8AL},{0x8AL,0x8AL},{0x8AL,0x8AL}},{{0x8AL,0x8AL},{0x8AL,0x8AL},{0x8AL,0x8AL},{0x8AL,0x8AL}},{{0x8AL,0x8AL},{0x8AL,0x8AL},{0x8AL,0x8AL},{0x8AL,0x8AL}}};
static uint8_t g_3782 = 0xD9L;
static int16_t g_3901 = (-3L);
static volatile int8_t g_3903 = 0x93L;
static int32_t g_4123 = 4L;



static uint16_t func_1(void);
static uint8_t func_10(int16_t p_11, int8_t p_12);
static int8_t func_13(uint16_t p_14, int16_t p_15, int32_t p_16);
static int8_t func_17(int32_t p_18, uint8_t p_19, uint16_t p_20, int8_t p_21);
static uint16_t func_23(int32_t p_24);
static int8_t func_47(int16_t p_48);
static int16_t func_55(int16_t p_56);
inline static int16_t func_60(uint8_t p_61, uint8_t p_62);
static uint32_t func_64(int32_t p_65, int16_t p_66);
inline static int32_t func_70(int16_t p_71, uint8_t p_72);
static uint16_t func_1(void)
{
    int16_t l_2 = 0x8A1FL;
    int16_t l_22 = (-1L);
    int32_t l_4309 = 0xCC5AFC00L;
    int32_t l_4310 = 0xDB3F08D2L;
    int32_t l_4311[3];
    uint32_t l_4312 = 4294967293UL;
    int i;
    for (i = 0; i < 3; i++)
        l_4311[i] = 0L;
    g_2236[1] = ((l_2 , (safe_add_func_int32_t_s_s(g_5, l_2))) > (l_4311[0] = (l_4310 = (1L == (safe_lshift_func_uint16_t_u_u(9UL, (safe_mod_func_int32_t_s_s((((l_4309 = ((func_10((func_13(g_5, g_5, (((func_17((g_35 = (g_34[5] = (l_22 & (g_33 = (func_23(((((safe_lshift_func_uint16_t_u_u(((g_27[2][0] = g_5) <= l_2), 9)) & 0x9E17L) , g_27[2][0]) | g_5)) , g_32[1][0]))))), g_5, g_5, g_5) <= 1L) != g_5) <= l_2)) , g_247), l_2) , 0xB8L) != l_22)) , 255UL) >= g_3901), g_3045[2][3]))))))));
    g_5 = l_4312;
    return g_2084;
}







static uint8_t func_10(int16_t p_11, int8_t p_12)
{
    uint32_t l_4281[8] = {0x57F96573L,0x57F96573L,0x57F96573L,0x57F96573L,0x57F96573L,0x57F96573L,0x57F96573L,0x57F96573L};
    int32_t l_4282 = 0x47CA2331L;
    int i;
    if ((g_897[0][2] = g_2222))
    {
        int32_t l_4253 = 0x298E0FB6L;
        int32_t l_4256 = 0xE99E48B2L;
        uint8_t l_4307 = 255UL;
        l_4253 = (g_1472 = (p_11 > 0x7F83L));
        l_4253 = ((((safe_sub_func_int32_t_s_s((5UL ^ l_4256), ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s(1UL, 11)) && 0xD98578FCL) & 1L), (+(((safe_add_func_int32_t_s_s((l_4282 = (((safe_unary_minus_func_int32_t_s((g_897[0][2] = ((((safe_mod_func_int32_t_s_s((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((((safe_lshift_func_uint8_t_u_s(((safe_add_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((((g_427[1] = (safe_sub_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_s((l_4281[5] != (-2L)), 7)) <= (((((g_1472 >= g_2084) , g_317) | g_1044) < l_4281[5]) < g_203)), p_11))) , p_11) , l_4281[2]), 3)), g_504[1][1][2])) | l_4253), g_27[2][0])) , p_12) && l_4281[2]), 4)), (-10L))), 0x774942A1L)) , l_4281[3]) | 4294967295UL) || 0x3866562AL)))) != 0x91L) , p_12)), p_12)) || 1L) <= g_250[0][1])))) <= l_4256) >= 0x64BCL) != g_3003) , (-10L)) < p_12))) , 0xF0E3L) | g_1669) , p_11);
        l_4282 = (p_12 , (p_11 & 0x9BAEL));
        g_4123 = ((((p_12 & (g_315 > (g_127 = p_11))) , ((!p_12) , ((safe_rshift_func_int16_t_s_u(p_11, 7)) | (safe_lshift_func_uint16_t_u_u(((l_4253 = ((safe_mod_func_uint8_t_u_u(((((safe_rshift_func_int8_t_s_s(((((safe_lshift_func_uint16_t_u_u(((safe_sub_func_uint16_t_u_u(p_11, ((safe_sub_func_uint32_t_u_u(p_11, ((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((+((safe_sub_func_uint32_t_u_u(4294967293UL, (safe_sub_func_int8_t_s_s(l_4281[1], l_4253)))) && 0x37L)), l_4253)) == p_12), g_427[1])) <= p_11) <= 1UL) < g_35))) > g_400))) == g_247), 6)) & l_4281[1]) && g_486) >= g_86), 4)) & 0xA7L) > (-5L)) , g_769), 5L)) < l_4282)) , l_4253), g_250[0][1]))))) & l_4281[5]) && l_4307);
    }
    else
    {
        int32_t l_4308 = 0L;
        l_4308 = (l_4308 && 0xCC7A4D59L);
    }
    return p_12;
}







static int8_t func_13(uint16_t p_14, int16_t p_15, int32_t p_16)
{
    int32_t l_4246 = 0L;
    int8_t l_4251 = 0x9DL;
    int32_t l_4252 = 0xE648F05DL;
    for (g_132 = 0; (g_132 <= 1); g_132 += 1)
    {
        return l_4246;
    }
    g_897[1][0] = (l_4252 = ((p_16 ^ (4L != (((l_4246 && ((g_34[3] = (safe_sub_func_int8_t_s_s((g_486 && (4294967295UL == (4294967295UL > 6UL))), 1L))) > ((g_456 = p_15) >= g_250[0][1]))) | l_4251) && g_1669))) | p_16));
    return g_344;
}







static int8_t func_17(int32_t p_18, uint8_t p_19, uint16_t p_20, int8_t p_21)
{
    uint16_t l_38 = 5UL;
    int32_t l_49[7];
    uint32_t l_3367 = 7UL;
    int32_t l_3529 = 0xC57B773AL;
    int32_t l_3859 = (-8L);
    uint16_t l_3864 = 65535UL;
    uint8_t l_3883 = 0UL;
    uint32_t l_3899[4];
    uint32_t l_3900[10] = {2UL,4294967287UL,2UL,4294967287UL,2UL,4294967287UL,2UL,4294967287UL,2UL,4294967287UL};
    int8_t l_3902 = (-1L);
    uint8_t l_3920 = 0x5FL;
    int32_t l_4026[8][10] = {{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L},{1L,(-1L),0xCFB9124BL,(-1L),1L,0L,7L,0x71610FDFL,7L,0L}};
    int32_t l_4070 = (-5L);
    int32_t l_4073 = 0L;
    int16_t l_4244 = 0L;
    int i, j;
    for (i = 0; i < 7; i++)
        l_49[i] = (-1L);
    for (i = 0; i < 4; i++)
        l_3899[i] = 0x95EF2DB8L;
    if ((l_49[6] = ((func_23((safe_rshift_func_int8_t_s_u(0x3BL, l_38))) <= (safe_unary_minus_func_int8_t_s(0x8EL))) , (safe_lshift_func_int16_t_s_s(l_38, (safe_rshift_func_uint8_t_u_s(((g_44 == 0L) && (safe_rshift_func_int8_t_s_u(func_47(func_23(p_18)), l_38))), 6)))))))
    {
        uint32_t l_54 = 0x5309F33DL;
        int32_t l_3177 = 0x39EDE1A3L;
        int32_t l_3184 = 0x492AE369L;
        int32_t l_3187 = 0x18D23FFAL;
        int32_t l_3313 = 0x0372B97CL;
        uint32_t l_3316 = 4294967295UL;
        uint16_t l_3496 = 65531UL;
        uint32_t l_3534 = 0x7FC14EECL;
        int8_t l_3596 = (-1L);
        uint8_t l_3664[9][10][1] = {{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}},{{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL},{0xC0L},{2UL}}};
        int32_t l_3680[3][2];
        uint32_t l_3704 = 0x260F5791L;
        int32_t l_3726 = 0x06134ACAL;
        int8_t l_4168 = (-6L);
        int16_t l_4221 = 0x4A0BL;
        int32_t l_4237 = 3L;
        int i, j, k;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
                l_3680[i][j] = 0L;
        }
lbl_3520:
        for (p_21 = 0; (p_21 <= (-24)); p_21 = safe_sub_func_int32_t_s_s(p_21, 4))
        {
            uint16_t l_52 = 0x102DL;
            int32_t l_3136 = 0x078473D5L;
            int32_t l_3228[9][1];
            int32_t l_3229 = (-7L);
            uint8_t l_3341 = 0xB6L;
            uint32_t l_3410 = 4UL;
            int i, j;
            for (i = 0; i < 9; i++)
            {
                for (j = 0; j < 1; j++)
                    l_3228[i][j] = 0x5F7A6B63L;
            }
            g_53 = l_52;
            l_54 = p_21;
            if ((((g_5 , func_55(p_21)) != (((((safe_sub_func_uint16_t_u_u(g_692, (safe_sub_func_int32_t_s_s((((p_19 | ((((7UL ^ l_54) <= (0x57E4L <= l_52)) & g_5) | l_52)) && l_3136) && (-3L)), 0x5D88587AL)))) ^ 0xCEL) > g_692) , l_52) <= (-3L))) , g_86))
            {
                uint16_t l_3137[10][10] = {{65535UL,0x714FL,0x714FL,65535UL,0UL,65528UL,65535UL,65528UL,0UL,65535UL},{65528UL,65535UL,65528UL,0UL,65535UL,0x714FL,0x714FL,65535UL,0UL,65528UL},{0x45B7L,0x45B7L,0x85F2L,65535UL,1UL,0x85F2L,1UL,65535UL,0x85F2L,0x45B7L},{1UL,0x714FL,65528UL,1UL,0UL,0UL,1UL,65528UL,0x714FL,1UL},{65528UL,0x45B7L,0x714FL,0UL,0x45B7L,0UL,0x714FL,0x45B7L,65528UL,65528UL},{1UL,65535UL,0x85F2L,0x45B7L,0x45B7L,0x85F2L,65535UL,1UL,0x85F2L,1UL},{0x45B7L,0x714FL,0UL,0x45B7L,0UL,0x714FL,0x45B7L,65528UL,65528UL,0x45B7L},{65528UL,1UL,0UL,0UL,1UL,65528UL,0x714FL,1UL,0x714FL,65528UL},{65535UL,1UL,0x85F2L,1UL,65535UL,0x85F2L,0x45B7L,0x45B7L,0x85F2L,65535UL},{65535UL,0x714FL,0x714FL,65535UL,0UL,65528UL,65535UL,65528UL,0UL,65535UL}};
                int32_t l_3160[1];
                int32_t l_3207 = 0xB7AA850CL;
                int32_t l_3227 = 0xCBA64E35L;
                int i, j;
                for (i = 0; i < 1; i++)
                    l_3160[i] = 0x4F1B40D7L;
                l_3136 = ((p_19 = (((l_3137[5][3] , ((+(0xC1244286L == ((l_38 < ((safe_rshift_func_int8_t_s_u(((safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(((-1L) | (l_3160[0] = (((safe_mod_func_int32_t_s_s((((p_19 && ((safe_lshift_func_uint16_t_u_s(((l_49[3] = (g_456 = l_38)) & p_19), 11)) <= (safe_rshift_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(((g_1472 = (safe_lshift_func_int8_t_s_s(p_19, 1))) , (((safe_mod_func_uint32_t_u_u((p_18 && 1UL), l_3136)) , p_19) == 249UL)), p_21)) > l_3137[4][3]), p_18)))) || p_18) > l_3137[5][3]), l_52)) > g_3159[1][3][0]) < g_2942))), l_52)), p_19)) < l_52), l_54)) && p_19), p_21)) == 65527UL)) != p_21))) , p_20)) , g_185[0][3][0]) || 0xF47BL)) <= 0x01L);
                if (g_2729[1][2])
                {
                    int8_t l_3185 = 1L;
                    int32_t l_3186 = (-1L);
                    for (g_1363 = 1; (g_1363 >= 0); g_1363 -= 1)
                    {
                        int i;
                        return g_183[(g_1363 + 1)];
                    }
                    l_3187 = (g_693[1] || ((safe_lshift_func_int8_t_s_u((0x1552L <= (g_53 = ((safe_mod_func_int16_t_s_s(((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(1UL, 7)), ((((safe_mod_func_uint32_t_u_u((l_3186 = (l_3185 = ((g_86 = (0L && (g_3159[1][3][0] == (((l_3184 = ((safe_mod_func_int16_t_s_s((l_3177 = 0x59C5L), (g_27[0][0] & (((safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_s((((((p_21 & g_1472) ^ g_183[9]) & g_1138) ^ g_183[5]) != (-7L)), 0)) || 0L), l_49[3])) & g_2084) != l_3136)))) , l_3136)) == 0xAC8D55A1L) < 0xD267D03DL)))) & l_3160[0]))), g_35)) > g_185[0][8][1]) == 1UL) != 0x1D1A26F7L))), 9L)), l_38)) > g_183[3]), l_54)) & 251UL))), g_2084)) > p_19));
                    for (l_3187 = 0; (l_3187 > 28); ++l_3187)
                    {
                        uint16_t l_3206 = 0xAC21L;
                        l_3136 = (safe_lshift_func_int8_t_s_s((p_19 > (((g_1472 || (l_3207 = (g_203 && (safe_rshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_u((((l_3160[0] = (safe_add_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u(l_3160[0], 1)) < ((safe_mod_func_uint8_t_u_u((g_185[0][6][1] = ((safe_add_func_uint32_t_u_u(1UL, ((l_3185 != (safe_lshift_func_uint16_t_u_s(g_400, 10))) < g_739))) >= p_19)), l_3206)) > 0x936BL)), g_2729[2][4]))) , l_3160[0]) | 65535UL), 7)), g_35))))) , p_19) || p_21)), l_52));
                    }
                }
                else
                {
                    l_3187 = 0x4A702519L;
                    if (g_427[1])
                        break;
                }
                for (l_3184 = 8; (l_3184 > 1); l_3184 = safe_sub_func_uint8_t_u_u(l_3184, 3))
                {
                    uint8_t l_3213 = 0xEEL;
                    int32_t l_3226 = (-2L);
                    l_3136 = ((l_3136 & (g_344 = 1L)) >= (l_3229 = (l_3228[3][0] = (+((safe_sub_func_uint16_t_u_u((l_3213 || (l_3160[0] = (((g_456 , (safe_rshift_func_int8_t_s_s(((l_3226 = (safe_add_func_uint8_t_u_u((p_19 = (((5UL != (g_918[4][0][2] > (((safe_sub_func_int32_t_s_s(g_566, (safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((p_20 >= (safe_mod_func_int32_t_s_s(g_427[0], 4294967287UL))), l_3137[7][5])), p_21)))) && l_52) < l_49[1]))) && 0x7EL) | 0x2F1FL)), g_2729[0][4]))) >= 0x0EL), 5))) < 0xC4F36B91L) & 65535UL))), l_3227)) != p_20)))));
                    if (p_18)
                        break;
                    if (g_185[0][0][1])
                        break;
                    l_3160[0] = (safe_rshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_s((1UL == p_21), 1)), 8));
                }
            }
            else
            {
                int32_t l_3265 = 0x25513B13L;
                int32_t l_3279 = 0xAC65A78DL;
                int16_t l_3312 = 2L;
                for (p_18 = 0; (p_18 >= 0); p_18 -= 1)
                {
                    uint16_t l_3243 = 0UL;
                    int32_t l_3260 = (-1L);
                    g_2942 = ((((safe_sub_func_int16_t_s_s(0L, ((l_3187 = ((((0xAAL <= p_20) >= 0xA59EAFF5L) >= (((0L == 3UL) == ((safe_mod_func_int16_t_s_s((!(safe_sub_func_uint32_t_u_u((g_183[9] | g_2236[0]), ((safe_sub_func_uint32_t_u_u((((0x1AEDE846L > p_19) ^ 0xDBL) , 9UL), p_18)) > p_18)))), l_3184)) == l_3243)) >= p_19)) ^ g_185[0][6][1])) <= g_27[0][0]))) ^ (-1L)) , p_18) , p_19);
                    if (p_19)
                        continue;
                    l_3184 = l_49[6];
                    for (g_456 = 0; (g_456 <= 0); g_456 += 1)
                    {
                        int32_t l_3259 = 1L;
                        l_3184 = (safe_lshift_func_uint8_t_u_u((l_49[6] = (safe_add_func_int32_t_s_s((l_3259 = ((((((g_132 = 0x83L) , (g_577 <= l_38)) || ((l_3260 = ((((((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_u(0x4EBFL, 5)) >= (~(((safe_add_func_uint8_t_u_u(l_3243, 0x29L)) | 1L) || (g_504[5][1][2] = ((((safe_lshift_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((0x18A1L || (p_21 != 0xEA7EC26AL)), 0x5B78L)), 1)) ^ 0xB009L) <= 0xC3D70109L) > 0x1CL))))), p_19)) == 0x8AL) | l_3259) || l_3243) <= g_1669) | 0UL)) , p_21)) & p_21) > l_54) != p_19)), 0L))), p_21));
                        return p_18;
                    }
                }
                l_3184 = ((p_19 , p_18) || (l_3265 = (safe_unary_minus_func_uint32_t_u((~((safe_sub_func_uint16_t_u_u(p_18, g_427[1])) || (l_3136 = p_19)))))));
                if (l_38)
                {
                    int32_t l_3268 = 0xD7C27A7FL;
                    uint16_t l_3278 = 0x6A8EL;
                    for (l_54 = 29; (l_54 >= 7); l_54 = safe_sub_func_uint16_t_u_u(l_54, 6))
                    {
                        if (l_3268)
                            break;
                        return g_897[0][2];
                    }
                    if ((!((g_2236[1] == ((((g_317 = (safe_add_func_int32_t_s_s((l_3265 = (safe_mod_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((p_21 != (g_34[5] = (((g_276 = (l_49[6] = p_20)) != 0x119C1A0FL) & ((safe_rshift_func_uint8_t_u_u(((p_21 > (p_21 < (g_692 <= p_20))) , ((g_35 != g_739) <= l_3268)), 3)) < 0x90F04890L)))), l_3177)), 249UL))), g_972))) > l_3278) <= l_3279) | 7UL)) <= p_18)))
                    {
                        g_897[1][2] = p_20;
                    }
                    else
                    {
                        int8_t l_3311[3];
                        int32_t l_3314 = 1L;
                        uint8_t l_3315 = 1UL;
                        int i;
                        for (i = 0; i < 3; i++)
                            l_3311[i] = 0x8EL;
                        l_3316 = ((g_639 = (((safe_add_func_int8_t_s_s(((p_19 <= ((safe_add_func_uint16_t_u_u(((safe_add_func_uint16_t_u_u((0UL >= (safe_rshift_func_uint8_t_u_s((l_3314 = (safe_mod_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(p_19, (((safe_add_func_uint8_t_u_u((((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_s((g_419 = (((l_49[1] = ((safe_sub_func_int32_t_s_s(l_3279, ((+g_820) & l_3177))) != ((safe_rshift_func_int16_t_s_u(l_3265, (g_391 = ((safe_mod_func_uint16_t_u_u((((safe_mod_func_uint8_t_u_u((((safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s(0x6775L, l_3311[2])), p_19)) <= p_21) , 255UL), p_19)) == l_3268) < p_21), g_126)) || l_3312)))) || 0x1285L))) || 0xD7L) | (-1L))), g_486)) || 0x8F1EL), 0UL)) <= l_3313) < g_692), p_18)) && g_897[0][0]) == p_21))), g_897[0][2]))), l_54))), l_3315)) != 4294967295UL), l_3311[2])) , 0x6294578FL)) ^ (-8L)), g_1472)) > l_38) ^ 248UL)) , l_3314);
                    }
                    l_49[6] = (((safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((((safe_mod_func_int8_t_s_s(((g_2942 = (safe_add_func_uint8_t_u_u((((safe_sub_func_uint32_t_u_u((l_3136 != p_20), l_3313)) , 0x23005C01L) , (g_86 <= (g_504[8][2][0] , ((safe_sub_func_uint8_t_u_u((((g_3045[1][2] , p_18) && (safe_sub_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((((((safe_add_func_int16_t_s_s((l_3268 < g_769), l_49[6])) ^ g_32[1][0]) & g_449) || 0xEDL) >= l_52), 1L)), l_54)), p_20))) >= 0x5E3494E1L), l_3265)) > p_19)))), (-1L)))) != l_3136), 1L)) , p_19) >= g_739), l_3341)), l_49[6])), 0x74884F53L)), p_19)) & 2L) , 0x4F471843L);
                    g_897[1][1] = l_49[6];
                }
                else
                {
                    int16_t l_3356 = 1L;
                    l_49[5] = g_693[0];
                    l_3229 = (safe_rshift_func_uint8_t_u_s((safe_add_func_int32_t_s_s((p_20 > (safe_lshift_func_uint16_t_u_u(l_3313, (safe_add_func_uint8_t_u_u(246UL, ((safe_lshift_func_int8_t_s_s(0xA2L, 6)) >= (safe_mod_func_uint32_t_u_u((1L != (l_54 >= 0UL)), (safe_lshift_func_int16_t_s_u(l_3356, 11)))))))))), ((!((((l_3187 = (g_1044 < p_20)) && p_18) && 0L) > g_108)) , g_126))), 7));
                }
            }
            for (g_2942 = 0; (g_2942 > 7); g_2942 = safe_add_func_int8_t_s_s(g_2942, 8))
            {
                uint8_t l_3378 = 0xF5L;
                int32_t l_3383 = 0x58D15DD0L;
                int32_t l_3435 = 0L;
                int32_t l_3498 = 1L;
                if (l_3136)
                    break;
                l_3136 = ((((safe_mod_func_int16_t_s_s(((-1L) >= (g_127 = 0xEB9EDD85L)), p_21)) & l_3187) >= ((g_2222 = (safe_sub_func_int16_t_s_s(l_54, (g_2222 != ((((l_3184 = ((p_20 > ((safe_lshift_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u((l_54 & g_419))), g_739)) <= 0xFAL)) < l_3367)) <= l_3229) == l_3187) || g_897[0][2]))))) != 0x867D9309L)) <= 0x72L);
                for (g_276 = 0; (g_276 <= 1); g_276 += 1)
                {
                    int16_t l_3422 = (-3L);
                    int32_t l_3434 = 1L;
                    int8_t l_3463 = 0L;
                    int i, j, k;
                    if (((l_3383 = (safe_rshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s(0xD8L, (p_19 = (l_3136 = (((-1L) > g_918[(g_276 + 2)][g_276][(g_276 + 4)]) ^ (((65527UL > (safe_sub_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((l_3378 == (250UL || (((safe_sub_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(((p_18 & 2L) <= (g_2222 = (-1L))), 0x6680B4B5L)), 0UL)) ^ l_3313) <= (-5L)))), 4294967290UL)) >= l_38), (-1L))), p_19))) < g_2729[1][4]) & g_897[0][2])))))), 0))) && g_918[(g_276 + 2)][g_276][(g_276 + 4)]))
                    {
                        int16_t l_3390 = 0xF395L;
                        g_2236[1] = (((p_20 = (safe_lshift_func_int8_t_s_u(g_692, 3))) != ((safe_mod_func_uint32_t_u_u((p_18 <= (-6L)), (l_3390 = l_3229))) | (l_49[5] = ((l_3383 = (l_3184 = (-8L))) , (!7L))))) <= 0x703F0452L);
                        if (g_203)
                            continue;
                    }
                    else
                    {
                        uint16_t l_3409 = 65530UL;
                        int32_t l_3411 = 0x80F8D9CDL;
                        int16_t l_3425 = 0L;
                        g_2236[3] = (safe_mod_func_uint8_t_u_u(((0x19F5E0A9L & ((safe_sub_func_uint16_t_u_u(((0xF1756D2CL && (g_972 = (safe_lshift_func_int8_t_s_u((l_3409 = (((safe_rshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u(((g_1472 = p_21) || p_21), ((((l_3184 = l_54) || (l_49[0] = (safe_mod_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((-4L), (~0x5BA3L))), p_19)))) && (safe_lshift_func_int16_t_s_u(p_19, g_1363))) >= g_486))), l_3187)) >= g_2222) | 0xA6L)), l_3136)))) & l_3228[7][0]), p_18)) || l_3410)) <= g_499), l_3411));
                        l_3184 = (safe_sub_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_s(((safe_mod_func_int8_t_s_s(0x49L, ((safe_mod_func_uint32_t_u_u((((safe_mod_func_int32_t_s_s(l_3422, (safe_sub_func_int8_t_s_s(l_3425, (((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint8_t_u_s((safe_sub_func_int32_t_s_s((-5L), (l_38 , (p_20 > 1L)))), 1)) && (g_298 ^ (safe_lshift_func_int16_t_s_s((l_3435 = ((g_35 & l_3434) & 5UL)), g_3003)))), g_419)) , p_20) && 0x96L))))) < p_20) <= p_21), 0x955773ADL)) | l_3425))) ^ 0x234FL), l_3177)) < 65535UL), 0xBF75L));
                        l_3184 = 0x4E8D4287L;
                    }
                    if (((g_298 < (safe_mod_func_uint8_t_u_u((l_38 || 0x08L), ((safe_sub_func_uint32_t_u_u((((((!(((safe_rshift_func_int8_t_s_u(1L, (safe_sub_func_uint32_t_u_u((((safe_mod_func_int32_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(((p_20 = ((safe_add_func_uint32_t_u_u(0xFE74E8F9L, (safe_rshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u((l_49[6] = (safe_add_func_int16_t_s_s(l_3378, ((l_3383 < ((l_3435 = (safe_add_func_int32_t_s_s(((safe_sub_func_uint8_t_u_u((4294967295UL < 0x6362C195L), 0xD1L)) != g_1001), p_18))) && l_3228[3][0])) | p_20)))), 1L)), g_2729[0][4])))) , l_3463)) >= p_18), 6)), g_108)), 0x612774E4L)) || g_276) == p_19), 1L)))) , g_32[4][0]) > p_19)) & l_3378) & 1L) != p_18) | g_3045[2][4]), (-1L))) , l_3313)))) == l_3184))
                    {
                        int32_t l_3465 = 0x58567D96L;
                        int32_t l_3494 = 0x591F0493L;
                        int32_t l_3495 = (-4L);
                        int32_t l_3497 = 0x333383BBL;
                        l_3497 = (((~((p_20 , g_897[0][2]) > l_3465)) < (((((safe_rshift_func_uint16_t_u_u(((safe_add_func_uint32_t_u_u((l_3434 = (safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u((((l_3495 = (((safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint16_t_u_u(((p_21 >= (safe_add_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((((safe_lshift_func_uint16_t_u_s((l_3184 = 0xA7EFL), 7)) != g_1044) != p_20), 11)) == ((safe_sub_func_int32_t_s_s(g_44, (l_3494 = ((safe_unary_minus_func_int8_t_s(((safe_add_func_uint8_t_u_u(((safe_mod_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((!65526UL) || g_391), l_3383)), l_3367)) < g_34[5]), g_972)) >= g_127))) & 0x70C0L)))) <= g_692)), 1UL))) , g_1138), 0x5AFEL)) , l_3341), p_20)) > l_3422) != 0x771EL)) || g_35) && 0xF24EBB3EL), l_3496)) >= 0xB71ECC7FL), 3))), g_315)) == p_18), g_34[6])) , 0x54L) | g_693[1]) || p_21) || g_132)) == 0x8A22BFF7L);
                        l_49[6] = ((((l_3498 | ((((((((g_250[0][1] , ((+4UL) ^ (safe_sub_func_int16_t_s_s(l_3136, 0L)))) != ((g_2729[2][6] = 0x0FBCL) | g_692)) , (!((((1L != (safe_sub_func_uint32_t_u_u(p_18, p_19))) < g_183[9]) & g_127) < 0x2833D95DL))) > 0x667D3430L) == 0xC7L) || l_3494) <= l_49[3]) , g_427[2])) , 247UL) < p_19) <= 0xCD2BL);
                    }
                    else
                    {
                        if (g_1001)
                            break;
                        g_2222 = (safe_rshift_func_int16_t_s_s(p_20, 0));
                    }
                }
            }
        }
        for (g_53 = 0; (g_53 != 13); ++g_53)
        {
            uint8_t l_3519 = 0xC3L;
            int32_t l_3593[5][9][5] = {{{(-1L),5L,(-1L),0xEFF4038FL,0L},{(-10L),(-4L),0x3D12D6ACL,0x3D12D6ACL,0xF7B9C197L},{2L,0xEFF4038FL,5L,0xEFF4038FL,2L},{0xF7B9C197L,0x3D12D6ACL,0x946D202EL,0xF7B9C197L,(-4L)},{(-1L),0xC8EA268AL,5L,0xEFF4038FL,5L},{(-4L),(-4L),0x4D03646FL,0x3D12D6ACL,(-4L)},{(-9L),0xEFF4038FL,(-9L),0xC8EA268AL,2L},{(-4L),0x946D202EL,0x946D202EL,(-4L),0xF7B9C197L},{(-1L),0xEFF4038FL,0L,0xEFF4038FL,(-1L)}},{{0xF7B9C197L,(-4L),0x946D202EL,0x946D202EL,(-4L)},{2L,0xC8EA268AL,(-9L),0xEFF4038FL,(-9L)},{(-4L),0x3D12D6ACL,0x4D03646FL,(-4L),(-4L)},{5L,0xEFF4038FL,5L,0xC8EA268AL,(-1L)},{(-4L),0xF7B9C197L,0x946D202EL,0x3D12D6ACL,0xF7B9C197L},{2L,0xEFF4038FL,5L,0xEFF4038FL,2L},{0xF7B9C197L,0x3D12D6ACL,0x946D202EL,0xF7B9C197L,(-4L)},{(-1L),0xC8EA268AL,5L,0xEFF4038FL,5L},{(-4L),(-4L),0x4D03646FL,0x3D12D6ACL,(-4L)}},{{(-9L),0xEFF4038FL,(-9L),0xC8EA268AL,2L},{(-4L),0x946D202EL,0x946D202EL,(-4L),0xF7B9C197L},{(-1L),0xEFF4038FL,0L,0xEFF4038FL,(-1L)},{0xF7B9C197L,(-4L),0x946D202EL,0x946D202EL,(-4L)},{2L,0xC8EA268AL,(-9L),0xEFF4038FL,(-9L)},{(-4L),0x3D12D6ACL,0x4D03646FL,(-4L),(-4L)},{5L,0xEFF4038FL,5L,0xC8EA268AL,(-1L)},{(-4L),0xF7B9C197L,0x946D202EL,0x3D12D6ACL,0xF7B9C197L},{2L,0xEFF4038FL,5L,0xEFF4038FL,2L}},{{0xF7B9C197L,0x3D12D6ACL,0x946D202EL,0xF7B9C197L,(-4L)},{(-1L),0xC8EA268AL,5L,0xEFF4038FL,5L},{(-4L),(-4L),0x4D03646FL,0x3D12D6ACL,(-4L)},{(-9L),0xEFF4038FL,(-9L),0xC8EA268AL,2L},{(-4L),0x946D202EL,0x946D202EL,(-4L),0xF7B9C197L},{(-1L),0xEFF4038FL,0L,0xEFF4038FL,(-1L)},{0xF7B9C197L,(-4L),0x946D202EL,0x946D202EL,(-4L)},{2L,0xC8EA268AL,(-9L),0xEFF4038FL,(-9L)},{(-4L),0x3D12D6ACL,0x4D03646FL,(-4L),(-4L)}},{{5L,0xEFF4038FL,5L,0xC8EA268AL,(-1L)},{(-4L),0xF7B9C197L,0x946D202EL,0x3D12D6ACL,0xF7B9C197L},{2L,0xEFF4038FL,5L,0xEFF4038FL,2L},{0xF7B9C197L,0x3D12D6ACL,0x946D202EL,0xF7B9C197L,0xF7B9C197L},{5L,5L,0L,0xC8EA268AL,0L},{0xF7B9C197L,0xF7B9C197L,0x3D12D6ACL,0x946D202EL,0xF7B9C197L},{5L,0xC8EA268AL,5L,5L,(-9L)},{0xF7B9C197L,0x4D03646FL,0x4D03646FL,0xF7B9C197L,(-10L)},{5L,0xC8EA268AL,(-1L),0xC8EA268AL,5L}}};
            int16_t l_3594 = 0L;
            int16_t l_3688 = 0x71C1L;
            int32_t l_3784[7] = {0x31260953L,0x31260953L,0x31260953L,0x31260953L,0x31260953L,0x31260953L,0x31260953L};
            uint32_t l_3884 = 0x6E5D0E77L;
            uint32_t l_3885 = 0x4294023EL;
            int16_t l_3940 = 0x152DL;
            int32_t l_3969 = (-1L);
            uint8_t l_4140 = 0x38L;
            int i, j, k;
            if (((((0xBEL > (p_19 = (((safe_rshift_func_uint16_t_u_s((((g_317 = (((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int16_t_s_s(1L, (g_298 = (((((l_3367 && 1L) == 65529UL) & (safe_lshift_func_int8_t_s_s(0xF3L, p_18))) | (0xB00FL > ((g_639 = ((((((((safe_rshift_func_int16_t_s_u(((g_486 < g_504[0][7][1]) > 0xB2L), 3)) == g_400) & l_3187) < p_19) | l_3519) , l_49[6]) & 4294967295UL) != g_203)) || 0x21E34445L))) == l_49[5])))), 5)) ^ g_1138) <= g_247) != 0x8D8C20F0L) | p_21)) , 0UL) <= l_3367), l_3519)) ^ 0x475E0D25L) >= p_20))) >= g_427[2]) <= p_21) <= p_21))
            {
                return l_3519;
            }
            else
            {
                int32_t l_3525 = 0x3C905A4AL;
                int32_t l_3563 = 1L;
                if (g_35)
                    break;
                if (l_3496)
                    goto lbl_3520;
                for (g_315 = 13; (g_315 != (-12)); g_315 = safe_sub_func_uint8_t_u_u(g_315, 4))
                {
                    int16_t l_3535 = (-4L);
                    g_2942 = ((((((safe_add_func_int8_t_s_s((p_21 < (l_3525 == 0UL)), 9UL)) , (safe_rshift_func_uint8_t_u_u((0x0BL < (safe_unary_minus_func_int32_t_s((((l_3529 , p_19) <= (safe_mod_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((g_2729[0][4] | p_18), l_3525)), p_18))) && l_3525)))), l_3534))) <= l_3535) > p_19) == l_3519) && 255UL);
                }
                for (p_18 = 0; (p_18 == (-13)); p_18 = safe_sub_func_int16_t_s_s(p_18, 7))
                {
                    int8_t l_3559[8][10] = {{0x1AL,0x6AL,8L,9L,0x69L,9L,8L,0x6AL,0x1AL,(-1L)},{0L,(-1L),(-1L),6L,0L,0x05L,0x5BL,0x69L,0x69L,0x5BL},{0x6AL,0L,6L,6L,0L,0x6AL,3L,0x05L,0x1AL,0x4EL},{0x4EL,0x69L,(-1L),9L,(-1L),8L,0x6AL,8L,(-1L),9L},{0x4EL,8L,0x4EL,0xDCL,0x5BL,0x6AL,9L,0L,(-1L),0x05L},{0x6AL,9L,0L,(-1L),0x05L,0x05L,(-1L),0L,9L,0x6AL},{0L,0xABL,0x4EL,0x69L,(-1L),9L,(-1L),8L,0x6AL,8L},{0x1AL,0x4EL,(-1L),0xABL,(-1L),0x4EL,0x1AL,0x05L,3L,0x6AL}};
                    int i, j;
                    for (l_3177 = 23; (l_3177 >= 10); l_3177--)
                    {
                        uint32_t l_3560[1][2];
                        uint32_t l_3561 = 0xE3826135L;
                        int32_t l_3562 = (-1L);
                        int i, j;
                        for (i = 0; i < 1; i++)
                        {
                            for (j = 0; j < 2; j++)
                                l_3560[i][j] = 4294967291UL;
                        }
                        l_3563 = (safe_mod_func_int16_t_s_s((0x8C18EE45L ^ (p_20 , (((((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_uint16_t_u_u(((l_3529 = ((g_1472 , (g_400 & (l_3562 = (((l_3184 = ((safe_sub_func_uint32_t_u_u(((((safe_lshift_func_uint16_t_u_u((0UL != 0x8EL), 11)) , (safe_add_func_uint8_t_u_u(((p_18 , (g_1472 != ((((l_3561 = (safe_sub_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_u((((l_3560[0][0] = ((safe_mod_func_uint16_t_u_u(g_34[5], l_3559[3][3])) & l_3519)) , l_3519) , 0x27L), l_3559[3][3])) | (-1L)), 0xB6L))) < g_639) , p_19) > g_298))) & 0xD9L), p_19))) , l_3519) > p_20), p_19)) && p_19)) && l_3559[5][1]) == 0xAA0BL)))) > p_18)) , g_577), p_21)) | (-5L)))), 0UL)) < (-10L)) <= 0xA3AEL) | 0x20DAL) , g_34[5]))), 8L));
                        l_3562 = (safe_rshift_func_uint8_t_u_s(255UL, 1));
                    }
                    if (l_54)
                        break;
                }
            }
            if ((247UL != (((g_391 || (safe_rshift_func_int16_t_s_s(((0xD2L & (safe_lshift_func_uint8_t_u_s((((l_3519 != (safe_unary_minus_func_uint32_t_u((safe_lshift_func_int8_t_s_u(((((((safe_rshift_func_int8_t_s_s(((safe_lshift_func_int16_t_s_s(((((g_185[1][3][0] == (safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((!l_54), 0)), (((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u((l_3593[4][5][2] = (safe_mod_func_int32_t_s_s(((((safe_mod_func_int8_t_s_s((l_3534 && g_34[5]), (l_3184 = (safe_lshift_func_uint16_t_u_s(g_419, 1))))) != g_3045[1][2]) & p_19) <= g_2084), g_1044))))), 0UL)), 2)) ^ 0xE050035FL) || 0xF0L)))) & p_21) && 0xA980L) , 0L), 3)) < l_3177), 6)) , g_391) ^ p_19) , p_20) < l_3496) == g_503), 7))))) > g_1363) && 65535UL), l_3594))) >= 0xEDE8B281L), p_21))) , 1UL) & l_3187)))
            {
                int32_t l_3633 = 0xA391FEF8L;
                int32_t l_3634 = (-1L);
                int8_t l_3635 = 0xD4L;
                int16_t l_3663[3];
                int32_t l_3665 = 0xEA6BB433L;
                uint8_t l_3666 = 0xE2L;
                uint16_t l_3667 = 0x217AL;
                uint32_t l_3669[4] = {0UL,0UL,0UL,0UL};
                int i;
                for (i = 0; i < 3; i++)
                    l_3663[i] = (-1L);
                l_3593[4][5][2] = (g_2222 || (g_247 = ((l_3594 | g_3003) != ((((safe_unary_minus_func_uint32_t_u((l_3596 >= ((safe_add_func_uint16_t_u_u((g_108 = 0x9841L), ((g_185[0][6][1] = (safe_lshift_func_int16_t_s_s((((safe_add_func_int32_t_s_s((p_20 , (safe_rshift_func_int8_t_s_s((((+l_3519) | (l_49[2] & (0xF1L == 3UL))) >= l_49[6]), 6))), 0x05512232L)) | p_18) < p_21), l_3313))) < 1UL))) | g_27[2][0])))) != 0UL) && g_2084) , 0x29L))));
                for (g_486 = 25; (g_486 == 44); g_486 = safe_add_func_int32_t_s_s(g_486, 9))
                {
                    int8_t l_3620 = 0x57L;
                    l_3187 = (safe_rshift_func_uint8_t_u_s((((safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s((((((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((((((safe_mod_func_uint16_t_u_u((p_19 < 0xC6D8B1DDL), l_3620)) >= (safe_mod_func_uint16_t_u_u(((((safe_rshift_func_uint16_t_u_u(((p_20 <= (safe_lshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((g_27[2][0] = (p_19 , (safe_mod_func_int32_t_s_s((g_35 ^ l_3519), 0x622B3DFEL)))), ((((((safe_mod_func_uint8_t_u_u(0UL, 0x57L)) >= 0x45L) ^ 3L) > p_21) < g_35) != 65528UL))), l_3633))) | g_486), g_739)) == 0xE13DL) <= (-10L)) , 65535UL), p_19))) && g_1045) || p_21) == p_21), 2)), g_108)) && 250UL) || 0L) != p_20) < l_3634), g_247)), 4294967286UL)) ^ (-4L)) ^ 0x02090288L), 1));
                }
                for (g_503 = 0; (g_503 <= 0); g_503 += 1)
                {
                    int32_t l_3668 = 0x8F75022CL;
                    int i, j;
                    for (g_692 = 0; (g_692 <= 9); g_692 += 1)
                    {
                        int i, j, k;
                        if (g_203)
                            goto lbl_3520;
                        l_3635 = 0x034A2824L;
                        l_3668 = ((((g_504[1][1][2] = 65533UL) , ((safe_mod_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((5L & 65535UL), (safe_mod_func_int32_t_s_s((safe_lshift_func_int8_t_s_u((l_3177 = 0xF7L), (((((((((((l_3666 = (((((l_3187 = (g_250[g_503][(g_503 + 3)] | (~((((l_3664[6][8][0] = (safe_add_func_int8_t_s_s(((safe_mod_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((((((((safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(0x17DC6105L, (((safe_mod_func_uint16_t_u_u((g_2729[2][0] = (g_108 = l_3593[(g_503 + 2)][(g_503 + 8)][(g_503 + 3)])), (((safe_sub_func_int8_t_s_s((l_3184 = g_183[(g_503 + 6)]), (5UL & g_183[g_692]))) , 3UL) , 1L))) < g_897[0][2]) < p_19))), 6)) , l_3663[0]) ^ 0x962EL) , p_20) | g_32[2][0]) || p_20) , l_3519) != p_20), 11)), 0x56L)) == 255UL), p_21))) , 0x2C34L) || g_2236[1]) <= l_3593[1][5][2])))) > 0x00L) > g_456) ^ l_3665) , l_3596)) == p_20) , p_20) && g_33) > 0x6DL) | p_18) || 0xDDL) && p_19) ^ g_27[2][0]) < l_3519) >= l_3593[(g_503 + 2)][(g_503 + 8)][(g_503 + 3)]))), 1L)))) > 0L) | g_3003), 65535UL)) || p_18), g_132)) , l_3667)) >= l_3668) , 0x3399B629L);
                        l_3633 = (l_3669[3] = g_427[2]);
                    }
                    if (((((-8L) || (((l_3529 = (safe_rshift_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u(g_250[g_503][(g_503 + 3)], 6UL)) & (safe_sub_func_int16_t_s_s((g_250[g_503][(g_503 + 3)] || (safe_rshift_func_uint8_t_u_s((((g_918[4][0][2] == (((l_3187 = ((((((l_3668 & (((((safe_lshift_func_uint16_t_u_s(l_3593[0][4][3], 8)) == (((g_183[7] <= (g_247 != l_3680[0][1])) , p_18) ^ 0x9502L)) | g_1044) , p_18) < l_49[0])) <= g_250[g_503][(g_503 + 3)]) , g_456) >= p_20) && l_49[4]) != g_185[0][6][1])) == l_49[2]) != l_38)) == g_247) ^ p_20), g_35))), 0x3463L))) || 0x51L), p_21))) , g_693[1]) , 0UL)) <= 4UL) != 4294967289UL))
                    {
                        l_3633 = g_32[1][0];
                    }
                    else
                    {
                        int8_t l_3703 = 9L;
                        l_3668 = (safe_unary_minus_func_int16_t_s(g_2674));
                        l_49[6] = (safe_lshift_func_uint8_t_u_u((((safe_sub_func_uint16_t_u_u((((p_21 = (((g_897[1][2] = (safe_mod_func_int32_t_s_s(((l_3688 > 0x77L) , (((l_3635 <= ((safe_unary_minus_func_uint8_t_u((safe_lshift_func_int8_t_s_s((p_20 || (g_250[g_503][(g_503 + 3)] >= (safe_unary_minus_func_uint32_t_u(l_49[6])))), (safe_add_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_u(g_33, 12)) ^ (0UL != (safe_sub_func_int16_t_s_s(((safe_add_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_s(p_18, g_486)) , g_577), l_3703)) > g_972), 65535UL)))), p_19)))))) >= g_566)) ^ l_3496) , p_21)), l_3703))) == p_18) == l_3669[3])) | 6L) & l_3703), p_20)) >= l_3704) , 0x82L), l_3668));
                        l_3187 = (safe_add_func_uint8_t_u_u((((7L | ((p_19 < ((safe_add_func_uint16_t_u_u((g_577 , (g_1044 <= (safe_mod_func_int16_t_s_s(0xAD14L, (~(+(0x348CAE3CL && l_49[6]))))))), (safe_lshift_func_int8_t_s_u(0xB4L, 2)))) == (0x1CL >= 0xDEL))) | p_18)) == g_344) , g_427[1]), g_503));
                    }
                    l_3529 = ((((~((((g_32[8][1] , ((((safe_add_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s((p_18 == (g_132 = (((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_s(((l_3726 <= (l_49[6] = ((0x89F51452L ^ l_3519) , (p_18 < ((safe_rshift_func_int8_t_s_u(0xD2L, 4)) & 0xF1L))))) <= ((g_250[g_503][(g_503 + 3)] >= 0x2DL) , l_3663[2])), l_3529)), g_3159[1][3][0])), 11)) && g_1045) < 1L))), l_3313)) , g_298), g_250[g_503][(g_503 + 3)])) <= g_427[1]) ^ l_3665) & 0x7DL)) && g_499) , l_3664[6][8][0]) , l_3668)) , 0xCBL) > 0x38L) , p_20);
                    if (p_21)
                        continue;
                }
                l_3634 = ((l_49[6] = (g_2236[1] || ((2UL && (safe_lshift_func_int16_t_s_u((safe_mod_func_uint8_t_u_u((~(((-1L) & ((((((safe_rshift_func_uint16_t_u_u(0x4BB1L, ((g_1472 = (((safe_add_func_uint32_t_u_u((~((p_19 != (g_897[1][0] = (safe_rshift_func_uint16_t_u_u(((safe_unary_minus_func_int16_t_s(g_400)) | p_19), 11)))) || (safe_add_func_uint8_t_u_u(((l_3688 & (l_3633 = (safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(p_21, p_20)), 12)), g_739)), l_3594)) | g_419), p_18)), 0xA0937FD1L)))) , g_427[1]), 0xB1L)))), 0UL)) <= l_3664[8][4][0]) , l_3593[4][5][2])) == 0x2A212394L))) < g_34[5]) ^ p_19) ^ l_3519) & 0xCFL) , l_54)) , 0xC8E3L)), l_3669[3])), 1))) >= g_503))) & g_503);
            }
            else
            {
                uint8_t l_3781 = 3UL;
                uint32_t l_3783 = 0xDAB8654BL;
                int32_t l_3785[2];
                int32_t l_3882 = 0xC1141A38L;
                int i;
                for (i = 0; i < 2; i++)
                    l_3785[i] = 0xDE3A56E5L;
                for (g_1138 = 0; (g_1138 < 19); g_1138 = safe_add_func_int32_t_s_s(g_1138, 1))
                {
                    uint32_t l_3767 = 0xFD0A0862L;
                    int16_t l_3780[3];
                    int32_t l_3786 = 0x5B2F25D9L;
                    int i;
                    for (i = 0; i < 3; i++)
                        l_3780[i] = 9L;
                    l_3784[1] = (l_3529 = (((safe_sub_func_int8_t_s_s((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(((((l_49[1] = (l_3593[3][8][1] = ((p_20 , ((safe_lshift_func_int16_t_s_s((!((((p_20 || l_38) | g_126) , l_3767) , l_3688)), 10)) , ((safe_mod_func_uint8_t_u_u((((((((l_3780[1] = (g_897[0][2] = ((safe_sub_func_uint8_t_u_u(((safe_add_func_int8_t_s_s((g_1328 != (safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(l_3519, 7)) < (p_21 = (safe_lshift_func_uint8_t_u_s((((0xF6D11BBAL <= g_27[2][0]) > g_27[2][0]) || g_1045), 2)))), p_18))), g_34[2])) && 0xDFDCB2BAL), g_27[2][0])) < 1L))) , p_18) < l_3781) > 1UL) ^ g_1669) ^ p_20) <= p_18), g_972)) || l_3593[4][5][2]))) != p_19))) == (-1L)) < g_3782) > l_3783), g_53)), l_3519)), p_19)) >= g_2942) >= 65535UL));
                    l_3785[0] = p_21;
                    l_3786 = l_3593[4][5][2];
                }
                if (g_693[0])
                {
                    uint8_t l_3814 = 1UL;
                    int32_t l_3820 = 0x7D53A492L;
                    for (g_127 = 0; (g_127 <= 2); g_127 += 1)
                    {
                        int16_t l_3787[8][8] = {{0x8BF1L,0x8BF1L,0x6A13L,(-10L),0xDB82L,0x6A13L,0xDB82L,(-10L)},{0xDFF0L,(-10L),0xDFF0L,0x2392L,(-10L),0L,0L,(-10L)},{(-10L),0L,0L,(-10L),0x2392L,0xDFF0L,(-10L),0xDFF0L},{(-10L),0xDB82L,0x6A13L,0xDB82L,(-10L),0x6A13L,0x8BF1L,0x8BF1L},{0xDFF0L,0xDB82L,0x2392L,0x2392L,0xDB82L,0xDFF0L,0L,0xDB82L},{0x8BF1L,0L,0x2392L,0x8BF1L,0x2392L,0L,0x8BF1L,0xDFF0L},{0xDB82L,(-10L),0x6A13L,0x8BF1L,0x8BF1L,0x6A13L,(-10L),0xDB82L},{0xDFF0L,0x8BF1L,0L,0x2392L,0x8BF1L,0x2392L,0L,0x8BF1L}};
                        int i, j;
                        g_2942 = l_3787[6][5];
                    }
                    l_3785[0] = (((safe_lshift_func_int8_t_s_u((g_918[3][0][5] , (p_21 = (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint16_t_u_u(((((((((p_19 && (((l_3680[2][0] = (((0x33L != ((+(l_3781 , (l_3184 = (((!(p_18 > ((safe_rshift_func_int16_t_s_u((p_21 >= (((safe_add_func_uint16_t_u_u((((((l_3529 = (g_503 = (p_21 | g_897[0][0]))) , 0xB2C7L) > 1L) || 8L) , g_639), p_18)) , p_18) , p_18)), p_19)) < l_3596))) , g_35) >= 0x3A9BL)))) && p_18)) != g_2222) < l_54)) , p_21) | p_19)) && g_3159[1][1][0]) || (-1L)) , (-10L)) || g_33) & 0x37B07981L) ^ 2UL) , 0x0415L), 0)) ^ g_693[0]), p_21)))), 4)) > l_3519) ^ g_53);
                    if (((((0UL ^ l_3783) < ((((((safe_rshift_func_uint8_t_u_u((0xB117L || ((l_3593[4][5][2] , ((safe_lshift_func_uint8_t_u_s(((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_s(0x3616L, 3)), (safe_sub_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(((((l_3814 | (((l_3593[4][5][2] = ((g_427[1] || (-1L)) , (safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(8L, 2)), l_3814)))) > g_2729[0][6]) ^ g_108)) > g_250[0][1]) >= p_21) != l_3785[0]), 0x77F205CCL)) ^ 0x80L), 5L)), g_298)))) <= g_1357), p_20)) < p_20)) || l_3664[8][8][0])), 6)) || p_21) <= 1UL) != 0xAA0FL) ^ p_21) , l_3785[0])) == p_18) <= 0x7A7DL))
                    {
                        uint8_t l_3835 = 0xB6L;
                        l_3820 = ((p_20 >= (+1L)) , (0x5507L & g_126));
                        l_3820 = (((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(p_18, 14)), (safe_mod_func_int32_t_s_s(1L, (safe_mod_func_int16_t_s_s((g_344 <= ((((safe_lshift_func_uint8_t_u_s(((((g_2729[0][4] ^ 0L) < 9L) | (l_3784[1] = (safe_add_func_int8_t_s_s(0xBBL, 7L)))) || p_21), l_3835)) <= g_108) <= l_49[6]) > l_3835)), 2UL)))))) , (-4L)), l_3814)) == 0L) | 0x7542EFD5L);
                    }
                    else
                    {
                        int32_t l_3841 = 3L;
                        l_3680[1][0] = (((safe_sub_func_int8_t_s_s(0x61L, (~((-1L) >= g_2674)))) >= (0x24L < (l_3820 = p_19))) >= (safe_sub_func_uint16_t_u_u(((((((0L > l_3841) , (l_3785[0] = ((safe_lshift_func_int16_t_s_u((((safe_sub_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((l_3785[0] , g_250[0][1]) >= p_20), g_108)), 10)) , g_127) | 0xB4F8L), p_21)) || 0UL) & l_3177), l_3177)) && p_21))) || 2L) < l_3841) & (-10L)) || 0x67L), p_20)));
                    }
                    l_3680[0][1] = ((g_1045 & ((((safe_add_func_int8_t_s_s(((g_897[0][0] & p_19) || ((((safe_rshift_func_uint16_t_u_s((((p_21 = ((((((+((safe_add_func_int32_t_s_s(l_3820, ((65531UL | g_2729[0][4]) , ((l_3814 >= ((safe_lshift_func_uint16_t_u_s((((l_3859 = (-4L)) & (safe_lshift_func_int16_t_s_u((safe_mod_func_uint8_t_u_u((((l_3593[4][5][2] >= l_3534) , l_3785[1]) | 0x2CB7L), p_19)), l_3820))) , g_3003), g_276)) < 0L)) , p_21)))) , (-2L))) , l_3177) != (-1L)) | (-10L)) | l_3820) < p_20)) & g_897[0][2]) >= 0L), p_19)) , g_427[2]) >= 65535UL) > l_3781)), p_18)) == p_18) | l_3688) , 0x8A13L)) > 0x2BL);
                }
                else
                {
                    return l_3187;
                }
                l_3864 = (l_3785[0] = g_203);
                for (g_127 = 0; (g_127 == 16); g_127 = safe_add_func_uint16_t_u_u(g_127, 4))
                {
                    int32_t l_3869 = 0x0DD29439L;
                    for (g_400 = 0; (g_400 < 22); g_400 = safe_add_func_int32_t_s_s(g_400, 7))
                    {
                        return l_3869;
                    }
                    l_3529 = (l_3784[1] = l_3859);
                    l_3680[0][1] = ((safe_add_func_int16_t_s_s(((l_3593[1][4][2] = ((p_19 , (((((p_18 >= g_1669) <= g_27[2][0]) >= (safe_rshift_func_uint16_t_u_u((((l_3784[4] && g_53) <= (((l_3593[4][5][2] == (((safe_mod_func_uint8_t_u_u((((safe_mod_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((0x9A66L >= g_2674) >= 8L), l_3869)), g_456)) >= g_820), 0x75B5EF6BL)) <= p_20) != 1UL), 0x0DL)) <= l_3313) != p_19)) >= g_427[1]) & p_19)) <= 0x53L), 5))) > l_3882) ^ l_3869)) || l_3883)) > l_49[6]), l_3884)) != g_692);
                }
            }
            if (((((l_3885 && 4294967292UL) < ((safe_rshift_func_uint16_t_u_s(((((p_18 = ((((((safe_add_func_int32_t_s_s(((p_19 , (((((((safe_sub_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((((safe_sub_func_uint8_t_u_u(((l_3688 , (l_3593[2][5][1] = (((safe_lshift_func_uint16_t_u_s(0xF06AL, 14)) ^ 0x03L) , (safe_unary_minus_func_int32_t_s(g_972))))) ^ l_3688), (l_3596 || g_86))) <= 0L) | 0xFAF52C24L), l_3899[3])), l_3900[1])) , g_247) , 0x83F1L) >= p_20) == p_20) == p_19) | g_3901)) != g_1044), g_1044)) >= g_693[0]) == p_18) ^ g_247) , 0x675FF8EDL) , (-6L))) , l_3902) || l_3519) >= g_419), l_3688)) ^ g_486)) | 7L) == g_3903))
            {
                uint32_t l_3921 = 4294967292UL;
                if (p_19)
                {
                    uint32_t l_3919 = 4294967295UL;
                    g_2236[3] = p_21;
                    for (g_1044 = 0; (g_1044 <= 41); ++g_1044)
                    {
                        g_2236[3] = (g_1472 ^ (p_20 = p_19));
                        if (p_20)
                            continue;
                        g_2942 = p_18;
                    }
                    g_2942 = (safe_mod_func_uint32_t_u_u((g_3045[2][6] <= (((((safe_lshift_func_int8_t_s_s(l_38, l_3864)) && (safe_add_func_uint16_t_u_u((g_1044 , ((g_1138 = g_449) , ((!(safe_mod_func_int8_t_s_s((((((g_27[2][0] < (((g_34[5] = p_21) != (((safe_mod_func_uint16_t_u_u((((safe_mod_func_uint16_t_u_u(((0x81L > ((l_3919 < 1UL) && g_2084)) & p_21), l_3920)) < g_276) && g_577), l_3688)) & p_18) > 0x2FCD3C51L)) , g_693[1])) & 0x352CB559L) >= p_19) != 0x35L) & l_3921), l_3885))) | p_18))), g_3782))) == 0x8A5AL) == 0x2318L) | p_19)), l_3316));
                    g_2236[1] = 0x3D52DA54L;
                }
                else
                {
                    g_897[0][0] = (-9L);
                }
                return l_3921;
            }
            else
            {
                int32_t l_3939 = 0L;
                int32_t l_4001 = 0x17D570C4L;
                int8_t l_4009 = 9L;
                uint8_t l_4052 = 255UL;
                uint32_t l_4165 = 1UL;
                for (l_3184 = 0; (l_3184 < 3); l_3184 = safe_add_func_uint8_t_u_u(l_3184, 9))
                {
                    int32_t l_3950 = 7L;
                    int32_t l_3984 = (-1L);
                    if ((p_21 < (((((p_20 = (safe_mod_func_uint16_t_u_u(g_33, (safe_sub_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((((3L || (((((safe_mod_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(l_3593[4][5][2], ((0x60L && ((safe_add_func_int8_t_s_s(((g_486 = (1L != (p_19 , ((+p_18) && l_49[6])))) & l_3939), p_19)) && l_3177)) == 0xEAL))), l_3680[0][1])) >= p_18) != l_3940) , l_3680[0][1]) > p_21)) ^ g_34[5]) || 0x67D02F70L), g_203)), p_19))))) | g_318) | g_769) > g_3901) == l_3680[0][1])))
                    {
                        int32_t l_3963 = (-2L);
                        uint32_t l_3985 = 0UL;
                        l_3593[4][5][2] = (((safe_rshift_func_uint16_t_u_u((l_3939 , p_19), 8)) <= ((((((safe_sub_func_uint32_t_u_u(p_20, (safe_add_func_int16_t_s_s(((l_3939 > (safe_sub_func_uint8_t_u_u(l_3367, (0x2834B2A0L & g_127)))) ^ 0xCD306B1BL), ((((~((l_3784[4] = g_32[1][0]) | l_3950)) < 0xE99B8828L) & 0x1FL) ^ 0xCAL))))) && p_19) < 0x3A1CL) || 0xDC87EA37L) && g_86) >= 1UL)) || g_2942);
                        g_2222 = (l_3963 = (l_3529 = (safe_rshift_func_int8_t_s_u(((g_34[5] = (safe_add_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s((g_400 ^ (safe_lshift_func_int8_t_s_u(g_1472, (+((((((safe_rshift_func_int16_t_s_s(((p_20 > (safe_unary_minus_func_int32_t_s(l_3963))) , l_3963), g_1328)) || (((+((((l_3187 = 1UL) ^ (safe_sub_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(((l_3177 = (0xAC79L == l_3969)) || 0L), g_3045[1][2])), g_32[1][0]))) | 0x4C231CDAL) , p_18)) > l_3950) != l_3899[3])) | 4L) ^ g_2674) == g_318) <= l_3594))))), 9)) > (-7L)), l_3596))) > 0xB5L), 1))));
                        g_2942 = 0x0F28A0F7L;
                        g_897[0][2] = ((g_639 = ((safe_add_func_uint16_t_u_u(0x068EL, ((!((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(((((l_3939 ^ (((l_3680[2][0] = 0x00D3L) > 0x3AAEL) >= (((g_820 == ((p_21 = (safe_sub_func_int8_t_s_s((g_34[5] = 0x5EL), (+(((l_3984 = (((p_19 || l_3939) >= (safe_mod_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(0x50L, 1UL)) & 0x26L), 0x34272393L))) >= g_1363)) <= l_3963) || 9UL))))) , l_3984)) < l_3985) <= l_3664[6][8][0]))) | g_33) ^ 0x23L) && 255UL), p_19)), p_19)) <= g_185[0][6][1])) | g_86))) && p_18)) == l_3940);
                    }
                    else
                    {
                        int16_t l_4000 = 0x3DADL;
                        int32_t l_4002 = 0x3F165195L;
                        l_4002 = ((safe_mod_func_int16_t_s_s((safe_sub_func_int16_t_s_s(8L, p_20)), (safe_lshift_func_int16_t_s_u((l_4001 = (safe_mod_func_uint32_t_u_u((((((g_3903 || l_3939) == (((safe_rshift_func_uint16_t_u_u((0xFBD1L > (safe_mod_func_int16_t_s_s(l_3939, (l_3984 = (((((0x08A97EE5L < ((safe_lshift_func_int8_t_s_s(9L, 0)) != g_739)) && g_27[2][0]) < p_18) , g_32[4][0]) , l_3688))))), 7)) >= 8L) , 6L)) || p_21) > l_3950) & g_203), l_4000))), p_18)))) == 0xA6L);
                        g_1472 = (safe_mod_func_uint16_t_u_u((l_4001 = (((safe_lshift_func_uint16_t_u_s(p_20, (safe_lshift_func_uint16_t_u_s(p_20, ((5L || (l_3593[2][4][4] = p_20)) < p_21))))) > (g_1363 && ((((l_4009 = 0UL) <= ((((safe_lshift_func_uint16_t_u_s(((((0x1F460B3AL & (0xA1L || 0x4AL)) | g_1328) <= p_19) , p_18), l_3864)) , 0xEC7DL) , g_250[0][1]) || p_21)) < p_20) > p_18))) >= p_18)), 0x041DL));
                        g_2222 = (safe_add_func_uint8_t_u_u((safe_add_func_int8_t_s_s((0x33L && ((g_127 = g_132) ^ (l_4002 ^ (l_3593[0][4][2] = l_4000)))), (l_3177 = ((p_21 , p_18) != (0x91A05305L || l_3984))))), (0L >= 0x878F0BA8L)));
                        if (l_3984)
                            break;
                    }
                    l_3593[4][5][2] = (safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint8_t_u_u((p_19 = ((p_20 = ((safe_mod_func_int16_t_s_s((g_3159[1][3][0] , l_3984), (((l_4001 = (0x4F5A0E6DL != (g_185[0][6][1] == ((l_3177 = ((safe_rshift_func_uint16_t_u_u((((((g_344 >= 0x99D8L) == g_27[2][0]) , (((l_3920 , (((safe_sub_func_uint16_t_u_u(p_19, l_3950)) ^ 0xE1L) == g_318)) >= p_19) , g_317)) ^ 0UL) != l_3593[4][5][2]), g_1138)) < l_3939)) || l_4001)))) >= l_3680[0][1]) || p_20))) && l_4026[2][5])) || l_3939)), 0L)) ^ (-1L)), p_18));
                    for (g_247 = 0; (g_247 > 32); g_247 = safe_add_func_int16_t_s_s(g_247, 2))
                    {
                        if (g_247)
                            goto lbl_3520;
                        l_4001 = (safe_lshift_func_uint8_t_u_u(0x39L, p_19));
                        g_2942 = g_504[2][3][2];
                    }
                }
                if (((safe_sub_func_uint8_t_u_u((l_3885 | ((((safe_add_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((0x3DAAE2A8L != (safe_sub_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((l_3883 , (safe_unary_minus_func_int16_t_s(0xC5E4L))), (g_3045[0][0] , (-1L)))), ((safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s((safe_sub_func_uint32_t_u_u(((((p_20 , l_3939) != (g_427[1] < p_20)) > g_639) == g_419), p_19)), l_3939)), 5)), l_3184)), 1UL)) ^ 1L)))), 0xD54CL)), l_3596)) > g_2084) , p_21) ^ g_86)), l_4052)) && 0xD2EDL))
                {
                    uint32_t l_4064 = 0x28418764L;
                    int32_t l_4069 = 0xAA42C36AL;
                    l_4001 = (-6L);
                    l_3187 = (((g_1472 = (((l_49[6] ^ (safe_add_func_uint32_t_u_u(l_3920, g_639))) >= ((p_19 = (safe_sub_func_uint8_t_u_u(p_20, (safe_mod_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((((!(safe_lshift_func_uint16_t_u_u(((l_4064 = 65531UL) == p_19), 15))) > l_4009) , ((safe_lshift_func_int8_t_s_u((0x846BL | (l_3593[0][0][0] = (g_298 = (l_4069 = ((((safe_lshift_func_uint8_t_u_u(((l_4001 == g_185[1][7][0]) ^ p_18), 0)) == l_3593[0][6][2]) > l_4064) <= 0x200DL))))), p_20)) | g_3159[0][3][1])), (-6L))), (-7L)))))) | g_3782)) , l_4070)) <= 0x3FEA7C48L) & g_972);
                }
                else
                {
                    l_3177 = 0x0BB2C264L;
                    l_3680[0][1] = (safe_sub_func_int32_t_s_s(l_4073, ((g_183[9] && (p_20 = 0x61CAL)) > (safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u(p_19, 0L)), (l_3726 <= l_3939))))));
                    l_3184 = (l_4001 = (0x6BCAL & (((l_4026[3][6] = ((l_3969 <= 6L) || ((g_27[0][0] = (safe_sub_func_int32_t_s_s(g_2236[2], ((((((safe_mod_func_int32_t_s_s(((((((g_391 = l_4052) ^ l_3726) != (((safe_rshift_func_int16_t_s_s((g_427[2] != ((g_32[1][0] ^ (p_20 , g_27[1][0])) != l_3940)), g_183[9])) , p_18) >= p_19)) | p_19) < 9UL) , l_3594), l_3534)) | p_21) || g_86) & p_21) | p_21) , 1UL)))) ^ g_5))) < 0xBCC1L) , 65535UL)));
                }
                for (g_2084 = (-27); (g_2084 == 4); g_2084 = safe_add_func_uint8_t_u_u(g_2084, 1))
                {
                    volatile int16_t l_4086 = 0L;
                    int32_t l_4093 = 0x541A850CL;
                    l_4086 = g_2236[1];
                    for (p_20 = 0; (p_20 <= 5); p_20 += 1)
                    {
                        int i;
                        g_2236[p_20] = (0x65D0L >= 0x6F07L);
                        g_2236[1] = (safe_add_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(0x4A7D1F19L, (g_2236[p_20] <= ((l_4093 = (safe_lshift_func_uint8_t_u_s(p_19, 6))) && (l_3680[2][1] = 4UL))))), 0x5AA8L));
                        g_2236[p_20] = p_19;
                        l_3784[4] = p_20;
                    }
                }
                for (g_203 = 27; (g_203 != (-22)); --g_203)
                {
                    int8_t l_4121 = 0x6CL;
                    int32_t l_4122 = 0L;
                    if ((((l_4001 = (g_1044 = (((safe_mod_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u(p_21, 6)) >= (((safe_mod_func_int8_t_s_s(((p_19 > (l_3680[0][1] = ((((g_2729[1][2] = (l_3680[0][1] == l_3900[1])) == ((l_4122 = (safe_rshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((-1L), (safe_add_func_int16_t_s_s(p_21, (((safe_rshift_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((~((1L == (safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((g_185[1][7][1] = (safe_add_func_uint32_t_u_u((l_3529 = g_427[2]), l_3920))), l_4121)), g_1363))) != p_20)), g_2236[1])), p_19)) == g_972), 3)) && l_4073) || p_21))))) == 0xB154505AL), p_18))) || 0xF2L)) , 251UL) > g_4123))) > g_33), g_486)) , g_126) != 0xED23L)), g_315)) , g_2674) & g_298))) <= g_2942) > 0xD1L))
                    {
                        uint32_t l_4137[1][6] = {{0x73A09CC6L,0x73A09CC6L,0x73A09CC6L,0x73A09CC6L,0x73A09CC6L,0x73A09CC6L}};
                        int i, j;
                        l_3177 = (((((((g_27[2][0] = (g_2942 < (((p_18 && l_3316) && (((safe_rshift_func_uint8_t_u_s((1UL | ((p_18 = p_21) , (((l_4001 = ((((((+1UL) && 0x6FL) , (l_3939 & ((((g_1363 , l_3864) || g_456) < p_20) | l_3534))) < p_21) == p_19) >= p_20)) , l_4121) & g_3159[1][1][1]))), 7)) | g_427[2]) , g_183[9])) ^ 4294967295UL))) == 1UL) && p_18) , p_18) <= 1UL) & p_20) , 0L);
                        l_4001 = ((p_19 = (g_34[6] , l_4122)) & (g_44 && (((((p_20 == (safe_rshift_func_uint16_t_u_u((p_18 | 0x34F3L), 1))) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u(p_21, (l_3593[2][6][1] = (((safe_sub_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((l_3680[0][1] = p_18), l_4137[0][3])) && g_2236[1]), l_3596)) , g_132) ^ (-5L))))), (-5L))) < l_4122)) , 6L) >= 255UL) , 0x9A78AE95L)));
                    }
                    else
                    {
                        uint16_t l_4160[9][4] = {{0x524AL,1UL,0xAB55L,1UL},{0x524AL,0xA6BEL,0xAB55L,0xA6BEL},{0x524AL,1UL,0xAB55L,1UL},{0x524AL,0xA6BEL,0xAB55L,0xA6BEL},{0x524AL,1UL,0xAB55L,1UL},{0x524AL,0xA6BEL,0xAB55L,0xA6BEL},{0x524AL,1UL,0xAB55L,1UL},{0x524AL,0xA6BEL,0xAB55L,0xA6BEL},{0x524AL,1UL,0xAB55L,1UL}};
                        int32_t l_4161[9] = {1L,1L,1L,1L,1L,1L,1L,1L,1L};
                        int i, j;
                        l_4073 = (g_2222 = (safe_lshift_func_int16_t_s_u(l_4140, 6)));
                        l_3784[1] = (((safe_add_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((p_19 , (((safe_lshift_func_uint16_t_u_u(((l_4122 = ((((safe_sub_func_int32_t_s_s(((!(((safe_sub_func_uint32_t_u_u((p_19 || (g_427[1] >= (0x37L ^ (safe_lshift_func_uint16_t_u_s(((safe_add_func_int8_t_s_s((p_19 && (g_693[1] != (safe_add_func_int16_t_s_s(((g_27[1][0] = ((g_693[1] != (l_4160[8][0] = (safe_sub_func_uint16_t_u_u(((l_4121 && (((((p_19 = ((p_20 = g_2222) | g_317)) && g_427[1]) && 0x25L) && p_19) , l_4009)) <= l_4121), g_3159[1][3][1])))) >= p_18)) >= l_4122), l_4161[7])))), p_21)) && p_18), 13))))), p_18)) && l_4161[7]) | p_18)) == g_1138), 0x7BCC9E79L)) , 4294967294UL) & l_4026[2][5]) , p_20)) , p_20), 5)) | p_18) < l_3939)) , l_4073), p_21)), 1UL)) > l_3688) < p_18);
                        l_4026[4][1] = ((~((((safe_lshift_func_int8_t_s_u(g_486, (0x04L || (((l_4122 ^ (p_18 | ((p_19 , (((l_4165 , (safe_rshift_func_uint8_t_u_u((0xA138L <= ((l_4168 = (0x4F53A880L <= l_4161[7])) , 65535UL)), 2))) , p_19) < l_4161[7])) <= 1UL))) <= g_2729[2][5]) , p_21)))) < (-3L)) , 0x5D7C836DL) <= g_693[1])) != p_18);
                    }
                    l_49[6] = l_3688;
                }
            }
            for (p_21 = 2; (p_21 >= 0); p_21 -= 1)
            {
                int16_t l_4185[2][7];
                int32_t l_4186 = (-1L);
                int32_t l_4187[3];
                uint32_t l_4188 = 4294967294UL;
                int32_t l_4204 = 4L;
                int8_t l_4207 = 0xD5L;
                int i, j;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 7; j++)
                        l_4185[i][j] = 0xEB28L;
                }
                for (i = 0; i < 3; i++)
                    l_4187[i] = (-1L);
                for (p_18 = 2; (p_18 >= 0); p_18 -= 1)
                {
                    uint32_t l_4205 = 0x1A46C2CDL;
                    for (g_35 = 0; (g_35 <= 2); g_35 += 1)
                    {
                        int32_t l_4206 = 0x8F5AB5CAL;
                        int i, j, k;
                        l_4188 = (((safe_rshift_func_int16_t_s_s(0xD76DL, 0)) != (((l_4187[0] = (+((g_504[(g_35 + 5)][(g_35 + 5)][p_21] <= g_2729[p_18][(p_18 + 1)]) ^ ((~p_18) > (0xFAL > ((safe_lshift_func_int16_t_s_s((l_4186 = (safe_add_func_uint8_t_u_u((((~65533UL) <= (safe_mod_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u(((!0UL) < (p_19 & ((((p_20 <= p_20) , l_3534) , l_3900[1]) & l_4185[1][5]))), p_18)), g_486)), p_20))) >= p_19), (-2L)))), 15)) ^ l_3187)))))) & p_20) , g_183[3])) || 1L);
                        l_3593[4][5][2] = (safe_unary_minus_func_uint8_t_u((g_3782 = ((safe_mod_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s(((~(g_35 >= (g_3003 && (safe_lshift_func_int16_t_s_s(p_20, (safe_add_func_int8_t_s_s((p_21 >= (safe_mod_func_uint8_t_u_u(249UL, p_19))), ((((((~l_4204) | ((l_4205 , ((((l_4206 = g_1045) < 6UL) | g_185[0][6][1]) | g_183[9])) && 0xED73EBAFL)) == g_344) <= 0x01L) == 4UL) >= g_486)))))))) , 0x6457L), 7)), l_4187[0])) <= 0xEDL), 0x65L)) , 6UL))));
                        if (l_3367)
                            break;
                    }
                }
                l_4207 = l_3969;
                l_3593[4][5][2] = (~(p_21 , ((~0x69D3E601L) , p_18)));
                for (g_1138 = 2; (g_1138 >= 0); g_1138 -= 1)
                {
                    int32_t l_4236 = (-1L);
                    int i, j, k;
                    l_3680[1][0] = ((g_504[(p_21 + 3)][(p_21 + 5)][p_21] || 0xC339L) && (+g_504[(p_21 + 6)][(p_21 + 3)][g_1138]));
                    l_4236 = (safe_lshift_func_uint8_t_u_s(((((((((((safe_lshift_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_s(p_21, 6)), ((g_34[5] = ((l_4221 = l_49[6]) ^ ((l_4073 = ((g_3045[1][6] != 250UL) < (safe_mod_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(l_3940, 4)), (safe_sub_func_uint8_t_u_u(255UL, (((((g_504[(g_1138 + 1)][(g_1138 + 1)][g_1138] = (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u(p_19, (safe_mod_func_uint8_t_u_u(g_1363, l_3884)))) > 0x44AD68C1L), 1UL)), g_504[(p_21 + 3)][(p_21 + 5)][p_21]))) && p_21) >= g_400) == g_2236[3]) == l_4236))))))) != 1UL))) , p_19))), l_3187)) & l_4236) == p_21) | l_4026[2][5]) , 0xF4705BCAL) || p_19) > l_4237) , g_693[0]) != g_419) & g_972), p_19));
                }
            }
        }
    }
    else
    {
        int8_t l_4243 = 1L;
        int32_t l_4245 = 0x601522E8L;
        l_4245 = (safe_sub_func_uint8_t_u_u((l_4026[2][5] , (((((g_86 = 0xAA604FD2L) & g_32[1][0]) , ((safe_add_func_int16_t_s_s(g_918[0][0][1], g_1472)) ^ (g_897[0][0] = (p_21 | (+((((((((l_4244 = l_4243) && (g_203 = g_250[0][0])) == (((0L || p_19) == p_19) , p_20)) , p_18) < g_298) != l_4243) , g_427[1]) >= 255UL)))))) >= g_391) == 0xE304L)), p_20));
    }
    l_49[6] = (p_21 & l_3864);
    return g_3903;
}







static uint16_t func_23(int32_t p_24)
{
    uint16_t l_30 = 0x8DACL;
    int32_t l_31 = 7L;
    l_31 = (l_30 = (safe_lshift_func_int16_t_s_s((p_24 ^ g_27[2][0]), p_24)));
    g_32[1][0] = g_5;
    return l_30;
}







static int8_t func_47(int16_t p_48)
{
    return p_48;
}







static int16_t func_55(int16_t p_56)
{
    int32_t l_63[4];
    uint32_t l_67 = 0x881DD571L;
    uint32_t l_77 = 5UL;
    int32_t l_457 = (-5L);
    int16_t l_2447 = 0xD223L;
    int32_t l_2489[8][7][4] = {{{5L,0xB3796EC0L,0xA8CF5080L,0x65CC8092L},{1L,1L,0x880EE9C9L,0xEA7F3B28L},{(-1L),0x00752643L,(-1L),7L},{(-7L),0xE32AC911L,0xA1313BFAL,0x00752643L},{0x80964293L,0L,9L,0x2BD0FE56L},{(-1L),0x90A9627CL,(-1L),0x234F6171L},{0x773F6E52L,7L,0x2BD0FE56L,0x405263F4L}},{{1L,5L,1L,3L},{0x51FDB2D6L,0x443D343BL,0xDDF431BAL,0L},{0x6D626025L,0x46304E9EL,0x46304E9EL,0x6D626025L},{0xA1313BFAL,0x8062EF52L,0x62D39AA5L,(-1L)},{5L,0x00752643L,0x2897B070L,1L},{0L,0xE81CF190L,1L,1L},{1L,0x00752643L,(-3L),(-1L)}},{{(-1L),0x8062EF52L,0x1CA8CA73L,0x6D626025L},{3L,0x46304E9EL,9L,0L},{0x5833539CL,0x443D343BL,0x285F9C6AL,3L},{1L,5L,0x92730339L,0x405263F4L},{6L,7L,0xA8CF5080L,0x234F6171L},{0x285F9C6AL,0x90A9627CL,0x62D39AA5L,0x2BD0FE56L},{0x6D626025L,0L,0L,0x00752643L}},{{0x00752643L,0xE32AC911L,0x5833539CL,7L},{0x285F9C6AL,0x00752643L,0L,0xEA7F3B28L},{0L,1L,0x92730339L,0x65CC8092L},{0x773F6E52L,0xB3796EC0L,(-3L),2L},{0x5833539CL,0x234F6171L,0xA1313BFAL,9L},{0L,1L,0x1CA8CA73L,0L},{0xE08322CAL,0x3AFB4DDBL,7L,0x234F6171L}},{{1L,0x405263F4L,0x880EE9C9L,(-3L)},{6L,0x51FDB2D6L,0x2897B070L,9L},{0x51FDB2D6L,0x3AFB4DDBL,0x5833539CL,0L},{0xA1313BFAL,0L,(-9L),9L},{1L,0x8062EF52L,0xDDF431BAL,(-1L)},{0x405263F4L,0xB3796EC0L,0L,8L},{1L,0L,1L,0xEA7F3B28L}},{{1L,0x6D626025L,(-1L),2L},{0xE08322CAL,0xE32AC911L,0xB3796EC0L,0x6D626025L},{0x80964293L,0x7B0502EAL,0L,0xE3C9401AL},{0x880EE9C9L,0L,1L,9L},{0x6D38A7DCL,0L,0x299AC7DAL,8L},{0x299AC7DAL,8L,0x74065357L,0L},{0x03E1CD81L,1L,0L,0xE32AC911L}},{{0x80964293L,0x0FF90146L,0x15056D7FL,0x80964293L},{0x12137BD5L,0xB3796EC0L,0x9876EC10L,0xEDBA69ACL},{8L,0x46304E9EL,(-1L),0x285F9C6AL},{0xE32AC911L,0x6A0A3D74L,0xAC201413L,7L},{1L,0x80964293L,0L,0xEDBA69ACL},{0x880EE9C9L,9L,3L,(-9L)},{0xEA7F3B28L,0x0FF90146L,0x12137BD5L,3L}},{{0x9876EC10L,0L,0x3CC5F57CL,0L},{0x5833539CL,0x03E1CD81L,0x8062EF52L,0xE81CF190L},{5L,0L,0x74065357L,0xA1313BFAL},{0x7BC3398BL,0xA8CF5080L,0x9876EC10L,0xE3C9401AL},{(-9L),1L,8L,0x80964293L},{0x46304E9EL,0x1CA8CA73L,0x92730339L,0x3AFB4DDBL},{0x7BC3398BL,0x80964293L,0xDDF431BAL,1L}}};
    uint32_t l_2522 = 0x14782674L;
    uint32_t l_2523 = 9UL;
    int8_t l_2524 = 1L;
    uint32_t l_2554 = 1UL;
    int32_t l_2670 = 0L;
    uint8_t l_2690 = 0xEEL;
    int32_t l_2704 = 0L;
    uint16_t l_2755 = 7UL;
    int16_t l_2896 = 0x5E6DL;
    int32_t l_3002[3][10] = {{2L,2L,2L,2L,2L,2L,2L,2L,2L,2L},{2L,2L,2L,2L,2L,2L,2L,2L,2L,2L},{2L,2L,2L,2L,2L,2L,2L,2L,2L,2L}};
    int32_t l_3114 = 0x65DDE7BFL;
    int i, j, k;
    for (i = 0; i < 4; i++)
        l_63[i] = 0x161DBFA2L;
    g_897[0][0] = ((!(((safe_rshift_func_int16_t_s_s(func_60(l_63[1], ((0UL > (func_64(l_67, (safe_sub_func_int32_t_s_s(func_70((((safe_add_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(0x41L, ((((l_77 == p_56) > ((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((((0xE1D3L == ((l_67 < g_5) < p_56)) | g_27[2][0]) > 65530UL), p_56)), 1UL)) , 0xB2365B21L)) ^ 0L) , 0xB8L))), l_77)) < l_77) , p_56), p_56), l_457))) | l_63[1])) && l_2447)), 2)) , 8L) , p_56)) >= g_32[1][0]);
lbl_2851:
    l_2489[5][3][3] = p_56;
    if ((safe_add_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u((0xF6L && ((g_1357 == ((((l_2489[5][1][1] = l_2447) == (l_2447 < g_250[0][1])) ^ (g_503 = (g_693[1] && l_2447))) < ((safe_sub_func_uint32_t_u_u(0x3404548DL, l_63[3])) != g_456))) < p_56)), p_56)) & g_693[0]), 1UL)))
    {
        int8_t l_2520 = 0xCDL;
        int32_t l_2521 = 0L;
        int32_t l_2557 = 0x711DAEEBL;
        int16_t l_2650 = 0xDDDCL;
        int16_t l_2688 = 0x89EDL;
        int32_t l_2930 = 0x1FFD44AEL;
        int32_t l_3032 = 0xA1BAF0D8L;
        int32_t l_3061 = 8L;
        int32_t l_3094 = 0x3AEEE4ACL;
        if (((g_391 & (safe_lshift_func_int8_t_s_u(0x53L, (((safe_add_func_int16_t_s_s(((((p_56 , (((safe_mod_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((((((2L == (safe_lshift_func_uint8_t_u_u((+g_972), ((((((((!p_56) && p_56) < ((safe_rshift_func_int16_t_s_u(((p_56 ^ ((safe_lshift_func_int8_t_s_s((l_2521 = (((safe_add_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u((g_2222 & l_2520), 0x57L)) <= g_32[2][1]), l_2520)), g_1138)) < 65535UL) ^ p_56)), p_56)) ^ p_56)) ^ l_2522), l_2520)) | p_56)) > 252UL) < l_2523) || g_1328) == p_56) || g_27[2][0])))) <= l_2520) || g_1001) <= l_2489[5][3][3]) , p_56), g_108)), 15)) < 0L), p_56)) <= g_185[0][6][1]) > p_56)) || g_1472) , 0x1EL) , l_2524), 5L)) & p_56) , l_2520)))) , 0L))
        {
            int16_t l_2540 = 0xA2B9L;
            int32_t l_2555 = 4L;
            int16_t l_2594 = 1L;
            int32_t l_2612[2];
            int8_t l_2710 = 0xF8L;
            int16_t l_2740 = (-5L);
            int i;
            for (i = 0; i < 2; i++)
                l_2612[i] = 0x174D17CFL;
lbl_2570:
            l_2489[3][3][3] = (safe_unary_minus_func_int16_t_s(g_1001));
            if (g_247)
            {
                uint32_t l_2569 = 0UL;
                int32_t l_2595 = 1L;
                uint32_t l_2649 = 0x37DFEF46L;
                for (g_1363 = 11; (g_1363 <= (-16)); --g_1363)
                {
                    int8_t l_2553 = (-4L);
                    uint32_t l_2566 = 0UL;
                    for (g_566 = 0; (g_566 <= 9); g_566 += 1)
                    {
                        int32_t l_2528 = 0xD0568BC6L;
                        uint8_t l_2556[10][6] = {{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL},{0UL,0UL,0x5AL,0UL,0UL,0x5AL}};
                        int i, j;
                        if (g_183[g_566])
                            break;
                        l_2557 = (((((((l_2528 = p_56) , l_2528) , (+(((((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s(g_486, ((safe_sub_func_uint16_t_u_u((((safe_add_func_uint8_t_u_u(((((((((safe_rshift_func_uint16_t_u_s((l_2540 = p_56), (safe_mod_func_uint16_t_u_u((l_2556[6][0] = (safe_mod_func_int16_t_s_s((l_2521 = ((((g_503 | ((((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_lshift_func_uint8_t_u_u((0x67L < 253UL), 5)) > (g_693[0] && ((((safe_mod_func_uint8_t_u_u((((l_2521 , 0L) >= 65534UL) <= l_2528), 0x83L)) < l_77) , l_2553) , p_56))) , g_1045) < g_183[g_566]), 11)), 1)) || g_183[g_566]) != l_2554) & g_1044)) > p_56) <= l_2555) , g_183[5])), p_56))), p_56)))) ^ (-1L)) != l_2555) != g_897[1][0]) > g_27[2][0]) != 0xF2L) | g_298) | 0xA80DB917L), 0x6FL)) != (-1L)) && 0x032FL), 0x1219L)) | l_2553))), 0)) , 0L) == p_56) > g_344) ^ 0x15L))) && 0xD3F38F9BL) | 4294967295UL) == 2UL) | p_56);
                    }
                    l_2557 = (safe_rshift_func_int8_t_s_u((255UL < (g_419 = ((((g_34[6] = ((safe_lshift_func_uint16_t_u_s(((4294967293UL >= ((((((((safe_sub_func_uint32_t_u_u((p_56 >= p_56), ((safe_mod_func_int8_t_s_s(l_2566, (safe_rshift_func_int8_t_s_s((l_2569 || (((p_56 <= ((-3L) != 0x3A61F472L)) ^ 65535UL) > l_457)), g_918[4][1][4])))) && 0x6B3848FBL))) < 0x3DC68261L) ^ g_1328) ^ 1UL) ^ 0xA4A7D45BL) | g_247) != l_2557) | g_183[7])) , p_56), 4)) != 0xACL)) , 0x22L) && 254UL) != l_2555))), 4));
                    l_2521 = 0xF5229E30L;
                }
                if (p_56)
                {
                    int32_t l_2573 = 0x2195D5BEL;
                    int32_t l_2596 = 0x46BB77ADL;
                    if (l_2555)
                        goto lbl_2570;
                    g_2236[4] = (l_2596 = (safe_add_func_uint32_t_u_u((((l_2573 && (((g_250[0][1] < ((l_2489[3][4][0] = (safe_rshift_func_uint16_t_u_u((((((((l_2595 = ((((safe_add_func_uint32_t_u_u((((safe_sub_func_uint32_t_u_u(g_577, g_86)) != l_2569) && (safe_lshift_func_uint8_t_u_s(((((l_2489[5][3][3] < ((((((p_56 | (((((((safe_mul_func_int32_t_s_s(((safe_add_func_uint32_t_u_u((g_1138 & ((((safe_rshift_func_int16_t_s_u((((safe_mod_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(p_56, g_897[0][2])), l_2521)), 255UL)) != 0x3E057178L) ^ p_56), 15)) && l_2569) , 250UL) > g_27[0][0])), p_56)) && 0xA871L), 0L)) ^ p_56) != l_2569) && g_5) == p_56) & 0x5DL) || g_250[0][3])) , g_897[0][2]) >= p_56) && g_86) != 0xC3L) ^ p_56)) , l_2573) | 3L) , 0x67L), p_56))), g_35)) && l_2594) && p_56) , l_2555)) < g_86) == p_56) ^ p_56) != 0L) | g_185[1][7][0]) > l_2569), 14))) >= g_1669)) || g_5) < g_32[1][0])) || (-3L)) <= 0xBBF1DBECL), g_1328)));
                    g_897[0][2] = (p_56 , 8L);
                }
                else
                {
                    int8_t l_2611 = 1L;
                    int32_t l_2638 = (-1L);
                    for (l_2555 = 19; (l_2555 == (-2)); l_2555 = safe_sub_func_int16_t_s_s(l_2555, 5))
                    {
                        int32_t l_2609 = 0xFA2F6F14L;
                        int32_t l_2637 = 1L;
                        g_1472 = g_2236[4];
                        l_2612[0] = ((l_2595 = (((0UL && (safe_rshift_func_uint16_t_u_u((((g_504[1][1][2] < (safe_mod_func_int8_t_s_s((((0L ^ ((l_2611 = ((((safe_add_func_int32_t_s_s(4L, (safe_sub_func_int16_t_s_s(((l_2557 || (l_457 != (g_639 > (l_2609 = (((l_2489[5][3][3] < ((+((!l_2447) | 3L)) ^ g_132)) > p_56) , g_53))))) >= (-8L)), 0xA168L)))) && g_2084) && g_2610) < p_56)) != l_2540)) >= g_566) != p_56), p_56))) != l_2595) <= g_566), 13))) ^ p_56) >= p_56)) , l_2609);
                        if (p_56)
                            continue;
                        l_2595 = ((((l_2638 = (((((((((((0xC0C3L & 0UL) <= (safe_mod_func_int32_t_s_s((((safe_mod_func_int32_t_s_s(((l_2637 = (((p_56 , ((safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((((g_317 = l_2521) || 4294967295UL) & 0x893DL), (safe_rshift_func_int8_t_s_s((l_2612[0] = (safe_rshift_func_uint16_t_u_s(g_315, (safe_sub_func_int32_t_s_s(((safe_rshift_func_uint8_t_u_u(p_56, (+(((!(safe_lshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s((l_457 | l_2521), 10)) & g_33), g_185[0][6][1])), p_56))) ^ p_56) | (-2L))))) ^ l_2611), l_2555))))), g_247)))), 0x2667F7C7L)) != 0x6EL)) >= 0x56C6L) <= p_56)) || p_56), 0x0DE532EBL)) || g_739) , l_2611), 0x9AFBD0BBL))) < p_56) ^ g_769) <= p_56) == 1L) , g_276) ^ l_63[2]) <= l_457) > g_503) || p_56)) == g_1363) , l_2594) < p_56);
                    }
                    l_2595 = ((((((safe_rshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_u((~l_2595), (!(l_2650 = (((l_2638 = ((safe_sub_func_uint8_t_u_u(((((safe_rshift_func_uint16_t_u_s(0xC6C4L, 14)) >= (l_2611 || l_2555)) <= (l_2521 == p_56)) <= ((l_2649 = p_56) >= 0x30724BD6L)), p_56)) , l_2521)) != p_56) != (-1L)))))) || p_56), 12)) | 255UL) <= p_56) <= 0xDFL) != g_126) < 0x17AEL);
                    g_2236[2] = (safe_mod_func_uint16_t_u_u(l_2554, (safe_mod_func_uint16_t_u_u((p_56 | (safe_lshift_func_int8_t_s_s(((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u(((safe_mod_func_int32_t_s_s(g_504[2][4][0], (safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((p_56 < l_63[1]) >= ((l_2670 = (l_2638 = (safe_unary_minus_func_int8_t_s(((0L || (l_2569 , (safe_sub_func_uint32_t_u_u((p_56 || (((((l_2489[5][3][3] = (g_2084 & 4294967287UL)) ^ p_56) , l_2523) & p_56) & 0xC80DCD9BL)), 0L)))) || g_183[8]))))) & 0x24C593D4L)), p_56)), g_391)))) >= 0xE291L), g_769)) <= g_250[0][1]) != g_86), 0x9530B6F0L)) || p_56), g_1138))), g_247))));
                }
                if (p_56)
                {
                    uint32_t l_2671[6] = {4294967295UL,4294967295UL,4UL,4294967295UL,4294967295UL,4UL};
                    int i;
                    return l_2671[1];
                }
                else
                {
                    if (g_108)
                        goto lbl_2570;
                    return p_56;
                }
            }
            else
            {
                uint8_t l_2679 = 0UL;
                int32_t l_2708 = 0L;
                int32_t l_2709[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_2709[i] = 0x73425C51L;
                l_2521 = (safe_sub_func_int16_t_s_s((g_1138 >= ((5UL || ((l_2670 = (g_2674 < (p_56 & (((((((0x63A4713EL | (+((safe_sub_func_int32_t_s_s((((p_56 >= g_315) != (((!65535UL) == ((l_2489[7][6][1] = ((l_2557 = (((l_2679 & p_56) && 0L) > l_2612[1])) >= p_56)) < p_56)) < l_2670)) == g_250[0][1]), l_2679)) , p_56))) | g_693[1]) & 0x5DA4L) , l_2612[1]) < p_56) > p_56) < (-1L))))) | g_692)) || g_2236[5])), 0x99EFL));
                l_2521 = ((g_34[5] , (safe_rshift_func_int16_t_s_s((((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s((g_1045 | (l_2650 | 1L)), (safe_add_func_int8_t_s_s(l_2555, l_2522)))) && (l_2688 = 0x39L)), (+p_56))) >= l_2690) | p_56), g_33))) >= (-3L));
                for (l_457 = 25; (l_457 == (-23)); l_457 = safe_sub_func_uint16_t_u_u(l_457, 4))
                {
                    int8_t l_2707 = 0L;
                    l_2521 = (p_56 && g_427[1]);
                    g_2236[3] = ((l_2557 = ((l_2679 , ((p_56 , (((safe_unary_minus_func_uint32_t_u((!(((p_56 , ((l_2709[0] = ((((p_56 = ((((g_317 <= ((safe_rshift_func_uint8_t_u_s((((l_2670 = (safe_lshift_func_uint8_t_u_s(l_2688, 5))) < (l_2708 = (safe_mod_func_int32_t_s_s(((safe_rshift_func_int16_t_s_s((((((((((g_32[3][0] & (safe_unary_minus_func_uint32_t_u(0xBA7E9EA0L))) <= (l_2704 || (safe_lshift_func_int8_t_s_u((l_2688 < p_56), p_56)))) & p_56) >= 0xD90C4FD3L) & 0xB1D72486L) && l_2707) , 6L) ^ g_276) | l_63[1]), 7)) >= 0UL), g_5)))) >= p_56), 3)) || g_504[9][4][2])) , g_183[9]) <= g_185[0][6][1]) > (-8L))) || g_504[1][1][2]) >= 0xAD41L) > 0x09CBD70AL)) && p_56)) != 0x2DL) || 0x039B642CL)))) || p_56) & 1UL)) <= l_2707)) | l_2707)) & g_34[5]);
                    if (l_2710)
                        continue;
                    l_2709[0] = (l_2612[0] = (safe_lshift_func_int16_t_s_s(p_56, 14)));
                }
                if ((((((((p_56 > (((g_32[7][1] && (safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s(0xC7C6L, (((safe_add_func_int16_t_s_s(0xC1DEL, g_127)) | (g_769 || (((((((safe_lshift_func_int16_t_s_s(((safe_mod_func_int32_t_s_s((((safe_mod_func_int16_t_s_s((safe_sub_func_uint8_t_u_u(g_2729[0][4], p_56)), ((g_1357 ^ 0x6CE1A812L) && l_2650))) , g_918[2][1][5]) != l_2650), 0x55F1BB13L)) > 1L), l_2594)) , g_44) , g_2084) , l_2489[6][0][3]) != p_56) != 4294967291UL) , l_2520))) == p_56))), p_56)), l_67))) < 1L) < 0x08L)) & g_2084) , g_1472) , g_400) & g_391) , 1UL) && 0x3FL))
                {
                    uint16_t l_2732 = 2UL;
                    l_2612[0] = (((safe_sub_func_int8_t_s_s(0xB4L, l_2688)) , (l_2732 ^ (safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((safe_unary_minus_func_uint8_t_u((p_56 < (p_56 ^ g_32[1][0])))), 2)), ((((((safe_add_func_uint8_t_u_u((0x8918CB0BL > p_56), ((-4L) || l_2740))) , l_63[3]) ^ 0xD30663B8L) ^ p_56) | 0x4A2BL) || g_315))))) != g_185[0][6][0]);
                }
                else
                {
                    int32_t l_2745 = 3L;
                    l_2708 = (p_56 && (((l_2709[1] && ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((l_2745 | (((((safe_add_func_uint32_t_u_u((((safe_lshift_func_uint8_t_u_u(p_56, (((l_2612[0] = ((((safe_lshift_func_int8_t_s_s((((0L >= ((safe_unary_minus_func_int32_t_s((0xFFBBL ^ (l_2555 = l_2709[0])))) > (l_2670 || (safe_lshift_func_int16_t_s_s(g_1138, p_56))))) == l_2755) ^ p_56), l_2710)) , p_56) & p_56) , g_250[0][1])) <= g_1472) ^ g_344))) , p_56) > p_56), p_56)) >= g_769) >= g_127) != g_53) ^ p_56)), g_820)), l_2523)) , 4UL)) | l_2554) == p_56));
                    for (g_820 = 0; (g_820 >= 0); g_820 -= 1)
                    {
                        int i;
                        return g_693[(g_820 + 1)];
                    }
                }
            }
lbl_3004:
            l_2612[0] = (safe_rshift_func_int8_t_s_s(0x6AL, l_2688));
            if ((safe_sub_func_uint16_t_u_u(((safe_unary_minus_func_uint8_t_u((1UL <= g_972))) >= 0xE6FAL), (l_2521 = 0x276AL))))
            {
                int16_t l_2784 = (-6L);
                int32_t l_2785[7][10][3] = {{{0x3416FBB8L,0x30044FF4L,(-2L)},{0x0523CF74L,1L,0xE6A7F8ECL},{3L,0x9E462E6BL,(-1L)},{0x80DD4D5FL,8L,0x74F3CB37L},{0x80DD4D5FL,0x80DD4D5FL,2L},{3L,0L,1L},{0x0523CF74L,(-5L),1L},{(-10L),1L,0L},{(-1L),1L,1L},{0x414CEA6EL,0x82C1F1FEL,0x551E483DL}},{{1L,0x6DEC5612L,0x3416FBB8L},{1L,0x1B67715EL,0L},{(-9L),0x1B67715EL,0L},{0L,0x6DEC5612L,(-8L)},{0x1B9AD149L,0x82C1F1FEL,3L},{0xE8DA2FB9L,1L,0L},{1L,1L,0x9E462E6BL},{0xE8DA2FB9L,(-1L),0L},{0x1B9AD149L,0xC3B263C4L,(-5L)},{0L,0x82C1F1FEL,1L}},{{(-9L),7L,1L},{1L,0xCFB6DD93L,(-5L)},{1L,1L,0L},{0x414CEA6EL,0x29F2DB05L,0x9E462E6BL},{(-1L),0x82C1F1FEL,0L},{(-10L),0x29F2DB05L,3L},{1L,1L,(-8L)},{(-1L),0xCFB6DD93L,0L},{0x82C1F1FEL,7L,0L},{0x82C1F1FEL,0x82C1F1FEL,0x3416FBB8L}},{{(-1L),0xC3B263C4L,0x551E483DL},{1L,(-1L),1L},{(-10L),1L,0L},{(-1L),1L,1L},{0x414CEA6EL,0x82C1F1FEL,0x551E483DL},{1L,0x6DEC5612L,0x3416FBB8L},{1L,0x1B67715EL,0L},{(-9L),0x1B67715EL,0L},{0L,0x6DEC5612L,(-8L)},{0x1B9AD149L,0x82C1F1FEL,3L}},{{0xE8DA2FB9L,1L,0L},{1L,1L,0x9E462E6BL},{0xE8DA2FB9L,(-1L),0L},{0x1B9AD149L,0xC3B263C4L,(-5L)},{0L,0x82C1F1FEL,1L},{(-9L),7L,1L},{1L,0xCFB6DD93L,(-5L)},{1L,1L,0L},{0x414CEA6EL,0x29F2DB05L,0x9E462E6BL},{(-1L),0x82C1F1FEL,0L}},{{(-10L),0x29F2DB05L,3L},{1L,1L,(-8L)},{(-1L),0xCFB6DD93L,0L},{0x82C1F1FEL,7L,0L},{0x82C1F1FEL,0x82C1F1FEL,0x3416FBB8L},{(-1L),0xC3B263C4L,0x551E483DL},{1L,(-1L),1L},{(-10L),1L,0L},{(-1L),1L,1L},{0x414CEA6EL,0x82C1F1FEL,0x551E483DL}},{{1L,0x6DEC5612L,0x3416FBB8L},{1L,0x1B67715EL,0L},{(-9L),0x1B67715EL,0L},{0L,0x6DEC5612L,(-8L)},{0x1B9AD149L,0x82C1F1FEL,3L},{0xE8DA2FB9L,1L,0L},{1L,1L,0x9E462E6BL},{0xE8DA2FB9L,(-1L),0L},{0x1B9AD149L,0xC3B263C4L,(-5L)},{0L,0x82C1F1FEL,1L}}};
                int32_t l_2789 = 0xBB0B75ADL;
                int32_t l_2790 = 0L;
                uint32_t l_2837[4] = {0xD8CDCC97L,0xD8CDCC97L,0xD8CDCC97L,0xD8CDCC97L};
                int i, j, k;
lbl_2943:
                if (g_108)
                {
                    uint8_t l_2761 = 1UL;
                    uint32_t l_2788 = 4294967289UL;
                    int32_t l_2791[4][5][9] = {{{(-8L),0xFDB64DAFL,0xA080896FL,4L,0x541D7298L,0x5E36A62FL,0x029A7320L,1L,0x0DF5CE33L},{0xA080896FL,0x5E36A62FL,4L,0xBE207B94L,(-8L),0xBE207B94L,4L,0x5E36A62FL,0xA080896FL},{(-6L),(-8L),4L,0xA54BB3B6L,0xF0CD08EFL,0xCD8C2604L,0x541D7298L,(-8L),0xBE207B94L},{0x571AEE78L,0x029A7320L,0xA080896FL,(-8L),0x1DE1D06BL,(-6L),0x4EB138F2L,0x4EB138F2L,(-6L)},{(-6L),0xF0CD08EFL,0x541D7298L,0xF0CD08EFL,(-6L),0x029A7320L,0xA54BB3B6L,0x4EB138F2L,0xFDB64DAFL}},{{0xA080896FL,1L,0xFDB64DAFL,0x541D7298L,4L,0x0DF5CE33L,7L,(-8L),0xCD8C2604L},{(-8L),0x571AEE78L,0x5E36A62FL,0xCD8C2604L,0x029A7320L,0x029A7320L,0xCD8C2604L,0x5E36A62FL,0x571AEE78L},{0x4EB138F2L,0x0DF5CE33L,(-8L),0xCD8C2604L,0xBB21A5A1L,(-6L),0x5E36A62FL,1L,0x8788910DL},{4L,0x8788910DL,0x029A7320L,0x541D7298L,0xA54BB3B6L,0xCD8C2604L,0x1DE1D06BL,0xBE207B94L,0x1DE1D06BL},{0xBE207B94L,0x0DF5CE33L,0xF0CD08EFL,0xF0CD08EFL,0x0DF5CE33L,0xBE207B94L,0xFDB64DAFL,0x571AEE78L,0x1DE1D06BL}},{{0xA54BB3B6L,0x571AEE78L,1L,(-8L),0x4EB138F2L,0x5E36A62FL,0xBE207B94L,0xF0CD08EFL,0x8788910DL},{(-8L),1L,0x571AEE78L,0xA54BB3B6L,0xFDB64DAFL,4L,0xFDB64DAFL,0xA54BB3B6L,0x571AEE78L},{0xF0CD08EFL,0xF0CD08EFL,0x0DF5CE33L,0xBE207B94L,0xFDB64DAFL,0x571AEE78L,0x1DE1D06BL,0x8788910DL,0xCD8C2604L},{0x541D7298L,0x029A7320L,0x8788910DL,4L,0x4EB138F2L,7L,0x5E36A62FL,0xFDB64DAFL,0xFDB64DAFL},{0xCD8C2604L,(-8L),0x0DF5CE33L,0x4EB138F2L,0x0DF5CE33L,(-8L),0xCD8C2604L,0xBB21A5A1L,(-6L)}},{{0xCD8C2604L,0x5E36A62FL,0x571AEE78L,(-8L),0xA54BB3B6L,1L,7L,4L,0xBE207B94L},{0x541D7298L,0xFDB64DAFL,1L,0xA080896FL,0xBB21A5A1L,0xA54BB3B6L,0xA54BB3B6L,0xBB21A5A1L,0xA080896FL},{0xF0CD08EFL,0x541D7298L,0xF0CD08EFL,(-6L),0x029A7320L,0xA54BB3B6L,0x4EB138F2L,0xFDB64DAFL,0x0DF5CE33L},{(-8L),0xA080896FL,0x029A7320L,0x571AEE78L,4L,1L,0x541D7298L,0x8788910DL,7L},{0xA54BB3B6L,4L,(-8L),(-6L),(-6L),(-8L),4L,0xA54BB3B6L,0xF0CD08EFL}}};
                    int i, j, k;
                    l_2761 = (g_897[0][2] = 0x75065145L);
                    g_2222 = ((safe_sub_func_int16_t_s_s((~p_56), (safe_mod_func_int16_t_s_s(((((((safe_sub_func_int16_t_s_s((l_2791[3][3][3] = (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((g_566 > (safe_sub_func_uint16_t_u_u(p_56, (l_2790 = (l_2789 = (g_1044 = (p_56 || (l_2557 = (safe_unary_minus_func_uint16_t_u((((((safe_add_func_uint16_t_u_u(0UL, ((safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s(((l_2785[6][7][2] = l_2784) && ((l_2521 = 0x0EL) , (safe_rshift_func_int8_t_s_u(((p_56 || 0x3F511B60L) <= l_67), 1)))), 2)) >= (-4L)), p_56)), g_566)) <= g_456))) && 6UL) && l_2788) == p_56) != p_56))))))))))) < g_897[0][2]), p_56)), p_56))), (-7L))) ^ l_2688) != g_250[0][1]) >= l_63[2]) || g_456) || g_972), p_56)))) ^ g_32[1][0]);
                    l_2612[0] = (1L ^ (safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((l_2785[6][7][2] = (~((p_56 | (safe_add_func_uint8_t_u_u((p_56 || (safe_sub_func_int32_t_s_s((p_56 >= (((l_2521 = (safe_rshift_func_uint8_t_u_u(l_2740, 6))) || (p_56 < (l_2670 = (((safe_sub_func_uint16_t_u_u((g_1001 < (safe_lshift_func_int8_t_s_s(((((((l_2489[5][3][3] = g_692) , (l_2791[0][3][7] = (l_2557 = ((safe_add_func_int32_t_s_s(((safe_mod_func_uint8_t_u_u((l_2555 = 255UL), 248UL)) >= 65533UL), g_449)) <= (-8L))))) > g_692) || p_56) == p_56) != 0x4CL), l_77))), g_566)) < 250UL) > p_56)))) ^ p_56)), p_56))), g_298))) | 0xAD0E7527L))), l_2688)), 5)));
                    return g_820;
                }
                else
                {
                    uint32_t l_2818 = 0x84B11E5EL;
                    int32_t l_2821 = (-7L);
                    int32_t l_2832 = 0xF60A75A9L;
                    uint8_t l_2858[2][6][3] = {{{1UL,0xFAL,0xFAL},{0x8BL,2UL,0xC6L},{1UL,1UL,1UL},{0xC6L,0UL,250UL},{0xFAL,1UL,1UL},{0xC6L,0UL,250UL}},{{0xFAL,1UL,1UL},{0xC6L,0UL,250UL},{0xFAL,1UL,1UL},{0xC6L,0UL,250UL},{0xFAL,1UL,1UL},{0xC6L,0UL,250UL}}};
                    uint32_t l_2876 = 4294967291UL;
                    int32_t l_2879[1][4];
                    uint16_t l_2880[2];
                    uint16_t l_2881 = 0x8213L;
                    int32_t l_2882 = 0L;
                    uint16_t l_2941 = 0x7155L;
                    int i, j, k;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_2879[i][j] = 2L;
                    }
                    for (i = 0; i < 2; i++)
                        l_2880[i] = 1UL;
                    for (l_2521 = 7; (l_2521 >= 0); l_2521 -= 1)
                    {
                        int i;
                        return g_34[(l_2521 + 2)];
                    }
                    if (l_2520)
                        goto lbl_2852;
lbl_2850:
                    for (g_2222 = 0; (g_2222 > (-15)); g_2222 = safe_sub_func_int8_t_s_s(g_2222, 4))
                    {
                        int8_t l_2815 = (-8L);
                        g_897[0][2] = (l_2821 = (((safe_mod_func_uint32_t_u_u((g_127 = 6UL), (l_2815 = g_2236[1]))) && (safe_mod_func_int8_t_s_s((((((g_1669 = ((((((l_2818 = g_693[1]) < (safe_rshift_func_uint16_t_u_u((l_2670 = l_2821), (g_33 == 0xB5L)))) <= p_56) || (safe_lshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(0xFD0FL, 5)) , (safe_lshift_func_int16_t_s_u(g_27[2][0], 8))), l_2688)), g_126)), 3))) && 254UL) , 8L)) != l_2821) != l_2785[6][7][2]) || l_2832) ^ l_2540), 0xFFL))) , l_2815));
                        l_2489[2][5][3] = (((p_56 == ((g_897[0][1] = l_2832) && 0xC0DD8427L)) > ((safe_lshift_func_uint16_t_u_s((l_2557 > (safe_rshift_func_int8_t_s_u((l_2521 || (l_2837[1] & ((((safe_lshift_func_int16_t_s_u(((((safe_mod_func_uint8_t_u_u((p_56 != (safe_rshift_func_uint16_t_u_u((p_56 & l_2688), 2))), 2L)) <= g_2236[1]) || l_77) && l_2688), 4)) , l_2789) || 0x3D49D56FL) == p_56))), l_2815))), l_2710)) || (-9L))) == g_504[1][4][2]);
                    }
                    if ((((l_2612[0] = (safe_add_func_int32_t_s_s(((g_276 , l_2790) , ((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((l_2489[5][3][3] = p_56) ^ p_56) > (g_86 = p_56)) >= g_34[8]), 2)) , (l_2832 = (l_2821 = g_2236[1]))), ((p_56 == (p_56 <= p_56)) && p_56))) < 0x4FB9513AL)), g_185[0][7][1]))) || 0x90L) == 7L))
                    {
                        if (g_132)
                            goto lbl_2850;
                        if (g_318)
                            goto lbl_2943;
lbl_2852:
                        if (g_2222)
                            goto lbl_2851;
                        l_2882 = ((g_456 = ((safe_sub_func_uint32_t_u_u((l_2489[5][3][3] = (g_486 = (safe_mod_func_int8_t_s_s((safe_unary_minus_func_uint32_t_u(l_2858[0][0][0])), (((g_183[0] = (safe_sub_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_add_func_int8_t_s_s(((((safe_add_func_int8_t_s_s(((safe_add_func_uint16_t_u_u((g_972 != (((((safe_sub_func_int16_t_s_s((((g_918[0][0][5] , ((((((p_56 > (p_56 > (safe_add_func_int32_t_s_s((((((l_2879[0][1] = (((safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint16_t_u((l_2876 && ((safe_rshift_func_int8_t_s_s(0x34L, 0)) || p_56)))), g_2729[1][6])) <= 0x4813L) || p_56)) < l_2837[1]) < p_56) > p_56) < g_427[1]), 0xFCE4AA4CL)))) != g_419) != g_486) == 0x16420D86L) | l_2880[1]) & l_2520)) == 0x5F54L) , l_2881), p_56)) >= g_1328) < 0xB1B7L) | 0L) | g_247)), p_56)) <= l_2784), g_317)) >= l_2520) || p_56) ^ p_56), l_2882)), g_317)) || (-6L)), 1UL))) , g_315) ^ g_32[1][0]))))), 1L)) <= 0UL)) , l_2557);
                        l_2489[5][3][3] = ((0x2829L ^ (((p_56 == (~((safe_add_func_uint32_t_u_u(g_27[1][0], l_2554)) ^ ((l_2557 = (safe_add_func_uint32_t_u_u((l_2540 , (safe_mod_func_uint8_t_u_u((l_2821 ^ (safe_rshift_func_uint16_t_u_s((((safe_mod_func_uint32_t_u_u(p_56, g_276)) | g_315) , l_2896), 3))), l_2524))), p_56))) == l_2784)))) != g_897[0][2]) != p_56)) <= 0xA58FL);
                    }
                    else
                    {
                        int32_t l_2900 = 0x3EEE9F64L;
                        g_2236[1] = ((safe_add_func_int16_t_s_s((!((((g_315 ^ 65533UL) | l_2900) , ((l_2785[6][7][2] == ((safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s(p_56, 4)), ((g_86 = (safe_rshift_func_int8_t_s_u((0x83293638L >= (safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(g_400, 11)), (1L == (g_419 || l_2876))))), 6))) > l_2521))) != 0xD3F1L)) >= l_2555)) < p_56)), 0L)) , p_56);
                        l_2879[0][1] = (safe_sub_func_uint32_t_u_u(g_1328, (safe_mod_func_int16_t_s_s(g_2729[0][4], (safe_lshift_func_int8_t_s_u((g_185[0][6][1] , (l_2900 = p_56)), (((safe_mod_func_int8_t_s_s(g_27[1][0], (safe_add_func_uint32_t_u_u(((((safe_lshift_func_int16_t_s_s((((safe_add_func_uint32_t_u_u((l_2930 = (((safe_sub_func_int32_t_s_s((l_2821 = (((safe_unary_minus_func_uint32_t_u(1UL)) != (-1L)) >= p_56)), ((g_419 = (((((g_503 = (((((safe_add_func_uint16_t_u_u(((g_456 && g_486) , p_56), g_27[2][0])) | l_2688) > l_2540) , 0x48L) ^ l_2837[1])) > l_2876) != l_2524) || p_56) | g_126)) & 0xB1L))) | 0x5C7476B0L) < g_400)), p_56)) >= 0xE9L) || 0x69L), p_56)) , 0x07L) & g_897[0][2]) && p_56), 0x081FC442L)))) < l_2555) & g_315)))))));
                        g_2222 = (safe_rshift_func_uint8_t_u_u(((((((g_183[9] = 4294967294UL) && 0x4AD86DD0L) <= (safe_rshift_func_uint8_t_u_u(((((l_2900 > l_2900) , (l_2789 = (g_2942 = (l_2941 = (l_2489[4][0][2] = ((safe_rshift_func_uint8_t_u_s((l_2790 = (safe_rshift_func_uint8_t_u_u(0x21L, 3))), (l_2900 = ((l_2540 , (p_56 == (safe_mod_func_int32_t_s_s(p_56, 0xBB0AE272L)))) , g_53)))) , 4UL)))))) <= l_2837[1]) <= g_456), g_32[5][0]))) & 4294967290UL) == g_400) != 8L), 7));
                        g_897[0][2] = (-9L);
                    }
                }
                l_2670 = p_56;
            }
            else
            {
                uint32_t l_2949 = 0x58059803L;
                int32_t l_2992 = 1L;
                int32_t l_2995 = 0x02A2020EL;
                for (l_2755 = 0; (l_2755 <= 59); l_2755 = safe_add_func_int8_t_s_s(l_2755, 6))
                {
                    uint8_t l_2950 = 0x8BL;
                    g_897[0][2] = (safe_lshift_func_uint8_t_u_s((((!((((p_56 | (l_2949 = 0x77698987L)) >= ((l_2555 < (l_2950 = p_56)) , g_44)) || ((~(safe_add_func_int32_t_s_s(l_2950, (l_2612[0] = (((p_56 = (g_298 = p_56)) & (l_2555 = (safe_mod_func_uint32_t_u_u((((((safe_mod_func_int32_t_s_s((safe_sub_func_int32_t_s_s(l_2949, g_1363)), l_2949)) == g_566) ^ g_739) , 0xC0DEFCDFL) , g_53), 0x2BAB85A4L)))) , 1L))))) > 0UL)) , g_639)) | 0x86L) == l_2688), 1));
                }
                if (g_692)
                    goto lbl_2851;
                for (l_2896 = 0; (l_2896 <= 9); l_2896++)
                {
                    uint8_t l_2991 = 8UL;
                    int32_t l_2993 = 0xA0681AF4L;
                    int32_t l_2994 = (-4L);
                    l_2995 = (safe_mod_func_int16_t_s_s(((p_56 = ((((((safe_sub_func_int8_t_s_s((1L != (p_56 >= (safe_sub_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((~l_2949), (safe_rshift_func_int8_t_s_s(((+p_56) <= p_56), (safe_add_func_uint8_t_u_u(255UL, ((~p_56) , (((safe_rshift_func_uint8_t_u_s((l_2994 = ((!0x5B15L) <= ((((((safe_add_func_uint8_t_u_u(((l_2993 = (((((l_2992 = ((((l_2555 = (safe_sub_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_add_func_int16_t_s_s(((+(-1L)) >= p_56), 1UL)), p_56)), g_918[4][0][1])), 4294967295UL))) > g_250[0][0]) == 0x21D28F4EL) == l_2991)) | l_2612[1]) > 0UL) ^ l_2991) | 1L)) <= 0x4897L), g_183[9])) , p_56) , l_2670) , l_2540) ^ g_2942) , 0xE2L))), 0)) > g_27[2][0]) && p_56)))))))), (-1L))))), g_1328)) & g_1669) , l_2521) <= p_56) && l_2540) <= l_2949)) && p_56), 65535UL));
                    if ((l_2523 != (safe_lshift_func_uint16_t_u_u((l_2489[7][4][2] = p_56), (!((((l_2991 , (p_56 >= (l_2670 = ((g_897[0][2] = p_56) >= (l_2994 && (safe_unary_minus_func_int32_t_s(1L))))))) <= (safe_lshift_func_uint8_t_u_s(((g_391 = ((l_3002[0][9] = (((((((g_185[1][2][0] < (0x5146581DL >= 4294967295UL)) | p_56) & g_486) , 0xFFFDE4E1L) , l_2991) & 1L) ^ p_56)) >= p_56)) | g_3003), 3))) >= l_2520) >= 250UL))))))
                    {
                        if (l_2896)
                            goto lbl_3004;
                        return l_2612[1];
                    }
                    else
                    {
                        uint16_t l_3005 = 0x948FL;
                        int32_t l_3011[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_3011[i] = 0x76EE0DA8L;
                        l_2994 = ((((((l_3005 = (-1L)) ^ 0x50L) > (safe_add_func_int32_t_s_s(p_56, ((((((g_972 = ((0UL > (l_2992 != l_457)) != (+(safe_sub_func_uint8_t_u_u((g_35 = l_3011[2]), (safe_rshift_func_int8_t_s_u(g_108, (safe_rshift_func_uint8_t_u_s(g_486, 3))))))))) < p_56) <= 0UL) <= l_2594) ^ 65534UL) ^ 0xEB0EL)))) | g_1001) != p_56) | p_56);
                        l_2555 = (((p_56 & (l_3011[0] = ((g_1357 , (g_108 > (safe_add_func_int8_t_s_s(((((safe_mod_func_int32_t_s_s((((((((((g_1472 = (g_897[0][0] = (4294967294UL | (((safe_add_func_int16_t_s_s(((g_185[1][8][0] = (safe_lshift_func_int16_t_s_u((l_2930 = ((((~(g_1363 != (safe_rshift_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(((((~(((g_693[1] , (((l_2612[1] = g_693[1]) , (((safe_lshift_func_uint16_t_u_s((g_1044 = g_2942), 10)) | p_56) >= p_56)) || p_56)) || p_56) | 255UL)) != l_3011[0]) < 0L) | (-1L)), p_56)) , l_2992), 6)))) >= g_317) & p_56) != p_56)), l_2995))) , l_2557), g_27[2][0])) , g_577) | 0x00L)))) < g_53) & 0x5C9A3945L) == 0xCAD33C40L) && 0xD6D5L) , 4294967288UL) , 0x0A5BL) >= l_2991) <= l_2489[5][3][3]), p_56)) , l_2740) != 0x26L) != g_34[5]), 1UL)))) , l_3005))) > 0x43L) == 8L);
                        l_2670 = ((((l_3032 > l_3011[2]) != (safe_sub_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((g_639 = ((((((((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(((safe_mod_func_int8_t_s_s(p_56, l_2949)) != 0x75A5L), g_1045)), (safe_mod_func_uint32_t_u_u(l_2555, (p_56 ^ g_391))))) , g_391) <= g_3045[1][2]) ^ 0x10D7219DL) > l_2670) && 0x29L) > 0xAAL) < 0x580F5507L)) >= l_2991) == g_250[0][4]) , 65532UL), 65526UL)) > l_2992), g_27[2][0]))) ^ l_2650) ^ p_56);
                    }
                }
                if ((((safe_mod_func_int8_t_s_s((-1L), (safe_mod_func_uint16_t_u_u(p_56, (safe_rshift_func_uint8_t_u_s(((0x66L == (((safe_lshift_func_int8_t_s_s((((g_504[1][1][2] ^ ((((l_3002[0][9] = (!(safe_add_func_uint32_t_u_u((p_56 , (((p_56 < ((safe_sub_func_int16_t_s_s((((3UL ^ (safe_lshift_func_uint16_t_u_s((0UL < (-9L)), 3))) >= 3UL) ^ p_56), 9UL)) , p_56)) & l_2949) , p_56)), g_1472)))) != l_3061) >= g_185[0][6][1]) != p_56)) == 0x9BC6L) == 0UL), 3)) || l_2521) & (-10L))) < l_2612[0]), l_2594)))))) | l_2992) & g_400))
                {
                    int32_t l_3062 = 0x629C30A2L;
                    l_3062 = p_56;
                }
                else
                {
                    int8_t l_3087[5];
                    int32_t l_3095 = 0x0D1152E9L;
                    int i;
                    for (i = 0; i < 5; i++)
                        l_3087[i] = 0x39L;
                    if (p_56)
                    {
                        int16_t l_3084 = (-10L);
                        l_2612[0] = (0xA08CL == (safe_mod_func_int8_t_s_s(((g_2222 = ((251UL | (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s((safe_mod_func_int16_t_s_s((!0xF8L), (((-3L) == p_56) , (safe_add_func_int16_t_s_s(((((safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((g_1669 = (safe_sub_func_uint16_t_u_u(g_400, (safe_lshift_func_int16_t_s_s(((l_2489[5][3][3] = g_108) || ((4UL >= ((p_56 | g_1669) != g_3003)) >= g_769)), l_2554))))), l_3084)), g_820)) || l_2995) , l_2670) == 1UL), l_2521))))), l_2650)) | 3L), 0x95L)), 6UL))) != g_183[4])) , g_183[9]), g_317)));
                        return l_2594;
                    }
                    else
                    {
                        l_2992 = (((p_56 < ((l_3002[0][9] = (safe_add_func_int32_t_s_s(0xCB6000F4L, (l_3087[3] = g_1357)))) | (safe_lshift_func_uint16_t_u_u((l_3094 = (g_897[0][2] > (l_2995 <= (safe_rshift_func_uint16_t_u_s((((g_972 = p_56) == (safe_lshift_func_int8_t_s_s((8L & (l_2489[5][3][3] = (0x4AFDL & (l_2612[0] = p_56)))), l_3094))) , l_3095), 3))))), 0)))) != g_1138) && l_2992);
                        g_2236[0] = ((safe_lshift_func_int8_t_s_u(((g_1044 = (0x8A1C0AF5L && (p_56 > (safe_lshift_func_int8_t_s_s(g_504[1][1][2], 4))))) != (g_298 = (0x9CL && (((safe_unary_minus_func_uint8_t_u(g_820)) ^ (safe_mod_func_uint32_t_u_u(l_2524, (l_2992 = ((-1L) || g_2942))))) <= p_56)))), 6)) & g_419);
                        g_2236[5] = 0L;
                    }
                }
            }
        }
        else
        {
            g_897[0][2] = l_3002[0][9];
            return g_566;
        }
    }
    else
    {
        int32_t l_3109 = 0x36CF7B42L;
        int32_t l_3118[6];
        int16_t l_3119 = 0L;
        int32_t l_3122[6][7][6] = {{{0L,1L,1L,0L,0x2183DC92L,0xF0AD9901L},{0L,0x2183DC92L,0xF0AD9901L,4L,1L,0xF0AD9901L},{0x9871B534L,1L,1L,0L,1L,1L},{4L,0x2183DC92L,0x8E46E817L,0L,0x2183DC92L,1L},{0x9871B534L,1L,0x8E46E817L,4L,1L,1L},{0L,1L,1L,0L,0x2183DC92L,0xF0AD9901L},{0L,0x2183DC92L,0xF0AD9901L,4L,1L,0xF0AD9901L}},{{0x9871B534L,1L,1L,0L,1L,1L},{4L,0x2183DC92L,0x8E46E817L,0L,0x2183DC92L,1L},{0x9871B534L,1L,0x8E46E817L,4L,1L,1L},{0L,1L,1L,0L,0x2183DC92L,0xF0AD9901L},{0L,0x2183DC92L,0xF0AD9901L,4L,1L,0xF0AD9901L},{0x9871B534L,1L,1L,0L,1L,1L},{4L,0x2183DC92L,0x8E46E817L,0L,0x2183DC92L,1L}},{{0x9871B534L,1L,0x8E46E817L,4L,1L,1L},{0L,1L,1L,0L,0x2183DC92L,0xF0AD9901L},{0L,0x2183DC92L,0xF0AD9901L,4L,1L,0xF0AD9901L},{0x9871B534L,1L,1L,0L,1L,1L},{4L,0x2183DC92L,0x8E46E817L,0L,0x2183DC92L,1L},{0x9871B534L,1L,0x8E46E817L,4L,1L,1L},{0L,1L,1L,0L,0x2183DC92L,0xF0AD9901L}},{{0L,0x2183DC92L,0xF0AD9901L,4L,1L,0xF0AD9901L},{0x9871B534L,1L,1L,0L,1L,1L},{4L,0x2183DC92L,0x8E46E817L,0L,0x2183DC92L,1L},{0x9871B534L,1L,0x8E46E817L,4L,1L,1L},{0L,1L,1L,0L,0x2183DC92L,0xF0AD9901L},{0L,0x2183DC92L,0xF0AD9901L,4L,1L,0xF0AD9901L},{1L,6L,0x69884704L,0x2183DC92L,0x69884704L,6L}},{{0xF0AD9901L,0xC248C659L,0x8552AB01L,0x2183DC92L,0xC248C659L,0x69884704L},{1L,0x69884704L,0x8552AB01L,0xF0AD9901L,6L,6L},{0x8E46E817L,0x69884704L,0x69884704L,0x8E46E817L,0xC248C659L,0x05FF7C23L},{0x8E46E817L,0xC248C659L,0x05FF7C23L,0xF0AD9901L,0x69884704L,0x05FF7C23L},{1L,6L,0x69884704L,0x2183DC92L,0x69884704L,6L},{0xF0AD9901L,0xC248C659L,0x8552AB01L,0x2183DC92L,0xC248C659L,0x69884704L},{1L,0x69884704L,0x8552AB01L,0xF0AD9901L,6L,6L}},{{0x8E46E817L,0x69884704L,0x69884704L,0x8E46E817L,0xC248C659L,0x05FF7C23L},{0x8E46E817L,0xC248C659L,0x05FF7C23L,0xF0AD9901L,0x69884704L,0x05FF7C23L},{1L,6L,0x69884704L,0x2183DC92L,0x69884704L,6L},{0xF0AD9901L,0xC248C659L,0x8552AB01L,0x2183DC92L,0xC248C659L,0x69884704L},{1L,0x69884704L,0x8552AB01L,0xF0AD9901L,6L,6L},{0x8E46E817L,0x69884704L,0x69884704L,0x8E46E817L,0xC248C659L,0x05FF7C23L},{0x8E46E817L,0xC248C659L,0x05FF7C23L,0xF0AD9901L,0x69884704L,0x05FF7C23L}}};
        int i, j, k;
        for (i = 0; i < 6; i++)
            l_3118[i] = (-6L);
        l_2670 = (safe_sub_func_uint32_t_u_u(((-1L) ^ ((g_35 = l_2489[3][5][2]) || ((g_2729[0][4] && (safe_sub_func_int8_t_s_s(((l_3114 = (l_3109 < (safe_mod_func_uint8_t_u_u(l_2489[5][3][3], (safe_lshift_func_uint16_t_u_s(l_2554, 13)))))) | (((((((((safe_sub_func_int8_t_s_s((l_3118[1] = (!l_2670)), ((l_3122[0][6][5] = (((g_1472 = (((l_3119 , (safe_add_func_int8_t_s_s(((((((((((p_56 || 0xCEB195B1L) , l_457) || 0L) & p_56) != 0x2FL) < 0x14C94FAAL) & 0x9B09L) || g_1045) && p_56) || l_3109), 8UL))) , g_504[5][4][0]) == l_67)) | g_419) <= l_2489[2][2][2])) >= p_56))) == 4294967295UL) ^ g_32[3][0]) < 0x653E3091L) < 5UL) & (-1L)) >= 1L) || l_2704) > p_56)), 0x35L))) , p_56))), p_56));
        l_3122[0][6][5] = (p_56 & (l_3118[4] = ((((l_3109 ^ (safe_mod_func_int32_t_s_s(((((((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u(p_56, (((l_2489[4][2][0] = p_56) < p_56) == ((l_3122[0][6][5] | g_127) < ((+(((safe_rshift_func_uint16_t_u_u((g_2236[0] && (g_427[1] > l_3002[0][9])), l_2554)) <= 1L) & 0x58BDL)) >= p_56))))) , l_2896), p_56)) , l_3122[0][6][5]) != l_2554) , p_56) | p_56) & 0x0CL), g_2084))) || l_2523) > p_56) != g_639)));
    }
    return l_2447;
}







inline static int16_t func_60(uint8_t p_61, uint8_t p_62)
{
    int16_t l_2448 = 5L;
    uint16_t l_2449[5][5][8] = {{{0xB7EFL,0x1191L,65535UL,1UL,3UL,3UL,1UL,65535UL},{0xF4B8L,0xF4B8L,0UL,0xF3DCL,0x31D1L,65534UL,0xD2A2L,0x3025L},{65530UL,0x011BL,3UL,0x1191L,0UL,65535UL,0x17DBL,0x3025L},{0x011BL,65535UL,0x2340L,0xF3DCL,65528UL,0xFE1AL,65527UL,65535UL},{0xC804L,0x4B97L,0xB51BL,1UL,0x9CACL,0x36EEL,0x4A81L,0UL}},{{0x17DBL,1UL,0x5DEAL,0x2340L,0xC804L,65535UL,65535UL,0x31D1L},{65535UL,0x2340L,65528UL,65526UL,0x0FFCL,65528UL,65527UL,0x1FCFL},{65526UL,0xB7EFL,0xF7E8L,65535UL,0xF4B8L,1UL,65531UL,8UL},{0x2340L,0x3025L,3UL,0x17DBL,65535UL,3UL,0x2776L,0xF3DCL},{1UL,65528UL,0x3275L,0xC804L,0x3275L,65528UL,1UL,65535UL}},{{0xF3DCL,65527UL,0xDABEL,0x011BL,0xD2A2L,8UL,1UL,0xF4B8L},{0x1191L,1UL,0xE0E4L,65530UL,0xD2A2L,0x0FFCL,0xF9C6L,0xC804L},{0xF3DCL,0x3275L,6UL,0xF4B8L,0x55C5L,0x0C54L,0xFE1AL,0xDABEL},{65535UL,3UL,0x4A81L,0x17DBL,0x2340L,0x011BL,0x16FFL,65528UL},{0x36EEL,0x1FCFL,0xFB0DL,1UL,65535UL,0xDABEL,0xBBFCL,65535UL}},{{0x1191L,0x2C84L,65526UL,65535UL,65534UL,0UL,0x2340L,8UL},{0x2340L,65535UL,0x011BL,0x2776L,65535UL,1UL,6UL,65535UL},{65526UL,0xFE1AL,0xF22DL,0x7559L,65535UL,0xF7E8L,0xF7E8L,65535UL},{65535UL,65526UL,65526UL,65535UL,1UL,0xB51BL,65530UL,0x0C54L},{0x1FCFL,0xE0E4L,0xF3DCL,0x75B4L,65528UL,0x3025L,0x16FFL,0x2776L}},{{8UL,0xE0E4L,0xDABEL,0xF7E8L,0xFE1AL,0xB51BL,0xFB0DL,0x2340L},{65535UL,65526UL,0x2C84L,0x1191L,0UL,0xF7E8L,65535UL,0xFB0DL},{0x17DBL,0xFE1AL,65535UL,0x0FFCL,0x75B4L,1UL,0x3275L,0xE0E4L},{1UL,65535UL,0x88FDL,0x477DL,0x3275L,0UL,0x477DL,3UL},{65535UL,0x2C84L,0x55C5L,6UL,0xFB0DL,0xDABEL,0xF9C6L,0xBBFCL}}};
    int32_t l_2450 = 9L;
    int32_t l_2472 = 6L;
    int32_t l_2473 = 0x0E419DCBL;
    int32_t l_2474 = (-6L);
    int i, j, k;
    l_2450 = (l_2448 == l_2449[4][3][6]);
    l_2474 = (((safe_sub_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u(0UL, (+2L))) == (g_108 = (((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((1L >= (g_203 > ((((safe_rshift_func_uint8_t_u_s((l_2473 = (l_2472 = (safe_lshift_func_int16_t_s_s(0xA6EAL, (safe_lshift_func_uint16_t_u_s(((((safe_rshift_func_uint8_t_u_u((((l_2450 = ((g_2084 = ((l_2448 != (g_504[5][4][0] = (safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((g_1138 != (((g_1044 = g_250[0][4]) & p_62) < 0x6138L)), p_62)), p_62)))) ^ 0x8A2CA4E2L)) , l_2449[4][3][6])) != l_2448) & p_61), 6)) == p_61) >= 4294967295UL) , 3UL), p_61)))))), 6)) , 0xA3E49F4AL) , 0xA2L) , g_5))) > l_2448), l_2449[4][3][6])), p_62)) , l_2448) > l_2448))) , l_2449[4][0][4]), l_2448)) < 0x9DFEED28L) != 0xA0D8L);
    if (p_61)
        goto lbl_2475;
lbl_2475:
    l_2472 = g_427[1];
    l_2474 = (((safe_sub_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((((+p_61) && (safe_mod_func_int16_t_s_s(p_62, l_2473))) || (((p_62 < ((1L && ((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s(p_62, ((((p_62 < 4UL) > (safe_rshift_func_uint8_t_u_u(p_61, 1))) < 0x27E4L) != g_2236[4]))), 0x311AL)) < g_86)) ^ g_344)) && 0xE679FC3AL) != l_2449[3][0][5])), 5)), p_62)) , l_2474) , 0x59E8D0EAL);
    return g_504[1][1][2];
}







static uint32_t func_64(int32_t p_65, int16_t p_66)
{
    uint16_t l_464 = 65535UL;
    uint8_t l_467[8][4][6] = {{{255UL,0xF7L,0x87L,1UL,0x13L,255UL},{255UL,255UL,255UL,0UL,0x31L,0x8DL},{1UL,255UL,1UL,248UL,251UL,255UL},{0x34L,0xA3L,248UL,0UL,4UL,0UL}},{{0xEFL,0x31L,0xEFL,0x87L,248UL,255UL},{255UL,0x97L,255UL,0xA0L,0xA3L,0xF7L},{0x13L,255UL,0xD3L,0xA0L,0xEFL,0x87L},{255UL,0x13L,1UL,0x87L,0xF7L,255UL}},{{0xEFL,0x8DL,0xA3L,0UL,0x31L,0xE4L},{0x34L,0UL,0x64L,248UL,248UL,0x64L},{1UL,1UL,248UL,0UL,0x89L,0xF7L},{255UL,0x31L,0x26L,1UL,8UL,248UL}},{{255UL,255UL,0x26L,0x8DL,1UL,0xF7L},{0UL,0x8DL,248UL,0xE4L,0xEFL,0x64L},{0xE4L,0xEFL,0x64L,0x87L,0x13L,0xE4L},{0x97L,255UL,0x0FL,0UL,0x0FL,255UL}},{{0x0FL,0xF7L,8UL,0x31L,1UL,255UL},{0x89L,0x0FL,0x31L,0x64L,0x8DL,0x87L},{0UL,0x0FL,0UL,0xD3L,1UL,255UL},{0x26L,0xF7L,0UL,0xEFL,0x0FL,1UL}},{{0x87L,255UL,0x34L,0UL,0x64L,248UL},{0xEFL,255UL,8UL,8UL,255UL,0xEFL},{0x13L,0xEFL,4UL,0x64L,0x89L,255UL},{252UL,0UL,255UL,255UL,1UL,0xD3L}},{{252UL,0x5DL,255UL,0x64L,0xE4L,1UL},{0x13L,0x89L,0UL,8UL,0x34L,0xA3L},{0xEFL,0xF7L,0xEFL,0UL,0x5DL,0x64L},{0x87L,0xEFL,0x31L,0xEFL,0x87L,248UL}},{{0x26L,0x64L,255UL,0xD3L,255UL,0x26L},{0UL,0x97L,252UL,0x64L,0x0FL,0x26L},{0x89L,0x13L,255UL,0x31L,0x34L,248UL},{0x0FL,0x5DL,0x31L,0UL,255UL,0x64L}}};
    uint8_t l_471 = 248UL;
    int32_t l_480[8][8] = {{0L,0L,0x2D324052L,0L,0L,0x2D324052L,0L,0L},{(-1L),0L,(-1L),(-1L),0L,(-1L),(-1L),0L},{0L,(-1L),(-1L),0L,(-1L),(-1L),0L,(-1L)},{0L,0L,0x2D324052L,0L,0L,0x2D324052L,0L,0L},{(-1L),0L,(-1L),(-1L),0L,(-1L),(-1L),0L},{0L,(-1L),(-1L),0L,(-1L),(-1L),0L,(-1L)},{0L,0L,0x2D324052L,0L,0L,0x2D324052L,0L,0L},{(-1L),0L,(-1L),(-1L),0L,(-1L),(-1L),0L}};
    uint16_t l_484 = 6UL;
    int8_t l_493 = 8L;
    int8_t l_524 = 0L;
    int32_t l_547 = (-1L);
    uint16_t l_578 = 0x4DC1L;
    uint32_t l_638 = 4294967288UL;
    int8_t l_803 = (-9L);
    int8_t l_819 = (-5L);
    int32_t l_821 = 0xB9B34874L;
    uint32_t l_845 = 1UL;
    int16_t l_896 = 2L;
    int16_t l_963 = 0L;
    int32_t l_1003[9] = {0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL,0x9F3D0B9CL};
    int32_t l_1004[9] = {(-1L),0xA11D63BCL,(-1L),0xA11D63BCL,(-1L),0xA11D63BCL,(-1L),0xA11D63BCL,(-1L)};
    int32_t l_1005 = 0xE514720CL;
    int16_t l_1022[1];
    int32_t l_1238 = 0x98108A17L;
    uint32_t l_1283 = 0x73DC3D07L;
    uint8_t l_1284 = 0x18L;
    uint32_t l_1298 = 7UL;
    int32_t l_1325 = 0x6A9C04A7L;
    uint16_t l_1467[1][6][5] = {{{0UL,0UL,0UL,0UL,0UL},{0x8240L,0x6A46L,1UL,1UL,0UL},{0x5ED4L,0UL,0x5ED4L,0x5ED4L,0UL},{0UL,1UL,1UL,1UL,1UL},{0UL,0UL,0UL,0UL,0UL},{1UL,1UL,1UL,1UL,0UL}}};
    uint16_t l_1635 = 0x316BL;
    int32_t l_1686[7];
    uint32_t l_1746[2];
    uint32_t l_1747 = 0x2A40B5CFL;
    int8_t l_1789 = (-1L);
    uint32_t l_1811 = 0xE94B7C56L;
    uint8_t l_1861 = 0x82L;
    int32_t l_1918[10] = {1L,0x5351D12EL,0x5351D12EL,1L,0x5351D12EL,0x5351D12EL,1L,0x5351D12EL,0x5351D12EL,1L};
    uint32_t l_1948[8][2] = {{0xAEDFA23BL,0xEC23F689L},{0xEC23F689L,0xAEDFA23BL},{0xEC23F689L,0xEC23F689L},{0xAEDFA23BL,0xEC23F689L},{0xEC23F689L,0xAEDFA23BL},{0xEC23F689L,0xEC23F689L},{0xAEDFA23BL,0xEC23F689L},{0xEC23F689L,0xAEDFA23BL}};
    int32_t l_2003 = 6L;
    int16_t l_2016 = (-4L);
    int16_t l_2106[8][4];
    int8_t l_2288 = 0x12L;
    uint16_t l_2304 = 2UL;
    uint32_t l_2359 = 0UL;
    uint32_t l_2402 = 1UL;
    int i, j, k;
    for (i = 0; i < 1; i++)
        l_1022[i] = 1L;
    for (i = 0; i < 7; i++)
        l_1686[i] = 0x82D5726CL;
    for (i = 0; i < 2; i++)
        l_1746[i] = 4294967295UL;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
            l_2106[i][j] = 0x1DC4L;
    }
lbl_1084:
    if ((((safe_add_func_uint32_t_u_u(((safe_add_func_int16_t_s_s((safe_mod_func_uint32_t_u_u(0x25E3DA1EL, p_66)), ((l_464 | g_185[0][5][2]) >= ((g_456 = ((l_471 = ((((safe_sub_func_uint16_t_u_u(l_467[1][0][4], (p_66 && 0UL))) <= (g_5 , (g_35 = (safe_sub_func_uint32_t_u_u((+0xC6L), l_464))))) > g_250[0][3]) , p_65)) > l_464)) & 0L)))) & 0x6E446F69L), p_66)) & g_27[2][0]) && g_185[0][3][2]))
    {
        uint32_t l_472 = 0xCB9BC567L;
        l_472 = p_65;
    }
    else
    {
        int8_t l_481 = 0x23L;
        int32_t l_482 = 0xC4F68496L;
        int32_t l_822 = 0L;
        uint32_t l_825 = 4294967295UL;
        for (g_400 = 0; (g_400 <= 7); ++g_400)
        {
            int16_t l_483[5][8][1] = {{{0xEED9L},{(-4L)},{0xD737L},{(-4L)},{0xEED9L},{0xD737L},{(-2L)},{(-2L)}},{{0xD737L},{0xEED9L},{(-4L)},{0xD737L},{(-4L)},{0xEED9L},{0xD737L},{(-2L)}},{{(-2L)},{0xD737L},{0xEED9L},{(-4L)},{0xD737L},{(-4L)},{0xEED9L},{0xD737L}},{{(-2L)},{(-2L)},{0xD737L},{0xEED9L},{(-4L)},{0xD737L},{(-4L)},{0xEED9L}},{{0xD737L},{(-2L)},{(-2L)},{0xD737L},{0xEED9L},{(-4L)},{0xD737L},{(-4L)}}};
            int32_t l_485[5] = {(-1L),(-1L),(-1L),(-1L),(-1L)};
            int32_t l_548 = 4L;
            uint8_t l_694 = 0x92L;
            uint32_t l_695 = 0xD98FA9A8L;
            uint16_t l_796 = 0x67DAL;
            int32_t l_797 = 0xFCC03608L;
            int32_t l_971 = 0x08A46F1AL;
            int32_t l_1080 = 0xA6E0B66AL;
            int i, j, k;
            if ((safe_sub_func_uint8_t_u_u(p_65, 0x1EL)))
            {
                int16_t l_479[1];
                int32_t l_494 = 0x80C86479L;
                int32_t l_521 = 0xB614299BL;
                uint32_t l_590 = 0x8A8EA48FL;
                int i;
                for (i = 0; i < 1; i++)
                    l_479[i] = 0L;
                if ((0x08136386L || (((((p_66 , (p_66 || ((safe_mod_func_int8_t_s_s(((4294967289UL | (l_480[6][0] = ((0xED6FAAFDL && l_479[0]) <= 0x39L))) <= ((l_481 = g_298) != ((((l_482 == 0x7CA6L) < 3L) == p_66) != p_65))), g_108)) != l_483[1][0][0]))) ^ g_32[1][0]) ^ 4UL) != l_484) | 0L)))
                {
                    int16_t l_502 = 0xB7ABL;
                    g_486 = ((l_485[4] = (g_32[1][0] , 0UL)) > g_34[3]);
                    for (g_298 = 7; (g_298 == 0); g_298 = safe_sub_func_int8_t_s_s(g_298, 2))
                    {
                        g_503 = (safe_lshift_func_uint16_t_u_s(((((((((safe_add_func_uint8_t_u_u(252UL, (l_494 = l_493))) ^ (((((((l_482 | (safe_add_func_int16_t_s_s(((~g_53) < (((!p_66) <= g_499) , l_483[1][0][0])), ((safe_sub_func_uint8_t_u_u(g_185[0][0][2], (l_502 & p_66))) || p_65)))) && (-1L)) , p_65) & l_502) ^ 0xB5L) , 0xC4E62DC6L) ^ p_66)) <= l_479[0]) , 4UL) || g_132) >= 0x35L) ^ 1UL) ^ l_479[0]), 5));
                        return g_35;
                    }
                    g_504[1][1][2] = l_502;
                }
                else
                {
                    uint32_t l_505 = 4294967295UL;
                    l_521 = (((g_127 && ((l_494 = 0UL) && ((((l_505 , (g_127 != ((((safe_mod_func_int16_t_s_s((1UL | (safe_lshift_func_uint8_t_u_u((g_456 = p_66), ((safe_mod_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((l_483[1][0][0] , ((safe_rshift_func_uint16_t_u_s((65532UL <= (safe_unary_minus_func_uint8_t_u(0UL))), l_479[0])) , 0xE1L)), g_27[2][0])), g_449)) , 0xB3L)))), l_484)) | l_464) || l_482) > l_480[6][5]))) >= g_317) == 1UL) , p_66))) != p_65) | p_65);
                }
                l_482 = (((-1L) ^ p_66) > (((safe_lshift_func_uint8_t_u_u((((p_66 || (0L ^ (l_524 , (safe_mod_func_int16_t_s_s((safe_mod_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_s((l_524 <= p_65), 9)) , ((safe_mod_func_uint16_t_u_u((g_185[0][6][1] == (l_483[0][5][0] && (-7L))), 0xB3F4L)) == p_65)), p_66)), p_66))))) || g_449) != (-8L)), 5)) != p_65) > g_34[8]));
                if (((l_548 = (safe_sub_func_uint8_t_u_u((l_485[4] = (g_185[0][6][1] = (safe_mod_func_uint32_t_u_u(p_65, 4294967295UL)))), (safe_mod_func_int16_t_s_s(p_65, (safe_rshift_func_uint8_t_u_u(((((l_482 = (safe_sub_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(l_479[0], (l_547 = ((0x7ABBL ^ (((l_479[0] , (((safe_sub_func_uint8_t_u_u(p_66, (p_65 < 0xA5L))) < 0UL) , p_65)) | l_467[1][0][4]) >= p_65)) , l_479[0])))), 9UL))) == g_183[9]) > p_65) != 0x58L), 2))))))) && g_27[2][0]))
                {
                    uint8_t l_561[10][2] = {{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL},{0xCFL,0x2CL}};
                    int32_t l_575 = 0x106A8AA5L;
                    int i, j;
                    l_480[6][0] = (g_566 = ((safe_lshift_func_int8_t_s_u((l_485[4] = ((0xCD43L >= (safe_rshift_func_int16_t_s_s((l_471 | ((0x7AL == (safe_lshift_func_uint8_t_u_s((((((p_65 || (safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((0xF5E7L <= g_400) , (((safe_sub_func_uint16_t_u_u(((l_561[1][0] <= ((safe_rshift_func_int8_t_s_u(((safe_sub_func_uint32_t_u_u(g_315, 1L)) ^ g_127), 0)) == p_66)) && p_65), 0xF57CL)) , l_480[3][4]) , (-1L))), 2)) , 0xDE674641L), (-4L)))) & g_247) , g_34[4]) & p_65) & l_480[1][5]), p_66))) < p_65)), 13))) && g_499)), 4)) & p_65));
                    p_65 = (1UL ^ (p_65 >= (l_480[6][0] = ((g_185[1][1][1] , (safe_mod_func_uint32_t_u_u(((g_566 = (((p_66 > g_126) > (p_65 && ((l_485[3] = ((l_494 = (1L != (safe_add_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s((l_547 , 0x2A29L), g_203)), 0xE4L)))) && l_561[1][0])) , g_127))) <= g_185[0][7][2])) , l_479[0]), p_65))) > p_66))));
                    l_521 = ((safe_sub_func_uint8_t_u_u(((l_575 = p_65) >= (safe_unary_minus_func_int32_t_s(g_27[0][0]))), (g_577 && ((g_419 = ((g_276 = l_578) , (~((((l_479[0] >= (safe_sub_func_int8_t_s_s((-6L), (((((g_317 <= (((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u((((safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((p_66 = (((((p_65 , (((l_590 | g_566) , p_65) >= g_391)) >= g_27[2][0]) , g_127) & g_27[2][0]) ^ g_400)) , g_250[0][1]), 7)), p_65)) > l_485[0]) | g_456), 0x1E71L)) , 0x59860439L), l_479[0])) && p_66) > 0x43A2DC47L)) & 1L) , 0xC822L) > l_521) >= l_561[6][1])))) , p_65) < g_27[2][0]) < g_5)))) | 0xC5L)))) & p_65);
                }
                else
                {
                    int8_t l_603 = (-6L);
                    uint8_t l_652 = 2UL;
                    int16_t l_681[3];
                    uint16_t l_722 = 65535UL;
                    int32_t l_737 = 2L;
                    int8_t l_738 = (-7L);
                    int i;
                    for (i = 0; i < 3; i++)
                        l_681[i] = 6L;
                    p_65 = (((safe_add_func_uint32_t_u_u(g_250[0][1], g_108)) , g_486) < 0x0B0EL);
                    for (g_86 = (-25); (g_86 != 17); g_86++)
                    {
                        int16_t l_602 = 0x5DE3L;
                        int32_t l_614 = (-2L);
                        l_603 = ((((safe_sub_func_uint32_t_u_u(1UL, (safe_unary_minus_func_int32_t_s(p_66)))) > ((p_66 <= (safe_lshift_func_int16_t_s_u(p_66, 0))) ^ (g_419 = (safe_lshift_func_int16_t_s_u(l_602, 14))))) || 0x6FL) <= 0x740B221DL);
                        l_494 = (!(safe_sub_func_int8_t_s_s(0x41L, l_603)));
                        p_65 = ((((safe_rshift_func_uint16_t_u_u(((l_603 & (-6L)) > 4294967295UL), (g_504[6][2][0] = 1UL))) , ((p_65 || ((((l_482 = p_65) != (((0L <= (safe_add_func_uint8_t_u_u((((safe_sub_func_int16_t_s_s((+(0x85DEL ^ (0x4EL > 0x06L))), 65530UL)) & g_566) <= l_494), l_603))) && g_108) < 4L)) == 1UL) && l_614)) == 0x1AL)) > g_127) , 0L);
                        g_639 = (g_318 <= ((+g_298) & (safe_rshift_func_int8_t_s_s((((((((g_427[1] > g_27[1][0]) | (safe_mod_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u(((((g_183[1] > (+0xB536L)) > (safe_mod_func_int32_t_s_s((safe_rshift_func_int16_t_s_s(((((((safe_sub_func_int16_t_s_s((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s(((l_638 = (!(p_66 = (safe_mod_func_uint32_t_u_u((safe_add_func_int32_t_s_s(((((l_485[3] = g_108) , (g_503 <= p_66)) == p_66) || 1L), 0xE9BEB38DL)), g_276))))) < p_65), p_65)), p_65)) ^ p_65) , l_614), 0x9183L)) > g_132) , 1L) & l_603) && g_449) ^ g_504[1][1][2]), 9)), g_34[5]))) != p_65) >= 2L), l_603)) || l_479[0]) , g_5), p_65))) >= p_65) || l_603) <= p_65) == p_65) , l_471), 2))));
                    }
                    if ((safe_lshift_func_int8_t_s_s((((((safe_rshift_func_int8_t_s_s(p_65, 7)) , (0x48L == (g_34[5] >= ((p_65 , (safe_rshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(4294967295UL, (((g_132 = ((((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_s(p_65, 6)), (((((0xDB54L >= g_504[1][1][2]) , ((l_652 >= p_65) | l_479[0])) > p_66) , 0UL) != p_66))) > g_203) & 0xC5057E2BL) <= 0x1AD2L)) < p_66) || p_66))), g_391))) > g_639)))) == 0x28L) <= 4294967290UL) ^ p_65), p_66)))
                    {
                        l_480[0][6] = (p_66 , g_317);
                    }
                    else
                    {
                        uint8_t l_691 = 0xD4L;
                        p_65 = (safe_mod_func_uint16_t_u_u((((safe_lshift_func_int16_t_s_u(0x0BECL, 4)) , 1UL) >= (((safe_sub_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(((safe_add_func_uint16_t_u_u(g_503, (safe_add_func_int16_t_s_s(l_638, ((((safe_sub_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_s((l_521 = ((g_503 , 0xBCL) < (safe_sub_func_uint32_t_u_u(l_521, ((safe_add_func_uint16_t_u_u(l_652, ((l_482 <= g_400) , p_65))) && g_185[0][6][1]))))), 6)) && p_66) != p_66), g_127)) && p_66) < (-1L)) <= p_66))))) , p_65), 12)), g_5)), 0x0CL)) == 1L) >= p_66)), p_66));
                        l_485[0] = (((((65526UL & ((g_693[1] = (((safe_lshift_func_int16_t_s_u((((g_503 >= ((((((((l_480[1][3] = ((safe_rshift_func_uint16_t_u_s(65535UL, 1)) ^ (l_691 = ((p_66 , ((l_681[2] || 1L) ^ ((safe_mod_func_uint8_t_u_u((((safe_sub_func_uint8_t_u_u(0x48L, (safe_lshift_func_uint16_t_u_s(((((safe_sub_func_uint8_t_u_u((l_482 = g_577), ((+g_132) == (-1L)))) & 1UL) || 0xD4L) > p_65), l_681[2])))) <= p_65) != g_53), g_27[2][0])) & (-6L)))) || 1UL)))) , 0UL) || l_681[2]) & g_692) == 9UL) , l_471) >= p_65) <= 4294967293UL)) & l_681[0]) >= (-1L)), 7)) , 0x2AL) == l_481)) && g_344)) | l_481) ^ g_419) != l_694) & l_695);
                        if (g_250[0][2])
                            break;
                    }
                    if (((((l_485[1] = (g_32[1][1] , (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((((safe_rshift_func_uint16_t_u_u((((-7L) > (safe_unary_minus_func_int8_t_s((safe_add_func_uint32_t_u_u((l_482 = (safe_sub_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((((l_482 , (safe_rshift_func_uint16_t_u_u(0x24E3L, 10))) > (safe_rshift_func_uint8_t_u_u(((g_108 = (safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((g_456 = p_66) < (safe_mod_func_uint16_t_u_u((g_504[1][1][2] = l_493), (((((((g_298 ^ g_566) > ((safe_lshift_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(g_503, g_185[1][1][1])) != p_66), p_66)) , p_66)) | p_66) == g_247) > g_32[1][0]) == l_482) | 0L)))), 2)), l_524))) <= p_66), p_65))) <= 65535UL))), g_185[1][5][1]))), g_427[1]))))) < p_66), 10)) , p_65) , l_483[1][0][0]) || l_722), 7)) ^ 0x6BA6L), g_185[0][6][1])))) , 0xAAA6L) & 0x812CL) && l_482))
                    {
                        uint8_t l_754 = 0x6AL;
                        uint8_t l_768 = 7UL;
                        g_739 = (safe_sub_func_uint16_t_u_u(((safe_sub_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_u(l_482, ((((((0L & ((((p_66 && (g_132 = 0x97L)) & ((safe_rshift_func_int8_t_s_u((((l_652 ^ (((((safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u(g_27[2][0], 4)), (safe_rshift_func_uint16_t_u_s(0UL, 6)))) >= ((((((g_185[0][6][1] = (l_737 = (p_65 != 0xADL))) && 0xB1L) > 0L) <= p_66) != g_32[1][0]) && g_298)) == p_65) && l_467[1][0][4]) > p_65)) < l_590) || 65535UL), 1)) ^ p_65)) < g_34[7]) != g_693[0])) , 0x20F1DFF9L) | l_652) < (-1L)) <= (-1L)) && l_738))) , p_66), g_5)) , 0xD70DL), 0xA1D7L));
                        l_768 = ((safe_sub_func_uint16_t_u_u(g_456, (safe_lshift_func_uint16_t_u_u(65534UL, 3)))) > ((~((safe_lshift_func_int8_t_s_s(g_250[0][4], 6)) < (((((safe_mod_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((~((safe_lshift_func_uint8_t_u_u(((l_754 && (((safe_mod_func_int8_t_s_s(((l_548 = l_479[0]) != ((g_456 < ((((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s(((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_uint8_t_u(((safe_lshift_func_uint8_t_u_s((safe_lshift_func_int8_t_s_u(g_32[1][1], 4)), 4)) ^ 252UL))), (0xC8C1L & g_27[2][0]))) == 4294967295UL) >= (-7L)) > g_44), g_344)), 4294967287UL)) == g_639) & g_419) | p_65)) , l_737)), g_247)) != p_65) & 0x3BL)) || g_86), 1)) && g_53)), 0x3B89L)) | 0x15L), g_298)) , p_66) ^ 0x57L) , l_722) || 0L))) && (-2L)));
                        p_65 = l_481;
                    }
                    else
                    {
                        g_769 = g_126;
                    }
                }
                return l_483[4][5][0];
            }
            else
            {
                uint32_t l_773 = 0x5A58B6C9L;
                int32_t l_780[6] = {(-4L),0xD0F3BAF9L,(-4L),(-4L),0xD0F3BAF9L,(-4L)};
                int32_t l_823 = 0x8C6B54D9L;
                int32_t l_824 = 0xE6A187CFL;
                int i;
                for (l_524 = 0; (l_524 <= 7); l_524 += 1)
                {
                    int8_t l_873 = 0x74L;
                    int i, j;
                    l_480[l_524][l_524] = l_480[l_524][l_524];
                    if (l_548)
                    {
                        uint32_t l_795 = 3UL;
                        if (g_86)
                            break;
                        l_797 = (((safe_unary_minus_func_int32_t_s((safe_add_func_int8_t_s_s((l_773 = 9L), (safe_sub_func_int32_t_s_s((safe_add_func_uint16_t_u_u(0x549AL, ((((g_317 > (safe_lshift_func_int16_t_s_s(l_780[1], g_247))) & (g_108 = ((l_480[l_524][l_524] = (safe_rshift_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_s((p_66 < ((safe_rshift_func_uint8_t_u_s((1UL ^ ((l_548 = (l_485[4] || (g_503 = (((safe_unary_minus_func_int8_t_s(((l_485[1] = (~(g_504[4][2][0] = ((safe_mod_func_uint32_t_u_u(l_795, 0xAD8177B1L)) > g_27[0][0])))) | l_695))) || 0x82L) != (-9L))))) > 247UL)), p_65)) , g_427[2])), p_66)) < 0x66L), 0x3B2E8B8FL)), p_66)) >= p_65), 15))) & l_795))) <= l_796) && l_480[l_524][l_524]))), 0xD11C5828L)))))) ^ l_795) | g_27[1][0]);
                        if (l_780[2])
                            continue;
                    }
                    else
                    {
                        uint16_t l_806 = 0x0BF4L;
                        if (g_32[1][0])
                            break;
                        p_65 = ((((l_780[4] , p_65) , (((((safe_rshift_func_uint16_t_u_s(((safe_add_func_uint8_t_u_u((~p_66), (g_183[6] < ((l_803 = 0x13L) != p_66)))) != ((-5L) >= ((0xA4L < ((0x31AF1C7AL < l_806) & l_694)) , 0UL))), p_65)) & 255UL) || g_34[5]) < 0x8F06A7A9L) && p_65)) == 0x2E6B6818L) | g_315);
                    }
                    p_65 = (((p_66 , ((((safe_mod_func_uint16_t_u_u(g_318, (((l_548 = 0x29L) ^ l_780[0]) ^ (safe_mod_func_int8_t_s_s((l_824 = ((l_823 = (((l_821 = (l_822 = ((((l_482 = (p_65 & (((((((((safe_lshift_func_int8_t_s_u(((l_485[1] = (((l_797 = ((0x680F592AL > (((safe_lshift_func_int16_t_s_s((((safe_mod_func_int8_t_s_s(((l_773 > (1UL || (((safe_mod_func_int8_t_s_s(p_66, l_483[0][3][0])) == l_480[l_524][l_524]) , 4294967295UL))) != 0xD0L), p_66)) , 0xE9CFL) , g_769), g_86)) || l_480[6][0]) , (-1L))) < g_693[1])) , g_250[0][1]) != g_27[0][0])) < p_66), l_819)) != (-1L)) == p_65) , 0x6FL) ^ l_780[4]) ^ p_66) && g_693[1]) ^ 0xFC2177D7L) >= 0L))) > g_820) || l_821) >= 0x70L))) ^ l_796) && p_65)) & 4294967286UL)), l_695))))) , p_65) == l_773) , l_825)) > l_480[6][0]) >= p_65);
                    for (l_796 = 1; (l_796 > 34); l_796 = safe_add_func_uint16_t_u_u(l_796, 8))
                    {
                        uint16_t l_832 = 0xF199L;
                        int32_t l_846 = 6L;
                        p_65 = (0x8839L | ((safe_add_func_int32_t_s_s((6L >= ((-1L) | g_44)), ((g_34[5] | ((((safe_lshift_func_uint8_t_u_s(l_832, 1)) && (l_832 >= (safe_add_func_int8_t_s_s(((l_846 = (safe_rshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_int16_t_s_u((safe_mod_func_int8_t_s_s(((((((l_780[0] = p_66) | (safe_sub_func_uint16_t_u_u((g_108 = ((((p_65 , l_773) , l_821) & l_483[1][0][0]) != p_66)), g_566))) || p_65) , l_482) || l_832) == l_471), p_65)), g_566)) != l_832), g_449)), l_845))) != p_65), p_65)))) <= g_317) & p_65)) ^ l_797))) , l_480[l_524][l_524]));
                        l_482 = (0xBDB0L || ((((safe_sub_func_uint32_t_u_u(((l_846 , ((l_832 >= ((0xE3BD165BL > (safe_unary_minus_func_uint32_t_u((safe_add_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((((l_822 = l_480[l_524][l_524]) != g_503) < ((1UL || (l_548 = p_65)) , ((g_183[9] = (((((0x3CL ^ l_482) > 0xDBCEA74AL) != 1L) && l_803) , g_35)) >= l_846))) | l_480[l_524][l_524]), l_823)), 0UL))))) , 6UL)) <= l_832)) | p_66), g_504[9][1][2])) > p_65) == 1L) <= 0UL));
                        p_65 = (((((safe_sub_func_int8_t_s_s((((1L || (safe_add_func_uint16_t_u_u((+(safe_mod_func_int32_t_s_s(((((safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u((l_480[l_524][l_524] > p_66), ((!l_832) & (((l_797 = (safe_lshift_func_int16_t_s_s(((g_5 == l_483[0][7][0]) > g_820), (safe_rshift_func_uint8_t_u_s((p_66 >= (g_391 = (((!0UL) | g_247) >= 0x19L))), l_873))))) == 0xCE8210CBL) ^ g_419)))), p_66)), p_65)) != g_183[2]) < 0xFB0CL) ^ l_480[l_524][l_524]), l_485[2]))), g_35))) < 4294967295UL) < 0x40L), 247UL)) < l_480[l_524][l_524]) <= g_203) && 0UL) <= p_66);
                    }
                }
                p_65 = (((l_695 , (((((0x593A734AL != ((safe_add_func_uint8_t_u_u(((0xEF2C38BFL | ((safe_sub_func_uint32_t_u_u(((l_821 = ((((l_480[6][0] = ((0x0AL <= (safe_add_func_uint8_t_u_u((((g_185[0][6][1] , g_400) == 0x4472L) != 0xE4873130L), ((l_485[4] = (((safe_sub_func_int16_t_s_s(l_482, 0UL)) > l_547) > g_276)) == p_66)))) && g_185[1][5][0])) && 4294967288UL) || g_577) & 0xE7BBECF8L)) || p_66), 7L)) , l_797)) != l_483[1][4][0]), l_797)) || 0L)) || g_639) | l_825) || 0x7AL) , g_739)) <= 0x3818E1B6L) , 0x4D5D8457L);
                p_65 = p_66;
                for (g_247 = (-13); (g_247 <= 57); g_247++)
                {
                    l_822 = (safe_lshift_func_uint16_t_u_s((g_639 ^ (((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s((p_65 < ((g_897[0][2] = (0xB1CBL & ((l_824 = (p_65 & (((safe_sub_func_uint8_t_u_u(((l_823 = (g_315 ^ ((safe_sub_func_int8_t_s_s((g_486 <= (safe_sub_func_int32_t_s_s(((0x3FL & (p_65 || (p_65 & g_456))) | l_694), p_66))), g_739)) <= g_504[0][3][2]))) , l_896), p_66)) & l_485[2]) & (-1L)))) == g_35))) ^ 0x11EE221BL)), 13)) < p_65), g_427[1])) ^ p_66) ^ g_32[1][1])), 8));
                    for (g_86 = 0; (g_86 >= 54); g_86++)
                    {
                        g_897[0][2] = (l_482 = g_504[9][1][0]);
                        l_480[6][0] = p_66;
                    }
                }
            }
            for (l_845 = 0; (l_845 <= 9); l_845 += 1)
            {
                int16_t l_923[1];
                uint16_t l_924 = 0xC5B5L;
                int i;
                for (i = 0; i < 1; i++)
                    l_923[i] = 0x6F58L;
                p_65 = (safe_rshift_func_uint8_t_u_s((l_485[4] = (((((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((g_86 = (g_32[1][0] > (g_183[l_845] = (safe_add_func_uint8_t_u_u(l_482, g_504[9][7][1]))))) || ((((!(safe_unary_minus_func_uint32_t_u(((l_821 = ((l_483[1][0][0] || (1UL & ((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s(((((((safe_add_func_uint8_t_u_u(0x74L, (safe_lshift_func_uint8_t_u_u((g_918[4][0][2] , (safe_lshift_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s(((l_923[0] = l_548) , (((((65528UL ^ p_65) < g_391) <= l_483[1][0][0]) < p_65) ^ l_822)), p_66)) , p_66), 13))), p_65)))) != l_638) != g_32[6][1]) , l_796) > g_183[l_845]) && p_66), 1)) || p_66), g_183[l_845])) || 0L))) < g_185[0][4][1])) , 4294967288UL)))) ^ 0x06L) <= 0UL) , g_32[1][0])), p_66)), g_566)) <= 9L) >= g_456) ^ g_820) && g_35)), l_924));
                g_897[1][1] = (-1L);
                return g_108;
            }
            if (((l_482 = (p_65 || (l_825 | (l_821 = ((safe_rshift_func_uint8_t_u_s(0x70L, (safe_mod_func_uint32_t_u_u((safe_sub_func_int8_t_s_s((g_34[2] = (l_480[6][0] = ((p_65 <= p_66) , (l_822 = g_27[2][0])))), ((0x0D59L && ((~p_66) != 0L)) & l_825))), g_183[9])))) > 0xFCE3B056L))))) | g_247))
            {
                int16_t l_940 = 0x25EDL;
                int32_t l_1060 = 7L;
                if ((((safe_rshift_func_uint8_t_u_s(((((p_66 && (safe_unary_minus_func_int32_t_s(((((0xFE135366L | ((0xC0B2F128L >= p_65) < ((p_66 != (((safe_rshift_func_int8_t_s_u(l_822, 1)) , 0x7E6F91A7L) , ((l_821 = ((((((l_797 = (l_822 = (((((((l_940 = (safe_unary_minus_func_int16_t_s(g_33))) <= (0x7E3FDE6DL > l_485[4])) != l_524) > 0xDE98L) | p_66) , p_65) , g_739))) != g_132) , g_918[4][1][2]) < 0UL) <= g_108) && 0x2EL)) != 0x0DL))) == p_65))) , g_34[8]) && 9L) < 1UL)))) | 9L) && 0x3DFAL) , l_481), p_65)) < l_481) ^ g_35))
                {
                    int32_t l_953 = 0L;
                    for (g_108 = (-12); (g_108 != 45); g_108++)
                    {
                        int32_t l_954 = 0x031C7BE6L;
                        p_65 = ((safe_mod_func_int8_t_s_s((-8L), g_44)) == (g_449 != ((safe_sub_func_int16_t_s_s((~(p_65 ^ (-1L))), (g_504[1][1][2] = ((+(l_482 <= (safe_lshift_func_int16_t_s_u(((safe_sub_func_int16_t_s_s(g_344, (l_953 = 5UL))) != (p_66 < l_485[4])), g_693[1])))) > l_954)))) , 1L)));
                    }
                }
                else
                {
                    uint16_t l_970 = 0x1AC3L;
                    int32_t l_1002[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_1002[i] = (-9L);
                    g_972 = ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u(((((((1L == (g_203 = (0x43F0A250L & 0x4662AD77L))) && l_940) , p_66) & ((((p_66 <= (g_127 = (safe_mod_func_uint16_t_u_u(l_963, (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(g_298, (safe_unary_minus_func_int16_t_s(((safe_unary_minus_func_uint8_t_u(l_638)) , g_769))))) , l_819), g_456)))))) ^ l_481) > l_484) , l_970)) != g_820) , 0xA7L), l_524)) || l_971) < 1UL), 10)), g_692)) < 1L);
                    for (l_547 = 0; (l_547 != (-27)); l_547--)
                    {
                        int16_t l_975 = (-5L);
                        l_975 = 0x8A8F6C36L;
                        return l_481;
                    }
                    l_1005 = (safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s(l_825, g_897[0][2])), (l_1004[4] = (safe_rshift_func_int16_t_s_u((l_1003[5] = (((g_456 && ((((safe_mod_func_int8_t_s_s(1L, (((((((safe_add_func_uint32_t_u_u((((safe_sub_func_int8_t_s_s(((l_1002[0] = (((l_821 = ((((l_485[4] < ((g_344 = (+(safe_lshift_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_s((1UL | 65528UL), ((g_183[1] == (((l_480[1][6] = (safe_mod_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s((-6L), l_471)) | 0x72L) >= 0xBAL), 10)) & g_344), p_66)), p_66))) && 65535UL) != 0x6BL)) , 2L))) ^ g_250[0][1]), g_1001)))) , 0x0AL)) >= p_65) & g_427[1]) < g_318)) | 0UL) > l_963)) , p_65), 0xD7L)) && p_65) , 0x8CE10570L), 0xA7E0ABDFL)) & l_970) != l_485[4]) != 8L) > g_486) == g_419) & (-1L)))) <= 0x15DDL) & (-1L)) < g_504[1][1][2])) , g_456) != g_86)), l_896)))));
                    l_1002[0] = (l_940 != l_464);
                }
                if ((((l_797 = g_739) >= g_315) , p_65))
                {
                    g_897[0][1] = (safe_add_func_uint32_t_u_u(g_44, 8L));
                }
                else
                {
                    int32_t l_1023[9][8];
                    uint32_t l_1024[6][3][9] = {{{2UL,4294967295UL,2UL,4294967286UL,3UL,3UL,4294967295UL,4294967295UL,0x7742791CL},{0x77CCB0CAL,0UL,0x77CCB0CAL,0UL,0UL,2UL,2UL,0UL,0UL},{2UL,4294967295UL,2UL,4294967286UL,3UL,3UL,4294967295UL,4294967295UL,0x7742791CL}},{{0x77CCB0CAL,0UL,0x77CCB0CAL,0UL,0UL,2UL,2UL,0UL,0UL},{2UL,4294967295UL,2UL,4294967286UL,3UL,3UL,4294967295UL,4294967295UL,0x7742791CL},{0x77CCB0CAL,0UL,0x77CCB0CAL,0UL,0UL,2UL,2UL,0UL,0UL}},{{2UL,4294967295UL,2UL,4294967286UL,3UL,3UL,4294967295UL,4294967295UL,0x7742791CL},{0x77CCB0CAL,0UL,0x77CCB0CAL,0UL,0UL,2UL,2UL,0UL,0UL},{1UL,3UL,1UL,4294967290UL,4294967295UL,0x3B6D839DL,0x1C09CA2AL,3UL,0xA41392A3L}},{{0x1DAA8A56L,2UL,0x1DAA8A56L,4294967295UL,2UL,0xED9AD4CCL,0xED9AD4CCL,2UL,4294967295UL},{1UL,3UL,1UL,4294967290UL,4294967295UL,0x3B6D839DL,0x1C09CA2AL,3UL,0xA41392A3L},{0x1DAA8A56L,2UL,0x1DAA8A56L,4294967295UL,2UL,0xED9AD4CCL,0xED9AD4CCL,2UL,4294967295UL}},{{1UL,3UL,1UL,4294967290UL,4294967295UL,0x3B6D839DL,0x1C09CA2AL,3UL,0xA41392A3L},{0x1DAA8A56L,2UL,0x1DAA8A56L,4294967295UL,2UL,0xED9AD4CCL,0xED9AD4CCL,2UL,4294967295UL},{1UL,3UL,1UL,4294967290UL,4294967295UL,0x3B6D839DL,0x1C09CA2AL,3UL,0xA41392A3L}},{{0x1DAA8A56L,2UL,0x1DAA8A56L,4294967295UL,2UL,0xED9AD4CCL,0xED9AD4CCL,2UL,4294967295UL},{1UL,3UL,1UL,4294967290UL,4294967295UL,0x3B6D839DL,0x1C09CA2AL,3UL,0xA41392A3L},{0x1DAA8A56L,2UL,0x1DAA8A56L,4294967295UL,2UL,0xED9AD4CCL,0xED9AD4CCL,2UL,4294967295UL}}};
                    int i, j, k;
                    for (i = 0; i < 9; i++)
                    {
                        for (j = 0; j < 8; j++)
                            l_1023[i][j] = (-1L);
                    }
                    for (g_132 = 2; (g_132 <= 9); g_132 += 1)
                    {
                        int32_t l_1046 = 0xDC6691FBL;
                        int i;
                        l_548 = (safe_lshift_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int16_t_s_s((g_34[g_132] >= (g_972 = (((0UL && p_65) & (g_897[0][2] = (safe_sub_func_uint16_t_u_u(((((safe_sub_func_uint16_t_u_u(0UL, ((g_449 > (2L || ((((safe_lshift_func_int16_t_s_s(((p_66 , 9UL) , l_1022[0]), p_65)) || 1UL) , g_185[0][6][1]) <= l_1023[3][0]))) != g_769))) == g_27[1][0]) <= p_65) && l_1023[3][0]), l_481)))) & (-1L)))), 11)) & (-5L)), 10)) >= 1L) ^ g_693[1]), p_66)) > 1UL) || g_897[0][2]) | g_86), l_1024[2][1][8]));
                        l_1046 = ((safe_add_func_uint32_t_u_u(g_503, ((((g_53 = ((((((((l_480[6][0] = 250UL) < (((safe_add_func_int32_t_s_s((p_65 < (safe_mod_func_uint32_t_u_u(((g_108 = ((g_34[g_132] != ((((((safe_rshift_func_int16_t_s_u((g_820 = (-7L)), (safe_add_func_int8_t_s_s(((g_504[1][1][2] = p_66) & (((safe_add_func_int32_t_s_s(((l_797 = (safe_rshift_func_uint8_t_u_s((~(((((safe_lshift_func_uint8_t_u_u(255UL, 6)) | (g_1044 > g_33)) , l_482) <= 4294967295UL) ^ l_1023[3][0])), 4))) || 9UL), 0x93298D86L)) != g_34[g_132]) <= p_66)), g_53)))) | g_692) != g_183[9]) <= 0x0BD5AA0FL) && g_566) <= g_250[0][2])) , l_940)) || 0x97A8L), 0x9537D7CDL))), g_34[g_132])) | p_65) && l_825)) , p_66) < g_27[2][0]) || 7L) >= g_127) & 0x0426004BL) != l_940)) ^ 0x2E9FL) , g_34[g_132]) > 0x71E8L))) >= g_1045);
                        p_65 = (safe_rshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((l_1024[5][2][5] > ((safe_rshift_func_int8_t_s_u((+(safe_sub_func_int32_t_s_s(0L, 0UL))), 3)) || ((((((p_66 = (safe_add_func_uint32_t_u_u((((p_66 ^ p_66) & (l_1023[7][1] = (safe_add_func_int8_t_s_s(((l_1046 = 0UL) , 0x32L), p_65)))) & g_391), 0x4CB54D56L))) > p_65) <= 0x15BDL) , 1L) > l_822) ^ l_822))), p_65)), l_803));
                        g_897[0][2] = l_485[4];
                    }
                    if ((g_897[1][2] = 0x33BC2DCCL))
                    {
                        if (g_247)
                            break;
                    }
                    else
                    {
                        uint32_t l_1081 = 0x3BD502FBL;
                        g_897[1][2] = 1L;
                        l_1060 = p_66;
                        if (p_66)
                            break;
                        p_65 = (g_897[0][2] = ((safe_rshift_func_int8_t_s_s((((l_1004[4] = (((((safe_lshift_func_uint16_t_u_s((((p_65 ^ (l_822 != ((g_344 = (((safe_add_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((((g_897[0][2] > 0xC5L) != (((((safe_mod_func_uint8_t_u_u((((((0xEA77BCE3L == (+((p_65 , (g_400 , (g_35 = (0x7E4FL && (safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((l_485[3] = ((l_1080 == g_183[2]) == l_548)), 5)) > l_822), g_185[0][6][1])), g_203)))))) , p_65))) && (-2L)) , g_504[9][0][2]) , (-5L)) ^ 0x7EC4L), 1L)) >= p_66) , g_499) || l_796) > l_822)) > 0x8ED35A66L) && 0UL), 7L)), 3)), g_276)) <= l_1003[5]) < l_483[1][0][0])) != l_1081))) >= 0xC60130D9L) | p_65), 4)) & 0xEC7E6477L) <= g_503) , g_86) <= 4L)) >= g_692) >= (-2L)), 7)) > g_298));
                    }
                    l_485[4] = p_65;
                }
                for (l_1080 = 0; (l_1080 > (-25)); --l_1080)
                {
                    if (l_483[1][0][0])
                        break;
                }
            }
            else
            {
                l_482 = 0x8AEDE75CL;
                return l_548;
            }
        }
        if (g_315)
            goto lbl_1084;
    }
lbl_1866:
    for (g_400 = 0; (g_400 <= 8); g_400 += 1)
    {
        int8_t l_1106 = 1L;
        int32_t l_1113[8] = {0x2EDFA925L,0x2EDFA925L,0x2EDFA925L,0x2EDFA925L,0x2EDFA925L,0x2EDFA925L,0x2EDFA925L,0x2EDFA925L};
        uint8_t l_1237 = 0UL;
        int32_t l_1241 = (-10L);
        int32_t l_1393 = 0xBD99AE45L;
        uint32_t l_1403[7][4][8] = {{{0x8B61BB37L,2UL,0UL,4294967295UL,0UL,4294967295UL,0xA5BE8696L,0x1E1D2FBDL},{1UL,0x7B406133L,7UL,0x1C558DDBL,1UL,4294967295UL,0xCDA4A9ACL,4294967295UL},{9UL,4294967288UL,0xFAC9E065L,0x7E586824L,0UL,1UL,0x8B61BB37L,4294967291UL},{1UL,2UL,0x1C558DDBL,0xDAE19DB9L,4294967295UL,0xD8E88DF4L,0x0AB5C1BBL,1UL}},{{0x9B1C11D9L,0xAEC40203L,0UL,0xB76471C7L,0xF2739003L,0x7498CE71L,0xF2739003L,0xB76471C7L},{0x7498CE71L,0x79F6060FL,0x7498CE71L,2UL,7UL,0UL,0xE06FC4AFL,4294967287UL},{0x7B406133L,0x436AF4D8L,1UL,5UL,0xFA0B717FL,9UL,7UL,0xDD9B9122L},{0x7B406133L,4294967295UL,0xFDEC5287L,4294967288UL,7UL,4294967291UL,0x78296069L,0UL}},{{0x7498CE71L,0x6E9D12DDL,7UL,0UL,0xF2739003L,0UL,4294967295UL,6UL},{0x9B1C11D9L,0x78296069L,4294967295UL,0x992335F2L,4294967295UL,2UL,4294967287UL,4294967291UL},{1UL,4294967295UL,0x7B2DDA65L,4294967291UL,0UL,4294967290UL,0xDAE19DB9L,0x7DCFB303L},{9UL,0x1E1D2FBDL,4294967295UL,0x223C17A3L,0UL,0xDD9B9122L,1UL,4294967295UL}},{{0x4DB4C402L,0x8B61BB37L,6UL,5UL,0UL,4294967291UL,4294967295UL,0xB76471C7L},{0UL,0xE06FC4AFL,4294967295UL,0x83B65FA3L,0UL,4294967288UL,0x2FB3D88CL,0UL},{6UL,4294967295UL,0UL,4294967295UL,4294967295UL,4294967295UL,0UL,0x992335F2L},{2UL,0x48819342L,0x4B97AA8EL,4294967291UL,0xFAC9E065L,6UL,0x7242413AL,0x8DDF11FDL}},{{1UL,0x7B406133L,0x9B1C11D9L,0xFAC9E065L,2UL,0UL,0x4DB4C402L,0x4F029831L},{0x37BF9B27L,0xDAE19DB9L,4294967295UL,1UL,5UL,5UL,1UL,4294967295UL},{0x2FB3D88CL,0x2FB3D88CL,0xA18EBFA4L,5UL,1UL,4294967295UL,4294967288UL,0x79F6060FL},{0xB76471C7L,0x3ECB2F48L,0UL,0xA5BE8696L,7UL,0UL,0x1C558DDBL,0x79F6060FL}},{{0x3ECB2F48L,0xB527B950L,0x436AF4D8L,5UL,0x4F029831L,0UL,4294967287UL,4294967295UL},{1UL,0x1E1D2FBDL,4294967291UL,1UL,4294967295UL,1UL,0xF77A926EL,0x4F029831L},{4294967289UL,0x436AF4D8L,4294967295UL,0xFAC9E065L,0x4B97AA8EL,0x7B2DDA65L,4294967295UL,0x8DDF11FDL},{7UL,7UL,4294967288UL,4294967291UL,0x37BF9B27L,0UL,1UL,0x992335F2L}},{{5UL,1UL,9UL,4294967295UL,0UL,0x7DCFB303L,0UL,0UL},{1UL,0UL,0UL,0x83B65FA3L,0x3ECB2F48L,0UL,0x7B406133L,0xB76471C7L},{4294967295UL,0UL,0x4DB4C402L,5UL,0xE06FC4AFL,0UL,0UL,4294967295UL},{0x103544D8L,4294967291UL,0xD8E88DF4L,0UL,6UL,0x37BF9B27L,0x78296069L,1UL}}};
        uint32_t l_1542 = 0x6F00904EL;
        int32_t l_1670 = 0xEA308454L;
        int i, j, k;
        for (g_35 = 3; (g_35 <= 8); g_35 += 1)
        {
            int32_t l_1089 = 0x706EF359L;
            int i;
            if (l_896)
                goto lbl_1084;
            l_1003[g_400] = (-5L);
            p_65 = (l_1004[g_35] | ((safe_rshift_func_uint16_t_u_u(((p_66 >= (l_963 < (safe_add_func_int8_t_s_s(((((((l_1089 = (((g_918[4][0][2] > (l_821 = (l_1003[g_400] = g_419))) == g_504[1][1][2]) == 0L)) <= 1UL) >= 65535UL) == l_1004[g_35]) != g_185[0][7][0]) | g_35), p_65)))) | p_65), 9)) > g_693[1]));
            for (g_391 = (-7); (g_391 != 14); ++g_391)
            {
                if (l_1089)
                    break;
                return g_504[1][1][2];
            }
        }
        for (g_449 = 0; (g_449 >= 15); g_449++)
        {
            uint32_t l_1105 = 0x88CCDD4FL;
            p_65 = (((~(safe_rshift_func_int8_t_s_u((l_1106 = ((((safe_unary_minus_func_int16_t_s((-1L))) || ((((safe_sub_func_uint8_t_u_u((~((0x85D0L < (((safe_mod_func_int32_t_s_s(g_739, 0x88300C94L)) >= (g_298 = g_318)) != (safe_sub_func_int8_t_s_s((g_34[5] = (((((l_1003[1] = (1UL > g_918[4][0][2])) & (g_35 = 0x66L)) < ((g_897[0][2] = (g_185[0][6][1] ^ l_1105)) == l_578)) >= (-3L)) > p_66)), g_250[0][1])))) || 0xD7L)), 1L)) && 1L) || l_1105) > 0xDD0C0A44L)) , p_65) || l_467[3][2][0])), g_5))) && g_486) | p_65);
            g_897[1][2] = 0xDD82B2FFL;
        }
        if (((g_1045 ^ (g_897[0][2] = g_503)) <= (safe_lshift_func_int8_t_s_u((((((+255UL) >= (g_400 < (-1L))) , ((g_504[1][1][2] ^ (!((((0xD4L || (l_1003[7] = ((p_66 = ((safe_rshift_func_uint16_t_u_u(((p_65 , (0x3158D8B2L > l_467[1][0][4])) , p_66), 4)) ^ g_566)) != 0xE20CL))) >= l_1106) , g_427[1]) && l_1113[3]))) & 0UL)) | l_1113[3]) & g_504[3][3][2]), 2))))
        {
            int32_t l_1140 = 0x8B9EA698L;
            uint8_t l_1145 = 246UL;
            int8_t l_1240 = 0x61L;
            for (g_972 = 0; (g_972 <= 8); g_972 += 1)
            {
                int16_t l_1191[7][7] = {{0L,0L,0L,1L,0L,0L,0L},{0x650CL,3L,(-7L),3L,0x650CL,0x650CL,3L},{(-3L),0x0ACDL,(-3L),0L,0L,(-3L),0x0ACDL},{3L,(-10L),(-7L),(-7L),(-10L),3L,(-10L)},{(-3L),0L,0L,(-3L),0x0ACDL,(-3L),0L},{0x650CL,0x650CL,3L,(-7L),3L,0x650CL,0x650CL},{0L,0L,1L,0L,0L,0L,0L}};
                uint16_t l_1198 = 0xFA89L;
                uint8_t l_1202 = 1UL;
                uint8_t l_1230[9] = {0x29L,0x17L,0x17L,0x29L,0x17L,0x17L,0x29L,0x17L,0x17L};
                int i, j;
                l_1004[g_972] = 0xC7D2D3EBL;
                for (l_524 = 0; (l_524 <= 8); l_524 += 1)
                {
                    uint32_t l_1139 = 0xB41943E5L;
                    int32_t l_1169 = 0x7291C365L;
                    int32_t l_1170 = 0x7144A9A7L;
                    int8_t l_1199 = 0x45L;
                    int32_t l_1212 = (-4L);
                    for (g_35 = 0; (g_35 <= 1); g_35 += 1)
                    {
                        int32_t l_1137 = 1L;
                        int i, j, k;
                        if (g_918[(g_35 + 2)][g_35][g_400])
                            break;
                        l_1004[g_400] = (((g_315 , g_918[(g_35 + 2)][g_35][g_400]) != (p_66 = (safe_sub_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u(((g_693[1] >= ((((safe_add_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s(l_1113[3], 2)), (+((safe_lshift_func_uint8_t_u_u((g_185[0][6][1] = (g_132 = (((safe_mod_func_int8_t_s_s(((((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((g_108 = (((safe_rshift_func_int16_t_s_u(((0x94725652L <= l_1004[g_972]) , p_65), 11)) <= (((safe_sub_func_uint8_t_u_u(l_1004[g_972], ((safe_add_func_uint8_t_u_u(253UL, 0x3BL)) , l_1137))) > g_108) == g_1138)) && g_419)), g_427[1])), 0xD151L)) , (-1L)) != p_66) != l_896), l_1139)) > g_419) != g_53))), 0)) , l_1140)))) & l_1137) & g_972) , g_504[1][1][2])) && p_66), 14)) ^ 0x768EL), g_897[1][1])))) != g_1044);
                        g_897[0][2] = (safe_add_func_int32_t_s_s(((p_65 <= ((((0x5C97L != 0UL) , ((l_1004[g_972] = (((l_1004[g_972] >= (((safe_sub_func_uint16_t_u_u(l_1145, (safe_rshift_func_int16_t_s_u(((((safe_sub_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((((((safe_add_func_uint32_t_u_u(((safe_add_func_int32_t_s_s(((((+(safe_mod_func_uint16_t_u_u(g_693[1], 2L))) | ((safe_mod_func_uint8_t_u_u((((((((((safe_rshift_func_uint8_t_u_s(((l_1169 = (safe_sub_func_int8_t_s_s((safe_mul_func_int8_t_s_s(l_1140, (((g_86 = l_1137) < 1L) != g_693[1]))), 1UL))) <= l_1004[g_400]), 4)) , p_66) <= p_65) | 2L) == g_456) && p_66) != p_65) < p_66) == g_918[3][1][6]), 0x68L)) != 0x7550D359L)) || g_427[2]) , g_820), 0L)) , l_1170), 7UL)) && g_769) | l_1106) < l_1139) < 0UL), p_65)), l_1106)), g_427[1])) & g_972) <= l_1113[3]) >= p_66), l_1004[g_400])))) && p_65) < g_692)) , p_66) && l_1140)) < g_486)) , 0x8FL) || 0x56L)) , g_897[0][1]), 0L));
                    }
                    for (l_1139 = 0; (l_1139 == 28); l_1139 = safe_add_func_int32_t_s_s(l_1139, 1))
                    {
                        uint32_t l_1186 = 0xC9EFE32DL;
                        int32_t l_1203 = (-5L);
                        int8_t l_1239[10][1] = {{0x89L},{0L},{0x89L},{0L},{0x89L},{0L},{0x89L},{0L},{0x89L},{0L}};
                        uint16_t l_1242 = 0x3883L;
                        int i, j;
                        p_65 = (+(l_1199 = (safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s(p_66, 1UL)), ((safe_lshift_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(l_1186, ((safe_mod_func_int8_t_s_s(((p_65 == (((safe_lshift_func_int16_t_s_u(p_66, 5)) != l_1191[6][0]) , p_65)) && (safe_mod_func_uint32_t_u_u((((safe_add_func_int8_t_s_s(((((g_820 = ((((0L > (safe_sub_func_int16_t_s_s(l_1113[4], g_250[0][0]))) , 0x0EA5L) , 4L) >= g_183[0])) & (-1L)) >= p_66) & p_66), 0x9BL)) < g_897[0][2]) ^ l_1198), l_1186))), g_692)) , g_53))) , g_203), p_66)), l_1004[g_972])) ^ 0xC438L))) , 0x7A0BL), 4))));
                        g_897[1][0] = (safe_add_func_uint32_t_u_u(((l_1202 == (65535UL || (((l_1003[5] = (l_1203 , (((3UL & ((p_65 || ((g_486 = 0x5AF079EFL) > (safe_sub_func_int32_t_s_s((safe_sub_func_uint16_t_u_u((((((g_419 = l_1198) != ((((safe_rshift_func_int16_t_s_s(g_34[4], (safe_sub_func_int16_t_s_s(((l_1106 == 0UL) || g_34[5]), g_126)))) != l_1022[0]) <= 0x9837L) & l_480[6][0])) && p_66) || 4294967295UL) < p_65), p_66)), 0x7A89F6FDL)))) , 0L)) , l_1140) & l_1145))) , l_819) ^ g_127))) , p_66), 0x4B9FC687L));
                        l_1212 = g_250[0][2];
                        l_1242 = (g_897[1][2] = (safe_rshift_func_uint8_t_u_u((l_1140 = ((l_1241 = ((+(safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((l_1113[3] ^ (safe_lshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((0UL & (l_1212 = l_1145)), (g_427[2] | ((((safe_mod_func_int32_t_s_s(((((l_1004[g_972] = ((safe_mod_func_int8_t_s_s((~(-1L)), ((((!((l_1230[8] , (g_185[0][2][2] && ((safe_add_func_int32_t_s_s((safe_rshift_func_int16_t_s_u((g_27[0][0] = (safe_add_func_uint8_t_u_u((((((g_298 != (l_1237 , g_503)) ^ 1UL) == g_897[0][2]) , l_1238) > l_1169), g_400))), 4)), (-1L))) <= p_66))) && g_972)) || l_1237) || l_1239[1][0]) , g_693[0]))) , g_108)) >= g_639) || p_65) || p_66), g_1001)) >= p_65) & l_1240) > l_1239[1][0])))), p_65))) != g_504[0][4][1]) > 0xAD11L), g_318)), 0xC1L))) > l_1230[8])) & g_897[0][1])), p_66)));
                    }
                    p_65 = ((safe_sub_func_int16_t_s_s(0xDF77L, (((l_1139 > (0x39L >= (safe_rshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s(((((safe_mod_func_uint32_t_u_u(p_65, (safe_lshift_func_uint8_t_u_u(((0x21ECCBBCL & (((l_1003[6] = (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((g_35 = (p_65 != (safe_mod_func_int32_t_s_s((((g_739 >= (g_897[1][0] = (((((safe_rshift_func_uint16_t_u_s((((((((safe_rshift_func_uint16_t_u_s((l_1113[2] > (l_1241 = (g_44 > 0x5BL))), 5)) | 0x3DB5L) != g_693[0]) , g_577) & p_65) | 0xB7220D20L) >= g_27[1][0]), 3)) <= 0x7211L) & g_897[0][0]) || p_65) | p_66))) && l_1139) >= l_1237), 0x3B5EA028L)))) >= l_1113[3]), 3)), 2))) && 0x00L) != p_66)) != l_471), p_65)))) , p_65) < 0x7C27L) <= 0L), p_66)), g_127)))) >= g_250[0][1]) , p_65))) ^ p_66);
                    p_65 = (-8L);
                }
            }
            g_897[0][0] = 0xF6CBF628L;
            if (l_1140)
                continue;
            if (p_66)
                break;
        }
        else
        {
            uint8_t l_1272 = 1UL;
            int32_t l_1296 = 1L;
            int16_t l_1345[10][5] = {{0xEF94L,0L,0xEF94L,0xC61CL,0xEF94L},{0x7D0AL,0x7D0AL,(-4L),1L,0L},{0xA7EFL,0xC61CL,0xD7E3L,0xC61CL,0xA7EFL},{0L,1L,(-4L),0x7D0AL,0x7D0AL},{0xEF94L,0xC61CL,0xEF94L,0L,0xEF94L},{0L,0x7D0AL,1L,1L,0x7D0AL},{0xA7EFL,0L,0xD7E3L,0L,0xA7EFL},{0x7D0AL,1L,1L,0x7D0AL,0L},{0xEF94L,0L,0xEF94L,0xC61CL,0xEF94L},{0x7D0AL,0x7D0AL,(-4L),1L,0L}};
            uint32_t l_1346 = 4UL;
            int i, j;
            g_897[0][2] = (((0x6AL != 253UL) | (g_639 & (((((((safe_lshift_func_uint16_t_u_u(g_86, 12)) , (+((safe_add_func_int32_t_s_s(((p_66 = p_65) , (((p_66 = ((g_203 <= l_1113[3]) != (safe_lshift_func_uint16_t_u_u((0UL > (((l_1272 = (g_639 ^ l_1003[3])) >= (-1L)) ^ p_65)), 1)))) > p_65) < 1L)), 0x88EC8059L)) && l_1272))) || p_66) , g_499) , 0xC3L) , 0x1548L) && (-1L)))) | p_65);
            g_897[0][2] = (-4L);
            l_1284 = (safe_mod_func_int16_t_s_s(1L, ((((safe_rshift_func_uint16_t_u_u((p_66 || (p_65 , g_820)), 3)) >= (p_65 & g_203)) | ((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(((l_821 = (((safe_add_func_int32_t_s_s((l_1283 && g_427[0]), l_1238)) ^ l_1003[5]) >= 0xA4C9A2EFL)) | p_66), g_33)), l_963)) <= l_1106)) || p_65)));
            for (g_33 = 0; (g_33 <= 0); g_33 += 1)
            {
                uint16_t l_1293 = 0x27B8L;
                int32_t l_1297 = 1L;
                for (g_449 = 0; (g_449 <= 0); g_449 += 1)
                {
                    int32_t l_1294 = 0x21D49D28L;
                    int32_t l_1295[10];
                    int16_t l_1378 = 9L;
                    uint16_t l_1391 = 0UL;
                    int i, j;
                    for (i = 0; i < 10; i++)
                        l_1295[i] = (-9L);
                    if (((g_86 = (safe_sub_func_uint32_t_u_u((safe_mod_func_int8_t_s_s((((g_247 = ((l_1297 = ((safe_mod_func_uint8_t_u_u(((((((g_897[0][2] = g_27[g_33][g_33]) | (g_250[0][2] == (safe_lshift_func_uint8_t_u_s((l_1296 = (0x60L > ((l_1294 = l_1293) >= ((l_1295[1] = 0UL) == p_65)))), 1)))) , p_66) < g_250[0][1]) >= (l_1113[3] < g_1138)) | 0xE7L), l_1106)) > g_185[0][0][2])) | g_456)) > 0x29FBFB7CL) | 0UL), 0x73L)), l_1298))) , p_65))
                    {
                        int32_t l_1302 = 0xAA0D94B7L;
                        g_1328 = (g_639 <= (0xFEL == (safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_uint16_t_u((l_1302 > (((g_566 , (+(safe_sub_func_int16_t_s_s((((safe_sub_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_s((((safe_mod_func_int16_t_s_s((g_820 = 0xCE0CL), ((g_247 = (l_1296 = ((((((l_1004[8] = ((safe_sub_func_int16_t_s_s(l_1302, (safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((((g_897[0][1] = ((p_66 <= (((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint16_t_u_u(((!((l_1325 || (safe_rshift_func_int8_t_s_u(l_1241, p_65))) < l_1272)) && 9UL), (-1L))) , 0xDF67L), 1)) < p_66) < 0x54011963L)) , l_1297)) > l_1272) > g_972) == (-5L)), p_65)), 7)))) < 0xB2L)) || l_1297) | g_739) < g_918[4][0][2]) , p_65) >= p_66))) , g_344))) ^ g_427[1]) > g_185[0][6][1]), g_318)) < 0UL), p_66)) <= 0x23L) , 0L), 0xF4E6L)))) == l_1297) > 0L)))) ^ p_66), g_34[5]))));
                        l_1296 = (safe_sub_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u((~(0x645CL || ((l_1345[5][0] = ((safe_mod_func_int32_t_s_s(((l_1272 && (safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_s((p_65 || ((((((-6L) <= 8L) , (~((((p_66 , (0xB66821A2L < (((safe_rshift_func_int16_t_s_s(((safe_lshift_func_int16_t_s_u((((0xE4F4L != g_972) && l_480[7][0]) != 4294967294UL), g_250[0][1])) & g_203), 4)) || p_66) | l_1302))) != l_524) == 65527UL) ^ l_1241))) , 0x26C4L) > 0x4D22L) == g_427[2])), p_66)), g_298))) > l_1297), l_1113[3])) != 0x96L)) && p_65))), p_66)) , l_1346), l_578));
                    }
                    else
                    {
                        uint32_t l_1358 = 1UL;
                        int32_t l_1371 = 0x7A5F4F65L;
                        int32_t l_1392[7];
                        int i;
                        for (i = 0; i < 7; i++)
                            l_1392[i] = 2L;
                        l_1296 = (safe_rshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((g_1357 >= (l_1295[1] = l_1358)), (safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s(g_1363, (0L >= (g_35 = (((!(((safe_mod_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((l_1294 = ((p_66 > ((((((safe_add_func_int32_t_s_s((l_467[5][3][3] <= (l_1325 , ((((g_183[5] != (0xFB72L < p_65)) && l_1358) >= g_897[0][2]) | 0x1D2E4787L))), 0xFDF57856L)) != l_1371) , g_27[g_33][g_33]) >= 0x2BL) | g_203) <= p_66)) , 0xAFL)), p_66)), p_66)) , l_1293) ^ p_66)) ^ p_66) & l_1371))))), g_5)))), p_65)), 1L)), 5)) | g_53) != g_1044), l_1106));
                        g_897[0][2] = (0xA1L && (safe_add_func_int16_t_s_s(l_1272, (safe_mod_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((0x19L || (p_65 > l_1378)), (safe_rshift_func_int16_t_s_s((g_344 = (((safe_mod_func_int8_t_s_s((l_1393 = (l_1241 = (l_1003[1] = (l_1392[5] = (safe_sub_func_int16_t_s_s(g_126, (safe_lshift_func_int8_t_s_s(p_66, ((((~g_504[7][7][1]) && (~(((((safe_add_func_uint32_t_u_u(g_27[0][0], g_419)) , l_1391) & l_845) || p_65) , 0x3E47AE32L))) | l_1358) & l_1358))))))))), g_504[2][4][2])) & 0xEDAC9C1BL) == 0x67L)), 11)))), g_504[8][0][2])))));
                    }
                    for (l_1378 = 0; (l_1378 <= 1); l_1378 += 1)
                    {
                        int i, j;
                        g_897[0][2] = ((g_897[(g_33 + 1)][(g_33 + 1)] != ((g_897[l_1378][(g_449 + 1)] ^ (p_66 < (((+((l_1297 = ((safe_add_func_uint8_t_u_u(((+(g_972 || ((0xE8D0L & (safe_sub_func_uint8_t_u_u(8UL, 0L))) != (p_65 , (!(safe_rshift_func_uint16_t_u_s((l_1403[5][2][5] = l_1113[6]), 7))))))) == g_33), 246UL)) == g_298)) | 0x99DAL)) == p_65) && 0xCFCCL))) > g_897[(g_33 + 1)][(g_33 + 1)])) && 8UL);
                        if (l_1297)
                            continue;
                        l_1325 = ((0xE17DL && g_250[0][1]) | ((safe_sub_func_uint8_t_u_u(l_1403[3][0][0], ((safe_add_func_int16_t_s_s(0x03E5L, (safe_sub_func_uint8_t_u_u((g_185[0][6][1] = (((safe_lshift_func_int8_t_s_s(p_66, ((((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_u(1L, 3)) != (safe_rshift_func_int8_t_s_u((l_1004[7] = (((!((l_1295[6] <= 0xF272E329L) < ((safe_rshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s(((255UL || l_1293) == 1UL), l_1113[3])), 4)) != p_65))) & 0xDACCL) >= 0x1871L)), p_66))), 0xF3501246L)), g_503)) & g_27[g_33][g_33]) , g_27[2][0]) , (-1L)))) == p_65) != g_86)), p_65)))) && p_66))) , g_250[0][1]));
                    }
                    if ((safe_lshift_func_int16_t_s_u(((((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(((((safe_mod_func_uint16_t_u_u((0x9CB499E2L >= (((0x208ED3C5L || p_65) , ((safe_rshift_func_uint8_t_u_u((6UL > l_1391), (safe_mod_func_int16_t_s_s((((safe_add_func_int16_t_s_s((g_1138 & p_65), ((((safe_mod_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((p_66 == ((safe_rshift_func_uint8_t_u_s(g_427[1], 0)) ^ l_1297)), 4)), 0xA845L)), 1L)) == 2L) ^ g_32[7][1]) | p_66))) == l_1297) >= p_65), g_44)))) >= p_65)) & l_493)), 1UL)) && l_1295[3]) || (-6L)) & p_66), p_66)), 2)) > 0x041038FBL) < p_65) | g_86), l_1237)))
                    {
                        uint32_t l_1450 = 0x843E54ABL;
                        p_65 = (((l_1295[1] = (g_86 | p_66)) , (p_66 <= (l_1296 = l_1393))) , (((safe_sub_func_uint8_t_u_u((safe_unary_minus_func_uint32_t_u(((l_1450 | (((safe_add_func_uint32_t_u_u((l_1293 | (g_897[1][2] = p_66)), (g_185[0][6][1] , (safe_rshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s(0L, p_66)), p_65))))) ^ 0x6FL) & p_66)) >= 0xED1C1E00L))), 0xA6L)) , l_1297) <= l_1004[4]));
                        if (l_1297)
                            break;
                    }
                    else
                    {
                        p_65 = (p_65 >= g_499);
                    }
                }
            }
        }
        for (g_739 = (-2); (g_739 >= 26); ++g_739)
        {
            uint32_t l_1470 = 0UL;
            uint8_t l_1471 = 0UL;
            uint32_t l_1494 = 4294967288UL;
            int32_t l_1529[9] = {1L,0x38A08F81L,1L,0x38A08F81L,1L,0x38A08F81L,1L,0x38A08F81L,1L};
            int8_t l_1558 = 1L;
            int32_t l_1560[4][8] = {{0xB28C2D5AL,(-1L),(-1L),0xB28C2D5AL,(-1L),(-1L),0xB28C2D5AL,(-1L)},{0xB28C2D5AL,0xB28C2D5AL,(-1L),0xB28C2D5AL,0xB28C2D5AL,(-1L),0xB28C2D5AL,0xB28C2D5AL},{(-1L),0xB28C2D5AL,(-1L),(-1L),0xB28C2D5AL,(-1L),(-1L),0xB28C2D5AL},{0xB28C2D5AL,(-1L),(-1L),0xB28C2D5AL,(-1L),(-1L),0xB28C2D5AL,(-1L)}};
            int16_t l_1658 = (-1L);
            uint32_t l_1668 = 4294967295UL;
            uint32_t l_1698 = 4294967289UL;
            uint16_t l_1760[9] = {0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL};
            int i, j;
            for (g_86 = 0; (g_86 <= 3); g_86 += 1)
            {
                int16_t l_1565 = 3L;
                int i, j, k;
                if ((((l_1003[g_400] > (l_1471 = ((l_467[(g_86 + 1)][g_86][(g_86 + 1)] <= (((safe_add_func_uint8_t_u_u(((-1L) & (l_1241 = (4294967292UL || (((safe_add_func_int32_t_s_s(((l_1470 = ((((p_66 | p_66) | (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s(((l_1467[0][2][4] | ((-7L) == ((((safe_add_func_int16_t_s_s(0x6EADL, l_1237)) ^ 0xBCL) , l_467[(g_86 + 1)][g_86][(g_86 + 1)]) <= p_66))) && 9UL), p_66)), 10))) & p_66) && 7UL)) == 0UL), g_127)) <= g_34[5]) , (-7L))))), l_467[(g_86 + 1)][g_86][(g_86 + 1)])) >= g_27[2][0]) || (-1L))) , g_1357))) || 1UL) | g_276))
                {
                    int32_t l_1493 = (-1L);
                    int16_t l_1528 = 0L;
                    uint32_t l_1530[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_1530[i] = 9UL;
                    g_897[0][2] = (-2L);
                    for (p_65 = 0; (p_65 <= 0); p_65 += 1)
                    {
                        int32_t l_1492 = 0x4D0D90E5L;
                        int32_t l_1495 = (-9L);
                        int i, j;
                        g_1472 = g_250[p_65][(p_65 + 3)];
                        l_1495 = ((((((g_250[0][1] < l_1237) , ((~l_1470) && (((safe_add_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(246UL, l_1470)), (((g_639 = ((g_486 & (safe_mod_func_int32_t_s_s((0x2EEBL < ((((safe_add_func_int8_t_s_s(((((l_467[7][0][5] , ((safe_mod_func_uint16_t_u_u((((((((((safe_rshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u(((l_1493 = (((safe_mod_func_int32_t_s_s((((safe_add_func_uint32_t_u_u((g_127 = (((g_897[0][2] = (p_66 == g_250[p_65][(p_65 + 3)])) | l_1492) || 0xF5C4L)), 9L)) != l_1470) | p_65), g_427[0])) < 1UL) & 0x2AL)) | (-1L)), g_1045)), p_65)) >= p_65) & g_504[1][1][2]) & g_250[0][4]) > 4UL) | 0L) , l_1003[g_400]) ^ 0L) | l_467[(g_86 + 1)][g_86][(g_86 + 1)]), 1L)) ^ g_86)) != 1L) & 0x40C9L) ^ p_66), (-1L))) == g_639) > 0x8A81L) == p_65)), p_65))) && g_1001)) < 2UL) > g_86))) , g_739) | l_467[(g_86 + 1)][g_86][(g_86 + 1)]))) || l_1493) & l_1494) <= 4294967288UL) ^ g_972);
                        l_1530[0] = (0xB1095615L ^ ((((g_276 = ((l_1237 , (safe_sub_func_int8_t_s_s(p_66, ((safe_mod_func_int32_t_s_s(((safe_add_func_int8_t_s_s(((((+((safe_rshift_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s(l_480[6][4])), (safe_mod_func_int32_t_s_s((~(((((safe_lshift_func_uint8_t_u_s((l_821 = p_66), (safe_sub_func_uint32_t_u_u(4294967293UL, ((l_1529[4] = ((safe_add_func_uint32_t_u_u((p_66 != g_250[p_65][(p_65 + 3)]), ((safe_add_func_uint16_t_u_u((safe_unary_minus_func_int8_t_s((((!((safe_add_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((!((safe_sub_func_uint16_t_u_u(9UL, 0x62AEL)) >= g_693[1])), g_1472)), g_897[1][2])) && l_1528)) < g_127) < g_503))), g_250[p_65][(p_65 + 3)])) != g_185[0][6][1]))) , g_427[1])) != l_1003[g_400]))))) , 0x645FEDD0L) > (-8L)) == 0UL) ^ g_34[5])), p_66)))), 9)) | l_467[(g_86 + 1)][g_86][(g_86 + 1)])) > p_66) ^ l_1495) <= p_65), p_66)) <= 65535UL), g_400)) & (-1L))))) <= l_1471)) , g_566) , 0x011947C7L) >= (-4L)));
                        g_897[1][0] = (((safe_sub_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(l_1241, g_1363)), (p_66 == ((safe_lshift_func_int8_t_s_s((((p_66 ^ (safe_rshift_func_uint16_t_u_s((((l_1005 = (safe_mod_func_uint16_t_u_u(((g_185[0][6][1] || (((g_456 >= (+0xD4L)) < 0x43L) >= (((l_467[3][2][3] , (-1L)) , 0x59D7E43EL) != l_467[(g_86 + 1)][g_86][(g_86 + 1)]))) | g_692), p_66))) != 0xFF3C684BL) > 0x3DA2L), 2))) == l_1542) == p_65), p_65)) >= 0x7539L)))) >= l_1529[8]) , (-10L));
                    }
                }
                else
                {
                    int8_t l_1559 = (-7L);
                    int32_t l_1581 = 0xAFC65760L;
                    int32_t l_1582 = 1L;
                    for (l_1470 = 0; (l_1470 < 12); l_1470 = safe_add_func_uint32_t_u_u(l_1470, 5))
                    {
                        int16_t l_1557 = 0xD922L;
                        p_65 = ((safe_mod_func_uint32_t_u_u((((((safe_rshift_func_uint16_t_u_s(((p_65 != (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((l_1494 <= (safe_lshift_func_int8_t_s_u((l_1560[0][0] = (((g_427[1] > 4294967295UL) || ((l_1241 = ((l_1557 ^ p_65) , l_1003[g_400])) < (g_344 = (l_1558 = 0x9BF8L)))) > (l_1529[8] = ((g_1138 = l_1559) && g_32[1][0])))), 5))) ^ p_65), l_1003[g_400])), 0x7E1AL))) | p_66), g_693[1])) <= 0L) != (-4L)) ^ g_639) >= g_639), g_456)) || 0UL);
                        if (p_65)
                            continue;
                    }
                    l_1582 = (safe_mod_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((g_419 = (l_1565 >= (safe_lshift_func_uint8_t_u_u((l_821 = (((((safe_add_func_int8_t_s_s(l_1559, (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u(((g_897[0][2] | (safe_sub_func_uint32_t_u_u(1UL, (safe_sub_func_uint8_t_u_u(((((((((safe_lshift_func_int8_t_s_s(0x8DL, (p_65 , g_1044))) | ((g_566 = (((((((l_1003[g_400] = ((!(((l_1581 = g_1044) | (l_1403[5][2][5] != g_692)) & p_65)) >= 65535UL)) && 3L) != 0xB3L) ^ l_1403[5][3][0]) , l_1529[2]) , l_1403[5][0][0]) >= p_66)) , g_400)) || l_464) < g_503) | l_1565) < 0x013AL) < g_318) || p_66), g_503))))) & l_1565), 13)), 7)))) || 0x2CAD4CBAL) , l_1559) < 65530UL) <= 0UL)), g_34[5])))), g_897[0][2])) , l_1560[0][0]) | 4294967295UL), 0xB6L));
                }
                p_65 = (safe_lshift_func_int16_t_s_s((((safe_sub_func_int16_t_s_s(((0x428EF9E6L & g_250[0][1]) ^ ((g_693[0] = ((l_1471 == (g_344 = (safe_add_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u(0xA0F1L, (l_1237 < p_65))), (l_1558 < (safe_lshift_func_int16_t_s_s(((0x68L || g_318) <= 0x40L), g_44))))))) & g_32[6][1])) , 0x64L)), 1L)) | l_1471) == 0xF62BL), 7));
                p_65 = ((((safe_lshift_func_uint16_t_u_s((l_1113[3] >= (safe_add_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_u((g_250[0][3] != ((safe_sub_func_int16_t_s_s((l_1003[g_400] = (~g_449)), 1UL)) && 0x66L)), 6)) , (l_1560[2][7] = ((l_1113[3] >= (l_1003[g_400] = (((g_315 , ((((safe_mod_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((((g_897[0][2] = ((+(((safe_lshift_func_uint8_t_u_u(g_34[5], g_918[4][0][2])) & p_65) && 0xAEL)) > p_66)) ^ l_1565) , g_693[1]))), 2UL)) ^ 0x3BL) | 0x12BD2217L) , g_693[1])) && l_1529[0]) ^ 0x68E2B964L))) , (-1L)))), 1)) , g_1044), l_1565))), g_317)) , g_1472) != p_66) || l_1113[2]);
            }
            p_65 = (((safe_rshift_func_uint16_t_u_s(((!4UL) || (((safe_lshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s((((safe_add_func_int16_t_s_s((l_821 && 0x8CL), (l_1393 = (safe_mod_func_uint8_t_u_u(((((g_183[4] ^ ((((g_34[1] = g_503) < g_499) > (safe_unary_minus_func_uint16_t_u(l_1237))) ^ ((l_1529[2] = (((safe_lshift_func_int16_t_s_s((((l_1560[2][4] = (p_65 >= 0xF573L)) > l_1471) | (-8L)), 3)) <= 1L) > g_639)) , g_315))) < p_65) <= g_185[0][0][1]) == g_503), 0x75L))))) != 0x9AL) || l_1529[3]), 0x37L)), 7)) <= p_66) < 0L)), 9)) >= p_65) , l_1467[0][4][1]);
            if (g_86)
            {
                return g_693[1];
            }
            else
            {
                p_65 = (safe_sub_func_int8_t_s_s((safe_unary_minus_func_int32_t_s(p_65)), ((g_27[0][0] == (((~(0xA0C7878AL || 0UL)) != (+(0xB8F97517L || l_819))) > g_185[0][6][1])) || (((safe_rshift_func_uint8_t_u_s(l_1005, 7)) , ((+((((p_66 && p_66) < 0x01L) >= g_897[0][2]) , 0xD3CDED4AL)) , l_1494)) == p_66))));
                if (g_317)
                    break;
            }
            for (g_132 = 0; (g_132 > 2); g_132 = safe_add_func_int32_t_s_s(g_132, 6))
            {
                uint8_t l_1634 = 0xB2L;
                int32_t l_1716 = 0xA3193607L;
                int32_t l_1717 = 0x90845B7EL;
                l_1635 = ((0UL <= 4294967295UL) != (g_185[0][8][1] = l_1634));
                for (g_108 = (-11); (g_108 != 10); g_108++)
                {
                    uint16_t l_1642 = 65527UL;
                    int32_t l_1648 = 0x48E861A4L;
                    for (l_1241 = 0; (l_1241 == 28); ++l_1241)
                    {
                        uint32_t l_1643 = 0x43FAAC56L;
                        int32_t l_1647 = 0L;
                        int32_t l_1667 = 8L;
                        int32_t l_1671 = 0x43CF90B1L;
                        p_65 = ((l_1560[1][6] = (safe_add_func_int32_t_s_s(p_65, (l_1642 = p_66)))) || ((0x2A73L > (0UL || (((l_1643 ^ (((~65535UL) | 254UL) , g_427[1])) | ((g_53 = (((l_1403[5][2][5] != 0x6CL) != (-3L)) || p_66)) >= p_65)) < 0x8A28E5CAL))) != l_1238));
                        l_1671 = (((l_1670 = (((safe_add_func_int32_t_s_s(((l_1393 = ((l_1647 = l_1403[0][2][7]) > g_400)) || (l_1648 = l_1471)), (safe_add_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((~((((safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_1328 = (l_1658 ^ ((((0L && (safe_add_func_uint8_t_u_u((((p_65 = g_972) | (l_1667 = ((l_1470 ^ (((((p_66 != (safe_lshift_func_int16_t_s_u((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(p_66, g_739)), 0xECL)), p_66))) & 4294967286UL) != g_185[0][6][1]) != 252UL) , 4294967291UL)) | 0x8EL))) , p_65), g_34[5]))) || g_449) != 0x7947L) , 4L))) <= l_1668), 11)), 2)) | g_1669) | 0x0242L) ^ 0xB29AL)), 5UL)) == (-7L)), g_34[8])))) || l_1634) | g_693[1])) > l_1642) ^ g_693[1]);
                        l_1648 = (p_65 | g_419);
                    }
                    p_65 = ((p_66 = 0x50CEL) || (((-1L) == p_65) >= g_86));
                }
                for (l_1658 = 0; (l_1658 <= 3); l_1658 += 1)
                {
                    uint16_t l_1677[9][3] = {{65534UL,65526UL,65534UL},{65535UL,65535UL,65535UL},{65534UL,65526UL,65534UL},{65535UL,65535UL,65535UL},{65534UL,65526UL,65534UL},{65535UL,65535UL,65535UL},{65534UL,65526UL,65534UL},{65535UL,65535UL,65535UL},{65534UL,65526UL,65534UL}};
                    int i, j;
                    for (g_566 = 1; (g_566 >= 0); g_566 -= 1)
                    {
                        int i, j, k;
                        l_1677[4][1] = (l_1560[3][5] = (((((safe_unary_minus_func_uint32_t_u(g_185[g_566][g_400][(g_566 + 1)])) && ((65535UL != ((1L == ((+l_1403[g_566][l_1658][(l_1658 + 3)]) <= (l_467[(g_566 + 5)][l_1658][(l_1658 + 2)] == (l_1403[0][2][6] , (((safe_unary_minus_func_int8_t_s(g_486)) ^ g_32[1][0]) , (g_1669 != g_692)))))) && p_66)) <= 0xD103L)) < l_467[(g_566 + 5)][l_1658][(l_1658 + 2)]) <= g_693[0]) , p_66));
                    }
                    for (g_203 = 0; (g_203 <= 1); g_203 += 1)
                    {
                        int i, j;
                        if (g_32[(l_1658 + 5)][g_203])
                            break;
                        return l_1634;
                    }
                }
                if ((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((((((safe_rshift_func_uint16_t_u_s(l_1686[0], (safe_rshift_func_int8_t_s_s((g_53 == ((((safe_sub_func_uint8_t_u_u((((0xD775L <= (0xAEE94457L && (~(0xABL != ((g_456 = (safe_rshift_func_uint16_t_u_s(((l_1470 , ((safe_mod_func_int8_t_s_s(((((l_464 < (l_1634 && (safe_sub_func_int32_t_s_s(((0xDF5BL > g_918[4][0][2]) >= p_66), g_32[1][0])))) , p_65) , l_1634) != g_27[2][0]), l_896)) | 0xB8L)) <= (-1L)), 8))) == 0UL))))) ^ 0x362AD372L) < 0x7ADCL), p_66)) > p_65) | 0x60L) , (-3L))), 7)))) , (-10L)) && l_1529[7]) & g_318) && l_1698) & g_1472), p_66)), 0x7AL)), p_66)))
                {
                    uint32_t l_1709 = 4294967295UL;
                    l_1241 = (1UL <= (safe_mod_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_s((g_185[1][2][2] >= ((((((((safe_sub_func_uint32_t_u_u((g_132 , (safe_mod_func_int16_t_s_s((((0x81L <= l_1709) , (p_65 , (l_1005 = (((l_1529[4] = ((l_1325 = (((l_1717 = (g_32[1][0] != (l_1716 = (safe_lshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u(((safe_sub_func_int8_t_s_s(((l_1686[0] = (l_1004[5] == p_66)) , l_1634), p_65)) >= l_1298), l_1005)) <= 0x0654L), p_66))))) && 0xBAB9L) <= 250UL)) > 254UL)) == 0x619AL) ^ g_315)))) && (-1L)), g_250[0][3]))), 1UL)) == l_1634) >= 1UL) | g_32[6][1]) , l_1471) && g_27[2][0]) , g_972) , 0L)), 2)) > g_1357), l_1560[0][0])));
                }
                else
                {
                    uint32_t l_1726 = 0x4FA10B89L;
                    int32_t l_1767 = 0x8BC3B71DL;
                    p_65 = ((((safe_lshift_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u(((((g_427[1] && (((((safe_rshift_func_uint8_t_u_s(p_66, ((p_66 , ((((p_66 && l_1560[2][4]) >= (g_1472 , (safe_add_func_int16_t_s_s(l_1726, (0xAEL <= (-1L)))))) || 0x5AL) , 0x84L)) >= l_638))) | l_1238) , p_65) && l_1005) | 0x16L)) , l_1634) || g_276) , p_66), l_1726)), 11)) && 0x108FL) & 0x52L) > 1UL);
                    g_1472 = (safe_sub_func_uint16_t_u_u(((safe_add_func_uint32_t_u_u(((g_639 = (safe_lshift_func_int8_t_s_u((l_1560[0][0] = ((p_65 = (safe_add_func_int32_t_s_s((g_427[2] , (safe_mod_func_int16_t_s_s(p_66, (((l_1284 >= (safe_sub_func_int16_t_s_s((p_65 == (((safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((p_66 | 0xF3CA0833L), (0x98L & (safe_lshift_func_uint16_t_u_s((0x37L >= ((safe_sub_func_uint32_t_u_u(0UL, g_127)) > g_391)), l_1634))))) || p_65))) > 1UL) || l_1746[0])), l_1747))) < p_65) || g_247)))), l_1726))) | 8L)), 5))) , l_1726), g_126)) <= p_66), l_1471));
                    p_65 = ((((safe_rshift_func_uint16_t_u_s((l_578 != (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((g_27[0][0] = p_65) != ((p_65 & (safe_lshift_func_uint8_t_u_s((((safe_mod_func_uint8_t_u_u((l_1393 = (0L != (l_1767 = ((4L != ((l_1760[6] <= (~(safe_lshift_func_int8_t_s_s(l_1726, g_577)))) > (safe_unary_minus_func_uint32_t_u((safe_mod_func_int8_t_s_s((p_65 , g_108), g_427[1])))))) , g_419)))), 6UL)) , 9L) && l_1635), 7))) || l_1560[3][5])), 0xD285L)), 0UL)), 1))), g_185[0][6][1])) || (-2L)) & p_65) <= p_66);
                }
            }
        }
    }
    g_897[0][0] = 0xDCEA6FB5L;
    for (g_1363 = (-24); (g_1363 >= (-29)); g_1363 = safe_sub_func_int32_t_s_s(g_1363, 6))
    {
        uint8_t l_1787 = 0xF3L;
        int32_t l_1788 = 0x0FA9B2A5L;
        int32_t l_1790 = (-1L);
        uint8_t l_2149 = 0x16L;
        uint32_t l_2289 = 4294967289UL;
        uint16_t l_2377 = 1UL;
        uint32_t l_2433 = 0x01B1006AL;
        l_1790 = ((p_66 | (l_821 = (((safe_mod_func_int16_t_s_s((g_53 = (l_1238 | ((p_65 ^ 0x749C2626L) < l_471))), ((safe_unary_minus_func_int32_t_s(((safe_add_func_int32_t_s_s(((safe_mod_func_int8_t_s_s((safe_sub_func_uint8_t_u_u(((l_1788 = (p_66 != (0x101AEE60L >= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_add_func_uint16_t_u_u(l_493, (((safe_add_func_int16_t_s_s((4294967295UL ^ l_845), p_65)) > 0x6AL) , l_1787))) & g_897[0][0]), 3)), g_1669))))) >= p_66), g_250[0][1])), 255UL)) || 0x7AL), l_1787)) , p_66))) && l_1787))) , 0xBF8CL) < l_1789))) ^ (-5L));
        if (((safe_sub_func_int32_t_s_s(l_1004[4], ((250UL | (safe_lshift_func_int8_t_s_u(g_247, 1))) < (((safe_mod_func_uint32_t_u_u(0x291232D6L, (safe_rshift_func_uint8_t_u_u(((l_1325 = ((((g_897[0][0] = (0xD281AB12L > ((safe_add_func_int8_t_s_s((((((safe_rshift_func_int8_t_s_s((0x4DL > ((p_66 || (safe_mod_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(0xB7L, (l_1790 = ((((((safe_add_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((1UL > l_1788), l_1811)), 0x4A19D9ABL)) | l_464) >= p_66) , g_503) | l_464) <= g_1472)))) < 0x507AL) , 0x8BD9L), g_1328))) && 255UL)), 7)) ^ 0xCA73L) , g_427[2]) == 0x64L) <= 4294967288UL), l_1811)) & p_65))) , p_66) , p_65) , l_896)) || g_32[1][0]), 5)))) > l_1298) , p_65)))) ^ 0x4425L))
        {
            p_65 = ((safe_mod_func_uint16_t_u_u(l_1790, g_183[5])) && (l_1788 = (((l_1790 = (l_1284 < l_1298)) | (g_456 = l_1788)) ^ 0x32L)));
        }
        else
        {
            int32_t l_1820 = 0x519D9E70L;
            uint32_t l_1828 = 0x36662FD9L;
            int32_t l_1841 = 0x5138AB18L;
            int32_t l_1844 = (-1L);
            int8_t l_1854 = 0x86L;
            uint32_t l_1865 = 8UL;
            int16_t l_2068 = 0x1033L;
            if (g_1472)
            {
                uint16_t l_1840[5][7] = {{65535UL,65535UL,65535UL,65535UL,0x14D5L,0xBA25L,4UL},{1UL,0xBA25L,65535UL,0x14D5L,0x14D5L,65535UL,0xBA25L},{0x14D5L,1UL,0x22B0L,5UL,65535UL,4UL,4UL},{0x22B0L,1UL,0x14D5L,1UL,0x22B0L,5UL,65535UL},{65535UL,0xBA25L,1UL,5UL,0x728AL,5UL,1UL}};
                int32_t l_1845 = 1L;
                uint16_t l_1862[9][4][7] = {{{65535UL,1UL,0x337AL,0x7FEAL,0x3B9DL,65535UL,0x012AL},{0x1192L,0UL,4UL,65534UL,65535UL,4UL,0x79A2L},{65528UL,0UL,0x337AL,0x7073L,65535UL,65535UL,0x2784L},{0xE6F5L,0x3FA8L,0xFFF7L,65531UL,0x13A0L,0x45B7L,4UL}},{{1UL,0xBF61L,0x840EL,65535UL,0x721CL,1UL,0x2784L},{0x4FEDL,6UL,0xE6F5L,65535UL,0xA48AL,0xA48AL,65535UL},{0UL,0xBF61L,0UL,0x74E5L,0UL,0UL,4UL},{1UL,0x3FA8L,2UL,65535UL,65533UL,0UL,0xB74AL}},{{1UL,65530UL,0xB010L,65535UL,65535UL,0UL,65535UL},{0xE6F5L,0x6E21L,0x6A4BL,65531UL,0UL,0xA48AL,4UL},{1UL,0xA66BL,0x840EL,0x2784L,0xDE0CL,1UL,65535UL},{1UL,6UL,0x6A4BL,0x811BL,0xA48AL,0x45B7L,0x811BL}},{{0UL,0xF760L,0xB010L,0x74E5L,0xDE0CL,0x791DL,4UL},{0x4FEDL,0x417DL,2UL,0xB74AL,0UL,0UL,0x811BL},{1UL,65530UL,0UL,65535UL,65535UL,65535UL,65535UL},{0xE6F5L,0x417DL,0xE6F5L,65531UL,65533UL,0x6680L,4UL}},{{0x25EAL,0xF760L,0x840EL,65535UL,0UL,1UL,65535UL},{0UL,6UL,0xFFF7L,0xB74AL,0xA48AL,0x6680L,0xB74AL},{0UL,0xA66BL,0x70B9L,0x74E5L,0x721CL,65535UL,4UL},{0UL,0x6E21L,2UL,0x811BL,0x13A0L,0UL,65535UL}},{{0x25EAL,65530UL,0x70B9L,0x2784L,65535UL,0x791DL,0x2784L},{0xE6F5L,0x3FA8L,0xFFF7L,65531UL,0x13A0L,0x45B7L,4UL},{1UL,0xBF61L,0x840EL,65535UL,0x721CL,1UL,0x2784L},{0x4FEDL,6UL,0xE6F5L,65535UL,0xA48AL,0xA48AL,65535UL}},{{0UL,0xBF61L,0UL,0x74E5L,0UL,0UL,4UL},{1UL,0x3FA8L,2UL,65535UL,65533UL,0UL,0xB74AL},{1UL,65530UL,0xB010L,65535UL,65535UL,0UL,65535UL},{0xE6F5L,0x6E21L,0x6A4BL,65531UL,0UL,0xA48AL,4UL}},{{1UL,0xA66BL,0x840EL,0x2784L,0xDE0CL,1UL,65535UL},{1UL,6UL,0x6A4BL,0x811BL,0xA48AL,0x45B7L,0x811BL},{0xF728L,65535UL,0x7073L,0xE61EL,1UL,65527UL,1UL},{0x6183L,65535UL,1UL,0x45B7L,65535UL,0x6E21L,0x6680L}},{{0xC2F3L,0x927CL,0xF728L,65535UL,0x342BL,0x342BL,65535UL},{0x79A2L,65535UL,0x79A2L,0xCE98L,6UL,0x676FL,0UL},{0UL,65535UL,65527UL,65535UL,65530UL,0xA66BL,0x791DL},{0xC341L,0x076EL,65534UL,0x45B7L,0x9F57L,0x676FL,0x45B7L}}};
                int i, j, k;
                for (g_1669 = 0; (g_1669 < 5); ++g_1669)
                {
                    int8_t l_1842[7] = {0x96L,(-3L),0x96L,0x96L,(-3L),0x96L,0x96L};
                    uint16_t l_1843 = 3UL;
                    int32_t l_1851 = (-10L);
                    int i;
                    l_1820 = (p_66 && (safe_mod_func_int8_t_s_s((l_1845 = (safe_rshift_func_uint16_t_u_u((((p_65 >= l_1820) ^ (((safe_sub_func_uint16_t_u_u((l_1844 = (l_480[6][0] = ((((safe_lshift_func_uint16_t_u_s((~((((g_247 = (safe_sub_func_int32_t_s_s(l_1828, ((((safe_add_func_int16_t_s_s((l_1843 = (safe_mod_func_int16_t_s_s(((((l_1790 = (+(5UL <= ((((g_693[1] <= (safe_lshift_func_int16_t_s_u(0L, (safe_sub_func_uint32_t_u_u((((((p_66 <= ((((l_1841 = l_1840[3][4]) || 0UL) , g_53) , 0x2BL)) > 1UL) & l_1003[5]) || l_1787) || 0x33L), l_1828))))) | (-1L)) <= g_33) == 0xA36A891DL)))) <= 0xCDDB0A30L) <= l_1842[3]) && 0L), p_65))), p_65)) == p_65) , 0xB2L) <= g_739)))) == 0x2429170DL) , g_132) == g_183[9])), 5)) == l_1787) < (-10L)) >= p_65))), (-4L))) | 6UL) == l_1746[0])) || p_66), g_32[6][1]))), 250UL)));
                    if (l_1845)
                        continue;
                    if (p_66)
                        break;
                    g_1472 = (((((safe_lshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s(p_66, ((l_1851 = (safe_unary_minus_func_uint16_t_u(p_65))) , ((((safe_add_func_int32_t_s_s(((((g_400 = l_1787) || l_1854) & (((p_65 , (safe_add_func_int8_t_s_s(g_27[2][0], (safe_mod_func_int16_t_s_s((((l_1788 = p_65) & (((safe_rshift_func_int16_t_s_s((l_1845 = p_66), (g_53 = (((l_1787 & p_65) < p_66) & l_1840[3][4])))) >= l_1842[3]) , l_1841)) >= 0x56L), g_504[1][1][2]))))) , p_66) == 4L)) < 0L), p_65)) , g_1138) , l_1844) && l_1861)))), p_65)) != l_1840[3][4]) ^ l_1842[1]) != l_1862[5][0][2]) & p_65);
                }
            }
            else
            {
                uint32_t l_1889 = 1UL;
                int32_t l_1952 = (-1L);
                int32_t l_1953 = (-10L);
                if ((safe_add_func_uint8_t_u_u(0x49L, l_1865)))
                {
                    int16_t l_1890[9][7] = {{0x8878L,0x8878L,0xE640L,0x838DL,0x8878L,(-5L),0x838DL},{0x460EL,0xF69DL,(-1L),(-1L),(-1L),0xF69DL,0x460EL},{0xE42EL,0x838DL,6L,0xE42EL,0x8878L,6L,6L},{1L,(-1L),0x0FC6L,(-1L),1L,5L,1L},{0x8878L,0xE42EL,6L,0x838DL,0xE42EL,0xE42EL,0x838DL},{(-1L),(-1L),(-1L),0xF69DL,0x460EL,0xF69DL,(-1L)},{0x8878L,0x838DL,0xE640L,0x8878L,0x8878L,0xE640L,0x838DL},{1L,0xF69DL,0x65EDL,(-1L),0x65EDL,0xF69DL,1L},{0xE42EL,0x8878L,6L,6L,0x8878L,0xE42EL,6L}};
                    int16_t l_1937 = 4L;
                    int i, j;
                    for (g_1328 = 0; (g_1328 <= 1); g_1328 += 1)
                    {
                        int32_t l_1882 = 0L;
                        int i;
                        if (l_1854)
                            goto lbl_1866;
                        l_1890[8][4] = (((safe_rshift_func_int8_t_s_u(g_183[(g_1328 + 5)], 3)) >= (((safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((g_27[2][0] = (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_u(g_400, 2)), l_1790)) == 0UL) < (safe_add_func_int8_t_s_s(g_32[1][0], (!(l_1882 = (safe_rshift_func_uint16_t_u_u(0x12E7L, 6)))))))), (safe_lshift_func_uint16_t_u_u(((p_65 | p_66) , (safe_lshift_func_int8_t_s_s(((safe_add_func_uint16_t_u_u(g_183[(g_1328 + 5)], l_1787)) , g_33), 0))), 5)))), l_1889)) > 65527UL) , p_66)) | 255UL);
                        if (g_183[(g_1328 + 5)])
                            continue;
                        g_1472 = ((safe_add_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(g_918[4][0][2], 4)) || (safe_lshift_func_uint16_t_u_s(g_183[(g_1328 + 5)], ((safe_add_func_uint16_t_u_u(l_1890[4][3], (0x38E0L > (safe_lshift_func_int8_t_s_s(p_65, 7))))) > (safe_sub_func_int32_t_s_s((l_1004[4] & ((safe_add_func_int8_t_s_s(((safe_mod_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_uint8_t_u((((safe_add_func_uint32_t_u_u((1L | (p_65 ^ (safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((((((l_1882 = ((((0xA0B5L <= l_1787) , (-1L)) | g_44) || l_1790)) | 0L) >= p_65) != l_1788) == l_1918[3]), g_972)), g_739)) , 0x1EL), 3)))), g_318)) == p_66) | g_32[1][0]))), p_65)) , 0L) | g_183[(g_1328 + 5)]), l_524)) && g_318), p_65)) & g_33)), l_1865)))))), l_484)) & p_66);
                    }
                    p_65 = ((-3L) & (((+l_1841) == g_33) < ((((safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(g_820, p_66)), l_1787)) != (l_1788 || g_820)) || ((g_1045 > 0x0C4EEC4BL) && l_1788)) , l_1890[8][4])));
                    p_65 = (safe_mod_func_uint8_t_u_u((((!((0UL | (l_1890[8][4] == l_1844)) >= (p_66 ^ (safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((-8L), (safe_mod_func_uint16_t_u_u(p_65, p_66)))), ((g_1472 | (l_1841 = (g_1328 = (((~(((((((safe_rshift_func_uint16_t_u_s((+(((l_1937 ^ l_1889) < g_577) >= l_1788)), p_66)) != 0UL) > 0xE227L) && p_65) != l_1788) && p_65) && g_693[1])) <= 0xADBEL) > p_66)))) || p_66)))))) >= p_66) , g_315), p_65));
                    g_897[0][2] = (safe_add_func_uint8_t_u_u(g_566, (l_1841 = (safe_add_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((((~3UL) & (safe_unary_minus_func_uint32_t_u((safe_mod_func_int8_t_s_s(g_391, l_1948[7][0]))))) < (l_1953 = (((safe_lshift_func_uint8_t_u_s(((((0x051CL != (g_1328 = (g_504[1][1][2] = ((((((p_66 , l_1790) || (((0xF1L | (((((l_1952 = (((+(((g_820 <= p_65) ^ g_247) , 0L)) , 2UL) | l_1937)) , g_566) , g_27[2][0]) & l_1889) < p_66)) <= (-1L)) > p_66)) > l_1844) , p_66) < l_1889) < l_1841)))) | l_1937) && 0x05CFL) || 0xE07CL), 2)) && p_65) < g_577))), 3)), p_66)))));
                }
                else
                {
                    uint8_t l_1954[6] = {0x85L,0x85L,246UL,0x85L,0x85L,246UL};
                    int32_t l_1969 = 0x4B3E8B39L;
                    int8_t l_2039 = (-3L);
                    int i;
                    for (l_547 = 1; (l_547 >= 0); l_547 -= 1)
                    {
                        int32_t l_1959 = 0xEAC54BEAL;
                        int i;
                        g_1472 = ((((l_1952 = (l_1954[4] = g_693[l_547])) > (((((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u((l_1953 = ((l_1959 = g_693[l_547]) , g_1357)), 4)), g_317)) , g_1328) || (((l_1790 = ((safe_unary_minus_func_uint16_t_u((safe_lshift_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(g_400, (safe_lshift_func_uint16_t_u_s(l_1969, (safe_sub_func_int8_t_s_s((+(safe_add_func_uint16_t_u_u((l_1788 == 0x38CAL), 0x6EDFL))), p_65)))))), 4294967287UL)) < l_1788), g_183[4])))) , p_66)) , l_1959) || p_66)) , 255UL) , 0xF4ABL)) , l_1828) || p_66);
                        l_1788 = ((l_1952 = p_66) , (safe_unary_minus_func_uint16_t_u((safe_mod_func_int16_t_s_s(0x5D75L, (l_1790 = l_1787))))));
                        l_1969 = ((safe_lshift_func_uint8_t_u_u((4294967291UL | (p_65 , (((safe_mod_func_uint16_t_u_u(g_1328, ((((((safe_lshift_func_uint16_t_u_s((g_1357 | l_1844), 6)) & g_1669) || (g_427[1] > l_1004[4])) , ((((safe_mod_func_uint8_t_u_u(l_480[7][4], 2L)) , p_66) | 0xACCFL) , p_65)) | 0L) , g_693[l_547]))) , g_1001) < p_65))), g_693[l_547])) & 0xD5L);
                    }
                    if ((safe_sub_func_uint32_t_u_u((l_1969 = 0x54ADABF8L), (safe_lshift_func_uint8_t_u_s((((safe_mod_func_int32_t_s_s(((safe_sub_func_uint8_t_u_u(g_1138, (g_34[5] = ((safe_mod_func_int8_t_s_s(g_315, p_66)) >= (safe_sub_func_uint8_t_u_u((0x6BL < (l_1686[0] = ((safe_mod_func_uint32_t_u_u(((((l_1788 = g_108) ^ 0xCEL) && ((safe_rshift_func_uint8_t_u_s((safe_unary_minus_func_int32_t_s((p_65 = ((g_317 < ((p_65 || p_66) > 2L)) <= 1UL)))), 1)) != 1UL)) == (-1L)), l_1841)) ^ l_1889))), 0x47L)))))) > p_66), p_66)) != g_35) & g_499), 1)))))
                    {
                        uint32_t l_2011 = 4294967286UL;
                        int32_t l_2047 = 1L;
                        g_897[0][2] = ((((l_2003 == (l_1820 = (safe_sub_func_int8_t_s_s((!(safe_rshift_func_uint8_t_u_s((l_1841 = ((safe_sub_func_int8_t_s_s(((((p_66 > (l_2011 , (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((0x3367L <= ((g_34[4] = (((l_1952 & ((l_2016 && (l_1828 != (p_65 = g_250[0][1]))) ^ g_504[4][0][2])) , p_66) == p_66)) || 1L)), 5)), g_427[1])))) | 0x1AL) , 0L) != 1UL), l_1969)) && g_27[1][0])), p_66))), p_66)))) <= (-6L)) && 1UL) || p_66);
                        if (p_65)
                            break;
                        l_1969 = ((safe_unary_minus_func_uint32_t_u(((g_1328 = (safe_mod_func_uint16_t_u_u((safe_mul_func_int32_t_s_s((g_1044 , (((safe_lshift_func_uint16_t_u_u(l_1787, ((l_1952 = ((safe_unary_minus_func_int8_t_s((l_1841 = (g_486 > ((safe_sub_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((p_66 && (((safe_sub_func_uint8_t_u_u((l_2047 = (safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_add_func_int16_t_s_s((l_2039 != (g_504[1][1][2] = g_32[6][1])), (0x4F42L < (g_298 = g_32[4][1])))) || (safe_rshift_func_uint8_t_u_s((safe_sub_func_uint32_t_u_u(((((!(safe_rshift_func_int8_t_s_u(((p_65 ^ l_2011) < p_65), l_1889))) , p_66) <= p_65) || 246UL), 0xBBB53246L)), 5))), 4)), 9L))), 8UL)) < 1L) | 0L)), l_2011)), p_65)) != l_1841), l_1953)) , l_1889))))) <= 0x17L)) , g_739))) >= g_315) < 5UL)), 0UL)), 0xB86EL))) <= 65528UL))) & 0xBCL);
                    }
                    else
                    {
                        g_897[0][1] = l_1953;
                        g_897[0][2] = (((l_821 = (((safe_rshift_func_uint16_t_u_s(l_2039, 6)) && (l_1820 = (((p_65 , 0UL) , (l_1787 || l_1954[1])) , g_639))) > l_1953)) || ((safe_sub_func_uint16_t_u_u(6UL, (safe_sub_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s(((5L | 0UL) != l_1790), g_27[2][0])) , 0xF0FEED72L), 0xDED2E308L)))) && p_66)) != 0x62L);
                    }
                }
            }
            p_65 = ((!0xCCL) , (((safe_sub_func_int32_t_s_s(0xCC9A5F1EL, ((((0UL != (((((!(g_132 = (safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(2UL, 2)), (safe_add_func_int16_t_s_s(p_65, (p_65 <= l_1854))))))) > ((safe_mod_func_int32_t_s_s((l_1004[4] = ((p_65 < p_66) , p_65)), 0x6C135FD5L)) | 1L)) < l_2068) ^ 0xF030L) <= (-2L))) && 1UL) | 0xFE525F63L) ^ l_1788))) > 0x8CF4690DL) != p_66));
            for (l_1238 = 0; (l_1238 <= 1); l_1238 += 1)
            {
                uint32_t l_2083 = 0xA96380A9L;
                int i, j;
                g_897[l_1238][(l_1238 + 1)] = 0x46B40BA6L;
                g_2084 = ((l_2003 = ((safe_add_func_uint16_t_u_u((~(g_897[l_1238][(l_1238 + 1)] = (safe_add_func_int16_t_s_s((((!(p_65 = ((g_897[l_1238][(l_1238 + 1)] ^ (p_65 > (g_276 || (safe_mod_func_int8_t_s_s((((((-7L) ^ (((+(((~(safe_sub_func_int8_t_s_s(0x8BL, (p_66 == 0xC3L)))) || (l_2083 = ((0x76B5L > 65535UL) , 0UL))) ^ 0L)) >= 0x6CL) && l_2083)) != 0xA818L) != l_1828) <= g_1328), p_66))))) == 2UL))) <= 255UL) ^ l_1828), 65532UL)))), p_66)) , l_1918[1])) & g_32[1][0]);
            }
        }
        if (((safe_add_func_int16_t_s_s((g_53 = ((safe_unary_minus_func_uint32_t_u((l_1686[2] = g_1669))) > (~(((g_203 && (((g_820 == l_1788) || ((((((((l_2003 = (safe_add_func_int32_t_s_s(((g_34[5] = (safe_add_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(((safe_lshift_func_int8_t_s_s(1L, ((l_1790 != (g_35 = (safe_mod_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((l_821 = (l_480[1][0] ^ 65535UL)), g_739)), 4UL)))) | l_1790))) ^ g_504[1][1][2]), 6)), g_127))) > 255UL), 0xE89649AAL))) && l_1788) < g_32[5][1]) ^ (-1L)) != 4UL) ^ 0x7F691811L) & p_66) > 1L)) ^ g_53)) <= g_918[4][0][2]) , 1UL)))), l_1811)) <= l_1790))
        {
            uint32_t l_2103[9][9] = {{0UL,0xFAA04BC0L,4294967293UL,4294967293UL,4294967292UL,4294967292UL,4294967293UL,4294967293UL,0xFAA04BC0L},{0UL,1UL,0x95E82AC0L,0x885E3658L,0UL,4294967289UL,0x7F593335L,4UL,0xE07C14B7L},{0xFEF033E5L,4294967293UL,4294967295UL,0x2E9C047FL,4294967293UL,4294967290UL,4294967293UL,0x2E9C047FL,4294967295UL},{1UL,1UL,4294967295UL,0xE07C14B7L,0x334FD436L,4294967288UL,4294967295UL,4294967295UL,0UL},{0xFFAFB7DBL,0xFAA04BC0L,0xC35E111CL,0xD4B8BFE3L,4294967288UL,0xFEF033E5L,0xFEF033E5L,4294967288UL,0xD4B8BFE3L},{4294967295UL,4294967288UL,4294967295UL,4294967289UL,4UL,0x9F6A72C8L,9UL,0UL,0x334FD436L},{4294967295UL,0xC35E111CL,4294967295UL,0UL,4294967293UL,0UL,0xD4B8BFE3L,0UL,4294967293UL},{4294967289UL,0x95E82AC0L,0x95E82AC0L,4294967289UL,4294967295UL,0UL,4294967295UL,5UL,9UL},{0x2E9C047FL,4294967288UL,0xFFAFB7DBL,4294967295UL,0xEBBD157BL,0xC35E111CL,4294967293UL,4294967293UL,0xC35E111CL}};
            int32_t l_2110[10] = {0L,0L,(-5L),0L,0L,(-5L),0L,0L,(-5L),0L};
            int32_t l_2111 = (-8L);
            int16_t l_2133 = 3L;
            uint8_t l_2173 = 0x68L;
            int32_t l_2237 = 0x71E8530EL;
            int i, j;
            if ((((((safe_lshift_func_uint8_t_u_s(p_65, 2)) , l_2103[4][5]) || l_2103[0][4]) <= ((p_66 <= 0x98L) != ((l_2103[4][5] && (safe_rshift_func_uint8_t_u_u(((l_2111 = (l_2106[2][3] & (safe_add_func_int32_t_s_s(0x54E97FADL, (g_897[1][1] = (+(l_2110[3] = p_65))))))) | g_400), g_1044))) & l_2103[4][5]))) ^ g_298))
            {
                int8_t l_2115[7][2] = {{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)}};
                int32_t l_2177 = 0xAA9400CDL;
                int32_t l_2238 = 1L;
                int i, j;
                if ((((g_33 & (l_1790 && ((safe_add_func_int8_t_s_s((g_34[5] = (-7L)), 0x8DL)) , (!(((l_2110[3] , ((((((g_897[1][2] = g_34[4]) | p_66) && ((l_1788 == ((g_5 < l_2115[3][0]) < g_918[4][0][2])) >= l_2115[3][0])) || g_203) , p_66) > g_400)) || p_66) | (-1L)))))) && 0xD9E8D83FL) || 255UL))
                {
                    uint16_t l_2132[6] = {0UL,0UL,0x73EDL,0UL,0UL,0x73EDL};
                    int32_t l_2136 = 0x3F75F6A0L;
                    int16_t l_2150[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_2150[i] = 0xC9A6L;
                    if ((g_391 , 0x8C9B131CL))
                    {
                        p_65 = (g_126 ^ (safe_mod_func_int16_t_s_s((g_897[0][2] <= 7L), (((safe_rshift_func_uint8_t_u_u(0x62L, 4)) | 1L) & (+(l_2110[3] = (safe_lshift_func_uint8_t_u_s((l_2133 = ((((safe_rshift_func_uint8_t_u_u(3UL, (safe_sub_func_int8_t_s_s(0xC3L, ((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((~((g_1472 && p_65) > g_315)), 5)), 2)) & p_65))))) || l_2132[3]) , p_66) < p_66)), l_1788))))))));
                        l_2150[0] = (((0xAAL > 1L) != ((safe_rshift_func_int16_t_s_s((g_820 = l_896), 5)) <= (l_2136 = p_65))) > ((g_419 ^ (((((safe_add_func_int32_t_s_s(((((safe_add_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(g_1044, l_484)), ((safe_sub_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_u((-4L), 0)), 4)), (0x6C0CL > g_419))) , 0x306BL))) , 0x67603F1BL) , l_2149) , 0x4D1D21AFL), 4294967294UL)) , 0xE7F0L) , g_427[1]) , g_27[1][0]) < l_1787)) <= l_2115[0][1]));
                        p_65 = ((safe_lshift_func_uint8_t_u_u(l_1787, l_2111)) & ((((((safe_mod_func_int8_t_s_s((((safe_add_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(4294967295UL, (safe_lshift_func_int16_t_s_s(0x27DFL, 10)))), (p_65 < ((safe_mod_func_uint16_t_u_u((l_2115[3][0] , ((~0xED65039CL) | ((((safe_add_func_uint8_t_u_u((g_35 = (((safe_sub_func_int8_t_s_s(((!(((l_2115[6][0] < ((g_27[0][0] = (safe_add_func_int16_t_s_s((((p_66 = (l_2136 = ((safe_rshift_func_uint16_t_u_s(g_566, l_2173)) == p_66))) < 0xD031L) | g_692), g_317))) > l_1788)) < g_693[1]) , 0UL)) != p_65), 6L)) && g_693[0]) || g_427[1])), 1UL)) , p_66) <= 0x92379295L) , 0L))), p_65)) >= l_2133)))) >= 7UL) , g_27[0][0]), p_65)) != l_467[7][2][4]) | 3L) != 1UL) ^ 65531UL) <= 0xE0F1L));
                        if (l_1298)
                            goto lbl_1866;
                    }
                    else
                    {
                        uint32_t l_2221[10][2][6] = {{{4294967295UL,4294967289UL,0x993CF049L,0x161D1F07L,1UL,0xF78E89E3L},{0UL,1UL,0x99365064L,0xDCFC65CAL,0x99365064L,1UL}},{{0x43258A84L,1UL,4294967287UL,0xA1A3CD24L,0xDCFC65CAL,0UL},{0xDA2898DEL,4294967290UL,0xCBE367A7L,4294967293UL,0xF78E89E3L,0x993CF049L}},{{1UL,4294967290UL,4294967295UL,0x05C28426L,0xDCFC65CAL,0x135DF28EL},{0xAE518E85L,1UL,4294967289UL,0xEBCBD73DL,0x99365064L,1UL}},{{0UL,1UL,4294967292UL,0x9C6C04D5L,1UL,0UL},{1UL,4294967289UL,4294967290UL,0x135DF28EL,4294967295UL,0x47814242L}},{{0x9C6C04D5L,0x47814242L,1UL,0UL,0UL,0xDCFC65CAL},{4294967293UL,0UL,1UL,4294967290UL,4294967293UL,0x8668F73FL}},{{0xF88F9FADL,4294967295UL,0xE473DEE0L,0xE473DEE0L,4294967295UL,0xF88F9FADL},{0x99365064L,4294967293UL,0x9C6C04D5L,0x962513B1L,0x135DF28EL,4294967292UL}},{{0UL,0x2C2F20E0L,0x8A155E41L,0xDA2898DEL,0UL,0xC5781BA1L},{0UL,0UL,0xDA2898DEL,0x962513B1L,0x979FC63CL,4294967290UL}},{{0x99365064L,0x135DF28EL,0x161D1F07L,0xE473DEE0L,0x648E8A16L,6UL},{0xF88F9FADL,0xA1A3CD24L,0x135DF28EL,4294967290UL,1UL,0xCBE367A7L}},{{4294967293UL,0x99365064L,0xF78E89E3L,0UL,4294967293UL,0x161D1F07L},{0x9C6C04D5L,0x8668F73FL,0UL,0x135DF28EL,0UL,4294967295UL}},{{1UL,0xAE518E85L,0UL,0x9C6C04D5L,1UL,4294967293UL},{0UL,0xEBCBD73DL,1UL,0xEBCBD73DL,0UL,0x43258A84L}}};
                        int i, j, k;
                        g_897[1][0] = (((l_2016 <= (((g_33 ^ (l_2177 = ((l_1790 = (!(p_65 , ((safe_mod_func_int8_t_s_s(0x5AL, l_2132[4])) & p_66)))) , g_33))) == ((safe_lshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(p_65, l_2115[3][0])), g_247)) <= 0xF4B0L), p_66)) == g_918[2][0][5])) >= g_315)) , 0xF7BE47CBL) ^ 0x82BBB2F9L);
                        g_897[0][2] = ((((safe_rshift_func_uint16_t_u_u((((p_66 || 2L) , (((g_504[0][5][1] && (safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((-1L), 2)), 3))) & ((safe_add_func_uint16_t_u_u(((l_2110[3] = (((p_66 , ((safe_rshift_func_uint8_t_u_s((l_1788 = g_185[0][6][1]), 6)) & (safe_mod_func_uint8_t_u_u(((!(((l_1790 = ((safe_lshift_func_int8_t_s_s(l_2136, (safe_rshift_func_int8_t_s_u(((!((safe_sub_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s(g_34[2], (((((safe_lshift_func_int8_t_s_u((-1L), 7)) > g_1472) & p_66) || g_1363) || 4294967293UL))) && 0x77E8D5D3L), g_35)) && p_65)) , g_5), 7)))) != 9UL)) < l_2106[2][3]) , g_276)) , p_66), l_1787)))) ^ g_566) <= g_126)) ^ l_2177), g_27[1][0])) == 0x16E7D832L)) , 0x6FL)) && g_1328), 3)) > (-1L)) == (-7L)) && p_65);
                        if (l_1790)
                            break;
                        l_1790 = (((safe_add_func_uint8_t_u_u(((((1L & ((((safe_rshift_func_int8_t_s_s((l_1325 = (((g_53 >= 0x04E391BAL) && l_1003[5]) , l_2149)), (l_480[7][2] = g_1669))) != ((0xF1L != ((((((l_2136 = (safe_add_func_int8_t_s_s((((safe_unary_minus_func_int8_t_s((safe_add_func_int8_t_s_s((l_1686[0] = (safe_lshift_func_int16_t_s_u((((safe_mod_func_uint16_t_u_u(l_2221[4][0][3], g_427[1])) , g_185[0][7][2]) && 8UL), 9))), g_1045)))) && 0x89L) , l_2115[4][0]), 0UL))) ^ p_66) , p_65) , 9L) & 0x8FL) > g_692)) >= g_34[4])) && g_2222) , p_66)) != l_2221[8][1][0]) , 1L) & l_2103[6][3]), (-1L))) & p_66) , (-1L));
                    }
                }
                else
                {
                    uint16_t l_2229 = 6UL;
                    int32_t l_2230[3][5][6] = {{{0xACB876FBL,1L,0xADF48121L,0xACB876FBL,1L,0x13C78112L},{0x875BBDD9L,0xACB876FBL,0x137BD6D1L,0xACB876FBL,0x875BBDD9L,(-1L)},{0xACB876FBL,0x875BBDD9L,(-1L),(-1L),0x875BBDD9L,7L},{1L,0xACB876FBL,1L,0x875BBDD9L,1L,7L},{1L,1L,(-1L),0xB7A4898CL,0xB7A4898CL,(-1L)}},{{1L,1L,0x137BD6D1L,0xB46C0946L,(-5L),(-1L)},{0xF0943486L,3L,0x875BBDD9L,0x58F0F2B0L,1L,1L},{0x04F30244L,0xF0943486L,0x875BBDD9L,0x04F30244L,3L,(-1L)},{0xB46C0946L,0x04F30244L,1L,0x04F30244L,0xB46C0946L,0xB7A4898CL},{0x04F30244L,0xB46C0946L,0xB7A4898CL,0x58F0F2B0L,0xB46C0946L,1L}},{{0xF0943486L,0x04F30244L,(-2L),0xB46C0946L,3L,1L},{3L,0xF0943486L,0xB7A4898CL,1L,1L,0xB7A4898CL},{3L,3L,1L,0xB46C0946L,(-5L),(-1L)},{0xF0943486L,3L,0x875BBDD9L,0x58F0F2B0L,1L,1L},{0x04F30244L,0xF0943486L,0x875BBDD9L,0x04F30244L,3L,(-1L)}}};
                    int i, j, k;
                    if ((g_897[1][2] = 0xB514014BL))
                    {
                        if (l_2177)
                            break;
                    }
                    else
                    {
                        return l_1022[0];
                    }
                    if (((((g_897[0][0] = (((safe_sub_func_int16_t_s_s(((g_298 = 0xFD84L) < (p_65 > g_693[0])), (safe_add_func_int16_t_s_s(0xB154L, (l_2230[1][1][2] = (g_972 , (((-9L) < (l_2229 = (safe_lshift_func_int8_t_s_s(l_1746[0], 7)))) == (l_2230[1][1][2] < g_1472)))))))) < g_566) | g_486)) >= 4UL) < 4294967286UL) == 0UL))
                    {
                        return g_503;
                    }
                    else
                    {
                        uint16_t l_2247 = 0x2E39L;
                        p_65 = (p_65 == (l_2238 = (((l_2177 = g_897[0][1]) <= (((g_276 = ((g_86 = p_65) , ((((l_2230[1][1][2] = (safe_unary_minus_func_int16_t_s(((65527UL == l_2230[1][1][2]) & (safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(65531UL, 15)), g_2236[1])))))) > (0L | l_2237)) , 0xC1L) != 248UL))) & p_66) < p_66)) > 247UL)));
                        l_2110[1] = (((((safe_add_func_int32_t_s_s(((((safe_rshift_func_int16_t_s_u((g_2236[2] && (((g_2222 = (((l_2177 < ((p_65 < ((safe_add_func_uint16_t_u_u((((safe_lshift_func_uint16_t_u_s(p_66, l_1790)) < p_65) != l_896), 0x924DL)) < (0x7013L < g_27[2][0]))) == l_638)) || l_2115[4][0]) || 0x2DL)) , 5L) > l_2149)), 7)) , l_2247) == p_65) != g_5), 0x0CEFAB25L)) <= 0x37CB769EL) , l_2230[1][1][2]) < 0xF452L) == g_250[0][3]);
                    }
                }
            }
            else
            {
                int16_t l_2252 = (-1L);
                g_897[0][1] = (safe_mod_func_uint16_t_u_u((l_1686[2] = (safe_rshift_func_int8_t_s_s((((((l_1790 = l_2252) > (!((safe_sub_func_uint8_t_u_u(l_1787, (safe_sub_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((0x68L && (((((p_65 <= (g_183[9] = (+((safe_add_func_uint8_t_u_u(l_2252, (safe_rshift_func_int16_t_s_s(((safe_add_func_int8_t_s_s((+(g_1044 = p_65)), (g_247 == (safe_mod_func_uint8_t_u_u((((g_427[0] , g_32[6][1]) , p_65) == g_27[2][0]), 0x27L))))) & (-10L)), 10)))) > g_250[0][3])))) | l_1787) <= g_276) && 6UL) && 0x7218B8CBL)), 0UL)), 0x44C1133AL)))) , g_2236[1]))) > g_897[1][1]) < g_503) && 0xD0C0L), 5))), 0x9944L));
                g_2236[0] = p_66;
                l_480[6][0] = ((0x4370566CL & 0x0ED557DCL) | (safe_lshift_func_int16_t_s_u(((g_693[1] = (safe_rshift_func_int8_t_s_u(l_2149, ((((p_65 | ((g_486 < ((((0x6317L <= ((safe_lshift_func_uint16_t_u_u(p_65, 15)) <= (safe_mod_func_int16_t_s_s((((safe_sub_func_uint32_t_u_u(g_127, (safe_sub_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_u(((((-5L) == l_2288) , 0x4F3DC1A8L) ^ (-6L)), l_1467[0][2][4])) & l_2252) | p_65) ^ g_456), l_2289)))) == g_183[9]) & 0x0C297A05L), 0x03F9L)))) > l_2289) ^ g_317) >= 0xEAD1L)) , 0xFAL)) && l_467[1][0][4]) | g_344) && 0x7D9FL)))) , p_66), g_344)));
            }
            p_65 = (safe_rshift_func_int16_t_s_s((!1L), p_65));
        }
        else
        {
            uint16_t l_2306 = 0UL;
            uint8_t l_2354 = 251UL;
            for (g_1138 = 5; (g_1138 > (-18)); g_1138--)
            {
                int32_t l_2297 = 0x01356E94L;
                int16_t l_2305 = (-8L);
                g_2236[1] = ((((safe_add_func_uint8_t_u_u(l_484, l_2149)) & l_2297) , ((safe_rshift_func_uint8_t_u_s(p_66, 4)) , l_2297)) , ((safe_rshift_func_uint16_t_u_u(((l_2305 = (safe_add_func_int8_t_s_s(((l_1003[5] = p_66) < l_2304), ((g_1472 = l_1787) , (((l_2297 == g_1328) >= g_203) & 9UL))))) || g_27[0][0]), l_2306)) & l_2297));
            }
            g_897[0][2] = (safe_rshift_func_int16_t_s_s(0x2DA4L, 11));
            for (g_639 = 0; (g_639 <= 0); g_639 += 1)
            {
                int32_t l_2327 = 0L;
                int i;
                g_2236[2] = (p_65 = (((safe_add_func_uint8_t_u_u((((0x0C5DL == (safe_mod_func_int32_t_s_s(l_1746[g_639], 4294967287UL))) , (safe_mod_func_int32_t_s_s(((((251UL != (0UL == 0xFFA6D013L)) > (safe_lshift_func_int8_t_s_s((((p_66 , p_66) > ((g_183[9] , l_2306) | 6UL)) && g_32[0][0]), l_1788))) , g_247) && l_1746[g_639]), p_65))) | g_1328), 7L)) , p_65) <= g_53));
                p_65 = (g_1328 , ((p_65 & (safe_lshift_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_u(((g_33 = ((((((((safe_sub_func_uint8_t_u_u(((((safe_rshift_func_int8_t_s_u((((g_400 & (((0xB6L != (((g_250[0][1] || (safe_lshift_func_uint16_t_u_u((l_2327 = l_2289), 15))) >= l_1746[g_639]) <= (l_1790 = (l_2306 != g_639)))) >= 252UL) > (-3L))) >= g_34[8]) , l_1790), 7)) , 0x38B8EBF5L) ^ 4UL) ^ 0xA3L), 2UL)) | g_1044) >= g_183[7]) >= 0L) || g_2084) < g_32[1][0]) <= 0x85L) ^ l_1746[g_639])) & 0xEC876E2FL), g_1363)) ^ l_2289) && p_66), 5))) > l_2289));
                if (l_1003[8])
                    break;
                for (g_449 = 0; (g_449 <= 0); g_449 += 1)
                {
                    uint8_t l_2401 = 0UL;
                    int32_t l_2410 = (-1L);
                    int i, j, k;
                    if ((safe_sub_func_uint8_t_u_u(l_1467[g_639][(g_449 + 4)][(g_639 + 3)], (g_639 , ((safe_add_func_int16_t_s_s((g_27[g_639][g_639] = (safe_add_func_int8_t_s_s((((((((safe_rshift_func_int8_t_s_s(g_1328, 3)) == (l_1467[g_639][(g_449 + 4)][(g_639 + 3)] <= l_1467[g_639][(g_449 + 4)][(g_639 + 3)])) ^ l_1790) != (((((!(g_127 == (g_391 = (((safe_unary_minus_func_uint32_t_u(p_66)) ^ (g_250[0][1] > 7L)) | 0x384B2D5BL)))) | l_2306) && 0x5FE3L) >= 0xA0380A68L) >= l_1467[g_639][(g_449 + 4)][(g_639 + 3)])) < g_32[1][0]) <= g_126) ^ g_298), l_1746[g_639]))), p_66)) , p_66)))))
                    {
                        uint32_t l_2344 = 0xBFCE861EL;
                        g_2236[4] = (l_1790 = (((1UL > ((g_504[2][4][0] = (safe_sub_func_uint32_t_u_u(l_2306, 0x3C949A95L))) , (((g_185[0][6][1] = ((safe_add_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(l_2344, (4294967295UL >= 0L))), (+1UL))) && (safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(((0L >= l_2344) , 0x16FFL), 0xF965L)), 10)) & l_2354), 0)) && 1L), p_66)))) , p_65) <= p_65))) <= 1L) ^ 0x01L));
                        p_65 = (safe_mod_func_int32_t_s_s(g_504[1][0][0], (safe_mod_func_int32_t_s_s((l_2359 <= (0x0CE65A3EL < (safe_rshift_func_int16_t_s_s(l_2149, ((safe_mod_func_int16_t_s_s((((l_2354 >= ((p_66 , (p_65 < (p_65 , ((g_33 = 0x8FDC2FD0L) < g_391)))) , l_1635)) || l_1467[0][0][0]) && 0x75B9B243L), g_315)) || g_1138))))), p_65))));
                    }
                    else
                    {
                        uint8_t l_2378 = 0UL;
                        p_65 = ((((((safe_add_func_uint8_t_u_u(1UL, (g_35 = p_66))) != (0xD2D1L <= 1UL)) ^ ((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((((((p_65 != (((l_1861 ^ ((((safe_mod_func_int8_t_s_s((g_127 <= (l_1790 = (g_769 , ((~((l_1787 , 0xF1L) , l_2354)) || g_32[7][1])))), l_2377)) < 0x48L) & g_693[1]) && p_66)) < l_2378) != 2L)) > (-6L)) | 3UL) == l_1467[g_639][(g_449 + 4)][(g_639 + 3)]) || p_66), 9)), 1)), p_66)), g_456)) > p_65)) < l_2306) , p_65) || g_108);
                        l_1790 = (g_972 < (((4L <= (~g_183[9])) & (g_185[0][6][1] = (safe_unary_minus_func_int8_t_s(((l_2378 == (((safe_add_func_int8_t_s_s(((safe_unary_minus_func_int8_t_s((safe_mod_func_int32_t_s_s((l_1004[4] = (((((safe_add_func_int32_t_s_s((((((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_lshift_func_int16_t_s_s((+(safe_sub_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s((-2L), l_2354)) < l_2378), (65535UL & g_27[g_639][g_639])))), 7)) & 3UL) <= 0UL), g_34[2])), l_1746[g_639])) < l_1746[0]) ^ 6UL) <= g_2236[1]) ^ g_34[5]), p_65)) > l_2401) <= 0L) != g_27[g_639][g_639]) && 0x8DF4759FL)), p_65)))) < l_2402), g_504[1][1][2])) & g_2222) < g_693[1])) >= 0xD3L))))) & l_2327));
                        return g_693[1];
                    }
                    l_2410 = ((safe_add_func_int8_t_s_s(0xDCL, 0x83L)) | (l_1790 < ((((safe_sub_func_int32_t_s_s((+l_2401), ((((0x15L > ((0x1C71D6D0L || p_65) | (((safe_lshift_func_int8_t_s_u(g_1001, g_1669)) || g_53) , p_65))) || g_250[0][1]) < l_2354) == g_185[0][6][1]))) >= 0x46L) & p_65) & 0xABD8L)));
                }
            }
            for (l_2402 = 0; (l_2402 > 30); l_2402++)
            {
                int32_t l_2426 = 0x6C7CA9D2L;
                uint16_t l_2429 = 65526UL;
                if (l_1788)
                    break;
                g_2236[2] = ((safe_lshift_func_int8_t_s_s(p_66, (((p_65 == ((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((safe_unary_minus_func_uint8_t_u(l_1467[0][0][3])), 0)), p_65)) | (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((0x13L >= (3UL | (p_66 && (((safe_mod_func_uint8_t_u_u(6UL, (l_1790 = (g_577 & 0x4075E619L)))) && g_456) >= l_2426)))) >= g_32[1][0]), l_2354)), p_66)))) != p_66) ^ 4294967295UL))) , (-1L));
                for (l_1788 = (-11); (l_1788 < (-23)); --l_1788)
                {
                    return l_2429;
                }
                for (g_33 = 0; (g_33 <= 22); g_33 = safe_add_func_int8_t_s_s(g_33, 9))
                {
                    int32_t l_2432 = 0x0CC37EA6L;
                    l_2432 = (-1L);
                }
            }
        }
        l_2003 = (((p_66 = (l_2433 < (safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((l_1790 = ((safe_lshift_func_int8_t_s_s((0x16BF8F3DL || p_65), 6)) != (g_820 == 0x7AL))), l_2289)), (((safe_mod_func_int16_t_s_s(p_65, (safe_sub_func_int16_t_s_s((((((p_66 == (l_1788 = (((safe_unary_minus_func_uint8_t_u((safe_add_func_uint16_t_u_u(0x6440L, g_2222)))) , l_1283) | 0L))) || l_2377) || l_1788) & g_820) >= g_315), p_66)))) <= l_2433) < p_66))))) & g_692) || p_65);
    }
    return p_66;
}







inline static int32_t func_70(int16_t p_71, uint8_t p_72)
{
    int32_t l_87 = 1L;
    int32_t l_110 = 0x9DAAC0CAL;
    uint16_t l_144 = 0UL;
    int32_t l_178 = 4L;
    uint8_t l_242 = 0x27L;
    uint32_t l_275 = 4294967289UL;
    uint32_t l_316[10] = {0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL,0xB55CD4BFL};
    uint16_t l_345 = 9UL;
    int i;
lbl_184:
    for (g_33 = 0; (g_33 > 34); g_33 = safe_add_func_uint8_t_u_u(g_33, 4))
    {
        int32_t l_109 = (-7L);
        int32_t l_125[3][3][5] = {{{0x48D7F838L,0x9FC80027L,0x9FC80027L,0x48D7F838L,0x9FC80027L},{0xE99C33BCL,0xE99C33BCL,0x22964CB1L,0xE99C33BCL,0xE99C33BCL},{0x9FC80027L,0x48D7F838L,0x9FC80027L,0x9FC80027L,0x48D7F838L}},{{0xE99C33BCL,0xA0F805AAL,0xA0F805AAL,0xE99C33BCL,0xA0F805AAL},{0x48D7F838L,0x48D7F838L,0x627CDBDBL,0x48D7F838L,0x48D7F838L},{0xA0F805AAL,0xE99C33BCL,0xA0F805AAL,0xA0F805AAL,0xE99C33BCL}},{{0x48D7F838L,0x9FC80027L,0x9FC80027L,0x48D7F838L,0x9FC80027L},{0xE99C33BCL,0xE99C33BCL,0x22964CB1L,0xE99C33BCL,0xE99C33BCL},{0x9FC80027L,0x48D7F838L,0x9FC80027L,0x9FC80027L,0x48D7F838L}}};
        int i, j, k;
        g_86 = (-1L);
        l_110 = (((((g_44 > 0x5DB5E494L) <= 0xE2D2L) || (((l_87 && (+(((safe_sub_func_int16_t_s_s(((safe_mod_func_int8_t_s_s((((safe_mod_func_int16_t_s_s((safe_mod_func_int8_t_s_s((((((safe_add_func_uint16_t_u_u((~l_87), (safe_sub_func_int32_t_s_s(p_72, (g_86 = 2UL))))) < (g_108 = (((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u(p_71, g_35)) , 0x023AL), 11)) < 0xE0EEEF66L) != p_72))) != 0xD055L) != 0UL) , l_87), l_109)), g_34[4])) <= g_34[5]) , g_5), 0x23L)) > (-9L)), l_109)) || g_34[9]) != p_72))) | p_72) <= g_32[1][0])) != g_5) < 0xD54CL);
        for (l_109 = 0; (l_109 <= 1); l_109 += 1)
        {
            int i, j;
            g_127 = ((((-1L) ^ ((g_34[(l_109 + 1)] ^ g_32[l_109][l_109]) , (((l_125[1][2][3] = ((safe_sub_func_int8_t_s_s((g_32[0][0] || ((!((((safe_add_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(l_109, ((safe_add_func_int16_t_s_s(8L, (!((l_110 = 1UL) && (safe_rshift_func_uint8_t_u_u((g_32[l_109][l_109] >= (g_86 = (safe_add_func_uint32_t_u_u((((((l_87 != g_35) ^ 0xBDL) , (-1L)) , p_72) & p_71), l_109)))), p_72)))))) >= p_71))) || l_87), g_33)) >= l_109) , l_109) < p_72)) ^ g_108)), 0x54L)) , l_87)) & p_72) != 0x9FC4A87EL))) , g_126) & 0x43L);
            return l_110;
        }
    }
    for (g_35 = 7; (g_35 != 45); g_35 = safe_add_func_int16_t_s_s(g_35, 5))
    {
        uint8_t l_130 = 0x41L;
        int32_t l_131 = 0xDFEA10F5L;
        uint16_t l_143[4] = {65535UL,65535UL,65535UL,65535UL};
        uint32_t l_239 = 0UL;
        int i;
        l_131 = l_130;
        g_132 = (g_53 | ((l_131 = 0xDE0CL) || g_34[5]));
        for (l_110 = 0; (l_110 == (-10)); l_110 = safe_sub_func_int16_t_s_s(l_110, 3))
        {
            uint16_t l_162 = 0x4120L;
            int32_t l_198[10];
            int32_t l_201 = (-1L);
            int16_t l_224 = 9L;
            int i;
            for (i = 0; i < 10; i++)
                l_198[i] = (-7L);
            for (g_127 = 0; (g_127 <= 1); g_127 += 1)
            {
                uint8_t l_161[9][7][4] = {{{0x40L,0xCEL,0x40L,0x16L},{246UL,1UL,0x11L,0x46L},{0x21L,246UL,0x16L,1UL},{0x90L,0x1EL,0x16L,0xEEL},{0x21L,0x11L,0x11L,0x21L},{246UL,0x90L,0x40L,0x83L},{0x40L,0x83L,1UL,0x1EL}},{{0x97L,0x5DL,0UL,0x1EL},{0x46L,0x83L,0x97L,0x83L},{0x37L,0x90L,0xCEL,0x21L},{1UL,0x11L,0x46L,0xEEL},{0x5DL,0x1EL,0xEEL,1UL},{0x5DL,246UL,0x46L,0x46L},{1UL,1UL,0xCEL,0x16L}},{{0x37L,0xCEL,0x97L,0x90L},{0x46L,0x40L,0UL,0x97L},{0x97L,0x40L,1UL,0x90L},{0x40L,0xCEL,0x40L,0x16L},{246UL,1UL,0UL,0x40L},{0x37L,0x11L,246UL,0x97L},{0x21L,0x5DL,246UL,0x46L}},{{0x37L,0UL,0UL,0x37L},{0x11L,0x21L,0UL,1UL},{0UL,1UL,0x97L,0x5DL},{0x90L,0x83L,0xEEL,0x5DL},{0x40L,1UL,0x90L,1UL},{0x16L,0x21L,0x1EL,0x37L},{0x97L,0UL,0x40L,0x46L}},{{0x83L,0x5DL,0x46L,0x97L},{0x83L,0x11L,0x40L,0x40L},{0x97L,0x97L,0x1EL,246UL},{0x16L,0x1EL,0x90L,0x21L},{0x40L,0UL,0xEEL,0x90L},{0x90L,0UL,0x97L,0x21L},{0UL,0x1EL,0UL,246UL}},{{0x11L,0x97L,0UL,0x40L},{0x37L,0x11L,246UL,0x97L},{0x21L,0x5DL,246UL,0x46L},{0x37L,0UL,0UL,0x37L},{0x11L,0x21L,0UL,1UL},{0UL,1UL,0x97L,0x5DL},{0x90L,0x83L,0xEEL,0x5DL}},{{0x40L,1UL,0x90L,1UL},{0x16L,0x21L,0x1EL,0x37L},{0x97L,0UL,0x40L,0x46L},{0x83L,0x5DL,0x46L,0x97L},{0x83L,0x11L,0x40L,0x40L},{0x97L,0x97L,0x1EL,246UL},{0x16L,0x1EL,0x90L,0x21L}},{{0x40L,0UL,0xEEL,0x90L},{0x90L,0UL,0x97L,0x21L},{0UL,0x1EL,0UL,246UL},{0x11L,0x97L,0UL,0x40L},{0x37L,0x11L,246UL,0x97L},{0x21L,0x5DL,246UL,0x46L},{0x37L,0UL,0UL,0x37L}},{{0x11L,0x21L,0UL,1UL},{0UL,1UL,0x97L,0x5DL},{0x90L,0x83L,0xEEL,0x5DL},{0x40L,1UL,0x90L,1UL},{0x16L,0x21L,0x1EL,0x37L},{0x97L,0UL,0x40L,0x46L},{0x83L,0x5DL,0x46L,0x97L}}};
                int32_t l_175[1];
                int8_t l_235 = 0xF2L;
                int i, j, k;
                for (i = 0; i < 1; i++)
                    l_175[i] = 0xEAE50A2DL;
                if (((((((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s(0L, ((safe_mod_func_uint16_t_u_u(g_32[(g_127 + 2)][g_127], l_143[1])) >= g_5))), 3)) < (l_144 >= (safe_lshift_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((safe_add_func_uint8_t_u_u((p_71 && ((((((safe_mod_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(g_35, (safe_rshift_func_int16_t_s_u(1L, g_32[1][0])))) , l_130), p_72)) , 1L) == g_34[7]) , g_32[7][0]) < l_161[0][2][3]) && p_71)), p_72)), g_34[5])), 0x3B3CL)), 0x6AL)) > l_87), 1)))), p_71)) != 0x7FL) >= l_162) , 65526UL) > g_32[(g_127 + 2)][g_127]) != 0x06D6L))
                {
                    l_131 = l_87;
                }
                else
                {
                    int16_t l_177 = (-10L);
                    for (g_108 = 0; (g_108 <= 1); g_108 += 1)
                    {
                        uint8_t l_174 = 254UL;
                        int32_t l_176 = 0x0E7BB6F3L;
                        g_183[9] = (safe_mod_func_uint16_t_u_u(((p_72 , ((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(0xDA66L, 7)), (safe_lshift_func_uint8_t_u_u((7L && ((l_178 = (safe_unary_minus_func_int8_t_s((0x642E7455L == (safe_unary_minus_func_uint32_t_u((g_86 = (+((l_174 , (l_176 = (l_175[0] = l_144))) , l_177))))))))) ^ (((safe_add_func_int16_t_s_s((((safe_sub_func_int32_t_s_s(((g_5 , (g_127 == (-7L))) <= 2UL), g_34[4])) > g_35) > p_72), 0x30FBL)) , 0x5094A51AL) ^ g_34[5]))), 4)))) || 3UL)) , p_72), p_71));
                        if (g_5)
                            continue;
                        if (g_5)
                            goto lbl_184;
                    }
                    g_185[0][6][1] = (g_34[5] >= l_87);
                }
                for (l_162 = 0; (l_162 <= 1); l_162 += 1)
                {
                    int16_t l_202 = (-6L);
                    int32_t l_236 = 0xF93AD4E5L;
                    for (l_131 = 0; (l_131 <= 1); l_131 += 1)
                    {
                        return g_126;
                    }
                    if ((safe_add_func_int8_t_s_s((p_72 & (safe_sub_func_int8_t_s_s((p_72 , (l_202 = (safe_lshift_func_int8_t_s_s((((safe_add_func_int16_t_s_s(l_144, 1L)) != (l_130 , ((safe_lshift_func_uint16_t_u_s((l_198[6] = g_183[9]), p_72)) > (safe_unary_minus_func_int8_t_s(p_71))))) & (((l_201 = ((safe_unary_minus_func_uint8_t_u(0x86L)) <= 0xAFL)) == p_71) <= l_144)), l_87)))), g_126))), 0x46L)))
                    {
                        uint32_t l_206[7];
                        int i;
                        for (i = 0; i < 7; i++)
                            l_206[i] = 0x2935077AL;
                        g_203 = (l_175[0] = (-1L));
                        l_206[4] = (safe_mod_func_uint16_t_u_u(((0x78527E74L > (l_198[3] = l_110)) >= 4294967295UL), l_143[1]));
                    }
                    else
                    {
                        uint32_t l_217 = 0x71EFC389L;
                        int32_t l_218 = 0x5E6A16A9L;
                        uint32_t l_223[8];
                        int i;
                        for (i = 0; i < 8; i++)
                            l_223[i] = 0xBA6CA5C4L;
                        l_224 = (safe_add_func_uint16_t_u_u(((((safe_unary_minus_func_uint32_t_u(((safe_mod_func_uint16_t_u_u(((safe_unary_minus_func_int32_t_s((l_178 = p_71))) , l_202), (safe_lshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_u(g_44, 4)), 14)))) && ((l_217 = (p_71 = 1L)) < l_144)))) < (l_218 , (safe_sub_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u((p_72 >= 1L), ((l_110 , 0x673AC837L) , g_27[0][0]))) & l_223[4]), p_72)))) != g_27[0][0]) , p_72), l_223[4]));
                        l_236 = ((safe_unary_minus_func_int16_t_s((p_71 = 0x7158L))) ^ (safe_add_func_int8_t_s_s((safe_add_func_uint32_t_u_u((safe_sub_func_int32_t_s_s((l_131 = p_72), (safe_unary_minus_func_uint8_t_u(p_72)))), ((safe_sub_func_int32_t_s_s(0xD35E6B1BL, ((0x0C78L && ((p_72 ^ (l_198[2] = l_235)) , (((0x38ADL <= 4UL) > g_126) <= 0UL))) ^ 0xDAL))) & g_27[2][0]))), p_72)));
                    }
                    if ((l_224 >= (p_72 ^ ((g_203 = (safe_mod_func_uint16_t_u_u(p_71, p_72))) != l_236))))
                    {
                        if (g_32[(g_127 + 2)][g_127])
                            break;
                        l_198[1] = p_71;
                        if (g_108)
                            break;
                        return p_72;
                    }
                    else
                    {
                        return g_32[1][0];
                    }
                }
            }
        }
        l_178 = l_239;
    }
    if ((l_144 & (l_178 = ((l_178 , ((l_110 = (safe_sub_func_int8_t_s_s(((-10L) && ((g_53 >= l_87) > l_242)), (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint16_t_u_u((g_108 = g_126), g_32[1][0])), (((g_247 = l_242) > 0xFAAB16F6L) , l_144)))))) , g_27[2][0])) == p_72))))
    {
        int8_t l_274 = (-3L);
        int32_t l_297 = (-1L);
        int32_t l_358 = (-2L);
        int32_t l_426 = 0x5672A767L;
        for (l_110 = 12; (l_110 > 21); l_110 = safe_add_func_int32_t_s_s(l_110, 8))
        {
            uint32_t l_253 = 4294967290UL;
            g_250[0][1] = (65528UL < p_72);
            g_276 = (safe_sub_func_int8_t_s_s((g_34[5] = (l_253 >= (safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s((((0x90DAL & (((safe_lshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_u(p_72, (safe_add_func_int32_t_s_s(((((((65534UL || l_253) ^ (((safe_sub_func_int16_t_s_s(l_253, ((safe_add_func_uint8_t_u_u(g_34[5], g_33)) < (safe_lshift_func_uint16_t_u_s(0x66C8L, 7))))) != 65529UL) != p_72)) ^ p_72) >= l_274) || g_185[0][2][2]) < g_132), g_5)))), 7)) & 0x4B6CL) == p_71)) < 3UL) < l_275), g_247)), l_253)) >= 0x79L) > 0xD3L) > g_44), p_72)), 0)))), l_144));
            return p_72;
        }
        g_298 = ((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s((((safe_add_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u((l_297 = ((p_71 ^ ((safe_rshift_func_uint8_t_u_u(g_203, 1)) || (((safe_mod_func_int16_t_s_s(g_276, l_274)) | ((l_178 = (safe_sub_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u(g_35, (g_27[2][0] = p_72))) & (safe_lshift_func_uint16_t_u_u((l_87 < (g_132 = (((safe_sub_func_int16_t_s_s(0x2625L, (g_5 <= g_35))) , l_274) > 0x2CL))), 11))), g_44))) > 1UL)) , l_274))) > p_71)), 0UL)) > g_185[0][7][0]), 0x7DF0B75FL)) <= l_87) < g_250[0][1]), 8)) & 0x00E8L), 2)) > g_276);
        for (g_203 = 1; (g_203 >= 0); g_203 -= 1)
        {
            int32_t l_326 = 2L;
            int32_t l_346 = 0x4BFED72CL;
            int8_t l_388 = 9L;
            if (((safe_add_func_int32_t_s_s(p_72, (safe_rshift_func_int8_t_s_u((l_316[0] = ((g_108 = l_274) && ((p_71 > ((safe_mod_func_int16_t_s_s(((!(l_144 & p_71)) <= (+(safe_sub_func_uint32_t_u_u(l_87, (g_315 = ((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((0x67L == g_250[0][1]) && (p_71 , 4UL)), p_71)) || p_71) && l_87), l_297)), g_250[0][3])) != (-1L))))))), p_72)) & 65526UL)) < g_34[5]))), g_27[1][0])))) , p_72))
            {
                g_317 = g_32[8][0];
            }
            else
            {
                g_318 = 9L;
                if (l_110)
                    break;
            }
            l_346 = ((!(((safe_add_func_int16_t_s_s(((l_275 == (safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(((l_345 = (((l_326 ^ (safe_add_func_uint8_t_u_u(p_72, (safe_lshift_func_uint16_t_u_s((g_185[0][6][1] <= ((((((g_344 = (((~((l_297 = (g_298 = ((safe_rshift_func_uint16_t_u_s((safe_mod_func_int16_t_s_s((g_27[2][0] = (safe_lshift_func_int8_t_s_u(g_32[1][0], l_326))), ((((l_326 , ((!((g_132 = 0xF3L) < (((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_int16_t_s((((safe_sub_func_uint32_t_u_u(1UL, p_71)) , l_275) , p_72))), g_250[0][0])) | g_247) < p_72))) || g_34[9])) > g_298) < l_110) && g_126))), 14)) < p_72))) == l_110)) , p_72) <= g_203)) != p_72) ^ l_326) || 9L) , l_297) >= g_203)), g_183[9]))))) || g_127) && l_274)) | l_326), 1)), g_315))) | p_71), 5UL)) > p_72) | 0x73L)) , l_274);
            l_358 = (g_250[0][1] == (safe_lshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((g_27[0][0] = ((((safe_mod_func_int16_t_s_s(((((((l_110 = l_297) , (l_275 , ((l_297 = (+((safe_rshift_func_uint8_t_u_s(l_346, 3)) > ((0xB8L && (((safe_rshift_func_int16_t_s_s(0x2D6AL, 5)) <= ((((l_178 = (g_32[7][0] , p_71)) <= (p_72 = (l_110 = l_275))) ^ l_346) & p_71)) , 0x55L)) || l_297)))) , p_72))) == l_345) | l_326) >= p_71) | 0x4811L), g_34[5])) <= l_346) & (-5L)) == l_326)), 0x5F79L)) , p_72), 9)));
            for (g_86 = 0; (g_86 <= 1); g_86 += 1)
            {
                int32_t l_389 = 4L;
                uint16_t l_399[1][8] = {{0x55EEL,65535UL,0x55EEL,65535UL,0x55EEL,65535UL,0x55EEL,65535UL}};
                uint32_t l_420[4] = {0UL,0UL,0UL,0UL};
                int32_t l_423[6][4][10] = {{{(-10L),0x7E36CFAEL,0x1BDCFD5DL,0x7E36CFAEL,0x2BA6EB3FL,0xAF1D0D59L,(-1L),(-1L),(-4L),0xAF1D0D59L},{1L,0x7E36CFAEL,8L,0x93143B80L,1L,0xAF1D0D59L,0x2DAAF693L,0xDC7A7DE5L,0x2DAAF693L,0xAF1D0D59L},{0x2BA6EB3FL,0x93143B80L,0x1BDCFD5DL,0x93143B80L,0x2BA6EB3FL,0L,(-1L),0xDC7A7DE5L,(-4L),0L},{1L,0x93143B80L,8L,0x7E36CFAEL,1L,0L,0x2DAAF693L,(-1L),0x2DAAF693L,0L}},{{0x2BA6EB3FL,0x7E36CFAEL,0x1BDCFD5DL,0x7E36CFAEL,0x2BA6EB3FL,0xAF1D0D59L,(-1L),(-1L),(-4L),0xAF1D0D59L},{1L,0x7E36CFAEL,8L,0x93143B80L,1L,0xAF1D0D59L,0x2DAAF693L,0xDC7A7DE5L,0x2DAAF693L,0xAF1D0D59L},{0x2BA6EB3FL,0x93143B80L,0x1BDCFD5DL,0x93143B80L,0x2BA6EB3FL,0L,(-1L),0xDC7A7DE5L,(-4L),0L},{1L,0x93143B80L,8L,0x7E36CFAEL,1L,0L,0x2DAAF693L,(-1L),0x2DAAF693L,0L}},{{0x2BA6EB3FL,0x7E36CFAEL,0x1BDCFD5DL,0x7E36CFAEL,0x2BA6EB3FL,0xAF1D0D59L,(-1L),(-1L),(-4L),0xAF1D0D59L},{1L,0x7E36CFAEL,8L,0x93143B80L,1L,0xAF1D0D59L,0x2DAAF693L,0xDC7A7DE5L,0x2DAAF693L,0xAF1D0D59L},{0x2BA6EB3FL,0x93143B80L,0x1BDCFD5DL,0x93143B80L,0x2BA6EB3FL,0L,(-1L),0xDC7A7DE5L,(-4L),0L},{1L,0x93143B80L,8L,0x7E36CFAEL,1L,0L,0x2DAAF693L,(-1L),0x2DAAF693L,0L}},{{0x2BA6EB3FL,0x7E36CFAEL,0x1BDCFD5DL,0x7E36CFAEL,0x2BA6EB3FL,0xAF1D0D59L,(-1L),(-1L),(-4L),0xAF1D0D59L},{1L,0x7E36CFAEL,8L,0x93143B80L,1L,0xAF1D0D59L,0x2DAAF693L,0xDC7A7DE5L,0x2DAAF693L,0xAF1D0D59L},{0x2BA6EB3FL,0x93143B80L,0x1BDCFD5DL,0x93143B80L,0x2BA6EB3FL,0L,(-1L),0xDC7A7DE5L,(-4L),0L},{1L,0x93143B80L,8L,0x7E36CFAEL,1L,0L,0x2DAAF693L,(-1L),0x2DAAF693L,0L}},{{0x2BA6EB3FL,0x7E36CFAEL,0x1BDCFD5DL,0x7E36CFAEL,0x2BA6EB3FL,0xAF1D0D59L,(-1L),(-1L),(-4L),0xAF1D0D59L},{1L,0x7E36CFAEL,8L,0x93143B80L,1L,0xAF1D0D59L,0x2DAAF693L,0xDC7A7DE5L,0x2DAAF693L,0xAF1D0D59L},{0x2BA6EB3FL,0x93143B80L,0x1BDCFD5DL,0x93143B80L,0x2BA6EB3FL,0L,(-1L),0xDC7A7DE5L,(-4L),0L},{1L,0x93143B80L,(-3L),0xDF3716DEL,0x2DAAF693L,0x93143B80L,0xB86C75B8L,0x0F1A0B10L,0xB86C75B8L,0x93143B80L}},{{(-4L),0xDF3716DEL,4L,0xDF3716DEL,(-4L),0x7E36CFAEL,1L,0x0F1A0B10L,0xD5871B23L,0x7E36CFAEL},{0x2DAAF693L,0xDF3716DEL,(-3L),0xC4F02E37L,0x2DAAF693L,0x7E36CFAEL,0xB86C75B8L,0xFCBB7210L,0xB86C75B8L,0x7E36CFAEL},{(-4L),0xC4F02E37L,4L,0xC4F02E37L,(-4L),0x93143B80L,1L,0xFCBB7210L,0xD5871B23L,0x93143B80L},{0x2DAAF693L,0xC4F02E37L,(-3L),0xDF3716DEL,0x2DAAF693L,0x93143B80L,0xB86C75B8L,0x0F1A0B10L,0xB86C75B8L,0x93143B80L}}};
                int32_t l_425 = (-4L);
                int i, j, k;
                l_346 = ((g_53 = l_326) && (safe_sub_func_int8_t_s_s((safe_sub_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s((g_250[0][3] < (((((((safe_rshift_func_uint16_t_u_u((4UL & (safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_u(0UL, ((safe_lshift_func_uint8_t_u_u(((((((((safe_mod_func_int32_t_s_s(p_71, 1L)) < (p_71 , (((g_34[5] = (safe_lshift_func_int16_t_s_s((!(l_110 = (!(safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((((~(safe_lshift_func_int16_t_s_s(g_247, (p_72 >= p_71)))) , l_388) , 0L), g_35)) , p_71), 0))))), 15))) & g_127) && l_389))) <= 0x6592A202L) || 6UL) , 0xB6D2DAACL) < 4294967287UL) | l_346) , g_44), l_326)) >= g_5))) > g_132) && l_274), g_185[0][6][1])), l_326))), g_317)) > g_35) > p_72) > p_72) , (-1L)) || 255UL) & 0xF0976038L)), p_72)), 1L)), l_345)));
                for (g_108 = 0; (g_108 <= 1); g_108 += 1)
                {
                    int32_t l_390 = 0xE762944AL;
                    int32_t l_401 = 0xA4694767L;
                    int i, j, k;
                    g_391 = (l_390 = g_185[g_203][(g_108 + 4)][g_108]);
                    l_401 = (l_178 = (((l_390 = ((safe_mod_func_uint32_t_u_u((((((0x219DL >= (g_250[0][1] && ((safe_add_func_uint32_t_u_u(((p_71 , ((((1L < (((+(safe_add_func_uint16_t_u_u(g_27[2][0], l_178))) , p_72) == (((p_71 , (l_346 = (((((((((g_185[g_203][(g_108 + 5)][g_86] = (65529UL || g_27[2][0])) ^ 1UL) | l_274) > p_72) & 0xA179D6CEL) || g_86) && p_72) >= 1L) < (-1L)))) & 0xAE8BL) && l_389))) == l_399[0][3]) ^ l_316[0]) , 0UL)) >= 0x63A6L), g_400)) <= 0xD652D0F0L))) ^ 4294967291UL) ^ p_72) && l_110) >= l_388), 0x895A3996L)) && p_71)) || 9UL) & g_33));
                    if (g_250[0][1])
                        continue;
                    for (p_72 = 0; (p_72 <= 1); p_72 += 1)
                    {
                        int16_t l_421 = (-1L);
                        int32_t l_422 = 0x48A7D601L;
                        int32_t l_424 = 0x8DE58FF8L;
                        l_426 = (safe_sub_func_int32_t_s_s(g_298, (l_425 = (safe_lshift_func_int16_t_s_u((safe_lshift_func_uint8_t_u_u((safe_unary_minus_func_int32_t_s(((safe_lshift_func_int8_t_s_u((g_315 | (l_424 = ((p_71 , ((l_358 = l_345) >= (l_297 = (l_423[0][0][7] = (g_276 = (safe_add_func_int8_t_s_s((l_422 = (l_389 = (safe_rshift_func_uint16_t_u_s(((((p_72 ^ 0UL) , g_44) && (((safe_mod_func_uint8_t_u_u((((g_400 = (((-5L) ^ (safe_lshift_func_int16_t_s_u(1L, g_419))) , 0xDFE0L)) < g_185[0][6][1]) > 251UL), 0x23L)) || l_420[1]) || l_390)) <= 0x90E6L), l_421)))), p_72))))))) , l_422))), l_399[0][5])) ^ g_419))), 7)), 4)))));
                    }
                }
                if (g_27[2][0])
                    continue;
                for (l_178 = 0; (l_178 <= 1); l_178 += 1)
                {
                    g_427[1] = g_32[1][0];
                }
            }
            for (l_275 = 0; (l_275 <= 1); l_275 += 1)
            {
                int32_t l_428[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_428[i] = 0x77D689E2L;
                l_428[1] = l_388;
                for (g_35 = 0; (g_35 <= 1); g_35 += 1)
                {
                    return p_71;
                }
            }
        }
        g_449 = (((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_mod_func_uint32_t_u_u(l_87, l_144)) && 0x47D4B7D2L), (safe_lshift_func_uint16_t_u_s((l_178 <= (l_426 >= p_72)), 12)))), ((safe_add_func_uint32_t_u_u(0xF8B27D58L, (safe_rshift_func_int16_t_s_u(((((g_86 > (safe_rshift_func_int16_t_s_s((-4L), g_427[1]))) && p_71) , g_317) | 0xF81DL), 6)))) & l_426))) <= g_27[2][0]), g_250[0][1])), g_183[4])), g_44)) , 8UL) & 0xDB72L);
    }
    else
    {
        uint32_t l_455 = 5UL;
        g_456 = (safe_sub_func_int8_t_s_s((((((g_185[0][5][2] > g_5) | g_126) & ((((((g_185[0][4][2] || ((safe_rshift_func_uint16_t_u_u((((safe_unary_minus_func_uint16_t_u(1UL)) < ((0UL && (((p_71 = (-5L)) > p_72) || (g_298 == p_71))) > 1UL)) , 0x768BL), l_455)) >= g_276)) > (-1L)) & l_316[0]) != l_455) | 65535UL) < g_250[0][4])) || l_345) <= g_108), g_449));
    }
    return g_315;
}





int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_5, "g_5", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
        {
            transparent_crc(g_27[i][j], "g_27[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_32[i][j], "g_32[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_33, "g_33", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        transparent_crc(g_34[i], "g_34[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_35, "g_35", print_hash_value);
    transparent_crc(g_44, "g_44", print_hash_value);
    transparent_crc(g_53, "g_53", print_hash_value);
    transparent_crc(g_86, "g_86", print_hash_value);
    transparent_crc(g_108, "g_108", print_hash_value);
    transparent_crc(g_126, "g_126", print_hash_value);
    transparent_crc(g_127, "g_127", print_hash_value);
    transparent_crc(g_132, "g_132", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        transparent_crc(g_183[i], "g_183[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_185[i][j][k], "g_185[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_203, "g_203", print_hash_value);
    transparent_crc(g_247, "g_247", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_250[i][j], "g_250[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_276, "g_276", print_hash_value);
    transparent_crc(g_298, "g_298", print_hash_value);
    transparent_crc(g_315, "g_315", print_hash_value);
    transparent_crc(g_317, "g_317", print_hash_value);
    transparent_crc(g_318, "g_318", print_hash_value);
    transparent_crc(g_344, "g_344", print_hash_value);
    transparent_crc(g_391, "g_391", print_hash_value);
    transparent_crc(g_400, "g_400", print_hash_value);
    transparent_crc(g_419, "g_419", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_427[i], "g_427[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_449, "g_449", print_hash_value);
    transparent_crc(g_456, "g_456", print_hash_value);
    transparent_crc(g_486, "g_486", print_hash_value);
    transparent_crc(g_499, "g_499", print_hash_value);
    transparent_crc(g_503, "g_503", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_504[i][j][k], "g_504[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_566, "g_566", print_hash_value);
    transparent_crc(g_577, "g_577", print_hash_value);
    transparent_crc(g_639, "g_639", print_hash_value);
    transparent_crc(g_692, "g_692", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        transparent_crc(g_693[i], "g_693[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_739, "g_739", print_hash_value);
    transparent_crc(g_769, "g_769", print_hash_value);
    transparent_crc(g_820, "g_820", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_897[i][j], "g_897[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 9; k++)
            {
                transparent_crc(g_918[i][j][k], "g_918[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_972, "g_972", print_hash_value);
    transparent_crc(g_1001, "g_1001", print_hash_value);
    transparent_crc(g_1044, "g_1044", print_hash_value);
    transparent_crc(g_1045, "g_1045", print_hash_value);
    transparent_crc(g_1138, "g_1138", print_hash_value);
    transparent_crc(g_1328, "g_1328", print_hash_value);
    transparent_crc(g_1357, "g_1357", print_hash_value);
    transparent_crc(g_1363, "g_1363", print_hash_value);
    transparent_crc(g_1472, "g_1472", print_hash_value);
    transparent_crc(g_1669, "g_1669", print_hash_value);
    transparent_crc(g_2084, "g_2084", print_hash_value);
    transparent_crc(g_2222, "g_2222", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_2236[i], "g_2236[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_2610, "g_2610", print_hash_value);
    transparent_crc(g_2674, "g_2674", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_2729[i][j], "g_2729[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2942, "g_2942", print_hash_value);
    transparent_crc(g_3003, "g_3003", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_3045[i][j], "g_3045[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 2; k++)
            {
                transparent_crc(g_3159[i][j][k], "g_3159[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_3782, "g_3782", print_hash_value);
    transparent_crc(g_3901, "g_3901", print_hash_value);
    transparent_crc(g_3903, "g_3903", print_hash_value);
    transparent_crc(g_4123, "g_4123", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
