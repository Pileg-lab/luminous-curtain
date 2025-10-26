
//---------- фунуция кнопки ----------

void handSet()
{
  butt1.tick();
  if (butt1.isSingle())   // если единичное нажатие
  {
    if (work_flag)
    {
      if (++mode > 3) mode = 0;
    }
  }
  // возвращает true при удержании дольше timeout. Сбрасывается после вызова
  if (butt1.isHolded())
  {
    work_flag = !work_flag; FastLED.clear(); FastLED.show();
  }
}
