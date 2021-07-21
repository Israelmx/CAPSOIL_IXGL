/*===========================================================================*\
 * FILE: name: CAPSOIL_IXGL.cpp
 *===========================================================================
 * Copyright 2021 IXGL Electronics., All Rights Reserved.
 * IXGL Electronics
 *---------------------------------------------------------------------------
 * version: 1
 * derived_by: Israel Gomez
 * date_modified: 07/19/2021
 *----------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   Archico que contiene los metodos de la clase CAPSOIL_IXGL
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

/*============================================================================*\
 * Other Header Files
\*============================================================================*/
#include "CAPSOIL_IXGL.h"

/*============================================================================*\
 * Local Preprocessor #define Constants
\*============================================================================*/

/*============================================================================*\
 * Local Preprocessor #define MACROS
\*============================================================================*/

/*============================================================================*\
 * Local Type Declarations
\*============================================================================*/

/*============================================================================*\
 * Exported Object Definitions
\*============================================================================*/

/*============================================================================*\
 * Local Object Definitions
\*============================================================================*/

/*============================================================================*\
 * Local Function Prototypes
\*============================================================================*/

/*============================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*============================================================================*/

/*============================================================================*\
 * Local Preprocessor Declaration
\*============================================================================*/

/*******************************************************************************
 * FUNCTION: CAPSOIL_IXGL CONSTRUCTOR
 *******************************************************************************
 * RETURN VALUE:
 *    None.
 *
 * PARAMETERS:
 *    None.
 *
 * EXTERNAL REFERENCES:
 *    None.
 *
 * DEVIATION FROM STANDARDS:
 *    None.
 *
 * -----------------------------------------------------------------------------
 * ABSTRACT:
 * -----------------------------------------------------------------------------
 * Constructor para Inicializar los atributos de la clase
 *
 * PRECONDITIONS:
 * None.
 *
 * POSTCONDITIONS:
 * None.
 *
\******************************************************************************/
// Old C++ way to initialize the attributes of the class
/*CAPSOIL_IXGL::CAPSOIL_IXGL(uint8_t analog_sensor_channel, uint16_t airvalue, uint16_t watervalue)
{
  _analog_sensor_channel = analog_sensor_channel;
  _airvalue = airvalue;
  _watervalue = watervalue;
}*/
// New C++ way to initialize the attributes of the class
CAPSOIL_IXGL::CAPSOIL_IXGL(uint8_t analog_sensor_channel, uint16_t airvalue, uint16_t watervalue)
  : _analog_sensor_channel{analog_sensor_channel}, _airvalue{airvalue}, _watervalue{watervalue}
{
}

/*******************************************************************************
 * FUNCTION: ~CAPSOIL_IXGL Destructor
 *******************************************************************************
 * RETURN VALUE:
 *    None.
 *
 * PARAMETERS:
 *    None.
 *
 * EXTERNAL REFERENCES:
 *    None.
 *
 * DEVIATION FROM STANDARDS:
 *    None.
 *
 * -----------------------------------------------------------------------------
 * ABSTRACT:
 * -----------------------------------------------------------------------------
 * Constructor para Inicializar los atributos de la clase
 *
 * PRECONDITIONS:
 * None.
 *
 * POSTCONDITIONS:
 * None.
 *
\******************************************************************************/
CAPSOIL_IXGL::~CAPSOIL_IXGL()
{
}

/*******************************************************************************
 * FUNCTION: Mtd_begin
 *******************************************************************************
 * RETURN VALUE:
 *    None.
 *
 * PARAMETERS:
 *    None.
 *
 * EXTERNAL REFERENCES:
 *    None.
 *
 * DEVIATION FROM STANDARDS:
 *    None.
 *
 * -----------------------------------------------------------------------------
 * ABSTRACT:
 * -----------------------------------------------------------------------------
 * Metodo para iniciar la configuracion del Sensor Capacitivo
 *
 * PRECONDITIONS:
 * None.
 *
 * POSTCONDITIONS:
 * None.
 *
\******************************************************************************/
void CAPSOIL_IXGL::Mtd_begin()
{
  //TODO hacer begin para inicializar conf An si se usa un device que lo requiera
  
  #ifdef IDEBUGSERIAL
  Serial.println("Se Inicia canal AN para el Sensor Capacitivo");
  #endif
}

/*******************************************************************************
 * FUNCTION: Mtd_get_hum
 *******************************************************************************
 * RETURN VALUE:
 *    value: Regresa el % de humedad en el sensor
 *
 * PARAMETERS:
 *    None.
 *
 * EXTERNAL REFERENCES:
 *    None.
 *
 * DEVIATION FROM STANDARDS:
 *    None.
 *
 * -----------------------------------------------------------------------------
 * ABSTRACT:
 * -----------------------------------------------------------------------------
 * Metodo para obtener la Humedad del sensor
 *
 * PRECONDITIONS:
 * None.
 *
 * POSTCONDITIONS:
 * None.
 *
\******************************************************************************/
uint8_t CAPSOIL_IXGL::Mtd_get_hum(uint8_t adcfiltersamples)
{
  uint16_t filteredADC = 0;

  for(uint8_t i = 0; i < adcfiltersamples; i++)
  {
    filteredADC = (filteredADC + (analogRead(_analog_sensor_channel)));
    delay(1);
  }

  _soilMoistureValue = filteredADC / adcfiltersamples;
  
  #ifdef IDEBUGSERIAL
  Serial.println(_soilMoistureValue);
  #endif
  if(_soilMoistureValue >= _watervalue && _soilMoistureValue <= _airvalue)
  {
    _soilmoisturepercent = map(_soilMoistureValue, _airvalue, _watervalue, 0, 100);
    #ifdef IDEBUGSERIAL
    Serial.print("Valores dentro de los limites: ");Serial.print(_soilmoisturepercent);Serial.println("%");
    #endif
  }
  else
  {
    _soilmoisturepercent = 254;
    #ifdef IDEBUGSERIAL
    Serial.println("ERROR!!! Valores fuera de los limites");
    #endif
  }
  return _soilmoisturepercent;
}