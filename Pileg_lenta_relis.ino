
// ----- настройка ленты и пинов
#define LED_PIN 5     // пин управления лентой (Din)
#define LED_NUM 205    // количество светодиодов (если светиков больше чем 255 - counter назначить int-ом)
#define IR_PIN 2      // пин ИК приёмника
#define btn_set 3    //пин кнопки переключения режимов

// ----- объявляем кнопки пульта (пульт от гирлянды 13 кнопок)
#define IR_1     0x44
#define IR_2     0x43
#define IR_3     0x7
#define IR_4     0x9
#define IR_5     0x16
#define IR_6     0xD
#define IR_7     0xC
#define IR_8     0x5E
#define IR_ON    0x45  //кнопка "ОК"
#define IR_OFF   0x47  //кнопка "0"
#define IR_TIMER 0x46
#define IR_DIM_plus  0x5A
#define IR_DIM_minus  0x8

// ----- периоды таймеров
int period_case1 = 30;
int period_case2 = 40;
uint32_t period_Timer = 600000; //таймер отключения ленты

#include <FastLED.h>   // подключаем библиотеку
CRGB leds[LED_NUM];    // создаём объект*/

#include "IRLremote.h" // подключаем библиотеку
CNec IRLremote;     //выбираем протокол*/

#include <GyverButton.h>  // подключаем библиотеку
GButton butt1(btn_set);  // создаём объект*/

uint32_t IRdata; // переменная для работы пульта
volatile byte mode = 0; //переменная номера режима
byte num_case2 = 0; //переменная для кейса 2
byte num_case3 = 0; //переменная для кейса 4
byte counter; //переменная для эффектов ленты
volatile bool ir_flag; // флаг для работы с ИК пультом
volatile bool tmr_flag = false;  // флаг для работы с кнопкой TIMER
volatile bool work_flag = false;  // флаг для включения выключения ленты
uint32_t tmrCase1, tmrCase2, tmrTimer;  //таймеры для кейсов вместо delay и для вывода принта отладки
byte bright = 70; //переменная яркости ленты
byte stepBright = 10; //переменная шага изменения яркости
byte stepSpeed = 20; //переменная шага изменения скорости
unsigned int stepTimer_little = 60000; //переменная малого шага изменения таймера
uint32_t stepTimer_big = 300000; //переменная большого шага изменения таймера

void setup()
{
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_NUM); //инициализация ленты
  FastLED.setBrightness(bright); //яркость ленты*/

  IRLremote.begin(IR_PIN); //запускаем ИК порт

  butt1.setTimeout(900); // установка времени удержания кнопки

  load(); // отключение ленты в случае перезагрузки МК
}

void loop()
{
  oprosIR();  // опрос ИК пульта
  handSet();  // опрос кнопки
  mainLoop(); // главный цикл обработки и отрисовки
  if (tmr_flag)
  {
    if (millis() - tmrTimer >= period_Timer)
    {
      tmr_flag = false; // опускаем флаг таймера
      work_flag = false; // опускаем флаг работы
      FastLED.clear();
      FastLED.show(); // отключаем ленту
    }
  }
}
