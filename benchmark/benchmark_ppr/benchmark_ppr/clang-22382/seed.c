#include <float.h>
#include <math.h>
#include <string.h>

#include <limits.h>

#include <stdint.h>

#include <assert.h>
#include <stdio.h>

static void platform_main_begin(void) {}

static void platform_main_end(uint32_t crc, int flag) {

  printf("checksum = %X\n", crc);
}
static int8_t(safe_unary_minus_func_int8_t_s)(int8_t si) {

  return

      (si == INT8_MIN) ? ((si)) :

                       -si;
}

static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT8_MAX - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < (INT8_MIN - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~INT8_MAX))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int8_t(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT8_MAX / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < (INT8_MIN / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < (INT8_MIN / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT8_MAX / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int8_t(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      ((si2 == 0) || ((si1 == INT8_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                           (si1 % si2);
}

static int8_t(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      ((si2 == 0) || ((si1 == INT8_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                           (si1 / si2);
}

static int8_t(safe_lshift_func_int8_t_s_s)(int8_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > (INT8_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int8_t(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > (INT8_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int8_t(safe_rshift_func_int8_t_s_s)(int8_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int8_t(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int16_t(safe_unary_minus_func_int16_t_s)(int16_t si) {

  return

      (si == INT16_MIN) ? ((si)) :

                        -si;
}

static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT16_MAX - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < (INT16_MIN - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int16_t(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~INT16_MAX))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int16_t(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT16_MAX / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < (INT16_MIN / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < (INT16_MIN / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT16_MAX / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == INT16_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == INT16_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 / si2);
}

static int16_t(safe_lshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > (INT16_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int16_t(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > (INT16_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int16_t(safe_rshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int16_t(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int32_t(safe_unary_minus_func_int32_t_s)(int32_t si) {

  return

      (si == INT32_MIN) ? ((si)) :

                        -si;
}

static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT32_MAX - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < (INT32_MIN - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~INT32_MAX))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT32_MAX / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < (INT32_MIN / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < (INT32_MIN / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT32_MAX / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == INT32_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == INT32_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 / si2);
}

static int32_t(safe_lshift_func_int32_t_s_s)(int32_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > (INT32_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int32_t(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > (INT32_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int32_t(safe_rshift_func_int32_t_s_s)(int32_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int32_t(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int64_t(safe_unary_minus_func_int64_t_s)(int64_t si) {

  return

      (si == INT64_MIN) ? ((si)) :

                        -si;
}

static int64_t(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT64_MAX - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < (INT64_MIN - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int64_t(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~INT64_MAX))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int64_t(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > (INT64_MAX / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < (INT64_MIN / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < (INT64_MIN / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT64_MAX / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int64_t(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == INT64_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int64_t(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == INT64_MIN) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 / si2);
}

static int64_t(safe_lshift_func_int64_t_s_s)(int64_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > (INT64_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int64_t(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > (INT64_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int64_t(safe_rshift_func_int64_t_s_s)(int64_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int64_t(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static uint8_t(safe_unary_minus_func_uint8_t_u)(uint8_t ui) { return -ui; }

static uint8_t(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ui1 + ui2;
}

static uint8_t(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ui1 - ui2;
}

static uint8_t(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint8_t(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint8_t(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint8_t(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > (UINT8_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > (UINT8_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}

static uint16_t(safe_unary_minus_func_uint16_t_u)(uint16_t ui) { return -ui; }

static uint16_t(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ui1 + ui2;
}

static uint16_t(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ui1 - ui2;
}

static uint16_t(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint16_t(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint16_t(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint16_t(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > (UINT16_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint16_t(safe_lshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > (UINT16_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint16_t(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint16_t(safe_rshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}

static uint32_t(safe_unary_minus_func_uint32_t_u)(uint32_t ui) { return -ui; }

static uint32_t(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ui1 + ui2;
}

static uint32_t(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ui1 - ui2;
}

static uint32_t(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint32_t(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint32_t(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint32_t(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > (UINT32_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint32_t(safe_lshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > (UINT32_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint32_t(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint32_t(safe_rshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}

static uint64_t(safe_unary_minus_func_uint64_t_u)(uint64_t ui) { return -ui; }

static uint64_t(safe_add_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return ui1 + ui2;
}

static uint64_t(safe_sub_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return ui1 - ui2;
}

static uint64_t(safe_mul_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return ((unsigned long long)ui1) * ((unsigned long long)ui2);
}

static uint64_t(safe_mod_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint64_t(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint64_t(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > (UINT64_MAX >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint64_t(safe_lshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > (UINT64_MAX >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint64_t(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint64_t(safe_rshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}
static float(safe_add_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * FLT_MAX)) ? (sf1) :

                                                              (sf1 + sf2);
}

static float(safe_sub_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * FLT_MAX)) ? (sf1) :

                                                              (sf1 - sf2);
}

static float(safe_mul_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) >
       (0x1.0p-100f * (0x1.0p-28f * FLT_MAX)))
          ? (sf1)
          :

          (sf1 * sf2);
}

static float(safe_div_func_float_f_f)(float sf1, float sf2) {

  return

      ((fabsf(sf2) < 1.0f) &&
       (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) >
                              (0x1.0p-100f * (0x1.0p-49f * FLT_MAX)))))
          ? (sf1)
          :

          (sf1 / sf2);
}

static double(safe_add_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * DBL_MAX)) ? (sf1) :

                                                          (sf1 + sf2);
}

static double(safe_sub_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * DBL_MAX)) ? (sf1) :

                                                          (sf1 - sf2);
}

static double(safe_mul_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) >
       (0x1.0p-100 * (0x1.0p-924 * DBL_MAX)))
          ? (sf1)
          :

          (sf1 * sf2);
}

static double(safe_div_func_double_f_f)(double sf1, double sf2) {

  return

      ((fabs(sf2) < 1.0) &&
       (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) >
                             (0x1.0p-100 * (0x1.0p-974 * DBL_MAX)))))
          ? (sf1)
          :

          (sf1 / sf2);
}

static int32_t(safe_convert_func_float_to_int32_t)(float sf1) {

  return

      ((sf1 <= INT32_MIN) || (sf1 >= INT32_MAX)) ? (INT32_MAX) :

                                                 ((int32_t)(sf1));
}

static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;

static void crc32_gentab(void) {
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

static void crc32_byte(uint8_t b) {
  crc32_context = ((crc32_context >> 8) & 0x00FFFFFF) ^
                  crc32_tab[(crc32_context ^ b) & 0xFF];
}
static void crc32_8bytes(uint64_t val) {
  crc32_byte((val >> 0) & 0xff);
  crc32_byte((val >> 8) & 0xff);
  crc32_byte((val >> 16) & 0xff);
  crc32_byte((val >> 24) & 0xff);
  crc32_byte((val >> 32) & 0xff);
  crc32_byte((val >> 40) & 0xff);
  crc32_byte((val >> 48) & 0xff);
  crc32_byte((val >> 56) & 0xff);
}

static void transparent_crc(uint64_t val, char *vname, int flag) {
  crc32_8bytes(val);
  if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname,
           crc32_context ^ 0xFFFFFFFFUL);
  }
}

static void transparent_crc_bytes(char *ptr, int nbytes, char *vname,
                                  int flag) {
  int i;
  for (i = 0; i < nbytes; i++) {
    crc32_byte(ptr[i]);
  }
  if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname,
           crc32_context ^ 0xFFFFFFFFUL);
  }
}

static long __undefined;

struct S0 {
  signed f0 : 1;
  int64_t f1;
  signed f2 : 20;
  unsigned f3 : 8;
};

static int32_t g_2 = 1L;
static struct S0 g_35 = {-0, -1L, 631, 9};
static uint16_t g_40 = 65534UL;
static int32_t g_85 = 0x89AB98CFL;
static uint8_t g_86 = 2UL;
static int64_t g_131 = 1L;
static int16_t g_153 = 0L;
static uint32_t g_154 = 3UL;
static int16_t g_158 = 0L;
static uint32_t g_159 = 0x5CC1FFD3L;
static uint32_t g_203 = 0xBD2EE514L;
static int16_t g_250 = 0x8C40L;
static uint32_t g_251 = 0xB89A725EL;
static uint8_t g_312 = 1UL;
static int32_t g_316 = 0x123013CDL;
static uint32_t g_355 = 9UL;
static int32_t g_356 = (-1L);
static struct S0 g_388 = {0, 6L, -661, 1};
static int32_t g_390 = (-1L);
static uint8_t g_391 = 255UL;
static uint16_t g_420[4][10] = {
    {65535UL, 0x88F0L, 65535UL, 65532UL, 0x88F0L, 7UL, 7UL, 0x88F0L, 65532UL,
     65535UL},
    {0UL, 0UL, 0x54A8L, 0x88F0L, 0x8AC6L, 0x54A8L, 0x8AC6L, 0x88F0L, 0x54A8L,
     0UL},
    {0x8AC6L, 7UL, 65535UL, 0x8AC6L, 65532UL, 65532UL, 0x8AC6L, 65535UL, 7UL,
     0x8AC6L},
    {65535UL, 0UL, 7UL, 65532UL, 0UL, 65532UL, 7UL, 0UL, 65535UL, 65535UL}};
static int32_t g_421[5][10][5] = {
    {{(-1L), 0x9CC7936FL, 0x733E4B69L, (-10L), 3L},
     {0x6F17C7B4L, 0x504E397CL, 0xFAF5C5A5L, 0x7C3E73E6L, (-1L)},
     {9L, 0x276B277BL, (-1L), 6L, 6L},
     {(-8L), 0xA1E38021L, (-8L), 0x94C3BD62L, 0xA7408F1FL},
     {0x8AC3A7DBL, 0xD1F34A63L, 0x05469B73L, 0x41E353BDL, 0x2626DBABL},
     {0x6F17C7B4L, 0L, (-3L), 1L, 0xC693E4D5L},
     {(-1L), 0x468DFB35L, 0x05469B73L, 0x2626DBABL, 3L},
     {0xD2A2360EL, (-9L), (-8L), 0x962C5FE5L, 0x6F17C7B4L},
     {0x44593456L, 0x9CC7936FL, (-1L), 0xADF75AD1L, 0xD7FDC368L},
     {0xC7DFE44CL, 0x889A9044L, 0xFAF5C5A5L, (-1L), 0x504E397CL}},
    {{0xD1F34A63L, 0x7D366DB7L, 0xFA444388L, 0x468DFB35L, 0x4A120EAAL},
     {0x7C3E73E6L, 0x40DD39B6L, 0xD06CBE39L, 0x73BCDCAEL, 0x92D6179AL},
     {3L, 0L, 0xADF75AD1L, 0L, 0x8AC3A7DBL},
     {0x889A9044L, 7L, 0x2DC81D43L, 0xB3515830L, 0xFAF5C5A5L},
     {0xFA444388L, 0x05469B73L, 1L, (-5L), 1L},
     {0x34421670L, 0x34421670L, (-1L), (-1L), 0x73BCDCAEL},
     {0xB2F5332AL, 0x2626DBABL, 0x7E2228E0L, 0x28B7BCCEL, 0x276B277BL},
     {0xDE5C95E5L, 0L, (-4L), 0xA3EA5012L, 0xDA0AB8EFL},
     {0xD5DD3E96L, 0x2626DBABL, 9L, 0x13025689L, 1L},
     {0L, 0x34421670L, 0x57F46E1EL, 0x40DD39B6L, 0xC7DFE44CL}},
    {{0x28B7BCCEL, 0x05469B73L, 1L, 1L, 0x7D366DB7L},
     {(-1L), 7L, 0x962C5FE5L, 0L, 0xDFEFCE86L},
     {0x0B56072FL, 0L, 0x733E4B69L, 0xD7FDC368L, 0L},
     {(-1L), 0x40DD39B6L, (-1L), 0xFAF5C5A5L, 0xD2A2360EL},
     {0xCD05DC4EL, 0x7D366DB7L, 1L, 0x4772FBBAL, 0xBB4B3D1CL},
     {0xDA0AB8EFL, 0x889A9044L, 0xA3EA5012L, 0x6F17C7B4L, (-1L)},
     {(-1L), 0x9CC7936FL, 0xB2F5332AL, 0xB2F5332AL, 0x9CC7936FL},
     {0xC693E4D5L, (-9L), 0x504E397CL, 0xD06CBE39L, 0xA3EA5012L},
     {1L, 0x468DFB35L, 9L, (-7L), 0x2871C56AL},
     {0xD06CBE39L, 0L, 0xEB725935L, (-1L), 1L}},
    {{1L, 0xD1F34A63L, (-1L), 1L, 0x13025689L},
     {0xC693E4D5L, 0xA1E38021L, 1L, (-1L), 0x5D2BDD0BL},
     {(-1L), 0x276B277BL, 0x2871C56AL, (-1L), 6L},
     {0xDA0AB8EFL, 0x504E397CL, 0x5D2BDD0BL, 7L, 0L},
     {0xCD05DC4EL, (-1L), 0xBB4B3D1CL, 3L, 0L},
     {(-1L), (-1L), 8L, 0x3E7F1E87L, 0x962C5FE5L},
     {0x0B56072FL, 0x28B7BCCEL, 0L, 0x2871C56AL, (-1L)},
     {(-1L), 0x0552E894L, (-1L), 0x5CF14D71L, (-8L)},
     {0x28B7BCCEL, (-1L), 8L, (-1L), 0x28B7BCCEL},
     {0L, (-8L), 0xA7408F1FL, 0L, 1L}},
    {{(-1L), 0x2871C56AL, 0L, 0x28B7BCCEL, 0x0B56072FL},
     {1L, 1L, (-1L), 0xB7C597CEL, 1L},
     {6L, 0x28B7BCCEL, 0xD1F34A63L, 0x9CC7936FL, 3L},
     {1L, 0x45CBE6D6L, (-3L), 0x3E7F1E87L, 0xB7C597CEL},
     {0xBC0FE9D4L, 1L, 0x4772FBBAL, 1L, 3L},
     {0x40DD39B6L, 0xC693E4D5L, 0x0552E894L, 0x6F17C7B4L, 0L},
     {0xCD05DC4EL, (-5L), 0x05469B73L, (-1L), 0x7E2228E0L},
     {0L, 0x0552E894L, 1L, 1L, 0xFAF5C5A5L},
     {0xBB4B3D1CL, 0x276B277BL, 9L, 1L, 0L},
     {0x3E7F1E87L, 0L, 0x962C5FE5L, (-1L), 0xD2A2360EL}}};
static uint64_t g_506 = 0UL;
static uint64_t g_559[8] = {4UL, 4UL, 4UL, 4UL, 4UL, 4UL, 4UL, 4UL};
static int16_t g_594 = 1L;
static uint16_t g_750[1][6][1] = {
    {{0xE455L}, {0xE455L}, {0xE455L}, {0xE455L}, {0xE455L}, {0xE455L}}};
static uint64_t g_754[6][10] = {
    {0x91FF780DDFEFE0BALL, 0x91FF780DDFEFE0BALL, 0xB71EF27D511E6B97LL,
     0x79AB76C8654775D1LL, 0xF443B1863DBA0E6ALL, 18446744073709551608UL,
     0x91FF780DDFEFE0BALL, 0xF443B1863DBA0E6ALL, 0UL, 0xF443B1863DBA0E6ALL},
    {0x91FF780DDFEFE0BALL, 0x5376858CA911C115LL, 0x7F1EB7A26DC46069LL,
     0x79AB76C8654775D1LL, 0x7F1EB7A26DC46069LL, 0x5376858CA911C115LL,
     0x91FF780DDFEFE0BALL, 0x7F1EB7A26DC46069LL, 18446744073709551615UL,
     0xF443B1863DBA0E6ALL},
    {0x5376858CA911C115LL, 0x91FF780DDFEFE0BALL, 0x7F1EB7A26DC46069LL,
     18446744073709551615UL, 0xF443B1863DBA0E6ALL, 0x5376858CA911C115LL,
     0x5376858CA911C115LL, 0xF443B1863DBA0E6ALL, 18446744073709551615UL,
     0x7F1EB7A26DC46069LL},
    {0x91FF780DDFEFE0BALL, 0x91FF780DDFEFE0BALL, 0xB71EF27D511E6B97LL,
     0x79AB76C8654775D1LL, 0xF443B1863DBA0E6ALL, 18446744073709551608UL,
     0x91FF780DDFEFE0BALL, 0xF443B1863DBA0E6ALL, 0UL, 0xF443B1863DBA0E6ALL},
    {0x91FF780DDFEFE0BALL, 0x5376858CA911C115LL, 0x7F1EB7A26DC46069LL,
     0x79AB76C8654775D1LL, 0x7F1EB7A26DC46069LL, 0x5376858CA911C115LL,
     0x91FF780DDFEFE0BALL, 0x7F1EB7A26DC46069LL, 18446744073709551615UL,
     0xF443B1863DBA0E6ALL},
    {0x5376858CA911C115LL, 0x91FF780DDFEFE0BALL, 0x7F1EB7A26DC46069LL,
     18446744073709551615UL, 0xF443B1863DBA0E6ALL, 0x5376858CA911C115LL,
     0x5376858CA911C115LL, 0xF443B1863DBA0E6ALL, 18446744073709551615UL,
     0x7F1EB7A26DC46069LL}};
static int32_t g_755[8] = {0x7375C0FDL, 0x7375C0FDL, 0x5F05B9D7L, 0x7375C0FDL,
                           0x7375C0FDL, 0x5F05B9D7L, 0x7375C0FDL, 0x7375C0FDL};
static int32_t g_1021[5] = {1L, 1L, 1L, 1L, 1L};
static int32_t g_1031 = 1L;
static uint32_t g_1032[9] = {
    18446744073709551615UL, 18446744073709551606UL, 18446744073709551615UL,
    18446744073709551606UL, 18446744073709551615UL, 18446744073709551606UL,
    18446744073709551615UL, 18446744073709551606UL, 18446744073709551615UL};
static int32_t g_1103 = 0x44377EFEL;
static int8_t g_1109 = (-10L);
static struct S0 g_1145[8] = {{-0, -1L, 887, 10}, {-0, -1L, 887, 10},
                              {-0, -1L, 887, 10}, {-0, -1L, 887, 10},
                              {-0, -1L, 887, 10}, {-0, -1L, 887, 10},
                              {-0, -1L, 887, 10}, {-0, -1L, 887, 10}};
static int64_t g_1238 = 0xEF73CDC07DB9FD50LL;
static uint64_t g_1241 = 1UL;
static uint32_t g_1304 = 0UL;
static uint32_t g_1732[2][7] = {
    {4294967287UL, 4294967287UL, 4294967287UL, 4294967287UL, 4294967287UL,
     4294967287UL, 4294967287UL},
    {0xA22DCD37L, 0UL, 0xA22DCD37L, 0UL, 0xA22DCD37L, 0UL, 0xA22DCD37L}};
static uint64_t g_1756[1][1][10] = {
    {{1UL, 2UL, 1UL, 1UL, 2UL, 1UL, 1UL, 2UL, 1UL, 1UL}}};
static uint32_t g_1935 = 3UL;
static int64_t g_1985 = 0x4E20E02FB14D3ADFLL;
static uint32_t g_2138 = 0xE3D39B8FL;
static uint8_t g_2239 = 0x2BL;
static uint32_t g_2299 = 0x533C3544L;
static int32_t g_2300 = (-1L);
static int32_t g_2342 = 0x91C31F8BL;

static int64_t func_1(void);
static int32_t func_6(uint32_t p_7, uint32_t p_8, int64_t p_9, int8_t p_10,
                      int32_t p_11);
static uint8_t func_12(uint32_t p_13, int16_t p_14, struct S0 p_15,
                       struct S0 p_16, int8_t p_17);
static uint8_t func_22(uint32_t p_23);
static uint8_t func_41(int32_t p_42, uint8_t p_43, int32_t p_44, int64_t p_45,
                       uint32_t p_46);
static uint16_t func_51(int16_t p_52, uint16_t p_53, uint64_t p_54,
                        int32_t p_55);
static struct S0 func_59(uint32_t p_60, int16_t p_61, uint64_t p_62,
                         uint8_t p_63, struct S0 p_64);
static int32_t func_66(uint16_t p_67, struct S0 p_68);
static int32_t func_71(uint8_t p_72, uint32_t p_73, uint32_t p_74);
static uint8_t func_78(uint32_t p_79);
static int64_t func_1(void) {
  uint32_t l_5 = 0x6DA5043CL;
  struct S0 l_34 = {0, 0x5C82F744ED25E425LL, -208, 14};
  int32_t l_2303[5];
  int8_t l_2308 = 3L;
  uint16_t l_2311 = 65527UL;
  uint16_t l_2345[4] = {0xEDBEL, 0xEDBEL, 0xEDBEL, 0xEDBEL};
  uint32_t l_2354 = 0x7FA494A4L;
  int32_t l_2357 = 0x75FE5BB8L;
  uint16_t l_2358 = 0UL;
  int i;
  for (i = 0; i < 5; i++)
    l_2303[i] = (-1L);
  for (g_2 = 22; (g_2 <= (-3)); g_2 = safe_sub_func_int16_t_s_s(g_2, 2)) {
    uint32_t l_30 = 0UL;
    uint8_t l_33 = 255UL;
    int32_t l_2301 = 0x444D8480L;
    int32_t l_2302 = (-2L);
    int32_t l_2304 = 0x33EA3733L;
    int32_t l_2305 = 0x25C00CA3L;
    int32_t l_2306 = 0L;
    int32_t l_2307 = 7L;
    int32_t l_2309 = 3L;
    int32_t l_2310[1];
    int16_t l_2343 = (-1L);
    uint32_t l_2344 = 1UL;
    int i;
    for (i = 0; i < 1; i++)
      l_2310[i] = 0xF3D959FAL;
    l_5 = g_2;
    g_2300 |= func_6(
        ((18446744073709551615UL != 0x315362DAAB72B21ALL) >
         func_12(
             (g_2 ==
              (safe_rshift_func_uint16_t_u_u(
                  (safe_sub_func_int64_t_s_s(
                      0x4CCFD66C4A87FCE6LL,
                      (g_2 &&
                       func_22((safe_sub_func_uint16_t_u_u(
                           (safe_add_func_uint64_t_u_u(
                               (0UL && ((safe_mul_func_int8_t_s_s(
                                            l_30, (safe_sub_func_int64_t_s_s(
                                                      (4294967290UL !=
                                                       ((l_33 ^ g_2) > l_30)),
                                                      g_2)))) &
                                        65534UL)),
                               0x2AD015B01D976D99LL)),
                           g_2)))))),
                  l_5))),
             l_5, l_34, g_35, l_34.f0)),
        l_30, l_33, g_2, l_33);
    l_2311++;
    l_2304 =
        (g_35.f0 =
             ((((0xB378L <=
                 (safe_mul_func_int8_t_s_s(
                     (safe_mul_func_int8_t_s_s(
                         g_506,
                         (safe_mul_func_int8_t_s_s(
                             (safe_lshift_func_int16_t_s_u(
                                 ((g_2299--) !=
                                  ((g_1756[0][0][6] = (safe_add_func_uint32_t_u_u(
                                        (g_1732[0][1]--),
                                        (l_2305 &&
                                         ((safe_mod_func_int8_t_s_s(
                                              ((safe_rshift_func_int8_t_s_s(
                                                   ((safe_mod_func_int64_t_s_s(
                                                        (safe_rshift_func_uint8_t_u_s(
                                                            (g_391 |=
                                                             (safe_rshift_func_int8_t_s_s(
                                                                 ((l_2306 &=
                                                                   l_2308) <=
                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                      (safe_mod_func_uint32_t_u_u(
                                                                          l_33,
                                                                          l_34.f1)),
                                                                      (((((((l_2305 >
                                                                             g_755
                                                                                 [7]) |
                                                                            (g_35.f2 =
                                                                                 ((g_388
                                                                                       .f0 =
                                                                                       ((g_35.f3,
                                                                                         l_2310
                                                                                             [0]) <
                                                                                        g_2)) >=
                                                                                  g_2342))),
                                                                           0x030870B0L) >=
                                                                          g_754
                                                                              [2]
                                                                              [1]) >
                                                                         g_755
                                                                             [0]) &
                                                                        l_2302) &&
                                                                       l_34.f0)))),
                                                                 7))),
                                                            g_1145[0].f0)),
                                                        l_2343)) &&
                                                    g_131),
                                                   4)) |
                                               0UL),
                                              l_2344)),
                                          1UL))))) < l_2345[1])),
                                 g_2138)),
                             0UL)))),
                     g_1103))) &&
                g_250) != g_131) >= l_34.f3));
  }
  g_356 |=
      ((safe_add_func_uint8_t_u_u(0xBEL, 253UL)) >=
       (g_35,
        ((((0x1BF0108EL ^
            (safe_mod_func_int16_t_s_s(
                ((l_5 |
                  (((((l_2303[2] = g_2138),
                      (safe_sub_func_int64_t_s_s(
                          (g_131 &= 7L), ((safe_add_func_int32_t_s_s(
                                              0x5B5F2838L, 5UL)) <= g_1935)))),
                     0x0B2CL) == g_251),
                   g_559[3])) == 0x870BF6B6L),
                65527UL))) != g_1238),
          l_5) == g_559[6])));
  l_2354--;
  ++l_2358;
  return g_1756[0][0][6];
}

static int32_t func_6(uint32_t p_7, uint32_t p_8, int64_t p_9, int8_t p_10,
                      int32_t p_11) {
  return p_8;
}

static uint8_t func_12(uint32_t p_13, int16_t p_14, struct S0 p_15,
                       struct S0 p_16, int8_t p_17) {
  uint16_t l_47[9][1];
  int32_t l_48 = 0x693CE85DL;
  int32_t l_58 = 1L;
  struct S0 l_65 = {-0, 0x398C3D34E0BB6923LL, 83, 9};
  int32_t l_2073 = 1L;
  int32_t l_2076 = 0xF76A42B0L;
  int32_t l_2077 = 0x8D8B355DL;
  int32_t l_2078 = 1L;
  int32_t l_2080[3][2][9];
  int32_t l_2166 = 0x1B7F9CF5L;
  int8_t l_2167 = 1L;
  uint16_t l_2242[1];
  int32_t l_2280 = 0xA36C0F69L;
  struct S0 l_2282[6] = {{0, -1L, 256, 10}, {0, -1L, 256, 10},
                         {0, -1L, 256, 10}, {0, -1L, 256, 10},
                         {0, -1L, 256, 10}, {0, -1L, 256, 10}};
  uint32_t l_2298 = 0xB81F1C22L;
  int i, j, k;
  
  safe_lshift_func_uint8_t_u_s(
          ((safe_lshift_func_uint8_t_u_u((g_40 = p_16.f2), 0)),
		  func_41(p_16.f1, (l_47[0][0] = g_2), func_22(g_35.f3), l_48,
                   ((safe_mul_func_int16_t_s_s(
                        (func_51(((safe_lshift_func_int8_t_s_s(l_58, 3)), 1L),
                                 (func_22(((g_1103 |=
                                            (func_59((p_15.f3 ^= 0x43772679L),p_16.f3, p_15.f2, g_35.f2,l_65),
                                             p_15.f2)) ||
                                           g_1021[4])),
                                  g_1021[3]),
                                 l_65.f1, g_1021[3]) &&
                         0L),
                        g_1021[3])) &&
                    0x72B8796B4B0CDDFFLL))),
          3); 
  {
    uint64_t l_2008 = 0xA93597A2757AA7B7LL;
    int32_t l_2056[4];
    uint8_t l_2061 = 254UL;
    uint8_t l_2084 = 8UL;
    int8_t l_2139 = 0x41L;
    uint8_t l_2160 = 8UL;
    uint64_t l_2169 = 0x00E90AC12B946C62LL;
    int i;
    for (i = 0; i < 4; i++)
      l_2056[i] = 0x01DBE096L;
    for (g_388.f1 = 0; (g_388.f1 >= 0); g_388.f1 -= 1) {
      uint8_t l_2007 = 7UL;
      int32_t l_2057 = 1L;
      int32_t l_2060 = 2L;
      int8_t l_2064[6];
      int32_t l_2069[3];
      int i;
      for (i = 0; i < 6; i++)
        l_2064[i] = 0x1CL;
      for (i = 0; i < 3; i++)
        l_2069[i] = (-2L);
      p_15 = g_1145[1];
      for (g_316 = 0; (g_316 <= 0); g_316 += 1) {
        int32_t l_1993 = 0x77FA8EE2L;
        int32_t l_2006[3][6];
        int32_t l_2058 = 0x05A3F779L;
        int32_t l_2068 = (-3L);
        int32_t l_2070 = (-1L);
        int32_t l_2071 = 0xD527FC4BL;
        int32_t l_2072 = 0L;
        int8_t l_2074 = (-1L);
        int32_t l_2075 = (-6L);
        int32_t l_2079 = (-7L);
        int32_t l_2081 = 1L;
        int32_t l_2082 = 0xE792AB5EL;
        int32_t l_2083 = 0x3CAE042CL;
        int64_t l_2106 = (-5L);
        uint32_t l_2181 = 0UL;
        int i, j;
        for (i = 0; i < 3; i++) {
          for (j = 0; j < 6; j++)
            l_2006[i][j] = (-1L);
        }
        p_16.f2 =
            ((-1L) >=
             (safe_add_func_int16_t_s_s(
                 (~(((((!(safe_unary_minus_func_uint32_t_u((
                           (((safe_mod_func_int8_t_s_s(
                                 (p_17 =
                                      (((g_1021[(g_316 + 1)] ^
                                         (l_1993 = 250UL)) >=
                                        g_1021[(g_316 + 4)]),
                                       (+(safe_sub_func_uint8_t_u_u(
                                           (safe_sub_func_uint64_t_u_u(
                                               (((((g_1021[(g_388.f1 + 4)] |
                                                    (+(1UL <=
                                                       (safe_rshift_func_uint16_t_u_u(
                                                           (((g_1021[(g_388.f1 +
                                                                      1)] <=
                                                              (((safe_sub_func_uint16_t_u_u(
                                                                    (g_750[0][4][0] =
                                                                         ((255UL ||
                                                                           (safe_mul_func_uint8_t_u_u(
                                                                               g_1021[(
                                                                                   g_388
                                                                                       .f1 +
                                                                                   4)],
                                                                               0x08L))) <=
                                                                          g_1021[(
                                                                              g_388
                                                                                  .f1 +
                                                                              4)])),
                                                                    l_2006
                                                                        [1]
                                                                        [0])) &&
                                                                g_312) &&
                                                               0x9599CF4CD2DC769FLL)) ^
                                                             0x8E1A2817L) ^
                                                            l_2007),
                                                           p_16.f3))))),
                                                   p_15.f0) &&
                                                  0xAAL) |
                                                 g_1021[(g_388.f1 + 1)]) ||
                                                0x89L),
                                               0xFBA833257928EB20LL)),
                                           p_13))))),
                                 l_65.f2)) <= p_15.f2) >= g_1021[3]) |
                           0x7F41BBB9EBBBEBD2LL)))) < l_2008) <
                      0xA2E148E449042A25LL),
                     0xC2L) > g_391)),
                 0xE564L)));
        if (g_250) {
          uint32_t l_2013 = 0UL;
          int32_t l_2059 = (-1L);
          int32_t l_2065 = 0xBB55C928L;
          int32_t l_2066 = 9L;
          int32_t l_2067[10] = {5L,    (-7L), (-7L), 5L,    (-7L),
                                (-7L), 5L,    (-7L), (-7L), 5L};
          int i;
          for (l_65.f1 = 1; (l_65.f1 <= 4); l_65.f1 += 1) {
            int32_t l_2009 = 0x1E926A40L;
            uint32_t l_2010 = 4294967295UL;
            int i, j, k;
            p_16.f2 =
                (g_1031 =
                     ((((l_2013 = (l_2010--)) == p_16.f1) ==
                       (l_2009 ||
                        (l_2009,
                         (g_153 = ((l_1993 = 0x4AL) <=
                                   ((p_14 = (p_16, (4294967295UL ^ p_14))) >
                                    ((((p_16.f2 ^ p_16.f2), l_2009), 0UL) !=
                                     0L))))))) > 0xD1C62C73L));
            p_16.f0 &= (safe_add_func_int32_t_s_s(
                (safe_mod_func_uint16_t_u_u(
                    ((!((safe_add_func_int32_t_s_s(
                            g_251,
                            (((safe_mul_func_uint16_t_u_u(
                                  (safe_sub_func_uint16_t_u_u(
                                      65535UL,
                                      ((safe_lshift_func_uint8_t_u_u(
                                           ((safe_mul_func_int8_t_s_s(
                                                (safe_rshift_func_int16_t_s_u(
                                                    (0xEE27EA3A9B845872LL ==
                                                     (safe_mod_func_int16_t_s_s(
                                                         (((l_58 =
                                                                ((1L ==
                                                                  (safe_add_func_uint8_t_u_u(
                                                                      ((safe_mod_func_int64_t_s_s(
                                                                           (l_2013 &&
                                                                            ((safe_lshift_func_int16_t_s_u(
                                                                                 l_2007,
                                                                                 15)) <
                                                                             p_13)),
                                                                           18446744073709551615UL)),
                                                                       (~(safe_unary_minus_func_uint64_t_u((
                                                                           g_1756
                                                                               [g_316]
                                                                               [g_316]
                                                                               [(g_388
                                                                                     .f1 +
                                                                                 9)] ^=
                                                                           (((p_14 <
                                                                              0x2257770E5FB5E42FLL) ||
                                                                             65534UL) <
                                                                            l_2007)))))),
                                                                      p_15.f1))) &&
                                                                 g_1732[0]
                                                                       [6])) &&
                                                           0x60L) &
                                                          g_420[1][8]),
                                                         l_65.f0))),
                                                    15)),
                                                (-6L))) &
                                            l_2008),
                                           7)) ^
                                       0x11F932D8D6B24690LL))),
                                  9L)) < 0x2B81L) &&
                             3L))) != g_159)) ||
                     p_15.f0),
                    g_1304)),
                g_1732[1][0]));
            if (g_1732[1][1])
              break;
            g_1031 &=
                (g_388,
                 ((((((safe_rshift_func_int8_t_s_u((p_17 = (p_15.f3 >= p_14)),
                                                   0)) &
                      ((((safe_mul_func_uint16_t_u_u(
                             (((g_1756[g_316][g_316][(g_388.f1 + 9)] &
                                ((safe_add_func_int32_t_s_s(
                                     (((safe_add_func_int32_t_s_s(
                                           ((g_391 &=
                                             ((~(p_14 ==
                                                 ((safe_rshift_func_int16_t_s_u(
                                                      g_1304, l_2010)) &&
                                                  (safe_mul_func_uint8_t_u_u(
                                                      (p_16.f2 >=
                                                       ((((l_2007 <= p_15.f1),
                                                          l_2009) ^
                                                         p_13) &
                                                        l_2007)),
                                                      l_65.f1))))) > 0x3EL)) !=
                                            0x59L),
                                           p_13)) ^
                                       p_16.f2) &&
                                      p_15.f1),
                                     0x8BE346C4L)) &&
                                 0x4C265C3A353CAB8FLL)),
                               l_2006[1][0]) &
                              g_1238),
                             l_2008)) >= 1UL) |
                        g_755[2]) ^
                       g_158)) <= l_2013) ||
                    g_1109),
                   g_1756[0][0][9]),
                  l_2010));
          }
          for (g_1103 = 0; (g_1103 <= 4); g_1103 += 1) {
            if (g_1032[4])
              break;
            g_1145[7] = p_16;
          }
          ++l_2061;
          l_2084++;
        } else {
          int16_t l_2092 = 0L;
          int32_t l_2103 = 0x7153F0D5L;
          int32_t l_2105[1][7][4] = {
              {{0x5EB7B5BBL, 4L, 8L, 0x016DD56EL},
               {0x5EB7B5BBL, 8L, 0x5EB7B5BBL, 0x54B48A9DL},
               {4L, 0x016DD56EL, 0x54B48A9DL, 0x54B48A9DL},
               {8L, 8L, 0xBD3CD425L, 0x016DD56EL},
               {0x016DD56EL, 4L, 0xBD3CD425L, 4L},
               {8L, 0x5EB7B5BBL, 0x54B48A9DL, 0xBD3CD425L},
               {4L, 0x5EB7B5BBL, 0x5EB7B5BBL, 4L}}};
          int i, j, k;
          if (((p_15.f1 !=
                (p_16.f1,
                 (safe_add_func_uint16_t_u_u(
                     2UL,
                     ((l_2069[2] | 0xAD6A8CABL) &
                      ((((safe_mod_func_uint32_t_u_u(
                             p_13,
                             ((((p_14 = (safe_unary_minus_func_int64_t_s((
                                     l_2092,
                                     (g_35.f1 |=
                                      ((safe_mod_func_int8_t_s_s(
                                           ((safe_sub_func_uint32_t_u_u(
                                                (safe_mod_func_uint64_t_u_u(
                                                    (g_312 ==
                                                     (safe_mod_func_int64_t_s_s(
                                                         (252UL ^ g_251),
                                                         0x54EAB2CE98B21CF8LL))),
                                                    p_13)),
                                                0UL)) &&
                                            l_58),
                                           p_15.f3)) <= (-10L))))))) ||
                                l_2092) &
                               p_16.f3) &&
                              0x915DDB6EL))),
                         p_15.f1) ||
                        g_420[2][7]) != 0UL)))))) >= g_1238)) {
            int8_t l_2101 = 0L;
            int32_t l_2102 = 1L;
            int32_t l_2104[4];
            uint32_t l_2107 = 0xF5155C7BL;
            int i;
            for (i = 0; i < 4; i++)
              l_2104[i] = (-3L);
            l_2056[1] = (g_35.f1 & g_85);
            if (l_2083)
              continue;
            ++l_2107;
          } else {
            uint8_t l_2116 = 0xECL;
            l_2116 = (7UL <= (safe_add_func_int16_t_s_s(
                                 (p_14 >= 0L), (safe_lshift_func_uint8_t_u_u(
                                                   (safe_mod_func_uint32_t_u_u(
                                                       g_388.f0, 0xD95D3B69L)),
                                                   (g_1032[4], 0x46L))))));
            if (p_15.f1)
              continue;
            if (g_251)
              continue;
          }
          g_85 =
              ((((safe_lshift_func_uint16_t_u_s(
                     (~((safe_mod_func_uint8_t_u_u(
                            (l_2103 |=
                             ((l_2079 =
                                   (((l_2069[0] =
                                          ((((safe_mul_func_uint8_t_u_u(
                                                 (~g_388.f1), 0xDAL)),
                                             ((g_1985 = g_1031) &&
                                              ((((safe_add_func_int64_t_s_s(
                                                     (safe_lshift_func_uint16_t_u_s(
                                                         p_16.f0,
                                                         (safe_add_func_uint16_t_u_u(
                                                             ((safe_add_func_uint64_t_u_u(
                                                                  (!(p_14 >=
                                                                     ((safe_mul_func_int8_t_s_s(
                                                                          (0L >
                                                                           g_391),
                                                                          (-9L))),
                                                                      (safe_lshift_func_int16_t_s_u(
                                                                          (g_1756
                                                                               [0]
                                                                               [0]
                                                                               [6] ||
                                                                           0x096AE7FBL),
                                                                          13))))),
                                                                  0L)) ==
                                                              l_2057),
                                                             g_1145[0].f3)))),
                                                     0x3F775840E4CD775ELL)) !=
                                                 0x8DL) <= l_2105[0][4][3]) &&
                                               0x00D2L))) <= g_2138) &
                                           l_2061)) > l_2139) <= g_1109)) &
                              0xB65AA63D71E1CA45LL)),
                            255UL)),
                        0x57311856L)),
                     p_13)) > p_16.f3) |
                l_2070) < 5UL);
          for (l_2079 = 0; (l_2079 <= 4); l_2079 += 1) {
            int i, j, k;
            return l_2080[(g_316 + 1)][(g_316 + 1)][(g_316 + 5)];
          }
        }
        p_16.f0 &=
            ((g_1145[0].f2,
              (p_15.f3 =
                   (g_2 ==
                    (safe_mod_func_uint8_t_u_u(
                        (((~(!(safe_add_func_int32_t_s_s(p_13,
                                                         ((-1L) & 1UL))))) ||
                          l_2084) >
                         ((((g_1109 ^= l_2007) != g_506) ==
                           ((((safe_sub_func_int64_t_s_s(p_16.f2, l_2064[2])) !=
                              0xDAL) != 0xC1672499L),
                            g_421[0][3][0])) <= l_2056[1])),
                        0x25L))))) < p_17);
        for (g_86 = 0; (g_86 <= 4); g_86 += 1) {
          uint16_t l_2165 = 0x25C2L;
          if ((safe_mul_func_uint8_t_u_u(
                  (((((safe_add_func_int64_t_s_s(
                          (0UL ==
                           (((-1L) <=
                             ((safe_sub_func_int64_t_s_s(
                                  (g_420[2][1] <=
                                   ((((p_16.f1 >
                                       ((safe_add_func_int32_t_s_s(
                                            (l_2160 |
                                             ((safe_add_func_uint64_t_u_u(
                                                  (safe_add_func_int8_t_s_s(
                                                      l_2165,
                                                      (g_1109 =
                                                           ((p_16.f2 <=
                                                             (((l_2056[1] !=
                                                                (((l_2166 <
                                                                   0x0909B4CBL),
                                                                  p_15.f0) &&
                                                                 0x5B8E753886222F94LL)) <=
                                                               l_2070) >
                                                              g_35.f0)) >
                                                            l_2139)))),
                                                  l_2167)) == g_1145[0].f0)),
                                            g_506)) &&
                                        1L)) ||
                                      l_2165) == (-1L)) >= 0L)),
                                  p_15.f0)) < l_2165)) >= l_2165)),
                          0x5907DCC24EAC188CLL)) ^
                      0x4EL) ||
                     0x57681B8ECC6044BELL) <= 0x99L) &
                   6L),
                  0UL))) {
            int32_t l_2168 = 0x020473F8L;
            l_2169++;
          } else {
            uint32_t l_2172 = 18446744073709551614UL;
            int32_t l_2194[3][2][3] = {
                {{(-1L), (-1L), 0x1A35FE3EL}, {(-1L), (-1L), 0x1A35FE3EL}},
                {{(-1L), (-1L), 0x1A35FE3EL}, {(-1L), (-1L), 0x1A35FE3EL}},
                {{(-1L), (-1L), 0x1A35FE3EL}, {(-1L), (-1L), 0x1A35FE3EL}}};
            int i, j, k;
            g_35.f0 =
                ((l_2172,
                  (safe_lshift_func_int8_t_s_s(
                      (((p_16.f0 ==
                         ((safe_mul_func_int16_t_s_s(
                              ((((--g_1304),
                                 (g_1756[g_316][g_316][(g_316 + 9)] |=
                                  (safe_mod_func_uint64_t_u_u(
                                      l_2181, 18446744073709551615UL)))) ||
                                ((safe_mod_func_int16_t_s_s(l_2007, p_16.f3)),
                                 (-10L))) !=
                               (l_2169, ((safe_lshift_func_uint16_t_u_s(
                                             (l_2081 |=
                                              ((g_1145[0].f0, p_15.f1) & p_17)),
                                             l_2070)) <= p_13))),
                              5L)) <= g_1021[(g_388.f1 + 4)])) |
                        0x4D13L) &&
                       g_1145[0].f3),
                      l_2167))) > p_15.f2);
            l_2194[0][1][1] = (safe_add_func_int32_t_s_s(
                g_159,
                ((p_13 !=
                  ((0x0AL &&
                    (safe_lshift_func_int8_t_s_u(
                        (l_2006[1][0], (l_2056[1], (-1L))),
                        (safe_rshift_func_int16_t_s_u(
                            ((safe_rshift_func_uint16_t_u_s(
                                 (p_13 >= p_16.f1), 3)) |
                             ((((g_1109 ^= (0xFACE4F9578FC59A3LL <=
                                            0x61490D3A8CA6555ALL)) != g_1304) >=
                               l_2165) == g_1756[g_316][g_316][(g_316 + 9)])),
                            7))))) &
                   p_14)) > g_421[2][3][0])));
            l_2075 = ((1L < 4294967292UL) == (p_16.f2 &= (-8L)));
          }
          return g_1756[0][0][7];
        }
      }
    }
    for (g_158 = 3; (g_158 >= 0); g_158 -= 1) {
      uint64_t l_2218 = 18446744073709551615UL;
      int32_t l_2221 = 6L;
      int32_t l_2223 = 1L;
      int32_t l_2224[1];
      int32_t l_2225[2];
      uint32_t l_2228 = 1UL;
      int i;
      for (i = 0; i < 1; i++)
        l_2224[i] = 0x592E0D27L;
      for (i = 0; i < 2; i++)
        l_2225[i] = 2L;
      if ((p_16.f0 < l_2078)) {
        int32_t l_2206 = 0xC331D8C5L;
        int32_t l_2207 = (-8L);
        int32_t l_2209 = 0x37BF2CFDL;
        int32_t l_2216 = (-6L);
        int32_t l_2217[3][8] = {
            {0xABEE5135L, 0x88A75556L, 0x30299C6DL, 1L, 0x30299C6DL,
             0x88A75556L, 0xABEE5135L, 0xDE961BF1L},
            {0x30299C6DL, 0x88A75556L, 0xABEE5135L, 0xDE961BF1L, (-9L), (-9L),
             0xDE961BF1L, 0xABEE5135L},
            {(-1L), (-1L), 0x88A75556L, (-1L), (-9L), 1L, 8L, 1L}};
        int i, j;
        for (g_1304 = 0; (g_1304 <= 3); g_1304 += 1) {
          int32_t l_2212 = 0L;
          int32_t l_2213 = (-6L);
          int32_t l_2214 = 5L;
          int32_t l_2215 = 0xA4A4B806L;
          int i;
          l_2056[g_1304] = p_14;
          if (((safe_add_func_int8_t_s_s(
                   ((l_2139 == p_16.f1) <=
                    ((0x7458L &&
                      (+(safe_rshift_func_int8_t_s_u(
                          (((7UL ==
                             (safe_unary_minus_func_int16_t_s(
                                 (safe_add_func_uint32_t_u_u(
                                     (safe_add_func_uint64_t_u_u(
                                         ((((0xF01A30E9L != (0x3FE1L & g_250)),
                                            g_316) ||
                                           p_16.f0) ||
                                          8L),
                                         0xC0E07CACADAC72B0LL)),
                                     9UL))))) > p_14) < p_17),
                          7)))) ^
                     (-1L))),
                   g_1241)),
               g_159)) {
            int64_t l_2205 = 0xA326DBE9726E5E8FLL;
            int32_t l_2208 = 0x2927C89FL;
            int32_t l_2210 = 0x0975FF2FL;
            int32_t l_2211 = 4L;
            if (l_2205)
              break;
            if (l_2206)
              break;
            l_2218--;
          } else {
            return l_2216;
          }
        }
      } else {
        for (g_159 = 0; (g_159 <= 3); g_159 += 1) {
          g_1145[1] = g_1145[0];
          return g_754[4][9];
        }
      }
      for (g_1985 = 3; (g_1985 >= 0); g_1985 -= 1) {
        int32_t l_2222 = 0xC3D92AFAL;
        int32_t l_2226 = 0L;
        int32_t l_2227[9][5][4] = {
            {{0xA3FE81E5L, 9L, (-7L), 8L},
             {9L, 0x7B5FFDFDL, 3L, 9L},
             {0x958646E1L, 9L, 3L, 1L},
             {9L, (-8L), (-7L), 0xA3FE81E5L},
             {0xA3FE81E5L, 3L, 1L, 0x33C5C768L}},
            {{1L, 0x33C5C768L, 1L, 1L},
             {8L, 8L, 0xCAB6F3F9L, 0xE5182B71L},
             {9L, 0x7B5FFDFDL, 3L, 0L},
             {1L, 0xE5182B71L, 0xFC9DB959L, 3L},
             {0x33C5C768L, 0xE5182B71L, (-7L), 0L}},
            {{0xE5182B71L, 0x7B5FFDFDL, 0x35AA3B59L, 0xE5182B71L},
             {0x958646E1L, 8L, 0x7B5FFDFDL, 1L},
             {(-1L), 0x33C5C768L, (-7L), 0x33C5C768L},
             {(-8L), 3L, 0x958646E1L, 0xA3FE81E5L},
             {1L, (-8L), (-6L), 1L}},
            {{0L, 9L, 0xCAB6F3F9L, 9L},
             {0L, 0x7B5FFDFDL, (-6L), 8L},
             {1L, 9L, 0x958646E1L, 3L},
             {(-8L), (-1L), (-7L), 9L},
             {(-1L), 0x7B5FFDFDL, 0x7B5FFDFDL, (-1L)}},
            {{0x958646E1L, 0L, 0x35AA3B59L, 1L},
             {0xE5182B71L, 0xA3FE81E5L, (-7L), (-8L)},
             {0x33C5C768L, 3L, 0xFC9DB959L, (-8L)},
             {1L, 0xA3FE81E5L, 3L, 1L},
             {9L, 0L, 0xCAB6F3F9L, (-1L)}},
            {{8L, 0x7B5FFDFDL, 1L, 9L},
             {1L, (-1L), 1L, 3L},
             {0xA3FE81E5L, 9L, 0L, 0xFC9DB959L},
             {3L, (-1L), (-7L), 3L},
             {1L, 0x958646E1L, (-7L), 0xE1C177A8L}},
            {{3L, 1L, 0L, 3L},
             {3L, (-7L), 0xDA872E50L, (-6L)},
             {0xDA872E50L, (-6L), 0xE1C177A8L, 0xE1C177A8L},
             {0xFC9DB959L, 0xFC9DB959L, 9L, 0x7B5FFDFDL},
             {0x958646E1L, (-1L), 0L, 1L}},
            {{0xDA872E50L, 0x7B5FFDFDL, 1L, 0L},
             {(-6L), 0x7B5FFDFDL, 0L, 1L},
             {0x7B5FFDFDL, (-1L), 0xCAB6F3F9L, 0x7B5FFDFDL},
             {1L, 0xFC9DB959L, (-1L), 0xE1C177A8L},
             {0x35AA3B59L, (-6L), 0L, (-6L)}},
            {{1L, (-7L), 1L, 3L},
             {0xDA872E50L, 1L, (-8L), 0xE1C177A8L},
             {1L, 0x958646E1L, 9L, 3L},
             {1L, (-1L), (-8L), 0xFC9DB959L},
             {0xDA872E50L, 3L, 1L, 0L}}};
        int i, j, k;
        ++l_2228;
      }
    }
  } 
   {
    uint16_t l_2247 = 2UL;
    int32_t l_2248 = 0x07CE1456L;
    uint64_t l_2249 = 0xA3F082DE2C18DA24LL;
    int64_t l_2277[3];
    int32_t l_2278 = 0xEE781271L;
    int32_t l_2279[5][10][3] = {{{0xCFD4230DL, 0x5B6938F0L, 0x398AD982L},
                                 {8L, 0xCEB0288AL, 0x40CB8E38L},
                                 {(-8L), (-1L), 0x08A5BD52L},
                                 {0x695D4B9FL, 0x71775154L, 0x695D4B9FL},
                                 {0x08A5BD52L, (-1L), (-8L)},
                                 {0x40CB8E38L, 0xCEB0288AL, 8L},
                                 {0x398AD982L, 0x5B6938F0L, 0xCFD4230DL},
                                 {0L, 0L, 1L},
                                 {0x398AD982L, 0x08A5BD52L, 0x5B6938F0L},
                                 {0x40CB8E38L, 1L, 0L}},
                                {{0x08A5BD52L, 0xA008A039L, 0xA008A039L},
                                 {0x695D4B9FL, 0x40CB8E38L, 0L},
                                 {(-8L), 0L, 0x5B6938F0L},
                                 {8L, (-1L), 1L},
                                 {0xCFD4230DL, 0L, 0xCFD4230DL},
                                 {1L, (-1L), 8L},
                                 {0x5B6938F0L, 0L, (-8L)},
                                 {0L, 0x40CB8E38L, 0x695D4B9FL},
                                 {0xA008A039L, 0xA008A039L, 0x08A5BD52L},
                                 {0L, 1L, 0x40CB8E38L}},
                                {{0x5B6938F0L, 0x08A5BD52L, 0x398AD982L},
                                 {1L, 0L, 0L},
                                 {0xCFD4230DL, 0x5B6938F0L, 0x398AD982L},
                                 {8L, 0xCEB0288AL, 0x40CB8E38L},
                                 {(-8L), (-1L), 0x08A5BD52L},
                                 {0x695D4B9FL, 0x71775154L, 0x695D4B9FL},
                                 {0x08A5BD52L, (-1L), (-8L)},
                                 {0x40CB8E38L, 0xCEB0288AL, 8L},
                                 {0x398AD982L, 0x5B6938F0L, 0xCFD4230DL},
                                 {0L, 0L, 1L}},
                                {{0x398AD982L, 0x08A5BD52L, 0x5B6938F0L},
                                 {0x40CB8E38L, 1L, 0L},
                                 {0x08A5BD52L, 0xA008A039L, 0xA008A039L},
                                 {0x695D4B9FL, 0x40CB8E38L, 0L},
                                 {(-8L), 0L, 0x5B6938F0L},
                                 {8L, (-1L), 1L},
                                 {0xCFD4230DL, 0L, 0xCFD4230DL},
                                 {1L, (-1L), 8L},
                                 {0x5B6938F0L, 0L, (-8L)},
                                 {0L, 0x40CB8E38L, 0x695D4B9FL}},
                                {{0xA008A039L, (-10L), 0xA008A039L},
                                 {8L, 0L, 0x71775154L},
                                 {0L, 0xA008A039L, (-8L)},
                                 {0L, 4L, 4L},
                                 {(-1L), 0L, (-8L)},
                                 {0x695D4B9FL, 0L, 0x71775154L},
                                 {0xCFD4230DL, 0x08A5BD52L, 0xA008A039L},
                                 {(-1L), 0x64D5E002L, (-1L)},
                                 {0xA008A039L, 0x08A5BD52L, 0xCFD4230DL},
                                 {0x71775154L, 0L, 0x695D4B9FL}}};
    int32_t l_2281 = 7L;
    uint64_t l_2297 = 0UL;
    int i, j, k;
    for (i = 0; i < 3; i++)
      l_2277[i] = 0x3E9E39A5FA8F92B6LL;
    l_58 ^= (safe_mul_func_uint16_t_u_u(
        (safe_sub_func_int8_t_s_s(
            0x5CL, (safe_rshift_func_uint16_t_u_u(0xD7EEL, 14)))),
        (((((0x8EC8L >
             (g_2239 >
              (safe_mul_func_int16_t_s_s(
                  (((g_1109 ^=
                     ((l_2167, l_2242[0]) >=
                      (((safe_rshift_func_uint8_t_u_u(
                            (((g_388.f1 ^= p_15.f2) !=
                              (p_16, (l_2248 &=
                                      (p_16.f1 = (safe_mod_func_uint16_t_u_u(
                                           l_2247, g_1935)))))) &&
                             0x4FL),
                            l_2247)) |
                        l_2249) == 0x29L))),
                    l_47[0][0]),
                   l_2248),
                  p_15.f3)))) &
            0L) &
           p_13) <= g_1031) ||
         9UL)));
        g_35 = func_59(((l_2078 = (l_58 = ((--g_391) | (p_17 < ((((l_2281 = (((((g_1109 = ((l_2280 = (g_506 > ((safe_add_func_int32_t_s_s(p_16.f0, ((((((safe_mod_func_int64_t_s_s((l_2279[1][9][1] = (safe_lshift_func_uint16_t_u_s((l_65.f0 = (safe_add_func_uint64_t_u_u((safe_mod_func_uint64_t_u_u((safe_add_func_uint64_t_u_u((l_2278 = (((g_159 = (0x74L < (p_13 | (safe_lshift_func_int8_t_s_s(g_421[3][7][1], (safe_unary_minus_func_uint16_t_u((safe_mul_func_int8_t_s_s((l_2076 |= (safe_rshift_func_int16_t_s_u(((p_14 = (safe_add_func_uint16_t_u_u((g_506 <= (safe_mul_func_uint16_t_u_u((l_2248 = (l_2249 > ((safe_mul_func_int8_t_s_s(p_15.f1, g_559[6])) | 1L))), g_1145[0].f2))), g_594))) || 3UL), 13))), l_2277[2]))))))))) , l_2277[1]) >= g_1032[8])), (-1L))), l_2242[0])), p_16.f3))), 14))), (-1L))) , g_1109) && g_390) >= p_15.f0) , 0x21L) == g_312))) <= 0x9AL))) > 0UL)) ^ 255UL) != 0x697984F0L) , l_2278) && 0x84673B59ABD64EBBLL)) & g_2138) <= 0x8B1272E60FADCBF8LL) >= g_1304))))) , l_2249), g_1756[0][0][6], l_2277[1], g_1304, l_2282[2]);
        l_2298 ^= (safe_add_func_uint64_t_u_u(
            18446744073709551612UL,
            (((l_2166 = l_2277[2]) ^
              (safe_sub_func_uint64_t_u_u(
                  (p_16.f0 >=
                   (p_15.f2 =
                        (((((((g_1238 >
                               ((((l_2277[2] <
                                   (safe_mul_func_uint16_t_u_u(
                                       ((safe_sub_func_uint32_t_u_u(
                                            (safe_rshift_func_uint16_t_u_s(
                                                (~l_2282[2].f3), 10)),
                                            0UL)) ^
                                        (((g_1032[4],
                                           (((safe_unary_minus_func_int32_t_s(
                                                 (safe_rshift_func_uint8_t_u_u(
                                                     (((l_2279[1][9][1] > 0UL) ^
                                                       l_2279[2][1][0]) &
                                                      g_559[4]),
                                                     0)))) &&
                                             l_2297) <= l_2167)) &&
                                          l_2282[2].f0) ||
                                         4294967295UL)),
                                       0x001EL))),
                                  l_2242[0]) >= 3UL) &&
                                l_65.f0)) <= p_15.f0),
                             l_2278) > l_2277[1]) <= 4UL) ^
                          p_15.f1) ||
                         l_2279[0][6][1]))),
                  l_2080[1][1][7]))),
             g_388.f0)));
  }
  g_35 = p_16;
  return g_2299;
}

static uint8_t func_22(uint32_t p_23) { return p_23; }

static uint8_t func_41(int32_t p_42, uint8_t p_43, int32_t p_44, int64_t p_45,
                       uint32_t p_46) {
  uint16_t l_1480 = 0xA686L;
  int32_t l_1505 = 0L;
  int32_t l_1506 = (-9L);
  int16_t l_1507 = 0L;
  int32_t l_1508 = 0L;
  struct S0 l_1570[3][4][5] = {{{{0, -4L, -116, 7},
                                 {0, 0x5F448C1F958DC280LL, -423, 15},
                                 {0, 8L, -490, 8},
                                 {0, 8L, -490, 8},
                                 {0, 0x5F448C1F958DC280LL, -423, 15}},
                                {{0, 0xA638DFE240EFA1CBLL, -152, 11},
                                 {0, 0x919B657A6F0D3D43LL, -795, 11},
                                 {-0, 0x603356D2FC8A99DCLL, -575, 2},
                                 {0, -1L, 825, 10},
                                 {0, -1L, 825, 10}},
                                {{0, 0xA0191CBE08CA11F3LL, -235, 10},
                                 {-0, 0L, 386, 13},
                                 {0, 0xA0191CBE08CA11F3LL, -235, 10},
                                 {0, 8L, -490, 8},
                                 {0, 1L, 900, 6}},
                                {{0, 0L, 88, 3},
                                 {-0, 0xD3427C9C5EA38133LL, 50, 9},
                                 {0, -1L, 825, 10},
                                 {-0, 0xD3427C9C5EA38133LL, 50, 9},
                                 {0, 0L, 88, 3}}},
                               {{{0, 0xA0191CBE08CA11F3LL, -235, 10},
                                 {0, -4L, -116, 7},
                                 {-0, 0L, 386, 13},
                                 {0, 0x5F448C1F958DC280LL, -423, 15},
                                 {-0, 0L, 386, 13}},
                                {{0, 0xA638DFE240EFA1CBLL, -152, 11},
                                 {0, 0xA638DFE240EFA1CBLL, -152, 11},
                                 {0, -1L, 825, 10},
                                 {0, 0L, 88, 3},
                                 {0, 0xEAA05D5F758D6168LL, 987, 14}},
                                {{0, -4L, -116, 7},
                                 {0, 0xA0191CBE08CA11F3LL, -235, 10},
                                 {0, 0xA0191CBE08CA11F3LL, -235, 10},
                                 {0, -4L, -116, 7},
                                 {-0, 0L, 386, 13}},
                                {{-0, 0xD3427C9C5EA38133LL, 50, 9},
                                 {0, 0L, 88, 3},
                                 {-0, 0x603356D2FC8A99DCLL, -575, 2},
                                 {-0, 0x603356D2FC8A99DCLL, -575, 2},
                                 {0, 0L, 88, 3}}},
                               {{{-0, 0L, 386, 13},
                                 {0, 0xA0191CBE08CA11F3LL, -235, 10},
                                 {0, 8L, -490, 8},
                                 {0, 1L, 900, 6},
                                 {0, 1L, 900, 6}},
                                {{0, 0x919B657A6F0D3D43LL, -795, 11},
                                 {0, 0xA638DFE240EFA1CBLL, -152, 11},
                                 {0, 0x919B657A6F0D3D43LL, -795, 11},
                                 {-0, 0x603356D2FC8A99DCLL, -575, 2},
                                 {0, -1L, 825, 10}},
                                {{0, 0x5F448C1F958DC280LL, -423, 15},
                                 {0, -4L, -116, 7},
                                 {0, 1L, 900, 6},
                                 {0, -4L, -116, 7},
                                 {0, 0x5F448C1F958DC280LL, -423, 15}},
                                {{0, 0x919B657A6F0D3D43LL, -795, 11},
                                 {-0, 0xD3427C9C5EA38133LL, 50, 9},
                                 {0, 0xA638DFE240EFA1CBLL, -152, 11},
                                 {0, 0L, 88, 3},
                                 {0, 0xA638DFE240EFA1CBLL, -152, 11}}}};
  int32_t l_1694 = 0x478A7D77L;
  int32_t l_1695 = (-3L);
  int64_t l_1700 = (-2L);
  int32_t l_1701 = 1L;
  int32_t l_1702 = 0x753BEF4DL;
  int32_t l_1878 = 1L;
  uint8_t l_1943[8] = {0xFCL, 0xFCL, 0xFCL, 0xFCL, 0xFCL, 0xFCL, 0xFCL, 0xFCL};
  int i, j, k;
lbl_1950:
    if ((l_1480 != (safe_lshift_func_int8_t_s_s(g_420[1][7], ((safe_rshift_func_int8_t_s_s(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((g_312 ^= ((safe_sub_func_uint16_t_u_u(((~((((((l_1508 |= (l_1507 = (((g_754[1][9] ^= l_1480) <= (safe_lshift_func_int16_t_s_s((g_250 = ((0x5A0AL <= (((((l_1506 |= (p_44 , ((safe_add_func_int64_t_s_s((p_45 &= (safe_mul_func_int8_t_s_s((((safe_lshift_func_uint8_t_u_s((0xE2L && (((+9UL) , ((p_46 = (safe_lshift_func_int16_t_s_u((g_158 |= ((((((((safe_lshift_func_int8_t_s_s((l_1505 = (((p_44 < g_506) >= 4294967289UL) | l_1480)), 0)) , l_1480) , 0x2E28L) , l_1505) < g_594) == 0xE8L) >= 1L) <= 1L)), g_594))) == 0x47E48E4FL)) >= p_42)), 1)) && g_85) & (-1L)), 0x9BL))), g_2)) < l_1480))) > l_1480) == p_44) ^ 1UL) , p_46)) == p_44)), 15))) | 0xE2L))) && 0L) , g_754[1][4]) == g_388.f1) < l_1480) & p_42)) > 255UL), p_43)) ^ g_86)), l_1480)), p_44)) > 0L), g_390)) , 0x96L)))))
    {
      int32_t l_1509 = 0xCF0D3FA9L;
      struct S0 l_1528 = {0, 0L, -253, 2};
      l_1508 = (g_312, ((0L < l_1509), p_44));
      l_1506 ^=
          ((safe_mod_func_int16_t_s_s(
               ((l_1528.f0 =
                     (p_44 ||
                      (safe_add_func_int16_t_s_s(
                          g_754[5][3],
                          (safe_mul_func_uint8_t_u_u(
                              (safe_lshift_func_int16_t_s_u(
                                  (g_594 =
                                       (0L ||
                                        (((safe_rshift_func_uint8_t_u_s(
                                              (((((safe_rshift_func_int8_t_s_u(
                                                      0x7DL, 6)) |
                                                  ((p_42 |
                                                    (safe_mod_func_uint64_t_u_u(
                                                        p_42,
                                                        ((safe_sub_func_int64_t_s_s(
                                                             ((((((g_1145[0] =
                                                                       l_1528),
                                                                  0x95076570L) !=
                                                                 ((safe_rshift_func_int16_t_s_s(
                                                                      (safe_sub_func_int64_t_s_s(
                                                                          (safe_unary_minus_func_uint16_t_u(
                                                                              (safe_mul_func_uint8_t_u_u(
                                                                                  ((8UL ^
                                                                                    g_388
                                                                                        .f3),
                                                                                   0xF4L),
                                                                                  0x13L)))),
                                                                          p_44)),
                                                                      12)) !=
                                                                  p_44)) ||
                                                                0x48774AAAL) >
                                                               g_86) |
                                                              l_1480),
                                                             g_421[4][0][4])) ||
                                                         0x61CBL)))) >= 1L)) >=
                                                 p_43) ||
                                                (-3L)),
                                               0x77L),
                                              l_1507)) ||
                                          g_1109) &&
                                         p_43))),
                                  10)),
                              p_46)))))) |
                p_42),
               l_1528.f1)) == 2UL);
    } else {
      uint32_t l_1540 = 0xD67BC027L;
      uint32_t l_1560 = 4294967294UL;
      int32_t l_1561[4] = {1L, 1L, 1L, 1L};
      int32_t l_1595 = 0x125009E3L;
      int32_t l_1652[8][3] = {{0x51A4C3ECL, 0x51A4C3ECL, 0xBE2572F9L},
                              {0xBDEF01DCL, 0x4A792898L, 0xBE2572F9L},
                              {0x4A792898L, 0xBDEF01DCL, 0xBE2572F9L},
                              {0x51A4C3ECL, 0x51A4C3ECL, 0xBE2572F9L},
                              {0xBDEF01DCL, 0x4A792898L, 0xBE2572F9L},
                              {0x4A792898L, 0xBDEF01DCL, 0xBE2572F9L},
                              {0x51A4C3ECL, 0x51A4C3ECL, 0xBE2572F9L},
                              {0xBDEF01DCL, 0x4A792898L, 0xBE2572F9L}};
      int i, j;
      for (g_355 = 0; (g_355 == 20);
           g_355 = safe_add_func_int32_t_s_s(g_355, 2)) {
        struct S0 l_1553 = {0, -6L, 721, 14};
        if (((safe_sub_func_int32_t_s_s(g_1021[3], (l_1540 ^= g_35.f2))) &&
             ((g_750[0][4][0] = (safe_sub_func_uint64_t_u_u(
                   (safe_rshift_func_uint8_t_u_u(
                       ((((g_131 =
                               ((g_1109 = 0x55L) >
                                ((4294967292UL != 0xE28497BAL) >=
                                 (safe_lshift_func_uint8_t_u_s(
                                     (((safe_mul_func_int8_t_s_s(
                                           (safe_lshift_func_uint8_t_u_s(
                                               ((safe_sub_func_int8_t_s_s(
                                                    ((l_1553,
                                                      ((safe_rshift_func_uint8_t_u_s(
                                                           (((safe_rshift_func_uint8_t_u_s(
                                                                 (l_1505 |=
                                                                  p_46),
                                                                 ((safe_lshift_func_int8_t_s_s(
                                                                      2L, 2)),
                                                                  0x61L))) !=
                                                             g_1031) &
                                                            l_1553.f1),
                                                           l_1553.f0)) !=
                                                       p_42)) &&
                                                     l_1506),
                                                    250UL)) &&
                                                p_45),
                                               p_44)),
                                           g_1304)) ^
                                       l_1506) == (-1L)),
                                     p_46))))),
                          p_43) >= 0L),
                        l_1560),
                       0)),
                   g_1241))),
              l_1553.f2))) {
          int32_t l_1563 = (-8L);
          int32_t l_1565 = (-3L);
          struct S0 l_1569 = {-0, 0L, 810, 1};
          l_1561[1] = 0x2F15491AL;
          for (p_44 = 3; (p_44 >= 0); p_44 -= 1) {
            uint32_t l_1566 = 2UL;
            int32_t l_1622 = 0x52D880B5L;
            for (g_159 = 0; (g_159 <= 3); g_159 += 1) {
              int32_t l_1562 = 0xC5F11417L;
              int32_t l_1564[4][2] = {{3L, 3L}, {3L, 3L}, {3L, 3L}, {3L, 3L}};
              int i, j;
              if (g_420[g_159][(p_44 + 4)])
                break;
              l_1566--;
              return g_2;
            }
            for (g_1241 = 0; (g_1241 <= 0); g_1241 += 1) {
              int32_t l_1581 = 0xEA029340L;
              int i;
              l_1570[0][1][2] = l_1569;
              p_42 = g_1032[(g_1241 + 8)];
              g_421[4][4][1] |=
                  ((safe_mul_func_int8_t_s_s(
                       (safe_rshift_func_int16_t_s_s(
                           (((((g_1032[(p_44 + 5)], 1UL) ||
                               (safe_add_func_int8_t_s_s(
                                   g_388.f1, (safe_rshift_func_uint8_t_u_s(
                                                 (p_42 & g_2), 7))))),
                              ((safe_rshift_func_int16_t_s_u(
                                   (l_1553.f2 =
                                        (((((l_1581 = 0xC8D8L) !=
                                            (safe_add_func_int16_t_s_s(
                                                (g_2 ^ p_43), l_1569.f3))),
                                           0L) < 7L) > 2UL)),
                                   p_44)) > g_390)) > g_1021[3]) &
                            l_1566),
                           0)),
                       g_158)) |
                   p_42);
              g_755[7] |=
                  (p_44,
                   (safe_add_func_uint8_t_u_u(
                       l_1561[1],
                       (safe_lshift_func_int16_t_s_u(
                           ((safe_mod_func_uint32_t_u_u(
                                ((safe_mul_func_uint8_t_u_u(
                                     l_1570[0][1][2].f3,
                                     ((((+(g_1304 <
                                           ((safe_add_func_int16_t_s_s(
                                                (l_1595 = ((-9L) & p_44)),
                                                g_388.f0)) <
                                            ((safe_rshift_func_uint16_t_u_u(
                                                 (safe_unary_minus_func_uint8_t_u(
                                                     g_754[1][9])),
                                                 ((((g_35.f3 ^ g_1145[0].f0) >
                                                    l_1553.f0) |
                                                   0xD81381D4L) == 3L))) &&
                                             g_750[0][3][0])))) &
                                        p_45) != g_355) |
                                      g_203))),
                                 g_158),
                                g_1109)) |
                            5UL),
                           0)))));
            }
            for (p_43 = (-30); (p_43 >= 2);
                 p_43 = safe_add_func_uint16_t_u_u(p_43, 6)) {
              uint32_t l_1623 = 0x19F8F8ABL;
              int8_t l_1651 = 0xC4L;
              g_421[2][3][3] =
                  ((((safe_lshift_func_uint16_t_u_s(
                         g_153, (safe_mul_func_int8_t_s_s(0xAEL, g_203)))) >
                     (safe_lshift_func_int8_t_s_s(
                         (l_1570[0][1][2].f2 ^
                          ((l_1561[1] = (safe_add_func_int8_t_s_s(
                                ((safe_lshift_func_int16_t_s_u(
                                     (((g_755[7] >
                                        (l_1622 =
                                             ((safe_mul_func_uint8_t_u_u(
                                                  (safe_mul_func_int16_t_s_s(
                                                      ((g_153 &
                                                        ((safe_sub_func_uint16_t_u_u(
                                                             (((p_44 <
                                                                ((p_45 ^=
                                                                  l_1553.f2) &
                                                                 (!(safe_add_func_int8_t_s_s(
                                                                     g_203,
                                                                     l_1566))))) ||
                                                               g_420[3][6]) |
                                                              p_42),
                                                             g_35.f3)) ||
                                                         0x04L)) &&
                                                       0UL),
                                                      0x58F7L)),
                                                  l_1566)) == g_750[0][4][0]))),
                                       p_46) ^
                                      p_43),
                                     l_1623)) |
                                 0x00L),
                                g_312))) |
                           l_1595)),
                         3))) ||
                    l_1569.f3) |
                   1L);
              p_42 ^=
                  ((safe_add_func_uint16_t_u_u(
                       g_754[1][0],
                       (safe_add_func_int8_t_s_s(
                           ((p_43 <
                             (safe_add_func_uint32_t_u_u(
                                 (l_1622 = 1UL),
                                 (l_1553.f3 !=
                                  (l_1565 ^=
                                   ((0x27751B71CBB9CA87LL && 8L) ||
                                    (safe_rshift_func_int16_t_s_s(
                                        ((((safe_mul_func_uint8_t_u_u(
                                               (((safe_unary_minus_func_int16_t_s((
                                                     (safe_add_func_int8_t_s_s(
                                                         (safe_mod_func_uint32_t_u_u(
                                                             (((g_388.f3 =
                                                                    (0x4258DEEEF776DBDBLL <
                                                                     (p_45 >
                                                                      (g_1145[0]
                                                                           .f3 =
                                                                           1UL)))) <=
                                                               g_203) < g_251),
                                                             g_356)),
                                                         p_43)) <= 0L))),
                                                 p_43) == 1UL),
                                               0x66L)) == l_1623) ^
                                          l_1570[0][1][2].f0) != 3L),
                                        l_1553.f2)))))))),
                            g_754[2][4]),
                           0xC7L)))) &&
                   p_43);
              g_755[1] =
                  ((safe_rshift_func_int8_t_s_s(
                       ((!((p_46 >=
                            (safe_mul_func_uint16_t_u_u(
                                l_1570[0][1][2].f1,
                                ((p_46 >
                                  ((4L || (+l_1570[0][1][2].f1)) >=
                                   (((l_1622 =
                                          (g_391 =
                                               (((safe_sub_func_int64_t_s_s(
                                                     (safe_sub_func_uint64_t_u_u(
                                                         (((l_1565 |
                                                            ((((g_1145[0],
                                                                ((((safe_sub_func_uint32_t_u_u(
                                                                       0xA8D8CFA5L,
                                                                       l_1623)) ==
                                                                   g_1145[0]
                                                                       .f2),
                                                                  0xE338L),
                                                                 0x455D144CAF2D42E0LL)) >
                                                               0x1DC56EAE6A15FC71LL),
                                                              0UL) &
                                                             g_1021[0])),
                                                           1UL) ^
                                                          p_45),
                                                         p_42)),
                                                     l_1622)) > 0L) >=
                                                l_1651))) < 0x6EL),
                                    g_1021[3]))) ||
                                 l_1652[7][1])))) != p_43)) != l_1506),
                       p_44)),
                   p_46);
            }
          }
        } else {
          if (p_43)
            break;
          return g_390;
        }
      }
    }
lbl_1944:
  g_755[7] = p_45;
  for (l_1508 = (-21); (l_1508 < 8); l_1508++) {
    int8_t l_1659 = 0x68L;
    struct S0 l_1663 = {-0, -9L, -126, 13};
    int8_t l_1683 = 1L;
    int32_t l_1687 = 0x93EC0BEEL;
    int32_t l_1688[3][8] = {
        {0L, 0x149F5A57L, 0x149F5A57L, 0L, 5L, 0L, 0x149F5A57L, 0x149F5A57L},
        {0x149F5A57L, 5L, 0x40D7E66EL, 0x40D7E66EL, 5L, 0x149F5A57L, 5L,
         0x40D7E66EL},
        {0L, 5L, 0L, 0x149F5A57L, 0x149F5A57L, 0L, 5L, 0L}};
    int16_t l_1703 = 4L;
    uint16_t l_1775 = 65535UL;
    uint16_t l_1804 = 0UL;
    uint16_t l_1846[10] = {0x61C4L, 0x61C4L, 0x61C4L, 0x61C4L, 0x61C4L,
                           0x61C4L, 0x61C4L, 0x61C4L, 0x61C4L, 0x61C4L};
    int i, j;
    if ((safe_mul_func_int16_t_s_s((p_43 != l_1570[0][1][2].f0), p_45))) {
      uint32_t l_1671[7] = {0xF6634759L, 0xF6634759L, 4294967295UL,
                            0xF6634759L, 0xF6634759L, 4294967295UL,
                            0xF6634759L};
      int32_t l_1674 = 0x0055A716L;
      int32_t l_1675 = 1L;
      int32_t l_1681 = 0x59A68BC2L;
      int32_t l_1684 = 0L;
      int64_t l_1686[7] = {1L, 9L, 9L, 1L, 9L, 9L, 1L};
      int32_t l_1690 = 0x01BDA021L;
      int32_t l_1691 = (-1L);
      int32_t l_1692 = (-1L);
      int32_t l_1693 = 0x518E5F60L;
      int32_t l_1696 = 1L;
      int32_t l_1697 = 0xA236570EL;
      int64_t l_1698 = 0x77425D4EB635C43FLL;
      int32_t l_1699[4][4][9] = {
          {{0x0DFF2D4DL, 0x67B6FE84L, 3L, 0L, (-9L), 0x85DD40FAL, 0x85DD40FAL,
            (-9L), 0L},
           {0L, 2L, 0x9AF78BB7L, 0x8D1496C3L, (-1L), 1L, (-9L), 0x6E77FF6AL,
            0xAE84A9E9L},
           {(-6L), 0x85DD40FAL, 0x4CC372A8L, 0x0814267AL, 0xD1914A2FL, 0L, 9L,
            1L, 0x67B6FE84L},
           {1L, 0x14984E48L, 0L, 0x8D1496C3L, 0x8D1496C3L, 0L, 0x14984E48L, 1L,
            0x9AF78BB7L}},
          {{1L, 8L, 0xD445C3F2L, 0x85DD40FAL, 0xD9EEB9E2L, 0x67B6FE84L,
            0x4CC372A8L, (-9L), (-1L)},
           {0x14984E48L, 0x77DC027AL, 0x6E77FF6AL, 0L, 0x9AF78BB7L, 0x7712D497L,
            0x1E4C50FBL, 0x7712D497L, 0x9AF78BB7L},
           {0x2D8F540FL, 9L, 9L, 0x2D8F540FL, 0x0DFF2D4DL, 0xD1914A2FL, 1L, 1L,
            0x67B6FE84L},
           {0L, 0x6E77FF6AL, 0x77DC027AL, 0x14984E48L, 2L, 0x3FC9230DL, (-1L),
            (-1L), 0xAE84A9E9L}},
          {{0x85DD40FAL, 0xD445C3F2L, 8L, 1L, 0x0DFF2D4DL, 1L, 8L, 0xD445C3F2L,
            0x85DD40FAL},
           {0x8D1496C3L, 0L, 0x14984E48L, 1L, 0x9AF78BB7L, 0x60988423L, 2L,
            0xC3E15649L, 0L},
           {0x0814267AL, 0x4CC372A8L, 0x85DD40FAL, (-6L), 0xD9EEB9E2L, 6L,
            0x2D8F540FL, 0x2D8F540FL, 6L},
           {0x8D1496C3L, 0x9AF78BB7L, 2L, 0x9AF78BB7L, 0x8D1496C3L, (-1L), 1L,
            (-9L), 0x6E77FF6AL}},
          {{0x85DD40FAL, 0L, 8L, 9L, 0xD1914A2FL, (-8L), 0x67B6FE84L, (-6L),
            3L},
           {0L, 0x7712D497L, 0x3FC9230DL, 0x60988423L, (-1L), (-1L),
            0x60988423L, 0x3FC9230DL, 0x7712D497L},
           {0x2D8F540FL, (-8L), 0x0DFF2D4DL, 3L, (-1L), 6L, 0xD445C3F2L, 0L,
            1L},
           {0x14984E48L, 0x1E4C50FBL, (-1L), 2L, 1L, 0x60988423L, 0x14656A2CL,
            0L, 0x14656A2CL}}};
      int i, j, k;
      for (g_1103 = 22; (g_1103 >= (-24)); g_1103--) {
        int64_t l_1660 = (-3L);
        int32_t l_1677 = 0xAFDE80E8L;
        int16_t l_1678 = 0xDB8FL;
        int32_t l_1679 = 0x6801BD39L;
        int32_t l_1680[8] = {0x78F72E0AL, (-1L),       0x78F72E0AL, 0x78F72E0AL,
                             (-1L),       0x78F72E0AL, 0x78F72E0AL, (-1L)};
        int i;
        l_1663 =
            func_59(l_1659, l_1660,
                    (safe_rshift_func_int16_t_s_s(0xDF77L, p_43)), p_44, g_35);
        for (l_1660 = 29; (l_1660 == (-12));
             l_1660 = safe_sub_func_uint8_t_u_u(l_1660, 5)) {
          int32_t l_1668 = (-3L);
          int32_t l_1669[6] = {0x07A58CFBL, 0x07A58CFBL, 0x07A58CFBL,
                               0x07A58CFBL, 0x07A58CFBL, 0x07A58CFBL};
          uint8_t l_1704 = 0x9EL;
          int i;
          for (p_42 = 0; (p_42 >= (-17)); p_42--) {
            int16_t l_1670 = 0L;
            int32_t l_1676[2][4];
            int64_t l_1682[9][5][4] = {
                {{0x6732FF54BC2A11FFLL, 0x6BBAFD526EAF602ALL, 4L, (-2L)},
                 {0xE9786CC3B43859CDLL, (-1L), 4L, 0x052742F788C24B4ALL},
                 {0x6732FF54BC2A11FFLL, 0x23AB060579F08B69LL, 1L, (-1L)},
                 {5L, (-2L), 7L, 0xDB7DE70E1BA03263LL},
                 {7L, 0xDB7DE70E1BA03263LL, 1L, 4L}},
                {{7L, 5L, 0x4E997535E161243DLL, (-2L)},
                 {(-2L), (-1L), (-1L), 1L},
                 {0x07C612C0D1FE874FLL, (-2L), 5L, 0L},
                 {0x23AB060579F08B69LL, (-7L), (-7L), 0x23AB060579F08B69LL},
                 {0x4E997535E161243DLL, 8L, (-1L), 5L}},
                {{0x5754C9976333A066LL, 0x052742F788C24B4ALL,
                  0x6732FF54BC2A11FFLL, (-1L)},
                 {0x23AB060579F08B69LL, 0x5754C9976333A066LL,
                  0x4B81A943D3112FFELL, (-1L)},
                 {(-1L), 0xE9786CC3B43859CDLL, 0xEC56D6EB7BF54C2FLL, 1L},
                 {0xC577C02034A491E8LL, 4L, 0xF8C6D5014338E6A6LL,
                  0xBB4E13E686D031EBLL},
                 {0x07C612C0D1FE874FLL, 0x23AB060579F08B69LL,
                  0xC577C02034A491E8LL, 5L}},
                {{1L, 1L, 0xBB4E13E686D031EBLL, (-8L)},
                 {0x052742F788C24B4ALL, 0x0F0F46911BB26E6ALL,
                  0xB9BDF6D0978099C8LL, 1L},
                 {0xE9786CC3B43859CDLL, 1L, 0x7F7F5033671C4641LL, (-1L)},
                 {(-1L), 0x6BBAFD526EAF602ALL, (-8L), 0x6BBAFD526EAF602ALL},
                 {(-1L), 1L, 0x6BBAFD526EAF602ALL, 0x4E997535E161243DLL}},
                {{0x4E997535E161243DLL, 0xBB4E13E686D031EBLL, 5L,
                  0xE9786CC3B43859CDLL},
                 {0x4B81A943D3112FFELL, 0xDB7DE70E1BA03263LL, 4L,
                  0x236A23DEFD385C8CLL},
                 {0x4B81A943D3112FFELL, (-1L), 5L, 0x6732FF54BC2A11FFLL},
                 {0x4E997535E161243DLL, 0x236A23DEFD385C8CLL,
                  0x6BBAFD526EAF602ALL, (-2L)},
                 {(-1L), 5L, (-8L), 0x052742F788C24B4ALL}},
                {{(-1L), (-1L), 0x7F7F5033671C4641LL, (-1L)},
                 {0xE9786CC3B43859CDLL, 0x7F7F5033671C4641LL,
                  0xB9BDF6D0978099C8LL, (-1L)},
                 {0x052742F788C24B4ALL, 7L, 0xBB4E13E686D031EBLL, (-7L)},
                 {1L, 0x6732FF54BC2A11FFLL, 0xC577C02034A491E8LL,
                  0xC577C02034A491E8LL},
                 {0x07C612C0D1FE874FLL, 0x07C612C0D1FE874FLL,
                  0xF8C6D5014338E6A6LL, 5L}},
                {{0xC577C02034A491E8LL, (-2L), 0xEC56D6EB7BF54C2FLL, 4L},
                 {(-1L), (-2L), 0x4B81A943D3112FFELL, 0xEC56D6EB7BF54C2FLL},
                 {0x23AB060579F08B69LL, (-2L), 0x6732FF54BC2A11FFLL, 4L},
                 {(-2L), (-2L), 0x0F0F46911BB26E6ALL, 5L},
                 {8L, 0x07C612C0D1FE874FLL, 0x23AB060579F08B69LL,
                  0xC577C02034A491E8LL}},
                {{0xBB4E13E686D031EBLL, 0x6732FF54BC2A11FFLL, 1L, (-7L)},
                 {0xF8C6D5014338E6A6LL, 7L, 0x4E997535E161243DLL, (-1L)},
                 {1L, 0x7F7F5033671C4641LL, 8L, (-1L)},
                 {5L, (-1L), 1L, 0x052742F788C24B4ALL},
                 {0x5754C9976333A066LL, 5L, 0x5754C9976333A066LL, (-2L)}},
                {{1L, 0x236A23DEFD385C8CLL, 0x07C612C0D1FE874FLL,
                  0x6732FF54BC2A11FFLL},
                 {(-2L), (-1L), (-1L), 0x236A23DEFD385C8CLL},
                 {(-1L), 0xDB7DE70E1BA03263LL, (-1L), 0xE9786CC3B43859CDLL},
                 {(-2L), 0xBB4E13E686D031EBLL, 0x07C612C0D1FE874FLL,
                  0x4E997535E161243DLL},
                 {1L, 1L, 0x5754C9976333A066LL, 0x6BBAFD526EAF602ALL}}};
            int32_t l_1685 = (-1L);
            int32_t l_1689[4][5][2] = {
                {{0L, (-1L)}, {0L, 0L}, {(-1L), 0L}, {0L, (-1L)}, {0L, 0L}},
                {{(-1L), 0L}, {0L, (-1L)}, {0L, 0L}, {(-1L), 0L}, {0L, (-1L)}},
                {{0L, 0L}, {(-1L), 0L}, {0L, (-1L)}, {0L, 0L}, {(-1L), 0L}},
                {{0L, (-1L)}, {0L, 0L}, {(-1L), 0L}, {0L, (-1L)}, {0L, 0L}}};
            int i, j, k;
            for (i = 0; i < 2; i++) {
              for (j = 0; j < 4; j++)
                l_1676[i][j] = 0x7C429BD2L;
            }
            --l_1671[0];
            ++l_1704;
          }
        }
      }
      if (p_45)
        continue;
      for (g_40 = 0; (g_40 > 39); g_40++) {
        int8_t l_1709 = 1L;
        int32_t l_1731 = 1L;
        l_1688[1][7] |=
            ((((((l_1709 &&
                  (safe_mul_func_int8_t_s_s(
                      p_43,
                      (((g_421[3][7][1] = (safe_rshift_func_int8_t_s_s(
                             (((safe_mul_func_int16_t_s_s(
                                   g_754[5][5], l_1570[0][1][2].f2)) != p_44),
                              (safe_add_func_uint64_t_u_u(
                                  g_2,
                                  (safe_sub_func_int64_t_s_s(
                                      ((safe_rshift_func_uint8_t_u_u(
                                           (l_1731 = (safe_rshift_func_uint16_t_u_s(
                                                g_750
                                                    [0][4][0],
                                                (~((((g_388.f1,
                                                      (safe_rshift_func_int16_t_s_s(
                                                          (safe_rshift_func_int8_t_s_u(
                                                              ((safe_lshift_func_int16_t_s_u(
                                                                   g_1103,
                                                                   p_43)) <
                                                               0x1AE79D3CL),
                                                              p_44)),
                                                          l_1570[0][1][2]
                                                              .f3))) < p_42) !=
                                                    l_1700),
                                                   g_35.f0))))),
                                           g_388.f2)) != p_46),
                                      0x85F5D5590CD21471LL))))),
                             1))) |
                        0xB6AB9AAFL) == g_1238)))) > g_203) &
                g_754[1][9]) < p_44),
              p_46) > 0x240EL);
      }
      g_1732[0][1]--;
    } else {
      uint32_t l_1755 = 0xA94A7E75L;
      int32_t l_1847 = 0xD31869CDL;
      int32_t l_1859 = 0L;
      int16_t l_1919 = 0x1A5FL;
      for (l_1507 = 0; (l_1507 <= 2); l_1507 += 1) {
        int32_t l_1805[9];
        int32_t l_1806 = 0x8B9D0E0BL;
        int i;
        for (i = 0; i < 9; i++)
          l_1805[i] = 0xBCD4AB51L;
        for (l_1683 = 0; (l_1683 <= 2); l_1683 += 1) {
          int32_t l_1735 = (-1L);
          for (g_40 = 0; (g_40 <= 5); g_40 += 1) {
            uint16_t l_1749 = 3UL;
            int i, j;
            if (l_1735)
              break;
            l_1688[l_1683][(g_40 + 1)] =
                ((g_750[0][4][0] |=
                  (((((safe_add_func_int8_t_s_s(
                          ((safe_add_func_int32_t_s_s(
                               g_35.f1,
                               (safe_add_func_int32_t_s_s(
                                   (safe_mul_func_int16_t_s_s(
                                       (l_1755 =
                                            ((l_1735,
                                              (+(safe_mod_func_int64_t_s_s(
                                                  ((((safe_add_func_int32_t_s_s(
                                                         ((l_1749 ==
                                                           (safe_mod_func_int32_t_s_s(
                                                               (((0xF7L |
                                                                  l_1570
                                                                      [0][1][2]
                                                                          .f0) >
                                                                 ((safe_unary_minus_func_uint32_t_u(
                                                                      1UL)) |
                                                                  ((safe_add_func_int16_t_s_s(
                                                                       0L,
                                                                       (g_1238,
                                                                        0x8542L))),
                                                                   0x90F3FAD7B2A48AA1LL))) >
                                                                p_42),
                                                               0xA083447AL))) ^
                                                          p_45),
                                                         l_1735)) != 65535UL),
                                                    l_1663.f0) ==
                                                   0x7F333B29554B8918LL),
                                                  l_1687)))),
                                             6L)),
                                       g_1304)),
                                   5UL)))) &&
                           g_1756[0][0][6]),
                          l_1735)) > l_1749) ^
                     l_1570[0][1][2].f2) < g_1732[1][3]) <= g_755[7])) &&
                 g_755[3]);
            l_1663 = l_1570[2][3][3];
          }
          return p_44;
        }
        for (g_86 = 0; (g_86 <= 2); g_86 += 1) {
          int64_t l_1757 = 0xF0B5ECA019CF6F4CLL;
          int32_t l_1803 = (-8L);
          for (g_1238 = 0; (g_1238 <= 2); g_1238 += 1) {
            int i, j;
            l_1688[g_1238][(g_1238 + 1)] &=
                (l_1757 ^
                 ((((((safe_rshift_func_int16_t_s_s(
                          (safe_rshift_func_uint16_t_u_s(
                              ((safe_mul_func_uint8_t_u_u(
                                   g_1021[3],
                                   (((safe_mul_func_int16_t_s_s(
                                         (l_1687 = 0x7E23L),
                                         (safe_mul_func_int16_t_s_s(
                                             l_1663.f2, g_755[7])))) <= p_42) <=
                                    (safe_lshift_func_int16_t_s_u(
                                        ((((safe_sub_func_uint16_t_u_u(
                                               (l_1663,
                                                (l_1570[0][1][2].f0 =
                                                     ((safe_add_func_int64_t_s_s(
                                                          (((((~g_85) < p_44),
                                                             0x9CCF57E0L) ^
                                                            p_46) < l_1659),
                                                          18446744073709551610UL)),
                                                      8UL))),
                                               l_1775)) >= g_35.f3) > p_42),
                                         l_1663.f1),
                                        g_35.f0))))) < g_153),
                              12)),
                          15)),
                      1L),
                     p_44) != g_391) <= g_1145[0].f0) |
                  18446744073709551608UL));
          }
                    p_42 = ((safe_rshift_func_int8_t_s_s((l_1570[1][2][1] , (safe_mul_func_uint16_t_u_u((g_754[1][9] && ((safe_mul_func_uint8_t_u_u(g_1032[2], (safe_add_func_uint64_t_u_u((((safe_lshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s((0L ^ ((safe_rshift_func_int16_t_s_s((l_1806 ^= ((safe_mod_func_uint32_t_u_u((g_1304 = (safe_unary_minus_func_uint64_t_u((l_1755 <= (((safe_mul_func_int16_t_s_s((-1L), (((((l_1688[1][7] = (0xD8L < (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(p_43, ((l_1803 ^= l_1663.f0) <= l_1804))) >= g_35.f0), 13)), 0x497C0E7CL)))) <= l_1805[4]) , 0UL) <= 0xCDE57A9AA4421596LL) < g_1732[1][2]))) > 1L) || l_1805[4]))))), 0x4C2B4452L)) | 0x126A966AL)), 5)) >= l_1755)), 0x2443L)), p_46)) && p_43), 0)) <= l_1757) >= p_43), g_35.f0)))) , p_43)), g_1103))), 0)) <= g_316);
                    for (l_1703 = 3; (l_1703 >= 0); l_1703 -= 1) {
                      int32_t l_1814 = 1L;
                      int32_t l_1860[10] = {
                          0xA7FDE534L, 0xA7FDE534L, 0xA7FDE534L, 0xA7FDE534L,
                          0xA7FDE534L, 0xA7FDE534L, 0xA7FDE534L, 0xA7FDE534L,
                          0xA7FDE534L, 0xA7FDE534L};
                      int i;
                      p_42 = (+(
                          ((+(((~g_1145[0].f1) ^ 0xB9B1L) >=
                              (0L <=
                               (safe_rshift_func_uint16_t_u_u(
                                   p_42,
                                   (g_754[1][1] |
                                    (g_35.f2,
                                     (p_44,
                                      (l_1814 |=
                                       (g_85 |
                                        (safe_mod_func_uint64_t_u_u(
                                            (0x720FL == 0x14D4L),
                                            0x1E7B790C5A96D6B6LL)))))))))))) &&
                           (-10L)) ||
                          0x750EAB0D19958733LL));
                      g_1103 ^= (safe_mul_func_uint16_t_u_u(
                          (p_43 <=
                           ((l_1702 = l_1805[4]) |
                            ((safe_lshift_func_uint16_t_u_u(
                                 l_1703,
                                 ((l_1803 = (~(safe_rshift_func_uint8_t_u_u(
                                       (safe_rshift_func_int8_t_s_s(
                                           (((safe_add_func_uint8_t_u_u(
                                                 ((2L &
                                                   (safe_sub_func_uint32_t_u_u(
                                                       l_1805[4],
                                                       (0UL == 0x194D4B58L)))) ^
                                                  (p_43,
                                                   ((safe_lshift_func_uint8_t_u_s(
                                                        l_1814, l_1755)),
                                                    g_316))),
                                                 p_42)) &&
                                             1UL) < l_1814),
                                           0)),
                                       l_1755)))) < g_420[0][6]))),
                             0x14B6B08078D36450LL))),
                          p_43));
                      l_1688[1][6] = 8L;
                        l_1860[9] = (((safe_sub_func_uint32_t_u_u((((((safe_sub_func_uint32_t_u_u((l_1803 ^= (g_559[6] || (l_1814 = ((safe_mul_func_uint8_t_u_u(((((p_43 && ((safe_add_func_int64_t_s_s((g_131 &= (g_35.f1 &= ((g_391 |= ((safe_mul_func_uint16_t_u_u((safe_add_func_int32_t_s_s(g_35.f3, ((safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(((l_1805[0] < (l_1847 = l_1846[1])) <= (l_1806 &= ((safe_rshift_func_int16_t_s_s(p_46, (safe_add_func_uint8_t_u_u((g_559[6] < (safe_mul_func_uint8_t_u_u((safe_sub_func_int16_t_s_s(l_1703, (!(l_1859 = (safe_add_func_uint16_t_u_u(1UL, p_44)))))), 0xD7L))), g_388.f2)))) >= 7UL))), g_35.f2)), 0xCBF53042L)) && g_312))), g_1238)) > 0UL)) , (-1L)))), 8UL)) == g_312)) == p_44) >= g_388.f0) || 0x3AL), 0x08L)) & 0xD33166D4L)))), l_1860[9])) , p_44) | 1UL) | l_1755) == p_44), 4294967290UL)) & 0xF793L) <= 0L);
                    }
        }
      }
      if ((249UL |
           (((((g_35.f3 ||
                (l_1847 = (safe_mul_func_int16_t_s_s(
                     (g_1145[0],
                      (safe_sub_func_int8_t_s_s(
                          ((safe_rshift_func_int8_t_s_u(
                               ((safe_rshift_func_uint16_t_u_u(
                                    (g_420[1][0] =
                                         (((safe_mul_func_uint8_t_u_u(
                                               0xBEL, l_1570[0][1][2].f0)),
                                           ((+4UL) <=
                                            (safe_mod_func_uint32_t_u_u(
                                                ((safe_rshift_func_int16_t_s_u(
                                                     l_1570[0][1][2].f1, 15)) ^
                                                 p_45),
                                                (safe_sub_func_int8_t_s_s(
                                                    0x6DL, p_45)))))) ^
                                          l_1878)),
                                    9)) |
                                (-2L)),
                               l_1804)) <= 0L),
                          (-1L)))),
                     0xBA85L)))) != 0xF2EF4BFC09FD468BLL) >= g_1021[3]),
             p_43) > p_43))) {
        uint8_t l_1920 = 0x00L;
        int32_t l_1934 = (-4L);
        int32_t l_1976 = 0x8AAAFA19L;
        if ((safe_sub_func_uint16_t_u_u(
                (--g_420[2][1]),
                (safe_mod_func_uint32_t_u_u(
                    (((g_594 ||
                       (l_1570[0][1][2].f1 ^
                        ((safe_unary_minus_func_int64_t_s(
                             (safe_sub_func_int16_t_s_s(
                                 ((+((l_1847, p_44),
                                     (((safe_mul_func_uint8_t_u_u(
                                           (((safe_add_func_int8_t_s_s(
                                                 l_1846[5], g_1756[0][0][6])),
                                             l_1700) <= 0x7B3D9A4FL),
                                           ((l_1859 =
                                                 ((safe_mul_func_int8_t_s_s(
                                                      (0L > p_46), l_1507)) ||
                                                  (-9L))) == l_1755))) |
                                       0x75CBL) &
                                      4294967293UL))) > g_2),
                                 0xF776L)))) &&
                         p_42))),
                      255UL) != 1UL),
                    0xA5C9F54EL))))) {
          int64_t l_1933 = (-5L);
          if (p_42)
            break;
          l_1663 =
              (l_1570[0][1][2] = func_59(
                   ((safe_mul_func_int8_t_s_s(
                        (safe_rshift_func_uint16_t_u_s(
                            (safe_rshift_func_int8_t_s_u(
                                p_44,
                                ((safe_add_func_uint8_t_u_u(
                                     ((safe_lshift_func_uint16_t_u_s(
                                          (l_1687 = (safe_mul_func_uint16_t_u_u(
                                               p_44, 2L))),
                                          3)) ||
                                      (0x5B2F29FC099F4C81LL ^
                                       (safe_rshift_func_int8_t_s_s(
                                           0x97L,
                                           (((safe_sub_func_int16_t_s_s(
                                                 ((safe_sub_func_int16_t_s_s(
                                                      (safe_add_func_uint16_t_u_u(
                                                          (safe_rshift_func_uint8_t_u_u(
                                                              0xACL, 1)),
                                                          (p_42 ||
                                                           (safe_rshift_func_int8_t_s_u(
                                                               p_45,
                                                               (l_1919 =
                                                                    g_35.f1)))))),
                                                      p_46)) ^
                                                  g_1021[3]),
                                                 p_45)) != l_1920) ==
                                            l_1505))))),
                                     g_1732[0][1])) ||
                                 1UL))),
                            10)),
                        2UL)),
                    0x104F9257L),
                   g_1732[0][2], g_1756[0][0][0], l_1920, g_1145[0]));
          g_388.f2 = (safe_rshift_func_uint8_t_u_s(
              (0xD0F7L || 0L),
              (l_1847 =
                   ((((p_43 ^ p_42) ^
                      (l_1934 |=
                       (l_1920 |
                        (((((((((safe_mul_func_uint16_t_u_u(
                                    ((!p_43) <=
                                     (safe_lshift_func_int8_t_s_u(
                                         ((safe_mul_func_int8_t_s_s(
                                              ((safe_rshift_func_uint8_t_u_s(
                                                   (!p_42), g_755[7])) ||
                                               1UL),
                                              l_1933)) == 1L),
                                         3))),
                                    l_1933)) < l_1933) &&
                               l_1755) ^
                              (-1L)),
                             0x93E1L) &
                            p_45) != (-1L)) ||
                          (-1L)) <= l_1570[0][1][2].f0)))) &
                     g_388.f0) <= l_1755))));
        } else {
          g_1935++;
          if ((p_42 = (8L < l_1859))) {
            int64_t l_1942 = 0x48C5EE7FFAAB482ELL;
            l_1943[0] ^=
                ((safe_lshift_func_int8_t_s_u(
                     (l_1934 = (safe_add_func_int16_t_s_s(0x0DD1L, p_43))),
                     (g_86 |= 0xFFL))),
                 (l_1942 = 0L));
            if (g_388.f1)
              goto lbl_1944;
            p_42 = (safe_mod_func_uint16_t_u_u(
                ((((p_46 == (-10L)) <= 1UL) < (+g_420[1][5])), p_42),
                (safe_mul_func_int8_t_s_s(g_2, 251UL))));
          } else {
            if (l_1480)
              goto lbl_1950;
            return l_1847;
          }
        }
        l_1976 =
            ((((safe_sub_func_uint16_t_u_u(g_159, l_1934)) &&
               (safe_mod_func_uint64_t_u_u(
                   (safe_lshift_func_int8_t_s_s(
                       (18446744073709551613UL ||
                        (safe_add_func_int8_t_s_s(
                            (((safe_sub_func_uint16_t_u_u(
                                  0xEA55L,
                                  (((safe_rshift_func_uint16_t_u_s(
                                        p_43,
                                        (safe_lshift_func_uint8_t_u_u(
                                            ((safe_sub_func_int8_t_s_s(
                                                 (((g_356 = g_35.f0) >=
                                                   (1L >=
                                                    (safe_mul_func_uint8_t_u_u(
                                                        ((((safe_mul_func_int8_t_s_s(
                                                               (safe_rshift_func_int16_t_s_u(
                                                                   0x1823L,
                                                                   11)),
                                                               ((l_1934 = (safe_unary_minus_func_int8_t_s(
                                                                     (safe_mul_func_uint16_t_u_u(
                                                                         1UL,
                                                                         0x5E27L))))) ^
                                                                p_45))) >
                                                           g_754[1][9]) ==
                                                          5UL) ^
                                                         p_44),
                                                        g_2)))) ||
                                                  0L),
                                                 (-8L))) |
                                             p_42),
                                            1)))) != p_45) &&
                                   0x4D8F8DDA1F5C9610LL))) &
                              0L),
                             p_45),
                            p_46))),
                       l_1920)),
                   g_1935))) |
              5L) ^
             (-1L));
      } else {
        int16_t l_1984[7] = {0x1100L, 0x1100L, 0x1100L, 0x1100L,
                             0x1100L, 0x1100L, 0x1100L};
        int i;
        g_421[3][7][1] &=
            ((p_42,
              (((safe_rshift_func_int8_t_s_s(
                    ((((l_1688[2][3] = 0xF8EEL) !=
                       ((g_755[1] =
                             ((p_42 = (g_1304 &&
                                       ((safe_sub_func_int64_t_s_s(
                                            (l_1663.f0 ^=
                                             (safe_unary_minus_func_int8_t_s(
                                                 p_45))),
                                            (((safe_add_func_uint64_t_u_u(
                                                  18446744073709551615UL,
                                                  l_1984[2])) == (1L >= p_45)) >
                                             l_1878))) < g_1732[0][1]))) &&
                              p_43)) > p_46)) >= g_1985) < p_44),
                    2)) |
                p_45) |
               0xDFEC4AF5L)) > 5L);
      }
      g_421[3][7][1] = (1L <= ((g_388 = (g_1145[1] = l_1570[2][3][1])), 1UL));
      return l_1847;
    }
    g_1145[0].f2 &= p_46;
  }
  return p_42;
}

static uint16_t func_51(int16_t p_52, uint16_t p_53, uint64_t p_54,
                        int32_t p_55) {
  uint8_t l_1104[4][4][5] = {{{0x67L, 0xA6L, 0x5DL, 0x66L, 0UL},
                              {0xA6L, 0xAEL, 0x21L, 251UL, 4UL},
                              {0x67L, 255UL, 9UL, 0xAEL, 254UL},
                              {0xC1L, 1UL, 1UL, 0x5DL, 255UL}},
                             {{1UL, 253UL, 0xA6L, 0UL, 0x4FL},
                              {253UL, 253UL, 255UL, 0x33L, 0x33L},
                              {255UL, 1UL, 255UL, 0x7DL, 255UL},
                              {255UL, 255UL, 253UL, 0x21L, 1UL}},
                             {{251UL, 0xAEL, 0x12L, 255UL, 0xC1L},
                              {255UL, 0xA6L, 253UL, 1UL, 0xC1L},
                              {0x41L, 7UL, 255UL, 0x04L, 253UL},
                              {9UL, 253UL, 255UL, 254UL, 0x6CL}},
                             {{7UL, 255UL, 0xA6L, 254UL, 0x67L},
                              {0x21L, 0x04L, 1UL, 0x04L, 0x21L},
                              {0x12L, 0x21L, 9UL, 1UL, 255UL},
                              {0x5DL, 253UL, 0x21L, 255UL, 0xAEL}}};
  struct S0 l_1144 = {0, 0x2C0EE27351D2F17ALL, -548, 3};
  int32_t l_1162 = 0x0D39437AL;
  int32_t l_1354 = 1L;
  int32_t l_1356[4] = {(-5L), (-5L), (-5L), (-5L)};
  uint16_t l_1363 = 0xE5EBL;
  uint16_t l_1426[2];
  struct S0 l_1427 = {0, -1L, 929, 12};
  int i, j, k;
  for (i = 0; i < 2; i++)
    l_1426[i] = 6UL;
  for (p_55 = 7; (p_55 >= 0); p_55 -= 1) 
  {
    int32_t l_1164 = (-2L);
    uint32_t l_1176 = 18446744073709551615UL;
    struct S0 l_1240;
    l_1240.f0 = -0;
    l_1240.f1 = 0L;
    l_1240.f2 = 291;
    l_1240.f3 = 15;

    int32_t l_1360 = 0x5D9D81B5L;
    int32_t l_1362 = 0xBA92A2E7L;
    uint16_t l_1423[2];
    int32_t l_1428 = 0xF2E968EEL;
    int i;
    for (i = 0; i < 2; i++)
      l_1423[i] = 0x69C6L;
    g_755[p_55] = 0x572DDF76L;
    if ((1L > l_1104[3][3][4])) {
      int32_t l_1114 = 0x194C2F91L;
      uint32_t l_1119 = 0xD6EA138DL;
      int32_t l_1177 = 1L;
      int32_t l_1178[10][2][8] = {
          {{0x96377CDCL, 0xA1323271L, 7L, 8L, 0xFD640F53L, 0x58FEF624L,
            0x5BCBB092L, 0x3CDA8A8EL},
           {0x5BCBB092L, 0xFD640F53L, 0x63B4B45AL, 0L, 2L, 0L, 0L, 0L}},
          {{0x63B4B45AL, 7L, (-10L), 7L, 0x63B4B45AL, 0xBF2FDC82L, (-9L),
            0xAA2D77E5L},
           {0x3CDA8A8EL, 0xD10CB2E7L, (-1L), 4L, 0x4BF6C601L, (-10L),
            0x96377CDCL, 7L}},
          {{7L, 0L, (-1L), 0x96377CDCL, 0xE060F729L, 0x5BCBB092L, (-9L), 7L},
           {0x4BF6C601L, 0xD7E59C5BL, (-10L), 0xAA2D77E5L, 0L, 0L, 0L, 0L}},
          {{2L, 0x63B4B45AL, 0x63B4B45AL, 2L, 7L, (-9L), 0x5BCBB092L,
            0xE060F729L},
           {0xA1323271L, 0x58FEF624L, 7L, 0L, 7L, 0x96377CDCL, (-10L),
            0x4BF6C601L}},
          {{0L, 0x58FEF624L, 0x4BF6C601L, 0x7605411FL, 0xAA2D77E5L, (-9L),
            0xBF2FDC82L, 0x63B4B45AL},
           {0xFD640F53L, 0x63B4B45AL, 0L, 2L, 0L, 0L, 0L, 2L}},
          {{0xBF2FDC82L, 0xD7E59C5BL, 0xBF2FDC82L, 0L, 0x3CDA8A8EL, 0x5BCBB092L,
            0x58FEF624L, 0xFD640F53L},
           {4L, 0L, 2L, 0xE060F729L, (-9L), (-10L), 0x3CDA8A8EL, 0x7605411FL}},
          {{4L, 0xD10CB2E7L, 0xD7E59C5BL, 0xA1323271L, 0x3CDA8A8EL, 0xBF2FDC82L,
            0xE060F729L, 0L},
           {4L, 0xBB33FB1BL, 0x5BCBB092L, 0L, 0x4BF6C601L, 0x4BF6C601L, 0L,
            0x5BCBB092L}},
          {{0L, 0L, 0xFD640F53L, 0x3CDA8A8EL, 2L, (-10L), 7L, 0xD10CB2E7L},
           {0x3CDA8A8EL, 0xAA2D77E5L, 0x63B4B45AL, (-9L), 0xBB33FB1BL,
            0x96377CDCL, 0x58FEF624L, 0xD10CB2E7L}},
          {{0xAA2D77E5L, 7L, 0L, 0x3CDA8A8EL, 0xD7E59C5BL, 7L, 0xA1323271L,
            0x5BCBB092L},
           {0x63B4B45AL, 0L, 2L, 0L, 0L, 0L, 2L, 0L}},
          {{(-9L), 0x3CDA8A8EL, 0L, 0xAA2D77E5L, 7L, 7L, 0L, 0xE060F729L},
           {0xBB33FB1BL, 0xD7E59C5BL, 0L, 7L, (-9L), 0x58FEF624L, 0L, 0L}}};
      int16_t l_1216 = 0x929DL;
      int i, j, k;
      if ((safe_lshift_func_int8_t_s_s(
              (safe_mul_func_uint16_t_u_u(
                  (g_1021[3] != (g_1109 ^= (-1L))),
                  ((g_559[p_55] = 0x650A5C6F80A1810ALL) >
                   (((((+((~((safe_mod_func_int64_t_s_s(1L, p_52)) ^
                             (--p_54))) != p_55)),
                       ((g_388.f2 || (-1L)) ^
                        (safe_add_func_uint8_t_u_u(
                            (g_316 || 0xD4A690CC6BE5E60CLL), l_1119)))) !=
                      g_755[p_55]) &&
                     0xF69AL) &
                    1UL)))),
              4))) {
        int8_t l_1143 = (-10L);
        struct S0 l_1167 = {-0, 0L, 573, 2};
        for (g_388.f1 = 3; (g_388.f1 >= 0); g_388.f1 -= 1) {
          int16_t l_1142 = (-1L);
          struct S0 l_1146 = {-0, 0x7D4EDEB371191E3ELL, 551, 0};
          int32_t l_1163 = (-1L);
          g_755[p_55] = p_53;
          if ((safe_lshift_func_uint16_t_u_u(
                  (g_755[p_55] =
                       ((g_420[2][1] =
                             (0x0F3E6AA5L |
                              (safe_add_func_int64_t_s_s(
                                  ((safe_mod_func_uint8_t_u_u(
                                       (((safe_mod_func_uint16_t_u_u(
                                             (safe_sub_func_uint8_t_u_u(247UL,
                                                                        0x85L)),
                                             ((safe_rshift_func_int8_t_s_u(
                                                  ((((safe_mod_func_uint8_t_u_u(
                                                         g_153, 0x1FL)) ==
                                                     (safe_lshift_func_int16_t_s_u(
                                                         ((safe_add_func_uint16_t_u_u(
                                                              ((p_54, 0L) ^
                                                               ((((((safe_add_func_int32_t_s_s(
                                                                        (0xCF9FL ||
                                                                         (safe_sub_func_uint32_t_u_u(
                                                                             ((l_1114 =
                                                                                   ((l_1114 |
                                                                                     1L) ||
                                                                                    g_159)) |
                                                                              g_755
                                                                                  [p_55]),
                                                                             g_594))),
                                                                        g_594)),
                                                                    g_250) ||
                                                                   0xDFCCE731E55434AELL) <=
                                                                  g_755[p_55]) >
                                                                 p_55) &
                                                                g_559[7])),
                                                              1L)),
                                                          (-4L)),
                                                         12))) != p_55) &&
                                                   p_54),
                                                  7)) &&
                                              0xF2283E39L))) &
                                         g_35.f0),
                                        0xD0L),
                                       l_1142)) <= l_1143),
                                  g_755[p_55])))) ||
                        g_355)),
                  6))) {
            g_1145[0] = l_1144;
          } else {
            l_1114 &= 0xDED93BC7L;
          }
          l_1146 = l_1146;
          g_421[3][7][1] =
              (l_1164 = (safe_unary_minus_func_uint32_t_u((
                   (safe_unary_minus_func_uint8_t_u((
                       ((p_52 = ((g_355 | 1UL), 0x2CA0L)) >=
                        (((g_356 = (l_1114 &= g_420[1][9])) <
                          (g_1145[0].f3 = g_85)) |
                         ((safe_sub_func_int8_t_s_s(
                              (l_1163 = (safe_mul_func_int8_t_s_s(
                                   (safe_lshift_func_int16_t_s_u(
                                       (~(l_1146.f3 ^
                                          ((g_1145[0].f1 =
                                                ((safe_add_func_int32_t_s_s(
                                                     ((p_55 ==
                                                       ((l_1162 =
                                                             ((safe_mod_func_uint64_t_u_u(
                                                                  (safe_rshift_func_int16_t_s_u(
                                                                      p_54,
                                                                      l_1143)),
                                                                  p_54)) >=
                                                              g_559[p_55])) !=
                                                        l_1146.f3)) !=
                                                      g_754[1][9]),
                                                     g_420[1][9])) <=
                                                 18446744073709551608UL)),
                                           l_1119))),
                                       12)),
                                   l_1104[3][3][4]))),
                              p_53)) <= g_388.f0))) >= g_86))),
                   p_55))));
          for (p_53 = 1; (p_53 <= 4); p_53 += 1) {
            int i, j, k;
            g_421[p_53][(p_53 + 3)][g_388.f1] =
                ((safe_mul_func_uint8_t_u_u(
                     ((l_1167,
                       (((safe_rshift_func_int16_t_s_u(
                             ((((g_421[p_53][p_55][p_53] ||
                                 (l_1167,
                                  (((safe_lshift_func_int16_t_s_s(
                                        (l_1119 <= l_1167.f2), 10)) ^
                                    (safe_rshift_func_uint8_t_u_u(
                                        (p_52, (safe_rshift_func_int16_t_s_s(
                                                   l_1176, 15))),
                                        0))) ||
                                   (g_312 = (g_35.f0 | ((0x1DACA4B2096FD014LL <=
                                                         p_52) < 8UL)))))) >
                                p_52) == p_53) ||
                              p_55),
                             4)) == p_54) <= p_55)),
                      g_421[3][7][1]),
                     g_421[p_53][p_55][p_53])) == p_55);
          }
        }
      } else {
        uint64_t l_1179 = 0xFC92D1F983E6BBE5LL;
        int32_t l_1222 = 0x95A39E74L;
        int32_t l_1223 = 1L;
        --l_1179;
        g_356 =
            ((safe_add_func_int8_t_s_s(
                 (g_1109 =
                      (l_1178[5][0][4] &= (safe_rshift_func_uint8_t_u_u(
                           (g_355 &
                            ((safe_rshift_func_int16_t_s_s(
                                 (((((safe_add_func_int8_t_s_s(
                                         (safe_rshift_func_int16_t_s_s(
                                             (l_1144.f2 =
                                                  (safe_rshift_func_int16_t_s_u(
                                                      (g_594 = 0x925BL), 6))),
                                             0)),
                                         (safe_add_func_int64_t_s_s(
                                             ((safe_add_func_uint16_t_u_u(
                                                  p_52,
                                                  ((p_55,
                                                    (g_1145[0].f0 <
                                                     (safe_mod_func_int8_t_s_s(
                                                         (safe_mul_func_int16_t_s_s(
                                                             g_251,
                                                             (((safe_mul_func_uint8_t_u_u(
                                                                   (safe_mod_func_int64_t_s_s(
                                                                       l_1179,
                                                                       (g_506 =
                                                                            l_1179))),
                                                                   p_55)) <=
                                                               p_52) <
                                                              (-10L)))),
                                                         1L)))),
                                                   l_1114))) > 2UL),
                                             (-6L))))) >= p_52) == 0xEFL) >=
                                   l_1176),
                                  g_35.f2),
                                 15)) |
                             l_1177)),
                           6)))),
                 0x18L)) &&
             g_35.f0);
        g_1103 |= (safe_rshift_func_int8_t_s_s(
            ((l_1223 =
                  ((safe_mod_func_uint16_t_u_u(
                       g_2,
                       (safe_unary_minus_func_int8_t_s((
                           (l_1222 =
                                (g_1145[0].f1 !=
                                 ((l_1164 = (safe_mul_func_uint16_t_u_u(
                                       ((g_755[7] &
                                         ((((((+(-9L)),
                                              (safe_rshift_func_int8_t_s_s(
                                                  ((((l_1216 |= p_52) <
                                                     ((l_1178[1][0][7] =
                                                           0xD5L) &
                                                      (~((l_1144.f0 |=
                                                          ((safe_rshift_func_uint8_t_u_s(
                                                               (1UL <= 1UL),
                                                               ((safe_rshift_func_uint8_t_u_s(
                                                                    l_1179,
                                                                    7)) ==
                                                                p_55))) ==
                                                           p_53)) |
                                                         9L)))),
                                                    l_1144.f3) &&
                                                   0x3F8AEED45A76F597LL),
                                                  l_1176))) &&
                                             g_750[0][1][0]) <= 0x1A67EEEAL) <=
                                           g_755[p_55]) &
                                          g_356)) < 1UL),
                                       g_388.f0))) > p_53))) ||
                           1L))))) &&
                   0x92L)) &&
             0xE30C7F7524BC882CLL),
            g_1032[0]));
      }
    } else {
      int32_t l_1233 = 0x0B4EC7FBL;
      int32_t l_1239 = 0x977BBB7EL;
      struct S0 l_1248 = {0, -1L, 869, 0};
      int32_t l_1358 = (-2L);
      int64_t l_1361 = 0L;
      g_1241 =
          ((0xF4D7L >=
            (!(safe_sub_func_uint32_t_u_u(
                (((func_59(
                       ((safe_lshift_func_uint8_t_u_u(
                            (p_54 !=
                             (~(g_388.f3 =
                                    (g_1145[0].f3 =
                                         (g_755[p_55] = (l_1144.f2, g_312)))))),
                            1)) ==
                        (safe_mod_func_uint32_t_u_u((!(0xA4L || g_1032[4])),
                                                    l_1233))),
                       ((g_754[0][6]++) !=
                        (l_1239 = (((g_1238 = ((safe_rshift_func_uint16_t_u_u(
                                                   3UL, 1)) &
                                               ((g_35, g_594), g_388.f2))),
                                    p_53) != l_1176))),
                       l_1176, p_53, l_1240),
                   l_1239) |
                  0x502AL) != g_1145[0].f1),
                p_53)))) |
           g_2);
      for (g_388.f1 = 1; (g_388.f1 <= 4); g_388.f1 += 1) {
        uint32_t l_1265 = 2UL;
        int32_t l_1275 = 8L;
        uint8_t l_1294 = 250UL;
        int32_t l_1355[7];
        int i;
        for (i = 0; i < 7; i++)
          l_1355[i] = 3L;
        if ((((safe_add_func_int8_t_s_s(
                  (0xA60D6EDBFC4B68AALL !=
                   (safe_sub_func_uint8_t_u_u(
                       ((safe_mul_func_uint8_t_u_u(
                            p_52, ((g_1145[0].f3 = 4UL) && 5L))),
                        (((l_1248,
                           (safe_lshift_func_uint16_t_u_u(
                               (safe_mul_func_int16_t_s_s(
                                   ((l_1265 =
                                         ((l_1248, p_52) &&
                                          (safe_mul_func_uint8_t_u_u(
                                              (safe_lshift_func_uint8_t_u_u(
                                                  (((safe_lshift_func_int16_t_s_u(
                                                        ((((safe_mod_func_int16_t_s_s(
                                                               (safe_rshift_func_uint8_t_u_s(
                                                                   (safe_rshift_func_int16_t_s_s(
                                                                       (((l_1240
                                                                              .f2 =
                                                                              (g_1109 =
                                                                                   (l_1104
                                                                                        [0]
                                                                                        [3]
                                                                                        [3] >
                                                                                    (g_388
                                                                                         .f3 =
                                                                                         ((((g_388,
                                                                                             p_53) <=
                                                                                            g_1145[0]
                                                                                                .f3) <
                                                                                           0x6EL) ==
                                                                                          3L))))) !=
                                                                         l_1239) ==
                                                                        7UL),
                                                                       2)),
                                                                   p_52)),
                                                               g_1238)) <
                                                           l_1248.f3) >
                                                          g_755[p_55]) >=
                                                         g_506),
                                                        10)) &
                                                    252UL) ||
                                                   p_53),
                                                  0)),
                                              p_52)))) &&
                                    g_153),
                                   4L)),
                               3))) <= p_53) != p_55)),
                       g_755[3]))),
                  0x7FL)) > g_1031) != p_55)) {
          uint8_t l_1268 = 0UL;
          int32_t l_1276 = 0x774F3D2EL;
          uint64_t l_1277 = 0UL;
          uint16_t l_1305[3];
          int i;
          for (i = 0; i < 3; i++)
            l_1305[i] = 65527UL;
                    if ((l_1265 | (((g_1145[0].f1 <= (((safe_sub_func_int64_t_s_s(l_1268, ((safe_add_func_int8_t_s_s((((((l_1276 |= (safe_lshift_func_uint8_t_u_u(((g_754[1][8] < ((safe_lshift_func_uint16_t_u_s((((((++l_1277) & ((safe_mod_func_uint16_t_u_u((p_53 &= (l_1233 = (safe_mod_func_uint8_t_u_u((l_1248.f0 = (((l_1275 = (g_86 | g_1032[0])) , (l_1144.f0 != (safe_add_func_int64_t_s_s((safe_lshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_s(((safe_lshift_func_int8_t_s_u((l_1144.f2 = (safe_rshift_func_uint16_t_u_s((l_1240.f0 > p_55), 13))), p_54)) && l_1265), 2)), 2)), (-10L))))) ^ 0xCBL)), g_2)))), p_52)) & g_1145[0].f3)) >= 0xE920C78C3F93D00ELL) > p_54) | p_55), 14)) ^ p_54)) && l_1162), 7))) != 4294967295UL) ^ l_1239) != (-1L)) && 0xE0L), g_35.f0)) , l_1144.f3))) < p_54) && p_55)) ^ l_1294) , p_55)))
                    {
                      struct S0 l_1299[10] = {
                          {0, 6L, 496, 15}, {0, 6L, 496, 15}, {0, 6L, 496, 15},
                          {0, 6L, 496, 15}, {0, 6L, 496, 15}, {0, 6L, 496, 15},
                          {0, 6L, 496, 15}, {0, 6L, 496, 15}, {0, 6L, 496, 15},
                          {0, 6L, 496, 15}};
                      int i;
                      g_356 |= (safe_rshift_func_uint16_t_u_s(g_250, 12));
                      g_356 = (safe_mod_func_int64_t_s_s(g_755[2],
                                                         (0x62L || l_1144.f2)));
                      l_1275 = 0xD888779BL;
                      l_1248 = l_1299[7];
                    } else {
                      g_755[7] = (safe_unary_minus_func_uint8_t_u(
                          (g_86 ^= (!(safe_mod_func_uint32_t_u_u(
                               (g_1304 >= l_1248.f1),
                               (g_421[3][7][1] = l_1305[2])))))));
                    }
        } else {
          uint64_t l_1328 = 1UL;
          int32_t l_1351 = 8L;
          int32_t l_1352 = 0x3DD43169L;
          int64_t l_1353 = 3L;
          int32_t l_1357 = 0xFDD0FA52L;
          int32_t l_1359 = 0x1D1C4007L;
          for (g_85 = 4; (g_85 >= 0); g_85 -= 1) {
            int32_t l_1316 = 0x10C1396FL;
            int i, j, k;
            g_1031 = (safe_mod_func_int32_t_s_s(
                ((((~((g_421[g_388.f1][(g_85 + 1)][g_388.f1] =
                           (safe_mul_func_uint16_t_u_u((~0x02L), 65535UL))) >=
                      (safe_rshift_func_int16_t_s_s(
                          ((((safe_sub_func_int32_t_s_s(
                                 ((((p_53 !=
                                     ((l_1316,
                                       ((safe_sub_func_uint16_t_u_u(
                                            (p_55 |
                                             (safe_rshift_func_int16_t_s_s(
                                                 (safe_sub_func_uint16_t_u_u(
                                                     ((((safe_mul_func_uint8_t_u_u(
                                                            ((!(safe_rshift_func_uint16_t_u_s(
                                                                 65527UL,
                                                                 g_203))) ==
                                                             (1L < g_2)),
                                                            l_1328)) <= g_356) ^
                                                       l_1328) > g_755[4]),
                                                     g_1304)),
                                                 l_1328))),
                                            g_420[0][7])) == p_54)) |
                                      l_1316)) != 18446744073709551613UL),
                                   (-1L)) < l_1104[3][2][3]),
                                 p_54)) &&
                             0x5239L) >= l_1316) ||
                           l_1144.f3),
                          l_1240.f3)))),
                   l_1248.f1) &
                  0xCB78EA1B0DD7FBFELL),
                 0L),
                0x082156AFL));
            g_356 &=
                (((safe_lshift_func_uint8_t_u_s(
                      (!((((g_1241 | (+l_1275)), 8UL) <
                          ((safe_mul_func_int16_t_s_s(
                               ((safe_lshift_func_int8_t_s_u(
                                    (0xF0L <= (g_391 = g_559[6])), g_755[3])) ||
                                ((safe_rshift_func_int8_t_s_s(
                                     ((l_1164 ^
                                       (safe_lshift_func_uint8_t_u_s(
                                           (safe_rshift_func_uint8_t_u_s(
                                               (p_53 >=
                                                ((safe_rshift_func_uint8_t_u_s(
                                                     (safe_lshift_func_uint16_t_u_s(
                                                         ((((((g_1238 =
                                                                   (((safe_mul_func_uint8_t_u_u(
                                                                         (safe_rshift_func_int16_t_s_s(
                                                                             l_1316,
                                                                             5)),
                                                                         p_55)) &&
                                                                     p_52) ^
                                                                    g_421[g_85][(
                                                                        g_388
                                                                            .f1 +
                                                                        3)]
                                                                         [g_85])) &&
                                                              g_421[g_388.f1]
                                                                   [(g_85 + 1)]
                                                                   [g_388
                                                                        .f1]) !=
                                                             p_55) &&
                                                            g_755[4]),
                                                           g_388.f1) &&
                                                          0L),
                                                         4)),
                                                     l_1240.f0)),
                                                 3UL)),
                                               0)),
                                           p_52))) > l_1248.f1),
                                     g_1241)) ^
                                 l_1328)),
                               l_1239)) ^
                           p_55)) < 0x34L)),
                      l_1144.f3)),
                  p_52) ||
                 p_55);
            return g_356;
          }
          --l_1363;
        }
        if (((safe_mul_func_uint16_t_u_u(
                 ((safe_sub_func_uint8_t_u_u(
                      0x65L,
                      (safe_lshift_func_uint16_t_u_u(
                          ((safe_sub_func_int8_t_s_s(
                               (((l_1239 ^=
                                  ((safe_add_func_uint64_t_u_u(
                                       (safe_mul_func_uint16_t_u_u(
                                           ((safe_mul_func_int16_t_s_s(
                                                (((p_55 >=
                                                   (((safe_lshift_func_uint8_t_u_u(
                                                         g_754[2][3], 0)),
                                                     (g_388.f0 < p_52)) !=
                                                    (l_1355[4] = p_53))) >=
                                                  (((((!((safe_rshift_func_uint16_t_u_u(
                                                             (g_755[5] <
                                                              ((0x70E0L !=
                                                                (safe_sub_func_uint32_t_u_u(
                                                                    (g_755[7],
                                                                     g_1109),
                                                                    1UL))) ||
                                                               g_1145[0].f2)),
                                                             2)),
                                                         l_1233)) &
                                                      g_559[6]) &&
                                                     p_55) != (-7L)),
                                                   (-9L))) |
                                                 p_52),
                                                l_1363)) |
                                            0UL),
                                           0xA8DEL)),
                                       p_55)) >= l_1361)) <= 0x4FB66BB9L) <
                                l_1294),
                               p_52)) ^
                           p_52),
                          l_1104[3][3][4])))) != l_1265),
                 g_86)) == p_52)) {
          return g_1103;
        } else {
          return g_40;
        }
      }
      l_1144 = g_1145[0];
      l_1356[2] &=
          ((safe_rshift_func_uint8_t_u_s(
               0xF8L,
               ((((safe_mod_func_uint64_t_u_u(
                      (safe_mod_func_int64_t_s_s(
                          (l_1240.f1 &
                           (l_1354 <=
                            ((((g_755[7] ^
                                (safe_sub_func_uint64_t_u_u(
                                    (safe_sub_func_uint16_t_u_u(
                                        l_1248.f1, 9UL)),
                                    (safe_unary_minus_func_uint64_t_u(
                                        (safe_mod_func_int64_t_s_s(
                                            ((!((l_1144,
                                                 (g_153 = (safe_lshift_func_uint8_t_u_u(
                                                      (safe_lshift_func_uint16_t_u_s(
                                                          (+(p_55, g_154)), 4)),
                                                      l_1240.f1)))) &
                                                1L)) |
                                             p_55),
                                            18446744073709551610UL))))))) !=
                               0x5D6371A78AA5C65FLL) == 0x120E6C0AL) &
                             18446744073709551615UL))),
                          g_1241)),
                      l_1144.f1)) != 0x4DB717AB198D5D5FLL) == g_355) |
                l_1164))),
           l_1248.f0);
    }
    l_1428 ^= (safe_sub_func_uint32_t_u_u(
        (func_59(
             (l_1164 = 4294967289UL), g_86, p_55,
             (((~((((safe_sub_func_uint16_t_u_u(
                        ((g_1021[3],
                          (((((safe_mul_func_int8_t_s_s(
                                  (g_312 ||
                                   ((((safe_lshift_func_int8_t_s_u(
                                          (safe_mul_func_int16_t_s_s(
                                              (safe_add_func_int32_t_s_s(
                                                  (((l_1144.f2 =
                                                         ((++g_506),
                                                          (safe_rshift_func_int16_t_s_s(
                                                              (0x88DAE7C37C3C3BB9LL !=
                                                               (((l_1240.f2,
                                                                  (l_1423[0] =
                                                                       l_1144
                                                                           .f3)) >=
                                                                 ((((safe_mod_func_int16_t_s_s(
                                                                        8L,
                                                                        0x9ED3L)),
                                                                    0x7B50B71F29030D9BLL) >
                                                                   g_420[2]
                                                                        [1]) &&
                                                                  g_85)),
                                                                (-7L))),
                                                              g_1145[0]
                                                                  .f0)))) <=
                                                    l_1360) &&
                                                   0x89L),
                                                  g_131)),
                                              p_52)),
                                          l_1144.f0)) < g_355),
                                     l_1104[3][3][4]) > l_1363)),
                                  p_53)) <= g_390),
                             p_54) &
                            l_1426[0]) ||
                           g_2)) &
                         g_594),
                        g_391)) <= g_85),
                   l_1240.f0) < l_1362)) &&
               g_390),
              g_421[3][7][1]),
             l_1427),
         4294967295UL),
        p_54));
  }
  for (g_153 = (-20); (g_153 < 6); g_153 = safe_add_func_int8_t_s_s(g_153, 1)) {
    uint32_t l_1440 = 0x3482DA34L;
    int32_t l_1452 = 0xB168BE91L;
    for (g_131 = (-16); (g_131 < 1); g_131++) {
      for (g_1241 = 24; (g_1241 < 34);
           g_1241 = safe_add_func_uint16_t_u_u(g_1241, 4)) {
        for (g_85 = 0; (g_85 != 0); g_85 = safe_add_func_uint8_t_u_u(g_85, 1)) {
          uint32_t l_1437 = 0xA9A030FBL;
          return l_1437;
        }
      }
    }
    g_388.f2 =
        ((0x9280DE75F5A10CCALL < g_158) ^
         ((9L &
           ((safe_add_func_uint16_t_u_u(
                (l_1440++),
                (safe_lshift_func_int16_t_s_u((g_594 = (g_316, p_55)), 15)))) &&
            ((+((18446744073709551611UL <
                 (l_1356[0] =
                      (((((safe_lshift_func_uint16_t_u_s(
                              (safe_rshift_func_uint8_t_u_s(
                                  (safe_add_func_int64_t_s_s((g_131 = p_53),
                                                             (p_54 ^= p_53))),
                                  7)),
                              3)) &&
                          (((0x1E1E57CAL & g_1021[1]), 0x9FA2L) <= l_1440)) !=
                         g_750[0][4][0]) > 0x3A70L) >= g_316))),
                0x7393L)) == 0x9F7EC0A2L))) ||
          g_35.f0));
    p_55 = (((l_1427.f2 = p_53) & (l_1452 &= (g_35.f1, 0x2C6BL))),
            ((safe_rshift_func_int8_t_s_u(
                 ((safe_rshift_func_uint16_t_u_s(
                      (safe_add_func_int16_t_s_s(
                          (~((l_1452 = 0xE489E68586BFF0DDLL) ^ l_1440)), p_53)),
                      (safe_mod_func_int8_t_s_s(
                          (0xAA7170BFL && 0x73A17C9BL),
                          (safe_add_func_int32_t_s_s((0xAFL != 0x3BL),
                                                     l_1440)))))) != p_52),
                 4)) &
             p_52));
  }
  g_1145[0].f2 =
      ((p_52,
        ((((-1L) |
           ((safe_sub_func_int64_t_s_s(g_40, l_1354)) |
            (((p_55 < (!65535UL)) !=
              (safe_mod_func_uint16_t_u_u(
                  (((safe_mod_func_int64_t_s_s(
                        ((((l_1162, (safe_add_func_uint32_t_u_u(
                                        ((safe_add_func_uint64_t_u_u(
                                             (safe_lshift_func_uint16_t_u_u(
                                                 0x6D2BL, 12)),
                                             g_1032[4])) > l_1162),
                                        (-1L)))) |
                           g_755[6]) &&
                          p_53) < l_1144.f3),
                        p_55)) > 0xD8L) <= 0x8A3AA13CL),
                  p_54))) < g_316))) > p_53) >= l_1144.f0)) != l_1427.f3);
  {
    int32_t l_1164 = (-2L);
    uint32_t l_1176 = 18446744073709551615UL;
    struct S0 l_1240;
    l_1240.f0 = -0;
    l_1240.f1 = 0L;
    l_1240.f2 = 291;
    l_1240.f3 = 15;
    int32_t l_1360 = 0x5D9D81B5L;
    int32_t l_1362 = 0xBA92A2E7L;
    uint16_t l_1423[2];
    int32_t l_1428 = 0xF2E968EEL;
    int i;

    safe_rshift_func_int16_t_s_s((-1L), 1);

    

    l_1428 ^= (safe_sub_func_uint32_t_u_u(
        (func_59(
             (l_1164 = 4294967289UL), g_86, p_55,
             (((~((((safe_sub_func_uint16_t_u_u(
                        ((g_1021[3],
                          (((((safe_mul_func_int8_t_s_s(
                                  (g_312 ||
                                   ((((safe_lshift_func_int8_t_s_u(
                                          (safe_mul_func_int16_t_s_s(
                                              (safe_add_func_int32_t_s_s(
                                                  (((l_1144.f2 =
                                                         ((++g_506),
                                                          (safe_rshift_func_int16_t_s_s(
                                                              (0x88DAE7C37C3C3BB9LL !=
                                                               (((l_1240.f2,
                                                                  (l_1423[0] =
                                                                       l_1144
                                                                           .f3)) >=
                                                                 ((((safe_mod_func_int16_t_s_s(
                                                                        8L,
                                                                        0x9ED3L)),
                                                                    0x7B50B71F29030D9BLL) >
                                                                   g_420[2]
                                                                        [1]) &&
                                                                  g_85)),
                                                                (-7L))),
                                                              g_1145[0]
                                                                  .f0)))) <=
                                                    l_1360) &&
                                                   0x89L),
                                                  g_131)),
                                              p_52)),
                                          l_1144.f0)) < g_355),
                                     l_1104[3][3][4]) > l_1363)),
                                  p_53)) <= g_390),
                             p_54) &
                            l_1426[0]) ||
                           g_2)) &
                         g_594),
                        g_391)) <= g_85),
                   l_1240.f0) < l_1362)) &&
               g_390),
              g_421[3][7][1]),
             l_1427),
         4294967295UL),
        p_54));

    

      for (g_391 = (-7); (g_391 != 54); g_391++) {
        struct S0 l_1479 = {0, -1L, 935, 13};
        l_1427 = (l_1479 = l_1427);
      }

    





  }
  return g_755[7];
}

static struct S0 func_59(uint32_t p_60, int16_t p_61, uint64_t p_62,
                         uint8_t p_63, struct S0 p_64) {
  int16_t l_75 = (-1L);
  int32_t l_80 = 0xDA297315L;
  int32_t l_81 = 0xEAE3254CL;
  int32_t l_82 = 0x588CB35BL;
  int64_t l_83 = (-5L);
  int32_t l_84[10][9] = {
      {0xA6B6B07CL, 0xA9E7339AL, (-1L), 0xA9E7339AL, 0xA6B6B07CL, 0xA9E7339AL,
       (-1L), 0xA9E7339AL, 0xA6B6B07CL},
      {0xF4112691L, 0xAA3CE9D1L, 0xD0B4E555L, 0x43A44ADEL, 0x43A44ADEL,
       0xD0B4E555L, 0xAA3CE9D1L, 0xF4112691L, 0xF4112691L},
      {0xC018302AL, 0xA9E7339AL, 0xC018302AL, 0x01D2D5FAL, 0xC018302AL,
       0xA9E7339AL, 0xC018302AL, 0x01D2D5FAL, 0xC018302AL},
      {0xF4112691L, 0x43A44ADEL, 0xAA3CE9D1L, 0xAA3CE9D1L, 0x43A44ADEL,
       0xF4112691L, 0xD0B4E555L, 0xD0B4E555L, 0xF4112691L},
      {0xA6B6B07CL, 0x01D2D5FAL, (-1L), 0x01D2D5FAL, 0xA6B6B07CL, 0x01D2D5FAL,
       (-1L), 0x01D2D5FAL, 0xA6B6B07CL},
      {0x43A44ADEL, 0xAA3CE9D1L, 0xAA3CE9D1L, 0x43A44ADEL, 0xF4112691L,
       0xD0B4E555L, 0xD0B4E555L, 0xF4112691L, 0x43A44ADEL},
      {0xC018302AL, 0x01D2D5FAL, 0xC018302AL, 0xA9E7339AL, 0xC018302AL,
       0x01D2D5FAL, 0xC018302AL, 0xA9E7339AL, 0xC018302AL},
      {0x43A44ADEL, 0x43A44ADEL, 0xD0B4E555L, 0xAA3CE9D1L, 0xF4112691L,
       0xF4112691L, 0xAA3CE9D1L, 0xD0B4E555L, 0x43A44ADEL},
      {0xA6B6B07CL, 0xA9E7339AL, (-1L), 0xA9E7339AL, 0xA6B6B07CL, 0xA9E7339AL,
       (-1L), 0xA9E7339AL, 0xA6B6B07CL},
      {0xF4112691L, 0xAA3CE9D1L, 0xD0B4E555L, 0x43A44ADEL, 0x43A44ADEL,
       0xD0B4E555L, 0xAA3CE9D1L, 0xF4112691L, 0xF4112691L}};
  struct S0 l_163 = {0, 0x74F8CE80C63ED81ALL, -372, 13};
  int64_t l_603[2];
  uint64_t l_606 = 0UL;
  uint64_t l_712 = 0xDB55FDE756C50D62LL;
  uint32_t l_716 = 1UL;
  int32_t l_902 = 0x0DED8928L;
  int64_t l_959[4];
  int32_t l_961 = 0L;
  int i, j;
  for (i = 0; i < 2; i++)
    l_603[i] = 2L;
  for (i = 0; i < 4; i++)
    l_959[i] = 0x779A6E1A9BF014B7LL;
  l_84[1][0] = func_66(
      (((((safe_mul_func_int16_t_s_s(
              p_63,
              (0x66354922L |
               func_71(l_75,
                       ((((p_63, (0xBF19L > (safe_mod_func_uint8_t_u_u(
                                                func_78((++g_86)), g_85)))) &
                          ((safe_lshift_func_int8_t_s_u(g_35.f0, 2)) | g_85)) <
                         0x6DL) >= g_2),
                       l_84[4][1])))) != g_35.f3) |
         p_64.f1),
        0xBC179A00L),
       g_40),
      l_163);
  p_64.f2 =
      ((((+((((g_390, (safe_sub_func_int16_t_s_s(p_64.f0, (p_63 | 255UL)))) <
              (safe_lshift_func_int8_t_s_u(
                  (((((((safe_lshift_func_int16_t_s_u(
                            (safe_add_func_uint64_t_u_u(
                                18446744073709551608UL,
                                (l_84[1][0] >=
                                 ((safe_sub_func_uint8_t_u_u(
                                      ((safe_add_func_int32_t_s_s(
                                           (safe_mod_func_int16_t_s_s(
                                               (((safe_lshift_func_uint8_t_u_u(
                                                     (((safe_mul_func_int16_t_s_s(
                                                           p_64.f1,
                                                           (safe_mul_func_int8_t_s_s(
                                                               (safe_add_func_int8_t_s_s(
                                                                   g_40,
                                                                   (g_594 =
                                                                        ((safe_add_func_uint8_t_u_u(
                                                                             (~l_163
                                                                                   .f1),
                                                                             g_153)) >
                                                                         0x3B4629F6L)))),
                                                               p_62)))),
                                                       0x2DE3A813L) &&
                                                      l_81),
                                                     g_355)) >
                                                 0x41687DFAAF6EBBA7LL) <
                                                (-10L)),
                                               g_131)),
                                           l_163.f3)),
                                       l_81),
                                      1L)),
                                  0x3674L)))),
                            g_355)) &
                        l_163.f0),
                       p_62) == g_420[3][5]) == g_421[0][3][1]) < g_559[6]) &
                   l_163.f1),
                  0))) &
             g_506) >= 0x0C24L)) < 0x6274L) &&
        g_388.f1) &&
       g_390);
lbl_903:
  for (g_250 = (-5); (g_250 == 28); g_250++) {
    int16_t l_604 = 0xB5C8L;
    int32_t l_605 = 0xB57BC166L;
    if (g_355)
      break;
    if (p_62)
      break;
    p_64.f2 =
        ((p_64.f3, ((g_158 = 0L) <=
                    (((l_163.f2 && ((g_559[7] && (g_388.f0 = g_86)) <
                                    (safe_mod_func_int16_t_s_s(
                                        (safe_sub_func_uint16_t_u_u(
                                            (safe_lshift_func_int16_t_s_u(
                                                ((0xFFL && p_61) | g_153), 0)),
                                            0x9350L)),
                                        l_163.f1)))) != 5L) |
                     p_62))) &&
         l_75);
    l_606--;
  }
  for (l_81 = 7; (l_81 >= 0); l_81 -= 1) {
    uint32_t l_629[3][4];
    int32_t l_654 = 0xD8CE1AEFL;
    uint32_t l_691 = 8UL;
    int32_t l_709 = (-3L);
    uint32_t l_753[1];
    int32_t l_776 = 0xBAA532F9L;
    uint64_t l_852 = 0x13291DBE59CDD07ELL;
    struct S0 l_865 = {-0, 0x9367B73D3741F08FLL, -151, 13};
    uint64_t l_898[1][8] = {{0x9377111B2CA8D5CFLL, 18446744073709551614UL,
                             0x9377111B2CA8D5CFLL, 18446744073709551614UL,
                             0x9377111B2CA8D5CFLL, 18446744073709551614UL,
                             0x9377111B2CA8D5CFLL, 18446744073709551614UL}};
    int8_t l_924 = 1L;
    struct S0 l_954 = {0, 0x5257524827E993F2LL, -178, 7};
    int64_t l_960 = (-7L);
    int i, j;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 4; j++)
        l_629[i][j] = 4UL;
    }
    for (i = 0; i < 1; i++)
      l_753[i] = 0x1A2CF2C2L;
    for (g_131 = 8; (g_131 >= 2); g_131 -= 1) {
      int32_t l_609 = 0x870AAE8EL;
      uint32_t l_628 = 0x6D20D883L;
      uint16_t l_655[3];
      uint32_t l_807 = 0xAFCF8717L;
      uint64_t l_868[3][6][4] = {
          {{18446744073709551615UL, 0x80B3716156A77E4ALL,
            18446744073709551615UL, 18446744073709551611UL},
           {0UL, 0x80B3716156A77E4ALL, 0xF2A66F71329C69CELL,
            18446744073709551613UL},
           {0x80B3716156A77E4ALL, 0x6BCF7FB9B936A8F7LL, 0x6BCF7FB9B936A8F7LL,
            0x80B3716156A77E4ALL},
           {18446744073709551615UL, 18446744073709551613UL,
            0x6BCF7FB9B936A8F7LL, 18446744073709551611UL},
           {0x80B3716156A77E4ALL, 0UL, 0xF2A66F71329C69CELL, 0UL},
           {0UL, 0x6BCF7FB9B936A8F7LL, 18446744073709551615UL, 0UL}},
          {{18446744073709551615UL, 18446744073709551611UL,
            0x75AD0B53AC787FC2LL, 0x75AD0B53AC787FC2LL},
           {18446744073709551615UL, 18446744073709551615UL,
            18446744073709551613UL, 0x6BCF7FB9B936A8F7LL},
           {18446744073709551615UL, 0xF2A66F71329C69CELL, 0x75AD0B53AC787FC2LL,
            18446744073709551615UL},
           {18446744073709551607UL, 0x6BCF7FB9B936A8F7LL,
            18446744073709551607UL, 0x75AD0B53AC787FC2LL},
           {18446744073709551611UL, 0x6BCF7FB9B936A8F7LL,
            18446744073709551613UL, 18446744073709551615UL},
           {0x6BCF7FB9B936A8F7LL, 0xF2A66F71329C69CELL, 0xF2A66F71329C69CELL,
            0x6BCF7FB9B936A8F7LL}},
          {{18446744073709551607UL, 18446744073709551615UL,
            0xF2A66F71329C69CELL, 0x75AD0B53AC787FC2LL},
           {0x6BCF7FB9B936A8F7LL, 18446744073709551611UL,
            18446744073709551613UL, 18446744073709551611UL},
           {18446744073709551611UL, 0xF2A66F71329C69CELL,
            18446744073709551607UL, 18446744073709551611UL},
           {18446744073709551607UL, 18446744073709551611UL,
            0x75AD0B53AC787FC2LL, 0x75AD0B53AC787FC2LL},
           {18446744073709551615UL, 18446744073709551615UL,
            18446744073709551613UL, 0x6BCF7FB9B936A8F7LL},
           {18446744073709551615UL, 0xF2A66F71329C69CELL, 0x75AD0B53AC787FC2LL,
            18446744073709551615UL}}};
      int i, j, k;
      for (i = 0; i < 3; i++)
        l_655[i] = 0x0681L;
      l_609 = g_559[l_81];
      if ((safe_add_func_int32_t_s_s(
              ((safe_sub_func_uint16_t_u_u(
                   ((safe_mul_func_uint8_t_u_u(
                        0x6CL,
                        (0x3BB0B88AL ==
                         (safe_mul_func_int8_t_s_s(
                             ((~((safe_rshift_func_uint16_t_u_s(
                                     (safe_mod_func_uint16_t_u_u(
                                         (l_84[l_81][g_131] ^ l_81), p_62)),
                                     12)) ||
                                 (p_63 ==
                                  ((safe_rshift_func_uint8_t_u_s(
                                       (g_35,
                                        (safe_unary_minus_func_uint16_t_u(
                                            ((((((safe_rshift_func_int16_t_s_u(
                                                     g_35.f1, 3)) &
                                                 g_356),
                                                8L) ^
                                               4294967295UL) <= g_159) !=
                                             g_312)))),
                                       l_628)) &
                                   l_629[0][1])))) |
                              p_64.f3),
                             0UL))))) < p_64.f2),
                   0xFE80L)) >= p_62),
              p_64.f2))) {
        uint64_t l_656[3][6][8] = {
            {{1UL, 7UL, 0xE746994BA50BD24CLL, 0xB9A1608C68975228LL, 0UL, 0UL,
              0UL, 0UL},
             {6UL, 0xB9A1608C68975228LL, 0xB9A1608C68975228LL, 6UL,
              0xE746994BA50BD24CLL, 18446744073709551615UL,
              18446744073709551610UL, 0x4ED6F1A732B446ACLL},
             {0xE746994BA50BD24CLL, 18446744073709551615UL,
              18446744073709551610UL, 0x4ED6F1A732B446ACLL,
              0x25D843191F452816LL, 18446744073709551613UL, 0UL, 7UL},
             {0xCB295E0BED3F6F53LL, 18446744073709551615UL,
              0xE51C36D8724A5D39LL, 1UL, 0xE51C36D8724A5D39LL,
              18446744073709551615UL, 0xCB295E0BED3F6F53LL, 1UL},
             {0UL, 0xB9A1608C68975228LL, 1UL, 18446744073709551615UL, 6UL, 0UL,
              0x2E7066FF67701C2ALL, 0x1A679923B0AF2E55LL},
             {0x1A679923B0AF2E55LL, 7UL, 1UL, 0x25D843191F452816LL, 6UL, 6UL,
              0x25D843191F452816LL, 1UL}},
            {{0UL, 0UL, 18446744073709551613UL, 0x1A679923B0AF2E55LL,
              0xE51C36D8724A5D39LL, 0xCB295E0BED3F6F53LL, 1UL,
              18446744073709551610UL},
             {0xCB295E0BED3F6F53LL, 0xE746994BA50BD24CLL, 0UL,
              0xE51C36D8724A5D39LL, 0x25D843191F452816LL,
              18446744073709551610UL, 0xB9A1608C68975228LL,
              18446744073709551610UL},
             {0xE746994BA50BD24CLL, 0x1A679923B0AF2E55LL, 6UL,
              0x1A679923B0AF2E55LL, 0xE746994BA50BD24CLL, 0x4ED6F1A732B446ACLL,
              18446744073709551613UL, 1UL},
             {6UL, 0x2E7066FF67701C2ALL, 7UL, 0x25D843191F452816LL, 0UL,
              0xE51C36D8724A5D39LL, 1UL, 0x1A679923B0AF2E55LL},
             {1UL, 18446744073709551613UL, 7UL, 18446744073709551615UL,
              18446744073709551615UL, 7UL, 18446744073709551613UL, 1UL},
             {0UL, 0xCB295E0BED3F6F53LL, 6UL, 1UL, 0UL, 0x2E7066FF67701C2ALL,
              0xB9A1608C68975228LL, 7UL}},
            {{0UL, 0x25D843191F452816LL, 0UL, 0x4ED6F1A732B446ACLL, 1UL,
              0x2E7066FF67701C2ALL, 1UL, 0x4ED6F1A732B446ACLL},
             {18446744073709551613UL, 0xCB295E0BED3F6F53LL,
              18446744073709551613UL, 6UL, 0x2E7066FF67701C2ALL, 7UL,
              0x25D843191F452816LL, 0UL},
             {0x4ED6F1A732B446ACLL, 18446744073709551613UL, 1UL,
              0xB9A1608C68975228LL, 0UL, 0xE51C36D8724A5D39LL,
              0x2E7066FF67701C2ALL, 0x2E7066FF67701C2ALL},
             {0x4ED6F1A732B446ACLL, 0x2E7066FF67701C2ALL, 1UL, 1UL,
              0x2E7066FF67701C2ALL, 0x4ED6F1A732B446ACLL, 0xCB295E0BED3F6F53LL,
              0xE746994BA50BD24CLL},
             {18446744073709551613UL, 0x1A679923B0AF2E55LL,
              0xE51C36D8724A5D39LL, 0xCB295E0BED3F6F53LL, 1UL,
              18446744073709551610UL, 0UL, 18446744073709551615UL},
             {0UL, 0xE746994BA50BD24CLL, 18446744073709551610UL,
              0xCB295E0BED3F6F53LL, 0UL, 0xCB295E0BED3F6F53LL,
              18446744073709551610UL, 0xE746994BA50BD24CLL}}};
        int32_t l_679 = 4L;
        int32_t l_751 = 0xA776C771L;
        int32_t l_752 = 1L;
        int i, j, k;
        l_655[0] &=
            ((~(safe_mul_func_int16_t_s_s(
                 (safe_add_func_uint16_t_u_u(
                     (0xC6212ABFE3EE249DLL >=
                      (safe_rshift_func_uint16_t_u_u(
                          (!(safe_lshift_func_uint8_t_u_u(
                              (p_63 =
                                   (0xCFA738BCAB1D74DFLL ^
                                    (!(safe_mul_func_uint16_t_u_u(
                                        (g_421[2][1][1] <
                                         (0x274BL &&
                                          ((((g_420[2][1] ||
                                              (safe_mod_func_int16_t_s_s(
                                                  (safe_add_func_int8_t_s_s(
                                                      (l_609 =
                                                           (l_163.f2 =
                                                                ((((((safe_add_func_int64_t_s_s(
                                                                         l_84[l_81]
                                                                             [g_131],
                                                                         (safe_sub_func_int32_t_s_s(
                                                                             (((((l_654 =
                                                                                      (p_62 ||
                                                                                       ((+((g_559
                                                                                                [l_81],
                                                                                            (safe_add_func_int64_t_s_s(
                                                                                                0xA53C1F47E488B108LL,
                                                                                                p_61))),
                                                                                           p_64.f2)),
                                                                                        g_356))) ^
                                                                                 0xA6L) <=
                                                                                g_251) <
                                                                               (-5L)) ==
                                                                              4294967294UL),
                                                                             l_80)))) ||
                                                                     l_629
                                                                         [0]
                                                                         [2]) ==
                                                                    0x59B0L),
                                                                   l_603[0]) &&
                                                                  0x59114B7581DAB8D1LL) <
                                                                 0x32L))),
                                                      p_64.f1)),
                                                  0x7815L))) ||
                                             6L) < 0xD3L) >= l_163.f1))),
                                        p_61))))),
                              7))),
                          8))),
                     0x3DFCL)),
                 g_388.f0))) &&
             p_61);
        l_656[1][5][3] = g_251;
        if ((~(safe_lshift_func_int8_t_s_s((p_61 >= p_61), 7)))) {
          for (g_86 = 0; (g_86 <= 1); g_86 += 1) {
            int i, j;
            g_388.f0 = (safe_mod_func_int64_t_s_s(
                ((safe_add_func_int64_t_s_s(
                     ((g_388.f2 &=
                       (g_420[(g_86 + 1)][(g_131 + 1)],
                        (safe_sub_func_uint8_t_u_u(
                            ((g_421[3][7][1] !=
                              (((((g_559[(g_86 + 4)] = g_506) >=
                                  (((safe_mul_func_int8_t_s_s(
                                        (g_420[(g_86 + 1)][(g_131 + 1)] |
                                         ((safe_add_func_uint8_t_u_u(
                                              g_420[2][1], 255UL)) &
                                          g_421[3][7][1])),
                                        (((safe_rshift_func_int8_t_s_u(
                                              g_388.f3,
                                              (safe_lshift_func_uint16_t_u_s(
                                                  ((((((safe_lshift_func_uint8_t_u_u(
                                                           (((((safe_add_func_uint16_t_u_u(
                                                                   (+((g_131 !=
                                                                       65535UL),
                                                                      p_61)),
                                                                   0UL)) >=
                                                               l_655[0]) ==
                                                              p_64.f2),
                                                             5UL) >= g_35.f0),
                                                           g_40)) >= 0x68L) <
                                                      g_420[2][1]) != (-1L)),
                                                    g_420[1][9]) &
                                                   0x9F85C223L),
                                                  3)))) > l_654) <=
                                         l_629[0][1]))),
                                    7L) &&
                                   g_391)) &&
                                 l_84[1][0]),
                                p_60) <= g_250)),
                             0x6BL),
                            p_63)))) &
                      g_153),
                     p_64.f2)) < 0x783806EBA17043C5LL),
                p_64.f0));
          }
          l_679 = 0xA0F5BF3BL;
          g_356 = p_64.f2;
        } else {
          int16_t l_686[3];
          uint32_t l_711 = 4294967295UL;
          struct S0 l_777 = {0, 0xE7C9041025406784LL, 918, 11};
          int i;
          for (i = 0; i < 3; i++)
            l_686[i] = 0xD6D2L;
          g_421[1][3][4] |=
              ((safe_rshift_func_int8_t_s_s(
                   (((0x41L ^ (p_63 = 0xC6L)) &
                     (safe_sub_func_int8_t_s_s(
                         l_628,
                         ((safe_sub_func_int8_t_s_s(
                              0xE0L,
                              (l_686[1] ||
                               (((safe_sub_func_int32_t_s_s(
                                     1L, (safe_mul_func_int8_t_s_s(
                                             (0x22L < (l_691++)),
                                             (safe_mul_func_uint16_t_u_u(
                                                 (+l_628),
                                                 ((((safe_sub_func_uint64_t_u_u(
                                                        (g_391 || p_64.f0),
                                                        p_64.f3)),
                                                    p_64.f3),
                                                   p_64.f3) < p_64.f1))))))) >=
                                 0x4013D0D146610D6FLL),
                                p_62)))),
                          0x0BL)))),
                    g_251),
                   g_316)) ||
               p_61);
          for (g_40 = 0; (g_40 <= 1); g_40 += 1) {
            int8_t l_710 = 0xABL;
            g_388.f2 =
                (((--g_559[6]) ^
                  (((p_64.f3 >
                     (safe_mul_func_uint16_t_u_u(
                         (p_62 |
                          ((l_679, 0x7BFAL) >
                           (g_355,
                            (((g_420[2][1] <=
                               (g_2 &&
                                ((safe_add_func_uint32_t_u_u(
                                     (safe_mod_func_int32_t_s_s(
                                         (((((l_710 =
                                                  (((((safe_sub_func_uint8_t_u_u(
                                                          0x45L, p_64.f3)) <
                                                      65533UL) >= p_64.f3) !=
                                                    (-1L)),
                                                   l_709)) |
                                             1L) > g_154) <= 0xDE6B5313L) |
                                          l_606),
                                         1UL)),
                                     g_506)) ||
                                 l_711))),
                              p_64.f2),
                             0L)))),
                         g_355))) == 0x2E41A14F558D61F0LL) >= 5UL)),
                 l_712);
            l_609 = l_710;
            if (g_35.f2)
              continue;
          }
          for (g_159 = 0; (g_159 <= 1); g_159 += 1) {
            int64_t l_713 = 0L;
            int32_t l_714 = 0L;
            int32_t l_715 = (-6L);
            int i, j;
            l_716++;
                        g_388.f2 ^= (((safe_mul_func_int8_t_s_s((((((safe_mul_func_uint16_t_u_u((g_755[7] &= ((((((safe_add_func_uint64_t_u_u(((safe_sub_func_int64_t_s_s((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_u((g_421[4][3][3] <= g_559[6]), (safe_mod_func_uint32_t_u_u(((p_60 ^ 3UL) | (p_64.f1 ^= ((~(safe_rshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_s((((safe_mul_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((((l_709 = ((((g_420[3][6] & (safe_add_func_uint64_t_u_u((((l_751 |= ((g_506 = ((l_603[g_159] = (safe_lshift_func_uint8_t_u_s((safe_mul_func_uint8_t_u_u(p_64.f2, ((g_86 = (g_312 = ((safe_mod_func_int8_t_s_s((g_355 , (l_679 == (0xF0FDE7FAL & p_63))), p_62)) , p_64.f3))) && 2UL))), 3))) & g_35.f2)) , g_750[0][4][0])) < 18446744073709551608UL) | p_64.f0), l_752))) & g_420[1][6]) , l_654) , 1UL)) ^ (-2L)) ^ p_63), g_559[l_81])) & l_609), l_609)) | 0L) || 4UL), 6)), 1))) && g_40))), 1UL)))), l_753[0])), p_60)) ^ l_714), p_60)) > g_754[1][9]) , l_80) < g_154) <= l_711) <= g_355)), (-6L))) != g_250) > p_63) && l_713) & 0xF118L), 8UL)) <= p_60) <= g_203);
                        l_751 =
                            (((safe_lshift_func_int16_t_s_s(
                                  p_63,
                                  ((((0x88B1EDC22DD11D12LL <=
                                      (safe_sub_func_int64_t_s_s(
                                          l_679, g_559[l_81]))) >= l_84[1][0]) |
                                    g_131) <
                                   (safe_rshift_func_int16_t_s_s(
                                       ((safe_lshift_func_uint8_t_u_s(
                                            (p_64.f2 >=
                                             (safe_add_func_uint64_t_u_u(
                                                 ((p_63,
                                                   (((-1L) & 0x5A264749L) !=
                                                    18446744073709551615UL)) >=
                                                  l_753[0]),
                                                 g_131))),
                                            g_153)) ||
                                        g_754[1][9]),
                                       3))))),
                              0xC4L) != p_60);
                        p_64.f2 = (safe_lshift_func_int8_t_s_u(
                            (+((safe_mul_func_uint8_t_u_u(
                                   (safe_lshift_func_int16_t_s_u(
                                       ((g_388 = p_64),
                                        (((!((-1L) &&
                                             (l_776 ==
                                              (l_777,
                                               ((((l_679 = (!(
                                                       (safe_mul_func_int16_t_s_s(
                                                           (g_754[2][3] !=
                                                            g_755[7]),
                                                           (safe_lshift_func_int16_t_s_u(
                                                               p_64.f1,
                                                               (((safe_rshift_func_uint16_t_u_s(
                                                                     (l_609 =
                                                                          g_158),
                                                                     2)),
                                                                 ((l_713 <=
                                                                   0xD7B9L),
                                                                  65532UL)) ||
                                                                g_35.f2))))) ==
                                                       0xBAL))) >= l_655[1]) ^
                                                 65533UL) <= 0xF91934E9L))))) !=
                                          l_691) >= g_559[6])),
                                       l_656[1][5][3])),
                                   g_506)) ^
                               p_64.f3)),
                            g_559[7]));
          }
          for (p_63 = 0; (p_63 <= 2); p_63 += 1) {
            int i, j, k;
            l_84[(p_63 + 7)][(p_63 + 4)] =
                ((((0x332F248BL &
                    ((safe_add_func_int32_t_s_s(
                         (safe_mul_func_int16_t_s_s(
                             l_84[l_81][g_131],
                             l_656[p_63][(p_63 + 2)][(p_63 + 4)])),
                         0x3FC18A0FL)) ||
                     (safe_mul_func_int16_t_s_s(
                         g_356,
                         (((((safe_lshift_func_uint8_t_u_u(
                                 ((safe_mul_func_uint16_t_u_u(
                                      (safe_add_func_int16_t_s_s(
                                          (g_250 =
                                               ((((safe_mul_func_int8_t_s_s(
                                                      (safe_rshift_func_int8_t_s_s(
                                                          p_62, 5)),
                                                      (((g_388.f3,
                                                         (((g_388,
                                                            (((p_64, g_388.f3) >
                                                              p_64.f1),
                                                             p_60)),
                                                           0x46F9L),
                                                          l_753[0])) <= p_61) >=
                                                       0L))) < g_755[7]),
                                                 p_64.f3) ||
                                                0xC45B6127L)),
                                          g_420[2][5])),
                                      2UL)),
                                  g_316),
                                 6)) |
                             g_85) == p_60),
                           0L) == g_755[6]))))) &&
                   0x26D46B2CL),
                  g_750[0][3][0]) <= g_559[6]);
            return l_777;
          }
        }
      } else {
        uint32_t l_812 = 4294967290UL;
        uint64_t l_858 = 0xC85CBCF712F44AA6LL;
        int32_t l_875 = (-9L);
        for (l_609 = 0; (l_609 == 29); ++l_609) {
          for (l_606 = 15; (l_606 == 38);
               l_606 = safe_add_func_int32_t_s_s(l_606, 7)) {
            if (g_35.f3)
              break;
          }
          p_64.f2 &=
              (p_64.f0 =
                   (((safe_mod_func_uint64_t_u_u(g_388.f3, l_807)),
                     ((safe_mul_func_int8_t_s_s(
                          (safe_add_func_uint8_t_u_u(p_64.f1, g_754[1][9])),
                          g_420[2][1])),
                      (p_64.f1, ((l_812 >= (safe_sub_func_int64_t_s_s(
                                               0xB9867DA03364F444LL,
                                               (((safe_lshift_func_uint8_t_u_u(
                                                     7UL, l_812)) ^
                                                 1L) |
                                                g_559[7])))) ^
                                 (-2L))))) ||
                    247UL));
          if (l_163.f0) {
            g_85 ^= 0x5D1F78DDL;
          } else {
            if (p_60)
              break;
          }
        }
        if (l_812) {
          uint8_t l_817 = 255UL;
          for (g_251 = 0; (g_251 <= 2); g_251 += 1) {
            uint16_t l_857[7];
            int32_t l_859 = 0xBDE63232L;
            struct S0 l_864[10] = {{0, 0x2865A4B2F14226F9LL, 940, 5},
                                   {0, 0xA9777A2724BE3C8DLL, -970, 4},
                                   {0, 0x2865A4B2F14226F9LL, 940, 5},
                                   {0, 0x2865A4B2F14226F9LL, 940, 5},
                                   {0, 0xA9777A2724BE3C8DLL, -970, 4},
                                   {0, 0x2865A4B2F14226F9LL, 940, 5},
                                   {0, 0x2865A4B2F14226F9LL, 940, 5},
                                   {0, 0xA9777A2724BE3C8DLL, -970, 4},
                                   {0, 0x2865A4B2F14226F9LL, 940, 5},
                                   {0, 0x2865A4B2F14226F9LL, 940, 5}};
            int i;
            for (i = 0; i < 7; i++)
              l_857[i] = 65535UL;
            --l_817;
                        g_755[7] = (safe_rshift_func_int8_t_s_s((safe_add_func_int32_t_s_s((((p_63 > 0x75B8L) ^ ((safe_unary_minus_func_int32_t_s((safe_mod_func_int32_t_s_s((p_64 , (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_u(((safe_sub_func_uint8_t_u_u((0xB8L != (safe_sub_func_int16_t_s_s((!(safe_mul_func_int16_t_s_s((g_153 &= (safe_add_func_int16_t_s_s((l_859 = ((l_163.f0 = (l_654 = (safe_add_func_int8_t_s_s(0x42L, ((safe_sub_func_uint64_t_u_u(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((safe_add_func_int8_t_s_s((((safe_mul_func_int64_t_s_s((-1L), (((((l_852 == ((safe_rshift_func_int8_t_s_u(((0xEFE83DE77FB6EB79LL ^ (safe_add_func_int16_t_s_s((p_60 | g_388.f2), g_356))) != g_506), p_64.f1)) <= l_857[4])) <= 0x81AEL) < 0x4173190CL) ^ g_388.f2) != g_388.f0))) || l_857[4]) & l_163.f1), p_62)), g_154)), 0x81A59A6EL)) == 7UL), g_2)) <= g_391))))) ^ l_858)), l_753[0]))), 65526UL))), g_35.f1))), p_60)) != p_64.f0), 4)), l_709))), 4294967295UL)))) > 0UL)) != p_64.f3), g_390)), 7));
                        g_421[3][7][1] =
                            ((safe_lshift_func_uint16_t_u_s(
                                 (safe_mul_func_uint8_t_u_u(
                                     1UL, (g_420[2][1] < p_64.f3))),
                                 p_64.f0)) ||
                             g_388.f1);
                        l_865 = l_864[0];
          }
          l_875 = ((0x1B4A0C91585D69BALL || (-7L)) !=
                   (g_35.f3 ^
                    ((safe_lshift_func_int16_t_s_u(
                         (((((l_858 ^ (-3L)) >= l_868[1][4][0]) &&
                            ((safe_lshift_func_uint16_t_u_s(
                                 (p_61 != l_817),
                                 (safe_sub_func_uint32_t_u_u(
                                     ((safe_mod_func_uint64_t_u_u(
                                          (p_64.f0 | p_62), (-10L))) == 1L),
                                     0x9613F3E3L)))) &&
                             0xE3F7E96DL)),
                           65528UL) >= l_812),
                         l_80)) < 0xAEDD5B65L)));
        } else {
          return p_64;
        }
        return g_388;
      }
    }
    for (g_388.f1 = 0; g_388.f1 < 6; g_388.f1 += 1) {
      for (p_63 = 0; p_63 < 10; p_63 += 1) {
        g_754[g_388.f1][p_63] = 18446744073709551615UL;
      }
    }
    g_356 =
        ((p_63 |= (safe_lshift_func_int8_t_s_s((-4L), 5))),
         ((safe_mod_func_uint32_t_u_u(
              (g_559[l_81] ==
               ((((safe_add_func_uint32_t_u_u(
                      ((((((safe_mul_func_int16_t_s_s(
                               (safe_sub_func_uint16_t_u_u(
                                   ((safe_sub_func_int16_t_s_s(
                                        (safe_rshift_func_uint16_t_u_s(
                                            l_709, g_754[1][2])),
                                        ((g_153 ^
                                          ((((safe_mul_func_uint16_t_u_u(
                                                 ((((g_506 = (safe_mul_func_int16_t_s_s(
                                                         (((safe_add_func_int8_t_s_s(
                                                               ((((safe_mul_func_uint8_t_u_u(
                                                                      g_754[5]
                                                                           [8],
                                                                      l_898
                                                                          [0]
                                                                          [0])) ==
                                                                  p_64.f3) >=
                                                                 (safe_rshift_func_uint16_t_u_s(
                                                                     (~((((p_64.f1 |
                                                                           (-1L)) !=
                                                                          18446744073709551614UL) <=
                                                                         g_35.f3),
                                                                        g_388
                                                                            .f3)),
                                                                     3))),
                                                                0xFDL),
                                                               l_898[0][3])),
                                                           g_316) ^
                                                          g_250),
                                                         l_80))) |
                                                    g_35.f0) |
                                                   l_709) ^
                                                  p_64.f2),
                                                 p_64.f3)) &&
                                             g_750[0][4][0]) &&
                                            p_64.f0) ^
                                           l_902)) &
                                         g_35.f1))) > g_312),
                                   g_356)),
                               g_420[1][8])) != p_64.f0) < g_559[7]) <
                         p_64.f2) |
                        0x1E2CF51AF3294D6CLL) |
                       l_776),
                      (-1L))) < p_62),
                 0UL) &
                65530UL)),
              p_63)),
          g_154));
    for (g_250 = 6; (g_250 >= 3); g_250 -= 1) {
      int32_t l_925[7][3] = {{0xC717F1A4L, 0xC717F1A4L, 0x38CA653FL},
                             {0xB28C7628L, (-1L), 0x38CA653FL},
                             {(-1L), 0xB28C7628L, 0x38CA653FL},
                             {0xC717F1A4L, 0xC717F1A4L, 0x38CA653FL},
                             {0xB28C7628L, (-1L), 0x38CA653FL},
                             {(-1L), 0xB28C7628L, 0x38CA653FL},
                             {0xC717F1A4L, 0xC717F1A4L, 0x38CA653FL}};
      int32_t l_926 = 0xC858E9C8L;
      uint8_t l_938[10] = {0x41L, 0x41L, 0x41L, 0x41L, 0x41L,
                           0x41L, 0x41L, 0x41L, 0x41L, 0x41L};
      int64_t l_1048 = 0L;
      uint32_t l_1089 = 7UL;
      int i, j;
      if (g_316)
        goto lbl_903;
      if ((safe_mod_func_int16_t_s_s(
              (safe_mod_func_int16_t_s_s(
                  ((safe_lshift_func_uint8_t_u_s(
                       (((l_84[(g_250 + 3)][(l_81 + 1)] >=
                          (g_559[6] =
                               ((l_865.f2 = g_559[l_81]) >
                                (safe_rshift_func_int16_t_s_s(
                                    ((safe_add_func_int64_t_s_s(
                                         g_356,
                                         (safe_rshift_func_int16_t_s_s(
                                             p_61,
                                             (l_925[0][0] = (safe_rshift_func_int16_t_s_u(
                                                  (p_64.f3 <
                                                   ((safe_mod_func_uint16_t_u_u(
                                                        (((((safe_lshift_func_uint16_t_u_u(
                                                                (safe_sub_func_int64_t_s_s(
                                                                    ((p_64.f2 ^
                                                                      0xCAA553492565BC81LL),
                                                                     ((((((1UL >=
                                                                           ((l_84[(
                                                                                 g_250 +
                                                                                 3)][(
                                                                                 l_81 +
                                                                                 1)] ==
                                                                             p_64.f2) <=
                                                                            p_61)) ||
                                                                          g_203) !=
                                                                         0xE56C3AFE55254D94LL) &&
                                                                        p_62) ^
                                                                       l_924) &&
                                                                      l_84[(
                                                                          g_250 +
                                                                          3)][(
                                                                          l_81 +
                                                                          1)])),
                                                                    g_559
                                                                        [l_81])),
                                                                9)) ^
                                                            g_754[1][9]) &&
                                                           g_250) > g_250) ^
                                                         g_559[l_81]),
                                                        0xEA49L)) != l_83)),
                                                  g_35.f3))))))) |
                                     g_250),
                                    p_61))))) &
                         p_63) > (-1L)),
                       4)) < l_84[(g_250 + 3)][(l_81 + 1)]),
                  6UL)),
              g_755[7]))) {
        int8_t l_941[8] = {(-1L), 0x6CL, 0x6CL, (-1L),
                           0x6CL, 0x6CL, (-1L), 0x6CL};
        int32_t l_956 = 0L;
        int32_t l_957 = 1L;
        int32_t l_958 = 0xE17DBF5EL;
        int32_t l_962 = 0xD554C6C3L;
        struct S0 l_1038 = {0, -2L, -237, 2};
        int64_t l_1053 = (-6L);
        int32_t l_1057 = 3L;
        int32_t l_1058[6][5][3] = {{{0xDFCA07DEL, 0x60A131E5L, (-1L)},
                                    {0x079C4F57L, 0xA0515889L, 0x079C4F57L},
                                    {0xDFCA07DEL, (-1L), (-4L)},
                                    {8L, 0xA0515889L, 0xC374AEAFL},
                                    {0x60A131E5L, 0x60A131E5L, (-4L)}},
                                   {{0x079C4F57L, (-1L), 0x079C4F57L},
                                    {0x60A131E5L, (-1L), (-1L)},
                                    {8L, (-1L), 0xC374AEAFL},
                                    {0xDFCA07DEL, 0x60A131E5L, (-1L)},
                                    {0x079C4F57L, 0xA0515889L, 0x079C4F57L}},
                                   {{0xDFCA07DEL, (-1L), (-4L)},
                                    {8L, 0xA0515889L, 0xC374AEAFL},
                                    {0x60A131E5L, 0x60A131E5L, (-4L)},
                                    {0x079C4F57L, (-1L), 0x079C4F57L},
                                    {0x60A131E5L, (-1L), (-1L)}},
                                   {{8L, (-1L), 0xC374AEAFL},
                                    {0xDFCA07DEL, 0x60A131E5L, (-1L)},
                                    {0x079C4F57L, 0xA0515889L, 0x079C4F57L},
                                    {0xDFCA07DEL, (-1L), (-4L)},
                                    {8L, 0xA0515889L, 0xC374AEAFL}},
                                   {{0x60A131E5L, 0x60A131E5L, (-4L)},
                                    {0x079C4F57L, (-1L), 0x079C4F57L},
                                    {0x60A131E5L, (-1L), (-1L)},
                                    {8L, (-1L), 0xC374AEAFL},
                                    {0xDFCA07DEL, 0x60A131E5L, (-1L)}},
                                   {{0x079C4F57L, 0xA0515889L, 0x079C4F57L},
                                    {0xDFCA07DEL, (-1L), (-4L)},
                                    {8L, 0xA0515889L, 0xC374AEAFL},
                                    {0x60A131E5L, 0x60A131E5L, (-4L)},
                                    {0x079C4F57L, (-1L), 0x079C4F57L}}};
        int32_t l_1061 = 8L;
        int8_t l_1062 = 0x0FL;
        int32_t l_1063 = (-1L);
        int i, j, k;
        if (l_926)
          break;
        for (p_64.f1 = 1; (p_64.f1 >= 0); p_64.f1 -= 1) {
          int32_t l_953 = (-5L);
          int i;
          l_941[4] |=
              (l_603[p_64.f1] >=
               (safe_mod_func_uint16_t_u_u(
                   ((safe_lshift_func_uint8_t_u_u(p_64.f2, 0)),
                    (safe_add_func_int64_t_s_s(
                        ((safe_lshift_func_uint16_t_u_s(p_63, 9)) >=
                         (safe_sub_func_int32_t_s_s(
                             ((l_603[p_64.f1] || g_251) !=
                              ((safe_unary_minus_func_uint64_t_u(
                                   ((l_938[4], 1UL) |
                                    ((safe_rshift_func_int8_t_s_u(
                                         ((0xBAD58878L < 7UL) != g_594), 4)) |
                                     p_63)))) ||
                               0x5E0D909FL)),
                             p_64.f3))),
                        l_925[4][2]))),
                   g_35.f1)));
          g_421[3][7][1] =
              (g_40 <
               (safe_sub_func_uint32_t_u_u(
                   ((g_420[2][1] &&
                     (l_603[p_64.f1] =
                          (safe_rshift_func_int8_t_s_s(g_250, 5)))) !=
                    ((p_63 <=
                      (safe_sub_func_int16_t_s_s(
                          p_61, (safe_rshift_func_uint8_t_u_s(
                                    (~(safe_mod_func_uint64_t_u_u(
                                        ((l_953 | 0xD953L) && 0xB74C2C24L),
                                        g_421[2][9][3]))),
                                    g_153))))) &
                     p_60)),
                   p_61)));
          if (g_35.f2)
            break;
        }
        if (((g_594 = (p_61 &= g_40)), p_64.f1)) {
          int64_t l_955[4];
          int32_t l_963 = (-8L);
          uint32_t l_964 = 0UL;
          int i;
          for (i = 0; i < 4; i++)
            l_955[i] = 8L;
          g_388 = (l_954 = g_388);
          if (g_35.f3)
            continue;
          l_964--;
        } else {
          g_35.f0 |= 0xAF702FE3L;
        }
        if ((safe_mod_func_uint32_t_u_u(
                (g_755[1] >=
                 ((!(g_750[0][4][0]++)) >
                  (+(((g_388.f0 = (safe_rshift_func_uint16_t_u_u(
                           (safe_rshift_func_int8_t_s_s(
                               (l_865.f2 =
                                    ((p_64.f1 = 1L) >=
                                     (((safe_add_func_uint8_t_u_u(
                                           (g_86--),
                                           (((safe_add_func_int16_t_s_s(
                                                 0x14BCL,
                                                 (safe_mod_func_int8_t_s_s(
                                                     l_865.f3, 0x03L)))) ==
                                             0x80A19FAF02B46F85LL),
                                            (((0xBEAA8E62L <=
                                               (safe_rshift_func_int16_t_s_s(
                                                   (safe_mod_func_int16_t_s_s(
                                                       (!(((((safe_lshift_func_int16_t_s_u(
                                                                 (((safe_lshift_func_int8_t_s_u(
                                                                       ((safe_mul_func_int16_t_s_s(
                                                                            (l_84[(
                                                                                 g_250 +
                                                                                 3)][(
                                                                                 l_81 +
                                                                                 1)],
                                                                             (safe_rshift_func_uint16_t_u_u(
                                                                                 (((p_64.f3 ==
                                                                                    3UL) |
                                                                                   0xEA6C0D16L) ||
                                                                                  8UL),
                                                                                 l_941
                                                                                     [0]))),
                                                                            (-7L))) !=
                                                                        p_64.f3),
                                                                       p_64.f0)) !=
                                                                   g_421[3][7]
                                                                        [1]) >
                                                                  0x1C009E89L),
                                                                 g_559[6])),
                                                             0xDD72L) < 7UL) >
                                                           l_956),
                                                          l_941[3])),
                                                       p_64.f0)),
                                                   4))) < 0xACL) != g_391)))) <
                                       0x3CD7143A49B39B1ELL),
                                      1L))),
                               l_716)),
                           1))) &
                      (-1L)) != p_64.f3)))),
                g_420[2][1]))) {
          int32_t l_1022 = 0L;
          int32_t l_1023 = 0xAE4D7B31L;
          for (p_60 = 0; (p_60 <= 1); p_60 += 1) {
            uint32_t l_1024 = 0x56AFC90CL;
            int32_t l_1035 = 0xC77FAB01L;
            int32_t l_1039 = (-6L);
            int i;
                        g_35.f2 = ((l_84[1][0] = (p_61 , (!(((l_603[p_60] = ((((safe_mod_func_int64_t_s_s((((safe_sub_func_int8_t_s_s((l_957 = (safe_mul_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_mod_func_uint8_t_u_u((0L ^ (p_64.f1 | (safe_lshift_func_uint8_t_u_s((g_391 = (l_1038.f0 = (safe_sub_func_uint16_t_u_u(g_594, (safe_rshift_func_int16_t_s_u((((safe_rshift_func_uint16_t_u_u((g_388.f2 | ((safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s(((l_1024--) && (safe_mul_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((g_559[6] == ((((++g_1032[4]) == ((l_1035 &= p_61) > (l_1023 = l_959[2]))) < (safe_lshift_func_int8_t_s_u(((((l_1038 , 0UL) >= 0UL) , g_420[0][9]) == p_64.f1), 5))) , l_709)), 2)) && l_84[(g_250 + 3)][(l_81 + 1)]), p_64.f0))), 4)), l_954.f2)) & g_131)), 3)) , l_1022) & 0x97D4L), g_356)))))), l_865.f0)))), p_62)) , p_64.f2), g_594)) | p_62), p_61))), (-10L))) && g_158) & l_1022), l_712)) < l_1039) != 0x20AEL) && l_1038.f1)) | g_754[1][9]) || 8UL)))) & 1UL);
                        if (g_158)
                          continue;
          }
        } else {
          int16_t l_1047[7] = {(-1L), (-1L), (-1L), (-1L), (-1L), (-1L), (-1L)};
          int32_t l_1049 = 0x5248070FL;
          int32_t l_1050 = 1L;
          int16_t l_1051 = 0xFB52L;
          int32_t l_1052[4];
          int16_t l_1055[4][7][9] = {
              {{0x815BL, (-7L), 0x5FA1L, (-1L), 0x5FA1L, (-7L), 0x815BL, (-9L),
                0xEB27L},
               {0xD21BL, 0xAEC4L, 0L, 0x145BL, 4L, 3L, 0x679EL, (-7L), 1L},
               {0L, 6L, (-9L), 0xBD3AL, (-9L), (-3L), (-3L), (-9L), 0xBD3AL},
               {0L, 3L, 0L, (-1L), 0x1DDEL, 4L, 0xAD10L, 0x0FFBL, 0x3A71L},
               {1L, 0xBD3AL, (-1L), 0x0FFAL, 0xB77EL, (-9L), 0L, 1L, 0x8A51L},
               {(-1L), (-1L), 3L, 0L, 0L, 3L, (-1L), (-1L), (-2L)},
               {0xC548L, 0xEB27L, (-1L), (-3L), (-1L), 6L, 0x5FA1L, (-9L),
                0xB77EL}},
              {{(-1L), 4L, 1L, 3L, (-2L), 0xAEC4L, (-1L), 0xAEC4L, (-2L)},
               {0x8A51L, 3L, 3L, 0x8A51L, 0L, (-7L), 1L, 0xC548L, 6L},
               {3L, 1L, 4L, (-1L), 0x4971L, 0x1DDEL, 0x3A71L, (-1L), 9L},
               {(-3L), (-1L), 0xEB27L, 0xC548L, 0L, 0xC548L, 0xEB27L, (-1L),
                (-3L)},
               {0L, 3L, (-1L), (-1L), (-2L), 3L, 0x4971L, 0xAFC2L, 0L},
               {0x1A4CL, 0x5FA1L, (-3L), 0xF19CL, (-1L), 0x0FFAL, 0x8A51L,
                0x8A51L, 0x0FFAL},
               {0L, (-2L), 0x4971L, (-2L), 0L, 0x3A71L, (-1L), 0x679EL, 1L}},
              {{(-3L), 0xBD3AL, 0x3620L, 3L, (-7L), 1L, 6L, 0xF19CL, (-9L)},
               {3L, 0xAEC4L, 0x1DDEL, 3L, 0x3A71L, 0x3A71L, 3L, 0x1DDEL,
                0xAEC4L},
               {0x8A51L, 1L, 0L, (-9L), 0xB77EL, 0x0FFAL, (-1L), 0xBD3AL, 1L},
               {(-1L), (-1L), 0x3A71L, 0x4971L, (-1L), 3L, 0xAD10L, 0L,
                0xAD10L},
               {0xC548L, 1L, (-9L), (-9L), 1L, 0xC548L, 0x3620L, 0x1A4CL,
                (-1L)},
               {(-1L), 0xAEC4L, (-1L), 0xAFC2L, 0x679EL, 0x1DDEL, 0L, (-2L),
                (-1L)},
               {0xF19CL, 0xBD3AL, 0x1A4CL, 0x6F82L, 0x3620L, (-7L), 0x3620L,
                0x6F82L, 0x1A4CL}},
              {{(-2L), (-2L), 9L, 0L, 1L, 0xAEC4L, 0xAD10L, (-1L), 3L},
               {3L, 0x5FA1L, 1L, 0xEB27L, 0x8A51L, 6L, (-1L), 0x3620L, 0x3620L},
               {3L, 3L, 9L, 0x679EL, 9L, 3L, 3L, (-7L), 0L},
               {(-9L), (-1L), 0x1A4CL, 0L, 0x6F82L, 0xBD3AL, 6L, (-7L),
                0xC548L},
               {0x4971L, 1L, (-1L), 4L, (-7L), (-1L), (-1L), (-7L), 4L},
               {(-9L), 0x815BL, 0xB77EL, 0x1A4CL, 1L, 0xEB27L, 6L, 0xC548L, 1L},
               {0xAD10L, (-1L), 9L, 0x1DDEL, 3L, 4L, 0xD21BL, 0xAFC2L, 1L}}};
          int i, j, k;
          for (i = 0; i < 4; i++)
            l_1052[i] = 0L;
          p_64.f2 = p_62;
          if (((((((p_60 &= (safe_lshift_func_uint8_t_u_u(
                        (l_84[(g_250 + 3)][(l_81 + 1)] =
                             ((0x4AC36A84699061E7LL || 0x33DE3F1A7612CA71LL) ^
                              0L)),
                        4))) |
                   (-6L)) >= g_754[3][1]) <=
                 (l_1050 = (p_64.f3 &
                            (+(safe_lshift_func_uint8_t_u_s(
                                (0x9AF1L |
                                 (l_1049 = (((p_62++) ^
                                             ((l_1048 &=
                                               (((((l_163.f0 = g_35.f1) !=
                                                   g_154) < l_1047[5]) != p_61),
                                                l_753[0])) ^
                                              0UL)) >= p_61))),
                                1)))))) >= l_1051) &
               g_1031)) {
            return p_64;
          } else {
            int32_t l_1054[9] = {0x57571A95L, 0x1334ACF3L, 0x57571A95L,
                                 0x1334ACF3L, 0x57571A95L, 0x1334ACF3L,
                                 0x57571A95L, 0x1334ACF3L, 0x57571A95L};
            int32_t l_1056 = 0xC17A9B95L;
            int32_t l_1059 = (-7L);
            int32_t l_1060[7][7][4] = {
                {{(-8L), 0x66E1FDF0L, (-10L), (-8L)},
                 {(-10L), (-8L), 0L, 0L},
                 {0L, 0L, (-8L), 0xC448FE93L},
                 {0L, 0x66E1FDF0L, 0L, 0L},
                 {(-10L), 0xC448FE93L, (-10L), 0L},
                 {(-8L), 0xC448FE93L, (-8L), 0L},
                 {0xC448FE93L, 0x66E1FDF0L, 0x66E1FDF0L, 0xC448FE93L}},
                {{(-10L), 0L, 0x66E1FDF0L, 0L},
                 {0xC448FE93L, (-8L), (-8L), (-8L)},
                 {(-8L), 0x66E1FDF0L, (-10L), (-8L)},
                 {(-10L), (-8L), 0L, 0L},
                 {0L, 0L, (-8L), 0xC448FE93L},
                 {0L, 0x66E1FDF0L, 0L, 0L},
                 {(-10L), 0xC448FE93L, (-10L), 0L}},
                {{(-8L), 0xC448FE93L, (-8L), 0L},
                 {0xC448FE93L, 0x66E1FDF0L, 0x66E1FDF0L, 0xC448FE93L},
                 {(-10L), 0L, 0x66E1FDF0L, 0L},
                 {0xC448FE93L, (-8L), (-8L), (-8L)},
                 {(-8L), 0x66E1FDF0L, (-10L), (-8L)},
                 {(-10L), (-8L), 0L, 0L},
                 {0L, 0L, (-8L), 0xC448FE93L}},
                {{0L, 0x66E1FDF0L, 0L, 0L},
                 {(-10L), 0xC448FE93L, (-10L), 0L},
                 {(-8L), 0xC448FE93L, (-8L), 0L},
                 {0xC448FE93L, 0x66E1FDF0L, 0x66E1FDF0L, 0xC448FE93L},
                 {(-10L), 0L, 0x66E1FDF0L, 0L},
                 {0xC448FE93L, (-8L), (-8L), (-8L)},
                 {(-8L), 0x66E1FDF0L, (-10L), (-8L)}},
                {{(-10L), (-8L), 0L, 0L},
                 {0L, 0L, (-8L), 0xC448FE93L},
                 {0L, 0x66E1FDF0L, 0L, 0L},
                 {(-10L), 0xC448FE93L, (-10L), 0L},
                 {(-8L), 0xC448FE93L, (-8L), 0L},
                 {0xC448FE93L, 0x66E1FDF0L, 0x66E1FDF0L, 0xC448FE93L},
                 {(-10L), 0L, 0x66E1FDF0L, 0L}},
                {{0xC448FE93L, (-8L), (-8L), (-8L)},
                 {(-8L), 0x66E1FDF0L, (-10L), (-8L)},
                 {(-10L), (-8L), 0L, 0L},
                 {0L, 0L, (-8L), 0xC448FE93L},
                 {0L, 0x66E1FDF0L, 0L, 0L},
                 {(-10L), 0xC448FE93L, (-10L), 0L},
                 {(-8L), 0x66E1FDF0L, 0L, (-10L)}},
                {{0x66E1FDF0L, (-8L), (-8L), 0x66E1FDF0L},
                 {(-10L), (-10L), (-8L), 0xAF199D9DL},
                 {0x66E1FDF0L, 0L, 0L, 0L},
                 {0L, (-8L), (-10L), 0L},
                 {(-10L), 0L, 0xAF199D9DL, 0xAF199D9DL},
                 {(-10L), (-10L), 0L, 0x66E1FDF0L},
                 {(-10L), (-8L), 0xAF199D9DL, (-10L)}}};
            uint16_t l_1064 = 0UL;
            int i, j, k;
            l_1064++;
            l_925[0][0] =
                ((safe_add_func_uint32_t_u_u(
                     ((g_1032[5] >
                       (p_64.f2 |
                        ((((p_61 = p_64.f1) == (p_64.f2 == g_421[3][7][1])) &
                          3L) >
                         ((safe_mod_func_uint32_t_u_u(
                              (safe_sub_func_int8_t_s_s(
                                  (safe_mod_func_int16_t_s_s(
                                      (safe_sub_func_uint16_t_u_u(
                                          (l_902 =
                                               (l_163.f0 =
                                                    (g_420[0][6] ^=
                                                     ((((p_62 =
                                                             (g_2,
                                                              (g_506 &=
                                                               0x387E3CDF10492640LL))) &
                                                        7UL) >= g_388.f2),
                                                      0x7C33L)))),
                                          0x5363L)),
                                      p_64.f2)),
                                  0x0AL)),
                              p_64.f2)) == 0xBDC1L)))),
                      1UL),
                     p_64.f2)) == 0x2389A102B3FBE4B4LL);
          }
        }
      } else {
        int8_t l_1080 = 2L;
        int32_t l_1090 = 1L;
        for (l_1048 = 0; (l_1048 <= 1); l_1048 += 1) {
          int32_t l_1087[5][5][1] = {
              {{0x039D1260L},
               {0x39501C4EL},
               {0x39501C4EL},
               {0x039D1260L},
               {1L}},
              {{0x6D1699AAL},
               {1L},
               {0x039D1260L},
               {0x39501C4EL},
               {0x39501C4EL}},
              {{0x039D1260L}, {1L}, {0x6D1699AAL}, {1L}, {0x039D1260L}},
              {{0x39501C4EL},
               {0x39501C4EL},
               {0x039D1260L},
               {1L},
               {0x6D1699AAL}},
              {{1L},
               {0x039D1260L},
               {0x39501C4EL},
               {0x39501C4EL},
               {0x039D1260L}}};
          uint32_t l_1088 = 0x851AEBF5L;
          int i, j, k;
          p_64.f2 =
              ((g_131 = (l_603[l_1048] = g_1021[4])) &
               (p_62 ^ ((safe_mul_func_uint16_t_u_u(
                            ((((safe_unary_minus_func_uint64_t_u(
                                   0xA46D5F4F3D787CA5LL)) &
                               (l_1080 < g_85)) &
                              ((((l_654 &= 0xC9B377A5L), p_64.f2) ||
                                ((g_754[0][3],
                                  (safe_add_func_int16_t_s_s(
                                      (g_594 = (g_158 |=
                                                (safe_lshift_func_uint16_t_u_s(
                                                    ((safe_mul_func_int8_t_s_s(
                                                         g_388.f3, 7UL)) !=
                                                     l_1087[2][4][0]),
                                                    l_1088)))),
                                      g_421[3][7][1]))) != g_421[3][7][1])),
                               g_559[l_81])) ||
                             l_1089),
                            g_506)),
                        g_754[4][9])));
        }
        for (g_40 = 0; (g_40 <= 1); g_40 += 1) {
          uint32_t l_1091[8] = {4294967295UL, 4294967295UL, 0x23DAB66DL,
                                4294967295UL, 4294967295UL, 0x23DAB66DL,
                                4294967295UL, 4294967295UL};
          int i;
          --l_1091[2];
          if (l_603[g_40])
            break;
        }
        g_35.f0 =
            ((1UL & l_938[4]) !=
             ((safe_sub_func_uint8_t_u_u(
                  ((g_153 =
                        ((g_388,
                          (safe_mul_func_uint16_t_u_u(
                              (250UL >
                               ((-1L) >
                                (((g_594 = (g_86,
                                            (l_1048 ^ (((++p_63) >=
                                                        ((((l_865.f2 = g_355) ||
                                                           0xECL) <= l_716) !=
                                                         p_60)) <= (-1L))))) ==
                                  g_1021[3]) != p_60))),
                              l_1080))) >= l_716)) != l_926),
                  p_64.f0)) < g_86));
        p_64.f0 = ((l_163.f1 > g_390),
                   (safe_add_func_uint16_t_u_u(g_559[l_81], (~p_63))));
      }
    }
  }
  return p_64;
}

static int32_t func_66(uint16_t p_67, struct S0 p_68) {
  uint32_t l_168 = 0x3F8D3DCDL;
  int8_t l_179[1][2];
  int64_t l_185 = (-7L);
  int32_t l_228 = 0x185051ADL;
  int32_t l_230 = 0x647FE7AAL;
  uint32_t l_268 = 0x20F4CF03L;
  int16_t l_359 = (-6L);
  int32_t l_473 = 0xDCCA3664L;
  int32_t l_510 = 0L;
  int32_t l_512[1][3][8];
  uint16_t l_544 = 6UL;
  int64_t l_551 = 6L;
  int32_t l_560 = 0x0C92ECC8L;
  struct S0 l_567[2][6][5] = {{{{-0, 0x71786727EA7006D1LL, 552, 9},
                                {0, 0x42C4DEBBA0133BA3LL, -707, 0},
                                {0, 0x8519C44ADFC325C0LL, 30, 11},
                                {0, 0L, 262, 3},
                                {-0, 0L, -471, 1}},
                               {{-0, -10L, 122, 9},
                                {-0, 0x71786727EA7006D1LL, 552, 9},
                                {0, 5L, 628, 13},
                                {-0, 0L, -471, 1},
                                {-0, 0xC86EFBAF48BD29F1LL, -736, 6}},
                               {{0, 1L, 478, 4},
                                {0, 0x8519C44ADFC325C0LL, 30, 11},
                                {-0, 0L, -471, 1},
                                {0, 0x42C4DEBBA0133BA3LL, -707, 0},
                                {-0, 0L, -471, 1}},
                               {{-0, 0L, -471, 1},
                                {-0, 0L, -471, 1},
                                {-0, -1L, -604, 9},
                                {0, 5L, 628, 13},
                                {0, -1L, -35, 12}},
                               {{-0, 0L, -471, 1},
                                {-0, 7L, 693, 13},
                                {0, -1L, -35, 12},
                                {0, 0xD0D1A3F0EE69D5CDLL, -352, 14},
                                {0, -3L, -677, 2}},
                               {{0, 1L, 478, 4},
                                {0, 0x7C6C453A6D93444DLL, 535, 5},
                                {-0, 0xC86EFBAF48BD29F1LL, -736, 6},
                                {-0, 0L, -902, 5},
                                {0, 0L, 262, 3}}},
                              {{{-0, -10L, 122, 9},
                                {-0, 7L, 693, 13},
                                {-0, 7L, 693, 13},
                                {-0, -10L, 122, 9},
                                {-0, 1L, 344, 2}},
                               {{-0, 0x71786727EA7006D1LL, 552, 9},
                                {-0, 0L, -471, 1},
                                {-0, 7L, 693, 13},
                                {0, -1L, -35, 12},
                                {0, 0xD0D1A3F0EE69D5CDLL, -352, 14}},
                               {{0, -1L, -35, 12},
                                {0, 0x8519C44ADFC325C0LL, 30, 11},
                                {-0, 0xC86EFBAF48BD29F1LL, -736, 6},
                                {0, 1L, 478, 4},
                                {-0, 7L, 693, 13}},
                               {{0, 0x7C6C453A6D93444DLL, 535, 5},
                                {-0, 0x71786727EA7006D1LL, 552, 9},
                                {0, -1L, -35, 12},
                                {0, -1L, -35, 12},
                                {-0, 0x71786727EA7006D1LL, 552, 9}},
                               {{0, -3L, -677, 2},
                                {0, 0x42C4DEBBA0133BA3LL, -707, 0},
                                {-0, -1L, -604, 9},
                                {-0, -10L, 122, 9},
                                {-0, 0x71786727EA7006D1LL, 552, 9}},
                               {{0, 0x8519C44ADFC325C0LL, 30, 11},
                                {0, 0L, 262, 3},
                                {-0, 0L, -471, 1},
                                {-0, 0L, -902, 5},
                                {-0, 7L, 693, 13}}}};
  int i, j, k;
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 2; j++)
      l_179[i][j] = 0x69L;
  }
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 8; k++)
        l_512[i][j][k] = 0x3331D5D9L;
    }
  }
  g_35.f0 = 0x6BBF86D3L;
  if (((safe_mul_func_int16_t_s_s(
           (safe_mul_func_uint8_t_u_u(0x11L, l_168)),
           (safe_mod_func_int64_t_s_s(
               (safe_lshift_func_uint8_t_u_u(l_168, 7)),
               ((safe_mod_func_uint16_t_u_u(
                    (safe_rshift_func_uint8_t_u_s(
                        (p_68.f2 >
                         (safe_add_func_uint64_t_u_u(
                             ((p_68.f2 != (1L && p_68.f0)) >
                              (0x4334ECE7258F3143LL &
                               (((g_35.f2 != p_68.f2) >= l_179[0][1]), l_168))),
                             g_159))),
                        0)),
                    p_68.f0)) &
                1UL))))) ||
       l_179[0][1])) {
    int32_t l_188[9] = {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L};
    int32_t l_229[5] = {1L, 1L, 1L, 1L, 1L};
    int32_t l_357 = 0x14B6D742L;
    int64_t l_358 = 0xFB503A674EA79FF9LL;
    int8_t l_372[5] = {0x87L, 0x87L, 0x87L, 0x87L, 0x87L};
    int8_t l_516 = (-8L);
    uint8_t l_518[8][10][3] = {{{0xA1L, 0x74L, 1UL},
                                {0x35L, 251UL, 255UL},
                                {254UL, 254UL, 1UL},
                                {0x80L, 255UL, 0x97L},
                                {0x6AL, 1UL, 1UL},
                                {0UL, 0x9AL, 255UL},
                                {0xA1L, 0x6AL, 1UL},
                                {0x78L, 251UL, 0x97L},
                                {254UL, 0xC6L, 1UL},
                                {1UL, 255UL, 255UL}},
                               {{0x6AL, 0xA1L, 1UL},
                                {1UL, 0x9AL, 0x97L},
                                {0xA1L, 0x74L, 1UL},
                                {0x35L, 251UL, 255UL},
                                {254UL, 254UL, 1UL},
                                {0x80L, 255UL, 0x97L},
                                {255UL, 247UL, 0xC6L},
                                {0x6EL, 0x09L, 0UL},
                                {0x8EL, 255UL, 0xC6L},
                                {0x9AL, 0xC0L, 1UL}},
                               {{246UL, 249UL, 0xC6L},
                                {248UL, 0x86L, 0UL},
                                {255UL, 0x8EL, 0xC6L},
                                {8UL, 0x09L, 1UL},
                                {0x8EL, 0x94L, 0xC6L},
                                {0UL, 0xC0L, 0UL},
                                {246UL, 246UL, 0xC6L},
                                {1UL, 0x86L, 1UL},
                                {255UL, 247UL, 0xC6L},
                                {0x6EL, 0x09L, 0UL}},
                               {{0x8EL, 255UL, 0xC6L},
                                {0x9AL, 0xC0L, 1UL},
                                {246UL, 249UL, 0xC6L},
                                {248UL, 0x86L, 0UL},
                                {255UL, 0x8EL, 0xC6L},
                                {8UL, 0x09L, 1UL},
                                {0x8EL, 0x94L, 0xC6L},
                                {0UL, 0xC0L, 0UL},
                                {246UL, 246UL, 0xC6L},
                                {1UL, 0x86L, 1UL}},
                               {{255UL, 247UL, 0xC6L},
                                {0x6EL, 0x09L, 0UL},
                                {0x8EL, 255UL, 0xC6L},
                                {0x9AL, 0xC0L, 1UL},
                                {246UL, 249UL, 0xC6L},
                                {248UL, 0x86L, 0UL},
                                {255UL, 0x8EL, 0xC6L},
                                {8UL, 0x09L, 1UL},
                                {0x8EL, 0x94L, 0xC6L},
                                {0UL, 0xC0L, 0UL}},
                               {{246UL, 246UL, 0xC6L},
                                {1UL, 0x86L, 1UL},
                                {255UL, 247UL, 0xC6L},
                                {0x6EL, 0x09L, 0UL},
                                {0x8EL, 255UL, 0xC6L},
                                {0x9AL, 0xC0L, 1UL},
                                {246UL, 249UL, 0xC6L},
                                {248UL, 0x86L, 0UL},
                                {255UL, 0x8EL, 0xC6L},
                                {8UL, 0x09L, 1UL}},
                               {{0x8EL, 0x94L, 0xC6L},
                                {0UL, 0xC0L, 0UL},
                                {246UL, 246UL, 0xC6L},
                                {1UL, 0x86L, 1UL},
                                {255UL, 247UL, 0xC6L},
                                {0x6EL, 0x09L, 0UL},
                                {0x8EL, 255UL, 0xC6L},
                                {0x9AL, 0xC0L, 1UL},
                                {246UL, 249UL, 0xC6L},
                                {248UL, 0x86L, 0UL}},
                               {{255UL, 0x8EL, 0xC6L},
                                {8UL, 0x09L, 1UL},
                                {0x8EL, 0x94L, 0xC6L},
                                {0UL, 0xC0L, 0UL},
                                {246UL, 246UL, 0xC6L},
                                {1UL, 0x86L, 1UL},
                                {255UL, 247UL, 0xC6L},
                                {0x6EL, 0x09L, 0UL},
                                {0x8EL, 255UL, 0xC6L},
                                {0x9AL, 0xC0L, 8UL}}};
    struct S0 l_521 = {0, -1L, 906, 4};
    int i, j, k;
    for (g_86 = 0; (g_86 <= 55); g_86 = safe_add_func_int64_t_s_s(g_86, 8)) {
      uint32_t l_182 = 0xBDBECFBBL;
      int32_t l_235[4] = {0xB102025CL, 0xB102025CL, 0xB102025CL, 0xB102025CL};
      uint8_t l_317 = 250UL;
      uint8_t l_384 = 0x41L;
      struct S0 l_387 = {0, 0x1B9E9F541C69828ALL, -510, 8};
      int i;
      if (((p_68.f2, l_182) !=
           (p_68.f0,
            ((safe_add_func_uint16_t_u_u(65535UL, (0xABL && 0xF2L))) ==
             ((l_185 >=
               (((((safe_sub_func_int32_t_s_s(p_67, (l_188[3] ^ 0x845BL))) ||
                   l_182) == g_2) ||
                 l_182) < l_188[3])),
              l_179[0][1]))))) {
        int8_t l_202 = 0x6EL;
        int32_t l_227 = 0x7F255F03L;
        int32_t l_267 = 1L;
        for (g_35.f1 = (-25); (g_35.f1 > (-16));
             g_35.f1 = safe_add_func_int8_t_s_s(g_35.f1, 9)) {
          uint16_t l_219 = 0x9208L;
          int32_t l_226 = 0L;
          int32_t l_231 = (-1L);
          int32_t l_232 = (-1L);
          g_85 = ((((safe_rshift_func_uint8_t_u_u(
                        (((g_131 >
                           (safe_mod_func_int8_t_s_s(
                               (safe_lshift_func_uint16_t_u_u(
                                   (safe_sub_func_int8_t_s_s((+l_182),
                                                             l_179[0][1])),
                                   ((((p_67 ^
                                       (g_35.f1,
                                        (safe_rshift_func_uint16_t_u_u(
                                            ((g_40 || (p_68.f2 &&
                                                       0x2127DE25B2766196LL)) !=
                                             (g_203 = l_202)),
                                            p_67)))) ^
                                      g_2) &&
                                     p_68.f1),
                                    g_154))),
                               p_68.f1))) >= l_185),
                         g_35.f2),
                        1)) <= 0x44ECL) |
                   l_182) |
                  p_68.f3);
          p_68.f2 =
              ((safe_mul_func_uint16_t_u_u(
                   (safe_mul_func_uint16_t_u_u(
                       ((((safe_rshift_func_int8_t_s_u(
                              0xD2L,
                              ((safe_add_func_int16_t_s_s(
                                   ((((+((((g_131 =
                                                (l_226 =
                                                     ((safe_mul_func_int8_t_s_s(
                                                          ((((((0xAE0DD45DL ==
                                                                0L) &
                                                               (safe_mul_func_uint16_t_u_u(
                                                                   p_67,
                                                                   (safe_mul_func_uint8_t_u_u(
                                                                       l_188[8],
                                                                       l_219))))) ^
                                                              (p_68.f1 =
                                                                   ((safe_add_func_uint16_t_u_u(
                                                                        l_202,
                                                                        ((l_235
                                                                              [3] ^=
                                                                          (((l_188
                                                                                 [0] <=
                                                                             (safe_lshift_func_int16_t_s_u(
                                                                                 (safe_mul_func_uint16_t_u_u(
                                                                                     (g_40--),
                                                                                     l_185)),
                                                                                 g_158))) |
                                                                            p_68.f0) >=
                                                                           5UL)) <=
                                                                         g_86))) <=
                                                                    g_35.f2))) |
                                                             p_68.f0) >=
                                                            0xFF6E787AL) ^
                                                           l_232),
                                                          l_226)) == l_182))) <=
                                           g_35.f1) &&
                                          4294967292UL) ^
                                         g_35.f3)) &
                                      0UL) > 0x2801L),
                                    p_67),
                                   g_203)),
                               l_235[1]))) != 65535UL) !=
                         0x9A4678B7D319A833LL) <= p_67),
                       0x3DE0L)),
                   g_158)) >= 0x0E952B72L);
        }
        for (g_159 = 0; (g_159 >= 53);
             g_159 = safe_add_func_uint8_t_u_u(g_159, 8)) {
          return l_235[3];
        }
                g_35.f0 = (((g_35.f2 = (safe_mul_func_uint8_t_u_u((g_35.f0 , (safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s(((0UL || ((safe_unary_minus_func_int32_t_s((((((safe_lshift_func_uint16_t_u_s(p_67, ((((!((safe_add_func_uint16_t_u_u((l_267 = ((g_251--) | (((g_131 < (((safe_lshift_func_uint8_t_u_s(2UL, (((((~4294967294UL) & 1UL) && (((((safe_mod_func_int64_t_s_s(((0x8E42A5BEL && (safe_mod_func_int16_t_s_s((l_227 |= (safe_sub_func_int32_t_s_s(((((p_68.f3 = (safe_rshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_u(g_158, 12)) == 0x70B449B74578E65ALL), 2))) || 4294967292UL) != p_67) ^ p_68.f0), g_85))), (-6L)))) > g_86), l_188[3])) , g_35.f3) > g_2) <= l_229[3]) | p_68.f1)) , g_86) || p_68.f2))) > g_2) ^ 1UL)) < 0x76L) , 0x4FC2E018L))), 0x1A80L)) && 0xC7C4E01A939D389ALL)) < 0xFAC57B76L) || 0UL) , l_168))) | g_35.f1) != 0xE917L) , p_68.f3) & g_153))) == 4294967288UL)) == p_68.f0), 4)) > l_268) , 0x442FD4E0L) > g_2), 3))), (-4L)))) < g_85) ^ g_86);
      } else {
        uint8_t l_269 = 0x17L;
        int32_t l_270[5] = {0L, 0L, 0L, 0L, 0L};
        int32_t l_299 = 0x02512B00L;
        int i;
                p_68 = ((g_35.f1 , ((((l_270[0] = (l_269 <= 0xFB450AE0L)) < (safe_lshift_func_uint8_t_u_s(((((safe_unary_minus_func_int32_t_s(((safe_mul_func_int16_t_s_s(p_68.f0, (safe_rshift_func_uint16_t_u_u(p_68.f3, 1)))) , (safe_mul_func_int16_t_s_s((~((+(safe_mod_func_uint8_t_u_u(((((safe_rshift_func_int8_t_s_u((p_68.f2 , (l_299 = (safe_rshift_func_uint8_t_u_s(((0x5AL & (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((((((safe_mod_func_int8_t_s_s((l_229[3] = (l_235[3] = (safe_mod_func_uint8_t_u_u((~(safe_rshift_func_uint8_t_u_s((p_68.f0 > g_35.f3), p_68.f3))), l_182)))), l_188[3])) & l_182) <= p_68.f2) , p_67) | 255UL) == (-4L)) , g_250), g_40)), p_67))) , p_68.f2), 1)))), g_159)) > 0x4C590CC90E365370LL) == g_251) , 7UL), p_67))) | l_182)), g_251))))) >= g_153) & 7L) >= l_182), 0))) & g_131) || l_179[0][1])) , g_35);
                if (p_67) {
                  int8_t l_315 = 0x6FL;
                  int8_t l_318 = 0x05L;
                  struct S0 l_360 = {0, 0xEA6B0394F41C5570LL, 890, 0};
                  if ((safe_rshift_func_uint8_t_u_u(
                          l_188[7],
                          ((((((((safe_add_func_int16_t_s_s(
                                     ((p_67 >=
                                       (l_229[3] =
                                            ((((safe_lshift_func_int8_t_s_s(
                                                   p_68.f2, 4)) |
                                               (g_40 = 0xFC10L)) ||
                                              (safe_sub_func_uint64_t_u_u(
                                                  ((safe_mod_func_int64_t_s_s(
                                                       ((((safe_sub_func_uint64_t_u_u(
                                                              0xE69D01ECBBADCDCBLL,
                                                              (g_131 = l_179
                                                                   [0][0]))),
                                                          (l_270[0],
                                                           (((l_299 ^=
                                                              (l_270[1] =
                                                                   (g_316 =
                                                                        ((((g_312--) !=
                                                                           g_2),
                                                                          (g_158 =
                                                                               (((l_229
                                                                                      [3],
                                                                                  p_68.f3) |
                                                                                 1L) &&
                                                                                0x9E9376ACL))) >
                                                                         l_315)))) ==
                                                             l_179[0][1]) &&
                                                            l_317))),
                                                         p_67) >= l_318),
                                                       0x1A493D74D1D46F6ALL)),
                                                   1UL),
                                                  p_68.f2))) < g_35.f0))) !=
                                      g_203),
                                     l_318)) != 0x6DB1L) <= p_68.f1) ||
                               l_270[1]),
                              g_203),
                             p_68.f3) &&
                            p_68.f2) >= l_188[8])))) {
                    uint16_t l_321 = 0xF891L;
                    int32_t l_327 = 0xAF79196BL;
                    struct S0 l_361[2][7][9] = {
                        {{{-0, 6L, -144, 14},
                          {-0, 6L, -144, 14},
                          {-0, 0xAEA7E32F0E826D90LL, -379, 9},
                          {-0, -9L, -495, 0},
                          {0, 1L, 356, 14},
                          {0, -6L, -63, 4},
                          {0, 0xE4D4F809129975E8LL, 927, 9},
                          {0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {0, 0x9BAACFC42F424CE6LL, 468, 10}},
                         {{-0, 6L, -144, 14},
                          {-0, -10L, 523, 10},
                          {0, -6L, -63, 4},
                          {0, 0L, 682, 15},
                          {-0, -10L, 523, 10},
                          {-0, 0x26E67078D9BABF24LL, 366, 6},
                          {-0, -9L, -495, 0},
                          {-0, 0x759944B1A716BBA2LL, 130, 1},
                          {0, 0x145808BEAA29AB84LL, -683, 0}},
                         {{0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {0, 0x8AB1516107DD1096LL, -414, 10},
                          {-0, 0xAEA7E32F0E826D90LL, -379, 9},
                          {0, 0L, 660, 15},
                          {-0, -10L, 523, 10},
                          {0, 7L, 410, 13},
                          {0, 0L, 660, 15},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {0, 0x7C83C6933AF73780LL, 638, 10}},
                         {{-0, -10L, 523, 10},
                          {-0, -1L, -160, 10},
                          {-0, 0x26E67078D9BABF24LL, 366, 6},
                          {-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {0, 1L, 356, 14},
                          {0, 0x7C83C6933AF73780LL, 638, 10},
                          {-0, -9L, -495, 0},
                          {-0, -9L, -495, 0},
                          {0, 0x7C83C6933AF73780LL, 638, 10}},
                         {{-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {-0, -1L, -682, 7},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {0, -10L, 156, 10},
                          {0, 0xE4D4F809129975E8LL, 927, 9},
                          {-0, 6L, -144, 14},
                          {0, 0x145808BEAA29AB84LL, -683, 0}},
                         {{0, 0xE4D4F809129975E8LL, 927, 9},
                          {-0, -1L, -160, 10},
                          {-0, 0xA24C8A71C66B8E97LL, 2, 0},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {-0, 0x759944B1A716BBA2LL, 130, 1},
                          {-0, 0xAEA7E32F0E826D90LL, -379, 9},
                          {-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {-0, -1L, -160, 10},
                          {0, 0x9BAACFC42F424CE6LL, 468, 10}},
                         {{-0, -9L, -495, 0},
                          {0, 0x8AB1516107DD1096LL, -414, 10},
                          {0, -6L, 439, 0},
                          {-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {-0, 6L, -144, 14},
                          {0, -10L, 156, 10},
                          {-0, -10L, 523, 10},
                          {-0, -1L, -160, 10},
                          {-0, 0x26E67078D9BABF24LL, 366, 6}}},
                        {{{0, 0L, 660, 15},
                          {-0, -10L, 523, 10},
                          {0, 7L, 410, 13},
                          {0, 0L, 660, 15},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {0, 0x7C83C6933AF73780LL, 638, 10},
                          {0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {-0, 6L, -144, 14},
                          {0, -6L, 439, 0}},
                         {{-0, -9L, -495, 0},
                          {-0, 6L, -144, 14},
                          {0, 7L, 410, 13},
                          {0, 0L, 682, 15},
                          {0, 0L, 682, 15},
                          {0, 7L, 410, 13},
                          {-0, 6L, -144, 14},
                          {-0, -9L, -495, 0},
                          {-0, -1L, -682, 7}},
                         {{0, 0xE4D4F809129975E8LL, 927, 9},
                          {0, 0L, 682, 15},
                          {0, -6L, 439, 0},
                          {-0, -9L, -495, 0},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {-0, 0x26E67078D9BABF24LL, 366, 6},
                          {-0, 6L, -144, 14},
                          {-0, 0x199CFDA8591A7F80LL, -839, 2},
                          {0, 0xC98676DEBBE85BA4LL, 699, 7}},
                         {{-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {0, 0xE4D4F809129975E8LL, 927, 9},
                          {-0, 0xA24C8A71C66B8E97LL, 2, 0},
                          {0, 0x8AB1516107DD1096LL, -414, 10},
                          {-0, 6L, -144, 14},
                          {0, -6L, -63, 4},
                          {0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {-0, 0x759944B1A716BBA2LL, 130, 1},
                          {-0, -1L, -682, 7}},
                         {{-0, -10L, 523, 10},
                          {0, 0xE4D4F809129975E8LL, 927, 9},
                          {-0, -1L, -682, 7},
                          {-0, 6L, -144, 14},
                          {-0, 0x759944B1A716BBA2LL, 130, 1},
                          {0, 0x9BAACFC42F424CE6LL, 468, 10},
                          {-0, -10L, 523, 10},
                          {0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {0, -6L, 439, 0}},
                         {{0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {0, 0L, 682, 15},
                          {-0, 0x26E67078D9BABF24LL, 366, 6},
                          {0, 0x8AB1516107DD1096LL, -414, 10},
                          {-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {0, 0x9BAACFC42F424CE6LL, 468, 10},
                          {-0, 0xF8E918BFD0892C7ELL, -15, 10},
                          {0, 0x8AB1516107DD1096LL, -414, 10},
                          {-0, 0x26E67078D9BABF24LL, 366, 6}},
                         {{-0, 6L, -144, 14},
                          {-0, 6L, -144, 14},
                          {-0, 0xAEA7E32F0E826D90LL, -379, 9},
                          {-0, -9L, -495, 0},
                          {0, 1L, 356, 14},
                          {0, -6L, -63, 4},
                          {0, 0xE4D4F809129975E8LL, 927, 9},
                          {0, 0x1E14933FC6AC2D5DLL, -119, 15},
                          {0, 0x9BAACFC42F424CE6LL, 468, 10}}}};
                    int i, j, k;
                    l_321 = (safe_sub_func_uint8_t_u_u(0xCAL, l_270[0]));
                    l_327 = (l_188[3] ==
                             (safe_mod_func_int32_t_s_s(
                                 (safe_rshift_func_uint8_t_u_s(g_203, 0)),
                                 (g_35.f1, (0x16B3L | (+p_68.f1))))));
                        l_361[1][3][1] = ((safe_lshift_func_int8_t_s_u((((((!(((safe_mod_func_uint64_t_u_u(((((l_229[3] = ((((((((l_230 = (l_358 = ((((g_356 = (+((g_355 = (safe_mod_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u(((((p_68.f1 != 9UL) <= 0xA9678BC31AB23EFCLL) , ((safe_mul_func_uint16_t_u_u((g_40--), ((l_179[0][1] || (((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s((safe_mul_func_int8_t_s_s((((!0xC3L) != l_315) , ((safe_add_func_uint16_t_u_u((0x026327A7D234CDECLL ^ (safe_add_func_int64_t_s_s((safe_sub_func_int64_t_s_s(g_316, ((p_68.f1 & g_2) | l_299))), l_321))), 0xD8B3L)) > 255UL)), 1UL)), g_154)), l_318)) < 65530UL) >= g_35.f3)) > p_68.f1))) & g_2)) ^ p_67), 0x01DBL)), 4294967291UL))) & l_270[4]))) && l_357) , l_318) & g_35.f1))) | 0UL) , g_356) & p_68.f0) <= l_359) , g_159) != l_235[3]) > l_235[3])) != 1L) != l_235[2]) || 0L), g_158)) <= 0x8BL) ^ l_188[7])) || l_270[2]) , g_131) , l_318) || g_35.f0), l_318)) , l_360);
                        if (g_316)
                          continue;
                  } else {
                    return p_68.f0;
                  }
                  p_68 = g_35;
                  for (g_355 = 0; (g_355 < 7);
                       g_355 = safe_add_func_uint8_t_u_u(g_355, 1)) {
                    g_85 = (safe_sub_func_int16_t_s_s(0x7650L, l_299));
                  }
                  if ((safe_mul_func_int16_t_s_s(
                          p_68.f3,
                          (g_40 =
                               ((safe_sub_func_int8_t_s_s(
                                    (l_270[0] || (safe_mul_func_int8_t_s_s(
                                                     g_154, g_35.f3))),
                                    l_372[1])) &
                                (safe_lshift_func_int8_t_s_s(
                                    p_68.f0,
                                    (safe_unary_minus_func_uint64_t_u(
                                        (((((safe_lshift_func_int16_t_s_u(
                                                ((safe_lshift_func_int8_t_s_s(
                                                     (l_372[1] & p_68.f2), 7)) ^
                                                 18446744073709551614UL),
                                                l_360.f2)) ||
                                            p_68.f2) ||
                                           0UL) < g_35.f1) < g_159)))))))))) {
                    int32_t l_380 = 9L;
                    uint32_t l_381 = 4294967295UL;
                    int64_t l_389 = 0x15BF4AFC80BC00F2LL;
                    --l_381;
                    l_384--;
                    g_388 = (l_387 = p_68);
                    g_391--;
                  } else 
				  {
                    g_35.f0 ^=
                        (g_35.f2 = ((g_250 > (p_68.f3, l_228)),
                                    ((safe_rshift_func_uint8_t_u_u((6UL != g_158), p_68.f1)) <((safe_sub_func_uint16_t_u_u(((safe_mul_func_uint8_t_u_u(                                               l_230, (g_391 |= (g_312++)))) !=g_35.f2),((g_35.f1 || 0xCB7D202A44838C9CLL) <=p_68.f3))),g_356))));
                  }
                } else {
                  int8_t l_425 = 0xE2L;
                  int32_t l_435[3][10][8] = {
                      {{0L, 0x5EF18C21L, 0xB254E173L, 0x264A9727L, 0x5EF18C21L,
                        7L, 1L, 0x8EA2810DL},
                       {0x13B8FAD0L, 0x264A9727L, (-5L), 0L, 0x4FB39624L,
                        0x14F4EB47L, 0xF9C379EFL, 0L},
                       {0x4FB39624L, 0x14F4EB47L, 0xF9C379EFL, 0L, (-5L),
                        0x71BC52FFL, 0x2FF14C85L, 0x551FC918L},
                       {1L, 0L, (-9L), 0x264A9727L, 0x264A9727L, (-9L), 0L, 1L},
                       {0x1B88068CL, 0L, 0xA7A597BEL, 0xF9C379EFL, 0L,
                        0x86E6DCB5L, (-7L), 0L},
                       {0x4FB39624L, 0x6B57A694L, 0x551FC918L, 0x29CF1B3CL,
                        0xF9C379EFL, 0x86E6DCB5L, 0x99DB32BBL, (-5L)},
                       {0x2FF14C85L, 0L, 0L, (-1L), 0x5EF18C21L, (-9L), (-5L),
                        0x14F4EB47L},
                       {0L, 0x6B57A694L, 0xDB8DE8F2L, 0xC451F9FFL, 0x551FC918L,
                        (-9L), 4L, 0xF9C379EFL},
                       {1L, 4L, 0xB0738AC5L, 0x6B57A694L, 0xB0738AC5L, 4L, 1L,
                        0x8EBA344DL},
                       {0x1B88068CL, (-7L), 0x8EA2810DL, 0L, 0x14F4EB47L,
                        0x29CF1B3CL, 0x6B57A694L, 0x14F4EB47L}},
                      {{7L, 1L, 0x17578884L, 7L, 0x14F4EB47L, 0L, 0x8EBA344DL,
                        0x6B57A694L},
                       {0x1B88068CL, 0xC62BDA8AL, 0xB254E173L, 0x14F4EB47L,
                        0xB0738AC5L, 0xDB8DE8F2L, 0x71BC52FFL, 0xC62BDA8AL},
                       {1L, 0xA7A597BEL, 0x29CF1B3CL, 0x71BC52FFL, 0x551FC918L,
                        0L, 0L, 0L},
                       {0L, 1L, (-9L), (-9L), 1L, 0L, 0xC451F9FFL, 0x13B8FAD0L},
                       {0xF9C379EFL, (-9L), 0L, 0x86E6DCB5L, 0xB254E173L, 4L,
                        0x71BC52FFL, 0L},
                       {0x71BC52FFL, 0x1B88068CL, 0x264A9727L, 0x86E6DCB5L,
                        0x6B57A694L, 0x5EF18C21L, 0xF9C379EFL, 0x13B8FAD0L},
                       {0xC451F9FFL, 0x6B57A694L, 0x17578884L, (-9L), (-7L),
                        0x17578884L, 0L, 0L},
                       {0L, 0L, 0x54F77BF7L, 0x71BC52FFL, 0L, 0xC62BDA8AL, 1L,
                        0xC62BDA8AL},
                       {0x71BC52FFL, 0x14F4EB47L, 0x2FF14C85L, 0x14F4EB47L,
                        0x71BC52FFL, 0x131CA756L, 0x1B88068CL, 0x6B57A694L},
                       {0x8EBA344DL, 0x86E6DCB5L, 0xDB8DE8F2L, 7L, 1L,
                        0x17578884L, 7L, 0x14F4EB47L}},
                      {{0x6B57A694L, 0L, 0xDB8DE8F2L, 0L, 0x54F77BF7L, (-9L),
                        0x1B88068CL, 0x8EBA344DL},
                       {1L, 0x1B88068CL, 0x2FF14C85L, 0x6B57A694L, 0x13B8FAD0L,
                        1L, 1L, 0xF9C379EFL},
                       {4L, (-7L), 0x54F77BF7L, 0xC451F9FFL, 0x14F4EB47L, 0L,
                        0L, 0x14F4EB47L},
                       {(-5L), 0x17578884L, 0x17578884L, (-5L), 0xDB8DE8F2L, 0L,
                        0xF9C379EFL, 0L},
                       {0x1B88068CL, 0xA7A597BEL, 0x264A9727L, 0x14F4EB47L,
                        0x13B8FAD0L, 0x99DB32BBL, 0x71BC52FFL, 0xA7A597BEL},
                       {0x17578884L, 0xA7A597BEL, 0L, 0xB254E173L, 0x551FC918L,
                        0L, 0xC451F9FFL, 0L},
                       {0x6B57A694L, 0x17578884L, (-9L), (-7L), 0x17578884L, 0L,
                        0L, 0xB0738AC5L},
                       {0xF9C379EFL, (-7L), 0x29CF1B3CL, 0x86E6DCB5L,
                        0x71BC52FFL, 1L, 0x71BC52FFL, 0x86E6DCB5L},
                       {0xB254E173L, 0x1B88068CL, 0xB254E173L, 0L, 0x6B57A694L,
                        (-9L), 0x8EBA344DL, 0x13B8FAD0L},
                       {0L, 0L, 0x17578884L, (-7L), (-9L), 0x17578884L,
                        0x6B57A694L, 0xC451F9FFL}}};
                  int i, j, k;
                  l_230 = (safe_lshift_func_int8_t_s_s(
                      (l_235[3] =
                           ((safe_mod_func_uint64_t_u_u(
                                (~(((((safe_sub_func_uint16_t_u_u(
                                          (p_68.f1 <
                                           (g_421[3][7][1] =
                                                (0x69L >=
                                                 (safe_add_func_uint8_t_u_u(
                                                     ((l_387.f1, g_35.f2) <=
                                                      (g_250 = (safe_add_func_uint16_t_u_u(
                                                           ((+(safe_rshift_func_int8_t_s_u(
                                                                (safe_lshift_func_uint16_t_u_u(
                                                                    (g_40 |=
                                                                     p_68.f1),
                                                                    4)),
                                                                l_229[0]))) !=
                                                            (((p_67--) ==
                                                              ((l_188[3],
                                                                (p_68.f2 >
                                                                 (g_35.f0 <
                                                                  p_68.f2))) ||
                                                               0xE1L)) ==
                                                             g_388.f0)),
                                                           g_355)))),
                                                     g_420[2][1]))))),
                                          g_388.f1)) != p_68.f0) > p_68.f2) &&
                                    0x62496134L) >= 0x7AEE73A9112BF304LL)),
                                0xEFBCFB0B8F56AA0BLL)) ||
                            0L)),
                      4));
                  l_435[0][5][1] |= (safe_sub_func_int32_t_s_s(
                      p_67,
                      ((~(-10L)) <=
                       (((l_425,
                          (l_359,
                           (safe_unary_minus_func_uint32_t_u(
                               (safe_add_func_int64_t_s_s(
                                   (safe_rshift_func_int16_t_s_u(
                                       p_68.f1,
                                       (safe_add_func_uint16_t_u_u(
                                           ((((((((g_356 ||
                                                   (safe_add_func_int16_t_s_s(
                                                       (l_235[3] = 0L),
                                                       (l_228 ||
                                                        ((l_357 > g_35.f0) >
                                                         l_168))))) ^
                                                  0x633208D911FE580DLL) <=
                                                 0xB6DF4DFEL),
                                                l_387.f0) != l_182),
                                              0xECABF22FL) &
                                             l_384) != p_68.f2),
                                           l_425)))),
                                   l_182)))))) &
                         g_35.f3) ^
                        g_355))));
                }
                l_473 &= ((safe_add_func_int32_t_s_s(((safe_unary_minus_func_uint32_t_u((~p_68.f3))) , 0xDB572780L), (+((safe_mod_func_uint64_t_u_u(0x6ED8BB31A6A542F5LL, (safe_add_func_int64_t_s_s((((safe_rshift_func_int8_t_s_u(p_68.f1, (safe_mul_func_uint8_t_u_u(g_251, (g_312 |= (safe_add_func_int64_t_s_s((l_188[3] || (l_228 = (safe_rshift_func_int16_t_s_u((((safe_mod_func_uint16_t_u_u((((l_235[3] = ((p_68.f1 == ((safe_sub_func_uint8_t_u_u((l_230 = (safe_mod_func_uint8_t_u_u(((((safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_u(((((safe_mul_func_uint16_t_u_u((++g_420[2][6]), ((safe_sub_func_uint8_t_u_u(9UL, (safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((p_68.f2 <= 0x35C9L), l_230)), g_40)))) , p_68.f0))) < 65535UL) <= g_391) & (-1L)), 8)), 255UL)) & p_68.f2) & p_68.f3) != p_68.f3), p_68.f0))), g_251)) && 0x714D87E6DFCEBFE9LL)) < g_250)) , p_68.f1) | 0xACL), 0x8E1BL)) != l_182) <= l_299), 1)))), 18446744073709551615UL))))))) != p_68.f0) >= p_68.f1), 0x3CA4B45ED650913CLL)))) & 1L)))) , p_68.f1);
                if (l_188[3])
                  break;
      }
    }
    for (g_355 = 0; (g_355 <= 4); g_355 += 1) {
      int16_t l_485[5];
      uint32_t l_486[5];
      int32_t l_511[5][6] = {{0L, 0L, (-9L), 0L, 0L, 0L},
                             {(-1L), (-1L), 0L, (-1L), (-1L), 0L},
                             {(-1L), (-1L), 0L, (-1L), (-1L), 0L},
                             {(-1L), (-1L), 0L, (-1L), (-1L), 0L},
                             {(-1L), (-1L), 0L, (-1L), (-1L), 0L}};
      int32_t l_517 = 0xE1BFC9C5L;
      struct S0 l_522 = {0, 0x5115A926D551A3DDLL, 758, 1};
      int i, j;
      for (i = 0; i < 5; i++)
        l_485[i] = (-1L);
      for (i = 0; i < 5; i++)
        l_486[i] = 18446744073709551615UL;
      for (l_168 = 0; (l_168 <= 4); l_168 += 1) {
        struct S0 l_487[5] = {{0, 0x805E1196B93EB39BLL, 334, 8},
                              {0, 0x805E1196B93EB39BLL, 334, 8},
                              {0, 0x805E1196B93EB39BLL, 334, 8},
                              {0, 0x805E1196B93EB39BLL, 334, 8},
                              {0, 0x805E1196B93EB39BLL, 334, 8}};
        int32_t l_507 = 0x1EBFE72AL;
        int8_t l_508 = 7L;
        int32_t l_513 = 4L;
        int32_t l_514 = 0L;
        int32_t l_515[1][8][4] = {
            {{0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L},
             {0x0DB85107L, 0x0DB85107L, 0x0DB85107L, 0x0DB85107L}}};
        int i, j, k;
        if (l_188[(g_355 + 2)]) {
          int i;
          l_229[l_168] = (-5L);
          p_68 = g_35;
          g_388.f2 = 0x58FA0369L;
        } else {
          uint16_t l_493 = 0x1A88L;
          int32_t l_509 = (-8L);
          g_356 =
              ((p_68.f3 ^ p_68.f1) ==
               (((0x32CC20C2L <
                  (0x06A549CCL |
                   (p_68.f1 &&
                    (l_486[1] =
                         (~((safe_rshift_func_int16_t_s_u(
                                (g_388.f0 ==
                                 ((safe_rshift_func_int16_t_s_s(
                                      ((safe_rshift_func_int16_t_s_u(
                                           (((((((safe_lshift_func_uint16_t_u_s(
                                                     65535UL, 9)) |
                                                 0UL) ||
                                                ((safe_mul_func_int8_t_s_s(
                                                     8L, l_485[2])) < (-1L))) ==
                                               2UL) == p_67) < (-1L)) ^
                                            p_68.f1),
                                           11)) <= g_312),
                                      15)) != g_35.f0)),
                                p_68.f1)) ||
                            l_188[(g_355 + 2)])))))) |
                 g_316) == g_35.f2));
          p_68 = l_487[3];
          for (g_251 = 1; (g_251 <= 8); g_251 += 1) {
            int i;
            if (g_85)
              break;
            l_509 |= (safe_mod_func_int16_t_s_s(
                (safe_unary_minus_func_int32_t_s((
                    ((safe_sub_func_uint32_t_u_u(
                         (l_493++),
                         (g_388.f2,
                          (l_508 =
                               (l_507 =
                                    ((((safe_lshift_func_uint16_t_u_u(
                                           (p_68.f0 <
                                            (safe_rshift_func_int16_t_s_s(
                                                (((g_388 = (l_487[l_168] =
                                                                l_487[g_355])),
                                                  (safe_mod_func_uint8_t_u_u(
                                                      ((((safe_unary_minus_func_int8_t_s(
                                                             (0L <
                                                              (safe_add_func_int16_t_s_s(
                                                                  g_35.f3,
                                                                  0x16ABL))))),
                                                         ((safe_unary_minus_func_int16_t_s(
                                                              (g_506 <=
                                                               (g_388.f1 <
                                                                g_420[1][5])))),
                                                          5L)) ||
                                                        p_68.f0) &&
                                                       g_85),
                                                      p_67))),
                                                 l_487[3].f1),
                                                l_486[1]))),
                                           g_356)) &&
                                       g_356) ^
                                      0L) >= 5UL)))))) == g_2) &&
                    l_188[(g_355 + 2)]))),
                g_131));
          }
        }
        l_518[3][6][1]--;
        g_35.f0 = ((g_250 = 0xDBE0L) ^ 0x7975L);
      }
      p_68.f2 &= l_179[0][1];
      l_522 = (l_521 = p_68);
    }
  } else {
    int64_t l_531[9][2][2] = {
        {{1L, 1L}, {0L, 1L}},
        {{1L, 0x3D2872760EF3DE38LL}, {0x3D2872760EF3DE38LL, 1L}},
        {{1L, 0L}, {1L, 1L}},
        {{0x3D2872760EF3DE38LL, 0x3D2872760EF3DE38LL}, {1L, 1L}},
        {{0L, 1L}, {1L, 0x3D2872760EF3DE38LL}},
        {{0x3D2872760EF3DE38LL, 1L}, {1L, 0L}},
        {{1L, 1L}, {0x3D2872760EF3DE38LL, 0x3D2872760EF3DE38LL}},
        {{1L, 1L}, {0L, 1L}},
        {{1L, 0x3D2872760EF3DE38LL}, {0x3D2872760EF3DE38LL, 1L}}};
    struct S0 l_558 = {0, 0x6EBB5A25F942B6EFLL, 985, 9};
    int i, j, k;
    p_68.f2 = (safe_sub_func_int64_t_s_s(
        0xBE8001C539FE3DD5LL,
        (((0xE339L < 65535UL) < ((g_35.f1 == l_228) < 254UL)) ^
         (g_312 = (safe_sub_func_int16_t_s_s(
              g_153, (((safe_lshift_func_uint16_t_u_u(p_68.f2, 1)) ||
                       (l_531[6][0][1] < p_67)) >= l_185)))))));
    g_388.f0 &=
        ((((safe_rshift_func_int16_t_s_s((-1L), 1)) | (-8L)),
          ((((safe_sub_func_int32_t_s_s(
                 (safe_add_func_uint16_t_u_u(
                     ((safe_rshift_func_uint8_t_u_u(
                          (safe_mul_func_uint8_t_u_u(
                              (safe_lshift_func_int8_t_s_s(l_544, 6)),
                              ((safe_add_func_int32_t_s_s(
                                   ((safe_mul_func_int16_t_s_s(
                                        (l_531[6][0][1],
                                         ((safe_mod_func_int32_t_s_s(
                                              l_551, p_68.f0)) ||
                                          ((p_68.f0 ||
                                            ((g_506 <
                                              ((safe_sub_func_int16_t_s_s(
                                                   (((((l_230 ^=
                                                        ((0x5914L & g_131) >=
                                                         l_268)),
                                                       l_531[6][0][1]) ||
                                                      g_388.f1) >=
                                                     l_531[2][1][0]) >
                                                    l_512[0][0][3]),
                                                   l_531[1][1][0])),
                                               l_228)),
                                             0UL)) ^
                                           g_35.f2))),
                                        1UL)) |
                                    0x4D534FA00A9F9CE9LL),
                                   g_421[3][7][1])),
                               g_35.f3))),
                          1)) != l_531[6][0][1]),
                     l_473)),
                 g_391)) >= g_388.f1) &
            l_531[6][0][1]) ^
           9L)) ||
         0x9371B1DCFD8ECBECLL);
    g_85 = ((safe_mod_func_uint16_t_u_u(
                (safe_mul_func_int8_t_s_s(
                    (((g_420[3][9] = (l_558, l_512[0][0][6])) != g_35.f3) !=
                     ((255UL <=
                       ((g_559[6] >
                         (65532UL |
                          (((((g_388.f2 <=
                               (((l_512[0][1][0] >= l_228) || l_560) || 6L)) ||
                              1L) &
                             6UL) ^
                            l_512[0][0][6]) < g_158))) < l_558.f0)) ||
                      0UL)),
                    0x16L)),
                0xAE48L)) > 0x8EF22322D9C916FFLL);
    g_388 = ((0xB90FL ||
              ((safe_mul_func_int16_t_s_s(
                   ((p_68.f2 = g_251) &&
                    (p_67,
                     (safe_mul_func_uint8_t_u_u(
                         (l_558.f2 = (safe_unary_minus_func_int16_t_s(1L))),
                         (+(p_68.f3 & ((0xB87AL ^ (p_68.f0 ^ l_512[0][1][0])) !=
                                       l_551))))))),
                   0xB7ACL)) &&
               p_68.f2)),
             l_567[1][3][4]);
  }
  return p_67;
}

static int32_t func_71(uint8_t p_72, uint32_t p_73, uint32_t p_74) {
  int32_t l_145 = 1L;
  int32_t l_148[4];
  int32_t l_151[6] = {(-1L), 0x6C71F3ECL, 0x6C71F3ECL,
                      (-1L), 0x6C71F3ECL, 0x6C71F3ECL};
  int32_t l_152 = 0xF6C6AD03L;
  int32_t l_155 = 3L;
  int8_t l_162 = 0x2DL;
  int i;
  for (i = 0; i < 4; i++)
    l_148[i] = 0xE73AB669L;
  l_155 |=
      (g_85 = (safe_mul_func_int8_t_s_s(
           (safe_lshift_func_int8_t_s_s(
               (g_154 =
                    ((g_153 =
                          (((safe_sub_func_uint32_t_u_u(p_74, 0x0C8DCDBDL)) !=
                            (safe_add_func_int64_t_s_s(
                                (g_35.f3,
                                 (safe_lshift_func_uint8_t_u_u(
                                     l_145,
                                     ((l_152 =
                                           ((g_131, l_145),
                                            (l_151[5] = (safe_add_func_int8_t_s_s(
                                                 (l_148[1] = 0L),
                                                 ((p_73 &
                                                   (safe_sub_func_uint32_t_u_u(
                                                       0xA808B72AL,
                                                       0x6805FA10L))) >
                                                  3L)))))) ^
                                      p_73)))),
                                8UL))),
                           0xC672L)) > g_35.f2)),
               l_145)),
           0x5DL)));
  for (g_153 = 27; (g_153 == 21); g_153 = safe_sub_func_int64_t_s_s(g_153, 1)) {
    l_152 = p_73;
    return g_131;
  }
  ++g_159;
  l_162 &= (g_35.f0 ^= (l_152 = (g_35.f2 = p_74)));
  return g_85;
}

static uint8_t func_78(uint32_t p_79) {
  int8_t l_93 = 0xFCL;
  uint32_t l_94 = 0xE62B9925L;
  uint8_t l_95 = 1UL;
  int32_t l_96 = 0x683588D2L;
  int32_t l_105 = 0x05D52AEBL;
  int64_t l_124[9] = {
      0x184C74488338C196LL, 0x184C74488338C196LL, 0x184C74488338C196LL,
      0x184C74488338C196LL, 0x184C74488338C196LL, 0x184C74488338C196LL,
      0x184C74488338C196LL, 0x184C74488338C196LL, 0x184C74488338C196LL};
  int i;
  for (p_79 = (-16); (p_79 <= 10); p_79 = safe_add_func_uint16_t_u_u(p_79, 2)) {
    return p_79;
  }
  l_95 =
      (g_2 <= (p_79 ^ (((~((+((l_93 || g_86), g_40)) > 0xD429592AE175A398LL)) >=
                        (0xFA44L >= ((0x762B6CB16C6279EALL > l_94) == g_85))) <
                       g_35.f1)));
  if ((g_35,
       (((l_94 |
          (((l_96 &= 255UL) |
            ((safe_mod_func_uint16_t_u_u(
                 (safe_add_func_int8_t_s_s(
                     p_79,
                     (((p_79 !=
                        (((g_40 |
                           ((((safe_add_func_int16_t_s_s(
                                  (safe_rshift_func_int8_t_s_u(
                                      (l_105 = g_85),
                                      (safe_rshift_func_uint16_t_u_u(
                                          (safe_sub_func_int32_t_s_s(
                                              g_35.f2, (p_79 && 0x8C76L))),
                                          l_94)))),
                                  4UL)),
                              p_79) &&
                             p_79) ^
                            l_94)),
                          7UL) <= g_35.f0)),
                       p_79) != p_79))),
                 g_2)) != g_85)) |
           p_79)) >= p_79) |
        0x4C26E522L))) {
    g_35.f2 = (65535UL ^ (safe_lshift_func_uint16_t_u_s(g_35.f3, 14)));
  } else {
    uint8_t l_130[8] = {0x26L, 7UL, 0x26L, 7UL, 0x26L, 7UL, 0x26L, 7UL};
    int i;
    g_35.f2 |=
        ((g_131 &=
          (l_130[4] =
               ((l_105 = (safe_unary_minus_func_uint8_t_u((
                     l_96 ^= (safe_sub_func_int64_t_s_s(
                         g_40,
                         (safe_mul_func_uint16_t_u_u(
                             (((safe_mul_func_uint16_t_u_u(
                                   ((18446744073709551612UL || p_79) >=
                                    (safe_lshift_func_int16_t_s_s(
                                        (safe_sub_func_int32_t_s_s(
                                            p_79,
                                            (+(l_124[2] ^
                                               (g_2 |
                                                (((+0x378BL) < 0xDF2DL) &
                                                 ((safe_mod_func_int32_t_s_s(
                                                      (((safe_sub_func_int8_t_s_s(
                                                            (p_79 == (-1L)),
                                                            p_79)) != 1L) ||
                                                       l_124[2]),
                                                      p_79)) >= 3L))))))),
                                        8))),
                                   g_40)) >= l_94) ^
                              p_79),
                             g_85)))))))) >= g_35.f1))),
         l_93);
  }
  if ((safe_unary_minus_func_uint16_t_u(((l_105 = l_94), p_79)))) {
    return p_79;
  } else {
    l_96 = 0xA4836ABEL;  }

  return g_40;
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  platform_main_begin();
  crc32_gentab();
  func_1();
  transparent_crc(g_2, "g_2", print_hash_value);
  transparent_crc(g_35.f0, "g_35.f0", print_hash_value);
  transparent_crc(g_35.f1, "g_35.f1", print_hash_value);
  transparent_crc(g_35.f2, "g_35.f2", print_hash_value);
  transparent_crc(g_35.f3, "g_35.f3", print_hash_value);
  transparent_crc(g_40, "g_40", print_hash_value);
  transparent_crc(g_85, "g_85", print_hash_value);
  transparent_crc(g_86, "g_86", print_hash_value);
  transparent_crc(g_131, "g_131", print_hash_value);
  transparent_crc(g_153, "g_153", print_hash_value);
  transparent_crc(g_154, "g_154", print_hash_value);
  transparent_crc(g_158, "g_158", print_hash_value);
  transparent_crc(g_159, "g_159", print_hash_value);
  transparent_crc(g_203, "g_203", print_hash_value);
  transparent_crc(g_250, "g_250", print_hash_value);
  transparent_crc(g_251, "g_251", print_hash_value);
  transparent_crc(g_312, "g_312", print_hash_value);
  transparent_crc(g_316, "g_316", print_hash_value);
  transparent_crc(g_355, "g_355", print_hash_value);
  transparent_crc(g_356, "g_356", print_hash_value);
  transparent_crc(g_388.f0, "g_388.f0", print_hash_value);
  transparent_crc(g_388.f1, "g_388.f1", print_hash_value);
  transparent_crc(g_388.f2, "g_388.f2", print_hash_value);
  transparent_crc(g_388.f3, "g_388.f3", print_hash_value);
  transparent_crc(g_390, "g_390", print_hash_value);
  transparent_crc(g_391, "g_391", print_hash_value);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 10; j++) {
      transparent_crc(g_420[i][j], "g_420[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 10; j++) {
      for (k = 0; k < 5; k++) {
        transparent_crc(g_421[i][j][k], "g_421[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_506, "g_506", print_hash_value);
  for (i = 0; i < 8; i++) {
    transparent_crc(g_559[i], "g_559[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_594, "g_594", print_hash_value);
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 6; j++) {
      for (k = 0; k < 1; k++) {
        transparent_crc(g_750[i][j][k], "g_750[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 10; j++) {
      transparent_crc(g_754[i][j], "g_754[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  for (i = 0; i < 8; i++) {
    transparent_crc(g_755[i], "g_755[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 5; i++) {
    transparent_crc(g_1021[i], "g_1021[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_1031, "g_1031", print_hash_value);
  for (i = 0; i < 9; i++) {
    transparent_crc(g_1032[i], "g_1032[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_1103, "g_1103", print_hash_value);
  transparent_crc(g_1109, "g_1109", print_hash_value);
  for (i = 0; i < 8; i++) {
    transparent_crc(g_1145[i].f0, "g_1145[i].f0", print_hash_value);
    transparent_crc(g_1145[i].f1, "g_1145[i].f1", print_hash_value);
    transparent_crc(g_1145[i].f2, "g_1145[i].f2", print_hash_value);
    transparent_crc(g_1145[i].f3, "g_1145[i].f3", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_1238, "g_1238", print_hash_value);
  transparent_crc(g_1241, "g_1241", print_hash_value);
  transparent_crc(g_1304, "g_1304", print_hash_value);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 7; j++) {
      transparent_crc(g_1732[i][j], "g_1732[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 1; j++) {
      for (k = 0; k < 10; k++) {
        transparent_crc(g_1756[i][j][k], "g_1756[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_1935, "g_1935", print_hash_value);
  transparent_crc(g_1985, "g_1985", print_hash_value);
  transparent_crc(g_2138, "g_2138", print_hash_value);
  transparent_crc(g_2239, "g_2239", print_hash_value);
  transparent_crc(g_2299, "g_2299", print_hash_value);
  transparent_crc(g_2300, "g_2300", print_hash_value);
  transparent_crc(g_2342, "g_2342", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}
