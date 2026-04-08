#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6fpM27KO7"
#define BLYNK_TEMPLATE_NAME "Nhà Thông Minh"
#define BLYNK_AUTH_TOKEN "dtBmPJOP2Gjdgdp6-BRvxMUT84LEDvV3"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ===== WIFI =====
char ssid[] = "Quang Ninh";
char pass[] = "98989898";

// ===== PIN =====
#define MQ2_DO 27
#define MQ2_AO 34

#define LED_PIN 25
#define BUZZER_PIN 32
#define RELAY_PIN 26

// ===== SYSTEM =====
bool blinkState = false;
unsigned long previousMillis = 0;
const int interval = 150;

const int alarmDuration = 3000;
bool gasAlarm = false;
unsigned long alarmStartTime = 0;

// ===== MODE =====
bool manualMode = false;
bool relayState = false;

// ===== BLYNK =====
BLYNK_WRITE(V2) {
  int value = param.asInt();

  manualMode = value;  // 1 = manual, 0 = auto

  digitalWrite(RELAY_PIN, value ? LOW : HIGH);

  Serial.print("Manual Mode: ");
  Serial.println(manualMode);
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V2);
}

void setup() {
  Serial.begin(115200);

  pinMode(MQ2_DO, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // relay OFF
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Khoi dong MQ2...");
  delay(30000); // warm-up

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  int gasDetected = digitalRead(MQ2_DO);
  int gasValue = analogRead(MQ2_AO);

  Serial.print("Gas AO: ");
  Serial.println(gasValue);
  Serial.print("D0: ");
  Serial.println(gasDetected);

  // ===== AUTO MODE =====
  if (!manualMode) {

    if (gasDetected == LOW && !gasAlarm) {
      gasAlarm = true;
      alarmStartTime = millis();
    }

    unsigned long currentMillis = millis();

    if (gasAlarm && (currentMillis - alarmStartTime < alarmDuration)) {

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        blinkState = !blinkState;

        digitalWrite(LED_PIN, blinkState);
        digitalWrite(BUZZER_PIN, blinkState);
      }

      // bật quạt
      digitalWrite(RELAY_PIN, LOW);

    } else {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(RELAY_PIN, HIGH);

      if (gasDetected == HIGH) {
        gasAlarm = false;
      }
    }
  }
}