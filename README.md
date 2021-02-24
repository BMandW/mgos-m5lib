# mongoose os M5Stack library

M5Stack M5Stack simple library

## build

```
$ mos build --local
```

## Example

mos.yml
```yaml
libs:
  - origin: https://github.com/mongoose-os-libs/boards
  - origin: https://github.com/mongoose-os-libs/ca-bundle
  - origin: https://github.com/mongoose-os-libs/rpc-service-config
  - origin: https://github.com/mongoose-os-libs/rpc-service-fs
  - origin: https://github.com/mongoose-os-libs/rpc-uart
  - origin: https://github.com/mongoose-os-libs/i2c
  - origin: https://github.com/BMandW/mgos-m5lib.git
    version: master

```

main.cpp
```cpp

#include <mgos.h>
#include <mgos_app.h>
#include <mgos_time.h>
#include <mgos_m5stack.h>

void button_handler(int pin, void* arg) {
    MGOS_M5.Lcd.printf(10, 20, "Button %d, uptime: %.3f sec", pin, mgos_uptime());
    LOG(LL_INFO, ("Button %d, %.3f", pin, mgos_uptime()));
}
enum mgos_app_init_result mgos_app_init(void) {
    MGOS_M5.begin();

    MGOS_M5.Lcd.printf(10, 10, "Hello World");
    MGOS_M5.BtnA.set_button_handler(button_handler, NULL);
    MGOS_M5.BtnB.set_button_handler(button_handler, NULL);
    MGOS_M5.BtnC.set_button_handler(button_handler, NULL);
}

```

## API

- MOGS_M5Stack class
    - MGOS_M5 instance
    - MGOS_M5Button instance: BtnA,B,C
    - MGOS_M5Display instance: Lcd

- MGOS_M5Button
    - set_button_handler method

- MGOS_M5Display
    - begin: initialize process
    - printf: text draw
    - printf_col: text draw with color
    - etc... [ili9341 driver's](https://mongoose-os.com/docs/mongoose-os/api/drivers/ili9341-spi.md) method