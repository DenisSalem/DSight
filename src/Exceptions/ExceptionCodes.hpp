#ifndef _EXCEPTION_CODES_HPP_INCLUDED_
#define _EXCEPTION_CODES_HPP_INCLUDED_

namespace DSight {
	enum ExceptionCode {
		DSIGHT_EXCEPTION_MULTIPLE_CONTEXT,
		DSIGHT_EXCEPTION_CONTEXT_INIT_FAILED,
		DSIGHT_EXCEPTION_UNSUPPORTED_CONTEXT,
		DSIGHT_EXCEPTION_CANVAS_CREATION_FAILED,
		DSIGHT_EXCEPTION_CANVAS_DOESNT_EXISTS,
		DSIGHT_EXCEPTION_MISMATCH_BETWEEN_PARAMS_LENGHT,
		DSIGHT_EXCEPTION_INVALID_COORDINATES
	};
}

#endif
