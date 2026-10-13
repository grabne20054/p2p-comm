#ifndef ENGINE_H
#define ENGINE_H

#include "data.h"
#include <stdint.h>
#include <driver/ledc.h>
#include "esp_err.h"

#include "esp_err.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "send.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define RPWM_GPIO 4
#define LPWM_GPIO 5

#define R_EN_GPIO 25
#define L_EN_GPIO 26

#define PWM_FREQ 20000
#define PWM_RES LEDC_TIMER_10_BIT
#define PWM_MAX_DUTY ((1<<10)-1)

#define BUTTON_GPIO 33

//extern EventGroupHandle_t engine_event_group;

void pwm_init();

engine_t * init_engine();

engine_t * get_unq_engine();

uint16_t get_position(engine_t *engine);

e_status_t get_engine_status(engine_t *engine);

e_status_t perform_engine_action(engine_t *engine, e_actions_t action, ds_actions_t action_type);

void check_engine(void *pvParameters);

void manual_control(void *pvParameters);



#endif 


