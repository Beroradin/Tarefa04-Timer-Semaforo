#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_PIN 11
#define YELLOW_PIN 12
#define GREEN_PIN 13

volatile int cont = 1;
uint32_t contador = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    switch (cont) {
        case 0:
            gpio_put(RED_PIN, 1);
            gpio_put(YELLOW_PIN, 0);
            gpio_put(GREEN_PIN, 0);
            break;
        case 1:
            gpio_put(RED_PIN, 0);
            gpio_put(YELLOW_PIN, 1);
            gpio_put(GREEN_PIN, 0);
            break;
        case 2:
            gpio_put(RED_PIN, 0);
            gpio_put(YELLOW_PIN, 0);
            gpio_put(GREEN_PIN, 1);
            break;
    }

    cont++;
    if (cont >= 3) cont = 0;
    return true;
}

int main() {
    stdio_init_all();

    // Inicializando os pinos
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);
    gpio_init(YELLOW_PIN);
    gpio_set_dir(YELLOW_PIN, GPIO_OUT);
    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("O valor do contador é: %d\n", contador);
        contador++;
        sleep_ms(1000);
    }
}
