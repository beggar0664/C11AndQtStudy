#include "my_highlight.h"
my_highlight::my_highlight(QTextDocument *parent):QSyntaxHighlighter(parent)
{

}

my_highlight::~my_highlight()
{

}

void my_highlight::highlightBlock(const QString &text)
{
    QTextCharFormat myFormat;
    myFormat.setFont(QFont("微软雅黑"));
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);
    //匹配char这个单词 前后都有空格
    QString pattern = "\\bchar\\b";
    //创建正则表达式
    QRegExp express(pattern);
    //从索引0的位置开始匹配
    int index = text.indexOf(express);
    while (index>0) {
       int matchLen = express.matchedLength();
       //对匹配的字符串设置高亮
       setFormat(index, matchLen, myFormat);
       index = text.indexOf(express, index+matchLen);
    }

}
