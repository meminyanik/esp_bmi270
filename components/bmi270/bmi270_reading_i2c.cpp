/**\
 * Copyright (c) 2024 Muhammet Emin Yanik.
 **/

/******************************************************************************/
/*!                 Header Files                                              */
#include <stdio.h>
#include <math.h>
#include "bmi270_library.h"
#include "bmi270_external.h"


/* I2C address selection */
static uint8_t i2cAddress = BMI2_I2C_PRIM_ADDR; // 0x68
//static uint8_t i2cAddress = BMI2_I2C_SEC_ADDR; // 0x69


/* Handle of the BMI270 task */
TaskHandle_t xBmi270Task;


/* BMI270 task */
static void bmi270Task(void *arg)
{
    /* Set the log level */
    static const char *TAG = "BMI270_TASK";

    /* Initialize the I2C */
    I2Cdev::initialize();
    ESP_LOGI(TAG, "I2C initialized successfully");

    /* Create a new sensor object */
    BMI270 imu;

    /* Check if sensor is connected and initialize */
    while(imu.beginI2C(i2cAddress) != BMI2_OK)
    {
        /* Not connected, inform user */
        ESP_LOGW(TAG, "Error: BMI270 not connected, check wiring and I2C address!");

        /* Block for 1s to see if connection is established */
        vTaskDelay( 1000 / portTICK_PERIOD_MS );
    }
    ESP_LOGI(TAG, "BMI270 connected successfully");

    /* Run the task at specified rate */
    TickType_t xLastWakeTime;
    const TickType_t xDelay = MPU_FRAME_PERIOD_MS / portTICK_PERIOD_MS;
    
    /* Initialise the xLastWakeTime variable with the current time. */
    xLastWakeTime = xTaskGetTickCount();

    /* Start the loop */
    while (1) {
        /* Get measurements from the sensor */
        imu.getSensorData();

        /* Print the measured data */
        ESP_LOGI(TAG, "Acceleration in g's: X: %0.2f, Y: %0.2f, Z: %0.2f", imu.data.accelX, imu.data.accelY, imu.data.accelZ);
        ESP_LOGI(TAG, "Rotation in deg/sec: X: %0.2f, Y: %0.2f, Z: %0.2f", imu.data.gyroX, imu.data.gyroY, imu.data.gyroZ);

        /* Wait for the next cycle. */
        xTaskDelayUntil( &xLastWakeTime, xDelay );
    }
}


/*!
 * @brief This function initializes the main task.
 */
void bmi270Initialize(void) {
    // Set the log level
    static const char *TAG = "BMI270_INITIALIZE";

    // Create the BMI270 task
    BaseType_t xReturned;
    xReturned = xTaskCreatePinnedToCore(bmi270Task, "bmi270Task", DEFAULT_TASK_STACK_SIZE_BYTES, NULL, MPU_TASK_PRIORITY, &xBmi270Task, MPU_TASK_CORE_ID);
    if( xReturned != pdPASS )
    {
        ESP_LOGE(TAG, "The BMI270 task could not be created.");
    }
}