#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

void MainWindow::iniUI()
{
    fLabCurFile = new QLabel;
    fLabCurFile->setMidLineWidth(150);
    fLabCurFile->setText("当前文件:");
    ui->statusbar->addWidget(fLabCurFile);

    progressBar = new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    comboFont = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel("字体"));
    ui->toolBar->addWidget(comboFont);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actioncuti_triggered(bool checked)
{
    QTextCharFormat fmt;
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actionjianqie->setEnabled(b);
    ui->actionfuzhi->setEnabled(b);
    ui->actionzhantie->setEnabled(ui->textEdit->canPaste());
}


void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    ui->actionxieti->setChecked(fmt.fontItalic());
    ui->actioncuti->setChecked(fmt.font().bold());
    ui->actionxiahuaxian->setChecked(fmt.fontUnderline());
}


void MainWindow::on_actAbout_triggered()
{
    // 创建消息对话框
    QMessageBox msgBox(this);
    // 设置对话框标题
    msgBox.setWindowTitle("关于");
    // 设置对话框内容
    msgBox.setText("开发者：陈灿粤\n学号：2023414290301");
    // 设置按钮为OK按钮
    msgBox.setStandardButtons(QMessageBox::Ok);
    // 设置默认按钮
    msgBox.setDefaultButton(QMessageBox::Ok);
    // 显示对话框并等待用户点击
    msgBox.exec();
}

