#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs = {{Qt::Key_0,ui->btnNum0},
               {Qt::Key_1,ui->btnNum1},
               {Qt::Key_2,ui->btnNum2},
               {Qt::Key_3,ui->btnNum3},
               {Qt::Key_4,ui->btnNum4},
               {Qt::Key_5,ui->btnNum5},
               {Qt::Key_6,ui->btnNum6},
               {Qt::Key_7,ui->btnNum7},
               {Qt::Key_8,ui->btnNum8},
               {Qt::Key_9,ui->btnNum9},
               };
    foreach(auto btn, digitBTNs)
        connect(btn, SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    //正负号
    connect(ui->btnSign, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));

    //connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    //connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if (ok != nullptr) *ok = false;  // 默认为计算失败

    // 仅当有2个操作数和1个运算符时计算
    if (operands.size() == 2 && !opcodes.isEmpty()) {
        double op1 = operands.pop().toDouble();  // 弹出栈顶（后输入的数）
        double op2 = operands.pop().toDouble();  // 弹出下一个数（先输入的数）
        QString op = opcodes.pop();              // 弹出运算符

        // 计算（注意顺序：op2 运算符 op1，因为栈是后进先出）
        if (op == "+") {
            result = op2 + op1;
        } else if (op == "-") {
            result = op2 - op1;
        } else if (op == "*") {
            result = op2 * op1;
        } else if (op == "/") {
            if (op1 == 0) {
                ui->statusbar->showMessage("除数不能为0");
                return "错误";
            }
            result = op2 / op1;
        }

        *ok = true;  // 计算成功
        ui->statusbar->showMessage(QString("计算后：操作数剩余%1，运算符剩余%2")
                                       .arg(operands.size()).arg(opcodes.size()));
    } else {
        ui->statusbar->showMessage("操作数或运算符不足，无法计算");
    }

    return QString::number(result);

}

void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && operand == "0")
        digit = "";

    if(operand == "0" && digit != "0")
        operand = "";

    operand += digit;

    ui->display->setText(operand);

}

void MainWindow::on_btnPeriod_clicked()
{
    if(!operand.contains("."))
        operand += qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(operand);
}


void MainWindow::on_btnDel_clicked()
{
    operand = operand.left(operand.length()-1);
    ui->display->setText(operand);
}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();       // 清空当前输入
    operands.clear();      // 清空操作数栈
    opcodes.clear();       // 清空运算符栈
    opcode.clear();        // 清空当前运算符
    ui->display->setText("");
}

void MainWindow::btnBinaryOperatorClicked()
{
    // 1. 获取当前点击的运算符（+、-、*、/），赋值给opcode
    opcode = qobject_cast<QPushButton*>(sender())->text();
    ui->statusbar->showMessage("当前操作数: " + operand);

    if (operand != "") {
        // 2. 压入当前操作数到栈
        operands.push(operand);  // 使用QStack的push()
        operand.clear();
    }

    // 3. 若已有足够的操作数和运算符（至少2个操作数+1个运算符），先计算前一次结果
    if (operands.size() >= 2 && !opcodes.isEmpty()) {
        bool ok;
        QString result = calculation(&ok);
        if (ok) {
            // 计算后，清空操作数栈，将结果作为新操作数压入
            operands.clear();
            operands.push(result);
            ui->display->setText(result);  // 显示x+y的结果
        }
    }

    // 4. 压入当前运算符（无论是否计算，记录新的运算符）
    opcodes.push(opcode);
}

void MainWindow::btnUnaryOperatorClicked()
{
    if (operand != "") {
        double result = operand.toDouble();
        operand.clear();

        QString op = qobject_cast<QPushButton*>(sender())->text();

        if(op == "±") {  // 新增正负号处理逻辑
            result = -result;  // 对当前数字取反
        } else if(op == "%") {
            result /= 100.0;
        } else if (op == "1/x") {
            result = 1/result;
        } else if (op == "x^2") {
            result *= result;
        } else if (op == "√") {
            result = sqrt(result);
        }

        ui->display->setText(QString::number(result));
        operand = ui->display->text();  // 更新 operand 存储取反后的值，支持后续操作
    }
}

void MainWindow::on_btnEqual_clicked()
{
    if (operand != "") {
        operands.push(operand);  // 压入最后一个操作数
        operand.clear();
    }

    // 计算最终结果
    bool ok = false;
    QString result = calculation(&ok);
    if (ok) {
        ui->display->setText(result);
        // 保留结果作为下一次计算的初始操作数（可选，如计算器的连续计算功能）
        operands.clear();
        operands.push(result);
    } else {
        ui->display->setText("错误");
    }
    opcodes.clear();  // 清空运算符栈，避免影响下一次计算
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey , digitBTNs.keys()){
        if(event->key() == btnKey){
            digitBTNs[btnKey]->animateClick();
            return;
        }
    }

    // 新增加减乘除键盘映射
    switch (event->key()) {
    case Qt::Key_Plus:      // 键盘 "+" 键
        ui->btnPlus->animateClick();
        break;
    case Qt::Key_Minus:     // 键盘 "-" 键
        ui->btnMinus->animateClick();
        break;
    case Qt::Key_Asterisk:  // 键盘 "*" 键（数字键区）
        ui->btnMultiple->animateClick();
        break;
    case Qt::Key_Slash:     // 键盘 "/" 键（数字键区）
        ui->btnDivide->animateClick();
        break;
    case Qt::Key_Enter:     // 键盘 Enter 键（补充：映射等于号）
    case Qt::Key_Return:    // 键盘 Return 键（补充：映射等于号）
        ui->btnEqual->animateClick();
        break;
    default:
        // 其他按键不处理
        break;
    }
}
