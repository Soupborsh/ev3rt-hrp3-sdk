#include "ev3api.h"
#include "tool_svc.h"

#define N_READS 1000

#define u32 uint32_t
#define u64 uint64_t

static void print_u64_on_screen(const char *fmt, u64 x);

void main_task(intptr_t unused) {
  SYSTIM start, end, time;
  get_tim(&start);
  for (u32 i = 0; i < N_READS; i++) {
    ev3_gyro_sensor_get_angle(EV3_PORT_1);
  }
  get_tim(&end);
  time = end - start;
  u64 freq = (N_READS * 1000000) / time;
  syslog(LOG_NOTICE, "freq: %llu, time: %lu\n", freq, time);
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  print_u64_on_screen("f: %llu", freq);
  return;
  tslp_tsk(2000000); // sleep 2 seconds?
}

static void print_u64_on_screen(const char *fmt, u64 x) {
  char s[64];
  snprintf(s, sizeof(s), fmt, x);
  ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
  ev3_lcd_draw_string(s, 0, 0);
}
