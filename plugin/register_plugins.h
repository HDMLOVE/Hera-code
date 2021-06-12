/******************************************
 * Filename : register_plugins.h
 * Time     : 2021-06-11 00:31
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_REGISTER_PLUGINS_H
#define HERA_CODE_REGISTER_PLUGINS_H

struct mod_private{
    const char *name;       /* 注册的插件模块名称 */
    int (*init)(int, int);  /* 模块初始化函数 */
    void (*clean)(void);    /* 模块清理函数 */
};

/插件注册宏函数*/
#define register_plugin_fn(modname, initfn, cleanfn) \
        struct mod_private *register_declare_##modname(void) \
        {                                            \
            static mod_private mod = {               \
            .name = #modname,                        \
            .init = initfn,                          \
            .clean = cleanfn,                        \
            };                                       \
            return &mod;                             \
        }
#endif
