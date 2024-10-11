/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 11 13:45:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "rtwtypes.h"
#include "untitled1_private.h"
#include <math.h>

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void untitled1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(untitled1_M, 1));
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
  (untitled1_M->Timing.TaskCounters.TID[1])++;
  if ((untitled1_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [2.0s, 0.0s] */
    untitled1_M->Timing.TaskCounters.TID[1] = 0;
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
void untitled1_step0(void)             /* Sample time: [0.1s, 0.0s] */
{
  boolean_T c_value;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (untitled1_DW.obj.SampleTime != untitled1_P.DigitalInput1_SampleTime) {
    untitled1_DW.obj.SampleTime = untitled1_P.DigitalInput1_SampleTime;
  }

  c_value = readDigitalPin(3);

  /* Logic: '<Root>/NOT' incorporates:
   *  MATLABSystem: '<Root>/Digital Input1'
   * */
  untitled1_B.NOT = !c_value;

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(12, (uint8_T)untitled1_B.NOT);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.taskTime0 =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void untitled1_step1(void)             /* Sample time: [2.0s, 0.0s] */
{
  real_T tmp;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  untitled1_B.PulseGenerator = (untitled1_DW.clockTickCounter <
    untitled1_P.PulseGenerator_Duty) && (untitled1_DW.clockTickCounter >= 0L) ?
    untitled1_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (untitled1_DW.clockTickCounter >= untitled1_P.PulseGenerator_Period - 1.0)
  {
    untitled1_DW.clockTickCounter = 0L;
  } else {
    untitled1_DW.clockTickCounter++;
  }

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(untitled1_B.PulseGenerator);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 2.0, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled1_M->Timing.clockTick1++;
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled1_M, -1);
  untitled1_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (1774847852U);
  untitled1_M->Sizes.checksums[1] = (1705949184U);
  untitled1_M->Sizes.checksums[2] = (2887281680U);
  untitled1_M->Sizes.checksums[3] = (2469051469U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.SampleTime = untitled1_P.DigitalInput1_SampleTime;
  untitled1_DW.obj.isInitialized = 1L;
  digitalIOSetup(3, 0);
  untitled1_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  untitled1_DW.obj_i.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(12, 1);
  untitled1_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled1_DW.obj_b.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(13, 1);
  untitled1_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!untitled1_DW.obj_i.matlabCodegenIsDeleted) {
    untitled1_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled1_DW.obj_b.matlabCodegenIsDeleted) {
    untitled1_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
