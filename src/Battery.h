#ifndef WATCHY_BATTERY_H
#define WATCHY_BATTERY_H

#include "esp_adc_cal.h"

class Battery {

private:
    // array with 101 elements, where index 0 is voltage at 0% battery, and index 100 is voltage at 100% capacity
    const double volt_lookup[101] = {3.2,3.28,3.34,3.37,3.39,3.42,3.42,3.44,3.44,3.46,3.47,3.47,3.48,3.5,3.5,3.51,3.52,3.53,3.53,3.54,3.55,3.56,3.57,3.57,3.59,3.6,3.61,3.62,3.63,3.65,3.65,3.66,3.67,3.67,3.68,3.7,3.69,3.7,3.71,3.71,3.71,3.72,3.72,3.72,3.72,3.72,3.73,3.73,3.73,3.73,3.74,3.74,3.74,3.74,3.75,3.75,3.76,3.76,3.76,3.77,3.77,3.79,3.79,3.79,3.79,3.8,3.8,3.81,3.82,3.82,3.83,3.84,3.84,3.85,3.86,3.86,3.87,3.88,3.9,3.9,3.91,3.92,3.93,3.95,3.95,3.96,3.97,3.98,3.98,4.0,4.02,4.03,4.04,4.05,4.06,4.08,4.09,4.1,4.11,4.13,4.2};
    const int lookup_len = sizeof(volt_lookup)/sizeof(volt_lookup[0]);
    esp_adc_cal_characteristics_t adc_chars = esp_adc_cal_characteristics_t();

private:
    uint binarySearch(double x);

public:
    Battery();
    double getVoltage();
    uint8_t getBatteryPercentage();

};


#endif //WATCHY_BATTERY_H
