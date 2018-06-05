#include "__cf_mdlref_dynamics.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "mdlref_dynamics_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "mdlref_dynamics.h"
#include "mdlref_dynamics_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_LoggingBusElement rtBusElements [ ] =
{ { 0 , rtwCAPI_signal } } ; static rtwCAPI_LoggingBusSignals rtBusSignals [
] = { { ( NULL ) , ( NULL ) , 0 , 0 , ( NULL ) } } ; static rtwCAPI_States
rtBlockStates [ ] = { { 0 , 0 , TARGET_STRING (
"mdlref_dynamics/Transfer Fcn.1" ) , TARGET_STRING ( "" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 , 1 } , { 1 , 1 , TARGET_STRING (
"mdlref_dynamics/Transfer Fcn.2" ) , TARGET_STRING ( "" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 , 1 } , { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void mdlref_dynamics_InitializeDataAddr ( void * dataAddr [ ] ,
p0wdhtge1j * localX ) { dataAddr [ 0 ] = ( void * ) ( & localX -> n2yvg5srwp
) ; dataAddr [ 1 ] = ( void * ) ( & localX -> ones4i0zka ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void mdlref_dynamics_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ]
) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 1 , 1
} ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static int_T
rtContextSystems [ 2 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] =
{ { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 2 , rtContextSystems , loggingMetaInfo , 0 ,
rtBusSignals , { 0 , NULL , NULL } , 0 , ( NULL ) } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0 , ( NULL )
, 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockStates , 2
} , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap ,
rtSampleTimeMap , rtDimensionArray } , "float" , & mmiStaticInfoLogging , 0 ,
} ; const rtwCAPI_ModelMappingStaticInfo * mdlref_dynamics_GetCAPIStaticMap (
) { return & mmiStatic ; } static void mdlref_dynamics_InitializeSystemRan (
ak145u3k0y * const iuhkr151ru , sysRanDType * systemRan [ ] , int_T systemTid
[ ] , void * rootSysRanPtr , int rootTid ) { systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemTid [ 1 ] = mo2nfnaknm
[ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ;
rtContextSystems [ 1 ] = 0 ; }
#ifndef HOST_CAPI_BUILD
void mdlref_dynamics_InitializeDataMapInfo ( ak145u3k0y * const iuhkr151ru ,
p0wdhtge1j * localX , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( iuhkr151ru -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( iuhkr151ru -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( iuhkr151ru -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; mdlref_dynamics_InitializeDataAddr ( iuhkr151ru ->
DataMapInfo . dataAddress , localX ) ; rtwCAPI_SetDataAddressMap ( iuhkr151ru
-> DataMapInfo . mmi , iuhkr151ru -> DataMapInfo . dataAddress ) ;
mdlref_dynamics_InitializeVarDimsAddr ( iuhkr151ru -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( iuhkr151ru -> DataMapInfo .
mmi , iuhkr151ru -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath (
iuhkr151ru -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath (
iuhkr151ru -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetInstanceLoggingInfo
( iuhkr151ru -> DataMapInfo . mmi , & iuhkr151ru -> DataMapInfo .
mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( iuhkr151ru -> DataMapInfo .
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( iuhkr151ru -> DataMapInfo .
mmi , 0 ) ; mdlref_dynamics_InitializeSystemRan ( iuhkr151ru , iuhkr151ru ->
DataMapInfo . systemRan , iuhkr151ru -> DataMapInfo . systemTid , sysRanPtr ,
contextTid ) ; rtwCAPI_SetSystemRan ( iuhkr151ru -> DataMapInfo . mmi ,
iuhkr151ru -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid ( iuhkr151ru
-> DataMapInfo . mmi , iuhkr151ru -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( iuhkr151ru -> DataMapInfo . mmi , & mo2nfnaknm [ 0
] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void mdlref_dynamics_host_InitializeDataMapInfo (
mdlref_dynamics_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
