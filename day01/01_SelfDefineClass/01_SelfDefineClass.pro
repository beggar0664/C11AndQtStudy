greaterThan(QT_MAJOR_VERSION, 4):QT+=widgets#添加 widgets 模块调用代码

HEADERS += \
    helloDialog.h \
    ui_hello.h

SOURCES += \
    helloDialog.cpp \
    main.cpp
