//git clone https://github.com/raspberrypi/pico-sdk.git --branch master
//cd pico-sdk
//git submodule update --init

//sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential

// cmake .. -DPICO_BOARD=pico_w

// cp blink.uf2 /media/psyker/RPI-RP2/
// sudo minicom -b 115200 -o -D /dev/ttyACM0


#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/cyw43_arch.h"

#define LED_PIN 1

void blinx(void);
void init(void);
void gpio_multi_init(uint16_t spin, uint16_t epin);

int main()
{
    // Initialize GPIO and other peripherals
    init();
  
    // Set initial states of the GPIO pins
for(int i =0;i<=29;i++){
  gpio_put(i, 1);
}
    
    gpio_put(12, 1);
    gpio_put(13, 1);
    gpio_put(15, 1);
    gpio_put(14, 1);
  
    // Start blinking
    blinx();
  
    return 0;
}

void init(void){
    stdio_init_all();
    cyw43_arch_init();
    gpio_multi_init(12, 15);
    gpio_multi_init(16, 19); // Initialize GPIO pins 0 to 4
}

void gpio_multi_init(uint16_t spin, uint16_t epin) {
    for (; spin <= epin; spin++) {
        gpio_init(spin);
        gpio_set_dir(spin, GPIO_OUT);
    }
}

void blinx(void){
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(1000);
    }
}
