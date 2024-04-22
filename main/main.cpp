/* 
	Copyright(C) 2022 Muhammet Emin Yanik
	
	Redistributions and use of source must retain the above copyright notice
	Redistributions in binary form must reproduce the above copyright notice
*/

/*
  Module Name:

	main.c

  Abstract:

	The entry point of the application
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"

#include "config.h"
#include "bmi270_external.h"


extern "C" void app_main(void)
{
    /* Initialize NVS */
    ESP_ERROR_CHECK(nvs_flash_init());

    /* Start BMI270 task */
    bmi270Initialize();
}