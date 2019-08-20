/*

 Copyright (c) 2014 University of Edinburgh, Imperial College, University of Manchester.
 Developed in the PAMELA project, EPSRC Programme Grant EP/K008730/1

 This code is licensed under the MIT License.

 */

#ifndef __PowerMonitor__
#define __PowerMonitor__
class PowerMonitor {

public:
    enum Sensor {
        SENSOR_A7 = 45, SENSOR_A15 = 40, SENSOR_GPU = 44, SENSOR_DRAM = 41
    };
    enum PowerMethod {
        // For now we assume PAPI_CPU to mean CPU
        // and PAPI_CUDA to mean GPU
        // and PAPI_ALL to potantially mean GPU and CPU
        ODROID, ARM_PROBE, PAPI_CPU, PAPI_CUDA, PAPI_ALL, DUMMY, NONE
    };
    PowerMonitor();
    ~PowerMonitor();
    float getPower(Sensor);
    bool isActive();
    PerfStats powerStats;
    double sample();
    double start();
private:

    FILE *powerA7;
    FILE *powerA15;
    FILE *powerGPU;
    FILE *powerDRAM;
    int enableSensor(Sensor);
    PowerMethod sensingMethod;
    double startTime;
};
#endif
