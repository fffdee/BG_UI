#include <stdio.h>
#include <stdint.h>
// 假设这是16位的RGB565数据
uint16_t rgb565 = 0b1111100110011110; // 示例数据

int main() {
    // 将RGB565数据拆分为红色、绿色和蓝色部分
    uint8_t r = (rgb565 >> 11) & 0x1F; // 移动11位到右边，然后与0x1F（即00011111）进行与操作，提取红色部分
    uint8_t g = (rgb565 >> 5) & 0x3F;  // 移动5位到右边，然后与0x3F（即00111111）进行与操作，提取绿色部分
    uint8_t b = rgb565 & 0x1F;          // 直接与0x1F进行与操作，提取蓝色部分

    // 由于RGB565中的红色和蓝色只有5位，而我们需要8位数据，因此需要将5位扩展到8位
    // 这可以通过将5位数据左移3位来实现
    r = r << 3;
    b = b << 3;

    // 打印结果
    printf("Red:   0x%02X\n", r);
    printf("Green: 0x%02X\n", g);
    printf("Blue:  0x%02X\n", b);

    return 0;
}