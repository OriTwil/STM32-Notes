# GPIO
```c
/**
* @：GPIO初始化
* @：HAL_GPIO_Init(GPIOA, GPIO_PIN_9)
*/
HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
/**
* @：GPIO反初始化
* @：HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9)
*/
HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)    
/**
* @：GPIO引脚读取
* @：HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)
* @：GPIO_PinState 返回值类型/0或1
* typedef enum
    {
        GPIO_PIN_RESET = 0U,
        GPIO_PIN_SET
    }GPIO_PinState;
*/
GPIO_PinState 
HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
/**
* @：GPIO写状态
* @：HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET)
* @:第二个参数：GPIO_PIN_RESET/GPIO_PIN_SET
*/
void 
HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
/**
* @：GPIO电平反转
* @：HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_9)
*/
void 
HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
/**
* @：GPIO电平状态锁定
* @：HAL_GPIO_LockPin(GPIOF,GPIO_PIN_9)
* @:typedef enum 
    {
        HAL_OK       = 0x00U,
        HAL_ERROR    = 0x01U,
        HAL_BUSY     = 0x02U,
        HAL_TIMEOUT  = 0x03U
    } HAL_StatusTypeDef
*/
HAL_StatusTypeDef 
HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
/**
* @：GPIO外部中断服务函数
* @：HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9)
*/
void 
HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin)
/**
* @：GPIO中断回调函数，用于写逻辑
* @：HAL_GPIO_EXTI_Callback(GPIO_PIN_9)
* 	{
* 		if(GPIO_Pin==GPIO_PIN_9) /判断哪个引脚/
* 	}
*/
__weak void 
HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)            
```
# USART
```c
/**
  * @brief  串口初始化(还有好几个初始化模式，一般用不到)
  * @param  句柄，（哪个串口）
  * @retval 0-ok,1-error,2-busy,3-timeout(上面写的有)
  * @eg:	HAL_UART_Init(&huart1);
  */
HAL_StatusTypeDef 
HAL_UART_Init(UART_HandleTypeDef *huart)
/**
  * @brief  反串口初始化
  * @param  句柄，（哪个串口）
  * @retval 0-ok,1-error,2-busy,3-timeout(上面写的有)
  * @eg:	HAL_UART_DeInit(&huart1);
  */
HAL_StatusTypeDef
HAL_UART_DeInit(UART_HandleTypeDef*huart);
/**
  * @brief  串口发送
  * @param  句柄，要发送的数据，数据大小，超时时间
  * @retval 0-ok,1-error,2-busy,3-timeout(上面写的有)
  * @eg:	HAL_UART_Transmit(&huart2, (uint8_t *)"helloworld", 10, 0xFFFF);
  */
HAL_StatusTypeDef
HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
/**
  * @brief  串口接收
  * @param  句柄，要保存接收数据的指针/数组，接收数据大小，超时时间
  * @retval 0-ok,1-error,2-busy,3-timeout(上面写的有)
  * @eg:	HAL_UART_Receive(&huart2, databuf, 10, 0xFFFF);
  */
HAL_StatusTypeDef
HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
/**
  * @brief  中断模式发送
  * @param  huart：句柄
  * @param  pData:要发送的指针或数组
  * @param  Size: 要发送的数据量
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/**
  * @brief  中断模式接收
  * @param  huart：句柄
  * @param  pData:要保存接收数据的指针或数组
  * @param  Size: 要接收的数据量
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/**
  * @brief  DMA模式发送
  * @param  huart：句柄
  * @param  pData:要发送的指针或数组
  * @param  Size: 要发送的数据量
  * @retval HAL status
  * @eg	    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)Senbuff, sizeof(Senbuff));  //串口发送Senbuff数组
  */
HAL_StatusTypeDef 
HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/**
  * @brief  DMA模式接收
  * @param  huart：句柄
  * @param  pData:要保存接收数据的指针或数组
  * @param  Size: 要接收的数据量
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/**
  * @brief 	暂停DMA发送
  * @param  huart:句柄 
  * @retval HAL status
  */
HAL_StatusTypeDef
HAL_UART_DMAPause(UART_HandleTypeDef *huart);
/**
  * @brief 	恢复DMA发送
  * @param  huart:句柄 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_UART_DMAResume(UART_HandleTypeDef *huart);
/**
  * @brief 	停止DMA发送
  * @param  huart:句柄 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_UART_DMAStop(UART_HandleTypeDef *huart);
/**
  * @brief 	几个不常用的终止正在进行的传输
  * @param  huart:句柄 
  * @retval HAL status
  */
//阻塞模式
HAL_StatusTypeDef 
HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
//中断模式
HAL_StatusTypeDef 
HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);
/**
  * @brief  处理中断请求
  * @param  huart: &huart1
  * @retval None
  */
void 
HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
/**
  * @brief  发送回调函数
  * @param  huart: &huart1
  * @retval None
  */
 __weak void 
HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
 /**
  * @brief  接收回调函数
  * @param  huart: &huart1
  * @retval None
  */
 __weak void 
HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
 /**
  * @brief  串口返回状态
  * @param  huart: &huart1
  * @retval None
  */
HAL_UART_StateTypeDef 
HAL_UART_GetState(UART_HandleTypeDef *huart);

```

# TIM
```c
		/" ##### Time Base functions ##### "/
		/" ####### 定时器基础功能 ######### "/
/**
  * @brief  初始化定时器
  * @param  htim : &htim1
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
/**
  * @brief  取消初始化定时器
  * @param  htim : &htim1
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);
/**
  * @brief  启动定时器
  * @param  htim : &htim1
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_Base_Start(TIM_HandleTypeDef *htim);
/**
  * @brief  停止定时器
  * @param  htim : &htim1
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim);
/**
  * @brief  中断模式下启动定时器
  * @param  htim : &htim1
  * @retval HAL status
  */  
HAL_StatusTypeDef 
HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
/**
  * @brief  中断模式下停止定时器
  * @param  htim : &htim1
  * @retval HAL status
  */
 HAL_StatusTypeDef 
 HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);
/**
  * @brief  DMA模式下启动定时器
  * @param  htim : &htim1
  * @param  pdata:原缓冲区地址
  * @param	从内存传输到外设的数据长度
  * @retval HAL status
  */  
HAL_StatusTypeDef 
HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
/**
  * @brief  DMA模式下停止定时器
  * @param  htim : &htim1
  * @retval HAL status
  */
HAL_StatusTypeDef
HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim);


```
# PWM
```c
  ==========================================================     
         ##### Time PWM functions #####
  ==========================================================
"配置通道"
HAL_StatusTypeDef
HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef* sConfig, uint32_t Channel)

/**
  * @brief PWM初始化
  * @param 句柄
  * @retval HAL_StatusTypeDef HAL状体，错误，ok,超时
  */
HAL_StatusTypeDef 
HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_TIM_PWM_Init(&htim12);
/**
  * @brief  取消初始化
  * @param  htim : TIM handle
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);
HAL_TIM_PWM_DeInit(&htim12);
/**
  * @brief  启动PWM信号.
  * @param  htim : TIM handle
  * @param  Channel : 要用的通道
  *          	可以是1 -- 4
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
*/
HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel) ;
HAL_TIM_PWM_Start(&htim13, TIM_CHANNEL_1);
/**
  *"关闭pwm参数与开启一样"
  */
HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_TIM_PWM_Stop(&htim13, TIM_CHANNEL_1);
/**
  * @brief  中断模式下PWM信号
  * @param  htim : TIM handle
  * @param  Channel :要开启的通道
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
*/
"开启____start"
HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
"关闭___stop"
HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @brief  DMA模式下PWM信号
  * @param  htim : TIM handle
  * @param  Channel : 要开启的通道
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @param  pData : 缓冲区
  * @param  Length :数据长度
  * @retval HAL status
*/
"开启____start"
HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
"关闭_____stop"
HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


"重装ARR寄存器，修改重装值（计数值）"
__HAL_TIM_SET_AUTORELOAD(__HANDLE__, __AUTORELOAD__)//
__HAL_TIM_SET_AUTORELOAD(&htim1, 1000);

"重装CCR寄存器，修改比较值(占空比)"
__HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__);
__HAL_TIM_SET_COMPARE(&htim1, 500); 

"占空比位50%"

```

# ADC
```c
/**
  * @：ADC使能
  * @：ADC_Enable(&hadc1)
  */
ADC_Enable(ADC_HandleTypeDef* hadc);
/**
  * @：ADC开启转换
  * @：HAL_ADC_Start(&hadc1)
  */
HAL_ADC_Start(ADC_HandleTypeDef* hadc);
/**
  * @：ADC关闭转换
  * @：HAL_ADC_Stop(&hadc1)
  */
HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
/**
  * @：带中断的ADC转换开启
  * @：HAL_ADC_Start_IT(&hadc1)
  */
HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
/**
  * @：带中断的ADC转换停止
  * @：HAL_ADC_Stop_IT(&hadc1)
  */
HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc); 
 /**
  * @：DMA方式ADC开启
  * @：HAL_ADC_Start_DMA(&hadc1，Data,5)
  * @:句柄，数据存储数组/指针，长度
  */
HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);	
 /**
  * @：DMA方式ADC关闭
  * @：HAL_ADC_Stop_DMA(&hadc1，Data,5)
  * @:句柄
  */
HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);
 /**
  * @：获取ADC转换值
  * @：HAL_ADC_GetValue(&hadc1)
  */
HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);

```

# DAC
```c
"初始化"
HAL_StatusTypeDef 
HAL_DAC_Init(DAC_HandleTypeDef* hdac)

HAL_StatusTypeDef 
HAL_DAC_DeInit(DAC_HandleTypeDef* hdac)
/**
  * @brief  开启DAC转换通道
  * @param  hdac: 句柄
  * @param  Channel: 2选一
  *            @arg DAC_CHANNEL_1: DAC Channel1 selected
  *            @arg DAC_CHANNEL_2: DAC Channel2 selected
  * @retval HAL status
  */
"START"
HAL_StatusTypeDef 
HAL_DAC_Start(DAC_HandleTypeDef* hdac, uint32_t Channel)
HAL_DAC_Start(&dac1)
"STOP"
HAL_StatusTypeDef 
HAL_DAC_Stop(DAC_HandleTypeDef* hdac, uint32_t Channel)

/**
  * @brief：DMA模式转换开启
  * @param：hdac 句柄 (哪个DAC)
  * @param: Channel	  (哪个通道)
  * @param: 存放数据的指针/数组
  * @param: 存放的数据长度/接收5个单长度，的数据 
  * @param:字节对齐方式，8位有对齐，12位左，12位右
  */
"DMA-DAC-START"
__weak HAL_StatusTypeDef
HAL_DAC_Start_DMA(DAC_HandleTypeDef* hdac, uint32_t Channel, uint32_t* pData, uint32_t Length, uint32_t Alignment)

"DMA-DAC-STOP"
__weak HAL_StatusTypeDef
HAL_DAC_Stop_DMA(DAC_HandleTypeDef* hdac, uint32_t Channel)

"***********""获取值"
uint32_t 
HAL_DAC_GetValue(DAC_HandleTypeDef* hdac, uint32_t Channel)

"回调函数"
__weak void 
HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef* hdac)

"DMA回调函数"
__weak void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef* hdac)

"error回调函数"
__weak void 
HAL_DAC_ErrorCallbackCh1(DAC_HandleTypeDef *hdac)

"DAC设置函数"
HAL_StatusTypeDef 
HAL_DAC_ConfigChannel(DAC_HandleTypeDef* hdac, DAC_ChannelConfTypeDef* sConfig, uint32_t Channel)

"为指定通道设定指定值"
HAL_StatusTypeDef 
HAL_DAC_SetValue(DAC_HandleTypeDef* hdac, uint32_t Channel, uint32_t Alignment, uint32_t Data)

"获取状态"
HAL_DAC_StateTypeDef 
HAL_DAC_GetState(DAC_HandleTypeDef* hdac)


```
# DMA
```c
/**
  * @brief  初始化指定DMA
  * @param  hdma: hdma1
  * @retval HAL status
  */
"初始化"
HAL_StatusTypeDef 
HAL_DMA_Init(DMA_HandleTypeDef *hdma)

"取消初始化"
HAL_StatusTypeDef 
HAL_DMA_DeInit(DMA_HandleTypeDef *hdma)

/**
  * @brief  Start the DMA Transfer.
  * @param  hdma: hdma(x)
  * @param  SrcAddress: 自己创建的存储的地址空间
  * @param  DstAddress: 目标的地址
  * @param  DataLength: 传输的长度
  * @retval HAL status
  */
"start"
HAL_StatusTypeDef 
HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)

"start-IT-mode"
HAL_StatusTypeDef 
HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)

"stop-Transfer/终止传输"
HAL_StatusTypeDef 
HAL_DMA_Abort(DMA_HandleTypeDef *hdma)

"stop--IT-Transfer/终止"
HAL_StatusTypeDef 
HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma)

"轮询传输结束，句柄，级别，超时时间"
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout)

"中断服务函数"
void 
HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma)

"注册回调"
HAL_StatusTypeDef
HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma))

"取消回调"
HAL_StatusTypeDef
HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID)

"获取状态"
HAL_DMA_StateTypeDef 
HAL_DMA_GetState(DMA_HandleTypeDef *hdma)


```
# CAN
```c
/**
  * @brief  初始化can
  * @param  hcan: 指向CAN_HandleTypeDef结构的指针，
  * 			  该结构包含 指定CAN的配置信息 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_CAN_Init(CAN_HandleTypeDef* hcan)
/**
  * @brief  配置CAN接收过滤器
  * @param  hcan: 指向CAN_HandleTypeDef结构的指针，
  * 			  该结构包含 指定CAN的配置信息 
  * @param sFilterConfig: 	指向CAN_FilterConfTypeDef结构的
  * 						指针，指向过滤器的配置信息
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_CAN_ConfigFilter(CAN_HandleTypeDef* hcan, CAN_FilterConfTypeDef* sFilterConfig)
/**
  * @brief  取消初始化，回复默认值
  * @param  hcan: 指向CAN_HandleTypeDef结构的指针，
  * 			  该结构包含 指定CAN的配置信息  
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_CAN_DeInit(CAN_HandleTypeDef* hcan)

/**
  * @brief  发送CAN消息
  * @param  hcan: 句柄 
  * @param  Timeout: Timeout value   
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_CAN_Transmit(CAN_HandleTypeDef* hcan, uint32_t Timeout)
/**
  * @brief  接收
  * @param  hcan: 句柄  
  * @param  FIFONumber: 指定接收FIFO编号
  * @param  Timeout: Timeout value 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_CAN_Receive(CAN_HandleTypeDef* hcan, uint8_t FIFONumber, uint32_t Timeout)

"中断发送"
HAL_StatusTypeDef 
HAL_CAN_Transmit_IT(CAN_HandleTypeDef* hcan)

"中断接收"
HAL_StatusTypeDef 
HAL_CAN_Receive_IT(CAN_HandleTypeDef* hcan, uint8_t FIFONumber)

"进入睡眠模式/低功耗模式"
HAL_StatusTypeDef 
HAL_CAN_Sleep(CAN_HandleTypeDef* hcan)

"从睡眠模式中唤醒"
HAL_StatusTypeDef
HAL_CAN_WakeUp(CAN_HandleTypeDef* hcan)


/**
  * @brief  CAN中断请求（中断服务函数）
  * @param  hcan: 句柄 
  * @param  Timeout: Timeout value   
  * @retval HAL status
  */
 void 
 HAL_CAN_IRQHandler(CAN_HandleTypeDef* hcan)
 
 "发送回调函数——自定义写逻辑"
__weak void 
HAL_CAN_TxCpltCallback(CAN_HandleTypeDef* hcan)

 "接收回调函数——自定义写逻辑"
__weak void 
HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan)

"错误回调"
__weak void 
HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)

"获取CAN状态"
HAL_CAN_StateTypeDef 
HAL_CAN_GetState(CAN_HandleTypeDef* hcan)

```

# IIC
```c
"初始化"
HAL_StatusTypeDef 
HAL_I2C_Init(I2C_HandleTypeDef *hi2c)

"取消初始化"
HAL_StatusTypeDef 
HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c)

/**
  * @brief  主模式发送
  * @param  hi2c ：hi2c(x)
  * @param :目标设备地址
  * @param  要发宋的数据
  * @param  发送的长度
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef
HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

/**
  * @brief  主模式-阻塞模式下-接收
  * @param  hi2c ：hi2c(x)
  * @param :目标设备地址
  * @param  要接收的数据
  * @param  接收的长度
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)

/**
  * @brief  从模式下发送
  * @param  hi2c ：hi2c(x)
  * @param  要发送的数据
  * @param  接收的长度
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout)

"从机接收"
HAL_StatusTypeDef 
HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout)

"中断模式主机发送 /句柄、设备地址、需要发送的数据、长度"
HAL_StatusTypeDef
HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)

"中断模式主机接收 /句柄、设备地址、存放接收的空间、长度"
HAL_StatusTypeDef
HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)

"中断模式从机发送 /句柄、需要发送的数据、长度"
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)

"中断模式从机接收 /句柄、存放接收的空间、长度"
HAL_StatusTypeDef
HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)

"DMA模式主机发送 /句柄、设备地址、需要发送的数据、长度"
HAL_StatusTypeDef
HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)

"DMA模式主机接收 /句柄、设备地址、存放接收的空间、长度"
HAL_StatusTypeDef
HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)

"DMA模式从机发送 /句柄、需要发送的数据、长度"
HAL_StatusTypeDef
HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)

"DMA模式从机接收 /句柄、存放接收的空间、长度"
HAL_StatusTypeDef
HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)

"阻塞模式写入设备特定的寄存器"
"param:句柄、设备地址、设备寄存器地址、寄存器大小，要发送到数据、发送数据的大小、超时时间"
HAL_StatusTypeDef 
HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)

"阻塞模式读取设备特定的寄存器"
"param:句柄、设备地址、设备寄存器地址、寄存器大小，存放数据地址、大小、超时时间"
HAL_StatusTypeDef 
HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)

"IT模式写入设备特定的寄存器"
"param:句柄、设备地址、设备寄存器地址、寄存器大小，要发送到数据、发送数据的大小"
HAL_StatusTypeDef 
HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)

"阻塞模式读取设备特定的寄存器"
"param:句柄、设备地址、设备寄存器地址、寄存器大小，要发送到数据、发送数据的大小"
HAL_StatusTypeDef 
HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)

"DMA模式写入设备特定的寄存器"
"param:句柄、设备地址、设备寄存器地址、寄存器大小，要发送到数据、发送数据的大小"
HAL_StatusTypeDef 
HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)

"DMA模式读取设备特定的寄存器"
"param:句柄、设备地址、设备寄存器地址、寄存器大小，要发送到数据、发送数据的大小"
HAL_StatusTypeDef 
HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)

"检查通信设备是否准备好通信"
"句柄、设备地址、实验次数、超时时间"
HAL_StatusTypeDef 
HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout)

"中断事件处理"
void 
HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c)

"中断错误处理"
void
HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c)

"主机发送完成回调"
__weak void 
HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)

"主机接收完成回调"
__weak void 
HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)

"从机发送完成回调"
__weak void 
HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)

"从机接收完成回调"
__weak void 
HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)

"获取状态"
HAL_I2C_StateTypeDef 
HAL_I2C_GetState(I2C_HandleTypeDef *hi2c)

"获取模式"
HAL_I2C_ModeTypeDef 
HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c)

"主机终止通信"
HAL_StatusTypeDef
HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress)
```

# SPI
```c
"硬件SPI"
"初始化"
__weak HAL_StatusTypeDef 
HAL_SPI_Init(SPI_HandleTypeDef *hspi)

"取消初始化"
HAL_StatusTypeDef 
HAL_SPI_DeInit(SPI_HandleTypeDef *hspi)

/**
  * @brief  阻塞模式传输一定数量的数据
  * @param  hspi: &hspi1
  * @param  pData: 需要发送的数据的指针
  * @param  Size: 传输数据的大小
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
"发送"
HAL_StatusTypeDef 
HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)

"接收"
HAL_StatusTypeDef 
HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)


/**
  * @brief  传送接收一体函数
  * @param  hspi: &hspi1
  * @param  pTxData: 指向发送的缓冲区的指针
  * @param  pRxData: 指向接收的缓冲区的指针
  * @param  Size: 发送和接收的数据量
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
"发送接收一体"
HAL_StatusTypeDef
HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout)


"中断模式发送"
HAL_StatusTypeDef 
HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)

"中断模式接收"
HAL_StatusTypeDef 
HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)

"中断模式发送接收一体"
HAL_StatusTypeDef
HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size)

"DMA发送"
HAL_StatusTypeDef 
HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)

"DMA接收"
HAL_StatusTypeDef 
HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)

"DMA发送接收一体"
HAL_StatusTypeDef
HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size)

"终止传输"
HAL_StatusTypeDef 
HAL_SPI_Abort(SPI_HandleTypeDef *hspi)

"DMA暂停传输"
HAL_StatusTypeDef 
HAL_SPI_DMAPause(SPI_HandleTypeDef *hspi)

"DMA回复传输"
HAL_StatusTypeDef 
HAL_SPI_DMAResume(SPI_HandleTypeDef *hspi)

"DMA停止传输"
HAL_StatusTypeDef 
HAL_SPI_DMAStop(SPI_HandleTypeDef *hspi)

"中断服务函数"
void 
HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi)

"发送回调函数"
__weak void 
HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)

"接收回调函数"
__weak void 
HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)

"获取函数状态"
HAL_SPI_StateTypeDef 
HAL_SPI_GetState(SPI_HandleTypeDef *hspi)

```
# FLASH
```c
/**
  * @brief  Locks the FLASH control register access
  * @retval HAL Status
  */
"锁定"
HAL_StatusTypeDef 
HAL_FLASH_Lock(void)

"解锁"
HAL_StatusTypeDef 
HAL_FLASH_Unlock(void)

/**
  * @brief 在指定地址写入
  * @note  在解锁之后调用，如果锁定首先要解锁
  * @note  同时请求擦除和写入，先执行擦除
  * @note  新编程之前应该擦除
  * @param  TypeProgram:写入方式
  * @param  Address：要写入的地址
  * @param  Data:要写入的数据
  * @retval HAL Status
  */
HAL_StatusTypeDef 
HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)

"IT-MODE"
HAL_StatusTypeDef 
HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data)

"中断服务入口"
void 
HAL_FLASH_IRQHandler(void)

```

# RTC
```c
"初始化"
HAL_StatusTypeDef 
HAL_RTC_Init(RTC_HandleTypeDef *hrtc)

"取消初始化"
HAL_StatusTypeDef 
HAL_RTC_DeInit(RTC_HandleTypeDef *hrtc)

"设置时间(时分秒)"
"句柄，设置时间，格式(1、RTC_FORMAT_BIN\
					2、RTC_FORMAT_BCD)"
HAL_StatusTypeDef 
HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format)

"获取时间"
HAL_StatusTypeDef 
HAL_RTC_GetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format)

"设置日期(年月日)"
HAL_StatusTypeDef 
HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format)

"获取日期"
HAL_StatusTypeDef 
HAL_RTC_GetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format)

"设置闹钟"
HAL_StatusTypeDef 
HAL_RTC_SetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Format)

"中断设置闹钟"
HAL_StatusTypeDef 
HAL_RTC_SetAlarm_IT(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Format)



```

# IWDG && WWDG
```c
***************iwdg************
"初始化看门狗"
HAL_StatusTypeDef 
HAL_IWDG_Init(IWDG_HandleTypeDef *hiwdg)

"刷新看门狗"
HAL_StatusTypeDef 
HAL_IWDG_Refresh(IWDG_HandleTypeDef *hiwdg)



***************wwdg************
"初始化"
HAL_StatusTypeDef
HAL_WWDG_Init(WWDG_HandleTypeDef *hwwdg)

void                  
HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)

"刷新"
HAL_StatusTypeDef     
HAL_WWDG_Refresh(WWDG_HandleTypeDef *hwwdg);

"中断服务"
void  
HAL_WWDG_IRQHandler(WWDG_HandleTypeDef *hwwdg);

```
# TIM
```c
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    
  HAL_TIM_STATE_READY             = 0x01U,   
  HAL_TIM_STATE_BUSY              = 0x02U,    
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    
  HAL_TIM_STATE_ERROR             = 0x04U    
}HAL_TIM_StateTypeDef;

"基本状态获取"
HAL_TIM_StateTypeDef
HAL_TIM_Base_GetState(TIM_HandleTypeDef *htim)

"输出比较获取"
HAL_TIM_StateTypeDef 
HAL_TIM_OC_GetState(TIM_HandleTypeDef *htim)

"PWM状态获取"
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(TIM_HandleTypeDef *htim)

"输入捕获状态获取"
HAL_TIM_StateTypeDef 
HAL_TIM_IC_GetState(TIM_HandleTypeDef *htim)

"单脉冲状态获取"
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(TIM_HandleTypeDef *htim)


	/"##### Time Output Compare functions #####"/ 
	/"############ 定时器输出比较功能 ##########"/
	
/**
  * @brief  初始化定时器输出比较
  * @param  htim : &htim1
  * @retval HAL status
  */	
HAL_StatusTypeDef 
HAL_TIM_OC_Init(TIM_HandleTypeDef* htim);
/**
  * @brief  取消初始化定时器输出比较
  * @param  htim : &htim1
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim);
/**
  * @brief  启动定时器输出比较
  * @param  htim : 句柄 
  * @param  Channel : 通道（1-4都可选）
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @brief  停止定时器输出比较
  * @param  htim : 句柄 
  * @param  Channel : 通道（1-4都可选）
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @brief  中断模式下启动定时器输出比较
  * @param  htim : 句柄 
  * @param  Channel : 通道（1-4都可选）
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @brief  中断模式下停止定时器输出比较
  * @param  htim : 句柄 
  * @param  Channel : 通道（1-4都可选）
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @brief  DMA模式下启动定时器输出比较
  * @param  htim : 句柄 
  * @param  Channel : 通道（1-4都可选）
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected 
  * @param  pData : 原地址
  * param	Lengh : 数据长度
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
/**
  * @brief  DMA模式下停止定时器输出比较
  * @param  htim : 句柄 
  * @param  Channel : 通道（1-4都可选）
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected 
  * @retval HAL status
  */
HAL_StatusTypeDef 
HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);

/**
  * @brief  初始化
  * @param  htim : TIM Input Capture handle
  * @retval HAL status
  */
"初始化"
HAL_StatusTypeDef 
HAL_TIM_IC_Init(TIM_HandleTypeDef *htim);
"取消初始化"
HAL_StatusTypeDef 
HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim);
/**
  * @brief  启动定时器输入捕获
  * @param  htim : 用哪个定时器
  * @param  Channel : 用哪个通道
  *          		  四选一
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
*/
"*****START******"
HAL_StatusTypeDef 
HAL_TIM_IC_Start (TIM_HandleTypeDef *htim, uint32_t Channel);
"*****STOP******"
HAL_StatusTypeDef 
HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

"中断模式启动"
HAL_StatusTypeDef 
HAL_TIM_IC_Start_IT (TIM_HandleTypeDef *htim, uint32_t Channel)

"中断模式关闭"
HAL_StatusTypeDef 
HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel)

"DMA_MODE_START"
HAL_StatusTypeDef 
HAL_TIM_IC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length)

"DMA_MODE_STOP"
HAL_StatusTypeDef 
HAL_TIM_IC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel)

"初始化"
HAL_StatusTypeDef 
HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode)
"取消初始化"
HAL_StatusTypeDef
HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim)
/**
  * @brief  启动
  * @param  htim : TIM One Pulse handle
  * @param  OutputChannel : TIM Channels to be enabled
  *          	2选1，支持单脉冲的通道少
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  * @retval HAL status
*/
HAL_StatusTypeDef 
HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel)
"参数同上_stop"
HAL_StatusTypeDef 
HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel)

"interrupt-mode-start"
HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel)

"interrupt-mode-stop"
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel)

"DMA-MODE-START"
"!!!!!!!!!!!!!!不支持DMA!!!!!!!!!!!!"
```
# 全局中断开启关闭，软系统复位
```c
__disable_irq();      //关闭全局中断
 /
__enable_irq();      //开启全局中断
 /
NVIC_SystemReset()  //软复位系统，最好关闭中断使用

```