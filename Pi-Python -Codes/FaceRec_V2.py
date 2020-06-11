#TECHEONICS
#SimAr The Humanoid Robot
#www.techeonics.com SimAr :-https://techeonics.com/?page_id=253 
#YouTube :- https://www.youtube.com/channel/UCVoZOntfYYGYCdJygatR2pA?view_as=subscriber



import cv2
import os
import numpy as np


def faceDetection(test_img):
    gray_img = cv2.cvtColor(test_img, cv2.COLOR_BGR2GRAY)      # Image fed is changed into gray image
    face_haar_cascade = cv2.CascadeClassifier(
        'cascade/haarcascade_frontalface_default.xml')         # Setup Classifier to detect face
    faces = face_haar_cascade.detectMultiScale(gray_img, scaleFactor=1.32, minNeighbors=5) # Use classifier to detect faces in the image and save it in faces

    return faces, gray_img                                     # Gives back the detected faces and gray image


def lables_for_training_data(directory):                       #fetch images n mention their labels
    faces =  []
    faceID = []

    for path, subdirnames, filenames in os.walk(directory):   # OS.walk gives path , dir and filename
        for filename in filenames:                            #Ignores sys files
            if filename.startswith("."):
                print("skip sys file")
                continue

            id = os.path.basename(path)                       #Path is stored in id as id of image or specific label
            img_path = os.path.join(path, filename)           #Extract image path n store in img_path var
            print("img_path ", img_path)                      #print path for debug
            print("id: ", id)                                 #prints id or base name
            test_img = cv2.imread(img_path)                   #feed classifier the images from the dir we fetched with OS walk
            if test_img is None:
                print("Img not loaded")
                continue
            faces_rect, gray_img = faceDetection(test_img)    #store face got by classifier in face rect and gray image n gray var
            #(x, y, w, h) = faces_rect[0]                      #Get coordinates of the detected face
            #roi_gray = gray_img[y:y + w, x:x + h]             #Crops the required face region
            roi_gray = gray_img
            faces.append(roi_gray)                            #Stores region of interest in faces
            faceID.append(int(id))                            #Stores fetched id into FaceId var

    return faces, faceID

def train_classifier(faces,faceID):                          #Training Function
    face_recognizer = cv2.face.LBPHFaceRecognizer_create()   #Specify which recognizer to use Here using LBPH
    face_recognizer.train(faces,np.array(faceID))            #Feed the training data to the recognizer
    return face_recognizer

def draw_rect(test_img,face):
    (x,y,w,h) = face
    cv2.rectangle(test_img,(x,y),(x+w,y+h),(255,0,0),thickness=5)

def put_text(test_img,text,x,y):
    cv2.putText(test_img,text,(x,y),cv2.FONT_HERSHEY_COMPLEX_SMALL,3,(0,255,0),3)