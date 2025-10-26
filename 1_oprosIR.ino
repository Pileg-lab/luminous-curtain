
//---------- опрос ИК пульта ----------

void oprosIR()
{
  if (IRLremote.available())
  {
    auto data = IRLremote.read();
    IRdata = data.command;
    ir_flag = true;
  }
  if (ir_flag)  // если данные пришли
  {
    switch (IRdata)
    {
      case IR_OFF: // отключение подсветки
        work_flag = false; FastLED.clear(); FastLED.show();
        break;
      case IR_ON: // включение подсветки
        work_flag = true;
        break;
      case IR_TIMER: // запуск таймера на выключение
        if (work_flag)
        {
          tmr_flag = true; // поднимаем флаг
          tmrTimer = millis();
        }
        break;
      case IR_1: // подсветка
        mode = 0;
        break;
      case IR_2: // радуга
        mode = 1;
        break;
      case IR_3: // бегущий светофор
        mode = 2;
        break;
      case IR_4: // изменяемая подсветка
        mode = 3;
        break;
      case IR_5: //кнопка смены подсветки
        if (work_flag)
        {
          if (mode == 3)
          {
            num_case3 = max(num_case3 - 1, 0);
          }
          if (mode == 0)
          {

            if (period_Timer <= stepTimer_big)
            {
              period_Timer = 60000;
            }
            else
            {
              period_Timer = max(period_Timer - stepTimer_big, 60000);
            }
            leds[LED_NUM / 2 + 10] = CRGB::Green;
            leds[LED_NUM / 2] = CRGB::Green;
            FastLED.show();
            delay(500);
            if (period_Timer == 60000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Blue;
              leds[LED_NUM / 2] = CRGB::Blue;
              leds[LED_NUM / 2 - 10] = CRGB::Blue;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 600000 || period_Timer == 1200000 || period_Timer == 1800000 || period_Timer == 2400000 || period_Timer == 3000000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Yellow;
              leds[LED_NUM / 2] = CRGB::Yellow;
              leds[LED_NUM / 2 - 10] = CRGB::Yellow;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 3600000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Purple;
              leds[LED_NUM / 2] = CRGB::Purple;
              leds[LED_NUM / 2 - 10] = CRGB::Purple;
              FastLED.show();
              delay(500);
            }
          }
        }
        break;
      case IR_6: //кнопка смены подсветки
        if (work_flag)
        {
          if (mode == 3)
          {
            num_case3 = min(num_case3 + 1, 13);
          }
          if (mode == 0)
          {
            period_Timer = min(period_Timer + stepTimer_big, 3600000);
            leds[LED_NUM / 2] = CRGB::Red;
            leds[LED_NUM / 2 - 10] = CRGB::Red;
            FastLED.show();
            delay(500);
            if (period_Timer == 60000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Blue;
              leds[LED_NUM / 2] = CRGB::Blue;
              leds[LED_NUM / 2 - 10] = CRGB::Blue;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 600000 || period_Timer == 1200000 || period_Timer == 1800000 || period_Timer == 2400000 || period_Timer == 3000000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Yellow;
              leds[LED_NUM / 2] = CRGB::Yellow;
              leds[LED_NUM / 2 - 10] = CRGB::Yellow;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 3600000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Purple;
              leds[LED_NUM / 2] = CRGB::Purple;
              leds[LED_NUM / 2 - 10] = CRGB::Purple;
              FastLED.show();
              delay(500);
            }
          }
        }
        break;
      case IR_7: // кнопка смены скорости огней
        if (work_flag)
        {
          if (mode == 1)
          {
            period_case1 = max(period_case1 - stepSpeed, 10);
          }
          if (mode == 2)
          {
            period_case2 = max(period_case2 - stepSpeed, 10);
          }
          if (mode == 0)
          {
            period_Timer = max(period_Timer - stepTimer_little, 60000);
            leds[LED_NUM / 2] = CRGB::Green;
            FastLED.show();
            delay(500);
            if (period_Timer == 60000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Blue;
              leds[LED_NUM / 2] = CRGB::Blue;
              leds[LED_NUM / 2 - 10] = CRGB::Blue;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 600000 || period_Timer == 1200000 || period_Timer == 1800000 || period_Timer == 2400000 || period_Timer == 3000000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Yellow;
              leds[LED_NUM / 2] = CRGB::Yellow;
              leds[LED_NUM / 2 - 10] = CRGB::Yellow;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 3600000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Purple;
              leds[LED_NUM / 2] = CRGB::Purple;
              leds[LED_NUM / 2 - 10] = CRGB::Purple;
              FastLED.show();
              delay(500);
            }
          }
        }
        break;
      case IR_8: // кнопка смены скорости огней
        if (work_flag)
        {
          if (mode == 1)
          {
            period_case1 = min(period_case1 + stepSpeed, 2000);
          }
          if (mode == 2)
          {
            period_case2 = min(period_case2 + stepSpeed, 2000);
          }
          if (mode == 0)
          {
            period_Timer = min(period_Timer + stepTimer_little, 3600000);
            leds[LED_NUM / 2] = CRGB::Red;
            FastLED.show();
            delay(500);
            if (period_Timer == 60000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Blue;
              leds[LED_NUM / 2] = CRGB::Blue;
              leds[LED_NUM / 2 - 10] = CRGB::Blue;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 600000 || period_Timer == 1200000 || period_Timer == 1800000 || period_Timer == 2400000 || period_Timer == 3000000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Yellow;
              leds[LED_NUM / 2] = CRGB::Yellow;
              leds[LED_NUM / 2 - 10] = CRGB::Yellow;
              FastLED.show();
              delay(500);
            }
            if (period_Timer == 3600000)
            {
              leds[LED_NUM / 2 + 10] = CRGB::Purple;
              leds[LED_NUM / 2] = CRGB::Purple;
              leds[LED_NUM / 2 - 10] = CRGB::Purple;
              FastLED.show();
              delay(500);
            }
          }
        }
        break;
      case IR_DIM_plus: // увеличение яркости
        if (work_flag)
        {
          bright = min(bright + stepBright, 255);
          FastLED.setBrightness(bright);
        }
        break;
      case IR_DIM_minus: // уменьшение яркости
        if (work_flag)
        {
          bright = max(bright - stepBright, 10);
          FastLED.setBrightness(bright);
        }
        break;
      default:

        break;
    }
    ir_flag = false;
  }
}
