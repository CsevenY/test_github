#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "loginview.h"
#include "doctorview.h"
#include "departmentview.h"
#include "patienteditview.h"
#include "patientview.h"
#include "welcomeview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientEditView(int rowNo);
    void goPatientView();
    void goPreviousView();

private slots:
    void on_btback_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogout_clicked();

private:
    void pushWidgetTostackView(QWidget *widget);

    Ui::Widget *ui;

    WelcomeView *welcomeView;
    DoctorView *doctorView;
    PatientEditView *patientEditView;
    PatientView *patientView;
    DepartmentView *departmentView;
    LoginView *loginView;
};
#endif // WIDGET_H
