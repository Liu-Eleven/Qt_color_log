#include "widget.h"
#include <QApplication>



#include <QDebug>
enum class LogType {
    Reset = 0,

    Bold,
    Unbold,

    FrontBlack,
    FrontRed,
    FrontGreen,
    FrontYellow,
    FrontBlue,
    FrontPurple,
    FrontCyan,
    FrontWhite,
    BackBlack,
    BackRed,
    BackGreen,
    BackYellow,
    BackBlue,
    BackPurple,
    BackCyan,
    BackWhite,

    TypeCount
};
static const char * logCommands[] = {
    "\033[0m",
    "\033[1m",
    "\033[2m",
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
    "\033[40m",
    "\033[41m",
    "\033[42m",
    "\033[43m",
    "\033[44m",
    "\033[45m",
    "\033[46m",
    "\033[47m",
};
template <typename EnumType, typename IntType = int>
int enumToInt(EnumType enumValue)
{
    static_assert (std::is_enum<EnumType>::value, "EnumType must be enum");

    return static_cast<IntType>(enumValue);
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    for (int i = enumToInt(LogType::Bold); i < enumToInt(LogType::TypeCount); ++i)
    {
        qInfo().nospace() << logCommands[i] << i << " Hello World" << logCommands[0];
    }
    qWarning() << logCommands[enumToInt(LogType::FrontBlue)]
            << logCommands[enumToInt(LogType::BackRed)]
            << u8"感谢大家对涛哥系列文章的支持，也"
               "欢迎直接联系我寻求帮助" << logCommands[0];





    Widget w;
    w.show();

    return a.exec();
}
