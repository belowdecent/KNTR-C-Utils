#ifndef _KNDS_Result
#define _KNDS_Result

typedef enum {
	KNDS_ResultCodeOK, KNDS_ResultCodeError
} KNDS_ResultCode;

typedef struct KNDS_Result {
	void* data;
	const KNDS_ResultCode code;
	const char* message;
} KNDS_Result;

KNDS_Result KNDS_ResultOK(void* data);
KNDS_Result KNDS_ResultError(void* data, const char* message);

#endif
