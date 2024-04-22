/* 
	Copyright(C) 2022 Muhammet Emin Yanik
	
	Redistributions and use of source must retain the above copyright notice
	Redistributions in binary form must reproduce the above copyright notice
*/

/*
  Module Name:

	config.h

  Abstract:

	The configuration header file
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>


/* Common thread/task parameters */
#define DEFAULT_TASK_STACK_SIZE_WORDS       1 * 1024
#define DEFAULT_TASK_STACK_SIZE_BYTES       DEFAULT_TASK_STACK_SIZE_WORDS * sizeof(uint32_t)


/* Task priorities */
#define MPU_TASK_PRIORITY 			(configMAX_PRIORITIES)

/* Task Cores */
#define MPU_TASK_CORE_ID 			0

#endif