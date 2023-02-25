#include "KNDS_Result.h"
#include <stdlib.h>

KNDS_Result KNDS_ResultOK(void* data) {
	KNDS_Result result = {
		.code = KNDS_ResultCodeOK,
		.data = data,
		.message = NULL
	};
	
	return result;
}

KNDS_Result KNDS_ResultError(void* data, const char* message) {
	KNDS_Result result = {
		.code = KNDS_ResultCodeError,
		.data = data,
		.message = message
	};
	
	return result;
}
