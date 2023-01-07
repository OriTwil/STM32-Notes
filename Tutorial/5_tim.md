# TIM

#### 学习内容
- 了解定时器（种类、作用、模式、工作原理）
- 定时器计数器模式与定时器中断
- 定时器PWM模式
- 定时器输入捕获
- CubeMX配置与HAL库函数的使用
- 直流电机闭环控制与多闭环控制结构
#### 推荐学习资料
- [谢阳学长整理的资料](https://github.com/MirTITH/WTR-EC-Training/blob/main/05-timer%26bldc/%EF%BC%88%E9%A2%84%E4%B9%A0%EF%BC%8905-timer%26bldcm.md)
- [文章](https://www.iotword.com/7855.html)
- [视频](https://www.bilibili.com/video/BV1Sy4y1y7B1/?p=6&spm_id_from=pageDriver&vd_source=baa784078e67e28c38d26cf6881f8357)
- WTR2021夏季STM32培训03-定时器

#### 小任务
- 尝试利用定时器中断实现灯以1s频率闪烁
- 利用定时器中断计算编码器速度
- 利用定时器产生指定个数的脉冲，并利用输入捕获测量脉冲宽度
- 利用定时器产生PWM波，并利用输入捕获测量频率与占空比
- 输出PWM波驱动无源蜂鸣器（不同频率）、实现呼吸灯
- 进阶任务：利用编码器实现直流电机的闭环控制