#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    QObject::connect(ui->lineEdit, &QLineEdit::textChanged,
                     ui->pushButton, &QPushButton::setText);

    QObject::connect(ui->lineEdit, &QLineEdit::textChanged,
                     [&](QString text){if(text == "exit") close();});
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->pushButton->setText("Tıklandı");
}
