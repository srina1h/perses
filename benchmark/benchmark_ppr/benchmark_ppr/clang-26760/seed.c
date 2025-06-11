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

static const uint8_t g_18 = 0x96L;
static uint32_t g_22 = 18446744073709551615UL;
static uint8_t g_59 = 0x26L;
static int8_t g_89 = 0xE8L;
static int8_t g_97[7] = {0x9AL, 0x9AL, 0x9AL, 0x9AL, 0x9AL, 0x9AL, 0x9AL};
static int8_t g_100 = 0x2FL;
static int16_t g_101 = 0x8DB7L;
static int32_t g_120[5] = {0x9873F28DL, 0x9873F28DL, 0x9873F28DL, 0x9873F28DL,
                           0x9873F28DL};
static uint32_t g_143 = 4294967295UL;
static int16_t g_540 = 0xE6F4L;
static int16_t g_694 = 0L;
static int8_t g_717 = 0x46L;
static uint32_t g_777 = 0xDDF76E03L;
static uint32_t g_849[1] = {0xBCE5A530L};
static int16_t g_935 = (-1L);
static uint32_t g_1168 = 0x7D4DB357L;
static uint8_t g_1171 = 7UL;
static uint16_t g_1217 = 0xB6F3L;
static int32_t g_1368[3] = {(-2L), (-2L), (-2L)};
static int16_t g_1482[4][3][4] = {{{0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L}},
                                  {{0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L}},
                                  {{0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L}},
                                  {{0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L},
                                   {0L, 1L, (-1L), 0x7568L}}};
static int32_t g_1540[6][2] = {{3L, (-8L)}, {3L, (-8L)}, {3L, (-8L)},
                               {3L, (-8L)}, {3L, (-8L)}, {3L, (-8L)}};
static int32_t g_1548[10][8][3] = {{{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}},
                                   {{6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL},
                                    {6L, 1L, 0x1E78C61EL}}};
static int8_t g_2003[6] = {8L, 0x85L, 8L, 0x85L, 8L, 0x85L};
static int32_t g_2100 = (-1L);
static int16_t g_2184[3][3] = {{0xC198L, 0x0844L, 0xC198L},
                               {0xC198L, 0x0844L, 0xC198L},
                               {0xC198L, 0x0844L, 0xC198L}};
static int16_t g_2254 = (-10L);
static uint16_t g_2414 = 2UL;
static uint8_t g_2431 = 1UL;
static uint32_t g_2467 = 0x7A51E780L;
static const int32_t g_2468 = 0x6A00EF02L;
static int32_t g_2469 = 1L;
static int32_t g_2470[3][1][10] = {{{0xD1D11586L, (-1L), (-6L), (-6L), (-1L),
                                     0xD1D11586L, (-1L), (-6L), (-6L), (-1L)}},
                                   {{0xD1D11586L, (-1L), (-6L), (-6L), (-1L),
                                     0xD1D11586L, (-1L), (-6L), (-6L), (-1L)}},
                                   {{0xD1D11586L, (-1L), (-6L), (-6L), (-1L),
                                     0xD1D11586L, (-1L), (-6L), (-6L), (-1L)}}};

static uint16_t func_1(void);
static int32_t func_3(int32_t p_4, uint16_t p_5, int32_t p_6, uint8_t p_7,
                      uint32_t p_8);
static int16_t func_10(uint32_t p_11, uint8_t p_12, int32_t p_13);
static int32_t func_19(int16_t p_20);
static int16_t func_25(uint16_t p_26);
static int16_t func_28(int32_t p_29, int32_t p_30);
static int16_t func_33(uint32_t p_34, int16_t p_35);
static int16_t func_38(int32_t p_39, int8_t p_40, uint16_t p_41, int16_t p_42,
                       uint16_t p_43);
static int32_t func_46(uint8_t p_47, uint16_t p_48, int16_t p_49, uint8_t p_50,
                       uint16_t p_51);
static int16_t func_54(int32_t p_55, const uint32_t p_56, int8_t p_57,
                       uint8_t p_58);
static uint16_t func_1(void) {
  uint32_t l_2[1];
  int16_t l_9 = 0x4210L;
  int i;
  for (i = 0; i < 1; i++)
    l_2[i] = 0xB50BF34FL;
  l_2[0] = 0xA8EAC8B1L;
  g_120[1] = func_3(l_9,
                    (func_10(l_2[0],
                             ((safe_lshift_func_uint16_t_u_u(
                                  (safe_add_func_uint16_t_u_u(g_18, l_2[0])),
                                  (func_19(l_2[0]),
                                   (((g_1171 < g_120[1]) != g_89) & l_2[0])))),
                              l_9),
                             g_1368[1]) != g_1168),
                    l_2[0], g_1168, g_1540[1][0]);
  return g_1548[4][3][1];
}

static int32_t func_3(int32_t p_4, uint16_t p_5, int32_t p_6, uint8_t p_7,
                      uint32_t p_8) {
  const uint8_t l_2352 = 0UL;
  int16_t l_2357 = 0xCDFDL;
  int8_t l_2397 = (-6L);
  int32_t l_2415 = 5L;
  int32_t l_2421 = 0x1502036FL;
  int32_t l_2429[1];
  uint16_t l_2465 = 0UL;
  uint8_t l_2515 = 0x8DL;
  int i;
  for (i = 0; i < 1; i++)
    l_2429[i] = 0xDAD1BFA1L;
  for (g_717 = (-20); (g_717 <= 1); ++g_717) {
    int8_t l_2362 = 0xDCL;
    uint16_t l_2371 = 0UL;
    int32_t l_2376 = 1L;
    uint32_t l_2398[6][5];
    int32_t l_2418 = 8L;
    int32_t l_2419 = (-1L);
    int32_t l_2420 = 0xB04F07EDL;
    uint32_t l_2422 = 0x9AA580D4L;
    int32_t l_2511 = 1L;
    int32_t l_2512[4][8][3] = {{{0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L}},
                               {{0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L}},
                               {{0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L}},
                               {{0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L},
                                {0x23D4EB6DL, 0x23D4EB6DL, 0L}}};
    int16_t l_2514[7][2] = {
        {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L},
        {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}};
    int i, j, k;
    for (i = 0; i < 6; i++) {
      for (j = 0; j < 5; j++)
        l_2398[i][j] = 1UL;
    }
    p_4 =
        ((l_2352 <= g_1548[9][4][0]) &
         (safe_add_func_int16_t_s_s(
             g_89,
             (safe_mul_func_uint32_t_u_u(
                 4294967295UL,
                 ((l_2357 &&
                   (((safe_add_func_int16_t_s_s(
                         (safe_lshift_func_uint16_t_u_u(
                             l_2362,
                             ((((((safe_rshift_func_uint16_t_u_s(
                                      ((safe_add_func_uint32_t_u_u(
                                           (safe_sub_func_int8_t_s_s(
                                               ((((safe_rshift_func_int16_t_s_u(
                                                      ((l_2357 <= g_849[0]) !=
                                                       l_2357),
                                                      p_8)) ^
                                                  l_2362) == g_1368[1]) ^
                                                0x92AB813CL),
                                               0x59L)),
                                           p_7)) &
                                       l_2362),
                                      8)) >= g_59),
                                 l_2357) ^
                                (-8L)) &&
                               0L) != g_143))),
                         p_4)) == 0x1DE1FACEL) == l_2371)) != 1L))))));
    l_2376 = ((safe_mod_func_int32_t_s_s(
                  g_101, (safe_add_func_uint32_t_u_u((p_5 <= 0xDBA3D591L),
                                                     g_1168)))) < l_2357);
    for (g_1168 = 0; (g_1168 >= 36); g_1168++) {
      uint32_t l_2389 = 0UL;
      int32_t l_2417[8] = {1L, 1L, 0x595B0FA1L, 1L, 1L, 0x595B0FA1L, 1L, 1L};
      int16_t l_2504 = 5L;
      int32_t l_2505[8][2][3] = {
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}},
          {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}};
      int16_t l_2513 = 1L;
      int i, j, k;
      for (g_1171 = 0; (g_1171 <= 44);
           g_1171 = safe_add_func_int8_t_s_s(g_1171, 2)) {
        uint32_t l_2381 = 1UL;
        int32_t l_2416[6];
        uint32_t l_2436 = 0x4366B639L;
        uint32_t l_2466 = 0x760CFC11L;
        int32_t l_2502 = 0x2781DDD3L;
        int i;
        for (i = 0; i < 6; i++)
          l_2416[i] = 5L;
        if (((l_2381 > p_4) ||
             (safe_add_func_uint16_t_u_u(
                 ((((((((~p_6) !=
                        ((safe_add_func_int32_t_s_s(
                             (safe_sub_func_uint32_t_u_u(
                                 g_2184[2][0], (l_2389 == (p_5 < l_2362)))),
                             (p_7 > (safe_sub_func_int8_t_s_s(
                                        (safe_mod_func_int32_t_s_s(
                                            (+((((safe_rshift_func_int16_t_s_u(
                                                     (l_2381 && (-1L)),
                                                     g_694)) == 0UL) < l_2362),
                                               g_97[2])),
                                            0xE2D14996L)),
                                        l_2381))))) ^
                         l_2397)) &&
                       p_5) &&
                      0x6F70B1C1L) != l_2389),
                    0UL) == l_2357) == l_2389),
                 l_2398[3][4])))) {
          int32_t l_2413 = 0L;
          int32_t l_2425 = 0x8DE3555FL;
          int32_t l_2427 = 1L;
          int32_t l_2428 = (-2L);
          if ((safe_sub_func_int32_t_s_s(
                  (l_2362, ((~g_2003[4]) != p_4)),
                  (safe_lshift_func_uint16_t_u_s(
                      (safe_unary_minus_func_int32_t_s(g_2003[0])), 6))))) {
            p_4 = p_5;
            l_2376 =
                (((safe_sub_func_uint32_t_u_u(
                      2UL,
                      (((safe_add_func_uint8_t_u_u(
                            (safe_sub_func_int16_t_s_s(
                                (((p_5, (0x2E78BE00L <=
                                         (((safe_mod_func_int32_t_s_s(
                                               (g_2184[1][1] >
                                                ((l_2413 ^
                                                  (1L > ((((0x544EL ^ p_4),
                                                           (g_1168 == p_4)),
                                                          l_2398[1][1]) <
                                                         g_97[5]))) == l_2413)),
                                               4294967295UL)) &
                                           p_7) ||
                                          g_89))) &
                                  l_2352) &&
                                 p_4),
                                65526UL)),
                            g_2254)),
                        (-1L)) |
                       g_2414))) == p_8) <= p_5);
            if (p_5)
              break;
          } else {
            if (l_2413)
              break;
            if (g_1482[2][1][1])
              continue;
          }
          l_2422--;
          for (l_2420 = 6; (l_2420 >= 1); l_2420 -= 1) {
            int32_t l_2426 = (-1L);
            int32_t l_2430 = (-1L);
            int i;
            l_2417[(l_2420 + 1)] = g_97[l_2420];
            g_2431--;
          }
        } else {
          if (l_2416[5])
            break;
          for (p_6 = 0; (p_6 == 24); p_6 = safe_add_func_int32_t_s_s(p_6, 5)) {
            return p_5;
          }
        }
                g_2470[0][0][5] &= (0x39A6L >= (l_2436 , (safe_add_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(p_4, (safe_sub_func_int32_t_s_s(l_2418, (safe_sub_func_uint32_t_u_u(((g_101 , (((safe_mod_func_uint32_t_u_u((((safe_add_func_int16_t_s_s(((((safe_add_func_uint16_t_u_u((((0UL | ((((((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint8_t_u_u((((((safe_lshift_func_int8_t_s_s((p_4 , ((safe_mod_func_int16_t_s_s(((p_7 > ((safe_rshift_func_int16_t_s_s(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(g_777, l_2465)), l_2371)) || 6UL), 7)) < 0x2256L)) < 0x4FL), g_1482[2][2][1])) > 0x8C0EL)), 5)) && 255UL) , l_2417[0]) || g_777) != p_5), g_120[1])) <= p_4), l_2466)) ^ p_8) , g_100) != p_7) != g_2467) & l_2417[0])) , l_2416[3]) && l_2418), p_6)) > 0x8D34L) , p_4) <= l_2436), l_2389)) , g_2468) < 6UL), 0xBA6FA250L)) , g_2469) , p_8)) , l_2398[2][1]), p_8)))))), p_5))));
                for (l_2420 = (-4); (l_2420 < (-28));
                     l_2420 = safe_sub_func_int32_t_s_s(l_2420, 2)) {
                  uint16_t l_2499 = 0x99C0L;
                  int32_t l_2501 = 0xEDED4BBBL;
                  int32_t l_2503 = (-1L);
                  int32_t l_2506 = 0L;
                  int32_t l_2507 = (-1L);
                  uint16_t l_2508 = 0xF71CL;
                  if (((((safe_rshift_func_int8_t_s_u(
                             (+p_5),
                             (safe_add_func_int32_t_s_s(
                                 (l_2417[7] ==
                                  ((l_2417[6] || p_5) |
                                   ((safe_lshift_func_uint8_t_u_s(
                                        l_2420,
                                        (((safe_lshift_func_uint16_t_u_s(
                                              0x21DFL, p_6)) > g_2431) ==
                                         (safe_mod_func_int32_t_s_s(
                                             ((safe_add_func_uint8_t_u_u(
                                                  l_2417[6], 0L)) &
                                              p_8),
                                             p_8))))) &
                                    p_4))),
                                 2L)))) == g_935),
                        g_1540[1][0]) ^
                       l_2417[6])) {
                    int16_t l_2498 = 0x1DD5L;
                    int32_t l_2500[5][8] = {
                        {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L},
                        {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L},
                        {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L},
                        {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L},
                        {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L}};
                    int i, j;
                    l_2500[1][4] &= (~(
                        l_2417[6] !=
                        (1UL <
                         ((p_5 <
                           (((p_6 <=
                              ((safe_add_func_int8_t_s_s(
                                   (-4L),
                                   ((((((((~((1UL ^
                                              ((safe_lshift_func_uint16_t_u_s(
                                                   (safe_sub_func_int16_t_s_s(
                                                       l_2397,
                                                       ((safe_sub_func_int32_t_s_s(
                                                            (safe_mod_func_uint16_t_u_u(
                                                                l_2498,
                                                                l_2466)),
                                                            (-10L))) != 0UL))),
                                                   p_8)) &
                                               l_2418)) == g_2003[3])) ^
                                          g_1168) >= l_2418) > 1L),
                                       p_8),
                                      p_8),
                                     0x1FL) &
                                    p_4))) == 0x1FFFL)),
                             (-1L)) ^
                            65535UL)) &&
                          l_2499))));
                    ++l_2508;
                    l_2418 &= g_59;
                    return l_2429[0];
                  } else {
                    return l_2371;
                  }
                }
      }
      l_2515++;
      if (p_5) {
        uint32_t l_2518 = 0x2412710BL;
        --l_2518;
      } else {
        uint16_t l_2528[2][10] = {
            {6UL, 6UL, 0UL, 0UL, 65535UL, 0UL, 0UL, 6UL, 6UL, 0UL},
            {6UL, 6UL, 0UL, 0UL, 65535UL, 0UL, 0UL, 6UL, 6UL, 0UL}};
        uint32_t l_2534[6][5] = {
            {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL},
            {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL},
            {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL},
            {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL},
            {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL},
            {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}};
        int i, j;
        p_4 =
            (1UL ==
             ((((((safe_lshift_func_int16_t_s_s(
                      ((((((((((safe_rshift_func_uint16_t_u_s(
                                   (g_2254 &
                                    (safe_unary_minus_func_uint8_t_u((
                                        p_5 ||
                                        ((safe_add_func_uint32_t_u_u(
                                             (((l_2528[0][8] ==
                                                (((+l_2429[0]) <
                                                  (((safe_lshift_func_int8_t_s_s(
                                                        0x1BL, 3)) <
                                                    ((((safe_mod_func_uint32_t_u_u(
                                                           (((l_2419 ==
                                                              (l_2534[5][3] >=
                                                               g_2470[0][0]
                                                                     [5])) <=
                                                             l_2534[1][2]) ==
                                                            l_2534[3][0]),
                                                           4294967290UL)) !=
                                                       l_2429[0]) > 1UL) <=
                                                     p_6)) ||
                                                   4294967286UL)) ^
                                                 0x64L)) == 0xE152L) &&
                                              g_1548[4][6][2]),
                                             l_2534[0][2])),
                                         (-1L)))))),
                                   p_4)) &
                               g_849[0]) ||
                              4294967294UL) > 0x45B2L),
                            p_6) < 0x77B3L) &&
                          g_1368[1]) &
                         1L) &
                        g_1171) &
                       0x24A1L),
                      l_2534[2][4])) &&
                  l_2398[3][4]),
                 l_2528[1][4]) == g_2100),
               l_2515),
              7L));
        for (g_100 = 0; (g_100 < 17); ++g_100) {
          for (g_777 = 0; (g_777 <= 4); g_777 += 1) {
            if (l_2417[6])
              break;
            g_120[0] = ((safe_unary_minus_func_int32_t_s((-3L))) >= 0x8490L);
          }
          if (g_2470[0][0][5])
            continue;
        }
      }
    }
    l_2429[0] =
        ((safe_add_func_uint32_t_u_u(
             (p_4 < 0xCEDAL),
             (safe_add_func_int16_t_s_s(
                 (safe_unary_minus_func_uint32_t_u(0x5F6C668FL)),
                 (+(safe_sub_func_uint32_t_u_u(
                     (l_2515 <=
                      ((+(((safe_unary_minus_func_int32_t_s(
                               (safe_add_func_uint8_t_u_u(
                                   p_8,
                                   (safe_mod_func_int32_t_s_s(
                                       (0x9434C9EBL ^
                                        (safe_add_func_uint16_t_u_u(
                                            (((g_2100 &&
                                               (g_1168 <
                                                (safe_lshift_func_uint16_t_u_s(
                                                    (((l_2397 < 0x8FL) && p_6) <
                                                     p_8),
                                                    l_2429[0])))) ^
                                              0xE70B22DFL) == g_849[0]),
                                            0xF98EL))),
                                       0xFC9ABC26L)))))) &&
                           g_1540[1][0]),
                          4294967292UL)) |
                       p_4)),
                     l_2357))))))) < 65535UL);
  }
  return l_2465;
}

static int16_t func_10(uint32_t p_11, uint8_t p_12, int32_t p_13) {
  const int32_t l_1494 = 1L;
  int32_t l_1549 = 3L;
  int32_t l_1648 = (-7L);
  int32_t l_1651 = 0x03FC532BL;
  uint32_t l_1671 = 0x5D19C228L;
  int32_t l_1693 = 6L;
  int32_t l_1694 = 0x93E56D52L;
  int32_t l_1695 = (-8L);
  int32_t l_1696[1];
  int32_t l_1698 = 0x373FD168L;
  int16_t l_1726 = 0x18DBL;
  int8_t l_1888[4] = {(-1L), 0xDAL, (-1L), 0xDAL};
  const int32_t l_2028 = 0L;
  uint32_t l_2050 = 0xE1AEC0EFL;
  int32_t l_2055 = 0x3AFF1B97L;
  int32_t l_2141[2][9][9] = {{{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L}},
                             {{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L},
                              {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L,
                               0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}};
  int32_t l_2178[3];
  int16_t l_2182 = 0L;
  int32_t l_2325 = 0xDDB3E8D8L;
  uint32_t l_2326 = 4UL;
  int i, j, k;
  for (i = 0; i < 1; i++)
    l_1696[i] = (-1L);
  for (i = 0; i < 3; i++)
    l_2178[i] = 0xA248903FL;
  for (g_717 = (-17); (g_717 != (-29)); g_717--) {
    int32_t l_1489[4][8][8] = {
        {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}},
        {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}},
        {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}},
        {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL},
         {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}};
    uint32_t l_1504 = 0x5BA9BBE8L;
    uint8_t l_1505 = 0xECL;
    int32_t l_1537 = 0L;
    int32_t l_1639 = (-1L);
    int32_t l_1644[7][7][5] = {
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}},
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}},
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}},
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}},
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}},
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}},
        {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL},
         {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}};
    int32_t l_1705 = 0x5B922F92L;
    const int32_t l_1724 = (-1L);
    int8_t l_1725 = (-7L);
    uint16_t l_1799[5][6];
    int32_t l_1842 = 1L;
    int8_t l_1854 = 1L;
    uint32_t l_1887 = 0x40D66011L;
    uint32_t l_1905 = 5UL;
    int8_t l_1931[6] = {(-1L), (-1L), 1L, (-1L), (-1L), 1L};
    uint8_t l_2006 = 255UL;
    int i, j, k;
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 6; j++)
        l_1799[i][j] = 65535UL;
    }
    l_1489[2][4][7] |= (safe_rshift_func_uint16_t_u_s(
        g_694, (safe_add_func_int8_t_s_s(0x34L, 0x31L))));
    g_120[2] =
        (((((((safe_add_func_int16_t_s_s(
                  (((p_12, 0xE95DL) !=
                    ((((safe_rshift_func_uint8_t_u_s((l_1489[3][4][7] > 0x91L),
                                                     3)) &
                       ((l_1494 >=
                         (((safe_lshift_func_uint8_t_u_s(g_18, 5)) &
                           (((safe_sub_func_uint16_t_u_u(
                                 (l_1494 |
                                  (((safe_sub_func_uint8_t_u_u(
                                        (((safe_sub_func_int8_t_s_s(
                                              (((l_1489[2][4][7] ==
                                                 (+(((g_59 || p_12) ^ p_13) <
                                                    l_1504))) > 8UL) !=
                                               4294967286UL),
                                              0xBAL)) != p_11),
                                         246UL),
                                        g_1482[2][0][1])) ^
                                    l_1504) > p_13)),
                                 g_1368[0])) ^
                             l_1504) <= 4294967295UL)) &&
                          0x59L)) < l_1489[0][5][2])),
                      (-10L)) &
                     0xF980F758L)) ^
                   g_777),
                  g_1171)) == 1UL) >= g_97[3]) > l_1504) > p_13) > l_1505) >=
         p_12);
    if (l_1494)
      break;
    for (g_1217 = (-15); (g_1217 != 6); g_1217++) {
      const uint32_t l_1522[6][9] = {
          {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L,
           0x38E53B65L, 0x7C2D2C19L, 2UL},
          {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L,
           0x38E53B65L, 0x7C2D2C19L, 2UL},
          {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L,
           0x38E53B65L, 0x7C2D2C19L, 2UL},
          {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L,
           0x38E53B65L, 0x7C2D2C19L, 2UL},
          {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L,
           0x38E53B65L, 0x7C2D2C19L, 2UL},
          {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L,
           0x38E53B65L, 0x7C2D2C19L, 2UL}};
      uint16_t l_1591 = 7UL;
      int32_t l_1599 = 0x10CC3626L;
      int16_t l_1633 = 0x164AL;
      int32_t l_1634 = 0x157EBADBL;
      int32_t l_1643[6][4][8] = {
          {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL}},
          {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL}},
          {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL}},
          {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL}},
          {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL}},
          {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL},
           {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL,
            0xBFED9D93L, 0x29968C4FL}}};
      uint32_t l_1659 = 0x83EA5D3CL;
      uint32_t l_1699 = 0x2C42C799L;
      uint16_t l_1706 = 0x0899L;
      int32_t l_1806 = 0x9CB7724BL;
      uint32_t l_1837 = 3UL;
      uint32_t l_1846 = 0xD008E7A8L;
      int i, j, k;
      if (((!(safe_add_func_int32_t_s_s(
               (p_11 || p_11),
               ((((safe_lshift_func_int16_t_s_u(
                      ((safe_lshift_func_int8_t_s_s(
                           (0x15L <=
                            (g_1171 <=
                             ((safe_add_func_uint16_t_u_u(
                                  (!g_849[0]),
                                  ((((safe_sub_func_int32_t_s_s(
                                         ((((p_12,
                                             ((p_12 |
                                               ((((((safe_sub_func_uint8_t_u_u(
                                                        (g_1368[1] <=
                                                         l_1489[2][7][0]),
                                                        (-1L))) ^
                                                    g_101) |
                                                   g_143),
                                                  255UL),
                                                 p_11) < g_120[0])) < p_12)) ^
                                            l_1494),
                                           l_1522[4][1]) < g_540),
                                         4294967295UL)) != 0x6AL) ||
                                    g_18) >= p_11))) < l_1505))),
                           g_100)),
                       0x5997L),
                      p_11)) <= g_100),
                 l_1522[0][5]) <= p_13)))) == l_1522[4][1])) {
        uint32_t l_1543 = 7UL;
        int32_t l_1547 = (-6L);
        int32_t l_1640 = 0x4E27C546L;
        int32_t l_1641 = 1L;
        int32_t l_1646 = 0xFBA92B18L;
        int32_t l_1647 = 0xBA2A75F3L;
        int32_t l_1649 = 0L;
        int32_t l_1650 = (-1L);
        int32_t l_1652 = (-1L);
        int32_t l_1654 = (-5L);
        int32_t l_1655 = 0L;
        int32_t l_1697 = 0L;
        for (p_11 = 5; (p_11 != 57); ++p_11) {
          int32_t l_1533[2][4] = {
              {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L},
              {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
          int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}},
                                     {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L},
                                      {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
          int i, j, k;
          if (((0UL <= (safe_rshift_func_int8_t_s_u(p_12, 5))) &
               (((((((p_13, ((safe_add_func_int32_t_s_s(
                                 0L, (safe_mod_func_int8_t_s_s(
                                         (safe_rshift_func_uint16_t_u_u(
                                             (((p_13 == l_1533[1][2]) &&
                                               (((p_11 && ((l_1489[3][7][5] &
                                                            0x189D8138L) &
                                                           g_540)) ^
                                                 g_97[2]) |
                                                l_1505)) <= (-6L)),
                                             12)),
                                         0x4AL)))) &
                             l_1505)) <= p_12) == 1L) ||
                   l_1494) |
                  l_1494) > 0xA7L) &
                1L))) {
            l_1537 &=
                ((safe_rshift_func_uint8_t_u_s(
                     (((p_13 ^ (~((g_97[2] == p_13), g_1217))) |
                       (l_1522[2][7] |
                        (((g_89 || l_1505),
                          (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^
                         g_97[1]))),
                      255UL),
                     1)) &&
                 (-1L));
            g_120[2] = (safe_add_func_int32_t_s_s(g_89, g_1368[1]));
            g_120[1] = g_1540[1][0];
          } else {
            int8_t l_1541 = (-1L);
            int32_t l_1546 = 0x3C02C0E7L;
            uint32_t l_1550 = 1UL;
            l_1543++;
            if (l_1489[0][4][1])
              continue;
            --l_1550;
          }
          for (l_1537 = 10; (l_1537 >= 5);
               l_1537 = safe_sub_func_uint32_t_u_u(l_1537, 6)) {
            int16_t l_1581 = 0x4CE7L;
            if (p_11)
              break;
            g_120[1] =
                (l_1549 ||
                 (0xA427L ==
                  (safe_mod_func_uint16_t_u_u(
                      (safe_sub_func_uint32_t_u_u((g_1368[1] == 1UL), (-1L))),
                      0x2E3AL))));
            g_120[1] =
                ((+(p_12 <
                    ((((((safe_sub_func_int16_t_s_s(
                             (safe_rshift_func_uint8_t_u_s(
                                 (~g_101),
                                 ((safe_lshift_func_int8_t_s_s(
                                      l_1547,
                                      (safe_lshift_func_int16_t_s_s(
                                          (safe_lshift_func_int16_t_s_s(
                                              ((+((safe_add_func_int8_t_s_s(
                                                      (0UL !=
                                                       (((safe_rshift_func_int8_t_s_u(
                                                             (g_89 > g_1368[2]),
                                                             1)) ==
                                                         (safe_unary_minus_func_int8_t_s(
                                                             (p_11,
                                                              (safe_rshift_func_uint8_t_u_s(
                                                                  (((safe_mod_func_int8_t_s_s(
                                                                        (0x71L >=
                                                                         l_1581),
                                                                        0xB6L)),
                                                                    p_11) <=
                                                                   p_13),
                                                                  3)))))) &&
                                                        g_777)),
                                                      0UL)) ^
                                                  l_1522[0][5])) &
                                               1UL),
                                              p_11)),
                                          13)))),
                                  0x89L))),
                             p_12)) != l_1537),
                        g_1217) ||
                       65531UL) > p_13) < 0x33D41A9EL))),
                 g_59);
          }
          for (g_540 = 0; (g_540 <= 4); g_540 += 1) {
            int16_t l_1588[5][10][5] = {
                {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}},
                {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}},
                {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}},
                {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}},
                {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)},
                 {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
            const int16_t l_1592 = (-1L);
            int i, j, k;
            g_120[g_540] =
                ((safe_sub_func_int32_t_s_s(g_101, 0xC58F4B07L)) ^
                 ((((((-1L) >
                      (((((safe_add_func_int8_t_s_s(
                              ((((safe_sub_func_uint32_t_u_u(
                                     ((l_1588[4][3][4] | (0xBBL | g_97[2])) ^
                                      l_1542[2][5][1]),
                                     (p_12,
                                      (safe_lshift_func_uint16_t_u_u(
                                          ((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL),
                                          8))))) &
                                 p_11) > 7L) >= l_1591),
                              l_1588[1][8][4])) &&
                          p_11) == 1UL),
                        l_1592) &&
                       g_97[2])) ||
                     g_717) <= p_11) ||
                   g_1217) >= l_1533[1][2]));
            return l_1549;
          }
        }
        if ((((safe_rshift_func_uint8_t_u_s(l_1549, 4)) >=
              (safe_lshift_func_uint8_t_u_s(
                  l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) !=
             ((safe_lshift_func_int16_t_s_u(
                  (!(((p_12 >= l_1547),
                      ((!g_849[0]) >=
                       ((g_89 <= (!(((safe_rshift_func_uint8_t_u_u(
                                         (((safe_rshift_func_uint16_t_u_u(
                                               (((g_540 > 0L) ^ p_13) < l_1504),
                                               p_12)) ||
                                           0x729EL) > 0xD46FL),
                                         2)) < g_97[2]),
                                    6UL))) ||
                        p_12))) |
                     l_1489[2][4][7])),
                  12)) == p_12))) {
          uint16_t l_1611 = 0xD966L;
          int32_t l_1636 = 1L;
          int32_t l_1638[4][6][7] = {
              {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}},
              {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}},
              {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}},
              {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L},
               {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
          uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}},
                                     {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}},
                                     {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L},
                                      {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
          int i, j, k;
          g_120[1] =
              ((((p_11 &
                  ((safe_mul_func_uint8_t_u_u(
                       l_1611,
                       ((((l_1494 |
                           (safe_mod_func_int8_t_s_s(
                               p_13,
                               (safe_lshift_func_uint16_t_u_u(
                                   (((((((+(l_1494,
                                            ((l_1504 &
                                              (safe_lshift_func_uint16_t_u_s(
                                                  (((+(((((((g_694 <=
                                                             (((((p_13 &
                                                                  ((0x4BA9L |
                                                                    0xAB14L) ==
                                                                   0xB0E53EB1L)) ==
                                                                 0x49L) >=
                                                                g_1168) &&
                                                               p_13) <
                                                              l_1611)) >
                                                            0x891AL) ^
                                                           0xC4L) >= g_22) >
                                                         l_1599) ^
                                                        g_849[0]) < l_1591)) &
                                                    0x2C1DL) >= 0L),
                                                  14))),
                                             g_1168))) &
                                         g_101) != 0x3AL),
                                       p_12) &&
                                      g_717) ^
                                     p_13) >= p_12),
                                   1))))) &&
                          p_11) >= l_1522[4][1]) <= 0x012802EEL))) ^
                   0x6FL)) |
                 p_12) != 4294967290UL) |
               g_120[4]);
          if ((l_1489[2][4][7] <= (g_97[0] <= l_1494))) {
            int32_t l_1635 = 0L;
            int32_t l_1637 = 1L;
            int32_t l_1642 = (-3L);
            int32_t l_1645[4][10][3] = {{{0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L}},
                                        {{0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L}},
                                        {{0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L}},
                                        {{0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L},
                                         {0L, 0L, 0L}}};
            int8_t l_1653 = 0xE0L;
            int i, j, k;
            l_1634 =
                (((((safe_mod_func_uint16_t_u_u(
                        (safe_unary_minus_func_uint8_t_u(
                            (safe_sub_func_uint8_t_u_u(
                                (safe_sub_func_uint8_t_u_u(
                                    ((p_13 ^
                                      (((((safe_mod_func_uint8_t_u_u(
                                              ((((safe_add_func_uint8_t_u_u(
                                                     ((safe_mod_func_int32_t_s_s(
                                                          ((p_11 &&
                                                            (((p_12, l_1494) >
                                                              (p_13 &
                                                               g_1168)) >=
                                                             (-2L))) ==
                                                           ((-1L) &
                                                            ((0x2C2C4A06L ||
                                                              0L) != g_100))),
                                                          0x84D0E611L)) <
                                                      247UL),
                                                     l_1537)) ==
                                                 g_1540[0][1]) != 65535UL) !=
                                               (-5L)),
                                              l_1599)),
                                          g_777),
                                         l_1611) == p_12) &&
                                       9L)) >= 0x3E95L),
                                    p_13)),
                                p_11)))),
                        65530UL)) >= l_1549) |
                   0xA236F820L),
                  l_1611) < l_1633);
            l_1656[1][6][4]++;
            ++l_1659;
          } else {
            int32_t l_1692 = 1L;
            l_1671 = (((safe_mod_func_uint16_t_u_u(
                           (safe_add_func_int16_t_s_s(
                               (safe_add_func_uint32_t_u_u(
                                   (((l_1651, ((((g_935 != l_1611) >=
                                                 (safe_sub_func_uint8_t_u_u(
                                                     0xEEL, g_849[0]))) <=
                                                g_1168) != (1UL & p_12))) &&
                                     (!(l_1651 >= l_1644[2][1][0]))) ||
                                    l_1641),
                                   (-2L))),
                               1UL)),
                           g_120[1])) > 0x1BL) |
                      0xC3L);
            g_120[1] = (+1UL);
            l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(
                0UL,
                (((safe_rshift_func_uint16_t_u_u(
                      ((safe_mod_func_int16_t_s_s(
                           (safe_rshift_func_int16_t_s_u(
                               (~p_13),
                               ((0x60L ^
                                 ((l_1651 ==
                                   ((((((-1L) ==
                                        ((0x4B8FL ==
                                          (p_12 |
                                           (((6L |
                                              (safe_rshift_func_uint16_t_u_u(
                                                  ((((((((safe_lshift_func_int8_t_s_u(
                                                             ((~(((((safe_mod_func_uint16_t_u_u(
                                                                        (safe_add_func_uint32_t_u_u(
                                                                            ((!(1UL !=
                                                                                g_89)) >
                                                                             l_1522
                                                                                 [2]
                                                                                 [7]),
                                                                            g_120
                                                                                [1])),
                                                                        l_1638
                                                                            [0]
                                                                            [0]
                                                                            [2])) <
                                                                    4294967295UL),
                                                                   p_11),
                                                                  0xE3L),
                                                                 0x49L)) &&
                                                              0x109AL),
                                                             6)),
                                                         g_540) ||
                                                        4294967288UL) <
                                                       0x758ECAE5L),
                                                      p_11) > l_1692) !=
                                                    g_120[4]) == 0x90143625L),
                                                  g_120[0]))) != p_12) |
                                            g_18))) |
                                         (-1L))) > p_11) > g_694),
                                     p_11) != p_11)) < l_1692)) < g_18))),
                           p_12)) |
                       0x4510FC82L),
                      g_22)) > 2UL) != l_1643[0][3][1])));
          }
        } else {
          g_120[4] = p_11;
          if (l_1671)
            break;
        }
        ++l_1699;
      } else {
        int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
        int32_t l_1703 = (-7L);
        int32_t l_1704[7][6][6] = {
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}},
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}},
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}},
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}},
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}},
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}},
            {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L},
             {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L,
              0x841B2AA2L}}};
        uint8_t l_1730[3][2];
        uint32_t l_1764 = 0x54F33472L;
        int i, j, k;
        for (i = 0; i < 3; i++) {
          for (j = 0; j < 2; j++)
            l_1730[i][j] = 0x7BL;
        }
        g_120[2] = g_1548[4][6][2];
        --l_1706;
        if ((((g_100 <
               ((safe_sub_func_int8_t_s_s(
                    g_1540[1][0],
                    (((((((1L |
                           (l_1643[4][0][3] !=
                            ((safe_sub_func_int16_t_s_s(
                                 ((safe_sub_func_int32_t_s_s(
                                      g_1548[9][3][2],
                                      (((((safe_add_func_uint16_t_u_u(
                                              (!l_1699), g_120[0])) !=
                                          ((safe_sub_func_int8_t_s_s(
                                               (safe_lshift_func_uint16_t_u_s(
                                                   (safe_rshift_func_int16_t_s_u(
                                                       (0UL != ((p_12 > l_1698),
                                                                l_1671)),
                                                       6)),
                                                   l_1703)),
                                               l_1724)) < 255UL)),
                                         l_1537) == l_1725) <
                                       l_1489[2][4][7]))) > l_1726),
                                 (-10L))) == p_13))),
                          0x853A9528L) != 1UL),
                        l_1706) >= 0x1C39L) == 0xF5678FABL),
                     0xD3L))) < 0x7EB415D5L)) != g_143) ||
             4294967289UL)) {
          int32_t l_1727 = 0L;
          int32_t l_1728 = 4L;
          int32_t l_1729[4][6][7] = {
              {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L,
                0x11543290L}},
              {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L,
                0x11543290L}},
              {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L,
                0x11543290L}},
              {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L},
               {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L,
                0x11543290L}}};
          int i, j, k;
          --l_1730[2][0];
        } else {
          uint16_t l_1751 = 0UL;
          for (g_89 = 0; (g_89 <= 3); g_89 += 1) {
            int i, j, k;
            l_1644[g_89][g_89][g_89] ^= (safe_lshift_func_uint8_t_u_u(
                (l_1489[g_89][(g_89 + 2)][g_89] >=
                 (safe_add_func_int32_t_s_s(
                     0x76753DFBL,
                     ((safe_rshift_func_uint8_t_u_s(
                          (safe_mod_func_int16_t_s_s(
                              5L,
                              (safe_lshift_func_int16_t_s_u(
                                  (((safe_lshift_func_uint16_t_u_u(
                                        g_1482[2][1][1], 6)) <
                                    ((safe_mod_func_uint32_t_u_u(
                                         (safe_rshift_func_int16_t_s_u(
                                             0xAAD7L,
                                             (((safe_add_func_int32_t_s_s(
                                                   (l_1751 &&
                                                    (((safe_add_func_uint8_t_u_u(
                                                          (((((~(l_1695,
                                                                 (((safe_mod_func_uint16_t_u_u(
                                                                       (safe_add_func_int8_t_s_s(
                                                                           (g_1368
                                                                                [1] ||
                                                                            (((((+(safe_lshift_func_int16_t_s_u(
                                                                                    (safe_sub_func_uint32_t_u_u(
                                                                                        l_1549,
                                                                                        9UL)),
                                                                                    g_540))),
                                                                                p_13),
                                                                               g_100) !=
                                                                              0xB3L) >
                                                                             p_13)),
                                                                           6L)),
                                                                       0x65A1L)) !=
                                                                   65533UL) >=
                                                                  l_1751))) >=
                                                              l_1764) |
                                                             l_1730[2][0]),
                                                            l_1751),
                                                           l_1751),
                                                          0UL)) <=
                                                      g_1548[5][0][1]) &&
                                                     255UL)),
                                                   g_22)) ^
                                               g_717) >= g_97[2]))),
                                         p_12)),
                                     p_11)) |
                                   l_1751),
                                  l_1698)))),
                          l_1751)) &
                      p_11)))),
                g_22));
          }
                    l_1651 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((p_13 == (safe_sub_func_uint16_t_u_u(((((g_143 & (safe_add_func_uint16_t_u_u((0L > ((((g_59 && l_1702[3]) >= p_12) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), p_11))) || l_1764)) >= g_22) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | p_12), p_12)) >= p_13), p_12)) < 0x90L), g_777)) & 0x68AFL), g_100)) , g_694), g_717))))), l_1724)), p_12)) || 4294967286UL), 13)) <= p_12) ^ 1L) , g_717) <= l_1751) & 0xABL))) | l_1706));
                    l_1643[0][3][1] ^= l_1751;
        }
        return p_12;
      }
      for (l_1634 = 0; (l_1634 >= 17);
           l_1634 = safe_add_func_int16_t_s_s(l_1634, 4)) {
        const uint32_t l_1798[7][8] = {
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L},
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L},
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L},
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L},
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L},
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L},
            {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL,
             0x14481399L, 0x659DA0B9L}};
        int i, j;
        l_1799[1][5] =
            ((6L ^
              (safe_rshift_func_int8_t_s_u(
                  (safe_mod_func_int8_t_s_s(
                      ((((((g_1217 ^
                            (((0L >=
                               (((safe_lshift_func_uint8_t_u_u(0x33L, p_11)) ^
                                 l_1699),
                                (safe_lshift_func_int8_t_s_s(g_694, 1)))) ==
                              ((((l_1489[2][4][7], (l_1798[3][0] && l_1705)) &
                                 1UL) &
                                g_1540[0][1]) &
                               g_849[0])) >= g_1368[2])) ||
                           2L),
                          g_120[1]) |
                         9UL),
                        g_1548[1][1][0]) &&
                       1UL),
                      l_1699)),
                  0))) >= 0x9FEE1EABL);
      }
      g_120[1] |=
          (((g_849[0] <= (safe_add_func_int32_t_s_s(p_11, p_11))) <=
            ((((((safe_mod_func_uint8_t_u_u(
                     (((safe_lshift_func_int8_t_s_u(
                           (p_13 &&
                            ((p_11 == l_1806) >
                             ((safe_rshift_func_int16_t_s_u(
                                  ((((((g_97[2] | p_12) &&
                                       ((!((safe_rshift_func_int16_t_s_s(
                                               ((0L | l_1549), p_13), g_22)) ^
                                           l_1698)) ^
                                        0L)) == p_12),
                                     1L) ||
                                    0xE5L) <= g_59),
                                  15)) ||
                              l_1806))),
                           3)) > g_101) ^
                      p_11),
                     g_1168)) ^
                 g_1368[1]) ||
                1L) != (-5L)),
              4294967290UL) <= p_11)) ^
           0x02D0829CL);
      if ((safe_lshift_func_int8_t_s_s(0xBCL, 7))) {
        int8_t l_1831 = (-6L);
        int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
        const uint8_t l_1889 = 252UL;
        int i;
        for (l_1706 = 0; (l_1706 >= 36);
             l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3)) {
          int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)},
                                  {(-1L), (-3L), (-1L), (-4L), (-6L)}};
          int32_t l_1841 = (-3L);
          int32_t l_1844 = 8L;
          int32_t l_1845 = 0xBE0388A2L;
          int16_t l_1853 = 0xBF53L;
          uint16_t l_1856 = 0x14A1L;
          int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1648 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((p_12 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && g_59), g_694)) >= 0x624C7317L) == p_13)) <= p_12)) , p_12) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), g_694)) > 1L)) & l_1698), p_13))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= g_1217) & l_1699) , l_1489[0][3][5])), 10)), p_11)) == g_97[2]) >= p_11)) || g_101) , l_1831) == p_13) ^ g_849[0])), p_12)) | l_1837) , l_1724);
                    for (g_1171 = 13; (g_1171 >= 1);
                         g_1171 = safe_sub_func_int32_t_s_s(g_1171, 9)) {
                      uint8_t l_1840 = 0x4FL;
                      int32_t l_1843 = 1L;
                      int32_t l_1850 = (-10L);
                      int32_t l_1851 = 0x86429966L;
                      int32_t l_1852 = 0xCA3D88B8L;
                      int32_t l_1855 = 1L;
                      l_1840 = g_1217;
                      --l_1846;
                      --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++) {
                      uint16_t l_1886[5];
                      int i;
                      for (i = 0; i < 5; i++)
                        l_1886[i] = 7UL;
                      g_120[1] &= l_1696[0];
                      g_120[0] =
                          (((((safe_lshift_func_uint16_t_u_u(
                                  ((safe_lshift_func_uint16_t_u_u(65535UL, 13)),
                                   0x9426L),
                                  (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(
                                      p_13,
                                      (((((0xEF2D849BL || l_1591) &
                                          (l_1841,
                                           (safe_add_func_uint8_t_u_u(
                                               (safe_lshift_func_int8_t_s_s(
                                                   (safe_rshift_func_int16_t_s_u(
                                                       (safe_mod_func_uint16_t_u_u(
                                                           (safe_mod_func_uint8_t_u_u(
                                                               (((((safe_sub_func_uint8_t_u_u(
                                                                       ((safe_rshift_func_uint16_t_u_s(
                                                                            g_22,
                                                                            (safe_rshift_func_uint16_t_u_s(
                                                                                (((l_1799
                                                                                       [1]
                                                                                       [5] >
                                                                                   (safe_add_func_uint16_t_u_u(
                                                                                       0x2E1AL,
                                                                                       0xBDC1L))) >=
                                                                                  l_1836
                                                                                      [0]
                                                                                      [4]) ==
                                                                                 l_1886
                                                                                     [0]),
                                                                                13)))) |
                                                                        (-2L)),
                                                                       l_1887)) &
                                                                   p_12) <
                                                                  0xBEL) <
                                                                 g_777) &
                                                                l_1888[2]),
                                                               0x66L)),
                                                           p_11)),
                                                       4)),
                                                   7)),
                                               0UL)))),
                                         1UL) ^
                                        l_1889) == 0xEAL))))))) > 0x483D69BBL),
                             l_1844),
                            247UL) ^
                           l_1706);
                      l_1644[0][3][4] =
                          ((((-2L) ==
                             (safe_add_func_uint16_t_u_u(
                                 (((((((((safe_add_func_int32_t_s_s(
                                             ((safe_add_func_uint32_t_u_u(
                                                  ((safe_lshift_func_int8_t_s_s(
                                                       ((safe_rshift_func_uint16_t_u_u(
                                                            (safe_rshift_func_uint8_t_u_s(
                                                                (safe_mod_func_int8_t_s_s(
                                                                    (251UL !=
                                                                     ((!l_1905) ==
                                                                      (((g_97[1] |
                                                                         (safe_lshift_func_int16_t_s_s(
                                                                             (safe_sub_func_uint32_t_u_u(
                                                                                 ((safe_rshift_func_uint16_t_u_s(
                                                                                      0xF54AL,
                                                                                      2)) &&
                                                                                  ((((p_11 >
                                                                                      ((((l_1853 &
                                                                                          (safe_add_func_uint16_t_u_u(
                                                                                              0x3ED4L,
                                                                                              1L))) ^
                                                                                         p_13) |
                                                                                        1L) ^
                                                                                       l_1849
                                                                                           [1])) >
                                                                                     (-1L)) &&
                                                                                    g_101) !=
                                                                                   0UL)),
                                                                                 0xEB10B25CL)),
                                                                             10))) <
                                                                        g_1482
                                                                            [2]
                                                                            [1]
                                                                            [1]) ||
                                                                       0x405D3F2AL))),
                                                                    l_1599)),
                                                                1)),
                                                            2)) &&
                                                        g_1217),
                                                       5)) &&
                                                   4294967295UL),
                                                  4294967293UL)),
                                              p_13),
                                             4294967288UL)) |
                                         p_12) ||
                                        p_12) &&
                                       l_1639) &&
                                      p_13) &&
                                     0x068C0922L),
                                    g_1171),
                                   (-1L)) < p_11),
                                 1UL))) ^
                            l_1846) ||
                           l_1699);
                      l_1693 = (safe_lshift_func_uint8_t_u_s(
                          p_12, ((safe_rshift_func_int8_t_s_s(9L, g_694)) !=
                                 l_1846)));
                    }
        }
        g_120[1] ^=
            ((p_12 &
              (0x8889L >=
               (p_13 ==
                ((safe_unary_minus_func_uint8_t_u(0UL)) <=
                 (safe_mod_func_int16_t_s_s(
                     g_1482[3][0][1],
                     ((p_13 >
                       (((~p_11) &&
                         ((~(!((((safe_sub_func_uint16_t_u_u(
                                     (((((((p_12 <
                                            ((((p_13, p_13) >= 0x93L), 1UL) ^
                                             g_100)) ^
                                           p_11) == l_1889) &
                                         0UL),
                                        g_717) < l_1799[4][4]) < 4294967295UL),
                                     l_1849[0])) <= 1L),
                                p_12),
                               0x3CL))),
                          p_11)) >= 7L)) &
                      l_1648))))))) |
             l_1831);
        l_1643[0][3][1] = (g_1171 > 0x5B7FL);
      } else {
        uint32_t l_1932 = 1UL;
        int32_t l_1945 = 0L;
        int32_t l_1946[1];
        uint32_t l_1971 = 0x9EF11B35L;
        uint8_t l_1990 = 0xB6L;
        int i;
        for (i = 0; i < 1; i++)
          l_1946[i] = 3L;
        for (g_101 = (-11); (g_101 < (-24)); --g_101) {
          int32_t l_1929 = 0L;
          int32_t l_1930 = 0x01C56913L;
          uint8_t l_1949 = 0xBEL;
          int32_t l_2005 = 0L;
          if (p_12) {
            int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL,
                                  0x3C11E539L, 0x6399E99BL, 0x3C11E539L,
                                  0x6399E99BL, 0x3C11E539L, 0x6399E99BL,
                                  0x3C11E539L};
            int i;
            l_1932--;
          } else {
            l_1693 = p_13;
          }
          if ((p_12, l_1694)) {
            int8_t l_1947 = 0x1BL;
            int32_t l_1948 = 0x27F08C10L;
            l_1945 =
                (((0x03L ==
                   (0xA11DL <
                    (g_59 | ((((0x6F1BL != g_935) <
                               (((((((((safe_rshift_func_int8_t_s_s(
                                           (((safe_rshift_func_uint16_t_u_s(
                                                 (safe_rshift_func_int8_t_s_u(
                                                     g_97[2], g_1171)),
                                                 2)) >
                                             (safe_add_func_uint16_t_u_u(
                                                 g_1548[4][6][2], 0x34DEL))) &
                                            p_11),
                                           l_1706)),
                                       0x3208L),
                                      g_1540[1][0]),
                                     l_1930) == g_101),
                                   g_1548[0][0][1]) <= l_1932) > p_11) >=
                                0UL)) < p_11) >= p_13)))) ^
                  g_97[2]),
                 g_849[0]);
            ++l_1949;
            g_120[4] = (safe_mod_func_uint8_t_u_u(
                ((safe_mod_func_int32_t_s_s(
                     6L,
                     (safe_sub_func_uint8_t_u_u(
                         0x94L,
                         (((l_1949 |
                            (safe_rshift_func_int8_t_s_u(
                                ((((safe_mod_func_int16_t_s_s(
                                       (safe_sub_func_uint16_t_u_u(
                                           (safe_add_func_uint8_t_u_u(
                                               ((((+(safe_add_func_uint16_t_u_u(
                                                      ((safe_sub_func_int8_t_s_s(
                                                           ((0xB3EFL ||
                                                             (l_1947 |
                                                              (((g_120[1] ^
                                                                 ((((-2L) &
                                                                    (((p_11 ^
                                                                       (l_1945,
                                                                        0x78L)),
                                                                      l_1971) <
                                                                     p_13)) <
                                                                   0xA9FBL) ==
                                                                  p_13)) <
                                                                l_1806) <
                                                               0xE1L))) &&
                                                            l_1948),
                                                           0x64L)),
                                                       p_13),
                                                      9UL))) >= 0x60B3L) !=
                                                 p_13) ^
                                                p_13),
                                               p_12)),
                                           0x0DAEL)),
                                       l_1887)) >= l_1947) > p_13) == p_11),
                                l_1948))),
                           5L) |
                          0xB082A17BL))))),
                 0x11L),
                0x03L));
          } else {
            l_1930 =
                ((0L & p_13) !=
                 (!((safe_mod_func_uint8_t_u_u(p_12, 0x7AL)) >
                    (((l_1932 | p_13), 0x1F0EL) <
                     (p_11 && ((((safe_mod_func_uint16_t_u_u(
                                     (safe_mod_func_uint8_t_u_u(l_1854, p_11)),
                                     0x3929L)) != 0L) == 0x2F747C30L),
                               0x96347F98L))))));
          }
          if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0], l_1930), p_11)) &
               (((g_935 <
                  (((((safe_lshift_func_int16_t_s_u(
                          ((p_13, ((p_11 &&
                                    (((safe_unary_minus_func_int16_t_s((
                                          (safe_add_func_uint16_t_u_u(
                                              l_1693,
                                              ((((safe_add_func_uint16_t_u_u(
                                                     (l_1591 ^ p_13), l_1990)) <
                                                 p_11) < 0x1D1DL) |
                                               g_694))) |
                                          g_120[1]))),
                                      p_13) &&
                                     l_1643[1][1][6])) ^
                                   g_89)),
                           p_13),
                          l_1599)) |
                      p_11) <= 0UL) != (-8L)),
                   p_13)) < l_1698) ||
                0x837FL))) {
            int8_t l_2002 = 0x5BL;
            int32_t l_2004[1];
            int i;
            for (i = 0; i < 1; i++)
              l_2004[i] = 7L;
            g_2003[0] |= (safe_add_func_uint8_t_u_u(
                (safe_add_func_int16_t_s_s(
                    (((((safe_rshift_func_uint16_t_u_u(
                            g_1482[0][1][0],
                            ((~((((-6L) < p_11) >= g_120[1]) | (p_11, p_11))) !=
                             (((safe_lshift_func_uint16_t_u_s(
                                   ((g_1548[4][6][2] ||
                                     ((((safe_rshift_func_int8_t_s_s(1L, 4)) <=
                                        0xC812E52FL) ||
                                       g_1368[1]) <= 0UL)),
                                    l_1888[1]),
                                   3)) != p_13) < 65535UL)))) |
                        g_1482[2][1][1]) <= 4294967292UL) &&
                      l_1929) > l_2002),
                    g_849[0])),
                p_12));
            l_2006--;
            if (l_1888[1])
              break;
          } else {
            uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
            int i, j;
            g_120[1] = (safe_rshift_func_int16_t_s_u(
                (((safe_sub_func_uint8_t_u_u(
                      (0xBC96E130L > l_2013[1][0]),
                      ((safe_add_func_uint8_t_u_u(
                           ((l_2005 >=
                             (((safe_add_func_uint8_t_u_u(
                                   (((l_1725 & l_2013[0][1]),
                                     ((safe_rshift_func_uint16_t_u_u(
                                          ((safe_rshift_func_uint16_t_u_u(
                                               g_1548[4][6][2], l_1932)),
                                           ((safe_mod_func_int16_t_s_s(
                                                ((safe_add_func_uint16_t_u_u(
                                                     ((p_11 ^
                                                       ((safe_mod_func_uint16_t_u_u(
                                                            (65534UL <= l_1549),
                                                            p_11)),
                                                        g_120[3])) ||
                                                      l_1591),
                                                     g_97[1])) > g_143),
                                                (-4L))) > 7L)),
                                          l_1949)) == l_1888[2])) < p_12),
                                   9UL)) |
                               g_1368[1]) &
                              l_1639)) <= l_1930),
                           0x27L)) &
                       9UL))) &&
                  p_12),
                 0x1E18L),
                g_18));
          }
          g_120[1] =
              ((((0UL == (0x99L == g_1482[2][1][1])), l_2028), g_97[2]) >
               ((g_120[3] >
                 ((((((safe_lshift_func_uint16_t_u_s(
                          ((safe_rshift_func_int8_t_s_u(
                               (safe_lshift_func_uint8_t_u_s(
                                   ((0x83922D4EL != ((-8L) > 0x08L)) || l_1634),
                                   5)),
                               l_1671)) >= l_1634),
                          15)) < p_13),
                     0xAC9FE61AL),
                    p_13) > p_11) |
                  g_1540[1][0])) ^
                (-1L)));
        }
      }
    }
  }
  for (g_100 = 0; (g_100 == 7); g_100 = safe_add_func_uint8_t_u_u(g_100, 6)) {
    int16_t l_2039 = 0x0ABAL;
    const uint16_t l_2040 = 65532UL;
    int32_t l_2061 = 0x90A8BF10L;
    int32_t l_2101 = 0x02F00675L;
    int32_t l_2137 = 0L;
    int32_t l_2143[3];
    uint32_t l_2152 = 0xDB2A778AL;
    uint16_t l_2158 = 0xFEEFL;
    uint16_t l_2301 = 0xE812L;
    int i;
    for (i = 0; i < 3; i++)
      l_2143[i] = 0x4EA06463L;
    if ((safe_add_func_uint8_t_u_u(
            1UL, ((((1UL | ((l_1671, ((g_849[0], l_2039) !=
                                      ((((l_2040, (-9L)) <= 0x9EA7L) > p_12),
                                       p_11))) <= g_717)) == l_1888[2]) ||
                   p_13) ^
                  g_935)))) {
      uint32_t l_2062 = 4UL;
      int32_t l_2136 = 0x587994DEL;
      int32_t l_2138 = 0x39236B84L;
      int32_t l_2139 = 0x2CD995FBL;
      int32_t l_2140 = (-1L);
      int32_t l_2142 = 0x807412D1L;
      int32_t l_2146 = (-8L);
      int32_t l_2147 = (-7L);
      int32_t l_2149 = 0x0E72D148L;
      int32_t l_2151 = 0x4ECFBDFFL;
      uint8_t l_2155 = 0x86L;
      int32_t l_2176[3];
      int16_t l_2177 = 0x3603L;
      int32_t l_2179 = 1L;
      int32_t l_2180 = 1L;
      int32_t l_2181 = 0xDF8F0F9CL;
      int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
      uint16_t l_2185 = 0x30E9L;
      int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L,
                          0xA3L, 0x43L, 0xA3L, 0x43L};
      int i;
      for (i = 0; i < 3; i++)
        l_2176[i] = (-1L);
      l_2061 = (safe_rshift_func_uint8_t_u_u(
          ((((l_2039,
              (safe_mod_func_int16_t_s_s(
                  (+((safe_sub_func_uint32_t_u_u(
                         (((safe_add_func_int8_t_s_s(
                               (0x9FB88B87L <= (l_2050 && l_2028)),
                               ((safe_add_func_uint32_t_u_u(
                                    (safe_mod_func_uint32_t_u_u(
                                        g_120[4], (l_2055 | p_12))),
                                    ((safe_unary_minus_func_uint32_t_u(
                                         (safe_mod_func_uint8_t_u_u(
                                             (((((((safe_rshift_func_uint8_t_u_u(
                                                       g_120[1], 3)) ^
                                                   0L) < l_2039) &&
                                                 0L) < g_143) &
                                               0xF6503CF8L) > p_11),
                                             p_11)))),
                                     l_1696[0]))),
                                l_1888[2]))) == 1UL),
                          p_11),
                         l_1648)) < 0x0C40299FL)),
                  p_12))) ||
             0x6671L) &&
            g_540) < g_540),
          3));
      if ((l_2062 == 0xF331L)) {
        uint32_t l_2075 = 0x3F7E974AL;
        int32_t l_2076 = 0xDD959D4BL;
        uint32_t l_2121 = 0xDB46FF94L;
        int32_t l_2135 = 0x8FD202FEL;
        int32_t l_2144 = 7L;
        int32_t l_2145 = 0x543A4A56L;
        int32_t l_2148 = (-7L);
        int32_t l_2150 = (-4L);
        for (g_59 = 11; (g_59 > 6);
             g_59 = safe_sub_func_uint16_t_u_u(g_59, 8)) {
          uint16_t l_2105 = 65535UL;
          for (l_2050 = 0; (l_2050 != 38); ++l_2050) {
            l_1695 =
                ((p_12 <
                  (safe_sub_func_int8_t_s_s(
                      (safe_add_func_int32_t_s_s((p_11 < 0L), (p_11 >= 0L))),
                      (-1L)))) >=
                 ((safe_lshift_func_uint8_t_u_u(
                      ((p_13 || 252UL), ((((safe_lshift_func_int8_t_s_s(
                                               l_1549, 7)) != 0L) == g_101),
                                         g_849[0])),
                      l_2075)) >= l_2076));
          }
          for (l_2055 = (-27); (l_2055 <= (-28)); l_2055--) {
            uint32_t l_2102 = 0x75F47E93L;
            g_120[2] = (safe_sub_func_int32_t_s_s(
                (safe_sub_func_uint8_t_u_u(
                    (g_101 > p_11),
                    (safe_sub_func_uint8_t_u_u(
                        ((p_13 &
                          (p_12 &
                           ((((~((((safe_mod_func_int32_t_s_s(
                                       (safe_sub_func_uint16_t_u_u(
                                           g_1168,
                                           (((((safe_lshift_func_int8_t_s_s(
                                                   ((safe_mod_func_uint8_t_u_u(
                                                        (((0xDFF1L >
                                                           ((safe_sub_func_int8_t_s_s(
                                                                (((+((!(((safe_lshift_func_int16_t_s_s(
                                                                             0xF854L,
                                                                             8)) ^
                                                                         g_1482
                                                                             [2]
                                                                             [1]
                                                                             [1]) ^
                                                                        g_540)),
                                                                     g_120
                                                                         [4])) ==
                                                                  0UL) ^
                                                                 g_100),
                                                                p_12)),
                                                            1L)),
                                                          g_89) |
                                                         g_2003[3]),
                                                        g_849[0])) ||
                                                    0x4AL),
                                                   p_12)) > p_12) &
                                              g_97[3]) == g_1368[1]),
                                            0x821DL))),
                                       p_11)) &
                                   0xDCA8CE5FL) <= l_2040) > p_13)) |
                              p_13),
                             p_12) ||
                            p_13))),
                         l_2076),
                        0x74L)))),
                g_2100));
            l_2101 |= 9L;
            l_2102 &= p_12;
          }
          for (l_2076 = 7; (l_2076 >= (-7)); --l_2076) {
            uint32_t l_2108 = 0xCCCFDF72L;
            l_2105 ^= p_13;
            g_120[2] =
                (((safe_rshift_func_uint8_t_u_u(
                      (((g_1482[2][1][3],
                         (((l_2108 | g_120[3]) == p_11),
                          ((safe_lshift_func_uint16_t_u_s(
                               ((safe_sub_func_uint8_t_u_u(
                                    ((0UL && g_2003[1]) || 1UL),
                                    ((safe_sub_func_uint8_t_u_u(
                                         ((((safe_sub_func_int8_t_s_s(
                                                (safe_sub_func_uint8_t_u_u(
                                                    (p_12 &&
                                                     (safe_lshift_func_uint8_t_u_s(
                                                         (0x24L >= 0UL), 0))),
                                                    p_11)),
                                                l_2121)) <= l_2040) &
                                           g_717),
                                          p_11),
                                         1UL)) >= l_2108))) >= p_13),
                               12)) >= (-1L)))) |
                        g_97[2]) != p_12),
                      2)) ^
                  0xB68DD604L) == 0UL);
          }
          l_1693 =
              (g_100 !=
               (safe_rshift_func_int16_t_s_u(
                   (safe_sub_func_int16_t_s_s(
                       (((-1L) || 0x95L) & g_1368[1]),
                       ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >=
                        (((((safe_unary_minus_func_uint16_t_u(1UL)),
                            ((((p_11 ==
                                ((l_2105, (safe_sub_func_int32_t_s_s(
                                              ((safe_lshift_func_int16_t_s_s(
                                                   g_540, g_120[1])),
                                               l_2039),
                                              l_2062))) == p_12)),
                               0x8847L) == g_101),
                             0x73EDD688L)) == p_13),
                          l_2062) < g_101)))),
                   8)));
        }
        l_2152++;
        l_2145 = ((((l_2151, (l_2155 != p_12)) || (0xADL && 0x61L)) < p_11) <
                  ((safe_lshift_func_uint16_t_u_s(
                       0xD3B9L,
                       (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) &
                               0x5C680109L)))) == 0xC0DAL));
      } else {
        uint32_t l_2161 = 0x817ED328L;
        l_2101 |=
            (7L ^
             (p_12 >
              (((l_2158 < (p_12 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) ||
                                   (255UL >= p_12)))),
                g_1548[2][0][1]) == l_2161)));
        l_2151 = (safe_sub_func_uint32_t_u_u(
            (g_2003[0] >=
             ((p_12 >=
               (safe_add_func_int32_t_s_s(
                   ((((((safe_add_func_int8_t_s_s(
                            ((((safe_sub_func_int8_t_s_s(
                                   g_2100,
                                   (safe_sub_func_uint16_t_u_u(
                                       0xB24EL,
                                       ((((safe_mod_func_uint32_t_u_u(
                                              g_22,
                                              ((((safe_sub_func_int32_t_s_s(
                                                     (0L == l_2176[0]),
                                                     (0x17L &&
                                                      (g_89, 0x38L)))) > g_22),
                                                255UL) &&
                                               g_1168))) ||
                                          0x8F222FB3L) ||
                                         0xC79840FEL) ^
                                        p_12))))) < p_12),
                              g_59) > g_97[5]),
                            7UL)) < g_120[2]),
                       g_120[1]) &
                      l_2146) <= g_1217) &&
                    g_18),
                   p_12))) &&
              p_12)),
            g_717));
      }
      l_2185++;
      for (l_1671 = 0; (l_1671 <= 8);
           l_1671 = safe_add_func_uint8_t_u_u(l_1671, 6)) {
        const int8_t l_2199 = (-1L);
        int32_t l_2255[3];
        int i;
        for (i = 0; i < 3; i++)
          l_2255[i] = 0L;
        for (g_59 = 0; (g_59 == 34);
             g_59 = safe_add_func_uint8_t_u_u(g_59, 3)) {
          int16_t l_2216 = 0x83C6L;
          int32_t l_2249 = 0xEA87154FL;
          int32_t l_2260 = 0xF84A0E45L;
          int32_t l_2261 = 0xC424E530L;
          uint16_t l_2263 = 65530UL;
          for (g_2100 = 0; (g_2100 <= (-15));
               g_2100 = safe_sub_func_uint32_t_u_u(g_2100, 1)) {
            const uint8_t l_2200 = 0xE4L;
            uint16_t l_2217 = 3UL;
            l_2143[0] =
                (0UL >=
                 ((g_1368[0] !=
                   (((safe_add_func_int16_t_s_s(
                         ((+(l_2176[0] &&
                             ((((0xEEL >= g_120[1]) && (+g_717)) || p_11) >
                              (((((~(p_13 <= (l_2199, 0L))) >= (-1L)) <= p_13),
                                g_59),
                               g_143)))) > p_11),
                         l_2200)) |
                     l_2200),
                    g_101)) != g_97[5]));
            g_120[1] = (safe_lshift_func_int8_t_s_u(
                ((safe_mod_func_uint16_t_u_u(
                     p_12,
                     (((l_2040 ||
                        (safe_unary_minus_func_int8_t_s((
                            (safe_mod_func_int16_t_s_s(
                                (0L !=
                                 ((safe_sub_func_uint32_t_u_u(
                                      0xF9EC49D5L,
                                      (safe_lshift_func_uint8_t_u_s(
                                          ((((safe_mod_func_uint16_t_u_u(
                                                 ((safe_rshift_func_uint16_t_u_u(
                                                      ((((-8L) &&
                                                         (0x53L || 1L)) <
                                                        (g_101 ==
                                                         (((0xAC9BL > p_11) <=
                                                           g_143) >= p_13))),
                                                       l_2216),
                                                      2)) &&
                                                  0xE90C1C13L),
                                                 2L)),
                                             g_101),
                                            0UL),
                                           l_2101),
                                          7)))),
                                  p_12)),
                                p_12)) < g_935)))) != 0L) ||
                      l_2217))) > p_13),
                6));
            g_120[1] &= l_2200;
            if (g_717)
              break;
          }
          if ((g_1482[2][1][1] & 0xDB81CA17L)) {
            l_2181 = l_2176[0];
            return p_13;
          } else {
            if (p_12)
              break;
          }
          for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1) {
            int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(p_13, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(p_12, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, g_540)) , 0x3DL) == p_12) > 0xB5BB9598L) != g_101) ^ 0L) || l_2158) <= 4294967291UL)), g_59)) <= g_97[0]), 14))), l_2179)) != p_12) != g_143) & 0UL), p_12)) != p_13) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | p_12)) | 0x6BL)) || p_11) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= p_11), l_1694)) && p_11) , 0x3F8D8182L);
                        g_2254 ^= (l_2143[l_2137] &&
                                   ((g_1168,
                                     (safe_sub_func_int8_t_s_s(
                                         (((0x01B30B9BL ^
                                            (1UL | (safe_sub_func_int32_t_s_s(
                                                       l_2199,
                                                       (((g_120[4], g_849[0]) ^
                                                         g_777) != l_2151))))) <
                                           1UL) |
                                          0x7EE96D31L),
                                         g_59))) == g_2100));
                        l_2255[1] = (p_11 != g_59);
          }
          for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1) {
            int32_t l_2256 = 0x52D2483BL;
            int32_t l_2257 = 1L;
            int32_t l_2258[2][3];
            int16_t l_2262 = 1L;
            int i, j;
            for (i = 0; i < 2; i++) {
              for (j = 0; j < 3; j++)
                l_2258[i][j] = 1L;
            }
            l_2101 = g_1368[l_2152];
            l_2263--;
            l_2260 &= (p_11 == p_13);
            l_1693 = (safe_sub_func_int16_t_s_s(
                ((g_1482[2][1][1] |
                  ((5L ||
                    (g_1548[3][7][1] !=
                     (safe_mod_func_int16_t_s_s(
                         (safe_sub_func_int8_t_s_s(
                             (safe_rshift_func_uint16_t_u_u(
                                 (safe_mod_func_int16_t_s_s(
                                     ((0x76L &
                                       ((safe_sub_func_uint8_t_u_u(
                                            (safe_rshift_func_uint8_t_u_u(
                                                (l_2039 &
                                                 (safe_lshift_func_uint16_t_u_u(
                                                     ((p_11 &
                                                       (0x5EL <=
                                                        ((safe_add_func_int8_t_s_s(
                                                             1L, (g_1368[0] >=
                                                                  0x02L))) <=
                                                         l_2256))) != g_694),
                                                     15))),
                                                l_2216)),
                                            g_1540[1][0])) < 0x866FL)) >=
                                      0x9DEFCED1L),
                                     0x570AL)),
                                 g_97[5])),
                             l_1694)),
                         p_11)))),
                   l_2143[2])) ^
                 0xAB2DL),
                0UL));
          }
        }
      }
    } else {
      int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L,
                               0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L},
                              {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L,
                               0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L},
                              {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L,
                               0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L},
                              {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L,
                               0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L},
                              {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L,
                               0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
      int32_t l_2321 = (-1L);
      uint32_t l_2322 = 0x99FED06DL;
      int i, j;
      for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1) {
        g_120[1] = (safe_sub_func_int32_t_s_s(g_2100, 0x8EEC641FL));
        for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1) {
          const int16_t l_2298 = 0x7AB4L;
          if (p_13) {
            int8_t l_2299 = 0xA2L;
            g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], g_694));
            g_120[1] =
                ((safe_rshift_func_int8_t_s_u(
                     p_13,
                     ((safe_mod_func_uint8_t_u_u(
                          (safe_lshift_func_int8_t_s_s(
                              (0x9CD8L &&
                               ((p_11 !=
                                 (1UL & (p_12, (safe_lshift_func_uint16_t_u_u(
                                                   (((p_13 ==
                                                      (0x32DBL >= (0x73E61AD3L <
                                                                   l_2298))) ||
                                                     g_100) >= l_2299),
                                                   4))))) >= 65535UL)),
                              g_143)),
                          p_13)) &&
                      0x6D137FB0L))) &&
                 7L);
            l_2301--;
            l_1648 =
                ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) &
                   (((((((safe_lshift_func_int16_t_s_u(
                             (((l_2300[3][1] &
                                ((safe_rshift_func_uint8_t_u_u(
                                     247UL,
                                     (safe_mod_func_uint8_t_u_u(
                                         1UL, (safe_mul_func_int16_t_s_s(
                                                  (+g_143),
                                                  (g_1548[7][6][1] >=
                                                   (safe_lshift_func_int8_t_s_u(
                                                       g_540, 0))))))))) ||
                                 ((safe_sub_func_int32_t_s_s(
                                      (((safe_lshift_func_int16_t_s_u(
                                            (-1L), 11)) == 0x5DL) |
                                       l_2299),
                                      4294967295UL)),
                                  l_2300[4][1]))) <= g_2184[2][0]) |
                              l_2300[3][6]),
                             14)),
                         (-7L)),
                        p_13) != 0x6C7C71DBL),
                      g_18),
                     g_1548[4][6][2]) |
                    g_2184[2][1])) == l_2141[1][6][5]) > p_12);
          } else {
            return p_11;
          }
        }
        ++l_2322;
      }
    }
  }
  l_2326--;
  l_1651 = (safe_mod_func_uint16_t_u_u(
      ((safe_sub_func_int8_t_s_s(
           (((safe_lshift_func_int8_t_s_u(
                 (safe_sub_func_int16_t_s_s(
                     l_1651,
                     ((p_13 != 0xD257L) ==
                      (safe_sub_func_uint8_t_u_u(
                          (((safe_lshift_func_uint16_t_u_s(
                                (safe_sub_func_int32_t_s_s(
                                    ((g_694 |
                                      ((safe_add_func_uint8_t_u_u(
                                           l_1651,
                                           ((((p_13 == (!(((!(~0xA2B5L)) ||
                                                           (g_694 != p_11)),
                                                          0xBE0E0ABDL))),
                                              l_2028) == 0x154C94FDL) <=
                                            0xDCE7L))) &
                                       l_1695)) == g_1368[0]),
                                    p_11)),
                                p_13)) > 0x8806C5F6L) > p_12),
                          p_12))))),
                 g_717)) |
             p_13) &
            l_1651),
           0xD3L)),
       g_97[2]),
      p_12));
  return l_1671;
}

static int32_t func_19(int16_t p_20) {
  uint32_t l_21 = 8UL;
  g_22 = l_21;
  g_1482[2][1][1] |= (safe_rshift_func_uint16_t_u_s(p_20, func_25(l_21)));
  return p_20;
}

static int16_t func_25(uint16_t p_26) {
  uint32_t l_27 = 4294967294UL;
  l_27 = 0x31AA08ECL;
  g_120[1] =
      (0x0415L >
       ((func_28(
             (l_27,
              (safe_mod_func_int16_t_s_s(
                  func_33(
                      (safe_mod_func_int32_t_s_s(
                          ((func_38(
                                (l_27 < g_22),
                                ((safe_lshift_func_int16_t_s_u(1L, 3)),
                                 (((((p_26 &&
                                      func_46(
                                          ((((safe_lshift_func_uint8_t_u_u(
                                                 0UL,
                                                 (func_54((0x373CL &&
                                                           (0x7530L < 2UL)),
                                                          p_26, p_26, l_27) >=
                                                  g_18))) == g_22) >=
                                            0xD45AA775L) > l_27),
                                          p_26, p_26, g_18, l_27)) != p_26) <
                                    p_26) != 0xE6DB759FL) != g_22)),
                                l_27, g_22, l_27) ^
                            p_26) != p_26),
                          0xDA6413EFL)),
                      p_26),
                  g_18))),
             p_26) ^
         5UL) == g_1168));
  for (g_59 = 26; (g_59 == 51); g_59++) {
    uint8_t l_1466 = 254UL;
    int32_t l_1481 = 7L;
    g_120[1] = l_1466;
    l_1481 =
        (((g_97[2] > p_26) |
          (safe_add_func_uint8_t_u_u(
              0x65L,
              ((!((safe_rshift_func_int8_t_s_s(
                      ((0x0584L <
                        (l_1466 &&
                         (safe_lshift_func_int8_t_s_u(
                             (safe_sub_func_int8_t_s_s(
                                 (((!(p_26, ((safe_mod_func_uint8_t_u_u(l_1466,
                                                                        g_22)),
                                             (safe_sub_func_int8_t_s_s(
                                                 (0xCDL > g_694), 0xCFL))))) <
                                   255UL) < 0xB6L),
                                 l_1466)),
                             p_26)))),
                       0x19L),
                      l_1466)) > 0xBFD8L)) == 0UL)))) >= l_27);
  }
  return p_26;
}

static int16_t func_28(int32_t p_29, int32_t p_30) {
  int32_t l_1461 = 1L;
  int16_t l_1462[7][1];
  int i, j;
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 1; j++)
      l_1462[i][j] = 0L;
  }
  for (g_101 = 10; (g_101 == (-12));
       g_101 = safe_sub_func_uint8_t_u_u(g_101, 9)) {
    uint32_t l_1447 = 0xDBB284DBL;
    int32_t l_1463 = 0xE4B3772FL;
    l_1463 |=
        ((safe_mod_func_uint16_t_u_u(
             (safe_lshift_func_int16_t_s_s(
                 ((l_1447 !=
                   (safe_add_func_int8_t_s_s(
                       ((((safe_mod_func_uint16_t_u_u(
                              ((l_1447 >=
                                (safe_add_func_uint16_t_u_u(
                                    ((safe_lshift_func_uint8_t_u_s(
                                         (g_540 >
                                          (safe_add_func_uint8_t_u_u(
                                              g_22,
                                              (0x5103L >=
                                               (safe_mul_func_uint32_t_u_u(
                                                   (((+l_1447) && g_777),
                                                    l_1461),
                                                   (0L == 0xFFC0EF70L))))))),
                                         4)) > g_97[2]),
                                    p_29))) &
                               p_30),
                              p_30)) < p_29) &&
                         255UL) < 8L),
                       g_540))),
                  0x1C47L),
                 l_1461)),
             l_1462[4][0])) != l_1462[0][0]);
  }
  return p_29;
}

static int16_t func_33(uint32_t p_34, int16_t p_35) {
  int8_t l_725[4] = {0x6CL, (-1L), 0x6CL, (-1L)};
  int32_t l_778 = 0L;
  int8_t l_790 = 0xCFL;
  int32_t l_793 = (-10L);
  uint32_t l_877[3][1];
  int8_t l_880 = 0x4CL;
  int32_t l_919 = 0x24F96B7BL;
  int32_t l_922 = 1L;
  uint32_t l_940[8] = {0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L,
                       0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L};
  uint32_t l_980 = 0xC75D6C4FL;
  uint8_t l_1007 = 0x6CL;
  uint32_t l_1052 = 0xC1E7B1A1L;
  int8_t l_1191[5] = {(-3L), 2L, (-3L), 2L, (-3L)};
  uint32_t l_1281 = 0x7B51DD50L;
  int32_t l_1327 = 0xC40777EBL;
  int32_t l_1329 = 0x90371E5EL;
  uint32_t l_1423 = 0UL;
  uint32_t l_1433 = 18446744073709551615UL;
  int32_t l_1439[6];
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 1; j++)
      l_877[i][j] = 0x46984ABCL;
  }
  for (i = 0; i < 6; i++)
    l_1439[i] = 9L;
  for (g_59 = 0; (g_59 != 4); ++g_59) {
    uint8_t l_722 = 0xE0L;
    int32_t l_770 = 0x6E81370EL;
    uint32_t l_779 = 1UL;
    int32_t l_792 = 0x2E89F638L;
    if ((safe_lshift_func_int16_t_s_u(
            (p_35 <= l_722),
            (safe_sub_func_int8_t_s_s(
                ((l_725[2] <=
                  ((((safe_sub_func_int32_t_s_s(
                         g_22,
                         (safe_mod_func_uint32_t_u_u(
                             (0x7ABE5FAFL >=
                              ((safe_sub_func_uint8_t_u_u(g_120[1], l_722)),
                               ((safe_lshift_func_int8_t_s_u(
                                    l_722, (((((((safe_lshift_func_int8_t_s_s(
                                                     g_22, 3)) |
                                                 l_725[2]) ||
                                                g_89) >= p_35) <= g_97[5]),
                                             l_722) >= 4294967295UL))) ==
                                g_694))),
                             l_725[2])))) >= p_35) ^
                    0UL) != 8L)) ^
                 0x0968FE10L),
                p_34))))) {
      uint32_t l_749 = 4294967288UL;
      if ((~(safe_add_func_uint32_t_u_u(
              ((0L !=
                (((l_725[2] ||
                   (safe_sub_func_int8_t_s_s(
                       0x65L, (safe_mod_func_uint32_t_u_u(p_34, l_722))))) ^
                  ((safe_add_func_uint16_t_u_u(
                       (g_717, (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))),
                       (((p_35 == g_143) >= g_18) < g_101))) < (-1L))) < p_35)),
               0x11329388L),
              4294967295UL)))) {
        int32_t l_769[1];
        int i;
        for (i = 0; i < 1; i++)
          l_769[i] = 0x804970A5L;
        g_120[1] = 1L;
        if (p_35)
          continue;
        l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
        l_770 = (safe_lshift_func_int8_t_s_s(
            (5UL >=
             (0UL < (safe_add_func_int8_t_s_s(
                        (((safe_rshift_func_int16_t_s_s(
                              (g_18 !=
                               (safe_sub_func_int32_t_s_s(
                                   (safe_unary_minus_func_int32_t_s(
                                       (safe_mod_func_int8_t_s_s(
                                           (safe_mod_func_int32_t_s_s(
                                               0x5B48709BL,
                                               ((safe_rshift_func_int16_t_s_s(
                                                    g_18, p_35)) ||
                                                3L))),
                                           (safe_sub_func_int32_t_s_s(
                                               g_694,
                                               ((((safe_rshift_func_int16_t_s_u(
                                                      p_35, 7)) ||
                                                  g_18) ||
                                                 l_769[0]) <= p_34))))))),
                                   g_22))),
                              6)) != p_35) != g_100),
                        l_722)))),
            p_34));
      } else {
        int16_t l_775 = (-4L);
        int32_t l_776 = (-3L);
        g_777 = ((((g_143 ^ (l_725[2], (0xB43536D7L > 0x43474B68L))) >=
                   (((g_18 < ((safe_add_func_int8_t_s_s(l_722, 0xFAL)) &
                              (safe_mod_func_int8_t_s_s(
                                  ((((((l_775 | l_776) || g_101) || g_89),
                                     p_34) <= 6L) <= 0x62L),
                                  0x36L)))) &&
                     g_143) > 0x8EL)) != p_34) == p_34);
      }
      --l_779;
    } else {
      int16_t l_786 = 8L;
      int32_t l_789 = 2L;
      int32_t l_791 = 0xB2B08DC3L;
      uint32_t l_794 = 0x67A078F5L;
      l_778 = (safe_rshift_func_int16_t_s_u(g_717, 9));
      if (p_34)
        break;
      for (l_778 = 0; (l_778 <= (-8)); l_778--) {
        return l_786;
      }
      for (g_694 = 2; (g_694 < 14);
           g_694 = safe_add_func_uint16_t_u_u(g_694, 3)) {
        l_794--;
      }
    }
  }
  if ((p_34 == g_540)) {
    int16_t l_801[8][10] = {
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L},
        {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}};
    int32_t l_821[9][7] = {
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L},
        {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}};
    uint32_t l_843 = 4294967290UL;
    int32_t l_1046 = 0x07FD8AA4L;
    int i, j;
    for (g_143 = 0; (g_143 > 15); ++g_143) {
      g_120[1] = 0x19D1A3FEL;
      if (p_35)
        continue;
    }
    for (l_793 = 0; (l_793 <= 24);
         l_793 = safe_add_func_uint16_t_u_u(l_793, 2)) {
      int32_t l_820 = (-1L);
      const int32_t l_844 = 1L;
      int32_t l_846 = 0xEFBA0CA9L;
      int32_t l_848 = 0x52FBE6A1L;
      uint32_t l_885 = 2UL;
      int32_t l_936[2][6] = {{0L, 0L, (-3L), 0L, 0L, (-3L)},
                             {0L, 0L, (-3L), 0L, 0L, (-3L)}};
      int i, j;
      l_801[7][5] = p_35;
      for (g_777 = 0; (g_777 <= 7); g_777 += 1) {
        int i, j;
        g_120[3] = l_801[g_777][g_777];
        l_821[6][1] = (safe_rshift_func_uint8_t_u_s(
            (safe_lshift_func_uint8_t_u_u(
                (g_97[2],
                 (safe_lshift_func_int16_t_s_u(
                     (((safe_rshift_func_int16_t_s_u(
                           (safe_add_func_uint8_t_u_u(
                               (4294967286UL != 0x9CDCB11EL),
                               ((l_801[g_777][g_777] ^
                                 (g_89 ==
                                  (safe_mod_func_int16_t_s_s(
                                      ((((2UL |
                                          (safe_mod_func_int8_t_s_s(
                                              (p_34 ||
                                               ((safe_add_func_int16_t_s_s(
                                                    (g_97[2], (0x978C1B61L >
                                                               4294967291UL)),
                                                    l_820)) < 0xB988L)),
                                              p_34))) ||
                                         l_790) >= p_35) == 0x1F887AC6L),
                                      p_34)))) > 6UL))),
                           6)) != g_694) <= l_801[7][5]),
                     p_35))),
                3)),
            l_801[7][5]));
      }
      if ((0x4DF543CEL && l_790)) {
        uint32_t l_847 = 0xB97BAC9CL;
        for (g_89 = 0; (g_89 >= (-10)); g_89--) {
          const uint32_t l_845 = 0xB19552AFL;
          l_846 =
              (((safe_sub_func_int8_t_s_s(
                    0x65L,
                    (safe_unary_minus_func_int8_t_s((+(
                        g_97[2] <
                        (safe_add_func_uint32_t_u_u(
                            ((safe_rshift_func_int8_t_s_u(
                                 ((p_34 >= g_100) || l_790),
                                 (((safe_sub_func_uint16_t_u_u(
                                       ((((safe_rshift_func_uint8_t_u_s(
                                              ((((safe_sub_func_int32_t_s_s(
                                                     (safe_mod_func_uint8_t_u_u(
                                                         p_34,
                                                         (safe_add_func_uint32_t_u_u(
                                                             l_801[7][1],
                                                             (~((l_790 <=
                                                                 (0xCC872D8FL ==
                                                                  4UL)) &&
                                                                g_120[1])))))),
                                                     p_35)) &
                                                 l_843) &
                                                p_35) ^
                                               g_143),
                                              g_97[2])) < (-1L)) >=
                                         0x60360610L) ^
                                        0x1EL),
                                       0xBA9AL)),
                                   l_844),
                                  p_34))) == 3L),
                            4294967295UL)))))))) <= l_845) != p_35);
          if (l_847)
            break;
          if (p_35)
            continue;
        }
        g_120[1] = 0x53887F5CL;
      } else {
        uint16_t l_875 = 6UL;
        int32_t l_881 = 0L;
        int32_t l_884[2][7] = {{0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L,
                                0xB1F54B37L, (-9L), 0xB1F54B37L},
                               {0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L,
                                0xB1F54B37L, (-9L), 0xB1F54B37L}};
        uint16_t l_953 = 0x2EE0L;
        int i, j;
        g_849[0]--;
        for (l_848 = 0; (l_848 >= 0); l_848 -= 1) {
          int32_t l_876 = 1L;
          int i;
          if ((safe_lshift_func_uint16_t_u_s(
                  (+(safe_sub_func_uint8_t_u_u(g_849[l_848], p_35))), 8))) {
            g_120[1] = 0xB8ED6298L;
            if (p_35)
              continue;
            l_846 &= (safe_mod_func_uint32_t_u_u(p_35, 0xE4729DD1L));
          } else {
            uint16_t l_861 = 0x987DL;
            g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);
            return g_849[l_848];
          }
          for (g_777 = 0; (g_777 <= 3); g_777 += 1) {
            uint8_t l_870 = 0x7BL;
            int32_t l_882 = (-8L);
            int32_t l_883 = (-1L);
            l_875 &=
                ((g_120[3],
                  (safe_add_func_int32_t_s_s(
                      (((((g_849[0] &
                           ((safe_sub_func_uint16_t_u_u(
                                g_120[4],
                                ((safe_sub_func_int32_t_s_s(
                                     ((safe_sub_func_uint16_t_u_u(
                                          l_790,
                                          (l_870 &
                                           (safe_mod_func_uint32_t_u_u(
                                               ((l_844 != (g_97[0] || g_97[3])),
                                                (safe_lshift_func_int8_t_s_u(
                                                    (g_120[1], l_820), g_22))),
                                               p_34))))),
                                      g_18),
                                     4294967295UL)),
                                 p_34))) ||
                            g_22)) ^
                          p_34) &
                         g_143) != g_777) &
                       p_35),
                      l_870))) > 8UL);
            l_877[2][0]--;
            --l_885;
          }
          g_120[1] =
              (((safe_lshift_func_int8_t_s_u((-7L), 4)), 1UL) <=
               (safe_lshift_func_uint16_t_u_u(
                   ((g_97[5] >= p_35) <
                    (safe_sub_func_uint8_t_u_u(
                        p_35,
                        (+((+(safe_mod_func_int16_t_s_s(
                               ((((g_717 ==
                                   (safe_lshift_func_int16_t_s_s(
                                       ((safe_rshift_func_uint8_t_u_u(
                                            ((safe_lshift_func_uint8_t_u_s(
                                                 (((((safe_rshift_func_uint8_t_u_u(
                                                         0xA3L, 3)) <=
                                                     (((safe_sub_func_uint8_t_u_u(
                                                           (g_101 ^
                                                            (((g_97[2] <=
                                                               7UL) >=
                                                              0x5416L) <
                                                             g_777)),
                                                           l_846)) < (-3L)),
                                                      p_34)) &
                                                    0x514BL) == 0x4A10A230L) >
                                                  1UL),
                                                 g_717)) &
                                             0x80BDL),
                                            1)) <= 0xB0L),
                                       g_849[0]))) == p_34) ^
                                 p_35) == p_34),
                               0xC7B8L))) < l_877[0][0]))))),
                   5)));
        }
        l_778 =
            ((g_97[2] >
              ((safe_mod_func_uint16_t_u_u(
                   (p_34 < p_34),
                   (safe_mod_func_int16_t_s_s(
                       ((safe_add_func_uint8_t_u_u(
                            (l_885,
                             (safe_mod_func_uint8_t_u_u(
                                 ((((~((l_778 & 0x0E4E5FD7L) ^
                                       ((((l_844 ==
                                           ((((g_22 |
                                               ((((((safe_rshift_func_uint8_t_u_s(
                                                        g_22, p_34)) &
                                                    0xC189E11AL) > 0x02171C1CL),
                                                  p_34) < g_97[2]),
                                                0xABAFL)) &&
                                              0x0FL),
                                             0x444BL) >= 9L)),
                                          0xCAB1L) ||
                                         g_101) &&
                                        0x2CF198DBL))) ^
                                    7UL),
                                   0x5D7CL) ^
                                  l_919),
                                 g_18))),
                            p_34)),
                        g_143),
                       p_35)))) ^
               (-1L))) <= 0x08L);
        for (l_919 = 0; (l_919 != (-11)); --l_919) {
          uint8_t l_923 = 0UL;
          int32_t l_937 = 0xB482D4E8L;
          int32_t l_938 = 0x297BE1A5L;
          int32_t l_939 = 0xFF539210L;
          int32_t l_1001 = 0x1C89D44EL;
          ++l_923;
          if ((((-1L) !=
                ((safe_sub_func_uint8_t_u_u(
                     l_820,
                     (~((p_34 ||
                         ((safe_lshift_func_int8_t_s_s(
                              l_844,
                              ((~0xB7L) &
                               (((~(safe_rshift_func_uint8_t_u_u(
                                     0xD5L, ((g_100, g_849[0]) == g_100)))) ||
                                 p_34) &
                                l_820)))),
                          g_935)) == 0xDBB7L)))) <= g_100)) != l_936[0][5])) {
            g_120[1] = l_725[2];
            --l_940[0];
          } else {
            int32_t l_956 = 0xA1C5A82EL;
            g_120[1] =
                ((((((g_849[0] ^ l_801[6][9]) & 0x3A09L) ==
                    ((g_97[3] ==
                      (safe_lshift_func_uint8_t_u_s(
                          (((p_34,
                             (p_35 <
                              ((g_935 ||
                                (((((safe_mod_func_int16_t_s_s(
                                        (((safe_mod_func_int8_t_s_s(
                                              (safe_lshift_func_uint8_t_u_u(
                                                  (((safe_mod_func_uint16_t_u_u(
                                                        g_120[0], g_935)) &
                                                    p_35) != l_938),
                                                  2)),
                                              g_849[0])) <= l_953) ||
                                         l_953),
                                        p_35)) <= l_801[7][5]) ||
                                   0xFCA679B8L) == g_120[1]) > l_801[0][3])) ||
                               l_923))) != l_953),
                           l_821[6][1]),
                          p_34))) < 0xABL)) == 65535UL),
                  0x310916CAL),
                 g_120[0]);
            l_884[0][0] =
                ((safe_sub_func_int8_t_s_s(
                     l_956,
                     ((safe_sub_func_uint32_t_u_u(
                          (safe_add_func_int8_t_s_s(
                              (((((safe_add_func_int8_t_s_s(
                                      (((safe_mod_func_int8_t_s_s(
                                            g_89, (p_34 ^ 0x4C3BL))) &
                                        ((+p_34) == (1L < g_100))) ||
                                       (((safe_add_func_int8_t_s_s(
                                             (((l_725[0] &
                                                ((+(-5L)) >= 0xEFL)) < l_820),
                                              (-9L)),
                                             0x84L)) >= l_936[0][5]) >
                                        0x4C33D59BL)),
                                      g_143)) ^
                                  g_849[0]) ^
                                 1L) ^
                                l_843) > g_540),
                              g_540)),
                          g_97[2])) |
                      0x0AD02AAFL))),
                 (-1L));
                        l_821[3][2] = (((safe_rshift_func_uint8_t_u_s((((p_35 <= 0xDED1L) == (g_935 ^ ((safe_add_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s(((l_980 == (safe_rshift_func_uint16_t_u_u(0x5CC1L, ((safe_lshift_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_u((((g_97[2] == ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u(g_97[2], (((p_34 || (((safe_rshift_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u(0x04849C4EL, p_34)) <= p_34) <= l_937) ^ g_120[1]), g_540)) > l_956) , l_939)) <= 7L) == g_18))) != g_22), g_89)) >= g_694)) < 255UL) != g_89), 1)), g_694)) != g_143) , l_923) > 8L), p_34)), 9)) , 0xB22CL)))) > 0xD0D7BB55L), 7)), 3UL)) == p_34) | p_34), l_884[0][5])))) ^ l_880), l_956)) <= p_34))) >= p_34), 1)) , 0xE75EL) == 0x5EECL);
          }
          g_120[1] ^= (safe_add_func_uint32_t_u_u(l_939, l_938));
          return l_1001;
        }
      }
      for (g_143 = 17; (g_143 <= 34);
           g_143 = safe_add_func_int32_t_s_s(g_143, 2)) {
        uint32_t l_1004 = 0x3C1B13C2L;
        if (p_35)
          break;
        if (l_1004)
          break;
      }
    }
    for (l_922 = (-29); (l_922 != (-3)); l_922++) {
      l_1007--;
      if (g_540)
        continue;
      for (g_101 = 0; (g_101 == (-12));
           g_101 = safe_sub_func_int8_t_s_s(g_101, 2)) {
        return g_849[0];
      }
    }
        l_793 = ((p_34 || (l_801[6][3] & g_849[0])) > (safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(p_35, (safe_mod_func_int8_t_s_s(((((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s(p_35, (+((safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((+((safe_mod_func_int16_t_s_s(((((safe_add_func_int8_t_s_s((g_18 ^ (safe_add_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_s(((l_821[6][1] ^ ((((((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((0x5FBED003L || ((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s((-5L), 0)), 5)) != l_790)), p_34)), l_1046)) < 0x3EL) , 0xE788D646L) == l_801[3][2]) , l_725[2]) || l_801[5][3])) || 0x23L), l_801[7][5])) , 0x32L) & 255UL) || p_34) && p_34), l_877[2][0])) , l_1046) , g_89), 0x67L))), 0UL)) >= 0x78D41AC2L) , p_35) ^ 255UL), l_725[2])) , 0x1712L)) , l_919) , p_35), p_34)), l_1046)) && g_143)))), p_34)) ^ g_777) , p_35) , g_849[0]), l_793)))), p_35)));
  } else {
    int32_t l_1051[4] = {0x0A2DD9A0L, 0L, 0x0A2DD9A0L, 0L};
    int32_t l_1081 = 1L;
    int32_t l_1226[1][2][5] = {
        {{0L, (-1L), 0L, (-1L), 0L}, {0L, (-1L), 0L, (-1L), 0L}}};
    int32_t l_1273 = 0x20573342L;
    int32_t l_1359 = 0x441BD344L;
    uint8_t l_1361 = 0x58L;
    int32_t l_1369 = (-7L);
    int i, j, k;
    l_1051[0] = (safe_lshift_func_uint16_t_u_s(
        (safe_lshift_func_int8_t_s_s(g_935, 1)), 14));
    l_1052 |= l_940[3];
    for (g_777 = 0; (g_777 > 1); ++g_777) {
      uint8_t l_1069 = 1UL;
      int8_t l_1216 = 0xBDL;
      int32_t l_1219 = 0x1BE859F7L;
      int32_t l_1224 = 7L;
      int32_t l_1227 = (-6L);
      int32_t l_1228 = 0x1EE42556L;
      int32_t l_1229 = 0xD31B29F5L;
      int32_t l_1231[6];
      uint32_t l_1233 = 1UL;
      int i;
      for (i = 0; i < 6; i++)
        l_1231[i] = 7L;
      if ((p_34,
           (((safe_add_func_uint8_t_u_u(
                 (safe_sub_func_int32_t_s_s(
                     (safe_sub_func_int32_t_s_s(
                         ((-3L) ==
                          ((safe_add_func_uint16_t_u_u(
                               (safe_rshift_func_uint16_t_u_s(0x6B9EL, p_34)),
                               ((safe_add_func_int32_t_s_s(
                                    (safe_mod_func_int16_t_s_s(
                                        (((l_1069,
                                           ((((~(l_1051[0],
                                                 ((safe_add_func_uint16_t_u_u(
                                                      ((safe_sub_func_uint32_t_u_u(
                                                           (((p_35 >=
                                                              (~((0x941CB444L |
                                                                  g_849[0]) ||
                                                                 g_18))) <
                                                             p_34) ==
                                                            l_1051[0]),
                                                           1UL)) <= p_34),
                                                      p_35)) > g_935))) ==
                                              6L) <= 0L),
                                            g_935)) &
                                          5L),
                                         p_34),
                                        1UL)),
                                    4294967288UL)) >= l_793))) != p_34)),
                         0xFF1D970AL)),
                     1L)),
                 p_34)),
             g_717) &
            g_935))) {
        uint8_t l_1080 = 1UL;
        l_919 = (safe_sub_func_uint32_t_u_u(
            (safe_sub_func_uint32_t_u_u(1UL, l_1051[3])),
            ((g_849[0] < l_1069) != (1L > g_89))));
        g_120[1] = ((g_849[0] || 0xD3L) <= l_919);
        if (l_1080)
          break;
        if (l_1069)
          break;
      } else {
        int16_t l_1094 = 0xECC4L;
        int32_t l_1149[2];
        int16_t l_1163[7][10];
        int i, j;
        for (i = 0; i < 2; i++)
          l_1149[i] = 0xBA560EB5L;
        for (i = 0; i < 7; i++) {
          for (j = 0; j < 10; j++)
            l_1163[i][j] = 6L;
        }
        l_1081 = (p_35 == p_35);
        for (g_935 = 16; (g_935 != (-28));
             g_935 = safe_sub_func_int16_t_s_s(g_935, 5)) {
          int32_t l_1095 = (-6L);
          for (g_143 = 0; (g_143 <= 0); g_143 += 1) {
            int i, j;
            return l_877[g_143][g_143];
          }
          l_1095 = ((((g_120[1] || (-5L)) &&
                      ((((safe_lshift_func_int16_t_s_u(
                             (((safe_rshift_func_int16_t_s_u(
                                   (p_35 ||
                                    (((0xBBL ^
                                       (safe_mod_func_uint8_t_u_u(
                                           (safe_sub_func_uint8_t_u_u(
                                               g_120[1],
                                               (((((-1L) > (g_777, 1L)),
                                                  ((safe_add_func_int16_t_s_s(
                                                       p_34, p_34)) &
                                                   4294967289UL)) <= p_34) !=
                                                l_1069))),
                                           g_120[1]))) |
                                      p_35) == p_35)),
                                   p_34)) >= 0x20L),
                              0x45CAL),
                             p_35)) > (-2L)) <= 0x8BB0L) < l_1094)),
                     l_1069) ^
                    g_101);
          for (l_919 = 0; (l_919 <= 0); l_919 += 1) {
            int i, j;
            g_120[2] = l_877[l_919][l_919];
          }
        }
        if ((p_34, p_34)) {
          uint16_t l_1101[10] = {0xEA04L, 0xEA04L, 0UL,     0xEA04L, 0xEA04L,
                                 0UL,     0xEA04L, 0xEA04L, 0UL,     0xEA04L};
          int i;
          if (g_717)
            break;
          if ((safe_add_func_int8_t_s_s(
                  (safe_add_func_int8_t_s_s(
                      (((p_35 ==
                         ((((((((!((p_34 ^
                                    (l_1069 ||
                                     ((l_1101[9] &
                                       ((-7L) |
                                        ((((safe_sub_func_uint8_t_u_u(
                                               p_35,
                                               (safe_add_func_uint32_t_u_u(
                                                   g_143, 0x1CB4D9C6L)))) &&
                                           g_717) >= l_877[2][0]) >= p_34))) <=
                                      g_22))) <= 4L)),
                                p_34) ||
                               p_34) != p_34),
                             p_35),
                            0xDF52L),
                           g_100) ^
                          l_1069)) ||
                        g_89),
                       0L),
                      255UL)),
                  p_34))) {
            uint16_t l_1114[5][1][4] = {{{0x8B41L, 0x38EFL, 1UL, 0x38EFL}},
                                        {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}},
                                        {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}},
                                        {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}},
                                        {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}};
            int i, j, k;
            l_922 =
                ((safe_sub_func_uint8_t_u_u(
                     (safe_sub_func_int32_t_s_s(p_35, (8L & (-1L)))), 5UL)) ^
                 (safe_sub_func_uint32_t_u_u(
                     (0x9B71DE32L ^ (p_34 < p_34)),
                     (+(((l_1101[9] != g_120[0]) <= 0x33L), l_1051[0])))));
            g_120[1] ^=
                (((((!((l_1114[4][0][3] ==
                        (safe_mod_func_uint32_t_u_u(
                            ((((safe_lshift_func_int8_t_s_s(
                                   (safe_add_func_int16_t_s_s(
                                       (+((!(g_849[0] > g_89)) ^ 0x0043E281L)),
                                       (g_97[2] >= g_143))),
                                   ((safe_sub_func_int8_t_s_s(
                                        (~((((safe_mod_func_uint16_t_u_u(
                                                 (0xC6L || 0x36L), p_34)) &
                                             0x68L) ||
                                            g_540),
                                           l_1051[0])),
                                        l_1094)) != 0x2E20L))) ||
                               p_34) |
                              l_1094) &
                             p_35),
                            p_34))) > 1UL)) < 1UL) > p_35) > 0x5E87ADE6L) ==
                 0x38C86F29L);
          } else {
            int8_t l_1148 = 0x89L;
            l_1149[1] =
                ((0x88L >
                  ((((g_935 ||
                      (safe_mod_func_uint32_t_u_u(
                          p_34,
                          (safe_add_func_int32_t_s_s(
                              ((safe_lshift_func_int8_t_s_u(
                                   (safe_mod_func_uint16_t_u_u(
                                       ((safe_mod_func_int32_t_s_s(
                                            (safe_sub_func_uint16_t_u_u(
                                                ((p_34,
                                                  (0L ^
                                                   (((safe_add_func_int8_t_s_s(
                                                         ((safe_add_func_int16_t_s_s(
                                                              (safe_lshift_func_uint16_t_u_s(
                                                                  p_35,
                                                                  ((g_97[2] |
                                                                    0x826CL) <
                                                                   ((((safe_rshift_func_uint8_t_u_s(
                                                                          g_22,
                                                                          p_35)) <=
                                                                      253UL) |
                                                                     l_1094) >=
                                                                    l_1148)))),
                                                              p_34)) < g_22),
                                                         l_1148)) ||
                                                     g_97[2]) |
                                                    0x9933L))) ||
                                                 g_143),
                                                0L)),
                                            p_34)) >= 0x23DDBF23L),
                                       g_100)),
                                   1)) &&
                               l_1069),
                              0x57543A32L))))) != 1L),
                    p_34) |
                   4294967295UL)) ^
                 0xB771L);
            if (g_101)
              break;
            g_120[1] = (safe_mod_func_int16_t_s_s(
                (((((safe_lshift_func_int8_t_s_s(
                        (((safe_sub_func_uint32_t_u_u(
                              (((((safe_mod_func_int16_t_s_s(
                                      0L,
                                      (((((+65533UL) >
                                          ((safe_mod_func_uint32_t_u_u(
                                               (safe_add_func_int16_t_s_s(
                                                   ((l_1149[1],
                                                     ((g_59 >= p_35) >=
                                                      (l_1163[1][2] ||
                                                       (((safe_sub_func_int16_t_s_s(
                                                             (g_935 !=
                                                              (l_1101[9] >=
                                                               (l_1051[2] ==
                                                                4294967295UL))),
                                                             p_34)) ^
                                                         g_143) &
                                                        p_35)))) &&
                                                    p_35),
                                                   g_935)),
                                               l_1051[1])) > 2L)) ||
                                         g_101) < g_1168),
                                       l_1081))) < p_34) &&
                                 g_540) ^
                                0x5443L) < g_777),
                              p_35)),
                          l_1149[0]),
                         p_35),
                        2)) != l_1101[6]) <= p_35),
                  p_34) >= l_1094),
                g_18));
          }
          l_919 = (safe_rshift_func_int8_t_s_s((l_1081 ^ 4294967295UL), 0));
        } else {
          for (g_100 = 3; (g_100 >= 1); g_100 -= 1) {
            int i;
            if (g_120[g_100])
              break;
            if (l_725[g_100])
              break;
            return p_35;
          }
        }
      }
      if (g_1171) {
        uint16_t l_1172 = 0x80D0L;
        l_922 &=
            ((((p_34 >= l_1172) &&
               (g_849[0],
                (((((0x4E57L !=
                     (safe_unary_minus_func_uint8_t_u((
                         ((((safe_sub_func_uint16_t_u_u(
                                ((safe_sub_func_int16_t_s_s(
                                     (!((safe_unary_minus_func_uint16_t_u(
                                            p_35)) |
                                        p_34)),
                                     (safe_rshift_func_int16_t_s_u(
                                         (safe_sub_func_uint16_t_u_u(
                                             (safe_sub_func_uint8_t_u_u(
                                                 0UL,
                                                 ((l_1069,
                                                   (safe_sub_func_int32_t_s_s(
                                                       (((((safe_add_func_int8_t_s_s(
                                                               (((!g_1171),
                                                                 g_935) <=
                                                                l_725[0]),
                                                               g_101)) !=
                                                           l_1172) >
                                                          l_1191[1]) < l_1172) &
                                                        0UL),
                                                       0x349E8373L))) |
                                                  g_935))),
                                             g_22)),
                                         p_35)))) &
                                 g_59),
                                (-5L))) < l_1069),
                           g_849[0]) |
                          l_1172) >= l_1069)))) &&
                    g_694) != 0UL) |
                  g_777) |
                 0x7351L))) &
              l_725[3]),
             g_22);
        g_1217 |=
            ((safe_mod_func_int16_t_s_s(
                 (-4L),
                 (safe_mod_func_uint8_t_u_u(
                     (safe_sub_func_uint8_t_u_u(
                         (((safe_add_func_int16_t_s_s(
                               (safe_lshift_func_int16_t_s_u(
                                   (safe_mod_func_int32_t_s_s(
                                       (((((safe_lshift_func_int8_t_s_u(
                                               g_849[0], (!0xE43BDF21L))) ||
                                           ((((((safe_lshift_func_int16_t_s_s(
                                                    (safe_rshift_func_int8_t_s_u(
                                                        (~(safe_lshift_func_int16_t_s_s(
                                                            p_34, 11))),
                                                        6)),
                                                    6)),
                                                0x9037L) ||
                                               g_1168) ^
                                              ((p_35 &
                                                (p_34 &&
                                                 (safe_rshift_func_uint8_t_u_s(
                                                     p_34, g_143)))) !=
                                               l_1081)) >= g_1168) &&
                                            g_849[0])) > g_120[1]),
                                         0xB8L) ^
                                        p_34),
                                       4294967295UL)),
                                   g_89)),
                               (-1L))) <= g_89) ^
                          l_1069),
                         l_1172)),
                     0xFBL)))) > l_1216);
      } else {
        int32_t l_1218 = 0L;
        int32_t l_1220 = 0xD6A84518L;
        int32_t l_1221 = 0x3E2F8B07L;
        int32_t l_1222 = 0xBC228DECL;
        int32_t l_1223 = 0L;
        int32_t l_1225 = 0x92788A2FL;
        int32_t l_1230 = 0x8A193837L;
        int32_t l_1232[1][1];
        int i, j;
        for (i = 0; i < 1; i++) {
          for (j = 0; j < 1; j++)
            l_1232[i][j] = 0xBE2CE0ADL;
        }
        l_1233++;
      }
      if (g_777) {
        uint32_t l_1241[4][8] = {{0x92359C80L, 18446744073709551615UL, 1UL, 5UL,
                                  0xE2F39250L, 1UL, 0xE2F39250L, 5UL},
                                 {0x92359C80L, 18446744073709551615UL, 1UL, 5UL,
                                  0xE2F39250L, 1UL, 0xE2F39250L, 5UL},
                                 {0x92359C80L, 18446744073709551615UL, 1UL, 5UL,
                                  0xE2F39250L, 1UL, 0xE2F39250L, 5UL},
                                 {0x92359C80L, 18446744073709551615UL, 1UL, 5UL,
                                  0xE2F39250L, 1UL, 0xE2F39250L, 5UL}};
        uint16_t l_1252 = 0x759AL;
        int i, j;
        g_120[4] |=
            ((safe_lshift_func_uint16_t_u_s(6UL, 8)),
             ((safe_unary_minus_func_int32_t_s((safe_sub_func_int16_t_s_s(
                  (((((l_1241[2][6] | 0L) &
                      ((((safe_rshift_func_uint16_t_u_u(
                             ((safe_unary_minus_func_int16_t_s(l_1191[0])) &
                              (p_34,
                               (((((safe_rshift_func_uint16_t_u_u(
                                       (safe_lshift_func_uint16_t_u_u(
                                           (p_34,
                                            (safe_add_func_int16_t_s_s(
                                                (((~l_1252),
                                                  (safe_add_func_uint16_t_u_u(
                                                      (((((g_18 |
                                                           (safe_lshift_func_uint16_t_u_s(
                                                               (safe_add_func_uint8_t_u_u(
                                                                   ((((0x1CA4L <
                                                                       p_34) &&
                                                                      g_89) |
                                                                     g_97[2]) ^
                                                                    p_35),
                                                                   p_35)),
                                                               p_34))) !=
                                                          p_34) ||
                                                         g_717) > l_1051[2]),
                                                       0x6DB4L),
                                                      l_778))) ||
                                                 p_34),
                                                0x5D57L))),
                                           g_97[2])),
                                       l_1219)) ||
                                   1UL) ||
                                  p_35) |
                                 p_34) != g_849[0]))),
                             l_790)) &&
                         1L) > 0x1DC0L),
                       p_35)) != 0x35A6L) ||
                    0xE981L) |
                   g_777),
                  1L)))),
              g_777));
      } else {
        uint16_t l_1263[6][10] = {{0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL,
                                   0x6DABL, 0xE2A8L, 0UL, 0xE2A8L},
                                  {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL,
                                   0x6DABL, 0xE2A8L, 0UL, 0xE2A8L},
                                  {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL,
                                   0x6DABL, 0xE2A8L, 0UL, 0xE2A8L},
                                  {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL,
                                   0x6DABL, 0xE2A8L, 0UL, 0xE2A8L},
                                  {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL,
                                   0x6DABL, 0xE2A8L, 0UL, 0xE2A8L},
                                  {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL,
                                   0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}};
        int32_t l_1277[9];
        int16_t l_1321 = 0x3AFEL;
        int i, j;
        for (i = 0; i < 9; i++)
          l_1277[i] = (-1L);
        for (l_922 = 0; (l_922 <= (-8)); --l_922) {
          uint8_t l_1265 = 0xA0L;
          int32_t l_1272 = 0xA92A5564L;
          uint8_t l_1274 = 1UL;
          int32_t l_1325 = 0x05F0F06DL;
          int32_t l_1326 = 0xA526867EL;
          int8_t l_1360 = 0xE8L;
          if (((safe_rshift_func_int16_t_s_s(
                   1L, (g_717 <
                        ((l_1263[4][9] && (!(l_1265 || p_35))),
                         ((((p_35, (safe_sub_func_uint8_t_u_u(
                                       ((safe_lshift_func_int16_t_s_u(
                                            ((((safe_lshift_func_uint8_t_u_u(
                                                   g_97[2], 2)) >= g_100) |
                                              8L),
                                             g_143),
                                            g_849[0])) ^
                                        g_120[1]),
                                       p_34))) == g_18) >= g_101) <
                          l_1263[0][9]))))) >= l_1081)) {
            uint32_t l_1278 = 0x7A1781B4L;
            l_1274--;
            l_1278--;
          } else {
            uint8_t l_1292 = 255UL;
            int32_t l_1301 = 0L;
            l_1281 ^= 0x10E3B930L;
            l_1277[4] &= (safe_rshift_func_int16_t_s_u(
                (safe_mod_func_uint16_t_u_u(
                    (9UL ||
                     ((g_849[0] < ((g_1217 >= g_849[0]) || g_935)),
                      (((safe_sub_func_int16_t_s_s(
                            (safe_sub_func_int8_t_s_s(
                                0xDDL,
                                (0UL ^
                                 (safe_lshift_func_uint16_t_u_u(
                                     ((l_1292 <=
                                       (safe_lshift_func_uint16_t_u_s(
                                           (safe_rshift_func_uint16_t_u_u(
                                               (safe_add_func_uint32_t_u_u(
                                                   (safe_mod_func_uint32_t_u_u(
                                                       (g_777 & (-1L)), g_59)),
                                                   l_1219)),
                                               7)),
                                           p_35))),
                                      g_143),
                                     1))))),
                            0UL)) &
                        p_35) ||
                       p_34))),
                    l_940[0])),
                p_35));
            l_1301 = 0x9FC577ABL;
          }
          for (l_790 = 0; (l_790 >= 7);
               l_790 = safe_add_func_uint8_t_u_u(l_790, 3)) {
            return p_35;
          }
          if ((p_35,
               (((safe_add_func_int8_t_s_s(
                     (safe_lshift_func_int8_t_s_u(p_35, 3)),
                     ((l_1277[4],
                       (safe_rshift_func_uint8_t_u_u(
                           g_540,
                           (safe_lshift_func_int8_t_s_s(
                               (l_1052 >
                                (safe_add_func_uint16_t_u_u(
                                    p_34,
                                    (((~(safe_add_func_uint8_t_u_u(
                                          (((p_35 >=
                                             (safe_mod_func_uint16_t_u_u(
                                                 ((safe_sub_func_int8_t_s_s(
                                                      g_97[0],
                                                      (g_849[0], l_1321))) ||
                                                  p_34),
                                                 g_143))) &&
                                            l_1229) ^
                                           p_35),
                                          l_1081))) &&
                                      l_1226[0][1][2]),
                                     p_34)))),
                               5))))) >= p_34))) >= 65527UL) == l_1277[4]))) {
            uint32_t l_1322 = 1UL;
            int32_t l_1328[3];
            uint16_t l_1330[7][2] = {{1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL},
                                     {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL},
                                     {1UL, 0UL}};
            int i, j;
            for (i = 0; i < 3; i++)
              l_1328[i] = 5L;
            --l_1322;
            l_1330[3][0]++;
            if (l_1326)
              continue;
          } else {
            int32_t l_1333[3];
            int i;
            for (i = 0; i < 3; i++)
              l_1333[i] = 8L;
            l_1333[2] = p_34;
            g_120[3] = (safe_lshift_func_uint16_t_u_s(
                (safe_rshift_func_uint16_t_u_u(0x461CL, 7)),
                (l_1051[0] <
                 (g_777 <
                  (safe_add_func_uint16_t_u_u(
                      ((0x1114L | g_100) !=
                       (safe_mod_func_uint32_t_u_u(
                           (safe_mod_func_int16_t_s_s(
                               g_1217,
                               (safe_add_func_uint16_t_u_u(
                                   ((safe_rshift_func_int16_t_s_u(
                                        ((((-1L) ^
                                           (safe_add_func_int8_t_s_s(
                                               ((0x17D87BE6L !=
                                                 (safe_rshift_func_int8_t_s_s(
                                                     ((safe_unary_minus_func_uint32_t_u(
                                                          (!g_143))) ^
                                                      0x50L),
                                                     g_540))) ^
                                                p_35),
                                               p_35))) < 8UL),
                                         g_1171),
                                        14)),
                                    l_1329),
                                   l_922)))),
                           0x45D6E44FL))),
                      g_22))))));
          }
          if ((g_717 >=
               ((l_1051[0] != (((p_35 == (g_849[0] ^ (l_1265 > p_34))) <
                                p_35) == g_849[0])) <=
                (safe_lshift_func_uint8_t_u_s(
                    ((safe_lshift_func_int8_t_s_u(p_34, g_89)), 0xF4L), 2))))) {
            l_1277[4] = p_35;
          } else {
            int32_t l_1358 = 0x27225A3DL;
            --l_1361;
            if (g_22)
              break;
          }
        }
      }
      for (l_1281 = (-1); (l_1281 == 31); ++l_1281) {
        l_1081 ^= ((safe_add_func_int8_t_s_s(l_1359, 1L)) <
                   (p_34 != (((((-2L) > g_18),
                               (((g_89 != 0xAEL) &
                                 ((((g_1368[1] > (g_1168 <= p_35)) & l_1359) ==
                                   g_97[5]) > l_1369)) == 4294967286UL)),
                              (-1L)) ^
                             255UL)));
      }
    }
    g_120[1] = (safe_sub_func_uint16_t_u_u(
        ((0x68DCACFFL |
          (safe_sub_func_int8_t_s_s(
              (((((safe_mod_func_uint32_t_u_u(
                      ((((((g_97[2], (safe_lshift_func_int16_t_s_u(
                                         (g_1368[2] && 0L), 0))) |
                           ((l_1361 &&
                             (safe_mod_func_int8_t_s_s(
                                 (p_35 &&
                                  (safe_rshift_func_int16_t_s_s(
                                      (((((((~(((safe_add_func_uint16_t_u_u(
                                                    ((((safe_lshift_func_uint8_t_u_u(
                                                           (((safe_add_func_uint8_t_u_u(
                                                                 l_1369,
                                                                 p_34)) &&
                                                             ((((1L !=
                                                                 0x1161L) !=
                                                                p_34) ^
                                                               l_980) ^
                                                              g_59)) < l_1361),
                                                           g_120[1])) >=
                                                       g_849[0]),
                                                      (-1L)) |
                                                     0x3F27L),
                                                    g_1368[0])),
                                                0x8D90L) ^
                                               g_1168)) ^
                                            l_725[2]) |
                                           0xC3L) &&
                                          g_1368[1]) <= p_34),
                                        l_1226[0][1][2]),
                                       l_1226[0][0][2]),
                                      2))),
                                 p_34))) <= l_1273)) >= 0x27L) >= g_97[6]) !=
                        2L) != 0x1C966BF2L),
                      g_1168)) |
                  (-3L)) < g_143) > p_35) == p_34),
              l_1191[1]))) <= g_717),
        8L));
  }
  for (g_100 = 4; (g_100 >= 0); g_100 -= 1) {
    int16_t l_1414 = 0x1AE5L;
    int32_t l_1416 = (-7L);
    for (g_1171 = 0; (g_1171 <= 0); g_1171 += 1) {
      int32_t l_1415 = (-1L);
      int i;
            l_1416 &= (g_120[g_100] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_100] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_1171] > ((((safe_add_func_int16_t_s_s(p_35, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_540, g_717)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_540)))), g_143)) , p_35), p_35)))) , g_120[g_100]) && g_22) ^ l_1414)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , p_35) ^ p_35) || p_35) ^ p_35) != g_120[1])), 4)), p_35)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= l_922) | g_100) && l_1191[1]) || g_18));
            return g_120[g_100];
    }
    l_1329 = p_35;
    l_1416 = (safe_add_func_int8_t_s_s(
        8L, ((safe_add_func_uint8_t_u_u(
                 ((safe_add_func_uint32_t_u_u(l_1423, g_1217)) &
                  ((0xA6F0F4F8L != (l_1414 == p_34)) &
                   (+(safe_add_func_uint16_t_u_u(l_1416, g_18))))),
                 (g_22, l_790))) > g_1368[0])));
    for (l_1416 = 0; (l_1416 >= 0); l_1416 -= 1) {
      int8_t l_1432 = (-1L);
      int32_t l_1440 = 0x9D9C4759L;
      l_1440 &=
          (((g_935 <
             (safe_add_func_uint8_t_u_u(
                 p_34, (((safe_unary_minus_func_int32_t_s(3L)), 250UL),
                        (safe_sub_func_uint8_t_u_u(
                            (((p_35 == l_1432),
                              ((l_1433 >
                                ((safe_lshift_func_int8_t_s_u(
                                     ((safe_mod_func_uint32_t_u_u(
                                          ((~((l_1423 ^ g_849[0]) >= g_1217)) ||
                                           g_22),
                                          (-6L))) ^
                                      g_849[0]),
                                     p_34)) >= l_1416)) |
                               0xA9A8L)) &
                             (-8L)),
                            l_1439[5])))))),
            6UL) &&
           g_120[1]);
    }
  }
  return g_97[6];
}

static int16_t func_38(int32_t p_39, int8_t p_40, uint16_t p_41, int16_t p_42,
                       uint16_t p_43) {
  uint8_t l_86 = 1UL;
  int32_t l_102 = 0xD37901A9L;
  int32_t l_213[6] = {0x32FFC17BL, 0x32FFC17BL, 1L,
                      0x32FFC17BL, 0x32FFC17BL, 1L};
  int32_t l_253 = 0x1789042DL;
  int16_t l_351 = (-8L);
  uint32_t l_396 = 18446744073709551609UL;
  uint32_t l_419 = 0UL;
  int16_t l_598[4];
  uint8_t l_613 = 0x0FL;
  uint8_t l_616 = 255UL;
  int8_t l_699 = 0x1AL;
  int i;
  for (i = 0; i < 4; i++)
    l_598[i] = 0xF69FL;
  for (p_42 = 0; (p_42 != 13); p_42++) {
    uint32_t l_83 = 0xB3DEF23EL;
    p_39 = p_39;
    g_89 =
        ((p_42 >
          ((((safe_add_func_int8_t_s_s(
                 (safe_lshift_func_uint8_t_u_u(
                     g_59,
                     (safe_rshift_func_uint16_t_u_s(
                         0xA4A7L,
                         (((l_83 ^ ((((p_41 ==
                                       ((safe_lshift_func_int16_t_s_u(
                                            ((((l_86 ||
                                                ((((p_40 <=
                                                    (safe_sub_func_uint8_t_u_u(
                                                        l_86, (g_18 ^ l_83)))) |
                                                   0x39L) <= p_43) &
                                                 0x3186L)) <= g_22),
                                              p_43) &
                                             1L),
                                            l_83)) ^
                                        65532UL)) &
                                      l_83) ||
                                     0x439AL) &&
                                    255UL)) == p_41) != g_18))))),
                 5L)) >= g_59) == g_18) != p_42)) <= p_43);
    return p_40;
  }
  for (p_43 = (-30); (p_43 <= 7); p_43++) {
    uint8_t l_121 = 0x0CL;
    int8_t l_296 = 0x7BL;
    int32_t l_368 = 0x73C1A89DL;
    uint16_t l_389 = 9UL;
    int32_t l_390 = 4L;
    int32_t l_394 = 0x0A309251L;
    int16_t l_472 = 1L;
    int32_t l_656 = 4L;
    for (l_86 = (-11); (l_86 >= 14); ++l_86) {
      int8_t l_94[2];
      uint32_t l_134 = 18446744073709551615UL;
      uint16_t l_142 = 0x7BCBL;
      int i;
      for (i = 0; i < 2; i++)
        l_94[i] = 1L;
      for (p_39 = 0; (p_39 <= 1); p_39 += 1) {
        int i;
        for (g_59 = 0; (g_59 <= 1); g_59 += 1) {
          int i;
          return l_94[p_39];
        }
        if (l_94[p_39])
          continue;
        if (l_94[0])
          continue;
      }
      for (g_89 = 0; (g_89 > (-19));
           g_89 = safe_sub_func_uint16_t_u_u(g_89, 7)) {
        uint8_t l_103[4] = {1UL, 0xABL, 1UL, 0xABL};
        int i;
        g_97[2] ^= p_43;
        for (g_22 = 1; (g_22 <= 6); g_22 += 1) {
          int16_t l_110[7] = {0xD96CL, (-2L), 0xD96CL, (-2L),
                              0xD96CL, (-2L), 0xD96CL};
          int8_t l_168 = 0xE9L;
          int8_t l_181 = 0xCFL;
          int i;
          for (p_40 = 6; (p_40 >= 1); p_40 -= 1) {
            int i;
            p_39 = (safe_mod_func_int32_t_s_s(g_97[p_40], l_86));
            g_100 = g_18;
            g_101 &= 0xEC293C97L;
          }
          l_103[3]++;
          if (((safe_rshift_func_int8_t_s_u(
                   (((((g_18 ^
                        ((safe_add_func_uint32_t_u_u(
                             (l_110[0] ==
                              (g_101 ==
                               (safe_mod_func_uint16_t_u_u(
                                   0UL,
                                   (((safe_unary_minus_func_uint16_t_u(g_89)) |
                                     (l_94[1],
                                      ((safe_add_func_uint16_t_u_u(
                                           ((((((safe_mod_func_int8_t_s_s(
                                                    p_41,
                                                    (safe_sub_func_uint8_t_u_u(
                                                        (g_120[1] >
                                                         (l_102 | p_41)),
                                                        p_41)))) ^
                                                g_59) ||
                                               0x17461B67L) &&
                                              g_97[2]) == 1L),
                                            g_18),
                                           g_120[4])),
                                       g_120[3]))) &
                                    g_89))))),
                             g_101)) > 0x3AD0L)) &
                       g_101) ||
                      p_40) != l_94[1]) == l_121),
                   g_18)) <= (-9L))) {
            int8_t l_141 = (-10L);
            g_143 ^=
                (g_97[6] <
                 (safe_mod_func_int16_t_s_s(
                     (((g_120[1] ^
                        ((safe_add_func_uint32_t_u_u(
                             ((g_101 <=
                               ((safe_sub_func_uint8_t_u_u(
                                    l_103[1],
                                    (((((((safe_sub_func_uint16_t_u_u(
                                              ((l_134 >= g_22) > 0UL),
                                              ((((((safe_sub_func_int32_t_s_s(
                                                       (((safe_add_func_uint8_t_u_u(
                                                             (((((((g_100 &
                                                                    (safe_lshift_func_uint8_t_u_u(
                                                                        (l_94[0] <=
                                                                         l_110
                                                                             [0]),
                                                                        g_101))) ||
                                                                   p_41) |
                                                                  0xF7L) &
                                                                 l_141),
                                                                0x6CL) |
                                                               g_100) <
                                                              l_94[1]),
                                                             l_103[3])) >=
                                                         l_86) > p_40),
                                                       1L)) ||
                                                   p_42) >= g_22),
                                                 l_86) > l_142) < g_22))) ==
                                          l_102),
                                         p_40) &&
                                        0x68L) &&
                                       l_121) >= l_110[0]) ^
                                     p_41))) != g_120[1])) != (-5L)),
                             0xB89AE2E4L)) > l_121)) > g_89) ||
                      0x3285CC41L),
                     g_97[2])));
          } else {
            int32_t l_167 = 0xBD733D80L;
            if (p_42)
              break;
            g_120[4] = (safe_rshift_func_int16_t_s_u(
                (safe_lshift_func_int16_t_s_u(
                    (safe_rshift_func_int16_t_s_s(
                        (safe_mod_func_uint8_t_u_u(
                            ((g_97[4] ^
                              (g_59 |
                               (safe_lshift_func_int16_t_s_u(
                                   (((safe_mod_func_int16_t_s_s(
                                         ((safe_rshift_func_int8_t_s_u(
                                              2L,
                                              ((+(((p_40,
                                                    ((safe_rshift_func_uint8_t_u_s(
                                                         ((l_103[3] >
                                                           ((((p_41 & 0x8D56L) >
                                                              (safe_lshift_func_uint8_t_u_s(
                                                                  (safe_add_func_uint8_t_u_u(
                                                                      (safe_sub_func_uint32_t_u_u(
                                                                          (65535UL ^
                                                                           (4L >=
                                                                            (-10L))),
                                                                          g_120
                                                                              [0])),
                                                                      p_40)),
                                                                  p_39))) ==
                                                             0xB673D79CL) ^
                                                            1L)) |
                                                          g_100),
                                                         l_103[3])) <=
                                                     l_102)) != (-8L)) <
                                                  l_167)) |
                                               g_59))),
                                          g_22),
                                         l_103[3])) ^
                                     0xBAC23114L) |
                                    l_110[0]),
                                   l_168)))) |
                             p_40),
                            (-2L))),
                        12)),
                    10)),
                g_100));
            g_120[4] =
                ((((safe_add_func_uint16_t_u_u(
                       ((safe_mod_func_int32_t_s_s(
                            (safe_lshift_func_uint8_t_u_s(
                                ((safe_lshift_func_uint8_t_u_s(
                                     ((255UL >= 254UL) <
                                      ((safe_mod_func_uint16_t_u_u(g_101,
                                                                   65531UL)) ||
                                       0x8F5F89A5L)),
                                     (((((+(((((~p_42) &
                                               ((p_43, l_168) <
                                                ((((((g_100 && p_40) &&
                                                     l_167) == p_40),
                                                   6L) ^
                                                  g_143),
                                                 0x9D48L))) < 0x5183DF78L),
                                             l_142) &
                                            1L)) != l_167) ||
                                        l_181) ||
                                       g_100) <= 4294967286UL))) ||
                                 0x76D7L),
                                1)),
                            p_39)) ||
                        0xFB851665L),
                       0x69F6L)) >= p_41),
                  0xDEBA2DDDL) <= l_121);
          }
        }
        for (g_59 = 0; (g_59 != 33); g_59++) {
          return p_41;
        }
        if (l_103[3])
          break;
      }
    }
    for (p_42 = 0; (p_42 < (-17)); --p_42) {
      uint8_t l_198 = 1UL;
      int16_t l_261 = (-10L);
      uint16_t l_350 = 5UL;
      int32_t l_367 = 1L;
      int32_t l_391[3][6] = {{0xD2D39850L, 1L, 1L, 0L, 0L, 1L},
                             {0xD2D39850L, 1L, 1L, 0L, 0L, 1L},
                             {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}};
      uint32_t l_431 = 0x13F79E03L;
      int i, j;
      if (l_121)
        break;
      p_39 ^= l_121;
      for (l_102 = 0; (l_102 == 26); ++l_102) {
        uint32_t l_210 = 0UL;
        int8_t l_281[8][7] = {{0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)},
                              {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}};
        uint32_t l_326 = 0x0A0DE782L;
        int32_t l_363 = 0L;
        int32_t l_392 = (-1L);
        int32_t l_395 = 0L;
        const uint32_t l_420 = 0xA82EA14BL;
        const int16_t l_427 = 0L;
        int i, j;
        if ((p_39 || (safe_mod_func_uint16_t_u_u(
                         ((safe_rshift_func_int8_t_s_u(0x73L, 5)) |
                          ((safe_mod_func_int32_t_s_s(
                               g_59, (safe_rshift_func_uint16_t_u_s(
                                         (safe_sub_func_int8_t_s_s(
                                             (((0x7CB8L < 0xB2B8L),
                                               ((l_198 ^ 0xDBL) != l_198)) &&
                                              0xD1L),
                                             l_86)),
                                         11)))) != p_39)),
                         0xA615L)))) {
          uint32_t l_207 = 0x44D27D01L;
          g_120[3] = p_42;
          for (g_143 = (-26); (g_143 >= 44); g_143++) {
            return l_198;
          }
          g_120[1] =
              (((((((g_120[1] && g_101) ||
                    ((safe_rshift_func_uint16_t_u_u(
                         ((p_41,
                           ((safe_mod_func_uint32_t_u_u(
                                ((safe_mod_func_uint16_t_u_u(
                                     ((((0x47C1L >= (g_89 ^ l_207)) <=
                                        (safe_sub_func_uint16_t_u_u(
                                            ((g_18 && p_43), l_121), l_121))) ^
                                       g_120[1]) < g_120[0]),
                                     g_120[1])) &
                                 g_97[2]),
                                0x3A8961DAL)) &
                            0L)),
                          p_42),
                         4)) &
                     g_120[1])) ^
                   p_39) == l_207) |
                 l_210) &
                0xD933A2BCL) &
               l_121);
        } else {
          uint8_t l_258 = 0x75L;
          int32_t l_262 = 0x18EC19C0L;
          for (g_143 = (-24); (g_143 < 42); ++g_143) {
            l_213[2] |= p_43;
            return l_198;
          }
          p_39 =
              ((0x5EL ||
                (safe_lshift_func_uint16_t_u_s(
                    (safe_sub_func_uint8_t_u_u(
                        (0x746C22C4L &&
                         (safe_add_func_int16_t_s_s(
                             ((p_41,
                               (safe_rshift_func_uint8_t_u_u(g_100, 6))) &&
                              (safe_add_func_uint8_t_u_u(
                                  p_42,
                                  (safe_lshift_func_int16_t_s_u(
                                      (((safe_rshift_func_int8_t_s_s(
                                            (safe_add_func_int8_t_s_s(
                                                ((g_89 ==
                                                  (((safe_sub_func_uint32_t_u_u(
                                                        ((l_198 || 0x50L) |
                                                         ((safe_sub_func_uint32_t_u_u(
                                                              (((l_213[2] ==
                                                                 p_40),
                                                                l_121) >=
                                                               g_101),
                                                              p_42)) ==
                                                          0xFF3A24CFL)),
                                                        0x3913078BL)) >= p_40),
                                                   1L)) != p_42),
                                                p_39)),
                                            p_39)) > g_101) |
                                       (-6L)),
                                      1))))),
                             g_120[2]))),
                        0L)),
                    15))) != p_39);
          for (l_86 = 0; (l_86 > 43);
               l_86 = safe_add_func_uint8_t_u_u(l_86, 2)) {
            uint16_t l_236 = 1UL;
            g_120[1] = 0x724D0293L;
            l_236 = p_40;
            l_262 = (safe_sub_func_int8_t_s_s(
                (((((((g_100 ||
                       ((((1UL <
                           ((safe_rshift_func_uint16_t_u_u(
                                ((safe_sub_func_uint8_t_u_u(
                                     (((safe_mod_func_uint8_t_u_u(
                                           255UL,
                                           (safe_rshift_func_uint8_t_u_s(
                                               ((safe_rshift_func_uint8_t_u_s(
                                                    ((safe_sub_func_int8_t_s_s(
                                                         (safe_mod_func_int16_t_s_s(
                                                             l_253, 65535UL)),
                                                         l_198)) >
                                                     ((safe_rshift_func_uint16_t_u_u(
                                                          p_42,
                                                          ((((safe_rshift_func_int16_t_s_u(
                                                                 ((l_258,
                                                                   (((safe_add_func_uint32_t_u_u(
                                                                         g_143,
                                                                         g_120
                                                                             [1])) ==
                                                                     l_198),
                                                                    l_236)) &
                                                                  l_258),
                                                                 p_42)) ||
                                                             g_97[2]),
                                                            g_89),
                                                           0x2CA6L))) > 0x62L)),
                                                    p_42)) |
                                                l_261),
                                               0)))) |
                                       l_210) &&
                                      p_39),
                                     255UL)) |
                                 g_18),
                                11)),
                            p_41)) ||
                          l_236),
                         0x43L) |
                        1UL)) ^
                      p_42),
                     g_22) < 0L) < l_253) != g_89) >= l_121),
                g_89));
                        l_296 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_121, g_101)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_258)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, g_22)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(p_41, g_97[4]))) == g_120[2]), p_40)) < 7UL)), 2UL))), p_42)), 0x96E64D66L)) >= g_89), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != p_39) ^ 8L), (-7L))) & p_43), p_39)) > l_236) <= (-1L)), p_42)), p_42)) >= g_143) ^ 0xF7BFL) , p_40) == l_198), g_101)) && g_59)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_121)) && p_42), 4)) & g_143) < 0x73054497L) != g_101);
          }
          for (l_86 = 0; (l_86 <= 4); l_86 += 1) {
            int i;
            g_120[l_86] =
                ((safe_sub_func_int32_t_s_s(
                     g_97[(l_86 + 2)],
                     (safe_unary_minus_func_uint8_t_u(
                         ((((safe_sub_func_int16_t_s_s(
                                ((g_97[l_86], 0xC6C2L) ^ 0xFEB2L),
                                ((safe_rshift_func_uint16_t_u_u(
                                     g_97[(l_86 + 1)],
                                     ((safe_rshift_func_uint16_t_u_u(
                                          g_120[l_86], 5)) !=
                                      (safe_mod_func_int8_t_s_s(
                                          ((((safe_add_func_uint32_t_u_u(
                                                 (safe_mod_func_uint32_t_u_u(
                                                     g_120[l_86],
                                                     ((0x60L < g_120[l_86]),
                                                      l_281[3][1]))),
                                                 0x2C0B2767L)) >= l_102) !=
                                            p_40) != 255UL),
                                          0xE6L))))) >= g_89))) != (-6L)) ||
                           g_120[0]) &&
                          g_97[(l_86 + 2)]))))) &
                 g_101);
            g_120[2] = ((-8L) == 0UL);
            l_326 =
                ((((((((65535UL >
                        (safe_mod_func_uint8_t_u_u(
                            ((safe_sub_func_uint8_t_u_u(
                                 (((l_262 ||
                                    (l_198 ||
                                     (safe_mod_func_uint8_t_u_u(
                                         (safe_lshift_func_uint16_t_u_s(
                                             ((safe_sub_func_uint32_t_u_u(
                                                  (safe_rshift_func_int8_t_s_u(
                                                      p_40,
                                                      (((l_253 >
                                                         (l_281[4][6], p_42)) !=
                                                        ((safe_rshift_func_uint16_t_u_u(
                                                             0xB25DL, 8)) ||
                                                         1UL)) <= g_89))),
                                                  g_101)) |
                                              g_97[2]),
                                             1)),
                                         g_101)))) &
                                   p_42) ||
                                  p_40),
                                 l_213[0])) &
                             l_258),
                            p_42))) <= p_40) < g_120[l_86]) == 0x8B28L) <
                    g_89) ||
                   l_213[2]) != g_100) <= 246UL);
            l_262 |= (~g_120[1]);
          }
        }
        for (l_121 = 20; (l_121 < 40);
             l_121 = safe_add_func_uint32_t_u_u(l_121, 1)) {
          int8_t l_362 = 0x43L;
          int32_t l_366 = (-2L);
          uint8_t l_369 = 0x5AL;
          int32_t l_393 = 0L;
          if ((safe_add_func_int16_t_s_s(
                  ((((l_213[1] ||
                      ((p_41 >= (+(-1L))) >=
                       (safe_lshift_func_int8_t_s_s(
                           ((safe_sub_func_int8_t_s_s(
                                (((safe_mod_func_int16_t_s_s(
                                      ((safe_lshift_func_int16_t_s_s(l_121,
                                                                     2)) ==
                                       (((safe_lshift_func_uint16_t_u_s(
                                             (g_59 ||
                                              ((safe_rshift_func_uint16_t_u_s(
                                                   (((safe_add_func_int16_t_s_s(
                                                         ((((((safe_mod_func_int16_t_s_s(
                                                                  p_43,
                                                                  l_86)) <=
                                                              0x56719CF5L) <
                                                             ((+(((((1UL &&
                                                                     0xD84E0731L) >
                                                                    l_281[6]
                                                                         [4]) <
                                                                   g_143) >
                                                                  0x15L) &
                                                                 0xF7L)) |
                                                              g_143)),
                                                            p_41) == l_350),
                                                          p_39),
                                                         0xA7B5L)),
                                                     2L),
                                                    l_351),
                                                   11)) >= g_101)),
                                             l_210)),
                                         0x25L) < 7UL)),
                                      g_59)) <= 1UL),
                                 l_210),
                                g_59)) ^
                            246UL),
                           g_18)))) <= 0x83L) >= 6UL) &
                   g_97[2]),
                  p_39))) {
            uint32_t l_364 = 0UL;
            int32_t l_365 = 1L;
            l_364 =
                ((safe_add_func_int8_t_s_s(
                     (((safe_lshift_func_uint16_t_u_u(
                           ((((p_42 != l_296) >
                              ((safe_lshift_func_uint16_t_u_u(
                                   (0xA1L !=
                                    (((-6L) &&
                                      (((safe_rshift_func_int8_t_s_u(
                                            0x08L,
                                            ((p_43 <
                                              ((g_97[2] |
                                                (((safe_sub_func_uint16_t_u_u(
                                                      (((l_362 != 0xFEFA8AE2L),
                                                        g_101) != g_97[2]),
                                                      g_100)) &&
                                                  0x6386802AL) >= g_97[1])) >=
                                               g_89)),
                                             p_39))) < 2UL) &&
                                       l_281[4][6])) != l_198)),
                                   0)) ^
                               p_39)) != g_97[2]) ||
                            0xF9L),
                           l_363)) ||
                       0xD2L),
                      p_41),
                     (-7L))) &&
                 p_41);
            ++l_369;
            if (l_281[4][3])
              break;
            l_366 = p_39;
          } else {
            uint32_t l_384 = 0UL;
            l_367 = (safe_sub_func_uint16_t_u_u(
                (safe_add_func_uint16_t_u_u(
                    (p_42,
                     (safe_mod_func_int32_t_s_s(
                         (((((((((((p_40,
                                    ((safe_mod_func_uint8_t_u_u(
                                         (g_97[2] ^ (~(+l_296))),
                                         ((((g_97[3] &
                                             ((safe_sub_func_uint16_t_u_u(
                                                  (l_384 >= l_351),
                                                  (((((((safe_lshift_func_int16_t_s_u(
                                                            (p_41 ||
                                                             (((((safe_rshift_func_int16_t_s_u(
                                                                     (1UL !=
                                                                      p_43),
                                                                     4)),
                                                                 0x8DL) >=
                                                                g_89),
                                                               l_389),
                                                              0x343F8062L)),
                                                            p_43)) > 4L) >
                                                       p_41),
                                                      g_120[1]) != p_40),
                                                    p_39) == 0xCB3F649DL))) |
                                              p_41)) ||
                                            g_89) |
                                           g_120[3]) &&
                                          0xE5L))) < 0UL)) >= g_97[1]) ||
                                  0x3F5AL) ^
                                 l_261) ||
                                p_43) |
                               l_366),
                              0L) ||
                             (-1L)) ^
                            0x8506B361L) >= p_42) ^
                          (-6L)),
                         0x3F0D7356L))),
                    g_100)),
                g_22));
            l_396--;
          }
          p_39 =
              (((((g_18 ^
                   (0UL &
                    (((g_59 ==
                       (safe_mod_func_uint8_t_u_u(
                           ((((safe_sub_func_int16_t_s_s(
                                  ((p_39 &
                                    ((safe_add_func_int8_t_s_s(
                                         (((safe_sub_func_int8_t_s_s(
                                               (safe_lshift_func_int16_t_s_s(
                                                   (((safe_mod_func_uint32_t_u_u(
                                                         (safe_sub_func_int16_t_s_s(
                                                             (((g_101 <=
                                                                g_143) >
                                                               (safe_lshift_func_uint16_t_u_u(
                                                                   (safe_sub_func_uint16_t_u_u(
                                                                       l_296,
                                                                       ((((((((safe_rshift_func_uint8_t_u_s(
                                                                                  g_101,
                                                                                  1)) &
                                                                              (((l_281
                                                                                     [4]
                                                                                     [6] ||
                                                                                 p_41) &&
                                                                                p_41) |
                                                                               0UL)) ==
                                                                             g_120
                                                                                 [1]) ||
                                                                            l_121) <
                                                                           l_326) <
                                                                          g_101) ||
                                                                         0x3CL) <
                                                                        g_18))),
                                                                   4))) >=
                                                              (-1L)),
                                                             l_351)),
                                                         l_419)) ||
                                                     p_43) >= l_420),
                                                   g_100)),
                                               g_89)) &
                                           (-1L)) |
                                          l_281[4][6]),
                                         0x42L)) < g_97[3])) <= g_120[1]),
                                  g_120[3])) |
                              l_396) != 0L) == l_391[1][4]),
                           l_395))) > 0x32L) ||
                     l_390))) ^
                  p_43) |
                 p_39) < p_40) < 1UL);
          for (l_86 = 0; (l_86 <= 4); l_86 += 1) {
            int i;
            return g_120[l_86];
          }
          if (g_143)
            break;
        }
        for (l_363 = 0; (l_363 == (-23)); --l_363) {
          uint32_t l_461[2][4][5] = {{{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL},
                                      {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL},
                                      {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL},
                                      {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL}},
                                     {{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL},
                                      {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL},
                                      {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL},
                                      {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL,
                                       0x62B936CDL, 4294967288UL}}};
          int i, j, k;
          g_120[1] =
              ((0x7DDEF103L >=
                ((((safe_rshift_func_int16_t_s_u(
                       ((0x2CD8L ==
                         ((((((0x0CE5L > p_42), (-9L)) ||
                             ((((safe_mod_func_uint32_t_u_u(
                                    (g_120[1] >
                                     (0xD6FEED26L |
                                      ((l_427 >=
                                        (((((((safe_unary_minus_func_uint8_t_u(
                                                  ((safe_rshift_func_int8_t_s_s(
                                                       g_97[1], 2)) !=
                                                   0xEF0CL))) > 0x88D4L) &&
                                             g_100) ^
                                            g_120[1]) >= l_281[3][0]) |
                                          (-6L)) == 1L)) ^
                                       7UL))),
                                    1UL)) < g_143) |
                               g_100),
                              0UL)) ^
                            (-1L)) |
                           l_281[0][3]) == l_396)) >= 0xBDE2D00BL),
                       7)),
                   7L) > p_42) ||
                 l_420)),
               l_419);
          l_431--;
                    p_39 = (((safe_unary_minus_func_int16_t_s(((((safe_unary_minus_func_uint16_t_u((l_326 , (((((~(safe_add_func_uint8_t_u_u((l_427 == (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(g_120[2], (((safe_add_func_uint8_t_u_u(((p_43 || ((safe_mod_func_int16_t_s_s(((((l_395 & ((0xAD109901L < ((((safe_rshift_func_uint8_t_u_s(p_40, 7)) != (p_41 <= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(((((((((p_40 , 4UL) > 0UL) == 0xC8C73883L) <= l_427) ^ g_18) && l_121) || g_120[1]) & l_390), p_42)), l_461[1][1][2])), l_296)), p_40)))) <= l_461[1][1][2]) < 0x237EL)) <= 0x28L)) < 65535UL) | l_363) >= p_41), l_213[4])) < 5UL)) ^ l_253), g_59)) >= 0UL) | g_97[2]))) <= g_59), g_120[1])) ^ g_100), 7))), p_41))) < 1L) || g_89) ^ g_22) , 6UL)))) | g_143) != g_22) , l_368))) , 1UL) != 255UL);
        }
        g_120[1] ^=
            ((0L & 0x37L) >=
             (safe_sub_func_uint16_t_u_u(
                 1UL, ((((safe_lshift_func_int8_t_s_u(
                             (g_97[3] >=
                              (safe_sub_func_uint16_t_u_u(
                                  (((safe_lshift_func_uint8_t_u_s(
                                        ((((((safe_lshift_func_uint16_t_u_s(
                                                 ((((0xC0653759L ^ l_363),
                                                    p_41) == (l_392 != p_39)),
                                                  1UL),
                                                 p_39)),
                                             4L),
                                            g_22) ||
                                           0x464EEE5AL) |
                                          8UL) &
                                         l_472),
                                        5)),
                                    0x83F7DA68L) &&
                                   g_18),
                                  1UL))),
                             5)) <= l_86) < 65531UL) ||
                       l_396))));
      }
    }
    for (l_102 = 29; (l_102 != (-14)); l_102--) {
      uint16_t l_507 = 65527UL;
      int32_t l_520[5][4] = {{0x55AC6CE3L, 1L, (-1L), (-1L)},
                             {0x55AC6CE3L, 1L, (-1L), (-1L)},
                             {0x55AC6CE3L, 1L, (-1L), (-1L)},
                             {0x55AC6CE3L, 1L, (-1L), (-1L)},
                             {0x55AC6CE3L, 1L, (-1L), (-1L)}};
      int32_t l_567 = (-1L);
      int32_t l_655 = (-2L);
      uint8_t l_696 = 0xEEL;
      uint16_t l_711[6] = {0x6659L, 0x6659L, 65527UL,
                           0x6659L, 0x6659L, 65527UL};
      int i, j;
      if (g_18) {
        uint8_t l_508 = 1UL;
                g_120[1] = (safe_rshift_func_int16_t_s_s(((!(1UL >= (((0xE1L != ((((safe_rshift_func_int16_t_s_s(((safe_lshift_func_int8_t_s_u((((safe_sub_func_int8_t_s_s(g_89, ((safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((65526UL & (safe_rshift_func_int16_t_s_s((((((g_100 != g_59) >= ((((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(1UL, (((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((!(safe_add_func_int8_t_s_s(((((safe_lshift_func_uint8_t_u_s((g_120[1] && ((safe_mod_func_uint8_t_u_u(0x86L, g_120[3])) <= g_22)), l_507)) <= (-10L)) && 1L) & l_508), 0x6CL))), 3)), 2)) ^ l_390) && p_40))), 7)) > l_253) && p_43) == 0x785C2DE3L)) & l_508) ^ l_419) , p_43), g_120[0]))), l_351)), 0)) <= g_97[2]))) , p_41) , l_507), g_59)) == g_101), l_351)) && l_86) & g_18) , g_143)) ^ 0x3CL) , 1UL))) ^ l_507), g_89));
      } else {
        int8_t l_513[10][2] = {
            {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L},
            {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}};
        int32_t l_569[8][6][5] = {{{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}},
                                  {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L},
                                   {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}};
        uint32_t l_642 = 18446744073709551615UL;
        int i, j, k;
        for (g_22 = 0; (g_22 >= 55);
             g_22 = safe_add_func_int32_t_s_s(g_22, 5)) {
          int8_t l_523 = 0xDBL;
          l_520[1][3] =
              ((((p_40 || 0UL) != p_43) <=
                (safe_rshift_func_int16_t_s_u(
                    0x4F5AL, (l_86 ^ (0x7DL <= l_513[9][0]))))),
               (g_89 ^ (safe_mod_func_uint16_t_u_u(
                           (((safe_rshift_func_int16_t_s_s(
                                 (safe_mod_func_int32_t_s_s(l_121, g_97[2])),
                                 12)) < p_40) |
                            l_513[9][0]),
                           p_41))));
          for (l_86 = (-26); (l_86 <= 16); l_86++) {
            int8_t l_524 = (-8L);
            l_524 = l_523;
            p_39 &= l_524;
          }
        }
        if (((safe_mod_func_int16_t_s_s(
                 g_89, (safe_rshift_func_int8_t_s_s(g_59, 1)))) >
             (0xAD5285A3L <= l_513[9][0]))) {
          uint16_t l_533 = 0xB016L;
          g_540 &= (safe_add_func_int32_t_s_s(
              (1UL != g_120[1]),
              (safe_add_func_int8_t_s_s(
                  (g_120[1] ||
                   (p_41 > (((((((l_533 >= p_42) & p_43) ||
                                ((safe_unary_minus_func_uint8_t_u(l_472)) &
                                 (((safe_lshift_func_int8_t_s_s(
                                       (+(safe_rshift_func_int16_t_s_u(
                                           (l_507, 0xDD7CL), g_120[3]))),
                                       l_368)) ^
                                   8L),
                                  p_42))) > p_43) != l_507) > 0xEEL),
                            l_102))),
                  p_43))));
          for (l_121 = 10; (l_121 != 4); l_121--) {
            const uint16_t l_568[6][9][4] = {
                {{0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL}},
                {{0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL}},
                {{0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL}},
                {{0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL}},
                {{0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL}},
                {{0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL},
                 {0x5921L, 0x6BC9L, 65527UL, 65526UL}}};
            const uint8_t l_576 = 249UL;
            int i, j, k;
            l_569[7][2][2] =
                (((safe_rshift_func_uint8_t_u_u(g_143, 6)),
                  (safe_rshift_func_uint16_t_u_u(
                      (((l_213[2] <=
                         (((safe_sub_func_int16_t_s_s(
                               (safe_add_func_uint32_t_u_u(
                                   ((((((((l_513[9][1] | g_97[2]) || g_59) ^
                                         0x77L),
                                        ((safe_rshift_func_uint16_t_u_s(
                                             p_43,
                                             (((safe_rshift_func_int8_t_s_s(
                                                   (safe_rshift_func_int16_t_s_s(
                                                       (((((safe_lshift_func_uint16_t_u_u(
                                                               (((((safe_lshift_func_uint8_t_u_u(
                                                                       l_296,
                                                                       5)) ==
                                                                   ((((((safe_rshift_func_uint8_t_u_s(
                                                                            ((safe_lshift_func_uint16_t_u_u(
                                                                                 ((safe_lshift_func_uint16_t_u_s(
                                                                                      9UL,
                                                                                      4)) <
                                                                                  l_520
                                                                                      [1]
                                                                                      [3]),
                                                                                 g_59)) &&
                                                                             g_100),
                                                                            g_18)) <
                                                                        p_40),
                                                                       p_40) <
                                                                      0xA5D176F9L) ||
                                                                     g_89) !=
                                                                    p_41)) ||
                                                                  g_540) >=
                                                                 l_567) !=
                                                                g_18),
                                                               5)) !=
                                                           0xFB0274BAL) >
                                                          l_389) &&
                                                         l_567) != p_42),
                                                       l_513[5][0])),
                                                   4)) == g_22) != g_540))) >
                                         l_102)) ^
                                       g_59) |
                                      l_507) |
                                     l_568[1][1][0]) &&
                                    l_520[1][3]),
                                   l_533)),
                               0UL)),
                           l_513[8][1]) &&
                          p_41)) <= 0x1E8AL) ||
                       p_39),
                      13))),
                 p_41);
            l_368 = (safe_rshift_func_int16_t_s_s(
                (safe_rshift_func_uint16_t_u_s(
                    (safe_add_func_int16_t_s_s(
                        l_576,
                        ((safe_sub_func_uint32_t_u_u(
                             4294967295UL,
                             ((safe_lshift_func_int8_t_s_u(
                                  p_43,
                                  (safe_add_func_uint32_t_u_u(
                                      (((safe_add_func_int16_t_s_s(
                                            (safe_add_func_int16_t_s_s(
                                                ((safe_sub_func_uint32_t_u_u(
                                                     g_100, g_120[1])),
                                                 0xD285L),
                                                (p_41,
                                                 (0UL !=
                                                  (safe_lshift_func_int16_t_s_u(
                                                      (((safe_sub_func_int16_t_s_s(
                                                            (!((((safe_add_func_int8_t_s_s(
                                                                     ((safe_rshift_func_int16_t_s_u(
                                                                          (-1L),
                                                                          13)) |
                                                                      g_22),
                                                                     l_569
                                                                         [7][2]
                                                                         [2])) <=
                                                                 l_513[9][0]) ||
                                                                l_598[1]) <=
                                                               g_18)),
                                                            l_213[2])) ^
                                                        p_40),
                                                       0xDB70L),
                                                      g_89)))))),
                                            p_41)) > g_120[1]) >= p_39),
                                      g_97[5])))) ^
                              0x9F178DF0L))) &&
                         l_598[1]))),
                    7)),
                p_41));
            p_39 = ((+0x203AL) &&
                    (safe_rshift_func_uint8_t_u_s(
                        (0xF62F64AEL <
                         (((safe_sub_func_int32_t_s_s(
                               (((safe_lshift_func_uint8_t_u_s(0x12L, 1)) &
                                 ((safe_rshift_func_int16_t_s_u(
                                      ((safe_sub_func_uint32_t_u_u(
                                           (safe_lshift_func_uint8_t_u_u(p_39,
                                                                         p_41)),
                                           (((!((g_97[1] |
                                                 (l_389 || ((l_613 < l_507) ==
                                                            l_520[1][3]))),
                                                p_43)) >= (-1L)) &&
                                            p_41))),
                                       0xD86FL),
                                      2)) &
                                  255UL)) > p_42),
                               0x9FADD9B3L)),
                           0L) |
                          p_43)),
                        l_533)));
            if (p_41)
              continue;
          }
          for (l_86 = (-15); (l_86 < 46);
               l_86 = safe_add_func_uint32_t_u_u(l_86, 1)) {
            --l_616;
            l_520[1][3] =
                (l_102 != ((~(safe_lshift_func_int16_t_s_u(g_143, p_42))) <=
                           (safe_add_func_int8_t_s_s(g_89, 1L))));
            if (g_97[2])
              break;
            return g_101;
          }
        } else {
          g_120[1] = 1L;
        }
        p_39 =
            (((((safe_add_func_uint8_t_u_u(
                    ((safe_rshift_func_uint16_t_u_s(
                         (((0xA08E28CFL <=
                            (g_143 ==
                             (((safe_rshift_func_int16_t_s_u(p_39, 8)) &&
                               (safe_rshift_func_uint16_t_u_u(
                                   (safe_lshift_func_int8_t_s_u(
                                       (safe_mod_func_uint8_t_u_u(g_120[1],
                                                                  l_616)),
                                       (0L > g_100))),
                                   (g_100 || (safe_sub_func_int16_t_s_s(
                                                 ((safe_mod_func_uint32_t_u_u(
                                                      g_143, l_642)) |
                                                  l_569[7][2][1]),
                                                 0UL)))))) |
                              l_507))) |
                           p_42),
                          p_43),
                         15)) != p_43),
                    g_540)) &&
                g_22) |
               l_520[0][2]) >= l_394) >= p_39);
        if ((safe_lshift_func_int16_t_s_s(
                p_42,
                (((((p_42 &&
                     (((safe_sub_func_uint8_t_u_u(
                           (safe_mod_func_uint32_t_u_u(
                               (((0x23L && l_569[4][5][3]) !=
                                 (safe_sub_func_uint32_t_u_u(l_296, g_97[1]))),
                                (safe_add_func_int8_t_s_s(p_39, l_121))),
                               g_101)),
                           l_613)) < 4294967295UL) |
                      p_41)) ^
                    0x77L),
                   l_394),
                  0x3B0A0897L) >= g_97[4])))) {
          p_39 &= (safe_rshift_func_uint16_t_u_u(l_655, 8));
        } else {
          for (g_100 = 0; (g_100 <= 5); g_100 += 1) {
            return l_656;
          }
          return g_120[1];
        }
      }
      if (((((((safe_add_func_int16_t_s_s(
                   ((p_41 == (safe_sub_func_int8_t_s_s(g_18, (65529UL | 0L)))),
                    (safe_sub_func_int8_t_s_s(
                        ((p_40 ^
                          ((g_97[3] >=
                            ((((safe_lshift_func_int8_t_s_s(
                                   ((safe_rshift_func_int16_t_s_u(l_368, 1)),
                                    (safe_mod_func_uint32_t_u_u(
                                        l_507, (~(g_101 && 0xFDA677A5L))))),
                                   g_143)) ^
                               g_22) &
                              p_42) &
                             1L)) == g_120[1])) &&
                         p_39),
                        p_39))),
                   g_143)) == p_43) &&
              255UL) < g_97[1]) >= l_296) ^
           p_41)) {
        int32_t l_691 = 0x098722ADL;
        int32_t l_693 = (-10L);
        for (g_100 = 5; (g_100 >= 0); g_100 -= 1) {
          uint16_t l_692 = 0xCE33L;
          uint32_t l_695 = 18446744073709551615UL;
          int i;
          g_694 &=
              ((safe_mod_func_uint16_t_u_u(
                   ((safe_rshift_func_uint16_t_u_s(l_213[g_100], 3)),
                    (((safe_add_func_int8_t_s_s(
                          (g_101 !=
                           (+(0xFEB6F005L !=
                              (safe_lshift_func_int16_t_s_u(
                                  ((0x63L ==
                                    ((safe_rshift_func_uint8_t_u_u(l_520[1][3],
                                                                   0)) >
                                     (safe_mod_func_int32_t_s_s(
                                         (l_396 > 3UL),
                                         (((((((0L >=
                                                (((safe_lshift_func_uint16_t_u_s(
                                                      (safe_rshift_func_uint16_t_u_s(
                                                          ((safe_lshift_func_int16_t_s_u(
                                                               (safe_add_func_uint16_t_u_u(
                                                                   ((0x37L ==
                                                                     l_691) |
                                                                    l_390),
                                                                   p_43)),
                                                               l_213[g_100])) !=
                                                           l_692),
                                                          l_691)),
                                                      p_43)) >= (-2L)) >=
                                                 p_40)),
                                               0xF9DAL) ||
                                              p_41) ||
                                             6L) ||
                                            g_18) >= l_692) &
                                          248UL))))) &
                                   g_59),
                                  9))))),
                          g_120[1])),
                      0UL) <= l_693)),
                   p_42)),
               0x2B6242CAL);
          g_120[3] =
              (((l_695, g_18) >=
                (l_696 &&
                 ((p_40 <=
                   ((((safe_add_func_uint32_t_u_u(
                          (((p_39 ^ ((l_389 > l_520[1][3]),
                                     (g_120[1] | 0x8AL))) > g_143) == l_699),
                          p_43)) &&
                      l_507),
                     65535UL) <= l_598[1])) &&
                  65535UL))),
               p_42);
          if (p_39)
            break;
        }
      } else {
        l_213[4] = g_694;
        if (l_507)
          continue;
      }
            g_717 &= ((((((((safe_mod_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u(((-3L) < (((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((!(((((l_472 == (0x1D5D50F0L == l_711[2])) >= (((safe_unary_minus_func_uint32_t_u(0xFC24DB18L)) | 0xA3L) || ((((~((((((((0UL < l_696) || ((((safe_sub_func_int32_t_s_s(((((((+((l_567 == l_711[2]) && 65535UL)) < l_389) || g_59) != l_253) == 0L) ^ g_97[2]), 0x3C3D0A9BL)) != p_39) , p_39) > l_389)) != l_507) >= 7L) && p_42) && p_39) < 1L) , p_41)) > 0x60B3L) && 6UL) != l_567))) || p_41) && 0x58L) | 0xEFC1L)) && l_655), l_389)), g_101)) ^ 9L) | 0x68L)), l_598[3])) >= g_120[4]), (-7L))) <= 0L) != l_213[2]) == l_616) && p_41) <= p_42) < 0x057B1D42L) | l_213[1]);
    }
  }
  return l_253;
}

static int32_t func_46(uint8_t p_47, uint16_t p_48, int16_t p_49, uint8_t p_50,
                       uint16_t p_51) {
  uint32_t l_74 = 0xF6860338L;
  l_74 |= 0x10DDF4F3L;
  return p_51;
}

static int16_t func_54(int32_t p_55, const uint32_t p_56, int8_t p_57,
                       uint8_t p_58) {
  int16_t l_68 = 0xEEB3L;
  uint16_t l_73 = 0xAD67L;
  g_59 = g_22;
  p_55 =
      ((((safe_sub_func_uint16_t_u_u(
             ((safe_lshift_func_uint16_t_u_s(
                  g_18,
                  (safe_mod_func_int32_t_s_s(
                      ((((safe_lshift_func_int8_t_s_s(
                             ((((l_68 == l_68) <= p_56) ^
                               ((l_68,
                                 (g_18 >=
                                  (!(((safe_lshift_func_uint8_t_u_s(
                                          (((p_57 >
                                             ((l_68 == (~((((l_73 < g_22) & 1L),
                                                           l_68) > 1L))) <=
                                              0x8971L)) > p_56),
                                           g_22),
                                          1)) &
                                      6UL) ||
                                     g_18)))) <= 0x164DL)) == p_56),
                             7)) == l_68) < p_56),
                       (-1L)),
                      l_68)))) > p_56),
             (-10L))),
         g_59) &&
        g_18),
       p_56);
  return l_73;
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  platform_main_begin();
  crc32_gentab();
  func_1();
  transparent_crc(g_18, "g_18", print_hash_value);
  transparent_crc(g_22, "g_22", print_hash_value);
  transparent_crc(g_59, "g_59", print_hash_value);
  transparent_crc(g_89, "g_89", print_hash_value);
  for (i = 0; i < 7; i++) {
    transparent_crc(g_97[i], "g_97[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_100, "g_100", print_hash_value);
  transparent_crc(g_101, "g_101", print_hash_value);
  for (i = 0; i < 5; i++) {
    transparent_crc(g_120[i], "g_120[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_143, "g_143", print_hash_value);
  transparent_crc(g_540, "g_540", print_hash_value);
  transparent_crc(g_694, "g_694", print_hash_value);
  transparent_crc(g_717, "g_717", print_hash_value);
  transparent_crc(g_777, "g_777", print_hash_value);
  for (i = 0; i < 1; i++) {
    transparent_crc(g_849[i], "g_849[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_935, "g_935", print_hash_value);
  transparent_crc(g_1168, "g_1168", print_hash_value);
  transparent_crc(g_1171, "g_1171", print_hash_value);
  transparent_crc(g_1217, "g_1217", print_hash_value);
  for (i = 0; i < 3; i++) {
    transparent_crc(g_1368[i], "g_1368[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 4; k++) {
        transparent_crc(g_1482[i][j][k], "g_1482[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 2; j++) {
      transparent_crc(g_1540[i][j], "g_1540[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 3; k++) {
        transparent_crc(g_1548[i][j][k], "g_1548[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  for (i = 0; i < 6; i++) {
    transparent_crc(g_2003[i], "g_2003[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_2100, "g_2100", print_hash_value);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      transparent_crc(g_2184[i][j], "g_2184[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_2254, "g_2254", print_hash_value);
  transparent_crc(g_2414, "g_2414", print_hash_value);
  transparent_crc(g_2431, "g_2431", print_hash_value);
  transparent_crc(g_2467, "g_2467", print_hash_value);
  transparent_crc(g_2468, "g_2468", print_hash_value);
  transparent_crc(g_2469, "g_2469", print_hash_value);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 1; j++) {
      for (k = 0; k < 10; k++) {
        transparent_crc(g_2470[i][j][k], "g_2470[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}
