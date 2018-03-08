#include "succ.h"
#include "ui_succ.h"
#include <QIcon>
#include <QMessageBox>
#include <QDebug>
#include <QBitmap>
#include <QPainter>



succ::succ(QWidget *parent) :
  BaseWindow(parent),
  ui(new Ui::succ)
{
  ui->setupUi(this);
  setFixedSize(315,300);

  loadStyleSheet("MyTitle");


  // 初始化标题栏;
  initTitleBar();
  SetRect(); //设置窗体圆角
  Interface();


}

succ::~succ()
{

}

//设置窗体圆角
void succ::SetRect()
{

  QBitmap bmp(this->size());
  bmp.fill();
  QPainter p(&bmp);
  p.setPen(Qt::NoPen);
  p.setBrush(Qt::black);
  p.drawRoundedRect(bmp.rect(),10,10);
  setMask(bmp);

}

//改变窗体标题颜色
void succ::SetColor()
{
  bool ok;
  int a = color_text1->text().toInt(&ok,10),
      b = color_text2->text().toInt(&ok,10),
      c = color_text3->text().toInt(&ok,10);  //将QString类型转换为int类型

  if(a<0 ||a>255|| b<0 ||b>255|| c<0 ||c>255)
     {
       QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("输入格式不对"));
       return ;
     }

  m_titleBar->setBackgroundColor(a,b,c);

}





void succ::Interface()
{
//颜色
  color_btn = new QPushButton(QStringLiteral("换标题栏的颜色"));
  color_text1 =new QLineEdit;color_text1->setPlaceholderText("R");color_text1->setFixedWidth(25);
  color_text2 =new QLineEdit;color_text2->setPlaceholderText("G");color_text2->setFixedWidth(25);
  color_text3 =new QLineEdit;color_text3->setPlaceholderText("B");color_text3->setFixedWidth(25);
  hb = new QHBoxLayout;
  hb->setSpacing(0); //使hb中的控件间的间距为0
  hb->addWidget(color_text1);
  hb->addWidget(color_text2);
  hb->addWidget(color_text3);
  hb->addWidget(color_btn);
  hb->addStretch();//靠左对齐



//高度
  int nMin = 0;
  int nMax = 100;
  int nSingleStep = 5;
  // 微调框
  pSpinBox = new QSpinBox(this);
  pSpinBox->setFixedWidth(40);
  pSpinBox->setMinimum(nMin);  // 最小值
  pSpinBox->setMaximum(nMax);  // 最大值
  pSpinBox->setSingleStep(nSingleStep);  // 步长
  pSpinBox->setValue(10); //默认值为10

  // 滑动条
  QSlider *pSlider = new QSlider(this);
  pSlider->setFixedWidth(50);
  pSlider->setOrientation(Qt::Horizontal);  // 水平方向
  pSlider->setMinimum(nMin);  // 最小值
  pSlider->setMaximum(nMax);  // 最大值
  pSlider->setSingleStep(nSingleStep);  // 步长




  btn_h = new QPushButton(QStringLiteral("换标题栏的高度"));
  hb1 = new QHBoxLayout;
  hb1->addWidget(pSpinBox);
  hb1->addWidget(pSlider);
  hb1->addWidget(btn_h);
  hb1->addStretch();//靠左对齐
  hb1->setSpacing(0); //使hb中的控件间的间距为0


//文字

  btn_t = new QPushButton(QStringLiteral("换标题栏的文字"));
  T_text = new QLineEdit;
  hb2 = new QHBoxLayout;
  hb2->addWidget(T_text);
  hb2->addWidget(btn_t);
  hb2->addStretch();//靠左对齐
  hb2->setSpacing(0); //使hb中的控件间的间距为0



 //图标
  T_ico = new QLineEdit;
  btn_i = new QPushButton(QStringLiteral("换标题栏的图标(没做)"));
  hb3 = new QHBoxLayout;
  hb3->addWidget(T_ico);
  hb3->addWidget(btn_i);
  hb3->addStretch();//靠左对齐
  hb3->setSpacing(0); //使hb中的控件间的间距为0


  QVBoxLayout *vb = new QVBoxLayout;
  vb->addStretch();
  vb->addLayout(hb);
  vb->addLayout(hb1);
  vb->addLayout(hb2);
  vb->addLayout(hb3);
  vb->addStretch();



  color_btn->setObjectName("ButtonColor");
  color_text1->setObjectName("LineEdit");
  color_text2->setObjectName("LineEdit");
  color_text3->setObjectName("LineEdit");

  btn_h->setObjectName("ButtonHeight");
  btn_t->setObjectName("ButtonColor");
  btn_i->setObjectName("ButtonHeight");

  T_ico->setObjectName("LineEdit");
  T_text->setObjectName("LineEdit");

  this->setLayout(vb);

  // 连接信号槽（相互改变）
  connect(pSpinBox, SIGNAL(valueChanged(int)), pSlider, SLOT(setValue(int)));
  connect(pSlider, SIGNAL(valueChanged(int)), pSpinBox, SLOT(setValue(int)));

  connect(color_btn,SIGNAL(clicked()),this,SLOT(SetColor()));
  connect(btn_t,SIGNAL(clicked()),this,SLOT(SetText()));
  connect(btn_h,SIGNAL(clicked()),this,SLOT(SetHeight()));
  connect(btn_i,SIGNAL(clicked()),this,SLOT(SetIco()));




}

void succ::SetText()
{
  QString str;
  str = T_text->text();
  m_titleBar->setTitleContent(str);
}


void succ::SetIco()
{
  //getOpenFileName()的参数，1--指定父组件，2--指定对话框标题，3--对话框显示时的默认打开目录，4--对话框显示的文件类型（只显示指定后缀名的）
    QString filePath= QFileDialog::getOpenFileName(this,tr("选择文件"),"","");
    T_ico->setText(filePath);

    //以下操作是为了保存文件名与文件后缀名
   QStringList  pathList1 = filePath.split("/");
   QString  stringPath=pathList1[pathList1.size()-1];
   QStringList  pathList2 = stringPath.split(".");

   //为了保存文件名
   QString p1=pathList2.at(0);



}


void succ::SetHeight()
{
  int a = pSpinBox->value();
  m_titleBar->setFixedHeight(a);
}


void succ::initTitleBar()
{

     // 设置标题栏跑马灯效果，可以不设置;
	m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon("://Resources/MyTitle/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("这是一个Qt自定义窗口的例子"));
	m_titleBar->setButtonType(MIN_BUTTON);
	m_titleBar->setTitleWidth(this->width());


}


void succ::loadStyleSheet(const QString &sheetName)
{
	QFile file(":/Resources/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}
