"""
SAMVAAD: A–Z Sign Language Recognizer (MediaPipe + KNN)

Usage:
1) Run this file -> choose mode:
   [1] Collect data
   [2] Train model
   [3] Real-time prediction
   [4] Exit

Controls in Real-time Mode:
- SPACE = insert space
- BACKSPACE = delete last character
- ENTER = speak full text
- C = clear all
- Q = quit
"""

import os 
import cv2
import pickle
import time
import numpy as np
from collections import deque, Counter

import mediapipe as mp
from sklearn.neighbors import KNeighborsClassifier

try:
    import pyttsx3
    TTS_AVAILABLE = True
except:
    TTS_AVAILABLE = False

# -----------------------------
# CONFIG
# -----------------------------
DATA_DIR = "sign_dataset"
MODEL_PATH = "sign_model.pkl"
LETTERS = [chr(c) for c in range(ord('A'), ord('Z') + 1)]

mp_hands = mp.solutions.hands
mp_draw = mp.solutions.drawing_utils


# -----------------------------
# FEATURE EXTRACTION
# -----------------------------
def extract_features(hand_landmarks):
    xs, ys = [], []
    for lm in hand_landmarks.landmark:
        xs.append(lm.x)
        ys.append(lm.y)
    xs, ys = np.array(xs), np.array(ys)

    # Normalize
    xs = (xs - xs.min()) / (xs.max() - xs.min() + 1e-6)
    ys = (ys - ys.min()) / (ys.max() - ys.min() + 1e-6)

    feat = np.empty(42)
    feat[0::2] = xs
    feat[1::2] = ys
    return feat.astype(np.float32)


# -----------------------------
# DATA COLLECTION
# -----------------------------
def collect_data():
    os.makedirs(DATA_DIR, exist_ok=True)
    letter = input("Enter LETTER to collect data for (A–Z): ").strip().upper()
    if letter not in LETTERS:
        print("❌ Invalid input")
        return
    save_dir = os.path.join(DATA_DIR, letter)
    os.makedirs(save_dir, exist_ok=True)

    cap = cv2.VideoCapture(0)
    with mp_hands.Hands(max_num_hands=1) as hands:
        count = 0
        while True:
            ret, frame = cap.read()
            if not ret: break
            frame = cv2.flip(frame, 1)
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            res = hands.process(rgb)

            if res.multi_hand_landmarks:
                hand = res.multi_hand_landmarks[0]
                mp_draw.draw_landmarks(frame, hand, mp_hands.HAND_CONNECTIONS)

                feats = extract_features(hand)
                np.save(os.path.join(save_dir, f"{int(time.time()*1000)}.npy"), feats)
                count += 1

            cv2.putText(frame, f"Collecting {letter} | Saved: {count}", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            cv2.imshow("Data Collection", frame)

            if cv2.waitKey(1) & 0xFF == ord('q'): break

    cap.release()
    cv2.destroyAllWindows()


# -----------------------------
# TRAIN MODEL
# -----------------------------
def train_model():
    X, y = [], []
    for label in os.listdir(DATA_DIR):
        folder = os.path.join(DATA_DIR, label)
        for file in os.listdir(folder):
            if file.endswith(".npy"):
                X.append(np.load(os.path.join(folder, file)))
                y.append(label)
    if not X:
        print("❌ No data found")
        return
    X, y = np.array(X), np.array(y)
    model = KNeighborsClassifier(n_neighbors=7, weights="distance")
    model.fit(X, y)
    with open(MODEL_PATH, "wb") as f:
        pickle.dump(model, f)
    print("✅ Model trained and saved!")


# -----------------------------
# DELETE MODEL
# -----------------------------
def delete_model():
    if os.path.exists(MODEL_PATH):
        os.remove(MODEL_PATH)
        print("🗑️ Trained model deleted successfully.")
    else:
        print("⚠️ No trained model found to delete.")







# -----------------------------
# REAL-TIME PREDICTION
# -----------------------------
def realtime_prediction():
    if not os.path.exists(MODEL_PATH):
        print("❌ Train the model first!")
        return
    with open(MODEL_PATH, "rb") as f:
        model = pickle.load(f)

    text = ""
    pred_history = deque(maxlen=8)

    tts = pyttsx3.init() if TTS_AVAILABLE else None

    cap = cv2.VideoCapture(0)
    with mp_hands.Hands(max_num_hands=1) as hands:
        while True:
            ret, frame = cap.read()
            if not ret: break
            frame = cv2.flip(frame, 1)
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            res = hands.process(rgb)

            if res.multi_hand_landmarks:
                hand = res.multi_hand_landmarks[0]
                mp_draw.draw_landmarks(frame, hand, mp_hands.HAND_CONNECTIONS)

                feats = extract_features(hand).reshape(1, -1)
                pred = model.predict(feats)[0]
                pred_history.append(pred)

                if len(pred_history) >= 5:
                    stable = Counter(pred_history).most_common(1)[0][0]
                    if not text or text[-1] != stable:
                        text += stable

            cv2.putText(frame, f"Text: {text}", (10, 50),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
            cv2.imshow("SAMVAAD", frame)

            key = cv2.waitKey(1) & 0xFF
            if key == ord(' '): text += " "
            elif key == 8: text = text[:-1]  # backspace
            elif key == ord('c'): text = ""
            elif key == 13 and tts:  # enter
                tts.say(text); tts.runAndWait()
            elif key == ord('q'): break

    cap.release()
    cv2.destroyAllWindows()


# -----------------------------
# MAIN MENU
# -----------------------------
if __name__ == "__main__":
    while True:
        print("\n--- SAMVAAD MENU ---")
        print("1. Collect data (A–Z)")
        print("2. Train model")
        print("3. Real-time prediction")
        print("4. Delete trained model")
        print("5. Exit")
        choice = input("Enter choice: ").strip()

        if choice == "1": 
            collect_data()
        elif choice == "2": 
            train_model()
        elif choice == "3": 
            realtime_prediction()
        elif choice == "4": 
            delete_model()
        elif choice == "5": 
            break
        else: 
            print("❌ Invalid choice")

