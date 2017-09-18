##<center>QColor</center>
QColor QColor::darker(int factor = 200) const
&emsp;&emsp;如果factor大于100，返回一个更深的颜色，但不改变颜色对象。低于100为更浅的颜色，但提倡使用lighter()函数。

QColor QColor::lighter(int factor = 150) const
&emsp;&emsp;如果factor大于100，返回一个更浅的颜色，但不改变颜色对象。低于100为更深的颜色，但提倡使用darker()函数。

##<center>QPalette<center>

&emsp;&emsp;QPalette类相当于对话框或控件的调色板，它管理着控件或窗体的所有颜色信息，每个窗体或控件都包含一个QPalette对象，在显示时按照它的QPalette对象中对各部分各状态下的颜色的描述来进行绘制。

QPalette类有两个基本的概念，一个是ColorGroup，另一个是ColorRole。
```
void QPalette::setColor ( ColorRole role, const QColor & color );
void QPalette::setColor ( ColorGroup group, ColorRole role, const QColor & color );
void QPalette::setBrush ( ColorRole role, const QBrush & brush );
void QPalette::setBrush ( ColorGroup group, ColorRole role, const QBrush & brush );
```

```
ColorGroup：
QPalette::Disabled 	不可用状态
QPalette::Active 	活跃状态（获得焦点）
QPalette::Inactive 	不活跃状态（未获得焦点）

ColorRole：
QPalette::Window 	一个常规的背景颜色
QPalette::Background 	这个值是废弃的，使用window代替
QPalette::WindowText 	一个一般的前景颜色
QPalette::Foreground 	这个值是废弃的，使用windowText代替.
QPalette::Base 	最长使用来作为text背景颜色为整个widget，但是也能被用来为其他的绘画，像combobox的上下清单的背景和工具栏句柄。它通常是白的或者其他亮的颜色.
QPalette::AlternateBase 	被用来作为轮流的背景颜色，轮流的行颜色
QPalette::ToolTipBase 	被用来作为背景颜色为QToolTip和QWhatsThis。工具尖端使用QPalette不活跃的颜色组，因为工具尖端不是活跃的窗口.
QPalette::ToolTipText 	被用来作为前景颜色为QToolTip和QWhatsThis.工具尖端使用QPalette不活跃的颜色组，因为工具尖端不是活跃的窗口.
QPalette::Text 	前景颜色使用base.这通常和windowText相同，它一定提供好的对比window和base
QPalette::Button 	button背景颜色。这个背景颜色能是不同于window作为一些风格，要求一个不同的背景颜色作为button
QPalette::ButtonText 	一个前景颜色被用来作为button颜色.
QPalette::BrightText 	一个text颜色是很不同于windowText，很好的对比与dark。典型的被用来为text，需要被画，在text或者windowText将给差的对比，就像在按下的button。注意text颜色能被用来为事情，而不只是单词；text颜色通常被用来为text，但是他是相当普通的使用text颜色角色为行，图标，等等。
```
另外，在设置对话框和控件的背景色时还会用到：

`void setAutoFillBackground ( bool enabled )；`