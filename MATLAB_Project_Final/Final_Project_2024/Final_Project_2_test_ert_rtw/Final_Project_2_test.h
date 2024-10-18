/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Project_2_test.h
 *
 * Code generated for Simulink model 'Final_Project_2_test'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Oct 16 17:38:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_Project_2_test_h_
#define RTW_HEADER_Final_Project_2_test_h_
#ifndef Final_Project_2_test_COMMON_INCLUDES_
#define Final_Project_2_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#include "MW_Ultrasonic.h"
#endif                               /* Final_Project_2_test_COMMON_INCLUDES_ */

#include "Final_Project_2_test_types.h"
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
  real_T RateTransition1;              /* '<S2>/Rate Transition1' */
  real_T RateTransition2;              /* '<S2>/Rate Transition2' */
  real_T Merge3;                       /* '<S2>/Merge3' */
  real_T Merge2;                       /* '<S2>/Merge2' */
  real_T Merge1;                       /* '<S2>/Merge1' */
  real_T y;                            /* '<S6>/MATLAB Function' */
  real_T y_l;                          /* '<S5>/MATLAB Function' */
  uint8_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  uint8_T Merge;                       /* '<S2>/Merge' */
} B_Final_Project_2_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_g_T obj; /* '<S1>/Analog Input1' */
  codertarget_arduinobase_block_T obj_g;/* '<S2>/Digital Output' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Red LED' */
  codertarget_arduinobase_block_T obj_o;/* '<Root>/Blue LED' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/PWM  ' */
  real_T UnitDelay_DSTATE;             /* '<S6>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S5>/Unit Delay' */
  codertarget_arduinobase_in_g2_T obj_l;/* '<Root>/Ultrasonic Sensor  ' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<S2>/Scope' */

  int32_T clockTickCounter;            /* '<S15>/Pulse Generator' */
  int32_T clockTickCounter_o;          /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S10>/Pulse Generator' */
  int32_T clockTickCounter_g;          /* '<S3>/Pulse Generator' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S2>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S2>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S2>/If Action Subsystem2' */
  int8_T IfActionSubsystem2_SubsysRanB_l;/* '<S9>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_b;/* '<S9>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_m;/* '<S9>/If Action Subsystem1' */
  int8_T ACCStandby_SubsysRanBC;       /* '<S2>/ACC Standby   ' */
  int8_T IfActionSubsystem2_SubsysRanB_h;/* '<S4>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_f;/* '<S4>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S4>/If Action Subsystem1' */
  int8_T ACCOFF_SubsysRanBC;           /* '<S2>/ACC OFF' */
  int8_T FunctionCallSubsystem1_SubsysRa;/* '<S2>/Function-Call Subsystem1' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<S2>/Function-Call Subsystem' */
  uint8_T is_active_c6_Final_Project_2_te;/* '<S6>/MATLAB Function' */
  uint8_T is_active_c5_Final_Project_2_te;/* '<S5>/MATLAB Function' */
} DW_Final_Project_2_test_T;

/* Parameters (default storage) */
struct P_Final_Project_2_test_T_ {
  real_T y_Y0;                         /* Computed Parameter: y_Y0
                                        * Referenced by: '<S5>/y'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  real_T SW2_Y0;                       /* Computed Parameter: SW2_Y0
                                        * Referenced by: '<S6>/SW2'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S3>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S3>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T PulseGenerator_Amp_j;         /* Expression: 1
                                        * Referenced by: '<S10>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_h; /* Computed Parameter: PulseGenerator_Period_h
                                   * Referenced by: '<S10>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_p;     /* Computed Parameter: PulseGenerator_Duty_p
                                     * Referenced by: '<S10>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_d;  /* Expression: 0
                                        * Referenced by: '<S10>/Pulse Generator'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T PulseGenerator_Amp_n;         /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p; /* Computed Parameter: PulseGenerator_Period_p
                                   * Referenced by: '<S4>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_n;     /* Computed Parameter: PulseGenerator_Duty_n
                                     * Referenced by: '<S4>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_c;  /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T PulseGenerator_Amp_ng;        /* Expression: 1
                                        * Referenced by: '<S15>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_f; /* Computed Parameter: PulseGenerator_Period_f
                                   * Referenced by: '<S15>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_j;     /* Computed Parameter: PulseGenerator_Duty_j
                                     * Referenced by: '<S15>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_l;  /* Expression: 0
                                        * Referenced by: '<S15>/Pulse Generator'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant_Value_o4;            /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_jt;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S2>/Merge2'
                                      */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S2>/Merge1'
                                      */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint8_T Gain_Gain_k;                 /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S15>/Gain'
                                        */
  uint8_T Constant1_Value_c;           /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S11>/Constant1'
                                        */
  uint8_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S10>/Gain'
                                        */
  uint8_T Constant_Value_jr;           /* Computed Parameter: Constant_Value_jr
                                        * Referenced by: '<S16>/Constant'
                                        */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S2>/Merge'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_Final_Project_2_test_T {
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
    uint32_T clockTick2;
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Final_Project_2_test_T Final_Project_2_test_P;

/* Block signals (default storage) */
extern B_Final_Project_2_test_T Final_Project_2_test_B;

/* Block states (default storage) */
extern DW_Final_Project_2_test_T Final_Project_2_test_DW;

/* Model entry point functions */
extern void Final_Project_2_test_initialize(void);
extern void Final_Project_2_test_step(void);
extern void Final_Project_2_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_Project_2_test_T *const Final_Project_2_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Conversion' : Unused code path elimination
 */

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
 * '<Root>' : 'Final_Project_2_test'
 * '<S1>'   : 'Final_Project_2_test/PWM_in '
 * '<S2>'   : 'Final_Project_2_test/Subsystem'
 * '<S3>'   : 'Final_Project_2_test/Subsystem/ACC OFF'
 * '<S4>'   : 'Final_Project_2_test/Subsystem/ACC Standby   '
 * '<S5>'   : 'Final_Project_2_test/Subsystem/Function-Call Subsystem'
 * '<S6>'   : 'Final_Project_2_test/Subsystem/Function-Call Subsystem1'
 * '<S7>'   : 'Final_Project_2_test/Subsystem/If Action Subsystem'
 * '<S8>'   : 'Final_Project_2_test/Subsystem/If Action Subsystem1'
 * '<S9>'   : 'Final_Project_2_test/Subsystem/If Action Subsystem2'
 * '<S10>'  : 'Final_Project_2_test/Subsystem/ACC Standby   /If Action Subsystem'
 * '<S11>'  : 'Final_Project_2_test/Subsystem/ACC Standby   /If Action Subsystem1'
 * '<S12>'  : 'Final_Project_2_test/Subsystem/ACC Standby   /If Action Subsystem2'
 * '<S13>'  : 'Final_Project_2_test/Subsystem/Function-Call Subsystem/MATLAB Function'
 * '<S14>'  : 'Final_Project_2_test/Subsystem/Function-Call Subsystem1/MATLAB Function'
 * '<S15>'  : 'Final_Project_2_test/Subsystem/If Action Subsystem2/If Action Subsystem'
 * '<S16>'  : 'Final_Project_2_test/Subsystem/If Action Subsystem2/If Action Subsystem1'
 * '<S17>'  : 'Final_Project_2_test/Subsystem/If Action Subsystem2/If Action Subsystem2'
 */
#endif                                 /* RTW_HEADER_Final_Project_2_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
