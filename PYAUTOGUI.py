import serial 
import time 
import pyautogui  

ArduinoSerial = serial.Serial('/dev/ttyACM0',9600) 
time.sleep(5) 
screenWidth, screenHeight = pyautogui.size()
currentMouseX, currentMouseY = pyautogui.position()
pyautogui.moveTo(0,667)
pyautogui.click()
while 1:
    incoming = str (ArduinoSerial.readline()) 
    print incoming
    
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)
	pyautogui.typewrite(['enter'],0.2)

    if 'Rewind' in incoming:
        pyautogui.press('left')  

    if 'Forward' in incoming:
        pyautogui.press('right') 

    if 'Volume Increased' in incoming:
        pyautogui.press('down')
        

    if 'Volume Decreased' in incoming:
        pyautogui.press('up')

    incoming = "";
