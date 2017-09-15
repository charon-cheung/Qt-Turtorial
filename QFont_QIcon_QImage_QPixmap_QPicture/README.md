##<center>QPixmap 类代表图像，实现在 QtGui 共享库中。</center>

    QPixmap();     // 构造一个大小为 0 的空图像  

    以下构造函数生成大小的 QPixmap 对象，但图像数据未初始化：
```
    QPixmap(const QSize &size);     // 构造大小为 size 的图像，图像数据未初始化  
    QPixmap(int width, int height);    // 等价于 QPixmap(QSize(width, height));  
```

    以下构造函数能够从指定的文件中加载图像并生成 QPixmap 对象：
```
    QPixmap(const QString &filename, const char *format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor);  
```

      其各个参数的含义解释如下。

      1) filename： 文件名。

      2) format： 字符串，表示图像文件的格式，如果为 0，将进行自动识别。

      3) flags：表示颜色的转换模式。


       如果图像文件加载失败则产生空图像，这里 flags 参数有以下取值。
```
       1) Qt::AutoColor：由系统自动决定。

       2) Qt::ColorOnly：彩色模式。

       3) Qt::MonoOnly：单色模式。
```
       以下成员函数可以获得 QPixmap 对象所表示的图像的相关信息：
```
    int depth() const;     // 颜色深度，既每像素所占的比特数  
    int width() const;     // 图像宽度，单位是像素  
    int height() const;   // 图像高度，单位是像素  
    QSize size() cosnt;  // 图像的大小，即 QSize(width(), height());  
    QRect rect() const;   // 图像的矩形区域，即 QRect(QPoint(0,0),size());  
```
    用下面的成员函数可以从文件加载图像：
```
    bool load(const QString &filename, const char *fornat = 0, Qt::ImageCoversionFlags flags = Qt::AutoColor);  
```
    这里各个参数的含义与构造函数中一样，返回值为 true 表示加载成功，false 表示加载失败。

    相反的操作是将 Qpixmap 代表的图像保存到文件，可用以下成员函数：
```
    bool save(const QString &filename, const char *format = 0, int quality = -1) const;  
```
       其各个参数及返回值的含义解释如下。

       1) filename：文件名。

       2) format：字符串，表示图像文件的格式，如果为0，将根据文件名的后缀自动确定文件格式。

       3) quality：对于有损压缩的文件格式来说，它表示图像保存的质量，质量越低压缩率越大。取值范围为 0～100，-1 表示采用默认值。

       4) 返回值：true 表示保存成功，false 表示保存失败。


    以下成员函数可以判断 QPixmap 对象是否为空图像：
```
    bool isNull() const;     // 判断是否为空图像  
```