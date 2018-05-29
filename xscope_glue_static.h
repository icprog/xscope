#ifndef XSCOPE_GLUE_STATIC_H
#define XSCOPE_GLUE_STATIC_H

#include "xscope_endpoint.h"

#define XSCOPE_GLUE_API

#ifdef __cplusplus
extern "C"
{
#endif

	// Call back registration functions
	XSCOPE_GLUE_API int xscope_epc_set_register_cb(xscope_ep_register_fptr registration);
	XSCOPE_GLUE_API int xscope_epc_set_record_cb(xscope_ep_record_fptr record);
	XSCOPE_GLUE_API int xscope_epc_set_stats_cb(xscope_ep_stats_fptr stats);
	XSCOPE_GLUE_API int xscope_epc_set_print_cb(xscope_ep_print_fptr print);

	// Connect and disconnect from server
	XSCOPE_GLUE_API int xscope_epc_connect(const char *ipaddr, const char *port);
	XSCOPE_GLUE_API int xscope_epc_disconnect(void);

	// Endpoint request functions
	XSCOPE_GLUE_API int xscope_epc_request_registered(void);
	XSCOPE_GLUE_API int xscope_epc_request_stats(void);
	XSCOPE_GLUE_API int xscope_epc_request_upload(unsigned int length, const unsigned char *data);

#ifdef __cplusplus
}
#endif

#endif