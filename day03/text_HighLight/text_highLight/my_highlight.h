#ifndef MY_HIGHLIGHT_H
#define MY_HIGHLIGHT_H

#include<QSyntaxHighlighter>
class my_highlight: public QSyntaxHighlighter
{
public:
    explicit my_highlight(QTextDocument *parent = nullptr);
    ~my_highlight();

    virtual void highlightBlock(const QString &text);//高亮函数 纯虚函数重写
};

#endif // MY_HIGHLIGHT_H
