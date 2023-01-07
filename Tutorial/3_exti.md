# EXTI

#### 学习内容（待完善）
1. 认识中断
2. 了解中断分类，中断优先级
3. 认识中断函数，中断回调函数
4. 认识GPIO外部中断（分类，分组）
5. 配置CubeMX
6. 看看stm32f1xx_it.c，了解外部中断服务函数，学会重写回调函数，完成实验
#### 推荐教程

- [视频教程]((https://www.bilibili.com/video/BV1Sy4y1y7B1?p=4&spm_id_from=pageDriver&vd_source=baa784078e67e28c38d26cf6881f8357))（配套资料在群里）
- [谢阳学长的教程](https://github.com/MirTITH/WTR-EC-Training/blob/main/%E4%B8%AD%E6%96%AD%E5%92%8Cfreertos/%E4%B8%AD%E6%96%AD%E5%92%8Cfreertos.md)
- [中断、事件中断事件理解](https://blog.csdn.net/xkf321/article/details/53088834)
- [外部中断文章](https://blog.csdn.net/liu6780/article/details/124633067)
- [外部中断文章](https://blog.csdn.net/zxh1592000/article/details/80280715)
- [CubeMX EXTI教程](https://blog.csdn.net/weixin_43892323/article/details/104383560)
- WTR培训讲义-串口（群文件有）

#### 小任务
- 尝试实现利用按键切换指示灯闪烁的模式，注意按键消抖
- 如果不在学校没有按键，可以用杜邦线插拔模拟按键，尝试检测一次插拔操作会触发多少次中断
- 进阶（待完善） : 了解编码器有关知识，读取编码器转的圈数
