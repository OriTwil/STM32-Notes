# GPIO

#### 学习内容
- GPIO 基本结构
- GPIO 8种模式
- GPIO 在CubeMX中的配置
- HAL库中 GPIO 常用函数
- 完成小任务
#### 教程推荐
- [谢阳学长推荐的教程](https://www.cnblogs.com/dongxiaodong/p/14128088.html)
- [关于GPIO的文章](https://blog.csdn.net/liu6780/article/details/124424825)（推荐）
- [视频理解GPIO的四种输出模式](https://www.bilibili.com/video/BV1Pr4y1n74J/?p=1&share_medium=android_hd&share_plat=android&share_session_id=30ff529e-8c30-4f3c-a328-b8938fbfe5aa&share_source=COPY&share_tag=s_i&timestamp=1651040730&unique_k=AULWUFK)（感兴趣看看，看不懂没关系，需要一点点模电知识）
- [视频教程](https://www.bilibili.com/video/BV1Sy4y1y7B1?p=3&spm_id_from=pageDriver&vd_source=baa784078e67e28c38d26cf6881f8357) （配套资料发到群里了）
-  [实验教程](https://blog.csdn.net/qq_38191568/article/details/126021237)
- [HAL库常用函数](https://blog.csdn.net/llq_the7/article/details/108235951#:~:text=HAL_GPIO_LockPin%20%2F%2F%20%E5%A6%82%E6%9E%9C%E4%B8%80%E4%B8%AA%E7%AE%A1%E8%84%9A%E7%9A%84%E5%BD%93%E5%89%8D%E7%8A%B6%E6%80%81%E6%98%AF1%EF%BC%8C%E8%AF%BB%E7%AE%A1%E8%84%9A%E5%80%BC%E4%BD%BF%E7%94%A8%E9%94%81%E5%AE%9A%EF%BC%8C%E5%BD%93%E8%BF%99%E4%B8%AA%E7%AE%A1%E8%84%9A%E7%94%B5%E5%B9%B3%E5%8F%98%E5%8C%96%E6%97%B6%E4%BF%9D%E6%8C%81%E9%94%81%E5%AE%9A%E6%97%B6%E7%9A%84%E5%80%BC%EF%BC%8C%E7%9B%B4%E5%88%B0%E9%87%8D%E7%BD%AE%E6%89%8D%E6%94%B9%E5%8F%98%20HAL_StatusTypeDef,HAL_GPIO_LockPin%20%28GPIO_TypeDef%2A%20GPIOx%2C%20uint16_t%20GPIO_Pin%29)（Note中也有总结）

#### TIPS
- (实验和视频所用开发板等不同，所以不要完全按照视频做，比如视频用的JLink,我们做实验可能用的STLink，CubeMX中Debug那一项就不同。**重点在于知道每一步在干什么**)
- 如果暂时看不太懂GPIO电路结构也问题不大，先理解GPIO的8种模式，动手配置cubeMX，熟悉HAL库常用函数就行，把实验做出来
- 教程中部分原理性的东西可能暂时不能理解，随着实验进行，后续的使用学习，学校模电等课程也学完了，会更深入地了解
- 完成实验后，可以经常翻翻文档讲义
- 任务比较简单，主要工作在于开发环境的配置
- 实验过程中不清楚的地方，如CubeMX中一些配置项的意思，都可以在群里交流
#### 小任务（点灯）
- 熟悉CubeMX配置项和HAL库常用函数就行
- 基础任务1：例如可以用杜邦线的插拔代替按键，一端连到3.3V,另一端连到GPIO对应引脚。实现插到不同的引脚，灯以不同的模式闪烁
  > PB9 灯亮
  > PB8 灯灭
  > PB7 灯以一定频率快速闪烁‘
  > PB6 灯锁定在当前状态
  > 不插时，灯以较慢频率闪烁
- 基础任务2：使用GPIO高低电平驱动有源蜂鸣器
- 进阶任务 ：
