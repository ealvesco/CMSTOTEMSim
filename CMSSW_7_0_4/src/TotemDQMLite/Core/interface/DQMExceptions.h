/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

/*********************************************************************
 * Exceptions used within Monitor Module
 * *****************************************************************/

#ifndef _DQMExceptions_h_
#define _DQMExceptions_h_

#include <exception>
#include <string>

/**
 * \ingroup TotemDQMLite
 * \brief
 **/
class UnknownMonitorException : public std::exception {

};


/**
 * \ingroup TotemDQMLite
 * \brief
 **/
class WrongGraphNameForPlotManager : public UnknownMonitorException {
};


/**
 * \ingroup TotemDQMLite
 * \brief
 **/
class NoDataFilesException : public UnknownMonitorException {
};


/**
 * \ingroup TotemDQMLite
 * \brief
 **/
class NoSourceInConfigurationFileException : public UnknownMonitorException {
};


#endif
