#ifndef ADC121C_ft
#define ADC121C_ft

#include "Arduino.h"
#include "Wire.h"

class ADC121C{
  public:
    ADC121C(uint8_t adr);
    void begin(TwoWire &wire = Wire);
    unsigned int readConversion(bool &boo); //optional reference
    unsigned int readConversion(); //overloaded

    // setting stuffs
    // 2 bytes config
    unsigned int getLowLimit();
    void setLowLimit(uint16_t val);
    unsigned int getHighLimit();
    void setHighLimit(uint16_t val);
    unsigned int getAlertHyst();
    void setAlertHyst(uint16_t val);
    unsigned int getLowConv();
    void setLowConv(uint16_t val);
    unsigned int getHighConv();
    void setHighConv(uint16_t val);
    
    // alert status config
    uint8_t getAlertStatus();
    void setAlertStatus(uint8_t val);

    // .. configuration register
    void setPolarity(bool val);
    void setAlertPinEnable(bool val);
    void setAlertFlagEnable(bool val);
    void setAlertHold(bool val);
    void setCycleTime(uint8_t val);
    int8_t checkConfig(uint8_t op);

    //no config checking functions.. it's already bloated in here
    
  private:
    TwoWire *_wire;
    uint8_t _adr;
    uint16_t readRegister(uint8_t reg); //some register returns two bytes
    void writeRegister(uint8_t reg, uint16_t val); //some register needs only one byte
};

#endif
