#TECHEONICS
#SimAr The Humanoid Robot
#www.techeonics.com SimAr :-https://techeonics.com/?page_id=253 
#YouTube :- https://www.youtube.com/channel/UCVoZOntfYYGYCdJygatR2pA?view_as=subscriber

import pyttsx3     #text to speech
import datetime    #for keeping track of the time
import speech_recognition as sr  #speech to text

engine = pyttsx3.init('sapi5')             #Sepi5 is Microsoft Speech Engine
voices = engine.getProperty('voices')
# print(voices)
engine.setProperty('voice', voices[1].id)  #Set assistant voice , male or female


# print(voices[1], id)


def speak(audio):         #Takes audio as string
    engine.say(audio)     #Feed audio to engine
    engine.runAndWait()


def wishme():              #wishes user according to the time of the day
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Good Morning")

    elif hour >= 12 and hour < 18:
        speak("Good Afternoon")

    else:
        speak("Good Evening")


def takeCommand():
    # It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:    #Use mic as source
        print("Listening...")
        r.pause_threshold = 1   #wait a sec and see if phrase is complete

        # audio = r.listen(source)
        audio = r.listen(source, timeout=3, phrase_time_limit=3)   #save recognized audio to audio var

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')     #raw audio fed to google recognizer
        print(f"User said: {query}\n")                          #recognizer returns string made from audio and save in query

    except Exception as e:                                      #if error occurs while recognizing
        # print(e)                                              #return none
        print("Say that again please...")
        return "None"
    return query


if __name__ == "__main__":
    speak("Hello Kunwar")
   while True:
       query = takeCommand().lower()






