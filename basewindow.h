﻿#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include "mytitlebar.h"

class BaseWindow : public QWidget
{
  Q_OBJECT
public:
  explicit BaseWindow(QWidget *parent = 0);
  ~BaseWindow();
private :
  void initTitleBar();
  void paintEvent(QPaintEvent *event);
  void loadStyleSheet(const QString &sheetName);

private slots:
  void onButtonMinClicked();
  void onButtonRestoreClicked();
  void onButtonMaxClicked();
  void onButtonCloseClicked();


protected:
        mytitlebar* m_titleBar;

};

#endif // BASEWINDOW_H
