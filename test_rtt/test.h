/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Thu Aug 13 15:19:07 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S7>/Data Type Conversion' */
  uint8_T DataTypeConversion_b;        /* '<S8>/Data Type Conversion' */
  uint8_T DataTypeConversion_i;        /* '<S9>/Data Type Conversion' */
} B_test_T;

/* Parameters (auto storage) */
struct P_test_T_ {
  real_T RepeatingSequence3_rep_seq_y[9];/* Mask Parameter: RepeatingSequence3_rep_seq_y
                                          * Referenced by: '<S4>/Look-Up Table1'
                                          */
  real_T RepeatingSequence1_rep_seq_y[26];/* Mask Parameter: RepeatingSequence1_rep_seq_y
                                           * Referenced by: '<S3>/Look-Up Table1'
                                           */
  real_T RepeatingSequence_rep_seq_y[26];/* Mask Parameter: RepeatingSequence_rep_seq_y
                                          * Referenced by: '<S2>/Look-Up Table1'
                                          */
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_k;     /* Mask Parameter: ServoWrite_pinNumber_k
                                        * Referenced by: '<S8>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_l;     /* Mask Parameter: ServoWrite_pinNumber_l
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[9];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S4>/Look-Up Table1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 180
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Bias_Bias;                    /* Expression: 0
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T Constant_Value_c;             /* Expression: period
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_c[26];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S3>/Look-Up Table1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Bias1_Bias;                   /* Expression: 179
                                        * Referenced by: '<S1>/Bias1'
                                        */
  real_T Constant_Value_a;             /* Expression: period
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_d[26];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S2>/Look-Up Table1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 90
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -90
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  real_T Bias2_Bias;                   /* Expression: 92
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
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_test_T test_P;

/* Block signals (auto storage) */
extern B_test_T test_B;

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
