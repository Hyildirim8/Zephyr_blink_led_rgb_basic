#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

#define LED_PIN 13  // ESP32 GPIO32 pinine bağlı LED
#define LED_PIN1 12
#define LED_PIN2 14
void main(void) {
    const struct device *gpio_dev;
    int ret;

    // GPIO sürücüsünü alın
    gpio_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));  // Zephyr 3.x sürümünde gpio0 olarak tanımlı
    if (!device_is_ready(gpio_dev)) {
        printk("Hata: GPIO cihazı hazır değil.\n");
        return;
    }

    // GPIO32 pinini çıkış olarak ayarla
    ret = gpio_pin_configure(gpio_dev, LED_PIN, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Hata: GPIO pini yapılandırılamadı.\n");
        return;
    }
    gpio_pin_configure(gpio_dev, LED_PIN1, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure(gpio_dev, LED_PIN2, GPIO_OUTPUT_ACTIVE);

    // LED'i belirli aralıklarla yakıp söndür
    while (1) {
        gpio_pin_toggle(gpio_dev, LED_PIN); 
        printk("led yanıyo"); // LED'i aç/kapat
        k_msleep(1000);
        gpio_pin_toggle(gpio_dev, LED_PIN1);
        k_msleep(1000);
        gpio_pin_toggle(gpio_dev, LED_PIN2);  
        k_msleep(1000);                    // 1 saniye bekle
    }
}