#include "__cf_mdlref_dynamics.h"
#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME mdlref_dynamics_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "mdlref_dynamics_types.h"
#include "mdlref_dynamics.h"
#include "mdlref_dynamics_private.h"
MdlRefChildMdlRec childModels [ 1 ] = { "mdlref_dynamics" , "mdlref_dynamics"
, 0 } ;
#define MDL_START
static void mdlStart ( SimStruct * S ) { j2rfdjcge2s * dw = ( j2rfdjcge2s * )
ssGetDWork ( S , 0 ) ; p0wdhtge1j * rtx = ( p0wdhtge1j * ) ssGetContStates (
S ) ; void * sysRanPtr = ( NULL ) ; int sysTid = 0 ; ssGetContextSysRanBCPtr
( S , & sysRanPtr ) ; ssGetContextSysTid ( S , & sysTid ) ; if ( sysTid ==
CONSTANT_TID ) { sysTid = 0 ; } ac2tgih0za ( S , ssGetSampleTimeTaskID ( S ,
0 ) , & ( dw -> rtm ) , & ( dw -> rtb ) , rtx , sysRanPtr , sysTid , ( NULL )
, ( NULL ) , 0 , - 1 ) ; ssSetModelMappingInfoPtr ( S , & ( dw -> rtm .
DataMapInfo . mmi ) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) {
_GenericFcn fcn = S -> mdlInfo -> genericFcn ; } }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { j2rfdjcge2s * dw = (
j2rfdjcge2s * ) ssGetDWork ( S , 0 ) ; owdlnsejlu * rtxdot = ( owdlnsejlu * )
ssGetdX ( S ) ; p0wdhtge1j * rtx = ( p0wdhtge1j * ) ssGetContStates ( S ) ;
a4x4bou2tv ( & ( dw -> rtb ) , rtx , rtxdot ) ; }
#define  MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions ( SimStruct * S ) { j2rfdjcge2s * dw = (
j2rfdjcge2s * ) ssGetDWork ( S , 0 ) ; p0wdhtge1j * localX = ( p0wdhtge1j * )
ssGetContStates ( S ) ; ar42usgqeo ( localX ) ; return ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetNumSFcnParams ( S , 0 ) ;
ssFxpSetU32BitRegionCompliant ( S , 1 ) ; rt_InitInfAndNaN ( sizeof ( real_T
) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) { _GenericFcn fcn = S ->
mdlInfo -> genericFcn ; real_T lifeSpan = rtInf ; real_T startTime = 0.0 ;
real_T stopTime = 10.0 ; int_T hwSettings [ 15 ] ; int_T opSettings [ 1 ] ;
boolean_T concurrTaskSupport = 0 ; boolean_T hasDiscTs = 0 ;
ModelRefChildSolverInfo solverInfo = { 0 , - 1 , 0.001 , 0.2 , 0.0 , 0.0 } ;
( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_TYPE_EARLY , 1 , ( NULL ) ) ; ( fcn
) ( S , GEN_FCN_MODELREF_RATE_GROUPED , 0 , ( NULL ) ) ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_LIFE_SPAN , - 1 , & lifeSpan ) ) return ; if ( ! ( fcn )
( S , GEN_FCN_CHK_MODELREF_START_TIME , - 1 , & startTime ) ) return ; if ( !
( fcn ) ( S , GEN_FCN_CHK_MODELREF_STOP_TIME , - 1 , & stopTime ) ) return ;
hwSettings [ 0 ] = 8 ; hwSettings [ 1 ] = 16 ; hwSettings [ 2 ] = 32 ;
hwSettings [ 3 ] = 32 ; hwSettings [ 4 ] = 32 ; hwSettings [ 5 ] = 64 ;
hwSettings [ 6 ] = 32 ; hwSettings [ 7 ] = 2 ; hwSettings [ 8 ] = 0 ;
hwSettings [ 9 ] = 32 ; hwSettings [ 10 ] = 1 ; hwSettings [ 11 ] = 0 ;
hwSettings [ 12 ] = 2 ; hwSettings [ 13 ] = 64 ; hwSettings [ 14 ] = 0 ; if (
! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_HARDWARE_SETTINGS , 15 , hwSettings ) )
return ; opSettings [ 0 ] = 0 ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_OPTIM_SETTINGS , 1 , opSettings ) ) return ; if ( ! (
fcn ) ( S , GEN_FCN_CHK_MODELREF_CONCURRETNT_TASK_SUPPORT , ( int_T )
concurrTaskSupport , ( NULL ) ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_SOLVER_TYPE , 0 , & hasDiscTs ) ) return ; if ( ! ( fcn
) ( S , GEN_FCN_CHK_MODELREF_SOLVER_NAME , 0 , ( void * ) "ode45" ) ) return
; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_MODE ,
SOLVER_MODE_SINGLETASKING , ( NULL ) ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_VSOLVER_OPTS , - 1 , & solverInfo ) ) return ; ( fcn ) (
S , GEN_FCN_CHK_MODELREF_FRAME_UPGRADE_DIAGNOSTICS , 1 , ( NULL ) ) ; } {
static const char * globalVarList [ ] = { "Md" , "Mq" , "Mw" , "Uo" , "Zd" ,
"Zw" } ; ssRegModelRefGlobalVarUsage ( S , 6 , ( void * ) globalVarList ) ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 2 ) ;
ssSetNumDiscStates ( S , 0 ) ; if ( ! ssSetNumInputPorts ( S , 3 ) ) return ;
if ( ! ssSetInputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 0 ,
FALSE ) ; ssSetInputPortSampleTime ( S , 0 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 0 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 1 ,
FALSE ) ; ssSetInputPortSampleTime ( S , 1 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 1 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 2 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 2 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 2 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 2 , 1 ) ; ssSetInputPortOptimOpts ( S
, 2 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 2 ,
FALSE ) ; ssSetInputPortSampleTime ( S , 2 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 2 , 0.0 ) ; if ( ! ssSetNumOutputPorts ( S , 2 ) ) return ; if ( !
ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } ssSetOutputPortSampleTime ( S , 0 , 0.0 ) ; ssSetOutputPortOffsetTime ( S
, 0 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 0 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 1 , SS_DOUBLE )
; } ssSetOutputPortSampleTime ( S , 1 , 0.0 ) ; ssSetOutputPortOffsetTime ( S
, 1 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 1 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 1 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortOptimOpts ( S , 1 , SS_NOT_REUSABLE_AND_GLOBAL ) ; { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 0 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 0 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 1 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 1 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 2 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 2 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefOutputSignalDesignMin ( S , 0 , & minValue ) ;
ssSetModelRefOutputSignalDesignMax ( S , 0 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefOutputSignalDesignMin ( S , 1 , & minValue ) ;
ssSetModelRefOutputSignalDesignMax ( S , 1 , & maxValue ) ; } { static
ssRTWStorageType storageClass [ 5 ] = { SS_RTW_STORAGE_AUTO ,
SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO ,
SS_RTW_STORAGE_AUTO } ; ssSetModelRefPortRTWStorageClasses ( S , storageClass
) ; } ssSetModelRefSignalLoggingSaveFormat ( S , SS_MODEL_DATA_LOGS ) ;
ssSetNumSampleTimes ( S , PORT_BASED_SAMPLE_TIMES ) ; ssSetNumRWork ( S , 0 )
; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ; ssSetNumModes ( S , 0 )
; { int_T zcsIdx = 0 ; } ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 1 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 1 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 0 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 0 ) ; ssSetInputPortIsNotDerivPort ( S , 2 , 0 ) ;
ssSetModelReferenceSampleTimeInheritanceRule ( S ,
DISALLOW_SAMPLE_TIME_INHERITANCE ) ; ssSetOptimizeModelRefInitCode ( S , 0 )
; ssSetAcceptsFcnCallInputs ( S ) ; { static const char * inlinedVars [ ] = {
"Md" , "Mq" , "Mw" , "Uo" , "Zd" , "Zw" } ; ssSetModelRefInlinedVars ( S , 6
, ( void * ) inlinedVars ) ; } ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
TRUE ) ; ssHasStateInsideForEachSS ( S , FALSE ) ;
ssSetModelRefHasParforForEachSS ( S , FALSE ) ;
ssSetModelRefHasVariantModelOrSubsystem ( S , FALSE ) ; ssSetNumAsyncTs ( S ,
0 ) ; ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE |
SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES
| SS_OPTION_WORKS_WITH_CODE_REUSE ) ; if ( S -> mdlInfo -> genericFcn != (
NULL ) ) { ssRegModelRefChildModel ( S , 1 , childModels ) ; }
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ;
mr_mdlref_dynamics_MdlInfoRegFcn ( S , "mdlref_dynamics" , & retVal ) ; if (
! retVal ) return ; }
#endif
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#if SS_SFCN_FOR_SIM
{ int mdlrefDWTypeId ; ssRegMdlRefDWorkType ( S , & mdlrefDWTypeId ) ; if (
mdlrefDWTypeId == INVALID_DTYPE_ID ) return ; if ( ! ssSetDataTypeSize ( S ,
mdlrefDWTypeId , sizeof ( j2rfdjcge2s ) ) ) return ; ssSetDWorkDataType ( S ,
0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S , 0 , 1 ) ; }
#endif
ssSetNeedAbsoluteTime ( S , 1 ) ; ssSetModelRefHasEnablePort ( S , 0 ) ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { return ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } return ; } static void mdlOutputs ( SimStruct * S , int_T tid
) { j2rfdjcge2s * dw = ( j2rfdjcge2s * ) ssGetDWork ( S , 0 ) ; const real_T
* ocz11diacw = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; const real_T *
dr23ilxne2 = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; const real_T *
dxucvkhuzj = ( real_T * ) ssGetInputPortSignal ( S , 2 ) ; real_T * B_1_1 = (
real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * B_1_2 = ( real_T * )
ssGetOutputPortSignal ( S , 1 ) ; p0wdhtge1j * localX = ( p0wdhtge1j * )
ssGetContStates ( S ) ; if ( tid != CONSTANT_TID ) { mdlref_dynamics (
ocz11diacw , dr23ilxne2 , dxucvkhuzj , B_1_1 , B_1_2 , & ( dw -> rtb ) ,
localX ) ; } }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { j2rfdjcge2s * dw = (
j2rfdjcge2s * ) ssGetDWork ( S , 0 ) ; jyicxpgorh ( ) ; return ; } static
void mdlTerminate ( SimStruct * S ) { return ; }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif
