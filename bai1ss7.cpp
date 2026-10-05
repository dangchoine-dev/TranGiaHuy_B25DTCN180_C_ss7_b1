#include <stdio.h>

struct SmartDevice {
    int id;
    float voltage;
    float current;
    float power_watt;
    int is_active;
    int is_overloaded;
};

int main() {
    struct SmartDevice heater;

    heater.id = 101;
    heater.voltage = 220.0f;
    heater.current = 35.0f;
    heater.is_active = 1;
    heater.is_overloaded = 0;

    if (heater.current > 30.0f) {
        heater.is_overloaded = 1;
        heater.is_active = 0;
        heater.power_watt = 0.0f;
    } else {
        heater.power_watt = heater.voltage * heater.current;
    }

    printf("=== HETHONG GIAM SAT THIET BI SMART HOME ===\n");
    printf("Ma thiet bi: %d\n", heater.id);
    printf("Trang thai hoat dong: %s\n",
           heater.is_active ? "BAT" : "TAT");
    printf("Cong suat tieu thu: %.2f W\n",
           heater.power_watt);
    printf("Canh bao qua tai (>30A): %s\n",
           heater.is_overloaded ? "CO (DA NGAT DIEN)" : "KHONG");

    return 0;
}
//Phân tích l?i:
//
//* L?i: Tính công su?t tru?c khi ki?m tra quá t?i.
//* Khi `current > 30A`, thi?t b? b? t?t nhung `power_watt` v?n gi? giá tr? cu.
//* S?a: Ki?m tra quá t?i tru?c, n?u quá t?i thì t?t thi?t b? và d?t `power_watt = 0`.
//* Test 1: 220V, 35A ? T?T, quá t?i, 0W.
//* Test 2: 220V, 20A ? B?T, an toàn, 4400W.

