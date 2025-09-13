PHP_ARG_ENABLE(public_id, whether to enable the public_id extension,
[  --enable-public-id           Enable public_id extension])

if test "$PHP_PUBLIC_ID" != "no"; then
  PHP_NEW_EXTENSION(public_id, public_id.c encode.c decode.c utils.c, $ext_shared)
fi