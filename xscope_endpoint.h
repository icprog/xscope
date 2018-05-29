#ifndef _XSCOPE_ENDPOINT_H_
#define _XSCOPE_ENDPOINT_H_

#ifdef WIN32
  #define XSCOPE_EP_DLL_EXPORT __declspec(dllexport)
#else
  #define XSCOPE_EP_DLL_EXPORT
#endif

#define XSCOPE_EP_SUCCESS 0
#define XSCOPE_EP_FAILURE 1

typedef void (*xscope_ep_register_fptr)(unsigned int id, 
                                        unsigned int type,
                                        unsigned int r,
                                        unsigned int g,
                                        unsigned int b,
                                        unsigned char *name,
                                        unsigned char *unit,
                                        unsigned int data_type,
                                        unsigned char *data_name);

typedef void (*xscope_ep_record_fptr)(unsigned int id,
                                      unsigned long long timestamp,
                                      unsigned int length,
                                      unsigned long long dataval,
                                      unsigned char *databytes);

typedef void (*xscope_ep_stats_fptr)(int id, unsigned long long average);

typedef void (*xscope_ep_print_fptr)(unsigned long long timestamp, unsigned int length, unsigned char *data);


int xscope_ep_init(xscope_ep_register_fptr register, 
                   xscope_ep_record_fptr record, 
                   xscope_ep_stats_fptr stats);


// Call back registration functions
XSCOPE_EP_DLL_EXPORT int xscope_ep_set_register_cb(xscope_ep_register_fptr registration);
XSCOPE_EP_DLL_EXPORT int xscope_ep_set_record_cb(xscope_ep_record_fptr record);
XSCOPE_EP_DLL_EXPORT int xscope_ep_set_stats_cb(xscope_ep_stats_fptr stats);
XSCOPE_EP_DLL_EXPORT int xscope_ep_set_print_cb(xscope_ep_print_fptr print);

// Connect and disconnect from server
XSCOPE_EP_DLL_EXPORT int xscope_ep_connect(const char *ipaddr, const char *port);
XSCOPE_EP_DLL_EXPORT int xscope_ep_disconnect(void);

// Endpoint request functions
XSCOPE_EP_DLL_EXPORT int xscope_ep_request_registered(void);
XSCOPE_EP_DLL_EXPORT int xscope_ep_request_stats(void);
XSCOPE_EP_DLL_EXPORT int xscope_ep_request_upload(unsigned int length, const unsigned char *data);

#endif
