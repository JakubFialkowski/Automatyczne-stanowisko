# Automatyczne-stanowisko

Siła ciągu wytwarzana przez silnik mierzona jest za pomocą belki tensometrycznej NA27 o zakresie pomiarowym od 0 do 5 kg. Pomiar wartości tensometru obsługuje 24-bitowy konwerter analogowo-cyfrowy oparty na chipie XH711. W celu realizacji pomiaru prędkości obrotowej silnika zastosowano tachometr bazujący na czujniku odbicia wiązki. W tym celu zastosowano czujnik odbiciowy TCRT5000 oraz naklejono pasek czarnej foli wokół rotora silnika, zostawiając mały fragment odbijający wiązkę z czujnika. Prędkość obrotowa określana jako liczba obrotów silnika na minutę (ang. RPM – revolutions per minute) liczony będzie stosunek czasu minuty do czasu, jaki upłynie między dwoma kolejnymi odbiciami wiązki. Do pomiaru natężenia prądu wykorzystano moduł ACS712, pracujący w oparciu o efekt Halla. Do pomiaru napięcia wykonano dzielnik napięcia na bazie rezystorów 100kΩ i 10kΩ, który obniża napięcie do zakresu 0-5V, dzięki czemu możliwy jest pomiar prądu za pomocą 10-bitowych wejść analogowych  jednostki pomiarowej. W celu akwizycji pomiarów użyto Arduino Uno z wykonanym oprogramowaniem, które rejestruje oraz wysyła dane zebrane z czujników do komputera. W celu sterowania elektronicznym regulatorem prędkości zastosowano układ testera serwomechanizmów modelarskich, który pozwala na zadawanie szerokości impulsu PWM za pomocą pokrętła. Szerokość impulsu została także zmierzona i zarejestrowana. Mierzone wartości zostały zapisane do pliku przy pomocy portu szeregowego oraz programu CoolTerm 1.4.7. Następnie dane zostały opracowane oraz przedstawione za pomocą programu MATLAB R2015.

Użyto:
Arduino Uno
Belka tensometryczna NA27
ADC XH711
TCRT5000
ACS712
Dzielnik napięcia 100kΩ i 10kΩ
