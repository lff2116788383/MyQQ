#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QWidget>

namespace Ui {
class DialogList;
}

class DialogList : public QWidget
{
    Q_OBJECT

public:
    explicit DialogList(QWidget *parent = nullptr);
    ~DialogList();

    QVector<bool>isShow;// 代表是否打开窗口的标识，false未打开，true打开
private:
    Ui::DialogList *ui;
};

#endif // DIALOGLIST_H
