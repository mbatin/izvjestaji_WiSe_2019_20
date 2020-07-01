#ifndef main_h
#define main_h

struct SensorData
{
    uint16_t air;
};

typedef enum
{
    READ_SERIAL,
    READ_SENSORS,
    RADIO_TX,
    SLEEP,

} StateType;
#endif