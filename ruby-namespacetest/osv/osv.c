#include <ruby.h>

extern void run_namespace1(char *path, char **args, int argv, int *return_code);

static VALUE osv_run_namespace(VALUE self, VALUE path, VALUE args)
{
    char *_path = StringValuePtr(path);
    char *_args[RARRAY_LEN(args)];
    int _argv = RARRAY_LEN(args);
    int _return_code = -1;
    int i;

    printf("%s path:%s args:", __func__, _path);
    Check_Type(args, T_ARRAY);

    for (i = 0; i < RARRAY_LEN(args); i++) {
        VALUE ent = rb_ary_entry(args, i);
        _args[i] = StringValuePtr(ent);
        printf("%s ", _args[i]);
    }
    printf("run_namespace1:%p\n", (void *)run_namespace1);

    run_namespace1(_path, _args, _argv, &_return_code);
    printf("%s return_code:%d\n", __func__, _return_code);
    return INT2FIX(_return_code);
}

void Init_osv()
{
    VALUE rb_cOSv = rb_define_class("OSv", rb_cObject);

    rb_define_singleton_method(rb_cOSv, "run_namespace", osv_run_namespace, 2);
}
