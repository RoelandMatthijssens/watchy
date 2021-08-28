
#include "Battery.h"

Battery::Battery() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_GPIO33_CHANNEL, ADC_ATTEN_DB_11);
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
}

double Battery::getVoltage() {
    int analog = adc1_get_raw(ADC1_GPIO33_CHANNEL);
    return esp_adc_cal_raw_to_voltage(analog, &this->adc_chars) * 2.0 / 1000.0;
}

uint8_t Battery::getBatteryPercentage() {
    double voltage = this->getVoltage();
    if(voltage >= 4.2) {
        return 100;
    } else if (voltage < 3.2) {
        return 0;
    } else {
        return binarySearch(voltage);
    }
}

// our lookup is an array with 101 elements, where index 0 is the voltage at 0% battery, and last index is voltage at 100% battery
// given a specific voltage, we do a binary search to find the index of the closest value (lower bound)
uint Battery::binarySearch(double x) {

    // handle values outside the mapped range
    if(x < volt_lookup[0])
        return 0;
    if(x > volt_lookup[lookup_len-1])
        return lookup_len-1;

    // classic iterative binary search
    int l = 0;
    int r = lookup_len-1;
    int m = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (volt_lookup[m] == x)
            return m;
        if (volt_lookup[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    /*
     if we get here, an exact match was NOT found
     however, after the algo ended, we know the value we're looking for fits somewhere between m-1 and m+1
     when x is between 2 entries, we always want to take the smallest of the 2, so that battery capacity is not over-estimated:
     - if x is between m and m+1, we take m (do nothing)
     - if x is between  m-1 and m, we take m-1 (decrease m)
    */
    if(x < volt_lookup[m] && m > 0) {
        m--;
    }

    return m;
}
