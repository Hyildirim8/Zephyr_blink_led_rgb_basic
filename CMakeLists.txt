# Minimum gereksinimleri belirtin
cmake_minimum_required(VERSION 3.13.1)

# Zephyr projesini başlat
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blink_led)

# Proje kaynak dosyalarını belirtin
target_sources(app PRIVATE src/main.c)
