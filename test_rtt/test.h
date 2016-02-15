/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Sep  8 14:56:21 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <stddef.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_test_T_ {
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_k;     /* Mask Parameter: ServoWrite_pinNumber_k
                                        * Referenced by: '<S8>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_l;     /* Mask Parameter: ServoWrite_pinNumber_l
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: 0
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T Constant1_Value;              /* Expression: 90
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Bias1_Bias;                   /* Expression: 0
                                        * Referenced by: '<S1>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 175
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Bias2_Bias;                   /* Expression: 0
                                        * Referenced by: '<S1>/Bias2'
                                        */
  uint8_T ServoWrite_p1;               /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  uint8_T ServoWrite_p1_g;             /* Computed Parameter: ServoWrite_p1_g
                                        * Referenced by: '<S8>/Servo Write'
                                        */
  uint8_T ServoWrite_p1_a;             /* Computed Parameter: ServoWrite_p1_a
                                        * Referenced by: '<S9>/Servo Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_test_T test_P;

/* Model entry point functions */
extern void test_initialize(void);
extern void test_output(void);
extern void test_update(void);
extern void test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_T *const test_M;

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
 * '<Root>' : 'test'
 * '<S1>'   : 'test/Calibration Platform'
 * '<S2>'   : 'test/Repeating Sequence'
 * '<S3>'   : 'test/Repeating Sequence1'
 * '<S4>'   : 'test/Repeating Sequence3'
 * '<S5>'   : 'test/Calibration Platform/Repeating Sequence Stair2'
 * '<S6>'   : 'test/Calibration Platform/Repeating Sequence2'
 * '<S7>'   : 'test/Calibration Platform/Standard Servo Write'
 * '<S8>'   : 'test/Calibration Platform/Standard Servo Write1'
 * '<S9>'   : 'test/Calibration Platform/Standard Servo Write2'
 * '<S10>'  : 'test/Calibration Platform/Repeating Sequence Stair2/LimitedCounter'
 * '<S11>'  : 'test/Calibration Platform/Repeating Sequence Stair2/LimitedCounter/Increment Real World'
 * '<S12>'  : 'test/Calibration Platform/Repeating Sequence Stair2/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
