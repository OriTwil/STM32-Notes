# USART

#### 内容
- 了解串口通讯基本概念（usart物理层、协议层，波特率、校验位等概念）
- 利用串口收发数据(了解工作原理，CubeMX、Hal库函数使用)
- 串口中断与DMA
- 串口调试助手 vofa+
- uart_printf重定向

#### 推荐教程
- [谢阳学长整理的资料](https://github.com/MirTITH/WTR-EC-Training/blob/main/04-%E4%B8%B2%E5%8F%A3/%E4%B8%B2%E5%8F%A3.md)
- WTR培训讲义-串口
- [视频教程](https://www.bilibili.com/video/BV1Sy4y1y7B1?p=5&spm_id_from=pageDriver&vd_source=baa784078e67e28c38d26cf6881f8357)（附带资料在群文件）
  
#### 小任务
- （如果不在学校没有，先试试简单版的，只需要开发板STM32F103C8T6、STLINK、杜邦线即可）将串口Tx与Rx短接，自己发送消息，自己接收，可以尝试统计中断次数，或者在接收中断中对消息进行一定处理
- 如果在学校，可以用串口调试助手，串口转ttl，实现单片机和电脑的数据传输，利用空闲终端＋DMA实现不定长数据传输
- 进阶版（待完善） : 学会用艾克申的码盘。通过阅读手册，在回调函数中对数据进行解码
- 进阶版（待完善） ： 学会用AS69模块和大疆遥控器（用`DMA`），尝试根据手册编写解码函数，读取遥控器数据。[AS69手册](https://max.book118.com/html/2021/0629/8050124000003115.shtm)