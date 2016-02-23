/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Calibration_procedure.h
 *
 * Code generated for Simulink model 'Calibration_procedure'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 8.8.1 (R2015aSP1) 04-Sep-2015
 * TLC version                    : 8.8 (Sep  6 2015)
 * C/C++ source code generated on : Wed Feb 17 12:32:00 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Calibration_procedure_h_
#define RTW_HEADER_Calibration_procedure_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Calibration_procedure_COMMON_INCLUDES_
# define Calibration_procedure_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* Calibration_procedure_COMMON_INCLUDES_ */

#include "Calibration_procedure_types.h"
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
  uint8_T DataTypeConversion;          /* '<S6>/Data Type Conversion' */
  uint8_T DataTypeConversion_e;        /* '<S7>/Data Type Conversion' */
  uint8_T DataTypeConversion_c;        /* '<S8>/Data Type Conversion' */
} B_Calibration_procedure_T;

/* Parameters (auto storage) */
struct P_Calibration_procedure_T_ {
  real_T RepeatingSequence2_rep_seq_y[10];/* Mask Parameter: RepeatingSequence2_rep_seq_y
                                           * Referenced by: '<S10>/Look-Up Table1'
                                           */
  real_T RepeatingSequence1_rep_seq_y[16];/* Mask Parameter: RepeatingSequence1_rep_seq_y
                                           * Referenced by: '<S9>/Look-Up Table1'
                                           */
  real_T RepeatingSequence1_rep_seq_y_h[17];/* Mask Parameter: RepeatingSequence1_rep_seq_y_h
                                             * Referenced by: '<S4>/Look-Up Table1'
                                             */
  real_T RepeatingSequence2_rep_seq_y_o[18];/* Mask Parameter: RepeatingSequence2_rep_seq_y_o
                                             * Referenced by: '<S5>/Look-Up Table1'
                                             */
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_f;     /* Mask Parameter: ServoWrite_pinNumber_f
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_n;     /* Mask Parameter: ServoWrite_pinNumber_n
                                        * Referenced by: '<S8>/Servo Write'
                                        */
  real_T Switch_Threshold;             /* Expression: 72
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value[3];            /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: period
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[10];    /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S10>/Look-Up Table1'
                                        */
  real_T Constant_Value_b;             /* Expression: period
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_j[16];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_fw;            /* Expression: period
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_i[17];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S4>/Look-Up Table1'
                                        */
  real_T Constant_Value_bc;            /* Expression: period
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_h[18];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S5>/Look-Up Table1'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 100
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 90
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -90
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: (130-25)/180
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Bias_Bias;                    /* Expression: 90
                                        * Referenced by: '<S2>/Bias'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Gain3_Gain;                   /* Expression: (130-25)/180
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T TrasmissioneRoll_Gain;        /* Expression: 52/103
                                        * Referenced by: '<S2>/TrasmissioneRoll'
                                        */
  real_T Bias1_Bias;                   /* Expression: 89
                                        * Referenced by: '<S2>/Bias1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S2>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S2>/Saturation2'
                                        */
  real_T Gain4_Gain;                   /* Expression: (115-35)/180
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T TrasmissioneYaw_Gain;         /* Expression: 59/94
                                        * Referenced by: '<S2>/TrasmissioneYaw'
                                        */
  real_T Bias2_Bias;                   /* Expression: 90
                                        * Referenced by: '<S2>/Bias2'
                                        */
  uint8_T ServoWrite_p1;               /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  uint8_T ServoWrite_p1_e;             /* Computed Parameter: ServoWrite_p1_e
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  uint8_T ServoWrite_p1_d;             /* Computed Parameter: ServoWrite_p1_d
                                        * Referenced by: '<S8>/Servo Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Calibration_procedure_T {
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
extern P_Calibration_procedure_T Calibration_procedure_P;

/* Block signals (auto storage) */
extern B_Calibration_procedure_T Calibration_procedure_B;

/* Model entry point functions */
extern void Calibration_procedure_initialize(void);
extern void Calibration_procedure_output(void);
extern void Calibration_procedure_update(void);
extern void Calibration_procedure_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Calibration_procedur_T *const Calibration_procedure_M;

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
 * '<Root>' : 'Calibration_procedure'
 * '<S1>'   : 'Calibration_procedure/Acc-Mag Calibration Sequence'
 * '<S2>'   : 'Calibration_procedure/Calibration Platform'
 * '<S3>'   : 'Calibration_procedure/Gyro Calibration Sequence'
 * '<S4>'   : 'Calibration_procedure/Acc-Mag Calibration Sequence/Repeating Sequence1'
 * '<S5>'   : 'Calibration_procedure/Acc-Mag Calibration Sequence/Repeating Sequence2'
 * '<S6>'   : 'Calibration_procedure/Calibration Platform/Standard Servo Write'
 * '<S7>'   : 'Calibration_procedure/Calibration Platform/Standard Servo Write1'
 * '<S8>'   : 'Calibration_procedure/Calibration Platform/Standard Servo Write2'
 * '<S9>'   : 'Calibration_procedure/Gyro Calibration Sequence/Repeating Sequence1'
 * '<S10>'  : 'Calibration_procedure/Gyro Calibration Sequence/Repeating Sequence2'
 */
#endif                                 /* RTW_HEADER_Calibration_procedure_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
