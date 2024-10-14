/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HC_SR04_ultrasonic.c
 *
 * Code generated for Simulink model 'HC_SR04_ultrasonic'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 14:30:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HC_SR04_ultrasonic.h"
#include "rtwtypes.h"
#include "HC_SR04_ultrasonic_private.h"

/* Block signals (default storage) */
B_HC_SR04_ultrasonic_T HC_SR04_ultrasonic_B;

/* Block states (default storage) */
DW_HC_SR04_ultrasonic_T HC_SR04_ultrasonic_DW;

/* Real-time model */
static RT_MODEL_HC_SR04_ultrasonic_T HC_SR04_ultrasonic_M_;
RT_MODEL_HC_SR04_ultrasonic_T *const HC_SR04_ultrasonic_M =
  &HC_SR04_ultrasonic_M_;

/* Model step function */
void HC_SR04_ultrasonic_step(void)
{
  uint32_T duration;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (HC_SR04_ultrasonic_DW.obj.TunablePropsChanged) {
    HC_SR04_ultrasonic_DW.obj.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  HC_SR04_ultrasonic_B.UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  HC_SR04_ultrasonic_M->Timing.taskTime0 =
    ((time_T)(++HC_SR04_ultrasonic_M->Timing.clockTick0)) *
    HC_SR04_ultrasonic_M->Timing.stepSize0;
}

/* Model initialize function */
void HC_SR04_ultrasonic_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(HC_SR04_ultrasonic_M, -1);
  HC_SR04_ultrasonic_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  HC_SR04_ultrasonic_M->Sizes.checksums[0] = (1795082992U);
  HC_SR04_ultrasonic_M->Sizes.checksums[1] = (4066054000U);
  HC_SR04_ultrasonic_M->Sizes.checksums[2] = (961462690U);
  HC_SR04_ultrasonic_M->Sizes.checksums[3] = (2982868841U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    HC_SR04_ultrasonic_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HC_SR04_ultrasonic_M->extModeInfo,
      &HC_SR04_ultrasonic_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HC_SR04_ultrasonic_M->extModeInfo,
                        HC_SR04_ultrasonic_M->Sizes.checksums);
    rteiSetTPtr(HC_SR04_ultrasonic_M->extModeInfo, rtmGetTPtr
                (HC_SR04_ultrasonic_M));
  }

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  HC_SR04_ultrasonic_DW.obj.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  HC_SR04_ultrasonic_DW.obj.TunablePropsChanged = false;
}

/* Model terminate function */
void HC_SR04_ultrasonic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
