#include "main.h"

int main()
{
    while(true)
    {
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
        HAL_Delay(100);
        // HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    }
}