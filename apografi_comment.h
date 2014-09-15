#ifndef APOGRAFI_COMMENT_H
#define APOGRAFI_COMMENT_H

#include <QDialog>

namespace Ui {
class apografi_comment;
}

class apografi_comment : public QDialog
{
    Q_OBJECT

public:
    explicit apografi_comment(QWidget *parent = 0);
    ~apografi_comment();

private:
    Ui::apografi_comment *ui;
};

#endif // APOGRAFI_COMMENT_H
