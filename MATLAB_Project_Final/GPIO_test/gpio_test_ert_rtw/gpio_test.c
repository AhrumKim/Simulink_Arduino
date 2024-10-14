/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: gpio_test.c
 *
 * Code generated for Simulink model 'gpio_test'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 13:46:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gpio_test.h"
#include "rtwtypes.h"
#include "gpio_test_private.h"
#include <math.h>

/* Block states (default storage) */
DW_gpio_test_T gpio_test_DW;

/* Real-time model */
static RT_MODEL_gpio_test_T gpio_test_M_;
RT_MODEL_gpio_test_T *const gpio_test_M = &gpio_test_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void gpio_test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(gpio_test_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (gpio_test_M->Timing.TaskCounters.TID[1])++;
  if ((gpio_test_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [2.0s, 0.0s] */
    gpio_test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void gpio_test_step0(void)             /* Sample time: [0.1s, 0.0s] */
{
  boolean_T c_value;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  if (gpio_test_DW.obj.SampleTime != gpio_test_P.DigitalInput_SampleTime) {
    gpio_test_DW.obj.SampleTime = gpio_test_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(3);

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<Root>/NOT'
   *  MATLABSystem: '<Root>/Digital Input'
   * */
  writeDigitalPin(12, (uint8_T)!c_value);
}

/* Model step function for TID1 */
void gpio_test_step1(void)             /* Sample time: [2.0s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (gpio_test_DW.clockTickCounter <
                        gpio_test_P.PulseGenerator_Duty) &&
    (gpio_test_DW.clockTickCounter >= 0L) ? gpio_test_P.PulseGenerator_Amp : 0.0;
  if (gpio_test_DW.clockTickCounter >= gpio_test_P.PulseGenerator_Period - 1.0)
  {
    gpio_test_DW.clockTickCounter = 0L;
  } else {
    gpio_test_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
}

/* Model initialize function */
void gpio_test_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Input' */
  gpio_test_DW.obj.matlabCodegenIsDeleted = false;
  gpio_test_DW.obj.SampleTime = gpio_test_P.DigitalInput_SampleTime;
  gpio_test_DW.obj.isInitialized = 1L;
  digitalIOSetup(3, 0);
  gpio_test_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  gpio_test_DW.obj_j.matlabCodegenIsDeleted = false;
  gpio_test_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(12, 1);
  gpio_test_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  gpio_test_DW.obj_p.matlabCodegenIsDeleted = false;
  gpio_test_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(13, 1);
  gpio_test_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void gpio_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!gpio_test_DW.obj.matlabCodegenIsDeleted) {
    gpio_test_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!gpio_test_DW.obj_j.matlabCodegenIsDeleted) {
    gpio_test_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!gpio_test_DW.obj_p.matlabCodegenIsDeleted) {
    gpio_test_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
