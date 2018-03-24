##These classes can print important info of system and Qt environment

####QSysInfo用于输出系统类型、位数等信息
1. productType()在windows系统输出"windows",在Ubuntu上输出"Ubuntu"
2. kernelType()在windows系统输出"winnt",在Ubuntu上输出"linux"

####QLibrary用于输出Qt版本，编译等信息

####QSetting用于读取注册表，比如CPU名称等信息