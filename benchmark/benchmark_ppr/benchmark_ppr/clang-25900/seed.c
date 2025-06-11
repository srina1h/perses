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
  uint16_t f0;
};

struct S1 {
  unsigned f0 : 29;
  unsigned f1 : 26;
  signed f2 : 10;
  unsigned f3 : 27;
  signed f4 : 18;
  signed f5 : 1;
  unsigned f6 : 26;
};

static int8_t g_12 = 0xBCL;
static int32_t g_13 = 0x5FEC46BCL;
static struct S0 g_21 = {0xC0B8L};
static int32_t g_30 = (-1L);
static int64_t g_32 = (-1L);
static uint8_t g_33 = 9UL;
static int64_t g_36 = 0xE281B1D0B827BE62LL;
static int32_t g_37 = 0x2EF61160L;
static int32_t g_38 = 6L;
static uint64_t g_39 = 0UL;
static int32_t g_65 = 1L;
static int8_t g_66 = (-5L);
static int8_t g_67 = (-4L);
static uint8_t g_69 = 0x3DL;
static uint32_t g_80 = 7UL;
static uint32_t g_182 = 18446744073709551609UL;
static int32_t g_183 = 0L;
static int16_t g_184 = 0L;
static uint8_t g_188 = 252UL;
static uint8_t g_191 = 1UL;
static struct S0 g_199 = {0x133DL};
static struct S1 g_238 = {8110, 1413, 13, 11418, 196, -0, 504};
static int8_t g_240 = 0L;
static uint32_t g_241 = 18446744073709551615UL;
static uint32_t g_301 = 0x7F6F722BL;
static uint16_t g_315 = 0x89BEL;
static uint8_t g_322 = 0x36L;
static int32_t g_377 = 0x76F0FC06L;
static uint32_t g_378 = 0x122AFA7AL;
static int8_t g_524 = 0x0FL;
static int64_t g_527 = (-7L);
static uint32_t g_528 = 18446744073709551615UL;
static int32_t g_571 = 0x7B01DCB5L;
static int8_t g_586 = 0xB5L;
static uint16_t g_620 = 0xCC35L;
static int32_t g_756 = 0x66BD1D4CL;
static int32_t g_791 = (-9L);
static int32_t g_792 = 0x3C3CEAB1L;
static uint16_t g_793 = 0UL;
static int32_t g_800 = 0xF1E12B68L;
static uint8_t g_801 = 251UL;
static uint32_t g_873 = 18446744073709551615UL;
static uint16_t g_928 = 1UL;
static int32_t g_967 = 0x80995892L;
static uint32_t g_968 = 0xFF7B2476L;
static int16_t g_993 = 0x54F0L;
static uint32_t g_1249 = 4294967295UL;
static uint8_t g_1276 = 0UL;
static uint16_t g_1285 = 65535UL;

static int64_t func_1(void);
static uint8_t func_5(uint8_t p_6);
static int8_t func_14(int8_t p_15, struct S1 p_16, struct S0 p_17,
                      struct S0 p_18, int32_t p_19);
static int16_t func_44(uint32_t p_45);
static int64_t func_56(struct S1 p_57, struct S0 p_58);
static uint8_t func_61(uint8_t p_62, uint32_t p_63, int64_t p_64);
static int8_t func_74(struct S0 p_75);
static uint8_t func_85(int16_t p_86, int8_t p_87, uint8_t p_88);
static uint8_t func_94(int16_t p_95, struct S0 p_96, int16_t p_97);
static int64_t func_101(int32_t p_102, uint16_t p_103);
static int64_t func_1(void) {
  struct S1 l_2 = {5257, 2494, 15, 7269, 192, 0, 6867};
  struct S1 l_20 = {8399, 1580, 12, 4707, 209, 0, 910};
  struct S1 l_1295 = {8978, 2774, 11, 1659, 145, 0, 2412};
  l_2.f2 =
      ((l_2,
        (((((((-8L) &&
              (safe_rshift_func_uint8_t_u_u(
                  func_5((
                      (l_1295 =
                           (l_20 =
                                ((safe_div_func_uint8_t_u_u(
                                     ((safe_lshift_func_uint16_t_u_u(
                                          ((!(g_12 || (l_2.f4 = (-1L)))) ^
                                           g_12),
                                          10)) <= (g_13 = g_12)),
                                     func_14(g_12, l_20, g_21, g_21, g_21.f0))),
                                 g_238))),
                      g_571)),
                  g_792))) != g_12),
            0UL) > l_2.f6) |
          0xC987502CL) &&
         g_528)) != g_524);
  return l_20.f1;
}

static uint8_t func_5(uint8_t p_6) {
  struct S0 l_1296 = {0xA01FL};
  g_21 = l_1296;
  return g_571;
}

static int8_t func_14(int8_t p_15, struct S1 p_16, struct S0 p_17,
                      struct S0 p_18, int32_t p_19) {
  uint32_t l_24 = 18446744073709551612UL;
  int32_t l_29 = 0x78472532L;
  int32_t l_31 = 0x54F90BF5L;
  int16_t l_1014 = 0xEBF2L;
  struct S0 l_1015 = {0xD8E3L};
  int32_t l_1027 = 0xDEBF6134L;
  uint16_t l_1031 = 65533UL;
  struct S1 l_1050 = {3817, 1817, -23, 852, 267, -0, 5079};
  int32_t l_1288 = 0x9A5E3A71L;
  int32_t l_1290 = 0x9960D519L;
  uint8_t l_1292 = 0x55L;
  if ((safe_lshift_func_int16_t_s_s(
          ((((g_21.f0, l_24) ==
             (0xFCD58F28D9227919LL ||
              ((1UL || (safe_add_func_uint32_t_u_u(
                           (safe_mod_func_uint64_t_u_u(g_12, (g_21.f0, l_24))),
                           l_24))) <= l_24))),
            g_21),
           3L),
          p_18.f0))) {
    uint64_t l_50 = 1UL;
    int32_t l_999 = 0x88B3C715L;
    g_33--;
    p_18 = g_21;
    ++g_39;
    l_999 &=
        ((l_29 | (safe_mod_func_int16_t_s_s(
                     ((func_44(((safe_rshift_func_int16_t_s_s((l_31 |= p_16.f3),
                                                              (g_37 <= 6L))),
                                (safe_sub_func_uint64_t_u_u(p_19, l_50)))),
                       p_16.f2) |
                      ((safe_sub_func_int8_t_s_s(0xA4L, p_16.f3)) <= g_571)),
                     g_571))) ||
         (-1L));
  } else {
    int32_t l_1002 = (-1L);
    int32_t l_1013 = 1L;
    uint32_t l_1051 = 0x65594852L;
    uint32_t l_1052 = 18446744073709551608UL;
    int8_t l_1053 = (-1L);
    int32_t l_1098 = 0L;
    struct S1 l_1133 = {18360, 2680, -9, 5913, -40, 0, 4915};
    struct S0 l_1185 = {0UL};
    int32_t l_1231 = (-1L);
    int32_t l_1279 = 1L;
    int32_t l_1289 = (-2L);
    int32_t l_1291 = (-1L);
    if (((safe_div_func_uint8_t_u_u(
             ((l_1002,
               (((p_16.f3 &&
                  (((g_801 < p_16.f5),
                    (((((!((((l_1002 &&
                              (safe_lshift_func_int8_t_s_u(
                                  (safe_div_func_int64_t_s_s(
                                      (p_16.f4 <
                                       (((l_1002 >=
                                          ((safe_rshift_func_int8_t_s_s(
                                               (!((((((((safe_lshift_func_uint8_t_u_u(
                                                            p_17.f0,
                                                            (l_29 & 65530UL))),
                                                        p_15) >= g_32) >=
                                                      0x84791F80L) ||
                                                     0x36FD788FL) >= g_37) !=
                                                   g_66) |
                                                  g_184)),
                                               p_16.f2)),
                                           18446744073709551609UL)) > g_65) ==
                                        l_29)),
                                      p_16.f6)),
                                  4))) == g_528) &
                            l_1013) == 0xA5L)) &&
                        p_16.f1) &&
                       p_16.f3) ||
                      g_12) == p_15)),
                   (-1L))) ||
                 18446744073709551608UL) &
                g_527)) ^
              p_16.f4),
             l_1014)),
         p_19)) {
      int64_t l_1024 = (-5L);
      int8_t l_1078 = (-6L);
      int32_t l_1097 = 1L;
      uint32_t l_1101 = 0xD7F1C410L;
      struct S1 l_1130 = {8673, 6450, 23, 10711, 151, 0, 6403};
      if (((l_1015,
            ((safe_sub_func_int16_t_s_s(
                 (safe_add_func_int32_t_s_s(
                     ((safe_sub_func_int32_t_s_s(
                          (g_21,
                           ((safe_div_func_uint8_t_u_u(
                                ((l_31 = ((p_15 ^ (l_29 = l_1013)) > l_1024)),
                                 (safe_rshift_func_int8_t_s_s(p_16.f3, 5))),
                                ((g_38 <= (l_1027 = g_322)) &&
                                 (g_967 = (+(safe_div_func_uint32_t_u_u(
                                      (p_19 == g_586), p_16.f1))))))) |
                            l_24)),
                          p_15)) <= g_182),
                     g_527)),
                 p_17.f0)) <= l_1031)) ^
           p_17.f0)) {
        int32_t l_1071 = 0x4CD963E3L;
        int32_t l_1112 = 0x19243E41L;
        int64_t l_1157 = (-1L);
        if ((safe_mod_func_int64_t_s_s(
                g_69,
                (safe_mod_func_uint64_t_u_u(
                    g_12,
                    (safe_add_func_int64_t_s_s(
                        ((safe_add_func_uint32_t_u_u(
                             l_1024,
                             ((g_993 |= (safe_add_func_int32_t_s_s(
                                   (p_16.f5 =
                                        ((((g_801 !=
                                            (((((0x05L ==
                                                 ((0x25L ^
                                                   (safe_lshift_func_uint16_t_u_u(
                                                       (((safe_add_func_uint32_t_u_u(
                                                             ((safe_lshift_func_int8_t_s_s(
                                                                  (g_21,
                                                                   p_16.f5),
                                                                  (((g_238,
                                                                     p_16.f3),
                                                                    l_1050),
                                                                   0L))) ||
                                                              l_1013),
                                                             l_1051)) >=
                                                         g_238.f4) >= 7UL),
                                                       13))) < g_69)),
                                                0x67L) &
                                               g_188),
                                              0xC3L) |
                                             l_1052)) ||
                                           p_16.f6),
                                          0L),
                                         l_1002)),
                                   g_33))) >= 0x08DCL))) == g_30),
                        l_1053))))))) {
          uint64_t l_1054 = 0UL;
          g_30 &=
              (((p_15 != 0x8446L), l_1015),
               (((l_1054 ^ p_17.f0),
                 ((safe_sub_func_int16_t_s_s(
                      (safe_add_func_uint32_t_u_u(
                          (safe_add_func_int64_t_s_s(
                              ((1UL &
                                (safe_rshift_func_int8_t_s_u(
                                    (safe_add_func_int64_t_s_s(
                                        (l_1051 <=
                                         (g_238,
                                          (safe_add_func_uint8_t_u_u(
                                              ((safe_lshift_func_uint16_t_u_u(
                                                   ((((safe_mod_func_uint16_t_u_u(
                                                          g_238.f3, g_191)) ||
                                                      p_16.f6) ^
                                                     l_1054),
                                                    l_1071),
                                                   8)) |
                                               l_1050.f3),
                                              5L)))),
                                        g_377)),
                                    p_16.f4))) |
                               l_1013),
                              0xCBB7D04007C17F65LL)),
                          g_791)),
                      p_16.f5)) > (-1L))) >= g_199.f0));
        } else {
          int8_t l_1100 = (-7L);
          int32_t l_1104 = 0L;
          int32_t l_1111 = 0x36BD596BL;
          uint16_t l_1129 = 65535UL;
          p_16.f2 ^=
              (((((g_301 >= 0L) <= g_377) ||
                 ((safe_add_func_uint64_t_u_u(
                      (safe_div_func_int32_t_s_s(
                          (g_586,
                           ((((0L <=
                               (0xAF2AFC70L ||
                                ((g_238.f1 |=
                                  ((((safe_sub_func_uint16_t_u_u(
                                         l_1078, (safe_lshift_func_uint16_t_u_u(
                                                     1UL, g_315)))),
                                     0x08EAL) > 0x7146L) ==
                                   0x51A9FA1A770123F4LL)) &&
                                 g_571))) != l_24) ||
                             g_967) >= p_16.f3)),
                          4294967295UL)),
                      0x8134BAAB9636E740LL)) |
                  0x429EL)) ||
                l_1051) &&
               g_527);
          for (g_32 = 16; (g_32 != 15);
               g_32 = safe_sub_func_int32_t_s_s(g_32, 1)) {
            int32_t l_1099 = 0x29D6DC62L;
            l_1101 |=
                ((safe_add_func_uint16_t_u_u(
                     ((safe_div_func_int64_t_s_s(
                          ((safe_rshift_func_uint8_t_u_s((g_188 |= g_238.f1),
                                                         0)) <= g_184),
                          (((safe_lshift_func_uint16_t_u_u(
                                (g_793 |=
                                 (((l_1013 = g_80) |
                                   ((g_238.f6 <
                                     (((0xE175236DL !=
                                        (((0x686D572EL ^
                                           ((((g_993 =
                                                   ((((((1L >=
                                                         ((safe_sub_func_uint16_t_u_u(
                                                              ((safe_lshift_func_uint8_t_u_s(
                                                                   (((l_1098 |=
                                                                      (((safe_add_func_uint64_t_u_u(
                                                                            (l_1024 <
                                                                             (l_1097 =
                                                                                  ((g_238
                                                                                        .f4 =
                                                                                        p_16.f2) <
                                                                                   l_1071))),
                                                                            0xB4C6519C0C658331LL)) |
                                                                        p_16.f1),
                                                                       0x869ACDBBBB3DB403LL)) &
                                                                     0x55232CB130B1BF30LL) !=
                                                                    1UL),
                                                                   3)) ==
                                                               0xDDL),
                                                              l_1099)),
                                                          g_315)) > p_16.f4) ||
                                                       p_16.f2),
                                                      0x7F6B51B9FD79C856LL) !=
                                                     (-1L)) > p_16.f1)) &&
                                              g_21.f0) &&
                                             l_1100) &
                                            l_1002)) ^
                                          g_315) &
                                         g_928)) >= 0UL),
                                      l_1099)) != g_33)) ||
                                  0x2FL)),
                                l_1100)) < p_16.f1) ||
                           4294967294UL))) &
                      p_17.f0),
                     65535UL)) >= p_16.f4);
            if (p_16.f1)
              continue;
          }
          g_238.f5 = (safe_add_func_int8_t_s_s(
              ((0L > (((l_1104 |= 0x342AL) &&
                       (l_1053 & (safe_div_func_uint8_t_u_u(
                                     0xA3L, (safe_rshift_func_uint16_t_u_u(
                                                0x820EL, 10)))))),
                      1L)),
               (safe_rshift_func_uint8_t_u_s((g_322++), 5))),
              (safe_add_func_int8_t_s_s(
                  ((0x5EA5295EB42C2F9DLL &&
                    (safe_rshift_func_int16_t_s_u(
                        ((safe_div_func_uint8_t_u_u(
                             (safe_mod_func_uint32_t_u_u(
                                 (safe_rshift_func_uint16_t_u_s(
                                     (safe_sub_func_uint8_t_u_u(
                                         (l_1097 &= l_1100),
                                         ((((safe_add_func_uint16_t_u_u(
                                                (g_21.f0 = ((g_801 < p_19) <=
                                                            0x6B6EL)),
                                                l_1129)),
                                            l_1101),
                                           p_16),
                                          0xCCL))),
                                     l_1071)),
                                 g_240)),
                             g_69)) &&
                         p_16.f2),
                        p_16.f5))) ||
                   g_188),
                  g_39))));
          l_1130 = (l_1050 = g_238);
        }
        g_967 = ((1L >= ((safe_mod_func_uint8_t_u_u(
                             (l_1071 >= ((l_1133 = l_1133),
                                         ((0L ^ 0xC90582774B564BEDLL) !=
                                          ((g_184 || g_527) >= (+p_16.f2))))),
                             (safe_rshift_func_int16_t_s_s(
                                 (safe_lshift_func_uint16_t_u_s(
                                     (l_1130.f0 ^ 0x3DD1A058L), l_1130.f3)),
                                 p_19)))),
                         0x1AD8CD47L)) &
                 18446744073709551615UL);
        g_967 = (safe_div_func_uint32_t_u_u(
            (safe_mod_func_int64_t_s_s(
                ((safe_mod_func_uint64_t_u_u(
                     (safe_add_func_uint16_t_u_u(
                         ((safe_div_func_uint8_t_u_u(p_16.f4,
                                                     (l_1112 && (g_191++)))) &&
                          (((safe_rshift_func_int8_t_s_u(
                                g_571, ((safe_add_func_uint16_t_u_u(
                                            (p_16.f3 ^ g_571), p_18.f0)) |
                                        g_527))) ^
                            (l_1157 || (((g_240 != p_16.f3) == (-4L)) &
                                        (-2L)))) == p_17.f0)),
                         g_238.f0)),
                     g_69)),
                 1L),
                l_1133.f4)),
            p_16.f2));
                l_1130.f4 |= (safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((l_1050.f5 = ((((4UL != ((safe_unary_minus_func_uint8_t_u((safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(g_199.f0, (l_24 & (p_16.f5 &= (safe_div_func_int8_t_s_s(p_16.f3, 0x82L)))))) && (((safe_rshift_func_int8_t_s_s(((((0xE4L ^ ((safe_sub_func_uint64_t_u_u((((((g_238.f0 &= (safe_mod_func_int64_t_s_s((((((8UL && ((safe_mod_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_u((safe_div_func_int32_t_s_s((p_16.f1 | l_1050.f6), l_1133.f2)), 7)) <= g_378) | p_16.f3), 0xF4092F41L)) || p_17.f0)) ^ l_1157) < g_238.f1) , l_1130.f6) , g_378), l_1130.f6))) , l_1112) & p_16.f4) ^ 0xCCBC0462L) == l_1051), g_571)) & 65535UL)) || l_29) | p_16.f2) > l_1097), l_1130.f3)) >= g_80) , 18446744073709551613UL)), 0x1DC2L)) , l_1185) , 0UL) || g_993), 13)), 3)))) || g_527)) | p_16.f4) , g_993) && g_238.f2)) <= 18446744073709551615UL), p_16.f6)), 7));
      } else {
        int16_t l_1198 = 1L;
                if ((((g_67 |= ((safe_lshift_func_int16_t_s_s((18446744073709551607UL != ((((((((safe_lshift_func_int16_t_s_s(((l_1015.f0 < (g_65 = ((safe_sub_func_int64_t_s_s((safe_add_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_1198, (safe_mod_func_int64_t_s_s((safe_mod_func_uint8_t_u_u(((p_15 |= ((safe_add_func_uint64_t_u_u(((g_528 < ((safe_mod_func_uint64_t_u_u(p_16.f0, (((safe_sub_func_int8_t_s_s(((((g_993 = g_182) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(l_1130.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ p_17.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , l_1078))) , p_18.f0)) == l_1130.f0), (-10L))) , g_967)) > g_38), l_1198)), p_19)))), 14)) > p_16.f2) && g_33), (-1L))), g_69)) == 0L))) && 1L), g_873)) != g_33) != p_16.f3) > p_18.f0) == l_31) <= 0x48L) > 2UL) != 0x87C43CC6L)), 0)) , p_16.f5)) & g_968) , (-9L)))
                {
                  g_65 |= p_15;
                } else {
                  g_65 = (l_1133.f2 = (p_16.f2 ^= (l_1130.f2 |= p_16.f0)));
                  g_238 = g_238;
                }
      }
    } else {
      int64_t l_1216 = 0x5E4A5199B7ADA9F3LL;
      int32_t l_1217 = 0x973A592CL;
      int8_t l_1229 = 0xA6L;
      int32_t l_1247 = 0x75C172F7L;
      int64_t l_1284 = 0xD8A6352B8836645ELL;
      g_37 |= ((g_238.f5 |
                (g_39 = (l_29 < ((0x237022BDB339B958LL |
                                  ((~((l_1216 = p_17.f0) <= l_1217)) >=
                                   (g_756 >= p_16.f0))) ^
                                 ((safe_rshift_func_int8_t_s_u(
                                      (safe_add_func_int64_t_s_s(
                                          l_1185.f0, (safe_sub_func_int32_t_s_s(
                                                         (-1L), g_238.f6)))),
                                      1)) ^
                                  0x09L))))) ||
               g_756);
      for (p_18.f0 = 2; (p_18.f0 >= 18);
           p_18.f0 = safe_add_func_int64_t_s_s(p_18.f0, 4)) {
        uint32_t l_1230 = 0xC2612157L;
        int32_t l_1241 = 0x1C3A57D2L;
        int32_t l_1244 = 0x0E65AD9AL;
        int32_t l_1246 = 1L;
        l_1050 = g_238;
        l_1217 &= (g_65 = (safe_lshift_func_uint8_t_u_s((+(g_80 < (-1L))), 6)));
        if (g_571) {
          uint32_t l_1238 = 0xACAF4E8DL;
          int32_t l_1240 = 0L;
          g_65 = l_1229;
          g_21 = (p_16.f6, p_17);
          p_16.f4 &= l_1230;
          if (l_1231) {
            int32_t l_1239 = 0xB567C114L;
            int32_t l_1242 = (-1L);
            int32_t l_1243 = (-8L);
            int32_t l_1245 = 0L;
            int32_t l_1248 = 0xE075FBDDL;
            g_238.f2 = (safe_div_func_int32_t_s_s(
                (safe_div_func_int64_t_s_s(
                    (safe_lshift_func_int8_t_s_s(1L, l_1230)),
                    (l_1239 = (l_1238 = g_30)))),
                (g_238.f6, l_1240)));
            g_1249++;
          } else {
            l_1240 &= g_528;
          }
        } else {
          uint64_t l_1260 = 0xF5DC1668590A4472LL;
          int32_t l_1273 = (-1L);
          int32_t l_1274 = 0xEA32A638L;
          int32_t l_1275 = 0x813DFFBBL;
          p_16.f5 = (safe_mod_func_uint8_t_u_u(
              (1UL ==
               (safe_sub_func_uint8_t_u_u(
                   ((p_15 && l_1050.f4) >
                    ((safe_div_func_uint64_t_u_u(g_69, g_322)) <=
                     (((l_1260, (safe_rshift_func_uint8_t_u_u(p_16.f4, 5))) !=
                       (--g_1249)) &&
                      (((g_240 &
                         (p_16.f2 = (l_1217 ^= (safe_mod_func_uint32_t_u_u(
                                         ((safe_lshift_func_uint8_t_u_s(
                                              (safe_mod_func_uint32_t_u_u(
                                                  0x17F9FA19L, g_36)),
                                              1)) &&
                                          p_16.f5),
                                         0xD66C9ADCL))))) |
                        p_18.f0) &
                       g_184)))),
                   l_1050.f5))),
              p_15));
          for (l_1031 = 3; (l_1031 != 32);
               l_1031 = safe_add_func_uint32_t_u_u(l_1031, 4)) {
            ++g_1276;
            if (l_1133.f1)
              break;
            if (l_1279)
              continue;
            p_16.f5 ^= (safe_mod_func_int32_t_s_s(
                (safe_mod_func_uint8_t_u_u(
                    0xAEL,
                    (0x4461L |
                     (g_183 != (l_1217 = (l_1284 == (p_16.f0 = g_66))))))),
                l_1273));
          }
        }
      }
    }
    g_1285--;
    l_1050 = (g_238 = p_16);
    l_1292--;
  }
  return g_993;
}

static int16_t func_44(uint32_t p_45) {
  uint8_t l_55 = 0UL;
  struct S1 l_59 = {1957, 70, 26, 2769, -287, 0, 5702};
  for (p_45 = (-25); (p_45 == 43); p_45 = safe_add_func_uint64_t_u_u(p_45, 6)) {
    g_967 ^=
        (safe_lshift_func_uint8_t_u_s((l_55 < (5UL | func_56(l_59, g_21))), 7));
  }
  l_59.f4 = l_59.f2;
  l_59.f5 = (safe_rshift_func_uint8_t_u_s(g_968, 5));
  return l_59.f3;
}

static int64_t func_56(struct S1 p_57, struct S0 p_58) {
  uint16_t l_60 = 0UL;
  int32_t l_68 = 9L;
  int32_t l_373 = 0x8875C18FL;
  int32_t l_375 = 1L;
  uint64_t l_399 = 0x7C64D58AAD345F6ELL;
  int16_t l_400 = (-1L);
  int64_t l_493 = 9L;
  uint64_t l_579 = 0x4A4D34B35DC61D2DLL;
  uint64_t l_596 = 18446744073709551614UL;
  uint32_t l_674 = 0x131A0242L;
  uint8_t l_757 = 0xD8L;
  uint64_t l_760 = 0xF17CF80899438E3ELL;
  int32_t l_859 = (-3L);
  uint8_t l_910 = 3UL;
  uint32_t l_920 = 4294967292UL;
  uint32_t l_942 = 18446744073709551615UL;
  struct S0 l_950 = {65531UL};
  int32_t l_958 = (-1L);
  uint64_t l_994 = 0x66AA51C4DFD92F84LL;
  p_57.f2 &= l_60;
  if ((l_68 =
           ((func_61(
                 g_30,
                 ((g_69++) &&
                  ((l_68 >= l_68),
                   (((safe_sub_func_int32_t_s_s(g_12, 1UL)) || func_74(p_58)) ||
                    (g_36 != (safe_sub_func_uint32_t_u_u(0UL, p_58.f0)))))),
                 p_57.f1) ^
             p_57.f6) ||
            (-6L)))) {
    int32_t l_338 = 1L;
    uint8_t l_367 = 0x7FL;
    int32_t l_370 = 0L;
    int32_t l_371 = 0x384BA09CL;
    int32_t l_372 = 0x83DB8F6AL;
    int32_t l_374 = (-4L);
    int32_t l_376 = 6L;
    for (g_184 = 10; (g_184 == (-17)); --g_184) {
      int32_t l_347 = 1L;
      int32_t l_368 = 5L;
      if (((safe_sub_func_int32_t_s_s(
               (~g_33),
               ((((+l_338) ||
                  (1L &&
                   (safe_div_func_uint8_t_u_u(
                       ((p_57.f1 ==
                         ((safe_add_func_int32_t_s_s(
                              0L,
                              ((((((!(safe_add_func_int8_t_s_s(g_240, 0xF5L))),
                                   (safe_unary_minus_func_int16_t_s(3L))) >
                                  p_57.f0) > l_338) ^
                                0x6B9E5876L) ||
                               1UL))) < l_347)) &
                        1L),
                       g_241)))) &&
                 65535UL) == 0UL))) &
           7UL)) {
        if ((p_57.f5 = (0xCDL ^ p_57.f1))) {
          return l_338;
        } else {
          return g_184;
        }
      } else {
        uint8_t l_348 = 255UL;
        struct S0 l_369 = {65529UL};
        if (l_348) {
          p_57.f2 ^= g_69;
          if (p_57.f1)
            break;
          if (p_57.f2)
            continue;
        } else {
          if ((safe_lshift_func_int8_t_s_s(
                  ((4294967295UL ^
                    ((((safe_sub_func_uint16_t_u_u(
                           ((safe_add_func_int16_t_s_s(
                                (((safe_rshift_func_uint16_t_u_u(
                                      (safe_div_func_int32_t_s_s(
                                          0x8676E750L,
                                          (((safe_rshift_func_uint8_t_u_s(
                                                (safe_div_func_int64_t_s_s(
                                                    (((l_347 = 1L) >= l_60) <
                                                     (p_57.f4, (g_184 != 1UL))),
                                                    (safe_sub_func_uint8_t_u_u(
                                                        (safe_add_func_int8_t_s_s(
                                                            (g_66 ^=
                                                             ((p_57.f0 ||
                                                               255UL) <
                                                              0xD6E0L)),
                                                            6L)),
                                                        p_57.f2)))),
                                                1)),
                                            4294967295UL),
                                           l_347))),
                                      l_338)) == g_238.f4) ||
                                 l_338),
                                65533UL)) ||
                            0x93L),
                           g_183)) ||
                       g_67) >= l_338),
                     l_367)) == l_368),
                  3))) {
            if (g_36)
              break;
          } else {
            l_369 = p_58;
          }
          return l_338;
        }
      }
    }
    g_378--;
  } else {
    int32_t l_385 = 0x98C9DF27L;
    int32_t l_394 = 0x473E9E37L;
    uint8_t l_418 = 3UL;
    int16_t l_445 = 1L;
    struct S1 l_508 = {3178, 1820, -21, 10076, -140, -0, 3313};
    int64_t l_515 = 0x5848DA2AB3D2CF8FLL;
    uint64_t l_516 = 0x8E7615848DB85ECELL;
    int32_t l_518 = 0x2938310BL;
    int32_t l_525 = 0x94A3069EL;
    int32_t l_526 = 3L;
    uint64_t l_535 = 0UL;
    if ((l_60,
         ((l_68 &
           ((((safe_mod_func_int32_t_s_s(
                  l_385,
                  ((safe_sub_func_int8_t_s_s(
                       g_182,
                       ((((((g_238 = g_238), g_21),
                           (p_58.f0 |= (safe_lshift_func_int8_t_s_u(
                                (safe_mod_func_uint8_t_u_u(
                                    (safe_sub_func_uint64_t_u_u(
                                        (((g_199.f0--) &
                                          (((0xF021F418L ^
                                             (safe_rshift_func_int8_t_s_u(
                                                 ((7UL > ((p_57.f4 ^ (-5L)),
                                                          g_39)) <= l_385),
                                                 g_184))) > p_57.f1) ^
                                           l_399)) ^
                                         g_378),
                                        g_12)),
                                    l_394)),
                                l_68)))) > 0xFF94L) ^
                         g_188) <= l_400))),
                   g_199.f0))),
              p_57.f4) >= g_240) >= g_315)),
          l_394))) {
      uint32_t l_417 = 0xCC00055AL;
      int32_t l_517 = 0x91FB3B16L;
      int32_t l_520 = 0x36D4D769L;
      int32_t l_522 = 5L;
      int32_t l_523 = 0x43AADE25L;
    lbl_464:
      g_238.f4 ^= 0x1529816DL;
    lbl_465:
      if ((g_39 >=
           (safe_mod_func_uint16_t_u_u(
               (0x6EL <=
                (((safe_sub_func_uint8_t_u_u(
                      (g_188 =
                           (g_238.f5 &
                            ((((p_57.f2 !=
                                ((((safe_sub_func_uint16_t_u_u(
                                       (safe_mod_func_uint64_t_u_u(
                                           (safe_lshift_func_uint8_t_u_u(
                                               ((((+(safe_sub_func_uint8_t_u_u(
                                                      g_65,
                                                      (((!(safe_rshift_func_int16_t_s_u(
                                                            l_417, 8))) &&
                                                        0x6568L) <= l_417)))) >
                                                  (0x25CBE153FDD8CB67LL |
                                                   p_57.f3)) >= l_418) ||
                                                l_385),
                                               l_417)),
                                           g_182)),
                                       0x7032L)) &
                                   4294967295UL) |
                                  0xD45DFDD5CE231998LL) != l_60)),
                               l_418) <= 0x13L) == p_57.f6))),
                      p_57.f0)) >= l_418),
                 l_385)),
               l_418)))) {
        uint16_t l_419 = 4UL;
        return l_419;
      } else {
        uint32_t l_443 = 0xC9CAAB59L;
        int32_t l_444 = (-8L);
        int32_t l_446 = 5L;
        struct S1 l_463 = {21369, 3168, -17, 1223, 267, 0, 5323};
        if (((safe_mod_func_int32_t_s_s(
                 (g_37,
                  (((safe_lshift_func_int8_t_s_s(
                        (safe_div_func_int64_t_s_s(
                            (safe_mod_func_int64_t_s_s(
                                ((l_373,
                                  (((g_238.f5 <
                                     ((safe_sub_func_int32_t_s_s(
                                          (g_69 <=
                                           ((safe_div_func_int64_t_s_s(
                                                ((l_444 =
                                                      ((safe_lshift_func_uint16_t_u_u(
                                                           p_57.f1, 9)) <=
                                                       ((((g_238.f1 ^
                                                           (l_443 =
                                                                ((((!(((+(-5L)) >=
                                                                       0x2077L) |
                                                                      (((safe_lshift_func_uint16_t_u_s(
                                                                            (safe_unary_minus_func_int32_t_s(
                                                                                (safe_lshift_func_uint16_t_u_u(
                                                                                    0x3FE3L,
                                                                                    15)))),
                                                                            9)) <
                                                                        0x3ED2BC827CFBFAACLL) ==
                                                                       0UL))) <=
                                                                   0xEE3FL) &&
                                                                  0xCB01CDCFF5673DEALL),
                                                                 l_399))) |
                                                          0x05B4L),
                                                         g_21.f0) >
                                                        0xF83382B7L))) == 1UL),
                                                g_240)) <= 0xF8L)),
                                          l_445)),
                                      g_301)),
                                    l_417) >= l_394)),
                                 0x1B3F29B522290BD6LL),
                                p_57.f3)),
                            p_57.f5)),
                        l_446)) == g_65) <= 0x80L)),
                 l_445)) == g_37)) {
          uint16_t l_451 = 0x721EL;
          int32_t l_453 = (-1L);
          p_57.f2 =
              ((l_444 |=
                (((g_38 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))),
                  (safe_lshift_func_int8_t_s_u(l_451, 1))) !=
                 (safe_unary_minus_func_int16_t_s((l_453 = 0xBB70L))))) &
               ((safe_mod_func_uint8_t_u_u(
                    (safe_div_func_uint32_t_u_u(
                        (!((((p_57.f4, l_417) < p_57.f0),
                            (safe_div_func_int64_t_s_s(
                                (g_36 = ((safe_add_func_uint64_t_u_u(
                                             p_57.f6, (g_32 = 0L))) >= (-1L))),
                                l_394))),
                           0x779BL)),
                        l_417)),
                    p_57.f6)) > p_57.f3));
        } else {
          p_58 = g_21;
          g_238 = l_463;
        }
        if (g_183)
          goto lbl_464;
      }
      if (p_57.f3) {
        int8_t l_468 = 1L;
        if (g_21.f0)
          goto lbl_465;
        l_468 ^= ((++p_58.f0) <= p_57.f3);
        for (g_301 = 18; (g_301 > 20);
             g_301 = safe_add_func_int32_t_s_s(g_301, 2)) {
          uint8_t l_483 = 0xD2L;
          l_493 = ((((safe_sub_func_int16_t_s_s(
                         (safe_sub_func_uint32_t_u_u((g_378--), g_191)),
                         (((safe_div_func_uint32_t_u_u(l_417, 0xF5DC8482L)) >
                           (safe_rshift_func_int16_t_s_u(
                               (safe_lshift_func_int16_t_s_s(8L, 6)), 7))),
                          (((((l_483 <
                               (((l_385 ||
                                  (safe_add_func_uint64_t_u_u(
                                      (~((l_68 ^=
                                          (((safe_rshift_func_uint16_t_u_u(
                                                0xEED5L, g_199.f0)) >=
                                            (((safe_lshift_func_int16_t_s_u(
                                                  (safe_sub_func_uint8_t_u_u(
                                                      8UL, l_417)),
                                                  0)) &
                                              p_57.f4) &
                                             0x20L)) |
                                           g_80)) ^
                                         5L)),
                                      g_301))) < 0x0DL) <= g_65)) |
                              l_417) ^
                             1UL),
                            g_188) == 0xD239F8EEL)))) &
                     249UL) >= p_57.f6),
                   g_66);
        }
      } else {
        int32_t l_519 = (-1L);
        int32_t l_521 = 0xC5583EF5L;
        l_518 &=
            ((0L <
              (((((safe_add_func_int64_t_s_s(
                      ((safe_lshift_func_int16_t_s_s(
                           ((-10L) | l_385),
                           ((safe_sub_func_int16_t_s_s(
                                (l_517 =
                                     (((l_394 |=
                                        ((safe_sub_func_int32_t_s_s(
                                             ((safe_sub_func_int16_t_s_s(
                                                  p_57.f2,
                                                  (l_515 = (safe_sub_func_uint8_t_u_u(
                                                       g_315,
                                                       (((p_57, p_57.f1),
                                                         l_508),
                                                        (safe_add_func_uint8_t_u_u(
                                                            (safe_sub_func_uint64_t_u_u(
                                                                ((((g_301++) &&
                                                                   (g_301 !=
                                                                    0xAEL)) ^
                                                                  0x9714L) <=
                                                                 0xD7EAL),
                                                                0x1FBFD773E599F898LL)),
                                                            g_33)))))))) <
                                              p_57.f5),
                                             l_400)) < g_315)) &&
                                       0x22L) ^
                                      l_516)),
                                g_184)) != p_57.f5))),
                       g_240),
                      g_80)) != l_417) > g_188) ||
                g_183) <= p_58.f0)) ||
             p_57.f2);
        g_528++;
        p_57.f4 &= (safe_sub_func_uint16_t_u_u(
            (safe_sub_func_uint16_t_u_u(l_535, 0x32B0L)), 0x8C89L));
      }
    } else {
      int16_t l_561 = (-8L);
      struct S0 l_562 = {0x698AL};
      uint32_t l_576 = 0x50148CBAL;
      for (l_400 = 0; (l_400 != (-23));
           l_400 = safe_sub_func_uint64_t_u_u(l_400, 6)) {
        uint32_t l_559 = 4294967295UL;
        int32_t l_560 = 9L;
        g_65 =
            ((18446744073709551615UL &&
              (((safe_unary_minus_func_int64_t_s((safe_add_func_uint16_t_u_u(
                    (p_58.f0 ==
                     (safe_div_func_int8_t_s_s(
                         (safe_mod_func_int64_t_s_s(
                             (+((((p_57.f0 ||
                                   (((g_238.f5,
                                      ((safe_mod_func_int8_t_s_s(
                                           (((((safe_sub_func_int64_t_s_s(
                                                   0xF9CED6740F5759D8LL,
                                                   g_33)) |
                                               0x5CB0L) &&
                                              (-1L)) <
                                             ((g_301 = (safe_mod_func_uint16_t_u_u(
                                                   (+((safe_div_func_int32_t_s_s(
                                                          ((l_559 = (safe_sub_func_uint64_t_u_u(
                                                                ((safe_mod_func_int64_t_s_s(
                                                                     ((p_57,
                                                                       g_241) >=
                                                                      0x34E3L),
                                                                     0x02128AB49729E21BLL)) &&
                                                                 l_68),
                                                                (-1L)))) !=
                                                           p_57.f1),
                                                          (-5L))) > p_57.f1)),
                                                   p_58.f0))) <= 4L)) |
                                            0xB4A67218FBF74A89LL),
                                           l_560)),
                                       g_37)) != 0xF6L) ||
                                    l_561)) >= g_12) ^
                                 0x08A696AFL) > g_67)),
                             1UL)),
                         0x24L))),
                    l_400)))) &
                l_375) > g_65)) &
             p_58.f0);
      }
      l_562 = l_562;
      for (g_38 = 0; (g_38 == 14); g_38 = safe_add_func_uint16_t_u_u(g_38, 7)) {
        int64_t l_568 = 0x5C343ED73A8738E9LL;
        g_238.f2 =
            (((p_57.f1 &=
               (7L &
                ((g_527 ^=
                  ((((g_39 =
                          ((l_561 != 0x4CL) == (+(((-9L) == l_568) > 0UL)))) <=
                     ((((safe_mod_func_uint8_t_u_u((g_69 = p_57.f0), g_183)) <=
                        0xA1BF90C52FB11BB9LL) <= 1UL) &
                      g_378)),
                    g_238),
                   g_571)) <= g_238.f2))) <= p_57.f5) <= p_57.f2);
        g_65 = (~0x67D3L);
        if (p_57.f4)
          break;
        p_57.f4 &=
            (g_238.f5 ^=
             ((!((((((safe_add_func_uint16_t_u_u(
                         (((g_238.f6 &
                            (((((l_576 < (safe_lshift_func_uint16_t_u_u(
                                             l_579, (g_524 > g_67)))) <
                                (safe_mod_func_int32_t_s_s(
                                    (safe_div_func_uint64_t_u_u(
                                        (safe_lshift_func_uint8_t_u_u(
                                            (1L &
                                             (g_36 <
                                              (0x7F8CL | (l_375 = g_238.f3)))),
                                            g_586)),
                                        l_400)),
                                    g_182))) < 4UL),
                              g_301) <= g_32)) ^
                           g_315) <= (-4L)),
                         p_57.f0)),
                     p_57.f1) != 1L) <= l_568) &
                  p_57.f1) &&
                 l_418)) ||
              0UL));
      }
      p_57 = g_238;
    }
  }
  if ((safe_sub_func_int16_t_s_s(
          ((((((safe_lshift_func_int8_t_s_s(
                   (0x6EL &
                    (safe_rshift_func_uint16_t_u_s(l_373, (l_68 = p_57.f4)))),
                   l_493)) <=
               ((0xD471L < (safe_lshift_func_uint8_t_u_s(g_66, 7))) ||
                l_373)) !=
              (((p_57.f0 & (((g_240 = (((safe_unary_minus_func_int64_t_s(
                                            ((l_375, l_400) | p_57.f2))) |
                                        7UL) <= 0x3B9260F6L)) ^
                             l_373),
                            g_241)),
                p_57.f1) |
               p_57.f6)) >= p_57.f4) > l_493) ||
           l_399),
          l_596))) {
    uint32_t l_609 = 0UL;
    uint32_t l_610 = 18446744073709551615UL;
    int16_t l_611 = 1L;
    int32_t l_672 = (-1L);
    int32_t l_673 = 0x5BAB80C9L;
    uint32_t l_677 = 4294967288UL;
    struct S1 l_691 = {14501, 5528, -0, 7773, 227, 0, 2285};
    uint32_t l_707 = 0xF605241DL;
    uint64_t l_733 = 18446744073709551611UL;
    int64_t l_820 = 0x28812E388A6D2202LL;
    uint8_t l_860 = 0xD6L;
    uint8_t l_869 = 0x70L;
    uint32_t l_885 = 0x7EBE34DAL;
    struct S0 l_907 = {65533UL};
    int32_t l_919 = (-5L);
    if ((g_524 &
         (((((p_57, (l_596 && l_399)) |
             (safe_mod_func_uint16_t_u_u(
                 ((g_65, ((safe_sub_func_uint16_t_u_u(
                              ((((2UL & (safe_add_func_uint16_t_u_u(
                                            (safe_mod_func_uint32_t_u_u(
                                                g_69, p_57.f3)),
                                            ((safe_sub_func_uint8_t_u_u(
                                                 (safe_div_func_int64_t_s_s(
                                                     0xEC0DF3DED07D7D71LL,
                                                     0xFE38C1710C6551B0LL)),
                                                 p_57.f3)),
                                             65532UL)))),
                                 0x598DL) > l_609) ||
                               l_609),
                              l_609)) == p_57.f0)) ||
                  l_610),
                 l_611))) <= p_57.f5) > 0xB0L) ||
          g_322))) {
      uint16_t l_644 = 7UL;
      int32_t l_655 = 0x4245560AL;
      int32_t l_658 = 1L;
      for (l_493 = 16; (l_493 >= (-4));
           l_493 = safe_sub_func_int64_t_s_s(l_493, 9)) {
        uint16_t l_614 = 0x585DL;
        ++l_614;
        return p_57.f2;
      }
      for (l_611 = 0; (l_611 >= 5); ++l_611) {
        int16_t l_619 = 6L;
        int16_t l_656 = 0xF40CL;
        ++g_620;
        for (g_586 = (-17); (g_586 > (-21)); --g_586) {
          uint64_t l_641 = 0UL;
          int32_t l_659 = (-1L);
          for (l_609 = 0; (l_609 == 39);
               l_609 = safe_add_func_uint16_t_u_u(l_609, 1)) {
            uint64_t l_657 = 1UL;
            g_238.f5 = 0xC207066FL;
            l_659 =
                (((safe_add_func_uint64_t_u_u(
                      ((((safe_sub_func_int8_t_s_s(
                             ((0xD8941FD6L ^
                               (l_373 =
                                    ((((safe_div_func_uint8_t_u_u(
                                           g_80,
                                           ((~(safe_sub_func_int8_t_s_s(
                                                0L,
                                                (safe_rshift_func_int16_t_s_s(
                                                    ((+(l_655 = (safe_mod_func_uint64_t_u_u(
                                                            l_641,
                                                            (g_36 &=
                                                             ((safe_add_func_int8_t_s_s(
                                                                  (l_644 =
                                                                       g_524),
                                                                  (safe_mod_func_int8_t_s_s(
                                                                      p_57.f3,
                                                                      (safe_sub_func_int16_t_s_s(
                                                                          (~0xD6L),
                                                                          (((safe_div_func_int32_t_s_s(
                                                                                (p_57.f5 &=
                                                                                 g_188),
                                                                                (safe_mod_func_uint8_t_u_u(
                                                                                    ((~l_619),
                                                                                     p_57.f1),
                                                                                    255UL)))),
                                                                            l_373) &
                                                                           p_57.f2))))))) !=
                                                              0xA14CL)))))) <=
                                                     l_656),
                                                    l_657))))) &&
                                            6UL))) == l_658) <= p_58.f0) <=
                                     1L))),
                              g_315),
                             p_58.f0)) == g_238.f4) ||
                        p_57.f0) |
                       g_586),
                      g_315)),
                  0x672551F9L),
                 0xA150D49BL);
          }
          if (((safe_rshift_func_int8_t_s_u(
                   (safe_lshift_func_int16_t_s_u(
                       ((p_57.f6 &
                         (safe_sub_func_uint8_t_u_u(p_57.f2, l_609))) <
                        (g_39 |=
                         ((safe_add_func_int8_t_s_s(
                              (((g_620 == 0x1D75A18AL) >=
                                (safe_rshift_func_int8_t_s_u(1L, 1))) &&
                               (((g_38, (0x3926L >
                                         ((safe_mod_func_int16_t_s_s(
                                              (g_184 = p_57.f3), g_238.f2)) |
                                          g_586))) >= g_238.f6),
                                (-1L))),
                              l_644)) <= 0L))),
                       4)),
                   6)),
               0L)) {
            return l_655;
          } else {
            p_57.f5 = p_57.f3;
            return g_37;
          }
        }
      }
      l_674++;
      ++l_677;
    } else {
      uint8_t l_687 = 2UL;
      uint32_t l_692 = 4294967291UL;
      int32_t l_758 = (-6L);
      int64_t l_759 = 0x10201B5C969F6449LL;
      int32_t l_796 = (-1L);
      int32_t l_797 = 0x66E5B6A1L;
      int32_t l_799 = (-9L);
      for (g_301 = (-14); (g_301 != 49);
           g_301 = safe_add_func_uint8_t_u_u(g_301, 3)) {
        int16_t l_690 = (-1L);
        int32_t l_705 = 3L;
        if (((((safe_div_func_uint64_t_u_u(
                   (p_57.f0 ||
                    ((g_69 ^=
                      (((((+(safe_rshift_func_int16_t_s_u(
                              ((l_687 ^= (((l_673 = (0xEB54L < p_57.f1)) <=
                                           g_238.f2) > g_12)) |
                               g_315),
                              g_21.f0))) ^
                          (safe_mul_func_int16_t_s_s(
                              (g_184 = 9L),
                              (18446744073709551606UL >= l_690)))) != 2UL) <=
                        0x1EL) < l_609)) ||
                     p_57.f3)),
                   18446744073709551614UL)) != 0xAC861C3EL) < g_571) ^
             0L)) {
          g_238 = l_691;
        } else {
          uint8_t l_715 = 0x80L;
          int64_t l_741 = 1L;
          int64_t l_785 = 0x89D08C2D27B3D546LL;
          int32_t l_798 = (-4L);
          int32_t l_809 = 0x4B1AA5B2L;
          int16_t l_831 = 8L;
          int32_t l_833 = 0x655BBAA5L;
          int32_t l_834 = 0x1FA30236L;
          if (l_692) {
            int64_t l_706 = 0x06ACFC086CD2EA72LL;
            p_57.f5 &=
                (!(l_673 = ((+(safe_mod_func_int32_t_s_s(
                                p_57.f3,
                                (safe_lshift_func_uint16_t_u_s(
                                    (((safe_add_func_int32_t_s_s(
                                          p_57.f1, 0x9391FA2DL)) &&
                                      (safe_lshift_func_int16_t_s_u(
                                          g_238.f3,
                                          (((++p_58.f0) |
                                            (l_690 > ((g_69, (l_705 ^= l_690)),
                                                      0x3CC1CF37L))) !=
                                           (l_677 == 249UL))))),
                                     l_706),
                                    g_199.f0))))) ^
                            l_707)));
            g_238 = p_57;
          } else {
            uint16_t l_731 = 0UL;
            uint64_t l_732 = 0xFD49211BAC9527ABLL;
            uint16_t l_745 = 0x07DBL;
                        p_57.f5 = (((!((((p_57.f0 == (safe_lshift_func_int8_t_s_s(g_315, ((safe_rshift_func_int8_t_s_s((p_57.f2 ^ ((((safe_sub_func_uint64_t_u_u((l_691.f4 &= l_715), (safe_mod_func_int16_t_s_s(((p_57.f4 > 1L) > ((g_571 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_399), 1UL)) == (-1L)), l_609)) & p_57.f1) == (-1L)) < g_301) && p_57.f0))), g_32)), 0xE6E002D4L)))) || l_732) >= l_732) == l_687), l_691.f3)) == 1UL) & g_377), l_733)) == 0x4FL)) >= p_57.f2)), p_57.f6)))) < p_58.f0) ^ g_238.f6) , g_238.f4)), g_182)) || 0xA8L)))) > 251UL) , g_301) , l_691.f4)) || p_57.f3) && 0L);
                        l_375 ^= (((safe_lshift_func_int8_t_s_s((g_191 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_66), (g_65 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((l_758 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_579 ^ (((5UL && ((((p_58 = g_199) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & p_57.f0)) >= 4UL) ^ g_756)) , p_58.f0), l_715)), p_57.f0)) <= l_687)) , p_57.f6), l_757)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | p_57.f3)), g_322))) >= 0xC1BC967721442813LL)))) ^ l_610), p_57.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);
                        p_57.f4 = (p_57.f2 = 0xA79062E5L);
                        l_760--;
          }
          l_705 = (-1L);
          if ((safe_add_func_uint16_t_u_u(
                  (l_691.f2 =
                       (((((((l_691.f2, g_30) ^
                             ((+(safe_lshift_func_int8_t_s_u(
                                  (safe_sub_func_int32_t_s_s(
                                      p_57.f3, (g_80 == p_57.f1))),
                                  6))) <=
                              (((8L &
                                 (l_692 <
                                  (((+(safe_rshift_func_int16_t_s_s(
                                        (safe_unary_minus_func_uint8_t_u(
                                            (l_705 = p_57.f2))),
                                        (safe_add_func_uint64_t_u_u(
                                            g_524, 0xC2CA4FFE53744833LL))))) <=
                                    (-5L)) |
                                   p_57.f3))) &
                                1UL) < 0x529AL))) ||
                            p_57.f0),
                           p_57.f1) |
                          g_240),
                         g_240) > p_57.f6)),
                  l_60))) {
            uint32_t l_786 = 0xBE94B622L;
            int8_t l_787 = 0L;
            int32_t l_788 = 0x65367992L;
            int32_t l_789 = 0x26FEF397L;
            int32_t l_790 = 0L;
            l_786 ^=
                ((g_199.f0 >= 0UL) <=
                 (safe_div_func_uint8_t_u_u(
                     (p_57.f4 &&
                      (p_57.f0 =
                           ((((safe_add_func_uint64_t_u_u(
                                  (p_57.f2 &
                                   (+(p_58.f0 |=
                                      ((((safe_div_func_int16_t_s_s(
                                             ((l_785, 0UL) & g_322), 0x0D89L)),
                                         0x9F8EAEBA3A833647LL) != l_715) >=
                                       l_692)))),
                                  l_673)) != 0x9F1F1DE72F8155A5LL),
                             65535UL),
                            p_57.f2))),
                     0x27L)));
            --g_793;
            g_801--;
          } else {
            int8_t l_818 = 2L;
            int32_t l_828 = (-7L);
            int32_t l_829 = 1L;
            int32_t l_830 = (-1L);
            int32_t l_832 = (-4L);
            if (g_30)
              break;
            p_57.f2 = (safe_rshift_func_uint16_t_u_s(
                (l_799 |
                 (((p_57.f5 <=
                    ((((((((!(safe_sub_func_uint8_t_u_u(
                               (g_801--),
                               (g_620 >
                                (((((safe_add_func_uint16_t_u_u(
                                        (safe_lshift_func_uint16_t_u_s(
                                            (p_58.f0 = l_818), (~0x15F3096FL))),
                                        (l_820 != g_524))) ==
                                    (safe_add_func_uint8_t_u_u(
                                        253UL,
                                        (safe_div_func_int32_t_s_s(
                                            (safe_unary_minus_func_int32_t_s((
                                                (safe_rshift_func_uint8_t_u_u(
                                                    ((++g_378) !=
                                                     ((l_834 = (p_57.f2 ==
                                                                1UL)) < 0xD0L)),
                                                    l_579)) ^
                                                g_182))),
                                            8L))))),
                                   0xE5B274CA6F72970ELL) &&
                                  0x791A8EF8E600BD62LL) >= 0x6BL))))) &&
                           l_375) &&
                          p_57.f2) &&
                         0xDAL),
                        g_800) <= p_57.f3) >= g_586) >= p_57.f1)) != p_57.f1) >
                  g_33)),
                l_672));
            l_705 =
                (p_57.f0 <=
                 (safe_div_func_uint8_t_u_u(
                     (p_57.f5 && (g_199.f0 = 0x40CEL)),
                     (safe_sub_func_int64_t_s_s(
                         (((--g_378) >=
                           ((safe_rshift_func_uint8_t_u_s(255UL, 4)) ==
                            (((safe_div_func_uint64_t_u_u(
                                  (safe_rshift_func_uint16_t_u_s(
                                      (((1L ^
                                         (safe_div_func_uint32_t_u_u(
                                             g_792,
                                             (safe_mod_func_int16_t_s_s(
                                                 (l_690 >=
                                                  (safe_mod_func_uint8_t_u_u(
                                                      (((safe_div_func_uint64_t_u_u(
                                                            l_690,
                                                            ((l_691.f5 &=
                                                              ((safe_mod_func_uint8_t_u_u(
                                                                   l_758,
                                                                   p_57.f3)),
                                                               l_797)),
                                                             18446744073709551613UL))) &&
                                                        (-8L)) &
                                                       p_57.f0),
                                                      (-1L)))),
                                                 p_57.f2))))) != g_184),
                                       l_859),
                                      5)),
                                  18446744073709551615UL)) &
                              l_691.f4) > l_860))) |
                          (-1L)),
                         l_690)))));
          }
        }
        g_30 = l_691.f3;
      }
    }
    for (l_399 = 0; (l_399 > 1); l_399++) {
      int32_t l_870 = (-1L);
      g_37 =
          (p_57.f3, (safe_rshift_func_uint16_t_u_u(
                        (safe_mod_func_int32_t_s_s(
                            (safe_rshift_func_uint16_t_u_s(g_69, 13)), l_869)),
                        10)));
      return l_870;
    }
    for (l_60 = 0; (l_60 < 19); l_60 = safe_add_func_int64_t_s_s(l_60, 7)) {
      int32_t l_878 = 0xFC2DEAD7L;
      int32_t l_897 = 0xF61E11E5L;
      l_691.f2 =
          ((g_199.f0 ==
            ((((l_885 =
                    (((((g_873++) <=
                        (l_672 =
                             (((0x792DL ||
                                (safe_rshift_func_uint16_t_u_s(l_878, 13))) ||
                               (((p_58.f0--) !=
                                 (l_691.f5 ^=
                                  (0x70BD7A420812CA0FLL >
                                   (safe_rshift_func_int16_t_s_u(
                                       (((p_57 = p_57), l_691.f0),
                                        (safe_rshift_func_uint8_t_u_s(
                                            p_57.f5,
                                            (0xF1AA9032L >= p_57.f6)))),
                                       1))))),
                                0xE25AB159L)) < g_191))) != 255UL) != g_377) ^
                     (-1L))) <= l_820),
              0x7AF6L) >= 1UL)) >= g_69);
      g_21 =
          (l_907 =
               (((((safe_add_func_int8_t_s_s(
                       (safe_lshift_func_int16_t_s_s(
                           ((safe_div_func_uint8_t_u_u(
                                (l_691.f5 =
                                     (safe_unary_minus_func_uint8_t_u(0UL))),
                                ((l_859 ^
                                  ((safe_add_func_int32_t_s_s(
                                       (safe_add_func_uint8_t_u_u(
                                           (++g_322),
                                           (safe_sub_func_uint32_t_u_u(
                                               g_30,
                                               (safe_rshift_func_uint16_t_u_s(
                                                   l_897,
                                                   ((((-1L) || (-6L)) !=
                                                     ((~0x65L) <
                                                      (((((p_57.f4 =
                                                               (((safe_lshift_func_uint16_t_u_u(
                                                                     ((l_878 >=
                                                                       l_897) |
                                                                      l_878),
                                                                     g_184)) >=
                                                                 0xA9570CA5L) &
                                                                p_57.f5)),
                                                          p_57.f6) > g_67) &
                                                        p_57.f2) ^
                                                       0x1299A5A1L))) |
                                                    0xB6L))))))),
                                       2UL)),
                                   g_33)) &&
                                 (-1L)))) == 0xD6L),
                           l_691.f6)),
                       g_586)) >= p_57.f5) <= 0xFEBE5530D01B6D3DLL) > l_691.f4),
                p_58));
      l_373 = l_878;
    }
    g_30 |=
        (((safe_add_func_int8_t_s_s(
              (((((l_373 ^= ((l_673 = l_672), l_910)) >=
                  (p_57.f4 =
                       ((safe_add_func_uint8_t_u_u(
                            (((safe_div_func_uint64_t_u_u(
                                  (safe_mod_func_uint64_t_u_u(
                                      0x5357627B9C38BE8CLL,
                                      (safe_rshift_func_int8_t_s_u(
                                          (((p_57.f2 < (l_919 = l_691.f4)) ^
                                            (g_315 &
                                             (l_920 <= (g_184 = g_67)))) <
                                           (l_859 =
                                                ((((l_691.f5 =
                                                        (safe_mod_func_int8_t_s_s(
                                                            (safe_div_func_int32_t_s_s(
                                                                ((l_691.f2 ^=
                                                                  (-8L)) ||
                                                                 0xF7D7L),
                                                                l_677)),
                                                            0x7AL))) ^
                                                   l_400) < l_707) <= g_756))),
                                          6)))),
                                  g_80)) |
                              g_238.f3),
                             0x4DL),
                            l_920)) &&
                        4294967292UL))) != 4294967293UL) ||
                0x61L) == 1UL),
              0x74L)),
          (-5L)),
         l_610);
  } else {
    int64_t l_925 = 0xA73062E26A32E214LL;
    int32_t l_926 = 0x25CEF752L;
    int32_t l_927 = 0xAB24C309L;
    struct S1 l_947 = {21304, 6517, -24, 3525, 164, 0, 2283};
    g_928++;
    for (g_37 = (-27); (g_37 < 10); ++g_37) {
      int8_t l_937 = 5L;
      l_947 =
          (g_238 =
               ((l_68 =
                     ((((p_57.f0 >
                         (safe_lshift_func_int8_t_s_u(
                             (safe_div_func_uint8_t_u_u(
                                 (g_793 !=
                                  (l_927,
                                   ((l_937 = 0xDABBL) ||
                                    (safe_add_func_int64_t_s_s(
                                        (safe_mod_func_int8_t_s_s(l_942, 1UL)),
                                        (safe_rshift_func_uint16_t_u_s(
                                            (l_920 <
                                             (safe_add_func_int8_t_s_s(
                                                 (l_937 >= p_57.f6), l_942))),
                                            7))))))),
                                 1UL)),
                             0))) &&
                        4294967295UL) > p_57.f5),
                      g_199.f0)),
                p_57));
    }
    l_947.f2 = 0L;
    for (g_378 = 0; (g_378 >= 10); ++g_378) {
      l_950 = (l_859, l_950);
    }
  }
  for (p_58.f0 = 0; (p_58.f0 == 17); ++p_58.f0) {
    int64_t l_953 = 0x86445DF67443E0CELL;
    struct S0 l_954 = {0xD225L};
    int32_t l_955 = (-1L);
    int32_t l_956 = 6L;
    int32_t l_957 = 1L;
    int32_t l_959 = (-5L);
    int32_t l_960 = 0xFA289949L;
    int32_t l_961 = 0x9CE9722AL;
    int32_t l_962 = 0x4270AC42L;
    int32_t l_963 = 0xE0FAB585L;
    int32_t l_964 = (-1L);
    int32_t l_965 = 9L;
    int32_t l_966 = (-1L);
    l_954 = (((l_375 = (g_377 = l_953)) | (g_37 &= (g_241 | p_57.f0))), l_950);
    l_954 = p_58;
    --g_968;
    g_30 |=
        ((safe_div_func_uint8_t_u_u(
             ((safe_div_func_uint8_t_u_u(
                  (safe_div_func_uint16_t_u_u((--g_315), p_57.f0)),
                  (0x5A0BAD988B54577ELL ||
                   (l_962 !=
                    (g_21,
                     (safe_lshift_func_int16_t_s_u(
                         (-3L),
                         (p_57.f1 |
                          (safe_add_func_int8_t_s_s(
                              p_57.f3,
                              (safe_sub_func_int32_t_s_s(
                                  (safe_div_func_int8_t_s_s(
                                      ((l_994 =
                                            ((((safe_div_func_int16_t_s_s(
                                                   (0x7BF8L >
                                                    ((safe_lshift_func_int16_t_s_s(
                                                         (safe_lshift_func_uint16_t_u_s(
                                                             (l_955 = (l_950,
                                                                       l_958)),
                                                             14)),
                                                         6)) >= g_993)),
                                                   g_65)) &&
                                               0xD5682F7CL) <= g_873) ==
                                             g_801)) >= 65527UL),
                                      251UL)),
                                  0xFC6382EAL)))))))))))) > g_993),
             l_963)) < 1L);
  }
  return l_910;
}

static uint8_t func_61(uint8_t p_62, uint32_t p_63, int64_t p_64) {
  uint8_t l_323 = 255UL;
  uint8_t l_328 = 0UL;
  struct S1 l_329 = {20957, 5903, 30, 8718, 270, -0, 5165};
  l_329 =
      ((((safe_sub_func_uint32_t_u_u(
             ((g_322 ^= (g_184 = 0xCEC1L)), (l_323 = 1UL)),
             ((safe_div_func_int32_t_s_s(p_62, g_238.f1)) ==
              (safe_rshift_func_uint8_t_u_u(
                  ((7L <=
                    (((l_328,
                       (((l_328 < (l_328 == (p_62 > g_182))), l_328) && l_328)),
                      0x4EC86742A66AFE18LL),
                     g_65)) != p_64),
                  p_63))))) >= (-1L)) >= 1UL),
       l_329);
  l_329 = g_238;
  return p_64;
}

static int8_t func_74(struct S0 p_75) {
  int32_t l_81 = 6L;
  int8_t l_82 = 0x18L;
  int32_t l_91 = (-5L);
  struct S0 l_100 = {0x200CL};
  int32_t l_268 = 0x62F120E7L;
  int64_t l_269 = 0x10A1EBC7C7492526LL;
  int32_t l_316 = (-6L);
  uint32_t l_317 = 18446744073709551615UL;
  l_317 =
      (((l_316 &= (safe_div_func_uint8_t_u_u(
             ((g_80 ^= g_30) &
              (((l_82 =
                     (l_81 = (0xDA1D0942DF00AC9ELL >= 0x9644A59A1FF38044LL))) ^
                0xCA3631A0D171E9D6LL) <=
               (g_315 |=
                ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, g_37)) >
                 (func_85(
                      (l_268 &= (safe_lshift_func_uint16_t_u_s(
                           (g_12 >= l_91),
                           ((safe_div_func_uint8_t_u_u(
                                func_94((safe_div_func_uint16_t_u_u(g_36, 1L)),
                                        l_100, p_75.f0),
                                0xCDL)) |
                            p_75.f0)))),
                      l_269, g_184) < g_38))))),
             (-4L)))),
        p_75.f0) |
       0xEDL);
  return g_238.f5;
}

static uint8_t func_85(int16_t p_86, int8_t p_87, uint8_t p_88) {
  int8_t l_276 = 0xBFL;
  int32_t l_289 = 6L;
  int32_t l_291 = (-1L);
  int32_t l_292 = 1L;
  int32_t l_293 = 0x81DF53A7L;
  int32_t l_294 = 0L;
  int32_t l_298 = 0x4EC99466L;
  for (g_191 = (-27); (g_191 < 39);
       g_191 = safe_add_func_uint8_t_u_u(g_191, 8)) {
    int32_t l_284 = 0xEE263D41L;
    uint64_t l_288 = 18446744073709551615UL;
    int32_t l_290 = 9L;
    int32_t l_296 = 0xC6978A9AL;
    int32_t l_297 = 0x9ADCCFBDL;
    int32_t l_299 = 8L;
    int32_t l_300 = 0x80C45391L;
    struct S0 l_311 = {1UL};
    struct S1 l_314 = {15034, 7901, -16, 6783, -510, -0, 5803};
    if ((((safe_lshift_func_uint8_t_u_s(
              (p_88 = (safe_rshift_func_uint8_t_u_s(g_241, 2))), l_276)) &&
          (((safe_unary_minus_func_uint16_t_u((
                (safe_lshift_func_int8_t_s_s(
                    ((((g_238 = g_238),
                       ((l_289 = (safe_add_func_int64_t_s_s(
                             ((((g_32 != p_86) ==
                                (((safe_rshift_func_int16_t_s_u(
                                      (3UL ==
                                       (((l_284 <= 0xB1A0L) !=
                                         (((((safe_rshift_func_uint8_t_u_u(
                                                 ((!p_86), p_87), 5)) > l_288) &
                                            (-10L)),
                                           0xE1L) > g_182)),
                                        g_191)),
                                      l_276)) &
                                  5L) ||
                                 0xA2B9BF124FD362E7LL)) == l_276),
                              (-1L)),
                             l_288))) &&
                        l_289)) &
                      l_284) >= 0x62L),
                    l_288)),
                l_276))) >= g_191) |
           1L)),
         p_86)) {
      int8_t l_295 = (-5L);
      --g_301;
      g_238.f4 &=
          ((((l_291 &= 0x62L) <=
             ((l_298 =
                   ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^
                          (l_293 = l_294)) &
                         (safe_rshift_func_uint16_t_u_s(0x2310L, 10))),
                        ((g_30 ^
                          ((l_289 &=
                            (l_295 !=
                             ((((g_184 =
                                     ((g_183 &
                                       ((~((((l_311, (p_87 ^ g_238.f3)) >
                                             p_87) != 0x2A7A2EF32379F2B3LL) !=
                                           l_284)) &&
                                        l_295)) &&
                                      l_295)) >= 0L),
                               0x1AL) |
                              0x83L))) >= g_238.f2)) != p_87)) <= l_296) &&
                      (-1L)) ||
                     g_238.f1),
                    g_66)) |
              1UL)) > 5L) ^
           0xDF8CL);
    } else {
      g_238.f2 = (-4L);
      for (l_300 = (-19); (l_300 > 10);
           l_300 = safe_add_func_uint16_t_u_u(l_300, 6)) {
        g_238 = l_314;
      }
    }
  }
  return p_87;
}

static uint8_t func_94(int16_t p_95, struct S0 p_96, int16_t p_97) {
  uint32_t l_120 = 0xA7EABDE2L;
  int32_t l_127 = 1L;
  uint64_t l_128 = 0x8893BA86ABA2F2E6LL;
  struct S1 l_139 = {7366, 6762, -28, 1126, -234, -0, 4325};
  struct S0 l_159 = {65529UL};
  uint32_t l_203 = 0UL;
  if (g_33) {
    int8_t l_126 = 0x41L;
    struct S0 l_158 = {65535UL};
    int32_t l_162 = (-1L);
    int8_t l_181 = 0x56L;
    int32_t l_206 = 0x501F8A61L;
    int32_t l_207 = 1L;
    int32_t l_209 = 0L;
    int32_t l_210 = 0x9105A86EL;
    int32_t l_211 = 0L;
    uint16_t l_214 = 0xEB0AL;
    struct S1 l_266 = {8020, 8046, -6, 1087, 99, -0, 4038};
    g_65 =
        ((func_101(
              p_97,
              (((safe_lshift_func_uint8_t_u_u(
                    (safe_lshift_func_int16_t_s_s(
                        (safe_lshift_func_int16_t_s_u(
                            ((safe_rshift_func_int8_t_s_s(
                                 (safe_rshift_func_uint16_t_u_s(
                                     ((((safe_add_func_int16_t_s_s(
                                            ((9UL == 18446744073709551614UL) &
                                             (safe_lshift_func_int8_t_s_u(
                                                 (safe_lshift_func_int16_t_s_u(
                                                     (-1L),
                                                     (65532UL != l_120))),
                                                 1))),
                                            l_120)) <=
                                        ((safe_div_func_int64_t_s_s(
                                             ((safe_mod_func_uint64_t_u_u(
                                                  (((((!2L) & (--l_128)) >
                                                     ((safe_mod_func_uint32_t_u_u(
                                                          (safe_lshift_func_int16_t_s_u(
                                                              ((((safe_add_func_int32_t_s_s(
                                                                     l_120,
                                                                     1UL)) |
                                                                 l_127),
                                                                1L) ||
                                                               l_126),
                                                              p_95)),
                                                          p_96.f0)) >=
                                                      p_96.f0)) >= p_96.f0) &
                                                   g_33),
                                                  g_37)) &&
                                              g_67),
                                             0xCC1C6A88B8388ADFLL)) >= l_120)),
                                       g_67) < g_39),
                                     13)),
                                 3)) &&
                             l_126),
                            4)),
                        g_32)),
                    6)) <= l_126) != 1UL)) >= g_66) <= g_30);
    l_127 =
        ((((l_139, 0xCFL) <= (g_21.f0 == (0xFF4B716CAE9C981CLL < l_126))) <=
          (0x1CL <
           ((g_66, l_126),
            ((safe_sub_func_int16_t_s_s(
                 (safe_add_func_uint32_t_u_u(
                     ((safe_add_func_uint16_t_u_u(0xAF64L, g_21.f0)) != p_95),
                     p_97)),
                 0x92ADL)) < p_97)))) |
         0xFAL);
    for (g_21.f0 = 0; (g_21.f0 != 25);
         g_21.f0 = safe_add_func_int64_t_s_s(g_21.f0, 8)) {
      uint32_t l_163 = 0UL;
      int32_t l_168 = 0x35FECE65L;
      int32_t l_185 = 1L;
      int32_t l_186 = 0xCCA4C161L;
      int32_t l_187 = 5L;
      g_182 ^=
          (g_12 ==
           ((safe_mod_func_int16_t_s_s(
                ((safe_div_func_uint64_t_u_u(
                     ((0x23B04249L >=
                       (safe_mod_func_uint64_t_u_u(
                           (((safe_rshift_func_int16_t_s_s(
                                 ((((l_159 = l_158), l_159),
                                   (safe_lshift_func_uint16_t_u_s(
                                       (++l_163),
                                       (safe_mod_func_uint32_t_u_u(
                                           l_168,
                                           (safe_div_func_int32_t_s_s(
                                               (g_66 >
                                                ((p_96.f0 |=
                                                  (safe_sub_func_uint64_t_u_u(
                                                      (safe_add_func_int32_t_s_s(
                                                          (65530UL |
                                                           (safe_div_func_uint8_t_u_u(
                                                               (safe_sub_func_uint16_t_u_u(
                                                                   0x88AFL,
                                                                   (safe_add_func_int16_t_s_s(
                                                                       (((l_158 =
                                                                              g_21),
                                                                         (-10L)) &
                                                                        0xC4A096ABL),
                                                                       0xBEFCL)))),
                                                               g_39))),
                                                          l_181)),
                                                      g_65))) ^
                                                 0x3F1CL)),
                                               0xBE4CFF9CL))))))) < l_162),
                                 7)) |
                             l_139.f2) ||
                            g_69),
                           p_97))) != 0x1A2308598B864A24LL),
                     l_139.f5)) < 1L),
                0x8ABAL)) < p_97));
      --g_188;
      g_191++;
    }
    if (p_95) {
      struct S0 l_200 = {0x8CAFL};
      int32_t l_205 = (-1L);
      int32_t l_208 = 0x15D7F043L;
      uint16_t l_215 = 0xEBE3L;
      struct S1 l_237 = {4888, 4404, -28, 3688, -181, 0, 4061};
      int32_t l_239 = 0x45497A7BL;
      for (l_128 = 14; (l_128 == 54); l_128++) {
        uint16_t l_196 = 1UL;
        l_196--;
        l_200 = g_199;
      }
      l_127 =
          (((safe_sub_func_uint8_t_u_u(l_203, (g_67, p_96.f0))) <
            ((l_215 = (l_139.f4 &=
                       (+((((-1L) &
                            ((0xAFL <
                              (((g_188 ==
                                 ((((l_139.f2 = (l_205 = (p_96, 8L))) <=
                                    ((((((g_39++) ^ p_95) >= l_200.f0), g_21),
                                      g_21.f0) ^
                                     (-7L))) > p_97) ^
                                  p_95)),
                                18446744073709551613UL) > g_37)) ^
                             l_200.f0)) &&
                           l_214) != 0x8890B9DDL)))) <= l_158.f0)),
           l_139.f1);
      g_238 =
          ((((((safe_mod_func_uint8_t_u_u(
                   (((safe_rshift_func_uint16_t_u_s(
                         ((g_191 = (safe_lshift_func_int16_t_s_s(
                               (((((((safe_sub_func_int32_t_s_s(
                                         ((((((safe_rshift_func_int16_t_s_s(
                                                  (+(p_95 && (g_66 = (-1L)))),
                                                  (p_97 = g_65))) &&
                                              (((safe_mod_func_uint16_t_u_u(
                                                    l_215,
                                                    (safe_lshift_func_uint8_t_u_s(
                                                        ((p_96.f0, 1L),
                                                         (0x34L !=
                                                          (safe_lshift_func_int8_t_s_s(
                                                              (safe_mod_func_uint64_t_u_u(
                                                                  (p_95 >=
                                                                   (safe_add_func_uint64_t_u_u(
                                                                       (g_32 ==
                                                                        4294967290UL),
                                                                       p_95))),
                                                                  p_96.f0)),
                                                              l_139.f5)))),
                                                        5)))) |
                                                l_205) &
                                               0x8900E08CL)) ||
                                             g_39) ||
                                            p_95) <= 0x3DL) < g_67),
                                         g_67)) |
                                     0xBFBDL) < g_199.f0) > l_210) != p_96.f0) |
                                 g_21.f0) <= 0xDC97BAAAL),
                               4))) ||
                          g_37),
                         g_67)) |
                     g_33) == l_211),
                   g_183)) ^
               l_215) ^
              p_95) ||
             1L),
            l_203),
           l_237);
      g_241++;
    } else {
      uint32_t l_265 = 0x211A307CL;
      g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(
                       255UL, (safe_rshift_func_uint8_t_u_s(g_39, 2)))) &
                   (safe_sub_func_int16_t_s_s(l_139.f2, 1L)));
      g_65 &= (p_96, l_139.f0);
      l_207 ^=
          (l_139.f5 =
               (g_238.f2 = (safe_div_func_int32_t_s_s(
                    ((((safe_sub_func_uint16_t_u_u(
                           l_158.f0,
                           (((0x5DL > g_65) !=
                             (safe_unary_minus_func_int16_t_s(1L))) ==
                            ((((((l_203 >
                                  (safe_lshift_func_int16_t_s_u(
                                      ((safe_lshift_func_uint16_t_u_u(0xCBFBL,
                                                                      6)) <
                                       (safe_add_func_uint32_t_u_u(
                                           (((safe_sub_func_uint64_t_u_u(
                                                 ((((p_96 = p_96),
                                                    0xA2463E9B3E846025LL),
                                                   (safe_div_func_int32_t_s_s(
                                                       g_37, 0x810FC398L))) |
                                                  l_265),
                                                 p_97)) ^
                                             l_265) ||
                                            g_12),
                                           g_21.f0))),
                                      g_188))) ^
                                 l_265) >= l_265),
                               l_266),
                              249UL),
                             p_95)))) >= 5L) >= 255UL),
                     l_139.f6),
                    p_95))));
    }
  } else {
    struct S0 l_267 = {0xB8F5L};
    l_267 = (g_21.f0, l_159);
    p_96 = p_96;
  }
  return g_241;
}

static int64_t func_101(int32_t p_102, uint16_t p_103) { return g_66; }

int main(int argc, char *argv[]) {
  int print_hash_value = 0;
  if (argc == 2 && strcmp(argv[1], "1") == 0)
    print_hash_value = 1;
  platform_main_begin();
  crc32_gentab();
  func_1();
  transparent_crc(g_12, "g_12", print_hash_value);
  transparent_crc(g_13, "g_13", print_hash_value);
  transparent_crc(g_21.f0, "g_21.f0", print_hash_value);
  transparent_crc(g_30, "g_30", print_hash_value);
  transparent_crc(g_32, "g_32", print_hash_value);
  transparent_crc(g_33, "g_33", print_hash_value);
  transparent_crc(g_36, "g_36", print_hash_value);
  transparent_crc(g_37, "g_37", print_hash_value);
  transparent_crc(g_38, "g_38", print_hash_value);
  transparent_crc(g_39, "g_39", print_hash_value);
  transparent_crc(g_65, "g_65", print_hash_value);
  transparent_crc(g_66, "g_66", print_hash_value);
  transparent_crc(g_67, "g_67", print_hash_value);
  transparent_crc(g_69, "g_69", print_hash_value);
  transparent_crc(g_80, "g_80", print_hash_value);
  transparent_crc(g_182, "g_182", print_hash_value);
  transparent_crc(g_183, "g_183", print_hash_value);
  transparent_crc(g_184, "g_184", print_hash_value);
  transparent_crc(g_188, "g_188", print_hash_value);
  transparent_crc(g_191, "g_191", print_hash_value);
  transparent_crc(g_199.f0, "g_199.f0", print_hash_value);
  transparent_crc(g_238.f0, "g_238.f0", print_hash_value);
  transparent_crc(g_238.f1, "g_238.f1", print_hash_value);
  transparent_crc(g_238.f2, "g_238.f2", print_hash_value);
  transparent_crc(g_238.f3, "g_238.f3", print_hash_value);
  transparent_crc(g_238.f4, "g_238.f4", print_hash_value);
  transparent_crc(g_238.f5, "g_238.f5", print_hash_value);
  transparent_crc(g_238.f6, "g_238.f6", print_hash_value);
  transparent_crc(g_240, "g_240", print_hash_value);
  transparent_crc(g_241, "g_241", print_hash_value);
  transparent_crc(g_301, "g_301", print_hash_value);
  transparent_crc(g_315, "g_315", print_hash_value);
  transparent_crc(g_322, "g_322", print_hash_value);
  transparent_crc(g_377, "g_377", print_hash_value);
  transparent_crc(g_378, "g_378", print_hash_value);
  transparent_crc(g_524, "g_524", print_hash_value);
  transparent_crc(g_527, "g_527", print_hash_value);
  transparent_crc(g_528, "g_528", print_hash_value);
  transparent_crc(g_571, "g_571", print_hash_value);
  transparent_crc(g_586, "g_586", print_hash_value);
  transparent_crc(g_620, "g_620", print_hash_value);
  transparent_crc(g_756, "g_756", print_hash_value);
  transparent_crc(g_791, "g_791", print_hash_value);
  transparent_crc(g_792, "g_792", print_hash_value);
  transparent_crc(g_793, "g_793", print_hash_value);
  transparent_crc(g_800, "g_800", print_hash_value);
  transparent_crc(g_801, "g_801", print_hash_value);
  transparent_crc(g_873, "g_873", print_hash_value);
  transparent_crc(g_928, "g_928", print_hash_value);
  transparent_crc(g_967, "g_967", print_hash_value);
  transparent_crc(g_968, "g_968", print_hash_value);
  transparent_crc(g_993, "g_993", print_hash_value);
  transparent_crc(g_1249, "g_1249", print_hash_value);
  transparent_crc(g_1276, "g_1276", print_hash_value);
  transparent_crc(g_1285, "g_1285", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}
