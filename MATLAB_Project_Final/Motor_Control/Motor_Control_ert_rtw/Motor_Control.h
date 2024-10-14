/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Control.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Oct 14 14:57:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Motor_Control_h_
#define RTW_HEADER_Motor_Control_h_
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T y;                            /* '<S1>/MATLAB Function' */
  uint8_T DataTypeConversion;          /* '<Root>/Data Type Conversion' */
} B_Motor_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_l_T obj_m;/* '<Root>/PWM' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  volatile real_T RateTransition1_Buffer0;/* '<Root>/Rate Transition1' */
  volatile real_T RateTransition1_Buffer1;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_write_buf;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_read_buf;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_last_buf_wr;/* '<Root>/Rate Transition1' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  uint8_T is_active_c2_Motor_Control;  /* '<S1>/MATLAB Function' */
} DW_Motor_Control_T;

/* Parameters (default storage) */
struct P_Motor_Control_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T RateTransition1_InitialConditio;/* Expression: 0
                                          * Referenced by: '<Root>/Rate Transition1'
                                          */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Motor_Control_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint8_T rtmDbBufReadBuf1;
    uint8_T rtmDbBufWriteBuf1;
    boolean_T rtmDbBufLastBufWr1;
    uint32_T rtmDbBufClockTick1[2];
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Motor_Control_T Motor_Control_P;

/* Block signals (default storage) */
extern B_Motor_Control_T Motor_Control_B;

/* Block states (default storage) */
extern DW_Motor_Control_T Motor_Control_DW;

/* Model entry point functions */
extern void Motor_Control_initialize(void);
extern void Motor_Control_step(void);
extern void Motor_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Motor_Control_T *const Motor_Control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Motor_Control'
 * '<S1>'   : 'Motor_Control/Function-Call Subsystem'
 * '<S2>'   : 'Motor_Control/Function-Call Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
