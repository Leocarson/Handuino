#!/usr/bin/env python3

# NOTE: this example requires PyAudio because it uses the Microphone class
import time
import speech_recognition as sr
import serial
# obtain audio from the microphone
def stringConvert(s):
    return [ord(char) - 96 for char in s.lower()]

ser = serial.Serial('COM8',9600)
print(ser.name)
while True:
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Awaiting audio...")
        audio = r.listen(source)
        
    # recognize speech using Houndify
    try:
        text = r.recognize_google(audio)
        print("Google thinks you said " + text)
    except sr.UnknownValueError:
        print("Google could not understand audio")
        continue
    except sr.RequestError as e:
        print("Could not request results from Google service; {0}".format(e))
        continue
    Numtext = stringConvert(text)
    i = 0
    while i < len(Numtext):
        numsend = str(Numtext[i])
        if numsend != '-64':
            ser.write(numsend)
        else:
            ser.write(27)
        print(numsend)
        time.sleep(2.1)
        i += 1
        
