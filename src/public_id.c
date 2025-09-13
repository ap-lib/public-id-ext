#include "public_id.h"

static const zend_function_entry public_id_functions[] = {
        PHP_FE(public_id_encode, arginfo_public_id_encode)
        PHP_FE(public_id_decode, arginfo_public_id_decode)
        PHP_FE_END
};

zend_module_entry public_id_module_entry = {
        STANDARD_MODULE_HEADER,
        "public_id",
        public_id_functions,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        PHP_PUBLIC_ID_VERSION,
        STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(public_id)