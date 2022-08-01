# STC8G-Nano
硬件在稍作改动，稍后上传。
后面的原理图PCB图以文件当中的为准。
亚克力外壳在稍作改动，稍后上传。
设计初衷是为了方便自己调试项目用，板子外形仿照了稚晖君的ESP32-PicoDK进行设计。

[开源地址](https://github.com/zhou-qi-98/STC8G-Nano)

> 采用增强型51，比传统52快12倍：
>
> * 采用STC8G1K17芯片，功能非常强大
> * 集成了一个0.78寸的OLED
> * 自带5050幻彩灯 RGB灯
> * 两路UART
> * ............

市面上的51最小系统居然TYPE-C都没有，所以板子上直接用TYPE-C

**板子设计已打样验证无误，好用记得点星星**👇
![实物图](http://youpai.7yunkj.com/halo/5a16aa32cfe035fd4d4df7722abe47b0.jpg)

##  特性

* 引出P1口，P3口。
* 板载一个一个OLED、一个白色LED、一个USB转串口、一个幻彩5050灯（RGB）、两个中断按键
* 上面提到的外设都是可以在板子背面通过**跳线**选择连接GPIO或者断开的，所以不影响GPIO作其他用途
* 极致迷你尺寸
* 带配套亚克力外壳（设计中稍后更新）
![PCB](http://youpai.7yunkj.com/halo/46d77ebb4648a06024f5cb7f8b340af1.png)
![PCB_TOP](http://youpai.7yunkj.com/halo/672f9b23a542473d35d95639cc0442fd.png)
![PCB_BON](http://youpai.7yunkj.com/halo/45ccf15b58ace03be407623a667538fd.png)
![002](http://youpai.7yunkj.com/halo/1d46c8b9aa7e4a8fe7b81443fe075bc9.png)
![SCH](http://youpai.7yunkj.com/halo/c3d9e4610b7c2d5b8e1a818ed093d86e.png)
