#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QToolButton>
#include "widget.h"
#include <QMessageBox>
#pragma execution_character_set("utf-8")
DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    setWindowTitle("Myself QQ 2017");
    setWindowIcon(QPixmap(":/images/qq.png"));

    QList<QString>nameList;
    nameList << "水票奇缘" << "忆梦如澜" <<"北京出版人"<<"Cherry"<<"淡然"
             <<"娇娇girl"<<"落水无痕"<<"青墨暖暖"<<"无语";


    QStringList iconNameList; //图标资源列表
    iconNameList << "spqy"<< "ymrl" <<"qq" <<"Cherry"<< "dr"
                 <<"jj"<<"lswh"<<"qmnn"<<"wy";

    QVector<QToolButton *>vToolBtn; //声明存放QtoolButton的容器 vToolBtn
    for(int i = 0 ;i < 9 ; i ++)
    {
        isShow.push_back(false);
        QToolButton * btn = new QToolButton;  //创建新按钮
        btn->setText( nameList[i]);     //设置按钮名称
        QString str = QString(":/images/%1.png").arg(iconNameList.at(i));
        btn->setIcon(QPixmap(str));   //设置图片
        btn->setIconSize(QPixmap(str).size()); //设置图片大小
        btn->setAutoRaise(true);  //设置图片透明效果
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置按钮风格，同时显示文字和图标

        ui->vLayout->addWidget(btn); //将按钮添加到布局中

        vToolBtn.push_back(btn); //将9个按钮放入到布局中
    }

    //添加点击事件
    for(int i = 0 ; i < vToolBtn.size();i++)
    {
        connect(vToolBtn[i],&QToolButton::clicked,this,[=]()
        {
            if(isShow[i])
            {
                QMessageBox::information(this,"警告",QString("用户%1窗口已弹出").arg(vToolBtn[i]->text()));
                return;
            }
            isShow[i] = true;
            //qDebug() <<i;
            //此时，widget的构造函数已经修改，（见4.2步骤）创建widget窗口时，参数1 ：0代表以顶层方式弹出
            //参数2：代表vToolBtn[i]->text()代表告诉聊天窗口 人物的姓名
            Widget *chatWidget = new Widget(0,vToolBtn[i]->text());
            chatWidget->setWindowTitle(vToolBtn[i]->text());
            chatWidget->setWindowIcon(vToolBtn[i]->icon());
            chatWidget->show();

            connect(chatWidget,&Widget::widgetClose,this,[=](){
                isShow[i] = false;
            });

        });
    }
}

DialogList::~DialogList()
{
    delete ui;
}
