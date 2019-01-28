/*
 * Common definitions/configuration of the firmware
 * By LA7ECA, ohanssen@acm.org
 */

#ifndef _DEFINES_H_
#define _DEFINES_H_


#define BIT_0	( 1 << 0 )


/* Conversions */
#define KNOTS2KMH 1.853
#define KNOTS2MPS 0.5148
#define FEET2M 3.2898


/* Queues for AFSK encoder/decoder */
#define AFSK_RX_QUEUE_SIZE      128
#define AFSK_TX_QUEUE_SIZE      128
#define HDLC_DECODER_QUEUE_SIZE  16
#define HDLC_ENCODER_QUEUE_SIZE  16

#define GPS_UART    UART_NUM_2
#define GPS_TXD_PIN 17
#define GPS_RXD_PIN 16

#define BLINK_NORMAL ; // FIXME
#define BLINK_GPS_SEARCHING ; // FIXME

#define HTTPD_DEFAULT_USR "arctic"
#define HTTPD_DEFAULT_PWD "hacker"
#define AP_DEFAULT_PASSWD ""
#define AP_DEFAULT_IP     "192.168.0.1"
#define AP_MAX_CLIENTS    4

#define AUTOCONNECT_PERIOD 240

#define STACK_AUTOCON 2300
#define STACK_HDLC_TEST 2000
#define STACK_HDLC_TXENCODER 2000
#define STACK_NMEALISTENER 2000

#define FBUF_SLOTSIZE 32
#define FBUF_SLOTS 1024

/* Regular expressions defining various input formats */
#define REGEX_AXADDR   "\\w{3,6}(-\\d{1,2})?"
#define REGEX_DIGIPATH "\\w{3,6}(-\\d{1,2})?(\\,\\w{3,6}(-\\d{1,2})?)*"
#define REGEX_IPADDR   "(\\d{1,3}\\.){3}\\d{1,3}"
#define REGEX_APRSSYM  "[0-9A-Z\\/\\\\&]."
#define REGEX_HOSTNAME "[0-9-a-zA-Z\\-\\_\\.]+"

#define NORMALPRIO 5

/* Simplified semaphore operations */
#define semaphore_t     SemaphoreHandle_t
#define sem_create(cnt) xSemaphoreCreateCounting(65000, cnt)
#define sem_delete(sem) vSemaphoreDelete(sem)
#define sem_up(x)       xSemaphoreGive(x)
#define sem_down(x)     xSemaphoreTake(x, portMAX_DELAY)
#define sem_getCount(x) uxSemaphoreGetCount(x)


#define sleepMs(n)  vTaskDelay(pdMS_TO_TICKS(n))
#define t_yield     taskYIELD

/* Make event groups look like simple condition variables */
#define cond_t               EventGroupHandle_t
#define cond_create          xEventGroupCreate
#define cond_wait(cond)      xEventGroupWaitBits(cond, BIT_0, pdFALSE, pdTRUE,  portMAX_DELAY)
#define cond_notifyAll(cond) xEventGroupSetBits(cond, BIT_0)
#define cond_clear(cond)     xEventGroupClearBits(cond, BIT_0)

#endif
