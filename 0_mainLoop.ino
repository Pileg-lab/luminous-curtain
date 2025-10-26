
//---------- световые эффекты ----------

void mainLoop()
{
  if (work_flag)
  {
    switch (mode)
    {
      case 0:  //подсветка
        for (int i = 0; i < LED_NUM; i++)
        {
          leds[i] = CRGB::MintCream;  //White
        }
        break;
      case 1: //динамичная радуга
        if (millis() - tmrCase1 >= period_case1)
        {
          tmrCase1 = millis();  // сброс таймера
          for (int i = 0; i < LED_NUM; i++)
          {
            leds[i].setHue(counter + i * 255 / LED_NUM);
          }
          counter++;        // counter меняется от 0 до 255 (тип данных byte)
        }
        break;
      case 2: //бегущие пиксели
        switch (num_case2)
        {
          case 0:
            if (millis() - tmrCase2 >= period_case2)
            {
              tmrCase2 = millis();  // сброс таймера
              FastLED.clear();
              if (counter < 2)
              {
                counter = 2;
              }
              leds[counter - 2] = CRGB::Red;
              leds[counter - 1] = CRGB::Yellow;
              leds[counter] = CRGB::Green;
              if (++counter >= LED_NUM - 3)
              {
                counter = LED_NUM - 3;
                num_case2 = 1;
              }
            }
            break;
          case 1:
            if (millis() - tmrCase2 >= period_case2)
            {
              tmrCase2 = millis();// сброс таймера
              FastLED.clear();
              if (counter > LED_NUM - 3)
              {
                counter = LED_NUM - 3;
              }
              leds[counter + 2] = CRGB::Red;
              leds[counter + 1] = CRGB::Yellow;
              leds[counter] = CRGB::Green;
              if (--counter <= 0)
              {
                counter = 2;
                num_case2 = 0;
              }
            }
            break;
        }
        break;
      case 3: //изменяющийся цвет подсветки
        switch (num_case3)
        {
          case 0:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Chartreuse;  //White
            }
            break;
          case 1:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Bisque;  //White
            }
            break;
          case 2:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::CadetBlue;  //White
            }
            break;
          case 3:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Chocolate;  //White
            }
            break;
          case 4:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Coral;  //White
            }
            break;
          case 5:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::CornflowerBlue;  //White
            }
            break;
          case 6:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::DarkGoldenrod;  //White
            }
            break;
          case 7:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::DarkOrange;  //White
            }
            break;
          case 8:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::DarkOrchid;  //White
            }
            break;
          case 9:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::DodgerBlue;  //White
            }
            break;
          case 10:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::FloralWhite;  //White
            }
            break;
          case 11:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::ForestGreen;  //White
            }
            break;
          case 12:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Goldenrod;  //White
            }
            break;
          case 13:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::LawnGreen;  //White
            }
            break;
          case 14:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::LightSalmon;  //White
            }
            break;
          case 15:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::LightSeaGreen;  //White
            }
            break;
          case 16:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::LightYellow;  //White
            }
            break;
          case 17:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::LimeGreen;  //White
            }
            break;
          case 18:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Orange;  //White
            }
            break;
          case 19:  //подсветка
            for (int i = 0; i < LED_NUM; i++)
            {
              leds[i] = CRGB::Peru;  //White
            }
            break;
        }
        break;
    }
    if (!IRLremote.receiving())
    {
      FastLED.show();
    }
  }
}
