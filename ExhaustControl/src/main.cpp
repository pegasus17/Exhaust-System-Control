#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

static TaskHandle_t taskBlinkHandle;

static void TaskBlink(void *pvParameters);

// cppcheck-suppress unusedFunction
void setup() {
  /**
   * Task creation
   */
  xTaskCreate(TaskBlink, // Task function
              "Blink", // Task name
              128, // Stack size 
              NULL, 
              0, // Priority
              &taskBlinkHandle); // Task handler
}

// cppcheck-suppress unusedFunction
void loop() {
  
}

/* 
 * Blink task. 
 */
static void TaskBlink(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED_BUILTIN, OUTPUT);

  for (;;)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay( 250 / portTICK_PERIOD_MS );
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}