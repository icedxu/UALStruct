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
  //setFixedSize(315,300);

  loadStyleSheet("MyTitle");


  // 初始化标题栏;
  initTitleBar();
  //SetRect(); //设置窗体圆角
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
  int a = m_pTextColorR->text().toInt(&ok,10),
      b = m_pTextColorG->text().toInt(&ok,10),
      c = m_pTextColorB->text().toInt(&ok,10);  //将QString类型转换为int类型

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
  m_pBtnColor = new QPushButton(QStringLiteral("换标题栏的颜色"));
  m_pTextColorR =new QLineEdit;m_pTextColorR->setPlaceholderText("R");m_pTextColorR->setFixedWidth(25);
  m_pTextColorG =new QLineEdit;m_pTextColorG->setPlaceholderText("G");m_pTextColorG->setFixedWidth(25);
  m_pTextColorB =new QLineEdit;m_pTextColorB->setPlaceholderText("B");m_pTextColorB->setFixedWidth(25);
  m_pColorLayout = new QHBoxLayout;
  m_pColorLayout->setSpacing(0); //使hb中的控件间的间距为0
  m_pColorLayout->addWidget(m_pTextColorR);
  m_pColorLayout->addWidget(m_pTextColorG);
  m_pColorLayout->addWidget(m_pTextColorB);
  m_pColorLayout->addWidget(m_pBtnColor);
  m_pColorLayout->addStretch();//靠左对齐



//高度
  int nMin = 0;
  int nMax = 100;
  int nSingleStep = 5;
  // 微调框
  m_pSpinBox = new QSpinBox(this);
  m_pSpinBox->setFixedWidth(40);
  m_pSpinBox->setMinimum(nMin);  // 最小值
  m_pSpinBox->setMaximum(nMax);  // 最大值
  m_pSpinBox->setSingleStep(nSingleStep);  // 步长
  m_pSpinBox->setValue(10); //默认值为10

  // 滑动条
  QSlider *pSlider = new QSlider(this);
  pSlider->setFixedWidth(50);
  pSlider->setOrientation(Qt::Horizontal);  // 水平方向
  pSlider->setMinimum(nMin);  // 最小值
  pSlider->setMaximum(nMax);  // 最大值
  pSlider->setSingleStep(nSingleStep);  // 步长




  m_pBtnHeight = new QPushButton(QStringLiteral("换标题栏的高度"));
  m_pSliderLayout = new QHBoxLayout;
  m_pSliderLayout->addWidget(m_pSpinBox);
  m_pSliderLayout->addWidget(pSlider);
  m_pSliderLayout->addWidget(m_pBtnHeight);
  m_pSliderLayout->addStretch();//靠左对齐
  m_pSliderLayout->setSpacing(0); //使hb中的控件间的间距为0


//文字

  m_pBtnText = new QPushButton(QStringLiteral("换标题栏的文字"));
  m_pText = new QLineEdit;
  m_pTextLayout = new QHBoxLayout;
  m_pTextLayout->addWidget(m_pText);
  m_pTextLayout->addWidget(m_pBtnText);
  m_pTextLayout->addStretch();//靠左对齐
  m_pTextLayout->setSpacing(0); //使hb中的控件间的间距为0



 //图标
  m_pIco = new QLineEdit;
  m_pBtnIco = new QPushButton(QStringLiteral("换标题栏的图标"));
  m_pIcoLayout = new QHBoxLayout;
  m_pIcoLayout->addWidget(m_pIco);
  m_pIcoLayout->addWidget(m_pBtnIco);
  m_pIcoLayout->addStretch();//靠左对齐
  m_pIcoLayout->setSpacing(0); //使hb中的控件间的间距为0


  QVBoxLayout *pvbLayout = new QVBoxLayout;
  pvbLayout->addStretch();
  pvbLayout->addLayout(m_pColorLayout);
  pvbLayout->addLayout(m_pSliderLayout);
  pvbLayout->addLayout(m_pTextLayout);
  pvbLayout->addLayout(m_pIcoLayout);
  pvbLayout->addStretch();



  m_pBtnColor->setObjectName("ButtonColor");
  m_pTextColorR->setObjectName("LineEdit");
  m_pTextColorG->setObjectName("LineEdit");
  m_pTextColorB->setObjectName("LineEdit");

  m_pBtnHeight->setObjectName("ButtonHeight");
  m_pBtnText->setObjectName("ButtonColor");
  m_pBtnIco->setObjectName("ButtonHeight");

  m_pIco->setObjectName("LineEdit");
  m_pText->setObjectName("LineEdit");

  this->setLayout(pvbLayout);

  // 连接信号槽（相互改变）
  connect(m_pSpinBox, SIGNAL(valueChanged(int)), pSlider, SLOT(setValue(int)));
  connect(pSlider, SIGNAL(valueChanged(int)), m_pSpinBox, SLOT(setValue(int)));

  connect(m_pBtnColor,SIGNAL(clicked()),this,SLOT(SetColor()));
  connect(m_pBtnText,SIGNAL(clicked()),this,SLOT(SetText()));
  connect(m_pBtnHeight,SIGNAL(clicked()),this,SLOT(SetHeight()));
  connect(m_pBtnIco,SIGNAL(clicked()),this,SLOT(SetIco()));




}

void succ::SetText()
{
  QString str;
  str = m_pText->text();
  m_titleBar->setTitleContent(str);
}


void succ::SetIco()
{
  //getOpenFileName()的参数，1--指定父组件，2--指定对话框标题，3--对话框显示时的默认打开目录，4--对话框显示的文件类型（只显示指定后缀名的）
    QString filePath= QFileDialog::getOpenFileName(this,tr("选择文件"),"","");
    m_pIco->setText(filePath);

    //以下操作是为了保存文件名与文件后缀名
   QStringList  pathList1 = filePath.split("/");
   QString  stringPath=pathList1[pathList1.size()-1];
   QStringList  pathList2 = stringPath.split(".");

   //为了保存文件名
   QString p1=pathList2.at(0);



}


void succ::SetHeight()
{
  int a = m_pSpinBox->value();
  m_titleBar->setFixedHeight(a);
}


void succ::initTitleBar()
{

     // 设置标题栏跑马灯效果，可以不设置;
	m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon("://Resources/MyTitle/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("这是一个Qt自定义窗口的例子"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
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
