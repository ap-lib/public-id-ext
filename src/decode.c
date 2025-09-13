#include "public_id.h"
#include "utils.h"
#include <math.h>

PHP_FUNCTION(public_id_decode) {
        zend_long publicID, secret, digitsDivider = 2;

        ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_LONG(publicID)
        Z_PARAM_LONG(secret)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(digitsDivider)
        ZEND_PARSE_PARAMETERS_END();

        if (digitsDivider < 1 || digitsDivider > 5) {
            zend_throw_exception_ex(zend_ce_exception, 0, "digitsDivider must be between 1 and 5");
            RETURN_THROWS();
        }

        RETURN_LONG((zend_long)decode_safe((uint64_t)publicID, (uint64_t)secret, (int)digitsDivider));
}