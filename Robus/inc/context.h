/******************************************************************************
 * @file context
 * @brief definition of context structure environement luos variable
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <robus.h>
#include "config.h"
#include "port_manager.h"
#include "reception.h"
#include "transmission.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifdef SNIFFER_H
typedef struct
{
    // Variables
    uint64_t crc_error_count;
    uint64_t corruption_count;
} sniffer_t;
#endif /*SNIFFER_H*/

typedef struct
{

    // Variables
    node_t node;       /*!< Node informations. */
    RxCom_t rx;        /*!< Receiver informations. */
    TxCom_t tx;        /*!< Transmitter informations. */
    PortMng_t port;    /*!< port informations. */
#ifdef SNIFFER_H       /*!< Sniffer Information */
    sniffer_t sniffer; /*!< sniffer informations. */
#endif                 /*SNIFFER_H*/

    // Low level service management
    ll_service_t ll_service_table[MAX_SERVICE_NUMBER]; /*!< Low level Service table. */
    uint16_t ll_service_number;                        /*!< Low level Service number. */

} context_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile extern context_t ctx;
/*******************************************************************************
 * Function
 ******************************************************************************/

#endif /* _CONTEXT_H_ */
