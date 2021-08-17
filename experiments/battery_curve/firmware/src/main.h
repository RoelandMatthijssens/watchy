//
// Created by rroels on 08/08/2021.
//

#ifndef WATCHY_MAIN_H
#define WATCHY_MAIN_H

//pins

#define WATCHY_SDA 21
#define WATCHY_SCL 22
#define WATCHY_ADC_PIN 33
#define WATCHY_RTC_PIN GPIO_NUM_27
#define WATCHY_CS 5
#define WATCHY_DC 10
#define WATCHY_RESET 9
#define WATCHY_BUSY 19
#define WATCHY_VIB_MOTOR_PIN 13
#define WATCHY_MENU_BTN_PIN 26
#define WATCHY_BACK_BTN_PIN 25
#define WATCHY_UP_BTN_PIN 32
#define WATCHY_DOWN_BTN_PIN 4
#define WATCHY_MENU_BTN_MASK GPIO_SEL_26
#define WATCHY_BACK_BTN_MASK GPIO_SEL_25
#define WATCHY_UP_BTN_MASK GPIO_SEL_32
#define WATCHY_DOWN_BTN_MASK GPIO_SEL_4
#define WATCHY_ACC_INT_MASK GPIO_SEL_14
#define WATCHY_BTN_PIN_MASK WATCHY_MENU_BTN_MASK|WATCHY_BACK_BTN_MASK|WATCHY_UP_BTN_MASK|WATCHY_DOWN_BTN_MASK


#endif //WATCHY_MAIN_H