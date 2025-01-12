#include "pico/stdlib.h"

// Pino do LED vermelho
#define LED_PIN_RED 13

// Função para enviar um ponto (.)
// Um ponto é representado pelo LED aceso por 0,2 segundos, gap entre a mesma letra 0,125
void enviar_ponto(int pino_led) {
    gpio_put(pino_led, 1);
    sleep_ms(200);
    gpio_put(pino_led, 0);
    sleep_ms(125);
}

// Função para enviar um traço (-)
// Um traço é representado pelo LED aceso por 0,8 segundos, gap entre a mesma letra 0,125
void enviar_traco(int pino_led) {
    gpio_put(pino_led, 1); 
    sleep_ms(800);
    gpio_put(pino_led, 0);
    sleep_ms(125);
}

// Função para enviar a letra "S" (3 pontos)
void enviar_S(int pino_led) {
    enviar_ponto(pino_led);
    enviar_ponto(pino_led);
    enviar_ponto(pino_led);
}

// Função para enviar a letra "O" (3 traços)
void enviar_O(int pino_led) {
    enviar_traco(pino_led);
    enviar_traco(pino_led);
    enviar_traco(pino_led);
}

int main() {
    // Inicializa a GPIO
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    while (1) {
        // Enviar o sinal SOS: S (pontos), O (traços), S (pontos), Intervalo entre letras (0,25s), loop a cada 3s
        enviar_S(LED_PIN_RED);
        sleep_ms(250);
        enviar_O(LED_PIN_RED);
        sleep_ms(250);
        enviar_S(LED_PIN_RED);
        sleep_ms(3000);
    }

    return 0;
}
