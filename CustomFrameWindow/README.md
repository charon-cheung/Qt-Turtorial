## 自定义窗口
#### 改变最大化、最小化、还原、关闭等四个按钮，其他功能不变

![预览](https://raw.githubusercontent.com/rjosodtssp/Qt-Turtorial/master/CustomFrameWindow/app.png)

本以为很简单，但想做好并不太容易。Dialog可以按此程序修改。

左上角不得不保留一个sizegrip，否则不能放缩

To-dos:
将窗口最大化，然后点击鼠标拖动标题栏，窗口恢复为普通大小。
这个过程发生的QEvent顺序：
```
NoClientAreaMouseButtonPress
Resize
Paint
Move
WindowStateChange
LayoutRequest
```
恢复普通大小后，鼠标的纵坐标不变，假设横坐标x映射到窗口坐标x_，x与显示器宽度比例为ratio, 那么x_与窗口宽度的比例应当也是ratio。

但鼠标点击修改后的标题栏第一个发生的事件为MousePressEvent。