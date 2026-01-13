# PC side service (placeholder)

import serial
from pynput.keyboard import Controller, Key

PORT = "COM3"
BAUDRATE = 9600

keyboard = Controller()

ser = serial.Serial(PORT, BAUDRATE, timeout=1)
print("Listening from Arduino...")

while True:
    line = ser.readline().decode("utf-8").strip()
    if not line:
        continue

    print("Received:", line)

    if line == "PLAY":
        keyboard.press(Key.media_play_pause)
        keyboard.release(Key.media_play_pause)

    if line == "VOL_UP":
        keyboard.press(Key.media_volume_up)
        keyboard.release(Key.media_volume_up)

    if line == "VOL_DOWN":
        keyboard.press(Key.media_volume_down)
        keyboard.release(Key.media_volume_down)

    if line == "NEXT":
        keyboard.press(Key.shift)
        keyboard.press("n")
        keyboard.release("n")
        keyboard.release(Key.shift)
        
