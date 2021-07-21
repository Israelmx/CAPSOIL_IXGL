#ifndef CAPSOIL_IXGL_H /* { */
#define CAPSOIL_IXGL_H
/*===========================================================================*\
 * FILE: name: CAPSOIL_IXGL.h
 *===========================================================================
 * Copyright 2021 IXGL Electronics., All Rights Reserved.
 * IXGL Electronics
 *---------------------------------------------------------------------------
 * version: 1
 * derived_by: Israel Gomez
 * date_modified: 07/18/2021
 *----------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   Archico que contiene los headers de la clase CAPSOIL
 *
 * ABBREVIATIONS:
 *   None.
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *   C Coding Standards SW REF 264.15D SW
 *
 * DEVIATIONS FROM STANDARDS:
 *
\*===========================================================================*/
/*============================================================================*\
 * Standard Header Files
\*============================================================================*/
#include <Arduino.h>

/*============================================================================*\
 * Other Header Files
\*============================================================================*/
//#define IDEBUGSERIAL

/*============================================================================*\
 * Class Preprocessor #define Constants
\*============================================================================*/

/*============================================================================*\
 *  Class Preprocessor #define MACROS
\*============================================================================*/

/*============================================================================*\
 * Class Type Declarations
\*============================================================================*/

/*============================================================================*\
 * Class Header
\*============================================================================*/
class CAPSOIL_IXGL
{
private:
  uint16_t _soilMoistureValue;
  uint8_t _soilmoisturepercent;
  uint8_t _analog_sensor_channel;
  uint16_t _airvalue;     //Calibration value, read the ADC value from the CS Sensor in air
  uint16_t _watervalue;   //Calibration value, read the ADC value from the CS Sensor in water

public:
  CAPSOIL_IXGL(uint8_t analog_sensor_channel = A0, uint16_t airvalue = 0, uint16_t watervalue = 0);    //Constructor
  ~CAPSOIL_IXGL();    //Destructor
  void Mtd_begin(void);
  uint8_t Mtd_get_hum(uint8_t adcfiltersamples = 1);
};

/*============================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *==============================================================================
 *
 * Date         userid    (Description on following lines: SCR #, etc.)
 * -----------  --------
 * 19-JUL-2021  Israel Gomez
 * - Created initial file.
 *
\*============================================================================*/
#endif /* } CAPSOIL_IXGL_H */