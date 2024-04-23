/* 
	Copyright(C) 2022 Muhammet Emin Yanik
	
	Redistributions and use of source must retain the above copyright notice
	Redistributions in binary form must reproduce the above copyright notice
*/

/*
  Module Name:

	bmi270_external.h

  Abstract:

	The header file of the BMI270 external API
*/

#ifndef BMI270_EXTERNAL_H
#define BMI270_EXTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "string.h"
#include "driver/gpio.h"

#include "config.h"
#include "I2Cdev.h"


/* Initialize the BMI270 */
void bmi270Initialize(void);

#ifdef __cplusplus
}
#endif

#endif
