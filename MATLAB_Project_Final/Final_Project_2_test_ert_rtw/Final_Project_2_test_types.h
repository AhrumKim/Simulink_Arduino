/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Project_2_test_types.h
 *
 * Code generated for Simulink model 'Final_Project_2_test'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Oct 18 09:29:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_Project_2_test_types_h_
#define RTW_HEADER_Final_Project_2_test_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Custom Type definition for MATLABSystem: '<S1>/Analog Input1' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_h_matlabshared_ioclient_perip_T
#define typedef_h_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN h_matlabshared_ioclient_perip_T;

#endif                             /* typedef_h_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  h_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_UTG5XI0vJCsmjbgura8BP
#define struct_tag_UTG5XI0vJCsmjbgura8BP

struct tag_UTG5XI0vJCsmjbgura8BP
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_UTG5XI0vJCsmjbgura8BP */

#ifndef typedef_g_arduinodriver_ArduinoAnalog_T
#define typedef_g_arduinodriver_ArduinoAnalog_T

typedef struct tag_UTG5XI0vJCsmjbgura8BP g_arduinodriver_ArduinoAnalog_T;

#endif                             /* typedef_g_arduinodriver_ArduinoAnalog_T */

#ifndef struct_tag_8ohiN1FAOgR98njPNu14NC
#define struct_tag_8ohiN1FAOgR98njPNu14NC

struct tag_8ohiN1FAOgR98njPNu14NC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_8ohiN1FAOgR98njPNu14NC */

#ifndef typedef_codertarget_arduinobase_int_g_T
#define typedef_codertarget_arduinobase_int_g_T

typedef struct tag_8ohiN1FAOgR98njPNu14NC codertarget_arduinobase_int_g_T;

#endif                             /* typedef_codertarget_arduinobase_int_g_T */

#ifndef struct_tag_jShWpKUOycwBMhFyiKcKhC
#define struct_tag_jShWpKUOycwBMhFyiKcKhC

struct tag_jShWpKUOycwBMhFyiKcKhC
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
};

#endif                                 /* struct_tag_jShWpKUOycwBMhFyiKcKhC */

#ifndef typedef_codertarget_arduinobase_in_g2_T
#define typedef_codertarget_arduinobase_in_g2_T

typedef struct tag_jShWpKUOycwBMhFyiKcKhC codertarget_arduinobase_in_g2_T;

#endif                             /* typedef_codertarget_arduinobase_in_g2_T */

/* Parameters (default storage) */
typedef struct P_Final_Project_2_test_T_ P_Final_Project_2_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Final_Project_2_test_T RT_MODEL_Final_Project_2_test_T;

#endif                            /* RTW_HEADER_Final_Project_2_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
