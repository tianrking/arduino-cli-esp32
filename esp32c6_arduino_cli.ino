#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

BLEServer *pServer = NULL;
BLECharacteristic *pTxCharacteristic;
bool deviceConnected = false;

class ServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        deviceConnected = true;
        Serial.println("Device connected");
    }

    void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
        Serial.println("Device disconnected");
    }
};

class RxCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
        String rxValue = pCharacteristic->getValue().c_str();
        if (rxValue.length() > 0) {
            Serial.write(rxValue.c_str(), rxValue.length());
        }
    }
};

void setupBLE() {
    BLEDevice::init("ESP32_BLE_UART");
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);

    pTxCharacteristic = pService->createCharacteristic(
                            CHARACTERISTIC_UUID_TX,
                            BLECharacteristic::PROPERTY_NOTIFY
                        );
    pTxCharacteristic->addDescriptor(new BLE2902());

    BLECharacteristic *pRxCharacteristic = pService->createCharacteristic(
                                               CHARACTERISTIC_UUID_RX,
                                               BLECharacteristic::PROPERTY_WRITE
                                           );
    pRxCharacteristic->setCallbacks(new RxCallbacks());

    pService->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();

    Serial.println("BLE device initialized and advertising");
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ; // 等待串口连接
    }
    Serial.println("Serial started");

    setupBLE();
    Serial.println("BLE UART Transparent Transmission Ready");
}

void loop() {
    if (deviceConnected && Serial.available()) {
        size_t len = Serial.available();
        uint8_t buffer[128];
        len = Serial.readBytes(buffer, min(len, sizeof(buffer)));
        pTxCharacteristic->setValue(buffer, len);
        pTxCharacteristic->notify();
    }

    // 如果设备未连接，每5秒重新开始广播
    static unsigned long lastAdvertisingTime = 0;
    if (!deviceConnected && millis() - lastAdvertisingTime > 5000) {
        BLEDevice::startAdvertising();
        Serial.println("Restarting advertising");
        lastAdvertisingTime = millis();
    }

    delay(10);
}