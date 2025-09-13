#ifndef PHP_PUBLIC_ID_H
#define PHP_PUBLIC_ID_H

#include "php.h"
#include <stdint.h>
#include "Zend/zend_exceptions.h"

// Version
#define PHP_PUBLIC_ID_VERSION "0.1.0"

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_public_id_encode, 0, 2, IS_LONG, 0)
ZEND_ARG_TYPE_INFO(0, original, IS_LONG, 0)
ZEND_ARG_TYPE_INFO(0, secret, IS_LONG, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, digitsDivider, IS_LONG, 0, "2")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_public_id_decode, 0, 2, IS_LONG, 0)
ZEND_ARG_TYPE_INFO(0, publicID, IS_LONG, 0)
ZEND_ARG_TYPE_INFO(0, secret, IS_LONG, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, digitsDivider, IS_LONG, 0, "2")
ZEND_END_ARG_INFO()

PHP_FUNCTION(public_id_encode);
PHP_FUNCTION(public_id_decode);

#endif // PHP_PUBLIC_ID_H